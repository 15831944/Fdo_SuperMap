//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWebRecordSet.h
//!  \brief UGWebRecordSet �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWEBRECORDSET_H
#define UGWEBRECORDSET_H

#include "Base/ugexports.h"
#include "Base/UGArray.h"
#include "Base/UGVariant.h"
#include "Engine/UGRecordset.h"

namespace UGC{

class WEBENGINE_API UGWebRecordSet : public UGRecordset  
{
public:
	UGWebRecordSet();

	UGWebRecordSet(UGDatasetVector * pDataset);

	virtual ~UGWebRecordSet();
public:
	//! ɾ�����м�¼
	virtual UGbool DeleteAll();

	//! ��ĳ��ͳ�Ʒ���ͳ��ĳ���ֶ�
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);

	//! ˢ�¼�¼��,һ��������²�ѯһ��
	virtual UGbool Refresh();

	//! �����ֶ�ֵ,strSrcField��
	//! strDestField���붼�������ֶ�����ƥ��
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);	
	
	//! ��ȡ��ǰ��¼��ID
	virtual UGint GetID();

	//! �жϵ�ǰ��¼ָ���Ƿ�ָ��ͷ
	virtual UGbool IsBOF();

	//! �жϵ�ǰ��¼ָ���Ƿ�ָ��β
	virtual UGbool IsEOF();
	
	//! �رռ�¼��
	virtual void Close();

	//! ֱ�Ӷ������ζ����ָ��,���ڰ��������ݶ������ڴ��е�����(��dgn)��˵��
	//! ����Ҫ�������ζ�������Ҳ��Ҫȥɾ����,�������Լӿ�����ٶ�
	virtual UGbool GetGeometryDirect(UGGeometry*& pGeometry);

	//! ȡ�ü��ζ��󣬷��صļ��ζ���ָ���ں����ڷ����ڴ棬
	//! ���渺��ɾ������������ڴ�й©
	virtual UGbool GetGeometry(UGGeometry*& pGeometry);

	//! ͨ���ֶ�����ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(const UGString& strName,
		UGVariant& varVal);

	//! ͨ��������Ż�ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(UGint nIndex,
		UGVariant& varVal);

	//! ���õ�ǰ��¼�ļ��ζ���
	virtual UGbool SetGeometry(UGGeometry &geometry);
	
	//! ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGVariant& varVal);
	
	//! ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGString& strVal);
	
	//! ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGVariant& varVal);

	//! ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGString& strVal);	

	//! ͨ���ֶ��������ֶ�ֵΪ��
	virtual UGbool SetFieldValueNull(const UGString& strName);	

	//! ͨ�����������ֶ�ֵΪ��
	virtual UGbool SetFieldValueNull(UGint nIndex);

	//! �ڼ�¼�����ٴβ�ѯ,���ҷ��������ĵ�һ����¼
	virtual UGbool FindFirst(const UGString& strFilter);
	
	//! �ڼ�¼�����ٴβ�ѯ,���ҷ������������һ����¼
	virtual UGbool FindLast(const UGString& strFilter);

	//! �ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	virtual UGbool FindNext(const UGString& strFilter);

	//! �ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	virtual UGbool FindPrev(const UGString& strFilter);

	//! ������Ӧ����,��ǰ������ƶ���¼ָ��
	virtual UGbool Move(UGint nRows);

	//! �ƶ���¼ָ�뵽��ǰ
	virtual UGbool MoveFirst();

	//! �ƶ���¼ָ�뵽���
	virtual UGbool MoveLast();

	//! �����ƶ�һλ��¼ָ��
	virtual UGbool MoveNext();

	//! �����ƶ�һλ��¼ָ��
	virtual UGbool MovePrev();

	//! �ƶ���¼ָ�뵽ָ��λ��
	virtual UGbool MoveTo(UGint nRow);

	//! ͨ��ID��λ��¼ָ��
	virtual UGbool SeekID(UGint nID);

	//! ��ȡ��¼����
	virtual UGint GetRecordCount();

	//! �ռ������ֶε���Ϣ
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos);
	
	
	//! ͨ���ֶ�����ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(const UGString& strName,
		UGFieldInfo& fieldInfo) ;
	
	//! ͨ������ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(UGint nIndex,
		UGFieldInfo& fieldInfo);
	
	//! ��ȡ�ֶθ���
	virtual UGint GetFieldCount();
	
	//! ���£��ύ�޸�
	virtual UGint Update();

	//! ȡ���޸�
	virtual UGbool CancelUpdate();
	
	//! ��ʼ�޸�����
	virtual UGbool Edit();
	
	//! ����¼�¼
	virtual UGint AddNew(UGGeometry *pGeometry,
		UGbool bReturnID=FALSE);

	//! ɾ����ǰ��¼
	virtual UGbool Delete();

	//! ˢ�¼�¼
	virtual void FlushCurrentRecord();
	
	//! �Ƿ�֧������
	virtual UGbool CanTransact() const;

	//! �Ƿ�ɸ���
	virtual UGbool CanUpdate();

	//! �Ƿ�����
	virtual UGbool CanAppend();

	//! �Ƿ�֧��ָ���Ĳ���
	virtual UGbool IsSupport(UGEngAction nAction);

	//! �����¼���ķ�Χ
	virtual UGbool ComputeBounds(UGRect2D &rc2Bounds,
		UGdouble &dMinZ,UGdouble &dMaxZ);	

	//! �ǳ�����״̬�µ�����
	virtual UGbool Lock();

	//! �ǳ�����״̬�µĽ���
	virtual UGbool UnLock();	

	//! �õ���ǰ��¼��˭��������
	virtual UGString GetRecordCheckedBy();

	virtual UGbool UndoCheckOutCurrent(UGbool bKeepCheckedOut);

	virtual UGbool CheckInCurrent(UGbool bKeepCheckedOut);	
	
	virtual UGbool CheckOutCurrent();

	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

	virtual UGbool CheckIn(UGbool bKeepCheckedOut);

	virtual UGbool CheckOut();

	UGString GetFilter() const;
	
	void CheckError() const;

	UGbool Create(const UGQueryDef& queryDef);

	UGbool RefreshPos();

	UGbool IsOpen() const;

	void CheckFields(UGArray<UGString>& fields);

	/// \brief �Ե�ǰ��ѯ�ֶν���һЩ��ʼ��������Ҫ�ǰ�SMID�ŵ���ǰ��
	UGbool InitFields();

	virtual UGString BuildBoundsSQL(const UGRect2D& rc2Bounds);
	
	/// \brief ����General��ѯ��SQL���
	virtual UGString BuildGeneralSQL();
	
	virtual UGString BuildIDsSQL(UGint *pIDs,UGint nCount,UGbool bRTree = FALSE);

	virtual UGbool CreateWithGeneral(const UGQueryDef& querydef);

	/// \brief ����ָ���Ŀռ䷶Χ����Bounds���ƵĲ�ѯ
	/// \param [in]	rc2Bounds	��ѯ���ݼ��� Bounds
	/// \note	ֻ��querydef.m_nOptions == CSmQuerydef::Boundsʱ�Ż���ô˺���
	/// \sa CSmQuerydef, Create, CreteWithGeneral, CreateWithIDs
	virtual UGbool CreateWithBounds(const UGRect2D& rc2Bounds, 
		UGint nOptions,UGint nMode);

	/// \brief ����ָ����ID������в�ѯ��ID��˳����ȡ�����ļ�¼��˳��
	/// \param [in]	pIDs	һ��SmID��IDs��ѯ
	/// \note	ֻ��querydef.m_nOptions == CSmQuerydef::IDsʱ�Ż���ô˺���
	/// \sa CSmQuerydef, Create, CreteWithGeneral, CreateWithBounds
	virtual UGbool CreateWithIDs(UGint *pIDs,UGint nCount,UGint nOptions,UGint nMode,UGbool bRTree = FALSE);
private:
	UGDatasetVector* m_pDataset;
};

}
#endif // !defined(UGWEBRECORDSET_H)
