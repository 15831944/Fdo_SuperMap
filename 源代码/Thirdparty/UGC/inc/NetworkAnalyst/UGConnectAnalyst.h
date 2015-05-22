/* 
	\file UGConnectAnalyst.h
	\brief ��ͨ�Է���
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/
#ifndef UGCONNECTANALYST_H
#define UGCONNECTANALYST_H

#include "NetworkAnalyst/UGNetworkAnalyst.h"
#include "Base/ugdefs.h"

namespace UGC {

class NETWORKANALYST_API UGConnectAnalyst  : public UGNetworkAnalyst
{
public:
	UGConnectAnalyst();

	virtual ~UGConnectAnalyst();

	//!	\brief	������ͨ�Է����ڽӾ���
	UGbool CreateConnectAdjMatrix();
	
	//!	\brief	ɾ����ͨ�Է����ڽӾ���
	UGbool DeleteConnectAdjMatrix();

	//!	\brief	�ڵ���ͨ�Է��� 
	//!	\param	nFromID			������ID
	//!	\param	nToID			��������
	//!	\return	�ɹ���true���κ��쳣�ʹ��󽫷���false;
	UGbool IsConnected(const UGint nFromID,const UGint nToID);
	
	//!	\brief	�ڽӵ���� 
	//!	\param	nNodeID			������ID
	//!	\param	nDirection		��������
	//!	\param	arrNodeID		���������ID��
	//!	\return	�ڽӵ����
	UGint FindAdjacentNodes(UGint nNodeID,UGint nDirection,UGArray<UGuint> &arrNodeID);
	
	//!	\brief	ͨ������ 
	//!	\param	nNodeID			������ID
	//!	\param	nDirection		��������
	//!	\param	nLevel			��������
	//!	\param	arrNodeID		���������ID
	//!	\return	ͨ������
	UGint FindConnectedNodes(UGint nNodeID,UGint nDirection,UGint nLevel,UGArray<UGuint> &arrNodeID);
	
	//!	\brief	ͨ��߷��� 
	//!	\param	nNodeID			������ID
	//!	\param	nDirection		��������
	//!	\param	nLevel			��������
	//!	\param	arrEdgeID		���������ID��
	//!	\return	ͨ�����
	UGint FindConnectedEdges(UGint nNodeID,UGint nDirection,UGint nLevel,UGArray<UGuint> &arrEdgeID);
	
	//!	\brief	�ؼ������ 
	//!	\param	nStartNode		���ڵ�ID
	//!	\param	nEndNode		�յ�ڵ�ID
	//!	\param	nDirection		��������
	//!	\param	arrNodeID		���������ID��
	//!	\return	�ؼ�����
	UGint FindCriticalNodes(UGint nStartNode,UGint nEndNode,UGint nDirection,UGArray<UGuint> &arrNodeID);
	
	//!	\brief	�ؼ��߷���
	//!	\param	nStartNode		���ڵ�ID
	//!	\param	nEndNode		�յ�ڵ�ID
	//!	\param	nDirection		��������
	//!	\param	arrEdgeID		���������ID��
    //!	\return	�ؼ�����
	UGint FindCriticalEdges(UGint nStartNode,UGint nEndNode,UGint nDirection,UGArray<UGuint> &arrEdgeID);
		
private:

	//!	\brief	���ڽ�Ԫ��
	//!	\param	nNodeID		�ڵ�ID[in]
	//!	\param	nDirection	��������[in]
	//!	\param	arrEdgeID	����������ε�ID��[out]
	//!	\param	arrEdgeID	��������ڵ�ID��[out]
    //!	\return	TRUE
	UGbool FindAdjacentElement(UGint nNodeID,UGint nDirection,UGArray<UGuint> &arrEdgeID,UGArray<UGuint> &arrNodeID);
	
	//!	\brief	�ҹؼ�Ԫ�ظ���
	//!	\param	nStartID 	 ��ʼ�ڵ�ID[in]
	//!	\param	nEndID	     �յ�ڵ�ID[in]
	//!	\param	arrElementID Ԫ��ID����[out]
	//!	\param	bIsNode	     �Ƿ�Ϊ�ڵ�[out]
    //!	\return	�ؼ�Ԫ�ظ���
	UGint FindCriticalElement(UGint nStartID,UGint nEndID,UGArray<UGuint> &arrElementID,UGbool bIsNode=false);
	
	//!	\brief	�ҹؼ�Ԫ�ظ���
	//!	\param	nStartID 	 ��ʼ�ڵ�ID[in]
	//!	\param	nEndID	     �յ�ڵ�ID[in]
	//!	\param	arrElementID Ԫ��ID����[out]
	//!	\param	bIsNode	     �Ƿ�Ϊ�ڵ�[out]
    //!	\return	�ؼ�Ԫ�ظ���
	UGbool FindCriticalTow(UGint nStartID,UGint nEndID,UGArray<UGuint> &arrElementID,UGbool bIsNode=false);
	
	//!	\brief	������Ԫ��
	//!	\param	nStartNode 	 ��ʼ�ڵ�ID[in]
	//!	\param	nDirection	 ��������[in]
	//!	\param	arrEdgeID    ����ID����[out]
	//!	\param	arrStartEnd	 ����ID����[out]	
	void FindConnectEP(UGint nStartNode,UGint nDirection,UGArray<UGuint> &arrEdgeID,UGArray<UGuint> &arrStartEnd);
	
	//!	\brief	������Ԫ��
	//!	\param	nNodeID		�ڵ�ID[in]
	//!	\param	arrArcID	����ID����[out]
	//!	\param	arrNodeID	�ڵ�ID����[out]
    //!	\return	TRUE
	UGbool FindConnectedElement(UGint nNodeID,UGArray<UGuint> &arrArcID,UGArray<UGuint> &arrNodeID);

	//�ؼ���,�ؼ��߷�����ؽṹ
	//!	\brief �����ؼ�Ԫ���ڽӾ���
	UGbool CreateCriticalOneAdjMatrix();

	//!	\brief �����ؼ�Ԫ���ڽӾ���
	UGbool DeleteCriticalOneAdjMatrix() ;

	//!	\brief �����ؼ����ڽӾ���
	UGbool CreateCriticalNodeAdjMatrix();
		
	//!	\brief �����ؼ����ڽӾ���
	UGbool DeleteCriticalNodeAdjMatrix();

	//!	\brief	����������Ƿ��ǹؼ���
	//!	\param	nEndNodeID  �յ�ڵ�ID[in]
	//!	\param	ntestNodeID	����ID[in]
	//!	\param	pNodeLevels	��������[in]
	//!	\param	nCount	����[in]
    //!	\return	TRUE
	UGbool TestNode(UGint nEndNodeID,UGint ntestNodeID,UGint *pNodeLevels,UGint nCount);
	
	//!	\brief	�����Ƿ��ǹؼ���
	//!	\param	nEndNodeID  �յ�ڵ�ID[in]
	//!	\param	ntestNodeID	����ID[in]
	//!	\param	pNodeLevels	��������[in]
	//!	\param	nCount	����[in]
    //!	\return	TRUE
	UGbool IsCritiCalEdge(UGint nEndNode,UGint nTestNode,UGint *pNodeLevel,UGint &nCount);
	
	//!	\brief	�����Ƿ��ǹؼ���
	//!	\param	nEndNodeID  �յ�ڵ�ID[in]
	//!	\param	ntestNodeID	����ID[in]
	//!	\param	pNodeLevels	��������[in]
	//!	\param	nCount	����[in]
    //!	\return	TRUE
	UGbool IsCriticalNode(UGint nEndNode,UGint nJudgeNode,UGint *pNodeLevel,UGint nCount);

public:
	//�ؼ��������ؽṹ��
	UGArray<CriticalOne*> m_CriticalOneAdjMatrix;

	//�ؼ��������ؽṹ��
	UGArray<CriticalNode*> m_CriticalNodeAdjMatrix;

	//UGArray<UGint> m_arrOrder;
	UGArray<CriticalIndex> m_arrOrder;


	UGArray <ArcInfo> m_ConnectArcInfo;					//������Ϣ��
	// �Ƿ��ؽ��ڽӾ���
	UGbool m_bReBuildCriticalNodeMatrix ;
};

}

#endif 
