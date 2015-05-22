// UGSqlDatasource.h: interface for the UGSqlDatasource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSqlDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
#define AFX_UGSqlDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_

#include "ODBCEngine/UGODBCDatasource.h"

namespace UGC
{

extern "C" UGEXPORT UGDataSource* CreateDataSource();

class SQLENGINE_API UGSqlDatasource  : public UGODBCDatasource
{
	friend class UGSqlDatasetVector;
public:
	UGSqlDatasource();
	virtual ~UGSqlDatasource();

public:
	//! \brief ��������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Create();

	//! \brief  ������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Open();

	//! \brief  ��ȡ������ʱ��
	virtual UGTime GetDateLastUpdated() const;

	//! \brief  ��ȡ����ʱ��
	virtual UGTime GetDateCreated() const;

	//! \brief ��������Դ
	virtual UGbool Connect();

	//! \brief  �޸�����
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	//! \brief  ͨ��DatasetVectorInfo�������ݼ�
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);

	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);
	//! \brief  ͨ��DatasetRasterInfo�������ݼ�
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);

	//! \brief  ɾ�����ݼ�(ͨ������)
	virtual UGbool DeleteDataset(const UGString& strName);

	//! \brief �õ�Ԫ���ݿ�
	//! \return �ǿձ�ʾ֧��Ԫ���ݲ���
	//! \remarks 
	//! \attention 
	virtual UGMetadata * GetMetaData();	

	//! \brief �汾����
	//! \brief �����汾
	//! \param strVersionName���汾[in]
	//! \param strDescription���汾������Ϣ[in]
	//! \remarks 
	UGbool CreateDataVersion(UGString &strVersionName,UGString &strDescription);
	//! \brief ɾ���汾
	//! \param strVersionName���汾[in]
	UGbool DeleteDataVersion(UGString &strVersionName);	
	//! \brief ���õ�ǰ�汾
	//! \param strVersionName���汾[in]
	UGbool SetCurrentVersion(UGString &strVersionName);	
	//! \brief ���õ�ǰ�汾
	//! \param nVersionID���汾��[in]
	UGbool SetCurrentVersion(UGint nVersionID);	
	//! \brief ��ȡ�汾��Ϣ
	//! \param aryDataVersionInfos���汾��Ϣ����[out]
	UGbool GetDataVersionInfos(UGArray<UGDataVersionInfo> &aryDataVersionInfos);

public:
	//! \brief �õ����л���ֵ
	//! \param nDatasetID ���ݼ�ID[in]
	virtual UGuint GetSeqValue(UGint nDatasetID);

protected:
	//! \brief ͬ��������Դ�������ݼ�
	//! \param strSrcDatasetName��	 Դ����Դ���ݼ���[in]
	//! \param strDestDatasetName	 Ŀ�����ݼ���[in]
	//! \param codecType			 ���ݼ�����[in]
	//! \param bShowProgress		 �Ƿ���ʾ������[in]
	//! \param bBuildIndxOrPyramid	 �Ƿ񴴽��������߽�����[in]
	//! \return ���ؽ�����ݼ�ָ��
	virtual UGDataset *CopyDatasetLocal(UGDataset *pSrcDataset,const UGString &strDestDatasetName,
		UGDataCodec::CodecType codecType = UGDataCodec::encNONE,
		UGbool bBuildIndxOrPyramid = FALSE);
	
	//! \brief ���ݼ��汾ά��
	//! \brief UGC20��SFC52������ʱ�Զ�����ά��ϵͳ��
	UGbool UpdateVersion();
	//! \brief ��50������
	UGbool OpenRegister50();

	//! \brief ����topo���ݼ� �� smregister ��smparentid�ֶ�
	UGbool OpenRegister53();
	UGbool OpenImgRegister50();

	//! \brief ������Ա�
	UGbool OpenExpandTable();

	//! \brief ���ݼ�ɾ��ʱ��ɾ�������ݼ� 
	void DeleteSubDataset(UGDatasetVector *pSubDataset);

	UGbool ConnectDB();
private:
	UGString m_strSchema;
};

}

#endif // !defined(AFX_UGSqlDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
