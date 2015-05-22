// UGODBCDatasetTopo.h: interface for the UGODBCDatasetTopo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCDATASETTOPO_H__9C1FD9BA_1546_404F_9BDB_BCBFA5C28518__INCLUDED_)
#define AFX_UGODBCDATASETTOPO_H__9C1FD9BA_1546_404F_9BDB_BCBFA5C28518__INCLUDED_

#include "Engine/UGTopoDataset.h"
#include "Engine/UGDataSource.h"
#include "ODBCEngine/UGODBCConnection.h"
namespace UGC{

class UGEXPORT UGODBCDatasetTopo : public UGDatasetTopo  
{
public:
	UGODBCDatasetTopo();
	UGODBCDatasetTopo(UGDataSource *pDS);
	virtual ~UGODBCDatasetTopo();

public:
	//! \brief  ������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Open();

	//! \brief  �ر����ݼ�
	virtual void Close();

	//! \brief  ����������ʱ��
	virtual UGTime GetDateLastUpdated();

	//! \brief  ���ش���ʱ��
	virtual UGTime GetDateCreated();
	
	//! \brief  �������ݼ���(���Ժͱ�����ͬ)
	virtual UGString GetName();

	//! \brief  ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName);

	//! \brief  �������ݼ���ѡ����Ϣ(�����ֽڵ��������ݴ���һЩ����)
	virtual UGint GetOptions();

	//! \brief  �������ݼ���Ϣ
	virtual UGbool SaveInfo();
	
	//! \brief  ˢ�����ݼ���Ϣ
	virtual UGbool RefreshInfo();

	//! \brief  �������ݼ���ѡ����Ϣ
	virtual void SetOptions(UGint nOptions);

public:
	//! \brief��ΪTopo������ݼ�
	//! \param��pDatasetVector����ӵ����ݼ�[in]
	//! \param��nPricision		���ȼ�[in]
	virtual UGbool AddDataset(UGDatasetVector *pDatasetVector,UGint nPricision);

	//! \brief��ΪTopo���ݼ����Topo����
	//! \param��pDatasetVector��ԴTopo���ݼ�[in]
	//! \param��pdatasetCheck��	Ŀ��Topo���ݼ�[in]
	//! \param��nRule			Topo����[in]
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,UGDatasetVector *pdatasetCheck,TopoRuleMode nRule);
	//! \brief��ΪTopo���ݼ����Topo����
	//! \param��pDatasetVector��Topo���ݼ�[in]
	//! \param��nRule			Topo����[in]
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,TopoRuleMode nRule);

	//! \brief ����ѡ�����ݼ����й��������ݼ���ȷ��ɾ����Rule
	//!	\brief Ҫע��һ�����������ݼ��ж��Rule�������С��ɾ������
	// param nRule			Topo����
	// param strSrcName		Դ���ݼ���
	// param strCheckName	Ŀ�����ݼ���
	virtual UGbool DeleteRule(TopoRuleMode nRule, const UGString &strSrcName, const UGString &strCheckName = "");

public:
	//! \brief������Topo���ݼ�
	// param strName Topo���ݼ���[in]
	UGbool Create(const UGString &strName);

	//! \brief �������
	UGODBCConnection * GetConnection() const;
};

}

#endif // !defined(AFX_UGODBCDATASETTOPO_H__9C1FD9BA_1546_404F_9BDB_BCBFA5C28518__INCLUDED_)
