/*! 
	\file	SMCFieldInfo.h
    \brief	�ֶ���Ϣ��
	\author	����
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-24 ��ʼ���汾
*/

#ifndef SMCFIELDINFO_H
#define SMCFIELDINFO_H

#include "SMC.h"
//#include "SMCArray.h"

class SMC_API SMCFieldInfo  
{
public:
	SMCFieldInfo(){}
	~SMCFieldInfo(){}
public:
	//! �ֶ�����
	enum FieldType
	{
		Boolean = 1,
		Byte = 2,
		Integer = 3,
		Long = 4,
		Currency = 5,
		Single = 6,
		Double = 7,
		Date = 8,
		Binary = 9,
		Text = 10,
		LongBinary = 11,
		Memo = 12,
		GUID = 15,
		BigInt = 16,
		VarBinary = 17,
		Char = 18,
		Numeric = 19,
		Decimal = 20,
		Float = 21,
		Time = 22,
		TimeStamp = 23,
		Geometry = 128,
		DgnLink = 129,
		//��ӿ��ֽ� 20070323
		NVarChar =130
	};

public:
	//! �ֶ�����
	_tstring m_strName;

	//! �ֶ�����
	FieldType m_nType;

	//! �ֶδ�С
	int m_nSize;
	
	//! �ֶ�����
	int m_nAttributes;
	
	//! �ֶ����λ��
	int m_nOrdinalPosition;

	//! �Ƿ��Ǳ����ֶ�
	bool m_bRequired;
	
	//! �ֶγ����Ƿ�����Ϊ��
	bool m_bAllowZeroLength;
	
	//! m_nCollatingOrder,��δʹ��
	int m_nCollatingOrder;

	//! ����
	_tstring m_strForeignName;

	//! Դ�ֶ���
	_tstring m_strSourceField;

	//! Դ����
	_tstring m_strSourceTable;

	//! m_strValidationRule,��δʹ��
	_tstring m_strValidationRule;

	//! m_strValidationText,��δʹ��
	_tstring m_strValidationText;

	//! Ĭ��ֵ
	_tstring m_strDefaultValue;

	//! �̶�
	int m_nScale;
	
	//! ����
	int m_nPrecision;

	//! ��ʽ
	_tstring m_strFormat;

	//! ������Ϣ
	_tstring m_strDomain;

	//! �Ƿ�ɱ༭
	bool m_bUpdatable;

	//! ����������
    _tstring m_strIndexTab;
		
};

class SMC_API SMCFieldInfos:public std::vector<SMCFieldInfo>
{
	SMCFieldInfos(){};
	~SMCFieldInfos(){};
};


#endif