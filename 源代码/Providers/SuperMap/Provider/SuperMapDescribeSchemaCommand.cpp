
/** \file	 SuperMapDescribeSchemaCommand.cpp
*  \author	 ����
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-09-19
*  \note : modified by zhouxu 2007-10-23
*/

#include <SuperMap.h>

SuperMapDescribeSchemaCommand::SuperMapDescribeSchemaCommand (FdoIConnection *connection) :
    FdoCommonCommand<FdoIDescribeSchema, SuperMapConnection> (connection)
{
}

/** Do not implement the copy constructor. **/
//SuperMapDescribeSchemaCommand::SuperMapDescribeSchemaCommand (const SuperMapDescribeSchemaCommand &right) { }

SuperMapDescribeSchemaCommand::~SuperMapDescribeSchemaCommand (void)
{
}

/** Do not implement the assignment operator. **/
//SuperMapDescribeSchemaCommand & operator= (const SuperMapDescribeSchemaCommand &right);

/// <summary>Gets the name of the schema to describe. This function is optional;
/// if not specified, execution of the command will describe all schemas.</summary>
/// <returns>Returns the schema name</returns> 
const wchar_t* SuperMapDescribeSchemaCommand::GetSchemaName ()
{
    return (m_SchemaName);
}


/// <summary>Sets the name of the schema to describe. This function is optional; if not
/// specified, execution of the command will describe all schemas.</summary>
/// <param name="value">Input the schema name</param> 
/// <returns>Returns nothing</returns> 
void SuperMapDescribeSchemaCommand::SetSchemaName (const wchar_t* value)
{
    m_SchemaName = value;
}


/// <summary>Executes the DescribeSchema command and returns a 
/// FdoFeatureSchemaCollection. If a schema name is given that has 
/// references to another schema, the dependent schemas will 
/// be returned as well. If the specified schema name does not exist,
/// the Execute method throws an exception.</summary>
/// <returns>Returns the schema collection representing the schema created.</returns> 
FdoFeatureSchemaCollection* SuperMapDescribeSchemaCommand::Execute ()
{
	// writed by zhoux
	TRACE(_T("��ʼ���� SuperMapDescribeSchemaCommand::Execute ��\n"));
	//SuperMapConfig::Init(); //��������Ϣ

	FdoPtr<FdoFeatureSchemaCollection> ret; //�����ص��߼�ģʽ����

	// ��ȡ�߼�ģʽ��������
	FdoPtr<SuperMapConnection> smConn = (SuperMapConnection*)GetConnection();
	// ��ȡ�߼�����ģʽ
	FdoPtr<SuperMapLpFeatureSchemaCollection> lpSchemas = smConn->GetLpSchemas();
	// ��ȡ�߼�ģʽ
	if(lpSchemas != NULL)
	{
		FdoPtr<FdoFeatureSchemaCollection> logicalSchemas = lpSchemas->GetLogicalSchemas();
		VALIDATE_POINTER(logicalSchemas);
		ret = FdoCommonSchemaUtil::DeepCopyFdoFeatureSchemas(logicalSchemas);  
		VALIDATE_POINTER(ret);
	}
	else
	{
		ret = FdoFeatureSchemaCollection::Create(NULL);
	}

	TRACE(_T("�������� SuperMapDescribeSchemaCommand::Execute ��\n"));

	////���ģʽ��Ϣ
	//TRACE(_T("ͨ������ģʽ����ص�ģʽ������Ϣ���£�\n"));
	//TRACE(_T("����%d��ģʽ \n"),ret->GetCount());
	//
	//for(FdoInt32 i = 0; i < ret->GetCount(); ++i)
	//{
	//	TRACE(_T("��%d��ģʽ��Ϣ���£�\n"), i);
	//	FdoPtr<FdoFeatureSchema> schema = ret->GetItem(i);
	//	TRACE(_T("ģʽ����%ls \n"), schema->GetName());
	//	FdoPtr<FdoClassCollection> classes = schema->GetClasses();
	//	TRACE(_T("����%d��Ҫ����\n"), classes->GetCount());
	//	for(FdoInt32 j = 0; j < classes->GetCount(); ++j)
	//	{
	//		FdoPtr<FdoClassDefinition> tmpClass = classes->GetItem(j);
	//		TRACE(_T("��%d��Ҫ���ࣺ\n"), j);
	//		TRACE(_T("������%ls ---- �����ͣ� "), tmpClass->GetName());
	//		if(tmpClass->GetClassType() == FdoClassType_Class)
	//			TRACE(_T(" FdoClassType_Class \n"));
	//		else if(tmpClass->GetClassType() == FdoClassType_FeatureClass)
	//			TRACE(_T(" FdoClassType_FeatureClass \n"));
	//		else
	//			TRACE(_T("�������� \n"));
	//	}
	//}
 
	return FDO_SAFE_ADDREF(ret.p);
}

