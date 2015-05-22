
/*!
    **************************************************************************************
     \file     UGFileRasterPng.h
    **************************************************************************************
     \author   ����
     \brief    Png�ļ�������                
     \remarks   ���� UGFileRaster��̳�                                                                         <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGFILERASTERPNG_H__F54AF582_8A49_46E4_9139_A8DF579D2E7F__INCLUDED_)
#define AFX_UGFILERASTERPNG_H__F54AF582_8A49_46E4_9139_A8DF579D2E7F__INCLUDED_


#include "UGFileParseRaster.h"
#include "png.h"
#include "Base/UGFileStream.h"
#include "Base/UGMemoryStream.h"

namespace UGC {

	class UGMemoryStream;
	class UGImage;

class FILEPARSER_API UGFileRasterPng : public UGFileParseRaster  
{
public:
	UGFileRasterPng();
	virtual ~UGFileRasterPng();
public:


	//! \brief 		���UGImage���ݵ�PNG�ļ�.
	//! \return 	UGbool  
	//! \param 		strFileName  ������ļ�·��
	//! \param 		pImage       
	//! \remarks 		
	UGbool OutputDirect(UGString strFileName, UGImage* pImage);
public:

	//////////////////////////////////////////////////////////////////////////
	// ��ȥ����
	//////////////////////////////////////////////////////////////////////////
	//! \brief ׼����ȡһ�������ļ�
	virtual UGbool OpenForRead(const UGString& strFileName);
	//! \brief ׼����ʼ��ȡդ������,�ڵ���ReadData֮ǰ�������
	virtual UGbool BeginRead(UGint nIndex = 1);

	//! \brief ��ȡһ��ɨ���е�����
	virtual UGbool ReadScanLine(UGImgScanline& imgScanline, UGint nRowIndex, UGint nBandIndex = 0);

	//! \brief ������ȡդ������,�ڵ���ReadData֮��������(�ͷŶ���)
	virtual void EndRead();

	//////////////////////////////////////////////////////////////////////////
	// д�뺯��
	//////////////////////////////////////////////////////////////////////////
	//! \brief ׼��д��һ�������ļ�
	virtual UGbool OpenForWrite(const UGString& strFileName);
	//! \brief ׼����ʼд����,�ڵ���WriteData֮ǰ�������
	virtual UGbool BeginWrite();

	//! \brief д��һ��ɨ���е�����
	virtual UGbool WriteScanLine(UGint nRowIndex, UGImgScanline& imgScanline);

	//! \brief ����д����,�ڵ���WriteData֮��������
	virtual void EndWrite();
	//! \brief �ر�����
	virtual void Close();

private:

	UGFileStream m_FilePng;
	png_structp m_pPngStruct;
	png_infop m_pPngInfo;
	png_colorp m_pPngPalette;
	UGbool m_bRead;		//������д��
	UGMemoryStream m_MemoryStream;
	//! \brief �Ƿ���OutputDirect��������SavePngHeader()��������ΪOutputDirect���þ���Ҫ���⴦����RGBA->RGB,����ת���Ͳ���Ҫ��
	UGbool m_bOutputDirect;
private:
	//! \brief ����Png���ļ�ͷ
	UGbool SavePngHeader();
	
};


} //namespace UGC

#endif // !defined(AFX_UGFILERASTERPNG_H__F54AF582_8A49_46E4_9139_A8DF579D2E7F__INCLUDED_)
