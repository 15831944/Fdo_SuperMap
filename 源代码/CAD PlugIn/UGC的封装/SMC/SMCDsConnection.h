/*! 
	\file	SMCDsConncetion.h
    \brief	����Դ������Ϣ�࣬��ǰ�汾��Ҫ�����򿪻��ߴ�������Դ
	\author	�� ��
	\attention	�ڴ򿪻��ߴ�������Դʱ�������ȶ�������Ϣ��������	
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-20 ��ʼ���汾
*/

#ifndef SMCDSCONNECTION_H
#define SMCDSCONNECTION_H

#include "SMC.h"



class SMC_API SMCDsConnection
{
public:
	//! \brief		������������
	enum SMEngineType
	{	
		SDB				=0,		//SdbPlus����
		//MDB			=1,
		//SQLServer		=2,		//SDX for SQL Server
		Oracle			=3,
		SDE				=4,		//SDX for SDE
		ImagePlugins	=5,		//�û������Զ������ʾimage��ʽ�Ĳ��
		//SIT			=6,		//SIT��ʽӰ���ļ�����
		MicroStation	=8,		
		AutoCAD			=9,		//AutoCAD File, *.DXF , *.DWG
		OracleSpatial	=10,	//11,	//Oracle Spatial�������棬Added by lsj at 2001��6��7�� 08:32:05
		OraclePlus		=12,	//SDX Plus for Oracle
		SDBPlus			=14,		
		SybasePlus      =15,	//6,    //������SyBase����
		SQLPlus			=16,	//3,	//������Sql
		DMPlus			=17,	//7,    //������DM
		DB2             =18,
		Kingbase		=19,	//Kingbase������ݿ�
		Memory			=20,    //�ڴ�����Դ
		ROF             =21,    //Ready only file ֻ���ļ�����
		UDB				=30,    //��ƽ̨�ļ����� add by xll
		WEB				=31,	//��ƽ̨������������ add by duxiaomin
		ExtFile			=101	//�ⲿ�ļ�ֻ������
	};

public:		
	//! \brief		Ĭ�Ϲ��캯��
	SMCDsConnection();
	~SMCDsConnection();

public:
	//! \brief		��������
	SMEngineType    m_nEngineType;

	//! \brief		�Ƿ�ֻ����
	bool			m_bReadOnly;

	//! \brief		�Ƿ�������ʽ��
	bool			m_bTransacted;

	//! \brief		�Ƿ��ռ��
	bool			m_bExclusive;

	//! \brief		����Դ�Ƿ���Ҫ�����
	bool			m_bEncrypt;

	//!\brief		 ���ݿ���
	_tstring		m_strDatabase;

	//! \brief		ODBC Driver
	_tstring		m_strDriver;	

	//! \brief		������
	_tstring		m_strServer;

	//! \brief		�û���
	_tstring		m_strUser;

	//! \brief		����
	_tstring		m_strPassword;

	//! \brief		����
	_tstring		m_strAlias;

	//! \brief		�򿪹����ռ�ʱ�Ƿ��Զ�������Դ
	bool			m_bAutoConnect;

	//! \brief		���ݿ����ӳص����������
	int				m_nConnMaxNum;

	//! \brief		���ݿ����ӳص���С������
	int			    m_nConnMinNum;

	//! \brief		���ݿ����ӳص�����������
	int				m_nConnIncNum;
};

#endif