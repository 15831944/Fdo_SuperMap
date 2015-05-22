/* 
	\file UGNetworkAnalyst.h
	\brief �����������
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/
#ifndef UGNETWORKANALYST_H
#define UGNETWORKANALYST_H

#include "Base/ugdefs.h"
#include "Base/UGList.h"
#include "Base/UGArray.h"
#include "Base/UGString.h"

#include "Engine/UGDatasetVector.h"

#include "Geometry/UGGeoLineM.h"
#include "NetworkAnalyst/UGNetworkAnalystEnv.h"

namespace UGC {

class UGRoute;

/*!	\brief	��������� \n*/
class NETWORKANALYST_API UGNetworkAnalyst  : public UGNetworkAnalystEnv
{
public:
	UGNetworkAnalyst();
	virtual ~UGNetworkAnalyst();
	
	/*!	\brief	����ģʽ�� */
	enum UGNetworkType
	{
		UGNTTrafficNetwork	= 1,	//��ͨ����
		UGNTUtilityNetwork	= 2		//��ʩ����
	};
	
	/*!	\brief	Ȩֵģʽ��*/
	enum UGWeightType
	{
		UGWTNULL	= 1,	//null
		UGWTBitGate	= 2,	//bit
		UGWTInteger	= 3,	//UGint
		UGWTSingle	= 4,	//float
		UGWTDouble	= 5		//UGdouble
	};

	/*!	\brief	��ѡ����ģʽ��*/
	enum	UGCenterCandidateType
	{
		UGCCTNULL	= 0,	//������
		UGCCTMobile	= 1,	//��ѡ����
		UGCCTFixed	= 2		//�̶�����
	};
	
	/*!	\brief	�������ͣ�*/
	enum	UGTraceType
	{
		UGTTSource	= 0,	//����Դ
		UGTTSink	= 1,	//������
	};

	//�ַ�������
	
	/*!	\brief	�߽����ģʽ */
	enum UGBoundFindType
	{
		UGBFTypeLeft	=	1 ,		// ���
		UGBFTypeRight	=	2 ,		// �ұ�
		UGBFTypeTop 	=	3 ,		// �ϱ�
		UGBFTypeBottom	=	4 		// �±�
	};

public:
	
	/*!	\brief	����ת���\n
	������ɺ��Զ���TRN*/
	UGbool CreateTRN();
	
	/*!	\brief	��ת���\n
	ʹ��ת���ǰ�����ȴ�TRN*/
	void OpenTRN();
	
	/*!	\brief	�Ƿ��Ѿ���ת���*/
	UGbool IsOpenTRN();
	
	/*!	\brief	�ر�ת���\n
	��ʱ��ʹ��TRN�������ȹرգ��ȴ���һ�δ���ʹ��*/
	void CloseTRN();
	
	/*!	\brief	ɾ��ת���\n
	����ɾ��TRN��ͬʱ�ͷ��ڴ�*/
	void DeleteTRN();
	
	/*!	\brief	�����ڽӾ���*/
	UGbool CreateAdjMatrix();
	
	/*!	\brief	�����ڽӾ���*/
	UGbool CreateAdjMatrixUtility();

	/*!	\brief	����������Χ���ڽӾ���*/
	UGbool CreateAdjMatrixUtility(const UGRect2D& rcBound);

	/*!	\brief	����������Χ���ڽӾ���*/
	UGbool CreateAdjMatrix(const UGRect2D& rcBound);
	
	/*!	\brief	ɾ���ڽӾ���\n
	ͬʱ�ͷ��ڴ�*/
	void DeleteAdjMatrixUtility();

	/*!	\brief	ɾ���ڽӾ���\n
	ͬʱ�ͷ��ڴ�*/
	void DeleteAdjMatrix();
	
	/*!	\brief	�����ڵ������*/
	UGbool CreateNodeDemand();
	
	/*!	\brief	ɾ���ڵ������\n*/
	void DeleteNodeDemand();
	
	/*!	\brief	�������������*/
	UGbool CreateArcDemand();
	
	/*!	\brief	ɾ�����������\n*/
	void DeleteArcDemand();
	
	/*!	\brief	�Ƿ��ǵ�·����*/
	void UseRoadRule(UGbool bUseRoadRule);
	
	/*!	\brief	���ýڵ��ϰ�\n
	*	\param	arrNodeID	�ϰ��㼯
	*/
	UGbool SetBarrierNodes(const UGArray<UGuint> &arrNodeID);

	/*!	\brief	��ӽڵ��ϰ�\n
	*	\param	arrNodeID	�ϰ��㼯
	*/
	UGbool AddBarrierNodes(const UGArray<UGuint> &arrNodeID);
	
	/*!	\brief	��ȡ�ڵ��ϰ�\n
	*	\param	arrNodeID	�ϰ��㼯
	*/
	UGbool GetBarrierNodes(UGArray<UGuint> &arrNodeID);
	
	/*!	\brief	���û����ϰ�\n
	*	\param	arrArcID		�ϰ����μ�
	*/
	UGbool SetBarrierArcs(const UGArray<UGuint> &arrArcID);
	
	/*!	\brief	��ӻ����ϰ�\n
	*	\param	arrArcID	�ϰ����μ�
	*/
	UGbool AddBarrierArcs(const UGArray<UGuint> &arrArcID);
	
	/*!	\brief	��ȡ�����ϰ�\n
	*	\param	arrArcID		�ϰ����μ�
	*/
	UGbool GetBarrierArcs(UGArray<UGuint> &arrArcID);
	
	/*!	\brief	�����ڵ��ϰ�\n
	*	\param	arrNodeID		�ϰ��㼯
	*/
	UGbool CancelBarrierNodes(const UGArray<UGuint> &arrNodeID);
	
	/*!	\brief	�������нڵ��ϰ� */
	UGbool CancelAllBarrierNodes();
	
	/*!	\brief	���������ϰ�\n
	*	\param	arrArcID		�ϰ����μ�
	*/
	UGbool CancelBarrierArcs(const UGArray<UGuint> &arrArcID);
	
	/*!	\brief	�������л����ϰ� */
	UGbool CancelAllBarrierArcs();
	
	/*!	\brief	���õ������ĵ�\n
	*	\param	nCenterID		���ĵ�ID
	*	\param	dResource		���ĵ���Դ��
	*	\param	dMaxImpedance	���ĵ������ֵ	
	*	\param	nCandidate		��ѡ�ؼ���(����ѡַ��������)
	*/
	UGbool SetCenter(UGint nCenterID,UGdouble dResource,UGdouble dMaxImpedance=0.0,UGCenterCandidateType nCandidate=UGCCTFixed);

	//!	\brief �������ĵ�
	UGbool SetCenter(UGCenterNode CenterNode,UGCenterCandidateType nCandidate=UGCCTFixed);
	
	//Add by wangsh 07.06.19 �����������ƣ���Ҫ�����Ż�����
	//!	\brief �������ĵ����ݼ�
    UGbool SetCenterDT(UGDatasetVector* pDTCenter);

	//!	\brief �õ����ĵ���Ϣ
	UGbool GetCenters(UGArray<UGCenterNode>&arrCenters);
	
	//!	\brief �õ��������ĵ�
	UGbool GetNodeDemands(UGArray<UGdouble>&arrNodeDemand);

	/*!	\brief	�����������ĵ�\n
	*	\param	arrNodeID		���ĵ�ID
	*/
	UGbool CancelCenter(UGint nCenterID);
	
	/*!	\brief	�����������ĵ�\n
	*/
	UGbool CancelAllCenters();
	
	/*!	\brief	�õ�����ڵ�ID��\n
	*	\param	arrDemandNodeID		�������㼯
	*/
	void GetAllocateNode(UGArray<UGuint> &arrDemandNodeID);
	
	/*!	\brief	�õ����󻡶�ID��\n
	*	\param	arrDemandArcID		������󻡶μ�
	*/
	void GetAllocateArc(UGArray<UGuint> &arrDemandArcID);
	
	/*!	\brief	�õ�·�ɻ���ID��\n
	*	\param	arrDemandArcID		������󻡶μ�
	*/
	UGbool GetViaArcIDs(UGArray<UGuint> &arrArcID);
	
	/*!	\brief	�õ�·�ɽڵ�ID��\n
	*	\param	arrDemandArcID		������󻡶μ�
	*/
	UGbool GetViaNodeIDs(UGArray<UGuint> &arrNodeID);

	/*!	\brief	�õ�·�������ID��\n
	*	\param	arrNodepnts		���������
	*/
	UGbool GetViaNodepnts(UGArray<UGPoint2D> &arrNodepnts);

	/*!	\brief	���÷��ؽ����Ϣ*/
	void SetResultInfos(const ResultInfo& resultinfo);
	
	/*!	\brief	��ȡ���ؽ����Ϣ*/
	ResultInfo GetResultInfos();
	
	/*!	\brief	���绷���Ƿ��Ѿ��ı�*/
	UGbool IsNetEnvModified();
	
	//!	\brief ����ת���
	UGbool ExportTRN(UGDatasetVector* pDtTRN);
	
	/*!	\brief	��ȡ��ʾ��Ϣ����ȡ·��������ͨ���м�·�ɵ�������ʾ��Ϣ\n
	  *	\param arrViaWeight			·�ɵ����ֵ��
	  *	\param arrViaDirection		·�ɵ�ķ����
	  * \return	�ɹ�����TRUE������FALSE��
	  *	\remarks 1��ʾ��ת��-1��ʾ��ת��0��ʾ��·����
	*/
	UGbool GetDirections(UGArray<UGdouble> &arrViaWeight,UGArray<UGshort> &arrViaDirection);
	
	//!	\brief �õ������������Ϣ
	UGbool GetAnalyseInfo(UGCostValues  *pCostValues,
		                 UGDatasetVector* pDtResultInfo,
						UGArray <UGuint>& arrNodeID, 
						UGArray <UGuint>& arrEdgeID,
						const UGString& strNodeName,
						const UGString& strEdgeName);
	//!	\brief �õ����
	UGbool GetPathTable(UGCostValues  *pCostValues,const  ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID, UGArray<UGuint>& arrArcID, UGint RouteCount);
	//!	\brief �õ����
	UGbool GetPathTable(UGCostValues  *pCostValues,const  ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID, UGArray<UGuint>& arrArcID);

	//UGCostValues *GetFeildCost(const UGString &strCostName);
	//!	\brief �õ����
	UGbool GetFeildCost(const UGString &strCostName,UGCostValues  * pCostValues);

public:

	//TraceWater
	//!	\brief ��ʼ���ڴ溯��
	UGbool AssignIniMemory();
	
	//!	\brief �ͷ��ڴ溯��
	void ReleaseMemory();
	
	//!	\brief �õ�������֮��ĽǶ�
	//!	\param pntStart ��ʼ��[in]
	//!	\param pntMiddle �м��[in]
	//!	\param pntEnd ��ֹ��[in]
	UGdouble GetAngle(const UGPoint2D &pntStart, const UGPoint2D &pntMiddle, const UGPoint2D &pntEnd);

	//!	\brief �õ����η���
	UGbool GetArcDirections(UGPoint2Ds& arrPoints,UGArray<UGdouble>& arrArcDirections);

	//!	\brief �õ�ת��ֵ
	UGbool GetTurnValue(UGPoint2Ds& arrPoints,UGArray<UGint>& arrTurnValue);
	
	//!	\brief �õ�׷�ٷ���
	UGbool GetTraceSign(UGint nCenterIndex,UGshort* &pbtOnPath,UGdouble* &pdNodeCost, UGint* &pnPrevArcID);
	
	//!	\brief	���ο���������
	//! \param  pData ����ָ��[in]
	//!	\param nCount ���θ���[in]
	void q_Sort(ArcInfo *pData, UGint nCount);

	//!	\brief	���ο���������
	//! \param  pData �����ָ��[in]
	//!	\param nCount ��������[in]
	void q_Sort(DemandNode *pData, UGint nCount);

	//!	\brief	�����������
	//! \param  pData �����ָ��[in]
	//!	\param nCount ��������[in]
	void q_Sort(PointIndex *pData, UGint nCount);

	//For TSP problem
	//!	\brief ����������
	void q_SortSCost(MTSPInfo *pData, UGint nCount);
	

	///For MTSP problem
	//UGbool GetCostMtx(UGArray<UGint>& arrTotalNodeIDs, MTSPInfo* pNodeMtx);
	//!	\brief ����������
	void q_SortNCost(MTSPInfo *pData, UGint nCount);

	//!	\brief ����������
	void q_SortSNIndex(MTSPInfo *pData, UGint nCount);
	
	//��̬�ֶ�
	//!	\brief �ж������Ƿ���ͬ
	UGbool IsSameArray(UGArray<UGint> &arrOld, UGArray<UGint> &arrNew);
	
	//!	\brief ���������е��ڴ�
	void DeleteArray(UGArray< UGshort*> & BArrOnPathPre,	UGArray< UGdouble*> & BArrNodeCostPre);

	// �� UGbool GetGeoLineM(CGeoRoute &resRoute, UGdouble dTotalCost)������������һ������
	
	//!	\brief ����routID���ɶ����
	UGbool GetCoverRegionByRoutID(UGArray<UGGeoLineM>& arrRoute,UGGeoRegion &CoverRegion,UGint nRoutID = -1 ) ;

	//!	\brief ȡ�����е�����
	UGbool CancleVirtualNodes();

	//!	\brief ���ݸ����Ļ���ID �����Ļ��ΰٷֱȽ���������
	// nArrSiteArcID �����ӳ��Ļ���ID
	// dArrPosSiteNode �����ӳ�䵽����ID����FNode�ľ���λ�� 1--0.0֮�����
	// nArrpntNodeID ����ÿ��������Ӧ������ID
	UGbool BuildVirtualNodes(UGArray<UGint> & nArrSiteArcID ,UGArray<UGdouble> & dArrPosSiteNode,UGArray<UGint> & nArrpntNodeID );

	//!	\brief �������ϰ���
	UGdouble GetArcCost(UGint nFNodeIndex,UGint nTNodeIndex);

	//!	\brief �������ĵ����ݼ�
	void SetCenterGeometry();
	
//	UGint FindIndex(UGint nNodeID);
	//!	\brief ��������ڵ�ID
	void SortNodeIDs();

	//!	\brief �������绡��ID
	void SortArcIDs();
	
	//!	\brief �������
	UGbool DistanceMatrix(UGArray<UGuint> &arrTSPIDs,UGdouble *&pdTSPMtx,UGbool bEndNodeSigned);
	
	//UGbool GetAnalyseNode(const UGPoint2D& pntNode,UGint& nArcID,UGint& nNodeID,UGdouble &dPos,short &shtDirection);
	
	//!	\brief ���ĵ�Ԥ����
	UGbool AllocatePreprocessing();
	
	//!	\brief �õ����ĵ�����
	UGbool GetDemandNodeIndex(UGint nCenterIndex,UGArray<UGuint>& arrDemandNodeIndex);
	
	//!	\brief ����������ĵ�
	UGbool CheckDemandAllocate();

	//!	\brief �õ���󸲸���������
	UGint GetMaxCoverCenterIndex();
	
	//!	\brief �õ����ĵ㸲�Ƿ���
	UGbool GetAllocateSign(UGint nCenterIndex,UGshort* &pbtOnPath,UGdouble* &pdNodeCost,UGdouble dResource,UGdouble dMaxImpedance=0);
	
	//!	\brief �õ�������
	void GetDemandTable(UGdouble* pdLocationMtx,UGchar*& pbtDemandMtx,UGint nLocations,UGint* pLocation,UGdouble* pdparam);
	
	//!	\brief �õ������Ͻ�
	UGdouble GetUpperBound(UGdouble* pdLocationMtx,UGint nLocations,UGint* pLocation);
	
	//!	\brief �õ������½�
	UGdouble GetLowerBound(UGdouble* pdLocationMtx,UGchar* pbtDemandMtx,UGint nLocations,UGint* pLocation);

	//!	\brief ��������
	void UpdateParameters(UGchar* pbtDemandMtx,UGdouble* pdparam,UGdouble& dConstant,UGdouble& dStepSize,
		UGdouble dLowerBound,UGdouble dUpperBound);

	//For multithread
	//!	\brief �̶����ĵ����
	UGbool AllocateFixedCenters( UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble>&arrNodeDemand,UGResultInfo& ResultInfo,UGdouble* pdLocationMtx,const UGArray<UGuint> &arrCenterIndex);
	//void DeleteArcDemand();
	//UGbool IsIntersectZones(const UGArray<UGuint> &arrCenterID,UGdouble dMaxImpedance,UGbool bFromCenter);
	
	//!	\brief �̶����η���
	UGbool GetCoverArcs(UGuchar* pbtOnPath,UGArray<UGuint> &arrArcIDs,UGbool bEnvelop=true);
	
	//!	\brief �õ����Ǿ���
	UGdouble GetCoverDist(UGuchar* pbtOnPath,UGbool bEnvelop=true);
	
	//!	\brief �õ�������Դ��
	UGdouble GetCoverResource(UGuchar* pbtOnPath,UGdouble* pdNodeCost,UGbool bEnvelop=true);

	//!	\brief �õ�����λ��
	UGint GetInsertPos(UGdouble dNodeCost,UGList<UGdouble>&lstNodeCost);
	
	//!	\brief �õ���󻨷�����
	UGint GetMaxCostIndex(const UGArray<UGdouble> &arrCoverDist);
	
	//!	\brief �õ����ξ���
	UGdouble GetArcDist(UGint nArcID);
	
	//!	\brief ĳ�㵽����㴮�ľ���
	UGdouble GetDistToStartNode(const UGPoint2D &pntHitTest,const UGPoint2D* pPoint,UGint nCount);
	
	//!	\brief �������ĵ����ݼ�
	void UpdateCentersFile(UGDatasetVector* pDTCenters);
	
	//UGString BuildQueryFilter(UGArray<UGuint> &arrKeys,const UGString strFieldName);
	//!	\brief �����������Ϊ�ϰ�
	UGbool SetDemandNodesToBarrier(const UGArray<UGuint> &arrDemandNodeIndex);
	
	//!	\brief ����������
	void q_Sort(NetIndex *pData, UGint nCount);
	
	//UGdouble GetTSPDivMatrix(UGdouble* pdDivMtx,UGint nCount,TourIndex* pTourNodeIndex = NULL,
	//						UGint nLevel = 0);
	
	//!	\brief �õ�����
	UGdouble GetDirectAngle(UGPoint2D pntStart, UGPoint2D pntEnd);
	
	//����������
public:

	//!	\brief ���������� �÷����ܽ��ڻ������������
	// arrLines ������߶� ��Щ�߶��������������ݼ��е��� �����ϸ���
	// arrRegions ���صĶ���� 
	// dBufferRadius ������ܹ����� ����buffer ��dBufferRadiusС��0ʱ������buffer
	static UGbool ShrinkRegion(UGArray<UGGeoLine> & arrLines,UGArray<UGGeoRegion> & arrRegions,UGdouble dBufferRadius = EP);	

private:

	//!	\brief ���������� 
	// arrLines ������߶� ��Щ�߶ζ��Ǳ˴���ͨ��
	// regions ���صĶ���� 
	static UGbool ShrinkRegion(UGArray<UGGeoLine> & arrLines,UGGeoRegion  & region,double dBufferRadius = EP);	

	//!	\brief ��ȡ͹����
	static  UGbool GetPackagePnt( UGArray<UGGeoLine> & arrLines,UGPoint2Ds & arrPnts);

	//!	\brief ���ݸ������߶δ������Ƕ����
	// ���Ƕ����:��pntStartΪ��ʼ�㣬˳ʱ����arrLines�ƶ� ֱ���ص�pntStart��
	static UGbool GetCoverRegion( UGPoint2D pntStart ,UGArray<UGGeoLine> & arrLines,UGGeoRegion & CoverRegion );

	//!	\brief ��ȡ��������εĹ��ɵ�
	// CoverRegion  ������GetCoverRegion ��õ���
	static UGbool GetShrinkPnt( UGGeoRegion & CoverRegion,UGPoint2Ds & arrPnts );

	//!	\brief ��� nLineIndexС��0 ������pntΪ��ͷ���߽�β�Ļ��� 
	// �������0 �Ͳ���nlineIndex���ڻ��μн���С�Ļ���
	static  int FindPntOnLines( UGPoint2D pnt ,UGArray<UGGeoLine> & arrLines,UGint nLineIndex = -1);

	//!	\brief ��ȡ GetShrinkPnt �еĵ� �� CoverRegion �е�λ��
	static UGbool GetPntPosInRegion( UGGeoRegion & CoverRegion,UGPoint2Ds & arrPnts,UGArray<UGint>& nArrPos );

	//!	\brief ���Ӹ��� ����γ�һ�������
	static UGbool LinkAllPnt( UGGeoRegion & CoverRegion ,UGPoint2Ds & arrPnts ,UGArray<UGint>& nArrPos,
		UGGeoRegion  & RegionShrink,UGdouble dBufferRadius = EP);
	
	//!	\brief �õ��߶�
	static UGbool GetLinesSets(UGArray<UGGeoLine> & arrLines,UGArray<UGint>  & arrLineState  ) ;
	
	//!	\brief �ݹ�ʵ�� GetLinesSets ����
	static UGbool GetLinesSets(UGint nLineIndex  ,UGArray<UGGeoLine> & arrLines,UGArray<UGint>  & arrLineState  ) ;

	//!	\brief ���������
	static UGbool AllInRegion(UGArray<UGGeoLine> & arrLines,	UGGeoRegion  & region ) ;
	
};

}

#endif

