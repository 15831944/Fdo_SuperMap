// UGRasterScan.h: interface for the UGRasterScan class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGRasterScan.h
   **************************************************************************************
    \author   �¹���
    \brief    ʸ��դ��ɨ����                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-26  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGRASTERSCAN_H__4477CA04_A5A3_4196_BDB3_212AED1B043D__INCLUDED_)
#define AFX_UGRASTERSCAN_H__4477CA04_A5A3_4196_BDB3_212AED1B043D__INCLUDED_

#include "UGRect.h"
#include "Base/UGString.h"
#include "Base/UGTextStyle.h"

namespace UGC{

typedef void (*RASTERSCANPROC)(UGint X, UGint Y, UGuint pData);

class ALGORITHM_API UGRasterScan  
{
public:
	UGRasterScan();
	virtual ~UGRasterScan();

public:

	//! \brief �߶�
	static UGbool Line(UGint x1, UGint y1, UGint x2, UGint y2, RASTERSCANPROC pProcFunc, UGuint pData);	
	
	//! \brief �߶�
	static UGbool Line(const UGPoint& pntStart, const UGPoint& pntEnd, RASTERSCANPROC pProcFunc, UGuint pData);	
	
	//! \brief ����
	static UGbool Polyline(const UGPoint* pPoints, UGint nCount, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bClosed = false);
	
	//! \brief ��������
	static UGbool PolyPolyline(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bClosed = false);
	
	//! \brief �����
	static UGbool Polygon(const UGPoint* pPoints, UGint nCount, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief ��������
	static UGbool PolyPolygon(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief ����
	static UGbool Rectangle(UGint x1, UGint y1, UGint x2, UGint y2, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief ����
	static UGbool Rectangle(const UGRect& rect, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief ��Բ
	static UGbool Ellipse(UGint x1, UGint y1, UGint x2, UGint y2, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief ��Բ
	static UGbool Ellipse(const UGRect& rect, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);

	//! \brief ��
	static UGbool Arc(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4, RASTERSCANPROC pProcFunc, UGuint pData);
	
	//! \brief ��
	static UGbool Arc(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd, RASTERSCANPROC pProcFunc, UGuint pData);

	//! \brief ����
	static UGbool Chord(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief ����
	static UGbool Chord(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief ����
	static UGbool Pie(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief ����
	static UGbool Pie(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);

	//! \brief Բ�Ǿ���
	static UGbool RoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief Բ�Ǿ���
	static UGbool RoundRect(const UGRect& rect, UGPoint point, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief �ı� 
	//! \remark  ���ӿڻ�δʵ��
	static UGbool TextOut(UGint x, UGint y, const UGString& str, const UGTextStyle& textStyle, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief �ı� 
	//! \remark  ���ӿڻ�δʵ��
	static UGbool TextOut(const UGPoint& point, const UGString& str, const UGTextStyle& textStyle, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);

};

}

#endif // !defined(AFX_UGRASTERSCAN_H__4477CA04_A5A3_4196_BDB3_212AED1B043D__INCLUDED_)
