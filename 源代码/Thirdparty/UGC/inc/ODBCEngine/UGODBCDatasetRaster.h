// UGODBCDatasetRaster.h: interface for the UGODBCDatasetRaster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCDATASETRASTER_H__07D60798_A059_496F_91CB_3371625C598D__INCLUDED_)
#define AFX_UGODBCDATASETRASTER_H__07D60798_A059_496F_91CB_3371625C598D__INCLUDED_

#include "Engine/UGDatasetRaster.h"
#include "ODBCEngine/UGODBCConnection.h"

namespace UGC
{
class UGEXPORT UGODBCDatasetRaster : public UGDatasetRaster
{
public:
	UGODBCDatasetRaster();
	virtual ~UGODBCDatasetRaster();

public:
	//! \brief  �����ݼ�
	virtual UGbool Open();

	//! \brief  �ر����ݼ�
	virtual void Close();
	
	//! \brief  �������ݼ���Ϣ
	virtual UGbool SaveInfo();
	
	//! \brief  ˢ�����ݼ���Ϣ
	virtual UGbool RefreshInfo();

	//! \brief  ����������ʱ��
	virtual UGTime GetDateLastUpdated();

	//! \brief  ���ش���ʱ��
	virtual UGTime GetDateCreated();
	
	//! \brief  �������ݼ���Ӧ����
	virtual UGString GetTableName();
	
	//! \brief  ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName);

	//! \brief ����������
	//! \param��bShhowProgress���Ƿ���ʾ������
	//!  \return �����ɹ�ΪTrue,����False
	virtual UGbool BuildPyramid(UGbool bShhowProgress);
	//! \brief ɾ��������
	virtual UGbool RemovePyramids();

	//! \brief  ����ָ��������
	//! \param��nRowBlock ����������
	//! \param��nColBlock ����������
	virtual UGImgBlock* LoadBlock(UGint nRowBlock,UGint nColBlock);

	//! \brief  pImgBlock����
	virtual UGbool SaveBlock(UGImgBlock* pImgBlock);

	//! \brief block�Ļ���
	//! \param nLeft,nTop,nWidth,nHeightȷ��һ��Bounds
	virtual UGbool CacheByBlock(UGint nLeft,UGint nTop, UGint nWidth,UGint nHeight);

	//! ж�������ѷ����ڴ�Ŀ�
	virtual void ReleaseAllBlock();

	//! ע��ѡ����Ϣ
	virtual UGbool RegisterOption(UGint nOption);

	//! ��ע��ѡ����Ϣ
	virtual UGbool UnRegisterOption(UGint nOption);
public:
	//! \brief���������Ӱ����ֵ
	//! \param��nMaxBlockSize��[in]
	void SetMaxBlockSize(UGint nMaxBlockSize);

	//! \brief����ȡ���Ӱ����ֵ
	UGint GetMaxBlockSize();

	//! \brief ��ȡ����
	UGODBCConnection * GetConnection() const;
protected:

	//! \brief ɾ�����������ݼ�
	UGbool ReleasePyramidDatasets();

	//! \brief �������������ݼ���
	UGDatasetRaster* Tier(UGint nLevel, UGint lWidth, UGint lHeight, UGDatasetRasterInfo::IBSizeOption eBlockSize, UGint nOptions);
	//! \brief ����ƽ��ֵ
	UGdouble CalcAvgValue(UGdouble a, UGdouble b,UGdouble c,UGdouble d);

	UGbool SaveAllBlocks();
protected:
	UGint m_nMaxBlockSize;
	UGbyte *m_pTempData;
	UGint m_nTempDataSize;
	UGMutex m_nOpenMutex;
};

}

#endif // !defined(AFX_UGODBCDATASETRASTER_H__07D60798_A059_496F_91CB_3371625C598D__INCLUDED_)
