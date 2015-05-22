/*! \file	 UGRelPoints.h
 *  \brief	 ���֮��Ŀռ��ϵ�ж�
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelPoints.h,v 1.8 2007/11/09 10:06:21 qiuli Exp $
 */



#if !defined(AFX_UGRELPOINTS_H__737795B6_7D1B_46C4_95CB_0A7A648655FB__INCLUDED_)
#define AFX_UGRELPOINTS_H__737795B6_7D1B_46C4_95CB_0A7A648655FB__INCLUDED_


#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"


namespace UGC {

//! \brief ���֮��Ŀռ��ϵ�ж�
class ALGORITHM_API UGRelPoints  
{
private:
	UGRelPoints();

#if PACKAGE_TYPE==PACKAGE_UGC
	
public: // ����/��Բ �ȵ��ж�

	//! \brief		�����Ƿ���
	//! \remarks 	���غϵ㣬Ҳ����
	static UGbool IsOnSameLine(const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3);

	//! \brief �ĵ��Ƿ�Բ
	static UGbool IsOnSameCircle(const UGPoint2D& pnt1, const UGPoint2D& pnt2, 
								 const UGPoint2D& pnt3, const UGPoint2D& pnt4);
#endif // end declare ugc API

public: // �����ж�

	//! \brief �����Ƿ���ʱ������
	static UGbool IsCounterClockwise(const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3);

	//! \brief �㼯��Bounds�Ƿ��ཻ
	//! \remarks �ܶ�ռ�λ���жϿ�������Bounds�Ƿ��ཻ���й���
	static UGbool IsExtentOverlap(const UGPoint2D* pPoints1, UGint nPntCount1,
								const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief	 �ж��Ƿ��й�ͬ��
	static UGbool IsCommonPoint(const UGPoint2D* pPoints1, UGint nPntCount1,
								const UGPoint2D* pPoints2, UGint nPntCount2);

	static UGbool EQ(const UGPoint2D& pnt1, const UGPoint2D& pnt2, UGdouble dTolerance);
};

}

#endif // !defined(AFX_UGRELPOINTS_H__737795B6_7D1B_46C4_95CB_0A7A648655FB__INCLUDED_)
