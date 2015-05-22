// UGDataSources.h: interface for the UGDataSources class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDataSources.h
   **************************************************************************************
    \author   �¹���
    \brief    ����Դָ������࣬ͨ������Դָ��������Դ������һһ��Ӧ��ϵ���й���
			  ����֤����Դ������Ψһ�ԡ�                                                    
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGDATASOURCES_H__70B46E96_726D_4AAD_A846_D57BCD50C9D0__INCLUDED_)
#define AFX_UGDATASOURCES_H__70B46E96_726D_4AAD_A846_D57BCD50C9D0__INCLUDED_

#include "Base/UGDict.h"
#include "Engine/UGDataSource.h"

namespace UGC {

class WORKSPACE_API UGDataSources  
{	
public:
	UGDataSources();
	virtual ~UGDataSources();

public:
	//========================================================
	//! \brief 		ͨ������Դ������������Դָ�롣
	//! \return 	UGbool ����ҵ��ͷ���true������ͷ���false��
	//! \param 		strAlias ����Դ������
	//! \param 		pResDataSource ��������Դָ�롣
	UGbool Lookup (const UGString& strAlias, UGDataSource* &pResDataSource)const;
	//========================================================
	//! \brief 		�õ�����Դ����Ŀ��
	//! \return 	UGint ���û������Դ�ͷ���0��
	UGint GetCount()const;
	//========================================================
	//! \brief 		�Ƿ񲻴�������Դ��
	//! \return 	UGbool ���û������Դ�ͷ���true������ͷ���false��
	UGbool IsEmpty()const;
	//========================================================
	//! \brief 		��ղ��ͷ�����Դָ�롣
	void RemoveAll();
	//========================================================
	//! \brief 		�����޸�ָ������������Դָ�룬������������ھ�����һ������Դָ�롣
	//! \return 	void
	//! \param 		strAlias ����Դ����������Ϊ���ַ�����
	//! \param 		pDataSource ����Դָ�룬����ΪNULL��
	void SetAt(const UGString& strAlias, UGDataSource *pDataSource);	
	//========================================================
	//! \brief 		�õ�ָ������������Դ������ָ�롣
	//! \return 	UGbool ����ҵ��ͷ���true������ͷ���false��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	//! \param 		strAlias ��������Դ������
	//! \param 		pDataSource ��������Դָ�롣
	UGbool GetAt(UGint nIndex, UGString& strAlias, UGDataSource *&pDataSource)const;

	//========================================================
	//! \brief 		����ָ������������Դָ�룬���ͷ�����Դָ�롣
	//! \return 	UGbool ����������ھͷ���true������ͷ���false��
	//! \param 		strAlias ����Դ������
	UGbool ReleaseAt(const UGString& strAlias);
	//========================================================
	//! \brief 		����ָ������λ�õ�����Դָ�룬���ͷ�����Դָ�롣
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	UGbool ReleaseAt(UGint nIndex);
	
	//========================================================
	//! \brief 		ͨ������Դ��������������
	//! \return 	UGint ����������ҵ��ͷ�������������ͷ���-1��
	//! \param 		UGString ����Դ������
	UGint FindAlias(const UGString& strAlias)const;	
	
	//========================================================
	//! \brief 		ͨ������Դָ���������Դ������
	//! \return 	UGString ����Դ����������ҵ��ͷ�������Դ����������ͷ��ؿ��ַ�����
	//! \param 		pDataSource ����Դָ�룬����ΪNULL��
	UGString GetAlias(UGDataSource* pDataSource)const;

	//========================================================
	//! \brief 		�õ�ָ������λ�õ�����Դ������
	//! \return 	UGString ����Դ����������ҵ��ͷ�������Դ����������ͷ��ؿ��ַ�����
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	UGString GetAliasAt(UGint nIndex)const;
	//========================================================
	//! \brief 		�����޸ı�ʶ���������Լ������ã����Ҷ��������޸ı�ʶ�ĳ�Ա�������á�
	//! \return 	void
	//! \param 		bModified �޸ı�ʶ��
	void SetModifiedFlag(UGbool bModified = true);
	//========================================================
	//! \brief 		�ж��Ƿ����޸ģ�������һ��Ա���޸ġ�
	//! \return 	UGbool ������޸ľͷ���true������ͷ���false��
	UGbool IsModified()const;
	//========================================================
	//! \brief 		����ָ������������Դָ�룬�����ͷ�����Դָ�롣
	//! \return 	UGDataSource* ��������Դָ�룬����Ƴ����ɹ��ͷ���NULL��
	//! \param 		nIndex ����λ�ã�������ڵ���0��С���������
	UGDataSource* RemoveAt(UGint nIndex);
	//========================================================
	//! \brief 		����һ��ָ������������Դָ�롣
	//! \return 	UGbool ����������ھ;ͷ���false������ͷ���true��
	//! \param 		strAlias ����Դ����������Ϊ���ַ�����
	//! \param 		pDataSource ����Դָ�룬����ΪNULL��
	UGbool Insert(const UGString& strAlias, UGDataSource* pDataSource);	
	//========================================================
	//! \brief 		�൱��RemoveAll()��
	//! \return 	void
	void Reset();												
	//========================================================
	//! \brief 		
	//! \return 	UGbool
	//! \param 		strAlias
	//! \param 		strNewAlias
	UGbool Rename(const UGString& strAlias, const UGString& strNewAlias);	
	//========================================================
	//! \brief 		����Դ�����Ƿ���ڡ�
	//! \return 	UGbool ����������ھͷ���true������ͷ���false��
	//! \param 		strAlias ����Դ������
	UGbool IsAliasExisted(const UGString& strAlias)const;					
		
	//========================================================
	//! \brief 		������������Դ��Ϣ��XML�ַ�������������Դָ�뼯�ϣ������ӻ������Դ��
	//! \return 	UGbool ����ɹ��ͷ���true������ͷ���false��
	//! \param 		strXML ��������Դ��Ϣ��XML�ַ�����
	//! \param 		strWorkspaceName �����ռ�ȫ·������
	//! \param 		nVersion �����ռ�汾�š�
	UGbool FromXML(const UGString &strXML, const UGString &strWorkspaceName, UGint nVersion = 0);
	//========================================================
	//! \brief 		������Դ������Ϣ����δXML�ַ�����
	//! \return 	UGString ���ذ�������Դ��Ϣ��XML�ַ�����������ɹ��ͷ��ؿ��ַ�����
	//! \param 		strWorkspaceName �����ռ�ȫ·������
	//! \param 		nVersion �����ռ�汾�š�
	UGString ToXML(const UGString &strWorkspaceName, UGint nVersion = 0)const;

public:
	//! \brief 		�Ƿ��޸ı�ʶ��
	UGbool m_bModified;		
	//! \brief 		����Դ���ϡ�
	UGDict<UGString,UGDataSource*> m_Datasources;	
	//! \brief 		����Դ�������顣
	UGArray<UGString> m_strArrNames;	

};

}

#endif // !defined(AFX_UGDATASOURCES_H__70B46E96_726D_4AAD_A846_D57BCD50C9D0__INCLUDED_)
