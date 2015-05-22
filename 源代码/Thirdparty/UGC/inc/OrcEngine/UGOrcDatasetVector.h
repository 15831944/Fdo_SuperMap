/*! \file	 UGOrcDatasetVector.h
 *  \brief	 Oracle Plus DatasetVector
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 */


#ifndef UGORCDATASETVECTOR_H
#define UGORCDATASETVECTOR_H

#include "Base/ugdefs.h"	// Added by ClassView
#include "Engine/UGDatasetVector.h"
#include "UGOCIConnection.h"
#include "Engine/UGDBRTree.h"
#include "Base/UGThread.h"
#include "Base/UGFileStream.h"
#include "Base/UGProgress.h"
namespace UGC{

class ORCENGINE_API UGOrcDatasetVector  :public UGDatasetVector
{
	friend class UGOrcRecordset;
	friend class UGOrcEditRecordset;
	friend class UGOrcCacheRecordset;
	friend class UGOrcDatasetVectorVersion;
	friend class UGOrcSpatialIndex;
public:
	enum ORCP_DT_OPTION
	{
		ORCP_DT_OPENED				= 0x00000001,
		ORCP_DT_TRANSMODIFIED		= 0x00000002,
		ORCP_DT_CHECKED_OUT			= 0x00000004,
		ORCP_DT_LONGTRANS_REGISTED	= 0x00000008
	};

	UGuint GetOnceFetchCount();
	UGOrcDatasetVector();

	UGOrcDatasetVector(UGDataSource *pDataSource);

	virtual ~UGOrcDatasetVector();

	//!�����ж���Ĵ��麯��
	
	//! �����ݼ�
	virtual UGbool Open();

	//! �ر����ݼ�
	virtual void Close();
	
	//! �������ݼ���Ϣ
	virtual UGbool SaveInfo();
	
	//! ˢ�����ݼ���Ϣ
	virtual UGbool RefreshInfo();

	//! �������ݼ��ķ�Χ
	virtual void SetBounds(const UGRect2D& r);
	
	UGbool Create(const UGString & strName, 
		UGDataset *pDatasetParent,
		const UGDatasetVectorInfo & vInfo);
	
	//! ����������ʱ��
	virtual UGTime GetDateLastUpdated();
	
	//! ���ش���ʱ��
	virtual UGTime GetDateCreated();
	
	//! ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName);		

	//! ��ѯ���ͼ����һ��ͼ��������
	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
		UGArray<UGString> & arFields,UGdouble dGranule);

	UGbool GetLibTileSQL(const UGRect2D& rc2SearchBounds,
		UGString& strLibTile);
	
	//! ͨ�����η�Χ��ѯͼ�����
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
		UGArray<UGint>& arLibTileIDs);
	
	//! �õ�һ��ͼ������Ϣ
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
		UGint& nRecCount,UGint& nVersion);
	
	/// \brief ���õ�ǰ���ݼ�������Geometry�Ĵ�С
	/// \remarks �ڲ�ѯʱ��Ҫ�������ݼ�����Geometry�Ĵ�С�����ڴ滺��ռ�
	UGbool SetMaxGeometrySize(UGuint nRawsize);

	//! ����������
	virtual UGbool CheckOut();
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

	UGint GetLoggedUserID();
	UGint GetLockedUserID();
	UGint GetCheckedUserID();
	
	
	//! ͨ��ֵ�����ֶ�ֵ
	virtual UGbool UpdateField(const UGString& strFieldName,
		const UGVariant& varValue,const UGString& strFilter = "");
	
	//! ͨ�����ʽ�����ֶ�ֵ
	virtual UGbool UpdateFieldEx(const UGString& strFieldName,
		const UGString& strExpress,const UGString& strFilter = "");
	
	//! �����ֶ�ֵ,strSrcField��
	//! strDestField���붼�������ֶ�����ƥ��
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);
	
	
	//! ����ͨ����
	virtual UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName);
	
	//! ɾ������
	virtual UGbool DropIndex(const UGString& strIndexName);

	//! �Ƿ��м������ݣ�����Tablur���ݼ������м�������
	virtual UGbool HasGeometry() const;
	
	//! ��ѯͨ�����
	virtual UGRecordset* Query(const UGQueryDef& querydef);

	virtual UGRecordset* Query2(UGLinkItem &linkitem);
	
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
	
	//! �ռ������ֶε���Ϣ
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos,
		UGbool bSystemFieldExcluded = FALSE);
	
	//! ͨ���ֶ�����ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(const UGString& strName,
		UGFieldInfo& fieldInfo);
	
	//! ͨ��������ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(UGint nIndex,
		UGFieldInfo& fieldInfo);
	
	//! ͨ���ֶ��������ֶ���Ϣ
	virtual UGbool SetFieldInfo(const UGString& strName,
		const UGFieldInfo& fieldInfo);
	
	//! ͨ�����������ֶ���Ϣ
	virtual UGbool SetFieldInfo(UGint nIndex,
		const UGFieldInfo& fieldInfo);
	
	//! ��ȡ�ֶθ���
	virtual UGint GetFieldCount();
		
	//! ɾ��������������
	virtual UGbool Truncate();
	
	//! ͳ���ֶ�ֵ
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);
	
	//! �����ֶε�ֵ����
	virtual UGint CalculateUniqueValues(const UGString &strFieldName,
		UGArray<UGVariant>& varKeys);
	
	//! ������SQL��ѯ��¼����,����Register��
	virtual UGbool ComputeRecCount();
	
	//! ��ȡ���ռ������ֽڴ�С
	virtual UGint GetMaxGeoSize();
	
	//! �������ռ������ֽڴ�С
	virtual UGbool SetMaxGeoSize(UGint nMaxGeoSize);
	
	//! ʱ�����ݵ�ע��ʱ��
	virtual UGTime GetRegistSequenceTime();
	
	//! ʱ�����ݵ����¸���ʱ��
	virtual UGTime GetLUSequenceTime();
	
	//! ͨ��ID����ɾ�����ݼ��еļ�¼
	virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount);
	
	//! ׷�Ӽ�¼
	virtual UGbool Append(UGRecordset* pSrcRecordset,UGbool bShowProgress = TRUE,
		UGString strTileName = "");
	
	//! �ز��������������ݼ���Ч
	virtual UGbool Resample(UGdouble dTolerance,
		UGbool bShowProgress=TRUE);	
	
	//! ���ؼ�¼������
	virtual UGint GetRecordsetCount();
	
	//! ����ָ�����������ݼ�ָ��
	virtual UGRecordset* GetRecordsetAt(UGint nIndex);
	
	//! ͨ�������ͷż�¼��
	virtual UGbool ReleaseRecordset(UGint nIndex);
	
	//! ͨ�������ͷż�¼��
	virtual UGbool ReleaseRecordset(UGRecordset *pRecordset);
	
	//! �Ƿ�ÿ���������Լ��ķ��
	virtual UGbool HasStyle();

	//! �����Ƿ�ÿ���������Լ��ķ��
	//virtual void SetStyleFlag(UGbool bHasStyle);
	virtual void SetFlag(UGint nOption,UGbool bHas);
	
	//! �ж��ֶ����Ƿ���Ч
	virtual UGbool IsAvailableFieldName(const UGString& strFieldName);
	
	//! �õ�ͼ������ͼ������	
	virtual UGString GetMiniatureDtName();		
	
	//! ͨ������ȡ�ֶ���
	virtual UGString GetFieldNameBySign(FieldSign nSign);
	
	//! �����ֶε����
	virtual UGbool SetFieldSign(const UGString& strFieldName,FieldSign nSign);

	//! �жϵ�ǰ���ݼ��Ƿ�ɱ༭
	virtual UGbool CanUpdate();

	//! ע��ѡ����Ϣ
	virtual UGbool RegisterOption(UGint nOption);

	//! ��ע��ѡ����Ϣ
	virtual UGbool UnRegisterOption(UGint nOption);

	//!���ݼ��Ƿ�֧��ĳ�ֲ���ģʽ
	virtual UGbool HasAbility(UGEngAbility dwEngAbility);

	virtual UGbool IsSupport(UGEngAction nAction);

	//! �������ݼ���Χ,һ�������ݼ���Ԫ�ر�ɾ�����޸ĺ�ʹ��,
	//! ���ܺķѽ϶�ʱ��
	virtual UGbool ComputeBounds();

	//! �������ݼ��ж������,�ٶ���,��ֵ�Ƚ���ȷ,
	//! ͨ��Register���ȡ
	virtual UGint GetObjectCount();

	virtual UGbool PostToMainVersion(UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);	

	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);


	virtual UGbool RollBackVersion(UGint nVersion);

	
	//! R����������
	virtual UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
	virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);
	
	virtual UGbool ExtractLeafData(const UGRectUInt& SearchBounds, 
		UGArray<UGint>& aryItemIDs, 
		UGArray<UGint>& aryCertainLeafIDs,
		UGArray<UGRectUInt> &aryCertainBounds,
		UGArray<UGint>& aryMaybeLeafIDs,
		UGArray<UGRectUInt> &aryMaybeBounds,
		UGbool bFuzzy,
		UGdouble dGranule);

protected:
	//! �����ռ�����
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

	//! ����ռ�����
	virtual UGbool DropSpatialIndex();

	//! �Ƿ���Ҫ�ؽ��ռ�����
	virtual UGbool IsSpatialIndexDirty();

	//! �����ݵĿռ���������ͳ�Ʒ���
	virtual UGbool StatisticIndex(UGDataSource *pDs);
	
	//! ���ؿռ�������ļ�¼����Ŀ��Ϊ�Ƿ���Ҫ�ؽ��ռ������ṩ�ο�
	virtual UGint GetDirtyRecordCount();

	//! ���������topo ���Ի��topo���ݼ�ָ��
	virtual UGDataset * GetTopoAdscriptionDT();

	virtual UGbool CreateSubDataset(UGDatasetVectorInfo & vInfo);
	virtual UGbool DeleteSubDataset(UGString &strName);

	//! \brief ͼ�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
    virtual UGbool LibTileSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption, UGdouble dbTolerance);

	virtual UGbool RTreeSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption,
		UGdouble dbTolerance);

	virtual UGbool DynamicSpatialQuery(UGGeometry *pGeo, 
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs, 
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, 
		UGdouble dbTolerance);

	//! \brief ���㷶Χ�߽�����
	//! \param &rcBounds [in]��
	//! \param &aryGrids [out]��
	//! \return T
	//! \remarks �м���ͼ��㼸�㣬aryGrids�������£����ϼ�¼
	//! \attention ��
	UGbool FindQueryGrids(UGRect2D &rcBounds,UGArray<UGPoint> &aryGrids);
public:

	/// \brief �����ݿ��ж�ȡ��ǰ���ݼ���Bounds��Ϣ
	/// \remarks �˺�����CDatasetVector::GetBounds�������𣬴˺����Ǵ����ݿ��ж�ȡ���õ��������µ�Bounds����������ֱ�Ӵ��ڴ��ж�ȡm_DatasetInfo�д洢��Bounds��Ϣ���ٶ�Ҫ��ö�
	/// \sa	CDatasetVector::GetBounds
	UGRect2D GetBoundsDirectly();

	UGbool RegisterUser(UGint nLogID,UGbool bRecordsetLevel = FALSE);

	UGOCIConnection * GetConnection() const;
	
	void CheckError() const;

	UGbool CanTransact();

	UGbool GetCacheFile(UGString &strFileName,UGint nLibTileID);
	UGbool RefreshIndexCache();
	
	UGbool QueryFieldInfos();
	
	UGbool IsSupportMyOption(UGint nMyOption){ return (m_nMyOption & nMyOption) == nMyOption;}
	void SetMyOption(UGint nMyOption){m_nMyOption |= nMyOption;}
	void UnsetMyOption(UGint nMyOption){m_nMyOption &= (~nMyOption);}
	UGString CheckFieldName(UGString strFieldName);
	UGbool ORAType2FieldType(UGString oraType, UGint nLength,UGint nScale,UGFieldInfo::FieldType &nFieldType);

	UGbool SetFieldInfo(const UGString& strName,
		const UGString& strForeignName,
		UGFieldInfo::FieldType nType,
		const UGString & strFormat,
		const UGString & strDomain,
		UGbool bUpdatable);

	UGbool U_CreateTable(UGString strName,UGFieldInfos &fieldInfos);
	void U_RefreshExtInfo(UGint nDataVersionID);

	//����Դɾ���汾ʱ����
	UGbool U_DeleteVersion(UGint nVersionID);

	UGbool IsPointDT();

	//! \brief	�����ַ���������smOption;
	void SetCharset(UGTextCodec::Charset c);

protected:
	void U_CreateLinkDatasource(UGDsConnection &conn);

	//�汾���ݼ� ��ͼ���滻����
	UGString ReplaceTNameByVName(UGString strSQL);
	
private:
	/// \brief ˢ�µ�ǰ���ݼ���ѡ����Ϣ
	/// \sa RegisterOption, UnRegisterOption, CSmDataset::GetOptions
	UGbool RefreshOption();
	
	UGbool Var2Ptr(UGbyte * pDestData,const UGFieldInfo & fieldInfo,UGVariant var);

	UGint GetMaxSmID();

	// \brief ��ȡ�������е�����
	UGString GetSequenceName();

	UGString GetStringbyFieldtype(const UGFieldInfo &fieldInfo);

public:
	UGDBRTree * m_pRTreeIndex;

private:
	UGint m_nMaxIndexSize;	
	UGint m_nMyOption;
	UGint m_nState;
	UGMutex m_mutex;
	UGMutex m_nOpenmutex;
	UGFileStream m_IndexFile;
};

}
#endif // !defined(UGORCDATASETVECTOR_H)
