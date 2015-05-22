// UGKBDatasource.h: interface for the UGKBDatasource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGKBDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
#define AFX_UGKBDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_

#include "ODBCEngine/UGODBCDatasource.h"

namespace UGC
{

extern "C" KINGENGINE_API UGDataSource* CreateDataSource();

class KINGENGINE_API UGKBDatasource  : public UGODBCDatasource
{
public:
	UGKBDatasource();
	virtual ~UGKBDatasource();

public:
	//! ��������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Create();

	//! ������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Open();

	//! ��ȡ������ʱ��
	virtual UGTime GetDateLastUpdated() const;

	//! ��ȡ����ʱ��
	virtual UGTime GetDateCreated() const;

	//! �޸�����
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	

	//! ͨ��DatasetVectorInfo�������ݼ�
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);

	//! ͨ��DatasetVectorInfo�������ݼ�
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);

	//! ͨ��DatasetRasterInfo�������ݼ�
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);

	//! ɾ�����ݼ�(ͨ������)
	virtual UGbool DeleteDataset(const UGString& strName);

protected:
	UGbool Connect();

private:
	UGString m_strSchema;

	
};

}

#endif // !defined(AFX_UGKBDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
