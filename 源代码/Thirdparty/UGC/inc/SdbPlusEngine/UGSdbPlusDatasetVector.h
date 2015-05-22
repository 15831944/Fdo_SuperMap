// SmDataset.h: interface for the UGSdbPlusDatasetVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDBDATASET49_H__017098AB_099E_11D3_92D2_0080C8EE62D1__INCLUDED_)
#define AFX_SDBDATASET49_H__017098AB_099E_11D3_92D2_0080C8EE62D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "Algorithm/UGQTreeManager.h"
#include "Engine/UGDatasetVector.h"

#include "UGRTree.h"

namespace UGC{

class UGFolder;
class UGFileLogical;

class UGSdbPlusDataSource;
class UGSdbPlusRecordset;
   
class SDBPLUSENGINE_API UGSdbPlusDatasetVector : public UGDatasetVector  
{
	friend class UGSdbPlusDataSource;
	friend class UGSdbPlusRecordset;
	friend class UGSdbPlusRecordsetSequence;

public:
	UGSdbPlusDatasetVector();
	UGSdbPlusDatasetVector(UGDataSource *pDataSource);
	virtual ~UGSdbPlusDatasetVector();

public:

	UGbool Open();	//��Dataset
	void Close();	//�ر�Dataset
	UGbool IsOpen() const;	//Dataset�Ƿ��

	UGbool Truncate(); //ɾ�����е���������
	UGbool Rename(const UGString& strNewName);	//���ݼ�������

	UGbool SaveInfo();	//���ݼ���Ϣ����

	//�ռ�����
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

	virtual UGbool DropSpatialIndex();
	virtual UGbool IsSpatialIndexDirty();			//�ռ������Ƿ�"��",�Ƿ���Ҫ�ؽ��ռ�����
	virtual UGint GetDirtyRecordCount();			//���ؿռ�������ļ�¼����Ŀ��Ϊ�Ƿ���Ҫ�ؽ��ռ������ṩ�ο�

	//�����ֶ�����
	virtual UGbool CreateIndex(const UGString &strFieldNameList,const UGString & strIndexName);
	virtual UGbool DropIndex(const UGString & strIndexName);

	//���ݼ�����
//	UGbool HasGeometry();		//�ж��Ƿ�Ϊ�ռ��������ݼ�
	UGbool CanUpdate();		//�ж����ݼ��Ƿ����Update

	/// \brief �жϵ�ǰ���ݼ��Ƿ���ִ��ָ������������
	virtual UGbool HasAbility(UGEngAbility dwEngAbility);

	UGTime GetDateLastUpdated();		//��������������
	UGTime GetDateCreated();			//���ش�������
	UGString GetTableName();

	
	//���ݼ���ѯ
	UGRecordset* Query(const UGQueryDef &querydef);	//ִ�в�ѯ����
	UGRecordset* QueryWithBounds(const UGRect2D &rc2Bounds,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Geometry,
		UGQueryDef::QueryMode nMode = UGQueryDef::FuzzyQuery);

	
	UGRecordset* QueryWithIDs(UGint *pIDs,UGint nCount,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Both ,
		UGQueryDef::QueryMode nMode = UGQueryDef::GeneralQuery);
	
	//! \brief �ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in] 
	//!			0x00000001 �ڲ�
	//!			0x00000002 Maybe					
	//!			0x00000004 �ⲿ
	//! \return �ɹ�
	//! \remarks ��Χ��ȷ�ռ��ѯ
	virtual UGbool SpatialQuery(UGGeoRegion *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption);

	
	//�����ֶ�
	UGbool CreateFields(const UGFieldInfos &fieldInfos);	//�����ֶμ�
	UGbool CreateField(const UGFieldInfo &fieldInfo);	//�����ֶ�
	UGbool CreateField(const UGString &strName, UGFieldInfo::FieldType nType, 
		UGint lSize, UGint lAttributes = 0);	//�����ֶ�
	
	//ɾ��
	UGbool DeleteField(const UGString &strName);	//ɾ��ָ�����ֵ��ֶ�
	UGbool DeleteField(UGint nIndex);	//ɾ��ָ����ŵ��ֶ�
	

	//�ֶ���Ϣ
	UGint GetFieldCount();	//�ֶ���
	UGbool GetFieldInfos(UGFieldInfos &fieldInfos,UGbool bSystemFieldExcluded = false/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);	//�ռ������ֶε���Ϣ
	UGbool GetFieldInfo(const UGString &strName, UGFieldInfo &fieldInfo/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);	//�ռ�ָ�������ֶε���Ϣ
	UGbool GetFieldInfo(UGint nIndex, UGFieldInfo &fieldInfo/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);			//�ռ�ָ������ֶε���Ϣ
	
	virtual UGbool SetFieldInfo(const UGString &strName, const UGFieldInfo &fieldInfo);		//�����ֶ���Ϣ��CDaoFieldInfo�ﶨ��������޷����ã�ֻ���ڴ���ʱ��ָ�������������Կ����趨
	virtual UGbool SetFieldInfo(UGint nIndex, const UGFieldInfo &fieldInfo);				//���õ�nIndex�ֶ���Ϣ,ͬ��
	virtual UGString GetFieldNameBySign(UGDatasetVector::FieldSign nSign);			//���������ֶα�ʶ	
	virtual UGbool SetFieldSign(const UGString& strFieldName,UGDatasetVector::FieldSign nSign);
	
	//ͳ���ֶ�ֵ�������ֶ����ͣ�����һ��������nMode��ͳ�����͡�
	virtual UGVariant Statistic(const UGString& strField,UGStatisticMode nMode);
	//�߽�
	UGbool ComputeBounds();	//�������ݼ�Bounds

	//���ݼ�ѡ���ʱ�����ݼ��ȡ�
	virtual UGbool RegisterOption(UGint dwOption);
	virtual UGbool UnRegisterOption(UGint dwOption);

	virtual UGbool IsSupport(UGEngAction dwEngAction);

	//ע��/��ע��ʱ�����ݼ�
	UGbool RegisterSequence();
	UGbool UnRegisterSequence();

public:
	virtual UGbool RefreshInfo();

	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
											UGArray<UGString> & arFields,
											UGdouble dGranule);

	//! ͨ�����η�Χ��ѯͼ�����
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
								 UGArray<UGint>& arLibTileIDs);

	//! �õ�һ��ͼ������Ϣ
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
									UGint& nRecCount,UGint& nVersion);

	virtual UGbool CheckOut();
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

	virtual UGbool UpdateField(const UGString& strFieldName,
		const UGVariant& varValue,const UGString& strFilter = "");

	//! ͨ�����ʽ�����ֶ�ֵ
	virtual UGbool UpdateFieldEx(const UGString& strFieldName,
		const UGString& strExpress,const UGString& strFilter = "");

	//! �����ֶ�ֵ,strSrcField��
	//! strDestField���붼�������ֶ�����ƥ��
	virtual UGbool CopyField(const UGString& strSrcField,const UGString& strDestField);

	//! R����������
	virtual UGint LoadRTreeLeaf(UGint nID, UGStream &stream);
	virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);

	virtual UGbool HasGeometry() const;

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
	virtual UGbool Append(UGRecordset* pSrcRecordset, 
		UGbool bShowProgress = TRUE,UGString strTileName = "");

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
	virtual void SetFlag(UGint nOption,UGbool bHas);


	//! �ж��ֶ����Ƿ���Ч
	virtual UGbool IsAvailableFieldName(const UGString& strFieldName);

	//! �õ�ͼ������ͼ������	
	virtual UGString GetMiniatureDtName();
	

	//! ��ȡ���ݼ�������Ϣ
	virtual UGString GetDescription() const;
	//! �������ݼ�������Ϣ
	virtual void SetDescription(const UGString& strDesc);

public:  //���ݸ����Ҫ��ʵ�ֶ�̬�ֶ���Ҫ����������
	/*! \brief ɾ����̬�¼�
	 
	 *  \return ɾ���¼��ɹ�����TRUE,���κδ��󷵻�FALSE
	 *  \note  ɾ����̬�¼�Ҫ�������£�
	  1����SmEventProperty����ɾ����ؼ�¼
	  2����tabular�¼�����ɾ�����ζ����ֶ�.(����¼�ɾ��smx,smy)
	 */
	UGbool DeleteEvent();

	/*! \brief ������̬�¼��ļ��ζ���,Ҫ����������ʵ��

	 *  \return 
	 *  \note  �ؼ����ڵ��� 
	         CGeoLineM::GetCoordinateAtM �õ���̬��
	     ��  CGeoLineM::GetSubCurveAtM  �õ���̬��

	 */
	UGbool BuildEventGeometry();

	/*! \brief ���涯̬�¼����Ե����ݿ���

	 *  \return
	 *  \note  ��������ʵ�֡���CSmEventProperty�е����ݴ洢����
	 ����11������
	 1��UGString	  m_strEventRouteIDFieldName; /// �¼�����RouteID�ֶ���
	 2��EventType m_nEventType;			    /// �¼�����
	 3��UGString m_strFromMeasureFieldName; /// ���¼�����ʼMeasure�ֶ�
	 4��UGString m_strToMeasureFieldName;   /// ���¼�����ֹMeasure�ֶ�
	 5��UGString m_strMeasureFieldName;     /// ���¼���Measure
	 6��UGint m_nEventMeasureUnit;          /// Measure��λ
	 7��UGString m_strEventTableName;
	 8��UGString m_strRouteDataSourceAlias; /// Route���ݼ����ڵ�����Դ����
	 9��UGString m_strRouteDtName;		   /// Route���ݼ�����	 
	10��UGString m_strRouteIDFieldName;	   /// RouteID�ֶ�	 
	11��UGString m_strOffsetField;		   /// ���ݶ�λƫ���ֶ�	
	 */
	UGbool SaveEvent();

protected: //call by buildeventgeometry;

	UGbool BuildPointEventGeometry();
	UGbool BuildLineEventGeometry();

protected:

	UGFolder  *m_pFolderDataset;		// ���ݼ���Folder
	CDaoTableDef *m_pTableDef;			// ���ݼ����������ݵ�Table	

	UGFileLogical	*m_pFileInfo;			// ������ݼ���Ϣ,�κ����ݼ�����
	UGFileLogical	*m_pFileMetadata;		// ������ݼ�Ԫ����,�κ����ݼ�����
	UGFileLogical	*m_pFileGeometry;		// ��ſռ�����,Tabular���ݼ��޺���
	UGFileLogical	*m_pFileTree;			// ��ſռ����ݵ�R�������Լ�Q������
	UGFileLogical	*m_pFileIndex;			// ��ſռ����ݵĶ���ID��λ�õĶ�Ӧ��ϵ

	UGQTreeManager m_QTreeIndex;		// �Ĳ�������
	//CSmRTree		m_RTreeIndex;		// R������
	UGRTree		m_RTreeIndex;			// R������

	UGbool m_bCached;				//�Ƿ��ѷ���Cache�ı�־

	UGString m_strDescription;

protected:
	UGint m_nNextID;
	UGint m_nEncryptionKey[2];	//������

protected:  //����ID�Ͷ�����Geometry�ļ��е�λ�ö�Ӧ��

	UGint *m_pIndexTable;		// ���ݿ�����,����ṹΪm_pIndexTable[xxx][2]
								// [0]��ż�¼ID,-1����ü�¼�ѱ�ɾ��;
								// [1]��ż�¼��Geometry�ļ��е�λ��;
	UGint m_nIndexAllCount;		// �����ļ�¼��,�����ѱ���־Ϊɾ����������¼
	UGint m_nIndexValidCount;	// �����ļ�¼��,�������ѱ���־Ϊɾ����������¼

	void AddNewIDandPos(UGint& nID,UGint nGeoPos);  //������ID��Pos
	void GetIDandGeoPos(UGint nIndex,UGint& nID,UGint& nGeoPos); //�õ�ID��Pos
	UGint GetIDByIndex(UGint nIndex);				//����nIndex�õ�ID
	void SetIDByIndex(UGint nIndex,UGint nID);	//����ID
	UGint GetGeoPosByID(UGint nID);				//����ID�õ�Pos
	void SetGeoPosByID(UGint nID,UGint nGeoPos);	//����ID����Pos
	UGint GetGeoPosByIndex(UGint nIndex);			//����λ��(nIndex)�õ�Pos
	void SetGeoPosByIndex(UGint nIndex,UGint nGeoPos); //����index����Pos
	void DeleteIDandPos(UGint nID);			//ɾ��ĳ��ID

	UGint IdToIndexPos(UGint nID);	//����ID��Ӧ�ļ�¼��Dataset�����е����

protected:

	//field info of all table.
	///	\brief	add new record of fieldinfo
	UGbool InsertField(const UGString& strTable,const UGString& strFieldName,const UGString& strCaption);
	UGbool InsertField(const UGFieldInfo& fieldInfo);
	/// \brief delete a record of fieldinfo
	UGbool DeleteField(const UGString& strTable,const UGString& strFieldName);
	/// \brief get field's info,such as caption, domain,updatable
	UGbool GetFieldInfo(const UGString& strTable,const UGString& strFieldName,UGFieldInfo& fieldInfo);
	UGbool GetFieldCaption(const UGString& strTable,const UGString& strFieldName,UGString& strCaption);
	/// \brief alter field info.
	UGbool SetFieldCaption(const UGString& strTable,const UGString& strFieldName,UGFieldInfo& fieldInfo);
	UGbool SetFieldCaption(const UGString& strTable,const UGString& strFieldName,const UGString& strCaption);
	
protected:
	//Ԫ������������
	UGint GetMetadataDescCount();	//����Ԫ������������
	UGbool GetMetadataDesc(UGint nIndex, UGString &strTitle, UGString &strContent);	//����Ԫ��������
	UGint AddMetadataDesc(UGString strTitle, UGString strContent);	//׷��Ԫ���������ַ��������е�Ԫ���������ַ������棬������ӵ���λ��
	void ClearMetadataDesc();				//���ԭ�е�Ԫ��������
	UGbool DeleteMetadataDesc(UGint nIndex);	//ɾ��ָ����Ԫ��������

protected:	//method
	
	//strName		Dataset����
	//nType			Dataste����
	//nOptions		Dataste Options,�μ�SmDatasource.h
	//dwStgmOpt		storage and stream create mode
	//stgDataset	��Storage,��ͨ���ݼ���m_stgDatasets,Node��TINVertex���ݼ��ǵ�ǰm_stgDataset
	//pDatasetParent�����ݼ�,��ͨ���ݼ���NULL,Node��TINVertex���ݼ��ǵ�ǰ���ݼ�
	//5.0����������洢ģʽ��Ŀǰ֧��encNone,encWORD,encDWORD
	UGbool Create(UGString strName, UGDataset::DatasetType nType,UGint nOptions,
				UGFolder *stgDataset,
				UGSdbPlusDatasetVector *pDatasetParent,
				UGDataCodec::CodecType nEncType=UGDataCodec::encNONE);
	

	//stgDataset	��Storage,��ͨ���ݼ���m_stgDatasets,Node��TINVertex���ݼ��ǵ�ǰm_stgDataset
	//bCached		Cache��־
	UGbool OpenEx(UGFolder *stgDataset,UGbool bCached);	//�����ݼ�
	
	UGbool IsValidDataset();	//�ж��Ƿ�Ϸ�Dataset

	//���º����ṩ��Spatial Indexʹ��
	UGbool InitialSpatialIndex();	//��ʼ��Spatial Index
	UGbool SaveSpatialIndex();	//Save Spatial Index to m_stmIndex
	UGbool LoadSpatialIndex();	//Load Spatial Index from m_stmIndex

	void Encrypt(UGString& strPassword);		//���ݼ���
	
	//�޸�����������
	UGbool RepairEx(UGint& nGeometryCount,UGint& nRecordCount);	//���ռ����������������Ƿ�һһ��Ӧ������ɾ��ȱʧ�ռ����ݵ��������ݣ�ȱʧ�������ݵĿռ��������ϡ�
	UGbool Repair();					//�ռ��������������ݲ�һ���ǵ��޸�,�����޸�֮ǰ,���ݼ�����datasetinfo,stgDataset���Ѿ��򿪡�
	UGbool RepairNoProperty();		//���Ա�ʧ����޸���
	
	/*
	//UGString strFileName,	�õ����ı��ļ���·��������
	//UGint &nDatasetN,			//Ҫ��SQL Server���ݼ����õĿռ���Ϣ
	//UGString strTerminate = "--$"		//���Լ���ֽڶεļ����
	UGbool Export2Txt(UGString strFileName,double &dGridSize,		
					UGint &nDatasetW,	UGint &nDatasetN,UGint &nDatasetE,UGint &nDatasetS,
					UGString strTerminate = "--$");	

	UGbool ExportSqlPlusText(UGString strFileName,UGint & nRecordCount,
							UGRect2D &rc2Bounds,	UGString strTerminate = "--$");
	
	UGbool ExportSybaseText(UGString strFileName,UGint & nRecordCount,
						UGRect2D &rc2Bounds,UGString strTerminate = "--$");
	*/

	static UGbool InitVariant(COleVariant& var,short nType);

};

}
#endif // !defined(AFX_SDBDATASET49_H__017098AB_099E_11D3_92D2_0080C8EE62D1__INCLUDED_)
