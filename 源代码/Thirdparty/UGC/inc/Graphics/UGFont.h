// UGFont.h: interface for the UGFont class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGFont.h  
   **************************************************************************************
    \author   ���������¹���
    \brief    �������                                                                 
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGFONT_H__93BF2531_3AD2_4B27_ACA8_BBB861E6150E__INCLUDED_)
#define AFX_UGFONT_H__93BF2531_3AD2_4B27_ACA8_BBB861E6150E__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGTextCodec.h"
#include "Base/UGTextStyle.h"

namespace UGC
{

class GRAPHICS_API UGFont  
{
public:

	struct UGFontData
	{		
		UGint nHeight;
		UGint nWidth;
		UGint nWeight;
		UGint nAngle;
		UGbool bBold;
		UGbool bItalic;
		UGbool bUnderline;
		UGbool bStrikeOut;
		UGbool bHalo;
		UGbool bShadow;
		UGint nItalicAngle;
		UGTextCodec::Charset nCharset;
		UGString strName;

		UGFontData()
		{					
			nHeight = 40;
			nWidth = 0;
			nWeight = 0;
			nAngle = 0;
			bBold = false;
			bItalic = false;
			bUnderline = false;
			bStrikeOut = false;
			bHalo = false;
			bShadow = false;
			nItalicAngle = 0;
			nCharset = UGTextCodec::Default;		
			strName = ("");
		}
	};

protected:
	UGFont();
public:
	virtual ~UGFont();

	//! \brief ��������
	virtual UGbool Create() = 0;
	
	//! \brief �������岢�������������(����,��С,��ʽ,�����).	
	virtual UGbool Create(const UGTextStyle& style, UGint nFontHeight, 
		UGint nFontWidth, UGint nAngle, UGuint nCharset);
	//! \brief ����UGFontData�ṹ��������
	virtual UGbool Create(const UGFontData& FontData);
	//! \brief ����һЩ���������������
	virtual UGbool Create(const UGString& strName,
					   UGint nHeight = 40, 
					   UGint nWidth = 0,
	                   UGint nWeight = 0, 
					   UGint nAngle = 0, 
	                   UGbool bBold = false, 
					   UGbool bItalic = false,
					   UGint nItalicAngle = 0,
	                   UGbool bUnderline = false, 
					   UGbool bStrikeOut = false,
					   UGbool bHalo = false, 
					   UGbool bShadow = false,
					   UGTextCodec::Charset nCharset = UGTextCodec::GB18030);
	
	//! \brief ɾ������
	virtual void DeleteObject() = 0;

	//! \brief ��ȡ�������Խṹ
	virtual void GetFontData(UGFontData& FontData);

	//! \brief ��ȡ��������
	virtual UGint GetWeight() const;
	//! \brief ������������
	virtual void SetWeight(UGint nWeight);

	//! \brief ��ȡ������б�Ƕ�
	virtual UGdouble GetItalicAngle() const;
	//! \brief ����������б�Ƕ�
	virtual void SetItalicAngle(UGdouble nItalicAngle);

	//! \brief ��ȡ������
	virtual UGString GetName() const;
	//! \brief ����������
	virtual void SetName(const UGString& strName);

	//! \brief ��ȡ����߶�
	virtual UGint GetHeight() const;	
	//! \brief ��������߶�
	virtual void SetHeight(UGint nHeight);

	//! \brief ��ȡ������
	virtual UGint GetWidth() const;	
	//! \brief ����������
	virtual void SetWidth(UGint nWidth);

	//! \brief ��ȡ�������ת�Ƕ�
	virtual UGint GetAngle() const;
	//! \brief ����������ת�Ƕ�
	virtual void SetAngle(UGint nAngle);

	//! \brief �жϵ�ǰ�����Ƿ��Ǵ���
	virtual UGbool IsBold() const;	
	//! \brief ��������Ϊ����
	virtual void SetBold(UGbool bBold);

	//! \brief �жϵ�ǰ�����Ƿ���б��
	virtual UGbool IsItalic() const;
	//! \brief ��������Ϊб��
	virtual void SetItalic(UGbool bItalic);

	//! \brief �жϵ�ǰ�����Ƿ�����»���
	virtual UGbool IsUnderline() const;
	//! \brief ����������»���
	virtual void SetUnderline(UGbool bUnderline);

	//! \brief �жϵ�ǰ�����Ƿ����ɾ����
	virtual UGbool IsStrikeOut() const;
	//! \brief ���������ɾ����
	virtual void SetStrikeOut(UGbool bStrikeOut);

	//! \brief �жϵ�ǰ�����Ƿ����������
	virtual UGbool IsHalo() const;
	//! \brief ���������������
	virtual void SetHalo(UGbool bHalo);

	//! \brief �жϵ�ǰ�����Ƿ������Ӱ
	virtual UGbool IsShadow() const;
	//! \brief �������������Ӱ
	virtual void SetShadow(UGbool bShadow);

	//! \brief ��ȡ�������
	virtual UGTextCodec::Charset GetCharset() const;
	//! \brief �����������
	virtual void SetCharset(UGTextCodec::Charset nCharset);	
	
	//! \brief ��ȡʵ�ʶ���
	void* GetNative() const;
	//! \brief ����ʵ�ʶ���
	void SetNative(void* pNative);
	//! \brief ��ȡ��ʾ��������
	virtual UGint GetGraphicsType();

	//! \brief ����/�����Ƿ���÷����� added by dongfei 2007-03-08
	/*
	 *	
	 */
	virtual void SetAntiAliasing(UGbool bAntiAliasing);
	virtual UGbool IsAntiAliasing();
	
protected:
	UGFontData m_FontData;
	void* m_pNative;

	UGint m_nGraphicsType;	
	UGbool m_bAntiAliasing;		//�Ƿ���÷����� added by dongfei 2007-03-08
};
}
#endif // !defined(AFX_UGFONT_H__93BF2531_3AD2_4B27_ACA8_BBB861E6150E__INCLUDED_)
