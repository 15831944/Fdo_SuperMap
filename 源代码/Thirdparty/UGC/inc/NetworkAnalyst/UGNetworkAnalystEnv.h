/* 
	\file UGNetworkAnalystEnv.h
	\brief �����������������
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/
#ifndef UGNETWORKANALYSTENV_H
#define UGNETWORKANALYSTENV_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Geometry/UGGeoLineM.h"
#include "NetworkAnalyst/UGNetworkTypes.h"
#include "Engine/UGDataSource.h"
#include "NetworkAnalyst/UGRoute.h"

namespace UGC {

class UGDatasetVector;

class NETWORKANALYST_API UGNetworkAnalystEnv  
{
public:
	UGNetworkAnalystEnv();
	
	virtual ~UGNetworkAnalystEnv();
	
	enum UGResultInfoType
	{
		UGRIRoutes			= 0x00000001,	//
		UGRIPathTable		= 0x00000002,	//
		UGRIPathGuides		= 0x00000002,	//
		UGRIViaEdges		= 0x00000004,	//
		UGRIViaNodes		= 0x00000008,	//
		UGRIServiceRegions	= 0x00000010,	//
		UGRILocationCenters	= 0x00000020,	//
		UGRILocationNodes	= 0x00000040,	//
		UGRIPathStops		= 0x00000080,	//
	};

	enum DirectionConstant
	{
		DC_EAST				= 0, // ��
		DC_NORTH_EAST		= 1, // ����
		DC_NORTH			= 2, // ��
		DC_NORTH_WEST		= 3, // ����
		DC_WEST				= 4, // ��
		DC_SOUTH_WEST		= 5, // ����
		DC_SOUTH			= 6, // ��
		DC_SOUTH_EAST		= 7, // ����
	};
	
	typedef UGArray<UGTurnCost*> TurnCost;
public:
	/*!	\brief	�����������ݼ�*/
	UGbool SetDatasetNetwork(UGDatasetVector* pDtNetwork);
	/*!	\brief	��ȡ�������ݼ�*/
	const UGDatasetVector* GetDatasetNetwork()const;
	/*!	\brief	��������Ȩֵ�ֶ�*/
	void SetFTWeightField(const UGString& strFTWeight);
	/*!	\brief	��ȡ����Ȩֵ�ֶ�*/
	const UGString& GetFTWeightField()const;
	/*!	\brief	���÷���Ȩֵ�ֶ�*/
	void SetTFWeightField(const UGString& strTFWeight);
	/*!	\brief	��ȡ����Ȩֵ�ֶ�*/
	const UGString& GetTFWeightField()const;
	/*!	\brief	���ýڵ�ID�ֶ�*/
	void SetNodeIDField(const UGString& strNodeIDField);
	/*!	\brief	��ȡ�ڵ�ID�ֶ�*/
	const UGString& GetNodeIDField()const;
	/*!	\brief	���û���ID�ֶ�*/
	void SetArcIDField(const UGString& strArcIDField);
	/*!	\brief	��ȡ����ID�ֶ�*/
	const UGString& GetArcIDField()const;
	/*!	\brief	����FNodeID�ֶ�*/
	void SetFNodeIDField(const UGString& strFNodeIDField);
	/*!	\brief	��ȡFNodeID�ֶ�*/
	const UGString& GetFNodeIDField()const;
	/*!	\brief	����TNodeID�ֶ�*/
	void SetTNodeIDField(const UGString& strTNodeIDField);
	/*!	\brief	��ȡFNodeID�ֶ�*/
	const UGString& GetTNodeIDField()const;
	
	/*!	\brief	����ת���*/
	UGbool SetDatasetTRN(UGDatasetVector* pDtTRN);
	/*!	\brief	��ȡת���*/
	const UGDatasetVector* GetDatasetTRN()const;
	/*!	\brief	����TRN�ڵ�ID�ֶ�*/
	void SetTRNNodeIDField(const UGString& strTRNNodeID);
	/*!	\brief	��ȡTRN�ڵ�ID�ֶ�*/
	const UGString& GetTRNNodeIDField()const;
	/*!	\brief	����TRN��ʼ����ID�ֶ�*/
	void SetTRNArcFromIDField(const UGString& strTRNArcFromID);
	/*!	\brief	��ȡTRN��ʼ����ID�ֶ�*/
	const UGString& GetTRNArcFromIDField()const;
	/*!	\brief	����TRN��ֹ����ID�ֶ�*/
	void SetTRNArcToIDField(const UGString& strTRNArcToID);
	/*!	\brief	��ȡTRN��ֹ����ID�ֶ�*/
	const UGString& GetTRNArcToIDField()const;
	/*!	\brief	����TRNWeight�ֶ�*/
	void SetTRNWeightField(const UGString& strTRNWeight);
	/*!	\brief	��ȡTRNWeight�ֶ�*/
	const UGString& GetTRNWeightField()const;
	
	/*!	\brief	��������ڵ��*/
	UGbool SetDatasetDMDNode(UGDatasetVector* pDtDMDNode);
	/*!	\brief	��ȡ����ڵ��*/
	const UGDatasetVector* GetDatasetDMDNode()const;
	/*!	\brief	�������󻡶α�*/
	UGbool SetDatasetDMDArc(UGDatasetVector* pDtDMDArc);
	/*!	\brief	��ȡ���󻡶α�*/
	const UGDatasetVector* GetDatasetDMDArc()const;
	/*!	\brief	���ýڵ��������ֶ�*/
	void SetNodeDemandField(const UGString& strNodeDemand);
	/*!	\brief	��ȡ�ڵ��������ֶ�*/
	const UGString& GetNodeDemandField()const;
	/*!	\brief	���û����������ֶ�*/
	void SetArcDemandField(const UGString& strArcDemand);
	/*!	\brief	��ȡ�����������ֶ�*/
	const UGString& GetArcDemandField()const;
	
	/*!	\brief	�������ĵ����ݼ�*/
	UGbool SetDatasetCenter(UGDatasetVector* pDtCenter);
	/*!	\brief	��ȡ���ĵ����ݼ�*/
	const UGDatasetVector* GetDatasetCenter()const;

	/*!	\brief	��������ID�ֶ�*/
	void SetCenterIDField(const UGString& strCenterID);
	/*!	\brief	��ȡ����ID�ֶ�*/
	const UGString& GetCenterIDField()const;
	/*!	\brief	���ú�ѡ�����ֶ�*/
	void SetCenterCandidateField(const UGString& strCenterCandidate);
	/*!	\brief	��ȡ��ѡ�����ֶ�*/
	const UGString& GetCenterCandidateField()const;
	/*!	\brief	����������Դ���ֶ�*/
	void SetCenterResourceField(const UGString& strCenterResource);
	/*!	\brief	��ȡ������Դ���ֶ�*/
	const UGString& GetCenterResourceField()const;
	/*!	\brief	�������������ֵ�ֶ�*/
	void SetCenterMaxImpedanceField(const UGString& strCenterMaxImpedance);
	/*!	\brief	��ȡ���������ֵ�ֶ�*/
	const UGString& GetCenterMaxImpedanceField()const;
	
	/*!	\brief	���û��ι����ֶ�*/
	void SetArcFilter(UGString strArcFilter);
	/*!	\brief	��ȡ���ι����ֶ�*/
	const UGString& GetArcFilter()const;
	
	/*!	\brief	���õ�·�����ֶ�*/
	void SetRoadRuleField(UGString strRoadRule);
	/*!	\brief	���������е�*/
	void SetLanePositive(UGArray<UGint> &arr_Lane_Positive);
	/*!	\brief	���������е�*/
	void SetLaneNegative(UGArray<UGint> &arr_Lane_Negative);
	/*!	\brief	���ý��е�·*/
	void SetNOEntry(UGArray<UGint> &arr_NO_Entry);
	/*!	\brief	����˫�е�*/
	void SetBothDirection(UGArray<UGint> &arr_Both_Direction);
	
	/*!	\brief	������ʹ�����к��ν�������ֶ�*/
	void SetPathGuideNameField(const UGPathGuideName& strPathFeildNames);
	
	/*!	\brief	��ȡ��ʹ�����к��ν�������ֶ�*/
	const UGPathGuideName& GetPathGuideNameField()const;
	
	/*!	\brief	���ýڵ�ѡ������*/
	void SetNodeInterval(UGdouble dNodeInterval);
	/*!	\brief	��ȡ�ڵ�ѡ������*/
	UGdouble GetNodeInterval()const;
	
	/*!	\brief	���ù�����·Ȩֵ�ֶ�*/
	void SetBusCostFields(const UGArray<UGString> &arrCostFields);
	UGbool GetBusCostFields(UGArray<UGString> &arrBusCostFields);
	
	
	
	UGDatasetVector* CreateResultRouteDT(const UGString& strResultRoute,UGArray<UGGeoLineM>  &arrRoute,UGbool bMSiteAnalyst = FALSE );
	
	//!	\brief	���ô�Ž��������Դ\n
	//!	\param	pOutputDataSource		����Դָ��
	//!	\return	���óɹ�����TRUE�����򷵻�FALSE��
	//!  \remarks	����Դָ�벻Ϊ�գ�����ReadOnly��
	UGbool SetOutputDataSource(UGDataSource* pOutputDataSource);
	
	/*!	\brief	�õ��������Դָ��*/
	UGDataSource* GetOutputDataSource();
	
	/*!	\brief	���ý�������ֶ�*/
	void SetNodeType(UGString strNodeType);
	/*!	\brief	��ȡ��������ֶ�*/
	const UGString& GetNodeType()const;
	/*!	\brief	���������ֶ�*/
	void SetDirection(UGString strDirection);
	/*!	\brief	��ȡ�����ֶ�*/
	const UGString& GetDirection()const;
	
	UGbool GetGeoLineM(UGint nStartNodeID, UGArray<UGuint>& arrArcIDs, UGArray<UGdouble>& arrCost);
	UGbool GetGeoLineM(UGint nStartNodeID, UGArray<UGuint>& arrArcID, UGdouble dTotalCost,UGArray<UGGeoLineM>& arrRoute);
	
	UGbool GetGeoLineM(UGPoint2D pntStart, UGRoute &resRoute,UGdouble dTotalCost);

	UGbool GetGeoLineM(UGRoute &resRoute, UGdouble dTotalCost,UGArray<UGGeoLineM>&arrRoute);
    //! Ϊ��Դ�����������ӵĽӿ�
	UGbool GetAllcateGeoLineM(UGRoute &resRoute, UGdouble dTotalCost,UGArray<UGGeoLineM>&arrRoute,UGArray<UGuint> &arrNodeIDAllocated,UGArray<UGuint> &arrArcIDAllocated);
	
	//�����Ϣ����
	//!	\brief �Ƿ����ɽ��
	UGbool IsRoute(const ResultInfo &nResultInfo);
	//!	\brief �Ƿ����ɽ��
	UGbool IsPathTable(const ResultInfo &nResultInfo);
	//!	\brief �Ƿ����ɽ��
	UGbool IsViaEdge(const ResultInfo &nResultInfo);
	//!	\brief �Ƿ����ɽ��
	UGbool IsViaNode(const ResultInfo &nResultInfo);
	//!	\brief �Ƿ����ɽ��
	UGbool IsRegion(const ResultInfo &nResultInfo);
	//!	\brief �Ƿ����ɽ��
	UGbool IsLocationCenters(const ResultInfo &nResultInfo);
	//!	\brief �Ƿ����ɽ��
	UGbool IsLocationNodes(const ResultInfo &nResultInfo);
	//!	\brief �Ƿ����ɽ��
	UGbool IsStops(const ResultInfo &nResultInfo);
	//��ʹ����
	//!	\brief �Ƿ����ɽ��
	UGbool IsPathGuide(const ResultInfo &nResultInfo);
	//!	\brief ���ɽ��
	UGbool GetStops(const ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID, UGArray<UGdouble>& arrCost);
	//!	\brief ���ɽ��
	UGbool GetServiceViaEdge( ResultInfo &nResultInfo,UGRoute& ServiceRoute);
	//!	\brief ���ɽ��
	UGbool GetServiceViaNode( ResultInfo &nResultInfo,UGuchar* pbtOnPath);
	//!	\brief ���ɽ��
	UGbool GetViaNode( ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID, UGint nRouteCount);
	//!	\brief ���ɽ��
	UGbool GetViaNode( ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID);
	//!	\brief ���ɽ��
	UGbool GetViaNode( ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID, UGArray<UGint>& arrViaCount);
	//!	\brief ���ɽ��
	UGbool GetViaEdge( ResultInfo &nResultInfo,UGArray<UGuint>& arrArcID, UGint nRouteCount);
	//!	\brief ���ɽ��
	UGbool GetViaEdge( ResultInfo &nResultInfo,UGArray<UGuint>& arrArcID);
	//!	\brief ���ɽ��
	UGbool GetViaEdge( ResultInfo &nResultInfo,UGArray<UGuint>& arrArcID, UGArray<UGint>& arrViaCount);
	//!	\brief ���ɽ��
	UGbool GetRegion(UGArray<UGGeoRegion>& arrCoverRegion, ResultInfo &nResultInfo);
	//!	\brief ���ɽ��
	UGbool GetRoute(const ResultInfo &nResultInfo,UGArray<UGGeoLineM>& arrRoute,UGbool bMSiteAnalyst = FALSE );
	//!	\brief ���ɽ��
	UGbool GetRoute(const ResultInfo &nResultInfo,UGint nStartNodeID, UGArray<UGuint>& arrArcIDs, UGdouble dTotalCost);
	//!	\brief ���ɽ��
	UGbool GetRoute(const ResultInfo &nResultInfo,const UGPoint2D& pntStartNode, UGRoute& resRoute, UGdouble dTotalCost);
	//!	\brief ���ɽ��
	UGbool GetRoute(const ResultInfo &nResultInfo,UGint nStartNodeID, UGArray<UGuint>& arrArcID, UGArray<UGdouble> &arrCost);
	//!	\brief ���ɽ��
	UGbool GetRoute(const ResultInfo &nResultInfo,const UGPoint2D& pntStart, UGArray<UGRoute>& arrArcIDs, UGArray<UGdouble>& arrFacilityDist);


	//�ж��Ƿ���Ҫ����·��
	UGbool IsRoute(UGint nOptions);
	
	//�ж��Ƿ���Ҫ������ʻ����
	UGbool IsPathGuide(UGint nOptions);
	
	//�ж��Ƿ���Ҫ���ɾ���������Ϣ
	UGbool IsViaEdge(UGint nOptions);
	
	//�ж��Ƿ���Ҫ���ɾ�������ڵ���Ϣ
	UGbool IsViaNode(UGint nOptions);
	
	//�ж��Ƿ���Ҫ����վ����Ϣ
	UGbool IsStops(UGint nOptions);
	
	//�ж��Ƿ���Ҫ���ɾ�����������
	UGbool IsRegion(UGint nOptions);
	
	//�ж��Ƿ���Ҫ������Դ�������ĵ���Ϣ
	UGbool IsLocationCenters(UGint nOptions);
	
	//�ж��Ƿ���Ҫ����ѡַ���ĵ���Ϣ
	UGbool IsLocationNodes(UGint nOptions);
	
	//�ж��Ƿ���Ҫ����PathTable
	UGbool IsPathTable(UGint nOptions);

	//!	\brief	���ɲ�ѯ�ַ������ʽ
	//!	\param  arrKeys IDs����[in] 
	//!	\param  strFieldName ָ����ѯ�������ݼ��ֶ�����[in] 
	//!	\return	��ѯ�ַ������ʽ
	//!  \remarks ���ݿ��ѯ��ʱ�򣬶�ָ���ֶε�IDs��ѯ
	UGString BuildQueryFilter(UGArray<UGuint> &arrKeyIDs,const UGString strFieldName);

	//{{����ĺ�������������ʹ�����ı�����ʽ
	//!	\brief	������ת��Ϊ�ַ�������
	//!	\param nDirection ����λ�ò���[in] 
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGString GetDirection(UGint nDirection);
	
	//!	\brief	ת��Ϊת�����
	//!	\param nViaTurnType ת��λ�ò���[in] 
	//!	\return	ת���ַ�������;
	//!  \remarks
	UGString GetVia2RoadPosition(UGint nViaTurnType);
	
	//!	\brief	���Ƕ�ת��Ϊ�˸���λ
	//!	\param dDegree �Ƕ�[in] 
	//!	\return	���Ƕ�ת��Ϊ�˸���λ;
	//!  \remarks
	DirectionConstant GetDirectionByDegree(UGdouble dDegree);
	
	//!	\brief	�õ�·���ķ���
	//!	\param nDirection ��λ[in] 
	//!	\return	·��������ַ���;
	//!  \remarks
	UGString GetRoadDirection(DirectionConstant nDirection);
    //}}
	
	//!	\brief	��NodeIDת��ΪNode����
	//!	\param arrIDs ID����[in] 
	//!	\param arrIndex ��������[out] 
	//!	\return	�ɹ�ת������TRUE�����򷵻�FALSE
	//!  \remarks
	UGbool NodeConvertIDToIndex(UGArray<UGuint> &arrIDs, UGArray<UGuint> &arrIndex);

	//!	\brief	��ArcIDת��ΪArc����
	//!	\param arrIDs ID����[in] 
	//!	\param arrIndex ��������[out] 
	//!	\return	�ɹ�ת������TRUE�����򷵻�FALSE
	//!  \remarks
	UGbool ArcConvertIDToIndex(UGArray<UGuint> &arrIDs, UGArray<UGuint> &arrIndex);

	//!	\brief	������ʹ���������� 
	//!	\param PathGuides ת���ṹ
	//!	\param strPathGuideName ת�������[in]
	//!	\param dTotalCost �ܵĻ���[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool MakePathguides(UGPathGuides& PathGuides, UGString &strPathGuideName,UGdouble dTotalCost);

	//!	\brief	���ɾ�����󱨸��� 
	//!	\param arrDistMatrix �����������[in]
	//!	\param streDistMatrixReportName ������󱨸�����[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool MakeDistMatrixReport(UGArray<UGDistMatrixUnit> &arrDistMatrix, UGString &streDistMatrixReportName);

	//!	\brief	���ɾ�����󱨸���
	//!	\param arrIDs ����[in]
	//!	\param strReportName ��������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool MakeTestArrayReport(UGArray<UGuint> &arrIDs, UGString &strReportName);

	//!	\brief	����·�����ݼ� 
	//!	\param strResultRoute ·�����ݼ�����[in]
	//!	\param arrRoute ·�ɽṹ[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGDatasetVector* MakeRouteDT(const UGString& strResultRoute,UGArray<UGGeoLineM>  &arrRoute,UGbool bCreate = FALSE );
	
	//!	\brief	���ɾ�������ڵ����ݼ� 
	//!	\param strViaNodeName ����ڵ����ݼ�����[in]
	//!	\param arrViaPT ����ڵ�ṹ[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool MakeViaNodeDT( const UGString &strViaNodeName,UGArray<UGViaInfo> &arrViaPT);

	//!	\brief	���ɾ������绡�����ݼ� 
	//!	\param strViaEdgeName ���绡�����ݼ�����[in]
	//!	\param arrViaArc ���绡�νṹ[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool MakeViaEdgeDT( const UGString &strViaEdgeName,UGArray<UGViaInfo> &arrViaArc);

	//!	\brief	���ɾ���վ����Ϣ���ݼ� 
	//!	\param strStopName վ�����ݼ�����[in]
	//!	\param arrViaStop վ��ṹ[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool MakeStopsDT( const UGString &strStopName,UGArray<UGStopInfo> &arrViaStop);

	//!	\brief	�����������ĵ���Ϣ���ݼ� 
	//!	\param strLocationNodeName ��������ݼ�����[in]
	//!	\param arrDemand �����ṹ[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool MakeLocationNodeDT( const UGString &strLocationNodeName,UGArray<UGDemandResInfo>& arrDemand);

	//!	\brief	����ѡַ���ĵ���Ϣ���ݼ� 
	//!	\param strLocationNodeName ѡַ���ĵ����ݼ�����[in]
	//!	\param arrDemand ѡַ���ĵ�ṹ[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool MakeLocationCenterDT( const UGString &strLocationCenterName,UGArray<UGRetCenterInfo>& arrRetCenter);

	//!	\brief	���ɷ�������������Ϣ���ݼ� 
	//!	\param strRegionName �����ݼ�����[in]
	//!	\param arrRegion     ��ṹ����[in]
	//!	\param arrCost       ������Ļ���[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool MakeRegionDT(const UGString &strRegionName,UGArray<UGGeoRegion>& arrRegion,UGArray<UGdouble>& arrCost);


	//!	\brief	�õ�·����Ϣ���� 
	//!	\param ResInfo ����ṹ[in]
	//!	\param arrRoute     ·������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool GetRouteInfo(UGResultInfo &ResInfo,UGArray<UGGeoLineM>& arrRoute);

	//!	\brief	�õ�·����Ϣ���� 
	//!	\param ResInfo ����ṹ[in]
	//!	\param pntStart     ��ʼ������[in]
	//!	\param resRoute     ����·��[in]
	//!	\param dTotalCost   ����·�ɻ���[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool GetRouteInfo(UGResultInfo &ResInfo, UGPoint2D pntStart, UGRoute &resRoute, UGdouble dTotalCost);

	//!	\brief	�õ�·����Ϣ���� 
	//!	\param ResInfo          ����ṹ[in]
	//!	\param pntStart         ��ʼ������[in]
	//!	\param arrresRoutes     ·������[in]
	//!	\param arrFacilityDist  ·�ɻ�������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool GetRouteInfo(UGResultInfo &ResInfo, UGPoint2D pntStart, UGArray<UGRoute>& arrresRoutes, UGArray<UGdouble>& arrFacilityDist);

	//!	\brief	�õ�·����Ϣ���� 
	//!	\param ResInfo          ����ṹ[in]
	//!	\param nStartNodeID     ��ʼ��ID[in]
	//!	\param arrArcID         ����ID����[in]
	//!	\param dTotalCost       �ܹ�����[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool GetRouteInfo(UGResultInfo &ResInfo,UGint nStartNodeID, UGArray<UGuint>& arrArcID, UGdouble dTotalCost);

	//!	\brief	�õ�·����Ϣ���� 
	//!	\param ResInfo          ����ṹ[in]
	//!	\param nStartNodeID     ��ʼ��ID[in]
	//!	\param arrArcID         ����ID����[in]
	//!	\param arrFacilityDist  ·�ɻ�������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool GetRouteInfo(UGResultInfo &nResultInfo,UGint nStartNodeID, UGArray<UGuint>& arrArcIDs, UGArray<UGdouble>& arrFacilityDist);
	
	//!	\brief	�õ���������ڵ���Ϣ���� 
	//!	\param ResInfo          ����ṹ[in]
	//!	\param arrNodeID        �ڵ�ID����[in]
	//!	\param arrViaCount      ������������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//!  \remarks
	UGbool GetViaNodeInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrNodeID, UGArray<UGint>& arrViaCount);

	//!	\brief	�õ���������ڵ���Ϣ���� 
	//!	\param ResInfo          ����ṹ[in]
	//!	\param arrNodeID        �ڵ�ID����[in]
	//!	\param nRouteCount      ��������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks
	UGbool GetViaNodeInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrNodeID, UGint nRouteCount);
	
	//!	\brief	�õ���������������ڵ���Ϣ���� 
	//!	\param ResInfo          ����ṹ[in]
	//!	\param pbtOnPath        ����·����ʶ����[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks
	UGbool GetServiceViaNodeInfo( UGResultInfo& ResultInfo,UGuchar* pbtOnPath);

	//!	\brief	�õ��������绡����Ϣ���� 
	//!	\param ResInfo          ����ṹ[in]
	//!	\param ServiceRoute     ����·��[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks
	UGbool GetServiceViaEdgeInfo( UGResultInfo& ResultInfo,UGRoute& ServiceRoute);

	//!	\brief	�õ��������绡����Ϣ���� 
	//!	\param ResInfo          ����ṹ[in]
	//!	\param arrArcID         ����ID����[in]
	//!	\param arrViaCount      ��������·���ܸ���[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks
	UGbool GetViaEdgeInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrArcID, UGint arrViaCount);

	//!	\brief	�õ��������绡����Ϣ���� 
	//!	\param ResInfo          ����ṹ[in]
	//!	\param arrArcID         ����ID����[in]
	//!	\param arrViaCount      ��������·�ɸ�������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks
	UGbool GetViaEdgeInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrArcID, UGArray<UGint>& arrViaCount);

	//!	\brief	�õ�����վ����Ϣ���� 
	//!	\param ResInfo      ����ṹ[in]
	//!	\param arrNodeID    �ڵ�ID����[in]
	//!	\param arrCost      ��������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks
	UGbool GetStopsInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrNodeID, UGArray<UGdouble>& arrCost);

	//!	\brief	�õ�����վ����Ϣ���� 
	//!	\param ResInfo      ����ṹ[in]
	//!	\param arrNodeID    �ڵ���������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks
	UGbool GetStopsInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrNodeID);


	//!	\brief	�õ���������Ϣ���� 
	//!	\param ResInfo      ����ṹ[in]
	//!	\param arrRoute     ·������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks
	UGbool GetRegionInfo(UGResultInfo &ResInfo,UGArray<UGGeoLineM>& arrRoute);

	//!	\brief	�õ�������Ϣ���� 
	//!	\param ResInfo      ����ṹ[in]
	//!	\param arrCost      ��������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks
	UGbool GetCostInfo(UGResultInfo &ResInfo,UGArray<UGdouble>& arrCost);

	//!	\brief	�õ�������Ϣ���� 
	//!	\param ResInfo      ����ṹ[in]
	//!	\param arrNodeID    �ڵ�����[in]
	//!	\param arrCenterID  ���ĵ�����[in]
	//!	\param arrCost      ��������[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks
	UGbool GetLocationNodesInfo(UGResultInfo &ResInfo,UGArray<UGint>& arrNodeID,UGArray<UGint>& arrCenterID, UGArray<UGdouble>& arrCost);

	//!	\brief	�õ�������Ϣ���� 
	//!	\param ResInfo         ����ṹ[in]
	//!	\param arrCenterIndex  �ڵ�����[in]
	//!	\param arrCenters      ���ĵ�����[in]
	//!	\param arrdCenterCost  ���ĵ㻨������[in]
	//!	\param arrDemand       ���󻨷�����[in]
	//!	\param arrdResource    ��Դ����[in]
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	//! \remarks
	UGbool GetLocationCentersInfo(UGResultInfo &ResInfo,const UGArray<UGuint> &arrCenterIndex,const UGArray<UGCenterNode>&arrCenters,
		const UGArray<UGdouble>& arrdCenterCost,UGArray< UGint>& arrDemand,const UGArray<UGdouble>& arrdResource);

	//!	\brief	�ҽڵ���������
	//! \param  nNodeID ����ID[in]
	//!	\return ����ɹ��ҵ����򷵻����������򷵻أ�1
	UGint FindIndex(UGint nNodeID);

	//!	\brief	�һ�����������
	//! \param  nArcID ����ID[in]
	//!	\return ����ɹ��ҵ����򷵻����������򷵻أ�1
	UGint FindArcIndex(UGint nArcID);

	//!	\brief	�һ�����������
	//! \param  nID ����ID[in]
	//!	\param pArcInfo ����ָ��[in]
	//!	\param nCount ���θ���[in]
	//!	\return ����ɹ��ҵ����򷵻����������򷵻أ�1
	UGint FindIndex(UGint nID,ArcInfo* pArcInfo,UGint nCount);
	
	//!	\brief	��UGint��������
	//! \param  nID  ID[in]
	//!	\param arrIDs IDs����[in]
	//!	\param nCount ����[in]
	//!	\return ����ɹ��ҵ����򷵻����������򷵻أ�1
	UGint FindIndex(UGint nID,UGint* arrIDs,UGint nCount);

	//!	\brief	��NetIndex��������
	//! \param  nID  ID[in]
	//!	\param arrNetIndex NetIndexָ��[in]
	//!	\param nCount ����[in]
	//!	\return ����ɹ��ҵ����򷵻����������򷵻أ�1
	UGint FindIndex(UGint nID,NetIndex* arrNetIndex,UGint nCount);

	//!	\brief	���ϰ���������
	//! \param  nID  ID[in]
	//!	\param arrIDs IDs����[in]
	//!	\param nCount ����ĸ���[in]
	//!	\return ����ɹ��ҵ����򷵻����������򷵻أ�1
	UGbool FindBarrierIndex(UGint nID,UGint* arrIDs,UGint nCount);

	//!	\brief	����nLineID������
	//! \param  nLineID  �� ID[in]
	//!	\param RelRoutes ����·�ɽṹ[in]
	//!	\return ����ɹ��ҵ����򷵻����������򷵻أ�1
	UGint FindIndex(UGint nLineID, UGRelRoutes& RelRoutes);

	//!	\brief	��վ���ǵ�����
	//! \param  nStopID  վ��ID[in]
	//!	\param UGRelStops վ��ṹ[in]
	//!	\return ����ɹ��ҵ����򷵻����������򷵻أ�1
	UGint FindIndex(UGint nStopID, UGRelStops& RelStops);

	//!	\brief	���ڵ㴮����������
	//! \param  pntNode  �����[in]
	//!	\param arrNetIndex ����Ϣ����[in]
	//!	\param nCount ����ĸ���[in]
	//!	\return ����ɹ��ҵ����򷵻����������򷵻أ�1
	UGint FindIndex(UGPoint2D& pntNode, PointIndex* arrNetIndex, UGint nCount);
	
	//!	\brief	�ҽڵ��From���κ�To����
	//! \param  pCostValues  ��������ָ��[in]
	//!	\param nNodeID       �ڵ�ID[in]
	//!	\param nFEdgeID      ��ʼ����ID[out]
	//!	\param nTEdgeID      �յ㻡��ID[out]
	//!	\return ����ɹ��ҵ����򷵻����������򷵻أ�1
	UGdouble GetNodeImp(UGCostValues  *pCostValues,UGint nNodeID, UGint nFEdgeID, UGint nTEdgeID);

	//!	\brief  �һ��ε������յ�ID
	//! \param  pCostValues  ��������ָ��[in]
	//!	\param nEdgeID       ����ID[in]
	//!	\param nFNodeID      �������ID[out]
	//!	\param nTNodeID      �����յ�ID[out]
	//!	\return ����ɹ��ҵ����򷵻����������򷵻أ�1
	UGdouble GetEdgeImp(UGCostValues  *pCostValues,UGint nEdgeID, UGint nFNodeID, UGint nTNodeID);

	//!	\brief	�õ�·�ɺ���
	//! \param  arrRoute  ·������ID[in]
	//!	\param resRoute ����·��[in]
	//!	\param nArrReAllotRoutID ʵ�ʷ���ID����[in]
	//!	\return ����ɹ��ҵ����򷵻�TRUE�����򷵻�FALSE
	UGbool GetGeoLineM(UGArray<UGGeoLineM>& arrRoute,UGRoute &resRoute,const UGArray< UGint > & nArrReAllotRoutID );
	
	//{{���߳�֧��
	//!	\brief	���������ֶκ���
	//! \param  arrCostFields  �����ֶνṹ[in]
	//!	\return 
	void SetCostFields(const UGArray<UGCostFields> &arrCostFields);

	//!	\brief	�õ������ֶα�������
	//! \param  arrCostName  ��������[in]
	//!	\return ����ɹ��ҵ����򷵻�TRUE�����򷵻�FALSE.
	UGbool GetCostName(UGStrArray &arrCostName);

	//!	\brief	�õ������ֶα�������
	//! \param  arrCostName  ��������[in]
	//!	\return ����ɹ��ҵ����򷵻�TRUE�����򷵻�FALSE.
	UGString GetFirstCostName();

	//!	\brief	����ת���
	//! \param  arrTurnCostFields  ת���ṹ[in]
	//!	\return 
	void SetTurnCostFields(const UGArray<UGString> &arrTurnCostFields);

	//!	\brief	�õ�ת���ֶα�������
	//! \param  arrTurnCostName  ת���������[in]
	//!	\return ����ɹ��ҵ����򷵻�TRUE�����򷵻�FALSE.
	UGbool GetTurnCostName(UGStrArray &arrTurnCostName);
	//}}���߳�֧��

	//!	\brief	NetIndex����������
	//! \param  pData  NetIndexָ��[in]
	//! \param  nCount �����С[in]
	//!	\return 
	void q_Sort(NetIndex *pData, UGint nCount);

public:
	//��Ա����
	UGDatasetVector *m_pDtNetwork;							//�����õ��������ݼ�
	UGDatasetVector *m_pDtTRN;								//�����õ�ת�����Ա�
	UGDatasetVector *m_pDtCenter;							//��Դ�����е����ĵ��ļ�
	UGDatasetVector *m_pDtDMDNode;							//��Դ�����е�����ڵ��ļ�
	UGDatasetVector *m_pDtDMDArc;							//��Դ�����е����󻡶��ļ�
	
	UGArray<UGPathNode*> m_AdjMatrix;					//�ڵ��ڽӱ�
	UGArray<UGTurnNode*> m_TurnTable;						//�ڵ�ת���

	UGArray<UGint> m_NodeIDs;							//�ڵ�ID��
	UGdouble m_dNodeInterval;							//������ѡ������

	//�洢��Ϣ
	UGArray<UGint> m_ArcIDs;                              //������Ϣ��

	UGArray<UGdouble>m_arrViaDist;						//����·�ɵ���ʻ�����ʱ��
	UGArray<short>m_arrViaDirection;					//����·�ɵ�ת����ʾ
	UGArray<UGuint> m_arrArcID;									//·�ɻ��α�
	UGArray<UGuint> m_arrNodeID;								//·�ɽڵ��
	
	UGArray<UGchar> m_arrbtDemandAllocated;						//����ڵ�����
	UGArray<UGchar> m_arrbtCenterAllocated;						//���Ľڵ�����
	
	UGArray<UGdouble> m_arrNodeDemand;							//�ڵ���������
	UGArray<UGPathNode*> m_arrArcDemand;						//������������

	//add by wangsh 11.19 ���η���������
	UGArray<UGbyte> m_arrArcAllocated;				//���η���������
	UGArray<double> m_arrArcResources;		        //���η�����Դ��ֵ
	
	UGArray<UGCenterNode> m_arrCenters;							//���Ľڵ��
	UGArray<UGuint> m_arrDemandNodeIndex;						//����ڵ�Index��
	UGArray<UGuint> m_arrDemandArcID;							//���󻡶�ID��
	
	UGArray<UGint>m_arr_Lane_Positive;					//����(����ͨ��)
	UGArray<UGint>m_arr_Lane_Negative;					//����(����ͨ��)
	UGArray<UGint>m_arr_NO_Entry;						//����
	UGArray<UGint>m_arr_Both_Direction;					//˫��ͨ��
	
	UGArray<BarrierNode> m_arrBarrierNode;		//�ڵ��ϰ���
	UGArray<BarrierArc> m_arrBarrierArc;			//�����ϰ���
	
	//UGArray<UGuint> m_arrArcIDAllocated;								//��Դ����������ڵ�
	//UGArray<UGuint> m_arrNodeIDAllocated;								//��Դ���������绡��

	//{{���߳�֧��
	UGArray<UGdouble*> m_arrFTCost;		//������������
	UGArray<UGdouble*> m_arrTFCost;		//������������
	UGint m_nRefCount;
	UGArray<UGCostFields> m_arrCostFields;

	UGArray<UGdouble*> m_arrTurnCost;	//ת�����

	UGArray<TurnCost*> m_TurnCost;
	//UGArray<UGTurnCost*> m_TurnCost;						//�ڵ�ת�򻨷ѱ�
	UGArray<UGString> m_arrTurnCostFields;
	//}}���߳�֧��
	
	//{{BusNetwork
	UGArray<UGString> m_arrBusCostFields;
	//}}BusNetwork
	
	UGString	 m_strFTWeight;			//���ε���ǰ��ֵ�ֶ�
	UGString	 m_strTFWeight;			//���ε������ֵ�ֶ�
	
	UGString	 m_strNodeID;			//�ڵ�ID�ֶ�
	UGString	 m_strArcID;			//����ID�ֶ�
	UGString	 m_strFNodeID;			//��ʼ�ڵ��ֶ�
	UGString	 m_strTNodeID;			//��ֹ�ڵ��ֶ�
	
	UGString	 m_strRoadRule;			//��·�����ֶ�
	
	UGString	 m_strTRNNodeID;		//ת����нڵ�ID�ֶ�
	UGString	 m_strTRNWeight;		//ת�����Cost�ֶ�
	UGString     m_strTRNArcFromID;		//ת�����From����ID�ֶ�
	UGString	 m_strTRNArcToID;		//ת�����To����ID�ֶ�
	
	//UGString	 m_strNodeFilter;		//�ڵ�����ֶ�
	UGString	 m_strArcFilter;			//���ι����ֶ�
	
	UGString	 m_strNodeDemand;			//�ڵ��������ֶ�
	UGString	 m_strArcDemand;			//�����������ֶ�
	
	UGString	 m_strCenterID;				//����ID�ֶ�
	
	UGString	 m_strCenterCandidate;		//��ѡ�����ֶ�
	UGString	 m_strCenterResource;		//������Դ���ֶ�
	UGString	 m_strCenterMaxImpedance;	//���������ֵ�ֶ�
	UGPathGuideName m_strPathFeildNames;
	//====================Network Flow===============================
	//UGString	 m_strFlowDirection;	//�����ֶ�(��ʩ����)Against,With;
	//UGString	 m_strRole;				//�ڵ��ɫSource,Sink;
	//UGString	 m_strEnabled;			//�ڵ�򻡶��Ƿ������yes,no
	//====================Network Flow===============================
	UGbool m_bAdjModified;
	UGbool m_bTRNModified;
	UGbool m_bUseTRN;
	UGbool m_bCreateReverse;
	UGbool m_bUseRoadRule;
	
    //Trace Source
	UGArray < UGPathNode*> m_TraceAdjMatrix;
	
	UGArray <ArcInfo> m_ArcInfo;					//������Ϣ��
	UGuchar* m_pbtOnPath;
	UGdouble* m_pdNodeCost;
	UGint* m_pnPrevArcID;
	UGint* m_pnPrevNodeIndex;
	UGint* m_pnHeapIndex;
	UGint  m_nLeft;
	
	UGString m_strDirection;
	UGString m_strNodeType;
	
	ResultInfo m_ResultInfo;
	UGint m_nOptions;
	
	UGDataSource  *m_pOutputDataSource;					//�������Դ
	
	//UGArray<UGGeoLineM> m_arrRoute;				//�����ϰ���
	//������������
	
	// ��¼ԭ������ڽӾ���Ĵ�С
	UGint m_nAdjMatrixSize ;
	
	// ��¼ԭ�����Ľ��ID
	UGint m_nNodeMaxID	  ;
	
	// ��¼ԭ�����εĻ��θ���
	UGint m_nArcSzie 	  ;
	
	// ��¼ԭ�����ε����ID
	UGint m_nArcMaxID ;
	
	// ��ʱ�洢������������Ļ�����Ϣ
	UGArray <ArcInfo> m_TempArcInfo ;
	
	// ͬ����� ��¼�û��ε�����cost
	UGArray <UGdouble> m_TempArcCost ;
	
	// ͬ����� ��¼�û��ε�����cost
	UGArray <UGdouble> m_TempArcCostBak ;
	
	// �洢�������ԭʼ����
	UGArray <ArcInfo> m_VirtualArcArcInfo ;
	
	// �洢������Ŀ�ʼ�����ԭʼ�����е�λ��
	UGArray <UGdouble> m_VirtualFNodePos ;
	
	// ������������������ĵ�Ķ������ĵ�ID
	// ���þ��������� m_pnRelation[ nCount * a + b] = 1 ��ʾ b �� a �Ķ�
	UGint * m_pnRelation ;

	UGint   m_nSiteCount ;	// ���ĵ����
	
	//{{��ʹ����
	//UGPathGuides m_PathGuides;
	//}}��ʹ����

	// 	//�ַ�������
	// 	// ����Ĳ�ͬͼ�� 
	// 	UGArray <UGDatasetVector *>  m_arrDMDtNetWorks ;	
	// 	// ����ͼ���Ľڵ�
	// 	UGArray <UGuint>  m_nDMNodeIDs ;
	// 	
	// 	// ����ͼ�����ڽӾ���
	// 	UGArray <UGPathNode*>  m_DMTraceAdjMatrix ;
	// 	// ͼ���Ľڵ������� m_nDivMapsNodeIndexFrom[i] ��ʾ��i��ͼ���ڵ���m_nDivMapsNodeIDs �еĿ�ʼλ��
	// 	UGArray <UGuint>  m_nDMFromIndex ;
	// 	// ͼ����ͬ�ڵ��index(index����m_nDivMapsNodeIDs�е�index)
	// 	UGArray<UGint >   m_nDMSameNode ;
	// 
	// 	// �Ƿ��ؽ��ڽӾ���
	// 	UGbool m_bReBuildDMatrix ;
	
	/*
	//�ؼ��������ؽṹ��
	UGArray<CriticalOne50*> m_CriticalOneAdjMatrix;
	
	  UGArray<CriticalNode50*> m_CriticalNodeAdjMatrix;
	  
		//UGArray<UGint> m_arrOrder;
		UGArray<CriticalIndex> m_arrOrder;
	*/
};

}

#endif 
