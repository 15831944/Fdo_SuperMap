/*! \file	 UGDImage.h
 *  \brief	 �洢UGColor��ʽͼ���ڴ�������,ƽ̨�޹�,���ṩƽ̨��صĺ���ָ��.
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDImage.h,v 1.2 2007/04/03 05:44:20 zengzm Exp $
 */

#ifndef UGDImage_H
#define UGDImage_H

#include "ugdefs.h"
#include "UGStream.h"

namespace UGC 
{
class UGDImage;

//! ���ڴ���������û��Զ��庯������
//! ����:��X11���Ǵ����ڷ������˵�Pixmap����, ��Windows���Ǵ���һ��HBITMAP����
typedef UGbool (*CreateUserData)(UGDImage& im);


//! �������ٶ�����û��Զ��庯������
//! ����:��X11���������ڷ������˵�Pixmap����, ��Windows��������һ��HBITMAP����
typedef void (*DestroyUserData)(UGDImage& im);


class BASE_API UGDImage  
{
public:

	//! ����ָʾ��Load��Save����������ͼ��ĸ�ʽ(bmp, png, jpg, ico)
	enum ImageType
	{
		BMPImage = 0,
		PNGImage = 1,
		JPGImage = 2,
		ICOImage = 3
	};

	UGDImage();	
	UGDImage(UGint w,UGint h,UGColor c = UGRGB(255,255,255));	
	virtual ~UGDImage();
			
	//! ���ⲿ����(һ��UGColor�ڴ���)����һ��UGDImage����
	UGbool Copy(UGint w,UGint h,UGColor* data);

	UGColor *GetData() const { return m_pData; }
			
	UGint GetWidth() const;
	UGint GetHeight() const;
	
	//! ȡͼ����(x, y)�������ֵ
	UGColor GetPixel(UGint x,UGint y) const;
	

	//! ����ͼ����(x, y)�������ֵ
	void SetPixel(UGint x,UGint y,UGColor c);
	
	
	//! �²�͸����ɫ, ����͸��ɫ
	UGColor GuessTransparent() const;
	

	//! ����͸��ɫ
	void SetTransparent(UGColor t);
	

	//! ��ȡ͸��ɫ
	UGColor GetTransparent() const;
	

	//! �ж��Ƿ��ǵ�ֵͼ��
	UGbool IsMonochrom() const;	
	

	//! ����Ϊ��ֵͼ��
	void SetMonochrom(UGbool m);
	

	//! ����ͼ�����������(Ŀǰ������JPEG��ʽ������)
	void SetQuality(UGint q);
	

	//! ��ȡͼ�����������(Ŀǰֻ��ȡJPEG��ʽ)
	UGint GetQuality() const;
	

	//! ����Ϊ�����ļ�
	UGbool Save(UGStream& store,ImageType type) const;
	

	//! �Ӵ����ļ�����
	UGbool Load(UGStream& store,ImageType type);	
	

	//! �ı�m_pData�ڴ����Ĵ�С
	void Scale(UGint w,UGint h, UGbool bIsResample=true);
	

	//! ��ȡ�û�����(ȡ���û��Զ�����Դ��ʶ)
	void* GetUserData() const { return m_hUserData; }
	

	//! �����û�����(�����û��Զ�����Դ��ʶ)
	void SetUserData(void* pUserData) { m_hUserData = pUserData; }
	
private:
	//! �û��Զ�����Դ�ı�ʶ
	//! ����:��X11��Ϊָ��������˵Ļ���ͼ��, ��Windows��ΪHBITMAP
	void* m_hUserData;	
	
protected:
	UGColor* m_pData;			// �洢ͼ���������
	UGColor  m_clrTransparent;	// ����͸����ɫ��ֵ
	UGbool   m_bMonochrom;		// �Ƿ��ǵ�ֵͼ��ı�־
	UGint    m_nQuality;		// jpegͼ���ʽ��ѹ������
	UGint    m_nWidth;			// ͼ����
	UGint    m_nHeight;			// ͼ��߶�

	
public:
	//! ����������û��Զ��庯��ָ��
	static CreateUserData m_pCreateUserDataFunc;
	

	//! ���ٶ�����û��Զ��庯��ָ��
	static DestroyUserData m_pDestroyUserDataFunc;

};
	
}

#endif


