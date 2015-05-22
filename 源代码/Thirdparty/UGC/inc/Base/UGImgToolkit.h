// UGImgToolkit.h: interface for the UGImgToolkit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGIMGTOOLKIT_H__21224E42_7983_49CB_99BC_9792CA94305F__INCLUDED_)
#define AFX_UGIMGTOOLKIT_H__21224E42_7983_49CB_99BC_9792CA94305F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ugdefs.h"


namespace UGC{


class BASE_API UGImgToolkit  
{
public:
	UGImgToolkit();
	virtual ~UGImgToolkit();

public:
	//==============================================================
	//�������ظ�ʽ�����ؿ�ȼ���DWORD����İ���BYTE�Ƶ�ʵ����Ҫ���.
	static UGint AlignWidth(PixelFormat PixelFormat,UGint lPixelWidth);
	static UGint AlignWidthByte(PixelFormat PixelFormat,UGint lPixelWidth);
	static UGint AlignWidthWord(PixelFormat PixelFormat,UGint lPixelWidth);
	
	static UGushort BitCount(PixelFormat PixelFormat);		//���ݸ�ʽ����λ��.
	static UGushort PaletteSize(PixelFormat PixelFormat);	//�õ���Ҫ�ĵ�ɫ���С.
	static PixelFormat Bit2Format(UGushort wBitCount);		//����λ�����ظ�ʽ.
	
	#if PACKAGE_TYPE==PACKAGE_UGC
	//ɫ�ʿռ�ת��------------------------------------------------------------
	static UGint RGB2CMY(UGint color);
	static UGint CMY2RGB(UGint color);
	static UGint RGB2YIQ(UGint color);
	static UGint YIQ2RGB(UGint color);
	static UGint RGB2YUV(UGint color);
	static UGint YUV2RGB(UGint color);
	static UGint RGB2YCC(UGint color);
	static UGint YCC2RGB(UGint color);
	#endif // end declare ugc API


};
}

#endif // !defined(AFX_UGIMGTOOLKIT_H__21224E42_7983_49CB_99BC_9792CA94305F__INCLUDED_)

