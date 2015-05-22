
/** \file	 SuperMapDeleteCommand.cpp
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#include "SuperMap.h"

SuperMapDeleteCommand::SuperMapDeleteCommand (FdoIConnection *connection) :
    FdoCommonFeatureCommand<FdoIDelete, SuperMapConnection> (connection)
{

}

SuperMapDeleteCommand::~SuperMapDeleteCommand (void)
{

}

/// <summary>Executes the delete command and returns the number of instances
/// deleted</summary>
/// <returns>Returns the number of instances deleted.</returns> 
FdoInt32 SuperMapDeleteCommand::Execute ()
{
	//******* ��FDO�����л�ȡ����Դ����������Դ�а���Ҫ��������ȡ��¼�� *********
	FdoPtr<SuperMapConnection> superMapConn = (SuperMapConnection*)GetConnection ();
	UGC::UGDataSource *pDataSource = NULL;
	UGC::UGDatasetVector *pDataset = NULL;
	UGC::UGRecordset *pRecordset = NULL;
	if(!superMapConn.p)
	{
		TRACE(_T("SuperMapDeleteCommand::�õ��յ�������... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_CONNECTION_NOT_ESTABLISHED, "SuperMap connection is invalid'%1$ls'.", L"Execute"));
	}

	pDataSource = superMapConn->GetDataSource(); //�õ�����Դ

	if(NULL == pDataSource)
	{
		TRACE(_T("SuperMapDeleteCommand::����ԴΪ��... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}
	if( !pDataSource->IsOpen() )
	{
		TRACE(_T("SuperMapDeleteCommand::����Դδ��... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}

	UGC::UGString strDatasetName = SuperMapUtil::WcharToString(mClassName->GetName()).c_str();
	pDataset = (UGC::UGDatasetVector *)pDataSource->GetDataset(strDatasetName); //�õ����ݼ�

	if(pDataset)
	{
		if(!pDataset->IsOpen()) //�����ݼ�
		{
			pDataset->Open();
		}
		UGC::UGQueryDef querydef;
		if(NULL != mFilter)
		{
			SuperMapFilterProcessor filterPro(pDataSource->GetEngineType());
			mFilter->Process( &filterPro );
			querydef.m_strFilter = filterPro.GetFilterText();
		}
		//************* ���ղ�ѯ������ȡ��¼��************
		pRecordset = pDataset->Query(querydef);
	}
	else
	{
		TRACE(_T("SuperMapDeleteCommand::��ȡ���ݼ�ʧ��... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}
	if(pRecordset)
	{
		//ִ��ɾ������
		int nRecNum = pRecordset->GetRecordCount();
		pRecordset->DeleteAll();
		pDataset->ReleaseRecordset(pRecordset);
		pRecordset = NULL;
		pDataset->Close();
		return nRecNum;
	}
	else
	{
		TRACE(_T("SuperMapDeleteCommand::��ȡ��¼��ʧ��... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'!.", L"SuperMapInsertCommand::Execute"));
	}
}

/// <summary> Deleting objects might result in lock conflicts if objects
/// to be deleted are not exclusively locked for the user attempting to
/// delete the object. A lock conflict report is generated.
/// The function GetLockConflicts returns a lock conflict reader that provides
/// access to the list of lock conflicts that occurred during the execution
/// of the delete operation.</summary>
/// <returns>Returns a lock conflict reader.</returns> 
FdoILockConflictReader* SuperMapDeleteCommand::GetLockConflicts ()
{
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"GetLockConflicts"));
}





