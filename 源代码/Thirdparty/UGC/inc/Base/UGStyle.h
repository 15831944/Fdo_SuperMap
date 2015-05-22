
/*!
   **************************************************************************************
    \file     UGStyle.h 
   **************************************************************************************
    \author   �¹���
    \brief    ���η����                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-07-06  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#ifndef UGSTYLE_H
#define UGSTYLE_H

#include "UGString.h"

namespace UGC {

typedef enum tagBrushGradientMode
{
	scbGradientNone	= 0,
	scbGradientLinear	= 1,	
	scbGradientRadial	= 2,
	scbGradientConical	= 3,
	scbGradientSquare	= 4,
		
}UGBrushGradientMode;

class UGStream;

class BASE_API UGStyle  
{
public:
	UGStyle();
	void operator = (const UGStyle &style);
	UGbool operator == (const UGStyle &style) const;
	UGbool operator != (const UGStyle &style) const;

public:	
	//! \brief �õ��洢��Ҫ��size
	static UGint GetStoreSize();
	static UGString ConvertRGBColor(UGColor crRGB);
	static UGColor ConvertRGBColor(const UGString& strRGB);
	static UGbool IsSameFillStyle(const UGStyle &style1, const UGStyle &style2);
	static UGbool IsSameLineStyle(const UGStyle &style1, const UGStyle &style2);
	static UGbool IsSameMarkerStyle(const UGStyle &style1, const UGStyle &style2);
	static UGbool IsSameDimensionStyle(const UGStyle &style1, const UGStyle &style2, UGint nDimension); 

	//! \brief ��䱳��ɫ
	UGColor GetFillBackColor() const;
	void SetFillBackColor(UGColor color);
	
	//! \brief ���ǰ��ɫ
	UGColor GetFillForeColor() const;
	void SetFillForeColor(UGColor color);
	
	//! \brief �����
	UGint GetFillStyle() const;
	void SetFillStyle(UGint nFillStyle);
	
	//! \brief ������ɫ
	UGColor GetLineColor() const;
	void SetLineColor(UGColor color);

	//! \brief ��������
	UGint GetLineStyle() const;
	void SetLineStyle(UGint nLineStyle);
	
	//! \brief ���Ϳ��
	UGdouble GetLineWidth() const;
	void SetLineWidth(UGdouble dLineWidth);
	
	//! \brief ���ŽǶ�
	UGdouble GetMarkerAngle() const;
	void SetMarkerAngle(UGdouble dMarkerAngle);

	//! \brief ���Ŵ�С
	UGdouble GetMarkerSize() const;
	void SetMarkerSize(UGdouble dMarkerSize);

	//! \brief ���ŷ��
	UGint GetMarkerStyle() const;
	void SetMarkerStyle(UGint nMarkerStyle);

	//! \brief ��䱳����͸��
	UGbool GetFillBackOpaque() const;
	void SetFillBackOpaque(UGbool bOpaque);

	//! \brief ��䲻͸����
	UGbyte GetFillOpaqueRate() const;
	void SetFillOpaqueRate(UGbyte btFillOpaqueRate);

	//! \brief ��佥������
	UGbyte GetFillGradientType() const;
	void SetFillGradientType(UGbyte btGradientType);

	//! \brief ���Ƕ�
	UGdouble GetFillAngle() const;
	void SetFillAngle(UGdouble dFillAngle);

	//! \brief ��佥������X����ƫ��
	UGshort GetFillCenterOffsetX() const;
	void SetFillCenterOffsetX(UGshort nFillCenterOffsetX);

	//! \brief ��佥������Y����ƫ��
	UGshort GetFillCenterOffsetY() const;
	void SetFillCenterOffsetY(UGshort nFillCenterOffsetY);

	//! \brief Load Style
	//! \remarks ���Զ�ȡ 30 �� 50 �ķ��
	UGbool LoadAll(UGStream& stream, UGint nStyleSize);
	//! \brief Save Style
	//! \remarks ֻ֧��50�Ĵ洢
	//! \return ���ر����style��size
	void SaveAll(UGStream& stream) const;
	UGint Load(UGStream& stream, UGint nDimension);
	void Save(UGStream& stream, UGint nDimension) const;

	UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	UGString ToXML(UGint nVersion = 0, const UGString& strElemName = ("")) const;
	//! \brief ���÷��ŵ����ű���ϵ�����շ��ű����Ƿ��ŵı߿�(255,255)
	//! \param bSymbolScale ��Ϊ���� ��Ϊ�߿�
	void SetScaleBySymbol(UGbool bSymbolScale)
	{
		m_bSymbolScale = bSymbolScale;
	}
	UGbool IsScaleBySymbol() const
	{
		return m_bSymbolScale;
	}

	//! \brief ��ȡ�������hashcode
	UGint GetHashCode() const;
private:	
	UGint m_nMarkerStyle;
	UGint m_nMarkerAngle;		//��λ��0.1��
	UGint m_nMarkerSize;

	UGint m_nLineStyle;
	UGColor m_LineColor;
	UGint m_nLineWidth;
	
	UGint m_nFillStyle;
	UGColor m_FillBackColor;
	UGColor m_FillForeColor;
	UGbool m_bFillBackOpaque;
	UGbyte m_btFillOpaqueRate;
	UGbyte m_btFillGradientType;	
	UGshort m_nFillAngle;		//��λ��0.1��
	UGshort m_nFillCenterOffsetX;
	UGshort m_nFillCenterOffsetY;
	
	UGbool	m_bSymbolScale;		//����ŵ�Size��Symbol��size���Ǳ߿�(255,255)��size
								//TRUE Symbol��size 
								//FALSE �߿� dongfei adds 2007-03-29
};

}

#endif
