/* 
	\file UGTrafficAnalyst.h
	\brief ��ͨ���������
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGTRAFFICANALYST_H
#define UGTRAFFICANALYST_H

#include "NetworkAnalyst/UGNetworkAnalyst.h"
#include "Base/ugdefs.h"

namespace UGC {

class NETWORKANALYST_API UGTrafficAnalyst  : public UGNetworkAnalyst
{
public:
	UGTrafficAnalyst();

	virtual ~UGTrafficAnalyst();
	
	/*!	\brief	·������ģʽ��*/
	enum	UGFindPathType
	{
		UGFPTMinWeight		= 1,	//��СȨֵ;			������һ���������·��������
		UGFPTMinEdgesSum	= 2		//���ٻ�����С��ֵ�����������������·��������
	};
	
	/*!	\brief	��Դ����ģʽ��*/
	enum	UGAllocateType
	{
		UGATNodes			= 1,	//�ڵ�����	���������ֻ���ǽڵ�����
		UGATEdges			= 2,	//��������	���������ֻ���ǻ�������
		UGATNodesAndEdges	= 3		//�ڵ�ͻ�������	������̿��ǽڵ�ͻ�������
	};
	
	/*!	\brief	ѡַģʽ��*/
	enum	UGLocateAllocateType
	{
		UGLATMinCost		=1,	//��СȨֵ��	�����ڣ��ֿ⣬����վ�ȵ�ѡַ����������ɱ����٣�
		UGLATMaxCover		=2,	//��󸲸ǣ�	������: ���ȷ�����ʩѡַ(��������վ���������ĵ�)��һ�㲻��Ҫ������Դ����
		UGLATMinCostPower	=3,	//��С����Ȩֵ�������ڣ�����������ʩ��ѡַ(����ͼ��ݵ�)���ȿ����ܾ��������ֿ��ǹ�ƽԭ��
		UGLATMaxAttend		=4	//���������	�����ڣ����۵�,�͹�ѡַ���������������
	};
	
	/*!	\brief	��������ģʽ��*/
	enum	UGMTSPType
	{
		UGMTSPMinTotalCost			= 1,	
		UGMTSPMinEachCost			= 2	
	};

	//! Ϊ��֧�ֶ��߳�,��������ӿ��Ѿ�������ڵ�������ģʽ,ͳһ��һ���ӿ�����

	//!	\brief	���·������
	//!	\param AnalyseParams ·��������������[in]
	//!	\param arrViaNodeID		˳����ID��[in]
	//! \param arrViaPoints     ˳�������[in]
	//!	\param bLeastEdgesSum   �Ƿ񻡶�����[in]
	//!	\return	�ɹ�:���ؽ��Route��Weight���κ��쳣�ʹ��󽫷���-1.0��
	UGdouble FindPath(const UGAnalyseParams &AnalyseParams, UGResultInfo& ResInfoOut,UGbool bLeastEdgesSum = FALSE);

	//!	\brief	�����̷���
	//!	\param AnalyseParams �����̷�����������[in]
	//!	\param arrViaNodeID         �������ID��[in]
	//!	\param bEndNodeSigned		�Ƿ�ָ���յ�[in]
	//!	\return	�ɹ�:���ؽ��Route��Weight���κ��쳣�ʹ��󽫷���-1.0��
	//!	\remarks ָ���յ���Է��յ�������ͬ�Ͳ�ͬ���֡�
	UGdouble FindTSPPath(const UGAnalyseParams &AnalyseParams,UGResultInfo& ResInfoOut,UGbool bEndNodeSigned);

	//!	\brief	�����ʩ��������ָ���¼���������ʩ 
	//!	\param AnalyseParams �����ʩ������������[in]
	//!	\param nEventID			�¼�ID[in]
	//!	\param pntEvent			�¼�������[in]
	//!	\param arrFacilityID	��ʩID��[in]
	//!	\param arrFacility		��ʩ�������б�[in]
	//!	\param nFacilities		Ŀ����ʩ�����[in]
	//!	\param arrFacilityDist  ���ҵ���ʩ��Ļ�������[out]
	//!	\param dMaxImpedance	���������ֵ[in]
	//!	\param bFromEvent		�Ƿ���¼��㿪ʼ����[in]	  
	//!	\return	�¼��㵽��Ч��ʩ����ܾ���		
	//!	\remarks ������Ч��ʩ��ID(����)����arrFacilityID(arrFacility)��;
	//! ������Ч��ʩ��������nFacilities�У�
	//!	dMaxImpedance��Ĭ��ֵΪ0����ʾ������������ֵ:
    UGdouble FindClosestFacility(const UGAnalyseParams &AnalyseParams,UGResultInfo& ResInfoOut,
		                               UGdouble dMaxImpedance=0,UGbool bFromEvent = TRUE);
	
	//!	\brief	���������� 
	//!	\param AnalyseParams �����������������[in]
	//!	\param nArrSiteID �������ĵ�[in]
	//!	\param dArrServiceCost ������cost[in]
	//!	\param bFromSite			[in]
	//!	\param bGeneralized		TRUE:��ͨ���������� FALSE���������ĵ㻥��[in]
	//! \param dArrSiteCost	 ���ظ������ĵ�ķ������ �����������ʱû�з��� ��[out]
	//!	\return ��������ɹ�����TRUE�����򷵻�FALSE
	//! \remarks 
	UGbool FindServiceArea(const UGAnalyseParams& AnalyseParams,UGResultInfo& ResInfoOut,
		                         UGbool bGeneralized = TRUE ,UGbool bFromSite = TRUE);

	//!	\brief	MTSP������(��������)������������
	//!	\param AnalyseParams �������������������[in]
	//!	\param arrMTSPIDs			�����̽���[in]
    //!	\param arrViaNode			��������[in]
	//!	\param arrDist				������·����[out]
	//!	\param bMinTotalCost		�Ƿ��ܺ���Сģʽ[in]
	//!	\return �ɹ�:����TRUE��ͬʱͨ�����÷��ظ���·�ߵĻ��Ρ���㡢���ѣ�
	//! \remarks (��������)������������,
	UGbool FindMTSPPath( const UGAnalyseParams& AnalyseParams,UGResultInfo& ResInfoOut, UGArray <UGuint> &arrOrderIndexs,
					           UGbool bMinTotalCost=FALSE);

	//!	\brief	ѡַ����������  
	//!	\param nMode			ѡַģʽ[in]
	//!	\param nLocations		Ŀ��������[in]
	//!	\param bFromCenter		�Ƿ�����ĳ���[in] 
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks ѡַ���������Ǿ���һ������������ʩ������λ�õĹ��̣�
	//!	���Ķ�λ����֤������ʩ�����������Ч�ķ�ʽΪ�����������Ⱥ�ṩ����
	UGbool LocateAllocate(const UGAnalyseParams& AnalyseParams,UGResultInfo& ResInfoOut,UGArray<UGuint> &arrLocationID,UGbool bFromCenter=TRUE);
	
	//!	\brief ��Դ�������
	//!	\param AnalyseParams ��Դ���������������[in]
	//!	\param nMode		����ģʽ[in]
	//!	\param bFromCenter	���䷽���Ƿ�����ĳ���[in]
	//!	\param bConnected	������������ɵ�Route�Ƿ������ͨ[in] 
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;	
	//! \remarks ��Դ�������ģ����ʵ������������Դ�Ĺ����ϵģ��;
	//!  ��Դ�ɹ�Ӧ�����������(�������λ�ڵ�)������Դ,��ȷ����Ӧ�����������Ч�ķ�ʽ
	//!  Ϊ�����������Ⱥ�ṩ����;
	UGbool Allocate( const UGAnalyseParams& AnalyseParams,UGResultInfo& ResInfoOut);

	//!	\brief	�������ӿ�
	//!	\param AnalyseParams  ��������б�[in];
	//!	\param arrDistMatrix  �������ľ������[in]
	//! \remarks ��������½ӿ�
	UGbool GetDistanceMatrix(const UGAnalyseParams &AnalyseParams, UGArray<UGDistMatrixUnit>& arrDistMatrix);
	
	//!	\brief	���»���Ȩֵ
	//! \param  nEdgeID			����ID[in]
	//! \param  nFromNodeID		������ʼ���ID[in]
	//! \param  nToNodeID		������ֹ���ID[in]
	//!	\param strCostName		�����ֶ�[in]
	//!	\param dWeight			����Ȩֵ[in]
	//!	\return ���غ��θ���ǰ��Ȩֵ������ʧ�ܷ���-1000
	UGdouble UpdateEdgeImp(UGint nEdgeID, UGint nFromNodeID, UGint nToNodeID, UGString& strCostName, UGdouble dWeight);
	
	//!	\brief	���½��Ȩֵ
	//! \param  nNodeID			���ID[in]
	//! \param  nFEdgeID		�����ʼ����ID[in]
	//! \param  nTEdgeID		�����ֹ����ID[in]
	//!	\param strCostName		�����ֶ�[in]
	//!	\param dWeight			����Ȩֵ[in]
	//!	\return ���ؽ�����ǰ��Ȩֵ������ʧ�ܷ���-1000
	UGdouble UpdateNodeImp(UGint nNodeID, UGint nFEdgeID, UGint nTEdgeID, UGString& strCostName, UGdouble dNodeImp);

private:

	//!	\brief	������С���Ƽ��� ��С���Ƽ���Ϊ��������������������������� 
	//!	\param	arrLocationID		��ѡ���ĵ��  
	//!	\return	�����������������������
	//! \remarks	�̶����ĵ�����ѡ���Ŀ���
	UGint CalculateMinControls(UGArray<UGuint> &arrLocationID);

	//�������������ڵ�ģʽ
	//!	\brief	�������� 	
	//!	\param nArrSiteID			�������ĵ�
	//!	\param dArrServiceCost		������cost
	//!	\param ArrServiceRoute		�����Ľ��·��
	//!	\param ArrServiceRegion		���������
	//!	\param bFromSite			
	UGbool FindMServiceArea(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGResultInfo &ResInfo,const UGArray<UGuint> & nArrSiteID,const UGArray<UGdouble> & dArrServiceCost,
							UGArray<UGdouble  > & dArrSiteCost ,UGbool bFromSite = TRUE);

	//�����������������ģʽ
	//!	\brief	�������� 	
	//!	\param nArrSiteID			�������ĵ�
	//!	\param dArrServiceCost		������cost
	//!	\param ArrServiceRoute		�����Ľ��·��
	//!	\param ArrServiceRegion		���������
	//!	\param bFromSite			
	UGbool FindMServiceArea(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGResultInfo &ResInfo,const UGPoint2Ds& pntArrSite,const UGArray<UGdouble> & dArrServiceCost,
							UGArray<UGdouble  > & dArrSiteCost ,UGbool bFromSite = TRUE);

	//!	\brief	��������������ȡָ��λ�õ�ķ�������ͷ������� 
	//!	\param nSiteID			����ID
	//!	\param dServiceCost		���Ǿ���
	//!	\param ServiceRoute		������Route
	//!	\param ServiceRegion	�����������
	//!	\param bFromSite		�Ƿ�����ķ��� 
	//!	\return	����������ܾ���
	UGdouble FindServiceArea(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGResultInfo &ResInfo,UGint nSiteID,UGdouble dServiceCost,UGbool bFromSite = TRUE);

	//!	\brief	��������������ȡָ��λ�õ�ķ�������ͷ������� 
	//!	\param pntSite			��������
	//!	\param dServiceCost		���Ǿ���
	//!	\param ServiceRoute		������Route
	//!	\param ServiceRegion	�����������
	//!	\param bFromSite		�Ƿ�����ķ��� 
	//!	\return	����������ܾ���
	UGdouble FindServiceArea(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGResultInfo &ResInfo,const UGPoint2D &pntSite,UGdouble dServiceCost,UGbool bFromSite = TRUE);

	//ѡַ��������
	//!	\brief	������С���Ƽ�
	//! \param  nLocations ѡַ����[in]
	//!	\param arrLocationIndex ѡַ��������[in]
	//!	\return ���ؼ���ĸ���
    UGint CalculateMinControls(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,
		UGArray<UGdouble> &arrNodeDemand,UGint nLocations, UGArray<UGuint> &arrLocationIndex);
	
	UGbool Allocate(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,
		UGArray<UGchar>&arrbtDemandAllocated,UGArray<UGuint> &arrDemandNodeIndex,UGAllocateType nMode,UGint nCenterIndex,UGbool bFromCenter=TRUE);

	//{{�����ת��
	//!	\brief	������ID����ͨ����ѯת��Ϊ���������Ϣ
	//!	\param arrArcID			����ID����[in]
    //!	\param ArcIDsInfo		������Ϣ����[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool GetArcInfos(UGArray<UGuint>& arrArcID, UGElemIDsInfo& ArcIDsInfo);

	//!	\brief	���ڵ�ID����ͨ����ѯת��Ϊ�ڵ������Ϣ
	//!	\param arrNodeID		�ڵ�ID����[in]
    //!	\param NodeIDsInfo		�ڵ���Ϣ����[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool GetNodeInfos(UGArray<UGuint>& arrNodeID, UGElemIDsInfo& NodeIDsInfo);

	//!	\brief	�����������ת��Ϊ����һ���ĵ����ڵ���Ϣ
	//!	\param pCostValues		·��������������ָ��[in]
	//!	\param pntViaNode		���������[in]
    //!	\param NodeInfo		    �����ڵ���Ϣ[out]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool GetAnalyseNode(UGCostValues  *pCostValues,const UGPoint2D &pntViaNode, UGNodeInfo& NodeInfo);

	//!	\brief	�����������ת��Ϊ����һ���Ľڵ���Ϣ����
	//!	\param pCostValues		·��������������ָ��[in]
	//!	\param pntViaNodes		�������������[in]
    //!	\param NodeInfos		�ڵ���Ϣ����[out]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool GetAnalyseNodes(UGCostValues  *pCostValues,const UGPoint2Ds &arrViaNode, UGNodeInfos& NodeInfos);

	//!	\brief	�����0��ʼ����ǰ�����ľ���֮��
	//!	\param nIndex		����λ��[in]
    //!	\param NodeIDsInfo	����ָ��[in]
	//!	\return ���ؾ��룻
	UGdouble GetDist(UGint nIndex, UGPoint2D* pPoints);

	//!	\brief	�õ��ڵ���Ϣ����
	//!	\param pCostValues		·��������������ָ��[in]
    //!	\param NodeInfos		�ڵ���Ϣ����[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool GetNodeInfo(UGCostValues  *pCostValues,UGNodeInfos& NodeInfos);

	//!	\brief	����������Ҫ���õ�һ���Ӻ���
	//!	\param pCostValues		·��������������ָ��[in]
	//!	\param pTurnCost		ת�����ָ��[in]
	//!	\param IniMemory		�ڴ�ṹ[in]
	//!	\param Barriers		    �ϰ����ϰ��߽ṹ[in]
	//!	\param NodeInfoFrom		�����Ϣ[in]
	//!	\param NodeInfoEnd		�յ���Ϣ[in]
	//!	\param resRoute		    �����·����Ϣ[out]
	//!	\param arrArcID		    ����ID����[out]
	//!	\param arrNodeID		�ڵ�ID����[out]
    //!	\param bLeastArcs		�Ƿ񻡶θ�������[in]
	//!	\param bSaveRoute		�Ƿ񱣴�·��[in]
	//!	\return �ɹ�:���ػ��ѣ����򷵻�-1.0��
	UGdouble FindPath(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGNodeInfo& NodeInfoFrom, UGNodeInfo& NodeInfoEnd,
		UGRoute &resRoute, UGArray<UGuint>& arrArcID, UGArray<UGuint>& arrNodeID,
		UGbool bLeastArcs=FALSE,UGbool bSaveRoute=TRUE);
	//}}�����ת��

	//{{��ʹ����
	//!	\brief	�õ���ʹ��������
	//!	\param PathGuide		��ʹ�����ṹ[out]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	void GetPathGuide(UGPathGuide& PathGuide);

	//!	\brief	�õ���ʹ��������
	//!	\param PathGuides		��ʹ�����ṹ����[out]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool GetPathGuides(UGPathGuides& PathGuides);
	
	//!	\brief	�õ���ʹ��������
	//!	\param PathGuides		��ʹ�����ṹ����[out]
	//!	\param pCostValues		���������ֶ�ָ��[in]
	//!	\param arrNodeID		�ڵ�ID����[in]
	//!	\param arrArcID		    ����ID����[in]
	//!	\param arrViaNodeID		����ID����[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool MakePathGuide(UGPathGuides& PathGuides,const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGArray<UGuint>& arrNodeID, UGArray<UGuint>& arrArcID, const UGArray<UGuint>& arrViaNodeID);

	//!	\brief	�õ���ʹ��������
	//!	\param PathGuides		��ʹ�����ṹ����[out]
	//!	\param pCostValues		���������ֶ�ָ��[in]
	//!	\param NodeInfos		�ڵ���Ϣ����[in]
	//!	\param arrGuideNodeID	�ڵ�ID����[in]
	//!	\param arrGuideArcID   ����ID����[in]
	//!	\param nSegCount		����·������[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool MakePathGuide(UGPathGuides& PathGuides,const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGNodeInfos& NodeInfos, UGArray<UGuint>& arrGuideNodeID, UGArray<UGuint>& arrGuideArcID, UGint nSegCount);
	
	//!	\brief	�õ���ʹ��������
	//!	\param PathGuides		��ʹ�����ṹ����[out]
	//!	\param pCostValues		���������ֶ�ָ��[in]
	//!	\param EventInfo		�¼�����Ϣ[in]
	//!	\param NodeInfos	    ��ʩ����Ϣ[in]
	//!	\param arrNodeIds       �ڵ�ID����[in]
	//!	\param arrArcIDs        ����ID����[in]
	//!	\param nSegCount		����·������[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool MakePathGuides(UGPathGuides& PathGuides,const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGNodeInfo& EventInfo, UGNodeInfos& NodeInfos, UGArray<UGuint>& arrNodeIds, UGArray<UGuint>& arrArcIds, 
		UGint nRouteCount);

	//!	\brief	�õ���ʹ��������
	//!	\param PathGuides		��ʹ�����ṹ����[out]
	//!	\param pCostValues		���������ֶ�ָ��[in]
	//!	\param arrNodeIds       �ڵ�ID����[in]
	//!	\param arrArcIDs        ����ID����[in]
	//!	\param nSegCount		����·������[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool MakePathGuides(UGPathGuides& PathGuides,const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGArray<UGuint>& arrNodeIDs, UGArray<UGuint>& arrArcIDs, UGint nRouteCount);
	
	//!	\brief	�ɷ�������Ϣ�õ�������ʻ����
	//!	\param pCostValues		���������ֶ�ָ��[in]
	//!	\param arrNodeIds       �ڵ�ID����[in]
	//!	\param arrEdgeID        ����ID����[in]
	//!	\param NodeIDsInfo		�ڵ���Ϣ[in]
	//!	\param ArcIDsInfo	    ������Ϣ[in]
	//!	\param PathGuide		������ʻ��������[out]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool GetAnalyseInfo(const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGArray<UGuint>& arrNodeID, UGArray<UGuint>& arrEdgeID, UGElemIDsInfo& NodeIDsInfo, 
		UGElemIDsInfo& ArcIDsInfo, UGPathGuide& PathGuide);

	//!	\brief	�ɷ�������Ϣ�õ�������ʻ����
	//!	\param pCostValues		���������ֶ�ָ��[in]
	//!	\param arrNodeIds       �ڵ�ID����[in]
	//!	\param arrEdgeID        ����ID����[in]
	//!	\param arrViaNodeID		�����ڵ�����[in]
	//!	\param PathGuide		������ʻ��������[out]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool GetAnalyseInfo(const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGArray<UGuint>& arrNodeID, UGArray<UGuint>& arrEdgeID, 
		const UGArray<UGuint>& arrViaNodeID,UGPathGuide& PathGuide);
	
	//!	\brief	�������õ�ת����Ϣ
	//!	\param arrPoints		����㴮����[in]
	//!	\param arrTurnType      ת������[in]
	//!	\param arrAngle         ת��Ƕ�����[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool GetTurnValue(UGPoint2Ds& arrPoints, UGArray<UGbyte>& arrTurnType, UGArray<UGdouble>& arrAngle);

	//!	\brief	�������õ����η�����Ϣ
	//!	\param arrPoints		����㴮����[in]
	//!	\param arrDirectType    ��������[out]
	//!	\param arrArcDirections ���η�������[out]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE��
	UGbool GetArcDirections(UGPoint2Ds& arrPoints, UGArray<UGbyte>& arrDirectType,UGArray<UGdouble>& arrArcDirections);
	//}}��ʹ����

	//!	\brief	��һ�������õ������Ϣ
	//!	\param pntNode	    ���������[in]
	//!	\param nArcID       ����ID[out]
	//!	\param nNodeID      �ڵ�ID[out]
	//!	\param dPos         �ڻ�����ռ�ٷֱ�[out]
	//!	\param shtDirection ���η���[out]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE.
	UGbool GetAnalyseNode(const UGPoint2D& pntNode,UGint& nArcID,UGint& nNodeID,UGdouble &dPos,UGshort &shtDirection);

	//!	\brief	��������ڵ������Դ����
	//!	\param pCostValues	        ��������ָ��[in]
	//!	\param pTurnCost            ת�򻨷�ָ��[in]
	//!	\param IniMemory            �ڴ�ṹ[in]
	//!	\param arrCenters           ���ĵ�����[in]
	//!	\param arrNodeDemand        ���������[in]
	//!	\param arrbtDemandAllocated	���������ʶ����[in]
	//!	\param arrDemandNodeIndex   ����ڵ�����[in]
	//!	\param nCenterIndex         ���ĵ�����[in]
	//!	\param resRoute             ��������·��[in]
	//!	\return �ɹ�:���ط��仨�ѣ����򷵻�-1.0.
	UGdouble AllocateNode(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,
		UGArray<UGchar>&arrbtDemandAllocated,UGArray<UGuint> &arrDemandNodeIndex,UGint nCenterIndex,UGRoute &resRoute);
	
	//!	\brief	�������绡�ν�����Դ����
	//!	\param pCostValues	        ��������ָ��[in]
	//!	\param pTurnCost            ת�򻨷�ָ��[in]
	//!	\param IniMemory            �ڴ�ṹ[in]
	//!	\param arrCenters           ���ĵ�����[in]
	//!	\param arrNodeDemand        ���������[in]
	//!	\param arrbtDemandAllocated	���������ʶ����[in]
	//!	\param arrDemandNodeIndex   ����ڵ�����[in]
	//!	\param nCenterIndex         ���ĵ�����[in]
	//!	\param resRoute             ��������·��[in]
	//!	\return �ɹ�:���ط��仨�ѣ����򷵻�-1.0.
	UGdouble AllocateArc(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,UGint nCenterIndex,UGRoute &resRoute);
	
	//!	\brief	��������ڵ�����绡�ν�����Դ����
	//!	\param pCostValues	        ��������ָ��[in]
	//!	\param pTurnCost            ת�򻨷�ָ��[in]
	//!	\param IniMemory            �ڴ�ṹ[in]
	//!	\param arrCenters           ���ĵ�����[in]
	//!	\param arrNodeDemand        ���������[in]
	//!	\param arrbtDemandAllocated	���������ʶ����[in]
	//!	\param arrDemandNodeIndex   ����ڵ�����[in]
	//!	\param nCenterIndex         ���ĵ�����[in]
	//!	\param resRoute             ��������·��[in]
	//!	\return �ɹ�:���ط��仨�ѣ����򷵻�-1.0.
	UGdouble AllocateNodeAndArc(UGCostValues *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,UGint nCenterIndex,UGRoute &resRoute);
	
	//!	\brief	������С���ѽ��з���
	//!	\param arrCenters      ���ĵ�����[in]
	//!	\param pdLocationMtx   ���Ѿ������[in]
	//!	\param nLocations	   ���ĵ����[in]
	//!	\param arrLocationID   ���䶨λID����[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE.
	UGbool LocateMinCost(UGArray<UGCenterNode> &arrCenters,UGdouble* pdLocationMtx, UGint nLocations,UGArray<UGuint> &arrLocationID);
	
	//!	\brief	����������󸲸ǰ�������ڵ������Դ����
	//!	\param pCostValues	   ��������ָ��[in]
	//!	\param pTurnCost       ת�򻨷�ָ��[in]
	//!	\param IniMemory       �ڴ�ṹ[in]
	//!	\param arrCenters      ���ĵ�����[in]
	//!	\param arrNodeDemand   ��������[in]
	//!	\param pdLocationMtx   ���Ѿ������[in]
	//!	\param nLocations	   ���ĵ����[in]
	//!	\param ResultInfo	   ����ṹ[in]
	//!	\param arrLocationID   ���䶨λID����[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE.
	//! \remarks ѡַ����ʹ�ô���.
	UGbool LocateMaxCover(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,
		UGdouble* pdLocationMtx,UGint nLocations,UGResultInfo& ResultInfo,UGArray<UGuint> &arrLocationID);
	
	//!	\brief	��ȡ��С���ĵ���Ŀ ����������󸲸ǰ�������ڵ������Դ����
	//!	\param pCostValues	   ��������ָ��[in]
	//!	\param pTurnCost       ת�򻨷�ָ��[in]
	//!	\param IniMemory       �ڴ�ṹ[in]
	//!	\param arrCenters      ���ĵ�����[in]
	//!	\param arrNodeDemand   ��������[in]
	//!	\param pdLocationMtx   ���Ѿ������[in]
	//!	\param nLocations	   ���ĵ����[in]
	//!	\param ResultInfo	   ����ṹ[in]
	//!	\param arrLocationID   ���䶨λID����[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE.
	//! \remarks ѡַ����ʹ�ô���:��ȡ��С���ĵ���Ŀ ����������󸲸ǰ�������ڵ������Դ���䣬
	//! ���û�и������ĵ���������Լ�����С������������ĵ����
	UGbool LocateMaxCover(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,
		                  UGdouble* pdLocationMtx,UGResultInfo& ResultInfo,UGArray<UGuint> &arrLocationID);

	//!	\brief	������СȨ���ѽ��з���
	//!	\param arrCenters      ���ĵ�����[in]
	//!	\param pdLocationMtx   ���Ѿ������[in]
	//!	\param nLocations	   ���ĵ����[in]
	//!	\param arrLocationID   ���䶨λID����[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE.
	UGbool LocateMinPowerCost(UGArray<UGCenterNode> &arrCenters,UGdouble* pdLocationMtx, UGint nLocations,UGArray<UGuint> &arrLocationID);
	
	//!	\brief	������СȨ���ѽ��з���
	//!	\param pdLocationMtx   ���Ѿ������[in]
	//!	\param nLocations	   ���ĵ����[in]
	//!	\param arrLocationID   ���䶨λID����[in]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE.
	UGbool LocateMaxAttend(UGdouble* pdLocationMtx, UGint nLocations,UGArray<UGuint> &arrLocationID);
	
	//!	\brief	�õ�����ľ������
	//!	\param pCostValues	   ��������ָ��[in]
	//!	\param pTurnCost       ת�򻨷�ָ��[in]
	//!	\param IniMemory       �ڴ�ṹ[in]
	//!	\param arrCenters      ���ĵ�����[in]
	//!	\param arrNodeDemand   �����ID����[in]
	//!	\param pdLocationMtx   ���Ѿ������[out]
	//!	\return �ɹ�:����TRUE�����򷵻�FALSE.
	UGbool GetLocationMtx(UGCostValues  *pCostValues,TurnCost*pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,UGdouble* pdLocationMtx);
	
	//!	\brief	�����̷��������ӽӿ�
	UGdouble TSPAnalyse(UGdouble* pdTSPMtx,UGint nDimension,UGArray<UGuint> &arrOrdinalIndex,UGint nIterations);
	
	//!	\brief	�����̷��������ӽӿڼ����Լ����
	UGdouble GetTSPDivMatrix(UGdouble* pdDivMtx,UGint nCount);

	//!	\brief	�������̷������ڻ���
	UGbool IniAssign(UGArray<UGuint>* parrMTSP, MTSPInfo* pSN_SNIndexMtx, MTSPInfo* pNN_SNIndexMtx,
							DemandNode* pFirstNode, UGdouble* pdServiceCost, UGint* pnSigned, UGint nMCount,
							UGint nNodeCount);
	
	//!	\brief	�������̷������ڻ���
	UGbool Adjust(UGArray<UGuint>* parrMTSP, MTSPInfo* pSN_SNIndexMtx, MTSPInfo* pNN_SNIndexMtx,
					UGdouble* pdServiceCost, UGint* pnSigned, UGint nMCount, UGint nNodeCount);

	//!	\brief	�������̷����ٴε��ڻ���
	UGbool AdjustBak(UGArray<UGuint>* parrMTSP, MTSPInfo* pSN_SNIndexMtx, MTSPInfo* pNN_SNIndexMtx,
					UGdouble* pdServiceCost, UGint* pnSigned, UGint nMCount, UGint nNodeCount);
	
	//!	\brief	�������̷������ڻ���
	UGbool GSX(UGArray<UGuint>* parrMTSP, MTSPInfo* pSN_SNIndexMtx, MTSPInfo* pNN_SNIndexMtx,
				UGdouble* pdServiceCost, UGint* pnSigned, UGint nMCount, UGint nNodeCount);
	
	//!	\brief	�������̷������ڻ���
	UGdouble GetReduceCost(UGArray<UGuint>& arrNodeIndexs, 
										UGint nReduceServiceIndex, 
										UGint nMinNodeIndex, 
										MTSPInfo* pSN_SNIndexMtx, 
										MTSPInfo* pNN_SNIndexMtx,
										UGint nNodeCount,UGint& nRemovePos);
	//!	\brief	�������̷������ڻ���
	UGdouble FindInsertPos(UGArray<UGuint>& arrNodeIndexs, 
										UGint nServiceIndex, UGint nNodeIndex, 
										UGint& nInsertPos,
										MTSPInfo* pSN_SNIndexMtx, 
										MTSPInfo* pNN_SNIndexMtx,
										UGint nNodeCount);

	//!	\brief	�������̷������ڻ���
	UGdouble FindInsertPos(UGArray<UGuint>& arrNodeIndexs, UGArray<UGuint>& arrServiceIndexs, 
							MTSPInfo* pSN_SNIndexMtx, MTSPInfo* pNN_SNIndexMtx,
							UGint nNodeCount, UGint nServiceIndex, UGint nFromIndex, 
							UGint nInsertCount,UGint& nInsertPos, UGbool& bReverse);
	//!	\brief	�������̷������ڻ���
	UGbool GetPCenterTable(UGdouble* pdLocationMtx,UGint nLocations,UGint*& pLocation,UGdouble* pdparam);

//	UGbool ShortestPath(UGint nStartID,UGArray<UGuint> &arrTSPIDs,UGdouble *pdDist);
	
//	UGbool ShortestPath(UGPoint2D pntStart,UGPoint2Ds &arrViaNode,UGdouble *pdDist);

//	UGdouble FindPath(const UGPoint2D& pntStart,const UGPoint2D& pntEnd,UGRoute &resRoute,
//		UGbool bLeastArcs=FALSE,UGbool bSaveRoute=TRUE);
	
//	UGdouble ShortestPath(UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID,UGbool bSaveArc=TRUE);

	//·�������õ��������

	//!	\brief	���·������
	UGdouble ShortestPath(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	���·������
	UGbool ShortestPathGroup(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nStartID,UGint* pEndIDs,UGint nCount,UGdouble* pdEndCost);
	
//	UGdouble ShortestPathP(UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID,UGint nStartArc=-1,UGint nEndArc=-1,
//		UGbool bSaveArc=TRUE);

	//!	\brief	���·������
	UGdouble ShortestPathP(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID,UGArray<UGuint> &arrNodeID,UGint nStartArc=-1,UGint nEndArc=-1,
		UGbool bSaveArc=TRUE);
	
//	UGdouble LeastArcsPath(UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID);

	//·�������õ��������
	//!	\brief	���·���������θ�������
	UGdouble LeastArcsPath(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	�ҵ����⻡��ԭ�����ڵĻ���
	// nVirtualArcID ���⻡�ε�ID
	// nRelArcID ���ص���ʵ����ID
	// dFromPos ���⻡��FNode�� nRelArcID��ʼ���ε�λ�� 0--1֮��
	// dToPos ���⻡��TNode�� nRelArcID��ʼ���ε�λ�� 0--1֮��
	// dArcCost nRelArcID������cost
	// dArcCostBak nRelArcIDBak������cost
	UGbool FindIDByVirtualArcID(UGint nVirtualArcID,UGint & nRelArcID ,
				UGdouble & dFromPos,UGdouble & dToPos,UGdouble & dArcCost,UGdouble &dArcCostBak);

	//!	\brief ��ȡ��������
	// nSiteCount ��ĸ���
	UGbool GetServiceRegion(UGArray<UGGeoLineM>& arrRoute,UGint nSiteCount,UGint *pnRelation,UGArray<UGGeoRegion> & ArrServiceRegion );	
	
	//!	\brief �õ�ÿ�����ĵ��ֵ
	UGdouble GetEachCenterValue(UGint nCenterIndex,UGdouble* pdLocationMtx,UGdouble* pdparam);
	
	
	// ����������
	//!	\brief �õ����񸲸�����Ϣ
	UGbool GetCoverSign(UGCostValues  *pCostValues,TurnCost* pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nCenterIndex, UGArray<UGuint> &arrFacilityID, UGint nCount,UGArray<UGuint> &arrResFacIndex, UGdouble dCoverCost);

	//!	\brief �õ����񸲸�����Ϣ
	UGbool GetCoverSign(UGCostValues  *pCostValues,TurnCost* pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nCenterIndex,UGuchar* &pbtOnPath,UGdouble* &pdNodeCost,UGdouble dCoverCost,
		UGint nCenterArc=-1,UGdouble dSiteCost=-1.0,UGdouble dNeighborCost=-1.0);
	
	//������������
	//!	\brief ��ȡ��������Ľ��cost
	UGbool GetCoverSign(UGCostValues  *pCostValues,TurnCost* pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		const UGArray<UGuint> & nArrSiteID,const UGArray<UGdouble> & dArrServiceCost,	
		UGArray< UGshort*> & BArrOnPathPre,	UGArray< UGdouble*> & dArrNodeCostPre);

	//!	\brief �߷���
	// BArrOnPathPre ���з������ĵ��ǰ�������Ϣ
	// dArrNodeCostPre ���ĵ�Ļ���
	// dArrServiceCost �������ĵ�ķ���Χ
	// bPntFind ����������������������
	UGbool AllotArcService(UGCostValues  *pCostValues ,UGIniMemory &IniMemory,const UGArray< UGshort*> & BArrOnPathPre ,const UGArray< UGdouble* > & dArrNodeCostPre,
		const UGArray<UGdouble > & dArrServiceCost,UGArray<UGdouble> & dArrSiteCost ,UGArray<UGGeoLineM>& arrRoute,
		UGbool bPntFind = FALSE );

	//!	\brief ��ø����������ĵ㣨���㣩�ĵ�����ϵ ������m_pnRelation��
	UGbool GetRelation(UGint nSiteCount,UGint *pnRelation,const UGArray<UGuint> & nArrSiteID,const UGArray<UGdouble> & dArrServiceCost,
		const UGArray< UGshort*> & BArrOnPathPre ,const UGArray< UGdouble*> & dArrNodeCostPre);

	//!	\brief ���ݸ�����routid ͳ�� ���linem���ݼ��е�linem����
	UGdouble StatisticLength(UGint nRouteID);

	//!	\brief �ڷ���������֮�� ��CoverCost �� CoverLength ���뵽��������ݼ���
	// dArrSiteCost ��ʾÿ�����ĵ�� CoverCost
	// CoverLength Ҫͳ�Ƹ��� LineM �� Length ֮��
	UGbool AddCostAndLength(UGArray<UGdouble> & dArrSiteCost,ResultInfo &ResInfo);
	
	//!	\brief �õ��������̻��Ѿ���
	UGbool GetCostMtx(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGArray<UGuint>& arrTotalNodeIDs, MTSPInfo* pNodeMtx);

	//!	\brief �õ��������̻��Ѿ���
	UGbool GetCostMtx(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGArray<UGuint>& arrServiceIDs, UGArray<UGuint>& arrNodeIDs, MTSPInfo* pCostMtx);
	
	//!	\brief �õ��������̻��Ѿ���
	UGbool GetCostMtx(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGArray<UGuint>& arrNodeIDs, UGdouble* pCostMtx);

	//!	\brief �õ��������̻��Ѿ���
	UGbool GetCostMtx(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGPoint2Ds& arrTotalNodeIDs, MTSPInfo* pNodeMtx);

	//!	\brief �õ��������̻��Ѿ���
	UGbool GetCostMtx(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGPoint2Ds& arrServiceIDs, UGPoint2Ds& arrNodeIDs, MTSPInfo* pCostMtx);

	//!	\brief ���·������
	UGbool ShortestPath(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,UGint nStartID,
		UGArray<UGuint> &arrTSPIDs,UGdouble *pdDist,UGArray<UGint> *parrPreArcID=NULL,UGArray<UGint> *parrPreNodeID=NULL);
	
	//!	\brief ���·������
	UGbool ShortestPath(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,UGint nStartID, UGArray<UGuint> &arrTSPIDs, UGdouble *pdDist, UGint *pnArcID, UGint *pnNodeID, 
						UGdouble *pdPos, UGint *pnPreArcID);

	//!	\brief �ֲ��Ż�����
	void LocalOptimize(MTSPInfo *pNN_CostMtx, UGint nNodeCount, UGArray<UGuint>& arrNodeIndexs, UGdouble& dTotalCost);
	
	//!	\brief	�����̷�����������ڵ�����ӽӿ�
	UGdouble FindTSPPath(const UGAnalyseParams &AnalyseParams,UGResultInfo &ResInfoOut,UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGuint> &arrNodeIDs, UGArray<UGuint> &arrOrderIndexs, UGbool bEndNodeSigned=TRUE,
						UGbool bReturnStart=TRUE);

	//!	\brief	�����̷����������������ӽӿ�
	UGdouble FindTSPPath(const UGAnalyseParams &AnalyseParams,UGResultInfo &ResInfoOut,UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGPoint2Ds &arrNodeIDs, UGArray<UGuint> &arrOrderIndexs, UGbool bEndNodeSigned=TRUE,
						UGbool bReturnStart=TRUE);

	//!	\brief	ת����Ϣ
	UGbool GetTurnCostValue(UGString strTurnCost,TurnCost*& pTurnCost);

	//!	\brief	�õ�����·��
	//! \param BArrOnPathPre ���з������ĵ��ǰ�������Ϣ
	//! \param dArrNodeCostPre ���ĵ�Ļ���
	//! \param nSite ��ǰ�������ĵ�
    //! \param pnMinCost ���н���л�����С�ķ������ĵ�
	//! \param dArrServiceCost �������ĵ�ķ���Χ
	//! \param CoverRoute ���ؽ��
	UGbool GetCoverRoute(const UGArray< UGshort*> & BArrOnPathPre ,const UGArray< UGdouble*> & dArrNodeCostPre,
		UGint nSite,const UGint  * pnMinCost ,	const UGArray<UGdouble> & dArrServiceCost,
		UGRoute &CoverRoute, UGint nSiteArcID = -1 );

	//!	\brief	�õ�����·��
	UGdouble GetCoverRoute(UGCostValues  *pCostValues,UGBarriers&Barriers,
		UGuchar* pbtOnPath,UGdouble* pdNodeCost,UGdouble dCoverCost,UGRoute &CoverRoute,UGArray<UGuint> arrNodeIDs,UGint nSiteArcID = -1);
	
	//!	\brief	�õ�������
	UGbool GetCoverRegion(UGuchar* pbtOnPath,UGdouble* pdNodeCost,UGdouble dCoverCost,UGGeoRegion &ServiceRegion);

	//!	\brief	�õ�������
	UGbool GetCoverRegion(UGArray<UGGeoLineM>&arrRoute,UGGeoRegion &CoverRegion);

	//!	\brief	���䵥������
	//! \param  nCenterIndex ��������[in]
	//!	\param pdCost ��������[in]
	//!	\return ���ط��䵥��������С����
	UGdouble AllocateSingleCenter(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,UGint nCenterIndex, UGdouble* pdCost);
};

}

#endif 
