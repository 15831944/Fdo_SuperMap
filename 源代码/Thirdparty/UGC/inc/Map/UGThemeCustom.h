// UGThemeCustom.h: interface for the UGThemeCustom class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeCustom.h
   **************************************************************************************
    \author   �¹���
    \brief    �Զ���ר��ͼ�ࡣ                                                        
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMECUSTOM_H__D7DEC1A3_106F_4EB3_806F_FA190E338AE4__INCLUDED_)
#define AFX_UGTHEMECUSTOM_H__D7DEC1A3_106F_4EB3_806F_FA190E338AE4__INCLUDED_

#include "UGThemeStyle.h"

namespace UGC {

class MAP_API UGThemeCustom : public UGThemeStyle  
{
public:
	UGThemeCustom();
	virtual ~UGThemeCustom();
	UGThemeCustom(const UGThemeCustom& ThemeCustom);
	UGThemeCustom& operator = (const UGThemeCustom& ThemeCustom);

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
	//! \brief ����Զ���ר��ͼ��Ϣ
	void SetEmpty();	

	//! \brief ��ȡ������ֶε�������Ϣ������ŷ�񣬴�С���Ƕȣ���ɫ��
	UGbool GetMarkerFieldName(UGArray<UGString>& strArray)const; 
	//! \brief ��ȡ���η����ֶε�������Ϣ������ŷ���߿���ɫ��
	UGbool GetLineFieldName(UGArray<UGString>& strArray)const;
	//! \brief ��ȡ���η����ֶε�������Ϣ�������ǰ��ɫ��͸���������
	UGbool GetFillFieldName(UGArray<UGString>& strArray)const;	

	//! \brief ���Ҷ�Ӧ��¼���ķ��
	virtual UGbool FindStyle(UGRecordset *pRecordset, UGStyle &Style)const;	

	//! \brief ��ȡר��ͼ�����hashcode
	virtual UGint GetHashCode() const;
	
protected:  
	void Swap(const UGThemeCustom& theme);
	UGbool GetFieldValue(const UGString& strFieldName, UGRecordset *pRecordset, UGdouble &dValue)const;
	
public:
	UGString m_strMarkerStyle;		
	UGString m_strMarkerSize;	
	UGString m_strMarkerAngle;	

	UGString m_strLineStyle;		
	UGString m_strLineWidth;		
	UGString m_strLineColor;		

	UGString m_strFillStyle;	
	UGString m_strFillForeColor;	
	UGString m_strFillBackColor;	
	UGString m_strFillOpaqueRate;	
	UGString m_strFillGradientType;
	UGString m_strFillAngle;		
	UGString m_strFillCenterOffsetX;
	UGString m_strFillCenterOffsetY;

};

}

#endif // !defined(AFX_UGTHEMECUSTOM_H__D7DEC1A3_106F_4EB3_806F_FA190E338AE4__INCLUDED_)
