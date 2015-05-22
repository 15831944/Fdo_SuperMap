/*! 
	\file	SMCDataSource.h
    \brief	����Դ������࣬��ǰ�汾��Ҫ�����������ݼ�����
	\author	�� ��
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-19 ��ʼ���汾
*/

#ifndef SMCDATASOURCE_H
#define SMCDATASOURCE_H

#include "SMC.h"
#include "SMCDsConnection.h"

class SMCDataset;

class SMC_API SMCDataSource
{
public:

	SMCDataSource();
	virtual ~SMCDataSource();

public:

	//========================================================
	//! \brief		��ȡ��ǰ����Դ���ڵ�Schema
	//! \return     _tstring ��ȡ����Schema
	_tstring GetSchema() const;

	//! \brief      ִ��SQL��䣬��Ҫ���������ݿ⼶ִ�е����ݲ���
	//! \return     bool ��ѯ�ɹ������棬���򷵻ؼ� 
	//! \param      [in]strSQL,Ҫִ�е�SQL���
	virtual bool Execute(const _tstring& strSQL)
	{
		return false;
	}

	//! \brief		��������Դ,��ҪԤ�����ú�������Ϣ
	//! \return     bool �����ɹ������棬���򷵻ؼ�
	virtual bool Create();

	//! \brief		������Դ,��ҪԤ�����ú�������Ϣ
	//! \return     bool �ɹ��򿪷����棬���򷵻ؼ�
	virtual bool Open();

	//! \brief      ����Դ�Ƿ����������
	//! \return     bool �Ѿ����ӷ����棬���򷵻ؼ�
	virtual bool IsConnected();

	//! \brief      �����������ݿ�,��ˢ�����ݼ���
	//! \return     bool ���ӳɹ������棬���򷵻ؼ�
	virtual bool Connect();

	//! \brief      �ر�����Դ
	virtual void Close();
	
	//! \brief      �ж�����Դ�Ƿ��Ѿ���
	//! \return	    bool �Ѿ��򿪷����棬���򷵻ؼ�     
	bool IsOpen() const;
	
	//! \brief      ����������Ϣ
	//! \return	    bool �ɹ�ִ�з����棬���򷵻ؼ�      
	virtual bool SaveInfo();

	//! \brief      �޸�����
	//! \return     bool �ɹ�ִ�з����棬���򷵻ؼ�
	//! \param      strNewPassword ������
	virtual bool ChangePassword(const _tstring& strNewPassword);

	//! \brief	    ɾ�����ݼ�(ͨ������)
	//! \return     bool ɾ���ɹ������棬���򷵻ؼ�
	//! \param      strName ���ݼ�����
	virtual bool DeleteDataset(const _tstring& strName);

public:

	//! \brief		��ȡ����Դ����
	//! \return     _tstring ����Դ������
	_tstring GetName() const ;

	//! \brief		��ȡ��������
	//! \return		_tstring ��������
	virtual _tstring GetEngineName() const ;

	//! \brief		���ݲ�������һ������Դ��Ŀǰû�е����ݼ�����
	//! \return		_tstring ���ɵ����ݼ�������
	//! \param      [in]strDataName ���ݼ�����
	virtual _tstring GetUnoccupiedDatasetName(const _tstring& strDatasetName);

	//! \brief		�ж�����Դ�Ƿ��޸Ĺ�
	//! \return		bool �޸Ĺ������棬 ���򷵻ؼ�
	bool IsModified();

	//! \brief		��������Դ�Ƿ��޸ı�־
	//! \param		[in]bModified Ĭ����Ϊ���޸�
	void SetModifiedFlag(bool bModified = true);

	//! \brief		�������ݼ�����
	//! return		int ����Դ�����ݼ��ĸ���
	int GetDatasetCount() const;

	//! \biref		ͨ����ŷ������ݼ�ָ��
	//! \return		bool �ɹ�ִ�з����棬���򷵻ؼ�
	//! \param		[in]nIndex ���ݼ������
	//! \param		[out]pDdataset ���ص����ݼ�
	//! \note		���øú���ǰ����Ҫ���������ݼ��������Ȼ����ָ��
	bool GetDataset(int nIndex, SMCDataset *&pDdataset) const;

	//! \biref		����ָ�����Ƶ����ݼ�ָ��
	//! \return		bool �ɹ�ִ�з����棬���򷵻ؼ�
	//! \param		[in]strDatasetName ���ݼ�����
	//! \param		[out]pDdataset ���ص����ݼ�
	//! \note		���øú���ǰ����Ҫ���������ݼ��������Ȼ����ָ��
	bool GetDataset(const _tstring& strDatasetName, SMCDataset *&pDdataset) const;

	//! \brief 		�жϴ�����ֶ���������Ƿ����
	//! \return 	bool ���÷����棬���򷵻ؼ�
	//! \param 		[in]strFieldOrTableName �ֶ������߱���
	//! \param 		nInvalidStata
	bool IsValidFieldOrTableName(const _tstring& strFieldOrTableName, int& nInvalidStata);



	//! \brief		��������Դ��������Ϣ
	//! \param      [in] conn ������Ϣ����
	void SetConnection(const SMCDsConnection& dsconn);

	//! \brief		��������Դ
	//! \return		bool �����ɹ������棬���򷵻ؼ�
	//! \param		����Դ���ͣ���ϸ��SMCDsConnection��������
	//! \note		����һ������Դ����󣬱�����øö���Ĵ˳�Ա�����������ɣ�֮����ܴ�����Դ
	bool CreateDataSource(SMCDsConnection::SMEngineType nEngineType);

	//! \brief		���ݸ����Ĳ���������Դ
	//! \return		bool �ɹ��򿪷����棬���򷵻ؼ�
	//! \param		[in]sdbDs ����Դ����
	//! \param		[in]strConnection �����ַ���
	bool OpenDataSource(SMCDataSource &sdbDs, _tstring strConnection);

	//! \brief		��������Oracle��SQL Server����Դ�򿪵ĺ���
	bool OpenOraDS();

public:
    //! \brief		����Դָ��
	void *m_pDataSource;

};
#endif
