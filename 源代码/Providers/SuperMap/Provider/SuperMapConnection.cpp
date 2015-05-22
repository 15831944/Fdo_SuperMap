/** \file	 SuperMapConnection.cpp
*  \author	 ����
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-09-19
*  \note : modified by zhouxu 2007-10-23
*/

#include <malloc.h>
#include <string.h>

#include <SuperMap.h>
#define __SUPERMAP_MESSAGE_DEFINE__
#include <../Message/Inc/SuperMapMessage.h>

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <windows.h>
#include <crtdbg.h>

#include <limits.h>
#undef min
#undef max

static wchar_t module[MAX_PATH];
static wchar_t home_dir[MAX_PATH];

wchar_t home_path[MAX_PATH]; //

/// <summary>
/// Calls on the FDO Client services to register the SuperMap SDB/SDX provider.
/// Use dynamic proc address binding because there will not be a path set up yet.
/// </summary>
/// <returns>S_FALSE if there was an error, S_OK otherwise.</returns> 
extern "C" FDO_SUPERMAP_API HRESULT DllRegisterServer ()
{
    HRESULT ret;
	
	ret = S_FALSE;
    // Find a matching provider in the Provider Registry.
    IProviderRegistry* registry = FdoFeatureAccessManager::GetProviderRegistry();

    registry->RegisterProvider (
        SUPERMAP_PROVIDER_NAME,
        /*WTEXT(SUPERMAP_PROVIDER_DEFAULT_DISPLAY_NAME),*/
		NlsMsgGet(SUPERMAP_PROVIDER_DISPLAY_NAME, SUPERMAP_PROVIDER_DEFAULT_DISPLAY_NAME),
		/*WTEXT(SUPERMAP_PROVIDER_DEFAULT_DESCRIPTION),*/
		NlsMsgGet(SUPERMAP_PROVIDER_DESCRIPTION, SUPERMAP_PROVIDER_DEFAULT_DESCRIPTION),
        SUPERMAP_PROVIDER_VERSION,
        SUPERMAP_FDO_VERSION,
        module,
        false);
    ret = S_OK;

    return (ret);
}

/// <summary>
/// Calls on the FDO Client services to unregister the SuperMap SDB/SDX provider.
/// Use dynamic proc address binding because there will not be a path set up yet.
/// </summary>
/// <returns>S_FALSE if there was an error, S_OK otherwise.</returns> 
extern "C" FDO_SUPERMAP_API HRESULT DllUnregisterServer ()
{
    // Find a matching provider in the Provider Registry.
    IProviderRegistry* registry = FdoFeatureAccessManager::GetProviderRegistry();
	registry->UnregisterProvider (SUPERMAP_PROVIDER_NAME);
	return S_OK;
}


BOOL APIENTRY DllMain (HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	DWORD nchars;
	wchar_t* last;
	BOOL ret;

	// UNCOMMENT THE FOLLOWING CODE TO HELP DISCOVER MEMORY LEAKS OR PREMATURE MEMORY DEALLOCATIONS;
	// WARNING: THIS CAN MAKE THE CODE RUN EXTREMELY SLOWLY IN CERTAIN PLACES!
	//
	//int debugFlags = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	//_CrtSetDbgFlag(debugFlags | _CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF);

	ret = TRUE;
	if (DLL_PROCESS_ATTACH == ul_reason_for_call)
	{
		// hModule - The value is the base address of the DLL.
		// The HINSTANCE of a DLL is the same as the HMODULE of the DLL,
		// so hinstDLL can be used in calls to functions that require a module handle.
		nchars = GetModuleFileNameW ((HINSTANCE)hModule, module, MAX_PATH);
		if (0 == nchars)
			ret = FALSE;
		else
		{   
			// scan the string for the last occurrence of a slash
			wcscpy (home_dir, module);
			last = wcsrchr (home_dir, L'\\');
			if (NULL == last)
				ret = FALSE;
			else
			{
				last++; // move past the slash
				*last = L'\0'; // null terminate it there
			}
		}

		TRACE(_T("�������ӳ�"));
		// �������ӳ�
		SuperMapConnectionPool::GetInstance();

		// ��ʼ��������Ϣ
		wcscpy(home_path,home_dir);
		SuperMapConfig::Init();
	}
	else if(DLL_PROCESS_DETACH == ul_reason_for_call)
	{
		// ɾ��
		SuperMapConnectionPool::GetInstance()->Dispose();
	}

	return (ret);
}
#endif // _WIN32


// external access to connection for client services
extern "C" FDO_SUPERMAP_API FdoIConnection* CreateConnection ()
{
	return (new SuperMapConnection ());
}


SuperMapConnection::SuperMapConnection (void):
	m_ConnectionString ((wchar_t*)NULL),
	m_ConnectionState(FdoConnectionState_Closed)
	//m_pTransaction(NULL)
{
	m_strConnectionSession = "";
	m_bCreate = false;
}

SuperMapConnection::~SuperMapConnection (void)
{
    Close ();
}

// <summary>Dispose this object.</summary>
// <returns>Returns nothing</returns> 
void SuperMapConnection::Dispose ()
{
	delete this;
}

/// <summary>Gets an FdoIConnectionCapabilities interface describing the capabilities
/// of the connection.</summary>
/// <returns>Returns the connection capabilities</returns> 
FdoIConnectionCapabilities* SuperMapConnection::GetConnectionCapabilities ()
{
	TRACE(_T("���� SuperMapConnection::GetConnectionCapabilities ��\n"));
	return (new SuperMapConnectionCapabilities ());
}

/// <summary>Gets an FdoISchemaCapabilities interface describing the provider's support for the feature schema.</summary>
/// <returns>Returns schema capabilities</returns> 
FdoISchemaCapabilities* SuperMapConnection::GetSchemaCapabilities ()
{
	TRACE(_T("���� SuperMapConnection::GetSchemaCapabilities ��\n"));
	return (new SuperMapSchemaCapabilities ());
}

/// <summary>Gets an FdoICommandCapabilities interface describing the commands a provider supports.</summary>
/// <returns>Returns the command capabilities</returns> 
FdoICommandCapabilities* SuperMapConnection::GetCommandCapabilities ()
{
	TRACE(_T("���� SuperMapConnection::GetCommandCapabilities ��\n"));
	return (new SuperMapCommandCapabilities ());
}

/// <summary>Gets an FdoIFilterCapabilities interface describing the provider's support for filters.</summary>
/// <returns>Returns the filter capabilities</returns> 
FdoIFilterCapabilities* SuperMapConnection::GetFilterCapabilities ()
{
	TRACE(_T("���� SuperMapConnection::GetFilterCapabilities ��\n"));
	return (new SuperMapFilterCapabilities ());
}

/// <summary>Gets an FdoIExpressionCapabilities interface describing the provider's support for expressions.</summary>
/// <returns>Returns the expression capabilities</returns> 
FdoIExpressionCapabilities* SuperMapConnection::GetExpressionCapabilities ()
{
	TRACE(_T("���� SuperMapConnection::GetExpressionCapabilities ��\n"));
	return (new SuperMapExpressionCapabilities ());
}

/// <summary>Gets an FdoIRasterCapabilities interface describing the provider's support for raster images.</summary>
/// <returns>Returns the raster capabilities</returns> 
FdoIRasterCapabilities* SuperMapConnection::GetRasterCapabilities (void)
{
	TRACE(_T("���� SuperMapConnection::GetRasterCapabilities ��\n"));
	return (new SuperMapRasterCapabilities ());
}

/// <summary>Gets an FdoITopologyCapabilities interface describing the provider's support for topology.</summary>
/// <returns>Returns the topology capabilities</returns> 
FdoITopologyCapabilities* SuperMapConnection::GetTopologyCapabilities ()
{
	TRACE(_T("���� SuperMapConnection::GetTopologyCapabilities ��\n"));
	return (new SuperMapTopologyCapabilities ());
}


/// Gets an FdoIGeometryCapabilities interface describing the provider's support for geometry
FdoIGeometryCapabilities* SuperMapConnection::GetGeometryCapabilities()
{
	TRACE(_T("���� SuperMapConnection::GetGeometryCapabilities ��\n"));
	return (new SuperMapGeometryCapabilities());
}

/// <summary>Gets the connection string used to open a DataStore.</summary>
/// <returns>Returns the connection string</returns> 
FdoString* SuperMapConnection::GetConnectionString ()
{
	TRACE(_T("���� SuperMapConnection::GetConnectionString [%ls]��\n"), m_ConnectionString);
	return (m_ConnectionString);
}

/// <summary>Sets the connection string used to open a DataStore. SetConnectionString can only be set while the
/// connection is closed.</summary>
/// <param name="value">Input the connection string</param> 
/// <returns>Returns nothing</returns> 
void SuperMapConnection::SetConnectionString (FdoString* value)
{
	TRACE(_T("���� SuperMapConnection::SetConnectionString(%ls)��\n"), value);
	FdoConnectionState state = GetConnectionState();
	if (state == FdoConnectionState_Closed || state == FdoConnectionState_Pending)
	{
		// Update the connection string:
		m_ConnectionString = value;

		// Update the connection property dictionary:
		FdoPtr<FdoIConnectionInfo> connInfo = GetConnectionInfo();
		FdoPtr<FdoCommonConnPropDictionary> connDict = dynamic_cast<FdoCommonConnPropDictionary*>(connInfo->GetConnectionProperties());
		connDict->UpdateFromConnectionString(m_ConnectionString);
	}
	else
		throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_ALREADY_OPEN, "The connection is already open."));
}

/// <summary>Gets an FdoIConnectionInfo interface that can be used to interrogate and set connection properties.</summary>
/// <returns>Returns the connection info</returns> 
FdoIConnectionInfo* SuperMapConnection::GetConnectionInfo ()
{
	if (m_ConnectionInfo == NULL)
		m_ConnectionInfo = new SuperMapConnectionInfo (this);
	return FDO_SAFE_ADDREF(m_ConnectionInfo.p);
}

/// <summary>Gets the current state of the connection.</summary>
/// <returns>Returns the current state of the connection</returns> 
FdoConnectionState SuperMapConnection::GetConnectionState ()
{
	TRACE(_T("���� SuperMapConnection::GetConnectionState ����[0:Busy,1:Closed,2:Open,3:Pending] %d��\n"), m_ConnectionState);
	return (m_ConnectionState);
}

/// <summary>Gets the number of milliseconds to wait while trying to establish a
/// connection before terminating the attempt and generating an error. If
/// the provider does not support the timeout capability 0 will be returned</summary>
/// <returns>Returns the time to wait (in milliseconds)</returns> 
FdoInt32 SuperMapConnection::GetConnectionTimeout ()
{
	return (0);
}

/// <summary>Sets the number of milliseconds to wait while trying to establish a
/// connection before terminating the attempt and generating an error. If
/// the provider does not support the timeout capability then attempting to
/// set a timeout will result in an exception</summary>
/// <param name="value">Input the time to wait (in milliseconds)</param> 
/// <returns>Returns nothing</returns> 
void SuperMapConnection::SetConnectionTimeout (FdoInt32 value)
{
	throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_TIMEOUT_UNSUPPORTED, 
		"Connection timeout is not supported."));
}


/// <summary>Opens a feature connection with the settings specified by the
/// ConnectionString attribute of the provider-specific feature connection
/// object.</summary>
/// <returns>Returns nothing</returns> 
FdoConnectionState SuperMapConnection::Open ()
{
	TRACE(_T("���� SuperMapConnection::Open ...\n"));

	if (GetConnectionState() == FdoConnectionState_Open)
		throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_103_CONNECTION_ALREADY_OPEN)));

	// Disconnect if currently 'partially' connected (but not if already 'fully' connected):
	if (GetConnectionState() == FdoConnectionState_Pending)
		Close();
	
	/* DEL *****************************************
	FdoPtr<ConnectionProperty> datastoreProperty = dictionary->FindProperty(CONNECTIONPROPERTY_DATASTORE);
	// Create an enum list with a single "Default Datastore" entry:
	wchar_t **enumArray = new wchar_t*[1];
	enumArray[0] = new wchar_t[wcslen(L"����")+1];
	wcscpy(enumArray[0], L"����");
	datastoreProperty->UpdateEnumerableProperties(1, (const wchar_t**)enumArray);

	if (FdoConnectionState_Pending == GetConnectionState ())
		datastoreProperty->SetIsPropertyRequired (true);
	************************************************/

	m_strConnectionSession = SuperMapConnectionPool::GetInstance()->GetConnectionInfo(this);
	if (m_strConnectionSession != "")
		m_ConnectionState = FdoConnectionState_Open;
	else
		m_ConnectionState = FdoConnectionState_Closed;

	return (GetConnectionState ());
}

/// <summary>Closes the connection to the DataStore</summary>
/// <returns>Returns nothing</returns> 
void SuperMapConnection::Close ()
{
	if (m_ConnectionState == FdoConnectionState_Closed)
		return ;

	TRACE(_T("���� SuperMapConnection::Close ...\n"));
	// Clear the LogicalPhysical/physical/override caches:  // Todo �����������е�ָ���Ա�������� 
	m_LpSchemas = NULL;

	// Reset the Spatial Contexts collection. Create the default SC.
	/*m_SpatialContextColl = new SuperMapSpatialContextCollection();
	FdoPtr<SuperMapSpatialContext> defltSpatialContext = new SuperMapSpatialContext();
	m_SpatialContextColl->Add(defltSpatialContext);*/
	m_SpatialContextColl = NULL;

	// Clear the Datastore connection property's enumerated list of datastores:

	// ���ӶϿ�ʱ�ر��Ѵ򿪵�����Դ
	SuperMapConnectionPool::GetInstance()->CloseDataSource(this->m_strConnectionSession);

	m_ConnectionState = FdoConnectionState_Closed;
	this->m_strConnectionSession = "";
}

/// <summary>Begins a transaction and returns an object that realizes
/// FdoITransaction.</summary>
/// <returns>Returns the transaction</returns> 
FdoITransaction* SuperMapConnection::BeginTransaction ()
{
	TRACE(_T("���� SuperMapConnection::BeginTransaction ...\n"));
	throw FdoException::Create(NlsMsgGet(SUPERMAP_CONNECTION_TRANSACTIONS_NOT_SUPPORTED, 
		"SuperMap Provider does not support transactions."));

    //if (m_pTransaction != NULL)	// �ж��Ƿ���Ƕ������
    //    throw FdoException::Create(NlsMsgGet(SUPERMAP_NESTED_TRANSACTIONS_NOT_SUPPORTED, "Nested transactions are not supported."));
    //m_pTransaction = new SuperMapTransaction ();
    //// the connection holds a hard reference to the transaction
    //// the transaction holds a soft reference to the connection
    //m_pTransaction->AddRef ();
    //m_pTransaction->SetConnection (this);

    //return (m_pTransaction);
}

void SuperMapConnection::EndTransaction ()
{
	TRACE(_T("���� SuperMapConnection::EndTransaction ...\n"));
	//if (NULL != m_pTransaction)
	//{
	//	m_pTransaction->SetConnection(NULL);
	//	m_pTransaction->Release ();			// ����ȷ��BeginTransaction ���غ�����ô��ʹ�����������ֶ������ơ�
	//	m_pTransaction = NULL;
	//}
}

/// <summary>Creates and returns the specified type of command object associated with
/// the connection.</summary>
/// <param name="commandType">Input the command type to be created</param> 
/// <returns>Returns the command</returns> 
FdoICommand* SuperMapConnection::CreateCommand (FdoInt32 commandType)
{

	FdoPtr<FdoICommand> ret = NULL;

	if ((GetConnectionState() == FdoConnectionState_Closed) || (GetConnectionState() == FdoConnectionState_Pending))
		throw FdoException::Create(NlsMsgGet(SUPERMAP_CONNECTION_INVALID, "Connection is invalid."));
	switch (commandType)
	{
	case FdoCommandType_Select:
		TRACE(_T("���� SuperMapConnection::CreateCommand:Select\n"));
		ret = new SuperMapSelectCommand (this);
		break;
	case FdoCommandType_SelectAggregates:
		TRACE(_T("���� SuperMapConnection::CreateCommand:SelectAggregates\n"));
		//ret = new SuperMapSelectAggregatesCommand (this);
		break;
	case FdoCommandType_DescribeSchema:
		ret = new SuperMapDescribeSchemaCommand (this);
		TRACE(_T("���� SuperMapConnection::CreateCommand:DescribeSchema\n"));
		break;
	case FdoCommandType_DescribeSchemaMapping:
		//ret = new SuperMapDescribeSchemaMappingCommand (this);
		TRACE(_T("���� SuperMapConnection::CreateCommand:DescribeSchemaMapping\n"));
		break;
	case FdoCommandType_GetSpatialContexts:
		ret = new SuperMapGetSpatialContextsCommand (this);
		TRACE(_T("���� SuperMapConnection::CreateCommand:GetSpatialContexts\n"));
		break;
	case FdoCommandType_CreateSpatialContext:
		ret = new SuperMapCreateSpatialContextCommand (this);
		TRACE(_T("���� SuperMapConnection::CreateCommand:CreateSpatialContext\n"));
		break;
	case FdoCommandType_Insert:
		ret = new SuperMapInsertCommand (this);
		TRACE(_T("���� SuperMapConnection::CreateCommand:Insert\n"));
		break;
	case FdoCommandType_Update:
		ret = new SuperMapUpdateCommand (this);
		TRACE(_T("���� SuperMapConnection::CreateCommand:Update\n"));
		break;
	case FdoCommandType_Delete:
		ret = new SuperMapDeleteCommand (this);
		TRACE(_T("���� SuperMapConnection::CreateCommand:Delete\n"));
		break;
	case FdoCommandType_ApplySchema:
		ret = new SuperMapApplySchemaCommand (this);
		TRACE(_T("���� SuperMapConnection::CreateCommand:ApplySchema\n"));
		break;
	case FdoCommandType_DestroySchema:
		ret = new SuperMapDestroySchemaCommand (this);
		TRACE(_T("���� SuperMapConnection::CreateCommand:DestroySchema\n"));
		break;
	case FdoCommandType_CreateDataStore:
		//ret = new SuperMapCreateDataStoreCommand (this);
		TRACE(_T("���� SuperMapConnection::CreateCommand:CreateDataStore\n"));
		break;

	default:
		throw FdoException::Create (FdoException::NLSGetMessage (FDO_102_COMMAND_NOT_SUPPORTED, 
			"The command '%1$ls' is not supported.", 
			(FdoString*)(FdoCommonMiscUtil::FdoCommandTypeToString (commandType))));
	}

	return (FDO_SAFE_ADDREF (ret.p));
}


/// <summary>Factory function that creates an empty Schema Override set specific
/// to this FDO Provider.</summary>
/// <returns>Returns FdoPhysicalSchemaMapping</returns> 
FdoPhysicalSchemaMapping* SuperMapConnection::CreateSchemaMapping()
{
	//FdoSuperMapOvPhysicalSchemaMappingP newPhysicalSchemaMapping = FdoSuperMapOvPhysicalSchemaMapping::Create();
	//return FDO_SAFE_ADDREF(newPhysicalSchemaMapping.p);
	TRACE(_T("���� SuperMapConnection::CreateSchemaMapping ...\n"));
	return NULL;
}


/// <summary>Sets the XML configuration stream used to configure the Data Store. 
/// SetConfiguration can only be called while the connection is closed.</summary>
/// <param name="configStream">Input the XML configuration stream</param> 
/// <returns>Returns nothing</returns> 
void SuperMapConnection::SetConfiguration(FdoIoStream* configStream)
{
	TRACE(_T("!!!���� SuperMapConnection::SetConfiguration ...\n"));

	throw FdoException::Create(NlsMsgGet(SUPERMAP_CONFIGURATION_FILE_NOT_SUPPORTED, 
		"SuperMap Provider does not support configuration files."));
}

void SuperMapConnection::Flush()
{
	TRACE(_T("���� SuperMapConnection::Flush ...\n"));
	
	FdoPtr<SuperMapLpFeatureSchemaCollection> schemas = GetLpSchemas();
	int count = schemas->GetCount();

	for(int i = 0; i < count; ++i)
	{
		FdoPtr<SuperMapLpFeatureSchema> lpSchema = schemas->GetItem(i);
		FdoPtr<SuperMapLpClassDefinitionCollection> classes = lpSchema->GetLpClasses();
		int class_count = classes->GetCount();

		for(int j = 0; j < class_count; ++j)
		{
			FdoPtr<SuperMapLpClassDefinition> lpClass = classes->GetItem(j);
			UGC::UGDataset* pDataset = lpClass->GetDataset();

			//��ͬ���ķ�ʽ�򿪸����ݼ���ʹ�����
			pDataset->Open();
		}
	}
}

UGC::UGDataSource* SuperMapConnection::GetDataSource()
{
	UGC::UGDataSource* ds = SuperMapConnectionPool::GetInstance()->GetDataSource(m_strConnectionSession);
	VALIDATE_POINTER(ds);
	return ds;
}

bool SuperMapConnection::IsOnlyConnectImage()
{
	return SuperMapConnectionPool::GetInstance()->IsImage(m_strConnectionSession);
}


SuperMapLpFeatureSchemaCollection* SuperMapConnection::GetLpSchemas()
{
	TRACE(_T("��ʼ���� SuperMapConnection::GetLpSchemas() ��\n"));
	//��һ�ε���ʱ���߼�����ģʽ��ʼ������ʼ���ɹ����ֻ��ֱ�ӷ��ء�
	if(m_LpSchemas == NULL)
	{
		TRACE(_T("���� SuperMapConnection::GetLpSchemas():�߼�����ģʽΪ�� ��\n"));
		UGC::UGDataSource* pDataSource = GetDataSource();
		m_LpSchemas = new SuperMapLpFeatureSchemaCollection(
			this, pDataSource);
	}
	TRACE(_T("�������� SuperMapConnection::GetLpSchemas() ��\n"));
	return FDO_SAFE_ADDREF(m_LpSchemas.p);
}

SuperMapSpatialContextCollection* SuperMapConnection::GetSpatialContexts()
{
	TRACE(_T("��ʼ���� SuperMapConnection::GetSpatialContexts() ��\n"));
	if(m_SpatialContextColl == NULL)
	{
		// ͨ����������Դ��ʼ���ռ������б�
		FdoStringP strName;
		FdoStringP strDescription;
		FdoStringP strCoordSysName;

		UGC::EmSpatialRefType eType;             //  �ռ���������
		FdoStringP strDatumName ;           //  ��׼���� DATUM
		FdoStringP strSpheroidName ;        //  ��������
		double dSemiMajor;                       //  �����峤���᳤��
		double dInvflattening;                   //  ��������ʵ��� 
		FdoStringP strPrimeMeridian ;       //  ���������ߣ�0�Ⱦ��ߣ�ͨ��Ϊ"Greenwich"
		FdoStringP GeoUnit ;                //  ����λ
		FdoStringP GeoUnitFactor ;          //  ����λ����ϵ��
		FdoStringP Unit ;                   //  ��λ
		FdoStringP UnitFactor ;             //  ��λ����ϵ��
		
		FdoPtr<SuperMapSpatialContext> pSpatialContext = new SuperMapSpatialContext(); 
		
		// ��γ�������ͶӰ���궼Ҫȡ�Ĺ�������
		UGC::UGPrjCoordSys prjCoordSys = GetDataSource()->GetPrjCoordSys();
		strName = prjCoordSys.GetName();
		
		eType = prjCoordSys.GetSpatialRefType();
		UGC::UGGeoCoordSys geoCoordSys = prjCoordSys.GetGeoCoordSys(); // ��ȡ����������Ϣ
		strCoordSysName = geoCoordSys.GetName();
		UGC::UGHorizonDatum datum = geoCoordSys.GetHorizonDatum();   // ��ȡ��׼����Ϣ
		strDatumName = datum.GetDatumName();
		UGC::UGSpheroid spheroid = datum.GetSpheroid();  // ��ȡ��������Ϣ
		strSpheroidName = spheroid.GetName();
		dSemiMajor = spheroid.GetAxis();
		dInvflattening = 1/(spheroid.GetFlatten());
		UGC::UGPrimeMeridian prmMeridian = geoCoordSys.GetPrimeMeridian();        // ��ȡ������������Ϣ
		strPrimeMeridian = prmMeridian.GetName();

		// ��ȡ����λ�͵���λϵ��
		switch(geoCoordSys.GetUnit())
		{
			// �Ƕȵ�λ���㵽���ȵ�λ
		case AU_DEGREE:
			GeoUnit = L"Degree";
			GeoUnitFactor = L"0.01745329";
			break;
		case AU_RADIAN:
			GeoUnit = L"Radian";
			GeoUnitFactor = L"1.00000000";
			break;
		case AU_MINUTE:
			GeoUnit = L"Minute";
			GeoUnitFactor = L"0.00029089";
			break;
		case AU_SECOND:
			GeoUnit = L"Second";
			GeoUnitFactor = L"0.00000485";
			break;
		case AU_GRAD:
			GeoUnit = L"Gard";
			GeoUnitFactor = L"0.01570796";
			break;
		case AU_MICRORADIAN:
			GeoUnit = L"MicroRadian";
			GeoUnitFactor = L"0.00000100";
			break;
		case AU_MINUTE_CENTESIMAL:
			GeoUnit = L"Minute_Centesimal";
			GeoUnitFactor = L"0.00015708";
			break;
		case AU_SECOND_CENTESIMAL:
			GeoUnit = L"Second_Centesimal";
			GeoUnitFactor = L"0.00000157";
			break;
		case AU_MIL_6400:
			GeoUnit = L"Mil_6400";
			GeoUnitFactor = L"0.00098175";
			break;
		}
		// ͶӰ���굥λ
		switch(prjCoordSys.GetUnit())
		{
		// ���ȵ�λ���㵽��
		case AU_MM:
			Unit = L"MILLIMETER";
			UnitFactor = L"0.001";
			break;
		case AU_CM:
			Unit = L"CENTIMETER";
			UnitFactor = L"0.01";
			break;
		case AU_DM:
			Unit = L"DECIMETER";
			UnitFactor = L"0.10";
			break;
		case AU_M:
			Unit = L"METER";
			UnitFactor = L"1.0";
			break;
		case AU_KM:
			Unit = L"KILOMETER";
			UnitFactor = L"1000.00";
			break;
		case AU_MI:
			Unit = L"MILE";
			UnitFactor = L"1609.31";
			break;
		case AU_IN:
			Unit = L"INCH";
			UnitFactor = L"0.0254";
			break;
		case AU_YARD:
			Unit = L"YARD";
			UnitFactor = L"0.9144";
			break;
		case AU_FT:
			Unit = L"FOOT";
			UnitFactor = L"0.3048";
			break;
		default:
			Unit = L"";
			UnitFactor = L"";
		}
		

		if(eType == UGC::SPATIALREF_EARTH_PROJECTION) // �����ͶӰ����ϵ����ȡ���ͶӰ������
		{
			UGC::UGProjection projection = prjCoordSys.GetProjection();
			pSpatialContext->m_ProjectName = projection.GetProjectionName();
			UGC::UGPrjParams prjParams = prjCoordSys.GetPrjParams();
			//��Ҫ��ֵ��ͶӰ������
			//double m_dFalseEasting;			//  0 False easting (X0)
			//double m_dFalseNorthing;		//  1 False northing (Y0)
			//double m_dCentralMeridian;		//  2 Central meridian, Longitude of origin (LON0)
			//double m_dCentralParallel;		//  6 Central parallel, Latitude of origin	(LAT0)

			//double m_dStandardParallel1;	//  3 Standard parallel 1, Latitude of 1st point (LAT1)
			//double m_dStandardParallel2;	//  4 Standard parallel 2, Latitude of 2nd point (LAT2)

			//double m_dScaleFactor;			//  5 Scale factor
			//double m_dAzimuth;				//  7 Azimuth

			//double m_dFirstPointLongitude;		//  8 Longitude of 1st point (LON1)
			//double m_dSecondPointLongitude;		//  9 Longitude of 2nd point  (LON2)
			pSpatialContext->m_dFalseEasting = prjParams.m_dFalseEasting;
			pSpatialContext->m_dFalseNorthing = prjParams.m_dFalseNorthing;
			pSpatialContext->m_dCentralMeridian = prjParams.m_dCentralMeridian;
			pSpatialContext->m_dCentralParallel = prjParams.m_dCentralParallel;
			pSpatialContext->m_dStandardParallel1 = prjParams.m_dStandardParallel1;
			pSpatialContext->m_dStandardParallel2 = prjParams.m_dStandardParallel2;
			pSpatialContext->m_dScaleFactor = prjParams.m_dScaleFactor;
			pSpatialContext->m_dAzimuth = prjParams.m_dAzimuth;
			pSpatialContext->m_dFirstPointLongitude = prjParams.m_dFirstPointLongitude;
			pSpatialContext->m_dSecondPointLongitude = prjParams.m_dSecondPointLongitude;
		}
		// end for ȡ�ռ������ʵ��ֵ
	
		// ���ù����Ŀռ�����Ĳ���
		pSpatialContext->SetName(strName);
		pSpatialContext->SetDescription(strDescription);
		pSpatialContext->SetCoordSysName(strCoordSysName); //(strCoordSysName.Right(L"---"));
		pSpatialContext->m_eType = eType;
		pSpatialContext->m_DatumName = strDatumName;
		pSpatialContext->m_SpheroidName = strSpheroidName;
		pSpatialContext->m_dSemiMajor = dSemiMajor;
		pSpatialContext->m_dInvflattening = dInvflattening;
		pSpatialContext->m_PrimeMeridian = strPrimeMeridian;
		pSpatialContext->m_Unit = Unit;
		pSpatialContext->m_UnitFactor = UnitFactor;
		pSpatialContext->m_GeoUnit = GeoUnit;
		pSpatialContext->m_GeoUnitFactor = GeoUnitFactor;

		m_SpatialContextColl = new SuperMapSpatialContextCollection();
		m_SpatialContextColl->Add(pSpatialContext);
	}

	return FDO_SAFE_ADDREF(m_SpatialContextColl.p);
}

void SuperMapConnection::CreateSpatialContext(
								FdoString* name,
								FdoString* description,
								FdoString* coordinateSystem,
								FdoString* coordinateSystemWkt,
								FdoSpatialContextExtentType extentType,
								FdoByteArray * extent,
								double xyTolerance,
								double zTolerance,
								bool   update
							)
{
	bool found = false;

	// ����Ƿ���ͬһ��WKT�ռ��������
	for(FdoInt32 i = 0; i < m_SpatialContextColl->GetCount() && !found; ++i)
	{
		FdoPtr<SuperMapSpatialContext>	sp = m_SpatialContextColl->GetItem(i);
		found = (coordinateSystemWkt == sp->GetCoordinateSystemWkt());
	}

	// ���µ�����ϵ
	if(!found)
	{
		FdoPtr<SuperMapSpatialContext> newSp = new SuperMapSpatialContext();
		FdoInt32 idxGenName = 1;
		FdoStringP newName = name;

		// �����ظ��Ŀռ��������������ֺ�����ֱ�������
		while(m_SpatialContextColl->FindItem(newName))
		{
			newName = FdoStringP::Format(L"%ls_%d", (FdoString*)name, idxGenName);
			idxGenName++;
		}

		//�����µĿռ�����
		newSp->SetName(newName);
		newSp->SetCoordSysName(coordinateSystem);
		newSp->SetCoordinateSystemWkt(coordinateSystemWkt);

		newSp->SetDescription(description); 
		newSp->SetExtent(extent);
		newSp->SetExtentType(extentType);
		newSp->SetXYTolerance(xyTolerance);
		newSp->SetZTolerance(zTolerance);

		m_SpatialContextColl->Add(newSp);
		
		//Todo: ����������Դ�����ͶӰ��Ϣ�Ƿ��ڴ�����
		
	}

}
