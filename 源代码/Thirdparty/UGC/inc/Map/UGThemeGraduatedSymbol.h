// UGThemeGraduatedSymbol.h: interface for the UGThemeGraduatedSymbol class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeGraduatedSymbol.h
   **************************************************************************************
    \author   �¹���
    \brief    �ȼ�����ר��ͼ�ࡣ                                                     
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEGRADUATEDSYMBOL_H__DF2EF891_8B50_4D38_8FF0_440CB02B0055__INCLUDED_)
#define AFX_UGTHEMEGRADUATEDSYMBOL_H__DF2EF891_8B50_4D38_8FF0_440CB02B0055__INCLUDED_

#include "UGThemeSymbol.h"

namespace UGC {

class MAP_API UGThemeGraduatedSymbol : public UGThemeSymbol  
{
public:
	UGThemeGraduatedSymbol();
	virtual ~UGThemeGraduatedSymbol();
	UGThemeGraduatedSymbol(const UGThemeGraduatedSymbol& ThemeGraduatedSymbol);
	UGThemeGraduatedSymbol& operator = (const UGThemeGraduatedSymbol& ThemeGraduatedSymbol);

public:
	//! \brief ר��ͼ�Ƿ���Ч
	virtual UGbool IsValid()const;
	//! \brief ר��ͼ������Ϣ����XML��ʽ
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ж�ȡר��ͼ��Ϣ
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief ����ѯ�ֶ��Ƿ�Ϊ��Ч����
	virtual UGbool CheckFieldType(UGint nType);
	//! \brief ��ȡ��ѯ�ֶ�
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;
	
	//! \brief ��ȡXƫ����
	virtual UGString GetOffsetXFieldName(UGbool bAddExpression = true)const;
	//! \brief ��ȡYƫ����
	virtual UGString GetOffsetYFieldName(UGbool bAddExpression = true)const;

	//! \brief ������ŷ��
	UGbool CalculateSymbolStyle(UGdouble dValue, UGStyle& Style);
	//! \brief ������Ŵ�С
	UGdouble CalculateSymbolSize(UGdouble dValue);

	//! \brief ����Ĭ�ϵȼ����ŷ��
	/**
	\param pDatasetV    ���ݼ�[in]
	\param JoinItems    �ⲿ������[in]
	*/
	UGbool MakeDefault(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems);

	//! \brief �õ��ȼ����Ż�׼ֵ
	UGdouble GetDefinitionValue()const;
	//! \brief ���õȼ����Ż�׼ֵ
	void SetDefinitionValue(UGdouble dValue);

	//! \brief �õ��ȼ����ŷּ���ʽ
	UGint GetGraduatedMode()const;
	//! \brief ���õȼ����ŷּ���ʽ
	void SetGraduatedMode(UGint nGraduatedMode = UGTheme::gmSquareRoot);

	//! \brief ���õȼ������Ƿ���ʾ��ֵ
	void SetEnableNegative(UGbool bEnableNegative = true);
	//! \brief �õ��ȼ������Ƿ���ʾ��ֵ
	UGbool IsEnableNegative()const;

	//! \brief ����ȼ�����ֵ�ļ�ֵ
	/**
	\param pDatasetV       ���ݼ�[in]
	\param JoinItems       �ⲿ������[in]
	\param strFieldName    ���ݼ������ֶ�[in]
	*/
	UGdouble CalculateExtremum(UGDatasetVector* pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString strFieldName);

	//! \brief �õ���ֵ�ķ��
	const UGStyle& GetNegativeStyle()const;
	//! \brief ���ø�ֵ�ķ��
	void SetNegativeStyle(const UGStyle& Style);

	//! \brief �õ���ֵ�ķ��
	const UGStyle& GetPositiveStyle()const;
	//! \brief ������ֵ�ķ��
	void SetPositiveStyle(const UGStyle& Style);

	//! \brief �õ��ֶα��ʽ
	UGString GetExpression()const;
	//! \brief �����ֶα��ʽ
	void SetExpression(const UGString& strExpression);

	//! \brief ��ȡר��ͼ�����hashcode
	virtual UGint GetHashCode() const;

	//! \brief �����Ƿ��ö�
	void SetGraduatedSymbolAlwaysOnTop(UGbool bAlwaysOnTop);
	//! \brief �õ��Ƿ��ö�
	UGbool IsGraduatedSymbolAlwaysOnTop()const;

	//! \brief �õ��Ƿ�֧����ֵ
	UGbool IsEnableZero()const;

	//! \brief �Ƿ�֧����ֵ
	void SetEnableZero(UGbool bEnableZero);

	//! \brief �õ���ֵ�ķ��
	const UGStyle& GetZeroStyle()const;

	//! \brief ������ֵ�ķ��
	void SetZeroStyle(const UGStyle& Style);

	//! \brief �õ�������ֵ�Ĵ�С
	UGdouble GetEpsilon() const;

	//! \brief ���ý�����ֵ�Ĵ�С
	void SetEpsilon(UGdouble dEpsilon);

	UGDict<UGint, UGPoint2D> m_arrCustomSymbol;

protected:  
	void Swap(const UGThemeGraduatedSymbol& theme);

protected:
	UGStyle m_NegativeStyle; 
	UGStyle m_PositiveStyle; 
	UGStyle m_ZeroStyle;
	UGdouble m_dDefinitionValue;
	UGString m_strExpression;
	UGbool m_bAlwaysOnTop;
	double m_dEpsilon;  //����ֶ�ֵ�����ֵС���Ǿ���Ϊ��0ֵ,Ĭ��1e-10;

};

}

#endif // !defined(AFX_UGTHEMEGRADUATEDSYMBOL_H__DF2EF891_8B50_4D38_8FF0_440CB02B0055__INCLUDED_)
