// UGOrcSpatialIndex.h: interface for the UGOrcSpatialIndex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCSPATIALINDEX_H__E4155113_5D24_478C_8C7D_7A9BAD348D7B__INCLUDED_)
#define AFX_UGORCSPATIALINDEX_H__E4155113_5D24_478C_8C7D_7A9BAD348D7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OrcEngine/UGOrcDatasetVector.h"

namespace UGC{

class UGOrcSpatialIndex  
{
	//��һ��class������linux�±��벻����modified by xielin 
	friend class UGOrcDatasetVector;
	friend class UGOrcEditRecordset;
	friend class UGOrcDatasetVectorVersion;
public:
	UGOrcSpatialIndex();
	UGOrcSpatialIndex(UGOrcDatasetVector *pDT);
	virtual ~UGOrcSpatialIndex();

public:
	//! �����ռ�����
	UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);

	//! \brief ���ݵ�ǰ����״̬�ؽ�����
	//! \param��
	//! \return
	//! \remarks
	//! \attention 
	UGbool ReBuildSpatialIndex();

	//! \brief �����ݵĿռ���������
	//! \param��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool UpdateSpatialIndex();
	
	//! ����ռ�����
	UGbool DropSpatialIndex();
	
	//! �Ƿ���Ҫ�ؽ��ռ�����
	UGbool IsSpatialIndexDirty();
	
	//! ���ؿռ�������ļ�¼����Ŀ��Ϊ�Ƿ���Ҫ�ؽ��ռ������ṩ�ο�
	UGint GetDirtyRecordCount();

	UGbool StatisticIndex(UGDataSource *pDs);
protected:
	//�������������� BuildSpatialIndex �е��ã����ڽ�����ͬ���͵�����

	//! \brief ����R������
	UGbool BuildSpatialIndexRTree(UGSpatialIndexInfo &spatial);
	
	//! \brief ����ͼ������
	UGbool BuildSpatialIndexTile(UGSpatialIndexInfo &spatial);
	
	//! \brief �����༶��������
	UGbool BuildSpatialIndexDynamic(UGSpatialIndexInfo &spatial);

	//! \brief �����Ĳ�������
	UGbool BuildSpatialIndexQTree(UGSpatialIndexInfo &spatial);

	/////////////////////////////// ͼ�������ķ��� ////////////////////////////////////
	//! \brief ע����������������������Lib��
	UGbool PrepareLib();

	//! \brief ͨ��ָ��ͼ���Ĵ�С��������������
	UGbool RegisterLibraryByGridSize(UGdouble dWidth, UGdouble dHeight);

	//! \brief ͨ��ָ�����Ƶ��ֶ���������������
	UGbool RegisterLibraryByField(const UGString &strFieldName);


	/////////////////////////////// R�������ķ��� ////////////////////////////////////
	
	//! \brief R��Ҷ�ӽڵ�ļ���
	UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
	
	//! \brief R��Ҷ�ӽڵ�Ĵ洢
	UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);

	UGbool ExtractLeafData(const UGRectUInt& SearchBounds, 
		UGArray<UGint>& aryItemIDs, 
		UGArray<UGint>& aryCertainLeafIDs,
		UGArray<UGRectUInt> &aryCertainBounds,
		UGArray<UGint>& aryMaybeLeafIDs,
		UGArray<UGRectUInt> &aryMaybeBounds,
		UGbool bFuzzy,
		UGdouble dGranule);


	//! \brief �༭��������ĸ������, pGeometry ֻ�ڶ༶��������ʱ����ǿգ���������NULL
	UGbool UpdateIndexItem(UGint nID, const UGint nEditState, UGGeometry *pGeometry,
										   const UGRect2D &rc2Org, const UGRect2D &rc2New);

	//! \brief ͼ�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
    UGbool LibTileSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption, UGdouble dbTolerance);

	UGbool RTreeSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, UGdouble dbTolerance);

	UGbool DynamicSpatialQuery(UGGeometry *pGeo, 
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs, 
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, UGdouble dbTolerance);

	UGbool ExtractLibIDs(UGGeometry *pGeo,
		UGArray<UGint> &aryLibInnerIDs, UGArray<UGint> &aryLibMaybeIDs,
		UGArray<UGGeoRegion*> &aryClipGeo, UGArray<UGGeoLine*> &aryClipLines,
		UGArray<UGint> &aryLibOuterIDs, SpatialQueryOption nOption);

	//! \brief ����nOption����ͼ��IDs aryLibIDs ����ȡ�����IDs 
	//! \param aryClipRegions ���ü�����LibTile�������,��ά����ʹ��[in]
	//! \param aryClipLines ��LibTile�ü�����pGeo�߶���,һά����ʹ��[in]
	//! \param aryLibIDs	[in]
	//! \param aryIDs	[out]
	//! \param nOptionָʾ�����aryLibIDs��Inner��Maybe����Outer��	[in]
	UGbool ExtractMaybeIDsByLibIDs(UGGeometry *pGeo,UGArray<UGGeoRegion*> &aryClipRegions, 
		UGArray<UGGeoLine*> &aryClipLines,UGArray<UGint> aryLibIDs, 
		UGArray<UGint> &aryInnerIDs,UGMaybeItems &aryMaybeIDsStruct,UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption, UGdouble dbTolerance);

	UGbool ExtractCertainIDsByLibIDs(UGArray<UGint> aryLibIDs,UGArray<UGint> &aryCertainIDs);

	//! \brief R�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryLeafIDs  [in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	UGbool ExtractIDsByLeafIDs(UGGeometry *pGeo, UGArray<UGint> aryLeafIDs, 
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption);

	//���������ռ��ѯ
	//! \brief ���������ռ��ѯ:��ȡ����aryGrids�����ж����ID��GX��GY
	//! \param aryGrids ��������[in]
	//! \param aryIDs ������ID�Ǿ�������ģ����� [out]
	//! \param aryGX [out]
	//! \param aryGY [out]
	UGbool ExtractIDsByGrids(UGArray<UGPoint> &aryGrids, UGArray<UGint> &aryIDs, 
		UGArray<UGint> &aryGX,UGArray<UGint> &aryGY);

	//���������ռ��ѯ
	//! \brief ���������ռ��ѯ:��ȡ����aryGrids�����ж����ID,�ڽ���Outer��ѯʱ����
	//! \param aryGrids ��������[in]
	//! \param aryIDs ������ID��û�о������򣬵���Ψһ�� [out]
	UGbool ExtractIDsByGrids(UGArray<UGPoint> &aryGrids, UGArray<UGint> &aryIDs);

	//! \brief ���������ռ��ѯ:ȥ���ظ�ID��������ȫInner �� IDs��������Maybe��
	//! \param pArry ��������Tag���� [in]
	//! \param nSize pArry�ĳ��� [in]
	//! \param pntOffset����Tag����ʼ�� [in]
	//! \param aryIDs [in]
	//! \param aryGX [in]
	//! \param aryGY [in]
	//! \param aryInnerIDs [out]
	//! \param aryUGMaybeIDs [out]
	UGbool FilterIDs(UGint *pArry, UGint nHeight, UGint nWidth, UGPoint pntOffset, UGArray<UGint> &aryIDs, 
		UGArray<UGint> &aryGX,UGArray<UGint> &aryGY,
		UGArray<UGint> &aryInnerIDs, UGArray<UG_MayIDs> &aryUGMaybeIDs,UGArray<UGint> &aryOuterIDs);

	//! \brief ���������ռ��ѯ: aryUGMaybeIDs ���ǰ����ӷ���ģ���ÿ���е�ID���н�һ���ж�
	//! \param pGeo ��ѯ�Ŀռ���� [in]
	//! \param aryUGMaybeIDs ID���� aryUGMaybeIDs[i] �е�i��ʾ��i������ [in]
	//! \param aryInnerIDs [out]
	//! \param aryMaybeIDs [out]
	//! \param aryOuterIDs [out]
	//! \param nOption [in]
	UGbool ExtractGridMaybeSubIDs(UGGeometry *pGeo, UGArray<UG_MayIDs> &aryUGMaybeIDs,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,UGArray<UGint> &aryOuterIDs, 
		SpatialQueryOption nOption, UGdouble dbTolerance);

	UGbool ExtractGridMaybeIDs(UGGeometry *pGeo, UGint nLevel, UGArray<UGPoint>& aryGridMaybe,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,UGArray<UGint> &aryOuterIDs, 
		SpatialQueryOption nOption);

	UGbool ExtractGridMaybeSubIDs(UGGeometry *pGeo,UGArray<UGPoint>& aryGridMaybe,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,UGArray<UGint> &aryOuterIDs, 
		SpatialQueryOption nOption);

	//! \brief R�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryGridInner  [in]
	//! \param aryIDs  [out]
	UGbool ExtractGridInnerIDs(UGArray<UGPoint>& aryGridInner,UGArray<UGint> &aryIDs);
private:
	//! \brief				����RTree����Ҷ�ڵ�
	// \param nID			���µļ�¼��ID
	// \param nEditState	�Լ�¼�����ĸ��²���	
	// \param rc2Org		��¼ԭ����Bounds
	// \param rc2Des		��¼�µ�Bounds��ֻ��SetGeometryʱrc2Org��rc2Dest��ͬ
	// \return				���������Ĳ����ɹ����
	UGbool UpdateRTreeItem(	UGint nID, const UGint nEditState, 
						   const UGRect2D &rc2Org, const UGRect2D &rc2New);
	
	//��Щ��UpdateRTreeItem����
	UGbool UpdateRTreeItemAdd(UGint nID, const UGRect2D &rc2New);
	UGbool UpdateRTreeItemDel(UGint nID, const UGRect2D &rc2Org);
	UGbool UpdateRTreeItemSetGeo(UGint nID, const UGRect2D &rc2Org, const UGRect2D &rc2New);

	//ȡ������Geometry��ID�����������R���������ڽ���R������ʱ����
	void GetAllNodeItems(UGDBRTreeNodeItems &NodeItems,UGProgress *pProgress,UGString strSort);

	//! \brief ����ͼ��������ͼ����Ϣ
	UGbool UpdateLibVersion(const UGuint dwLibID, const UGint nID, 
		const UGint nEditMode, const UGRect2D &rc2New);

	//! \brief ���¶༶��������
	UGbool UpdateDynamicIdx(UGint nID, const UGint nEditMode, UGGeometry *pGeometry);

	//! \brief ���´��Ĳ�������
	UGbool UpdateQTreeIdx(UGint nID, const UGint nEditMode, const UGRect2D &rc2New);

	//! \brief ����������Ϣ
	UGbool SaveIndexInfo();

private:
	UGOrcDatasetVector *m_pDataset;
};

}
#endif // !defined(AFX_UGORCSPATIALINDEX_H__E4155113_5D24_478C_8C7D_7A9BAD348D7B__INCLUDED_)
