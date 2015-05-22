// UGThemeStyle.h: interface for the UGThemeStyle class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeStyle.h
   **************************************************************************************
    \author   �¹���
    \brief    ���ר��ͼ�࣬����ֻ�Ǹı�������ר��ͼ������������                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMESTYLE_H__EEA9B655_2AD0_4829_A149_D239AE00A9B4__INCLUDED_)
#define AFX_UGTHEMESTYLE_H__EEA9B655_2AD0_4829_A149_D239AE00A9B4__INCLUDED_

#include "UGTheme.h"

namespace UGC {

class MAP_API UGThemeStyle : public UGTheme  
{
public:
	UGThemeStyle();
	virtual ~UGThemeStyle();

public:
	virtual UGbool FindStyle(UGRecordset *pRecordset, UGStyle &Style)const = 0;

};

}

#endif // !defined(AFX_UGTHEMESTYLE_H__EEA9B655_2AD0_4829_A149_D239AE00A9B4__INCLUDED_)
