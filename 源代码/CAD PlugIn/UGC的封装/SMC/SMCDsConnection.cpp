/*! 
	\file	SMCDsConnection.cpp
    \brief	����Դ������Ϣ�࣬��ǰ�汾��Ҫ�����򿪻��ߴ�������Դ
	\author	�� ��
	\attention	�ڴ򿪻��ߴ�������Դʱ�������ȶ�������Ϣ��������
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-20 ��ʼ���汾
*/

//#include "UGC.h"
#include "SMCDsConnection.h"

SMCDsConnection::SMCDsConnection()
{
	m_nEngineType	= SDBPlus; 
	m_bReadOnly  	= false;
	m_bTransacted	= false;
	m_bExclusive 	= false;
	m_bEncrypt   	= true;
	m_strDatabase	= _T("");
	m_strDriver  	= _T("");
	m_strServer  	= _T("");
	m_strUser    	= _T("");
	m_strPassword	= _T("");
	m_strAlias   	= _T("");
	m_bAutoConnect  = true;
	m_nConnMaxNum   = 0;
	m_nConnMinNum   = 0;
	m_nConnIncNum   = 0;

}

SMCDsConnection::~SMCDsConnection()
{
	
}