;
;/** \file	 SuperMapMessage.h
; *  \brief	 ��ϢID
; *  \author	 ����
; *  \attention 
; *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
; *  All Rights Reserved
; *  \version 1.0
; *  \date 2007-09-19
; */

;
;
;#ifdef __SUPERMAP_MESSAGE_DEFINE__
;// the default message catalog filename
;#	ifdef _WIN32
;		char *fdoshp_cat = "SuperMapMessage.dll";
;#	else
;		char *fdoshp_cat = "SuperMapMessage.cat";
;#	endif
;	FdoString* NlsMsgGet(int msg_num, char* default_msg, ...)
;	{
;		va_list varargs;
;		va_start(varargs, default_msg);
;		FdoString* ret = FdoException::NLSGetMessage(msg_num, default_msg, fdoshp_cat, varargs);
;		va_end(varargs);
;
;		return ret;
;	}
;#else // __SUPERMAP_MESSAGE_DEFINE__
;	extern char *fdoshp_cat;
;	extern FdoString* NlsMsgGet(int msg_num, char* default_msg, ...);
;#endif // __SUPERMAP_MESSAGE_DEFINE__
;

MessageIdTypedef=DWORD

;
;//LanguageNames=(English=0x409:MSG00409)
;//LanguageNames=(Chinese=0x804:MSG00804)
;
LanguageNames=(Chinese=0x804:MSG00804)

MessageId=1000
SymbolicName=SUPERMAP_UNEXPECTED_ERROR
Language=Chinese
��SuperMap���ݷ��ʽӿ��з���δԤ�ϵ�����'%1$ls'��
.
MessageId=1002
SymbolicName=SUPERMAP_OPEN_FAILED
Language=Chinese
������Դʧ�ܡ�
.
MessageId=1003
SymbolicName=SUPERMAP_NULL_ARGUMENT
Language=Chinese
����ΪNULL��
.
MessageId=1004
SymbolicName=SUPERMAP_INVALID_PROPERTY_NAME
Language=Chinese
�������ƴ���
.
MessageId=1005
SymbolicName=SUPERMAP_CONFIGURATION_FILE_NOT_SUPPORTED
Language=Chinese
SuperMap�ṩ�߲�֧�������ļ���
.
;//************************************************************************************
;//************************************************************************************
;//** CONNECTION MESSAGES 
;//************************************************************************************
;//************************************************************************************
MessageId=1006
SymbolicName=SUPERMAP_CONNECTION_ALREADY_OPEN
Language=Chinese
�Ѿ��������ӡ�
.
MessageId=1007
SymbolicName=SUPERMAP_CONNECTION_TIMEOUT_UNSUPPORTED
Language=Chinese
��֧�����ӳ�ʱ��
.
MessageId=1008
SymbolicName=SUPERMAP_CONNECTION_LOCATION_NOT_EXIST
Language=Chinese
���� '%1$ls' �ļ������ڡ�
.
MessageId=1009
SymbolicName=SUPERMAP_INVALID_CONNECTION_STRING
Language=Chinese
��Ч�����ַ��� '%1$ls' ��
.
MessageId=1010
SymbolicName=SUPERMAP_CONNECTION_INVALID
Language=Chinese
������Ч��
.
MessageId=1011
SymbolicName=SUPERMAP_INVALID_CONNECTION_PROPERTY_NAME
Language=Chinese
��Ч���������� '%1$ls'
.
MessageId=1012
SymbolicName=SUPERMAP_CONNECTION_PROPERTY_DATASTORE
Language=Chinese
���ݼ�
.
MessageId=1013
SymbolicName=SUPERMAP_CONNECTION_NOT_ESTABLISHED
Language=Chinese
������Ч��
.

MessageId=1014
SymbolicName=SUPERMAP_CONNECTION_NOT_TYPE
Language=Chinese
ȱ���������͡�
.

MessageId=1015
SymbolicName=SUPERMAP_CONNECTION_NOT_SERVER
Language=Chinese
ȱ�����ӷ�������
.

MessageId=1016
SymbolicName=SUPERMAP_CONNECTION_NOT_DATABASE
Language=Chinese
ȱ���������ݿ⡣
.

MessageId=1017
SymbolicName=SUPERMAP_CONNECTION_NOT_USER
Language=Chinese
ȱ���������ݿ���û���
.

MessageId=1018
SymbolicName=SUPERMAP_CONNECTION_NOT_PASSWORD
Language=Chinese
ȱ���������ݿ�����롣
.
MessageId=1019
SymbolicName=SUPERMAP_CONNECTION_FAIL
Language=Chinese
�������ݿ�ʧ�ܡ�
.

MessageId=1020
SymbolicName=SUPERMAP_CONNECTION_STRING
Language=Chinese
�����ַ���
.


;//************************************************************************************
;//************************************************************************************
;//** SCHEMA-RELATED MESSAGES 
;//************************************************************************************
;//************************************************************************************
MessageId=2001
SymbolicName=SUPERMAP_SCHEMA_FAIL_READ_FEATURE_SCHEMAS
Language=Chinese
�������м���ģʽ����
.
MessageId=2002
SymbolicName=SUPERMAP_SCHEMA_FAIL_READ_SCHEMA_MAPPINGS
Language=Chinese
�������м���ģʽӳ�����
.
MessageId=2003
SymbolicName=SUPERMAP_INVALID_PHYSICAL_SCHEMA_PROVIDER_NAME
Language=Chinese
��Чʵ��ģʽӳ���ṩ����
.
;//************************************************************************************
;//************************************************************************************
;//** CONNECTION PROPERTIES 
;//************************************************************************************
;//************************************************************************************

MessageId=3000
SymbolicName=SUPERMAP_CONNECTION_PROPERTY_DATASOURCE
Language=Chinese
����Դ
.
MessageId=3001
SymbolicName=SUPERMAP_CONNECTIONPROPERTY_TEMPORARY_FILE
Language=Chinese
��ʱĿ¼
.
MessageId=3002
SymbolicName=SUPERMAP_CONNECTIONPROPERTY_CONN_TYPE
Language=Chinese
��������
.


;//************************************************************************************
;//************************************************************************************
;//** TRANSACTION MESSAGES 
;//************************************************************************************
;//************************************************************************************

MessageId=4001
SymbolicName=SUPERMAP_CONNECTION_TRANSACTIONS_NOT_SUPPORTED
Language=Chinese
SuperMap SDB/SDX+ ���ݷ��ʲ�֧��������
.

MessageId=4002
SymbolicName=SUPERMAP_TRANSACTIONS_NOT_START
Language=Chinese
���ݷ��ʲ�����������
.

MessageId=4003
SymbolicName=SUPERMAP_TRANSACTION_SPENT
Language=Chinese
��������Ѿ�ִ�й��ύ��ع���
.

MessageId=4004
SymbolicName=SUPERMAP_NESTED_TRANSACTIONS_NOT_SUPPORTED
Language=Chinese
��֧������Ƕ�ס�
.

;//************************************************************************************
;//************************************************************************************
;//** CONNECTION INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=5001
SymbolicName=SUPERMAP_PROVIDER_DISPLAY_NAME
Language=Chinese
������ SuperMap SDB/SDX+ �� FDO �ṩ����
.
MessageId=5002
SymbolicName=SUPERMAP_PROVIDER_DESCRIPTION
Language=Chinese
�Ի��� SuperMap SDB/SDX+ �����ݴ洢���ж���дȨ�ޡ�
.

;//************************************************************************************
;//************************************************************************************
;//** SELECT INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=6001
SymbolicName=SUPERMAP_UNEXPECTED_DATATYPE
Language=Chinese
Ҫ��Դ���޶�Ӧ����������'%1$ls'
.

;//************************************************************************************
;//************************************************************************************
;//** SCHEMA INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=7001
SymbolicName=SUPERMAP_DEFAULT_SCHEMA_DESCRIPTION
Language=Chinese
ȱʡģʽ
.

MessageId=7002
SymbolicName=SUPERMAP_DEFAULT_SCHEMA_NAME
Language=Chinese
ȱʡģʽ
.

MessageId=7003
SymbolicName=SUPERMAP_PHYSICAL_SCHEMA_MAPPING_NOT_SUPPORTED
Language=Chinese
��֧������ģʽӳ��
.

MessageId=7004
SymbolicName=SUPERMAP_SCHEMA_NOT_SPECIFIED
Language=Chinese
��֧������ģʽӳ��
.

MessageId=7005
SymbolicName=SUPERMAP_SCHEMA_UNSUPPORTED_ELEMENT_STATE
Language=Chinese
��֧�ֵ�ģʽԪ��״̬
.

MessageId=7006
SymbolicName=SUPERMAP_SCHEMA_DELETED_CLASS_IN_ADDED_SCHEMA
Language=Chinese
ģʽԪ��״̬��ͻ���ڴ���ӵ�ģʽ������ɾ������
.

MessageId=7007
SymbolicName=SUPERMAP_SCHEMA_MODIFIED_CLASS_IN_ADDED_SCHEMA
Language=Chinese
ģʽԪ��״̬��ͻ���ڴ���ӵ�ģʽ�������޸ĵ���
.

MessageId=7008
SymbolicName=SUPERMAP_SCHEMA_UNCHANGED_CLASS_IN_ADDED_SCHEMA
Language=Chinese
ģʽԪ��״̬��ͻ���ڴ���ӵ�ģʽ����δ�仯����
.

MessageId=7009
SymbolicName=SUPERMAP_CLASS_NAME_INVALID
Language=Chinese
'%l$s'��Ч��Ҫ������
.

MessageId=7010
SymbolicName=SUPERMAP_SCHEMA_EXCESSIVE_GEOMETRY
Language=Chinese
Ҫ���� '%l$ls' ��������һ����������
.

MessageId=7011
SymbolicName=SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z
Language=Chinese
��ʱ��֧��Zά�Ķ���
.

MessageId=7012
SymbolicName=SUPERMAP_GEOMETRY_NOT_SUPPORTED_M
Language=Chinese
��ʱ��֧��Mά�Ķ���
.

MessageId=7013
SymbolicName=SUPERMAP_DATASET_CREATED_FAILED
Language=Chinese
'%l$ls' ʸ�����ݼ�����ʧ��
.

MessageId=7014
SymbolicName=SUPERMAP_CREATED_FAILED
Language=Chinese
ģʽ����ʧ��
.

MessageId=7015
SymbolicName=SUPERMAP_DATA_TYPE_NOT_SUPPORTED
Language=Chinese
��Fdo��������'%l$d'��provider�ݲ�֧��
.

MessageId=7016
SymbolicName=SUPERMAP_FIELD_CREATED_FAILED
Language=Chinese
�������ݼ����ֶδ���ʧ��
.

MessageId=7017
SymbolicName=SUPERMAP_DATASET_EXIST
Language=Chinese
���������ݼ����Ѿ�����
.

MessageId=7018
SymbolicName=SUPERMAP_SCHEMA_NAME_SHOULD_BE_CHANGED
Language=Chinese
��ģʽ���Ѿ����ڣ����޸�ģʽ����
.

MessageId=7019
SymbolicName=SUPERMAP_NOT_SUPPORT_DATASET_TYPE
Language=Chinese
�Բ�����ʱ��֧�ֵ㡢�ߡ��桢�ı����������ݼ���������ݼ����͡�
.

MessageId=7020
SymbolicName=SUPERMAP_IMAGE_SCHEMA_NAME
Language=Chinese
Ӱ��ģʽ
.

MessageId=7021
SymbolicName=SUPERMAP_CANT_DELETE_NON_EMPTY_CLASS
Language=Chinese
����ɾ����'%1$ls'����Ϊ����������
.

MessageId=7022
SymbolicName=SUPERMAP_CANT_MODIFY_NON_EMPTY_CLASS
Language=Chinese
�����޸���'%1$ls'����Ϊ����������
.

MessageId=7023
SymbolicName=SUPERMAP_CANT_DELETE_NON_EMPTY_SCHEMA
Language=Chinese
����ɾ��ģʽ'%1$ls'����Ϊ���е��� '%2$ls'��������
.

MessageId=7024
SymbolicName=SUPERMAP_CANT_DELETE_CLASS_NOT_FOUND
Language=Chinese
����ɾ����'%1$ls'����Ϊ�Ҳ�������
.


;//************************************************************************************
;//************************************************************************************
;//** GEOMETRY INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=8001
SymbolicName=SUPERMAP_UNKNOWN_SHAPE_TYPE
Language=Chinese
�ݲ�֧�ֵ����ݼ������Σ�����'%1$d'
.

;//************************************************************************************
;//************************************************************************************
;//** FEATURE SOURCE INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=9001
SymbolicName=SUPERMAP_FEATURE_SOURCE_NOT_OPEN
Language=Chinese
�޷���Ҫ��Դ '%1$ls'
.


MessageId=9002
SymbolicName=SUPERMAP_COMPLICATED_FEATURE_OBJECT_NOT_SUPPORTED
Language=Chinese
Ҫ��Դ���ݲ�֧�ָ��Ӽ��ζ��� '%1$ls'
.

MessageId=9003
SymbolicName=SUPERMAP_LOCKING_NOT_SUPPORTED
Language=Chinese
��֧������ '%1$ls'
.

MessageId=9004
SymbolicName=SUPERMAP_POINT_FEATURE_SOURCE_NOT_SUPPORT_MULTIPOINT
Language=Chinese
��ͼ�㲻֧�ִ������
.

MessageId=9005
SymbolicName=SUPERMAP_FEATURE_NOT_EXIST
Language=Chinese
��Ҫ���Ѿ������ڣ���ȡ��Ҫ�ؼ��
.

;//************************************************************************************
;//************************************************************************************
;//** SPATIAL CONTEXT INFORMATIONS
;//************************************************************************************
;//************************************************************************************

MessageId=10001
SymbolicName=SUPERMAP_READER_NOT_READY
Language=Chinese
'%1$ls'�ռ������ȡ��δ׼����
.

MessageId=10002
SymbolicName=SUPERMAP_SPATIALCONTEXT_EMPTYWKT
Language=Chinese
WKT������Ϊ��
.

MessageId=10003
SymbolicName=SUPERMAP_SPATIALCONTEXT_INVALIDWKT
Language=Chinese
�Ƿ���WKT����������������ϵ����
.

MessageId=10004
SymbolicName=SUPERMAP_SPATIALCONTEXT_CONFLICTINGWKT
Language=Chinese
�ռ���������WKT����ͻ
.

;//************************************************************************************
;//************************************************************************************
;//** FILTER INFORMATION
;//************************************************************************************
;//************************************************************************************

MessageId=11001
SymbolicName=SUPERMAP_OUT_OF_MEMORY_ERROR
Language=Chinese
�ڴ����ʧ��
.

MessageId=11002
SymbolicName=SUPERMAP_FILTER_MISSING_OPERAND
Language=Chinese
�����ж�ʧ�߼������
.

MessageId=11003
SymbolicName=SUPERMAP_FILTER_UNARY_ONLY_SUPPORT_NOT
Language=Chinese
һԪ�߼������֧��NOT����
.

MessageId=11004
SymbolicName=SUPERMAP_FILTER_MISSING_EXPRESSION
Language=Chinese
��ʧ������ұ��ʽ
.

MessageId=11005
SymbolicName=SUPERMAP_FILTER_UNKNOWN_COMPARISION_OPERATION
Language=Chinese
δ֪�Ƚ������
.

MessageId=11006
SymbolicName=SUPERMAP_FILTER_MISSING_PROPERTY
Language=Chinese
�������ʧ������
.
MessageId=11007
SymbolicName=SUPERMAP_FILTER_EMPTY_PROPERTY_VALUE
Language=Chinese
IN�������ʧ����ֵ
.

MessageId=11008
SymbolicName=SUPERMAP_FILTER_BINARY_EXPRESSION_NOT_SUPPORTED
Language=Chinese
��֧�ֵĶ�Ԫ���ʽ
.

MessageId=11009
SymbolicName=SUPERMAP_FILTER_ONLY_SUPPORT_NEGATE
Language=Chinese
һԪ���ʽ��֧�ָ�����
.

MessageId=11010
SymbolicName=SUPERMAP_FILTER_NOT_SUPPORTED_EXPRESSION
Language=Chinese
Ŀǰ��֧�ָñ��ʽ
.

;//************************************************************************************
;//************************************************************************************
;//** RASTER INFORMATION
;//************************************************************************************
;//************************************************************************************

MessageId=12001
SymbolicName=SUPERMAP_UNEXPECTED_PARAMETER
Language=Chinese
��Ч����
.

MessageId=12002
SymbolicName=SUPERMAP_PALLETTE_NOT_SUPPORTED
Language=Chinese
Ŀǰ����֧�ִ��е�ɫ���ͼ���ȡ
.
