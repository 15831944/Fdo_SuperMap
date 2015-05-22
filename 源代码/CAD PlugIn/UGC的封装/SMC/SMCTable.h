/*! 
	\file	SMCTable.h
    \brief	���ݼ����ࣨ�����ࣩԤ���ڴ��Ա���չ���������ݵĲ���
	\author	����
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-19 ��ʼ���汾
*/

#ifndef SMCTABLE_H
#define SMCTABLE_H

#include "SMC.h"
#include "SMCFieldInfo.h"
#include "SMCVariant.h"

class SMC_API SMCTable
{
public:
	SMCTable(){}
	virtual ~SMCTable(){}
/*
public:
	//! ͨ��ֵ�����ֶ�ֵ
//	virtual bool UpdateField(const _tstring& strFieldName,
//		const SMCVariant& varValue,const _tstring& strFilter = _T("")) =0;

	//! ͨ�����ʽ�����ֶ�ֵ
	virtual bool UpdateFieldEx(const _tstring& strFieldName,
		const _tstring& strExpress,const _tstring& strFilter = _T("")) =0;

	//! �����ֶ�ֵ,strSrcField��
	//! strDestField���붼�������ֶ�����ƥ��
	virtual bool CopyField(const _tstring& strSrcField,
		const _tstring& strDestField) =0;

	//! ����ͨ����
	virtual bool CreateIndex(const _tstring& strFieldNameList,
		const _tstring& strIndexName) =0;
	//! ɾ������
	virtual bool DropIndex(const _tstring& strIndexName) =0;
	*/
/*
	//! ��������ֶ�
	virtual bool CreateFields(const SMCFieldInfos& fieldInfos) =0;
	
	//! ͨ��FieldInfo�����ֶ�
	virtual bool CreateField(const SMCFieldInfo& fieldInfo) =0;

	//! �����ֶ�
	virtual bool CreateField(const _tstring& strName,SMCFieldInfo::FieldType nType,int nSize,int nAttributes = 0) =0;

	//! ͨ���ֶ�����ɾ���ֶ�
	virtual bool DeleteField(const _tstring& strName) =0;
  
	//! ͨ��������ɾ���ֶ�
	virtual bool DeleteField(int nIndex) =0;

	//! �ռ������ֶε���Ϣ
	virtual bool GetFieldInfos(SMCFieldInfos& fieldInfos,bool bSystemFieldExcluded = FALSE) =0;

	//! ͨ���ֶ�����ȡ�ֶ���Ϣ
	virtual bool GetFieldInfo(const _tstring& strName,SMCFieldInfo& fieldInfo) =0;
	
	//! ͨ��������ȡ�ֶ���Ϣ
	virtual bool GetFieldInfo(int nIndex,SMCFieldInfo& fieldInfo) =0;

	//! ͨ���ֶ��������ֶ���Ϣ
	virtual bool SetFieldInfo(const _tstring& strName,const SMCFieldInfo& fieldInfo) =0;

	//! ͨ�����������ֶ���Ϣ
	virtual bool SetFieldInfo(int nIndex,const SMCFieldInfo& fieldInfo) =0;
	
	//! ��ȡ�ֶθ���
	virtual int GetFieldCount() =0;

	//! ɾ��������������
	virtual bool Truncate() =0;

	//! ͳ���ֶ�ֵ
//	virtual SMCVariant Statistic(const _tstring& strField,UGStatisticMode??? nMode) =0;

	//! �����ֶε�ֵ����
	virtual int CalculateUniqueValues(const _tstring &strFieldName,SMCArray<SMCVariant>& varKeys) =0;
	*/

public:
	void* m_pTable;
};

#endif