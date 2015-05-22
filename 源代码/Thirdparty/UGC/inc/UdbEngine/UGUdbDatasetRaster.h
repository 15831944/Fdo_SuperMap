/*! \file	 UGUdbDatasetRaster.h
 *  \brief	 Oracle Plus UGUdbDatasetRaster
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGUdbDatasetRaster.h,v 1.3 2007/11/06 03:08:13 liwl Exp $
 */

#if !defined(AFX_UGUdbDatasetRaster_H__3DF7970F_EE60_4428_A101_DDC3CCE82A39__INCLUDED_)
#define AFX_UGUdbDatasetRaster_H__3DF7970F_EE60_4428_A101_DDC3CCE82A39__INCLUDED_

#include "Engine/UGDatasetRaster.h"
#include "Base/ugdefs.h"

namespace UGC {

class UDBENGINE_API UGUdbDatasetRaster : public UGDatasetRaster
{
	friend class UGUdbDataSource;
	
	
public:
	UGUdbDatasetRaster();
	UGUdbDatasetRaster(UGDataSource *pDataSource);
	virtual ~UGUdbDatasetRaster();

public:

	//! �����ݼ�
	virtual UGbool Open();

	//! �ر����ݼ�
	virtual void Close();
	
	//! �������ݼ���Ϣ
	virtual UGbool SaveInfo();
	
	//! ˢ�����ݼ���Ϣ
	virtual UGbool RefreshInfo() {
		return FALSE;
	}

	//! ����������ʱ��
	virtual UGTime GetDateLastUpdated();
	
	//! ���ش���ʱ��
	virtual UGTime GetDateCreated();

	//! �жϵ�ǰ���ݼ��Ƿ�ɱ༭
	virtual UGbool CanUpdate();

		
	//! �������ݼ���Ӧ����
	virtual UGString GetTableName() {
		return m_RasterInfo.m_strTableName;
	}

	//! ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName);

	virtual UGbool BuildPyramid(UGbool bShhowProgress);
	virtual UGbool RemovePyramids();

	UGint GetMaxBlockSize() const {
		return m_nMaxBlockSize;
	}

	void SetMaxBlockSize(UGint nMaxBlockSize) {
		m_nMaxBlockSize = nMaxBlockSize;
		SetModifiedFlag();
	}
	UGbool Create(const UGDatasetRasterInfo &rInfo);

	UGImgBlock* LoadBlock(UGint nRowBlock,UGint nColBlock);

	//! ж�������ѷ����ڴ�Ŀ�
	virtual void ReleaseAllBlock();

	//! pImgBlock����
	virtual UGbool SaveBlock(UGImgBlock* pImgBlock);


	virtual UGbool CacheByBlock(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight);

	//! �ж����ݼ��Ƿ�֧��ĳ�ֲ���
	virtual UGbool IsSupport(UGEngAction nAction);


private:

	UGDatasetRaster* Tier(UGint nLevel, UGint lWidth, UGint lHeight, UGDatasetRasterInfo::IBSizeOption eBlockSize, UGint nOptions);

	UGbool ReleasePyramidDatasets();

	void GetImgPyramidValue(PixelFormat ipf, UGbool bIndexedColor, UGuint a,
		UGuint b, UGuint c, UGuint d, UGuint& e);
	
	UGdouble CalcAvgValue(UGdouble a, UGdouble b, UGdouble c, UGdouble d);

	//! �ڲ����������ڴ����鲢��� 
	void CheckError() const;
	
	//! \brief ����������Ӱ��飬�����ƻ��ڴ�
	//! \return True �ɹ�
	//! \attention ��
	UGbool SaveAllBlocks();	

	UGint m_nMaxBlockSize;	

	UGbool m_bPrepared;

	UGDataSource *m_DataSource;


};

}

#endif // !defined(AFX_UGUdbDatasetRaster_H__3DF7970F_EE60_4428_A101_DDC3CCE82A39__INCLUDED_)

