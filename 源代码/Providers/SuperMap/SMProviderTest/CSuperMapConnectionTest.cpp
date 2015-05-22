/** \file	 CSuperMapConnectionTest.cpp
*  \brief    �����SuperMapConnection����е�Ԫ����
*  \author	 �� ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-17
*  \note :
*/

#include "stdafx.h"
#include "CSuperMapConnectionTest.h"
#include "SMProviderSuite.h"
// FDO Headers File
#include <FdoStd.h>
#include <FDO.h>
#include <FdoCommon.h>
#include <FdoGeometry.h>
#include <FdoMessage.h>

#define LOCATION L".\\TestData\\"

//CPPUNIT_TEST_SUITE_REGISTRATION (CSuperMapConnectionTest);
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CSuperMapConnectionTest,SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> CSuperMapConnectionTest::m_connection;

CSuperMapConnectionTest::CSuperMapConnectionTest()
{
	m_connection = NULL;
	
}

CSuperMapConnectionTest::~CSuperMapConnectionTest()
{
}

void CSuperMapConnectionTest::setUp()
{
	if(m_connection == NULL)
	{
		m_connection = GetSuperMapConnection();
	}
	
}

void CSuperMapConnectionTest::tearDown()
{
	FDO_SAFE_RELEASE(m_connection.p);
}

FdoIConnection* CSuperMapConnectionTest::GetSuperMapConnection()
{
	/*FdoPtr<IConnectionManager> manager = FdoFeatureAccessManager::GetConnectionManager ();
	FdoPtr<FdoIConnection> connection = manager->CreateConnection (L"OSGeo.SuperMap.1.0");
	return (FDO_SAFE_ADDREF(connection.p));*/

	FdoPtr<IConnectionManager> manager = FdoFeatureAccessManager::GetConnectionManager ();
    return (manager->CreateConnection (L"SuperMap.SDB&SDX.1.0"));
}

void CSuperMapConnectionTest::testConnect()
{
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"world\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
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

void CSuperMapConnectionTest::testSetConnectionString()
{
	try
	{
		// �Ƿ�֧����Ӣ��,����״̬Ϊ�ر�ʱ�Ƿ�������������ַ���
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"English����");
		CPPUNIT_ASSERT_MESSAGE("SetConnectionString failed!", 0 == wcscmp(L"English����", m_connection->GetConnectionString()));
		FdoConnectionState state = m_connection->Open();
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
	try
	{
		// ����״̬ΪPendingʱ���Ƿ���Ȼ�������������ַ���(���ǵ�providerֻ��һ���������ԣ������ܳ�������״̬Ϊpending�����)
		/*CPPUNIT_ASSERT_MESSAGE("connection state not pending", FdoConnectionState_Pending == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"test");
		CPPUNIT_ASSERT_MESSAGE("SetConnectionString failed when connection state is pending", 0 == wcscmp(L"test", m_connection->GetConnectionString()));*/
		
		// ����״̬ΪOpenʱ���Ƿ������������������ַ���
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"world\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"test");
		CPPUNIT_ASSERT_MESSAGE("SetConnectionString when Open!", 0 == wcscmp(L"test", m_connection->GetConnectionString()));
		m_connection->Open();
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
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
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

//void CSuperMapConnectionTest::connect2()
//{
//	try
//	{
//		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
//		m_connection->SetConnectionString(L"DataSource=" LOCATION L"world");
//		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
//		FdoConnectionState state = m_connection->Open();
//		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
//		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
//		m_connection->Close();
//	}
//	catch (FdoException* ex)
//    {
//        FdoException* nex = ex;
//        while (nex)
//        {
//			AfxMessageBox(nex->GetExceptionMessage());
//            nex = nex->GetCause();
//        }
//		ex->Release();
//    }
//	catch (...)
//	{
//		AfxMessageBox(L"non-FdoException");
//	}
//	CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Closed == m_connection->GetConnectionState());
//}

//void CSuperMapConnectionTest::connect3()
//{
//	try
//	{
//		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
//		m_connection->SetConnectionString(L"DataSource=" LOCATION L"world");
//		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
//		FdoConnectionState state = m_connection->Open();
//		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
//		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
//		
//		// Verify results of DescribeSchema:
//		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
//		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
//		CPPUNIT_ASSERT_MESSAGE("������Ԥ�ڵ�һ������Դ��Ӧһ��schema", schemas->GetCount() == 1);
//		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
//		CPPUNIT_ASSERT_MESSAGE("ģʽ����������Դ��", 0 == wcscmp(schema->GetName(),L"world")); // world Ϊ��������Դ������ͬ��������Դ�������޸Ĵ˲��� 
//		CPPUNIT_ASSERT_MESSAGE("ģʽ������Ϊȱʡģʽ����", 0 == wcscmp(schema->GetDescription(),L"Default schema."));
//		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
//		CPPUNIT_ASSERT_MESSAGE("����Ԥ�ڵ�Ҫ�������", 8 == classes->GetCount()); // world����8�����ݼ�
//		FdoPtr<FdoClassDefinition> classDef = classes->GetItem(0);
//		CPPUNIT_ASSERT_MESSAGE("����Ԥ�ڵ�Ҫ������", 0 == wcscmp(classDef->GetName(),L"Ocean")); //��һ�����ݼ���ΪOcean
//
//		m_connection->Close();
//		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
//
//	}
//	catch (FdoException* ex)
//    {
//        FdoException* nex = ex;
//        while (nex)
//        {
//			AfxMessageBox(nex->GetExceptionMessage());
//            nex = nex->GetCause();
//        }
//		ex->Release();
//    }
//	catch (...)
//	{
//		AfxMessageBox(L"non-FdoException");
//	}
//}

//void CSuperMapConnectionTest::testSetConnectionString()
//{
//	// ��Ҫ���ԣ�
//	// 1. ����״̬Ϊclosed��pendingʱ��������ȷ���������ַ���
//	// 2. ����״̬Ϊopenʱ���Ƿ�����ı����������ַ���
//	try
//	{
//		CPPUNIT_ASSERT_MESSAGE("����δ�ر�",FdoConnectionState_Closed == m_connection->GetConnectionState());
//		m_connection->SetConnectionString(L"dd")
//	}
//}



