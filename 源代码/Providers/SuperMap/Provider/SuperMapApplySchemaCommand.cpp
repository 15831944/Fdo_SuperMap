/** \file	 SuperMapApplySchemaCommand.h
*  \brief    ������ҪΪʵ��FDO��FdoIApplySchema�ӿڣ�����޸�ģʽ�Ĺ���
*  \author	 ����
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/  

#include "SuperMap.h"

SuperMapApplySchemaCommand::SuperMapApplySchemaCommand (FdoIConnection *connection) :
    FdoCommonCommand<FdoIApplySchema, SuperMapConnection> (connection),
    m_IgnoreStates (false)
{
}

/** Do not implement the copy constructor. **/
//SuperMapApplySchemaCommand::SuperMapApplySchemaCommand (const SuperMapApplySchemaCommand &right) { }

SuperMapApplySchemaCommand::~SuperMapApplySchemaCommand (void)
{
}

/** Do not implement the assignment operator. **/
//SuperMapApplySchemaCommand & operator= (const SuperMapApplySchemaCommand &right);

///<summary>Gets the schema to create.</summary>
/// <returns>Returns the schema that would be created.</returns> 
FdoFeatureSchema* SuperMapApplySchemaCommand::GetFeatureSchema ()
{
    return (FDO_SAFE_ADDREF (m_Schema.p));
}

///<summary>Sets the schema to create.</summary>
/// <param name="value">Input the definition of the schema to create.</param> 
/// <returns>Returns nothing</returns> 
void SuperMapApplySchemaCommand::SetFeatureSchema (FdoFeatureSchema* value)
{
    m_Schema = FDO_SAFE_ADDREF (value);
}

/// <summary> Gets the FdoPhysicalSchemaMapping used to specify how the schema definition
/// gets mapped into physical storage.</summary>
/// <returns>Returns FdoPhysicalSchemaMapping</returns> 
FdoPhysicalSchemaMapping* SuperMapApplySchemaCommand::GetPhysicalMapping ()
{
    return NULL;
}


///<summary>Sets the FdoPhysicalSchemaMapping used to specify how the schema definition
///gets mapped into physical storage.</summary>
/// <param name="value">Input the FdoPhysicalSchemaMapping</param> 
/// <returns>Returns nothing</returns> 
/// note: Physical Schema mapping not supported by SuperMap Provider.
void SuperMapApplySchemaCommand::SetPhysicalMapping (FdoPhysicalSchemaMapping* value)
{
   throw FdoCommandException::Create (NlsMsgGet(SUPERMAP_PHYSICAL_SCHEMA_MAPPING_NOT_SUPPORTED,
	   "physical schema mapping not supported"));
}

/// <summary> Indicates whether Execute() will ignore element states 
/// when applying the feature schema.</summary>
/// <returns>Returns true if elements states will be ignored, false otherwise. 
/// </returns> 
FdoBoolean SuperMapApplySchemaCommand::GetIgnoreStates()
{
    return (m_IgnoreStates);
}

///<summary>Changes the handling of element states by Execute().</summary>
/// <param name="ignoreStates">Input True: Execute() will ignore the 
/// element states on the Feature Schema elements. Instead, it 
/// will additively merge the Feature Schema into the current DataStore.
/// False: Execute() will use the element states to determine whether
/// each element is inserted, modified or deleted.</param> 
/// <returns>Returns nothing</returns> 
void SuperMapApplySchemaCommand::SetIgnoreStates( FdoBoolean ignoreStates )
{
    m_IgnoreStates = ignoreStates;
}

//
// internals
//
void SuperMapApplySchemaCommand::AddSchema ()
{
	TRACE(_T("SuperMapApplySchemaCommand::AddSchema ()"));

	FdoPtr<SuperMapLpFeatureSchemaCollection> lpSchemas = mConnection->GetLpSchemas();
	UGC::UGDataSource* pDataSource = mConnection->GetDataSource();

	VALIDATE_POINTER(pDataSource);

	//����һ���߼�����ģʽ���������Զ��ӵ��߼�����ģʽ�����У�
	FdoPtr<SuperMapLpFeatureSchema> newLpSchema = new SuperMapLpFeatureSchema(lpSchemas,mConnection,
		pDataSource,m_Schema,m_IgnoreStates);                   //��m_Schema���ݼӵ�pDataSource��ȥ
}

void SuperMapApplySchemaCommand::ModifySchema ()
{
	TRACE(_T("************SuperMapApplySchemaCommand::ModifySchema ()"));
 
    //��ȡ�Ѿ����ڵ�LpSchema :
	FdoPtr<SuperMapLpFeatureSchemaCollection> lpSchemas = mConnection->GetLpSchemas();
	FdoPtr<SuperMapLpFeatureSchema> lpSchema = lpSchemas->GetItem(m_Schema->GetName());

	//ͨ����������Ϣ�޸�ģʽ
	lpSchema->Modify(mConnection,m_Schema,m_IgnoreStates); 
}

void SuperMapApplySchemaCommand::DeleteSchema ()
{
	TRACE(_T("************SuperMapApplySchemaCommand::DeleteSchema ()"));

	//��ȡ�Ѿ����ڵ�LpSchema
	FdoPtr<SuperMapLpFeatureSchemaCollection> lpSchemas = mConnection->GetLpSchemas();
	FdoPtr<SuperMapLpFeatureSchema> lpSchema = lpSchemas->GetItem(m_Schema->GetName());

	//ɾ��LpSchema���Զ���LpSchemas collection���Ƴ���
	lpSchema->Delete(mConnection);
}


///<summary>Executes the ApplySchema command that creates metadata and physical
///storage for the schema. An exception is thrown if the schema already
///exists or if a schema already exists and the feature provider only
///supports a single schema. If schema changes include deletion of classes
///or the schema itself, then those classes (or the schema, if it is marked
///as deleted) must not contain any instance data. If they do, an exception
///will be thrown.</summary>
/// <returns>Returns nothing</returns> 
void SuperMapApplySchemaCommand::Execute ()
{
	TRACE(_T("���� SuperMapApplySchemaCommand::Execute() ��\n"));
    FdoSchemaElementState state;
	FdoPtr<SuperMapLpFeatureSchemaCollection> lp_schemas;
	FdoPtr<SuperMapLpFeatureSchema> schema;

	if((m_Schema == NULL) || (NULL == m_Schema->GetName()) || 0 == wcslen(m_Schema->GetName()))
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_SCHEMA_NOT_SPECIFIED, 
			"No schema specified for the apply schema command"));
	}
	state = m_Schema->GetElementState();

	// ����״̬���Ա�־��ͬ����ͬ����
	if(GetIgnoreStates())
	{
		lp_schemas = mConnection->GetLpSchemas();
		schema = lp_schemas->FindItem(m_Schema->GetName());
		if(schema == NULL)
			state = FdoSchemaElementState_Added;
		else
			state = FdoSchemaElementState_Modified;
	}

	switch(state)
	{
	case FdoSchemaElementState_Added:
		AddSchema();
		break;
	case FdoSchemaElementState_Deleted:
		DeleteSchema();
		break;
	case FdoSchemaElementState_Detached:
		break;
	case FdoSchemaElementState_Modified:
		ModifySchema();
		break;
	case FdoSchemaElementState_Unchanged:
		break;
	default:
		throw FdoException::Create(NlsMsgGet(SUPERMAP_SCHEMA_UNSUPPORTED_ELEMENT_STATE,
			"Schema element state '%l$d' is not supported.", (int)m_Schema->GetElementState()));
	}

	m_Schema->AcceptChanges();
}