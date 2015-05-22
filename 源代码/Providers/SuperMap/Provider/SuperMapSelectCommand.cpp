
/** \file	 SuperMapSelectCommand.cpp
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#include "SuperMap.h"

// TODO::�ؼ��������ݿ��в�ѯ���õ������о�һ�£�

SuperMapSelectCommand::SuperMapSelectCommand (SuperMapConnection* connection) :
    FdoCommonFeatureCommand<FdoISelect, SuperMapConnection> (connection)
{
}

/** Do not implement the copy constructor. **/
//SuperMapSelectCommand::SuperMapSelectCommand (const SuperMapSelectCommand &right) { }

SuperMapSelectCommand::~SuperMapSelectCommand (void)
{
}

// <summary>Dispose this object.</summary>
// <returns>Returns nothing.</returns> 
void SuperMapSelectCommand::Dispose ()
{
    delete this;
}

/// <summary>Gets the FdoIdentifierCollection that holds the list of property names to 
/// return with the result. If empty all properties of the specified class
/// are returned.</summary>
/// <returns>Returns the list of property names.</returns> 
FdoIdentifierCollection* SuperMapSelectCommand::GetPropertyNames ()
{
	//TODO::���о�һ�£��Ƿ���԰�B(C)LOB���Ƶ��ֶ����ε���
	// 
	TRACE(_T("���� SuperMapSelectCommand::GetPropertyNames()... \n"));
    if (m_PropertiesToSelect == NULL)
        m_PropertiesToSelect = FdoIdentifierCollection::Create();

    return (FDO_SAFE_ADDREF(m_PropertiesToSelect.p));
}

/// <summary>Gets the FdoLockType value (see "Locking Commands").</summary>
/// <returns>Returns the lock type.</returns> 
FdoLockType SuperMapSelectCommand::GetLockType ()
{
	TRACE(_T("���� SuperMapSelectCommand::GetLockType()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"GetLockType"));
}

/// <summary>Sets the FdoLockType value (see "Locking Commands").</summary>
/// <param name="value">Input the lock type.</param> 
/// <returns>Returns nothing</returns> 
void SuperMapSelectCommand::SetLockType (FdoLockType value)
{
	TRACE(_T("���� SuperMapSelectCommand::SetLockType()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"SetLockType"));
}

/// <summary>Gets the FdoLockStrategy value (see "Locking Commands").</summary>
/// <returns>Returns the lock strategy.</returns> 
FdoLockStrategy SuperMapSelectCommand::GetLockStrategy ()
{
	TRACE(_T("���� SuperMapSelectCommand::GetLockStrategy()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"GetLockStrategy"));
}

/// <summary>Sets the FdoLockStrategy value (see "Locking Commands").</summary>
/// <param name="value">Input the lock strategy.</param> 
/// <returns>Returns nothing</returns> 
void SuperMapSelectCommand::SetLockStrategy (FdoLockStrategy value)
{
	TRACE(_T("���� SuperMapSelectCommand::SetLockStrategy()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"SetLockStrategy"));
}

/// <summary>Executes the select command and returns a reference to an FdoIFeatureReader.</summary>
/// <returns>Returns the feature reader.</returns> 
FdoIFeatureReader* SuperMapSelectCommand::Execute ()
{
	
	TRACE(_T("���� ShpMapSelectCommand::Execute()... \n"));
	if(mFilter == NULL)
	{
		TRACE(_T("SuperMapSelectCommand::��ѯ����Ϊ��... \n"));
	}
	else
	{
		TRACE(_T("SuperMapSelectCommand::��ѯ����Ϊ:[%ls]\n"), mFilter->ToString());
	}
	if(mClassName == NULL)
	{
		TRACE(_T("SuperMapSelectCommand::Ҫ������Ϊ��... \n"));
	}
	else
	{
		TRACE(_T("SuperMapSelectCommand::Ҫ������Ϊ[%ls]... \n"), mClassName->GetName());
	}
	//*********************** ��ģʽ�����л�ȡҪ���ඨ�� ***********************
	FdoPtr<SuperMapConnection> superMapConn = (SuperMapConnection*)GetConnection ();
	UGC::UGDataSource *pDataSource = NULL;
	UGC::UGDataset *pDataset = NULL;
	UGC::UGRecordset *pRecordset = NULL;
	if(!superMapConn.p)
	{
		TRACE(_T("SuperMapSelectCommand::�õ��յ�������... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_CONNECTION_NOT_ESTABLISHED, "SuperMap connection is invalid'%1$ls'.", L"Execute"));
	}

	FdoPtr<SuperMapLpFeatureSchemaCollection> pLPFeatureSchemaCollection = superMapConn->GetLpSchemas();
	FdoPtr<FdoFeatureSchemaCollection> pFeatureSchemaCollection = pLPFeatureSchemaCollection->GetLogicalSchemas();

	// modified by zhouxu 2007-12-6 ��Ҫ���Ƕ��ģʽ�����
	// ������COPY�ĺ���һ������Դ�п��ܶ�Ӧ���ģʽ������������¾Ϳ�����Ҫ�ڶ��ģʽ�в�ѯ����Ҫ���ࡣ
	FdoPtr<FdoFeatureSchema> pFeatureSchema;
	FdoPtr<FdoClassCollection> pClassCollection;
	FdoPtr<FdoClassDefinition> pClassDef;
	for(FdoInt32 i = 0; i < pFeatureSchemaCollection->GetCount(); ++i)
	{
		pFeatureSchema = pFeatureSchemaCollection->GetItem(i);
		pClassCollection = pFeatureSchema->GetClasses();
		pClassDef = pClassCollection->FindItem(mClassName->GetName());
		
		// �ҵ�������ѭ�������ģʽ����ͬһ������Դ�У���һ������Դ��������ͬ�������ݼ�����˶��ģʽ��Ҳ������ͬ����Ҫ����
		if(pClassDef != NULL)
			break;        
	}

	//******* ��FDO�����л�ȡ����Դ����������Դ�а���Ҫ��������ȡ��¼�� *********
	pDataSource = superMapConn->GetDataSource(); //Get UGC DataSource
	if (NULL == pDataSource)
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));

	if ( !pDataSource->IsOpen() )    
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));


	UGC::UGString strDatasetName = SuperMapUtil::WcharToString(mClassName->GetName()).c_str();
	pDataset = pDataSource->GetDataset(strDatasetName); //get the dataset
	if(pDataset)
	{
		//TODO:: ��ҪĬ�ϲ�ѯ��Ҫ��ÿ���ֶζ��г�����ѯ����������һ�²��ԣ�
		pDataset->Open();
		if(pDataset->IsVector()) //ʸ�����ݼ�
		{
			UGC::UGQueryDef querydef;
			querydef.m_nCursorType = UGC::UGQueryDef::OpenStatic;
			UGC::UGGeometry *pQueryGeometry = NULL; //used for spatial query
			SuperMapFilterProcessor filterPro(pDataSource->GetEngineType());

			if(NULL != mFilter) // �����������
			{			
				mFilter->Process( &filterPro );
				pQueryGeometry = filterPro.GetGeometry();
				if(NULL != filterPro.GetFilterText())
				{
					querydef.m_strFilter = filterPro.GetFilterText();
				}
			}		
			pRecordset = ( (UGC::UGDatasetVector *)pDataset )->Query(querydef); //��β�ѯΪ�ǿռ��ѯ
 			for(int i = 0; i < filterPro.m_GeometryArray.size(); ++i) //���Խ��ж�οռ��ѯ
			{
				UGC::UGSpatialQuery spatialquery;
				if( filterPro.m_GeometryArray[i] )
				{
					pRecordset = spatialquery.Query(pRecordset, 
						filterPro.m_GeometryArray[i], 
						(UGC::UGSpatialQuery::UGSpatialQueryMode)filterPro.GetSpatialQueryType());
					delete filterPro.m_GeometryArray[i];
				}
			}	
		}
	}
	else
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}

	FdoPtr<FdoIFeatureReader> ret;
	if(pDataset->IsVector()) //ʸ�����ݼ�
	{
		ret = new SuperMapFeatureReader(FDO_SAFE_ADDREF(pClassDef.p), pRecordset);
	}
	else if(pDataset->IsRaster()) //դ�����ݼ�
	{
		FdoPtr<FdoIdentifierCollection> selProp = GetPropertyNames();
		if(selProp->GetCount() > 0)
		{
			TRACE(_T("���� SuperMapSelectCommand::�Ѿ�����դ�����ݼ���FeatureReader...[%ls] \n"), selProp->GetItem(0)->ToString());
		}
		TRACE(_T("���� SuperMapSelectCommand::�Ѿ�����դ�����ݼ���FeatureReader...[%d] \n"), selProp->GetCount());
		ret = new SuperMapFeatureReader(FDO_SAFE_ADDREF(pClassDef.p), (UGC::UGDatasetRaster *)pDataset);
	}
	return FDO_SAFE_ADDREF(ret.p);
}

/// <summary>Executes the select command and returns a reference to an
/// IFeatureReader.</summary> 
/// <returns>Returns the feature reader.</returns> 
FdoIFeatureReader* SuperMapSelectCommand::ExecuteWithLock ()
{
	TRACE(_T("���� SuperMapSelectCommand::ExecuteWithLock()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"ExecuteWithLock"));
}

/// <summary> When executing the operation ExecuteWithLock lock 
/// conflicts may occur. Those lock conflicts are reported. The 
/// function GetLockConflicts returns a lock conflict reader 
/// providing access to the list of lock conflicts that occurred 
/// during the execution of the operation.</summary>
/// <returns>Returns a lock conflict reader.</returns> 
FdoILockConflictReader* SuperMapSelectCommand::GetLockConflicts ()
{
	TRACE(_T("���� SuperMapSelectCommand::GetLockConflicts()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"GetLockConflicts"));
}
