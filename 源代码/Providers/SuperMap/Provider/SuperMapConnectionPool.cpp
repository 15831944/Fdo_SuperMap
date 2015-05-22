
/** \file	 SuperMapConnectionPool.cpp
*  \author	 ����
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/

#include <SuperMap.h>

SuperMapConnectionPool* SuperMapConnectionPool::m_Instance = NULL;


SuperMapConnectionPool::SuperMapConnectionPool()
{
}

SuperMapConnectionPool::~SuperMapConnectionPool()
{
	for (ConnectionInfoMap::iterator iter = m_ConnInfoMap.begin (),
		end = m_ConnInfoMap.end ();
		iter != end; ++iter)
	{
		ConnectionInfo* conninfo = (*iter).second;
		delete conninfo;
	}
}

SuperMapConnectionPool* SuperMapConnectionPool::GetInstance()
{
	//TODO: Synchronize this for threads?
	if(NULL == m_Instance)
	{
		m_Instance = new SuperMapConnectionPool(); 
	}

	return m_Instance;
}

void SuperMapConnectionPool::Dispose()
{
	delete SuperMapConnectionPool::m_Instance;
	SuperMapConnectionPool::m_Instance = 0;
}


SuperMapConnectionPool::ConnectionInfo::ConnectionInfo()
{
	pDataSource = NULL;
	nEngineType = (UGC::UGEngineType) 0;
	nUseCount = 0;
	bAutoDelete = false;
	strUserName = "";
	strPassword = "";
	strServer = "";
	strDatabase = "";
	bIsImage = false;
}   

SuperMapConnectionPool::ConnectionInfo::~ConnectionInfo()
{
	Cleanup(true);
}

void SuperMapConnectionPool::ConnectionInfo::Cleanup(bool bForce)
{

	if(!bForce)
	{
		if(nUseCount != 0)
			return ;
	}

	if (NULL != pDataSource)
	{
		if (pDataSource->IsConnected() || pDataSource->IsOpen())
		{
			pDataSource->Close();
		}
		// �ڴ��ͷ�����Դ
		delete pDataSource;
	}

	pDataSource = NULL;
	nEngineType = (UGC::UGEngineType) 0;
	nUseCount = 0;
	bAutoDelete = false;
	strUserName = "";
	strPassword = "";
	strServer = "";
	strDatabase = "";
	bIsImage = false;
}


std::string SuperMapConnectionPool::GetConnectionInfo(SuperMapConnection* conn)
{
	if (NULL == conn)
	{
		return "";
	}

	FdoPtr<FdoIConnectionInfo> info = conn->GetConnectionInfo ();
	FdoPtr<FdoCommonConnPropDictionary> dictionary = dynamic_cast<FdoCommonConnPropDictionary*>(info->GetConnectionProperties ());
	
	FdoCommonConnStringParser parser (NULL, conn->GetConnectionString ());
	if (!parser.IsConnStringValid())
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_INVALID_CONNECTION_STRING, 
			"Invalid connection string '%1$ls'",
			conn->GetConnectionString ()));

	}
	if (parser.HasInvalidProperties(dictionary))
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_INVALID_CONNECTION_PROPERTY_NAME,
			"Invalid connection property name '%1$ls'", 
			parser.GetFirstInvalidPropertyName (dictionary)));
	}

	FdoCommonConnStringParser againparser (NULL, dictionary->GetProperty(CONNECTIONPROPERTY_DATASOURCE));
	if (!againparser.IsConnStringValid())
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_INVALID_CONNECTION_STRING, 
			"Invalid connection string '%1$ls'", 
			conn->GetConnectionString ()));
	}
																													
	/**************��������***************/
	if ( NULL == againparser.GetPropertyValue(CONNECTIONPROPERTY_CONN_TYPE) )
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_NOT_TYPE,
			"Invalid connection type"));
	}

	std::string strType = SuperMapUtil::MakeLower(againparser.GetPropertyValue(CONNECTIONPROPERTY_CONN_TYPE));
	
	int nType = GetEngineType(strType);
	if (-1 == nType )
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_INVALID_CONNECTION_STRING, 
			"Invalid connection string '%1$ls'", 
			conn->GetConnectionString ()));
	}

	/**************�������ݿ�***************/
	if ( NULL == againparser.GetPropertyValue(CONNECTIONPROPERTY_DATABASE) )
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_NOT_DATABASE, 
			"Invalid connection datebase"));
	}

	/**************����ϸ��***************/
	UGC::UGEngineType nEngType = (UGC::UGEngineType)nType;
	switch(nEngType)
	{
	case UGC::SDBPlus:
		break;
	case UGC::OraclePlus:
	case UGC::SQLPlus:
		if ( NULL == againparser.GetPropertyValue(CONNECTIONPROPERTY_SERVER) )
		{
			throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_NOT_SERVER,
				"Invalid connection datebase server"));
		}
		if ( NULL == againparser.GetPropertyValue(CONNECTIONPROPERTY_USER) )
		{
			throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_NOT_USER, 
				"Invalid connection datebase user"));
		}
		if ( NULL == againparser.GetPropertyValue(CONNECTIONPROPERTY_PASSWORD) )
		{
			throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_NOT_PASSWORD, 
				"Invalid connection datebase password"));
		}
		break;
	case UGC::AutoCAD:
		break;
	}

	/**************����������Ϣ***************/
	ConnectionInfo *newConnInfo = new ConnectionInfo();
	newConnInfo->nEngineType = nEngType;
	newConnInfo->strDatabase = _(againparser.GetPropertyValue(CONNECTIONPROPERTY_DATABASE));
	newConnInfo->strServer = _(againparser.GetPropertyValue(CONNECTIONPROPERTY_SERVER));
	newConnInfo->strUserName = _(againparser.GetPropertyValue(CONNECTIONPROPERTY_USER));
	newConnInfo->strPassword = _(againparser.GetPropertyValue(CONNECTIONPROPERTY_PASSWORD));
	//if( UGC::ImagePlugins == nEngType)
	//	newConnInfo->bIsImage = true;
	//else
	newConnInfo->bIsImage = SuperMapUtil::ToBool(_(againparser.GetPropertyValue(CONNECTIONPROPERTY_IMAGE))); // added by zhouxu

	newConnInfo->nUseCount = 1;	// 

	/**************�ж��Ƿ��Ѿ�����***************/
	std::string session = this->MakeSession(newConnInfo);
	::OutputDebugStringA(session.c_str());
	if(NULL != FindConnectionInfo(session))
	{
		delete newConnInfo;
		// ��һ����ʹ��
		Use(session);
		ShowDataSourceInfo(session);
		return session;
	}
	/**************������Դ***************/
	bool IsSucceed = false;
	newConnInfo->pDataSource = UGC::UGDataSourceManager::CreateDataSource(newConnInfo->nEngineType);
	if(newConnInfo->pDataSource != NULL)
	{
		UGC::UGDsConnection &conn = newConnInfo->pDataSource->GetConnectionInfo();
		conn.m_nEngineType = newConnInfo->nEngineType;


		if(newConnInfo->nEngineType != -1 )//UGC::SDBPlus)   //Ϊ�˷�����deskpro��������ʱע�͵� by zhouxu 2008-6-2
		{
			// �����ļ����͵��Զ�ɾ��������Ϣ
			// ���ORA and SQL�������Զ��ر����ݿ�����Ļ���
			// �û����²������µ����ݿ���Ϣ
			newConnInfo->bAutoDelete = true;
		}
		
		//added by zhouxu 2008-1-17
		if(newConnInfo->bIsImage)
			conn.m_bReadOnly = true;  // Ӱ��ģʽ��ֻ����ʽ��

		// NOTE:: �ļ������ݿⲻһ��֮����������ļ����͵ģ���Ҫ���޸�
		if(newConnInfo->nEngineType == UGC::SDBPlus
			|| newConnInfo->nEngineType == UGC::ImagePlugins)
		{
			conn.m_strServer = UGC::UGString(newConnInfo->strDatabase);
			conn.m_strDatabase = "";

		}
		else
		{
			conn.m_strServer = UGC::UGString(newConnInfo->strServer);
			conn.m_strDatabase = UGC::UGString(newConnInfo->strDatabase);
		}

		conn.m_strUser = UGC::UGString(newConnInfo->strUserName);
		conn.m_strPassword = UGC::UGString(newConnInfo->strPassword);
		conn.m_strAlias = UGC::UGString(session.c_str());//added by zhouxu 2008-2-21

		if ( newConnInfo->nEngineType == UGC::SQLPlus )
		{
			conn.m_strDriver = "SQL Server";
		}

		IsSucceed = newConnInfo->pDataSource->Open()?true:false;

		if(!IsSucceed)
		{
			delete newConnInfo->pDataSource;
			newConnInfo->pDataSource = NULL;
		}
	}

	if(!IsSucceed)
	{
		delete newConnInfo;
		throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_FAIL, "connection datebase fail"));
	}

	/**************�������ӳ�***************/
	m_ConnInfoMap[session] = newConnInfo;
	return session;
}

int SuperMapConnectionPool::GetEngineType(const std::string &strType)
{
	if(strType == "sdb")
		return (int)UGC::SDBPlus;
	else if(strType == "ora")
		return (int)UGC::OraclePlus;
	else if (strType == "sql")
		return (int)UGC::SQLPlus;
	else if (strType == "sit")
		return (int)UGC::ImagePlugins;

	return -1;
}

// ��ȡ����Դ
UGC::UGDataSource* SuperMapConnectionPool::GetDataSource(const std::string &strSession)
{
	ConnectionInfo* conninfo = FindConnectionInfo(strSession);
	if(conninfo)
	{
		return conninfo->pDataSource;
	}
	return NULL;
}

// �ر�����Դ
void SuperMapConnectionPool::CloseDataSource(const std::string &strSession, bool bForceClose)
{
	// ������
	Disuse(strSession);

	if (bForceClose)
	{
		DeleteConnInfo(strSession);
	}
}

SuperMapConnectionPool::ConnectionInfo*  SuperMapConnectionPool::FindConnectionInfo(const std::string &session)
{
	ConnectionInfoMap::iterator iter = m_ConnInfoMap.find (session);
	if (iter == m_ConnInfoMap.end ())
	{
		return NULL;
	}

	return (*iter).second;
}

// ����SESSION
std::string SuperMapConnectionPool::MakeSession(const ConnectionInfo* conninfo)
{
	if (NULL == conninfo)
	{
		return "";
	}

	char session[1024];

	if (conninfo->nEngineType == UGC::SDBPlus || conninfo->nEngineType == UGC::ImagePlugins)
	// �ļ�SESSION
	{
		// ����+·��+�ļ���+��չ��
		std::vector<std::string> dirarr = SuperMapUtil::SplitString(SuperMapUtil::MakeLower(conninfo->strDatabase),
			"\\/.: ");
		sprintf(session, "SM%d%d%s", 
			conninfo->nEngineType,
			(conninfo->bIsImage)?1:0,
			SuperMapUtil::JoinString(dirarr, "").c_str());
	}
	else 
	// �ռ�����SESSION
	{
		// ����+���ݷ�������+�����û���+���ݿ���
		std::vector<std::string> strser = SuperMapUtil::SplitString(SuperMapUtil::MakeLower(conninfo->strServer), 
			".\\/ ");
		sprintf(session, "SM%d%d%s%s%s", 
				conninfo->nEngineType,
				(conninfo->bIsImage)?1:0,
				SuperMapUtil::JoinString(strser, "").c_str() , 
				SuperMapUtil::MakeLower(conninfo->strUserName).c_str(), 
				SuperMapUtil::MakeLower(conninfo->strDatabase).c_str());
	}

	return std::string(session);
}

void SuperMapConnectionPool::Disuse(const std::string &strSession)
{
	ConnectionInfo* conninfo = FindConnectionInfo(strSession);
	if(conninfo)
	{
		conninfo->nUseCount --;

		// �Զ�ɾ��
		if(conninfo->bAutoDelete)
		{
			DeleteConnInfo(strSession);
		}
	}
}

void SuperMapConnectionPool::Use(const std::string &strSession)
{
	ConnectionInfo* conninfo = FindConnectionInfo(strSession);
	if(conninfo)
	{
		conninfo->nUseCount ++;

		if (!conninfo->pDataSource->IsOpen())
		{
			if(!conninfo->pDataSource->Open())
			{
				throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_FAIL, 
					"reconnection datebase fail"));
			}
		}
	}
}

void SuperMapConnectionPool::DeleteConnInfo(const std::string &strSession)
{
	ConnectionInfoMap::iterator iter = m_ConnInfoMap.find(strSession);
	if (iter != m_ConnInfoMap.end ())
	{
		ConnectionInfo* conninfo = (*iter).second;
		delete conninfo;

		m_ConnInfoMap.erase(iter);
	}
}

bool SuperMapConnectionPool::IsDatabase(const std::string &strSession)
{
	bool isdatabase = false;
	ConnectionInfo* conninfo = FindConnectionInfo(strSession);
	if(conninfo)
	{
		switch(conninfo->nEngineType)
		{
		case UGC::OracleSpatial:
		case UGC::OraclePlus:
		case UGC::SybasePlus:
		case UGC::SQLPlus:
		case UGC::Kingbase:
		case UGC::DB2:
			isdatabase = true;
			break;
		}
	}
	return isdatabase;
}

bool SuperMapConnectionPool::IsImage(const std::string &strSession)
{
	bool isdatabase = false;
	ConnectionInfo* conninfo = FindConnectionInfo(strSession);
	if(conninfo)
	{
		return conninfo->bIsImage;
	}
	return false;
}

// ���Ժ���
void SuperMapConnectionPool::ShowDataSourceInfo(const std::string &session)
{
	ConnectionInfo* conninfo = FindConnectionInfo(session);
	if(conninfo)
	{

		TRACE(_T("��ʼ >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> "));

		TRACE(_T("����Դ[%ls]"), SuperMapUtil::StringToWString(conninfo->pDataSource->GetAlias().Cstr()).c_str());

		TRACE(_T("����Դ·���� %ls"), SuperMapUtil::StringToWString(conninfo->pDataSource->GetName().Cstr()).c_str());
		TRACE(_T("  �������ͣ� %ls"),  SuperMapUtil::StringToWString(conninfo->pDataSource->GetEngineName().Cstr()).c_str());
		TRACE(_T("����Դ������ %ls"),  SuperMapUtil::StringToWString(conninfo->pDataSource->GetDescription().Cstr()).c_str());
		TRACE(_T("�Ƿ�򿪣� %ls"),  conninfo->pDataSource->IsOpen()?_T("��"):_T("��"));
		TRACE(_T("�Ƿ���ֻ����ʽ�򿪣� %ls"),  conninfo->pDataSource->IsReadOnly()?_T("��"):_T("��"));
		TRACE(_T("�Ƿ�֧������ %ls"),  conninfo->pDataSource->IsTransStarted()?_T("��"):_T("��"));
		TRACE(_T("�Ƿ�Ķ��� %ls"),  conninfo->pDataSource->IsModified()?_T("��"):_T("��"));
		
		TRACE(_T("���ݼ�����%d "), conninfo->pDataSource->GetDatasetCount());

		for(int j = 0; j < conninfo->pDataSource->GetDatasetCount(); j++)
		{
			TRACE(_T("| -- %ls   \t[%d]"),  SuperMapUtil::StringToWString(conninfo->pDataSource->GetDataset(j)->GetName().Cstr()).c_str(),
				conninfo->pDataSource->GetDataset(j)->GetType());

			TRACE(_T("|        �Ƿ�򿪣� %ls"), conninfo->pDataSource->GetDataset(j)->IsOpen()?_T("��"):_T("��"));
		}	

		TRACE(_T("����ϵ���ƣ� %s"), SuperMapUtil::StringToWString(conninfo->pDataSource->GetPrjCoordSys().GetName().Cstr()).c_str());

		TRACE(_T("���� <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< "));

	}
}