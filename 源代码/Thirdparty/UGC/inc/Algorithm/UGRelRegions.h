/*! \file	 UGRelRegions.h
 *  \brief	 �ж�����֮��Ŀռ��ϵ
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelRegions.h,v 1.4 2007/10/16 02:23:23 guohui Exp $
 */



#if !defined(AFX_UGRELREGIONREGION_H__028F4851_CE7D_4268_B59C_F8C3F632ECF1__INCLUDED_)
#define AFX_UGRELREGIONREGION_H__028F4851_CE7D_4268_B59C_F8C3F632ECF1__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGRect2D.h"

namespace UGC {

//! \brief �ж�����֮��Ŀռ��ϵ
class ALGORITHM_API UGRelRegions
{
private:
	UGRelRegions();
	
public: // ��������ռ�λ�ù�ϵ�ж�

	//! \brief �ж��������Ƿ��ͬ
	//! \remarks ��ĸ���,˳��,���� ������һ��
	static UGbool IsIdentical(const UGPoint2D* pPoints1, UGint nPntCount1, 
							  const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief �ж��������Ƿ��ͬ
	//! \remarks ��ĸ���,˳��,���� ������һ��
	static UGbool IsIdentical(const UGPoint2D* pPoints1,const UGint* pPolyCount1, UGint nSubCount1, 
							const UGPoint2D* pPoints2,const UGint* pPolyCount2, UGint nSubCount2 );
	// by guohui 2007.10.12	
	//! \brief �ж���1�Ƿ���ȫ����2���ڲ�
	static UGbool IsWithin(const UGPoint2D* pPoints1,const UGint* pPolyCount1, UGint nSubCount1, 
							const UGPoint2D* pPoints2,const UGint* pPolyCount2, UGint nSubCount2 );

	//! \brief �ж���1�Ƿ���ȫ����2���ڲ�
	static UGbool IsWithin(	const UGPoint2D* pPoints1,const UGint* pPolyCount1, UGint nSubCount1,
							const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief �ж���1�Ƿ���ȫ����2���ڲ�
	//! \remarks ������Ľ���������1
	static UGbool IsWithin(const UGPoint2D* pPoints1, UGint nPntCount1, 
							const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief �ж���1�Ƿ���ȫ����2���ڲ�
	//! \remarks ����������Ѿ�ȷ��û���ཻ��ϵ������������ȷ������Ը���
	//��Ҫ�����ж϶���������Ӷ���֮����໥��ϵ��
	static UGbool IsWithin(const UGPoint2D* pPoints1, UGint nPntCount1, UGRect2D rcBounds1, 
							const UGPoint2D* pPoints2, UGint nPntCount2, UGRect2D rcBounds2);
	
	//! \brief �ж��������Ƿ�Ӵ�
	//! \remarks ������ı߽�Ľ�����Ϊ��
	static UGbool IsTouch(const UGPoint2D* pPoints1, UGint nPntCount1, 
						  const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief �ж��������Ƿ񽻵�
	//! \remarks ������Ľ����ж�ά����, ͬʱ�����������κ�һ����
	static UGbool IsOverlap(const UGPoint2D* pPoints1, UGint nPntCount1, 
						  const UGPoint2D* pPoints2, UGint nPntCount2);


	//! \brief �ж��������Ƿ�����
	//! \remarks ������ı߽� �ڲ��Ľ�����Ϊ��
	static UGbool IsDisjoint(const UGPoint2D* pPoints1, UGint nPntCount1, 
							 const UGPoint2D* pPoints2, UGint nPntCount2);

};

}

#endif // !defined(AFX_UGRELREGIONREGION_H__028F4851_CE7D_4268_B59C_F8C3F632ECF1__INCLUDED_)
