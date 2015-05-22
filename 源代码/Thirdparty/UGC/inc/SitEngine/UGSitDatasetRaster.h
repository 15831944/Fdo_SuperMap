// UGSitDatasetRaster.h: interface for the UGSitDatasetRaster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSITDATASETRASTER_H__3EDB907A_EDF4_4CAC_99C1_FF2566D22C16__INCLUDED_)
#define AFX_UGSITDATASETRASTER_H__3EDB907A_EDF4_4CAC_99C1_FF2566D22C16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDatasetRaster.h"
#include "SitEngine/UGSitDataSource.h"

namespace UGC
{

class SITENGINE_API UGSitDatasetRaster  : public UGDatasetRaster
{
	friend class UGSitDataSource;

public:
	UGSitDatasetRaster();
	virtual ~UGSitDatasetRaster();

	virtual UGbool BuildPyramid(UGbool bShhowProgress) {return FALSE;};
	virtual UGbool RemovePyramids() {return FALSE;};

	
	//! \brief  pImgBlock����
	virtual UGbool SaveBlock(UGImgBlock* pImgBlock) {return FALSE;};

	
	//! \brief  �������ݼ���Ϣ
	virtual UGbool SaveInfo(){return FALSE;};
	
	//! \brief  ˢ�����ݼ���Ϣ
	virtual UGbool RefreshInfo() {
		return FALSE;
	}
	
	//! \brief  ����������ʱ��
	virtual UGTime GetDateLastUpdated(){return UGTime(0.0);};
	
	//! \brief  ���ش���ʱ��
	virtual UGTime GetDateCreated(){return UGTime(0.0);};
	
	//! \brief  �жϵ�ǰ���ݼ��Ƿ�ɱ༭
	virtual UGbool CanUpdate(){return FALSE;};
	
	
	//! \brief  �������ݼ���Ӧ����
	virtual UGString GetTableName() {
		return m_RasterInfo.m_strTableName;
	}
	
	//! \brief  ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName){return FALSE;};
	
	UGbool Create(const UGDatasetRasterInfo &rInfo){return FALSE;};
	
	
	//! \brief  ����ָ��������
	virtual UGImgBlock* LoadBlock(UGint nRowBlock,UGint nColBlock);

	//! \brief  �����ݼ�
	virtual UGbool Open();
	
	//! \brief  �ر����ݼ�
	virtual void Close();
	

	//! \brief  ж�������ѷ����ڴ�Ŀ�
	virtual void ReleaseAllBlock();
	
	
	
private:
	UGbool ReleasePyramidDatasets();
	SmTierInfo * m_pTierInfo;
	UGSitDataSource * m_pOrgDataSource;

	
	
};

}

#endif // !defined(AFX_UGSITDATASETRASTER_H__3EDB907A_EDF4_4CAC_99C1_FF2566D22C16__INCLUDED_)
