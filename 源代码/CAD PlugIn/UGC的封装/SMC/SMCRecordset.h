/*! 
	\file	SMCRecordset.h
    \brief	��¼���࣬��ǰ�汾��Ҫ�����ѯ�õ��ļ�¼
	\author	�� ��
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-24 ��ʼ���汾
*/

#ifndef SMCRECORDSET_H
#define SMCRECORDSET_H

#include "SMC.h"
#include "SMCTableRecordset.h"

enum SMCStatisticMode
{
	smMax				= 1,	//! ���ֵ
	smMin				= 2,	//! ��Сֵ
	smAvg				= 3,	//! ƽ��ֵ 
	smSum				= 4,	//! �ܺ�
	smStdev				= 5,	//! ��׼��
	smVar				= 6		//! ����
};

class SMCDatasetVector;
class SMCVariant;

class SMC_API SMCRecordset : public SMCTableRecordset
{
public:
	//! ���캯��
	SMCRecordset();
	//! ��������
	virtual ~SMCRecordset();

public:
	//!	\brief		��ȡ��¼����Ӧ�����ݼ�
	//! \param		[out]pDatasetVector ���ص����ݼ�
	//! \return		bool �ɹ���ȡ�����棬���򷵻ؼ�
	bool GetDataset(SMCDatasetVector *&pDatasetVector) const;

	//! \brief		�ж��Ƿ�����������
	//! \return		bool ���������ݷ����棬���򷵻ؼ�
	bool HasDBInfo();

	//! \brief		�ж��Ƿ��м�������
	//! \return		bool �м������ݷ����棬���򷵻ؼ�
	bool HasGeometry();

	//! \brief		ɾ�����м�¼
	//! \return		ɾ���ɹ������棬���򷵻ؼ�
	virtual bool DeleteAll();

	//! \brief		��ĳ��ͳ�Ʒ���ͳ��ĳ���ֶ�
	//! \param		[in]strField �ֶ���
	//! \param		[in]nMode ͳ�Ʒ�ʽ
	virtual bool Statistic(const _tstring& strField,SMCStatisticMode nMode, SMCVariant &varVal);

	//! \brief		ˢ�¼�¼��,һ��������²�ѯһ��
	//! \return		�ɹ�ִ�з����棬���򷵻ؼ�
	virtual bool Refresh();

	//! \brief		�����ֶ�ֵ,strSrcField��
	//! \param		[in]strSrcField Դ�ֶ�
	//! \param		[in]strDestField Ŀ���ֶ�
	//! \return		bool �ɹ�ִ�з����棬���򷵻ؼ�
	//! \attention	���붼�������ֶ�����ƥ��
	virtual bool CopyField(const _tstring& strSrcField,const _tstring& strDestField);

	//! \brief		��ȡ��ǰ��¼��ID
	//! \return		��ȡ����ID,���󷵻�-1
	virtual int GetID();

	//! \brief		�жϼ�¼���Ƿ�Ϊ��
	//! \return		bool Ϊ�շ����棬���򷵻ؼ�
	bool IsEmpty();

	//! \brief		���£��ύ�޸�
	virtual int Update();

	//! \brief		ȡ���޸�
	virtual bool CancelUpdate();

	//! \brief		��ʼ�޸�����
	//! \return		bool �ɹ�ִ�з����棬���򷵻ؼ�
	virtual bool Edit();

	//! \brief		ɾ����ǰ��¼
	//! \return		bool �ɹ�ִ�з����棬���򷵻ؼ�
	virtual bool Delete();

	//! \brief		�Ƿ�ɸ���
	//! \return		������ӷ����棬���򷵻ؼ�
	virtual bool CanUpdate();	

	//! \brief		�Ƿ�����
	//! \return		������ӷ����棬���򷵻ؼ�
	virtual bool CanAppend();



	//�����º����ӻ���������������ϸע�ͼ�����
	//! \brief		�жϵ�ǰ��¼ָ���Ƿ�ָ��β
	virtual bool IsBOF();
	//! \brief		�жϵ�ǰ��¼ָ���Ƿ�ָ��β
	virtual bool IsEOF();
	//! \brief		�رռ�¼��
	virtual void Close();
	//! \brief		ͨ���ֶ�����ȡ�ֶ�ֵ
	virtual bool GetFieldValue(const _tstring& strName,SMCVariant &varVal);
	//! \brief		ͨ��������Ż�ȡ�ֶ�ֵ
	virtual bool GetFieldValue(int nIndex,SMCVariant &varVal);
	//! brief		ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual bool SetFieldValue(const _tstring& strName,const SMCVariant& varVal);
	//! \brief		ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual bool SetFieldValue(const _tstring& strName,const _tstring& strVal);
	//! brief		ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual bool SetFieldValue(int nIndex,const SMCVariant& varVal);
	//! \brief		ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual bool SetFieldValue(int nIndex,	const _tstring& strVal);
	//! \brief		ͨ���ֶ��������ֶ�ֵΪ��
	virtual bool SetFieldValueNull(const _tstring& strName);
	//! \brief		ͨ�����������ֶ�ֵΪ��
	virtual bool SetFieldValueNull(int nIndex);
	//! \brief		�ڼ�¼�����ٴβ�ѯ,���ҷ��������ĵ�һ����¼
	virtual bool FindFirst(const _tstring& strFilter);
	//! \brief		�ڼ�¼�����ٴβ�ѯ,���ҷ������������һ����¼
	virtual bool FindLast(const _tstring& strFilter);
	//! \brief		�ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	virtual bool FindNext(const _tstring& strFilter);
	//! \brief		�ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	virtual bool FindPrev(const _tstring& strFilter);
	//! \brief		������Ӧ����,��ǰ������ƶ���¼ָ��
	virtual bool Move(int nRows);
	//! \brief		�ƶ���¼ָ�뵽��ǰ
	virtual bool MoveFirst();
	//! \brief		�ƶ���¼ָ�뵽���
	virtual bool MoveLast();
	//! \brief		�����ƶ�һλ��¼ָ��
	virtual bool MoveNext();
	//! \brief		�����ƶ�һλ��¼ָ��
	virtual bool MovePrev();
	//! \brief		�ƶ���¼ָ�뵽ָ��λ��
	virtual bool MoveTo(int nRow);
	//! \brief		��ȡ��¼����
	virtual int GetRecordCount();
	//! \brief		�ռ������ֶε���Ϣ
	virtual bool GetFieldInfos(SMCFieldInfos& fieldInfos);
	//! \brief		ͨ���ֶ�����ȡ�ֶ���Ϣ
	virtual bool GetFieldInfo(const _tstring& strName,SMCFieldInfo& fieldInfo);
	//! \brief		ͨ������ȡ�ֶ���Ϣ
	virtual bool GetFieldInfo(int nIndex,SMCFieldInfo& fieldInfo);
	//! \brief		��ȡ�ֶθ���
	virtual int GetFieldCount();

	

public:
	void *m_pRecordset;

};
#endif

