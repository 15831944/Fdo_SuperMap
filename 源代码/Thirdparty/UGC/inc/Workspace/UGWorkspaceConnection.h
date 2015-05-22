/*! \file	 UGWorkspaceConnection.h
 *  \brief	 �����ռ�������Ϣ�ඨ��
 *  \author	 xielin
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGWorkspaceConnection.h,v 1.3 2007/09/24 09:02:02 xielin Exp $
 */

#if !defined(AFX_UGWORKSPACECONNECTION_H__FD9EB000_6044_422A_B5AF_CD922BEA06BC__INCLUDED_)
#define AFX_UGWORKSPACECONNECTION_H__FD9EB000_6044_422A_B5AF_CD922BEA06BC__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
//#include "Workspace/UGWorkspace.h"

namespace UGC {
class UGWorkspace;

class WORKSPACE_API UGWorkspaceConnection  
{
public:		
	//! \brief Ĭ�Ϲ��캯��
	UGWorkspaceConnection();

	//! \brief ���캯��
	UGWorkspaceConnection(
		UGint nWorkspaceType,
		const UGString& strWorkspaceName,
		const UGString& strServer,
		const UGString& strDriver,
		const UGString& strDatabase,
		const UGString& strUser,
		const UGString& strPassword);

	//! \brief ���캯��
	UGWorkspaceConnection(
		UGint nWorkspaceType,
		const UGString& strWorkspaceName,
		const UGString& strServer,
		const UGString& strDriver,
		const UGString& strDatabase,
		const UGString& strUser,
		const UGString& strPassword,
		UGint nVersion,
		UGbool bFailIfExists);

	//! ��������
	~UGWorkspaceConnection();

	void operator =(const UGWorkspaceConnection &conn);

	UGbool operator ==(const UGWorkspaceConnection &conn);

public:
	//! \brief �����ռ�����
	UGint	m_nWorkspaceType;
	
	//! \brief ���ݿ���
	UGString		m_strDatabase;

	//! \brief ��������������ļ��͹����ռ䣬��ô����ȫ·�������ļ���
	UGString		m_strServer;

	//! \brief �û���
	UGString		m_strUser;
	
	//! \brief ����
	UGString		m_strPassword;

	//! \brief �����ռ�����
	UGString		m_strWorkspaceName;

	//! \brief ����ļ��͹����ռ���Ч������ļ��Ѿ������Ƿ񷵻�ʧ��,Ĭ����true
	UGbool			m_bFailIfExists;
	
	//! \brief	�����ռ�İ汾��Ĭ����0
	UGint			m_nVersion;

	//! \brief ODBC Driver
	UGString		m_strDriver;	

};


}

#endif // !defined(AFX_UGWORKSPACECONNECTION_H__FD9EB000_6044_422A_B5AF_CD922BEA06BC__INCLUDED_)
