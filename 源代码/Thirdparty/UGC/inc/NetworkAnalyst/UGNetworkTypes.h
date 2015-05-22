#ifndef UGNETWORKTYPES_H
#define UGNETWORKTYPES_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Engine/UGDatasetVector.h"
#include "Geometry/UGGeoLineM.h"
#include "Geometry/UGGeoRegion.h"
namespace UGC {

#define NETWORKINFINITY 10e6
#define SM_NO_MEASURE -9999
#define MAX_RECORD_COUNT 100
#define MAX_TRANSFER_COUNT 5


//�ڽӻ��δ洢�ṹ
class UGNeighborArc
{
public:
	UGNeighborArc(UGint nFromArc=-1,UGint nToArc=-1, UGdouble dCost=0.0):m_nFromArc(nFromArc),
		m_nToArc(nToArc),
		m_dCost(dCost) {}
public:
	UGint m_nFromArc;
	UGint m_nToArc;
	UGdouble m_dCost;
};

//�ڽӽڵ�洢�ṹ
class UGNeighborNode
{
public:
	//UGNeighborNode(UGint nIndex=-1,UGint nArcID=-1, UGdouble dCost=0.0) : m_nIndex(nIndex),
	UGNeighborNode(UGint nIndex=-1,UGint nArcIndex=-1, UGdouble dCost=0.0) : m_nIndex(nIndex),
		//m_nArcID(nArcIndex),
		m_nArcIndex(nArcIndex),
		m_dCost(dCost) {}
public:
	UGint m_nIndex;
	UGint m_nArcIndex;
	UGdouble m_dCost;
};

//·���ڵ�洢�ṹ
class UGPathNode
{
public:
	UGPathNode(){m_nNeighborCount = 0;m_pNeighborNode = NULL;}
	UGbool AddNeighbor(UGint nIndex, UGint nArcID, UGdouble dDist);
	//
	UGbool AddNeighbor(UGint nIndex, UGint nArcIndex);
	
public:
	UGint m_nNeighborCount;
	UGNeighborNode* m_pNeighborNode;
};

//ת��ڵ�洢�ṹ
class UGTurnNode
{
public:
	UGTurnNode(){m_nNeighborCount = 0;m_pNeighborArc = NULL;}
	UGbool AddNeighbor(UGint nFromArc,UGint nToArc, UGdouble dCost);
	UGdouble GetTurnCost(UGint nFromArc, UGint nToArc);
	
	//֧�ֶ��߳�
	UGbool AddNeighbor(UGint nFromArc,UGint nToArc,UGint &nInsertPos);
	UGint GetTurnCostIndex(UGint nFromArc, UGint nToArc);
public:
	UGint m_nNeighborCount;
	UGNeighborArc* m_pNeighborArc;
};

//ת��ڵ�洢�ṹ
class UGTurnCost
{
public:
	UGTurnCost(){m_nNeighborCount = 0;m_pTurnCost = NULL;}

	UGbool AddTurnCost(UGint nInsertPos,UGdouble dCost);
	UGdouble GetTurnCost(UGint nPos);
	
public:
	UGint m_nNeighborCount;
	UGdouble* m_pTurnCost;
};

//�ؼ�Ԫ�ش洢�ṹ
typedef struct tagCriticalOne
{
	UGArray<UGuint>  ForeNbIDs;
	UGArray<UGuint>  BackNbIDs;
	UGArray<UGuint>  ForeRouteIDs;
	UGArray<UGuint>  ForeNoNbIDs;
	UGArray<UGuint>  BackRouteIDs;
	UGArray<UGuint>  BackNoNbIDs;
	
	UGint  nNodeID;
	UGint  nNoNum;
	UGint  nLeftNb;
}CriticalOne;

typedef struct tagTourNode
{
	UGint* pNodeIndex;
	UGint nNodeCount;
}TourNodeIndex;

//�ؼ��ڵ�洢�ṹ
typedef struct tagCriticalNode
{
	UGArray<UGuint> NbIDs;
	UGArray<UGuint> RouteIDs;
	UGArray<UGuint> NoNbNums;
	
	UGint  nNodeID;
	UGint  nNoNum;
	UGint  nLeftNb;
}CriticalNode;

//�ϰ���洢�ṹ
typedef struct tagBarrierNode
{
	UGPathNode* pNode;
	UGint nIndex;
}BarrierNode;

//�ϰ��ߴ洢�ṹ
typedef struct tagBarrierArc
{
	UGint nFNodeIndex;
	UGint nTNodeIndex;
	UGint nArcID;
	UGint nIndex;
}BarrierArc;

//�����洢�ṹ
typedef struct tagDemandNode
{
	UGint	nDemandID;
	UGdouble	dDemand;
}DemandNode;

typedef struct tagIndex
{
	UGint nID;
	UGint nIndex;
}NetIndex;

//��洢�ṹ
typedef struct tagPointIndex
{
	UGint nIndex;
	UGPoint2D pntNode;
}PointIndex;

typedef struct tagTour
{
	UGint nParentIndex;
	UGint nIndex;
}TourIndex;

//Trace Source
//������Ϣ�ṹ
typedef struct tagArcInfo
{
	UGint 	nArcID;
	UGint	nFNodeID;
	UGint	nTNodeID;
}ArcInfo;

typedef struct tagMTSP
{
	UGint	nServiceIndex;
	UGint	nNodeIndex;
	UGdouble	dCost;
}MTSPInfo;

//�����Ϣ�ṹ
typedef struct tagResultInfo
{
	UGint	nOptions;
	
	UGString str_RouteName;
	UGString str_ViaEdgeName;
	UGString str_ViaNodeName;
	UGString str_StopName;
	
	UGString str_PT_Name;
	UGString str_PT_EdgeName;
	UGString str_PT_NodeName;
	
	UGString str_Service_RegionName;
	
	UGString str_Location_NodeName;
	UGString str_Location_CenterName;
}ResultInfo;

//��ͨ�Է����ؼ���͹ؼ��߷�����Ҫ�Ľṹ
typedef struct tagCriticalIndex
{
	UGint nID;
	UGint nOrderNum;
}CriticalIndex;

//���ĵ����ݽṹ
typedef struct tagCenterNode
{
	UGint	nCandidate;
	UGint	nCenterID;
	UGdouble	dResource;
	UGdouble	dMaxImpedance;
}UGCenterNode;

// �ȽϺ�������
class NetIndexCompare
{
public:
	UGbool operator()(const NetIndex& netIndex1, const NetIndex& netIndex2) const
	{
		if (netIndex1.nID < netIndex2.nID)
		{
			return true;
		}
		return false;
	}
};


//{{֧�ֶ��߳�
typedef struct tagUGCostFields
{
	UGString strCostName;
	UGString strFTField;
	UGString strTFField;
}UGCostFields;

typedef struct tagUGCostValues
{
	UGdouble *dFTCost;
	UGdouble *dTFCost;
}UGCostValues;

typedef struct tagIniMemory
{
	//UGshort* pbtOnPath;
	UGuchar* pbtOnPath;
	UGdouble* pdNodeCost;
	UGint* pnPrevArcID;
	UGint* pnPrevNodeIndex;
	UGint* pnHeapIndex;
}UGIniMemory;

//ת���ṹ
typedef struct tagUGTurnCostFields
{
	UGString strTurnCostName;
	UGString strTurnField;
}UGTurnCostFields;

typedef struct tagUGBarriers
{
	UGArray<UGuint> arrBarrierNodeIDs;//�ϰ���
	UGArray<UGuint> arrBarrierArcIDs;//�ϰ���
}UGBarriers;
//}}֧�ֶ��߳�

//����������ṹ��Ԫ
typedef struct tagUGDistMatrix
{
	UGuint nFNodeID;
	UGuint nTNodeID;
	UGdouble dCost;
}UGDistMatrixUnit;

//{{��ʹ����
class  UGElemInfo
{
//{{ by guohui 2008.01.03
public:

	//!	\brief ����
	enum UGElemType
	{
		ARCELEM		=	0,
		NODEELEM	=	1
	};

	//!	\brief ת��
	enum UGTurnType
	{
		TURNNONE	=	255	,	//	�Ƿ�ֵ(��ʼ��Ϊ��ֵ)
		TERMINUS	=	0	,	//	�յ�
		TURNLEFT	=	1	,	//	��ת
		TURNRIGHT	=	2	,	//	��ת
		GOAHEAD		=	3	,	//	ֱ��
		TURNAROUND	=	4		//	��ͷ
	};

	//!	\brief ��������
	enum UGDirectType
	{
		DIRNONE		=	255	,	//	�Ƿ�ֵ(��ʼ��Ϊ��ֵ)
		EAST		=	0	,	//	��
		SOUTH		=	1	,	//	��
		WEST		=	2	,	//	��
		NORTH		=	3	,	//	��
	};

	//!	\brief ת������
	enum UGViaTurnType
	{
		VIATURNNONE	=	255	,	//	�Ƿ�ֵ(��ʼ��Ϊ��ֵ)
		ONSIDE		=	0	,	//	��·��
		SIDELEFT	=	1	,	//	�ڵ�·���
		SIDERIGHT	=	2	,	//	�ڵ�·�ұ�
	};

//}} by guohui 2008.01.03

public:
	UGElemInfo()
	{
		bViaNode	= FALSE;
		nElemID		= -1;
		nNodeNO		= -1;
		dElemCost	= 0;
		dLength		= 0;
		dAngle		= -1;
		dDirection	= -1;
		bViaTurnType= 0;
		strElemName	= ("");

		//{{ by guohui 2008.01.03
		bTurnType = TURNNONE;
		bDirectType = DIRNONE;
		bViaTurnType = VIATURNNONE;
		//}} by guohui 2008.01.03
	};
	
	~UGElemInfo()
	{
	};
	
public:	
	
	UGElemInfo& operator=(const UGElemInfo& ElemInfo)
	{
		bViaNode		= ElemInfo.bViaNode;
		nElemID			= ElemInfo.nElemID;
		nNodeNO			= ElemInfo.nNodeNO;
		bElemType		= ElemInfo.bElemType;
		bTurnType		= ElemInfo.bTurnType;
		bDirectType		= ElemInfo.bDirectType;
		bViaTurnType	= ElemInfo.bViaTurnType;
		dElemCost		= ElemInfo.dElemCost;
		dLength			= ElemInfo.dLength;
		dAngle			= ElemInfo.dAngle;
		dDirection		= ElemInfo.dDirection;
		strElemName		= ElemInfo.strElemName;
		rcBound			= ElemInfo.rcBound;
		
		return *this;
	};
	/*   (1)  �����·�ɵ㣬�� bViaNode = true,bElemType = NODEELEM.��ʱʹ�� bViaTurnType 
	*         �����е�ֵ��·�ɵ�ֻ���ڡ���·�ϡ������ڵ�·��ߡ������ڵ�·�ұߡ�����״̬��
	*    (2)  ����ǻ��Σ��� bViaNode = false,bElemType = SIDEELEM.��ʱʹ�� bDirectType 
	*		  �����е�ֵ��·�ɵ�ֻ���ڡ����������ϡ���������������������״̬��
	*    (3)  ����������㣬�� bViaNode = false,bElemType = NODEELEM.��ʱʹ�� bTurnType 
	*		  �����е�ֵ��·�ɵ�ֻ���ڡ��յ㡱������ת��������ת������ֱ�С�������ͷ������״̬��
	*/
public:
	
	//�Ƿ���·�ɵ�
	UGbool	bViaNode;

	//���λ����ID
	UGint	nElemID;

	//·�ɵ��Ż��������򻡶εı��
	UGint	nNodeNO;

	// 0---����	1---���
	// ��ʹ�� UGElemType ö�ٳ���
	UGbyte	bElemType;

	// 0---�յ�	1---��ת	2---��ת	3---ֱ��	4--��ͷ
	// ��ʹ�� UGTurnType �е�ö�ٳ���
	UGbyte	bTurnType;

	//0---��	1---��	2---��	3---��
	// ��ʹ�� UGDirectType ö�ٳ���
	UGbyte	bDirectType;

	//0---��·��	1---�ڵ�·���	-1---�ڵ�·�ұ�
	// ��ʹ�� UGViaTurnType ö�ٳ���
	UGshort	bViaTurnType;

	//ͨ�����λ��������ֵ
	UGdouble	dElemCost;

	//���εĳ���
	UGdouble	dLength;

	//ͨ������ת��Ƕ�(�Ƕ�)
	UGdouble	dAngle;

	//���������ص��X������ļн�
	UGdouble	dDirection;

	//���λ��������(�����ƻ��λ���ͳһ��Ϊ"Anonymous")
	UGString strElemName;

	//����Χ
	UGRect2D rcBound;

	//·�ɵ㵽���εľ���
	UGdouble	dDist;
};

typedef UGArray<UGElemInfo> UGElemInfos;

class  UGPathGuide
{
public:
	UGPathGuide()
	{
		nRouteID	= 1;
	};
	
    //����ſ����ͻ���ֿ�������������!
	/*
	UGPathGuide(UGPathGuide& PathGuide)
	{
		ElemInfos.RemoveAll();
		ElemInfos.Append(PathGuide.ElemInfos);
		
		nRouteID = PathGuide.nRouteID;
	};
	*/

	~UGPathGuide()
	{
		ElemInfos.RemoveAll();
	};
	
public:	
	UGint Add(UGElemInfo ElemInfo)
	{
		return ElemInfos.Add(ElemInfo);
	};
	
	UGint Append(UGPathGuide& PathGuide)
	{
		return ElemInfos.Append(PathGuide.ElemInfos);
	};
	
	void RemoveAll()
	{
		ElemInfos.RemoveAll();
		nRouteID = 1;
	};
	
	UGPathGuide& operator=(const UGPathGuide& PathGuide)
	{
		ElemInfos.RemoveAll();
		ElemInfos.Append(PathGuide.ElemInfos);
		
		nRouteID = PathGuide.nRouteID;
		
		return *this;
	};
	
public:
	//�ýṹ�����ɽ��ͻ��ν������
	UGElemInfos ElemInfos;
	UGint nRouteID;
};

typedef UGArray<UGPathGuide> UGPathGuides;
//}}��ʹ����

//{{�����ת�� 
typedef struct tagNodeInfo
{
	UGbool	bNode;
	UGshort	btDirection;
	UGint	ArcID;
	UGint	NodeID;
	UGint	FromID;
	UGint	ToID;
	
	UGdouble	dDist;
	UGdouble	dPos;
	
	UGdouble	ForwardCost;
	UGdouble	BackwardCost;
	
	UGPoint2D pntNode;
	
	tagNodeInfo ()
	{
		bNode = FALSE;
		dDist = -1.0;
	};
}UGNodeInfo;

typedef UGArray<UGNodeInfo> UGNodeInfos;

typedef UGArray<NetIndex> UGNetIndexs;

typedef UGArray< UGGeometry*> UGGeometrys;
typedef UGArray<UGdouble> UGLengths;

typedef struct tagElemIDsInfo
{
	UGNetIndexs		NetIndexs;
	UGGeometrys		Geometrys;
	UGStrArray   	Names;
	UGLengths		Lengths;
}UGElemIDsInfo;

typedef UGArray<UGElemIDsInfo> UGElemIDsInfos;
//}}�����ת�� CP2007��ֲ

//{{����������������Ϣ������������
typedef struct tagPathGuideName
{
	UGString strNodeName;
	UGString strArcName;
}UGPathGuideName;

typedef struct tagViaInfo
{
	//UGint nCount; //! ��С��Array��С��û�б�Ҫ�洢
	UGArray<UGuint> arrViaIDs;
}UGViaInfo;

typedef struct tagStopInfo
{
	//UGint nCount;//! ��С��Array��С��û�б�Ҫ�洢
	UGArray<UGuint>   arrViaIndex;
	UGArray<UGdouble> arrCost;
}UGStopInfo;

typedef struct tagDemandResInfo
{
    UGuint   nNodeID;
	UGuint   nCenterID;
	UGdouble dCost;
}UGDemandResInfo;

typedef struct tagRetCenterInfo
{
    UGuint   nCenterType;
	UGuint   nCenterID;
	UGdouble dResources;
	UGdouble dMaxIMP;
	UGdouble dAltCost;
	UGdouble dAltDemand;
	UGdouble dAltResources;
	UGdouble dAveCost;
}UGRetCenterInfo;

//! ���������
typedef struct tagUGResultInfo
{
	//! ѡ����Ҫ�洢�Ľ��ģʽ
	//! ���û��� UGNetworkAnalystEnv::UGResultInfoType ����ֵ
	UGint nOptions;

	//! ���·��·����Ϣ
	UGArray<UGGeoLineM> arrLineM;
    //! ���������������ݼ�
	UGArray<UGGeoRegion> arrRegion;
	//! ��ʻ������Ϣ
	UGPathGuides PathGuides; 
	//! ��������ڵ���Ϣ
	UGArray<UGViaInfo> arrViaPT; 
	//! ����������Ϣ
	UGArray<UGViaInfo> arrViaArc;
	//! ����վ����Ϣ
	UGArray<UGStopInfo> arrViaStop;
	//! �������ѣ������ʩ����ʱ���ø�cost��
	UGArray<UGdouble> arrCost;
	//! �������Ϣ ѡַ������
    UGArray<UGDemandResInfo> arrDemand;
    //! ���ĵ���Ϣ ѡַ������
	UGArray<UGRetCenterInfo> arrRetCenter;
	//{{ 2007.12.24 by guohui 
	tagUGResultInfo()
	{
		nOptions = 0 ;
	}
	//}} 2007.12.24 by guohui
	void Clear()
	{
		arrLineM.RemoveAll();
		arrRegion.RemoveAll();
		PathGuides.RemoveAll();
		arrViaPT.RemoveAll();
		arrViaArc.RemoveAll();
		arrViaStop.RemoveAll();
		arrCost.RemoveAll();
		arrDemand.RemoveAll();
		arrRetCenter.RemoveAll();
	}
}UGResultInfo;

//! ��������ʽ˵��
typedef struct tagUGAnalyseParams
{
	//! �ر���Ҫ����Ҫ�޸�ѡ����Ҫ�洢�Ľ��ģʽ
	//! ���û��� UGNetworkAnalystEnv::UGResultInfoType ����ֵ
	UGint nOptions;

	//! ��ʹ������Ҫ������ڵ�����绡�ε��ֶ�����
	//UGPathGuideName  strPathFeildNames;

	//! �������·����,��ʩ��,���͵�ڵ�ID����,
	UGArray<UGuint> arrViaNodeIDs;
    //! �������·����,��ʩ��,���͵����������
	UGPoint2Ds      arrViaPoints;
	
	//! �����������ĵ�ID����
	UGArray<UGuint> arrCenterNodeIDs;
    //! �����������ĵ����������
	UGPoint2Ds arrCenterPoints;
	
	//! �ϰ���
	UGArray<UGuint> arrBarrierNodeID;
	//! �ϰ���
	UGArray<UGuint> arrBarrierArcID;
	
	//! �����ʩ�����¼���ID
	UGint nNodeID;
	//! �����ʩ�����¼������
	UGPoint2D PointEvent;
	//! �����ʩ���Ҹ���
	UGint nSearchCount;
	
	//�����̵ĵ�������
	//UGint nIterations;
    //! ����,����뾶
	UGArray<UGdouble > arrNodeIDCosts;
	
	//! ��Դ����ģʽ
	UGint nMode;
	//! �Ƿ�����Ŀ�ʼ����
	UGbool bFromCenter;
	//! �Ƿ���ͨ
	UGbool bConnected;
	
	//! �����ֶεı�����������ȡ���������ֶκͷ��������ֶΣ���������
	UGString strCostName;
	//! ת���ֶ�����
	UGString strTurnCostName;
	
	//! �����Ҫ����
	//ResultInfo ResInfo;
	//! �����������ͻ�ȡ��� �����������������ֿ�������
	//UGResultInfo ResInfoOut;

	//{{ 2007.12.24 by guohui 
	tagUGAnalyseParams()
	{
		nOptions = 0 ;
	}
	//}} 2007.12.24 by guohui 
}UGAnalyseParams;

//��ʩ�����������������Ϣ
typedef struct tagUGUtilityAnalyseParams
{
	//��ʩ�������
	UGint nTraceID;
	UGint nEndID;
	UGint nSearchMode;
	UGArray<UGuint> arrTraceIDs;
	
	UGArray<UGuint> arrBarrierNodeID;//�ϰ���
	UGArray<UGuint> arrBarrierArcID;//�ϰ���
	
	UGString strCostName;
	
	UGbool bFindConnected;
	UGbool bCreateFeild;
	UGbool bFindWithoutLoops;
	
	tagUGUtilityAnalyseParams()
	{
		bFindWithoutLoops = TRUE;
		bCreateFeild      = FALSE;
	};	
}UGUtilityAnalyseParams;
//}}����������������Ϣ������������

//{{��������
typedef struct tagUGBusNetworkDT
{
	UGDatasetVector* pDTBusLine;
	UGDatasetVector* pDTBusStop;
	UGDatasetVector* pDTBusNetwork;
}UGBusNetworkDT;

typedef struct tagUGTransferParams
{
	UGint nFromID;
	UGint nToID;
	
	UGString strFromName;
	UGString strToName;
	
	UGString strCostName;
	
	UGPoint2D pntFrom;
	UGPoint2D pntTo;
	
	//�������ȼ�
	UGbool bPriority;
	UGArray<UGint> arrPriLineIDs;
	//UGQueryDef QueryDef;
	
	//Ԥ�����˷�����
	UGint nTransferCount;
	
	tagUGTransferParams()
	{
		nFromID		= -1;
		nToID		= -1;
		bPriority	= FALSE;
		nTransferCount = MAX_TRANSFER_COUNT;
		
		strFromName.Empty();
		strToName.Empty();
	};
	
}UGTransferParams;

class NETWORKANALYST_API UGBusRouting
{
public:
	UGBusRouting();
	~UGBusRouting();

public:
	UGint nRouteIndex;
	UGint nFromIndex;
	UGint nToIndex;
	
	UGint nRouteID;
	UGint nFromID;
	UGint nToID;
	
	UGdouble dCost;
	UGdouble dLength;
	
	UGString strFromStopName;
	UGString strToStopName;
	UGString strRouteName;
};

typedef UGArray<UGBusRouting> UGBusRouteings;

class NETWORKANALYST_API UGRouteResult
{
public:
	UGRouteResult();
	~UGRouteResult();
	UGbool Add(UGBusRouting& BusRouteing);

public:
	UGArray<UGBusRouting> BusRouteings;
	//UGBusRouting* pBusRouteings;
	UGint nCount;
	
	UGdouble dCost;
};

typedef UGArray<UGRouteResult> UGRouteResults;

class UGBusStop
{
public:
	UGBusStop();
	~UGBusStop();
	
	UGbool SetStopID(UGint nStopID);
	UGbool AddRoute(UGint nRouteID);
	//UGbool GetPassRoutes(UGArray<UGint>& arrRouteID);
	
public:
	
	UGint nIndex;
	UGint nRouteCount;
	UGint* pRoutes;
	UGint* pIndexs;
	//UGString strName;
};
typedef UGArray<UGBusStop*> UGBusStops;

class UGBusRoute
{
public:
	UGBusRoute();
	~UGBusRoute();
	
	UGbool SetRouteID(UGint nRouteID);
	UGbool AddStop(UGint nStopID, UGbool bForward=TRUE);
	UGbool GetStops(UGArray<UGint>& arrStopID);
	
public:
	
	UGint nIndex;
	UGint* pStopIndexs;
	UGint* pStopIDs;
	UGdouble* pdMeasures;
	UGdouble* pdPositions;
	UGint nStopCount;
	UGint nDirection;
	UGbool bDirty;
	//UGString strName;
	//UGbool bPriority;//���Ƕ��߳̾Ͳ�������
};

typedef UGArray<UGBusRoute*> UGBusRoutes;

typedef struct tagUGBusNetworkParam
{
	UGint nLineID;
	//UGint nRouteID;
	UGint nStopID;
	UGint nMergeStopID;
	UGint nIndex;
	UGdouble dMeasure;
	UGdouble dPosition;
	
	tagUGBusNetworkParam()
	{
		//nRouteID		= -1;
		nMergeStopID	= -1;
		nStopID			= -1;
		nIndex			= -1;
	};
	
}UGBusNetworkParam;
typedef UGArray<UGBusNetworkParam*> UGBusNetworkParams;

class UGSingleRoute
{
public:
	UGSingleRoute();
	~UGSingleRoute();

public:	
	UGint nLineID;
	//UGint nRouteID;
	UGint nStopCount;
	UGint* pStopIDs;
	UGint* pMergeIDs;
	UGdouble* pdMeasures;
	UGdouble* pdPositions;
};
typedef UGArray<UGSingleRoute*> UGSingleRoutes;

typedef struct tagUGRelRoute
{
	UGint nLineID;
	//UGint nRouteID;
	UGint nDirection;
	UGdouble dCost;
	UGString strName;
}UGRelRoute;
typedef UGArray<UGRelRoute*> UGRelRoutes;

typedef struct tagUGRelStop
{
	UGint nID;
	UGint nMergeID;
	UGString strName;
}UGRelStop;
typedef UGArray<UGRelStop*> UGRelStops;

//��nLineID��С�����������
class RelRouteCompare
{
public:
	UGbool operator()(const UGRelRoute* netIndex1, const UGRelRoute* netIndex2) const
	{
		if (netIndex1->nLineID < netIndex2->nLineID)
		{
			return TRUE;
		}
		return FALSE;
	}
};

//��nLineID(��)��dPosition(��)��С�����������
class BusNetworkParamCompare
{
public:
	UGbool operator()(const UGBusNetworkParam* netIndex1, const UGBusNetworkParam* netIndex2) const
	{
		if (netIndex1->nLineID < netIndex2->nLineID)
		{
			return TRUE;
		}
		else if (netIndex1->nLineID == netIndex2->nLineID)
		{
			if (netIndex1->dPosition < netIndex2->dPosition)
			{
				return TRUE;
			}
		}
		
		return FALSE;
	}
};

typedef struct tagUGResultRouteInfo
{
	UGbyte btPriority;
	UGint nRouteIndex;
	UGint nTransferCount;
	UGdouble dCost;
}UGResultRouteInfo;
typedef UGArray<UGResultRouteInfo*> UGResultRouteInfos;

class CostCompare
{
public:
	UGbool operator()(const UGResultRouteInfo* netIndex1, const UGResultRouteInfo* netIndex2) const
	{
		if (netIndex1->nTransferCount < netIndex2->nTransferCount)
		{
			return TRUE;
		}
		else if (netIndex1->nTransferCount == netIndex2->nTransferCount)
		{
			if (netIndex1->btPriority < netIndex2->btPriority)
			{
				return TRUE;
			}
			else if  (netIndex1->btPriority == netIndex2->btPriority)
			{
				if (netIndex1->dCost < netIndex2->dCost)
				{
					return TRUE;
				}
			}
		}
		
		return FALSE;
	}
};
//}}��������

//������ṹ
class UGHeap
{
public:
	UGHeap(UGint* pnHeapIndex,UGdouble* dCost);
	~UGHeap();
	UGint GetMinCostIndex();
	void Insert(const UGint lItem);
	void Update(const UGint lIndex);
	UGint GetSize();
private:
	UGbool Compare(const UGint nNode1,const UGint nNode2);
private:
	UGArray <UGint> m_SearchedList;
	UGdouble* m_pdCost;
	UGint*	m_pnHeapIndex;
};

}

#endif

