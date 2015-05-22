
/** \file	 SuperMapMessage.h
 *  \brief	 ��ϢID
 *  \author	 ����
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */


#ifdef __SUPERMAP_MESSAGE_DEFINE__
// the default message catalog filename
#	ifdef _WIN32
		char *fdoshp_cat = "SuperMapMessage.dll";
#	else
		char *fdoshp_cat = "SuperMapMessage.cat";
#	endif
	FdoString* NlsMsgGet(int msg_num, char* default_msg, ...)
	{
		va_list varargs;
		va_start(varargs, default_msg);
		FdoString* ret = FdoException::NLSGetMessage(msg_num, default_msg, fdoshp_cat, varargs);
		va_end(varargs);

		return ret;
	}
#else // __SUPERMAP_MESSAGE_DEFINE__
	extern char *fdoshp_cat;
	extern FdoString* NlsMsgGet(int msg_num, char* default_msg, ...);
#endif // __SUPERMAP_MESSAGE_DEFINE__


//LanguageNames=(English=0x409:MSG00409)
//LanguageNames=(Chinese=0x804:MSG00804)

//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: SUPERMAP_UNEXPECTED_ERROR
//
// MessageText:
//
//  ��SuperMap���ݷ��ʽӿ��з���δԤ�ϵ�����'%1$ls'��
//
#define SUPERMAP_UNEXPECTED_ERROR        ((DWORD)0x000003E8L)

//
// MessageId: SUPERMAP_OPEN_FAILED
//
// MessageText:
//
//  ������Դʧ�ܡ�
//
#define SUPERMAP_OPEN_FAILED             ((DWORD)0x000003EAL)

//
// MessageId: SUPERMAP_NULL_ARGUMENT
//
// MessageText:
//
//  ����ΪNULL��
//
#define SUPERMAP_NULL_ARGUMENT           ((DWORD)0x000003EBL)

//
// MessageId: SUPERMAP_INVALID_PROPERTY_NAME
//
// MessageText:
//
//  �������ƴ���
//
#define SUPERMAP_INVALID_PROPERTY_NAME   ((DWORD)0x000003ECL)

//
// MessageId: SUPERMAP_CONFIGURATION_FILE_NOT_SUPPORTED
//
// MessageText:
//
//  SuperMap�ṩ�߲�֧�������ļ���
//
#define SUPERMAP_CONFIGURATION_FILE_NOT_SUPPORTED ((DWORD)0x000003EDL)

//************************************************************************************
//************************************************************************************
//** CONNECTION MESSAGES 
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_CONNECTION_ALREADY_OPEN
//
// MessageText:
//
//  �Ѿ��������ӡ�
//
#define SUPERMAP_CONNECTION_ALREADY_OPEN ((DWORD)0x000003EEL)

//
// MessageId: SUPERMAP_CONNECTION_TIMEOUT_UNSUPPORTED
//
// MessageText:
//
//  ��֧�����ӳ�ʱ��
//
#define SUPERMAP_CONNECTION_TIMEOUT_UNSUPPORTED ((DWORD)0x000003EFL)

//
// MessageId: SUPERMAP_CONNECTION_LOCATION_NOT_EXIST
//
// MessageText:
//
//  ���� '%1$ls' �ļ������ڡ�
//
#define SUPERMAP_CONNECTION_LOCATION_NOT_EXIST ((DWORD)0x000003F0L)

//
// MessageId: SUPERMAP_INVALID_CONNECTION_STRING
//
// MessageText:
//
//  ��Ч�����ַ��� '%1$ls' ��
//
#define SUPERMAP_INVALID_CONNECTION_STRING ((DWORD)0x000003F1L)

//
// MessageId: SUPERMAP_CONNECTION_INVALID
//
// MessageText:
//
//  ������Ч��
//
#define SUPERMAP_CONNECTION_INVALID      ((DWORD)0x000003F2L)

//
// MessageId: SUPERMAP_INVALID_CONNECTION_PROPERTY_NAME
//
// MessageText:
//
//  ��Ч���������� '%1$ls'
//
#define SUPERMAP_INVALID_CONNECTION_PROPERTY_NAME ((DWORD)0x000003F3L)

//
// MessageId: SUPERMAP_CONNECTION_PROPERTY_DATASTORE
//
// MessageText:
//
//  ���ݼ�
//
#define SUPERMAP_CONNECTION_PROPERTY_DATASTORE ((DWORD)0x000003F4L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_ESTABLISHED
//
// MessageText:
//
//  ������Ч��
//
#define SUPERMAP_CONNECTION_NOT_ESTABLISHED ((DWORD)0x000003F5L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_TYPE
//
// MessageText:
//
//  ȱ���������͡�
//
#define SUPERMAP_CONNECTION_NOT_TYPE     ((DWORD)0x000003F6L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_SERVER
//
// MessageText:
//
//  ȱ�����ӷ�������
//
#define SUPERMAP_CONNECTION_NOT_SERVER   ((DWORD)0x000003F7L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_DATABASE
//
// MessageText:
//
//  ȱ���������ݿ⡣
//
#define SUPERMAP_CONNECTION_NOT_DATABASE ((DWORD)0x000003F8L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_USER
//
// MessageText:
//
//  ȱ���������ݿ���û���
//
#define SUPERMAP_CONNECTION_NOT_USER     ((DWORD)0x000003F9L)

//
// MessageId: SUPERMAP_CONNECTION_NOT_PASSWORD
//
// MessageText:
//
//  ȱ���������ݿ�����롣
//
#define SUPERMAP_CONNECTION_NOT_PASSWORD ((DWORD)0x000003FAL)

//
// MessageId: SUPERMAP_CONNECTION_FAIL
//
// MessageText:
//
//  �������ݿ�ʧ�ܡ�
//
#define SUPERMAP_CONNECTION_FAIL         ((DWORD)0x000003FBL)

//
// MessageId: SUPERMAP_CONNECTION_STRING
//
// MessageText:
//
//  �����ַ���
//
#define SUPERMAP_CONNECTION_STRING       ((DWORD)0x000003FCL)

//************************************************************************************
//************************************************************************************
//** SCHEMA-RELATED MESSAGES 
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_SCHEMA_FAIL_READ_FEATURE_SCHEMAS
//
// MessageText:
//
//  �������м���ģʽ����
//
#define SUPERMAP_SCHEMA_FAIL_READ_FEATURE_SCHEMAS ((DWORD)0x000007D1L)

//
// MessageId: SUPERMAP_SCHEMA_FAIL_READ_SCHEMA_MAPPINGS
//
// MessageText:
//
//  �������м���ģʽӳ�����
//
#define SUPERMAP_SCHEMA_FAIL_READ_SCHEMA_MAPPINGS ((DWORD)0x000007D2L)

//
// MessageId: SUPERMAP_INVALID_PHYSICAL_SCHEMA_PROVIDER_NAME
//
// MessageText:
//
//  ��Чʵ��ģʽӳ���ṩ����
//
#define SUPERMAP_INVALID_PHYSICAL_SCHEMA_PROVIDER_NAME ((DWORD)0x000007D3L)

//************************************************************************************
//************************************************************************************
//** CONNECTION PROPERTIES 
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_CONNECTION_PROPERTY_DATASOURCE
//
// MessageText:
//
//  ����Դ
//
#define SUPERMAP_CONNECTION_PROPERTY_DATASOURCE ((DWORD)0x00000BB8L)

//
// MessageId: SUPERMAP_CONNECTIONPROPERTY_TEMPORARY_FILE
//
// MessageText:
//
//  ��ʱĿ¼
//
#define SUPERMAP_CONNECTIONPROPERTY_TEMPORARY_FILE ((DWORD)0x00000BB9L)

//
// MessageId: SUPERMAP_CONNECTIONPROPERTY_CONN_TYPE
//
// MessageText:
//
//  ��������
//
#define SUPERMAP_CONNECTIONPROPERTY_CONN_TYPE ((DWORD)0x00000BBAL)

//************************************************************************************
//************************************************************************************
//** TRANSACTION MESSAGES 
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_CONNECTION_TRANSACTIONS_NOT_SUPPORTED
//
// MessageText:
//
//  SuperMap SDB/SDX+ ���ݷ��ʲ�֧��������
//
#define SUPERMAP_CONNECTION_TRANSACTIONS_NOT_SUPPORTED ((DWORD)0x00000FA1L)

//
// MessageId: SUPERMAP_TRANSACTIONS_NOT_START
//
// MessageText:
//
//  ���ݷ��ʲ�����������
//
#define SUPERMAP_TRANSACTIONS_NOT_START  ((DWORD)0x00000FA2L)

//
// MessageId: SUPERMAP_TRANSACTION_SPENT
//
// MessageText:
//
//  ��������Ѿ�ִ�й��ύ��ع���
//
#define SUPERMAP_TRANSACTION_SPENT       ((DWORD)0x00000FA3L)

//
// MessageId: SUPERMAP_NESTED_TRANSACTIONS_NOT_SUPPORTED
//
// MessageText:
//
//  ��֧������Ƕ�ס�
//
#define SUPERMAP_NESTED_TRANSACTIONS_NOT_SUPPORTED ((DWORD)0x00000FA4L)

//************************************************************************************
//************************************************************************************
//** CONNECTION INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_PROVIDER_DISPLAY_NAME
//
// MessageText:
//
//  ������ SuperMap SDB/SDX+ �� FDO �ṩ����
//
#define SUPERMAP_PROVIDER_DISPLAY_NAME   ((DWORD)0x00001389L)

//
// MessageId: SUPERMAP_PROVIDER_DESCRIPTION
//
// MessageText:
//
//  �Ի��� SuperMap SDB/SDX+ �����ݴ洢���ж���дȨ�ޡ�
//
#define SUPERMAP_PROVIDER_DESCRIPTION    ((DWORD)0x0000138AL)

//************************************************************************************
//************************************************************************************
//** SELECT INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_UNEXPECTED_DATATYPE
//
// MessageText:
//
//  Ҫ��Դ���޶�Ӧ����������'%1$ls'
//
#define SUPERMAP_UNEXPECTED_DATATYPE     ((DWORD)0x00001771L)

//************************************************************************************
//************************************************************************************
//** SCHEMA INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_DEFAULT_SCHEMA_DESCRIPTION
//
// MessageText:
//
//  ȱʡģʽ
//
#define SUPERMAP_DEFAULT_SCHEMA_DESCRIPTION ((DWORD)0x00001B59L)

//
// MessageId: SUPERMAP_DEFAULT_SCHEMA_NAME
//
// MessageText:
//
//  ȱʡģʽ
//
#define SUPERMAP_DEFAULT_SCHEMA_NAME     ((DWORD)0x00001B5AL)

//
// MessageId: SUPERMAP_PHYSICAL_SCHEMA_MAPPING_NOT_SUPPORTED
//
// MessageText:
//
//  ��֧������ģʽӳ��
//
#define SUPERMAP_PHYSICAL_SCHEMA_MAPPING_NOT_SUPPORTED ((DWORD)0x00001B5BL)

//
// MessageId: SUPERMAP_SCHEMA_NOT_SPECIFIED
//
// MessageText:
//
//  ��֧������ģʽӳ��
//
#define SUPERMAP_SCHEMA_NOT_SPECIFIED    ((DWORD)0x00001B5CL)

//
// MessageId: SUPERMAP_SCHEMA_UNSUPPORTED_ELEMENT_STATE
//
// MessageText:
//
//  ��֧�ֵ�ģʽԪ��״̬
//
#define SUPERMAP_SCHEMA_UNSUPPORTED_ELEMENT_STATE ((DWORD)0x00001B5DL)

//
// MessageId: SUPERMAP_SCHEMA_DELETED_CLASS_IN_ADDED_SCHEMA
//
// MessageText:
//
//  ģʽԪ��״̬��ͻ���ڴ���ӵ�ģʽ������ɾ������
//
#define SUPERMAP_SCHEMA_DELETED_CLASS_IN_ADDED_SCHEMA ((DWORD)0x00001B5EL)

//
// MessageId: SUPERMAP_SCHEMA_MODIFIED_CLASS_IN_ADDED_SCHEMA
//
// MessageText:
//
//  ģʽԪ��״̬��ͻ���ڴ���ӵ�ģʽ�������޸ĵ���
//
#define SUPERMAP_SCHEMA_MODIFIED_CLASS_IN_ADDED_SCHEMA ((DWORD)0x00001B5FL)

//
// MessageId: SUPERMAP_SCHEMA_UNCHANGED_CLASS_IN_ADDED_SCHEMA
//
// MessageText:
//
//  ģʽԪ��״̬��ͻ���ڴ���ӵ�ģʽ����δ�仯����
//
#define SUPERMAP_SCHEMA_UNCHANGED_CLASS_IN_ADDED_SCHEMA ((DWORD)0x00001B60L)

//
// MessageId: SUPERMAP_CLASS_NAME_INVALID
//
// MessageText:
//
//  '%l$s'��Ч��Ҫ������
//
#define SUPERMAP_CLASS_NAME_INVALID      ((DWORD)0x00001B61L)

//
// MessageId: SUPERMAP_SCHEMA_EXCESSIVE_GEOMETRY
//
// MessageText:
//
//  Ҫ���� '%l$ls' ��������һ����������
//
#define SUPERMAP_SCHEMA_EXCESSIVE_GEOMETRY ((DWORD)0x00001B62L)

//
// MessageId: SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z
//
// MessageText:
//
//  ��ʱ��֧��Zά�Ķ���
//
#define SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z ((DWORD)0x00001B63L)

//
// MessageId: SUPERMAP_GEOMETRY_NOT_SUPPORTED_M
//
// MessageText:
//
//  ��ʱ��֧��Mά�Ķ���
//
#define SUPERMAP_GEOMETRY_NOT_SUPPORTED_M ((DWORD)0x00001B64L)

//
// MessageId: SUPERMAP_DATASET_CREATED_FAILED
//
// MessageText:
//
//  '%l$ls' ʸ�����ݼ�����ʧ��
//
#define SUPERMAP_DATASET_CREATED_FAILED  ((DWORD)0x00001B65L)

//
// MessageId: SUPERMAP_CREATED_FAILED
//
// MessageText:
//
//  ģʽ����ʧ��
//
#define SUPERMAP_CREATED_FAILED          ((DWORD)0x00001B66L)

//
// MessageId: SUPERMAP_DATA_TYPE_NOT_SUPPORTED
//
// MessageText:
//
//  ��Fdo��������'%l$d'��provider�ݲ�֧��
//
#define SUPERMAP_DATA_TYPE_NOT_SUPPORTED ((DWORD)0x00001B67L)

//
// MessageId: SUPERMAP_FIELD_CREATED_FAILED
//
// MessageText:
//
//  �������ݼ����ֶδ���ʧ��
//
#define SUPERMAP_FIELD_CREATED_FAILED    ((DWORD)0x00001B68L)

//
// MessageId: SUPERMAP_DATASET_EXIST
//
// MessageText:
//
//  ���������ݼ����Ѿ�����
//
#define SUPERMAP_DATASET_EXIST           ((DWORD)0x00001B69L)

//
// MessageId: SUPERMAP_SCHEMA_NAME_SHOULD_BE_CHANGED
//
// MessageText:
//
//  ��ģʽ���Ѿ����ڣ����޸�ģʽ����
//
#define SUPERMAP_SCHEMA_NAME_SHOULD_BE_CHANGED ((DWORD)0x00001B6AL)

//
// MessageId: SUPERMAP_NOT_SUPPORT_DATASET_TYPE
//
// MessageText:
//
//  �Բ�����ʱ��֧�ֵ㡢�ߡ��桢�ı����������ݼ���������ݼ����͡�
//
#define SUPERMAP_NOT_SUPPORT_DATASET_TYPE ((DWORD)0x00001B6BL)

//
// MessageId: SUPERMAP_IMAGE_SCHEMA_NAME
//
// MessageText:
//
//  Ӱ��ģʽ
//
#define SUPERMAP_IMAGE_SCHEMA_NAME       ((DWORD)0x00001B6CL)

//
// MessageId: SUPERMAP_CANT_DELETE_NON_EMPTY_CLASS
//
// MessageText:
//
//  ����ɾ����'%1$ls'����Ϊ����������
//
#define SUPERMAP_CANT_DELETE_NON_EMPTY_CLASS ((DWORD)0x00001B6DL)

//
// MessageId: SUPERMAP_CANT_MODIFY_NON_EMPTY_CLASS
//
// MessageText:
//
//  �����޸���'%1$ls'����Ϊ����������
//
#define SUPERMAP_CANT_MODIFY_NON_EMPTY_CLASS ((DWORD)0x00001B6EL)

//
// MessageId: SUPERMAP_CANT_DELETE_NON_EMPTY_SCHEMA
//
// MessageText:
//
//  ����ɾ��ģʽ'%1$ls'����Ϊ���е��� '%2$ls'��������
//
#define SUPERMAP_CANT_DELETE_NON_EMPTY_SCHEMA ((DWORD)0x00001B6FL)

//
// MessageId: SUPERMAP_CANT_DELETE_CLASS_NOT_FOUND
//
// MessageText:
//
//  ����ɾ����'%1$ls'����Ϊ�Ҳ�������
//
#define SUPERMAP_CANT_DELETE_CLASS_NOT_FOUND ((DWORD)0x00001B70L)

//************************************************************************************
//************************************************************************************
//** GEOMETRY INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_UNKNOWN_SHAPE_TYPE
//
// MessageText:
//
//  �ݲ�֧�ֵ����ݼ������Σ�����'%1$d'
//
#define SUPERMAP_UNKNOWN_SHAPE_TYPE      ((DWORD)0x00001F41L)

//************************************************************************************
//************************************************************************************
//** FEATURE SOURCE INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_FEATURE_SOURCE_NOT_OPEN
//
// MessageText:
//
//  �޷���Ҫ��Դ '%1$ls'
//
#define SUPERMAP_FEATURE_SOURCE_NOT_OPEN ((DWORD)0x00002329L)

//
// MessageId: SUPERMAP_COMPLICATED_FEATURE_OBJECT_NOT_SUPPORTED
//
// MessageText:
//
//  Ҫ��Դ���ݲ�֧�ָ��Ӽ��ζ��� '%1$ls'
//
#define SUPERMAP_COMPLICATED_FEATURE_OBJECT_NOT_SUPPORTED ((DWORD)0x0000232AL)

//
// MessageId: SUPERMAP_LOCKING_NOT_SUPPORTED
//
// MessageText:
//
//  ��֧������ '%1$ls'
//
#define SUPERMAP_LOCKING_NOT_SUPPORTED   ((DWORD)0x0000232BL)

//
// MessageId: SUPERMAP_POINT_FEATURE_SOURCE_NOT_SUPPORT_MULTIPOINT
//
// MessageText:
//
//  ��ͼ�㲻֧�ִ������
//
#define SUPERMAP_POINT_FEATURE_SOURCE_NOT_SUPPORT_MULTIPOINT ((DWORD)0x0000232CL)

//
// MessageId: SUPERMAP_FEATURE_NOT_EXIST
//
// MessageText:
//
//  ��Ҫ���Ѿ������ڣ���ȡ��Ҫ�ؼ��
//
#define SUPERMAP_FEATURE_NOT_EXIST       ((DWORD)0x0000232DL)

//************************************************************************************
//************************************************************************************
//** SPATIAL CONTEXT INFORMATIONS
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_READER_NOT_READY
//
// MessageText:
//
//  '%1$ls'�ռ������ȡ��δ׼����
//
#define SUPERMAP_READER_NOT_READY        ((DWORD)0x00002711L)

//
// MessageId: SUPERMAP_SPATIALCONTEXT_EMPTYWKT
//
// MessageText:
//
//  WKT������Ϊ��
//
#define SUPERMAP_SPATIALCONTEXT_EMPTYWKT ((DWORD)0x00002712L)

//
// MessageId: SUPERMAP_SPATIALCONTEXT_INVALIDWKT
//
// MessageText:
//
//  �Ƿ���WKT����������������ϵ����
//
#define SUPERMAP_SPATIALCONTEXT_INVALIDWKT ((DWORD)0x00002713L)

//
// MessageId: SUPERMAP_SPATIALCONTEXT_CONFLICTINGWKT
//
// MessageText:
//
//  �ռ���������WKT����ͻ
//
#define SUPERMAP_SPATIALCONTEXT_CONFLICTINGWKT ((DWORD)0x00002714L)

//************************************************************************************
//************************************************************************************
//** FILTER INFORMATION
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_OUT_OF_MEMORY_ERROR
//
// MessageText:
//
//  �ڴ����ʧ��
//
#define SUPERMAP_OUT_OF_MEMORY_ERROR     ((DWORD)0x00002AF9L)

//
// MessageId: SUPERMAP_FILTER_MISSING_OPERAND
//
// MessageText:
//
//  �����ж�ʧ�߼������
//
#define SUPERMAP_FILTER_MISSING_OPERAND  ((DWORD)0x00002AFAL)

//
// MessageId: SUPERMAP_FILTER_UNARY_ONLY_SUPPORT_NOT
//
// MessageText:
//
//  һԪ�߼������֧��NOT����
//
#define SUPERMAP_FILTER_UNARY_ONLY_SUPPORT_NOT ((DWORD)0x00002AFBL)

//
// MessageId: SUPERMAP_FILTER_MISSING_EXPRESSION
//
// MessageText:
//
//  ��ʧ������ұ��ʽ
//
#define SUPERMAP_FILTER_MISSING_EXPRESSION ((DWORD)0x00002AFCL)

//
// MessageId: SUPERMAP_FILTER_UNKNOWN_COMPARISION_OPERATION
//
// MessageText:
//
//  δ֪�Ƚ������
//
#define SUPERMAP_FILTER_UNKNOWN_COMPARISION_OPERATION ((DWORD)0x00002AFDL)

//
// MessageId: SUPERMAP_FILTER_MISSING_PROPERTY
//
// MessageText:
//
//  �������ʧ������
//
#define SUPERMAP_FILTER_MISSING_PROPERTY ((DWORD)0x00002AFEL)

//
// MessageId: SUPERMAP_FILTER_EMPTY_PROPERTY_VALUE
//
// MessageText:
//
//  IN�������ʧ����ֵ
//
#define SUPERMAP_FILTER_EMPTY_PROPERTY_VALUE ((DWORD)0x00002AFFL)

//
// MessageId: SUPERMAP_FILTER_BINARY_EXPRESSION_NOT_SUPPORTED
//
// MessageText:
//
//  ��֧�ֵĶ�Ԫ���ʽ
//
#define SUPERMAP_FILTER_BINARY_EXPRESSION_NOT_SUPPORTED ((DWORD)0x00002B00L)

//
// MessageId: SUPERMAP_FILTER_ONLY_SUPPORT_NEGATE
//
// MessageText:
//
//  һԪ���ʽ��֧�ָ�����
//
#define SUPERMAP_FILTER_ONLY_SUPPORT_NEGATE ((DWORD)0x00002B01L)

//
// MessageId: SUPERMAP_FILTER_NOT_SUPPORTED_EXPRESSION
//
// MessageText:
//
//  Ŀǰ��֧�ָñ��ʽ
//
#define SUPERMAP_FILTER_NOT_SUPPORTED_EXPRESSION ((DWORD)0x00002B02L)

//************************************************************************************
//************************************************************************************
//** RASTER INFORMATION
//************************************************************************************
//************************************************************************************
//
// MessageId: SUPERMAP_UNEXPECTED_PARAMETER
//
// MessageText:
//
//  ��Ч����
//
#define SUPERMAP_UNEXPECTED_PARAMETER    ((DWORD)0x00002EE1L)

//
// MessageId: SUPERMAP_PALLETTE_NOT_SUPPORTED
//
// MessageText:
//
//  Ŀǰ����֧�ִ��е�ɫ���ͼ���ȡ
//
#define SUPERMAP_PALLETTE_NOT_SUPPORTED  ((DWORD)0x00002EE2L)

