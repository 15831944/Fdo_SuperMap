/** \file	 SuperMapTransaction.cpp
*  \author	 ����
*  \attention ������û�м����̰߳�ȫ���⣬���Ҫ֧�ֶ��̣߳�����̰߳�ȫ��
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-03-03
*/

#include <SuperMap.h>

SuperMapTransaction::SuperMapTransaction () :
m_pConnection (NULL),
m_bSpent(false)
{
}

SuperMapTransaction::~SuperMapTransaction (void)
{
	if (!m_bSpent)	// ���ʲô������������Ĭ���ύ����
		Commit();
}

/// <summary> Gets the FdoIConnection object associated with the transaction.</summary>
/// <returns>Returns FdoIConnection object</returns>
FdoIConnection* SuperMapTransaction::GetConnection ()
{
	return (FDO_SAFE_ADDREF(m_pConnection));
}

/// <summary> Commits the transaction.</summary>
/// <returns>Returns nothing</returns>
void SuperMapTransaction::Commit ()
{
	TRACE(_T("���� SuperMapTransaction::Commit [�ύ����]...\n"));
	if (m_bSpent)
		throw FdoException::Create (NlsMsgGet(SUPERMAP_TRANSACTION_SPENT, 
								"This transaction has already been committed or rolled back."));

	if (NULL != m_pConnection)
	{
		// finish edit session
		m_pConnection->Flush ();

		// Commit
		UGC::UGDataSource* pDataSource = m_pConnection->GetDataSource();
		if(pDataSource->IsTransacted())	// �ж�����Դ�Ƿ�֧�ֶ��������
		{
			pDataSource->Commit();
		}

		m_bSpent = true;
		m_pConnection->EndTransaction();
	}
}

/// <summary> Rolls back a transaction from a pending state.</summary>
/// <returns>Returns nothing</returns>
void SuperMapTransaction::Rollback ()
{
	TRACE(_T("���� SuperMapTransaction::Rollback [�ع�����]...\n"));
	if (m_bSpent)
		throw FdoException::Create (NlsMsgGet(SUPERMAP_TRANSACTION_SPENT, 
						"This transaction has already been committed or rolled back."));

	if (NULL != m_pConnection)
	{
		// finish edit session
		m_pConnection->Flush ();

		// rollback
		UGC::UGDataSource* pDataSource = m_pConnection->GetDataSource();
		if(pDataSource->IsTransacted())	// �ж�����Դ�Ƿ�֧�ֶ��������
		{
			pDataSource->Rollback();
		}

		m_bSpent = true;
		m_pConnection->EndTransaction();
	}
}

// <summary>Dispose this object.</summary>
// <returns>Returns nothing</returns> 
void SuperMapTransaction::Dispose ()
{
	TRACE(_T("���� SuperMapTransaction::Dispose [����]...\n"));
	m_bSpent = true;
	m_pConnection = NULL;
}

void SuperMapTransaction::SetConnection (SuperMapConnection* pConnection)
{
	// ����ʼ
	m_pConnection = pConnection;
	if (NULL != m_pConnection)
	{
		TRACE(_T("���� SuperMapTransaction::SetConnection [��ʼ����]...\n"));
		UGC::UGDataSource* pDataSource = m_pConnection->GetDataSource();
		if(pDataSource->IsTransacted())	// �ж�����Դ�Ƿ�֧�ֶ��������
		{
			if(!pDataSource->BeginTrans())
			{
				throw FdoException::Create(NlsMsgGet(SUPERMAP_TRANSACTIONS_NOT_START, 
										"Failed to start transaction."));
			}
		}
	}
}

bool SuperMapTransaction::IsSpent ()
{
	return (m_bSpent);
}

