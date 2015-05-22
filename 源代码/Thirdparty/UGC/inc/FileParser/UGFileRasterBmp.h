
/*!
    **************************************************************************************
     \file     UGFileRasterBmp.h
    **************************************************************************************
     \author   ����
     \brief    BMP�ļ�������                
     \remarks   ���� UGFileRaster��̳�                                                                    <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/

#if !defined(AFX_UGFILERASTERBMP_H__A42B6B70_BD1B_4C71_8676_2BB3AFD97FD6__INCLUDED_)
#define AFX_UGFILERASTERBMP_H__A42B6B70_BD1B_4C71_8676_2BB3AFD97FD6__INCLUDED_


#include "UGFileParseRaster.h"
#include "FileParser/UGFileLibBmp.h"
#include "Base/UGFileStream.h"
#include "Base/UGMemoryStream.h"

namespace UGC {

	class UGImgScanline;
	class UGImage;
	
class FILEPARSER_API UGFileRasterBmp : public UGFileParseRaster  
{
public:
	UGFileRasterBmp();
	virtual ~UGFileRasterBmp();

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
	//! \brief ��ȡһ��ɨ���е�����
	UGuchar *pBmpData;
	//! \brief ��д�ļ���
	UGFileLibBmp m_bmp;
	//! \brief Bmp�����ظ�ʽ�������
	BitmapType m_type;
	//! \brief �洢���ձ�ColorTable��
	UGuchar *pColorTable;
	
};

} //namespace UGC

#endif // !defined(AFX_UGFILERASTERBMP_H__A42B6B70_BD1B_4C71_8676_2BB3AFD97FD6__INCLUDED_)
