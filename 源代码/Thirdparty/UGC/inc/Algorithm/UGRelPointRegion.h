/*! \file	 UGRelPointRegion.h
 *  \brief	 �����Ŀռ�λ�ù�ϵ�ж�
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelPointRegion.h,v 1.5 2007/09/29 06:06:08 guohui Exp $
 */


#if !defined(AFX_UGRELPOINTREGION_H__2312A74C_9CD3_48E9_A1D8_62AE9DC2BF70__INCLUDED_)
#define AFX_UGRELPOINTREGION_H__2312A74C_9CD3_48E9_A1D8_62AE9DC2BF70__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGRect2D.h"

namespace UGC {

//! \brief �����Ŀռ�λ�ù�ϵ�ж�
class ALGORITHM_API UGRelPointRegion  
{
private:
	UGRelPointRegion();

public:  
	

	//! \brief ���Ƿ��ڼ򵥶������
	//! \param pBounds ��ѡ����, ����ε�Bounds
	//! \param bInside ���ڶ���α߽���, �����ڻ���������, =trueʱ,������; =falseʱ,������
	static UGbool IsWithin(const UGPoint2D& pnt, 
						   const UGPoint2D* pPoints, UGint nPntCount, 
						   const UGRect2D* pBounds=NULL,UGbool bInside=true);

	//! \brief ���Ƿ��ڸ��Ӷ������
	//! \param pBounds ��ѡ����, ����ε�Bounds
	//! \param bInside ���ڶ���α߽���, �����ڻ���������,=trueʱ,������; =falseʱ,������
	static UGbool IsWithin(const UGPoint2D& pnt, 
						   const UGPoint2D* pPoints, const UGint* pPolyCount, UGint nSubCount, 
						   const UGRect2D* pBounds=NULL,UGbool bInside=true);
	
	//! \brief ���Ƿ��ڸ��Ӷ������
	//! \param pBounds ����ε�Bounds
	//! \param dTolerance	���� 
	//! \return 0	���ڶ�����ⲿ; 1	���ڶ�����ڲ�;	 2 ���ڱ߽���;
	static UGint IsWithin(const UGPoint2D &point, UGPoint2D *pPoints,UGint *plPolyCounts,
							UGint nSubCount, const UGRect2D &rcFrame, UGdouble dTolerance=EP);


};

}

#endif // !defined(AFX_UGRELPOINTREGION_H__2312A74C_9CD3_48E9_A1D8_62AE9DC2BF70__INCLUDED_)
