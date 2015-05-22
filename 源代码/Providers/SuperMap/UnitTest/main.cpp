#include <cstddef>
#include <string>
#include <iostream>
#include <tchar.h>
#include <windows.h>

// FDO Headers File
#include <FdoStd.h>
#include <FDO.h>
#include <FdoCommon.h>
#include <FdoGeometry.h>
#include <FdoMessage.h>
#include <SuperMapIniFile.h>

#include "fdoutility.h"
using namespace fdoutility;

/********************************************************************
	ת���ַ���
********************************************************************/
std::string WcharToString(const wchar_t* wstr)
{
	size_t		nSize;
	char	*ASCIITemp;

	nSize = _tcslen(wstr) * 2;

	ASCIITemp = (char*) malloc (nSize + 1);

	WideCharToMultiByte(
		CP_ACP, /* ANSI code page */
		0, /* no flags */
		wstr, /* wchar_t */
		(int)nSize,
		ASCIITemp,
		(int)nSize,
		NULL, /* Don't worry about other characters */
		NULL  /* Don't worry about other characters */
		);

	ASCIITemp[nSize] = '\0';

	std::string StringTemp(ASCIITemp);

	free(ASCIITemp);

	return StringTemp;
}

/*
#define RETURN_CHECK(x, msg) 	if(NULL == x){ std::cout << msg; return 0;}

#define CONFIG_SECTION	"ProviderConfig"

int _tmain()
{
	SuperMapIniFile inifile;
	inifile.Load("c:\\test.ini");
	inifile.AddSection(CONFIG_SECTION);

	FdoPtr<FdoProviderRegistry> registry = (FdoProviderRegistry *)FdoFeatureAccessManager::GetProviderRegistry();
 
	FdoStringP displayName;
	FdoStringP internalName;
	FdoStringP libraryPath;
	FdoPtr<FdoProvider> provider;
	int count = registry->GetProviders()->GetCount();
	for(int i = 0; i < count; i++) 
	{
		provider = registry->GetProviders()->GetItem(i);
		internalName = provider->GetName();
		displayName = provider->GetDisplayName();
		libraryPath = provider->GetLibraryPath();

		std::cout << "�ṩ�����ƣ�" << WcharToString(internalName) 
				<< "\n��ʾ�����ƣ�" <<  WcharToString(displayName)  
				<< "\n�ṩ�ߵĿ⣺" <<  WcharToString(libraryPath) 
				<< std::endl;
	}

	inifile.SetValue(CONFIG_SECTION, "ProviderName", WcharToString(internalName).c_str());
	inifile.SetValue(CONFIG_SECTION, "ProviderDisplayName", WcharToString(displayName).c_str());
	inifile.SetValue(CONFIG_SECTION, "ProviderLibraryPath", WcharToString(libraryPath).c_str());


	inifile.Save();
	inifile.ClearAll();

	inifile.Load("c:\\test.ini");

	std::cout << "---------------------------------------------" << std::endl;
	std::string strTemp1, strTemp2, strTemp3;
	inifile.GetValue(CONFIG_SECTION, "ProviderName", strTemp1,"");
	inifile.GetValue(CONFIG_SECTION, "ProviderDisplayName", strTemp2, "");
	inifile.GetValue(CONFIG_SECTION, "ProviderLibraryPath", strTemp3, "");

	std::cout << "�ṩ�����ƣ�" << strTemp1 
		<< "\n��ʾ�����ƣ�" <<  strTemp2 
		<< "\n�ṩ�ߵĿ⣺" <<  strTemp3
		<< std::endl;

	inifile.ClearAll();

	std::cout << "���� OSGeo.SuperMap.1.0 �ṩ�� ..." << std::endl;
	FdoPtr<FdoConnectionManager> connectMgr = (FdoConnectionManager *)FdoFeatureAccessManager::GetConnectionManager();
	FdoPtr<FdoIConnection> fdoConnection = connectMgr->CreateConnection(_T("OSGeo.SuperMap.1.0"));
	RETURN_CHECK(fdoConnection, "��������ʧ��... \n");

	FdoPtr<FdoIConnectionInfo> info = fdoConnection->GetConnectionInfo();
	RETURN_CHECK(info, "��ȡ������Ϣʧ��... \n");

	FdoPtr<FdoIConnectionPropertyDictionary> ConnDict = info->GetConnectionProperties();
	RETURN_CHECK(ConnDict, "��ȡ����������Ϣʧ��... \n");

	FdoInt32 nPropertyCount = 0;
	FdoString ** names = NULL;
	FdoStringP name;
	FdoStringP localname;
	FdoStringP val;
	FdoStringP defaultVal;
	bool isRequired = false;
	bool isProtected = false;
	bool isFilename = false;
	bool isFilepath = false;
	bool isDatastorename = false;
	bool isEnumerable = false;
	FdoInt32 enumCount = 0;
	FdoString ** enumNames = NULL;
	FdoStringP enumName;

	names = ConnDict->GetPropertyNames(nPropertyCount);
	for(int i = 0; i < nPropertyCount; i++)
	{
		name = names[i];
		val = ConnDict->GetProperty(name);
		defaultVal = ConnDict->GetPropertyDefault(name);
		localname = ConnDict->GetLocalizedName(name);
		isRequired = ConnDict->IsPropertyRequired(name);
		isProtected = ConnDict->IsPropertyProtected(name);
		isFilename = ConnDict->IsPropertyFileName(name);
		isFilepath = ConnDict->IsPropertyFilePath(name);
		isDatastorename = ConnDict->IsPropertyDatastoreName(name);
		isEnumerable = ConnDict->IsPropertyEnumerable(name);

		std::cout << "���ƣ�\t\t" << name 
				<< "\nĬ��ֵ��\t" <<  defaultVal 
				<< "\n�������ƣ�\t" <<  WcharToString(localname) 
				<< "\n���裺\t\t" <<  (isRequired?"��":"��") 
				<< "\n������\t\t" <<  (isProtected?"��":"��")  
				<< "\n�ļ���\t\t" <<  (isFilename?"��":"��")  
				<< "\n·����\t\t" <<  (isFilepath?"��":"��")  
				<< "\n���ݿ�����\t" <<  (isDatastorename?"��":"��")  
				<< "\n�о٣�\t\t" <<  (isEnumerable?"��":"��") 

				<< std::endl;

		if (isEnumerable) 
		{
			if (isRequired)
			{
				enumNames = ConnDict->EnumeratePropertyValues(name, enumCount);                                             
				for(int j = 0; j < enumCount; j++)
				{
					enumName = enumNames[j];
					std::cout << "�о����ƣ�" << enumName;
				}
				std::cout << std::endl;
			}
		}

	}

	ConnDict->SetProperty(_T("DataSource"), _T("c:\\world.sdb"));

	FdoConnectionState state = fdoConnection->Open();


	std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>��ʼִ��Select����\n";

	FdoPtr<FdoISelect> sampleSelect;
	sampleSelect = (FdoISelect *)fdoConnection->CreateCommand(FdoCommandType_Select);


	sampleSelect->SetFeatureClassName(L"SampleFeatureClass");

	// ����һ��������
	FdoPtr<FdoIdentifier> queryPropertyName;
	queryPropertyName = FdoIdentifier::Create(L"SampleIdentityDataProperty");

	// 2. ����FdoDataValue
	FdoPtr<FdoDataValue> queryPropertyValue;
	queryPropertyValue = FdoDataValue::Create(101);
	// 3. ���� FdoComparisonCondition::Create() �����ȽϹ�������

	FdoPtr<FdoFilter> filter;
	filter = FdoComparisonCondition::Create(queryPropertyName, FdoComparisonOperations_EqualTo, queryPropertyValue);
	sampleSelect->SetFilter(filter);
	// ִ�в�ѯ����
	FdoPtr<FdoIFeatureReader> queryResults;
	queryResults = sampleSelect->Execute();

	FdoPtr<FdoClassDefinition> classDef;
	FdoPtr<FdoPropertyDefinitionCollection> properties;
	FdoInt32 numProperties = 0;
	FdoPropertyDefinition * propertyDef;
	FdoPropertyType propertyType;
	FdoDataType dataType;
	FdoDataPropertyDefinition * dataPropertyDef;
	FdoString * propertyName = NULL;
	FdoPtr<FdoByteArray> byteArray;
	FdoIGeometry * geometry = NULL;
	FdoGeometryType geometryType = FdoGeometryType_None;
	FdoILineString * linestring = NULL;
	FdoIDirectPosition * position = NULL;
	FdoInt32 dimensionality = FdoDimensionality_XY;
	FdoInt32 numPositions = 0;
	FdoInt32 numInteriorRings = 0;

	// ѭ���������κ�����������Ϣ
	while (queryResults->ReadNext())
	{
		classDef = queryResults->GetClassDefinition();
		properties = classDef->GetProperties();
		
		numProperties = properties->GetCount();
		for(int i = 0; i < numProperties; i++) 
		{
			propertyDef = properties->GetItem(i);
			propertyName = propertyDef->GetName();
			propertyType = propertyDef->GetPropertyType();
			std::cout << "�����������ƣ�" <<  WcharToString(propertyName);
			switch (propertyType) 
			{
			case FdoPropertyType_DataProperty:
				dataPropertyDef = dynamic_cast<FdoDataPropertyDefinition *> (propertyDef);
				dataType = dataPropertyDef->GetDataType();
				switch (dataType) 
				{
				case FdoDataType_Boolean:
					break;
				case FdoDataType_Int32:
					std::cout << "\t�������ͣ�Int32" << "\t\tֵ��" << queryResults->GetInt32(propertyName) << std::endl;
					break;
				case FdoDataType_String:
					std::cout << "\t�������ͣ��ַ���" << "\tֵ��" << WcharToString(queryResults->GetString(propertyName)) << std::endl;
					break;
				default:
					break;
				}
				break;
			case FdoPropertyType_GeometricProperty:
				{
					FdoFgfGeometryFactory * geometryFactory = FdoFgfGeometryFactory::GetInstance();
					byteArray = queryResults->GetGeometry(propertyName);
					geometry = geometryFactory->CreateGeometryFromFgf (byteArray);
					geometryType = geometry->GetDerivedType();
		
					switch (geometryType) 
					{
						case FdoGeometryType_None:
							break;
						case FdoGeometryType_Point:
							std::cout << "\t�����������ͣ���\n" ;
							break;
						case FdoGeometryType_LineString:
							std::cout << "\t�����������ͣ���" ;

							linestring = dynamic_cast<FdoILineString *>(geometry);
							numPositions = linestring->GetCount();

							std::cout << "\t����" <<  numPositions << "��\n";
							double X, Y, Z, M;
							Z = M = 0;

							for(int i = 0; i < numPositions; i++) 
							{
								position = linestring->GetItem(i);
								if (dimensionality & FdoDimensionality_Z && dimensionality & FdoDimensionality_M)
								{
									X = position->GetX();
									Y = position->GetY();
									Z = position->GetZ();
									M = position->GetM();

								}
								else if (dimensionality & FdoDimensionality_Z && !(dimensionality & FdoDimensionality_M)) 
								{
									X = position->GetX();
									Y = position->GetY();
									Z = position->GetZ();
								}
								else
								{
									X = position->GetX();
									Y = position->GetY();
								}

								std::cout << "X=" << X << "\tY=" << Y << "\tZ=" << Z << "\n";
							}
							break;
						case FdoGeometryType_Polygon:
							std::cout << "\t�����������ͣ���\n" ;
							break;
						case FdoGeometryType_MultiPoint:
							break;
						case FdoGeometryType_MultiLineString:
							break;
						case FdoGeometryType_MultiPolygon:
							break;
						case FdoGeometryType_MultiGeometry:
							break;
						case FdoGeometryType_CurveString:
							break;
						case FdoGeometryType_CurvePolygon:
							break;
						case FdoGeometryType_MultiCurveString:
							break;
						case FdoGeometryType_MultiCurvePolygon:
							break;
						default:
							break;
					}
				}
				
			}
		}
	}
	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<����ִ��Select����\n";


	return 0;
}

*/




int _tmain()
{
	try
	{
		std::wstring provider(L"SuperMap.SuperMap SDX.1.0");

		// Create connection
		FdoPtr<FdoIConnection> conn = fdoutility::create_connection(provider);

		// Connection string with datastore specified
		FdoPtr<FdoIConnectionInfo> info = conn->GetConnectionInfo();

		FdoPtr<FdoIConnectionPropertyDictionary> ConnDict = info->GetConnectionProperties();


		//ConnDict->SetProperty(_T("DataSource"), _T("type=sql;server=192.168.1.76;database=test1;user=fdo;password=fdo;IsImage=false"));
		ConnDict->SetProperty(_T("DataSource"), _T("type=sdb;database=C:\\sdbguass.sdb;IsImage=false"));

		// Open connection
		FdoConnectionState state = conn->Open();

		std::wcout <<  "FdoIConnection::Open()\n";
		std::wcout <<  " State: " << conn->GetConnectionState() << std::endl;

		// Close connection (usually optional)
		conn->Close();

		std::wcout <<  "FdoIConnection::Close()\n";
		std::wcout <<  " State: " << conn->GetConnectionState() << std::endl;
	}
	catch (FdoException* ex)
	{
		std::wcout << L"*** FDO Error:\n";
		int i = 5;
		FdoException* nex = ex;
		while (nex)
		{
			const wchar_t* msg = nex->GetExceptionMessage();
			if (NULL == msg)
			{
				msg = L"NO MESSAGE";
			}
			std::wcout << std::setw(++i) << L"*** " << msg << std::endl;
			nex = nex->GetCause();
		}
		ex->Release();
	}
	catch(std::exception& ex)
	{
		std::cout << "*** Std Error: " << ex.what() << std::endl;
	}
	catch(...)
	{
		std::cout << "*** Undefined error!\n" << std::endl;
	}
	return 0;
}








