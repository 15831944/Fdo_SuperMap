/** \file	 SuperMapStreamReader.cpp
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-01-03
*/

#include "SuperMap.h"

SuperMapStreamReader::SuperMapStreamReader(UGC::UGDatasetRaster *pDatasetRaster, 
										   FdoRasterDataModel* datamodel)
{
	TRACE(_T("���� SuperMapStreamReader::SuperMapStreamReader()... \n"));
	m_pDatasetRaster = pDatasetRaster;
	m_nStreamIndex = 0; 
	m_dataModel = datamodel;
	m_nBytesPerPixel = 0;
}

SuperMapStreamReader::~SuperMapStreamReader(void)
{
	TRACE(_T("���� SuperMapStreamReader::~SuperMapStreamReader()... \n"));
}

void SuperMapStreamReader::Dispose()
{
	TRACE(_T("���� SuperMapStreamReader::Dispose()... \n"));
	delete this;
}

FdoInt64 SuperMapStreamReader::GetLength()
{
	TRACE(_T("���� SuperMapStreamReader::GetLength()... \n"));

	//�ô��ĳ�����ָ��������Ӱ�����ֽڵ��ܸ��������㷽��Ϊ: ÿ�����ص��ֽ���*Ӱ���������
	FdoInt64 nStreamLength = 0;
	int nXLength = 0;
	int nYLength = 0;

	if(NULL != m_pDatasetRaster)
	{
		switch( m_pDatasetRaster->GetPixelFormat() )
		{
		case UGC::IPF_MONO: //��ֵ
		case UGC::IPF_BYTE:
			if( IsPalletteImage() )
			{
				m_nBytesPerPixel = THREEBYTESPIXEL;
			}
			else
			{
				m_nBytesPerPixel = ONEBYTEPIXEL;
			}
			break;

		case UGC::IPF_FBIT: //4 bits
		case UGC::IPF_TBYTE: //16 bits
		case UGC::IPF_RGB: //24 bits
			m_nBytesPerPixel = THREEBYTESPIXEL;
			break;

		case UGC::IPF_RGBA: //32 bits
			m_nBytesPerPixel = FOURBYTESPIXEL;
			break;

		case UGC::IPF_TRGB: //48 bits
			m_nBytesPerPixel = SIXBYTESPERPIXEL;
			break;

		case UGC::IPF_LONGLONG: //64 bits
			m_nBytesPerPixel = EIGHTBYTESPERPIXEL;
			break;

		case UGC::IPF_FLOAT: //32 bits
			m_nBytesPerPixel = FOURBYTESPIXEL;
			break;

		case UGC::IPF_DOUBLE: //64 bits
			m_nBytesPerPixel = EIGHTBYTESPERPIXEL;
			break;

		default:
			m_nBytesPerPixel = THREEBYTESPIXEL;
			break;
		}
		nStreamLength  = m_pDatasetRaster->GetWidth() * m_pDatasetRaster->GetHeight() * m_nBytesPerPixel;
	}
	return nStreamLength;
}

void SuperMapStreamReader::Skip(const FdoInt32 offset)
{
	TRACE(_T("���� SuperMapStreamReader::Skip()... \n"));
}

FdoInt64 SuperMapStreamReader::GetIndex()
{
	TRACE(_T("���� SuperMapStreamReader::GetIndex()... \n"));
	return m_nStreamIndex;
}

void SuperMapStreamReader::Reset()
{
	TRACE(_T("���� SuperMapStreamReader::Reset()... \n"));
}

FdoInt32 SuperMapStreamReader::ReadNext( FdoByte* buffer, const FdoInt32 offset, const FdoInt32 count)
{
	TRACE(_T("���� SuperMapStreamReader::ReadNext(Byte)...ƫ����[%d]..�ֽ���[%d] \n"), offset, count);
	int nReadBytes = 0;
	if (count < -1 || offset < 0 || NULL == buffer || NULL == m_pDatasetRaster)
	{
		TRACE(_T("SuperMapStreamReader�쳣������"));
		return nReadBytes;
	}

	int nXLength = 0;  //ͼ���ʵ�����ؿ�
	int nYLength = 0;  //ͼ���ʵ�����ظ�
	int nImgColorType = IMGRGB24; // Ĭ��ΪRGB��ʽ
	UGC::UGDatasetRasterInfo* pRasterInfo = m_pDatasetRaster->GetInfo();
	if(NULL != pRasterInfo)
	{
		nXLength = pRasterInfo->m_nWidth;    
		nYLength = pRasterInfo->m_nHeight;

		switch( pRasterInfo->m_ePixelFormat )
		{
		case UGC::IPF_MONO: //��ֵ
			nImgColorType = IMGMONO;
			break;

		case UGC::IPF_FBIT: //4 bits
			nImgColorType = IMGRGB4;
			break;

		case UGC::IPF_BYTE: //�Ҷ�
			nImgColorType = IMGGRAY;
			break;

		case UGC::IPF_TBYTE: //16 bits
			nImgColorType = IMGRGB16;
			break;

		case UGC::IPF_RGB: //24 bits
			nImgColorType = IMGRGB24;
			break;

		case UGC::IPF_RGBA: //32 bits
			nImgColorType = IMGRGB32;
			break;

		case UGC::IPF_TRGB: //48 bits 
			nImgColorType = IMGRGB48;
			break;

		case UGC::IPF_LONGLONG: //64 bits
			nImgColorType = IMGRGB64;
			break;

		case UGC::IPF_FLOAT: //float 32 bits
			nImgColorType = IMGRGBFLOAT;
			break;

		case UGC::IPF_DOUBLE: //double 64 bits
			nImgColorType = IMGRGBDOUBLE;
			break;

		default:
			break;
		}
	}
	int nViewXLength = nXLength;	//�ز�������ʾͼ��Ŀ��
	int nViewYLength = nYLength;	//�ز�������ʾͼ��ĸ߶�
	
	if(NULL != m_dataModel)			//��ȡ��ʾͼ��Ŀ�Ⱥ͸߶�
	{
		nViewXLength = m_dataModel->GetTileSizeX();
		nViewYLength = m_dataModel->GetTileSizeY();
	}

	buffer += offset;
	return FuncRatioResample(buffer, nXLength, nYLength, nViewXLength, nViewYLength, nImgColorType, count);
}

FdoInt32 SuperMapStreamReader::ReadNext(  FdoArray<FdoByte> * &buffer, const FdoInt32 offset, const FdoInt32 count )
{
	TRACE(_T("���� SuperMapStreamReader::ReadNext(FdoArray)... \n"));
	return ReadNext(buffer->GetData(), offset, count);
}

//ĿǰUGC��֧�ֶ�ȡ������󳤶�Ϊ32λ������֧��48��64λ�Ĳ�ɫͼ�����⣬����ֵΪdouble����Ӱ��
//��DEM��ECW��ʽ�ģ���ϵͳ�ݲ�֧�֣��������нӿڣ������ز�������ֻ�Ƕ�ȡ���¸�ʽ��Ӱ��
// 1��4��8��16��24��32λ��Ӱ�񣬿��Դ���ɫ�壬Ҳ���Բ�����ɫ��
int SuperMapStreamReader::FuncRatioResample(FdoByte* buffer, int nFileXlen, int nFileYLen, 
		int nViewXLen, int nViewYLen, int nImgColorType, int nCount)
{
	TRACE(_T("���� SuperMapStreamReader::FuncRatioResample()Ҫ��ȡ���ֽ���[%d]... \n"), nCount);
	//FdoInt64 nStreamLenth = GetLength();
	//int nReadBytes = (nStreamLenth - m_nStreamIndex * m_nBytesPerPixel >= nCount) ? 
								//nCount : (nStreamLenth - m_nStreamIndex * m_nBytesPerPixel);
	int nReadBytes = nCount;
	double fXShowRatio = 1;			//X�������������Ĭ��Ϊ1
	double fYShowRatio = 1;			//Y�������������Ĭ��Ϊ1
	bool bImgSITFile = false;		//�ж��Ƿ���SIT�ļ���ʽ��SIT���ܰ���������
	if(m_pDatasetRaster->GetDataSource()->GetEngineType() == UGC::ImagePlugins)
	{
		bImgSITFile = true;
	}

	if(nViewXLen && nViewYLen)
	{
		fXShowRatio = double(nFileXlen) / double(nViewXLen);
		fYShowRatio = double(nFileYLen) / double(nViewYLen);
	}
	//Ӱ��������Ĳ���
	int ntPyramidCount = m_pDatasetRaster->GetPyramidDatasets().GetSize();
	if(ntPyramidCount > 0)
	{
		UGC::UGDatasets PyramidDatasets = m_pDatasetRaster->GetPyramidDatasets();
		int nPyramidIndex = int(log(double(fXShowRatio)) / log(double(2)) + 0.5);
		//�����ԭͼ���еȴ���߷Ŵ���ʾ��ֱ�Ӷ�ȡԭͼ����
		if( nPyramidIndex <= 0)
		{
			m_pDatasetRaster = m_pDatasetRaster;
		}
		//��ԭͼ������С��ʾ�������ڽ�������Χ��
		else if( nPyramidIndex > 0 && nPyramidIndex < ntPyramidCount) 
		{
			m_pDatasetRaster = (UGC::UGDatasetRaster *)PyramidDatasets.GetAt(nPyramidIndex - 1);
		}
		//��ԭͼ������С��ʾ�������Ѿ�������������Χ��ֱ��ȡ������һ��
		else if( nPyramidIndex >= ntPyramidCount ) 
		{
			m_pDatasetRaster = (UGC::UGDatasetRaster *)PyramidDatasets.GetAt(ntPyramidCount - 1);
		}
		//ȡ�˽�������ĳһ�����Ҫ���¼���Ҫȡͼ��Ŀ�Ⱥ͸߶��Լ����ű���
		if( !m_pDatasetRaster->IsOpen() )
		{
			m_pDatasetRaster->Open();
		}
		nFileXlen = m_pDatasetRaster->GetWidth();
		nFileYLen = m_pDatasetRaster->GetHeight();
		fXShowRatio = double(nFileXlen) / double(nViewXLen);
		fYShowRatio = double(nFileYLen) / double(nViewYLen);
		TRACE(_T("���� SuperMapStreamReader::FuncRatioResample()��������[%d]��.ȡ��[%d]��.. \n"), ntPyramidCount, nPyramidIndex);
	}
	
	int nBlockSize = m_pDatasetRaster->GetBlockSize(); //Ӱ���Ĵ�С
	int nColBlockCount = m_pDatasetRaster->GetColBlockCount(); //����Block�ĸ���
	int nRowIndex = 0; //�ж�ȡ������
	int nRowBlockIndex = 0; //�Ѿ���ȡ�Ŀ��������
	//SIT�ļ�Ӱ���ܻ���
	if( !bImgSITFile )
	{
		m_pDatasetRaster->CacheByBlock(0, nRowBlockIndex++, nColBlockCount, 1);
	}
	nRowIndex += nBlockSize;
	int nReadPixel = 0;
	bool bPalletteImage = IsPalletteImage();
	if(bPalletteImage)
	{
		TRACE(_T("���� SuperMapStreamReader::ReadNext()�е�ɫ����Ϣ]... \n"));
	}
	for(int i = 0; i < nViewYLen; i++)
	{
		for(int j = 0; j < nViewXLen; j++)
		{
			int nPixelX = int(j * fXShowRatio + 0.5);
			int nPixelY = int(i * fYShowRatio + 0.5);

			//�����ǰ���ز����Ѿ�����Ŀ��ڣ����ͷ����п�
			if( nPixelY >= nRowIndex) 
			{
				m_pDatasetRaster->ReleaseAllBlock();
				//SIT�ļ�Ӱ���ܻ���
				if( !bImgSITFile )
				{
					m_pDatasetRaster->CacheByBlock(0, nRowBlockIndex++, nColBlockCount, 1);
				}
				nRowIndex += nBlockSize;
			}
			UGC::UGuint color = m_pDatasetRaster->GetPixel(nPixelX, nPixelY);
			if(bPalletteImage)
			{
				*(buffer++) = UGC::UGREDVAL(color);
				*(buffer++) = UGC::UGGREENVAL(color);
				*(buffer++) = UGC::UGBLUEVAL(color);
			}
			else //�޵�ɫ��
			{
				switch(nImgColorType)
				{
				case IMGMONO: //��ֵ
					{
						*(buffer++) = color & 0XFF;
						break;
					}
				case IMGRGB4: //4 bits
					{
						/*UGC::UGbyte colorB = (color >> 3) & 0X01;
						UGC::UGbyte colorG = (color >> 1) & 0X03;
						UGC::UGbyte colorR = color & 0X01;

						*(buffer++) = colorR;
						*(buffer++) = colorG;
						*(buffer++) = colorB;*/
						*(buffer++) = UGC::UGREDVAL(color);
						*(buffer++) = UGC::UGGREENVAL(color);
						*(buffer++) = UGC::UGBLUEVAL(color);
						break;
					}
				case IMGGRAY: //�Ҷ�
					{
						*(buffer++) = color & 0XFF;
						break;
					}
				case IMGRGB16: //16 bits
					{
						/*UGC::UGbyte colorB = (color >> 11) & 0X1F;
						UGC::UGbyte colorG = (color >> 5) & 0X3F;
						UGC::UGbyte colorR = color & 0X1F;

						*(buffer++) = colorR;
						*(buffer++) = colorG;
						*(buffer++) = colorB;*/
						*(buffer++) = UGC::UGREDVAL(color);
						*(buffer++) = UGC::UGGREENVAL(color);
						*(buffer++) = UGC::UGBLUEVAL(color);
						//TRACE(_T("���� SuperMapStreamReader::��=[%d]��=[%d]��=[%d]... \n"), UGC::UGREDVAL(color), UGC::UGGREENVAL(color), UGC::UGBLUEVAL(color));
						break;
					}
				case IMGRGB24: //24 bits
					{
						*(buffer++) = UGC::UGREDVAL(color);
						*(buffer++) = UGC::UGGREENVAL(color);
						*(buffer++) = UGC::UGBLUEVAL(color);
						break;
					}
				case IMGRGB32: //32 bits
					{
						*(buffer++) = UGC::UGREDVAL(color);
						*(buffer++) = UGC::UGGREENVAL(color);
						*(buffer++) = UGC::UGBLUEVAL(color);
						*(buffer++) = UGC::UGALPHAVAL(color);
						break;
					}
				case IMGRGB48: //48 bits	
				case IMGRGB64: //64 bits
					break;

				case IMGRGBFLOAT: //float 32 bits
				case IMGRGBDOUBLE: //double 64 bits
					break;

				default:
					break;
				}//switch
			}//else
			nReadPixel++;
		} //for
	} //for
	m_pDatasetRaster->ReleaseAllBlock(); //�ͷ����п�
	m_nStreamIndex += nReadPixel;
	TRACE(_T("���� SuperMapStreamReader::ReadNext()��ȡ���ֽ���[%d]... \n"), nReadBytes);
	return nReadBytes;
}

bool SuperMapStreamReader::IsPalletteImage()
{
	if(NULL == m_pDatasetRaster)
	{
		return false;
	}
	if( m_pDatasetRaster->GetColorset().GetSize() == 0 ) //�޵�ɫ��
	{
		return false;
	}
	else
	{
		return true;
	}
}