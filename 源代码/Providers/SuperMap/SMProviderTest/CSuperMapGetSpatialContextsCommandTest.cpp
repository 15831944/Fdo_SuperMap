/** \file	 CSuperMapGetSpatialContextsCommandTest.cpp
*  \brief    �����SuperMapGetSpatialContextsCommand���ռ������������е�Ԫ����
*  \author	 �� ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-19
*  \note :
*/

#include "stdafx.h"
#include "CSuperMapGetSpatialContextsCommandTest.h"
#include "SMProviderSuite.h"
// FDO Headers File
#include <FdoStd.h>
#include <FDO.h>
#include <FdoCommon.h>
#include <FdoGeometry.h>
#include <FdoMessage.h>

#define LOCATION L".\\TestData\\"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CSuperMapGetSpatialContextsCommandTest,SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> CSuperMapGetSpatialContextsCommandTest::m_connection;

CSuperMapGetSpatialContextsCommandTest::CSuperMapGetSpatialContextsCommandTest()
{
	m_connection = NULL;
}

CSuperMapGetSpatialContextsCommandTest::~CSuperMapGetSpatialContextsCommandTest()
{
}

void CSuperMapGetSpatialContextsCommandTest::setUp()
{
	if(NULL == m_connection)
	{
		m_connection = GetSuperMapConnection();
	}
}

void CSuperMapGetSpatialContextsCommandTest::tearDown()
{
	FDO_SAFE_RELEASE(m_connection.p);
}

FdoIConnection* CSuperMapGetSpatialContextsCommandTest::GetSuperMapConnection()
{
	FdoPtr<IConnectionManager> manager = FdoFeatureAccessManager::GetConnectionManager ();
    return (manager->CreateConnection (L"SuperMap.SDB&SDX.1.0"));
}

void CSuperMapGetSpatialContextsCommandTest::testExecute1()
{
	// ����WKT���Ƿ���ȷֻ��ͨ��MAP3D�����⣬��Ԫ����ֻ���ԶԸ������͵�����ϵ�ռ������ȡ���ĵ����Ƿ���ȷ���Ƿ������ѭ��
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"��ͨƽ������ϵ\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of GetSpatialContext:
		FdoPtr<FdoIGetSpatialContexts> getSpatialContexts = (FdoIGetSpatialContexts*)m_connection->CreateCommand(FdoCommandType_GetSpatialContexts);
		//FdoPtr<FdoISpatialContextReader> spatialReader = getSpatialContexts->Execute();
		       // Get a SC reader
        FdoPtr<FdoISpatialContextReader> reader = getSpatialContexts->Execute();

        // Iterate ...
        while ( reader->ReadNext() )
        {
			reader->GetExtent();
		}

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

void CSuperMapGetSpatialContextsCommandTest::testExecute2()
{
	//�⾭γ���������
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"��γ����ϵ\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of GetSpatialContext:
		FdoPtr<FdoIGetSpatialContexts> getSpatialContexts = (FdoIGetSpatialContexts*)m_connection->CreateCommand(FdoCommandType_GetSpatialContexts);

        FdoPtr<FdoISpatialContextReader> reader = getSpatialContexts->Execute();

        // Iterate ...
        while ( reader->ReadNext() )
        {
			reader->GetExtent();
		}

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

void CSuperMapGetSpatialContextsCommandTest::testExecute3()
{
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"ͶӰ����ϵ\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of GetSpatialContext:
		FdoPtr<FdoIGetSpatialContexts> getSpatialContexts = (FdoIGetSpatialContexts*)m_connection->CreateCommand(FdoCommandType_GetSpatialContexts);

        FdoPtr<FdoISpatialContextReader> reader = getSpatialContexts->Execute();

        // Iterate ...
        while ( reader->ReadNext() )
        {
			reader->GetExtent();
		}

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