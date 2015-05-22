// UGBitmapStroke.h:

#ifndef UG_BITMAPSTROKE_H
#define UG_BITMAPSTROKE_H

#include "Graphics/UGGraphics.h"

namespace UGC {
	
class SYMBOL_API UGBitmapStroke  
{
public:
	UGBitmapStroke();
	~UGBitmapStroke();
	UGBitmapStroke(const UGBitmapStroke& bitmapStroke);
	void operator = (const UGBitmapStroke& bitmapStroke);
	
public:
	//! \brief ���λͼ����
	void   Clear();
	//! \brief ��ȡλͼ��Ϣ
	UGbool Load(UGStream& stream, UGuint nVersion = 0);
	//! \brief ����λͼ��Ϣ
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

	//! \brief ���߼�����pntCenter�����Ƹ�Bitmap�ʻ�
	void Draw( UGGraphics& graphics, const UGPoint& pntCenter,
		       UGint nWidth, UGint nHeight, const UGdouble dAngle,  UGbool bHighlight/*�Ƿ������ʾ*/, UGint nTransPercent = 100) const;

	//! \brief ����λͼ�ĸ߶ȺͿ��
	void GetSize( UGint& nWidth, UGint& nHeight )
	{
		if ( m_pImageData == NULL )
		{
			nWidth = nHeight = 0;
		}
		else
		{
			nWidth  = m_pImageData->nWidth;
			nHeight = m_pImageData->nHeight;
		} 
	}

	//! \brief ��ȡSFC5.0�汾λͼ��Ϣ
	UGbool LoadBmp(UGStream& stream);
	//! \brief ����SFC5.0�汾λͼ��Ϣ
	UGbool SaveBmp(UGStream& stream) const;

	//! \brief ����ΪBitmap�ļ�ʱ���ֽ���
	UGuint GetBytesOfSavingBmpFile() const;

protected:
	//! ͸������λͼ��������һ����ɫ(�ɲ���clrTransparentָ��)����ڱ���ͼ͸����ʾ
	void TransparentDraw(UGGraphics& graphics, UGImage* pImgSrc, 
		                 UGint xStart, UGint yStart, UGColor clrTransparent, UGint nTransPercent = 100) const;

	UGbool LoadImageData(UGStream& stream, UGImage::UGImageData*& pImageData);
	UGbool SaveImageData(UGStream& stream, UGImage::UGImageData* pImageData) const;
	//! \brief ������ת���Bounds��ê��
	/**
	\param nWidth         ԭͼ���[in]
	\param nHeight        ԭͼ�߶�[in]
	\param pntAnchor      ԭͼê��[in]
	\param dAngle         ��ת�Ƕ�[in]
	\param nNewWidth      ��ͼ���[in\out]
	\param nNewHeight     ��ͼ�߶�[in\out]
	\param pntNewAnchor   ��ͼê��[in\out]
	*/
	void CalculateRotateBounds(const UGint nWidth, const UGint nHeight,const UGPoint pntAnchor, const UGdouble dAngle,UGint& nNewWidth,UGint& nNewHeight,UGPoint& pntNewAnchor)const;
	
protected:
	//! bmp��λͼ����
	UGImage::UGImageData* m_pImageData;
};
	
}

#endif
