/*! \file	 UGOpLineRegion.h
 *  \brief	 �ߺ��� ���еĿռ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOpLineRegion.h,v 1.6 2007/10/12 06:06:52 guohui Exp $
 */


#ifndef UGOPLINEREGION_H
#define UGOPLINEREGION_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGArray.h"
#include "Base/UGList.h"

namespace UGC {

//! \brief �ߺ��� ���еĿռ�����
class ALGORITHM_API UGOpLineRegion  
{
private:
	UGOpLineRegion();


	//{{ by guohui 2007.10.12
public: // ����

	//! \brief ���ߵ������С����
	static UGdouble MinDistance(const UGPoint2D* pPointsLine,const UGint* pPolyCountLine,UGint nSubCountLine, 
					   const UGPoint2D* pPointsRegion,const UGint* pPolyCountRegion,UGint nSubCountRegion );
	//}} by guohui 2007.10.12

public: // �ָ�

	//! \brief �����߷ָ���棬�治�����Ӷ���
	//! \brief �����潻�������Ϊ2������False. ���ص���������ǲ���յ�.
	static UGbool Split(const UGPoint2D* pLinePoints, UGint nLinePntCount, 
					   const UGPoint2D* pRgnPoints, UGint nRgnPntCount, 
					   UGPoint2Ds& pntResRegion1, UGPoint2Ds& pntResRegion2);

public: // �ü�	

    //! \brief ��rect�ü���
	//! \param resPoints	 ���ü�����ߵĿ��Ƶ� 
	//! \param resPolyCount	 ÿ�����������Ŀ��Ƶ����  
	//! \param nResSubCount	 ���ü�����ߵĸ��� 
	//! \param bInside		 true,�򷵻��ھ����ڲ�����;false,�����ھ����ⲿ����
	static UGbool Clip(const UGPoint2D* pPoints, const UGint* pPolyCount, UGint nSubCount, 
					 const UGRect2D& rectClip, UGPoint2Ds& resPoints,
					 UGArray<UGint>& resPolyCount, UGint& nResSubCount, UGbool bInside=TRUE);


    //! \brief �ö����ü���(λ�ڶ���α��ϵ��ߣ����ڽ������)
	//! \param pPointsRes	 ���ü�����ߵĿ��Ƶ� 
	//! \param pPolyCountRes ÿ�����������Ŀ��Ƶ����  
	//! \param nSubCountRes	 ���ü�����ߵĸ��� 
	//! \param bInside		 true,�򷵻��ڶ�����ڲ�����;false,�����ڶ�����ⲿ����
	static UGbool Clip(const UGPoint2D* pPointsLine,const UGint* pPolyCountLine,UGint nSubCountLine, 
					   const UGPoint2D* pPointsRegion,const UGint* pPolyCountRegion,UGint nSubCountRegion,
					   UGPoint2D*& pPointsRes,UGint*& pPolyCountRes,UGint& nSubCountRes,
					   UGbool bInside=TRUE);
	
#if PACKAGE_TYPE==PACKAGE_UGC
public: 

	//! \brief ����һ����Բ��ͨ����Բ���ĵ����ߵĽ���
	//! \param a			��Բ������
	//! \param b			��Բ�̰���
	//! \param x0			��ԲԲ�ĺ�����
	//! \param y0			��ԲԲ��������
	//! \param dRadian		���ߵĻ���(����������Ϊ0�����ȵ�λ)
	static UGPoint2D IntersectEllipseRay(UGdouble a, UGdouble b,
										UGdouble x0, UGdouble y0, UGdouble dRadian);
#endif // end declare ugc API
private:
	
	//! \brief ��rect�ü���(���ؾ����ڲ�����)
	static UGbool ClipLine(const UGPoint2D* pPoints, const UGint* plPolyCounts, UGint lCount, 
					const UGRect2D& rectClip, UGPoint2Ds& resPoints, 
					UGArray<UGint>& resPolyCount, UGint& nResSubCount);

	//! \brief ������α߽���߶εĹ�ϵ
	static UGbool ClipLineTest(UGdouble p, UGdouble q, UGdouble& u1, UGdouble& u2);

	//! \brief ��rect�ü���(���ؾ����ⲿ����)
	static UGbool ClipLine2(const UGPoint2D* pPoints, const UGint* plPolyCounts, UGint lCount, 
					const UGRect2D& rectClip, UGPoint2Ds& resPoints, 
					UGArray<UGint>& resPolyCount, UGint& nResSubCount);

	static UGbool Clip(const UGPoint2D* pLinePoints,UGint nCount,const UGPoint2D* pRegionPoints,
						const UGint* pRegionPolyCount,UGint nRegionSubCount,
						UGList<UGPoint2D>&pntArray,UGArray<UGuint> &PolyArray,UGbool bInside=TRUE);

};

}

#endif
