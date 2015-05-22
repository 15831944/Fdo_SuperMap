#include "StdAfx.h"
#include "SuperMapSelectTest.h"
#include "SMProviderSuite.h"
#include "FDOConnection.h"


CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(SuperMapSelectTest, SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> SuperMapSelectTest::m_connection = NULL;

SuperMapSelectTest::SuperMapSelectTest(void)
{
	
}

SuperMapSelectTest::~SuperMapSelectTest(void)
{

}
void SuperMapSelectTest::setUp ()
{
	if(m_connection == NULL)
	{
		m_connection = GetFDOConnection();
	}
}
void SuperMapSelectTest::tearDown ()
{
	if(NULL != m_connection)
	{
		m_connection->Close();
		m_connection = NULL;
	}
}

void SuperMapSelectTest::select_point()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"��");

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

	int count = 0;
	int SmID;
	int UserID;
	FdoPtr<FdoByteArray> geometry;

	try
	{
		while (ret->ReadNext ())
		{
			count++;
			if(!ret->IsNull(L"SmID"))
			{
				SmID = ret->GetInt32 (L"SmID");
			}
			if(!ret->IsNull(L"SmUserID"))
			{
				UserID = ret->GetInt32 (L"SmUserID");
			}
			if(!ret->IsNull(L"Geometry"))
			{
				geometry = ret->GetGeometry (L"Geometry");
			}
			CPPUNIT_ASSERT_MESSAGE ("���ζ������Ͳ���ȷ", FdoGeometryType_Point == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("δ��������ݼ��е�Ҫ��", 0 != count);
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
}

void SuperMapSelectTest::select_line()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"��");

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

	int count = 0;
	int SmID;
	int UserID;
	double Length;
	int ToPoError;
	FdoPtr<FdoByteArray> geometry;

	try
	{
		while (ret->ReadNext ())
		{
			count++;
			if(!ret->IsNull(L"SmID"))
			{
				SmID = ret->GetInt32 (L"SmID");
			}
			if(!ret->IsNull(L"SmUserID"))
			{
				UserID = ret->GetInt32 (L"SmUserID");
			}
			if(!ret->IsNull(L"SmLength"))
			{
				Length = ret->GetDouble (L"SmLength");
			}
			if(!ret->IsNull(L"SmTopoError"))
			{
				ToPoError = ret->GetInt32 (L"SmTopoError");
			}
			if(!ret->IsNull(L"Geometry"))
			{
				geometry = ret->GetGeometry (L"Geometry");
			}
			CPPUNIT_ASSERT_MESSAGE ("���ζ������Ͳ���ȷ", FdoGeometryType_MultiLineString == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("δ��������ݼ��е�Ҫ��", 0 != count);
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
}

void SuperMapSelectTest::select_region()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"��");

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

	int count = 0;
	int SmID;
	int UserID;
	double SmArea;
	double SmPerimeter;
	bool TestBoolen;
	short TestShort;
	float TestFloat;
	FdoString *str;
	FdoDateTime date;
	int length;
	FdoPtr<FdoByteArray> geometry;

	try
	{
		while (ret->ReadNext ())
		{
			count++;
			if(!ret->IsNull(L"SmID"))
			{
				SmID = ret->GetInt32 (L"SmID");
			}
			if(!ret->IsNull(L"SmUserID"))
			{
				UserID = ret->GetInt32 (L"SmUserID");
			}
			if(!ret->IsNull(L"SmArea"))
			{
				SmArea = ret->GetDouble (L"SmArea");
			}
			if(!ret->IsNull(L"SmPerimeter"))
			{
				SmPerimeter = ret->GetDouble (L"SmPerimeter");
			}
			if(!ret->IsNull(L"TestBoolen"))
			{
				TestBoolen = ret->GetBoolean (L"TestBoolen");
			}
			if(!ret->IsNull(L"TestShort"))
			{
				TestShort = ret->GetInt16(L"TestShort");
			}
			if(!ret->IsNull(L"TestFloat"))
			{
				TestFloat = ret->GetSingle(L"TestFloat");
			}
			if(!ret->IsNull(L"TestString"))
			{
				str = ret->GetString(L"TestString");
			}
			if(!ret->IsNull(L"TestDate"))
			{
				date = ret->GetDateTime(L"TestDate");
			}
			if(!ret->IsNull(L"����"))
			{
				length = ret->GetInt32(L"����");
			}
			if(!ret->IsNull(L"Geometry"))
			{
				geometry = ret->GetGeometry (L"Geometry");
			}
			CPPUNIT_ASSERT_MESSAGE ("���ζ������Ͳ���ȷ", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("δ��������ݼ��е�Ҫ��", 0 != count);
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
}

void SuperMapSelectTest::select_cad()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	if(Select)
	{
		Select->SetFeatureClassName(L"New_CAD");

		//���Զ��
		FdoString *strFilter = L"SmID = 34";
		Select->SetFilter( strFilter );

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

		int count = 0;
		int SmID;
		int UserID;

		FdoPtr<FdoByteArray> geometry;

		try
		{
			while (ret->ReadNext ())
			{
				count++;
				if(!ret->IsNull(L"SmID"))
				{
					SmID = ret->GetInt32 (L"SmID");
				}
				if(!ret->IsNull(L"SmUserID"))
				{
					UserID = ret->GetInt32 (L"SmUserID");
				}
				if(!ret->IsNull(L"Geometry"))
				{
					geometry = ret->GetGeometry (L"Geometry");
				}
				CPPUNIT_ASSERT_MESSAGE ("���ζ������Ͳ���ȷ", FdoGeometryType_MultiPoint == *(int*)geometry->GetData());
			}
			CPPUNIT_ASSERT_MESSAGE ("δ����������ݼ��е�Ҫ��", 0 != count);
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

		//���Զ���
		strFilter = L"SmID = 7";
		Select->SetFilter( strFilter );
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

		try
		{
			while (ret->ReadNext ())
			{
				count++;
				if(!ret->IsNull(L"SmID"))
				{
					SmID = ret->GetInt32 (L"SmID");
				}
				if(!ret->IsNull(L"SmUserID"))
				{
					UserID = ret->GetInt32 (L"SmUserID");
				}
				if(!ret->IsNull(L"Geometry"))
				{
					geometry = ret->GetGeometry (L"Geometry");
				}
				CPPUNIT_ASSERT_MESSAGE ("���ζ������Ͳ���ȷ", FdoGeometryType_MultiLineString == *(int*)geometry->GetData());
			}
			CPPUNIT_ASSERT_MESSAGE ("δ����������ݼ��е�Ҫ��", 0 != count);
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

		//������
		strFilter = L"SmID = 38";
		Select->SetFilter( strFilter );
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

		try
		{
			while (ret->ReadNext ())
			{
				count++;
				if(!ret->IsNull(L"SmID"))
				{
					SmID = ret->GetInt32 (L"SmID");
				}
				if(!ret->IsNull(L"SmUserID"))
				{
					UserID = ret->GetInt32 (L"SmUserID");
				}
				if(!ret->IsNull(L"Geometry"))
				{
					geometry = ret->GetGeometry (L"Geometry");
				}
				CPPUNIT_ASSERT_MESSAGE ("���ζ������Ͳ���ȷ", FdoGeometryType_Polygon == *(int*)geometry->GetData());
			}
			CPPUNIT_ASSERT_MESSAGE ("δ����������ݼ��е�Ҫ��", 0 != count);
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
	}
}

void SuperMapSelectTest::select_text()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	if(Select)
	{
		Select->SetFeatureClassName(L"�ı�");

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

		int count = 0;
		int SmID;
		int UserID;
        FdoString *Text;
		double TextSize;

		FdoPtr<FdoByteArray> geometry;

		try
		{
			while (ret->ReadNext ())
			{
				count++;
				if(!ret->IsNull(L"SmID"))
				{
					SmID = ret->GetInt32 (L"SmID");
				}
				if(!ret->IsNull(L"SmUserID"))
				{
					UserID = ret->GetInt32 (L"SmUserID");
				}
				if(!ret->IsNull(L"TxtString"))
				{
					Text = ret->GetString (L"TxtString");
				}
				if(!ret->IsNull(L"TextSize"))
				{
					TextSize = ret->GetDouble (L"TextSize");
				}

				if(!ret->IsNull(L"Geometry"))
				{
					geometry = ret->GetGeometry (L"Geometry");
				}
				CPPUNIT_ASSERT_MESSAGE ("���ζ������Ͳ���ȷ", FdoGeometryType_Point == *(int*)geometry->GetData());
			}
			CPPUNIT_ASSERT_MESSAGE ("δ��������ݼ��е�Ҫ��", 0 != count);
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
	}
}

void SuperMapSelectTest::select_sdb_boolean()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	if(Select)
	{
		Select->SetFeatureClassName(L"��");

		FdoString *strFilter = L"TestBoolen = true";
		Select->SetFilter( strFilter );

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

		int count = 0;
		int SmID;
		int UserID;
		bool TestBool = false;

		FdoPtr<FdoByteArray> geometry;

		try
		{
			while (ret->ReadNext ())
			{
				count++;
				if(!ret->IsNull(L"SmID"))
				{
					SmID = ret->GetInt32 (L"SmID");
				}
				if(!ret->IsNull(L"SmUserID"))
				{
					UserID = ret->GetInt32 (L"SmUserID");
				}
				if(!ret->IsNull(L"TestBoolen"))
				{
					TestBool = ret->GetBoolean (L"TestBoolen");
				}
				if(!ret->IsNull(L"Geometry"))
				{
					geometry = ret->GetGeometry (L"Geometry");
				}
				CPPUNIT_ASSERT_MESSAGE ("���ζ������Ͳ���ȷ", FdoGeometryType_Polygon == *(int*)geometry->GetData());
			}

			CPPUNIT_ASSERT_EQUAL(true, TestBool);
			CPPUNIT_ASSERT_MESSAGE ("δ��������ݼ��е�Ҫ��", 0 != count);
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
	}
}

void SuperMapSelectTest::select_sdb_date()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	if(Select)
	{
		Select->SetFeatureClassName(L"��");

		FdoString *strFilter = L"TestDate <= TIMESTAMP '2007-12-12 00:00:00'";
		Select->SetFilter( strFilter );

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

		int count = 0;
		int SmID;
		int UserID;
		FdoDateTime Date;

		FdoPtr<FdoByteArray> geometry;

		try
		{
			while (ret->ReadNext ())
			{
				count++;
				if(!ret->IsNull(L"SmID"))
				{
					SmID = ret->GetInt32 (L"SmID");
				}
				if(!ret->IsNull(L"SmUserID"))
				{
					UserID = ret->GetInt32 (L"SmUserID");
				}
				if(!ret->IsNull(L"TestDate"))
				{
					Date = ret->GetDateTime (L"TestDate");
				}
				if(!ret->IsNull(L"Geometry"))
				{
					geometry = ret->GetGeometry (L"Geometry");
				}
				CPPUNIT_ASSERT_MESSAGE ("���ζ������Ͳ���ȷ", FdoGeometryType_Polygon == *(int*)geometry->GetData());
			}

			CPPUNIT_ASSERT_MESSAGE ("δ��������ݼ��е�Ҫ��", 0 != count);
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
	}
}

void SuperMapSelectTest::select_no_featureclass()
{
	CPPUNIT_ASSERT_MESSAGE("FDO����δ��!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO�������ô�����Ϊ1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"");

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
}

int SuperMapSelectTest::GetRecordCount(char *strDataset, char *strFilter)
{
/*	int nRecCount = 0;
	UGC::UGDataSource *pDataSource = NULL;
	UGC::UGDatasetVector *pDataset = NULL;
	UGC::UGRecordset *pRecordset = NULL;
	FdoPtr<SuperMapConnection> superMapConn = (SuperMapConnection*)m_connection;
	pDataSource = superMapConn->GetDataSource();
	if(NULL != pDataSource)
	{
		pDataset = pDataSource->GetDataset(strDataset);
	}
	if(NULL != strDataset)
	{
		UGC::UGQueryDef querydef;
		querydef.m_strFilter = strFilter;
		pRecordset = strDataset->Query(querydef);
	}
	if(NULL != pRecordset)
	{
		nRecCount = pRecordset->GetRecordCount();
	}
	return nRecCount;
	*/
	return 0;
}