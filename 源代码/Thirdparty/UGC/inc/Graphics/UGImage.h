/*!
   **************************************************************************************
    \file     UGImage.h 
   **************************************************************************************
    \author   ���������¹���
    \brief    դ���ڴ�λͼ��                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGIMAGE_H__824E53E6_0F39_49FA_A3A4_1EFA13C6FD4B__INCLUDED_)
#define AFX_UGIMAGE_H__824E53E6_0F39_49FA_A3A4_1EFA13C6FD4B__INCLUDED_

#include "Algorithm/UGPoint.h"
#include "UGPalette.h"

namespace UGC
{
class UGGraphics;

class GRAPHICS_API UGImage  
{
public:
	struct UGImageData
	{		
		UGint nWidth;		//! \brief Image�Ŀ�
		UGint nHeight;		//! \brief Image�ĸ�
		UGint nWidthBytes;	//! \brief Image���ֽ���������nWidth*ÿ�������ֽ���������32λ�ֽ�������4
		UGbyte btPlanes;	//! \brief ��ɫ����ɫ��Ŀ
		UGbyte btBitsPixel; //! \brief ÿ�����ص�bit��������32��24
		UGPalette palette;	//! \brief ��ɫ��
		void* pBits;		//! \brief �ڴ����飬ͨ�������洢��ɫֵ

		UGImageData()
		{		
			nWidth = 0;
			nHeight = 0;
			nWidthBytes = 0;
			btPlanes = 1;
			btBitsPixel = 0;
			pBits = NULL;
		}
	};

protected:
	// ���ɿյ�UGImage����
	UGImage();	
public:
	// destructor
	virtual ~UGImage();		
	
	//! \brief ����Image	
	virtual UGbool Create(const UGImageData& ImageData) = 0;
	virtual UGbool Create(
						UGint nWidth,
						UGint nHeight,
						UGuint nPlanes, 
						UGuint nBitcount, 
						const UGPalette& palette,
						const void* pBits) = 0;
	//! \brief ���鶼�øýӿ�������Image����
	virtual UGbool CreateCompatibleImage(UGGraphics *pGraphics, 
										UGint nWidth, UGint nHeight) = 0;
	
	//! \brief ɾ��Image
	virtual void DeleteObject() = 0;

	//! \brief ����Դװ��ͼƬ
	virtual UGbool Load(UGuint nIDResource) = 0;

	//! \brief ��ȡImageData
	virtual UGbool GetImageData(UGImageData& ImageData) = 0;		


	//! \brief ��ȡUGImage�����ڲ�����
	virtual UGuint GetBits(UGuint unCount, void* pBits) const = 0;
	//! \brief ����UGImage�����ڲ�����
	virtual UGuint SetBits(UGuint unCount, const void* pBits) = 0;	
	
	//added by xielin 2007-08-24 �ⲿ������ʵϣ���Ż�һ��UGColor�����飬
	//������linux������Ч�ʸߺܶ�(2~4��)��������������һ���ӿڣ���Windows
	//���ڲ����û����Ƽ�������Bits����linux����Colors���ⲿ���ý��鶼��Colors
	//! \brief ��ȡUGImage�����ڲ����ݣ�ת������UGColor��ʽ,ע�⣬���ص�ָ��
	//! \brief �ⲿ��Ҫɾ�����ڲ�������Ŀǰֻ֧��16λ������ɫ
	virtual UGuint* GetColors();

	//! \brief ����UGImage�����ڲ����ݣ�Ŀǰֻ֧��16λ������ɫ
	virtual void SetColors(UGuint unCount,const UGuint* pColors);

	//! \brief ȡͼ����(x, y)�������ֵ
	virtual UGColor GetPixel(UGint x, UGint y) const = 0;
	//! \brief ����ͼ����(x, y)�������ֵ
	virtual UGColor SetPixel(UGint x, UGint y, UGColor color) = 0;	
	
	//! \brief ����͸��ɫ
	void SetTransparentColor(UGColor color);	
	//! \brief ��ȡ͸��ɫ
	UGColor GetTransparentColor() const;
	
	//! \brief �ж��Ƿ��ǵ�ֵͼ��
	virtual UGbool IsMonochrom() const = 0;		
	
	//! \brief �ı�m_pData�ڴ����Ĵ�С
	virtual void Scale(UGint w,UGint h, UGbool bIsResample=true) = 0;	
	
	//! \brief ��ȡʵ�ʶ���
	void* GetNative() const;
	//! \brief ����ʵ�ʶ���
	void SetNative(void* pNative);
	//! \brief ��ȡ��ʾ��������
	virtual UGint GetGraphicsType();

	//added by xielin 2007-04-20
	//! \brief ��image�е����ݻ��浽buffer�У�Ŀǰ��Ҫ����linux�еķ�����
	//ʵ�ַ�ʽ��ÿ�λ���һ��ͼ��ǰ������ǰ���ƵĻ��浽Image��һ����Ա������
	//�������л����������ʱ��getpixel��ֱ��ȡ�����еı����л�ȡ������ٶ�
	virtual void PrepareBuffer() = 0;
	
protected:
	//! �û��Զ�����Դ�ı�ʶ
	//! ����:��X11��Ϊָ��������˵Ļ���ͼ��, ��Windows��ΪCBITMAP
	void* m_pNative;	
	UGColor m_clrTransparent;	// ����͸����ɫ��ֵ

	UGint m_nGraphicsType;	
};	

}

#endif // !defined(AFX_UGIMAGE_H__824E53E6_0F39_49FA_A3A4_1EFA13C6FD4B__INCLUDED_)
