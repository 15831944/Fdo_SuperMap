// UGSqlDatasetVector.h: interface for the UGSqlDatasetVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSqlDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_)
#define AFX_UGSqlDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_

#include "ODBCEngine/UGODBCDatasetVector.h"
#include "Engine/UGFieldInfo.h"
namespace UGC
{

class SQLENGINE_API UGSqlDatasetVector  : public UGODBCDatasetVector
{
public:
	UGSqlDatasetVector();
	UGSqlDatasetVector(UGDataSource *pDataSource);
	virtual ~UGSqlDatasetVector();

public:
	//! \brief �����ݼ�
	virtual UGbool Open();

	//! \brief ��ѯ���ͼ����һ��ͼ��������
	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
		UGArray<UGString> & arFields,UGdouble dGranule);

	//! \brief ͨ�����η�Χ��ѯͼ�����
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
		UGArray<UGint>& arLibTileIDs);

	//! \brief �õ�һ��ͼ������Ϣ
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
		UGint& nRecCount,UGint& nVersion);

	//! \brief ͨ������ȡ�ֶ���
	virtual UGString GetFieldNameBySign(FieldSign nSign);

	//! \brief �����ֶε����
	virtual UGbool SetFieldSign(const UGString& strFieldName,FieldSign nSign);

	//! \brief ��ѯͨ�����
	virtual UGRecordset* Query(const UGQueryDef& querydef);

	//! \brief �������ѯ
	virtual UGRecordset* Query2(UGLinkItem &linkitem);

	//! \brief ͨ��Bounds��ѯ
	// param  rc2Bounds ��ѯ��Χ[in]
	// param  nOptions	��ѯѡ��[in]
	// param  nMode���� ��ѯģʽ[in]
	virtual UGRecordset* QueryWithBounds(const UGRect2D &rc2Bounds,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Geometry,
		UGQueryDef::QueryMode nMode = UGQueryDef::FuzzyQuery);

	//! \brief ͨ��IDs��ѯ
	// param  pIDs	 ��ѯIDs����[in]
	// param  nCount	��ѯ��Ŀ[in]
	// param  nOptions	��ѯѡ��[in]
	// param  nMode���� ��ѯģʽ[in]
	virtual UGRecordset* QueryWithIDs(UGint *pIDs,UGint nCount,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Both ,
		UGQueryDef::QueryMode nMode = UGQueryDef::GeneralQuery);

	//! \brief ��������ֶ�
	// param  fieldInfos �ֶ���Ϣ����[in]
	virtual UGbool CreateFields(const UGFieldInfos& fieldInfos);
	
	//! \brief ͨ��FieldInfo�����ֶ�
	// param  fieldInfo �ֶ���Ϣ[in]
	virtual UGbool CreateField(const UGFieldInfo& fieldInfo);

	//! \brief �����ֶ�
	// param  strName	�ֶ���[in]
	// param  nType		��ѯ����[in]
	// param  nSize		�ֶδ�С[in]
	// param  nAttributes [in]
	virtual UGbool CreateField(const UGString& strName,UGFieldInfo::FieldType nType,
		UGint nSize,UGint nAttributes = 0);

	//! \brief ͨ���ֶ�����ɾ���ֶ�
	virtual UGbool DeleteField(const UGString& strName);

	//! \brief ͨ��������ɾ���ֶ�
	virtual UGbool DeleteField(UGint nIndex);

	//! \brief ע��ѡ����Ϣ
	virtual UGbool RegisterOption(UGint nOption);

	//! \brief ע��ѡ����Ϣ
	virtual UGbool UnRegisterOption(UGint nOption);

	//! \brief �������ݼ�
	UGbool Create(const UGString & strName,
		UGDataset *pDatasetParent,
		const UGDatasetVectorInfo & vInfo);

	//! \brief ����������ʱ��
	virtual UGTime GetDateLastUpdated();

	//! \brief ������ȷ��ID
	virtual UGint GetNewID();

	//! \brief ���ݼ�׷��
	// param pSrcRecordset Դ���ݼ�[in]
	// param bShowProgress���Ƿ���ʾ������[in]
	// param strTileName ��������[in]
	virtual UGbool Append(UGRecordset* pSrcRecordset, 
		UGbool bShowProgress = TRUE,UGString strTileName = "");

	//! \brief ��ȡ�ֶ���Ϣ
	virtual UGbool QueryFieldInfos();


	//! \brief �汾�ύ����
	// param��strVersion��		�汾
	// param��nPostOption		��ͻ�����ʽ
	// param��CheckConfilcts	��¼�����ĳ�ͻ
	virtual UGbool PostToMainVersion(UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);	

	//! \brief �汾�ύ����
	// param��strVersion��		�汾��
	// param��nPostOption		��ͻ�����ʽ
	// param��CheckConfilcts	��¼�����ĳ�ͻ
	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	//! \brief �汾�ύ����
	// param��strVersion��		�汾
	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);


	//! \brief �汾�ع�
	// param��strVersion��		�汾��
	virtual UGbool RollBackVersion(UGint nVersion);

	//! \brief �汾������ط���
	//! \brief ����Դɾ���汾ʱ����
	UGbool U_DeleteVersion(UGint nVersionID);

	//! \brief ˢ�����ݼ���Ϣ
	void U_RefreshExtInfo(UGint nDataVersionID);

protected:
	//! \brief ���������topo ���Ի��topo���ݼ�ָ��
	virtual UGDataset * GetTopoAdscriptionDT();
	virtual UGbool CreateSubDataset(UGDatasetVectorInfo &vInfo);
	virtual UGbool DeleteSubDataset(UGString &strName);

public:
	friend class UGSqlDatasource;
};

}
#endif // !defined(AFX_UGSqlDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_)
