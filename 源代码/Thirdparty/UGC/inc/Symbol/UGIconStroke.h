// UGIconStroke.h:

#ifndef UG_ICONSTROKE_H
#define UG_ICONSTROKE_H

#include "Graphics/UGGraphics.h"

namespace UGC 
{

class SYMBOL_API UGIconStroke  
{
public:
	UGIconStroke();
	~UGIconStroke();

	UGIconStroke(const UGIconStroke& iconStroke);
	void operator = (const UGIconStroke& iconStroke);

public:
	struct IconHeader  // 6�ֽ�
	{
		UGushort idReserved; // Reserved, must be 0
		UGushort idType;     // resource type (1 for icons)
		UGushort idCount;    // how many images?
	};

	struct IconDirEntry // 16�ֽ�
	{
		UGbyte	    bWidth;               // Width of the image
		UGbyte	    bHeight;              // Height of the image (times 2)
		UGbyte	    bColorCount;          // Number of colors in image (0 if >=8bpp)
		UGbyte	    bReserved;            // Reserved
		UGushort	wPlanes;              // Color Planes
		UGushort	wBitCount;            // Bits per pixel
		UGuint	    dwBytesInRes;         // how many bytes in this resource?
		UGuint	    dwImageOffset;        // where in the file is this image
	};

	struct BitmapInfoHeader
	{
        UGint      biSize;
        UGint      biWidth;
        UGint      biHeight;
        UGushort   biPlanes;
        UGushort   biBitCount;
        UGint      biCompression;
        UGint      biSizeImage;
        UGint      biXPelsPerMeter;
        UGint      biYPelsPerMeter;
        UGint      biClrUsed;
        UGint      biClrImportant;
	};

public:
	UGbool Load(UGStream& stream, UGuint nVersion = 0);
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;
	
	void Draw(UGGraphics& graphics, const UGPoint& pntCenter, UGint nWidth, UGint nHeight, const UGdouble dAngle, UGbool bHighlight/*�Ƿ������ʾ*/, UGint nTransPercent = 100) const;
	void   ClearImageData();
	void   GetSize(UGint& nWidth, UGint& nHeight) const;

	//! ��ȡIcon�ļ��е�Iconͼ������
	UGbool LoadIconImage(UGStream& stream);
	//! ��Iconͼ�����ݱ���ΪIcon�ļ�
	UGbool SaveIconImage(UGStream& stream)const;

	//! ����ΪIcon�ļ�������Icon�ļ����ֽ���
	UGuint GetBytesOfSavingIconFile() const;

protected:
	UGbool Load_Version2003(UGStream& stream);
	UGbool Load_Version2005(UGStream& stream);
    UGbool Save_Version2005(UGStream& stream) const;
	UGbool Save_Version2003(UGStream& stream) const;

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

private:

	//! Icon��λͼ����
	UGImage::UGImageData* m_pImageXORMaskData;
	UGImage::UGImageData* m_pImageANDMaskData;
};

}

#endif
