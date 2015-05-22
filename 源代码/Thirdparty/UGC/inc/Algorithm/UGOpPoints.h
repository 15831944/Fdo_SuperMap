/*! \file	 UGOpPoints.h
 *  \brief	 �� �Լ� ���֮��Ŀռ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOpPoints.h,v 1.16 2007/10/08 07:54:29 guohui Exp $
 */


#ifndef UGOPPOINTS_H
#define UGOPPOINTS_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGRect2D.h"
#if PACKAGE_TYPE==PACKAGE_UGC
#include "Base/UGList.h"
#endif // end declare ugc API

namespace UGC {

//! \brief �� �Լ� ���֮��Ŀռ�����
//! \remarks ���ﶨ��: �Ƕ� Angle; ���� Radian
class ALGORITHM_API UGOpPoints  
{
private:
	UGOpPoints();

public: // ��ת

	//! \brief �����Ƕȼ������ת(��ʱ�뷽��)
	static void RotateAngle(const UGPoint2D& pntAnchor, UGdouble dAngle, 
							UGPoint2D& pntSource);

	//! \brief �����Ƕ������������ת(��ʱ�뷽��)
	static void RotateAngle(const UGPoint2D& pntAnchor, UGdouble dAngle, 
							UGPoint2D* pPoints, UGint nPntCount);

	//! \brief �������ȼ������ת(��ʱ�뷽��)
	static void RotateRadian(const UGPoint2D& pntAnchor, UGdouble dRadian, 
							 UGPoint2D& pntSource);

	//! \brief �������������������ת(��ʱ�뷽��)
	static void RotateRadian(const UGPoint2D& pntAnchor, UGdouble dRadian, 
							 UGPoint2D* pPoints, UGint nPntCount);

	//! \brief ��������(cos,sin)�������ת(��ʱ�뷽��)
	static void Rotate(const UGPoint2D& pntAnchor, UGdouble dCos, UGdouble dSin, 
						UGPoint2D& pntSource);

	//! \brief ��������(cos,sin)�����������ת(��ʱ�뷽��)
	static void Rotate(const UGPoint2D& pntAnchor, UGdouble dCos, UGdouble dSin, 
					   UGPoint2D* pPoints, UGint nPntCount);


public: // ����Ƕ�

	//! \brief ��������ķ�λ��(�Ƕ�)
	//! \remarks ��λ��: ��ĳ���ָ������������˳ʱ�뷽��Ŀ�귽����֮���ˮƽ�н�
	static UGdouble Azimuth(const UGPoint2D& pntFrom, const UGPoint2D& pntTo);


	//! \brief ��������ĽǶ�(�������������ʱ��н�)
	//! \brief ����������Ϊ��ʼ���ߣ���ʱ����ת����pntFrom-pntTo�ĽǶ�
	static UGdouble Angle(const UGPoint2D& pntFrom, const UGPoint2D& pntTo);

	//! \brief ��������Ļ���(�������������ʱ��н�)
	static UGdouble Radian(const UGPoint2D& pntFrom, const UGPoint2D& pntTo);


public: // �������

	//! \brief ƽ�������ľ����ƽ��
	static UGdouble DistanceSquare(const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief ƽ�������ľ���
	static UGdouble Distance(const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief ���������ľ���.pnt1 �� pnt2���ڴ�Բ��
	//! \remarks sphere n. ��, ����, ����, ����; ����뾶Ĭ��������Ϊ��λ,���Ը���
	//! \param pnt1 ����ֵ���붼�Ǿ�γ����
	//! \param pnt2 ����ֵ���붼�Ǿ�γ����
	//! \return	����ֵ�͵���뾶��λһ��
	static UGdouble SphereDistance(const UGPoint2D& pnt1, const UGPoint2D& pnt2, 
									UGdouble dRadius=6371118);

	// zengzm: ��������ľ�ȷ����,�����д��õ�ʱ�ٴ���� 
	//! \brief �������������ľ���
	//! \remarks ellipsoid n.��Բ��
	//! \param dPrimeAxis ����
	//! \param dFlattening ����
	//static UGdouble EllipsoidDistance(const UGPoint2D& pnt1, const UGPoint2D& pnt2, 
	//								UGdouble dPrimeAxis, UGdouble dFlattening);
	
public: // ����Bounds

	//! \brief ����Bounds
	static UGRect2D Bounds(const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief ����Bounds
	static UGRect2D Bounds(const UGPoint2D* pPoints, UGint nPntCount);

	//! \brief ����Bounds
	static UGRect2D Bounds(const UGPoint2D* pPoints, const UGint* pPolyCounts, UGint nSubCount);
	
public: // ȥ��	�ظ���

	//! \brief ȥ���ظ���
	//! \param pntResults ����ʱ����Ϊ�ռ�
	static void CleanRepeat(const UGPoint2D* pPoints, UGint nPntCount, UGPoint2Ds& pntResults);

public:
	// add by guohui 2007.10.08
	//! \brief ������ͬ��
	static UGbool GetSamePnts(const UGPoint2D* pPoints1, const UGint* pPolyCount1,UGint nSubCount1,
							const UGPoint2D* pPoints2, const UGint* pPolyCount2,UGint nSubCount2,
							UGPoint2Ds& pntResult);

#if PACKAGE_TYPE==PACKAGE_UGC
public: // ����͹��

	//! \brief ����㴮��͹��
	//! \param pPoints ����ĵ�
	//! \param nPntCount ����� �����������ڵ���2
	//! \param pntResult ���ص��׵��ĩ����ͬ
	static void Flange(const UGPoint2D* pPoints, UGint nPntCount, UGPoint2Ds& pntResult);
	
	//! \brief ���㾵�� �����
	//! \param pPointDes �ⲿ���������ڴ�
	static UGbool Mirror(UGPoint2D *pPointSrc, UGint nPointCount, UGPoint2D *pPointDes,
						  const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
	//! \brief ���㾵�� һ���㡣
	//! \param pntSrc [in] ԭʼ�㡣
	//! \param pntDes [out] �����ĵ㡣
	//! \param pntMirror1 [in] ���ɾ���ĵ�һ���㡣
	//! \param pntMirror2 [in] ���ɾ���ĵڶ����㡣
	//! \return ������ɾ���ĵ��غ�,����false��
	static UGbool Mirror(const UGPoint2D& pntSrc, UGPoint2D& pntDes,
						  const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
	//! \brief ���㾵�� �Ƕȡ�
	//! \param dAngleSrc [in] ԭʼ�Ƕȡ�
	//! \param dAngleDes [out] �����ĽǶȡ�
	//! \param pntMirror1 [in] ���ɾ���ĵ�һ���㡣
	//! \param pntMirror2 [in] ���ɾ���ĵڶ����㡣
	//! \return ������ɾ���ĵ��غ�,����false��
	static UGbool Mirror(UGdouble dAngleSrc, UGdouble& dAngleDes, 
						const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);	

public: // �����Ľ��������
	
	// by guohui 2007.09.19 ��������������죬ע�͵����ⲿҲû��ʹ�á�
	//! \brief �����Ľ��������
	//! \param pnt2sSource [in]  ����ĵ㡣
	//! \param pnt2sRezult [out] ����㡣
	//! \return �����ķ��ظ�������������2����False.���е����һ��ֱ���Ϸ���false
	//static UGbool ImpactRegion(const UGPoint2D* pnt2sSource, UGint nPntCount, UGPoint2Ds& pnt2sRezult);

private:
	// by guohui 2007.09.19 ����ķ����Ѿ�����ʹ����
//	// ����͹������Ҫ�õ��ļ�������
//	static void UpLeft(const UGPoint2D* pPoints, UGint nPntCount, UGList<int> &transmitted);
//	static void DownLeft(const UGPoint2D* pPoints, UGint nPntCount, UGList<int> &transmitted);
//	static void DownRight(const UGPoint2D* pPoints, UGint nPntCount, UGList<int> &transmitted);
//	static void UpRight(const UGPoint2D* pPoints, UGint nPntCount, UGList<int> &transmitted);
//	static UGbool Concavity(const UGPoint2D& pnta, const UGPoint2D& pntb, const UGPoint2D& pntc);
#endif // end declare ugc API
};

}

#endif
