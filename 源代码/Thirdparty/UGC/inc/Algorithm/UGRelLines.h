/*! \file	 UGRelLines.h
 *  \brief	 ���߿ռ�λ�ù�ϵ
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelLines.h,v 1.10 2007/11/02 10:20:58 qiuli Exp $
 */


#if !defined(AFX_UGRELLINELINE_H__98175692_7F5B_4534_A287_7F7C990E4436__INCLUDED_)
#define AFX_UGRELLINELINE_H__98175692_7F5B_4534_A287_7F7C990E4436__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"

namespace UGC {

// ���ﶨ�壺
// LineSeg: �߶Σ���������ɣ������������˵㼰��֮��Ĳ���; ���㲻����ͬ
// Polyline: ����, ������һ�������ĵ㴮; ��㲻��Ϊͬһ����
// PolyPolyline: ��������, �ɶ���������, ���߼���β�ɲ��ཻ
// 

//! \brief ���߿ռ�λ�ù�ϵ��
class ALGORITHM_API UGRelLines
{
private:
	UGRelLines();

public:	// ���߻����ռ��ϵ�ж�

/// ��ȫ���
	//! \brief �ж��߶κ��߶��Ƿ����
	//! \remarks ���: ��ĸ���,��Ӧ����ֵ
	static UGbool IsIdentical(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
							  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �ж����ߺ������Ƿ����
	//! \remarks ���: ��ĸ���,��Ӧ����ֵ
	static UGbool IsIdentical(const UGPoint2D* pPoints1, UGint nPntCount1,
							  const UGPoint2D* pPoints2, UGint nPntCount2);

	// by guohui 2007.10.16
	//! \brief �ж����ߺ������Ƿ����
	//! \remarks ���: ��ĸ���,��Ӧ����ֵ
	static UGbool IsIdentical(const UGPoint2D* pPoints1,const  UGint* lPolyCount1, UGint nSubCount1,
						  const UGPoint2D* pPoints2,const  UGint* lPolyCount2, UGint nSubCount2);

/// ����
	//! \brief �ж��߶�1�Ƿ�����߶�2
	//! \remarks ����: �߶�1���߶�2�Ľ��������߶�2
	static UGbool IsContain(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
							const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �ж������Ƿ�����߶�
	//! \remarks ����: ���ߺ��߶εĽ��������߶�
	static UGbool IsContain(const UGPoint2D* pPoints, UGint nPntCount,
							const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	static UGbool IsContain(const UGPoint2D* pPoints,const   UGint* lPolyCount, UGint nSubCount,
							const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief �ж�����1�Ƿ��������2
	//! \remarks ����: ����1������2�Ľ�����������2
	static UGbool IsContain(const UGPoint2D* pPoints1, UGint nPntCount1,
							const UGPoint2D* pPoints2, UGint nPntCount2);


	// by guohui 2007.10.16 copy from UGGeoRelation::IsLineBContainLineB
	//! \brief �ж�����1�Ƿ��������2
	static UGbool IsContain(const UGPoint2D* pPoints1,const  UGint* lPolyCount1, UGint nSubCount1,
							const UGPoint2D* pPoints2,const  UGint* lPolyCount2, UGint nSubCount2);
// �໥����
	//! \brief �ж��߶κ��߶��Ƿ��غ�
	//! \remarks �غ�: ���߻������
	static UGbool IsContainEachOther(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
						  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �ж����ߺ������Ƿ��غ�
	//! \remarks �غ�: ���߻������
	static UGbool IsContainEachOther(const UGPoint2D* pPoints1, UGint nPntCount1,
						  const UGPoint2D* pPoints2, UGint nPntCount2);


// ����
	//! \brief �ж��߶κ��߶��Ƿ񽻵�
	//! \remarks ����: ���߽���������һά����,�Ҳ����غ�
	static UGbool IsOverlap(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
						    const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �ж����ߺ������Ƿ񽻵�
	//! \remarks ����: ���߽���������һά����,�Ҳ����غ�
	static UGbool IsOverlap(const UGPoint2D* pPoints1, UGint nPntCount1,
						    const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief �ж����ߺ������Ƿ񽻵�
	//! \remarks ����: ���߽���������һά����,�Ҳ����غ�
	static UGbool IsOverlap(const UGPoint2D* pPoints1,const  UGint* lPolyCount1, UGint nSubCount1,
						  const UGPoint2D* pPoints2,const  UGint* lPolyCount2, UGint nSubCount2);


// �ཻ
	//! \brief �ж��߶κ��߶��Ƿ��ཻ
	//! \remarks �ཻ: ���ߵĽ�����������ά����
	static UGbool IsIntersect(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
							  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, UGdouble dTolerance=EP);

	//! \brief �ж����ߺ������Ƿ��ཻ
	//! \remarks �ཻ: ���ߵĽ�����������ά����
	static UGbool IsIntersect(const UGPoint2D* pPoints1, UGint nPntCount1,
							  const UGPoint2D* pPoints2, UGint nPntCount2);

//��Խ
	//! \brief �ж��߶�1�Ƿ��Խ�߶�2
	//! \remarks ��Խ: �߶�1���߶�2�ָ�Ϊ������������,�ֱ�λ��2������,�ҷ���㲻���ڶ˵�(���or�յ�)
	static UGbool IsCross(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
						  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �ж�����1�Ƿ��Խ����2
	//! \remarks ��Խ: ����1������2�ָ�Ϊ������������,�ֱ�λ��2������,�ҷ���㲻���ڶ˵�(���or�յ�)
	static UGbool IsCross(const UGPoint2D* pPoints1, UGint nPntCount1,
						  const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief �ж�����1�Ƿ��Խ����2
	//! \remarks ��Խ: ����1������2�ָ�Ϊ������������,�ֱ�λ��2������,�ҷ���㲻���ڶ˵�(���or�յ�)
	static UGbool IsCross(const UGPoint2D* pPoints1,const  UGint* lPolyCount1, UGint nSubCount1,
						  const UGPoint2D* pPoints2,const  UGint* lPolyCount2, UGint nSubCount2);

	
// ����
	//! \brief �ж��߶κ��߶��Ƿ�����
	//! \remarks ����: ���߽���Ϊ�ռ�
	static UGbool IsDisjoint(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
							 const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �ж����ߺ������Ƿ�����
	//! \remarks ����: ���߽���Ϊ�ռ�
	static UGbool IsDisjoint(const UGPoint2D* pPoints1, UGint nPntCount1,
							 const UGPoint2D* pPoints2, UGint nPntCount2);


public: // ����������ϵ�����ʵ�ù�ϵ�ж�

	//! \brief �ж��߶�1�Ƿ���߶�2�Ӵ�
	//! \remarks �Ӵ�: ������Ϊ��,��������
	static UGbool IsTouch(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
						  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �ж�����1�Ƿ������2�Ӵ�
	//! \remarks �Ӵ�: ������Ϊ��,��������
	static UGbool IsTouch(const UGPoint2D* pPoints1, UGint nPntCount1,
							const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief �߶ν�����һά����
	//! \remarks ���� Contain(A,B) || Contain(B,A) || Overlap
	static UGbool IsMatch(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
						  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �߶ν�����һά����
	//! \remarks ���� Contain(A,B) || Contain(B,A) || Overlap
	static UGbool IsMatch(const UGPoint2D* pPoints1, UGint nPntCount1,
							const UGPoint2D* pPoints2, UGint nPntCount2);

	// add by guohui 2007.10.08
	//! \brief �߶ν�����һά����
	//! \remarks ���� Contain(A,B) || Contain(B,A) || Overlap
	static UGbool IsMatch(const UGPoint2D* pPoints1, const UGint* pPolyCount1,UGint nSubCount1,
							const UGPoint2D* pPoints2, const UGint* pPolyCount2,UGint nSubCount2);
	
	//! \brief �ߺ����ڲ��Ƿ��ཻ
	//! \remarks ���ڲ��Ķ����ǣ������ߵ������˵�����ߵ���������
	static UGbool IsInteriorIntersect(const UGPoint2D* pPoints1, UGint nPntCount1,
							const UGPoint2D* pPoints2, UGint nPntCount2);


public:	// ����һ��ʵ���ж��㷨

	//! \brief �ж��߶��Ƿ�ֱ, ����û�н���
	static UGbool IsPerpendicular(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
								  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �ж��߶��Ƿ�ƽ��, ������ͬһ��ֱ����,Ҳ�����ص�,�����غ�
	static UGbool IsParallel(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
								  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �ж��߶ε���С�����Ƿ������޷�Χ֮��
	static UGbool IsNear(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
								  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2,
								  const UGdouble dDistance);



public: // �ڲ�����ʹ��,�ռ��㷨���ⲻ��ʹ��

	//! \brief ����ֵ��ȷ�����������߶��ཻ�����
	static UGint IntersectLineSegment(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
									  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);
	//! \brief �õ�һ���߶��о���From��ܽ��ĵ�,��֮����From�㲻����һ����λ
	static UGPoint2D GetTestPoint(const UGPoint2D* pPointFrom, const UGPoint2D* pPointTo);

	//! \brief �߶�1���߶�2 �Ƿ�ͬ��
	//! \remarks ʸ��������ͬһ��������
	static UGbool IsSameQuadrant(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
								  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

};

}

#endif // !defined(AFX_UGRELLINELINE_H__98175692_7F5B_4534_A287_7F7C990E4436__INCLUDED_)
