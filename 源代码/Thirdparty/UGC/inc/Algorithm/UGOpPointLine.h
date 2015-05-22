/*! \file	 UGOpPointLine.h
 *  \brief	 ��/�� ֮��Ŀռ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOpPointLine.h,v 1.11 2007/10/19 03:01:30 guohui Exp $
 */


#if !defined(AFX_UGOPPOINTLINE_H__7A4B3872_A489_4650_8358_D2B6A03AFA6C__INCLUDED_)
#define AFX_UGOPPOINTLINE_H__7A4B3872_A489_4650_8358_D2B6A03AFA6C__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGPoint3D.h"

namespace UGC {
//! \brief ��/�� ֮��Ŀռ�����
class ALGORITHM_API UGOpPointLine  
{
private:
	UGOpPointLine();
	
public: // ��㵽�ߵľ���
	
	//! \brief �õ�ָ����
	static UGbool Split(const UGPoint2D& pntSplit, const UGPoint2D* pLinePoints, 
						UGint nLinePntCount, UGPoint2Ds& pntResLine1, 
						UGPoint2Ds& pntResLine2);

	//! \brief ��Point2D�ָ���ά�ߣ���LineM.��ϵ��Zֵ����ֵ
	static UGbool Split(const UGPoint2D& pntSplit, const UGPoint3D* pLinePoints, 
						UGint nLinePntCount, UGPoint3Ds& pntResLine1, 
						UGPoint3Ds& pntResLine2);

	//! \brief �㵽�߶εľ���
	//! \return ����㵽�߶εĴ������߶���,�򷵻ص㵽����ľ���; 
	//!			���򷵻ص㵽�߶������˵����Ľ�Сֵ
	static UGdouble DistanceToSegment(const UGPoint2D& pnt, 
							 const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief �㵽ֱ�ߵľ���
	static UGdouble DistanceToLine(const UGPoint2D& pnt, 
							 const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief �㵽ֱ�ߵľ����ƽ��
	static UGdouble DistanceToLineSquare(const UGPoint2D& pnt, 
							 const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief �㵽���ߵľ���
	//! \remarks �ǵ�vertex����Сֵ, �� ���߶δ������Сֵ �е���Сֵ
	static UGdouble Distance(const UGPoint2D& pnt, 
							 const UGPoint2D* pPoints, UGint nPntCount);
	//{{ by guohui 2007.10.12
	//! \brief �㵽���ߵľ���
	static UGdouble Distance(const UGPoint2D& pnt, 
							 const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint nSubCount);
	//}} by guohui 2007.10.12

	//! \brief �㵽�����ϵ�ľ������Сֵ �� �����ϸõ��Index
	//! \remarks ��Ҫ����Сֵ�����dMinValue����С,���򷵻�0,nPntIndex==-1
	static UGdouble MinDistanceToVertex(const UGPoint2D& pnt, 
							 const UGPoint2D* pPoints, UGint nPntCount, 
							 UGint& nPntIndex, UGdouble dMinValue=INFINITEBIG);

	// by guohui 2007.09.13
	//! \brief �㵽���ߵľ������Сֵ�Լ���Ӧ�ĵ�
	//! \param pntHitTest	[in]		��
	//! \param pPoints		[in]		���ߵĵ�
	//! \param nPntCount	[in]		���ߵ����
	//! \param pntProject	[in]		ӳ���
	//! \return �ɹ�,����true
	static UGbool NearestPointToVertex(const UGPoint2D& pntHitTest, 
							 const UGPoint2D* pPoints, UGint nPntCount, 
							 UGPoint2D & pntProject,UGdouble &dDistance);

	// by guohui 2007.10.09
	//! \brief �㵽���ߵľ������Сֵ�Լ���Ӧ�ĵ�
	//! \param pntHitTest	[in]		��
	//! \param pPoints		[in]		���ߵĵ�
	//! \param pPolyCounts	[in]		���ߵ����
	//! \param pntProject	[in]		ӳ���
	//! \return �ɹ�,����true
	static UGbool NearestPointToVertex(const UGPoint2D& pntHitTest, 
							 const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint nSubCount, 
							 UGPoint2D & pntProject,UGdouble &dDistance);

	//! \brief �㵽�������߶εľ������Сֵ �� ���߶ε���ʼ��Index
	//! \remarks ��Ҫ����Сֵ�����dMinValue����С,���򷵻�0,nPntIndex==-1
	static UGdouble MinDistanceToSegment(const UGPoint2D& pnt, 
							 const UGPoint2D* pPoints, UGint nPntCount, 
							 UGint& nPntIndex, UGdouble dMinValue=INFINITEBIG);
	
	//!  \brief �㵽�������߶εľ���
	//! \remarks ������������ת����Ҫ�õ�
	static  UGdouble DistPtToLinesect(const UGPoint2D &pntStart, const UGPoint2D &pntEnd, 
									const UGPoint2D &pntHitTest, UGdouble& dDistToFrom);

	//! \brief	 �㵽�߶ε�������
	//! \remarks ������: �߶��ϴ���һ��pntTest,ʹ��Ditance(pntTest,pntHitTest)���
	static  UGdouble MaxDistance(const UGPoint2D &pntHitTest, 
								 const UGPoint2D &pntStart, const UGPoint2D &pntEnd );
	
	//! \brief	 �㵽�߶ε�������
	//! \remarks ������: �߶��ϴ���һ��pntTest,ʹ��Ditance(pntTest,pntHitTest)���
	static  UGdouble MaxDistance(const UGPoint2D& pntHitTest, 
							 const UGPoint2D* pPoints, UGint nPntCount );

	//! \brief	 �㵽�߶ε�������
	//! \remarks ������: �߶��ϴ���һ��pntTest,ʹ��Ditance(pntTest,pntHitTest)���
	static  UGdouble MaxDistance(const UGPoint2D& pntHitTest, 
							 const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint nSubCount);

	//! \brief		�����ϣ��㵽ֱ�ߵľ���
	//! \param		pntHitTest  ����ĵ�(x,y����ֱ��ʾ���Ⱥ�ά��)
	//! \param		pntStart	����ĵ�(x,y����ֱ��ʾ���Ⱥ�ά��)
	//! \param		pntEnd		����ĵ�(x,y����ֱ��ʾ���Ⱥ�ά��)
	//! \param		dRadius		����뾶
	static  UGdouble RadianDistPointToLinesect(const UGPoint2D &pntHitTest, 
					 const UGPoint2D &pntStart, const UGPoint2D &pntEnd , double dRadius=6371118);
public: // ��㵽�ߵĴ���

	//! \brief ��㵽ֱ�ߵĴ���
	static UGPoint2D ProjectPoint(const UGPoint2D& pnt,
								  const UGPoint2D& pnt1, const UGPoint2D& pnt2);


public: // �õ�����

	//! \brief �õ�����
	//! \param pntResults ����ʱ,����Ϊ������
	//! \return �ɹ����,����true
	static UGbool Break(const UGPoint2D& pnt, 
						  const UGPoint2D* pPoints, UGint nPntCount, 
						  UGArray<UGPoint2Ds*>& pntResults);

	//! \brief �õ�����
	//! \param pntResults ����ʱ,����Ϊ������
	//! \return �ɹ����,����true
	static UGbool Break(const UGPoint2D& pnt, 
						  const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint nSubCount, 
						  UGArray<UGPoint2Ds*>& pntResults);

};

}

#endif // !defined(AFX_UGOPPOINTLINE_H__7A4B3872_A489_4650_8358_D2B6A03AFA6C__INCLUDED_)
