/*! 
	\file	SMCQueryDef.cpp
    \brief	��ѯ������
	\author	�� ��
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-25 ��ʼ���汾
*/

#include "SMCQueryDef.h"

SMCQueryDef::SMCQueryDef()
{
	m_nType = General;
	m_nOptions = Both;
	m_nMode = GeneralQuery;
}

SMCQueryDef::~SMCQueryDef()
{
}