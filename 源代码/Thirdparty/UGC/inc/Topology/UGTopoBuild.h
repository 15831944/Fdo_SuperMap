#ifndef UGTOPOBUILD_H
#define UGTOPOBUILD_H

#include "Engine/UGDatasetVector.h"
#include "Topology/UGTopoTypes.h"
#include "Base/UGBitArray.h"

namespace UGC {

class UGTopoFile;

class TOPOLOGY_API UGTopoBuild  
{

public:
	UGTopoBuild();
	UGTopoBuild(UGDatasetVector *pDataset);
	virtual ~UGTopoBuild();
	
public:
	
	void SetInterval(UGdouble dInterval);
	UGdouble GetInterval();
	UGbool LineDTIntersect(UGDatasetVector *pDatasetArc, UGint nApartIndex);
	UGbool LineDTClearRepeateLine(UGDatasetVector *pDatasetArc, UGint nApartIndex);
	UGbool TopoBuildPolygon(UGDatasetVector *pDatasetArc, UGArray<UGGeoRegion*> &arrRegions);
	
	//! \brief������
	UGbool TopoEditIntersectAllLine(UGDatasetVector *pDatasetArc, 
		UGbool IsAbandonMinLine = false,UGdouble dMinLineLength = 0);
	
	//! \brief����������
	UGbool TopoEditLongDangleLineExtend(UGDatasetVector *pDatasetArc);
	
	//! \brief�ϲ��ٽڵ�
	UGbool TopoEditMergePseudoNode(UGDatasetVector *pDatasetArc);
	
	//! \brief�ٽ��ڵ�ϲ�
	UGbool TopoEditMergeCloseNode(UGDatasetVector *pDatasetArc);
	
	//! \briefȥ������
	UGbool TopoEditClearSmallDangleLine(UGDatasetVector *pDatasetArc);
	
	//! \briefȥ���ظ���
	UGbool TopoEditClearRepeatedLine(UGDatasetVector *pDatasetArc);
	
	//! \brief	ȥ�������
	UGbool TopoEditClearRedundanceVertex(UGDatasetVector *pDatasetArc);
	
	//! \brief	���˹���
	//! \param	pDatasetArc			�����ݼ�
	//! \param	pDatasetPoly		�������������ݼ�
	//! \param	pDatasetPolyTmp		����������ʱ�����ݼ�
	//! \param	IsAddBoundPolygon	�Ƿ���ӱ߽�����
	//! \remark	pDatasetPolyTmp���û���ʱ����,�����,���û�����ɾ��!
	UGbool TopoBuildPolygon(UGDatasetVector *pDatasetArc, 
		UGDatasetVector *pDatasetPoly, 
		UGDatasetVector *pDatasetPolyTmp,
		UGbool IsAddBoundPolygon = false);
	
	//! brief	���˹���
	//! \param	pDatasetArc			�����ݼ�
	//! \param	pDatasetPoly		�������������ݼ�
	//! \param	pDatasetPolyTmp		����������ʱ�����ݼ�
	//! \param	IsAddBoundPolygon	
	//! \remark	pDatasetPolyTmp���û���ʱ����,�����,���û�����ɾ��!
	UGbool TopoBuildHatchPolygon(UGRecordset *pArcRecordset,const UGPoint2D& pntHit,
								UGGeoRegion& HitRegion);
	
	//! \brief	�������˴�����Ϣ
	UGbool TopoEditCreateTopoErrorInfo(UGDatasetVector *pDatasetArc);
	
	//! brief	�����������ݼ�
	//! \param pDatasetArc			�����ݼ�
	//! \param	pDatasetNode		�ڵ����ݼ�
	//! \param	pDatasetNet			���������������ݼ�
	UGbool TopoBuildNetwork(UGDatasetVector *pDatasetArc,UGDatasetVector *pDatasetNode,
		UGDatasetVector *pDatasetNet);
	
	//! \brief �ֽ⸴�϶���
	UGbool TopoSeparateComplex(UGDatasetVector *pDatasetArc);

	UGbool SetFilterElement(UGDatasetVector *pDatasetFilter,const UGString& strEdgeFilter,const UGdouble& dNodeInterval);
	
	void CancelNodeFilter();
	//UGbool MarkUpCommonLine(UGRect2D& rcBounds, UGRecordset* pRecordset, UGbyte* pWeight, UGArray<UGint>& arrIDs);
	UGbool MarkUpCommonLine(UGRect2D& rcBounds, UGRecordset* pRecordset, UGTopoGrid* pWeight, UGArray<UGint>& arrIDs);
	
	UGbool TopoEditExtendDangleLine(UGbool IsShowProgress, UGDatasetVector *pDatasetArc, UGdouble ExtendedLength,
									UGbool IsOutToLogFile);

	UGbool TopoBuildPolygonEx(UGDatasetVector *pDatasetArc, UGArray<UGGeoRegion*> &arrRegion);

	// �ϲ����⻬��ֵ��
	UGbool TopoSmoothAfterMerge(UGDatasetVector *pDatasetArc, UGString& strElev, UGint nSmoothDegree);

protected:
	
	UGbool GetIntersectPnt(UGRect2D &rectBounds,UGRecordset* &partRecordset,
							UGArray<UGTopoGridUnitNodesEx>&pArcIntersetPntNo,
							UGint &RealArcCount,UGArray<UGint> &fieldIndexs,
							UGArray<UGPoint2D>&pIntersetPoints,UGArray<UGint> &ArcIDs);
	
	UGint GetArcIDIndex(UGint nArcId,UGArray<UGint> &ArcIds);
	
	UGbool TopoBuildPolygonFile(UGDatasetVector *pDatasetArc, 
		UGDatasetVector * &pDatasetPoly, 
		UGDatasetVector * &pDatasetPolyTmp,
		UGbool IsAddBoundPolygon);
	
	UGbool TopoBuildPolygonArray(UGDatasetVector *pDatasetArc, 
		UGDatasetVector * &pDatasetPoly, 
		UGDatasetVector * &pDatasetPolyTmp,
		UGbool IsAddBoundPolygon,
		UGint ArcsCount);
	
	UGbool ComposeRegion(UGGeoRegion &geoRegion, UGRecordset *pRecordsetArc,
		UGint *pPolyArcs,UGint nArcCount);
	UGbool ComposeRegion(UGGeoRegion*& pgeoRegion, UGRecordset *pRecordsetArc, 
		UGint *pPolyArcs, UGint nArcCount,UGArray<UGint> &arrIDs);
	
	UGbool TopoEditNodesIdentify(UGDatasetVector *pDatasetArc, 
		UGTopoFile **pFileNodeIndex,
		UGTopoFile **pFileNodeArcs,
		UGint& IndexNodesCount,
		UGTopoFile **pFileNodeFrom = NULL,
		UGTopoFile **pFileNodeTo = NULL,
		UGTopoFile **pFileNodeFromNext = NULL,
		UGTopoFile **pFileNodeToPrev = NULL,
		UGTopoFile **pFileArcNodeIDFrom = NULL,
		UGTopoFile **pFileArcNodeIDTo = NULL,
		UGbool bIsReturnNodePoints = false);
	
	UGbool TopoEditNodeID(UGDatasetVector *pDatasets, 
		UGArray<TNodeIndexPN> &pNodeIndex,
		UGint **pNodeArcs,
		UGint  &IndexNodesCount,
		UGint **pArcNodeIDFrom,
		UGint **pArcNodeIDTo);
	
	UGbool TopoEditNodesIdentifyEx(UGDatasetVector *pDatasetArc, 
		UGTopoFile **pFileNodeIndex,
		UGTopoFile **pFileNodeArcs,
		UGint& IndexNodesCount,							
		UGTopoFile **pFileArcNodeIDFrom,
		UGTopoFile **pFileArcNodeIDTo	);
	
	void RemoveErrorArc(UGTopoFile **pFileNodeIndex,
		UGTopoFile **pFileNodeArcs,
		UGTopoFile **pFileArcNodeIDFrom,
		UGTopoFile **pFileArcNodeIDTo,
		UGint **pArcsLCode,
		UGint **pArcsRCode,
		UGint ArcNo);
	
	void RemoveErrorArcEx(UGArray<TNodeIndexPN> &pNodeIndex,
		UGint **pArcIndex,
		UGint **pArcNodeFromID,
		UGint **pArcNodeToID,
		UGint **pArcsLCode,
		UGint **pArcsRCode,
		UGint ArcNo);
	
	UGint IntersectLineSect(UGPoint2D &pntStart1, UGPoint2D &pntEnd1, 
		UGPoint2D &pntStart2, UGPoint2D &pntEnd2,
		UGPoint2D &pntResult1, UGPoint2D &pntResult2);
	
	void InitTopoFile(UGTopoFile **pTopoFile, UGint ArcsCount, UGuint nRecordSize, 
		UGuint nRecordsCount);
	
	void ReleaseTopoFile(UGTopoFile **pTopoFile);

public:
	
	UGdouble dMinDangleLength;
	UGdouble dMinVertexInterval;
	UGdouble dMinNodeInterval;
	UGdouble dMinArea;
	UGdouble dExtendedLength;
	UGdouble dMinRatioOfAreaToPerimeter;
	
private:
	UGint FindInsetPos(UGint nID,UGint* arrIDs,UGint nCount);
	UGbool TopoBuildHatchPolygon(UGDatasetVector *pDatasetArc, const UGPoint2D& pntLabel,
								UGGeoRegion &geoRegion);
	UGbool GetHatchNodeID(UGDatasetVector *pDatasetArc,UGTopoGridUnitNodes *&pGridUnitNodes,
						UGTopoFile *&pFileNode,UGPoint2D* &pFPoints,UGPoint2D* &pTPoints);
	
	UGbool GetHatchHead(UGDatasetVector *pDatasetArc,UGPoint2D pntLabel,
						UGArray<THatchHead&> &arrHatchHead);
	
	UGint TopoBuildHatchPolygon(UGDatasetVector *pDatasetArc, UGPoint2D pntLabel);
	
	void TopoPreprocess(UGDatasetVector *pDatasetArc);
	
	UGbool IsTopoLineValid(UGGeoLine*& pSingleLine);
	
	UGbool bIsPreProcess;
	
	UGbool GetNodeXYFromDT();
	UGbool IsFilterNode(const UGPoint2D &pntIntersect);
	
	UGbool GetApartIntersectPnt(UGRect2D &rectBounds, UGint nApartIndex,
								UGRecordset * &partRecordset,
								UGArray<UGTopoGridUnitNodesEx> &pArcIntersetPntNo,
								UGArray<UGPoint2D> &pIntersetPoints,
								UGArray<UGint>& arrIDs);
	
	UGDatasetVector* m_pDatasetFilter;
	UGString m_strEdgeFilter;
	UGdouble m_dNodeInterval;
	UGbool m_bNodeFilter;
	UGPoint2Ds m_NodeXY;
	UGdouble m_dInterval;
};

}

#endif
