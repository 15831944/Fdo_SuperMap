// UGDB2Datasource.h: interface for the UGDB2Datasource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDB2DATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
#define AFX_UGDB2DATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_

#include "ODBCEngine/UGODBCDatasource.h"

namespace UGC
{

extern "C" DB2ENGINE_API UGDataSource* CreateDataSource();

class DB2ENGINE_API UGDB2Datasource  : public UGODBCDatasource
{
public:
	UGDB2Datasource();
	virtual ~UGDB2Datasource();

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

public:
	virtual UGuint GetSeqValue(UGString &strSeq,UGint nMode = 1);
public:
	UGString GetTbSpaceName();
	UGString GetLongTbSpaceName();
	UGString GetIndexTbSpaceName();

protected:
	UGbool Connect();
	void   ReadTbSpaceInfo();
private:
	UGString m_strSchema;
	UGString m_strTbSpace;
	UGString m_strLongTbSpace;
	UGString m_strIndexTbSpace;
	
};

}

#endif // !defined(AFX_UGDB2DATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
