/** \file	 CSuperMapDescribeSchemaCommandTest.cpp
*  \brief    �����SuperMapDescribeSchemaCommand����е�Ԫ����
*  \author	 �� ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-17
*  \note :
*/

#include "stdafx.h"
#include "CSuperMapDescribeSchemaCommandTest.h"
#include "SMProviderSuite.h"
// FDO Headers File
#include <FdoStd.h>
#include <FDO.h>
#include <FdoCommon.h>
#include <FdoGeometry.h>
#include <FdoMessage.h>

#define LOCATION L".\\TestData\\"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CSuperMapDescribeSchemaCommandTest,SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> CSuperMapDescribeSchemaCommandTest::m_connection;

CSuperMapDescribeSchemaCommandTest::CSuperMapDescribeSchemaCommandTest()
{
	m_connection = NULL;
}

CSuperMapDescribeSchemaCommandTest::~CSuperMapDescribeSchemaCommandTest()
{
}

void CSuperMapDescribeSchemaCommandTest::setUp()
{
	if(NULL == m_connection)
	{
		m_connection = GetSuperMapConnection();
	}
}

void CSuperMapDescribeSchemaCommandTest::tearDown()
{
	FDO_SAFE_RELEASE(m_connection.p);
}

FdoIConnection* CSuperMapDescribeSchemaCommandTest::GetSuperMapConnection()
{
	FdoPtr<IConnectionManager> manager = FdoFeatureAccessManager::GetConnectionManager ();
    return (manager->CreateConnection (L"SuperMap.SDB&SDX.1.0"));
}

void CSuperMapDescribeSchemaCommandTest::testExecute1()
{
	// ���ԶԻ����ĺ��㡢�ߡ��桢�ı��������ݼ�������Դ�Ƿ��ܹ��ɹ������߼�ģʽ
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"world\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of DescribeSchema:
		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
		CPPUNIT_ASSERT_MESSAGE("������Ԥ�ڵ�һ������Դ��Ӧһ��schema", schemas->GetCount() == 1);
		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
		CPPUNIT_ASSERT_MESSAGE("����Ԥ�ڵ�Ҫ�������", 8 == classes->GetCount()); // world����8�����ݼ�
		FdoPtr<FdoClassDefinition> classDef = classes->GetItem(0);
		CPPUNIT_ASSERT_MESSAGE("����Ԥ�ڵ�Ҫ������", 0 == wcscmp(classDef->GetName(),L"Ocean")); //��һ�����ݼ���ΪOcean

		m_connection->Close();
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());

	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(nex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
}

void CSuperMapDescribeSchemaCommandTest::testExecute2()
{
	//���Զ�CAD�����������ݼ��ܷ����߼�ģʽ
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		//��һ��������CAD���ݼ�������Դ
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"CAD\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of DescribeSchema:
		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
		CPPUNIT_ASSERT_MESSAGE("ģʽ������Ԥ�ڵ�1", 1 == schemas->GetCount());
		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
		CPPUNIT_ASSERT_MESSAGE("Ҫ����������Ԥ�ڵ�2", 2 == classes->GetCount());
		FdoPtr<FdoClassDefinition> classDefinition = classes->GetItem(1); //ȡ�ڶ���Ҫ����Ϊ��
		CPPUNIT_ASSERT_MESSAGE("Ҫ���ಢ��ָ�����ݼ�", 0 == wcscmp(L"CAD_2",classDefinition->GetName()));

		m_connection->Close();	
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(nex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
}

void CSuperMapDescribeSchemaCommandTest::testExecute3()
{
	//���Զ����ĵ�����Դ�������ݼ����������ֶ�����֧��
	//�������ݷ�Χ�����㡢�ߡ��桢�ı������ϵ�����provider֧���������ݼ�
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		//��һ��������CAD���ݼ�������Դ
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"����Դ\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of DescribeSchema:
		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
		CPPUNIT_ASSERT_MESSAGE("ģʽ������Ԥ�ڵ�1", 1 == schemas->GetCount());
		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
		CPPUNIT_ASSERT_MESSAGE("Ҫ����������Ԥ�ڵ�5", 5 == classes->GetCount());
		FdoPtr<FdoClassDefinition> classDefinition1 = classes->GetItem(0);
		CPPUNIT_ASSERT_MESSAGE("�����ݼ�����������", 0 == wcscmp(L"�����ݼ�",classDefinition1->GetName()));
		FdoPtr<FdoClassDefinition> classDefinition2 = classes->GetItem(1); 
		CPPUNIT_ASSERT_MESSAGE("�����ݼ�����������", 0 == wcscmp(L"�����ݼ�",classDefinition2->GetName()));
		FdoPtr<FdoClassDefinition> classDefinition3 = classes->GetItem(2); 
		CPPUNIT_ASSERT_MESSAGE("�����ݼ�����������", 0 == wcscmp(L"�����ݼ�",classDefinition3->GetName()));
		FdoPtr<FdoClassDefinition> classDefinition4 = classes->GetItem(3); 
		CPPUNIT_ASSERT_MESSAGE("�ı����ݼ�����������", 0 == wcscmp(L"�ı����ݼ�",classDefinition4->GetName()));
		FdoPtr<FdoClassDefinition> classDefinition5 = classes->GetItem(4); 
		CPPUNIT_ASSERT_MESSAGE("�������ݼ�����������", 0 == wcscmp(L"�������ݼ�",classDefinition5->GetName()));
		
		FdoPtr<FdoPropertyDefinitionCollection> properties = classDefinition1->GetProperties();
		CPPUNIT_ASSERT_MESSAGE("�����������ֶ�������", NULL != properties->FindItem(L"�����ֶ�"));

		m_connection->Close();	
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(nex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
}

void CSuperMapDescribeSchemaCommandTest::testExecute4()
{
	//���Զ�SuperMap�㡢�ߡ��桢�ı����������ݼ���������ݼ��Ƿ���Գɹ�����
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		//��һ�������в�֧���������ݼ�������Դ
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"��֧��\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of DescribeSchema:
		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
		CPPUNIT_ASSERT_MESSAGE("ģʽ������Ԥ�ڵ�1", 1 == schemas->GetCount());
		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
		CPPUNIT_ASSERT_MESSAGE("Ҫ����������Ԥ�ڵ�0", 0 == classes->GetCount());

		m_connection->Close();	
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(nex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
}

void CSuperMapDescribeSchemaCommandTest::testExecute5()
{
	//�����������͵������ֶ��Ƿ��ܳɹ�ת��FDO�߼������ֶ�
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		//��һ�������в�֧���������ݼ�������Դ
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"fieldtest\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of DescribeSchema:
		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
		CPPUNIT_ASSERT_MESSAGE("ģʽ������Ԥ�ڵ�1", 1 == schemas->GetCount());
		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
		CPPUNIT_ASSERT_MESSAGE("Ҫ����������Ԥ�ڵ�1", 1 == classes->GetCount());
		FdoPtr<FdoClassDefinition> classDefinition = classes->GetItem(0);
		FdoPtr<FdoPropertyDefinitionCollection> properties = classDefinition->GetProperties();
		CPPUNIT_ASSERT_MESSAGE("���Ը�������Ԥ�ڵ�10", 10 == properties->GetCount());

		m_connection->Close();	
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(nex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
}
