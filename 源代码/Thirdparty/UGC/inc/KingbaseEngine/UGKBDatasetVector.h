// UGKBDatasetVector.h: interface for the UGKBDatasetVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGKBDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_)
#define AFX_UGKBDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_

#include "ODBCEngine/UGODBCDatasetVector.h"
#include "Engine/UGFieldInfo.h"
namespace UGC
{

class KINGENGINE_API UGKBDatasetVector  : public UGODBCDatasetVector
{
public:
	UGKBDatasetVector();
	UGKBDatasetVector(UGDataSource *pDataSource);
	virtual ~UGKBDatasetVector();

public:
	//! �����ݼ�
	virtual UGbool Open();

	//! ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName);

	//! ��ѯ���ͼ����һ��ͼ��������
	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
		UGArray<UGString> & arFields,UGdouble dGranule);

	//! ͨ�����η�Χ��ѯͼ�����
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
		UGArray<UGint>& arLibTileIDs);

	//! �õ�һ��ͼ������Ϣ
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
		UGint& nRecCount,UGint& nVersion);

	//! ��ѯͨ�����
	virtual UGRecordset* Query(const UGQueryDef& querydef);

	//! ͨ��Bounds��ѯ
	virtual UGRecordset* QueryWithBounds(const UGRect2D &rc2Bounds,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Geometry,
		UGQueryDef::QueryMode nMode = UGQueryDef::FuzzyQuery);

	//! ͨ��IDs��ѯ
	virtual UGRecordset* QueryWithIDs(UGint *pIDs,UGint nCount,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Both ,
		UGQueryDef::QueryMode nMode = UGQueryDef::GeneralQuery);

	//! ��������ֶ�
	virtual UGbool CreateFields(const UGFieldInfos& fieldInfos);
	
	//! ͨ��FieldInfo�����ֶ�
	virtual UGbool CreateField(const UGFieldInfo& fieldInfo);

	//! �����ֶ�
	virtual UGbool CreateField(const UGString& strName,UGFieldInfo::FieldType nType,
		UGint nSize,UGint nAttributes = 0);

	//! ͨ���ֶ�����ɾ���ֶ�
	virtual UGbool DeleteField(const UGString& strName);

	//! ͨ��������ɾ���ֶ�
	virtual UGbool DeleteField(UGint nIndex);

	//!�������ݼ�
	UGbool Create(const UGString & strName, 
		UGKBDatasetVector *pDatasetParent,
		const UGDatasetVectorInfo & vInfo);

	//! ����������ʱ��
	virtual UGTime GetDateLastUpdated();

	//! ׷�Ӽ�¼
	virtual UGbool Append(UGRecordset* pSrcRecordset, 
		UGbool bShowProgress = TRUE,UGString strTileName = "");

	//! brief  ����ͨ����
	virtual UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName);

	virtual UGint GetNewID();
protected:
	virtual UGbool QueryFieldInfos();
	UGbool  RefreshMemDT();

};

}
#endif // !defined(AFX_UGKBDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_)
