// UGGeoRelation.h: interface for the UGGeoRelation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEORELATION_H__4BFF0D4D_CD98_4DF5_B7AD_ED2C116651AD__INCLUDED_)
#define AFX_UGGEORELATION_H__4BFF0D4D_CD98_4DF5_B7AD_ED2C116651AD__INCLUDED_

#include "Base/ugdefs.h"
#include "UGGeometry.h"

namespace UGC {

//! \brief ����Geometry�Ŀռ��ϵ�ж�����
//! \remarks ��ѯ���� : Search ��Ŀ����� Target
//!			��һ������Ϊ��ѯ���󣬵ڶ���ΪĿ�����
//!		����	�߿�				�߽�				�ڲ�							�ⲿ
//!		��	�������				�������			�������						�����߽��������
//!		��	�߶������С��Ӿ���	�߶�����ƱߵĲ���	�߶���ı߽�ȥ��
//!														�߶������ʼ�����ֹ��Ĳ���	�߶���߽��������
//!		��	��������С��Ӿ���	�������ƱߵĲ���	�����߽�Χ�ɵ�����			�����߽��������
class GEOMETRY_API UGGeoRelation  
{
private:
	UGGeoRelation();

public: // ��������
	
	//! \brief �ж��Ƿ�߿��ཻ
	//! \remarks ��ѯ����(A)�ı߿���Ŀ�����(B)�ı߿��ཻ�գ�A�ı߿��B�ı߿򽻼���Ϊ�գ�
	//!			��ѯ����: ��,��,��
	//!			Ŀ�����: ��,��,��
	//!			(A�߿� �� B�߿�) 
	static UGbool IsExtentIntersect(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ж��Ƿ�Ӵ�
	//! \remarks ��ѯ����(A)�߽���Ŀ�����(B)���У�A�ı߽���B�߽罻����Ϊ�գ�
	//!			��ѯ����: ��,��,��
	//!			Ŀ�����: ��,��,��
	//!			(A�߽� �� B�߽�) 
	static UGbool IsTouch(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ж��Ƿ�Խ
	//! \remarks ��ѯ����(A)��ԽĿ�����(B)
	//!			���棺A���ڲ���B���ڲ��Ľ�����Ϊ�գ�A���ڲ���B���ⲿ�Ľ�����Ϊ�գ�
	//!			���ߣ�A��B�ڲ���һ����벢��B�ڲ���ĳ����һ�ഩ����
	//!			��ѯ����: ��
	//!			Ŀ�����: ��,��
	//!			(A�ڲ� �� B�ڲ�) && (A�ڲ� �� B�ⲿ) 
	static UGbool IsCross(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ж��Ƿ񽻵�
	//! \remarks ��ѯ����(A)��Ŀ�����(B)����
	//!			1.A��B��ά����ͬ��
	//!			2.A���ڲ���B���ڲ�����(C)��Ϊ�գ� 
	//!			3. C����������A��������ͬ��
	//!			4. C���ܵ���(Identical)A;
	//!			5. C���ܵ���(Identical)B;
	//!			��ѯ������,��
	//!			Ŀ�������,��
	//!			(A.D==B.D) && (A�ڲ� �� B�ڲ�) && ((A�ڲ� �� B�ڲ�).D==A.D) 
	//!			D��Dimension ά��
	static UGbool IsOverlap(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ж��Ƿ����
	//!			��ѯ����(A)��ȫ����Ŀ�����(B)(A,B���Ա߽罻�����Բ�Ϊ��)
	//!			1.A���ⲿ��B���ڲ��Ľ���Ϊ��;
	//!			2.A��ά��>=B��ά��;
	//!			��ѯ����: ��,��,��
	//!			Ŀ�����: ��,��,��
	//!			(��(A�ⲿ �� B�ڲ�)) 
	static UGbool IsContain(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ж��Ƿ�������
	//! \remarks Contains��������
	//!			��ѯ����: ��,��,��
	//!			Ŀ�����: ��,��,��
	//!			(��(A�ڲ��� B�ⲿ)) 
	static UGbool IsWithin(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ж��Ƿ�����
	//! \remarks ��ѯ����(A)��Ŀ�����(B)����
	//!			��ѯ����: ��,��,��
	//!			Ŀ�����: ��,��,��
	//!			(��(A�߽� �� B�߽�)) && (��(A�ڲ� �� B�ڲ�)) 
	static UGbool IsDisjoint(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ж��Ƿ��ͬ
	//! \remarks ��ѯ�����Ŀ�������ȫ��ȣ����˳��Ҳ����һ����һ�����ڲ�ѯ���ƶ���
	//!			��ѯ����: ��,��,��
	//!			Ŀ�����: ��,��,��
	//!			(A�߿�==B�߿�) && (A�߽�==B�߽�) && (A�ڲ�==B�ڲ�) 
	//!			*A---------*B------------*C------------*D	*A'---------*B'------------*C'
	//!			*E-----------------------*F------------*G	*E'---------*F'------------*G'
	//!          ��ͬ:ABCD��EFG����ͬ��A'B'C'��E'F'G'��ͬ
	static UGbool IsIdentical(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

public: // ʵ�� ��������ӣ��������ӣ�
	
	//! \brief �ж��Ƿ��й�ͬ�ڵ㣨vertex��
	//! \remarks ��ѯ�����Ŀ������й������Ƶ�
	//!			��ѯ���󣺵�,��,��
	//!			Ŀ����󣺵�,��,��
	//!			*A---------*B------------*C------------*D
	//!			---*E--------------------*F--------------*G
	//!          ��ͬ���: F��CΪ��ͬ���
	static UGbool IsCommonPoint(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ж��Ƿ��й�ͬ�߶�
	//! \remarks ��ѯ�����Ŀ������й�����(��������������ͬ)
	//!			��ѯ������,��
	//!			Ŀ�������,��
	//!			*A---------*B------------*C------------*D
	//!			*E-----------------------*F------------*G
	//!          ��ͬ�߶�: CD��FGΪ��ͬ�߶Σ�ABC��EF���ǹ�ͬ�߶Σ�AB��EF���ǹ�ͬ�߶Ρ�
	static UGbool IsCommonLine(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ж��Ƿ�������ཻ
	//! \remarks ��ѯ�����Ŀ������ڲ�������Ϊ��; ��ѯ�����Ŀ����������һ��Ϊ�����
	//!			��ѯ���󣺵�,��,��
	//!			Ŀ����󣺵�,��,��
	static UGbool IsAreaIntersect(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ж��Ƿ��������
	//! \remarks ��ѯ�������Ŀ����������
	//!			��ѯ������
	//!			Ŀ�������
	static UGbool IsCentroidInPolygon(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

//	//! \brief �ж��Ƿ������һ����
//	//! \remarks Ŀ����������ѯ����ĵ�һ����
//	//!			��ѯ���󣺵�,��,��
//	//!			Ŀ�������
//	//!			�ݲ���Ϊ���⹫�����ӣ������ڲ�ʹ��
//	static UGbool IsFirstPointInPolygon(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

public: // �ɻ������� ��϶��ɵ� ʵ������

	//! \brief �ж��Ƿ�����
	//! \remarks Touch&&(!Cross)&&(!Overlap)&&(!Contain)&&(!Within)
	static UGbool IsTangent(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);
	
	//! \brief �ж��Ƿ������
	//! \remarks Contain && (!Touch)
	static UGbool IsContainNoTouch(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ж��Ƿ��汻����
	//! \remarks Within && (!Touch)
	static UGbool IsWithinNoTouch(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \remarks Contain || Overlap
	static UGbool IsContainOrOverlap(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \remarks Touch && (!Cross)
	static UGbool IsTouchNoCross(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

public: // �� �������Ӻ��������� ��϶��ɵ� ʵ������

	//! \brief �Ƿ������ͬ����ߴ�Խ
	static UGbool IsCommonPointOrCross(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �Ƿ�����ཻ���Ҳ��������
	static UGbool IsAreaIntersectsNoContain(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �Ƿ�����ཻ���߽Ӵ�
	static UGbool IsAreaIntersectOrTouch(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �Ƿ���ͬ�߻����ص�
	static UGbool IsCommonLineOrOverlap(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �Ƿ���ͬ�߲��ҽ���
	static UGbool IsCommonLineAndOverlap(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);
	
private: // Geometry�ڲ����ⲿ���߽�Ĺ�ϵ�ж�

	//! \brief �ڲ����ڲ��Ĺ�ϵ
	static UGbool InteriorToInterior(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief �ڲ���߽�Ĺ�ϵ
	static UGbool InteriorToBoundary(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief �ڲ����ⲿ�Ĺ�ϵ
	static UGbool InteriorToExterior(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief �߽����ڲ��Ĺ�ϵ
	static UGbool BoundaryToInterior(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief �߽���߽�Ĺ�ϵ
	static UGbool BoundaryToBoundary(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief �߽����ⲿ�Ĺ�ϵ
	static UGbool BoundaryToExterior(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief �ⲿ���ڲ��Ĺ�ϵ
	static UGbool ExteriorToInterior(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief �ⲿ��߽�Ĺ�ϵ
	static UGbool ExteriorToBoundary(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);
	
	//! \brief ���ڲ��Ƿ����߽߱��ཻ
	static UGbool IsLineIIntersectLineB(UGPoint2D *pSrcPoints,UGint nSrcPointCount,UGPoint2D *pTagPoints,
										UGint nTagPointCount);
	//! \brief ���ڲ��Ƿ������ཻ
	static UGbool IsRegionIIntersectLineB(UGPoint2D *pSrcPoints,UGint *pSrcRegionCounts,UGint nSrcSubCount,
										  UGPoint2D *pTagPoints,UGint *pTagLineCounts,UGint nTagSubCount);
	//! \brief �߽߱��Ƿ�����߽߱�
	static UGbool IsLineBContainLineB(UGPoint2D *pSrcPoints,UGint *pSrcLineCounts,UGint nSrcSubCount,
										UGPoint2D *pTagPoints,UGint *pTagLineCounts,UGint nTagSubCount);
	//! \brief ���Ƿ������
	static UGbool IsRegionContainLine(UGPoint2D *pSrcPoints,UGint *pSrcRegionCounts,UGint nSrcSubCount,
											  UGPoint2D *pTagPoints,UGint *pTagLineCounts,UGint nTagSubCount);

};

}

#endif // !defined(AFX_UGGEORELATION_H__4BFF0D4D_CD98_4DF5_B7AD_ED2C116651AD__INCLUDED_)
