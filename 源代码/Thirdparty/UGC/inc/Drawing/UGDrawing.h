// UGDrawing.h: interface for the UGDrawing class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDrawing.h
   **************************************************************************************
    \author   ���������¹���
    \brief    ��ʾ��                                                                 
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGDRAWING_H__AAC47E2E_B5B6_476C_9462_FBF34F02DFF5__INCLUDED_)
#define AFX_UGDRAWING_H__AAC47E2E_B5B6_476C_9462_FBF34F02DFF5__INCLUDED_

#include "UGDrawCache.h"
#include "UGDrawParamaters.h"
#include "UGDrawMaker.h"
#include "Engine/UGDataSource.h"
#include "Base/ugplatform.h"
#include "Base/UGProgress.h"
namespace UGC {	

typedef void (UGSTDCALL *DRAWPAINTPROC)(UGGraphics* pGraphics, UGlong pPaintWnd);

// by zengzm 2007-3-26 ��__stdcall���嵽ugplatform��
typedef void (UGSTDCALL *DRAWCALLBACKPROC)(UGint nPercent, UGbool &bCancel, UGlong pWnd);
//#ifdef WIN32
//typedef void (__stdcall *DRAWCALLBACKPROC)(UGint nPercent, UGbool &bCancel, UGuint pWnd);
//#else
//typedef void (*DRAWCALLBACKPROC)(UGint nPercent, UGbool &bCancel, UGuint pWnd);
//#endif
//added by xielin 2007-04-30 
//! \brief �ص�������������չ�������
//! \param 		pGraphics		��ǰ���Ƶ�Graphics�������ڸ�Graphics�ϻ��ƶ���
//! \param 		pGeometry		��չ����
//! \param 		pWnd			ʵ�ָûص����������ָ��
typedef void (UGSTDCALL *DRAWCUSTOMGEOMETRYCALLBACKPROC)(UGGraphics* pGraphics,UGGeometry* pGeometry,UGlong pWnd);

class UGGeoPoint;
class UGGeoLine;
class UGGeoRegion;
class UGGeoText;
class UGGeoArc;
class UGGeoBSpline;
class UGGeoCardinal;
class UGGeoCircle;
class UGGeoCompound;
class UGGeoDonut;	
class UGGeoEllipse;
class UGGeoEllipticArc;
class UGGeoLineM;	
class UGGeoLwpline;
class UGGeoMultiPoint;	
class UGGeoPath;
class UGGeoPie;
class UGGeoRect;
class UGGeoRectRound;
class UGGeoEquilateral;
class UGGeoCurve;
class UGTINBlock;

class DRAWING_API UGDrawing  
{
public:
	UGDrawing();
	virtual ~UGDrawing();

public:
	//! \brief ���Ƽ��ζ���
	//! \param pGeometry ���ζ���
	//! \return �����Ƿ�ɹ�
	UGbool Draw(UGGeometry* pGeometry);
	//! \brief �����ı�
	//! \param UGGeoText �ı�����
	//! \param bThemeStyle �Ƿ��Ǳ�ǩ��ʽ
	//! \param bSingleTextStyle �Ƿ�͵�ǰͼ����ͬһ���ı���ʽ
	//! \return �����Ƿ�ɹ�
	UGbool Draw(UGGeoText* pGeoText, UGbool bThemeStyle, UGbool bSingleTextStyle = true);
    //! \brief �������ݼ�
	//! \param pDataset �ı�����
	//! \param nTransparentRate ͸����
	//! \param UGProgress ��������
	//! \return �����Ƿ�ɹ�
	UGbool Draw(UGDataset* pDataset, UGint nTransparentRate = 0,UGProgress* pProgress = NULL);
	//! \brief ���Ƶ�
	//! \param point Ҫ���Ƶĵ�
	//! \return �����Ƿ�ɹ�
	UGbool Point(const UGPoint& point);
	//! \brief ���Ƶ�
	//! \param x Ҫ���Ƶĵ�x����
    //! \param y Ҫ���Ƶĵ�y����
	//! \return �����Ƿ�ɹ�
	UGbool Point(UGint x, UGint y);
	 //! \brief ��һ������
    //! \param pPoints ���ߵĵ���ָ��
	//! \param nCount �ж��ٸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	UGbool Polyline(const UGPoint* pPoints, UGint nCount);
	//! \brief ���������
    //! \param pPoints �������ߵĵ���ָ��
	//! \param pPntCount ÿ�����ߵĵ���
	//! \param nCount ���ߵĸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	UGbool PolyPolyline(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount);
   //! \brief ��һ�����������
    //! \param pPoints ����εĵ���ָ��
	//! \param nCount �ж��ٸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	UGbool Polygon(const UGPoint* pPoints, UGint nCount);
	//! \brief ��������������
    //! \param pPoints ����εĵ���ָ��
	//! \param pPntCount ÿ������εĵ���
	//! \param nCount ����εĸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	UGbool PolyPolygon(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount);

	//! \brief ������
	//! \param x1 ���ε����Ͻǵ�X���� 
    //! \param y1 ���ε����Ͻǵ�Y���� 
	//! \param x2 ���ε����½ǵ�X����
	//! \param y2 ���ε����½ǵ�Y����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Rectangle(UGint x1, UGint y1, UGint x2, UGint y2);
	//! \brief ������
	//! \param rect ��Ҫ���Ƶľ��� 
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Rectangle(const UGRect& rect);
	//! \brief ����Բ
	//! \param x1 ���Ƶľ��ε����Ͻǵ�X���� 
    //! \param y1 ���Ƶľ��ε����Ͻǵ�Y���� 
	//! \param x2 ���Ƶľ��ε����½ǵ�X����
	//! \param y2 ���Ƶľ��ε����½ǵ�Y����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Ellipse(UGint x1, UGint y1, UGint x2, UGint y2);
	//! \brief ����Բ
	//! \param rect ���Ƶľ��� 
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Ellipse(const UGRect& rect);

	//! \brief    ������
	//! \param x1 ���Ƶľ��ε����Ͻǵ�X���� 
    //! \param y1 ���Ƶľ��ε����Ͻǵ�Y���� 
	//! \param x2 ���Ƶľ��ε����½ǵ�X����
	//! \param y2 ���Ƶľ��ε����½ǵ�Y����
	//! \param x3 ������ʼ���ߵ� 
	//! \param y3 ���߽������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Arc(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4);
	//! \brief    ������
	//! \param pntStart ������ʼ���ߵ� 
	//! \param pntEnd ���߽������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Arc(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd);
	//! \brief    ������
	//! \param x1 ���Ƶľ��ε����Ͻǵ�X���� 
    //! \param y1 ���Ƶľ��ε����Ͻǵ�Y���� 
	//! \param x2 ���Ƶľ��ε����½ǵ�X����
	//! \param y2 ���Ƶľ��ε����½ǵ�Y����
	//! \param x3 ������ʼ���ߵ� 
	//! \param y3 ���ν������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Chord(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4);
//! \brief    ������
	//! \param pntStart ������ʼ���ߵ� 
	//! \param pntEnd ���ν������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Chord(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd);
	//! \brief    ������
	//! \param x1 ���Ƶľ��ε����Ͻǵ�X���� 
    //! \param y1 ���Ƶľ��ε����Ͻǵ�Y���� 
	//! \param x2 ���Ƶľ��ε����½ǵ�X����
	//! \param y2 ���Ƶľ��ε����½ǵ�Y����
	//! \param x3 ������ʼ�� 
	//! \param y3 ���ν�����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Pie(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4);
  //! \brief    ������
	//! \param pntStart ������ʼ���ߵ� 
	//! \param pntEnd ���ν������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool Pie(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd);
	//! \brief ��Բ�Ǿ���
	//! \param x1 ���Ƶľ��ε����Ͻǵ�X���� 
    //! \param y1 ���Ƶľ��ε����Ͻǵ�Y���� 
	//! \param x2 ���Ƶľ��ε����½ǵ�X����
	//! \param y2 ���Ƶľ��ε����½ǵ�Y����
	//! \param x3 Բ�Ǿ���X����
	//! \param y3 Բ�Ǿ���Y����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool RoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3);
	//! \brief    ��Բ�Ǿ���
	//! \param rect ���Ƶľ��� 
	//! \param point Բ�Ǿ���XY����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	UGbool RoundRect(const UGRect& rect, UGPoint point); 
	//! \brief ��һ���ı�����
	//! \param UGPoint �ı�����
	//! \param str �ı�
	//! \param style �ı����
	//! \param bThemeStyle �Ƿ��Ǳ�ǩ��ʽ
	//! \param bSingleTextStyle �Ƿ�͵�ǰͼ����ͬһ���ı���ʽ
	//! \return �����Ƿ�ɹ�
	UGbool Text(const UGPoint &pnt, const UGString &str, const UGTextStyle &style, UGbool bThemeStyle = FALSE,UGbool bSingleTextStyle = true);
	//! \brief ��ȡ�ı����
	//! \return �ı���� 
	UGTextStyle GetTextStyle() const;
    //! \brief ���ζ�����
	//! \return ���ζ����� 
	UGStyle GetStyle() const;
	//! \brief ���õ�ǰ��ʾ����
	//! \param style ���ü����������
	//! \param nDimesion ���϶����ά��
	//! \return ��ǰ����ʾ�ߴ�
	UGbool Prepare(const UGStyle& style, const UGint nDimesion);
	//! \brief ���õ�ǰ��ʾ����
	//! \param style ���ü����������
	//! \param nDimesion ���϶����ά��
	//! \�����Ƿ�ɹ� ��ǰ����ʾ�ߴ�
	UGbool Prepare(const UGTextStyle& style, UGbool bThemeStyle = FALSE);
	//! \brief �ͷŵ�ǰ����
	void Release();
	//! \brief ��ȡGraphics����
	//! \return ����Graphics����
	UGGraphics* GetGraphics() const;
	//! \brief ����Graphics����
	//! \param pGraphics Ҫ���õ�Graphics���� 
	//! \return ���ؾɵ�Graphics����
	UGGraphics* SetGraphics(UGGraphics* pGraphics);
	//! \brief ���㿪ʼ���Ƶ�ʱ��
	//! \param pGraphics ʹ�õ�Graphics����
	void BeginCalculateTime(UGGraphics* pGraphics);
	//! \brief ����������Ƶ�ʱ��
	void EndCalculateTime();
	//! \brief �ж��Ƿ�ʼ����
	//! \return �Ƿ�ʼ����
	UGbool IsBeginCalculateTime();
	//! \brief ˢ��ͼ��
	void OvertimeRefresh();
	//! \brief  ��ʾ�жϺ���ʾˢ����Ϣ
	UGbool DrawCallBack();
	//! \brief ��Graphicsͼ����ƶ���
	//! \param  Graphicsͼ����ƶ���
	void OnPaint(UGGraphics* pGraphics);
	//! \brief ������չ������ƺ���
	//! \param pDrawCustomGeometryFunc ������չ����ĺ���ָ��
	//! \param pWnd ����ָ���Hand 
	void SetDrawCallBackFunc(DRAWCALLBACKPROC pDrawCallBackFunc, UGlong pWnd);
    //! \brief ������չ������ƺ���
	//! \param pDrawCustomGeometryFunc ������չ����ĺ���ָ��
	//! \param pWnd ����ָ���Hand 
	void SetDrawPaintFunc(DRAWPAINTPROC pDrawPaintFunc, UGlong pPaintWnd);
	//added by xielin 2007-04-30 
    //! \brief ������չ������ƺ���
	//! \param pDrawCustomGeometryFunc ������չ����ĺ���ָ��
	//! \param pWnd ����ָ���Hand 
	void SetDrawCustomGeometryFunc(DRAWCUSTOMGEOMETRYCALLBACKPROC pDrawCustomGeometryFunc,
		UGlong pWnd);
		
	// �����ı�ʹ��  //modified by dongfei 2007-04-11 ����������� һ����������룬һ�����Ƿ�ǿ�м�����ı���Χ
	//! \brief �ж��Ƿ�ѹ��ͼ���ı�����
	//! \param pText Ҫ�жϵ��ı��Ķ���
	//! \param bThemeStyle �Ƿ�Ϊ��ǩר��ͼ
	//! \param szBuffer ������� 
	//! \param bSingleTextStyle �Ƿ�͵�ǰ��һ�����ı���ʽ 
	//! \param bSelfOverlap �Ƿ���ѹ�� 
	//! \param bOverlapBounds �Ƿ���ͼ��߽��ཻ 
	//! \return �Ƿ�ѹ���ı����� 

	UGbool	IsOverlapText(UGGeoText* pText, UGbool bThemeStyle = false,UGSize2D szBuffer = UGSize2D(-1.0,-1.0), 
		UGbool bSingleTextStyle = true, UGbool bSelfOverlap = false,UGbool bOverlapBounds = false);
    //! \brief �ж��Ƿ�ѹ��ͼ���ı�����
	//! \param UGGeoCompound Ҫ�жϵķ��϶���
	//! \param bThemeStyle �Ƿ�Ϊ��ǩר��ͼ
	//! \param bOverlapBounds �Ƿ���ͼ��߽��ཻ 
	//! \return �Ƿ�ѹ���ı����� 

	UGbool	IsOverlapText(UGGeoCompound* pGeoCompound, UGbool bThemeStyle = false,UGbool bOverlapBounds = false);
    //! \brief �жϾ��ζ����Ƿ�ѹ��ͼ���ı�����
	//! \param pRect Ҫ�жϵľ��ζ���
	//! \param szBuffer ����������
	//! \return �Ƿ�ѹ���ı����� 
	UGbool	IsOverlapText(UGRect* pRect,UGSize szBuffer = UGSize(-1,-1));
	//! \brief ���һ���ı�������ĸ��߽ǵ����Ƶ���Ļ���ı�����m_arrTextVertexs��
	//! \param pText Ҫ��ӵ��ı�����
    //! \param bThemeStyle �Ƿ�Ϊ��ǩר��ͼ
	//! \param szBuffer ����������
	void	AddTextVertexs(UGGeoText* pText, UGbool bThemeStyle = false,UGSize2D szBuffer = UGSize2D(-1.0,-1.0));
	//�������IsOverlapText��AddTextVertexs�����������ı����ĸ��߽ǳ������ ���ֻ�����Щ�鷳 �Ժ�����
	//UGbool  GetSubTextVertexs(UGSubText* pSubText,const UGPoint2D& pntAnchor, UGArray<UGPoint>& pnts);
	//! \brief �Ƴ���Ļ���ı����������
	void	RemoveAllTextVertexs();
	//! \brief �ָ�϶���
	//! \param  pGeoCompound Ҫ�ָ�ĸ��϶���
	//! \param  arrGeometry  �ָ������� 
	//! \return �ָ��Ƿ�ɹ�
	static UGbool SplitGeoCompound(UGGeoCompound *pGeoCompound, UGArray<UGGeometry*>& arrGeometry);
	//! \brief �ж�ĳ���Ƿ����ı�������
	//! \param pGeoText �ı�����
	//! \param pntHitTest Ҫ�жϵĵ�
	//! \return �Ƿ����ı�������
	static UGbool HitTestGeoText(UGGeoText* pGeoText, const UGPoint2D& pntHitTest, UGDrawParamaters *pDrawParam);
	//! \brief �ж�ĳ���Ƿ��ڼ��ε���
	//! \param pGeoText ���ε�
	//! \param style ���ζ�����
	//! \param pntHitTest Ҫ�жϵĵ�
	//! \return �Ƿ��ڼ��ε�
	static UGbool HitTestGeoPoint(UGGeoPoint* pGeoPoint, const UGStyle& style, const UGPoint2D& pntHitTest, UGdouble dTolerance, UGDrawing *pDrawing);
	//! \brief ��õ��ı������С
	//! \param pGraphics ���Ƶ�Graphics����
	//! \param strText �ı�����
	//! \return �ı�����Ĵ�С
	static UGSize GetTextSize(UGGraphics *pGraphics, const UGString &strText);
	//! \brief ���ÿ�е��ı�����
	//! \param strText �жϵ��ı�
	//! \param strRows �ָ����ı�
	//! \return �ı��Ĵ�С��UGSize.cx �����е�����ı��� UGSize.cy �ı�����
	static UGSize GetRowStrings(const UGString &strText, UGArray<UGString> &strRows);
	//! \brief �����ı����߼��߽�
	//! \param pGraphics ���Ƶ�Graphics����
	//! \param pntAnchor �ı��Ļ���
	//! \param strText  ������ı�
	//! \param btAlign �ı��Ķ��뷽ʽ
	//! \return �ı����߼��߽�
	static UGRect CalcTextLogBounds(UGGraphics *pGraphics, const UGPoint& pntAnchor, const UGString& strText, UGbyte btAlign);
	//! \brief ����ı�������
	//! \param strText �ı�����
	//! \return �ı�����
	static UGint CalcTextRowCount(const UGString &strText);

protected:
	UGbool DrawDataset(UGDatasetVector* pDatasetV,UGProgress* pProgress = NULL);
	UGbool DrawDataset(UGDatasetRaster* pDatasetR, UGint nTransparentRate = 0,UGProgress* pProgress = NULL);
	UGbool DrawGeometry(UGGeoPoint* pGeo);
	UGbool DrawGeometry(UGGeoLine* pGeo);
	UGbool DrawGeometry(UGGeoRegion* pGeo);
	UGbool DrawGeometry(UGGeoText* pGeo, UGbool bThemeStyle = false, UGbool bSingleTextStyle = true);	
	UGbool DrawGeometry(UGGeoArc* pGeo);
	UGbool DrawGeometry(UGGeoBSpline* pGeo);
	UGbool DrawGeometry(UGGeoCardinal* pGeo);
	UGbool DrawGeometry(UGGeoCurve* pGeo);
	UGbool DrawGeometry(UGGeoCircle* pGeo);
	UGbool DrawGeometry(UGGeoCompound* pGeo);
	//UGbool DrawGeometry(UGGeoDonut* pGeo);	
	UGbool DrawGeometry(UGGeoEllipse* pGeo);
	UGbool DrawGeometry(UGGeoEllipticArc* pGeo);
	UGbool DrawGeometry(UGGeoLineM* pGeo);	
	UGbool DrawGeometry(UGGeoLwpline* pGeo);
	UGbool DrawGeometry(UGGeoMultiPoint* pGeo);	
	UGbool DrawGeometry(UGGeoPath* pGeo);
	UGbool DrawGeometry(UGGeoPie* pGeo);
	UGbool DrawGeometry(UGGeoRect* pGeo);
	UGbool DrawGeometry(UGGeoRectRound* pGeo);
	UGbool DrawGeometry(UGGeoEquilateral* pGeo);
	UGbool DrawGeometry(UGTINBlock* pGeo);

	UGbool GetArcPoints(UGRect &rect, UGdouble dAngleStart, UGdouble dAngleEnd, 
		UGArray<UGPoint> &arr);

	///////////////////////////////////////////////////////
	// ��һ���Ա�ǻ���դ�����ݼ�ʱ��Ҫ��
	UGbool PaintRaster(UGint nTransparentRate = 0,UGProgress* pProgress = NULL);
	void PaintImgBegin();
	UGbool PaintImgBlock(UGImgBlock* pIBlock, UGint nTransparentRate);
	UGColor ImageIndexToColor(UGint nColor);
	///////////////////////////////////////////////////////

	// Ϊ�˹����ı�ʹ��
	UGbool IsOverlapRects(const UGPoint* pPntObliqueRect, const UGRect& rect)const;
	UGint IsPointInRect(const UGPoint& Pnt, const UGRect& rect)const;
	UGint IsPointInObliqueRect(const UGPoint& pnt, const UGPoint* pPntObliqueRect)const;

	//! \brief ��ȡ�ı����Ͻ����� added by dongfei 2007-03-21
	UGbool GetTextLeftTop(UGPoint & pntAnchor1, const UGString & strText, const UGTextStyle & style);
	
public:
	UGDrawParamaters m_DrawParam;
	UGDrawCache m_DrawCache;
	UGDrawMaker m_DrawMaker;

protected:
	DRAWCALLBACKPROC m_pDrawCallBackFunc;
	UGlong m_pWnd;
	DRAWPAINTPROC m_pDrawPaintFunc;
public:
	UGlong m_pPaintWnd;
protected:
	//added by xielin 2007-04-30��չ������ƻص�����
	DRAWCUSTOMGEOMETRYCALLBACKPROC m_pDrawCustomGeometryFunc;
	UGlong m_pDrawCustomGeometryWnd;

protected:
	UGStyle m_Style;
	UGTextStyle m_TextStyle;
	UGGraphics* m_pGraphics;

	UGGraphics* m_pRefreshGraphics;
	UGbool m_bBeginCalculateTime;
	UGbool m_bBeginDrawImg;
	clock_t m_clockBegin;
	UGint m_nCalculateNum;

	///////////////////////////////////////////////////////
	//��һ���Ա�ǻ���դ�����ݼ�ʱ��Ҫ��
	UGRect m_rcImgPaint;
	UGSize2D m_szImgViewOffset;
	UGSize2D m_szImgViewRatio;
	UGImage::UGImageData m_ImgInfo;

	UGDatasetRaster *m_pDTRaster;
	UGImgBlock *m_pDemBlock;
	///////////////////////////////////////////////////////
	//��ʾ����Ļ�ϵ����ֵ���Ļ��������
	UGArray<UGPoint> m_arrTextVertexs;	

public:

#if PACKAGE_TYPE==PACKAGE_UGC
	//!ר��ͼ��ʾģʽ
	//0, theme none; 1, theme unique; 2, theme range;
	UGint m_nDrawMode;
	
	//!�ֶ�ר��ͼ��KEYS
	UGArray <UGdouble> *m_pAryDoubleKeys;
	
	//!��ֵר��ͼ��KEYS,Ҳ��ugdouble���洢�ɡ�
	UGArray <UGdouble> *m_pAryIntKeys;
	
	//!ר��ͼ���
	UGColorset *m_pStyles;
	
	//!ר��ͼĬ�Ϸ��
	UGColor m_DefaultStyle;
#endif // end declare ugc sdk

	//������Ҫ���̳߳�ͼ��դ�����ݼ��Ĳ��ֱ�����Ϣ���浽Drawing����
	UGColor m_NoDataStyle;
	UGColor m_BackColor;
	UGbyte m_btBackColorTolerance;
	UGchar m_btBrightness;
	UGchar m_btContrast;
	UGColorTable m_ColorsetTable;

	UGColorTable* GetColorsetTable();

};

}

#endif // !defined(AFX_UGDRAWING_H__AAC47E2E_B5B6_476C_9462_FBF34F02DFF5__INCLUDED_)
