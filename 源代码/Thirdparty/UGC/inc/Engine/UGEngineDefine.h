// UGEngineDefine.h: interface for the UGEngineDefine class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGEngineDefine.h
   **************************************************************************************
    \author   �¹���
    \brief    �������涯̬�ⶨ���ࡣ                                                 
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGENGINEDEFINE_H__050487B3_D93F_41AF_974B_AAB48862D363__INCLUDED_)
#define AFX_UGENGINEDEFINE_H__050487B3_D93F_41AF_974B_AAB48862D363__INCLUDED_

#include "Engine/UGDataSource.h"

namespace UGC {

class ENGINE_API UGEngineDefine  
{
public:
	UGEngineDefine();
	virtual ~UGEngineDefine();
	
public:
	void operator =(const UGEngineDefine& EngineDef);
	//========================================================
	//! \brief 		����������涨����Ϣ��
	void Empty();
public:
	//! \brief 		����Դ�������͡� 
	UGEngineType m_nType;
	//! \brief 		�������涯̬������������
	UGString m_strName;
	//! \brief 		�������涯̬������ 
	void* m_hHandle;	
};

}

#endif // !defined(AFX_UGENGINEDEFINE_H__050487B3_D93F_41AF_974B_AAB48862D363__INCLUDED_)
