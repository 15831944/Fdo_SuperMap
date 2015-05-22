/*! 
	\file	SMCTableRecordset.h
    \brief	��¼��������࣬��ǰ�汾��Ҫ�����¼���Ĺ����ӿ�
	\author	�� ��
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-24 ��ʼ���汾
*/

#ifndef SMCTABLERECORDSET_H
#define SMCTABLERECORDSET_H

#include "SMC.h"
class SMCVariant;
class SMCFieldInfo;
class SMCFieldInfos;

class  SMC_API SMCTableRecordset
{
public:
	SMCTableRecordset(){}
	virtual ~SMCTableRecordset(){}

public:
	//! \brief		��¼���Ƿ�Ϊ��(û�м�¼)
	//! \return		��¼��Ϊ�շ����棬���򷵻ؼ�
	virtual bool IsEmpty() = 0; 

	//! \brief		�жϵ�ǰ��¼ָ���Ƿ�ָ��ͷ
	//! \return		ָ��ָ��ͷ�����棬���򷵻ؼ�
	virtual bool IsBOF() =0;

	//! \brief		�жϵ�ǰ��¼ָ���Ƿ�ָ��β
	//! \return		ָ��ָ��β�������棬���򷵻ؼ�
	virtual bool IsEOF() =0;
	
	//! \brief		�رռ�¼��
	virtual void Close() =0;

	//! \brief		ͨ���ֶ�����ȡ�ֶ�ֵ
	//! \param		[in]strName �ֶ���
	//! \param		[out]varVal �ֶ�ֵ
	//! \raturn		bool ��ȡ�ɹ������棬���򷵻ؼ�
	virtual bool GetFieldValue(const _tstring& strName,SMCVariant &varVal) =0;

	//! \brief		ͨ��������Ż�ȡ�ֶ�ֵ
	//! \param		[in]nIndex �ֶ��������
	//! \param		[out]varVal �ֶ�ֵ
	//! \return		bool ��ȡ�ɹ������棬���򷵻ؼ�
	virtual bool GetFieldValue(int nIndex,SMCVariant &varVal) =0;

	//! brief		ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	//! param		[in]strName �ֶ���
	//! param		[in]varVal �ֶ�ֵ
	//! \return		bool �ɹ����÷����棬���򷵻ؼ�
	virtual bool SetFieldValue(const _tstring& strName,const SMCVariant& varVal) =0;
	
	//! \brief		ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	//! param		[in]strName �ֶ���
	//! param		[in]strVal �ֶ�ֵ
	//! \return		bool �ɹ����÷����棬���򷵻ؼ�
	virtual bool SetFieldValue(const _tstring& strName,const _tstring& strVal) =0;
	
	//! \brief		ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	//! param		[in]nIndex �ֶ��������
	//! param		[in]varVal �ֶ�ֵ
	//! \return		bool �ɹ����÷����棬���򷵻ؼ�
	virtual bool SetFieldValue(int nIndex,const SMCVariant& varVal) =0;

	//! \brief		ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	//! param		[in]strName �ֶ���
	//! param		[in]strVal �ֶ�ֵ
	//! \return		bool �ɹ����÷����棬���򷵻ؼ�
	virtual bool SetFieldValue(int nIndex,	const _tstring& strVal) =0;

	//! \brief		ͨ���ֶ��������ֶ�ֵΪ��
	//! param		[in]strName �ֶ���
	//! \return		bool �ɹ����÷����棬���򷵻ؼ�
	virtual bool SetFieldValueNull(const _tstring& strName) =0;

	//! \brief		ͨ�����������ֶ�ֵΪ��
	//! param		[in]nIndex �ֶ��������
	//! \return		bool �ɹ����÷����棬���򷵻ؼ�
	virtual bool SetFieldValueNull(int nIndex) =0;

	//! \brief		�ڼ�¼�����ٴβ�ѯ,���ҷ��������ĵ�һ����¼
	//! \param		[in]strFilter ��ѯ����
	//! \return		bool �ɹ�ִ�з����棬���򷵻ؼ�
	virtual bool FindFirst(const _tstring& strFilter) =0;
	
	//! \brief		�ڼ�¼�����ٴβ�ѯ,���ҷ������������һ����¼
	//! \param		[in]strFilter ��ѯ����
	//! \return		bool �ɹ�ִ�з����棬���򷵻ؼ�
	virtual bool FindLast(const _tstring& strFilter) =0;

	//! \brief		�ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	//! \param		[in]strFilter ��ѯ����
	//! \return		bool �ɹ�ִ�з����棬���򷵻ؼ�
	virtual bool FindNext(const _tstring& strFilter) =0;

	//! \brief		�ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	//! \param		[in]strFilter ��ѯ����
	//! \return		bool �ɹ�ִ�з����棬���򷵻ؼ�
	virtual bool FindPrev(const _tstring& strFilter) =0;

	//! \brief		������Ӧ����,��ǰ������ƶ���¼ָ��
	//! \param		[in]nRows ָ���ƶ��Ĵ���
	//! \return		bool �ƶ��ɹ������棬���򷵻ؼ�
	virtual bool Move(int nRows) =0;

	//! \brief		�ƶ���¼ָ�뵽��ǰ
	//! \return		�ɹ�ִ�з����棬���򷵻ؼ�
	virtual bool MoveFirst() =0;

	//! \brief		�ƶ���¼ָ�뵽���
	//! \return		�ɹ�ִ�з����棬���򷵻ؼ�
	virtual bool MoveLast() =0;

	//! \brief		�����ƶ�һλ��¼ָ��
	//! \return		�ɹ�ִ�з����棬���򷵻ؼ�
	virtual bool MoveNext() =0;

	//! \brief		�����ƶ�һλ��¼ָ��
	//! \return		�ɹ�ִ�з����棬���򷵻ؼ�
	virtual bool MovePrev() =0;

	//! \brief		�ƶ���¼ָ�뵽ָ��λ��
	//! \param		[in]nRow ָ���ƶ�����λ��
	//! \return		bool �ƶ��ɹ������棬���򷵻ؼ�
	virtual bool MoveTo(int nRow) =0;

	//! \brief		��ȡ��¼����
	//! \return		int ��¼����
	virtual int GetRecordCount() =0;

	//! \brief		�ռ������ֶε���Ϣ
	//! \param		[out]fieldInfos �ֶ���Ϣ����
	//! \return		bool �ɹ���ȡ�����棬���򷵻ؼ�
	virtual bool GetFieldInfos(SMCFieldInfos& fieldInfos) =0;
	
	//! \brief		ͨ���ֶ�����ȡ�ֶ���Ϣ
	//! \param		[in]strName �ֶ���
	//! \param		[out]fieldInfo ��ȡ���ֶ���Ϣ
	//! \return		bool �ɹ���ȡ�����棬���򷵻ؼ�
	virtual bool GetFieldInfo(const _tstring& strName,SMCFieldInfo& fieldInfo)  =0;
	
	//! \brief		ͨ������ȡ�ֶ���Ϣ
	//! \param		[in]nIndex �ֶ�����
	//! \param		[out]fieldInfo ��ȡ���ֶ���Ϣ
	//! \return		bool �ɹ���ȡ�����棬���򷵻ؼ�
	virtual bool GetFieldInfo(int nIndex,SMCFieldInfo& fieldInfo)  =0;
	
	//! \brief		��ȡ�ֶθ���
	//! \return		int �ֶθ���
	virtual int GetFieldCount()  =0; 

};

#endif