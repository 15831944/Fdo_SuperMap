
/** \file	 SuperMapConnectionPool.h
*  \author	 ����
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/


#ifndef __SUPERMAPCONNECTIONPOOL_H__
#define __SUPERMAPCONNECTIONPOOL_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "UGC.h"

// ת��NULLΪ""
#define		_(X)	(X)?(X):("")

class SuperMapConnection;

/*! \class SuperMapConnectionPool
*	\brief ����������Ϣ
*/
class SuperMapConnectionPool
{
public:
	/*! \fn static SuperMapConnectionPool* GetInstance()
	* \brief ����ʵ��
	*/
	static SuperMapConnectionPool* GetInstance();
	virtual ~SuperMapConnectionPool();
	virtual void Dispose();

public:

	/*! \class ConnectionInfo
	*	\brief ������Ϣ
	*/
	class ConnectionInfo
	{
	public:
		ConnectionInfo();
		virtual ~ConnectionInfo();
		// ��ʼ��
		void Cleanup(bool bForce = false);
	public:
		//! ����Դ
		UGC::UGDataSource* pDataSource;
		//! ������������
		UGC::UGEngineType nEngineType;
		//! ʹ�ü���
		int nUseCount;
		bool bAutoDelete;
		std::string strUserName;
		std::string strPassword;
		std::string strServer;
		//! �ļ�ȫ��������������ݿ�
		std::string strDatabase;
		// �Ƿ���Ӱ��ʽ��
		bool bIsImage;
	};

	/*! \fn std::string GetConnectionInfo(SuperMapConnection* conn)
	* \brief �������ݿ⣬����SESSION
	*/
	std::string GetConnectionInfo(SuperMapConnection* conn);

	/*! \fn UGC::UGDataSource* GetDataSource(const std::string &strSession)
	* \brief ��ȡ����Դ
	*/
	UGC::UGDataSource* GetDataSource(const std::string &strSession);

	// bForceClose Ϊ�棬ǿ�ƹر�����Դ�������Ƿ���ʹ��
	/*! \fn void CloseDataSource(std::string &strSession, bool bForceClose = false)
	* \brief �ر�����Դ  bForceClose Ϊ�棬ǿ�ƹر�����Դ�������Ƿ���ʹ��
	*/
	void CloseDataSource(const std::string &strSession, bool bForceClose = false);

	/*! \fn bool IsDatabase(const std::string &strSession)
	* \brief �Ƿ�֧�ָ߼��������ļ������ݿ���жϣ�
	*/
	bool IsDatabase(const std::string &strSession);

	/*! \fn bool IsImage(const std::string &strSession)
	* \brief �Ƿ���Ӱ��
	*/
	bool IsImage(const std::string &strSession);

private:
	// ת����������
	int GetEngineType(const std::string &strType);
	// �ж��Ƿ��Ѿ�����
	SuperMapConnectionPool::ConnectionInfo*  FindConnectionInfo(const std::string &session);
	// ����SESSION
	std::string MakeSession(const ConnectionInfo* conninfo);
	// ����ʹ�úͷ���
	void Disuse(const std::string &strSession);
	void Use(const std::string &strSession);
	// ����SESSIONɾ��һ������
	void DeleteConnInfo(const std::string &strSession);

	// ���Ժ���
	void ShowDataSourceInfo(const std::string &session);

private:
	typedef std::map<std::string, ConnectionInfo*> ConnectionInfoMap;
	SuperMapConnectionPool();
	ConnectionInfoMap m_ConnInfoMap;
	static SuperMapConnectionPool* m_Instance;
	
};

#endif