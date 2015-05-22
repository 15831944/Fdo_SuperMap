// UGTableRecordset.h: interface for the UGTableRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTABLERECORDSET_H__7C95DC17_F28F_441D_A6C8_4AEB7AC45601__INCLUDED_)
#define AFX_UGTABLERECORDSET_H__7C95DC17_F28F_441D_A6C8_4AEB7AC45601__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "UGFieldInfo.h"

namespace UGC{

class ENGINE_API UGTableRecordset  
{
public:
	UGTableRecordset();
	virtual ~UGTableRecordset();

public:
	//! �Ƿ��¼��Ϊ��(û�м�¼)
	virtual UGbool IsEmpty() = 0; 

	//! �жϵ�ǰ��¼ָ���Ƿ�ָ��ͷ
	virtual UGbool IsBOF() =0;

	//! �жϵ�ǰ��¼ָ���Ƿ�ָ��β
	virtual UGbool IsEOF() =0;
	
	//! �رռ�¼��
	virtual void Close() =0;

	//! ͨ���ֶ�����ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(const UGString& strName,UGVariant& varVal) =0;

	//! ͨ��������Ż�ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(UGint nIndex,UGVariant& varVal) =0;

	//! ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual UGbool SetFieldValue(const UGString& strName,const UGVariant& varVal) =0;
	
	//! ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual UGbool SetFieldValue(const UGString& strName,const UGString& strVal) =0;
	
	//! ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual UGbool SetFieldValue(UGint nIndex,const UGVariant& varVal) =0;

	//! ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual UGbool SetFieldValue(UGint nIndex,	const UGString& strVal) =0;

	//! ͨ���ֶ��������ֶ�ֵΪ��
	virtual UGbool SetFieldValueNull(const UGString& strName) =0;

	//! ͨ�����������ֶ�ֵΪ��
	virtual UGbool SetFieldValueNull(UGint nIndex) =0;

	//! �ڼ�¼�����ٴβ�ѯ,���ҷ��������ĵ�һ����¼
	virtual UGbool FindFirst(const UGString& strFilter) =0;
	
	//! �ڼ�¼�����ٴβ�ѯ,���ҷ������������һ����¼
	virtual UGbool FindLast(const UGString& strFilter) =0;

	//! �ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	virtual UGbool FindNext(const UGString& strFilter) =0;

	//! �ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	virtual UGbool FindPrev(const UGString& strFilter) =0;

	//! ������Ӧ����,��ǰ������ƶ���¼ָ��
	virtual UGbool Move(UGint nRows) =0;

	//! �ƶ���¼ָ�뵽��ǰ
	virtual UGbool MoveFirst() =0;

	//! �ƶ���¼ָ�뵽���
	virtual UGbool MoveLast() =0;

	//! �����ƶ�һλ��¼ָ��
	virtual UGbool MoveNext() =0;

	//! �����ƶ�һλ��¼ָ��
	virtual UGbool MovePrev() =0;

	//! �ƶ���¼ָ�뵽ָ��λ��
	virtual UGbool MoveTo(UGint nRow) =0;

	//! ��ȡ��¼����
	virtual UGint GetRecordCount() =0;

	//! �ռ������ֶε���Ϣ
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos) =0;
	
	//! ͨ���ֶ�����ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(const UGString& strName,UGFieldInfo& fieldInfo)  =0;
	
	//! ͨ������ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(UGint nIndex,UGFieldInfo& fieldInfo)  =0;
	
	//! ��ȡ�ֶθ���
	virtual UGint GetFieldCount()  =0;

public:

	//! ����������ѯ
	virtual UGbool GetForeignKeysVal(UGArray<UGString> &aryForeignKeys,UGArray<UGVariant> &aryVal);
	virtual UGbool FetchForeignKeysVal(UGArray<UGVariant> &aryVal);
};

}

#endif // !defined(AFX_UGTABLERECORDSET_H__7C95DC17_F28F_441D_A6C8_4AEB7AC45601__INCLUDED_)

