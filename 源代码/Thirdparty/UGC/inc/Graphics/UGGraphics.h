
/*!
   **************************************************************************************
    \file     UGGraphics.h
   **************************************************************************************
    \author   ���������¹���
    \brief    ͼ����ʾ����                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#ifndef UGGRAPHICS_H
#define UGGRAPHICS_H

#include "UGImage.h"
#include "UGRgn.h"
#include "UGBrush.h"
#include "UGFont.h"
#include "UGPen.h"

namespace UGC
{

//! \brief ������ʾ����
class GRAPHICS_API UGGraphics 
{
public:	
	struct UGGraphicsData
	{
		UGuint nWidth;       //! \brief Graphics�Ŀ�
		UGuint nHeight;      //! \brief Graphics�ĸ�
		UGbyte btBitsPixel;  //! \brief ÿ�����ص�bit��������32��24
		UGint nType;	     //! \brief ��ʾ�������� 0:CDC, 1:hDC, 2:hPixmap, 3:hXWindow, 4:UGImage 5:PostScript
		void *pNative;       //! \brief ָ���豸�����ĵ�ָ��
		void *pReverse;      //! \brief �ڴ����飬ͨ������������ɫֵ
		UGGraphicsData()
		{
			nWidth = 1;
			nHeight = 1;
			btBitsPixel = 1;
			nType = 0;
			pNative = NULL;
			pReverse = NULL;
		}
	};
	
	//! \brief ��ʾ��������
	enum GraphicsType
	{
		GT_Windows = 1,    //! \brief windows���� 
		GT_Unix = 2,       //! \brief Linux\Unix����
		GT_Universal = 3,  //! \brief ��ƽ̨ͨ������
		GT_PostScript = 4  //! \brief ��ӡ����
	};

	//! \brief ��ʾ������������
	enum GraphicsDataType
	{
		GDT_WCDC = 0,       //! \brief windows cdc ����
		GDT_WhDC = 1,       //! \brief windows hdc ����
		GDT_XhPixmap = 2,   //! \brief linux  pixmap ����
		GDT_XhWindow = 3,   //! \brief linux xwindow ����
		GDT_UImage = 4,     //! \brief UGImage ����
		GDT_PostScript = 5  //! \brief PostScript ����
	};

	//! \brief ����ģʽ��ͬWindows�ϵ�BackMode
	enum BackMode
	{
		BackOpaque = 2,			//! \brief ��͸��
		BackTransparent = 1		//! \brief ͸��
	};	
	
	//! \brief �ı����뷽ʽ
	enum TextAlign
	{ 
		TopLeft = 0,			//! \brief ���ϽǶ���
		TopCenter = 1,			//! \brief ������ж���
		TopRight = 2,			//! \brief ���ϽǶ���
		BaselineLeft = 3,		//! \brief ��׼�������
		BaselineCenter = 4,		//! \brief ��׼�߾��ж���
		BaselineRight = 5,		//! \brief ��׼���Ҷ���
		BottomLeft = 6,			//! \brief ���½Ƕ���
		BottomCenter = 7,		//! \brief ���߾��ж���
		BottomRight = 8	,		//! \brief ���½Ƕ���
		CenterLeft = 9,			//! \brief ���ж���
		Center = 10,			//! \brief ���Ķ���
		CenterRight = 11		//! \brief ���ж���
	};	

	//! \brief ӳ��ģʽ
	enum MapMode
	{
		Text = 0,				//! \brief pixel	
		Lometric = 10,			//! \brief 0.1mm
		IsoTropicLometric = 11,	//! \brief 0.1mm, x������y����һ��
		Himetric = 100,			//! \brief 0.01mm		
		IsoTropicHimetric = 101,//! \brief 0.01mm, x������y����һ��
		PostScript  = 102		//! \brief Postscript
	};
    //! \brief ��ˢģʽ 
	enum BrushOrgMode
	{
		Absolute = 0,			// ����������ǰ������޹�
		Relative = 1			// ����������ǰ��������
	};
    //! \brief ��ͼǰ��ģʽ
	enum DrawMode
	{
		DM_BLACK =			1,   //! \brief  0       
		DM_NOTMERGEPEN =    2,   //! \brief DPon  
		DM_MASKNOTPEN =     3,   //! \brief DPna     
		DM_NOTCOPYPEN =     4,   //! \brief PN       
		DM_MASKPENNOT =     5,   //! \brief PDna     
		DM_NOT =            6,   //! \brief Dn       
		DM_XORPEN =         7,   //! \brief DPx      
		DM_NOTMASKPEN =     8,   //! \brief DPan     
		DM_MASKPEN =        9,   //! \brief DPa      
		DM_NOTXORPEN =      10,  //! \brief DPxn     
		DM_NOP =            11,  //! \brief D        
		DM_MERGENOTPEN =    12,  //! \brief DPno     
		DM_COPYPEN =        13,  //! \brief P        
		DM_MERGEPENNOT =    14,  //! \brief PDno     
		DM_MERGEPEN =       15,  //! \brief DPo      
		DM_WHITE =          16	 //! \brief  1       
	};

	//! \brief ����λͼ��ʽ
	enum ImageRop
	{
		IMAGE_SRCAND = 0x008800C6,   //! \brief boolean and
		IMAGE_SRCCOPY = 0x00CC0020,  //! \brief copy
		IMAGE_SRCINVERT = 0x00660046,//! \brief boolean xor
		IMAGE_SRCPAINT = 0x00EE0086  //! \brief boolean or
	};

protected:
	// 
	UGGraphics();
public:
	// destructor
	virtual ~UGGraphics();
	//! \brief ����һ�� pGraphics����
	//! \param pGraphics ���õ�pGraphics����
	//! \return ���ش����Ƿ�ɹ� 
	virtual UGbool CreateCompatibleGraphics(UGGraphics* pGraphics) = 0;
	//! \brief ɾ����ǰ����
	//! \return ɾ���Ƿ�ɹ�
	virtual UGbool DeleteGraphics() = 0;
	//! \brief ��ȡ��ǰͼƬ
	//! \return ���ص�ǰͼƬ
	virtual UGImage* GetCurrentImage() const;
	//! \brief ��ȡ��ǰ����
	//! \return ���ص�ǰ����
	virtual UGFont* GetCurrentFont() const;
	//! \brief ��ȡ��ǰ��ˢ
	//! \return ���ص�ǰ��ˢ
	virtual UGBrush* GetCurrentBrush() const;
	//! \brief ��ȡ��ǰ����
	//! \return ���ص�ǰ����
	virtual UGPen* GetCurrentPen() const;
    //! \breif �жϵ�ǰ�Ƿ�Ҫ��ӡ���ļ���
	//! \reutrn ���ص�ǰ�Ƿ���Դ�ӡ���ļ���
	virtual UGbool IsPrintToFile() const;
	//! \brief �����Ƿ��ӡ���ļ�����
	//! \param UGbool �Ƿ��ӡ���ļ���
	virtual void SetPrintToFile(UGbool bPrintToFile = TRUE);
    //! \breif �жϵ�ǰ�Ƿ��ڴ�ӡ
	//! \reutrn ���ص�ǰ�Ƿ��ڴ�ӡ
	virtual UGbool IsPrinting() const = 0;
	//! \breif ��ȡ���ԭ���ģʽ
	//! \reutrn ���ص�ǰ�����ԭ��ģʽ
	virtual UGint GetBrushOrgMode() const;
	//! \brief �������ԭ��ģʽ
	//! \param nBrushOrgMode Ҫ���õ�ԭ�����ģʽ
	//! \return ԭ����ԭ�����ģʽ 
	virtual UGint SetBrushOrgMode(UGint nBrushOrgMode);
	//! \brief ��ȡ���ԭ��
	//! \return �������ԭ��
	virtual UGPoint GetBrushOrg() const;
	//! \brief �������ԭ��
	//! \param point Ҫ���õ����ԭ��
	//! \return ����ԭ�������ԭ��
	virtual UGPoint SetBrushOrg(const UGPoint& point);
	//! \brief ѡ��ǰͼƬ
	//! \param pPen Ҫѡ���ͼƬ
	//! \return ����ԭ����ͼƬ
	virtual UGImage* SelectImage(UGImage *pImage) = 0;
	//! \brief ѡ��ǰ����
	//! \param pPen Ҫѡ�������
	//! \return ����ԭ��������
	virtual UGFont* SelectFont(UGFont *pFont) = 0;
	//! \brief ѡ��ǰ��ˢ
	//! \param pPen Ҫѡ��Ļ�ˢ
	//! \return ����ԭ���Ļ�ˢ
	virtual UGBrush* SelectBrush(UGBrush *pBrush) = 0;
	//! \brief ѡ��ǰ����
	//! \param pPen Ҫѡ��Ļ���
	//! \return ����ԭ���Ļ���
	virtual UGPen* SelectPen(UGPen *pPen) = 0;
	
	//! \brief ��ȡǰ����ɫ
	//! \return ����ǰ����ɫ
	virtual UGColor GetForeColor() const = 0;
	//! \brief ����ǰ����ɫ
	//! \param color Ҫ���õ�ǰ����ɫ
	//! \return ����ԭ����ǰ����ɫ
	virtual UGColor SetForeColor(UGColor color) = 0;	
	//! \brief ��ȡ������ɫ
	//! \return ���ر�����ɫ
	virtual UGColor GetBackColor() const = 0;
	//! \brief ���ñ�����ɫ
	//! \param color Ҫ���õı�����ɫ
	//! \return ����ԭ���ı�����ɫ
	virtual UGColor SetBackColor(UGColor color) = 0;

	//! \brief ��ȡ����ģʽ
	//! \return ���ر���ģʽ
	virtual UGint GetBackMode() const = 0;
	//! \breif ���ñ���ģʽ
	//! \param nBKMode Ҫ���õı���ģʽ
	//! \return ����ԭ���ı���ģʽ
	virtual UGint SetBackMode(UGint nBKMode) = 0;
    //! \brief ����ǰ��ģʽ
	//! \param nDrawMode Ҫ���õ�ģʽ
	//! \return ����ԭ����ǰ��ģʽ
	virtual UGint SetROP2(UGint nDrawMode) = 0;
	//! \brief ��ȡǰ��ģʽ
	//! \return ����ǰ��ģʽ
	virtual UGint GetROP2() = 0;	
     
	//! \brief ��ȡӳ��ģʽ
	//! \return ����ӳ��ģʽ
	virtual UGint GetMapMode() const = 0;
	//! \brief ����ӳ��ģʽ
	//! \param nMapMode Ҫ���õ�ӳ��ģʽ
	//! \return UGint ����ԭ����ӳ��ģʽ
	virtual UGint SetMapMode(UGint nMapMode) = 0;
	//! \brief ��ȡ���ڵ�ԭ������
	//! \return ����ԭʼ��ԭ������
	virtual UGPoint GetWindowOrg() const;
	//! \brief ���ô��ڵ�ԭ������
	//! \param point Ҫ���õ�����,
	//! \return ����ԭʼ��ԭ������
	virtual UGPoint SetWindowOrg(const UGPoint& point);
	//! \brief ���ô��ڵ�ԭ������
	//! \param x Ҫ���õ�x����,
	//! \param y Ҫ���õ�y����
	//! \return ����ԭʼ��ԭ������
	virtual UGPoint SetWindowOrg(UGint x, UGint y);
	//! \brief ʵ������ת�����߼�����
	//! \param pPoints Ҫת����������ָ��,����ת������߼�����
	//! \param nCount �������
	virtual void DPtoLP(UGPoint* pPoints, UGint nCount = 1) = 0;
	//! \brief ʵ������ת�����߼�����
	//! \param rect Ҫת���ľ���,����ת������߼�����ľ���
	virtual void DPtoLP(UGRect& rect) = 0;
	//! \brief ʵ������ת�����߼�����
	//! \param size Ҫת����ʵ������,����ת������߼�����
	virtual void DPtoLP(UGSize& size) = 0;
	//! \brief �߼�����ת����ʵ������
	//! \param pPoints Ҫת����������ָ��,����ת�����ʵ������
	//! \param nCount �������
	virtual void LPtoDP(UGPoint* pPoints, UGint nCount = 1) = 0;
	//! \brief �߼�����ת����ʵ������
	//! \param rect Ҫת���ľ���,����ת�����ʵ������ľ���
	virtual void LPtoDP(UGRect& rect) = 0;
	//! \brief �߼�����ת����ʵ������
	//! \param size Ҫת�����߼�����,����ת������߼�����
	virtual void LPtoDP(UGSize& size) = 0;
    //! \brief �߼�����ת����mm
	//! \param size Ҫת����ʵ������,����ת�����mm
	virtual void LPtoHIMETRIC(UGSize& size) = 0;
	//! \brief ʵ������ת����mm
	//! \param size Ҫת����ʵ������,����ת�����mm
	virtual void DPtoHIMETRIC(UGSize& size) = 0;
	//! \brief mmת�����߼�����
	//! \param size Ҫת����mm,����ת���������
	virtual void HIMETRICtoLP(UGSize& size) = 0;
	//! \brief mmת����ʵ������
	//! \param size Ҫת����mm,����ת���������
	virtual void HIMETRICtoDP(UGSize& size) = 0;
    //! \brief ѡ������ΪGraphics��ǰ����
	//! \param pRgn Ҫѡ�������
	//! \param nMode ��������, �������,�����
	//! \return ������һ������
	virtual UGRgn* SelectClipRgn(UGRgn* pRgn, UGint nMode) = 0;
    //! \brief ��ȡ��ǰ���ʵ�����
	//! \return ���ص�ǰ���ʵ�����
	virtual UGPoint GetCurrentPosition() const = 0;

	//! \brief ��ȡ����ֵ
    //! \param x ���ص�X����
	//! \param y ���ص�Y����
	//! \return �������ص���ɫ
	virtual UGColor GetPixel(UGint x,UGint y) = 0;
	//! \brief ��������ֵ
    //! \param x ���ص�X����
	//! \param y ���ص�Y����
	//! \param color �趨���ص���ɫ
	//! \return ����ԭʼ��ɫ
	virtual UGColor SetPixel(UGint x,UGint y, UGColor color) = 0;
	//! \brief �������ƶ���ָ������
    //! \param x ָ����X����
	//! \param y ָ����Y����
	//! \return ����ԭʼ���� 
	virtual UGPoint MoveTo(UGint x,UGint y) = 0;
	//! \brief ��һ��ֱ��
    //! \param x ֱ�ߵ��յ�X����
	//! \param y ֱ�ߵ��յ�Y����
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE 
	virtual UGbool LineTo(UGint x,UGint y) = 0;
	//! \brief �������ƶ���ָ������
    //! \param point ָ��������
	//! \return ����ԭʼ����
	virtual UGPoint MoveTo(UGPoint point) = 0;
	//! \brief ��һ��ֱ��
    //! \param point ֱ�ߵ��յ�����
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool LineTo(UGPoint point) = 0;
    //! \brief ��һ��ֱ��
    //! \param x1 ֱ�ߵ���ʼ���x����
	//! \param y1 ֱ�ߵ���ʼ���y����
	//! \param x2 ֱ�ߵ��յ��x����
	//! \param y2 ֱ�ߵ��յ��y����
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool Line(UGint x1,UGint y1,UGint x2,UGint y2) = 0;
	//! \brief ��һ��ֱ��
    //! \param point1 ֱ�ߵ���ʼ��
	//! \param point2 ֱ�ߵ��յ�
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool Line(UGPoint point1, UGPoint point2) = 0;
    //! \brief ��һ������
    //! \param pPoints ���ߵĵ���ָ��
	//! \param nCount �ж��ٸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool Polyline(const UGPoint* pPoints, UGint nCount) = 0;
	//! \brief ���������
    //! \param pPoints �������ߵĵ���ָ��
	//! \param pPntCount ÿ�����ߵĵ���
	//! \param nCount ���ߵĸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool PolyPolyline(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount) = 0;
    //! \brief ��һ�����������
    //! \param pPoints ����εĵ���ָ��
	//! \param nCount �ж��ٸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool Polygon(const UGPoint* pPoints, UGint nCount) = 0;
	//! \brief ��������������
    //! \param pPoints ����εĵ���ָ��
	//! \param pPntCount ÿ������εĵ���
	//! \param nCount ����εĸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool PolyPolygon(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount) = 0;

	//! \brief ������
	//! \param x1 ���ε����Ͻǵ�X���� 
    //! \param y1 ���ε����Ͻǵ�Y���� 
	//! \param x2 ���ε����½ǵ�X����
	//! \param y2 ���ε����½ǵ�Y����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool Rectangle(UGint x1, UGint y1, UGint x2, UGint y2) = 0;
	//! \brief ������
	//! \param rect ��Ҫ���Ƶľ��� 
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool Rectangle(const UGRect& rect) = 0;

	//! \brief ����Բ
	//! \param x1 �����ľ��ε����Ͻǵ�X���� 
    //! \param y1 �����ľ��ε����Ͻǵ�Y���� 
	//! \param x2 �����ľ��ε����½ǵ�X����
	//! \param y2 �����ľ��ε����½ǵ�Y����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool Ellipse(UGint x1, UGint y1, UGint x2, UGint y2) = 0;
	//! \brief ����Բ
	//! \param rect �����ľ��� 
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool Ellipse(const UGRect& rect) = 0;

	//! \brief    ������
	//! \param x1 �����ľ��ε����Ͻǵ�X���� 
    //! \param y1 �����ľ��ε����Ͻǵ�Y���� 
	//! \param x2 �����ľ��ε����½ǵ�X����
	//! \param y2 �����ľ��ε����½ǵ�Y����
	//! \param x3 ������ʼ���ߵ� 
	//! \param y3 ���߽������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool Arc(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) = 0;
	//! \brief    ������
	//! \param pntStart ������ʼ���ߵ� 
	//! \param pntEnd ���߽������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool Arc(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) = 0; 

	//! \brief    ������
	//! \param x1 �����ľ��ε����Ͻǵ�X���� 
    //! \param y1 �����ľ��ε����Ͻǵ�Y���� 
	//! \param x2 �����ľ��ε����½ǵ�X����
	//! \param y2 �����ľ��ε����½ǵ�Y����
	//! \param x3 ������ʼ���ߵ� 
	//! \param y3 ���ν������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool Chord(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) = 0;
	//! \brief    ������
	//! \param pntStart ������ʼ���ߵ� 
	//! \param pntEnd ���ν������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool Chord(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) = 0; 
	//! \brief    ������
	//! \param x1 �����ľ��ε����Ͻǵ�X���� 
    //! \param y1 �����ľ��ε����Ͻǵ�Y���� 
	//! \param x2 �����ľ��ε����½ǵ�X����
	//! \param y2 �����ľ��ε����½ǵ�Y����
	//! \param x3 ������ʼ�� 
	//! \param y3 ���ν�����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool Pie(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) = 0;
    //! \brief    ������
	//! \param pntStart ������ʼ���ߵ� 
	//! \param pntEnd ���ν������ߵ�
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool Pie(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) = 0; 
	
	//! \brief ��Բ�Ǿ���
	//! \param x1 �����ľ��ε����Ͻǵ�X���� 
    //! \param y1 �����ľ��ε����Ͻǵ�Y���� 
	//! \param x2 �����ľ��ε����½ǵ�X����
	//! \param y2 �����ľ��ε����½ǵ�Y����
	//! \param x3 Բ�Ǿ���X����
	//! \param y3 Բ�Ǿ���Y����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool RoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3) = 0;
	//! \brief    ��Բ�Ǿ���
	//! \param rect �����ľ��� 
	//! \param point Բ�Ǿ���XY����
	//! \return ���ػ�ͼ�Ƿ�ɹ�
	virtual UGbool RoundRect(const UGRect& rect, UGPoint point) = 0; 

	//! \brief ��ͼ��
	//! \param x Ŀ��Graphics�ľ��ε����Ͻǵ�x���� 
    //! \param y Ŀ��Graphics�ľ��ε����Ͻǵ�y���� 
	//! \param nWidth  Ŀ��Graphics�ľ��εĿ��
	//! \param nHeight Ŀ��Graphics�ľ��εĸ߶�
	//! \param pMemGraphics ԴGraphics
	//! \param xSrc ԴGraphics�ľ��ε����Ͻǵ�x���� 
	//! \param ySrc ԴGraphics�ľ��ε����Ͻǵ�y����
	//! \param nDrawMode ����λͼ��ʽ
	//! \return ���ػ����Ƿ�ɹ�
	virtual UGbool DrawImage(UGint x, UGint y,
							UGint nWidth, UGint nHeight,  
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc, 							
							UGint nDrawMode) = 0;
	//! \brief ��չͼ��
	//! \param x Ŀ��Graphics�ľ��ε����Ͻǵ�x���� 
    //! \param y Ŀ��Graphics�ľ��ε����Ͻǵ�y���� 
	//! \param nWidth  Ŀ��Graphics�ľ��εĿ��
	//! \param nHeight Ŀ��Graphics�ľ��εĸ߶�
	//! \param pMemGraphics ԴGraphics
	//! \param xSrc ԴGraphics�ľ��ε����Ͻǵ�x���� 
	//! \param ySrc ԴGraphics�ľ��ε����Ͻǵ�y����
	//! \param nSrcWidth ԴGraphic�ľ��εĿ��
	//! \param nSrcHeight ԴGraphic�ľ��εĸ߶�
	//! \param nDrawMode ����λͼ��ʽ
	//! \return ���ػ����Ƿ�ɹ�
	virtual UGbool StretchImage(UGint x, UGint y, 
							UGint nWidth, UGint nHeight,
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc, 
							UGint nSrcWidth, UGint nSrcHeight, 
							UGint nDrawMode) = 0;
	//! \brief ��չͼ��
	//! \param x Ŀ��Graphics�ľ��ε����Ͻǵ�x���� 
    //! \param y Ŀ��Graphics�ľ��ε����Ͻǵ�y���� 
	//! \param nWidth  Ŀ��Graphics�ľ��εĿ��
	//! \param nHeight Ŀ��Graphics�ľ��εĸ߶�
	//! \param xSrc ԴGraphics�ľ��ε����Ͻǵ�x���� 
	//! \param ySrc ԴGraphics�ľ��ε����Ͻǵ�y����
	//! \param nSrcWidth ԴGraphic�ľ��εĿ��
	//! \param nSrcHeight ԴGraphic�ľ��εĸ߶�
	//! \param ImageData Դͼ�������
	//! \return ���ػ����Ƿ�ɹ�
	virtual UGbool StretchImage(UGint x, UGint y, 
							UGint nWidth, UGint nHeight,
							UGint xSrc, UGint ySrc, 
							UGint nSrcWidth, UGint nSrcHeight, 
							UGImage::UGImageData& ImageData) = 0;
	//! \brief ����תͼ��
	//! \param x Ŀ��Graphics�ľ��ε����Ͻǵ�x���� 
    //! \param y Ŀ��Graphics�ľ��ε����Ͻǵ�y���� 
	//! \param nWidthRotate  Ŀ��Graphics�ľ��εĿ��
	//! \param nHeightRotate Ŀ��Graphics�ľ��εĸ߶�
	//! \param dAngle   ��ת�ĽǶ�
	//! \param pMemGraphics ԴGraphics
	//! \param xSrc ԴGraphics�ľ��ε����Ͻǵ�x���� 
	//! \param ySrc ԴGraphics�ľ��ε����Ͻǵ�y����
	//! \param nWidth ԴGraphic�ľ��εĿ��
	//! \param nHeight ԴGraphic�ľ��εĸ߶�
	//! \param nDrawMode ����λͼ��ʽ
	//! \return ���ػ����Ƿ�ɹ�
	virtual UGbool RotateImage(UGint x, UGint y, 
							UGint nWidthRotate, UGint nHeightRotate,
							UGdouble dAngle,
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc,
							UGint nWidth,UGint nHeight,
							UGint nDrawMode) = 0;

	//! \brief ��д�ַ���
	//! \param x �ַ����Ķ���λ�õ�x����
	//! \param y �ַ����Ķ���λ�õ�y����
	//! \param str ָ���ַ�����ָ��
	//! \param textStyle �ı�����ʽ
	//! \return ������д�Ƿ�ɹ�
	virtual UGbool TextOut(UGint x, UGint y, const UGString& str, UGTextStyle textStyle = UGTextStyle()) = 0;	
	//! \brief ��д�ַ���
	//! \param rect �ı��������ľ���
	//! \param str ����Ҫ��д���ַ���
	//! \param nFormat
	//! \return �����ı��ĸ߶�
	virtual UGint DrawText(const UGRect& rect, const UGString& str, UGint nFormat) = 0;
	
	//! \brief ��ȡ�ı����뷽ʽ
    //! \return �ı����뷽ʽ
	virtual UGint GetTextAlign() const  = 0;
	//! \brief �����ı����뷽ʽ
    //! \param nTextAlign ���뷽ʽ
	virtual UGint SetTextAlign(UGint nTextAlign) = 0;
	//! \brief ��ȡ�ı��ַ�������ռ��С
	//! \return������ռ��С
	virtual UGSize GetTextExtent(const UGString& str) = 0;
	
	//! \brief ��ȡʵ�ʶ���
	//! \param data ����ʵ�ʶ���
	virtual void GetGraphicsData(UGGraphicsData &data) const;
	//! \brief ����ʵ�ʶ���
	//! \param data ʵ�ʶ�������
	virtual void SetGraphicsData(const UGGraphicsData &data);
    //! \brief  ��ȡ��ʾ��������
	//! \return ��ʾ��������
	virtual UGint GetGraphicsType();
	
	//���ߺ��ı����������ֿ�����SFC����һ��
	//virtual UGbool IsSmoothingMode() const;
	//virtual void SetSmoothingMode(UGbool bSmoothingMode);
	//! \brief �Ƿ�⻬ģʽ
	//! \return �⻬ģʽ
	virtual UGbool IsLineSmoothingMode() const;
	//! \brief ���ù⻬ģʽ
	//! \param bSmoothingMode �⻬ģʽ
	virtual void SetLineSmoothingMode(UGbool bSmoothingMode);
	//! \brief �Ƿ�⻬ģʽ
	//! \return �⻬ģʽ
	virtual UGbool IsTextSmoothingMode() const;
	//! \brief ���ù⻬ģʽ
	//! \param bSmoothingMode �⻬ģʽ
	virtual void SetTextSmoothingMode(UGbool bSmoothingMode);
	//! \biref����psgraphics��ʾ����
	virtual void SetCoordRatio(UGfloat dRatioX,UGfloat dRatioY);
	virtual void GetCoordRatio(UGfloat& dRatioX,UGfloat& dRatioY);
	//! \brief ��ȡ������ê�㣨���Ͻǣ��ľ���
	//! \return ������ê�㣨���Ͻǣ��ľ���
	virtual UGint GetBaselinetoAnchor();
	//! \brief ����/���������Ƿ�תΪʸ��
	void SetTextConvertToVector(UGbool bTextConvertToVector);
	UGbool IsTextConvertToVector();
	//! \brief ���βü� for PSGraphics
	virtual UGbool RectClip(UGdouble left, UGdouble top, UGdouble right, UGdouble bottom);
	virtual UGbool RectClip(const UGRect& rect);
protected:		
	UGPoint m_pntCurPos;
	UGint m_nMapMode;
	UGPoint m_pntWindowOrg;
	UGint m_nBrushOrgMode;
	UGPoint m_pntBrushOrg;	
	UGbool m_bPrintToFile;

	UGImage* m_pImage;
	UGFont* m_pFont;
	UGBrush* m_pBrush;
	UGPen* m_pPen;
	UGRgn* m_pRgn;
	UGGraphicsData m_Data;	// �������ʵ���豸

	UGint m_nGraphicsType;
	UGbool m_bLineSmoothingMode;
	UGbool m_bTextSmoothingMode;

		// ����/�߼���λ��
	double m_dCoorRatioX;
	double m_dCoorRatioY;
	UGbool m_bTextToVector;	//�����Ƿ�תΪʸ��
	virtual UGint GetTextPath(const UGString& strText, const UGint x, const UGint y, UGFont* pFont, 
						   UGArray<UGPoint>* pPointArray, UGArray<UGbyte>* pTypes); 
	friend class UGPSGraphics;
};

}

#endif
