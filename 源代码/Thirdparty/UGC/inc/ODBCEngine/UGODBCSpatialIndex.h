// UGODBCSpatialIndex.h: interface for the UGODBCSpatialIndex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCSPATIALINDEX_H__1BF4DAD3_380B_41A7_9DE4_6E7914AC028C__INCLUDED_)
#define AFX_UGODBCSPATIALINDEX_H__1BF4DAD3_380B_41A7_9DE4_6E7914AC028C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ODBCEngine/UGODBCDatasetVector.h"
namespace UGC{

class UGEXPORT UGODBCSpatialIndex  
{
	friend class UGODBCDatasetVector;
	friend class UGODBCEditRecordset;
	friend class UGSqlDatasetVectorVersion;
public:
	UGODBCSpatialIndex();
	UGODBCSpatialIndex(UGODBCDatasetVector *pDT);
	virtual ~UGODBCSpatialIndex();

public:
	//! \brief �����ռ�����
	//! \param spatial[in] ����������Ҫ�����������Ϣ
	//! \return �ɹ�ΪTRUE,����ΪFALSE.
	//! \remarks
	//! \attention 
	UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);

	//! \brief ���ݵ�ǰ����״̬�ؽ�����
	//! \param
	//! \return �ɹ�ΪTRUE,����ΪFALSE.
	//! \remarks
	//! \attention 
	UGbool ReBuildSpatialIndex();

	//! \brief �����ݵĿռ���������
	//! \param
	//! \return �ɹ�ΪTRUE,����ΪFALSE.
	//! \remarks 
	//! \attention
	UGbool UpdateSpatialIndex();
	
	//! \brief ����ռ�����
	//! \param
	//! \return �ɹ�ΪTRUE,����ΪFALSE.
	//! \remarks 
	//! \attention
	UGbool DropSpatialIndex();
	
	//! \brief �Ƿ���Ҫ�ؽ��ռ�����
	//! \param
	//! \return ��Ҫ����TRUE,����ΪFALSE.
	//! \remarks 
	//! \attention
	UGbool IsSpatialIndexDirty();
	
	//! \brief ���ؿռ�������ļ�¼����Ŀ��Ϊ�Ƿ���Ҫ�ؽ��ռ������ṩ�ο�
	UGint GetDirtyRecordCount();

	//! \brief ��������
	//! \param
	//! \return �ɹ�ΪTRUE,����ΪFALSE.
	//! \remarks 
	//! \attention
	UGbool StatisticIndex(UGDataSource *pDs);

	//! \brief ͼ�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	virtual UGbool LibTileSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption,
		UGdouble dbTolerance);

	//! \brief R�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption		[in]
	virtual UGbool RTreeSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption,
		UGdouble dbTolerance);

	//! \brief �༶���������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	virtual UGbool DynamicSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption,UGdouble dbTolerance);
	
protected:
	//�������������� BuildSpatialIndex �е��ã����ڽ�����ͬ���͵�����

	//! \brief ����R������
	//! \param spatial[in] ����������Ҫ�����������Ϣ
	//! \return �ɹ�ΪTRUE,����ΪFALSE.
	UGbool BuildSpatialIndexRTree(UGSpatialIndexInfo &spatial);
	
	//! \brief ����ͼ������
	//! \param spatial[in] ����������Ҫ�����������Ϣ
	//! \return �ɹ�ΪTRUE,����ΪFALSE.
	//! \attention ���ݼ���Χ�ر�������£��û��Զ��巶Χ�Ƚ�С�п��ܳ����ڴ治��������
	UGbool BuildSpatialIndexTile(UGSpatialIndexInfo &spatial);
	
	//! \brief �����༶��������
	//! \param spatial[in] ����������Ҫ�����������Ϣ
	//! \return �ɹ�ΪTRUE,����ΪFALSE.
	UGbool BuildSpatialIndexDynamic(UGSpatialIndexInfo &spatial);

	//! \brief �����Ĳ�������
	//! \param spatial[in] ����������Ҫ�����������Ϣ
	//! \return �ɹ�ΪTRUE,����ΪFALSE.
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
	UGbool UpdateIndexItem(UGint nID, UGint nEditState, UGGeometry *pGeometry,
									   const UGRect2D &rc2Old, const UGRect2D &rc2New);

private:
	//! \brief				����RTree����Ҷ�ڵ�
	// \param nID			���µļ�¼��ID
	// \param nEditState	�Լ�¼�����ĸ��²���	
	// \param rc2Old		��¼ԭ����Bounds
	// \param rc2New		��¼�µ�Bounds��ֻ��SetGeometryʱrc2Old��rc2New��ͬ
	// \return				���������Ĳ����ɹ����
	UGbool UpdateRTreeItem(	UGint nID, const UGint nEditState, 
						   const UGRect2D &rc2Old, const UGRect2D &rc2New);
	
	//��Щ��UpdateRTreeItem����
	UGbool UpdateRTreeItemAdd(UGint nID, const UGRect2D &rc2New);
	UGbool UpdateRTreeItemDel(UGint nID, const UGRect2D &rc2Old);
	UGbool UpdateRTreeItemSetGeo(UGint nID, const UGRect2D &rc2Old, const UGRect2D &rc2New);

	//ȡ������Geometry��ID�����������R���������ڽ���R������ʱ����
	void GetAllNodeItems(UGDBRTreeNodeItems &NodeItems,UGProgress &Progress,UGString strSort);

	//! \brief ����ͼ��������ͼ����Ϣ
	UGbool UpdateLibVersion(const UGuint dwLibID, const UGint nID, 
		const UGint nEditMode, const UGRect2D &rc2New);

	//! \brief ���¶༶��������
	UGbool UpdateDynamicIdx(UGint nID, const UGint nEditMode, UGGeometry *pGeometry);

	//! \brief ���´��Ĳ�������
	UGbool UpdateQTreeIdx(UGint nID, const UGint nEditMode, const UGRect2D &rc2New);

	//! \brief ����������Ϣ
	UGbool SaveIndexInfo();

	//ͼ�������ռ��ѯ����

	//! \brief ͼ��ID��ѯ
	//! \param pGeo					�����[in]
	//! \param aryInnerLibIDs		�洢����Inner�����ͼ��ID[out]
	//! \param aryMaybeLibTileIDs	�����ȡMaybe�����ͼ��ID[out]
	//! \param aryOuterLibIDs		�洢����Outer�����ͼ��ID[out]
	//! \param aryGeoRg				�洢��Ӧͼ���ü��Ķ����[out]
	//! \param nOption				��ѯѡ��[in]
	UGbool GetQueryLibTileIDs(UGGeometry *pGeo,UGArray<UGint>& aryInnerLibIDs,
		UGArray<UGint>& aryMaybeLibTileIDs,UGArray<UGint>& aryOuterLibIDs,
		UGArray<UGGeoRegion> &aryGeoRg,SpatialQueryOption nOption);
	
	//! \brief ����ID��ѯ����ȡMaybe���ͼ���ڶ���ID
	//! \param pGeo					 �����[in]
	//! \param aryMaybeLibTileIDs	 Maybe�����ͼ��ID[in]
	//! \param aryGeoRg				 Maybe�����ͼ��ID��Ӧ�Ĳü������[in]
	//! \param aryMaybeInnerIDs		 �洢Maybe���ͼ��������Inner��������ID[out]
	//! \param aryMaybeOuterIDs		 �洢Maybe���ͼ��������Outer��������ID[out]
	//! \param aryMaybeIDs		 	 �洢Maybe���ͼ��������Maybe��������ID[out]
	//! \param dbTolerance			 �жϵ���ͬһλ�õ�����
	UGbool GetMaybeIDsInTile(UGGeometry *pGeo,UGArray<UGint>& aryMaybeLibTileIDs,
		UGArray<UGint>& aryMaybeInnerIDs,UGArray<UGGeoRegion> &aryGeoRg,
		UGArray<UGint>& aryMaybeOuterIDs,UGMaybeItems& aryMaybeIDs,UGdouble dbTolerance);

	//! \brief ����ID��ѯ����ȡͼ���ڶ���ID
	//! \param aryQueryLibIDs	ͼ��ID[in]
	//! \param aryIDs  ͼ���ڶ���ID[out]
	UGbool GetIDsInTile(UGArray<UGint>& aryQueryLibIDs,UGArray<UGint>& aryIDs);

	//! \brief R���������ڷ������ID
	//! \param pGeo				�����[in]
	//! \param aryLeafIDs		R��������[in]
	//! \param aryInnerIDs		�洢����inner�Ķ���[out]
	//! \param aryMaybeIDs		�洢����maybe�Ķ���[out]
	//! \param aryIDs			�洢����inner��outer�Ķ���ID[out]
	UGbool GetIDsInLeaf(UGGeometry *pGeo,UGArray<UGint>& aryLeafIDs,
		UGArray<UGint>& aryInnerIDs,UGMaybeItems& aryMaybeIDs,UGArray<UGint>& aryIDs);

	//! \brief ��ѯ�Ĳ�������Ķ���ID
	//! \param pGeo				�����[in]
	//! \param aryInnerIDs		����inner�Ķ���[out]
	//! \param aryMaybeIDs		����maybe�Ķ���[out]
	//! \param aryIDs			�洢����inner��outer�Ķ���ID[out]
	UGbool GetIDsInQTree(UGGeometry *pGeo,UGArray<UGint>& aryInnerIDs,UGMaybeItems& aryMaybeIDs,UGArray<UGint>& aryIDs);

	//! \brief ��ȡouter����ID(ȡ��)
	//! \param aryIDs			����inner��maybe�Ķ���ID[in]
	//! \param aryOuterIDs		����outer�Ķ���ID[out]
	UGbool GetIDsOuter(UGArray<UGint>& aryIDs,UGArray<UGint>& aryOuterIDs);

	//! \brief maybe�����ڷ���
	//��maybe���������ڵ������ϲ�������ü�����μ������ڵĶ���ID(���ֳ�maybe��inner�Ķ���)������Ҳ�ù����ظ���ID
	//! \param pGeo				�����[in]
	//! \param nLevel			����Ĳ���[in]
	//! \param aryGridMaybe		����maybe������[in]
	//! \param aryMaybeIDs		�洢����maybe�Ķ���[out]
	//! \param aryInnerIDs		�洢����inner�Ķ���[out]
	//! \param aryIds			�洢����maybe�����ID[out](��ʱ��)
	UGbool GetMaybeGridIDs(UGGeometry *pGeo,UGint& nLevel,UGArray<UGPoint>& aryGridMaybe,
						UGMaybeItems &aryMaybeIDs,UGArray<UGint> &aryInnerIDs,UGArray<UGint> &aryIds);

// 	//! \brief	��ȡmaybe�����ڶ���
// 	//! \param pGeo					�����[in]
// 	//! \param GridPoint			����x,y[in]
// 	//! \param aryMaybeIDs			����maybe�Ķ���[out]
// 	//! \param aryInnerIDs			����inner�Ķ���[out]
// 	UGbool GetIDsInMaybeGrid(UGGeoRegion *pGeo,UGPoint& GridPoint,
// 						UG_SQ_MAYBEIDS& aryMaybeID,UGArray<UGint>& aryInnerIDs);

	//! \brief	Ϊ�����inner��maybe������Ǵ��뵽��ά���飬��ͨ��������ѯ������㷨��ȡ�����ظ�ID��inner����ID��maybe����ID�ķ���(���������)
	//! \param nLevel				���ڵ������[in]
	//! \param aryGrids				��ѯ���󾭹��������������ϵ�����[in]
	//! \param aryGridMaybe			��ѯ���󾭹���maybe����[in]
	//! \param aryGridInner			��ѯ���󾭹���inner����[in]
	//! \param aryInnerIDsTemp		����inner�Ķ���[out]
	//! \param aryUGMaybeIDs		����maybe�ķ������[out]
	//! \param aryouterIDs			����outer�Ķ���id[out]
	UGbool GetIDsFromMarkGrid(UGbool bOuter,UGint nLevel,UGArray<UGPoint>& aryGrids,UGArray<UGPoint>& aryGridMaybe,UGArray<UGPoint>& aryGridInner,
		UGArray<UGint>& aryInnerIDsTemp,UGArray<UG_MayIDs>& aryUGMaybeIDs,UGArray<UGint>& aryouterIDs);

	//! \brief	��maybe������ü������
	//! \param pGeo						�����[in]
	//! \param aryUGMaybeIDs			maybe������[in]
	//! \param aryMaybeGirdinnerIDs		��Щ����������inner�Ķ���[out]
	//! \param aryMaybeGirdouterIDs		��Щ����������outer�Ķ���[out]
	//! \param aryMaybeIDsTemp			����maybe�Ķ���[out]
	UGbool MaybeIDsClipRegion(UGGeometry *pGeo,UGArray<UG_MayIDs>& aryUGMaybeIDs,UGArray<UGint>& aryMaybeGirdinnerIDs,
		UGArray<UGint>& aryMaybeGirdouterIDs,UGMaybeItems& aryMaybeIDsTemp,UGdouble dbTolerance);
	
	//! \brief	��maybe������ü������
	//! \param aryGridMaybe			��ѯ���󾭹���maybe����[in]
	//! \param aryGridInner			��ѯ���󾭹���inner����[in]
	//! \param aryOuterIDsTemp		����outer�Ķ���[out]
	UGbool GetIDsFromOuterGrid(UGArray<UGPoint>& aryGridMaybe,UGArray<UGPoint>& aryGridInner,UGArray<UGint>& aryOuterIDsTemp);

private:
	UGODBCDatasetVector *m_pDataset;

};
}
#endif // !defined(AFX_UGODBCSPATIALINDEX_H__1BF4DAD3_380B_41A7_9DE4_6E7914AC028C__INCLUDED_)


