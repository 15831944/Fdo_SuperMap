// UGThemeGridUnique.h: interface for the UGThemeGridUnique class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeGridUnique.h
   **************************************************************************************
    \author   �¹���
    \brief    Grid��ֵר��ͼ�ࡣ                                                     
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEGRIDUNIQUE_H__8B99A243_9B39_4032_9576_3A33420C55BD__INCLUDED_)
#define AFX_UGTHEMEGRIDUNIQUE_H__8B99A243_9B39_4032_9576_3A33420C55BD__INCLUDED_

#include "Base/UGColorset.h"
#include "UGTheme.h"

namespace UGC {

class MAP_API UGThemeGridUnique : public UGTheme  
{
	friend class UGLayer;
public:
	UGThemeGridUnique();
	virtual ~UGThemeGridUnique();	
	UGThemeGridUnique(const UGThemeGridUnique& ThemeGridUnique);
	UGThemeGridUnique& operator = (const UGThemeGridUnique& ThemeGridUnique);

public:
	//λ��֧��double���͵�grid����dem������ǰ�洢ΪUGint����ΪUGdouble,modified by xielin 2007-08-06
	//! \brief ר��ͼ�Ƿ���Ч
	virtual UGbool IsValid()const;
	//! \brief ר��ͼ������Ϣ����XML��ʽ
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ж�ȡר��ͼ��Ϣ
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief ��ȡ��ѯ�ֶ�
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;

	//! \brief �õ���nIndex�εĶ�ֵ
	UGdouble GetValueAt(UGint nIndex)const;
	//! \brief ���õ�nIndex�εĶ�ֵ
	void SetValueAt(UGint nIndex, UGdouble dValue);

	//! \brief �õ���nIndex�ε���ɫ
	UGColor GetColorAt(UGint nIndex)const;
	//! \brief ���õ�nIndex�ε���ɫ
	void SetColorAt(UGint nIndex, UGColor color);
	
	//! \brief �õ���nIndex�εı���
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief ���õ�nIndex�εı���
	void SetCaptionAt(UGint nIndex, const UGString& strCaption);

	//! \brief ��nIndex���Ƿ�ɼ�
	UGbool IsVisibleAt(UGint nIndex)const;
	//! \brief ���õ�nIndex���Ƿ�ɼ�
	void SetVisibleAt(UGint nIndex, UGbool bVisible = true);
	
	//! \brief ��ȡĬ����ɫ
	UGColor GetDefaultColor()const;
	//! \brief �õ�Ĭ����ɫ
	void SetDefaultColor(UGColor color);

	//! \brief ���ĳ�ֶ�ֵ�ķ����
	UGbool IsExist(UGdouble dValue)const;
	//! \brief ����ĳֵ��Ӧ����ɫ
	UGColor FindColor(UGdouble dValue)const;
	//! \brief ����ĳֵ��Ӧ������
	UGint Find(UGdouble nValue)const;

	
	//UGbool Add(UGint nValue);
	//! \brief  ���ĳ��ֵ
	/**
	\param dValue         ��ֵ[in]
	\return ����Ƿ�ɹ�
	*/
	UGbool Add(UGdouble dValue);
	//UGbool InsertAt(UGint nIndex, UGint nValue);
	//! \brief  ����ĳ��ֵ�ͷ�Χ
	/**
	\param nIndex         ����ε�����[in]
	\param dValue         ��ֵ[in]
	\return �����Ƿ�ɹ�
	*/
	UGbool InsertAt(UGint nIndex, UGdouble dValue);
	//! \brief  �Ƴ�ĳ��ֵ�ͷ�Χ
	/**
	\param nIndex         �Ƴ��ε�����[in]
	\param nCount         �Ӹ�������ɾ���ĸ���[in]
	\return ɾ���ĸ���
	*/
	UGint RemoveAt(UGint nIndex,UGint nCount = 1);	
	//! \brief  ��������������Ӧ��ֵ����ɫ��λ��
	UGbool Swap(UGint nIndex1, UGint nIndex2);	
	//! \brief �����ֵ�ֶ�����ɫ����ͷֶ�ֵ����
	void RemoveAll();
	//! \brief ��ȡ��ֵ����
	UGint GetCount()const;

	//! \brief �Զ�ֵ��������
	/**
	\param bDescending    �Ƿ��ս���[in]
	*/
	void Sort(UGbool bDescending = false);
	//! \brief �Ƿ�Ϊ��Ч����
	UGbool IsValidCount(UGint nCount)const;
	
	//! \brief ����Ĭ�ϱ���
	void MakeDefaultCaptions();
	//! \brief ����Ĭ����ɫ
	void MakeGradientColors(UGColor clrStart, UGColor clrEnd);
	//! \brief ����Ĭ����ɫ
	void MakeDefaultColors();

	//! \brief ��ȡר��ͼ�����hashcode
	virtual UGint GetHashCode() const;

	UGColor m_NoDataStyle;
protected:  
	void Swap(const UGThemeGridUnique& theme);	

protected:
	//�ĳ�double�İɣ�Ҫ֧��double,modified by xielin 2007-08-06
	//UGArray<UGint> m_Values;		//Values
	UGArray<UGdouble> m_Values;
	UGColorset m_Colors;		//colors
	UGArray<UGbool> m_Visibles;		//Visibles
	UGColor m_DefaultColor;			//default color
	UGArray<UGString> m_Captions;		//ÿ����ֵ��Caption

};

}

#endif // !defined(AFX_UGTHEMEGRIDUNIQUE_H__8B99A243_9B39_4032_9576_3A33420C55BD__INCLUDED_)
