/*! \file	 UGRelLineRegion.h
 *  \brief	 ����ռ�λ�ù�ϵ�ж�
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelLineRegion.h,v 1.4 2007/10/16 02:23:22 guohui Exp $
 */


#if !defined(AFX_UGRELLINEREGION_H__9DE64C51_B071_45AB_AC10_B9487CE80304__INCLUDED_)
#define AFX_UGRELLINEREGION_H__9DE64C51_B071_45AB_AC10_B9487CE80304__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"

namespace UGC {

//! \brief ����ռ�λ�ù�ϵ�ж�
class ALGORITHM_API UGRelLineRegion  
{
private:
	UGRelLineRegion();
	
public: // ��������ռ�λ�ù�ϵ�ж�
	
	//! \brief ���Ƿ�������ڲ�
	//! \remarks ����ߵĽ���������,�߿��Ժ���ı߽��н���
	static UGbool IsWithin(const UGPoint2D* pLinePoints, UGint nLinePntCount,
							const UGPoint2D* pRgnPoints, UGint nRgnPntCount);

	//{{ add by guohui 2007.10.12
	//! \brief ���Ƿ�������ڲ�
	static UGbool IsWithin(const UGPoint2D* pLinePoints, const UGint* pLinePolyCount,UGint nLineSubCount,
							const UGPoint2D* pRgnPoints, const UGint* pRgnPolyCount,UGint nRgnSubCount);

	//! \brief ���Ƿ�������ڲ�
	static UGbool IsWithin(const UGPoint2D* pLinePoints, UGint nLinePntCount,
							const UGPoint2D* pRgnPoints, const UGint* pRgnPolyCount,UGint nRgnSubCount);
	//}} add by guohui 2007.10.12

	//! \brief ���Ƿ��Խ��
	//! \remarks �ߺ�����ڲ����ⲿ�Ľ�����Ϊһά
	static UGbool IsCross(const UGPoint2D* pLinePoints, UGint nLinePntCount,
						  const UGPoint2D* pRgnPoints, UGint nRgnPntCount);

	//{{ add by guohui 2007.10.12	
	//! \brief ���Ƿ�Ӵ���
	//! \remarks �ߺ���ı߽��н���
	static UGbool IsTouch(const UGPoint2D* pLinePoints, const UGint* pLinePolyCount,UGint nLineSubCount,
							const UGPoint2D* pRgnPoints, const UGint* pRgnPolyCount,UGint nRgnSubCount);
	//}} add by guohui 2007.10.12

	//! \brief ���Ƿ�Ӵ���
	//! \remarks �ߺ���ı߽��н���
	static UGbool IsTouch(const UGPoint2D* pLinePoints, UGint nLinePntCount,
						  const UGPoint2D* pRgnPoints, UGint nRgnPntCount);

	//! \brief ���Ƿ��������
	//! \remarks �ߺ���ı߽硢�ⲿ�Ľ�����Ϊ��
	static UGbool IsDisjoint(const UGPoint2D* pLinePoints, UGint nLinePntCount,
							 const UGPoint2D* pRgnPoints, UGint nRgnPntCount);

public: // ���������ռ�λ�ù�ϵ�ж�

	// add by guohui 2007.10.12	copy from UGGeoRelation::IsRegionIIntersectLineB
	//! \brief ���Ƿ�����ཻ 
	static UGbool IsRegionIIntersectLine(UGPoint2D *pRegionPoints,UGint *pRegionCounts,UGint nRegionSubCount,
										  UGPoint2D *pLinePoints,UGint *pLineCounts,UGint nLineSubCount);
private: // �ڲ�����

	//! \brief �ߺ���ı߽��޽���
	static UGbool IsIrrelative(const UGPoint2D *pLinePoints, UGint lLinePntCount, 
						const UGPoint2D *pRegPoints, UGint lRegPntCount);
};

}

#endif // !defined(AFX_UGRELLINEREGION_H__9DE64C51_B071_45AB_AC10_B9487CE80304__INCLUDED_)
