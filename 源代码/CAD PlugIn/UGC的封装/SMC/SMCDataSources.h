/*! 
	\file	SMCDataSources.h
    \brief	����Դָ������࣬ͨ������Դָ��������Դ������һһ��Ӧ��ϵ���й���.
	\author	�� ��
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-18 ��ʼ���汾
*/

#ifndef SMCDATASOURCES_H
#define SMCDATASOURCES_H

#include "SMC.h"
#include "SMCDataSource.h"

class SMC_API SMCDataSources
{
public:
	SMCDataSources();
	virtual ~SMCDataSources();

public:
	//! \brief 		�õ�����Դ����Ŀ��
	//! \return 	int ���û������Դ�ͷ���0��
	int GetCount()const;

	//! \brief 		�Ƿ񲻴�������Դ��
	//! \return 	bool ���û������Դ�ͷ���true������ͷ���false��
	bool IsEmpty()const;

	//! \brief 		��ղ��ͷ�����Դָ�롣
	void Reset();

	//! \brief 		����ָ������������Դָ�룬���ͷ�����Դָ�롣
	//! \return 	bool ����������ھͷ���true������ͷ���false��
	//! \param 		strAlias ����Դ������
	bool ReleaseAt(const _tstring& strAlias);

	//! \brief 		����ָ������λ�õ�����Դָ�룬���ͷ�����Դָ�롣
	//! \return 	bool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	bool ReleaseAt(int nIndex);

	//! \brief 		ͨ������Դ��������������
	//! \return 	int ����������ҵ��ͷ�������������ͷ���-1��
	//! \param 		strAlias ����Դ������
	int FindAlias(const _tstring& strAlias)const;	

	//! \brief 		�õ�ָ������λ�õ�����Դ������
	//! \return 	string ����Դ����������ҵ��ͷ�������Դ����������ͷ��ؿ��ַ�����
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	_tstring GetAliasAt(int nIndex)const;

	//! \brief 		�����޸ı�ʶ���������Լ������ã����Ҷ��������޸ı�ʶ�ĳ�Ա�������á�
	//! \return 	void
	//! \param 		bModified �޸ı�ʶ��
	void SetModifiedFlag(bool bModified = true);

	//! \brief 		�ж��Ƿ����޸ģ�������һ��Ա���޸ġ�
	//! \return 	bool ������޸ľͷ���true������ͷ���false��
	bool IsModified()const;

	//! \brief 		
	//! \return 	bool
	//! \param 		strAlias
	//! \param 		strNewAlias
	bool Rename(const _tstring& strAlias, const _tstring& strNewAlias);	

	//! \brief 		����Դ�����Ƿ���ڡ�
	//! \return 	bool ����������ھͷ���true������ͷ���false��
	//! \param 		strAlias ����Դ������
	bool IsAliasExisted(const _tstring& strAlias)const;	

	//! \brief 		������������Դ��Ϣ��XML�ַ�������������Դָ�뼯�ϣ������ӻ������Դ��
	//! \return 	bool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		strXML ��������Դ��Ϣ��XML�ַ�����
	//! \param 		strWorkspaceName �����ռ�ȫ·������
	//! \param 		nVersion �����ռ�汾�š�
	bool FromXML(const _tstring &strXML, const _tstring &strWorkspaceName, int nVersion = 0);

	//! \brief 		������Դ������Ϣ����δXML�ַ�����
	//! \return 	string ���ذ�������Դ��Ϣ��XML�ַ�����������ɹ��ͷ��ؿ��ַ�����
	//! \param 		strWorkspaceName �����ռ�ȫ·������
	//! \param 		nVersion �����ռ�汾�š�
	_tstring ToXML(const _tstring &strWorkspaceName, int nVersion = 0)const;

public:
	//! \brief 		ͨ������Դ������������Դָ�롣
	//! \return 	bool ����ҵ��ͷ���true������ͷ���false��
	//! \param[in] 		strAlias ����Դ������
	//! \param[out] 		pResDataSource ��������Դָ�롣
	bool Lookup (const _tstring& strAlias, SMCDataSource* &pResDataSource)const;

	//! \brief 		�����޸�ָ������������Դָ�룬������������ھ�����һ������Դָ�롣
	//! \param 		strAlias ����Դ����������Ϊ���ַ�����
	//! \param 		pDataSource ����Դָ�룬����ΪNULL��
	void SetAt(const _tstring& strAlias, SMCDataSource *pDataSource);	

	//! \brief 		�õ�ָ������������Դ������ָ�롣
	//! \return 	bool ����ҵ��ͷ���true������ͷ���false��
	//! \param[in] 		nIndex ����λ�ã�������ڵ���0��С���������
	//! \param[out] 		strAlias ��������Դ������
	//! \param[out] 		pDataSource ��������Դָ�롣
	bool GetAt(int nIndex, _tstring& strAlias, SMCDataSource *&pDataSource)const;

	//! \brief 		ͨ������Դָ���������Դ������
	//! \return     ����Դ����������ҵ��ͷ�������Դ����������ͷ��ؿ��ַ�����
	//! \param 		pDataSource ����Դָ�룬����ΪNULL��
	_tstring GetAlias(SMCDataSource* pDataSource)const;

	//! \brief 		����һ��ָ������������Դָ�롣
	//! \return 	bool ����������ھ;ͷ���false������ͷ���true��
	//! \param 		strAlias ����Դ����������Ϊ���ַ�����
	//! \param 		pDataSource ����Դָ�룬����ΪNULL��
	bool Insert(const _tstring& strAlias, SMCDataSource* pDataSource);	

public:
	void* m_pDataSources ;
};

#endif