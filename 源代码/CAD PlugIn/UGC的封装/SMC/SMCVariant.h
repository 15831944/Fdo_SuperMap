/*! 
	\file	SMCVariant.h
    \brief	ͨ������������
	\author	�� ��
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-24 ��ʼ���汾
*/

#ifndef SMCVARIANT_H
#define SMCVARIANT_H

#include "SMC.h"

class SMC_API SMCVariant  
{
public:
	//! \brief		֧�ֵ�����
	enum VarType
	{ 
		Null			=	0, //! δ���������
		Byte			=	1, //! ���ֽ�����
		Short			=	2, //! ˫�ֽ���������
		Integer			=	3, //! ���ֽ���������
		Long			=	4, //! ���ֽ���������
		Float			=	5, //! ���ֽڸ�������
		Double			=	6, //! ���ֽڸ�������
		Time			=	7, //! ʱ������
		Binary			=	8, //! ����������
		String			=   9  //! �ַ���
	};

	//! \brief		��������
	union VarValue
	{
		unsigned char bVal;
		short sVal;
		int	iVal;
		long long int  lVal;
		float fVal;
		double dVal;
		double   tVal; // Time���ڲ�ʵ��
		void* pVal;	//�洢String��MemeroyStream��ָ��
	};

public:
	SMCVariant(){}
	~SMCVariant(){}

public:
	//! \brief		��������
	VarType m_nType;
	//! \brief		����ֵ
	VarValue m_value;	
};

#endif
