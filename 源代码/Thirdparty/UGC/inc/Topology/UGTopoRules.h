/* 
	\file UGTopoRulesCheck.h
	\brief ���˹�����
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGTOPORULESCHECK_H
#define UGTOPORULESCHECK_H

#include "Engine/UGTopoDataset.h"
#include "Topology/UGTopoOperators.h"
#include "Topology/UGTopoSpatialQuery.h"

namespace UGC {

class TOPOLOGY_API UGTopoRulesCheck
{
public:
	UGTopoRulesCheck();
	virtual ~UGTopoRulesCheck();
	
	//! \brief ��������
	/**
	 \param		dInterval	���õ�����
	 \return	���óɹ�����TRUE���޴��󷵻�FALSE
	 \remarks	��dInterval<EP,�����Ӷ�����ΪEP
	*/
	void SetInterval(UGdouble dInterval);
	
	//! \brief ��ȡ�����õ�����
	/**
	 \param		dInterval	���õ�����
	 \return	��������ֵ
	 \remarks	
	*/
	UGdouble GetInterval();
	
	//! \brief ����Ԥ�����㲶׽
	/**
	  \param	arrDTPricision		���ݼ�ָ���Լ�������Ϣ����
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	�����ڵ㡢�ߡ������ݼ�
	*/
	UGbool TopoIniNodeSnap(UGArray<UGTopoDTPricision> &arrDTPricision);
	
	//! \brief ����Ԥ������뽻��
	/**
	  \param	arrpDatasets		���ݼ�ָ������
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	�����ڵ㡢�ߡ������ݼ�
	*/
	UGbool TopoIniIntersectPnt(UGArray<UGDatasetVector*>arrpDatasets);
	
	//! \brief ����Ԥ���������ε�����ϵ
	/**
	  ��֤���Ӷ��󵺡������������˳��˳����ʱ������
	  \param	arrpDatasets		���ݼ�ָ������
	 \return	�����Ϸ�����TRUE��	�޴��󷵻�FALSE
	 \remarks	�����������ݼ�
	*/
	UGbool TopoIniCheckPolygon(UGArray<UGDatasetVector*>arrpDatasets);
	
	//! \brief ���������������
	/**
	ͬһ���ݼ����໥�����Ķ���
	 \param		pDTRegion			�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionOverlap(UGRecordset *pRecordset, UGArray<UGint> &arrIDs, UGArray<UGint> &arrCheckIDs);
	
	//! \brief ���������������
	/**
	������pDTRegion��pDTOverlap�໥�����Ķ���
	 \param		pDTRegion			�����ݼ�ָ��
	 \param		pDTOverlap			�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionOverlap(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs, 
									UGArray<UGint> &arrCheckIDs);
	
	//! \brief ���������ݼ����ڲ���϶(����߽�)
	/**
	 \param		pDTRegion			�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionGaps(UGRecordset *pRecordset, UGArray<UGGeoLine*> &arrpGeoLines);
	
	//! \brief ����û�б���ȫ���ǵ������
	/**
	����pDTRegion��û�б�pDTCover�ڵĶ�����ȫ���ǵĶ���,�����Ǽ������󸲸�һ������
	 \param		pDTRegion			�����ݼ�ָ��
	 \param		pDTCover			�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionNotCovered(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs, 
									UGArray<UGGeoRegion*> &arrpGeoRegion);
	
	//! \brief ����û�б���ȫ���ǵ������
	/**
	pDTRegion�еĶ�����pDTCover�еĶ��������ȫ���า��
	 \param		pDTRegion			�����ݼ�ָ��
	 \param		pDTCover			�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionNotCoveredEach(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs,
										UGArray<UGGeoRegion*> &arrpGeoRegion);
	
	//! \brief ����û�б���ȫ�����������
	/**
	pDTRegion�е�ÿ���������뱻pDTContain�е�ĳ����������
	 \param		pDTRegion			�����ݼ�ָ��
	 \param		pDTContain			�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionNotContained(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs);
	
	//! \brief ���ҳ��ڲ�û�е�������
	/**
	 \param		pDTRegion			�����ݼ�ָ��
	 \param		pDTPoint			�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	������ڱ������ٰ���һ���㣬������Ǵ��������
	*/
	UGbool TopoCheckRegionNotContainPoint(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs);
	
	//! \brief �������ݼ����໥�����Ķ���
	/**
	 \param		pDTLine				�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineOverlap(UGRecordset *pRecordset, UGArray<UGint> &arrIDs, UGArray<UGint> &arrCheckIDs);
	
	//! \brief �������ݼ����Խ����Ķ���
	/**
	 \param		pDTLine				�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineOverlapSelf(UGRecordset *pRecordset, UGArray<UGint> &arrIDs);
	
	//! \brief �����ݼ�֮�䲻�����໥�����Ķ���
	/**
	��pDTLine�в����pDTOverlap�ж������ص����ֵ��߶���
	 \param		pDTLine			�����ݼ�ָ��
	 \param		pDTOverlap			�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineOverlap(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs, 
								UGArray<UGint> &arrCheckIDs);
	
	//! \brief �������ཻ��ϵ���߶���
	/**
	  �����ָཻ����������֮����ڲ��ཻ��Ҳ���ǲ�����������ĳ���ߵĶ˵�������
	  ��������֮�����ص������
	 \param		pDTLine				�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineIntersect(UGRecordset *pRecordset, UGArray<UGint> &arrIDs);
	
	//! \brief ���������ཻ��ϵ���߶���
	/**
	  ���ཻ�����ڲ��������ڲ������������
	 \param		pDTLine				�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineIntersectSelf(UGRecordset *pRecordset, UGArray<UGint> &arrIDs);
	
	//! \brief ���������ཻ��Ӵ���ϵ���߶���
	/**
	  ��Intersect��ȣ�������������˱߽���ڲ��ཻ�����
	 \param		pDTLine				�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineIntersectORTouch(UGRecordset *pRecordset, UGArray<UGint> &arrIDs);
	
	//! \brief ��������������߶���
	/**
	 \param		pDTLine				�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineDangleNode(UGRecordset *pRecordset, UGArray<UGint> &arrIDs, UGArray<UGPoint2D> &arrpnts);
	
	//! \brief ��������α�����߶���
	/**
	 \param		pDTLine				�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckLinePseudoNode(UGRecordset* pRecordset, UGArray<UGint> &arrIDs, UGArray<UGPoint2D> &arrpnts);
	
	//! \brief �����˵�û�б��㸲�ǵ��߶���
	/**
	 \param		pDTLine				�����ݼ�ָ��
	 \param		pDTPoint			�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineEndPointNotCovered(UGRecordset* pRecordset, UGRecordset* pRSCheck, UGArray<UGint> &arrIDs, 
											UGArray<UGPoint2D> &arrpnts);
	
	//! \brief ����û�б�����ȫ�����ĵ����
	/**
	 \param		pDTPoint			�����ݼ�ָ��
	 \param		pDTRegion			�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	������ı߽���Ҳ�����
	*/
	UGbool TopoCheckPointNotContained(UGRecordset* pRecordset, UGRecordset* pRSCheck, UGArray<UGint> &arrIDs);
	
	//! \brief ����û�б��ߵĶ˵㸲�ǵĵ����
	/**
	 \param		pDTPoint			�����ݼ�ָ��
	 \param		pDTLine				�����ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	
	*/
	UGbool TopoCheckPointNotCoveredByEndPoint(UGRecordset* pRecordset, UGRecordset* pRSCheck, UGArray<UGint> &arrIDs);
	
	//! \brief ����pDataset�ж���ı߽�û�б�pDTCover�ж���ı߽���ȫ���ǵĶ���
	/**
	 \param		pDataset			���ݼ�ָ��
	 \param		pDTCover			���ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	pDataset�����ǵ㡢�ߡ������ݼ���pDTCover�����ߡ������ݼ�
	*/
	UGbool TopoCheckBoundaryNotCovered(UGRecordset* pRecordset, UGRecordset* pRSCheck, UGArray<UGint> &arrIDs);
	
	//! \brief ����pDataset�еĸ��϶���
	/**
	  ������Щ������Ҫ��֤�ڲ������и��϶���,���ǿ���ͨ�����������м��
	  \param	UGTopoDTPricision	���ݼ�ָ��
	 \return	�����Ϸ�����TRUE���޴��󷵻�FALSE
	 \remarks	�������ߡ������ݼ�
	*/
	UGbool TopoCheckMultiPart(UGRecordset *pRecordset, UGArray<UGint> &arrIDs);
	
private:
	
	UGdouble m_dInterval;
	UGGeoRegion *m_pGeoDirtyArea;
	UGTopoOperators m_TopoOperators;
	UGTopoSpatialQuery m_TopoSpatialQuery;
	
	UGbool GetObjectIDs(TopoGridEnv &TopoGridUnit, UGRecordset* pRecordset, UGArray<UGint> &arrIDs, UGArray<UGint> &arrCheckIDs);
	/*!	\brief	���ֲ���\n	
*	\param nValue		Ҫ��ѯ��ֵ
*	\param pData		����ָ��
*	\param nCount		���ݳ���
  *	\return	 ����nValue��pData��λ���������������򷵻�-1��
  *	\remarks pData�����Ѿ��ź���
	*/
	UGint FindIndex(UGint nValue, UGint* pData, UGint nCount);
	UGbool GetSnapSegment(UGRect2D& rcBounds, UGArray<UGRecordset*> &arrpRecordset, 
							UGArray<UGTopoGridUnitNodesEx*> &parrArcIntersetPoints,
							UGArray<UGPoint2D> &pIntersetPoints, UGArray<UGint*> &arrpIDs, 
							UGArray<UGint> &arrPricision);
	UGbool GetSnapPnt(UGRect2D& rcBounds, UGArray<UGRecordset*> &arrpRecordset, 
						UGArray<UGTopoGridUnitNodesEx*> &parrArcIntersetPoints,
						UGArray<UGPoint2D> &pIntersetPoints, UGArray<UGint*> &arrpIDs, 
						UGArray<UGint> &arrPricision);
	UGbool GetIntersectPnt(UGRect2D& rcBounds, UGArray<UGRecordset*> &arrpRecordset, 
							UGArray<UGTopoGridUnitNodesEx*> &parrArcIntersetPoints,
							UGArray<UGPoint2D> &pIntersetPoints, UGArray<UGint*> &arrpIDs);
	UGbool TopoIniVertexSnapSegment(UGArray<UGDatasetVector*>parrDatasets, UGArray<UGint>arrPricision);
	UGbool TopoIniVertexSnapVertex(UGArray<UGDatasetVector*>parrDatasets, UGArray<UGint>arrPricision);
	UGbool RegionsCovered(UGDatasetVector *pDTRegion, UGDatasetVector *pDTCover);
	UGbool RegionsOverlap(UGDatasetVector *pDTRegion, UGDatasetVector *pDTOverlap);
	UGbool RegionsOverlap(UGDatasetVector *pDTRegion);
	UGbool RegionGaps(UGDatasetVector *pDTRegion);
	UGbool PntCoverByLine(UGDatasetVector *pDatasetPoint, UGDatasetVector *pDTLine);
	UGbool EndPointCoverByPnt(UGDatasetVector *pDTLine, UGDatasetVector *pDatasetPoint);
	UGbool PointCoverPoint(UGPoint2Ds &arrPoint1, UGPoint2Ds &arrPoint2, UGRect2D &rcBound, 
							UGArray<UGint> &arrPointIndex);
	UGbool ContainPiont(UGDatasetVector *pDatasetRegion, UGDatasetVector *pDatasetPoint);
	UGbool LineBeCoverByLine(UGDatasetVector *pDatasetLine1, UGDatasetVector *pDatasetLine2, UGbool bCover);
	UGbool NotOverlap(UGDatasetVector *pDTLine, UGbool bSelf);
	UGbool NotIntersect(UGDatasetVector *pDTLine, UGbool bSelf);
	
	UGbool PointCoverPoint(UGPoint2Ds &arrPoint1, UGPoint2Ds &arrPoint2, UGRect2D &rcBound, 
		UGArray<UGint> &arrPointIndex, UGdouble dTolerance);
	UGbool PickUpBoundary(UGDatasetVector *pDTRegion, UGArray<UGint*> &parrSegment, 
		UGArray<UGint> &arrSegmentCount);
	UGbool CheckOverlap(UGDatasetVector *pDTRegion, UGArray<UGint*> &parrSegment, UGArray<UGint> &arrSegmentCount);
	UGbool PickUpGaps(UGDatasetVector *pDTRegion, UGArray<int*> &parrSegment, 
		UGArray<UGint> &arrSegmentCount);
	UGbool MarkUpCommonLine(UGRect2D& rcBounds, UGRecordset* pRecordset,
		UGArray<UGint*> &parrSegment, UGArray<UGint> &arrSegmentCount,
		UGArray<UGint>& arrIDs, UGbool IsDelCommonLine);
	void MakeCommonLine(UGDatasetVector *pRegion, UGArray<int*> &parrSegment,
		UGDatasetVector *pDataset, UGbool bAddMaidenLine);
	
	UGbool GetDisJointID(UGRecordset *pRecordset, UGArray<UGint> &arrIDs, UGArray<UGint> &arrResIDs);
};

}

#endif

