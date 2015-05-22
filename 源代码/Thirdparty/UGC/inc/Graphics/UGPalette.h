
/*!
   **************************************************************************************
    \file     UGPalette.h
   **************************************************************************************
    \author   �¹���
    \brief    ��ɫ����                                                               
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#ifndef UGPALETTE_H
#define UGPALETTE_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"

namespace UGC {

class GRAPHICS_API UGPalette
{
public:
	struct UGPaletteEntry  //! \brief һ����ɫ����Ϣ
	{
		UGbyte peRed;      //! \brief ��ɫ�ı���
		UGbyte peGreen;    //! \brief ��ɫ�ı���
		UGbyte peBlue;     //! \brief ��ɫ�ı���
		UGbyte peFlags;    //! \brief ��ʶ��
		
		UGPaletteEntry()
		{		
			peRed = 0;
			peGreen = 0;
			peBlue = 0;
			peFlags = 0;
		}
	};

public:
	UGPalette();
	~UGPalette();
	
public:
	//! \brief ���ҵ�ɫ���λ��
	//! \param paletteEntry Ҫ���ҵĵ�ɫ��
	//! \return �����ҵ��ĵ�ɫ���λ�ã��Ҳ������� -1
	UGint Find(UGPaletteEntry paletteEntry) const;
    //! \brief ������������һ����ɫ��
	//! \param paletteEntry Ҫ��ӵĵ�ɫ��
	//! \return ������Ӻ�,��ɫ���������е�λ��
	UGint Add(UGPaletteEntry paletteEntry);
	//! \brief ���������Ƴ���ɫ��
	//! \param nIndex Ҫ�Ƴ��ĵ�ɫ���������λ��
	//! \remarks ָ��λ�ñ��������鷶Χ��
	//! \param nCount �Ƴ��ĸ���,Ĭ��Ϊ1
	//! \return ����ʵ���Ƴ����ĸ���
	//! \remarks ��� nCount>UGArray.size-nIndex ����  nCount>UGArray.size-nIndex
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief ������ָ��λ�ò���һ����ɫ��
	//! \remarks ���ָ��λ�ò������鷶Χ��,���Զ�������[0,size]
	//! \param nIndex Ҫ�����λ��
	//! \param paletteEntry Ҫ����ĵ�ɫ��
	void InsertAt(UGint nIndex, UGPaletteEntry paletteEntry);
	//! \brief �������ָ��λ���滻��ɫ��
	//! \param nIndex ָ����λ��
	//! \remarks ָ��λ�ñ���������size��Χ֮��
	//! \param paletteEntry Ҫ�滻�ĵ�ɫ��
	void SetAt(UGint nIndex, UGPaletteEntry paletteEntry);
    //! \brief ��ȡָ��λ�õĵ�ɫ��
	//! \param nIndex ָ����λ��
	//! \remarks ָ��λ�ñ���������size��Χ֮��
	//! \return ���ػ�õĵ�ɫ��
	UGPaletteEntry GetAt(UGint nIndex)const;
    //! �Ƴ�����Ԫ��,ͬʱ������пռ�
	void RemoveAll();
	//! \brief �õ������ڲ�ָ��(��ַ����)
	//! \return ���������ڲ�ָ��(��ַ����) 
	UGPaletteEntry* GetData();
	//! \brief �������������һ������
	//! \brief palette Ҫ���ӵ�����
	//! \return ���ؼ����������ʼλ��
	UGint Append(const UGPalette& palette);
	//! \brief ���鿽��,ԭ�������ݱ�����
	//! \param palette ���������
	void Copy(const UGPalette& palette);
	//! \brief ����m_Palette���ڴ�ռ�Ϊ nSize, 
	//! \remarks ���ԭ�пռ䲻��, �ڴ�ռ������, 
	//! \param nSize ָ�����µĵ�ɫ�����
	void SetSize(UGint nSize);
	//! \brief �õ����õĵ�ɫ��ĸ���
	//! \return ���صĵ�ɫ��ĸ���
	UGint GetSize()const;
	//! \brief �ж������Ƿ�Ϊ��
	//! \return ����շ��� true,���򷵻� false.
	UGbool IsEmpty()const;

protected:
	//! \brief ����ɫ��������ʵ��
	UGArray<UGPaletteEntry> m_Palette;	

};

}

#endif


