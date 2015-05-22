// UGODBCDatasetVector.h: interface for the UGODBCDatasetVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCDATASETVECTOR_H__C7B96DD7_2CBA_4F39_AD4_9C23CB53FD__INCLUDED_)
#define AFX_UGODBCDATASETVECTOR_H__C7B96DD7_2CBA_4F39_AD4_9C23CB53FD__INCLUDED_

#include "Engine/UGDatasetVector.h"
#include "Engine/UGDBRTree.h"
#include "Base/UGFileStream.h"
#include "Base/UGThread.h"
#include "Base/UGProgress.h"

namespace UGC
{

class UGODBCConnection;

class UGEXPORT UGODBCDatasetVector  : public UGDatasetVector
{
	friend class UGODBCEditRecordset;
	friend class UGODBCRecordset;
	friend class UGODBCSpatialIndex;

public:
	UGODBCDatasetVector();
	virtual ~UGODBCDatasetVector();

public:
	//! \brief  �ر����ݼ�
	virtual void Close();

	//! \brief  �������ݼ���Ϣ
	virtual UGbool SaveInfo();
	
	//! \brief  ˢ�����ݼ���Ϣ
	virtual UGbool RefreshInfo();

	//! \brief  ����������ʱ��
	virtual UGTime GetDateLastUpdated();

	//! \brief  ���ش���ʱ��
	virtual UGTime GetDateCreated();

	//! \brief  ����������
	virtual UGbool CheckOut();
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

	//! \brief  ͨ��ֵ�����ֶ�ֵ
	virtual UGbool UpdateField(const UGString& strFieldName,
		const UGVariant& varValue,const UGString& strFilter = "");

	//! \brief  ͨ�����ʽ�����ֶ�ֵ
	virtual UGbool UpdateFieldEx(const UGString& strFieldName,
		const UGString& strExpress,const UGString& strFilter = "");

	//! \brief �����ֶ�ֵ,strSrcField��
	//! \brief  strDestField���붼�������ֶ�����ƥ��
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);

	//! \brief  ����ͨ����
	virtual UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName);

	//! \brief  ɾ������
	virtual UGbool DropIndex(const UGString& strIndexName);

	//! \brief  R����������
	UGbool ExtractLeafData(const UGRectUInt& SearchBounds, 
		UGArray<UGint>& aryItemIDs, 
		UGArray<UGint>& aryCertainLeafIDs,
		UGArray<UGRectUInt> &aryCertainBounds,
		UGArray<UGint>& aryMaybeLeafIDs,
		UGArray<UGRectUInt> &aryMaybeBounds,
		UGbool bFuzzy,
		UGdouble dGranule);
	virtual UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
	virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);

	//! \brief  �Ƿ��м������ݣ�����Tablur���ݼ������м�������
	virtual UGbool HasGeometry() const;

	//! \brief  �ռ������ֶε���Ϣ
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos,
		UGbool bSystemFieldExcluded = FALSE);

	//! \brief  ͨ���ֶ�����ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(const UGString& strName,
		UGFieldInfo& fieldInfo);
	
	//! \brief  ͨ��������ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(UGint nIndex,
		UGFieldInfo& fieldInfo);
	
	//! \brief ͨ���ֶ��������ֶ���Ϣ
	virtual UGbool SetFieldInfo(const UGString& strName,
		const UGFieldInfo& fieldInfo);

	//! \brief  ͨ�����������ֶ���Ϣ
	virtual UGbool SetFieldInfo(UGint nIndex,
		const UGFieldInfo& fieldInfo);

	//! \brief  ��ȡ�ֶθ���
	virtual UGint GetFieldCount();

	//! \brief  ɾ��������������
	virtual UGbool Truncate();

	//! \brief  ͳ���ֶ�ֵ
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);
	
	//! \brief  �����ֶε�ֵ����
	virtual UGint CalculateUniqueValues(const UGString &strFieldName,
		UGArray<UGVariant>& varKeys);

	//! \brief  ������SQL��ѯ��¼����,����Register��
	virtual UGbool ComputeRecCount();

	//! \brief  ��ȡ���ռ������ֽڴ�С
	virtual UGint GetMaxGeoSize();

	//! \brief  �������ռ������ֽڴ�С
	virtual UGbool SetMaxGeoSize(UGint nMaxGeoSize);

	//! \brief  ʱ�����ݵ�ע��ʱ��
	virtual UGTime GetRegistSequenceTime();

	//! \brief  ʱ�����ݵ����¸���ʱ��
	virtual UGTime GetLUSequenceTime();

	//! \brief  ͨ��ID����ɾ�����ݼ��еļ�¼
	virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount);

	//! \brief  �ز��������������ݼ���Ч
	virtual UGbool Resample(UGdouble dTolerance,
		UGbool bShowProgress=TRUE);	

	//! \brief  ���ؼ�¼������
	virtual UGint GetRecordsetCount();

	//! \brief  ����ָ�����������ݼ�ָ��
	virtual UGRecordset* GetRecordsetAt(UGint nIndex);

	//! \brief  ͨ�������ͷż�¼��
	virtual UGbool ReleaseRecordset(UGint nIndex);

	//! \brief  ͨ�������ͷż�¼��
	virtual UGbool ReleaseRecordset(UGRecordset *pRecordset);

	//! \brief  ����ѡ����Ϣ
	virtual void SetFlag(UGint nOption,UGbool bHas);

	//! \brief  �ж��ֶ����Ƿ���Ч
	virtual UGbool IsAvailableFieldName(const UGString& strFieldName);

	//! \brief  �õ�ͼ������ͼ������	
	virtual UGString GetMiniatureDtName();

	//! \brief  ͨ������ȡ�ֶ���
	virtual UGString GetFieldNameBySign(FieldSign nSign);
	
	//! \brief  �����ֶε����
	virtual UGbool SetFieldSign(const UGString& strFieldName,FieldSign nSign);

	//! \brief  �жϵ�ǰ���ݼ��Ƿ�ɱ༭
	virtual UGbool CanUpdate();

	//! \brief  ע��ѡ����Ϣ
	virtual UGbool RegisterOption(UGint nOption);

	//! \brief  ��ע��ѡ����Ϣ
	virtual UGbool UnRegisterOption(UGint nOption);

	//! \brief  �������ݼ��ж������,�ٶ���,��ֵ�Ƚ���ȷ,
	//! \brief  ͨ��Register���ȡ
	virtual UGint GetObjectCount();

	//! \brief  ���÷�Χ
	virtual void SetBounds(const UGRect2D& r);
	//! \brief �������ݼ�Bound,һ�������ݼ���Ԫ�ر�ɾ�����޸ĺ�ʹ�ã����ķѴ���ʱ��
	virtual UGbool ComputeBounds();

	//! \brief ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName);
	
protected:
	//! \brief  �����ռ�����
	virtual UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);

	//! \brief ���ݵ�ǰ����״̬�ؽ�����
	//! \param *pDataset [in]��
	//! \return
	//! \remarks
	//! \attention 
	virtual UGbool ReBuildSpatialIndex();

	//! \brief �����ݵĿռ���������
	//! \param *pDataset [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGbool UpdateSpatialIndex();

	//! \brief  ����ռ�����
	virtual UGbool DropSpatialIndex();

	//! \brief  �Ƿ���Ҫ�ؽ��ռ�����
	virtual UGbool IsSpatialIndexDirty();
	
	//! \brief  ���ؿռ�������ļ�¼����Ŀ��Ϊ�Ƿ���Ҫ�ؽ��ռ������ṩ�ο�
	virtual UGint GetDirtyRecordCount();

	//! \brief  �����ݵĿռ���������ͳ�Ʒ���
	virtual UGbool StatisticIndex(UGDataSource *pDs);
	
public:
	//! \brief  ���ò�ѯ��Χ
	void SetQueryBounds(UGRect2D &rcRectBounds);
	
	//! \brief 		���û�����ˢ�����GeometrySize
	//! \return 	void
	//! \remarks 	ֻˢ���ڴ����	
	void RefreshMaxGeoSize();

	/// \brief �����ݿ��ж�ȡ��ǰ���ݼ���Bounds��Ϣ
	/// \remarks �˺�����CDatasetVector::GetBounds�������𣬴˺����Ǵ����ݿ��ж�ȡ���õ��������µ�Bounds����������ֱ�Ӵ��ڴ��ж�ȡm_DatasetInfo�д洢��Bounds��Ϣ���ٶ�Ҫ��ö�
	/// \sa	CDatasetVector::GetBounds
	UGRect2D GetBoundsDirectly();

	//************ͼ��************//
	//! \brief ���ݲ�ѯ��Χ�ڵ�ͼ��ID�����ѯSQL���
	//! \param	[in]	rc2SearchBounds		��ѯ��Χ
	//! \param	[in/out]	strLibTile		������Ĳ�ѯ���
	//! \sa GetLibTileInfo, GetLibTileIDs
	UGbool GetLibTileSQL(const UGRect2D& rc2SearchBounds,UGString & strLibTile);
	//! \brief ���ز�ѯ��Χ�ڵ�LibTileIDs
	//! \param	[in]	rc2Bounds		��ѯ��Χ
	//! \param	[in/out]	aryLibTileIDs	��ѯ������IDs
	//! \sa GetLibTileInfo, GetLibTileSQL
	virtual UGbool GetLibTileIDs(UGRect2D & rc2Bounds,
						UGArray<UGint> &aryLibTileIDs);

	//! \brief ��ȡ����
	UGODBCConnection * GetConnection() const;
	
	//! \brief��������������
	//! \param strFileName �ļ���[in]
	UGbool GetCacheFile(UGString &strFileName,UGint nLibTileID = 0);

	//! \brief �ĵ����л����ֶ�
	virtual UGint GetNewID();

	//! \brief ������ұ������Դ
	//! \param conn������Դ������Ϣ[in]
	void X_CreateLinkDatasource(UGDsConnection &conn);

	//! \brief	�����ַ�����������smOption
	void SetCharset(UGTextCodec::Charset c);
	
protected:
	//! \brief �����ֶ���Ϣ
	//! \param strName���ֶ���[in]
	//! \param strForeignName���ֶα���[in]
	//! \param m_nType���ֶ�����[in]
	UGbool SetFieldInfo(const UGString & strName,const UGString & strForeignName,
		UGFieldInfo::FieldType nType,const UGString & strFormat,
		const UGString & strDomain,UGbool bUpdatable);

	//! \brief ��ȡ�ֶ���Ϣ
	virtual UGbool QueryFieldInfos();

	//! \brief ɾ�����е�����
	//! \param strName������[in]
	virtual UGbool TruncateTable(UGString & strName);

public:
	//! \brief
	// �������ݼ��Ķ����С�Լ�����������20M�ڼ����һ��ȡ����ĸ���
	// �ܶ�ط������õõ������Ծ���Ϊ���п��ų����� added by yanmb
	UGint GetOnceFetchCount();

	//! \brief ͼ�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption		[in]
    virtual UGbool LibTileSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption,
		UGdouble dbTolerance);

	//! \brief R�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption		[in]
	virtual UGbool RTreeSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption,
		UGdouble dbTolerance);

	//! \brief �༶���������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	virtual UGbool DynamicSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption,UGdouble dbTolerance);

private:
	UGint GetKey(const UGRect2D rc2Bounds);
	UGbool Var2Ptr(UGbyte * pDestData,const UGFieldInfo & fieldInfo,UGVariant var);

	//! \brief ���������Χ���������������������¼�������������� 
	//! \param rcBounds ���η�Χ[in]
	//! \param aryGrids ���¼��������������[out]
	UGbool FindQueryGrids(UGRect2D &rcBounds,UGArray<UGPoint> &aryGrids);

	//! \brief ˢ��ѡ����Ϣ
	void RefreshOption();

public:
	UGDBRTree * m_pRTreeIndex;
	//��������
	UGdouble	m_dGranule;
	UGbool m_bMemoryed;
	UGTime m_memLastUpdateTime;
	UGMutex m_mutex;
	UGMutex m_nOpenMutex;
	UGint m_nMaxIndexSize;
protected:
	UGString m_strDescription;
	UGRect2D m_QueryBounds;
	
private:
	UGFileStream m_IndexFile;
};

}

#endif // !defined(AFX_UGODBCDATASETVECTOR_H__C7B96DD7_2CBA_4F39_AD4_9C23CB53FD__INCLUDED_)

