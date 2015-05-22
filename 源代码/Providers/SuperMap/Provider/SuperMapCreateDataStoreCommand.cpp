/** \file	 SuperMapCreateDataStoreCommand.cpp
*  \brief    ������ҪΪʵ��FDO��FdoICreateDataStore�ӿڣ���ɴ���SDB����Դ�Ĺ���
*  \author	 ����
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-1-23
*/  

#include "SuperMap.h"

SuperMapCreateDataStoreCommand::SuperMapCreateDataStoreCommand(SuperMapConnection* connection):
	 FdoCommonCommand<FdoICreateDataStore, SuperMapConnection> (connection)
{
	m_dataStorePropertyDictionary = new FdoCommonDataStorePropDictionary(connection);

	//�������е���������
	char* mbPropName = NULL;

	wide_to_multibyte(mbPropName, CONNECTIONPROPERTY_DATASOURCE);
	FdoPtr<ConnectionProperty> newProp = new ConnectionProperty(CONNECTIONPROPERTY_DATASOURCE,
		NlsMsgGet(SUPERMAP_CONNECTION_STRING, "Connection String"),
				// TODO:: ��ʾ��Ϣ��Ϊ�꣬���ʺ���Ӣ��
				//L"�����ַ���",
				L"", true, false, false, true, false, false, false, 0, NULL);
	m_dataStorePropertyDictionary->AddProperty(newProp);
}

void SuperMapCreateDataStoreCommand::Execute()
{
	TRACE(_T("���� SuperMapCreateDataStoreCommand::Execute()... \n"));

	FdoPtr<SuperMapConnection> connection = (SuperMapConnection*)GetConnection ();
	VALIDATE_POINTER(connection);

	if(connection->GetConnectionState() != FdoConnectionState_Closed)
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_CONNECTION_ALREADY_OPEN,"supermap connection already open"));
	}

	FdoCommonConnStringParser againparser (NULL, m_dataStorePropertyDictionary->GetProperty(CONNECTIONPROPERTY_DATASOURCE));
	if (!againparser.IsConnStringValid())
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_INVALID_CONNECTION_STRING, 
			"Invalid connection string '%1$ls'", 
			connection->GetConnectionString ()));
	}

	FdoStringP databaseName = _(againparser.GetPropertyValue(CONNECTIONPROPERTY_DATABASE));

	UGC::UGString fileName = SuperMapUtil::WcharToString((FdoString*)databaseName).c_str();
	
	// Todo::����Ƿ���ͬ���ļ�����



	// ��ס�ɵ����Ӵ�
	FdoStringP oldConnStr = connection->GetConnectionString();

	FdoStringP connStr = L"DataSource=\"type=sdb;database=XXX;IsImage=false\";";
	FdoStringP newConnStr = connStr.Replace(L"XXX",databaseName);

	// Todo::��������sdb�ļ�(���ߴ�����־��connection��)
	connection->SetCreateSDB();
	
	connection->SetConnectionString(newConnStr);
	if(connection->Open() == FdoConnectionState_Open)
	{
		//do sth
		connection->Close();
	}
	else
	{
		//�׳��쳣 sdb�ļ�����ʧ��
	}

	//������ؾ����Ӵ�
	connection->SetConnectionString(oldConnStr);



}