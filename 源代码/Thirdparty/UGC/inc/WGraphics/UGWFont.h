// UGWFont.h: interface for the UGWFont class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGWFont.h 
   **************************************************************************************
    \author   ���������¹���
    \brief    Windows������                                                          
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGWFONT_H__2C01872B_FE49_4DD9_ADD3_4B88CE95D1EC__INCLUDED_)
#define AFX_UGWFONT_H__2C01872B_FE49_4DD9_ADD3_4B88CE95D1EC__INCLUDED_

#include "Graphics/UGFont.h"

namespace UGC
{

class WGRAPHICS_API UGWFont : public UGFont  
{
public:
	UGWFont();
	virtual ~UGWFont();

	// ��������
	virtual UGbool Create();
	
	// �������岢�������������(����,��С,��ʽ,�����).	
	virtual UGbool Create(const UGFontData& FontData);
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
	//! \brief �����Ƿ���÷����� added by dongfei 2007-03-08
	/**
	 *
	 */
	virtual void SetAntiAliasing(UGbool bAntiAliasing);
	
	// ɾ������
	virtual void DeleteObject();
private:
	UGbool m_bNeedRelease;	
};

}

#endif // !defined(AFX_UGWFONT_H__2C01872B_FE49_4DD9_ADD3_4B88CE95D1EC__INCLUDED_)
