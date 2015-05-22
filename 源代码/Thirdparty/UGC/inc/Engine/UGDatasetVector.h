/*! \file	 UGDatasetVector.h
 *  \brief	 ʸ�����ݼ���
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetVector.h,v 1.78 2008/03/25 09:35:38 lisj Exp $
 */

#ifndef UGDATASETVECTOR_H
#define UGDATASETVECTOR_H

#include "Base/ugdefs.h"
#include "UGDataset.h"
#include "Base/UGTime.h"
#include "UGRecordset.h"
#include "Base/UGTextCodec.h"
#include "UGDatasetVectorInfo.h"
#include "Engine/UGSpatialIndexInfo.h"
#include "UGTable.h"

namespace UGC {


class UGDataHistory;
struct UG_DATA_CACHE_FILE_HEADER 
{
	UGint nVersion;
	UGint nRecordCount;
	UGDataCodec::CodecType nCodecType;
	UGint nDatasetID;
	UGint nLibID;
	UGint nOffBits;
	UGRect2D rc2Bounds;
	UGdouble dXGridSize;
	UGdouble dYGridSize;
	UGint nReserved1;
	UGint nReserved2;

	void Save(UGStream& stream)
	{
		stream<<nVersion;
		stream<<nRecordCount;
		stream<<(UGint)nCodecType;
		stream<<(UGint)nDatasetID;
		stream<<nLibID;
		stream<<nOffBits;
		
		stream<<rc2Bounds.left;
		stream<<rc2Bounds.top;
		stream<<rc2Bounds.right;
		stream<<rc2Bounds.bottom;
		
		stream<<dXGridSize;
		stream<<dYGridSize;
		stream<<nReserved1;
		stream<<nReserved2;
	};

	void Load(UGStream& stream)
	{
		stream>>nVersion;
		stream>>nRecordCount;
		UGint nEnc = 0;
		stream>>nEnc;
		nCodecType = (UGDataCodec::CodecType)nEnc;
		stream>>nDatasetID;
		stream>>nLibID;
		stream>>nOffBits;
		
		stream>>rc2Bounds.left;
		stream>>rc2Bounds.top;
		stream>>rc2Bounds.right;
		stream>>rc2Bounds.bottom;
		
		stream>>dXGridSize;
		stream>>dYGridSize;
		stream>>nReserved1;
		stream>>nReserved2;
	};
};

struct UG_INDEX_CACHE_FILE_HEADER 
{
	UGint nReserved1;
	UGint nReserved2;
	UGint nOffBits;

	void Save(UGStream& stream)
	{
		stream<<nReserved1;
		stream<<nReserved2;
		stream<<nOffBits;
	};

	void Load(UGStream& stream)
	{
		stream>>nReserved1;
		stream>>nReserved2;
		stream>>nOffBits;
	};
};	

//��¼��ʷ����ָ����Ƿ�ָ����Ч�Ľṹ
struct ValidDataHistory{
	UGDataHistory* pDataHistory;
	UGbool bValid ;
};

class  ENGINE_API UGSubDtArray : public UGArray<UGDatasetVector *>
{
public:
	UGSubDtArray()
	{
	};

	~UGSubDtArray()
	{
	};
public:
	UGDatasetVector * operator [](UGint nIndex) const;
	UGDatasetVector * operator [](UGString strName) const;
};
//UG_SQ_MAYBEIDS
class ENGINE_API UGMaybeItem
{
public:
	UGMaybeItem()
	{
		pGeometry = NULL;
		aryIDs.RemoveAll();
	};

	~UGMaybeItem()
	{
		if(pGeometry)
		{
		}
		aryIDs.RemoveAll();
	};

public:
	UGGeometry *pGeometry;
	UGArray<UGint> aryIDs;
};

class ENGINE_API UGMaybeItems : public UGArray<UGMaybeItem >
{
public:
	void ReleaseAll()
	{
		for(UGint n=0; n < this->GetSize(); n++)
		{
			delete GetAt(n).pGeometry;
//			GetAt(n).pGeometry = NULL;
		}
	};
};

typedef UGArray<UGint> UG_MayIDs;

class ENGINE_API UGDatasetVector : public UGDataset, public UGTable
{
public:
	//! ����ϵͳ�ֶα�ʶ
	enum FieldSign  
	{
		signNodeID			= 1, //! �������ݼ��Ľڵ�ID��Ĭ����SmNodeID�ֶ�
		signFNode			= 2, //! �������ݼ�����ֶ�, Ĭ����SmFNode
		signTNode			= 3, //! �������ݼ��յ��ֶ�, Ĭ����SmTNode
		signEdgeID			= 4, //! �������ݼ��ߵ�ID�ֶ�
		signRouteID			= 5, //! ·�����ݼ���RouteID�ֶ�			
		signCustom			= 50 //! �û��Զ����ֶα�ʶ��ʼֵ
	};

	

public:
	//! ���캯��
	UGDatasetVector();
	//! ��������
	~UGDatasetVector();

	//! ����UGDataset����Ĵ��麯��
public:
	//! �������ݼ�����
	virtual DatasetType GetType() const
	{
		return m_DatasetInfo.m_nType;
	}

	//! �������ݼ���ά��
	virtual UGint GetDimension();

	//! �������ݼ���(���Ժͱ�����ͬ)
	virtual UGString GetName()
	{
		return m_DatasetInfo.m_strName;
	}
	
	//! �������ݼ���Ӧ����
	virtual UGString GetTableName()
	{
		return m_strTableName;
	}

	//! �������ݼ���Ӧ�����ݱ������
	void SetTableName(const UGString& strTableName)
	{
		m_strTableName = strTableName;
	}
	
	//! ��ȡ���ݼ�������Ϣ
	virtual UGString GetDescription() const;

	//! �������ݼ�������Ϣ
	virtual void SetDescription(const UGString& /*strDesc*/);

	//! ������С�߳�
	virtual UGdouble GetMinZ()
	{
		return m_DatasetInfo.m_dMinZ;
	}
	
	//! ������С�߳�
	virtual void SetMinZ(UGdouble d)
	{
		m_DatasetInfo.m_dMinZ = d;
		SetModifiedFlag();
	}
	
	//! �������߳�
	virtual UGdouble GetMaxZ()
	{
		return m_DatasetInfo.m_dMaxZ;
	}
	
	//! �������߳�
	virtual void SetMaxZ(UGdouble d)
	{
		m_DatasetInfo.m_dMaxZ = d;
		SetModifiedFlag();
	}

	//! �ж��Ƿ���ʸ�����ݼ�
	virtual UGbool IsVector(){return m_DatasetInfo.m_nType != LinkTable;};

	virtual UGbool IsLinkTable(){return m_DatasetInfo.m_nType == LinkTable; };

	//! �ж��Ƿ���topo���ݼ�
	virtual UGbool IsTopoDataset(){return FALSE;};

	//! �ж��Ƿ���դ�����ݼ�
	virtual UGbool IsRaster(){return FALSE;};

	//! �������ݼ��ķ�Χ
	virtual const UGRect2D& GetBounds() const{return m_DatasetInfo.m_rc2Bounds;}
	
	//! �������ݼ��ķ�Χ
	virtual void SetBounds(const UGRect2D& r){
		m_DatasetInfo.m_rc2Bounds = r;SetModifiedFlag();
	}

	//! ���ؿռ����ݱ��뷽ʽ
	virtual UGDataCodec::CodecType GetCodecType(){return (UGDataCodec::CodecType)m_DatasetInfo.m_nCodecType;}
	
	//! ���ÿռ����ݱ��뷽ʽ,�������ݼ���ʱ������,��������ݲ��������޸�
	virtual void SetCodecType(UGDataCodec::CodecType c){
		m_DatasetInfo.m_nCodecType = c;
		SaveInfo();
	}

	//! ֱ�Ӵ��ڴ��з��ض������,�ٶȱȽϿ�,
	//! �����ܱ�֤��ȷ,ͨ��DatsetInfo��ȡ
	virtual UGint GetObjectCountDirectly() {
		return m_DatasetInfo.m_nObjectCount;
	}
	
	//! �������ݼ��ж������,�ٶ���,��ֵ�Ƚ���ȷ,
	//! ͨ��Register���ȡ
	virtual UGint GetObjectCount() {
		return m_DatasetInfo.m_nObjectCount;
	}

	//! �������ݼ��ж������,�ٶ���,��ֵ�Ƚ���ȷ,
	//! ͨ��Register���ȡ
	virtual void SetObjectCount(UGint nCount) {
		m_DatasetInfo.m_nObjectCount = nCount;
	}

	//! �������ݼ���ѡ����Ϣ(�����ֽڵ��������ݴ���һЩ����)
	virtual UGint GetOptions()
	{
		return m_DatasetInfo.m_nOptions;
	}

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
	//! \remarks ��Χ��ȷ�ռ��ѯ,UG_SQ_MAYBEIDS��Geo�������ڲ����ж���ΧUnion֮�����ѯ����Ĳü������
	virtual UGbool SpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption, UGdouble dbTolerance=EP);

	//! \brief ͼ�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
    virtual UGbool LibTileSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, 
		UGdouble dbTolerance);

	//! \brief R�������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	virtual UGbool RTreeSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption,
		UGdouble dbTolerance);

	//! \brief �༶���������ռ��ѯ 
	//! \param pGeo �����[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	//! \brief pGeoΪ��ά����ʱ��aryInnerIDs�Ǳ�pGeo��ȫ�����Ķ���ID��aryMaybeIDs����pGeo�ཻ��ID����ϵ��Ҫ��һ���жϣ�aryOuterIDs��һ����pGe�ⲿ�Ķ���ID
	//! \brief pGeoΪһά����ʱ��aryInnerIDsΪ�գ�aryMaybeIDs����pGeo�ཻ��ID����ϵ��Ҫ��һ���жϣ�aryOuterIDs����pGeoû�н������ID
	//! \brief pGeoΪ��ά����ʱ��aryInnerIDsΪ�գ�aryMaybeIDs�ǵ����ڶ���Χ�ڵĶ���ID��aryOuterIDs�ǵ����ڶ���Χ��Ķ���ID
	virtual UGbool DynamicSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, 
		UGdouble dbTolerance);
public:
	UGDatasetVectorInfo * GetInfo();
	//! �ж����ݼ��Ƿ���ĳ��ѡ����Ϣ
	UGbool HasFlag(UGint nOption);

	//! �������ݼ�������,һ�㲻����ֱ���޸�
	virtual void SetFlag(UGint nOption,UGbool bHas) =0;

	//! �Ƿ��м������ݣ�����Tablur���ݼ������м�������
	virtual UGbool HasGeometry() const =0;

	//! ��ѯͨ�����
	virtual UGRecordset* Query(const UGQueryDef& querydef) =0;

	//! ������Ա��ѯ
	virtual UGRecordset* Query2(UGLinkItem &linkitem);

	//! ��ȡ���ռ������ֽڴ�С
	virtual UGint GetMaxGeoSize() =0;

	//! �������ռ������ֽڴ�С
	virtual UGbool SetMaxGeoSize(UGint nMaxGeoSize) =0;

	//! ׷�Ӽ�¼
	virtual UGbool Append(UGRecordset* pSrcRecordset, 
		UGbool bShowProgress = TRUE,UGString strTileName = "") =0;

	//! ׷�Ӽ�¼,�����ֶ��ж�Ӧ��ϵ,�ռ��ֶβ�����
	virtual UGbool Append(UGRecordset* pSrcRecordset,
		UGArray<UGString> &strSrcFieldNames,
		UGArray<UGString> &strDesFieldNames,
		UGbool bShowProgress = TRUE,
		UGString strTileName = "");

	//! ��ȡ�����ݼ�ָ��
	UGDataset* GetParentDataset() const {
		return m_pParentDataset;
	}

	//! ��ȡ�����ݼ�ָ��
	UGDatasetVector * GetChildDataset() const;

	//! ���ø����ݼ�ָ��
	void SetParentDataset(UGDatasetVector* pDatasetVector)
	{
		m_pParentDataset = pDatasetVector;
	}

	//! ���ؼ�¼������
	virtual UGint GetRecordsetCount() =0;

	//! ����ָ�����������ݼ�ָ��
	virtual UGRecordset* GetRecordsetAt(UGint nIndex) =0;

	//! ͨ�������ͷż�¼��
	virtual UGbool ReleaseRecordset(UGint nIndex) =0;

	//! ͨ�������ͷż�¼��
	virtual UGbool ReleaseRecordset(UGRecordset *pRecordset) =0;

	//! �ͷ����м�¼��
	void ReleaseAllRecordsets();

	//! �õ����ݼ��пռ�������BOUNDS
	UGRect2D GetIndexBounds() const {
		return m_DatasetInfo.m_rc2IndexedBounds;
	}

	//! �������ݼ���������BOUNDS
	void SetIndexBounds(const UGRect2D& rc2Bounds)
	{
		m_DatasetInfo.m_rc2IndexedBounds = rc2Bounds;
		SetModifiedFlag();
	}

	//! �ж��ֶ����Ƿ���Ч
	virtual UGbool IsAvailableFieldName(const UGString& strFieldName) =0;

	//! �õ�δ��ռ�õ��ֶ���
	virtual UGString GetUnoccupiedFieldName(const UGString& strFieldName);

	//! �õ�ͼ������ͼ������	
	virtual UGString GetMiniatureDtName() =0;
	
	//! ͨ������ȡ�ֶ���
	virtual UGString GetFieldNameBySign(FieldSign nSign) =0;
	
	//! �����ֶε����
	virtual UGbool SetFieldSign(const UGString& strFieldName,FieldSign nSign) =0;


	virtual UGString GetDVATabName();
	virtual UGString GetDVAIndexTabName();
	
	virtual UGString GetDVDTabName();
	
	virtual UGString GetDVCTabName();

	//! �������ݼ��ַ����뷽ʽ
	UGTextCodec::Charset GetCharset() const {
		return m_nCharset;
	}
	
	//! �������ݼ��ַ����뷽ʽ
	virtual void SetCharset(UGTextCodec::Charset c) {
		m_nCharset = c;
		SetModifiedFlag();
	}
	
	UGbool PJConvert( UGRefTranslator *pRefTranslator );		//ͶӰת��
	UGbool PJForward( UGPrjCoordSys *pPrjCoordSys );			//�������굽ͶӰ����,�ٶ�Datum��ͬ.
	UGbool PJInverse( UGPrjCoordSys *pPrjCoordSys );			//ͶӰ���굽��������,�ٶ�Datum��ͬ.


	//*****************����ά������******************
	//! ������SQL��ѯ��¼����,����Register��
	virtual UGbool ComputeRecCount() =0;
	//*****************����ά������******************

	//! ͨ��ID����ɾ�����ݼ��еļ�¼
	virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount) =0;

	//*****************�汾����ķ���******************
	virtual UGbool RollBackVersion(UGint nVersion);

	virtual UGbool PostToMainVersion(UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);	

	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);
	//*****************�汾����ķ���******************

	virtual UGbool ExtractLeafData(const UGRectUInt& SearchBounds,
					const UGRectUInt& rcReferenceBounds,
					UGArray<UGint>& aryItemIDs,
					UGArray<UGint>& aryCertainLeafIDs,
					UGArray<UGRectUInt> &aryCertainBounds,
					UGArray<UGint>& aryMaybeLeafIDs,
					UGArray<UGRectUInt> &aryMaybeBounds,
					UGbool bFuzzy,
					UGdouble dGranule);

	//! ��ȡ�����ļ�����ʱ·��
	UGString GetCacheTempPath() const {return m_strCacheTempPath;}

	//! ���û����ļ�����ʱ·��
	void SetCacheTempPath(const UGString& strTempPath){ m_strCacheTempPath = strTempPath;}

	//! ����������
	virtual UGbool CheckOut() =0;
	virtual UGbool CheckIn(UGbool bKeepCheckedOut) =0;
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut) =0;

	//! ���������������
	virtual UGString GetIndexTableName()
	{
		return m_strIndexTable;
	}

	//! ���������������
	void SetIndexTableName(const UGString& strIndexTable)
	{
		m_strIndexTable = strIndexTable;
	}
		
	//*************ʱ�ղ���************
	//! ʱ�����ݵ�ע��ʱ��
	virtual UGTime GetRegistSequenceTime() =0;

	//! ʱ�����ݵ����¸���ʱ��
	virtual UGTime GetLUSequenceTime() =0;
	//*************ʱ�ղ���************

	//! R����������
	virtual UGint LoadRTreeLeaf(UGint nID,UGStream &stream) =0;
	virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream) =0;
	virtual UGbool StoreRTreeTrunk(UGStream &stream);
	

	
	//! �����Ƿ��(0.0) 
	UGbool IsToleranceEmpty() const {
		return UGIS0(m_DatasetInfo.m_dToleranceDangle) &&
			UGIS0(m_DatasetInfo.m_dToleranceExtend) &&
			UGIS0(m_DatasetInfo.m_dToleranceGrain) &&
			UGIS0(m_DatasetInfo.m_dToleranceNodeSnap) &&
			UGIS0(m_DatasetInfo.m_dToleranceSmallPolygon);
	}

	//! ʹ��Ĭ������
	virtual void SetToleranceToDefault();

	//! ��������Ϊ��
	void EmptyTolerance() {
		m_DatasetInfo.m_dToleranceDangle = 0;
		m_DatasetInfo.m_dToleranceExtend = 0;
		m_DatasetInfo.m_dToleranceGrain = 0;
		m_DatasetInfo.m_dToleranceNodeSnap = 0;
		m_DatasetInfo.m_dToleranceSmallPolygon = 0;
		SetModifiedFlag();
	}

	//! ������С���������ķ�Χ
	void SetToleranceSmallPolygon(UGdouble dNewValue) {
		m_DatasetInfo.m_dToleranceSmallPolygon = dNewValue;
		SetModifiedFlag();
	}

	//! �õ���С���������ķ�Χ
	UGdouble GetToleranceSmallPolygon() const {
		return m_DatasetInfo.m_dToleranceSmallPolygon;
	}

	//! ���ö���������
	void SetToleranceDangle(UGdouble dNewValue) {
		m_DatasetInfo.m_dToleranceDangle = dNewValue;
		SetModifiedFlag();
	}

	//! �õ�����������
	UGdouble GetToleranceDangle() const {
		return m_DatasetInfo.m_dToleranceDangle;
	}

	//! ���ýڵ�����
	void SetToleranceNodeSnap(UGdouble dNewValue) {
		m_DatasetInfo.m_dToleranceNodeSnap = dNewValue;
		SetModifiedFlag();
	}

	//! �õ��ڵ�����
	UGdouble GetToleranceNodeSnap() const {
		return m_DatasetInfo.m_dToleranceNodeSnap;
	}

	//! ������������
	void SetToleranceGrain(UGdouble dNewValue) {
		m_DatasetInfo.m_dToleranceGrain = dNewValue;
		SetModifiedFlag();
	}

	//! �õ���������
	UGdouble GetToleranceGrain() const {
		return m_DatasetInfo.m_dToleranceGrain;
	}

	//! ���úϲ��ٽڵ�����
	void SetToleranceExtend(UGdouble dNewValue) {
		m_DatasetInfo.m_dToleranceExtend = dNewValue;
		SetModifiedFlag();
	}

	//! �õ��ϲ��ٽڵ�����
	UGdouble GetToleranceExtend() const {
		return m_DatasetInfo.m_dToleranceExtend;
	}
	
	//! �������ݼ���ѡ����Ϣ
	void SetOptions(UGint nOptions)
	{
		m_DatasetInfo.m_nOptions = nOptions;
		SetModifiedFlag();
	}

	//added by xielin 2007-05-23 
	void RegisterToDataset(UGDataHistory* pDataHistory);
	void UnRegisterFromDataset(UGDataHistory* pDataHistory);

	//! ���������topo ���Ի��topo���ݼ�ָ��
	virtual UGDataset * GetTopoAdscriptionDT();

	//! For Tin ���ݼ�
	virtual UGbool CreateSubDataset(UGDatasetVectorInfo & vInfo);
	virtual UGbool DeleteSubDataset(UGString &strName);

	//!ͨ����ʵ��ȣ����豸��ȣ���������ʾTin����������һ������
	UGDatasetVector * GetTinLayer(UGint nWidth,UGint nDeviceWidth);
protected:
	//! �����ռ�����
	//! �˷���ֻ�����������Ĳ���������R������,ͼ�������������ĺ���,�����IDXNone
	//! ��ôĬ���ؽ��Ĳ���������R������
	virtual UGbool BuildSpatialIndex(UGSpatialIndexInfo  &spatial)=0;
	
	//! \brief ���ݵ�ǰ����״̬�ؽ�����
	//! \param *pDataset [in]��
	//! \return
	//! \remarks
	//! \attention 
	virtual UGbool ReBuildSpatialIndex() = 0;

	//! \brief �����ݵĿռ���������
	//! \param *pDataset [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGbool UpdateSpatialIndex() = 0;

	//! ����ռ�����,Ϊû��������״̬
	virtual UGbool DropSpatialIndex() = 0;
	
	//! \brief ��ѯ���ͼ����һ��ͼ��������
	//! \param nLibTileID [in]��
	//! \param arFields [in]��
	//! \param dGranule [in]��
	//! \return UGRecordset
	//! \remarks ���dGraunle<=0����ô�Ͳ����ù��˷�ʽ,��֮����
	//! \attention ��
	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
		UGArray<UGString> & arFields,UGdouble dGranule) =0;

	//! \brief ͨ�����η�Χ��ѯͼ�����
	//! \param rc2Bounds [in]��
	//! \param arLibTileIDs [out]��
	//! \return UGbool
	//! \remarks ��
	//! \attention ��
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
		UGArray<UGint>& arLibTileIDs) =0;
	
// 	virtual UGbool GetLibTileIDs(const UGGeoRegion *pGeo,
// 		UGArray<UGint>& aryInnerLibTileIDs,UGArray<UGint>& aryMaybeLibTileIDs);

	//! \brief �õ�һ��ͼ������Ϣ
	//! \param nTileID [in]��
	//! \param rc2TileBounds [out]��
	//! \param nRecCount [out]��
	//! \param nVersion [out]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
		UGint& nRecCount,UGint& nVersion) =0;	

	//! �Ƿ���Ҫ�ؽ��ռ�����
	//! �涨:���û����������FALSE,�����������������
	virtual UGbool IsSpatialIndexDirty() =0;
	//! ���ؿռ�������ļ�¼����Ŀ��Ϊ�Ƿ���Ҫ�ؽ��ռ������ṩ�ο�
	//! ���û�������������ݶ�����,��������ʵ�����Ϊ׼
	virtual UGint GetDirtyRecordCount() =0;

	//! �����ݵ���������ͳ�Ʒ���
	virtual UGbool StatisticIndex(UGDataSource *pDs);

	//! \brief ��������ķ�Χ
	//! \param aryGrid		����[in]
	//! \param aryGridRect	����ķ�Χ[out]
	virtual UGbool GetGridBounds(UGint& nLevel,UGArray<UGPoint>& aryGrid,UGArray<UGRect2D>& aryGridRect);

	//! \brief	maybe��������(���Ȱ���X+1�ķ���)
	//! \param aryGridMaybe			����maybe������[in]
	//! \param aryGridMaybeTemp		������maybe����(˳ʱ�룬��ʱ�뷽���˳���п���)[out]
	virtual UGbool GridMaybeSort(UGArray<UGPoint> &aryGridMaybe,UGArray<UGPoint> &aryGridMaybeTemp);

public:
	//! һ�λ�ȡ�ļ�¼��
	UGint m_nOnceFetchCount;
	//! �Ż�����¼���Ż�����
	UGint m_nOptimizeCount;
	//! �Ż�������Ż�����
	UGdouble m_dOptimizeRatio;
	//! ���ռ������ֽڴ�С
	UGint m_nMaxGeometrySize;
	//! �����ŵ��ֽڴ�С
	UGint m_nMaxSymbolSize;
	//! ���ݼ��������ݼ�ָ��
	UGSubDtArray m_ArySubDataset;
	//! ʸ�����ݼ���Ϣ
	UGDatasetVectorInfo m_DatasetInfo;
	//! TIN���ݼ������ݼ�ָ��

	//! ���ݼ�������ѯ���ⲿ����Դ
	UGArray<UGDataSource *> m_aryLinkDatasource;
	
protected:
	//! ��¼��ָ��ļ��ϣ��򿪵����м�¼������������
	//! ����֪����ô�ͷ�
	UGRecordsets m_Recordsets;
	//! �����ļ�����ʱ·��
	UGString m_strCacheTempPath;

	UGTextCodec::Charset m_nCharset;

	//! �����ݼ���ָ��
	UGDataset * m_pParentDataset;

	//! ���ݿ��б������
	UGString m_strTableName;
	//! �����������
	UGString m_strIndexTable;

	//added by xielin 2007-05-22
	UGArray<ValidDataHistory> m_aryValidDataHistory;

	friend class UGSpatialIndex;
};

}

#endif
