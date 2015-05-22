//////////////////////////////////////////////////////////////////////////
//!  \file UGUdbSpatialIndex.h
//!  \brief UGUdbSpatialIndex ��Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br>
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGUDBSPATIALINDEX_H__EFA5DF23_E7FE_439D_A1D9_C6885B0183C6__INCLUDED_)
#define AFX_UGUDBSPATIALINDEX_H__EFA5DF23_E7FE_439D_A1D9_C6885B0183C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UdbEngine/UGUdbDatasetVector.h"

namespace UGC{

class UGUdbSpatialIndex  
{
	friend class UGUdbDatasetVector;
	friend class UGUdbEditRecordset;

public:
	UGUdbSpatialIndex();
	UGUdbSpatialIndex(UGUdbDatasetVector *pDT);
	virtual ~UGUdbSpatialIndex();
	
public:
	//! \brief �����ռ�������
	//! \param spatial �ռ�������Ϣ������,����Ϣ��¼�����������ͼ���Ҫ����[in]��
	//! \return �Ƿ�ɹ������������ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �˺����ǶԴ�����ͬ�����ķ�֧������
	UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);

	//! \brief ���ݵ�ǰ����״̬�ؽ�������
	//! \return �Ƿ�ɹ��ؽ��������ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool ReBuildSpatialIndex();

	//! \brief �����ݵĿռ��������¡�
	//! \return �Ƿ�ɹ������������ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �Ƿ��������������������ռ�ܼ�¼���ı����Ƿ�ﵽ�ٽ�ֵ��������
	UGbool UpdateSpatialIndex();
	
	//! \brief ����ռ�������
	//! \return �Ƿ�ɹ�����������ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool DropSpatialIndex();
	
	//! \brief �Ƿ���Ҫ�ؽ��ռ�������
	//! \return ��Ҫ�ؽ���������TRUE�����򷵻�FALSE��
	//! \remarks ������������ռ������ȷ����
	UGbool IsSpatialIndexDirty();
	
	//! \brief �õ��ռ�������ļ�¼����Ŀ��
	//! \return �ռ�������ļ�¼����Ŀ��
	//! \remarks Ϊ�Ƿ���Ҫ�ؽ��ռ������ṩ�ο����Ƿ���TRUE���񷵻�FALSE��
	UGint GetDirtyRecordCount();

	//! \brief ͳ�������������һЩ������
	//! \param pDs ����Դָ��[in]��
	//! \return ��ͳ�Ƴɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool StatisticIndex(UGDataSource *pDs);
protected:
	//�������������� BuildSpatialIndex �е��ã����ڽ�����ͬ���͵�����

	//! \brief ����R��������
	//! \param spatial �ռ�������Ϣ������[in]��
	//! \return �Ƿ�ɹ������������ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool BuildSpatialIndexRTree(UGSpatialIndexInfo &spatial);
	
	//! \brief ����ͼ��������
	//! \param spatial �ռ�������Ϣ������[in]��
	//! \return �Ƿ�ɹ������������ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool BuildSpatialIndexTile(UGSpatialIndexInfo &spatial);
	
	//! \brief �����༶��������
	//! \param spatial �ռ�������Ϣ������[in]��
	//! \return �Ƿ�ɹ������������ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool BuildSpatialIndexDynamic(UGSpatialIndexInfo &spatial);

	//! \brief �����Ĳ�������
	//! \param spatial �ռ�������Ϣ������[in]��
	//! \return �Ƿ�ɹ������������ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool BuildSpatialIndexQTree(UGSpatialIndexInfo &spatial);

	/////////////////////////////// ͼ�������ķ��� ////////////////////////////////////
	
	//! \brief ע����������������������Lib��
	//! \return �Ƿ�ɹ�����Lib���ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool PrepareLib();

	//! \brief ͨ��ָ��ͼ���Ĵ�С����������������
	//! \param dWidth ͼ���Ŀ��[in]��
	//! \param dHeight ͼ���ĸ߶ȶ�[in]��
	//! \return �Ƿ�ɹ����������������ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool RegisterLibraryByGridSize(UGdouble dWidth, UGdouble dHeight);

	//! \brief ͨ��ָ�����Ƶ��ֶ�����������������
	//! \param strFieldName ָ�����Ƶ��ֶ�[in]��
	//! \return �Ƿ�ɹ����������������ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool RegisterLibraryByField(const UGString &strFieldName);

	/////////////////////////////// R�������ķ��� ////////////////////////////////////
	
	//! \brief R��Ҷ�ӽڵ�ļ��ء�
	//! \param nID �ڵ�ID��[in]��
	//! \param stream �ڵ��Ӧ��������[out]��
	//! \return Ҷ�ӽڵ���Ĵ�С(�ֽ�)��
	UGint LoadRTreeLeaf(UGint nID,UGStream &stream);	
	
	//! \brief R��Ҷ�ӽڵ�Ĵ洢��
	//! \param nID �ڵ�ID��[in]��
	//! \param stream �ڵ��Ӧ��������[in]��
	//! \return �Ƿ�ɹ����������������ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);	

	//! \brief ��ȡҶ�ڵ����ݡ�
	//! \param SearchBounds ѡ������[in]��
	//! \param aryItemIDs ��ȡ���ĺ��ʵĵ㼯[out]��
	//! \param aryCertainLeafIDs ȷ����ѡ����ڵ�Ҷ�ڵ�ID����[in]��
	//! \param &aryCertainBounds ȷ����ѡ����ڵĶ����������Χ����[in]��
	//! \param aryMaybeLeafIDs ������ѡ����ڵ�Ҷ�ڵ�ID����[in]��
	//! \param &aryMaybeBounds ������ѡ����ڵĶ����������Χ����[in]��
	//! \param bFuzzy �Ƿ�ģ����ѯ[in]��
	//! \param dGranule ��ѯ������[in]��
	//! \return �Ƿ���ȡҶ�ڵ����ݣ��ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool ExtractLeafData(const UGRectUInt& SearchBounds, 
		UGArray<UGint>& aryItemIDs, 
		UGArray<UGint>& aryCertainLeafIDs,
		UGArray<UGRectUInt> &aryCertainBounds,
		UGArray<UGint>& aryMaybeLeafIDs,
		UGArray<UGRectUInt> &aryMaybeBounds,
		UGbool bFuzzy,
		UGdouble dGranule);	

	//! \brief ���¶������ı༭��
	//! \param nID ���µļ�¼��ID[in]��
	//! \param nEditState �Լ�¼�����ĸ��²���[in]��
	//! \param pGeometry ���ζ���ָ��[in]��
	//! \param rc2Org �༭ǰ�ı߽�[in]��
	//! \param rc2New �༭��ı߽�[in]��
	//! \return �Ƿ�ɹ����±༭���ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �༭��������ĸ�����ڡ�
	//! \attention pGeometry ֻ�ڶ༶��������ʱ����ǿգ���������NULL��
	UGbool UpdateIndexItem(UGint nID, const UGint nEditState, 
		UGGeometry *pGeometry,const UGRect2D &rc2Org, const UGRect2D &rc2New);	

private:

	//! \brief ����RTree����Ҷ�ڵ㡣
	//! \param nID ���µļ�¼��ID[in]��
	//! \param nEditState �Լ�¼�����ĸ��²���[in]��
	//! \param &rc2Org ��¼ԭ����Bounds[in]��
	//! \param &rc2New ��¼�µ�Bounds��ֻ��SetGeometryʱrc2Org��rc2Dest��ͬ[in]��
	//! \return ���������Ĳ����ɹ����
	UGbool UpdateRTreeItem(	UGint nID, const UGint nEditState, 
						   const UGRect2D &rc2Org, const UGRect2D &rc2New);	
	
	//��Щ��UpdateRTreeItem����

	//! \brief ����R����������ӱ༭��
	//! \param nID ���µļ�¼��ID[in]��
	//! \param rc2New �¼�¼������[in]��
	//! \return �Ƿ�ɹ����±༭���ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool UpdateRTreeItemAdd(UGint nID, const UGRect2D &rc2New);

	//! \brief ����R��������ɾ���༭��
	//! \param nID ���µļ�¼��ID[in]��
	//! \param rc2Org ԭ��¼������[in]��
	//! \return �Ƿ�ɹ����±༭���ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool UpdateRTreeItemDel(UGint nID, const UGRect2D &rc2Org);	

	//! \brief ����R���������ƶ��༭��
	//! \param nID ���µļ�¼��ID[in]��
	//! \param &rc2Org ԭ��¼������[in]��
	//! \param &rc2New �¼�¼������[in]��
	//! \return �Ƿ�ɹ����±༭���ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool UpdateRTreeItemSetGeo(UGint nID, const UGRect2D &rc2Org, const UGRect2D &rc2New);	

	//! \brief �����ݱ���ȡ������Geometry��ID�����������R��������
	//! \param NodeItems �ڵ�Ԫ�ؼ�����[in]��
	//! \param strSort �����ֶ�[in]��
	//! \attention ���ڽ���R������ʱ���á�
	void GetAllNodeItems(UGDBRTreeNodeItems &NodeItems,UGString strSort);	

	//! \brief ����ͼ��������ͼ����Ϣ��
	//! \param dwLibID ͼ��������ID��[in]��
	//! \param nID ���µļ�¼��ID[in]��
	//! \param nEditMode �Լ�¼�����ĸ��²���[in]��
	//! \param rc2New �¼�¼������[in]��
	//! \return �Ƿ�ɹ����±༭���ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool UpdateLibVersion(const UGuint dwLibID, const UGint nID, 
		const UGint nEditMode, const UGRect2D &rc2New);	

	//! \brief ���¶༶��������
	//! \param nID ���µļ�¼��ID[in]��
	//! \param nEditMode �Լ�¼�����ĸ��²���[in]��
	//! \param *pGeometry ���ζ����ָ��[in]��
	//! \return �Ƿ�ɹ����±༭���ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool UpdateDynamicIdx(UGint nID, const UGint nEditMode, UGGeometry *pGeometry);

	//! \brief ���´��Ĳ�������
	//! \param nID ���µļ�¼��ID[in]��
	//! \param nEditMode �Լ�¼�����ĸ��²���[in]��
	//! \param rc2New �¼�¼������[in]��
	//! \return �Ƿ�ɹ����±༭���ɹ�����TRUE��ʧ�ܷ���FALSE��
	UGbool UpdateQTreeIdx(UGint nID, const UGint nEditMode, const UGRect2D &rc2New);

	//! \brief ����������Ϣ
	UGbool SaveIndexInfo();

private:
	//! \brief �����������������ݼ�ָ�롣
	UGUdbDatasetVector *m_pDataset;
};

}
#endif // !defined(AFX_UGUDBSPATIALINDEX_H__EFA5DF23_E7FE_439D_A1D9_C6885B0183C6__INCLUDED_)
