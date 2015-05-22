/*! 
	\file	SMCDatasetVector.h
    \brief	ʸ�����ݼ��ࣨ�����ࣩ
	\author	����
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-21 ��ʼ���汾
*/

#ifndef SMCDATASETVECTOR_H
#define SMCDATASETVECTOR_H

#include "SMC.h"
#include "SMCDataset.h"
#include "SMCTable.h"
#include "SMCQueryDef.h"
#include "SMCRecordset.h"

class SMC_API SMCDatasetVector : public SMCDataset, public SMCTable
{
public:
	SMCDatasetVector();
	~SMCDatasetVector();

public:
	//! \brief	�����ݼ�
	virtual bool Open();

	//! \brief	�ر����ݼ�
	virtual void Close();

	//! \brief		���ݼ�������,ֻ�ı����ݼ���,��������
	//! \param		steNewName  �޸ĺ��������
	//! \return     bool �޸ĳɹ�����true�� ���򷵻�false
	virtual bool Rename(const _tstring& strNewName) ;

	//! \brief		�������ݼ���Ϣ
	//! \return		bool ����ɹ�����true�� ���򷵻�false
	virtual bool SaveInfo();

public:
	//! brief		�������ݼ�����
	//! return		DatasetType ����ʸ�����ݼ�������
	virtual DatasetType GetType() const;
           
	//! brief		�������ݼ���
	//! return		_tstring ����ʸ�����ݼ�����
	virtual _tstring GetName();

	//! \brief		�ж��Ƿ���ʸ�����ݼ�
	//! \return		bool ��ʸ�����ݼ�����true�� ���򷵻�false
	virtual bool IsVector();

	//! \brief		�Ƿ��м������ݣ�����Tablur���ݼ������м�������
	//! \return		bool����м��������򷵻�true�� ���򷵻�false��
	virtual bool HasGeometry() const;

	//! \brief		��ѯͨ�����
	//! \return     bool��ѯ�ɹ�����true�� ���򷵻�false
	//! \param[in]  ��ѯ��������
	//! \param[out] pRecordset���ز�ѯ��ȡ�ļ�¼��
	virtual bool Query(const SMCQueryDef& queryDef, SMCRecordset*& pRecordset);   

	//! \brief		׷�Ӽ�¼
	//! \return		bool ��ӳɹ�����true,����false
	//! \param		pSrcRecordset�������¼
	virtual bool Append(SMCRecordset* pSrcRecordset, 
		bool bShowProgress = TRUE, _tstring strTileName = _T(""));

	//! \brief		��ȡ�����ݼ�ָ��
	//! \return		SMCDataset* ���ظ����ݼ�ָ��
//	SMCDataset* GetParentDataset() const ;   //(�������ݼ���)

	//! \brief		��ȡ�����ݼ�ָ��
	//! \return		SMCDatasetVector*���������ݼ�ָ��		
//	SMCDatasetVector* GetChildDataset() const;  //(�������ݼ���)

	//! \brief		���ز�ѯ�õ��ļ�¼����������
	//! \note       ���ô˺��������ݼ����ȴ�
	virtual int GetRecordsetCount();

	//! \brief		����ָ�������ļ�¼��ָ��
	//! \param[in]	nIndexָ�����صļ�¼�����
	//! \param[out] pRecordset���ػ�ȡ�ļ�¼��
	//! \return     bool��ȡ�ɹ�����true�����򷵻�false
	virtual bool GetRecordsetAt(int nIndex, SMCRecordset*& pRecordset);

	//! ͨ�������ͷż�¼��
	virtual bool ReleaseRecordset(int nIndex);

	//! ͨ�������ͷż�¼��
	virtual bool ReleaseRecordset(SMCRecordset *pRecordset);

};

#endif