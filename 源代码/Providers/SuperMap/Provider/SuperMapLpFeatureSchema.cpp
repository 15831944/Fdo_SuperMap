/** \file	 SuperMapLpFeatureSchema.cpp
*  \brief    ������Ҫ��ɴ�SuperMap����Դ��Fdo�߼�ģʽ��ת����
*  \author	 �� ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-5
*/

#include "SuperMap.h"

SuperMapLpFeatureSchema::SuperMapLpFeatureSchema()
{
	// 0-argument constructor to please FdoPtr::operator-> 
    throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_ERROR, 
		"Unexpected error '%1$ls'.", L"zero arg SupermapLpFeatureSchema::SuperMapLpFeatureSchema"));
}

SuperMapLpFeatureSchema::SuperMapLpFeatureSchema(
	SuperMapLpFeatureSchemaCollection* parentLpSchemas,
	SuperMapConnection* connection,
	UGC::UGDataSource* pDataSource,
	FdoFeatureSchema* configLogicalSchema,
	bool ignoreStates)
:
	m_parentLpSchemas(parentLpSchemas),
	m_pDataSource(pDataSource)
{
	TRACE(_T("���� SuperMapLpFeatureSchema::SuperMapLpFeatureSchema() ��\n"));

	VALIDATE_POINTER(connection);

	// �����߼������༯��
	m_lpClasses = new SuperMapLpClassDefinitionCollection(); 

	VALIDATE_POINTER(pDataSource);
	
	if(configLogicalSchema == NULL)
		ConvertPhysicalToLogical(connection);
	else
		ConvertLogicalToPhysical(connection,configLogicalSchema,ignoreStates);

	// ���ģʽ�Ѿ����ڣ�������µ�Ҫ���ൽ���ڵ����ģʽ�У������µ��߼�����ģʽ�ӵ����ĸ�������
	FdoPtr<SuperMapLpFeatureSchema> schema = m_parentLpSchemas->FindItem(GetName());
	if(schema != NULL)
	{
		FdoPtr<SuperMapLpClassDefinitionCollection> newClasses = GetLpClasses();
		FdoPtr<SuperMapLpClassDefinitionCollection> existingClasses = schema->GetLpClasses();
		FdoPtr<FdoFeatureSchema> existingLogicalSchema = schema->GetLogicalSchema();
		FdoPtr<FdoClassCollection> existingLogicalClasses = existingLogicalSchema->GetClasses();
		FdoPtr<FdoFeatureSchema> newLogicalSchema = GetLogicalSchema();
		FdoPtr<FdoClassCollection> newLogicalClasses = newLogicalSchema->GetClasses();
		for(int i = 0; i < newClasses->GetCount(); ++i)
		{
			FdoPtr<SuperMapLpClassDefinition> definition = newClasses->GetItem(i);
			existingClasses->Add(definition);
			definition->SetParent(schema);
			FdoPtr<FdoClassDefinition> cls = newLogicalClasses->GetItem(definition->GetName());
			newLogicalClasses->Remove(cls);
			existingLogicalClasses->Add(cls);
		}
	}
	else
	{
		m_parentLpSchemas->Add(this);
	}
}

SuperMapLpFeatureSchema::~SuperMapLpFeatureSchema()
{

}

FdoString* SuperMapLpFeatureSchema::GetName() const
{
	return m_logicalSchema->GetName();
}

bool SuperMapLpFeatureSchema::CanSetName() const
{
    return false;
}

FdoFeatureSchema * SuperMapLpFeatureSchema::GetLogicalSchema() const
{
    FDO_SAFE_ADDREF(m_logicalSchema.p);
    return m_logicalSchema;
}

//FdoFeatureSchema * SuperMapLpFeatureSchema::GetImageSchema() const
//{
//	FDO_SAFE_ADDREF(m_ImageSchema.p);
//	return m_ImageSchema;
//}

SuperMapLpClassDefinitionCollection* SuperMapLpFeatureSchema::GetLpClasses()
{
    FDO_SAFE_ADDREF(m_lpClasses.p);
    return m_lpClasses;
}

UGC::UGDataSource* SuperMapLpFeatureSchema::GetDataSource() const
{
	return m_pDataSource;
}

//������ɴ���������Դ���߼�ģʽ��ת�����ٷ����ݼ���Ҫ�����ת��
void SuperMapLpFeatureSchema::ConvertPhysicalToLogical(SuperMapConnection * connection) 
{
	TRACE(_T("���� SuperMapLpFeatureSchema::ConvertPhysicalToLogical() ��\n"));

	// ��ȡ��������Դ
	if(m_pDataSource == NULL)
	{
		m_pDataSource = connection->GetDataSource();
	}
	// �����߼�ģʽ����������Դ��Ϊ�߼�ģʽ����
	//FdoStringP pSchemaName = NlsMsgGet(SUPERMAP_DEFAULT_SCHEMA_NAME, "Default Schema.");
	FdoStringP pSchemaName = SuperMapUtil::StringToWString(m_pDataSource->GetAlias().Cstr()).c_str();
	FdoString* logicalSchemaName = (FdoString*)pSchemaName;
	FdoStringP pDefaultSchDesc = NlsMsgGet(SUPERMAP_DEFAULT_SCHEMA_DESCRIPTION, "Default schema.");
	FdoString * logicalSchemaDescription = (FdoString*)pDefaultSchDesc;
    
	m_logicalSchema = FdoFeatureSchema::Create(logicalSchemaName, logicalSchemaDescription);

	////����Ӱ��ģʽ
	/*pSchemaName = NlsMsgGet(SUPERMAP_IMAGE_SCHEMA_NAME, "Image Schema");
	FdoString* ImageSchemaName = (FdoString*)pSchemaName;
	m_ImageSchema = FdoFeatureSchema::Create(ImageSchemaName, L"");*/
    
	//������������Դ��ͨ���������ݼ��ٷ�ģʽ��Ҫ����Ľ���
	VALIDATE_POINTER(m_pDataSource);

	//�����Ƿ�Ӱ��ģʽ�������ж�
	if(!connection->IsOnlyConnectImage())
	{
		TRACE(_T("����Դ�����ݼ�������%d"),m_pDataSource->GetDatasetCount());
		for(FdoInt32 i = 0; i < m_pDataSource->GetDatasetCount(); ++i)
		{
			UGC::UGDataset* pDataset = m_pDataSource->GetDataset(i);

			//���ε���֧�ֵ����ݼ����� added by zhouxu 2007-12-10
			FdoInt32 nDatasetType = pDataset->GetType();
			if ( !(nDatasetType == UGC::UGDataset::Point 
				|| nDatasetType == UGC::UGDataset::Line 
				|| nDatasetType == UGC::UGDataset::Region
				|| nDatasetType == UGC::UGDataset::CAD 
				|| nDatasetType == UGC::UGDataset::Text
				)) // ��������ݲ�֧�ֵ����ݼ����ͣ�����
			{
				continue;
			}

			//ʹ��Dataset��ʼ��Class Definition���Զ��ӵ��������У�
			FdoPtr<SuperMapLpClassDefinition> pLpClassDefinition =
				new SuperMapLpClassDefinition(this, connection, pDataset, NULL);
		}  
	}
	else
	{
		for(FdoInt32 i = 0; i < m_pDataSource->GetDatasetCount(); ++i)
		{
			UGC::UGDataset* pDataset = m_pDataSource->GetDataset(i);

			//���ε���֧�ֵ����ݼ����� added by zhouxu 2007-12-10
			FdoInt32 nDatasetType = pDataset->GetType();
			if ( nDatasetType != UGC::UGDataset::Image ) // ��������ݲ�֧�ֵ����ݼ����ͣ�����
			{
				continue;
			}

			//ʹ��Dataset��ʼ��Class Definition���Զ��ӵ��������У�
			FdoPtr<SuperMapLpClassDefinition> pLpClassDefinition =
				new SuperMapLpClassDefinition(this, connection, pDataset, NULL);
		}  
	}

	
	
	//�����߼�ģʽ��Ӷ����߼�ģʽ�����У�
	FdoPtr<FdoFeatureSchemaCollection> logicalSchemas = m_parentLpSchemas->GetLogicalSchemas();
	logicalSchemas->Add(m_logicalSchema);
	// ����Ӱ��ģʽ
	//logicalSchemas->Add(m_ImageSchema);
}

void SuperMapLpFeatureSchema::ConvertLogicalToPhysical(SuperMapConnection* connection, FdoFeatureSchema* configLogicalSchema, bool ignoreStates)
{
	TRACE(_T("���� SuperMapLpFeatureSchema::ConvertLogicalToPhysical() ��\n"));

	// ��ȡ��������Դ
	if(m_pDataSource == NULL)
	{
		m_pDataSource = connection->GetDataSource();
	}
	// �����߼�ģʽ���������ӵ��������У�
	VALIDATE_POINTER(configLogicalSchema);
	m_logicalSchema = FdoCommonSchemaUtil::DeepCopyFdoFeatureSchema(configLogicalSchema); //�߼�������ʵ�����߼�ģʽ�ǲ���ģ����Դ˴�ֱ�ӽ�����ȿ���,����Ҫ����ı�ʶ�����ֶεñ��FEATID_PROPERTY
	// ����ģʽ�е�����Ҫ���࣬����ʶ�ֶ�����ΪFEATID_PROPERTY
	FdoPtr<FdoClassCollection> tmpClasses = m_logicalSchema->GetClasses();
	FdoPtr<FdoClassDefinition> tmpClass;
	FdoPtr<FdoPropertyDefinitionCollection> tmpProperties;
	FdoPtr<FdoDataPropertyDefinitionCollection> tmpIdProperties;
	FdoPtr<FdoDataPropertyDefinition> tmpIdProperty;
	for(FdoInt32 i = 0; i < tmpClasses->GetCount(); ++i)
	{
		tmpClass = tmpClasses->GetItem(i);
		tmpProperties = tmpClass->GetProperties();
		tmpIdProperties = tmpClass->GetIdentityProperties();
		// ����գ�������һ����ΪFEATID_PROPERTY�ı�ʶ�ֶ�
		for(FdoInt32 j = 0; j < tmpIdProperties->GetCount(); ++j)
		{
			FdoPtr<FdoPropertyDefinition> oldIdProperty = tmpIdProperties->GetItem(i);
			tmpProperties->Remove(oldIdProperty);
		}
		tmpIdProperties->Clear();
		tmpIdProperty = FdoDataPropertyDefinition::Create(FEATID_PROPERTY,L"");
		tmpIdProperty->SetDataType(FdoDataType_Int32);
		tmpIdProperty->SetIsAutoGenerated(true);
		tmpIdProperty->SetNullable(false);
		tmpIdProperty->SetReadOnly(true);
		tmpProperties->Add(tmpIdProperty);
		tmpIdProperties->Add(tmpIdProperty);
	} // end for replace Identity Property

	FdoPtr<FdoFeatureSchemaCollection> logicalSchemas = m_parentLpSchemas->GetLogicalSchemas();
	// ȷ�ϴ�ģʽ�Ƿ��ڸ�������
	bool bAlreadyInCollection = false;
	for(FdoInt32 i = 0;i < logicalSchemas->GetCount() && !bAlreadyInCollection; ++i)
	{
		FdoPtr<FdoFeatureSchema> logicalSchema = logicalSchemas->GetItem(i);
		if(0 == wcscmp(logicalSchema->GetName(), m_logicalSchema->GetName()))
		{
			bAlreadyInCollection = true;
		}
	}
	if(!bAlreadyInCollection)
		logicalSchemas->Add(m_logicalSchema);

	// ��ȡ�߼���
	FdoPtr<FdoClassCollection> logicalClasses = configLogicalSchema->GetClasses();

	// �����µ��߼������ࣨ�����д����µ��������ݼ���
	FdoInt32 size = logicalClasses->GetCount();
	for(FdoInt32 i = 0; i < size; ++i)
	{
		FdoPtr<FdoClassDefinition> logicalClass = logicalClasses->GetItem(i);
		// ����ignoreState��־
		FdoSchemaElementState state = logicalClass->GetElementState();
		if(ignoreStates)
		{
			FdoPtr<SuperMapLpClassDefinition> lpExistingClass = m_lpClasses->FindItem(logicalClass->GetQualifiedName());
			if(lpExistingClass == NULL)
				state = FdoSchemaElementState_Added;
			else
				state = FdoSchemaElementState_Modified;
		}
		switch(state)
		{
		case FdoSchemaElementState_Added:
			addClass(connection, logicalClass);
			break;
		case FdoSchemaElementState_Deleted:
			// �������ģʽ��ɾ����״̬ì��
			throw FdoException::Create(NlsMsgGet(SUPERMAP_SCHEMA_DELETED_CLASS_IN_ADDED_SCHEMA,"Conflicting schema element state: a class marked for deletion was found in a schema to be added."));
			break;
		case FdoSchemaElementState_Detached:
			break;
		case FdoSchemaElementState_Modified:
			throw FdoException::Create(NlsMsgGet(SUPERMAP_SCHEMA_MODIFIED_CLASS_IN_ADDED_SCHEMA,"Conflicting schema element state: a class marked for modification was found in a schema to be added."));
			break;
		case FdoSchemaElementState_Unchanged:
			throw FdoException::Create(NlsMsgGet(SUPERMAP_SCHEMA_UNCHANGED_CLASS_IN_ADDED_SCHEMA,"Conflicting schema element state: a class marked unchanged was found in a schema to be added."));
			break;
		default:
			throw FdoException::Create(NlsMsgGet(SUPERMAP_SCHEMA_UNSUPPORTED_ELEMENT_STATE, "Schema element state '%l$d' is not supported.", (int)logicalClass->GetElementState()));
		}
	}
}

void SuperMapLpFeatureSchema::Modify(SuperMapConnection* connection, FdoFeatureSchema* configLogicalSchema, bool ignoreStates)
{
	TRACE(_T("************SuperMapLpFeatureSchema::Modify ()"));

	FdoString* name;
	FdoSchemaElementState state;

	//��ȡ�������߼��༯��
	FdoPtr<FdoClassCollection> logicalClasses = configLogicalSchema->GetClasses();

	//����Ҫ����
	for(int i = 0, size = logicalClasses->GetCount(); i < size; ++i)
	{
		FdoPtr<FdoClassDefinition> logicalClass = logicalClasses->GetItem(i);
		name = logicalClass->GetName();

		//�����Ƿ����Ԫ��״̬�ı�־���д���
		state = logicalClass->GetElementState();
		if(ignoreStates)
		{
			FdoPtr<SuperMapLpClassDefinitionCollection> existingClasses = GetLpClasses();
			FdoPtr<SuperMapLpClassDefinition> classDefinition = existingClasses->FindItem(name);
			if(classDefinition = NULL)
			{
				state = FdoSchemaElementState_Added;
			}
			else
			{
				state = FdoSchemaElementState_Modified;
			}
		}

		switch(state)
		{
		case FdoSchemaElementState_Added:
			addClass(connection, logicalClass);
			break;
		case FdoSchemaElementState_Deleted:
			deleteClass(connection, logicalClass);
			break;
		case FdoSchemaElementState_Detached:
			break;
		case FdoSchemaElementState_Modified:
			modifyClass(connection, logicalClass);
			break;
		case FdoSchemaElementState_Unchanged:
			break;
		default:
			;
		}
	}
	/// added by zhouxu 2008-9-11 
	//FdoPtr<SuperMapLpFeatureSchema> schema = m_parentLpSchemas->FindItem(GetName());
	//FdoPtr<SuperMapLpClassDefinitionCollection> newClasses = GetLpClasses();
	//FdoPtr<SuperMapLpClassDefinitionCollection> existingClasses = schema->GetLpClasses();
	//FdoPtr<FdoFeatureSchema> existingLogicalSchema = schema->GetLogicalSchema();
	//FdoPtr<FdoClassCollection> existingLogicalClasses = existingLogicalSchema->GetClasses();
	//FdoPtr<FdoFeatureSchema> newLogicalSchema = GetLogicalSchema();
	//FdoPtr<FdoClassCollection> newLogicalClasses = newLogicalSchema->GetClasses();
	//for(int i = 0; i < newClasses->GetCount(); ++i)
	//{
	//	FdoPtr<SuperMapLpClassDefinition> definition = newClasses->GetItem(i);
	//	existingClasses->Add(definition);
	//	definition->SetParent(schema);
	//	FdoPtr<FdoClassDefinition> cls = newLogicalClasses->GetItem(definition->GetName());
	//	newLogicalClasses->Remove(cls);
	//	existingLogicalClasses->Add(cls);
	//}
}

void SuperMapLpFeatureSchema::addClass(SuperMapConnection *connection, FdoClassDefinition *logicalClass)
{
	TRACE(_T("���� SuperMapLpFeatureSchema::addClass() ��\n"));
	//ȷ�ϸ��಻����
	FdoPtr<SuperMapLpClassDefinition> oldLpClass = m_lpClasses->FindItem(logicalClass->GetName());
	if(oldLpClass != NULL)
	{
		throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_126_CLASS_ALREADY_EXISTS),
		logicalClass->GetName()));
	}
	
	// �Ӹ������߼��ഴ���µ��߼������ࣨ�Զ��ӵ��������У�
	FdoPtr<SuperMapLpClassDefinition> newLpClass = new SuperMapLpClassDefinition(this, connection, NULL, logicalClass);

	//// ���߼�����ӵ��߼�ģʽ��  added by zhouxu 20080926
	//FdoPtr<FdoClassCollection> logicalClasses = m_logicalSchema->GetClasses();
	//logicalClasses->Add(logicalClass);
}

void SuperMapLpFeatureSchema::deleteClass(SuperMapConnection* connection, FdoClassDefinition* logicalClass)
{
	//ȷ�������Ƿ����κ�����
	FdoPtr<FdoISelect> select = (FdoISelect*)connection->CreateCommand(FdoCommandType_Select);
	select->SetFeatureClassName(logicalClass->GetQualifiedName());
	FdoPtr<FdoIFeatureReader> reader = select->Execute();
	bool bClassHasData = reader->ReadNext();
	reader->Close();

	//���Ҫ�����ΰ�����������ɾ����Ҫ����
	if(bClassHasData)
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_CANT_DELETE_NON_EMPTY_CLASS, "Can't delete class '%1$ls'\
			  because it contains data", (FdoString*)logicalClass->GetQualifiedName()));
	}
	
	//ͨ�������ҵ���Ӧ���߼���������ɾ���߼�������
	FdoPtr<SuperMapLpClassDefinition> lpClass;
	FdoPtr<SuperMapLpClassDefinitionCollection> lpClasses = this->GetLpClasses();
	int i = 0;
	int size = lpClasses->GetCount();
	for(i = 0; i < size; ++i)
	{
		lpClass = lpClasses->GetItem(i);
		FdoPtr<FdoClassDefinition> classDefinition = lpClass->GetLogicalClass();
		if(0 == wcscmp(classDefinition->GetName(), logicalClass->GetName()))
		{
			break;
		}
	}
	// �ж����ҵ���Ŀ���˳���ѭ������ѭ�������˳���ѭ��
	if(i == size)
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_CANT_DELETE_CLASS_NOT_FOUND, "Can't delete class '%1$ls'\
			beacause not find it", logicalClass->GetQualifiedName()));
	}

	lpClass->Delete(connection);
}

void SuperMapLpFeatureSchema::modifyClass(SuperMapConnection* connection, FdoClassDefinition* logicalClass)
{
	//ȷ���Ƿ���ຬ���κ�����
	FdoPtr<FdoISelect> select = (FdoISelect*)connection->CreateCommand(FdoCommandType_Select);
	select->SetFeatureClassName(logicalClass->GetQualifiedName());
	FdoPtr<FdoIFeatureReader> reader = select->Execute();
	bool bClassHasData = reader->ReadNext();
	reader->Close();

	//�������������ݣ��׳��쳣������ɾ���ٴ�����
	if(bClassHasData)
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_CANT_MODIFY_NON_EMPTY_CLASS, "Can't modify class '%1$ls'\
			  because it contains data", (FdoString*)logicalClass->GetQualifiedName()));
	}

	//ɾ��ԭ������
	deleteClass(connection, logicalClass);

	//��������
	addClass(connection, logicalClass);
}

void SuperMapLpFeatureSchema::Delete(SuperMapConnection* connection)
{
	FdoPtr<FdoISelect> select = (FdoISelect*)connection->CreateCommand(FdoCommandType_Select);
	FdoPtr<FdoIFeatureReader> reader;

	FdoPtr<FdoFeatureSchema> logicalSchema = this->GetLogicalSchema();
	FdoPtr<FdoClassCollection> logicalClasses = logicalSchema->GetClasses();

	//�ȼ�����е����Ƿ��ǿյ�
	for(int i = 0; i < logicalClasses->GetCount(); ++i)
	{
		FdoPtr<FdoClassDefinition> logicalClass = logicalClasses->GetItem(i);
		select->SetFeatureClassName(logicalClass->GetQualifiedName());
		reader = select->Execute();

		if(reader->ReadNext())
		{
			throw FdoException::Create(NlsMsgGet(SUPERMAP_CANT_DELETE_NON_EMPTY_SCHEMA, "Can't delete schema '%1$ls'\
				because class '%2$ls' contains data", (FdoString*)logicalSchema->GetQualifiedName(),
				(FdoString*)logicalClass->GetQualifiedName()));
		}
		reader->Close();
	}

	// ɾ�����߼�����ģʽ�����������߼�������
	FdoPtr<SuperMapLpClassDefinitionCollection> lpClasses = this->GetLpClasses();
	for(int i = 0, size = lpClasses->GetCount(); i < size; ++i)
	{
		FdoPtr<SuperMapLpClassDefinition> lpClass = lpClasses->GetItem(0);
		lpClass->Delete(connection);
	}

	// ���߼�����ģʽ�������Ƴ�����߼�����ģʽ
	m_parentLpSchemas->Remove(this);

	// ɾ���������ݲ��֣��Ƿ�����ɾ�����ļ�����
	m_pDataSource->Close();
	
	// ɾ���߼�����
	FdoPtr<FdoFeatureSchemaCollection> logicalSchemas = m_parentLpSchemas->GetLogicalSchemas();
	logicalSchemas->Remove(m_logicalSchema);
}

////////////////////////////////////////////////////////////////////////
SuperMapLpFeatureSchemaCollection::SuperMapLpFeatureSchemaCollection()
{
	  m_logicalSchemas = FdoFeatureSchemaCollection::Create (NULL);
}

FdoFeatureSchemaCollection* SuperMapLpFeatureSchemaCollection::GetLogicalSchemas()
{
	return FDO_SAFE_ADDREF(m_logicalSchemas.p);
}

SuperMapLpFeatureSchemaCollection::SuperMapLpFeatureSchemaCollection(SuperMapConnection *connection, UGC::UGDataSource *pDataSource)
{
	TRACE(_T("���� SuperMapLpFeatureSchemaCollection::���캯��() ��\n"));

	VALIDATE_POINTER(pDataSource);
	ConvertPhysicalToLogical(connection, pDataSource);
}

void SuperMapLpFeatureSchemaCollection::ConvertPhysicalToLogical(
	SuperMapConnection *connection, 
	UGC::UGDataSource *pDataSource)
{
	TRACE(_T("���� SuperMapLpFeatureSchemaCollection::ConvertPhysicalToLogical() ��\n"));

	//�����߼�ģʽ����
	m_logicalSchemas = FdoFeatureSchemaCollection::Create(NULL);
    VALIDATE_POINTER(pDataSource);

	//����������Դ�����߼�����ģʽ���Զ��ӵ������У�
	FdoPtr<SuperMapLpFeatureSchema> pLpSchema = new SuperMapLpFeatureSchema(
		this, connection, pDataSource,NULL);
}