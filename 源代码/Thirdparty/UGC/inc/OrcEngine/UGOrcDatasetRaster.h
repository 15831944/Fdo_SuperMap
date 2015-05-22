// UGOrcDatasetRaster.h: interface for the UGOrcDatasetRaster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCDATASETRASTER_H__3DF7970F_EE60_4428_A101_DDC3CCE82A39__INCLUDED_)
#define AFX_UGORCDATASETRASTER_H__3DF7970F_EE60_4428_A101_DDC3CCE82A39__INCLUDED_

#include "Engine/UGDatasetRaster.h"
#include "OrcEngine/UGOCIConnection.h"
#include "Base/ugdefs.h"	// Added by ClassView
#include "UGOCICursor.h"
#include "Base/UGThread.h"

namespace UGC {

class ORCENGINE_API UGOrcDatasetRaster : public UGDatasetRaster
{
	friend class UGOrcDataSource;
	
public:
	UGOrcDatasetRaster();
	virtual ~UGOrcDatasetRaster();

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

	//! ע��ѡ����Ϣ
	virtual UGbool RegisterOption(UGint nOption);

	//! ��ע��ѡ����Ϣ
	virtual UGbool UnRegisterOption(UGint nOption);
private:
	UGOCIConnection * GetConnection();

	UGDatasetRaster* Tier(UGint nLevel, UGint lWidth, UGint lHeight, UGDatasetRasterInfo::IBSizeOption eBlockSize, UGint nOptions);

	UGbool ReleasePyramidDatasets();


	//! \brief ����������Ӱ��飬�����ƻ��ڴ�
	//! \return True �ɹ�
	//! \attention ��
	UGbool SaveAllBlocks();	

	void GetImgPyramidValue(PixelFormat ipf, UGbool bIndexedColor, UGuint a,
		UGuint b, UGuint c, UGuint d, UGuint& e);
	
	UGdouble CalcAvgValue(UGdouble a, UGdouble b, UGdouble c, UGdouble d);

	//! �ڲ����������ڴ����鲢��� 
	void CheckError() const;
	
	UGint m_nMaxBlockSize;	
	UGMutex m_nOpenmutex;
};

}

#endif // !defined(AFX_UGORCDATASETRASTER_H__3DF7970F_EE60_4428_A101_DDC3CCE82A39__INCLUDED_)

