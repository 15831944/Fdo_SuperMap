// UGOrcDatasetTopo.h: interface for the UGOrcDatasetTopo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCDATASETTOPO_H__2749D3DB_8387_4EC3_B436_5D6784AEB79D__INCLUDED_)
#define AFX_UGORCDATASETTOPO_H__2749D3DB_8387_4EC3_B436_5D6784AEB79D__INCLUDED_

#include "Engine/UGTopoDataset.h"
#include "Engine/UGDataSource.h"
#include "OrcEngine/UGOCIConnection.h"

namespace UGC{

class ORCENGINE_API UGOrcDatasetTopo : public UGDatasetTopo
{
	friend class UGOrcDataSource;
public:
	UGOrcDatasetTopo();
	UGOrcDatasetTopo(UGDataSource *p);
	virtual ~UGOrcDatasetTopo();

public:
	//! ������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Open();

	//! �ر����ݼ�
	virtual void Close();

	//! ����������ʱ��
	virtual UGTime GetDateLastUpdated();

	//! ���ش���ʱ��
	virtual UGTime GetDateCreated();
	
	//! �������ݼ���(���Ժͱ�����ͬ)
	virtual UGString GetName();

	//! ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName);

	//! �������ݼ���ѡ����Ϣ(�����ֽڵ��������ݴ���һЩ����)
	virtual UGint GetOptions();

	//! �������ݼ���Ϣ
	virtual UGbool SaveInfo();
	
	//! ˢ�����ݼ���Ϣ
	virtual UGbool RefreshInfo();

	//! �������ݼ���ѡ����Ϣ
	virtual void SetOptions(UGint nOptions);

public:
	virtual UGbool AddDataset(UGDatasetVector *pDatasetVector,UGint nPricision);

	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,UGDatasetVector *pdatasetCheck,TopoRuleMode nRule);
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,TopoRuleMode nRule);

	virtual UGbool DeleteRule(TopoRuleMode nRule, const UGString &strSrcName, const UGString &strCheckName = "");

	void U_CheckError() const;
	
public:
	UGbool Create(const UGString &strName);
	UGOCIConnection * GetConnection() const;

	friend class UGOrcDataSource;
};
}
#endif // !defined(AFX_UGORCDATASETTOPO_H__2749D3DB_8387_4EC3_B436_5D6784AEB79D__INCLUDED_)
