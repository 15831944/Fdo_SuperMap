// UGSqlDatasetTopo.h: interface for the UGSqlDatasetTopo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSQLDATASETTOPO_H__22002727_16F3_4A2E_8D4A_1537DDD6DCAB__INCLUDED_)
#define AFX_UGSQLDATASETTOPO_H__22002727_16F3_4A2E_8D4A_1537DDD6DCAB__INCLUDED_

#include "Engine/UGTopoDataset.h"
#include "Engine/UGDataSource.h"
#include "ODBCEngine/UGODBCConnection.h"
#include "SqlPlusEngine/UGSqlDatasource.h"

namespace UGC{

class SQLENGINE_API UGSqlDatasetTopo : public UGDatasetTopo  
{
	friend class UGSqlDatasource;

public:
	UGSqlDatasetTopo();
	UGSqlDatasetTopo(UGDataSource *pDS);
	virtual ~UGSqlDatasetTopo();

public:
	//! \brief ������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Open();

	//! \brief �ر����ݼ�
	virtual void Close();

	//! \brief ����������ʱ��
	virtual UGTime GetDateLastUpdated();

	//! \brief ���ش���ʱ��
	virtual UGTime GetDateCreated();
	
	//! \brief �������ݼ���(���Ժͱ�����ͬ)
	virtual UGString GetName();

	//! \brief ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName);

	//! \brief �������ݼ���ѡ����Ϣ(�����ֽڵ��������ݴ���һЩ����)
	virtual UGint GetOptions();

	//! \brief �������ݼ���Ϣ
	virtual UGbool SaveInfo();
	
	//! \brief ˢ�����ݼ���Ϣ
	virtual UGbool RefreshInfo();

	//! \brief �������ݼ���ѡ����Ϣ
	virtual void SetOptions(UGint nOptions);

public:
	//! \brief ���Topo���ݼ�
	virtual UGbool AddDataset(UGDatasetVector *pDatasetVector,UGint nPricision);

	//! \brief ΪTopo���ݼ����Topo����
	// param pDatasetVector	Դ���ݼ�	
	// param pdatasetCheck	Ŀ�����ݼ�
	// param nRule			Topo����
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,UGDatasetVector *pdatasetCheck,TopoRuleMode nRule);
	//! \brief ΪTopo���ݼ����Topo����
	// param pDatasetVector	���ݼ�	
	// param nRule			Topo����
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,TopoRuleMode nRule);

	//! \brief ����ѡ�����ݼ����й��������ݼ���ȷ��ɾ����Rule
	//!	\brief Ҫע��һ�����������ݼ��ж��Rule�������С��ɾ������
	// param nRule			Topo����
	// param strSrcName		Դ���ݼ���
	// param strCheckName	Ŀ�����ݼ���
	virtual UGbool DeleteRule(TopoRuleMode nRule, const UGString &strSrcName, const UGString &strCheckName = "");

public:
	//! \brief ����Topo���ݼ�
	// param strName	���ݼ�����	
	UGbool Create(const UGString &strName);
	//! \brief����ȡ����
	UGODBCConnection * GetConnection() const;	
};

}

#endif // !defined(AFX_UGSQLDATASETTOPO_H__22002727_16F3_4A2E_8D4A_1537DDD6DCAB__INCLUDED_)
