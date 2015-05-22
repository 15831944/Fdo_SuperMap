/*! \file	 UGImgScanline.h
 *  \brief	 ɨ�����ඨ���ļ�
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGImgScanline.h,v 1.6 2005/03/31 01:33:59 aiguo Exp $
 */

#ifndef UGIMGSCANLINE_H
#define UGIMGSCANLINE_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Base/UGToolkit.h"

namespace UGC {


//! ɨ������

//=======================================================
//{{ Modified by GUOQC at [2005-02-23 09:56:08]
// * �޸�ԭ�򼰱�Ҫ˵��	
//���m_data��Ϊ��Ա���ܶ����array��ʹ�þͲ����㣬�����������ֱ�ӵ���getdata��setsize֮��Ķ���
//�ĸ�sfc�е����һ������array�̳�

class GEOMETRY_API UGImgScanline:public UGArray<UGuchar>
{
public:
	//! ���캯��
	UGImgScanline();
	
	//! ��������
	~UGImgScanline();
	
	//! ��������BYTE˳�򽻻�
	void SwapBlueRed();	
	
	//! �����ҵ�BYTE˳�򽻻�
	void SwapLeftRight();
	
	//! ����Pixel
	UGbool SetPixel(UGint x,UGint nPixel);
	
	//! ��ȡPixel
	UGint GetPixel(UGint x);
	
	//! ����Value
	UGbool SetValue(UGint x,UGdouble dValue);
	
	//! ��ȡValue
	UGdouble GetValue(UGint x);

	//! ��ȡ���ظ�ʽ
	PixelFormat GetPixelFormat() const {return m_ePixelFormat;}

	//! �������ظ�ʽ
	void SetPixelFormat(const PixelFormat ePixelFormat){m_ePixelFormat = ePixelFormat;}

	//! ��ȡɨ������ռ�ֽ���
	UGint GetWidthBytes() const
	{
		return (m_nWidth*UGToolkit::GetBitCount(m_ePixelFormat)+7)/8;
	}

	//! ����ɨ������ռ�ֽ���
	void SetWidthBytes(const UGint nNewSize)
	{
		SetSize(nNewSize);
	}


	//! ��ȡɨ���߿��
	UGint GetWidth() const {return m_nWidth;}

	//! ����ɨ���߿��
	void SetWidth(const UGint nWidth) {m_nWidth = nWidth;}
		
private:
	//! ���ظ�ʽ
	PixelFormat m_ePixelFormat;

	//! ɨ���߿��
	UGint m_nWidth;
};
//}} Modified by GUOQC at [2005-02-23 09:56:08]
//=======================================================

}

#endif


