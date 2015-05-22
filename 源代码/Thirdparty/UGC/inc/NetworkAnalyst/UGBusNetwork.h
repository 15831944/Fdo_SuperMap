/* 
	\file UGBusNetwork.h
	\brief �������˽����ͷ���
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGBUSNETWORK_H
#define UGBUSNETWORK_H

#include "NetworkAnalyst/UGNetworkAnalystEnv.h"

namespace UGC {

class TopoGridEnv;
class NETWORKANALYST_API UGBusNetwork  : public UGNetworkAnalystEnv
{
public:
	UGBusNetwork();
	
	virtual ~UGBusNetwork();
	
	enum UGDirectionType
	{
		UGSingle	= 1,	
		UGBoth		= 2,
		UGRound		= 3
	};
	
public:		
	//! \brief ��������
	/**
	 \param		dMergerInterval	վ��鲢����
	 \param		dStopInterval	վ�㲶׽����
	 \remarks	
	 1��������dMergerInterval��Χ�ڵ�վ����Ҫ���кϲ������ϲ�֮�������һ���߼�վ�㣬��ʵվ����߼�վ��
		�γɶ��һ�Ĺ�ϵ����ʵ�ʷ���������ʹ���߼�վ����д����ڽ��������ٻ������ʵվ�㡣
	 2��վ�㵽��·�ľ�����dStopInterval��Χ�ھ͹涨��վ�����ڶ�Ӧ����·��
	 3��dMergerIntervalһ��Ҫ��dStopInterval��,�������߶�Ҫ����0��
	*/
	void SetInterval(const UGdouble& dMergerInterval, const UGdouble& dStopInterval);
	
	//! \brief ��ȡ�����õ�����
	/**
	 \param		dMergerInterval	վ��鲢����
	 \param		dStopInterval	վ�㲶׽����
	*/
	void GetInterval(UGdouble& dMergerInterval, UGdouble& dStopInterval);
	
	//!	\brief	�������罨��\n
	/**
	//!	\param	pDTBusLine			������·���ݼ�
	//!	\param	pDTBusStop			����վ�����ݼ�
	//!	\param	strBusNetworkName	���ɹ�����������
	//!	\return	�ɹ������ع����������ݼ����κ��쳣�ʹ��󽫷���NULL;
	\remarks	������·��վ���������ɹ������磬��������洢�˹�����·��վ��֮������˹�ϵ�����˷������ڹ������磻
	*/
	UGDatasetVector* BuildBusNetwork(UGDatasetVector* pDTBusLine, UGDatasetVector* pDTBusStop,
									const UGString& strBusNetworkName);
	
	//!	\brief	���¹������粿����·\n
	/**
	//!	\param	pRSBusLine			��Ҫ���µĹ�����·��¼��
	//!	\param	pDTBusStop			����վ�����ݼ�
	//!	\param	pDTBusNetwork		�����������ݼ�
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	\remarks	������·����ʵ���Ͼ��Ǹ�����·����ƥ�����վ�㣬���Ѹ��½�������ڹ�������pDTBusNetwork�У�
	*/
	UGbool UpdateBusLines(UGRecordset* pRSBusLine, UGDatasetVector* pDTBusStop, UGDatasetVector* pDTBusNetwork);
	
	//!	\brief	ɾ���������粿����·\n
	/**
	//!	\param	arrLineIDs			��Ҫɾ���Ĺ�����·ID����
	//!	\param	pDTBusNetwork		�����������ݼ�
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	\remarks	������·ɾ��ʵ���Ͼ����ڹ�������pDTBusNetwork��ɾ���ͱ�ɾ����·��صļ�¼��
	*/
	UGbool RemoveBusLines(UGArray<UGint> arrLineIDs, UGDatasetVector* pDTBusNetwork);
	
	//!	\brief	ɾ����������һ����·\n
	/**
	//!	\param	nLineID				��Ҫɾ���Ĺ�����·ID
	//!	\param	pDTBusStop			����վ�����ݼ�
	//!	\param	pDTBusNetwork		�����������ݼ�
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	*/
	UGbool RemoveBusLine(UGint nBusLineID, UGDatasetVector* pDTBusNetwork);

public:	
	/*!	\brief	���ù�����·�����ֶ�*/
	void SetRouteNameField(const UGString& strRouteName);
	
	/*!	\brief	��ȡ������·�����ֶ�*/
	const UGString& GetRouteNameField()const;
	
	/*!	\brief	���ù���վ�������ֶ�*/
	void SetStopNameField(const UGString& strStopName);
	
	/*!	\brief	��ȡ����վ�������ֶ�*/
	const UGString& GetStopNameField()const;
	
	//!	\brief	���ù�������������ݼ�\n
	//!	\param	BusNetworkDT		��������������ݼ��ṹ
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	UGbool SetBusNetworkDT(const UGBusNetworkDT& BusNetworkDT);
	
	//!	\brief	��ȡ��������������ݼ�\n
	//!	\return	���������õĹ�������������ݼ��������÷���NULL;
	const UGBusNetworkDT& GetBusNetworkDT() const;
	
	//! \brief �����ڴ湫����·��վ������˹�ϵ
	UGbool CreateBusNetwork();
	
	//!	\brief	�������˷���\n
	//!	\param	BusNetworkParams		�������˷�������
	//!	\param	ResultRoutings			�����·����
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	UGbool DoTransfer(const UGTransferParams& BusNetworkParams, UGRouteResults& ResultRoutings);
	
	//!	\brief	��ȡ��·��������\n
	//!	\param	RouteResult			������·
	//!	\param	arrLines			��ɸù�����·�ļ����߼���
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	UGbool GetGeoLines(const UGRouteResult& RouteResult, UGArray<UGGeoLine*>& arrLines);
	
	//!	\brief	��ȡÿ�λ��ɳ���·�м侭����վ��ID\n
	//!	\param	pResRouting			���ɳ���·��
	//!	\param	arrStopIDs			��ȡ�ö���·�������м�վ��ID
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	UGbool GetRoutingStopIDs(const UGBusRouting* pResRouting, UGArray<UGint>& arrStopIDs);
	
public:
	//!	\brief	��ȡĳ����·�ϵ�վ��\n
	//!	\param	nBusLineID			������·ID
	//!	\param	arrBusStopIDs		վ�㼯��
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	UGbool GetBusStops(UGint nBusLineID, UGArray<UGint>& arrBusStopIDs);
	
	//!	\brief	��ȡ����ĳվ���������·\n
	//!	\param	nBusStopID			����վ��ID
	//!	\param	arrBusLineIDs		������·����
	//!	\return	�ɹ���TRUE���κ��쳣�ʹ��󽫷���FALSE;
	UGbool GetBusLines(UGint nBusStopID, UGArray<UGint>& arrBusLineIDs);
	
private:
	UGbool BuildBusNetwork(UGRecordset* pRSBusLine, UGRecordset* pRSBusStop, UGDatasetVector* pDTBusNetwork);
	UGbool MergerStops(TopoGridEnv& TopoGridUnitP);
	
	UGbool MatchStops(TopoGridEnv& TopoGridUnitL, UGArray<UGGeometry*> &arrObjects, UGArray<UGint> &arrStopID, 
						UGSingleRoutes& SingleRoutes);
	
	UGbool MergeRoutes(UGSingleRoutes& SingleRoutes, UGBusNetworkParams& BusNetworkParams);
	
	UGbool TransZeroTime(UGBusStop* pFromStop, UGBusStop* pToStop, UGbyte* pbtRouteSign, UGRouteResults& RouteResults);
	UGbool TransOneTime(UGBusStop* pFromStop, UGBusStop* pToStop, UGbyte* pbtRouteSign, UGRouteResults& RouteResults);
	UGbool TransOneTime(UGBusStop* pFromStop, UGBusStop* pToStop, UGbyte* pbtRouteSign, UGBusRouteings& BusRouteings);
	UGbool DirectRoutes(UGBusStop* pFromBusStop, UGBusStop* pToBusStop, UGbyte* pbtRouteSign, UGBusRouteings& BusRouteings);
	UGbool IntersectByStop(UGBusRoute* pFromBusRoute, UGBusRoute* pToBusRoute, UGint nFromIndex, UGint nToIndex,UGBusRouteings& BusRouteings);
	UGbool IntersectByRoute(UGBusRoute* pFromBusRoute, UGBusRoute* pToBusRoute, UGint nFromIndex, UGint nToIndex, 
							UGbyte* pbtRouteSign, UGBusRouteings& BusRouteings, UGint nPassRouteCount);
	
	UGbool DoTransfer(UGBusStop* pFromBusStop, UGBusStop* pToBusStop, UGbyte* pbtRouteSign, UGBusRouteings& BusRouteings, UGint nPassRouteCount);
	UGbool DoTransfer(UGBusStop* pFromBusStop, UGBusStop* pToBusStop, UGbyte* pbtRouteSign, UGRouteResults& RouteResults, UGint nTransferCount);
	UGBusStop* GetBusStop(UGint nStopID);
	UGbool UnionRoutes(UGBusRouting& FromBusRouteing, UGBusRouting& ToBusRouteing,
						UGBusRouteings& BusRouteings, UGBusRouteings& UnionRouteings,
						UGint nPassRouteCount);
	
	UGbool BuildTopoGrid(UGRecordset *pRecordset, UGdouble dGridCount, TopoGridEnv& TopoGridUnit, 
						UGint GridType);
	
	UGbool SortRoutes(UGRouteResults& RouteResults, UGbyte* pbtRouteSign, const UGString& strCostName, 
						UGint nTransferCount);
	
private:	
	UGdouble m_dMergerInterval;
	UGdouble m_dStopInterval;
	UGBusNetworkDT m_BusNetworkDT;
	
	UGBusRoutes m_BusPaths;
	UGBusStops  m_BusStops;
	UGRelRoutes m_RelRoutes;
	UGRelStops  m_RelStops;
	UGArray<UGint> m_arrMergeID;
	UGArray<UGdouble*> m_arrBusLineCost;
	UGdouble* m_pdLength;
	
	UGString m_strRouteName;
	UGString m_strStopName;
};

}


#endif
