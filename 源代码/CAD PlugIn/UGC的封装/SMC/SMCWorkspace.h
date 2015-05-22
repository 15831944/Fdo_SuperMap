/*! 
	\file	SMCWorkspace.h
    \brief	�����ռ�����࣬��ǰ�汾��Ҫ������������Դ����
	\author	�� ��
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-18 ��ʼ���汾
*/

#ifndef SMCWORKSPACE_H
#define SMCWORKSPACE_H

#include "SMC.h"
#include "SMCDataSources.h"

class SMC_API SMCWorkspace
{
public:
	enum SMCWorkspaceType
	{
		WS_Version_NO       = 1, //! \brief 	û�й����ռ�
	//	WS_Version_SXW30    = 2, //! \brief 	3.0SXW�����ռ�
	//	WS_Version_SMW30    = 3, //! \brief 	3.0SMW�����ռ�
		WS_Version_SXW		= 4, //! \brief 	SXW�����ռ�
		WS_Version_SUW		= 5, //! \brief 	SUW�����ռ�
		WS_Version_Oracle   = 6, //! \brief 	Oracle�����ռ�
		WS_Version_Sql		= 7	 //! \brief 	Sql�����ռ� 
	};

public:
	SMCWorkspace();
	virtual ~SMCWorkspace();

public:
	//! \brief 		�򿪹����ռ�
	//! \return 	bool ����򿪳ɹ��ͷ���true, ����ͷ���false
	//! \param 		strWorkspaceName ȫ·�������ռ��ļ���
	//! \param 		strPassword �Ƿ���ܣ��������룬���벻��Ϊ�գ�Ϊ�վͱ�ʾû������
	bool Open(const _tstring& strWorkspaceName, const _tstring& strPassword = (_T(""))); 

	//! \brief 		�رչ����ռ䡣	
	void Close();

	//! \brief 		��յ�ǰ�����ռ���������
	void Reset();	

	//! \brief		�����Ƿ��޸ı�־
	void SetModifiedFlag(bool bModified = false);	

	//! \brief 		�Ƿ��޸Ĺ���������һ��Ա���޸ģ�������ͨ�����������ȷ���Ƿ���Ҫ��ʾ�û�����
	bool IsModified()const;

	//! \brief 		���湤���ռ�
	//! \return     bool ����ɹ�����true, ���򷵻�false
	bool Save();

	//! \brief 		��湤���ռ�.
	//! \return 	bool �������ɹ��ͷ���true������ͷ���false��
	//! \param 		strWorkspaceName �����ռ��ļ�������·��
	//! \param 		bFailIfExists����ļ����ڣ��Ƿ񴴽�ʧ��
	//! \param 		bIsXMLFormat �Ƿ�ѹ����ռ���ΪXML����,Ĭ�ϲ�ΪXML��
	//! \param 		strNewPassword �����޸�����,�����µ����롣
	//! \param 		nVersion �汾
	bool SaveAs(const _tstring& strWorkspaceName, 
		        bool bFailIfExists = true,
	  	        bool bIsXMLFormat = false,
				int nVersion = 0,
				const _tstring& strNewPassword = (_T("")));

public:
	//! \brief 		���ع����ռ�����ƣ���ʵ��ȫ·���ļ�����
	_tstring GetName()const;

	//! \brief 		�õ������ռ�����
	//! \note       WS_Version_NO       = 1, //! \brief 	û�й����ռ�
	//! \note		WS_Version_SXW		= 4, //! \brief 	SXW�����ռ�
	//! \note		WS_Version_SUW		= 5, //! \brief 	SUW�����ռ�
	//! \note		WS_Version_Oracle   = 6, //! \brief 	Oracle�����ռ�
	//! \note		WS_Version_Sql		= 7	 //! \brief 	Sql�����ռ�
	int GetType()const;

	//! \brief 		�õ�SUW�����ռ����룬Ҫ��֤��
	_tstring GetPassword()const;

	//! \brief 		�޸Ĺ����ռ����롣
	void ChangePassword(const _tstring& strNewPassword);

public:
	//! \brief		ͨ������Դ������ȡ����Դ
	//! \return		bool��ȡ�ɹ�����true�����򷵻�false
	//! \param[in]  strAlias����Դ����
	//! \param[out] pDataSource��������Դ
	bool GetDataSource(const _tstring& strAlias, SMCDataSource*& pDataSource);

	//! \brief		ͨ������Դ��Ż�ȡ����Դ
	//! \return		bool��ȡ�ɹ�����true�����򷵻�false
	//! \param[in]  nIndex����Դ���
	//! \param[out] pDataSource��������Դ
	bool GetDataSource(int nIndex, SMCDataSource*& pDataSource);

protected:
	void* m_pWorkspace;
public:
	//! ����Դ����
	SMCDataSources m_DataSources;
    
};

#endif 
