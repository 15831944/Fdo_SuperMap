// UGContourTree.h: interface for the UGContourTree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGCONTOURTREE_H__126201E8_7C67_4C3A_910C_DD6E3CC23073__INCLUDED_)
#define AFX_UGCONTOURTREE_H__126201E8_7C67_4C3A_910C_DD6E3CC23073__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry/UGTINBlock.h"
#include "GridAnalyst/UGMultiResolutionTIN.h"

namespace UGC{

class GRIDANALYST_API UGContourTree
{
public:


	struct Component
	{
		UGint nBirth;
		Component *pred, *succ;
		Component *nextPred, *prevPred;
		Component* uf;
	};

	struct Node;

	struct Arc
	{
		/** Node at the top of the arc */
		Node *hi;
		
		/** Node at the bottom of the arc */
		Node *lo;
		
		/** Next arc in the list of arcs attached to the lo node */
		Arc *nextUp;

		/** Prev arc in the list of arcs attached to the lo node */
		Arc *prevUp;
		
		/** Next arc in the list of arcs attached to the hi node */
		Arc *nextDown;

		/** prev arc in the list of arcs attached to the hi node */
		Arc *prevDown;

		/** if arc is not covered, nProcessed = 0; if arc is covered, nProcessed = 1; 
		if arc is covered and segment has attached, nProcessed = 2; default nProcessed = 0.*/
		UGint nProcessed;
		
		/** */
		UGint* pSegments;
		UGint nSize;
		UGint nIndex;

		~Arc ()
		{
			if (pSegments)
				free (pSegments);
			pSegments = NULL;
		}
	};

	struct Node
	{
		/** vertex that this node represents. */
		UGint nIndex;
		
		/** Doubly-linked, null-terminated list of arcs extended upwards from this node. Iterate like this:
		
		  for (Arc * a = node->up; a != NULL; a = a->nextUp )...
		*/
		Arc *up;
		
		/** Doubly-linked, null-terminated list of arcs extended upwards from this node. Iterate like this:
		
		  for (Arc * a = node->down; a != NULL; a = a->nextDown )...
		*/
		Arc *down;

		/** left and right value existed to indicate the relation of parent and child by the way of two iterations ,
		
		  one of which is scan from left to right ,the other is from right to left. if and only if the two values of 
		  
		one node are both smaller than another, we can say that this node is parent of another */
		UGint nLeft, nRight;

	};

	struct LeafQ
	{	
		Component** pComp;

		UGbyte* pType; // 0��join��1��split��0��max��1��min��2��join

		UGint nHead;
		
		UGint nTail;
		
		UGint nSize;		
	};

	struct AET 
	{
		Arc* pArc;
		UGint nMark;
	};

	enum NodeType {UGNull, UGMax, UGMin, UGJoin, UGSplit, UGRegular};

	struct arcNbrs
	{
		Arc** pArc;  // segment��Խ�ı���Ϣ
		UGint nIndex;
		UGint nSize;

		arcNbrs ()
		{
			pArc = NULL; 
			nIndex = nSize = 0;
		}

		arcNbrs (UGint nCount)
		{
			nIndex = 0;
			nSize = nCount;

			pArc = (Arc**)malloc(nCount*sizeof(Arc*));
			memset(pArc, 0x0, nCount*sizeof(Arc*));
		}

		~arcNbrs ()
		{
			if (pArc)
				free (pArc);
			pArc = NULL;
		}
	};
public:

	UGContourTree();
	virtual ~UGContourTree();

	// ����ContourTree
	void BuildContourTree(UGTINBlock* pTin, UGint nBlockID, TriPntInfo& tripntInfo);

private:

	// ��������
	void quicksort(UGint* pPnts, UGint nBegin, UGint nEnd, UGPoint3D* pnt);

	// ɨ��
	Component* Sweep(UGint* pPnts, UGint nBegin, UGint nEnd, UGint nAdd, Component** pComps, TriPntInfo& tripntInfo);

	// �½�component
	Component* NewComponent();

	// ����pCurrent��pPred�Ĺ�ϵ
	void AddPredComponent(Component* pCurrent, Component* pPred);

	// ���pCurrent��pPred�Ĺ�ϵ
	void RemovePredComponent(Component* pCurrent, Component* pPred);

	// ��һ�����ϵ�����segmentuf���ó������Ǹ�segment��ָ��
	void UnionComponent(Component* pComp, Component* pNewComp);

	// �ü���coponent����һ����
	void PruneComponent(Component* pLeaf);

	// pSelf�ǲ���Ҷ���
	UGbool IsLeafComponent(Component* pSelf);

	// pComp�ǲ���һ������Ľ�㣨��Ⱥͳ��ȶ���1��
	UGbool IsRegularComponent(Component* pComp);

	// ���pComp��ʹ��ǰ�����ж�pComp��ָ��Ľ���Ƿ�regular
	void EatComponent(Component* pComp);

	// ɾ��Component
	void DeleteComponent(Component*& pComp);

	// �ж�pNewComp�Ƿ��Ѿ�����comp
	Component* FindComponent(Component* pCurrent);

	// ��jointree��splittree�ϲ���contourtree
	void Merge(Component* pJoinRoot, Component* pSplitRoot, Component** pJoinMap, Component** pSplitMap, Node** pNodeMap);

	// �½�����
	LeafQ* NewLeafQ(UGint nSize);

	// ����������Ӷ���
	void PushBackLeafQ(LeafQ* pSelf, Component* pComp, UGint nType);

	// �Ӷ����е�������
	void PopFrontLeafQ(LeafQ* pSelf, Component*& pComp, UGint& nType);

	// �ж϶����Ƿ�Ϊ��
	UGbool IsEmptyLeafQ(LeafQ* pSelf);

	// ���leaf
	void DeleteLeaf(LeafQ*& pLeafQ);

	// ��Component���е�Ҷ���ӵ�leafQ��
	void QueueLeaves(LeafQ* pLeafQ, Component* pRoot, Component** pMap, UGint nType);

	// �½�node���
	Node* NewNode(UGint nPntIndex);

	// ��pArc�ӵ�pHigh��������
	void AddDownArcNode(Node* pHigh, Arc* pArc);

	// ��pArc���ӵ�pLow��������
	void AddUpArcNode(Node* pLow, Arc* pArc);

	// �½�һ���µı�
	Arc* NewArc(Node* pHigh, Node* pLow);

	// ɾ����pDown
	void DeleteDownArc(Arc* pDown);

	// ɾ����pUp
	void DeleteUpArc(Arc* pUp);

	// ���ͨ�����ɨ�躯����������е�contours
	void SweepForContours(UGint* pPnts, Node** pNodeMap, UGint nPntCount, UGArray<ContourLayer*>& arrContours, TriPntInfo& tripntInfo);

	// ��aet����ɾ��ĳ��arc
	AET RemoveFromAET(Arc* pArc, UGArray<AET>& arrAET);

	// ��aet���м���ĳ��arc
	void InsertIntoAET(Arc* pArc, UGArray<AET>& arrAET);

	// ��nBegin��nEnd�ε�segment���뵽pLayer��
	void AddToContours(Arc* pArc, UGint nBegin, UGint nEnd, ContourLayer* pLayer, TriPntInfo& tripntInfo);

	// ���¼���aet��nMark
	void RecalAET(AET& aet, UGdouble dCut, TriPntInfo& tripntInfo);

	// ���ض��������
	NodeType GetNodeType(const Node* pNode);

	// �õ�ÿ������һ����С��segment���Ǽ�
	void GetSmallCover(Node** pNodeMap, UGint nPntCount, TriPntInfo& tripntInfo);

	// ɨ��contourtree��������������Ĺ�ϵ
	void IterateGraph(Node* pBeginNode);

	// ����������
	void SetNodesValueFromLeft(Arc* const pArc, UGint& nPntCount, UGint& nLastBegin, UGArray<Arc*>& arrRightArc, Arc* pTerminate = NULL);

	// ������nLeftֵʱ������ĳһ��arc������node��ֵ
	void SetSplitValueFromLeft(Arc* const pArc, UGint& nPntCount, UGint& nLastBegin, UGArray<Arc*>& arrRightArc);

	// ���ҵ�������
	void SetNodesValueFromRight(Arc * const pArc, UGint& nPntCount, UGint& nLastBegin, UGArray<Arc*>& arrRightArc, Arc* pTerminate = NULL);

	// ������nRightֵʱ������ĳһ��arc������node��ֵ
	void SetSplitValueFromRight(Arc* const pArc, UGint& nPntCount, UGint& nLastBegin, UGArray<Arc*>& arrRightArc);

	// ɾ��arrArcPass(ÿ�������ڵ�segment��������arc��Ϣ)
	void DeleteArcPass(UGArray<arcNbrs*>& arrArcPass);

	// �ж�nCur�Ƿ���nLeft��nRight֮��
	UGbool IsBetween(UGint nCur, UGint nLeft, UGint nRight);

	// �ж�pFromNode��pToNode�串������Щ����
	UGint Wander(Node* pFromNode, Node* pToNode, UGint nSegIndex, arcNbrs* pArcNbrs);

	// ɨ�裬ɾ��regular��㣬����arc��Խ��segment��arc�󶨣�Ϊ�ڶ���ɨ����׼��
	void SweepForSegment(UGint* pPnts, Node** pNodeMap, UGint nPntCount);

	// ����
	void ReOrder(Arc* pArc, UGint nBegin, UGint nEnd, UGdouble dTopValue, UGdouble dDownValue, TriPntInfo& tripntInfo);

	// ɾ����ͻ���
	void DeleteNodeArc(Node** pNodeMap, UGint nPntCount);

	// test
	UGbool TestComponent(Component* pComp);
	UGbool TestNode(Node** pNodeMap, UGint nPntCount);
	UGbool TestPnt(UGint* pnt, UGint nCount);
	UGbool TestContour(UGArray<ContourLayer*>& arrContours);
	UGbool TestGragh(Node** pNodeMap, UGint nCount);
	void TestArcCovered(Node** pNodeMap, UGint nPntCount);

private:
	UGTINBlock* m_pTin;
};

}
#endif // !defined(AFX_UGCONTOURTREE_H__126201E8_7C67_4C3A_910C_DD6E3CC23073__INCLUDED_)
