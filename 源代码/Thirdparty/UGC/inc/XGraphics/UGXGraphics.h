// UGXGraphics.h: interface for the UGXGraphics class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGXGRAPHICS_H__0B8ABC21_18A2_4B88_8E1E_15D7EB407EE5__INCLUDED_)
#define AFX_UGXGRAPHICS_H__0B8ABC21_18A2_4B88_8E1E_15D7EB407EE5__INCLUDED_

#include "Graphics/UGGraphics.h"
#include "XGraphics/UGXPen.h"
#include "XGraphics/UGXBrush.h"
#include "XGraphics/UGXRgn.h"
#include "XGraphics/UGXFont.h"
#include "Base/UGArray.h"
#include <X11/Xlib.h>	// for XPoint
#include "XGraphics/UGFreeTypeLib.h"
  
#include   <libart_lgpl/art_misc.h>
#include   <libart_lgpl/art_svp.h>
#include   <libart_lgpl/art_vpath.h>
#include   <libart_lgpl/art_svp_vpath.h>
#include   <libart_lgpl/art_gray_svp.h>
#include   <libart_lgpl/art_svp_vpath_stroke.h>

namespace UGC
{
typedef UGArray<XPoint> arrayPoints;
class XGRAPHICS_API UGXGraphics : public UGGraphics  
{
	friend void UGXFont::Draw_Bitmap(UGXGraphics&,void*,UGint,UGint);
	friend void UGXFont::DrawString(UGXGraphics&,UGint,UGint,const UGString&,UGint,UGint);
	friend class UGXFont;

	//added by xielin 2007-08-16 ΪXFont�Ż�����ΪX11�»����ı������Freetype������
	//Ϊ�˾������ٴ�Freetype��ȡ���κͰ�����ת���ɣ���Ҫ��gettextextend��drawstring
	//�Ż����������ǻ������ϴε��ַ������ַ�����һЩ���ԣ��������壬�߶ȣ���ȣ���ת�Ƕ�
	//ÿ�λ��ƻ�����Ҫ��freetype�򽻵���ʱ���ж�һ���ϴ��Ƿ񻺴棬����л��棬��ô
	//�ж��Ƿ���ͬ�����ַ�����ͬ���ĸ߶ȡ���ȵȣ�����ǣ���ôֱ���û����е����ݣ���ʡЧ��
	struct UGCacheFontInfo
	{		
		UGint nHeight;
		UGint nWidth;
		UGint nAngle;
		UGString strFontName;  //��������
		UGString strText;	//�ı�����
		FT_Vector fvMax;   //�ַ����������ֵ���豸���꣩
		FT_Vector fvMin;	//�ַ�����С����ֵ(�豸����)
		UGArray<FT_Glyph> glyphs;  //����drawstring�����е�glyph
		UGArray<FT_Vector> glyphsPos; //����drawstring������glyphλ��
		UGint nMaxDxS;	//����@����ı�������������
		UGint nMinDy;	//����@����ı�������������
		UGint nMaxDxE; //����@����ı�������������
		UGCacheFontInfo()
		{					
			nHeight = 0;
			nWidth = 0;
			nAngle = 0;
			strFontName = "";
			strText = "";
			fvMax.x = 0;
			fvMax.y = 0;
			fvMin.x = 0;
			fvMin.y = 0;
			nMaxDxS = 0;
			nMinDy = 0;
			nMaxDxE = 0;
		}
	};

	//added by xielin 2007-08-22 ��¼�������һ���ṹ������xy���꣬����һ���Ҷ�ֵ��0��255֮�䣩
	struct UGAntiPoint
	{
		UGint nX;
		UGint nY;
		UGuchar charColor;
		UGAntiPoint()
		{
			nX = 0;
			nY = 0;
			charColor = 0;
		}
	};

public:
	
	UGXGraphics();
	virtual ~UGXGraphics();

	virtual UGbool CreateCompatibleGraphics(UGGraphics* pGraphics) ;
	virtual UGbool DeleteGraphics() ;

	virtual UGbool IsPrinting() const ;
	
	virtual UGImage* SelectImage(UGImage *pImage) ;
	virtual UGFont* SelectFont(UGFont *pFont) ;
	virtual UGBrush* SelectBrush(UGBrush *pBrush) ;
	virtual UGPen* SelectPen(UGPen *pPen) ;
	
	virtual UGColor GetForeColor() const ;
	virtual UGColor SetForeColor(UGColor color) ;	
	
	virtual UGColor GetBackColor() const ;
	virtual UGColor SetBackColor(UGColor color) ;

	
	virtual UGint GetBackMode() const ;
	virtual UGint SetBackMode(UGint nBKMode) ;

	virtual UGint SetROP2(UGint nDrawMode) ;
	virtual UGint GetROP2() ;	

	virtual UGint GetMapMode() const ;
	virtual UGint SetMapMode(UGint nMapMode) ;

	virtual void DPtoLP(UGPoint* pPoints, UGint nCount = 1) ;
	virtual void DPtoLP(UGRect& rect) ;
	virtual void DPtoLP(UGSize& size) ;
	virtual void LPtoDP(UGPoint* pPoints, UGint nCount = 1) ;
	virtual void LPtoDP(UGRect& rect) ;
	virtual void LPtoDP(UGSize& size) ;
	
	virtual void LPtoHIMETRIC(UGSize& size) ;
	virtual void DPtoHIMETRIC(UGSize& size) ;
	virtual void HIMETRICtoLP(UGSize& size) ;
	virtual void HIMETRICtoDP(UGSize& size) ;

	virtual UGRgn* SelectClipRgn(UGRgn* pRgn, UGint nMode) ;

	virtual UGPoint GetCurrentPosition() const ;

	
	virtual UGColor GetPixel(UGint x,UGint y)  ;
	virtual UGColor SetPixel(UGint x,UGint y, UGColor color) ;

	virtual UGPoint MoveTo(UGint x,UGint y) ;
	virtual UGPoint MoveTo(UGPoint point) ;
	
	virtual UGbool LineTo(UGint x,UGint y) ;
	virtual UGbool LineTo(UGPoint point) ;
	
	virtual UGbool Line(UGint x1,UGint y1,UGint x2,UGint y2) ;
	virtual UGbool Line(UGPoint point1, UGPoint point2) ;
		
	virtual UGbool Polyline(const UGPoint* pPoints, UGint nCount) ;
	
	virtual UGbool PolyPolyline(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount) ;

	virtual UGbool Polygon(const UGPoint* pPoints, UGint nCount) ;
	
	virtual UGbool PolyPolygon(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount) ;

	virtual UGbool Rectangle(UGint x1, UGint y1, UGint x2, UGint y2) ;
	virtual UGbool Rectangle(const UGRect& rect) ;

	virtual UGbool Ellipse(UGint x1, UGint y1, UGint x2, UGint y2) ;
	virtual UGbool Ellipse(const UGRect& rect) ;

	virtual UGbool Arc(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) ;
	virtual UGbool Arc(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) ; 

	virtual UGbool Chord(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) ;
	virtual UGbool Chord(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) ; 
	
	virtual UGbool Pie(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) ;
	virtual UGbool Pie(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) ; 

	virtual UGbool RoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3) ;
	virtual UGbool RoundRect(const UGRect& rect, UGPoint point) ; 

	virtual UGbool DrawImage(UGint x, UGint y,
		UGint nWidth, UGint nHeight,  
		UGGraphics* pMemGraphics,
		UGint xSrc, UGint ySrc, 
		UGint nDrawMode) ;

	virtual UGbool StretchImage(UGint x, UGint y, 
		UGint nWidth, UGint nHeight,
		UGGraphics* pMemGraphics,
		UGint xSrc, UGint ySrc, 
		UGint nSrcWidth, UGint nSrcHeight, 
		UGint nDrawMode) ;

	virtual UGbool StretchImage(UGint x, UGint y, 
		UGint nWidth, UGint nHeight,
		UGint xSrc, UGint ySrc, 
		UGint nSrcWidth, UGint nSrcHeight, 
		UGImage::UGImageData& ImageData) ;
	
	virtual UGbool _textOut(UGint x, UGint y, const UGString& str, UGint nPaintOption=0/*PaintOption::PaintAll*/) ;	
	virtual UGbool TextOut(UGint x, UGint y, const UGString& str, UGTextStyle textStyle = UGTextStyle()) ;	
	virtual UGint DrawText(const UGRect& rect, const UGString& str, UGint nFormat) ;
	
	virtual UGint GetTextAlign() const ;
	virtual UGint SetTextAlign(UGint nTextAlign) ;
	virtual UGSize GetTextExtent(const UGString& str) ;
	virtual void SetGraphicsData(const UGGraphicsData &data);

	//added by lugw 2007-04-07 ��ӻ�ɾ���������ĵ����Ϣ
	//! \brief  ��ӷ��������λ��
	/**
	\param nBuffer  �õ���FT�е�ֵ��͸���ȣ�
	\param point    �õ��λ��
	*/
	void AddBuffer(UGint nBuffer,XPoint point);
	//deleted by xielin 2007-08-23 ���������������Ҫ��
	//void RemoveAllBuffer();

	//added by xielin 2007-04-20 ��XImage���ڴ������л�ȡָ��λ�õ�Color����Ҫ���ڷ����������ʱ��Ƶ����ȡ��ͼ��ɫֵ����
	//! \brief ��image��buffer�������л�ȡcolor
	/**
	\param x  x���꣬�߼���λ
	\param y  y���꣬�߼���λ
	\remarks  x��y�����Ӧ����ɫֵ
	*/
	UGColor GetPixelFromBuffer(UGint x,UGint y) ;

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
	//! \brief ��ȡ������ê�㣨���Ͻǣ��ľ���
	virtual UGint GetBaselinetoAnchor();
	
protected:
	inline UGint DPtoLP_X(UGint x);
	inline UGint DPtoLP_Y(UGint y);
	inline UGint LPtoDP_X(UGint x);
	inline UGint LPtoDP_Y(UGint y);

	
	void drawPoints(UGArray<XPoint> &points);
	//added by xielin 2007-08-15 Ϊ�����Ч�ʣ���дһ��drawPoints����������ָ��͸���
	void drawPoints(XPoint* pPoints,UGint nCount);
	void *calcMask(const UGPoint *pPoints, const UGint* pPntCount, UGint nCount);
	void create();
	//added by lugw 2007-04-07 ����������RGBֵ
	//! \brief  ��ӷ��������λ��
	/**
	\param nForeColor  ǰ��ɫ��ָ���Ƶ��ߵ���ɫ
	\param nBackFore   ����ɫ��ָ��ͼ����ɫ
	\param nC   ͸����
	\remarks �������RGBֵ
	*/
	UGColor AntiForeColor(UGColor& nForeColor,UGColor nBackFore,UGdouble nC);

	//! \brief  Ԥ���������ߣ���Ҫʵ�ִ�������ߵ�����㴮��Ȼ��ͨ�������ȡ��Ҫ͸������ĵ������͸����
	/**
	\param pPoints  �����ߵĵ㴮���豸����
	\param nCount   �㴮�е������
	\param nLineWidth   �ߵĿ��
	\remarks �ɹ�����true������ŵ���Ա����m_nAntiArray��
	*/
	virtual UGbool PrePareForPolyLineAnti(const XPoint* pPoints, UGint nCount,UGint nLineWidth);

	//! \brief  ���Ʒ�������͸���㵽ָ��λ�ã������ı��ķ����������
	virtual void drawPointOfAnti();

	//! \brief  ���Ʒ�������͸���㵽ָ��λ�ã������ߣ���������εı��ߣ��ķ����������
	virtual void drawLinePointOfAnti();

	//added by xielin 2007-04-20 �����ж��Ƿ���Ҫƽ������Ȼ������ߵķ������㣬����Ķ����豸����
	//! \brief  ���Ʒ�������͸���㵽ָ��λ�ã������ߣ���������εı��ߣ��ķ����������
	virtual void drawLinePointOfAnti(const XPoint* pPoints, UGint nCount,UGint nLineWidth = -1);
	//virtual void drawLinePointOfAnti(UGint x1,UGint y1,UGint x2,UGint y2);
	virtual void drawLinePointOfAnti(UGint x1,UGint y1,UGint x2,UGint y2,UGint nLineWidth = -1);
	//! \brief ������建��
	void ClearCacheFontInfo();

protected:
	UGbool m_bNeedRelease;
	UGbool m_bUpdate;
	UGint m_nBkMode;
	UGint m_nDrawMode;
	UGint m_nTextAlign;
	
	UGRgn *m_pRgn;
	
	// ����/�߼���λ��
//	double m_dCoorRatioX; �Ƶ�Graphics����
//	double m_dCoorRatioY;
	
	void *m_gc;
	//added by lugw 2007-04-07 �洢�������ĵ�λ��
	
	UGArray<arrayPoints> m_nAntiArray;

	//added by xielin 2007-04-19 ͨ��x11ȡǰ������ɫ�е������ó�Ա����������������ٶ� 
	UGColor m_backcolor;
	UGColor m_forecolor; 
//added by xielin 2007-08-15 ��XGraphics�Ż�����һ����Ա������¼�㴮������ÿ��new
protected:
	//! \brief LPtoDPת��XPointָ��
	void LPtoDP(XPoint* pPoints, UGint nCount = 1);
	//! \brief Ԥ������ĵ㴮��ִ�еĲ����аѵ㴮�ŵ���Ա�㴮�У�lp����ת����dp����
	void PreProcessPoints(const UGPoint* pPoints, UGint nCount,UGint nXPointSize = 0);
	//! \brief UGPointת����XPoint
	static void ConvertUGPoint2POINT(const UGPoint* pPoints, XPoint* pXPoints, UGint nCount);	
	//! \brief XPointת����UGPoint
	static void ConvertPOINT2UGPoint(const XPoint* pXPoints, UGPoint* pPoints, UGint nCount);
	//! \brief ר��ΪX11�Ż��ĺ�������ΪX11����ֱ�ӻ���polypolygon�������Ƕ�λ���polygon����ô�͵�������Ż��ĺ���������polygon
	//! \brief �Ϳ��ų�ȥ��polygon������һ�����ǣ��ú���������Ѿ����豸�����XPoint�ˣ��ڲ�����Ҫ���κδ���ֱ�ӻ��Ƽȿɣ����Ч��
	UGbool PolygonFromMemory(XPoint* pPoints, UGint nCount) ;

	XPoint* m_lpPoints;	
	UGint m_nPntCountMax;	

	//! \brief Ϊ����������Ż�������ÿ�λ��ƵĴ�freetype��ȡ������һЩ��Ϣ
	UGCacheFontInfo m_CacheFontInfo;

	void PreCachAntiPoints(UGint nCount);
	//! \brief �����ĸ����������������ͷ�����ʱ����Ҫ���ڴ�����
	art_u8 *m_pLineArtbuffer;
	UGint m_nLineArtBufferMaxCount;
	ArtVpath *m_pLineArtVpath;
	UGint m_nLineArtVpathMaxCount;

	//! \brief ��¼�����������Ϣ
	UGAntiPoint* m_pAntiPoints;
	UGint m_nAntiPointsCount;
	UGint m_nAntiPointsMaxCount;

	//����graphics��ǰʹ�õ��ڴ�Image�Ƿ���Ҫ���£�Ҳ���Ǵ�pixmap��ͬ�����ݣ�
	void SetImageNeedUpdate(UGbool bNeedUpdate=true);

	//added by xielin ^_^ ΪStretchImage��RotateImage���Ż����ó�Ա��������任�����е����飬�ӿ���ʾ�ٶ�
	//�������ռ��һ���ڴ棬�����ۺ�������Ӧ����ֵ�õġ�
	//! \brief �任ԴͼƬ��Colors����
	UGColor *m_pSrcImageColors;
	//! \brief ԴͼƬcolors���������С
	UGint m_nMaxSrcImageColorsCount;
	//! \brief �任Ŀ��ͼƬ��Colors����
	UGColor *m_pDesImageColors;
	//! \brief Ŀ��ͼƬcolors���������С
	UGint m_nMaxDesImageColorsCount;

	UGbool StretchImage(UGint x, UGint y, 
		UGint nWidth, UGint nHeight,
		UGImage* pImage,
		UGint xSrc, UGint ySrc, 
		UGint nSrcWidth, UGint nSrcHeight, 
		UGint nDrawMode) ;
		

};

}

#endif // !defined(AFX_UGXGRAPHICS_H__0B8ABC21_18A2_4B88_8E1E_15D7EB407EE5__INCLUDED_)

