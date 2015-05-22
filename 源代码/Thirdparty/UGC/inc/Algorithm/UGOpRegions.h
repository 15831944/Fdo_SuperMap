/*! \file	 UGOpRegions.h
 *  \brief	 ��, ������֮�������
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOpRegions.h,v 1.7 2007/10/10 08:17:56 guohui Exp $
 */


#ifndef UGOPREGIONS_H
#define UGOPREGIONS_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGPoint3D.h"
#include "Algorithm/UGRect2D.h"

namespace UGC {

//! \brief ��, ������֮�������
//! \remarks �������:
//!				����:��������
class ALGORITHM_API UGOpRegions  
{
private:
	UGOpRegions();


public: // �õ�ͼ�ε������(����ֵ)
	
	//! \brief		�õ����Ӷ���ε��ڵ�(�ڶ������,�������ĵĵ�)
	static UGPoint2D InnerPoint(const UGPoint2D* pPoints, const UGint* pPolyCount, 
								UGint nSubCount, UGRect2D* pBounds=NULL);
public:
	//! \brief		��Rect�ü�һ�������	
	//! \return		�õ��ü���,��rect�ڵĶ����
	//! \param 		pntResults	�������εĵ�����
	//! \param 		PolyCountResult	��������εĵ����
	//! \param		bInside		 true,�򷵻��ھ����ڲ�;false,�����ھ����ⲿ
	static void ClipRegionWithRect(const UGPoint2D* pRgnPoints,const UGint* pRgnPolyCount,UGint nRgnSubCount, 
								const UGRect2D& rect,UGPoint2Ds& pntResults,UGArray<UGint>& PolyCountResult, 
								UGbool bInside=TRUE);

public: // ��(or rect)�ü���
	//! \brief		�������
	//! \return		
	//! \param 		nMode		��ģʽ��ȡֵΪ UGGeneralPolygonClip::Difference,UGGeneralPolygonClip::Intersect
	//!							UGGeneralPolygonClip::Union,UGGeneralPolygonClip::Xor
	static UGbool Intersects(UGPoint2D* pPoints1,UGint* lPolyCount1,UGint lCount1,
							UGPoint2D* pPoints2,UGint* lPolyCount2,UGint lCount2,
							UGPoint2D*& pPoints,UGint*& lPolyCount,UGint& lCount,
							UGint nMode);

#if PACKAGE_TYPE==PACKAGE_UGC
	
	//! \brief �õ�����������.Ҳ���������ε����ġ�
	static UGPoint2D TriangleCentroid(const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3);

	//! \brief �õ�����������(���ԲԲ��)
	//! \remarks Circumcenter: n.����(��ѧ�����Բ������) ������ֱƽ���ߵĽ���
	static UGPoint2D TriangleCircumcenter(const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3);

	//! \brief �õ���ԲPie������(��������)
	//! \param pntCenter ��Բ�����ĵ�; 
	//! \param a ����;
	//! \param b ����; 
	//! \param dAngleStart ��ʼʵ�ʽǶ�; �Ƕ�
	//! \param  dAngleEnd: ��ֹʵ�ʽǶ�; �Ƕ�
	static UGPoint2D PieCentroid(const UGPoint2D& pntCenter, UGdouble a, UGdouble b, 
									UGdouble dAngleStart, UGdouble dAngleEnd);

	//! \brief �õ�������ķ�����
	//! \remarks �õ����㹹�ɵ�ƽ���ƽ�淽�� Ax+By+Cz+D=0 ������ABC������ֵ
	static void TriangleNormal(const UGPoint3D& pnt1, const UGPoint3D& pnt2, const UGPoint3D& pnt3, 
							   UGdouble& A, UGdouble& B, UGdouble& C);

	// �����������û�б�Ҫ
	//! \brief �ö����1�ü�һ�������2
	//! \return �õ��ü���,�ڶ����1�ڵĶ����
	// static void ClipRegionWithRegion(const UGPoint2D* pRgnPoints, const UGint* pRgnPolyCount, UGint nRgnSubCount, 
	// 								const UGPoint2D* pClipPoints, const UGint* pClipPolyCount, UGint nClipSubCount, 
	//								UGPoint2Ds& pntResults, UGArray<UGint>& PolyCountResult, UGint& nResSubCount);

private: 

	//! \brief		��Rect�ü�һ�������	
	//! \return		�õ��ü���,��rect�ڵĶ����
	static void ClipRegionWithRectInside(const UGPoint2D* pRgnPoints,const UGint* pRgnPolyCount,UGint nRgnSubCount, 
								const UGRect2D& rect,UGPoint2Ds& pntResults,UGArray<UGint>& PolyCountResult);

	//! \brief		��Rect�ü�һ�������	
	//! \return		�õ��ü���,��rect��Ķ����
	static void ClipRegionWithRectOutside(const UGPoint2D* pRgnPoints,const UGint* pRgnPolyCount,UGint nRgnSubCount, 
								const UGRect2D& rect,UGPoint2Ds& pntResults,UGArray<UGint>& PolyCountResult);

#endif // end declare ugc API
};

}

#endif
