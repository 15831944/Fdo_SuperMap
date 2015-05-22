/** \file	 SuperMapRaster.cpp
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-01-03
*/

#include "SuperMap.h"

SuperMapRaster::SuperMapRaster(UGC::UGDatasetRaster *pDatasetRaster, FdoClassDefinition* ClassDef)
{
	TRACE(_T("���� SuperMapRaster::SuperMapRaster()... \n"));
	m_nBandNum = 1;
	m_nCurBand = 1;
	m_bNull = false;
	m_pDatasetRaster = pDatasetRaster;
	m_ClassDef = ClassDef;
}

SuperMapRaster::~SuperMapRaster(void)
{
	TRACE(_T("���� SuperMapRaster::~SuperMapRaster()... \n"));
}

void SuperMapRaster::Dispose()
{
	TRACE(_T("���� SuperMapRaster::Dispose()... \n"));
	delete this;
}

FdoInt32 SuperMapRaster::GetNumberOfBands ()
{
	TRACE(_T("���� SuperMapRaster::GetNumberOfBands()... \n"));
	return m_nBandNum;
}

void SuperMapRaster::SetNumberOfBands (FdoInt32 value)
{
	TRACE(_T("���� SuperMapRaster::SetNumberOfBands()... \n"));
	m_nBandNum = value;
}

FdoInt32 SuperMapRaster::GetCurrentBand ()
{
	TRACE(_T("���� SuperMapRaster::GetCurrentBand()... \n"));
	return m_nCurBand;
}

void SuperMapRaster::SetCurrentBand (FdoInt32 value)
{
	TRACE(_T("���� SuperMapRaster::SetCurrentBand()... \n"));
	m_nCurBand = value;
}

bool SuperMapRaster::IsNull ()
{
	TRACE(_T("���� SuperMapRaster::IsNull()... \n"));
	return m_bNull;
}

void SuperMapRaster::SetNull ()
{
	TRACE(_T("���� SuperMapRaster::SetNull()... \n"));
	m_bNull = true;        
}

FdoByteArray* SuperMapRaster::GetBounds ()
{
	TRACE(_T("���� SuperMapRaster::GetBounds()... \n"));
	FdoPtr<FdoByteArray> ret;
	FdoPtr<FdoIEnvelope> envelope;                      //��Χ��

	if( NULL != m_pDatasetRaster )
	{
		UGC::UGRect2D recBound = m_pDatasetRaster->GetBounds();

		TRACE(_T("���� SuperMapRaster::GetBounds()...left=[%f],bottom=[%f],top=[%f],right=[%f] \n"),
			recBound.left, recBound.bottom, recBound.top, recBound.right);

		FdoFgfGeometryFactory *pFactory = FdoFgfGeometryFactory::GetInstance();
		if( NULL != pFactory )
		{
			envelope = pFactory->CreateEnvelopeXY(recBound.left, 
				recBound.bottom,
				recBound.right, 
				recBound.top);
			FdoPtr<FdoIGeometry> geometry = pFactory->CreateGeometry(envelope);
			ret = pFactory->GetFgf(geometry.p);
		}
	}

	return FDO_SAFE_ADDREF(ret.p); 
}

void SuperMapRaster::SetBounds (FdoByteArray* bounds)
{
	TRACE(_T("���� SuperMapRaster::SetBounds()... \n"));
	int *pGeoArray = (int*)bounds->GetData();
	bool bThreeDim = false; //�ж��Ƿ�����ά
	double MaxX, MaxY, MinX, MinY;
	if(FdoGeometryType_Polygon != *(pGeoArray++)) //�ж�����
	{
		return;
	}
	else
	{
		if(FdoDimensionality_XY != *(pGeoArray++))
		{
			bThreeDim = true;
		}
		if( 1 !=*(pGeoArray++) ) //����������
		{
			return;
		}
		if( 5 != *(pGeoArray++) )//����5����Ļ�
		{
			return;
		}
		double *pCoordinate = (double *)pGeoArray;
		MinX = MaxX = *(pCoordinate++);
		MaxY = MinY = *(pCoordinate++);
		if(bThreeDim)
		{
			pCoordinate++; //���Ե���ά
		}
		for(int i = 0; i< 4; i++)
		{
			double CoordinateX = *(pCoordinate++);
			if(MinX > CoordinateX)
			{
				MinX = CoordinateX;
			}
			if(MaxX < CoordinateX)
			{
				MaxX = CoordinateX;
			}
			double CoordinateY = *(pCoordinate++);
			if(MinY > CoordinateY)
			{
				MinY = CoordinateY;
			}
			if(MaxY < CoordinateY)
			{
				MaxY = CoordinateY;
			}
			if(bThreeDim)
			{
				pCoordinate++; //���Ե���ά
			}
		}//for
		if( NULL != m_pDatasetRaster )
		{
			UGC::UGRect2D recBound(MinX, MaxY, MaxX, MinY);
			m_pDatasetRaster->SetBounds(recBound);
		}

	}//else
}

FdoRasterDataModel* SuperMapRaster::GetDataModel ()
{
	TRACE(_T("���� SuperMapRaster::GetDataModel()... \n"));
	if(NULL != m_dataModel)
	{
		return  FDO_SAFE_ADDREF(m_dataModel.p);
	}
	m_dataModel = FdoRasterDataModel::Create();
	if( NULL != m_pDatasetRaster )
	{
		UGC::UGDatasetRasterInfo* pRasterInfo = m_pDatasetRaster->GetInfo();
		if( NULL != pRasterInfo )
		{	
			m_dataModel->SetTileSizeX(m_pDatasetRaster->GetWidth()); // ���ÿ�Ĵ�С
			m_dataModel->SetTileSizeY(m_pDatasetRaster->GetHeight()); 
			m_dataModel->SetOrganization(FdoRasterDataOrganization_Pixel);

			FdoRasterDataModelType nDataModelType = FdoRasterDataModelType_RGB;
			FdoRasterDataType nDataType = FdoRasterDataType_UnsignedInteger;
			switch(pRasterInfo->m_ePixelFormat)
			{
			case UGC::IPF_MONO: //��ֵͼ��
			case UGC::IPF_BYTE: //8λͼ���п����ǻҶ�ͼ��Ҳ�п����Ǵ��е�ɫ��Ĳ�ɫͼ��
				if( IsPalletteImage() )
				{
					nDataModelType = FdoRasterDataModelType_RGB;
					nDataType = FdoRasterDataType_UnsignedInteger;
					m_dataModel->SetBitsPerPixel( RGB24 ); 
				}
				else //�Ҷ�ͼ��
				{
					nDataModelType = FdoRasterDataModelType_Gray;
					nDataType = FdoRasterDataType_UnsignedInteger;
					m_dataModel->SetBitsPerPixel( GRAYORMONO ); 
				}
				break;

			case UGC::IPF_RGB: //RGBͼ��
			case UGC::IPF_TBYTE: //16λ��ɫͼ��
			case UGC::IPF_FBIT: //4λ��ɫͼ��
				nDataModelType = FdoRasterDataModelType_RGB;
				nDataType = FdoRasterDataType_UnsignedInteger;
				m_dataModel->SetBitsPerPixel( RGB24 ); 
				break;

			case UGC::IPF_RGBA: //RGBAͼ��
				nDataModelType = FdoRasterDataModelType_RGBA;
				nDataType = FdoRasterDataType_UnsignedInteger;
				m_dataModel->SetBitsPerPixel( RGBA32 ); 
				TRACE(_T("���� SuperMapRaster::GetDataModel()...RGBAģʽ \n"));
				break;
			case UGC::IPF_TRGB: //TRGBͼ��
				nDataModelType = FdoRasterDataModelType_RGB;
				nDataType = FdoRasterDataType_UnsignedInteger;
				m_dataModel->SetBitsPerPixel( TRGB48 ); 
				break;

			case UGC::IPF_LONGLONG:
				nDataModelType = FdoRasterDataModelType_RGB;
				nDataType = FdoRasterDataType_UnsignedInteger;
				m_dataModel->SetBitsPerPixel( RGB64 ); 
				break;

			case UGC::IPF_FLOAT:
				nDataModelType = FdoRasterDataModelType_RGB;
				nDataType = FdoRasterDataType_Float;
				m_dataModel->SetBitsPerPixel( RGBA32 ); 
				break;

			case UGC::IPF_DOUBLE:
				nDataModelType = FdoRasterDataModelType_RGB;
				nDataType = FdoRasterDataType_Double;
				m_dataModel->SetBitsPerPixel( RGB64 ); 
				break;

			default:
				break;
			}
			m_dataModel->SetDataModelType(nDataModelType);
			m_dataModel->SetDataType( nDataType );
		}
	}
	return  FDO_SAFE_ADDREF(m_dataModel.p);
}

void SuperMapRaster::SetDataModel (FdoRasterDataModel* datamodel)
{
	TRACE(_T("���� SuperMapRaster::SetDataModel()... \n"));
	if (datamodel == NULL || !m_bNull)
	{
		return;
	}
	FdoPtr<SuperMapRasterCapabilities> rasterCap = new SuperMapRasterCapabilities();
	if (!rasterCap->SupportsDataModel(datamodel))
	{
		return;
	}
	m_dataModel = FDO_SAFE_ADDREF(datamodel);
}

FdoInt32 SuperMapRaster::GetImageXSize ()
{
	int nImageX = 0;
	if(NULL != m_dataModel)
	{
		nImageX = m_dataModel->GetTileSizeX( );
	}
	else if( NULL != m_pDatasetRaster)
	{
		nImageX = m_pDatasetRaster->GetWidth();
	}
	TRACE(_T("���� SuperMapRaster::GetImageXSize()...X=[%d] \n"), nImageX);
	return nImageX;
}

void SuperMapRaster::SetImageXSize (FdoInt32 size)
{
	TRACE(_T("���� SuperMapRaster::SetImageXSize()...X=[%d] \n"), size);
	if(NULL != m_dataModel)
	{
		m_dataModel->SetTileSizeX(size);
	}
}

FdoInt32 SuperMapRaster::GetImageYSize ()
{
	int nImageY = 0;
	if(NULL != m_dataModel)
	{
		nImageY = m_dataModel->GetTileSizeY( );
	}
	else if( NULL != m_pDatasetRaster)
	{
		nImageY = m_pDatasetRaster->GetHeight();
	}
	TRACE(_T("���� SuperMapRaster::GetImageYSize()...Y=[%d] \n"), nImageY);
	return nImageY;

}

void SuperMapRaster::SetImageYSize (FdoInt32 size)
{
	TRACE(_T("���� SuperMapRaster::SetImageYSize()...Y=[%d] \n"), size);
	if(NULL != m_dataModel)
	{
		m_dataModel->SetTileSizeY(size);
	}
}

FdoIRasterPropertyDictionary* SuperMapRaster::GetAuxiliaryProperties ()
{
	TRACE(_T("���� SuperMapRaster::GetAuxiliaryProperties()... \n"));
	return NULL;
}

FdoDataValue* SuperMapRaster::GetNullPixelValue ()
{
	TRACE(_T("���� SuperMapRaster::GetNullPixelValue()... \n"));
	FdoPtr<FdoDataValue> val;
	if( NULL != m_pDatasetRaster )
	{
		double noValue = m_pDatasetRaster->GetNoValue();
		val = FdoDoubleValue::Create(noValue);
	}
	return FDO_SAFE_ADDREF(val.p);
}

void SuperMapRaster::SetStreamReader (FdoIStreamReader* reader)
{
	TRACE(_T("���� SuperMapRaster::SetStreamReader()... \n"));
}

FdoIStreamReader* SuperMapRaster::GetStreamReader ()
{
	TRACE(_T("���� SuperMapRaster::GetStreamReader()... \n"));
	FdoPtr<FdoIStreamReader> streamReader = new SuperMapStreamReader(m_pDatasetRaster, 
		FDO_SAFE_ADDREF(m_dataModel.p));
	return FDO_SAFE_ADDREF(streamReader.p);
}

FdoString* SuperMapRaster::GetVerticalUnits ()
{
	TRACE(_T("���� SuperMapRaster::GetVerticalUnits()... \n"));
	return L"";
}

void SuperMapRaster::SetVerticalUnits (FdoString* units)
{
	TRACE(_T("���� SuperMapRaster::SetVerticalUnits()... \n"));
}


bool SuperMapRaster::IsPalletteImage()
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