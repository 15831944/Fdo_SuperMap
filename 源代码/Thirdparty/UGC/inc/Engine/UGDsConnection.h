/*! \file	 UGDsConnection.h
*  \brief	 ����Դ������Ϣ�ඨ��
*  \author	 ugc team
*  \attention 
*  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version $Id: UGDsConnection.h,v 1.24 2007/10/25 01:00:57 yanmb Exp $
*/

#ifndef UGDSCONNECTION_H
#define UGDSCONNECTION_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"

namespace UGC {
	
	//! ������������
	enum UGEngineType
	{	
			NOEngine		=-1,
			SDB				=0,		//SdbPlus����
			//MDB				=1,
			//SQLServer		=2,		//SDX for SQL Server
			Oracle			=3,
			SDE				=4,		//SDX for SDE
			ImagePlugins	=5,		//�û������Զ������ʾimage��ʽ�Ĳ��
			//SIT				=6,		//SIT��ʽӰ���ļ�����
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
			WEB				=23,	//��ƽ̨������������ add by duxiaomin
			UDB				=30,    //��ƽ̨�ļ����� add by xll
			ExtFile			=101		//�ⲿ�ļ�ֻ������
	};
	
	//! ����Դ������Ϣ��
	class ENGINE_API UGDsConnection  
	{	
	public:		
		//! Ĭ�Ϲ��캯��
		UGDsConnection();
		//! ���캯��
		UGDsConnection(
			UGEngineType nEngineType,
			const UGString& strServer,
			const UGString& strDriver,
			const UGString& strDatabase,
			const UGString& strUser,
			const UGString& strPassword,
			const UGString& strAlias,
			UGbool bEncrypt = TRUE,
			UGbool bTransacted = FALSE,
			UGbool bReadonly = FALSE,		
			UGbool bExclusive = FALSE,		
			UGbool bAutoConnect = TRUE);
		
		//!���캯��:SqlServer��ODBC�� DriverConnect
		UGDsConnection(
			const UGString& strServer,
			const UGString& strDriverName,
			const UGString& strDatabase,
			const UGString& strUser,
			const UGString& strPassword,
			const UGString& strAlias,
			UGEngineType nEngineType = SQLPlus,
			UGbool bTransacted = FALSE,
			UGbool bReadonly = FALSE);
		
		
		//! ���캯��: Oracle;SQL Server��������Դ���� 
		UGDsConnection(const UGString& strDNSOrServerName,
			const UGString& strDatabase,
			const UGString& strUser,
			const UGString& strPassword,
			const UGString& strAlias,
			UGEngineType nEngineType = OraclePlus,
			UGbool bTransacted = FALSE,
			UGbool bReadonly = FALSE);
		
		//!���캯��:�����ļ������� UDB,SDBPlus,MEMORY ���strFilePathΪ��
		UGDsConnection(const UGString& strFilePath,
			const UGString& strUser,
			const UGString& strPassword,
			const UGString& strAlias,
			UGEngineType nEngineType = UDB,
			UGbool bTransacted = FALSE,
			UGbool bReadonly = FALSE,
			UGbool bEncrypt = TRUE,
			UGbool bExclusive = FALSE);
		
		//! ��������
		~UGDsConnection();
		
		//! ������Դ������Ϣ��ΪXML��ʽ
		//! \param nVersion �汾��
		//! \return ������XML��ʽ�ַ���
		UGString ToXML(UGint nVersion,UGString strRefPath = "") const;
		
		//! ��XML�н�������Դ������Ϣ
		//! \param strXML XML��ʽ�ַ���
		//! \param nVersion �汾��	
		UGbool FromXML(const UGString& strXML,UGint nVersion,UGString strRefPath = "");
		
		void operator =(const UGDsConnection &conn);
		
		UGbool operator ==(const UGDsConnection &conn);
		
	public:
		//! ��������
		UGEngineType	m_nEngineType;
		
		//! �Ƿ�ֻ����
		UGbool			m_bReadOnly;
		
		//! �Ƿ�������ʽ��
		UGbool			m_bTransacted;
		
		//! �Ƿ��ռ��
		UGbool			m_bExclusive;
		
		//! ����Դ�Ƿ���Ҫ�����
		UGbool			m_bEncrypt;
		
		//! ���ݿ���
		UGString		m_strDatabase;
		
		//! ODBC Driver
		UGString		m_strDriver;	
		
		//! ������
		UGString		m_strServer;
		
		//! �û���
		UGString		m_strUser;
		
		//! ����
		UGString		m_strPassword;
		
		//! ����
		UGString		m_strAlias;
		
		//! �򿪹����ռ�ʱ�Ƿ��Զ�������Դ
		UGbool			m_bAutoConnect;
		
		//! brief ���ݿ����ӳص����������
		UGint			m_nConnMaxNum;
		
		//! brief ���ݿ����ӳص���С������
		UGint			m_nConnMinNum;
		
		//! brief ���ݿ����ӳص�����������
		UGint			m_nConnIncNum;

		//! brief ���ݿ��Ƿ���չ��	
		UGbool			m_bExpandOpen;
};

}

#endif
