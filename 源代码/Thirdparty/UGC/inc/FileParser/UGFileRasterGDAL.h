
/*!
    **************************************************************************************
     \file     UGFileRasterGDAL.h
    **************************************************************************************
     \author   ����
     \brief    Gdal�ļ�������               
     \remarks   ����դ������඼�����̳�                                                                       <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/

#if !defined(AFX_UGFILERASTERGDAL_H__9E8BA4C7_A34C_41EB_A4A0_61965343C3BF__INCLUDED_)
#define AFX_UGFILERASTERGDAL_H__9E8BA4C7_A34C_41EB_A4A0_61965343C3BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "gdal_priv.h"
#include "FileParser/UGFileParseRaster.h"

namespace UGC{


class UGFileRasterGDAL : public UGFileParseRaster  
{
public:
	UGFileRasterGDAL();
	virtual ~UGFileRasterGDAL();

public:	
	
	//////////////////////////////////////////////////////////////////////////
	// UGFileParse �еķ���
	//////////////////////////////////////////////////////////////////////////
	
	//! \brief ׼����ȡһ�������ļ�
	virtual UGbool OpenForRead(const UGString& strFileName);


public:
	//////////////////////////////////////////////////////////////////////////
	// �̳� UGFileParseRaster �ķ���
	//////////////////////////////////////////////////////////////////////////
	

	//////////////////////////////////////////////////////////////////////////
	// ��ȥ����
	//////////////////////////////////////////////////////////////////////////

	//! \brief ��ȡդ�����ݵ� nodata
	virtual UGint GetNoValue();

	//! \brief ׼����ʼ��ȡդ������,�ڵ���ReadData֮ǰ�������
	virtual UGbool BeginRead(UGint nIndex = 1);

	//! \brief ��ȡһ��ɨ���е�����
	virtual UGbool ReadScanLine(UGImgScanline& imgScanline, UGint nRowIndex, UGint nBandIndex = 0);
	
	//! \brief ��ȡһ��Block����
	virtual UGbool ReadBlock(UGImgBlock* pImgBlock, UGint nRowBlockIndex, UGint nColBlockIndex, UGint nBandIndex = 0);
	
	//! \brief ������ȡդ������,�ڵ���ReadData֮��������(�ͷŶ���)
	virtual void EndRead();

	//! \brief �ر��ļ�
	virtual void Close();
	
private:
	//! \brief ��ȡ���صĸ�ʽ
	PixelFormat ReadPixelFormat();

	//! \brief �õ���ɫ��
	UGColorset ReadColorset();

	//! \brief ��ȡBounds
	UGRect2D ReadBounds();
	
private:
	
	//! \brief ���ļ��� gdal ���ݼ�ָ��
	GDALDataset  *m_pgDataset;

	//! \brief Bandָ��
	GDALRasterBand  *m_pgBand;
};

}
#endif // !defined(AFX_UGFILERASTERGDAL_H__9E8BA4C7_A34C_41EB_A4A0_61965343C3BF__INCLUDED_)
