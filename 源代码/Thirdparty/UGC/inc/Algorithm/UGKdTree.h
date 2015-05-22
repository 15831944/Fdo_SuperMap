//-------------------------------------------------------------------------------------
// �ļ�����			UGKdTree.h, UGKdTree.cpp
// ��  ����			UGKdTree
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		��KdTree�����ٽ������
// ����˵����		
//-------------------------------------------------------------------------------------
/* �޸�˵����
 *		2007.09.25	guohui	Ϊ��ͷ�ļ����ע��
 */

#if !defined(UGKDTREE_H)
#define UGKDTREE_H
#include "Algorithm/UGRect2D.h"

namespace UGC{

class UGPoint3D;

#define MaxBucketSize 2500//30
//! \brief kά��(k-dimensional tree)
/** 
by guohui 2007.09.25
	�ο����ף�
	�����㼸��-�㷨��Ӧ��(��2��)�� M.de Berg,M.van Kreveld,M.Overmars,OSchwarzkofp�����˿����� p113
*/

class ALGORITHM_API UGKdTreeNode
{
public:
	
	//! \brief �и��
	enum DType 
	{
		eKdTreeX,			//	�� X ����
		eKdTreeY,			//	�� Y ����
		eKdTreeNONE			//  ���߾�����
	};  
	

	//! \brief Ҷ�ӽڵ��еĵ�ĸ���,�м�ڵ�Ϊ��
	UGint   m_nBucketSize;

	//! \brief �ڵ��еĵ�����к�,�������Ҷ�����ΪNULL�����ҿ����������ж��ǲ���Ҷ�ӽڵ�
	UGint* m_pPointIndex;

	//! \brief �ڵ�
	UGPoint3D* m_pPoint3D;

	//! \brief ������,Ҷ�ӽڵ�Ϊ��
	UGKdTreeNode* m_pLeftChild;

	//! \brief ������,Ҷ�ӽڵ�Ϊ��
	UGKdTreeNode* m_pRightChild;

	//! \brief �и�����ڵ�ά��,Ҷ�ӽڵ�Ϊ��
	DType m_nCutDim;

	//! \brief �и���ֵ,���ΪҶ�ӽڵ�Ϊ��
	UGdouble m_dCutValue;

	//! \brief �����ݿ��еĿ�ţ����ڶ�ֱ��ʵĹ���
	UGint m_nID;

	//! \brief ��ķ�Χ
	UGRect2D m_rcBound;

	//! \brief ����ID
	void SetID(UGint nID)
	{
		m_nID = nID;
	};
};
	

class ALGORITHM_API UGKdTree  
{
public:
	//! \brief 		ȱʡ���캯��
	UGKdTree();

	//! \brief 		��������
	virtual ~UGKdTree();	

public:

	//! \brief 		���ι��캯��
	//! \param 		pPointArray		��ά�����
	//! \param 		nPointCount		��������
	//! \param 		pPointList		�����к�
	//! \param 		pDistance		����
	UGKdTree(UGPoint3D *pPointArray,UGint nPointCount,UGint *pPointList,UGdouble *pDistance);

	//! \brief 		���ι��캯��
	//! \param 		pPointArray		��ά�����
	//! \param 		nPointCount		��������
	//! \param 		pPointList		�����к�
	UGKdTree(UGPoint3D *pPointArray,UGint nPointCount,UGint *pPointList);

	//! \brief 		���ι��캯��
	//! \param 		pPointArray		��ά�����
	//! \param 		nPointCount		��������
	//! \param 		rect			��ķ�Χ
	UGKdTree(UGPoint3D *pPointArray,UGint nPointCount, UGRect2D& rect);

	//! \brief 		������ά��
	//! \return 	UGbool
	//! \remarks 	
	UGbool KdTree_CreateTree();	

	//! \brief 		���ڵ��ѯ(ָ����ѯ����)
	//! \return 	void
	//! \param 		pTree			����kdtree
	//! \param 		x				������
	//! \param 		y				������
	//! \param 		nSearchCount	Ҫ�������ڵ����
	//! \param 		pPointIndex		���ҵ��ĵ�����,����֮ǰ����Ҫ�ȷ���ռ�
	//! \param 		pPointDist		���ҵ��ĵ�������ľ��룬����֮ǰ����Ҫ�ȷ���ռ� 
	//! \remarks 	���ӿ�ֻ���������������������kd��
	void KdTree_SearchKdTree(UGKdTree* pTree,UGdouble x, UGdouble y,
		UGint nSearchCount, UGint *pPointIndex,	UGdouble *pPointDist);

	//! \brief 		���ڵ��ѯ(ָ����ѯ����)
	//! \return 	void
	//! \param 		pTree			����kdtree
	//! \param 		x				������
	//! \param 		y				������
	//! \param 		dRadius			��ѯ���룬���������ƶ��İ뾶
	//! \param 		nPointSearched	�ҵ��ĵ�
	//! \param 		pPointDist		���ҵ��ĵ�������ľ��룬����֮ǰ����Ҫ�ȷ���ռ� 
	//! \remarks 	pPointIndex �� 	pPointDist �ڴ���䲻������ MAX_POINTS
	void KdTree_SearchKdTreeDis(UGKdTree *pTree,UGdouble x,UGdouble y, 
		UGdouble dRadius,UGint &nPointSearched,	UGint *pPointIndex,UGdouble *pPointDist);

	//! \brief 		����ͷָ��
	//! \return 	UGKdTreeNode
	//! \param 		pTree			����kdtree
	//! \remarks 		
	UGKdTreeNode* ReturnRoot();

	void SetMaxBucketSize(	UGint nMaxBucketSize = MaxBucketSize);
	UGint GetMaxBucketSize(	);

protected:	
	

	//! \brief 		���������������
	//! \return 	UGKdTreeNode
	//! \param 		pPointIndex		����
	//! \param 		lPointCount		��������
	//! \remarks 		
	UGKdTreeNode* KdTree_CreateNode(UGint *pPointIndex,UGint lPointCount);

	//! \brief 		��������㴴�����
	//! \return 	UGKdTreeNode
	//! \param 		pPoint3D		�����
	//! \param 		lPointCount		��������
	//! \param 		rect			����
	//! \remarks 		
	UGKdTreeNode* KdTree_CreateNode(UGPoint3D *pPoint3D,UGint lPointCount, UGRect2D& rect);

	//! \brief 		�ͷ��ڴ�
	//! \return 	UGbool
	//! \param 		pTreeNode		ָ��
	//! \remarks 		
	UGbool KdTree_FreeNode(UGKdTreeNode* pTreeNode); 

	//! \brief 		����ѡ��Ҫsplit��ά����λ��
	//! \return 	void
	//! \param 		pPointIndex		����
	//! \param 		lPointCount		����
	//! \param 		nCutDim			����
	//! \remarks 		
	void KdTree_SelectSplit(UGint *pPointIndex,UGint lPointCount, UGKdTreeNode::DType &nCutDim);

	//! \brief 		����ѡ��Ҫsplit��ά����λ��
	//! \return 	void
	//! \param 		pPoint3D		�����
	//! \param 		lPointCount		����
	//! \param 		nCutDim			����
	//! \remarks 		
	void KdTree_SelectSplit(UGPoint3D* pPoint3D,UGint lPointCount, UGKdTreeNode::DType &nCutDim);

	//! \brief 		���ҽ��
	//! \return 	void
	//! \param 		pTreeNode		���ָ��
	//! \remarks 		
	void KdTree_SearchNode(UGKdTreeNode *pTreeNode);

	//! \brief 		���ҽ��
	//! \return 	void
	//! \param 		pTreeNode		���ָ��
	//! \remarks 		
	void KdTree_SearchNodeDis(UGKdTreeNode *pTreeNode);

	//! \brief 		���㼯�ȷ�Ϊ����
	//! \return 	void
	//! \param 		pPointIndex		����ָ��
	//! \param 		lPointCount		����
	//! \param 		nMedian			
	//! \param 		nCutDim			����
	//! \remarks 		
	void KdTree_PointMedian(UGint *pPointIndex, UGint lPointCount, UGint nMedian, UGKdTreeNode::DType  nCutDim);  // ���㼯�ȷ�Ϊ����

	//! \brief 		���㼯�ȷ�Ϊ����
	//! \return 	void
	//! \param 		pPoint3D		����ָ��
	//! \param 		lPointCount		����
	//! \param 		nMedian			
	//! \param 		nCutDim			����
	//! \remarks 		
	void KdTree_PointMedian(UGPoint3D *pPoint3D, UGint lPointCount, UGint nMedian, UGKdTreeNode::DType  nCutDim);
	
private:

	//! \brief 		�������
	UGint m_lPointCount;

	//! \brief 		��
	UGPoint3D *m_pPointArray;

	//! \brief 		������к�
	UGint *m_pPointIndex;

	//! \brief 		�����
	UGKdTreeNode *m_pRoot;

	//! \brief 		
	UGdouble  m_dx;               

	//! \brief 		
	UGdouble  m_dy;

	//! \brief 		����Ҫ�ҵĵ���
	UGint m_nSearchCount;

	//! \brief 		�ӽ���Զ���ص���
	UGint *m_pPointList;

	//! \brief 		��С���󷵻ؾ���
	UGdouble *m_pdDistance;

	//! \brief 		�������ҵİ뾶
	UGdouble m_dRadius;

	//! \brief 		��ķ�Χ
	UGRect2D m_rcBound; 

	//! \brief 		��������
	UGint m_nMaxBucketSize;
};
}

#endif // !defined(UGKDTREE_H)
