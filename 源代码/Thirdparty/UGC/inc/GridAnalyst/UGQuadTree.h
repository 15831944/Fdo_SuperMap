#if !defined(UGQUADTREE_H)
#define UGQUADTREE_H

#include "Base/ugdefs.h"
#include "Algorithm/UGRect2D.h"

namespace UGC {

class UGRect2D;
class UGPoint3D;
//class UGArray;

enum QuadChild
{
	NW = 0,
	NE = 1,
	SW = 2,
	SE = 3
};

class GRIDANALYST_API UGQuadNode
{
public:
	UGQuadNode();
	~UGQuadNode();
	//!�ݹ鴴���Ĳ���
	void Create(UGPoint3D* pPointList,UGint* pPointIndex,UGint nPointCount,UGint nMaxPntCount,const UGRect2D& rcBounds);
	//!��ѯ�����ص�����
	UGint QueryWithBounds(UGPoint3D* pPointList,const UGRect2D& rcBounds,UGArray<UGint>&arrResultIndex);
	//! �õ�ָ�����ӽڵ�
	UGQuadNode* GetChild(int nIndex);
	//! �Ƿ�ΪҶ�ӽڵ�
	UGbool IsLeaf();
	//! ��ýڵ��Bounds
	UGRect2D GetBounds();
	//! ���Ҷ�ӽڵ����
	UGint GetLeafCount();
protected:
	//!��õ㼯�����ĵ�
	UGPoint2D GetPointCenter(UGPoint3D* pPointList,UGint* pPointIndex,UGint nPointCount);
	//!����ڵ���û�е��򴴽��սڵ�
	void CreateNullNode(const UGRect2D& rcBounds);
	//!�жϸýڵ��Ƿ���rcbounds�ཻ
	UGbool IsIntersect(const UGRect2D& rcBounds);
	//!�ӽڵ�
	UGQuadNode** m_pChilds;
	UGRect2D m_rcBounds;
	UGint m_nPointCount;
	//!���Ϊ�ӽڵ��¼�ýڵ�洢�ĵ�����
	UGint* m_pIndex;
};

}

#endif // !defined(UGQUADTREE_H)



