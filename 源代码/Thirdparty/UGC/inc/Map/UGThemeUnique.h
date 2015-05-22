// UGThemeUnique.h: interface for the UGThemeUnique class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeUnique.h
   **************************************************************************************
    \author   �¹���
    \brief    ��ֵר��ͼ�ࡣ                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEUNIQUE_H__5C24AD2C_3397_4CF7_89CA_8D10DA408701__INCLUDED_)
#define AFX_UGTHEMEUNIQUE_H__5C24AD2C_3397_4CF7_89CA_8D10DA408701__INCLUDED_

#include "UGThemeStyle.h"
#include "UGThemeItem.h"

namespace UGC {

class MAP_API UGThemeUnique : public UGThemeStyle  
{
public:
	UGThemeUnique();
	virtual ~UGThemeUnique();
	UGThemeUnique(const UGThemeUnique& ThemeUnique);
	UGThemeUnique& operator = (const UGThemeUnique& ThemeUnique);

public:
	//! \brief ר��ͼ�Ƿ���Ч
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
	virtual UGbool CheckFieldType(UGint nType);

	//! \brief ��ȡ��ѯ�ֶ�
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;
	//! \brief ��ȡ��¼����Ӧ�ķ��
	/**
	\param pRecordset ��ѡ�ļ�¼��[in]
	\param Style      ��Ӧ���[in/out]
	*/
	virtual UGbool FindStyle(UGRecordset *pRecordset, UGStyle &Style) const;
	//! \brief ��ȡ�ֶα��ʽ
	UGString GetExpression()const;
	//! \brief �����ֶα��ʽ
	void SetExpression(const UGString& strExpression);

	//! \brief �õ���������Ӧ�Ķ�ֵ
	/**
	\param nIndex ����ֵ[in]
	\return ��Ӧ������ֵ
	*/
	UGString GetValueAt(UGint nIndex)const;
	//! \brief ���ø�������Ӧ�Ķ�ֵ
	/**
	\param nIndex     ����ֵ[in]
	\param strValue   ��Ӧ��ֵ[in]
	*/
	void SetValueAt(UGint nIndex, const UGString& strValue);

	//! \brief �õ���������Ӧ�ķ��
	/**
	\param nIndex     ����ֵ[in]
	\return ��Ӧ�ķ��[in]
	*/
	const UGStyle& GetStyleAt(UGint nIndex )const;
	//! \brief ���ø�������Ӧ�ķ��
	/**
	\param nIndex     ����ֵ[in]
	\param Style      ��Ӧ�ķ��[in]
	*/
	void SetStyleAt(UGint nIndex, const UGStyle& Style);
	
	//! \brief �õ���������Ӧ�ı���
	/**
	\param nIndex     ����ֵ[in]
	\return ������Ӧ�ı���
	*/
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief ���ø�������Ӧ�ı���
	/**
	\param nIndex          ����ֵ[in]
	\param strCaption      ��Ӧ�ı���[in]
	*/
	void SetCaptionAt(UGint nIndex, const UGString& strCaption);

	//! \brief ��������Ӧ�ķ���Ƿ�ɼ�
	/**
	\param nIndex        ����ֵ[in]
	\return    �Ƿ�ɼ�
	*/
	UGbool IsVisibleAt(UGint nIndex)const;
	//! \brief ���ø�������Ӧ�ķ���Ƿ�ɼ�
	/**
	\param nIndex          ����ֵ[in]
	\param bVisible        �Ƿ�ɼ�[in]
	*/
	void SetVisibleAt(UGint nIndex, UGbool bVisible = true);

	//! \brief ����ö�ֵ�Ƿ����
	/**
	\param strValue        ��ֵ[in]
	\return �ö�ֵ�Ƿ����
	*/
	UGbool IsExist(const UGString& strValue)const;
	//! \brief ���Ҷ�Ӧ�Ķ�ֵ���ֶη����Ϣ
	/**
	\param strValue        ��ֵ[in]
	\param ThemeItem       ��Ӧ�����Ϣ[in/out]
	\return ���ز��Ҹö�ֵ�Ƿ�ɹ�
	*/
	UGbool Find(const UGString& strValue, UGThemeItem& ThemeItem) const;
	//! \brief ���Ҷ�Ӧ�Ķ�ֵ���ֶα���
	/**
	\param strValue        ��ֵ[in]
	\param strCaption      ��Ӧ����[in/out]
	\return ���ز��Ҹö�ֵ�Ƿ�ɹ�
	*/
	UGbool FindCaption(const UGString& strValue, UGString& strCaption) const;

	//! \brief ��ȡ������Ӧ�ķ��
	/**
	\param variant    ��ѡ�ı���[in]
	\param Style      ��Ӧ���[in/out]
	\return �������Ϊ-1��Ϊ����ʧ�ܣ����Ϊ0��Ϊ���ҳɹ����÷�񲻿ɼ������Ϊ1��Ϊ���ҳɹ��Ҹ÷��ɼ�
	*/
	UGint FindStyle(const UGVariant& variant, UGStyle &Style) const;
	//! \brief ��ȡ��Ӧ��ֵ�ķ��
	/**
	\param strValue    ��ѡ�Ķ�ֵ[in]
	\param Style       ��Ӧ���[in/out]
	\return �������Ϊ-1��Ϊ����ʧ�ܣ����Ϊ0��Ϊ���ҳɹ����÷�񲻿ɼ������Ϊ1��Ϊ���ҳɹ��Ҹ÷��ɼ�
	*/
	UGint FindStyle(const UGString& strValue, UGStyle &Style) const;
	
	//! \brief �����Ӧ���ݼ��µĸ�����ֵ
	/**
	\param strValue        ��ֵ[in]
	\param JoinItems       ��Ӧ�ⲿ���Ա�[in]
	\param strExpression   �ֶα��ʽ[in]
	\param strValues       �õ��Ķ�ֵ[in/out]
	\param bLimitCount     �Ƿ����ƶθ���[in]
	\return ���ض�ֵ���������Ϊ0���ʾʧ��
	*/
	UGint CalculateUniqueValues(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression, UGArray<UGString>& strValues, UGbool bLimitCount = false);
	
	//! \brief �õ�Ĭ�Ϸ��
	const UGStyle& GetDefaultStyle()const;
	//! \brief ����Ĭ�Ϸ��
	void SetDefaultStyle(const UGStyle& Style);

	//! \brief �õ��������µĶη��
	UGThemeItem GetAt(UGint nIndex)const;
	//! \brief ���ø������µĶη��
	void SetAt(UGint nIndex, const UGThemeItem& ThemeItem);

	//! \brief ���ĳһ����ֶ�
	/**
	\param strValue        ��ֵ[in]
	\param ThemeItem       ��ӷ��[in]
	\return ����Ƿ�ɹ�
	*/
	UGbool Add(const UGString& strValue, const UGThemeItem& ThemeItem);	
	//! \brief ����ĳһ����ֶ�
	/**
	\param nIndex          Ҫ���������[in]
	\param strValue        ��ֵ[in]
	\param ThemeItem       ��ӷ��[in]
	\return �����Ƿ�ɹ�
	*/
	UGbool InsertItem(UGint nIndex, const UGString& strValue, const UGThemeItem& ThemeItem);
	//! \brief �Ƴ�ĳһ����ֶ�
	/**
	\param nIndex          Ҫ�Ƴ�������[in]
	\param nCount          �Ƴ��ĸ���[in]
	\return ʵ���Ƴ��ĸ���
	*/
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief �Ƴ�ĳһ����ֶ�
	/**
	\param strValue          Ҫ�Ƴ��Ķ�ֵ[in]
	\return �Ƴ��Ƿ�ɹ�
	*/
	UGbool Remove(const UGString& strValue);
	
	//! \brief ������ֵλ��
	/**
	\param nIndex1          Ҫ�����Ķ�ֵ1[in]
	\param nIndex2          Ҫ�����Ķ�ֵ2[in]
	\return �����Ƿ�ɹ�
	*/
	UGbool Swap(UGint nIndex1, UGint nIndex2);	
	//! \brief ��ն�ֵ������
	void RemoveAll();

	//! \brief ��ȡ�θ���
	UGint GetCount()const;

	//! \brief �Զ�ֵ��������
	/**
	\param nType          ����ʽ[in]
	\param bDescending    �Ƿ��ս���[in]
	*/
	void Sort(UGint nType, UGbool bDescending = false);
	//! \brief �Ƿ�Ϊ��Ч����
	UGbool IsValidValueCount(UGint nValueCount)const;
	
	//! \brief ��ȡר��ͼ�����hashcode
	virtual UGint GetHashCode() const;
protected:  
	void Swap(const UGThemeUnique& theme);	
	UGRecordset * QueryWithExpression(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression);

protected:
	UGString m_strExpression;
	UGDict<UGString,UGThemeItem> m_UniqueItems;
	UGArray<UGString> m_strKeys;

	UGStyle m_DefaultStyle; 

};

}

#endif // !defined(AFX_UGTHEMEUNIQUE_H__5C24AD2C_3397_4CF7_89CA_8D10DA408701__INCLUDED_)
