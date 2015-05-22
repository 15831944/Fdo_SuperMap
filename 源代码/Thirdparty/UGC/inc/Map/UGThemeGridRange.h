// UGThemeGridRange.h: interface for the UGThemeGridRange class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeGridRange.h
   **************************************************************************************
    \author   �¹���
    \brief    Grid�ֶ�ר��ͼ�ࡣ                                                     
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEGRIDRANGE_H__66F63B7E_2BC1_47BA_8BBA_15B35BDEF0B8__INCLUDED_)
#define AFX_UGTHEMEGRIDRANGE_H__66F63B7E_2BC1_47BA_8BBA_15B35BDEF0B8__INCLUDED_

#include "UGTheme.h"

namespace UGC {

class UGLayer;

class MAP_API UGThemeGridRange : public UGTheme  
{
	friend class UGLayer;

public:
	UGThemeGridRange();
	virtual ~UGThemeGridRange();
	UGThemeGridRange(const UGThemeGridRange& ThemeGridRange);//copy construtor
	UGThemeGridRange& operator = (const UGThemeGridRange& ThemeGridRange);

public:
	//! \brief ר��ͼ�Ƿ���Ч
	virtual UGbool IsValid()const;
	//! \brief ר��ͼ������Ϣ����XML��ʽ
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ж�ȡר��ͼ��Ϣ
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief ��ȡ��ѯ�ֶ�
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;
	
	//! \brief ��ȡ��Χֵ�ĸ���
	virtual UGint GetValueCount()const;

	//! \brief �õ��ֶ��еķ��Χ�ĸ���
	UGint GetCount()const;
	//! \brief �����Χ�ֶ��з������ͷֶ�ֵ����
	void RemoveAll();

	//! \brief  ���ĳ��ֵ
	/**
	\param dValue         ��ֵ[in]
	\return ��ǰר��ͼ�µ����з��ֶεĸ���
	*/
	UGint Add(UGdouble dValue);
	//! \brief  �Ƴ�ĳ��ֵ�ͷ�Χ
	/**
	\param nIndex         �Ƴ��ε�����[in]
	\param nCount         �Ӹ�������ɾ���ĸ���[in]
	\return ɾ���ĸ���
	*/
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief  ����ĳ��ֵ�ͷ�Χ
	/**
	\param nIndex         ����ε�����[in]
	\param dValue         ��ֵ[in]
	\return �����Ƿ�ɹ�
	*/
	UGbool InsertAt(UGint nIndex, UGdouble dValue);

	//! \brief  ����ĳ��ֵ
	UGint Find(UGdouble dValue)const ;
	//! \brief  ����ĳֵ��Ӧ����ɫ
	UGbool FindColor(UGdouble dValue, UGColor& color)const;

	//! \brief �Ƿ���
	UGbool IsDescending()const;			// �Ƿ���
	//! \brief �����Ƿ���
	void SetDescending(UGbool bDescending = false);		// Ĭ������

	//! \brief �õ���nIndex�εı���
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief ���õ�nIndex�εı���
	void SetCaptionAt(UGint nIndex, const UGString& strCaption );

	//! \brief �õ���nIndex�ε���ɫ
	UGColor GetColorAt(UGint nIndex)const;
	//! \brief ���õ�nIndex�ε���ɫ
	void SetColorAt(UGint nIndex, UGColor color);
	
	//! \brief �õ���nIndex�εĶ�ֵ
	UGdouble GetValueAt(UGint nIndex)const;
	//! \brief ���õ�nIndex�εĶ�ֵ
	void SetValueAt(UGint nIndex, UGdouble dValue);

	//! \brief ��nIndex���Ƿ�ɼ�
	UGbool IsVisibleAt(UGint nIndex)const;
	//! \brief ���õ�nIndex���Ƿ�ɼ�
	void SetVisibleAt(UGint nIndex, UGbool bVisible = true);

	//! \brief �ֶ��Ƿ���Ч
	UGbool IsValidValueCount(UGint nValueCount)const;
	//! \brief ���÷ֶη�Χ
	UGbool SetRanges(UGdouble *pValues, UGint nValueCount);

	//! \brief ����Ĭ�Ϸֶ�
	/**
	\param nClassType         �ֶ�����[in]
	\param nClasses           �ֶθ���[in]
	\param dMaxValue          �ֶ����ֵ[in]
	\param dMinValue          �ֶ���Сֵ[in]
	*/
	UGbool MakeDefault(UGint nClassType, UGint nClasses, UGdouble dMaxValue, UGdouble dMinValue, UGdouble dInterval = 0.0);
	//! \brief ����Ĭ����ɫֵ
	void MakeDefaultColors();
	void MakeDefaultColors(UG_ENUM_STOCK_GRADIENT_SET_STYLE nIndex);
	void MakeDefaultColors(UGColor clrStart, UGColor clrEnd);
	//! \brief ����Ĭ�ϱ���
	void MakeDefaultCaptions();

	//! \brief ��ȡר��ͼ�����hashcode
	virtual UGint GetHashCode() const;

	UGColor m_NoDataStyle;

protected:  
	void Swap(const UGThemeGridRange& theme);	
	void ClassifyWithCustomInterval(UGdouble dInterval, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithEqualDistance(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithExtraction(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithLogarithm(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);

protected:
	UGbool m_bDescending;
	UGArray<UGdouble> m_Values;
	UGColorset m_Colors;		//colors
	UGArray<UGbool> m_Visibles;		//Visibles
	UGArray<UGString> m_Captions;	//ÿ����ֵ��Caption

};

}

#endif // !defined(AFX_UGTHEMEGRIDRANGE_H__66F63B7E_2BC1_47BA_8BBA_15B35BDEF0B8__INCLUDED_)
