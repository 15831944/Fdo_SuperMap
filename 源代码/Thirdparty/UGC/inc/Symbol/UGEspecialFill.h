// UGEspecialFill.h: interface for the UGEspecialFill class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGEspecialFill.h
   **************************************************************************************
    \author   �¹���
    \brief    ��������ࡣ                                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-24  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGESPECIALFILL_H__BBE9546F_9F24_4083_8BB9_4B71D2F97602__INCLUDED_)
#define AFX_UGESPECIALFILL_H__BBE9546F_9F24_4083_8BB9_4B71D2F97602__INCLUDED_

#include "Graphics/UGGraphics.h"

namespace UGC {

class SYMBOL_API UGEspecialFill  
{
public:
	UGEspecialFill();
	virtual ~UGEspecialFill();

public:	
	//! \brief ����ν������
	static UGbool GradientPolygon(UGGraphics *pGraphics, const UGPoint* pPoints, 
				UGint nCount, UGColor clrStart, UGColor clrEnd, UGdouble dRadian,
				UGint nHOffsetCenter = 0, UGint nVOffsetCenter = 0,
				UGint nGradientType = UGBrush::BrushGradientLinear,	UGint nTransPercent = 0);

	//! \brief �������ν������
	static UGbool GradientPolyPolygon(UGGraphics *pGraphics, const UGPoint* pPoints, 
				const UGint* pPolyCounts, UGint nCount, UGColor clrStart, UGColor clrEnd, 
				UGdouble dRadian, UGint nHOffsetCenter = 0, UGint nVOffsetCenter = 0,
				UGint nGradientType = UGBrush::BrushGradientLinear,	UGint nTransPercent = 0);

	//! \brief ���ν������
	static UGbool GradientRectangle(UGGraphics *pGraphics, const UGRect& rect, UGColor clrStart, 
				UGColor clrEnd, UGdouble dRadian, UGint nHOffsetCenter = 0, UGint nVOffsetCenter = 0,
				UGint nGradientType = UGBrush::BrushGradientLinear,	UGint nTransPercent = 0);

	//! \brief ����ΰ�͸�����
	static UGbool TransparentPolygon(UGGraphics *pGraphics, const UGPoint* pPoints, 
				UGint nCount, UGColor color, UGint nTransPercent = 0);

	//! \brief �������ΰ�͸�����
	static UGbool TransparentPolyPolygon(UGGraphics *pGraphics, const UGPoint* pPoints, 
				const UGint* pPolyCounts, UGint nCount, UGColor color, UGint nTransPercent = 0);

	//! \brief ���ΰ�͸�����
	static UGbool TransparentRectangle(UGGraphics *pGraphics, const UGRect& rect,
				UGColor color, UGint nTransPercent = 0);

	//! \brief Image��͸�����
	static UGbool TransparentBitblt(UGGraphics *pGraphics, UGImage *pImage, UGint nStartX,			
				UGint nStartY, UGint nWidth, UGint nHeight, UGint nTransPercent = 0);	

	//! \brief Image��͸�����
	static UGbool TransparentBitbltMask(UGGraphics *pGraphics, UGImage *pImage, 
				UGImage *pImageMask, UGint nStartX, UGint nStartY, UGint nWidth, 
				UGint nHeight, UGint nTransPercent = 0);
	//! \brief �õ���Ļ���ش�С
	static UGSize GetScreenSize();

	//! \brief ͸������λͼ��������һ����ɫ(�ɲ���clrTransparentָ��)����ڱ���ͼ͸����ʾ
	static void TransparentDraw(UGGraphics* pGraphics, UGImage* pImgSrc, 
		                 UGint xStart, UGint yStart, UGColor clrTransparent, UGint nTransPercent = 100);

protected:
	static UGdouble CalAzimuth(const UGPoint& pntStart, const UGPoint& pntEnd);

	static void GetSectionPoint(const UGPoint& pntStart, const UGPoint& pntEnd,
				UGPoint &pntSection);    

	static void GetEndPointOfColor(UGdouble dRadian, const UGRect &rect, UGPoint &pntStart, 
				UGPoint &pntEnd);

    static void GetColor(const UGPoint &pntStart, const UGPoint& pntEnd, UGColor clrStart, 
				UGColor clrEnd, const UGPoint& point, UGColor &color);

    static void GetVerticalPoint(const UGPoint& pntStart, const UGPoint& pntEnd, UGPoint &pntResult);    

	static UGImage* GetLinearImage(UGGraphics *pGraphics, const UGRect& rect, UGColor clrStart,
				UGColor clrEnd,	UGdouble dRadian);

	static UGImage* GetRadialImage(UGGraphics *pGraphics, const UGRect& rect, UGColor clrStart,
				UGColor clrEnd,	UGint nHOffsetCenter, UGint nVOffsetCenter);	  

	static UGImage* GetConicalImage(UGGraphics *pGraphics, const UGRect& rect, UGColor clrStart,
				UGColor clrEnd,	UGint nHOffsetCenter, UGint nVOffsetCenter, UGdouble dRadian);

	static UGImage* GetSquareImage(UGGraphics *pGraphics, const UGRect& rect, UGColor clrStart,
				UGColor clrEnd,	UGint nHOffsetCenter, UGint nVOffsetCenter, UGdouble dRadian);

};

}

#endif // !defined(AFX_UGESPECIALFILL_H__BBE9546F_9F24_4083_8BB9_4B71D2F97602__INCLUDED_)
