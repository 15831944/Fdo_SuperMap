// UGXImage.h: interface for the UGXImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGXIMAGE_H__593E340E_9333_48FB_AAA5_F913D23C9576__INCLUDED_)
#define AFX_UGXIMAGE_H__593E340E_9333_48FB_AAA5_F913D23C9576__INCLUDED_

#include "Graphics/UGImage.h"
#include "XGraphics/UGXGraphics.h"

namespace UGC
{

class XGRAPHICS_API UGXImage : public UGImage  
{
	friend UGbool UGXGraphics::StretchImage(UGint,UGint,UGint,UGint,UGGraphics*,UGint,UGint,UGint,UGint,UGint); 
	friend UGbool UGXGraphics::StretchImage(UGint,UGint,UGint,UGint,UGint,UGint,UGint,UGint,UGImage::UGImageData&);
	friend UGbool UGXGraphics::DrawImage(UGint,UGint,UGint,UGint,UGGraphics*,UGint,UGint,UGint);
	friend UGImage *UGXGraphics::SelectImage(UGImage*);
	friend class UGXGraphics;
public:
	UGXImage();
	
	virtual ~UGXImage();

	virtual UGbool Create(
			UGint nWidth,
			UGint nHeight,
			UGuint nPlanes, 
			UGuint nBitcount, 
			const UGPalette& palette,
			const void* pBits);

	virtual UGbool Create(const UGImageData & BitmapData);

	virtual UGbool CreateCompatibleImage(UGGraphics *pGraphics, 
		UGint nWidth, UGint nHeight);

	virtual void DeleteObject();

	virtual UGbool Load(UGuint nIDResource);
	
	virtual UGbool GetImageData(UGImageData& ImageData) ;
	
	virtual UGuint GetBits(UGuint unCount, void *pBits) const;

	virtual UGuint SetBits(UGuint unCount, const void *pBits);

	virtual UGColor GetPixel(UGint x, UGint y) const;

	virtual UGColor SetPixel(UGint x, UGint y, UGColor color);

	virtual UGbool IsMonochrom() const;

	virtual void Scale(UGint w, UGint h, UGbool bIsResample=TRUE);
	
	virtual void PrepareBuffer();
	UGColor getPixel(UGint x, UGint y,void *pMemBits = NULL);

	//added by xielin 2007-08-24 �ⲿ������ʵϣ���Ż�һ��UGColor�����飬
	//������linux������Ч�ʸߺܶ�(2~4��)��������������һ���ӿڣ���Windows
	//���ڲ����û����Ƽ�������Bits����linux����Colors���ⲿ���ý��鶼��Colors
	//! \brief ��ȡUGImage�����ڲ����ݣ�ת������UGColor��ʽ,ע�⣬���ص�ָ��
	//! \brief �ⲿ��Ҫɾ�����ڲ�������Ŀǰֻ֧��16λ������ɫ
	virtual UGuint* GetColors();

	//! \brief ����UGImage�����ڲ����ݣ�Ŀǰֻ֧��16λ������ɫ,ĿǰҪ�����pColorsΪABGR��ʽ������б����Ҫ������ϵxielin�����޸�
	virtual void SetColors(UGuint unCount,const UGuint* pColors);

protected:
	static void render_true_N_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_true_24(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_true_16_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_true_32(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_true_8_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_index_4_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_index_8_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_index_N_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_gray_8_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_gray_N_dither(void *xim,UGuchar *img, UGint width, UGint height) ; 
	static void render_mono_1_dither(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_true_N_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_true_16_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_true_8_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_index_4_fast(void *xim,UGuchar *img,UGint width, UGint height) ;
	static void render_index_8_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_index_N_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_gray_8_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_gray_N_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_mono_1_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render(XImage *xim, int depth, UGuchar *m_buf, UGint w, UGint h);

	static void hscalergba(UGuchar *dst,const UGuchar *src,UGint dw,UGint dh,UGint sw,UGint sh) ;
	static void vscalergba(UGuchar *dst,const UGuchar *src,UGint dw,UGint dh,UGint sw,UGint sh) ;
	static void scalenearest(UGColor *dst, const UGColor *src, UGint dw, UGint dh, UGint sw, UGint sh);

	
	UGColor getPixel1(UGint x, UGint y,void *pMemBits);
	UGColor getPixel4(UGint x, UGint y,void *pMemBits);
	UGColor getPixel8(UGint x, UGint y,void *pMemBits);
	UGColor getPixel16(UGint x, UGint y,void *pMemBits);
	UGColor getPixel24(UGint x, UGint y,void *pMemBits);
	UGColor getPixel32(UGint x, UGint y,void *pMemBits);
	UGbool setPixel(UGint x, UGint y,UGColor value,void *pMemBits);
	UGbool setPixel1(UGint x, UGint y, UGColor value,void *pMemBits);
	UGbool setPixel4(UGint x, UGint y, UGColor value,void *pMemBits);
	UGbool setPixel8(UGint x, UGint y, UGColor value,void *pMemBits);
	UGbool setPixel16(UGint x, UGint y, UGColor value,void *pMemBits);
	UGbool setPixel24(UGint x, UGint y, UGColor value,void *pMemBits);
	UGbool setPixel32(UGint x, UGint y, UGColor value,void *pMemBits);

	// �Ƿ��Ǵ�m_BitmapData.pBits => m_buf,
	// Ĭ���Ǵ�m_buf => m_BitmapData.pBits
	//�Ӽ���������,��һ��Ҫÿ�ζ�����m_BitmapData.pBits��m_buf��̫�˷�Ч���ˡ�
	void updateBuffer(void *pBits = NULL,UGuint *pColors = NULL,UGbool direction = FALSE);
	void updatePixmap();

	//added by xielin ^_^ �Ż�Ximage���Ȳ���ok��дע��
	//��Ҫ�������ݣ���pixmap�и������ݵ������ugcolor�У�m_buf��
	UGbool m_bNeedUpdate;
	//�Ƿ���Ҫ��m_bufת��bits
	UGbool m_bNeedFromColorToBits;
	UGColor *m_buf;

	//! \brief ������ARGB��ʽ��Color
	UGuint *m_pARGBBuf;
	//! \brief ������ARGB��ʽ��Color������С
	UGint m_nMaxARGBBufCount;

	void SetNeedUpdate(UGbool bNeedUpdate=TRUE);
	UGbool IsNeedUpdate();

	//! \brief ��bitsת����colors������stretchImage�в�����ImageData�����������ǰ���÷��ӿ��ٶ�
	void ConvertImageDataToColors(const UGImageData & ImageData,UGuint *pColors,UGbool bIsReverse);
private:
	UGbool m_bNeedRelease;
	UGbool m_bIsReverse;
	UGImageData m_ImageData;
	
};

}

#endif // !defined(AFX_UGXIMAGE_H__593E340E_9333_48FB_AAA5_F913D23C9576__INCLUDED_)

