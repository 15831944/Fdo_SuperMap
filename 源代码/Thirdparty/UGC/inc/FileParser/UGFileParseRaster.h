
/*!
    **************************************************************************************
     \file     UGFileParseRaster.h
    **************************************************************************************
     \author   ����
     \brief    �ļ�����դ����               
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


#if !defined(AFX_UGFileParseRaster_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_)
#define AFX_UGFileParseRaster_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_


#include "UGFileParse.h"
#include "Geometry/UGImgScanline.h"
#include "Geometry/UGImgBlock.h"
#include "Base/UGColorset.h"


namespace UGC {

class FILEPARSER_API UGFileParseRaster : public UGFileParse  
{
public:
	UGFileParseRaster();
	virtual ~UGFileParseRaster();

public:
	//////////////////////////////////////////////////////////////////////////
	// �������ú���
	//////////////////////////////////////////////////////////////////////////

	//! \brief ���õ���դ�������
	void SetImageName(const UGString& strDatasetImage);

	//! \brief ���õ���դ�����ݵ�����
	void SetGridDataType(UGint nGridDataType);

	//! \brief ���õ���򵼳�Ӱ������ʱ��������Ӱ������ο��ļ�������
	void SetImageGeoRefFileName(const UGString& strImageGeoRefFileName);

	//! \brief ���õ���򵼳�Ӱ������ʱ��������Ӱ������ο��ļ�������
	void SetImageGeoRefFileType(UGint nImageGeoRefFileType);

	//////////////////////////////////////////////////////////////////////////
	// ����ѯ�ʳ������ú���
	//////////////////////////////////////////////////////////////////////////

	//! \brief �Ƿ�ನ��
	UGbool IsMultiBand() const;

	//! \brief �Ƿ���ɨ���д���
	UGbool IsScanline() const;

	//! \brief 	�Ƿ���ɨ�����෴����
	virtual UGbool IsReverse() const;

	//! \brief ���ò��εĸ���
	void SetBandCount(UGint nBandCount);

	//! \brief �õ����εĸ���
	UGint GetBandCount() const;

	//! \brief �������صĸ�ʽ
	void SetPixelFormat(PixelFormat nPixelFormat);
	//! \brief �������صĸ�ʽ
	PixelFormat GetPixelFormat() const;

	//! \brief ����Ӱ����
	void SetWidth(UGint nWidth);
	//! \brief ����Ӱ����
	UGint GetWidth() const;

	//! \brief ����Ӱ��߶�
	void SetHeight(UGint nHeight);
	//! \brief ����Ӱ��߶�
	UGint GetHeight() const;

	//! \brief ���ú���ֿ�����(��������)
	void SetColBlocks(UGint nColBlocks); 
	//! \brief �õ�����ֿ�����(��������)
	UGint GetColBlocks() const;

	//! \brief ��������ֿ�����(��������)
	void SetRowBlocks(UGint nRowBlocks);
	//! \brief �õ�����ֿ�����(��������)
	UGint GetRowBlocks() const;

	//! \brief ����Ӱ���Bounds
	void SetBounds(const UGRect2D& re2Bound);
	//! \brief �õ�Ӱ���Bounds
	UGRect2D GetBounds() const;

	//! \brief ����Ӱ��ֿ�߳�
	void SetIBlockSize(UGint nBlockSize); 
	//! \brief ����Ӱ��ֿ�߳�
	UGint GetIBlockSize() const; 

	//! \brief ���õ�ɫ��
	void SetColorset(const UGColorset& Palette);
	//! \brief �õ���ɫ��
	UGColorset GetColorset() const;

	//! \brief ���õ�������������
	void SetDatasetType(UGint nDatasetType);
	//! \brief �õ��������������
	UGint GetDatasetType() const;

	//! \brief ��������Դ�ĵ�λ��Ӱ��ĵ�λ
	void SetUnit(UGint lUnit);
	//! \brief �õ�����Դ�ĵ�λ��Ӱ��ĵ�λ
	UGint GetUnit() const;

	//! \brief ��ȡդ�����ݵ� nodata
	virtual UGint GetNoValue();
	
	//////////////////////////////////////////////////////////////////////////
	// ��ȥ����
	//////////////////////////////////////////////////////////////////////////
	//! \brief ׼����ʼ��ȡդ������,�ڵ���ReadData֮ǰ�������
	virtual UGbool BeginRead(UGint nIndex = 1);
	//! \brief ��ȡһ��ɨ���е�����
	virtual UGbool ReadScanLine(UGImgScanline& imgScanline, UGint nRowIndex, UGint nBandIndex = 0) {return FALSE;};
	//! \brief ��ȡһ��Block����
	virtual UGbool ReadBlock(UGImgBlock* pImgBlock, UGint nRowBlockIndex, UGint nColBlockIndex, UGint nBandIndex = 0) {return FALSE;};
	//! \brief ������ȡդ������,�ڵ���ReadData֮��������(�ͷŶ���)
	virtual void EndRead();
	
	//////////////////////////////////////////////////////////////////////////
	// д�뺯��
	//////////////////////////////////////////////////////////////////////////
	//! \brief ׼����ʼд����,�ڵ���WriteData֮ǰ�������
	virtual UGbool BeginWrite();
	//! \brief д��һ��ɨ���е�����
	virtual UGbool WriteScanLine(UGint nRowIndex, UGImgScanline& imgScanline) {return FALSE;};
	//! \brief ����д����,�ڵ���WriteData֮��������
	virtual void EndWrite();
	//! \brief ɾ���ļ�������ļ�����ʧ�ܣ�
	virtual void DeleteFile(const UGString& strFileName);

protected:
	//! \brief 	����image���ݼ�ʱ��ָ�����ɵ�Ӱ��ο��ļ�������
	UGString m_strImageGeoRefFileName; 

	//! \brief	����image���ݼ�ʱ��ָ�����ɵ�Ӱ��ο��ļ�������
	UGint m_nImageGeoRefFileType;

	//! \brief	ת��image�ļ�ʱ�����ɵ�image���͵����ݼ�������
	UGString m_strDatasetImage;

	//! \brief 	ת��Ӱ�����ݺ�ÿ��դ����������ͣ������ֽ�����ʾһ��դ�����ݣ�����Ԥ����ĺ�
	UGint m_nGridDataType; 

protected:
	//! \brief 	Ӱ��Ŀ�
	UGint m_nWidth;
	//! \brief 	Ӱ��ĸ�
	UGint m_nHeight;
	//! ����ֿ�����(��������)
	UGint m_nColBlocks;		
	//! ����ֿ�����(��������)
	UGint m_nRowBlocks;
	//! Ӱ���Bounds
	UGRect2D m_rc2Bounds;
	//! \brief 	Ӱ������ظ�ʽ
	UGint m_nPixelFormat;
	//! \brief 	Ӱ���Block��С
	UGint m_nBlockSize;
	//! \brief 	Ӱ��ĵ�ɫ��
	UGColorset m_Colorset;

	//! \brief ����Դ�ĵ�λ��Ӱ��ĵ�λ
	UGint m_nUnit;

	//! \brief 	Ӱ��Ĳ��θ���
	UGint m_nBandCount;
	//! \brief 	Ӱ����������ͣ���8λ��һ��byte
	UGint m_nDatasetType;
	//! \brief 	Ӱ����ձ�ʵ�����
	UGint m_nColorEntryCount;

	//! \brief 	�Ƿ�ನ�εı�־
	UGbool m_bIsMultiBand;
	//! \brief 	�Ƿ���ɨ���У������ǿ�״��
	UGbool m_bIsScanline;
	//! \brief 	�Ƿ���ɨ�����෴����
	UGbool m_bIsReverse;

};

} //namespace UGC

#endif // !defined(AFX_UGFileParseRaster_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_)
