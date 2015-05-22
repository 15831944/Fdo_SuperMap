// UGWGraphics.h: interface for the UGWGraphics class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGWGraphics.h
   **************************************************************************************
    \author   ���������¹���
    \brief    Windowsͼ����ʾ��                                                      
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGWGRAPHICS_H__DF5DB089_3725_4D76_963F_BF593DB7D870__INCLUDED_)
#define AFX_UGWGRAPHICS_H__DF5DB089_3725_4D76_963F_BF593DB7D870__INCLUDED_

#include "Graphics/UGGraphics.h"

// added by zengzm 2007-4-29 ������Ͷ���, ������gdiplus��Ҫ,��ֻ��vc8��ͷ�ļ��ж���
#if defined(_WIN64)
    typedef unsigned __int64 ULONG_PTR;
#elif (_MSC_VER == 1200) //Defined as 1200 for Microsoft Visual C++ 6.0. 
//#else
    typedef unsigned long ULONG_PTR;
#else // VC8
	typedef _W64 unsigned long ULONG_PTR;
#endif

namespace UGC
{

class WGRAPHICS_API UGWGraphics : public UGGraphics  
{
public:
	UGWGraphics();
	virtual ~UGWGraphics();
	
	//! ��ȡʵ�ʶ���
	virtual void GetGraphicsData(UGGraphicsData &data) const;
	//! ����ʵ�ʶ���
	virtual void SetGraphicsData(const UGGraphicsData &data);
	virtual UGbool CreateCompatibleGraphics(UGGraphics* pGraphics);
	virtual UGbool DeleteGraphics();

	virtual UGbool IsPrinting() const;

	virtual UGImage* SelectImage(UGImage *pImage);
	virtual UGFont* SelectFont(UGFont *pFont);
	virtual UGBrush* SelectBrush(UGBrush *pBrush);
	virtual UGPen* SelectPen(UGPen *pPen);
	
	// ��ȡǰ��ɫ
	virtual UGColor GetForeColor() const;
	// ����ǰ��ɫ
	virtual UGColor SetForeColor(UGColor color);
	// ��ȡ����ɫ
	virtual UGColor GetBackColor() const;
	// ���ñ���ɫ
	virtual UGColor SetBackColor(UGColor color);

	// ��ȡ����ģʽ
	virtual UGint GetBackMode() const;
	// ���ñ���ģʽ
	virtual UGint SetBackMode(UGint nBKMode);

	virtual UGint SetROP2(UGint nDrawMode);
	virtual UGint GetROP2();

	// ��ȡӳ��ģʽ
	virtual UGint GetMapMode() const;
	// ����ӳ��ģʽ
	virtual UGint SetMapMode(UGint nMapMode);	

	virtual void DPtoLP(UGPoint* pPoints, UGint nCount = 1);
	virtual void DPtoLP(UGRect& rect);
	virtual void DPtoLP(UGSize& size);
	virtual void LPtoDP(UGPoint* pPoints, UGint nCount = 1);
	virtual void LPtoDP(UGRect& rect);
	virtual void LPtoDP(UGSize& size);
	
	virtual void LPtoHIMETRIC(UGSize& size);
	virtual void DPtoHIMETRIC(UGSize& size);
	virtual void HIMETRICtoLP(UGSize& size);
	virtual void HIMETRICtoDP(UGSize& size);

	virtual UGRgn* SelectClipRgn(UGRgn* pRgn, UGint nMode);

	virtual UGPoint GetCurrentPosition() const;

	// ��ȡ����ֵ
	virtual UGColor GetPixel(UGint x,UGint y);
	// ��������ֵ
	virtual UGColor SetPixel(UGint x,UGint y, UGColor color);

	// 
	virtual UGPoint MoveTo(UGint x,UGint y);
	// 
	virtual UGbool LineTo(UGint x,UGint y);
	// 
	virtual UGPoint MoveTo(UGPoint point);
	// 
	virtual UGbool LineTo(UGPoint point);

	// ��ֱ��
	virtual UGbool Line(UGint x1,UGint y1,UGint x2,UGint y2);
	// ��ֱ��
	virtual UGbool Line(UGPoint point1, UGPoint point2);

	// ������
	virtual UGbool Polyline(const UGPoint* pPoints, UGint nCount);
	// ����������
	virtual UGbool PolyPolyline(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount);

	// �������
	virtual UGbool Polygon(const UGPoint* pPoints, UGint nCount);
	// ����������
	virtual UGbool PolyPolygon(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount);

	// ������
	virtual UGbool Rectangle(UGint x1, UGint y1, UGint x2, UGint y2);
	virtual UGbool Rectangle(const UGRect& rect);

	// ����Բ
	virtual UGbool Ellipse(UGint x1, UGint y1, UGint x2, UGint y2);
	virtual UGbool Ellipse(const UGRect& rect);

	// ����
	virtual UGbool Arc(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 );
	virtual UGbool Arc(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd); 

	// ������
	virtual UGbool Chord(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 );
	virtual UGbool Chord(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd); 
	// ������
	virtual UGbool Pie(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 );
	virtual UGbool Pie(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd); 

	// ��Բ�Ǿ���
	virtual UGbool RoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3);
	virtual UGbool RoundRect(const UGRect& rect, UGPoint point); 

	// ��ͼƬ
	virtual UGbool DrawImage(UGint x, UGint y, 
							UGint nWidth, UGint nHeight, 
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc, 							
							UGint nDrawMode);
	virtual UGbool StretchImage(UGint x, UGint y, 
							UGint nWidth, UGint nHeight,
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc, 
							UGint nSrcWidth, UGint nSrcHeight, 
							UGint nDrawMode);
	virtual UGbool StretchImage(UGint x, UGint y, 
							UGint nWidth, UGint nHeight,
							UGint xSrc, UGint ySrc, 
							UGint nSrcWidth, UGint nSrcHeight, 
							UGImage::UGImageData& ImageData);

	//added by lugw 2007-04-28 ʵ��ͼƬ��ת
	//! \brief ������ת���դ��ͼƬ
	/**
	\param x��y           ��ͼ��ʼ��[in]
	\param nWidthRotate   ��ͼ���[in]
	\param nHeightRotate  ��ͼ�߶�[in]
	\param dAngle         ��ת�Ƕ�[in]
	\param pMemGraphics   ԭͼ����graphics[in]
	\param xSrc��ySrc     ԭͼ��ʼ��[in]
	\param nWidth         ԭͼ���[in]
	\param nHeight        ԭͼ�߶�[in]
	\param nDrawMode      ����ģʽ[in]
	\remarks ����ģʽ��ʱ��û���õ���������
	*/
	virtual UGbool RotateImage(UGint x, UGint y, 
							UGint nWidthRotate, UGint nHeightRotate,
							UGdouble dAngle,
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc, 
							UGint nWidth, UGint nHeight,
							UGint nDrawMode);

	// д�ַ���
	virtual UGbool TextOut(UGint x, UGint y, const UGString& str, UGTextStyle textStyle = UGTextStyle());	
	virtual UGint DrawText(const UGRect& rect, const UGString& str, UGint nFormat);
	
	// ��ȡ�ı�������Ϣ
	virtual UGint GetTextAlign() const;
	// �����ı�������Ϣ
	virtual UGint SetTextAlign(UGint nTextAlign);
	virtual UGSize GetTextExtent(const UGString& str);	

	//! ���ù⻬ģʽ
	virtual void SetLineSmoothingMode(UGbool bSmoothingMode);
	//! \brief ��ȡ������ê�㣨���Ͻǣ��ľ���
	virtual UGint GetBaselinetoAnchor();
public:
	static UGRect ConvertUGPoint2POINT(const UGPoint* pPoints, LPPOINT lpPoints, int nCount);	
	static void ConvertPOINT2UGPoint(const LPPOINT lpPoints, UGPoint* pPoints, int nCount);

protected:
	int DPtoLP_X(int x);
	int DPtoLP_Y(int y);
	int LPtoDP_X(int x);
	int LPtoDP_Y(int y);	
	void LPtoDP(LPPOINT pPoints, int nCount = 1);

	UGRect PreProcessPoints(const UGPoint* pPoints, int nCount);
	void ProcessBrushOrg(int x, int y);

	UGbool RegionWithBitmap(UGRgn *pClipRgn, UGbool bRect = TRUE);
	virtual UGint GetTextPath(const UGString& strText, const UGint x, const UGint y, UGFont* pFont, 
						   UGArray<UGPoint>* pPointArray, UGArray<UGbyte>* pTypes);
private:
	UGbool m_bNeedReleaseDC;

	LPPOINT m_lpPoints;	
	int m_nPntCountMax;



	//unsigned long m_nGdiplusToken;
	ULONG_PTR m_nGdiplusToken;

//friend class UGPSGraphics;
};

}

#endif // !defined(AFX_UGWGRAPHICS_H__DF5DB089_3725_4D76_963F_BF593DB7D870__INCLUDED_)
