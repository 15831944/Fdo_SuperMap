/*! \file	 UGRelPointLine.h
 *  \brief	 �жϵ���֮��Ŀռ�λ�ù�ϵ
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelPointLine.h,v 1.8 2007/11/12 07:42:24 guohui Exp $
 */

#if !defined(AFX_UGRELPOINTLINE_H__5CEDF8F8_5E21_43F5_B5E5_1F502EEE435C__INCLUDED_)
#define AFX_UGRELPOINTLINE_H__5CEDF8F8_5E21_43F5_B5E5_1F502EEE435C__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"

namespace UGC {

//! \brief �жϵ���֮��Ŀռ�λ�ù�ϵ
class ALGORITHM_API UGRelPointLine  
{
private:
	UGRelPointLine();
	 
public: // �� �߶λ����ռ�λ�ù�ϵ�ж�

	//! \brief �жϵ��Ƿ����߶ε����
	static UGbool IsLeft(const UGPoint2D& pnt, 
						 const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief �жϵ��Ƿ����߶ε��ұ�
	static UGbool IsRight(const UGPoint2D& pnt, 
						  const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief �жϵ��Ƿ����߶���(�����ӳ���)
	static UGbool IsOnLineSegment(const UGPoint2D& pnt, const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
									UGdouble dTolerance=EP);

public: // ���� ��չ�ռ�λ�ù�ϵ�ж�(���û���λ�ù�ϵ�ж��Ƶ��õ�)

	//! \brief �жϵ��Ƿ���ֱ����(�����߶μ����ӳ���)
	static UGbool IsOnLine(const UGPoint2D& pnt, 
						   const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief �õ����ֱ�ߵ�λ�ù�ϵ
	//! \return 1��ʾ����ֱ�ߵ����, -1��ʾ���ұ�, 0 ��ʾ��ֱ����
	static UGint PntMatchLine(const UGPoint2D& pnt, 
							   const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief �жϵ��Ƿ������ߵ����
	//! \remarks ���þ����������߶δ�������,�ж�����߻����ұ�
	static UGbool IsLeft(const UGPoint2D& pnt, 
						 const UGPoint2D* pPoints, UGint nPntCount);

	//! \brief �жϵ��Ƿ���������
	static UGbool IsOnPolyline(const UGPoint2D& pnt, 
							   const UGPoint2D* pPoints, UGint nPntCount);
	// add by guohui 2007.10.08
	//! \brief �жϵ��Ƿ���������
	static UGbool IsOnPolyline(const UGPoint2D &pnt, 
							   const UGPoint2D *pPoints,const UGint* pPolyCount,UGint nSubCount);

	//! \brief �ж��������Ƿ���ֱ�ߵ�ͬһ��
	//! \return 0,��ͬһ��ֱ����; 1,��ͬһ��; 2, ������; 3,��һ����ֱ����
	static UGuint IsOnSameSide(const UGPoint2D& pnt1, const UGPoint2D& pnt2, 
							   const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

public: // ������ϵ�ж�

	//! \brief �жϵ����߶εĴ����Ƿ����߶���
	static UGbool IsProjectOnLineSegment(const UGPoint2D& pnt, 
										 const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief �жϵ����߶εĴ����Ƿ����߶��ڲ�(�������߶ε������˵�)
	static UGbool IsProjectOnLineSegmentInterior(const UGPoint2D& pnt, 
										 const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief �жϵ㵽�߶εľ����Ƿ���ָ����������
	static UGbool IsNearToLineSegment(const UGPoint2D& pnt, 
									  const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
									  UGdouble dTolerance);
	
	//! \brief �жϵ㵽�߶εľ����Ƿ���ָ����������
	//! \return -1���������ڣ��������ֵ����[0,1]����ʾ��pnt�������pntStart-penEnd�ϵ�λ�ñ�����
	static UGdouble NearToLineSegment(const UGPoint2D& pnt, const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
									UGdouble dTolerance);
	
	//! \brief �жϵ㵽���ߵľ����Ƿ���ָ����������
	static UGbool IsNearToPolyline(const UGPoint2D& pnt, 
								   const UGPoint2D* pPoints, UGint nPntCount,
								   UGdouble dTolerance);
	
	//! \brief �жϵ㵽�ߵľ����Ƿ���ָ����������
	//!	\remark �����߶�ʹ�������жϣ��м��߶�ʹ���߶��жϡ�
	static UGbool IsPointOnLine(const UGPoint2D &pntTest, UGPoint2D *pPoints, UGint nCount, UGdouble dTolerance);
	
	//! \brief �жϵ㵽�ߵľ����Ƿ���ָ����������
	static UGbool IsPointOnLine(const UGPoint2D &pntTest, const UGPoint2D &pntStart, const UGPoint2D &pntEnd,
								UGdouble dTolerance);


};

}

#endif // !defined(AFX_UGRELPOINTLINE_H__5CEDF8F8_5E21_43F5_B5E5_1F502EEE435C__INCLUDED_)
