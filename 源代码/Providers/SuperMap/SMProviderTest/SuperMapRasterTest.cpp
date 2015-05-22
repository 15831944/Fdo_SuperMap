#include "StdAfx.h"
#include "SuperMapRasterTest.h"
#include "SMProviderSuite.h"
#include "FDOConnection.h"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(SuperMapRasterTest, SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> SuperMapRasterTest::m_connection = NULL;

SuperMapRasterTest::SuperMapRasterTest(void)
{

}

SuperMapRasterTest::~SuperMapRasterTest(void)
{

}

void SuperMapRasterTest::setUp ()
{
	if(m_connection == NULL)
	{
		m_connection = GetFDOConnection("sdb", true);
	}
}
void SuperMapRasterTest::tearDown ()
{
	if(NULL != m_connection)
	{
		m_connection->Close();
		m_connection = NULL;
	}
}

void SuperMapRasterTest::select_raster_1bit()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"T1λ");

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	CPPUNIT_ASSERT_MESSAGE("���ص�Ҫ�ؼ���Ϊ��!", ret != NULL);

	FdoPtr<FdoIRaster> Raster = NULL;
	FdoPtr<FdoBLOBStreamReader> Reader = NULL;
	FdoByte *buffer = NULL;
	buffer = new unsigned char[1024*768*3];
	int nReadCount = 0;

	try
	{
		Raster = ret->GetRaster(L"SuRaster");
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ�������Ϣ", NULL != Raster);

		Raster->GetDataModel();
		Raster->SetImageXSize(1024);
		Raster->SetImageYSize(768);
		Reader = (FdoBLOBStreamReader *)Raster->GetStreamReader();
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ������", NULL != Reader);

		nReadCount = Reader->ReadNext(buffer, 0, 1024*768*3);
		CPPUNIT_ASSERT_EQUAL(1024*768*3, nReadCount);

	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	delete buffer;
}

void SuperMapRasterTest::select_raster_4bit()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"T4λ");

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	CPPUNIT_ASSERT_MESSAGE("���ص�Ҫ�ؼ���Ϊ��!", ret != NULL);

	FdoPtr<FdoIRaster> Raster = NULL;
	FdoPtr<FdoBLOBStreamReader> Reader = NULL;
	FdoByte *buffer = NULL;
	buffer = new unsigned char[1024*768*3];
	int nReadCount = 0;

	try
	{
		Raster = ret->GetRaster(L"SuRaster");
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ�������Ϣ", NULL != Raster);

		Raster->GetDataModel();
		Raster->SetImageXSize(1024);
		Raster->SetImageYSize(768);
		Reader = (FdoBLOBStreamReader *)Raster->GetStreamReader();
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ������", NULL != Reader);

		nReadCount = Reader->ReadNext(buffer, 0, 1024*768*3);
		CPPUNIT_ASSERT_EQUAL(1024*768*3, nReadCount);

	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	delete buffer;

}

void SuperMapRasterTest::select_raster_8bit()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"T8λ");

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	CPPUNIT_ASSERT_MESSAGE("���ص�Ҫ�ؼ���Ϊ��!", ret != NULL);

	FdoPtr<FdoIRaster> Raster = NULL;
	FdoPtr<FdoBLOBStreamReader> Reader = NULL;
	FdoByte *buffer = NULL;
	buffer = new unsigned char[1024*768*3];
	int nReadCount = 0;

	try
	{
		Raster = ret->GetRaster(L"SuRaster");
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ�������Ϣ", NULL != Raster);

		Raster->GetDataModel();
		Raster->SetImageXSize(1024);
		Raster->SetImageYSize(768);
		Reader = (FdoBLOBStreamReader *)Raster->GetStreamReader();
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ������", NULL != Reader);

		nReadCount = Reader->ReadNext(buffer, 0, 1024*768*3);
		CPPUNIT_ASSERT_EQUAL(1024*768*3, nReadCount);

	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	delete buffer;

}

void SuperMapRasterTest::select_raster_16bit()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"T16λ");

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	CPPUNIT_ASSERT_MESSAGE("���ص�Ҫ�ؼ���Ϊ��!", ret != NULL);

	FdoPtr<FdoIRaster> Raster = NULL;
	FdoPtr<FdoBLOBStreamReader> Reader = NULL;
	FdoByte *buffer = NULL;
	buffer = new unsigned char[1024*768*3];
	int nReadCount = 0;

	try
	{
		Raster = ret->GetRaster(L"SuRaster");
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ�������Ϣ", NULL != Raster);

		Raster->GetDataModel();
		Raster->SetImageXSize(1024);
		Raster->SetImageYSize(768);
		Reader = (FdoBLOBStreamReader *)Raster->GetStreamReader();
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ������", NULL != Reader);

		nReadCount = Reader->ReadNext(buffer, 0, 1024*768*3);
		CPPUNIT_ASSERT_EQUAL(1024*768*3, nReadCount);

	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	delete buffer;
}

void SuperMapRasterTest::select_raster_24bit()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"T24λ");

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	CPPUNIT_ASSERT_MESSAGE("���ص�Ҫ�ؼ���Ϊ��!", ret != NULL);

	FdoPtr<FdoIRaster> Raster = NULL;
	FdoPtr<FdoBLOBStreamReader> Reader = NULL;
	FdoByte *buffer = NULL;
	buffer = new unsigned char[1024*768*3];
	int nReadCount = 0;

	try
	{
		Raster = ret->GetRaster(L"SuRaster");
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ�������Ϣ", NULL != Raster);

		Raster->GetDataModel();
		Raster->SetImageXSize(1024);
		Raster->SetImageYSize(768);
		Reader = (FdoBLOBStreamReader *)Raster->GetStreamReader();
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ������", NULL != Reader);

		nReadCount = Reader->ReadNext(buffer, 0, 1024*768*3);
		CPPUNIT_ASSERT_EQUAL(1024*768*3, nReadCount);

	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	delete buffer;

}

void SuperMapRasterTest::select_raster_32bit()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"T32λ");

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	CPPUNIT_ASSERT_MESSAGE("���ص�Ҫ�ؼ���Ϊ��!", ret != NULL);

	FdoPtr<FdoIRaster> Raster = NULL;
	FdoPtr<FdoBLOBStreamReader> Reader = NULL;
	FdoByte *buffer = NULL;
	buffer = new unsigned char[1024*768*4];
	int nReadCount = 0;

	try
	{
		Raster = ret->GetRaster(L"SuRaster");
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ�������Ϣ", NULL != Raster);

		Raster->GetDataModel();
		Raster->SetImageXSize(1024);
		Raster->SetImageYSize(768);
		Reader = (FdoBLOBStreamReader *)Raster->GetStreamReader();
		CPPUNIT_ASSERT_MESSAGE ("δȡ��Ӱ������", NULL != Reader);

		nReadCount = Reader->ReadNext(buffer, 0, 1024*768*4);
		CPPUNIT_ASSERT_EQUAL(1024*768*4, nReadCount);

	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(ex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
    catch(...)
    {
		CPPUNIT_FAIL("unresolved exception");
    }
	delete buffer;

}
