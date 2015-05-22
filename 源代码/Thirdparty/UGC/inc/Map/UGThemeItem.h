// UGThemeItem.h: interface for the UGThemeItem class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeItem.h
   **************************************************************************************
    \author   �¹���
    \brief    ר��ͼ���Ҫ���ڵ�ֵ�ͷֶ�ר��ͼ��                                                               
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEITEM_H__B60FB9DA_DCD4_4ACE_BE9C_59A5F2EE2E39__INCLUDED_)
#define AFX_UGTHEMEITEM_H__B60FB9DA_DCD4_4ACE_BE9C_59A5F2EE2E39__INCLUDED_

#include "Base/UGString.h"
#include "Base/UGStyle.h"

namespace UGC {

class MAP_API UGThemeItem  
{
public:
	UGThemeItem();
	virtual ~UGThemeItem();
	UGThemeItem(const UGThemeItem& ThemeItem);
	UGThemeItem& operator = (const UGThemeItem& ThemeItem);

public:
	UGbool m_bVisible;				//�ɼ�
	UGString m_strCaption;			//����
	UGStyle m_Style;				//���

};

}

#endif // !defined(AFX_UGTHEMEITEM_H__B60FB9DA_DCD4_4ACE_BE9C_59A5F2EE2E39__INCLUDED_)
