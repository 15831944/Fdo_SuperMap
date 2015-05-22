/*! \file	 UGTable.h
 *  \brief	 ���ݼ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGTable.h,v 1.5 2007/11/30 02:28:15 chenyong Exp $
 */

#if !defined(AFX_UGTABLE_H__93882047_ECE5_4A73_9B3F_FD8D539F8C69__INCLUDED_)
#define AFX_UGTABLE_H__93882047_ECE5_4A73_9B3F_FD8D539F8C69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "UGDataset.h"
#include "Base/UGVariant.h"
#include "UGRecordset.h"

namespace UGC{

class ENGINE_API UGTable  
{
public:
	UGTable();
	virtual ~UGTable();

public:
	//! ͨ��ֵ�����ֶ�ֵ
	virtual UGbool UpdateField(const UGString& strFieldName,
		const UGVariant& varValue,const UGString& strFilter = "") =0;

	//! ͨ�����ʽ�����ֶ�ֵ
	virtual UGbool UpdateFieldEx(const UGString& strFieldName,
		const UGString& strExpress,const UGString& strFilter = "") =0;

	//! �����ֶ�ֵ,strSrcField��
	//! strDestField���붼�������ֶ�����ƥ��
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField) =0;

	//! ����ͨ����
	virtual UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName) =0;
	//! ɾ������
	virtual UGbool DropIndex(const UGString& strIndexName) =0;

	//! ��������ֶ�
	virtual UGbool CreateFields(const UGFieldInfos& fieldInfos) =0;
	
	//! ͨ��FieldInfo�����ֶ�
	virtual UGbool CreateField(const UGFieldInfo& fieldInfo) =0;

	//! �����ֶ�
	virtual UGbool CreateField(const UGString& strName,UGFieldInfo::FieldType nType,UGint nSize,UGint nAttributes = 0) =0;

	//! ͨ���ֶ�����ɾ���ֶ�
	virtual UGbool DeleteField(const UGString& strName) =0;

	//! ͨ��������ɾ���ֶ�
	virtual UGbool DeleteField(UGint nIndex) =0;

	//! �ռ������ֶε���Ϣ
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos,UGbool bSystemFieldExcluded = FALSE) =0;

	//! ͨ���ֶ�����ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(const UGString& strName,UGFieldInfo& fieldInfo) =0;
	
	//! ͨ��������ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(UGint nIndex,UGFieldInfo& fieldInfo) =0;

	//! ͨ���ֶ��������ֶ���Ϣ
	virtual UGbool SetFieldInfo(const UGString& strName,const UGFieldInfo& fieldInfo) =0;

	//! ͨ�����������ֶ���Ϣ
	virtual UGbool SetFieldInfo(UGint nIndex,const UGFieldInfo& fieldInfo) =0;
	
	//! ��ȡ�ֶθ���
	virtual UGint GetFieldCount() =0;

	//! ɾ��������������
	virtual UGbool Truncate() =0;

	//! ͳ���ֶ�ֵ
	virtual UGVariant Statistic(const UGString& strField,UGStatisticMode nMode) =0;

	//! �����ֶε�ֵ����
	virtual UGint CalculateUniqueValues(const UGString &strFieldName,UGArray<UGVariant>& varKeys) =0;

public:
	//����һ�º���� 
	UGFieldInfos m_FieldInfos;
};

}

#endif // !defined(AFX_UGTABLE_H__93882047_ECE5_4A73_9B3F_FD8D539F8C69__INCLUDED_)
