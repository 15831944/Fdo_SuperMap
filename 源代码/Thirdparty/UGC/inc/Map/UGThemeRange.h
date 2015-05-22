// UGThemeRange.h: interface for the UGThemeRange class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeRange.h
   **************************************************************************************
    \author   �¹���
    \brief    �ֶ�ר��ͼ�ࡣ                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMERANGE_H__1E880B1F_F87E_4E5A_A46F_D02EFD663CF0__INCLUDED_)
#define AFX_UGTHEMERANGE_H__1E880B1F_F87E_4E5A_A46F_D02EFD663CF0__INCLUDED_

#include "UGThemeStyle.h"
#include "UGThemeItem.h"

namespace UGC {

class UGLayer;

class MAP_API UGThemeRange : public UGThemeStyle  
{
public:
	UGThemeRange();
	virtual ~UGThemeRange();
	UGThemeRange(const UGThemeRange& ThemeRange);//copy construtor
	UGThemeRange& operator = (const UGThemeRange& ThemeRange);

public:
	//! \brief ר��ͼ�Ƿ���Ч
	/**
	*/
	virtual UGbool IsValid()const;
	//! \brief ר��ͼ������Ϣ����XML��ʽ
	/**
	*/
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ж�ȡר��ͼ��Ϣ
	/**
	*/
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief ����ѯ�ֶ��Ƿ�Ϊ��Ч����
	/**
	*/
	virtual UGbool CheckFieldType(UGint nType);
	//! \brief ��ȡ��ѯ�ֶ�
	/**
	*/
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;
	//! \brief ��ȡ��Χֵ�ĸ���
	/**
	*/
	virtual UGint GetValueCount()const;
	//! \brief ����Recordset��Ӧ�ķ��
	/**
	*/
	virtual UGbool FindStyle(UGRecordset *pRecordset, UGStyle &Style)const;

	//! \brief �õ��ֶ��еķ��Χ�ĸ���
	/**
	*/
	UGint GetCount()const;
	//! \brief �����Χ�ֶ��з������ͷֶ�ֵ����
	/**
	*/
	void RemoveAll();

	//! \brief  ���ĳ��ֵ�ͷ�Χ
	/**
	\param dValue         ��ֵ[in]
	\param ThemeItem      �öεķ��[in]
	\return ��ǰר��ͼ�µ����з��ֶεĸ���
	*/
	UGint Add(UGdouble dValue, const UGThemeItem& ThemeItem);
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
	\param ThemeItem      �ö��µķֶη��[in]
	\return �����Ƿ�ɹ�
	*/
	UGbool InsertAt(UGint nIndex, UGdouble dValue, const UGThemeItem& ThemeItem);

	//! \brief  �ҵ���ֵ��Ӧ������
	/**
	\param dValue         ��ֵ[in]
	\return ����ɹ���Ϊ��ֵ��Ӧ�����������򷵻�-1
	*/
	UGint Find(UGdouble dValue)const;
	//! \brief  �ҵ���ֵ��Ӧ�ķ�Χ�µķ��
	/**
	\param dValue         ��ֵ[in]
	\param Style          ��Ӧ�ķ��[in/out]
	\return �Ƿ��ҵ���Ӧֵ�ķ��
	*/
	UGbool FindStyle(UGdouble dValue, UGStyle& Style)const;

	//! \brief  �����Ӧ���ݼ��µĶ�ֵ
	/**
	\param pDatasetV         ���ݼ�[in]
	\param strExpression     ���ʽ[in]
	\param arrValues         ��ֵ[in/out]
	\return �����Ƿ�ɹ�
	*/
	UGbool CalculateExtremum(UGDatasetVector* pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression, UGArray<UGdouble>& arrValues);
	
	//! \brief �õ��������ʽ
	/**
	*/
	UGString GetExpression()const;			//�õ��������ʽ,�������ֶ����ƻ���ʽ
	//! \brief �����������ʽ
	/**
	*/
	void SetExpression(const UGString& strExpression);

	//! \brief �Ƿ���
	/**
	*/
	UGbool IsDescending()const;			// �Ƿ���
	//! \brief �����Ƿ���
	/**
	*/
	void SetDescending(UGbool bDescending = false);		// Ĭ������

	//! \brief �õ���nIndex�ε���Ϣ
	/**
	*/
	UGThemeItem GetAt(UGint nIndex)const;
	//! \brief �õ���nIndex�ε���Ϣ
	/**
	*/
	void SetAt(UGint nIndex, const UGThemeItem& ThemeItem);

	//! \brief �õ���nIndex�εı���
	/**
	*/
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief ���õ�nIndex�εı���
	/**
	*/
	void SetCaptionAt(UGint nIndex, const UGString& strCaption );

	//! \brief �õ���nIndex�εķ��
	/**
	*/
	const UGStyle& GetStyleAt(UGint nIndex)const;
	//! \brief ���õ�nIndex�εķ��
	/**
	*/
	void SetStyleAt(UGint nIndex, const UGStyle& Style);
	
	//! \brief �õ���nIndex�εĶ�ֵ
	/**
	*/
	UGdouble GetValueAt(UGint nIndex)const;
	//! \brief ���õ�nIndex�εĶ�ֵ
	/**
	*/
	void SetValueAt(UGint nIndex, UGdouble dValue);

	//! \brief ��nIndex���Ƿ�ɼ�
	/**
	*/
	UGbool IsVisibleAt(UGint nIndex)const;
	//! \brief ���õ�nIndex���Ƿ�ɼ�
	/**
	*/
	void SetVisibleAt(UGint nIndex, UGbool bVisible = true);

	//modified by xilin 2007-07-10 ���������װ��ʱ���봫��UGLayer���޸�һ�½ӿ�����
	//UGbool MakeDefault(UGint nClassType, UGint nClasses, const UGArray<UGdouble> &aryValues, UGdouble dInterval = 0.0, UGLayer* pLayer = NULL);
	//! \brief ����Ĭ�Ϸֶ�
	/**
	\param nClassType         �ֶ�����[in]
	\param nClasses           �ֶθ���[in]
	\param aryValues          �ֶ�ֵ[in]
	\param dInterval          �Զ���ֶεķ�Χ[in]
	\param pDv                ��Ӧ���ݼ�[in]
	\param pQueryDef          ��ѯ����[in]
	*/
	UGbool MakeDefault(UGint nClassType, UGint nClasses, const UGArray<UGdouble> &aryValues, UGdouble dInterval = 0.0, UGDatasetVector* pDv = NULL,UGQueryDef* pQueryDef = NULL);
	//! \brief ����Ĭ�ϱ���
	void MakeDefaultCaptions();
	//! \brief ����Ĭ�Ϸ��
	void MakeDefaultStyles(UG_ENUM_STOCK_GRADIENT_SET_STYLE nIndex);

	//! \brief ���÷ֶη�Χ
	/**
	*/
	UGbool SetRanges(UGdouble *pValues, UGint nValueCount);
	//! \brief �ֶ��Ƿ���Ч
	/**
	*/
	UGbool IsValidValueCount(UGint nValueCount)const;
	
	//! \brief ��ȡר��ͼ�����hashcode
	virtual UGint GetHashCode() const;
protected:  
	void Swap(const UGThemeRange& theme);	
	UGRecordset * QueryWithExpression(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression);
	void ClassifyWithCustomInterval(UGdouble dInterval, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithEqualDistance(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithExtraction(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void Stdev(const UGArray<UGdouble> &arySrc, UGdouble &dMean, UGdouble &dStdev);
	void ClassifyWithStdev(const UGArray<UGdouble> &arySrc);
	void ClassifyWithLogarithm(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	//modified by xilin 2007-07-10 ���������װ��ʱ���봫��UGLayer���޸�һ�½ӿ�����
	//void ClassifyWithQuantile(UGint nClasses, UGint nKeyCount, UGLayer* pLayer);
	void ClassifyWithQuantile(UGint nClasses, UGint nKeyCount, UGDatasetVector* pDv,UGQueryDef* pQueryDef);

protected:
	UGString m_strExpression;
	UGbool m_bDescending;
	UGArray<UGdouble> m_Values;
	UGArray<UGThemeItem> m_RangeItems;

};

}

#endif // !defined(AFX_UGTHEMERANGE_H__1E880B1F_F87E_4E5A_A46F_D02EFD663CF0__INCLUDED_)
