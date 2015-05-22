// UGPSGraphics.h: interface for the UGPSGraphics class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPSGRAPHICS_H__C9316B6D_6F60_4137_942A_4811741085EB__INCLUDED_)
#define AFX_UGPSGRAPHICS_H__C9316B6D_6F60_4137_942A_4811741085EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Graphics/UGGraphics.h"
#include "PSGraphics/CreEPS.h"
#include "Algorithm/UGRect2D.h"

namespace UGC
{
#define BITSPERPIXEL  8								//һ�����صĵ�ɫλ��������������ռ����λ��

class PSGRAPHICS_API UGPSGraphics : public UGGraphics  
{
public:
	UGPSGraphics();
	UGPSGraphics(const UGchar* filename, const UGfloat startX, const UGfloat startY,
		                                    const UGfloat   endX, const UGfloat   endY,
		              const UGbool latex = false, const UGchar* altEPSFilename = NULL);
	UGPSGraphics(const UGchar* filename, const UGfloat width, const UGfloat height,
		              const UGbool latex = false, const UGchar* altEPSFilename = NULL );
	virtual ~UGPSGraphics();
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
	// ����ǰ��ɫ	�ı���ɫ
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

public:
//	static UGRect ConvertUGPoint2POINT(const UGPoint* pPoints, LPPOINT lpPoints, int nCount);	
//	static void ConvertPOINT2UGPoint(const LPPOINT lpPoints, UGPoint* pPoints, int nCount);
	void NewFile( const UGchar* filename, const UGfloat startX, const UGfloat startY,
		                                    const UGfloat   endX, const UGfloat   endY,
		              const UGbool latex = false, const UGchar* altEPSFilename = NULL );
	void NewFile( const UGchar* filename, const UGfloat width, const UGfloat height,
		              const UGbool latex = false, const UGchar* altEPSFilename = NULL );
	virtual void SetCoordRatio(UGfloat dRatioX,UGfloat dRatioY);
	
	//���ߺ��ı��������ֿ�����SFCһ��
	//virtual void SetSmoothingMode(UGbool bSmoothingMode);//psgraphics�в����Ƿ�����
	virtual void SetLineSmoothingMode(UGbool bSmoothingMode);//psgraphics�в����Ƿ�����
	virtual void SetTextSmoothingMode(UGbool bSmoothingMode);//psgraphics�в����Ƿ�����

	////! \brief ���βü�
	virtual UGbool RectClip(UGint left, UGint top, UGint right, UGint bottom);
	virtual UGbool RectClip(const UGRect& rect);

protected:
	UGint DPtoLP_X(UGdouble x);
	UGint DPtoLP_Y(UGdouble y);
	UGdouble LPtoDP_X(UGint  x);
	UGdouble LPtoDP_Y(UGint  y);	
	
	void DPtoLP(const UGPoint2D* pPnts2D,UGPoint* pPoints, UGint nCount = 1);
	void DPtoLP(const UGRect2D& rect2D,UGRect& rect);
	void DPtoLP(const UGSize2D& size2D,UGSize& size);
	void LPtoDP(const UGPoint* pPoints, UGPoint2D* pPnts2D,UGint nCount = 1);
	void LPtoDP(const UGRect& rect, UGRect2D& rect2D);
	void LPtoDP(const UGSize& size,UGSize2D& size2D);

	UGint GetBits(UGImage::UGImageData& bmpData,UGint* pIntBits);

	//! \biref ��UGImageData�е�pBitsתΪRGB��������ɫֵ��ÿ��UGchar��ʾR��G��B�е�һ��
	/*
	\param bmpData ����Ҫת����ɫֵ��pBits��imagedata
	\param pBits	ת����RGBֵ����һ��R��G��Bֵ�������ж�����һ���R��G��B��R��G��B...����
	*/
	UGint GetBitsChar(UGImage::UGImageData& bmpData, UGint xSrc, UGint ySrc, UGint nWidth, UGint nHeight, UGchar* pBits);

	void PointstoLine(const UGPoint* pPoints, UGint nCount);
private:
	UGbool m_bNeedReleaseDC;

	UGPoint2D* m_lpPoints;	
	UGint m_nPntCountMax;

	// ����/�߼���λ��
//	UGdouble m_dCoorRatioX;
//	UGdouble m_dCoorRatioY;

	CreEPS *  m_pCreEPS;	
//	UGString m_strPath;
//	UGGraphics* pGraphics;		//�����ƽ̨���
	UGbool m_bTransparentMode;	//�����Ƿ񱳾�͸��
	UGbool m_bCompatible;		//�����CreateCompatibleGraphics ��Ϊ�� ֱ��new��Ϊ��
};
}
#endif // !defined(AFX_UGPSGRAPHICS_H__C9316B6D_6F60_4137_942A_4811741085EB__INCLUDED_)
