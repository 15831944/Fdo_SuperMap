/*! 
	\file	SMCQueryDef.h
    \brief	��ѯ������
	\author	�� ��
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-25 ��ʼ���汾
*/

#ifndef SMCQUERYDEF_H
#define SMCQUERYDEF_H

#include "SMC.h"

class SMC_API SMCQueryDef
{
	public:
	//! ��ѯ����ö��
	enum QueryType
	{
		General							=0, //! һ���ѯ
		Bounds							=1, //! ʹ��Bounds��ѯ
		IDs								=2, //! ʹ��ID�����ѯ
	};

	//! ��ѯѡ��ö��
	enum QueryOption
	{		
		Geometry						= 1,//! ��ѯ���ζ���
		Attribute						= 2,//! ��ѯ������Ϣ
		Both							= 3 //! ��ѯ���ζ���������Ϣ
	};

	//! ��ѯģʽö��
	enum QueryMode
	{
		GeneralQuery					=0x00000000, //! һ���ѯ
		FuzzyQuery						=0x00000001  //! ģ����ѯ
	};

public:
	//! ���캯��
	SMCQueryDef();
	//! ��������
	~SMCQueryDef();

public:
	//! ��ѯ����(General,Bounds,IDs�����ֿռ��ѯ�ȣ�
	//! ���� (Ĭ�� General)
	QueryType			m_nType;

	//! ��ѯѡ��(�Ƿ񷵻�Geometry��Attribute,�����߶��еȣ�
	//! ���� ��Ĭ�� Both��
	QueryOption			m_nOptions;

	//! ��ѯ��ʽ(GeneralQuery��FuzzyQuery)
	//! ��ѡ Ĭ���أ�GeneralQuery
	QueryMode			m_nMode;
};

#endif