// UGFillSymParam.h: interface for the UGFillSymParam class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGFillSymParam.h
   **************************************************************************************
    \author   �¹���
    \brief    �����Ų�����                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-23  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGFILLSYMPARAM_H__FD7DA634_1368_40D9_80A9_6593E14331D4__INCLUDED_)
#define AFX_UGFILLSYMPARAM_H__FD7DA634_1368_40D9_80A9_6593E14331D4__INCLUDED_

#include "Algorithm/UGSize2D.h"
#include "Graphics/UGGraphics.h"

namespace UGC {

class UGFillSymbol;
class UGMarkerSymbolLib;

class SYMBOL_API UGFillSymParam  
{
public:
	UGFillSymParam();
	virtual ~UGFillSymParam();

public:
	//! ��������ʾʱ�Ĵ�С�����ΪUGSize(0,0)����Ĭ�ϴ�С
	UGSize2D GetSize() const;
	void SetSize(const UGSize2D& size);

	//! ��������ʾʱ�ı���ɫ��
	UGColor GetBackColor() const;
	void SetBackColor(UGColor color);

	//! ��������ʾʱ��ǰ��ɫ��
	UGColor GetForeColor() const;
	void SetForeColor(UGColor color);

	//! ��������ʾʱ�����ű�����
	UGdouble GetScale() const;
	void SetScale(UGdouble dScale);

	//! ��������ʾʱ�Ƿ񱳾���͸����
	UGbool IsBackOpaque() const;
	void SetBackOpaque(UGbool bOpaque);
	
	//! �����ţ�
	UGFillSymbol* GetFillSymbol() const;
	void SetFillSymbol(UGFillSymbol *pFillSymbol);
	
	//! ������ʹ�õ��ĵ�״���ſ⣻
	UGMarkerSymbolLib* GetMarkerSymbolLib() const;
	void SetMarkerSymbolLib(UGMarkerSymbolLib *pMarkerSymLib);
	
	//! ��������ʾʱλͼ��ʱ�Ļ��棻
	const UGImage* GetImageAnd() const;	
	const UGImage* GetImageOr() const;
	const UGImage* GetImage() const;

	//! ����λͼ��ʱ���棻
	UGbool Create(UGGraphics& graphics);
	UGbool Create(UGGraphics& graphics, 
			UGFillSymbol *pFillSymbol,			
			UGMarkerSymbolLib *pPointSymLib,
			UGColor clrFore = UGRGB(0,0,0),
			UGColor clrBack = UGRGB(255,255,255),
			const UGSize2D& size = UGSize2D(0.0,0.0),
			UGdouble dScale = 1.0,
			UGbool bBackOpaque = true,
			UGbyte btOpaqueRate = 100);
	//! �ͷ���ʱ���棻
	void Release();

	//! ���㻺�棻
	UGRect PreProcessPoints(UGGraphics& graphics, const UGPoint* pPoints, UGint nCount);
	const UGPoint* GetPointsBuf() const;
	UGint GetPointsBufSize() const;

	//! ���͸����
	UGbyte GetOpaqueRate() const;
	void SetOpaqueRate(UGbyte btOpaqueRate);

protected:
	//! ���ģʽ��ʾʱ�Ĵ�С��
	UGSize2D m_szSize;	
	//! ���ģʽ��ʾʱ�ı���ɫ��
	UGColor m_clrBack;	
	//! ���ģʽ��ʾʱ��ǰ��ɫ��
	UGColor m_clrFore;		

	//!  ������ű���
	UGdouble m_dScale;

	//! ͸����ʾʱ�����õ�Image
	UGImage* m_pImageAnd;			
	//! ͸����ʾʱ�����õ�Image
	UGImage* m_pImageOr;		
	//! ����ָ��ǰ����ɫ��Image
	UGImage*  m_pImage;		

	UGbool m_bBackOpaque;
	UGbyte m_btOpaqueRate;

	UGFillSymbol* m_pFillSymbol;
	UGMarkerSymbolLib* m_pMarkerSymLib;

	UGPoint* m_pPoints;
	UGint m_nPntCount;

};

}

#endif // !defined(AFX_UGFILLSYMPARAM_H__FD7DA634_1368_40D9_80A9_6593E14331D4__INCLUDED_)
