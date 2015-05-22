// UGWImage.h: interface for the UGWImage class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGWImage.h
   **************************************************************************************
    \author   ���������¹���
    \brief    Windowsλͼ��                                                          
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGWIMAGE_H__1E3D0CD0_C1C7_4B31_91FB_9D7A600AAD54__INCLUDED_)
#define AFX_UGWIMAGE_H__1E3D0CD0_C1C7_4B31_91FB_9D7A600AAD54__INCLUDED_

#include "Graphics/UGImage.h"

namespace UGC
{

class WGRAPHICS_API UGWImage : public UGImage  
{
public:
	UGWImage();
	virtual ~UGWImage();

	// ����Image	
	virtual UGbool Create(const UGImageData& ImageData);
	virtual UGbool Create(
		UGint nWidth,
		UGint nHeight,
		UGuint nPlanes, 
		UGuint nBitcount, 
		const UGPalette& palette, 
		const void* pBits);
	virtual UGbool CreateCompatibleImage(UGGraphics *pGraphics, 
		UGint nWidth, UGint nHeight);
	
	// ɾ��Image
	virtual void DeleteObject();

	virtual UGbool Load(UGuint nIDResource);
	
	virtual UGbool GetImageData(UGImageData& ImageData);
	
	
	// ��ȡUGImage�����ڲ�����
	virtual UGuint GetBits(UGuint unCount, void* pBits) const;
	virtual UGuint SetBits(UGuint unCount, const void* pBits);

	//added by xielin 2007-08-24 �ⲿ������ʵϣ���Ż�һ��UGColor�����飬
	//������linux������Ч�ʸߺܶ�(2~4��)��������������һ���ӿڣ���Windows
	//���ڲ����û����Ƽ�������Bits����linux����Colors���ⲿ���ý��鶼��Colors
	//! \brief ��ȡUGImage�����ڲ����ݣ�ת������UGColor��ʽ,ע�⣬���ص�ָ��
	//! \brief �ⲿ��Ҫɾ�����ڲ�������Ŀǰֻ֧��16λ������ɫ
	virtual UGuint* GetColors();

	//! \brief ����UGImage�����ڲ����ݣ�Ŀǰֻ֧��16λ������ɫ
	virtual void SetColors(UGuint unCount,const UGuint* pColors);
	
	//! ȡͼ����(x, y)�������ֵ
	virtual UGColor GetPixel(UGint x, UGint y) const;
	//! ����ͼ����(x, y)�������ֵ
	virtual UGColor SetPixel(UGint x, UGint y, UGColor color);		

	//! �ж��Ƿ��ǵ�ֵͼ��
	virtual UGbool IsMonochrom() const;
	//! �ı�m_pData�ڴ����Ĵ�С
	virtual void Scale(UGint w,UGint h, UGbool bIsResample = true);	
	void SetNativePalette(CPalette *pNativePalette);
	CPalette *GetNativePalette() const;

	//added by xielin 2007-04-20
	//! \brief ��image�е����ݻ��浽buffer�У�Ŀǰ��Ҫ����linux�еķ�����
	//ʵ�ַ�ʽ��ÿ�λ���һ��ͼ��ǰ������ǰ���ƵĻ��浽Image��һ����Ա������
	//�������л����������ʱ��getpixel��ֱ��ȡ�����еı����л�ȡ������ٶ�
	virtual void PrepareBuffer();

private:
	UGbool m_bNeedRelease;
	UGPalette m_Palette;
	CPalette *m_pNativePalette;
	//added by xielin 2007-08-24 ����������ɫ���飬getcolors�õ�
	UGColor* m_pBuf;
	//added by xielin 2007-08-24 ��������bits,����ÿ��new��getcolors�õ�
	UGbyte* m_pBits;
	UGint m_nBufCount;
	UGint m_nBitsCount;
};

}

#endif // !defined(AFX_UGWIMAGE_H__1E3D0CD0_C1C7_4B31_91FB_9D7A600AAD54__INCLUDED_)
