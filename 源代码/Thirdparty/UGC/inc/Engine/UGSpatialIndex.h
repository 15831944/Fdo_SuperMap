/* 
	\file UGSpatialIndex.h
	\brief	�������������һ��
			���������Ĵ������ؽ���ɾ��
			������������֮ǰ�����ݵķ������������������������Լ���������Ӧ��
			���������Ƿ�֧��ĳ�������Ŀ���

	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
*/
	// UGSpatialIndex.h: interface for the UGSpatialIndex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSPATIALINDEX_H__AAA6D3A9_BE41_415A_8BB9_122FF427F2D0__INCLUDED_)
#define AFX_UGSPATIALINDEX_H__AAA6D3A9_BE41_415A_8BB9_122FF427F2D0__INCLUDED_

#include "Base/ugdefs.h"
#include "Engine/UGDatasetVector.h"

namespace UGC {

class ENGINE_API UGSpatialIndex
{
public:
	UGSpatialIndex();
	virtual ~UGSpatialIndex();

public:

	//! \brief ��������
	//! \param *pDataset [in]��
	//! \return
	//! \remarks
	//! \attention 
	UGbool BuildSpatialIndex(UGDatasetVector *pDataset,UGSpatialIndexInfo &spatial);

	//! \brief ���ݵ�ǰ����״̬�ؽ�����
	//! \param *pDataset [in]��
	//! \return
	//! \remarks
	//! \attention 
	UGbool ReBuildSpatialIndex(UGDatasetVector *pDataset);

	//! \brief �����ݵĿռ���������
	//! \param *pDataset [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool UpdateSpatialIndex(UGDatasetVector *pDataset);

	//! \brief ɾ������
	//! \param *pDataset [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool DropSpatialIndex(UGDatasetVector *pDataset);

	//! \brief ������ǰ���������ѷ����������ϵͳ��Ϣͳ�Ʊ���
	//! \param *pDataset [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool StatisticIndex(UGDatasetVector *pDataset);
	
	//! \brief ��ǰ���ݼ��Ƿ������֧��
	//! \param *pDataset [in]��
	//! \param nIdxType [in]��
	//! \return 
	//! \remarks 
	//! \attention 
	UGbool IsSupported(UGDatasetVector *pDataset,IndexType nIdxType);

	//! \brief �����Ƿ�����
	//! \param *pDataset [in]��
	//! \return ��
	//! \remarks TRUE ��ʾ�ࣻ���򣬲���
	//! \attention ��
	UGbool IsSpatialIndexDirty(UGDatasetVector *pDataset);

public:
	UGbool AnalyzeDataset(UGDatasetVector *pDataset,UGSpatialIndexInfo &info);

	UGshort RecommendSpatialIndexLevel(UGDatasetVector *pDataset);

protected:
	UGbool IsNeedBuiltIndex(UGDatasetVector *pDataset);

private:
	UGbool ConfigIndexByDataDistributing(UGDatasetVector *pDataset,UGSpatialIndexInfo &info);
};
}

#endif // !defined(AFX_UGSPATIALINDEX_H__AAA6D3A9_BE41_415A_8BB9_122FF427F2D0__INCLUDED_)
