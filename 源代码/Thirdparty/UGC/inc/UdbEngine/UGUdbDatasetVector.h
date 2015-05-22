/*! \file	 UGUdbDatasetVector.h
*  \brief	 Oracle Plus DatasetVector
*  \author	 ugc team
*  \attention 
*  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*/


#ifndef UGUdbDatasetVector_H
#define UGUdbDatasetVector_H

#include "Base/ugdefs.h"	// Added by ClassView
#include "Engine/UGDatasetVector.h"
#include "Engine/UGDBRTree.h"
#include "Base/UGProgress.h"
#include "Base/UGFileStream.h"

namespace UGC{
	
	class UDBENGINE_API UGUdbDatasetVector  :public UGDatasetVector
	{
		friend class UGUdbRecordset;
		friend class UGUdbEditRecordset;
		friend class UGUdbSpatialIndex;
	public:
		UGUdbDatasetVector();
		
		UGUdbDatasetVector(UGDataSource *pDataSource);
		
		virtual ~UGUdbDatasetVector();
		
		//!�����ж���Ĵ��麯��
		
		//! \brief �����ݼ���
		//! \return �򿪳ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool Open();
		
		//! \brief �ر����ݼ���
		//! \remarks ��
		//! \attention ��
		virtual void Close();
		
		//! \brief �������ݼ���Ϣ��
		//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool SaveInfo();
		
		//! \brief ˢ�����ݼ���Ϣ��
		//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool RefreshInfo();
		
		//! \brief �������ݼ��ķ�Χ��
		//! \param r ���ݼ��ķ�Χ[in]��
		//! \remarks ��
		//! \attention ��
		virtual void SetBounds(const UGRect2D& r);
		
		//! \brief �������ݼ���
		//! \param strName ���ݼ���[in]��
		//! \param *pDatasetParent ���ݼ���������Դ��ָ��[in]��
		//! \param vInfo ʧ�����ݼ�����[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		UGbool Create(const UGString & strName, 
			UGUdbDatasetVector *pDatasetParent,
			const UGDatasetVectorInfo & vInfo);

		//! \brief ��WFS��GetFeature XML�ļ��������ݼ���
		//! \param strXMLPath GetFeature XML�ļ���ַ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
	 	UGbool Create(UGString strXMLPath);
		
		//! \brief �õ�������ʱ�䡣
		//! \return ������ʱ�䡣
		//! \remarks ��
		//! \attention ��
		virtual UGTime GetDateLastUpdated();
		
		//! \brief �õ�����ʱ�䡣
		//! \return ����ʱ�䡣
		//! \remarks ��
		//! \attention ��
		virtual UGTime GetDateCreated();
		
		
		//! \brief ���ݼ���������
		//! \param strNewName [in]��
		//! \return �������ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ֻ�ı����ݼ���,�������䡣
		//! \attention ��
		virtual UGbool Rename(const UGString& strNewName);		
		
		//! \brief ��ѯ���ͼ����һ��ͼ��������
		//! \param nLibTileID ͼ����[in]��
		//! \param arFields �ֶ�������[in]��
		//! \return ��¼��ָ�롣
		//! \remarks ��
		//! \attention ��
		virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
			UGArray<UGString> & arFields,UGdouble dGranule);
		
		//! \brief ��
		//! \param rc2SearchBounds [in]��
		//! \param strLibTile [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		UGbool GetLibTileSQL(const UGRect2D& rc2SearchBounds,
			UGString& strLibTile);
		
		//! \brief ͨ�����η�Χ��ѯͼ����š�
		//! \param rc2Bounds ���ݼ��ķ�Χ[in]��
		//! \param arLibTileIDs [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
			UGArray<UGint>& arLibTileIDs);
		
		//! \brief �õ�һ��ͼ������Ϣ��
		//! \param nTileID ͼ����[in]��
		//! \param rc2TileBounds ���ݼ��ķ�Χ[in]��
		//! \param nRecCount [in]��
		//! \param nVersion [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
			UGint& nRecCount,UGint& nVersion);
		
		
		//! \brief ����������,ǩ����
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CheckOut();
		
		//! \brief ����������,ǩ�롣
		//! \param bKeepCheckedOut [in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CheckIn(UGbool bKeepCheckedOut);
		
		//! \brief ����������,����ǩ����
		//! \param bKeepCheckedOut [in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);
		
		//! \brief �õ��������û���ID��
		//! \return �������û���ID��
		//! \remarks ��
		//! \attention ��
		UGint GetLockedUserID();
		
		//! \brief �õ�ǩ���û���ID��
		//! \return ǩ���û���ID��
		//! \remarks ��
		//! \attention ��
		UGint GetCheckedUserID();
		
		
		//! \brief ͨ����ֵ���������ֶ�ֵ��
		//! \param strFieldName Ҫ���µ��ֶ�����
		//! \param varValue Ҫ���µ��ֶ�ֵ��
		//! \param strFilter ��������Where Info ����"Where �ؼ���"��
		//! \return ���³ɹ�����TRUE,ʧ�ܷ���FALSE ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool UpdateField(const UGString& strFieldName,
			const UGVariant& varValue,const UGString& strFilter = "");
		
		//! \brief ͨ�����ʽ�����ֶ�ֵ��
		//! \param strFieldName ׼�����µ��ֶ�����
		//! \param strExpress ׼�����µ��ֶ�ֵ��
		//! \param strFilter  ��������Where Info ����"Where �ؼ���",Ĭ��Ϊ�ա�
		//! \return ���³ɹ�����TRUE,ʧ�ܷ���FALSE ��
		//! \remarks ��
		//! \attention ��
		virtual UGbool UpdateFieldEx(const UGString& strFieldName,
			const UGString& strExpress,const UGString& strFilter = "");
		
		
		//! \brief �����ֶ�ֵ��
		//! \param strSrcField Դ�ֶ���[in]��
		//! \param strDestField Ŀ���ֶ���[in]��
		//! \return ���Ƴɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CopyField(const UGString& strSrcField,
			const UGString& strDestField);
		
		
		//! \brief ����ͨ������
		//! \param strFieldNameList �����ֶ��б�,���ֶ���Ҫ�� "," ����,���� fld1,fld2,fld3[in]��
		//! \param strIndexName ������[in]��
		//! \return ���������ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CreateIndex(const UGString& strFieldNameList,
			const UGString& strIndexName);
		
		//! \brief ɾ������ ��
		//! \param strIndexName ������[in]��
		//! \return ɾ�������ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool DropIndex(const UGString& strIndexName);
		
		//! \brief R����������,����Ҷ�ڵ㡣
		//! \param nID Ҷ�ڵ�ID[in]��
		//! \param &stream Ҷ�ڵ����ݰ�[in]��
		//! \return ���Ĵ�С��
		//! \remarks ��
		//! \attention ��
		virtual UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
		
		//! \brief R����������,�洢Ҷ�ڵ㡣
		//! \param nID Ҷ�ڵ�ID[in]��
		//! \param &stream Ҷ�ڵ����ݰ�[in]��
		//! \return �洢�ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);
				

		//! \brief ��
		//! \param SearchBounds [in]��
		//! \param aryItemIDs [in]��
		//! \param aryCertainLeafIDs [in]��
		//! \param &aryCertainBounds [in]��
		//! \param aryMaybeLeafIDs [in]��
		//! \param &aryMaybeBounds [in]��
		//! \param bFuzzy [in]��
		//! \param dGranule [in]��
		//! \return ��
		//! \remarks ��
		//! \attention ��
			virtual UGbool ExtractLeafData(const UGRectUInt& SearchBounds, 
			UGArray<UGint>& aryItemIDs, 
			UGArray<UGint>& aryCertainLeafIDs,
			UGArray<UGRectUInt> &aryCertainBounds,
			UGArray<UGint>& aryMaybeLeafIDs,
			UGArray<UGRectUInt> &aryMaybeBounds,
			UGbool bFuzzy,
			UGdouble dGranule);
		
		//! \brief �õ��ռ������е��ֶ�����
		//! \return �ռ������е��ֶ�����
		//! \remarks ��
		//! \attention ��
		virtual UGString GetGeoColName() const;
		
		//! \brief �Ƿ��м������ݡ�
		//! \return �м������ݷ���TRUE,û�з���FALSE��
		//! \remarks ����Tablur���ݼ������м������ݡ�
		//! \attention ��
		virtual UGbool HasGeometry() const;
		
		//! \brief ��ѯͨ����ڡ�
		//! \param querydef ��ѯ�������[in]��
		//! \return UGRecordset ��¼��ָ�롣
		//! \remarks ��
		//! \attention ��
		virtual UGRecordset* Query(const UGQueryDef& querydef);
		
		//! \brief ��������ֶΡ�
		//! \param fieldInfos �ֶ���Ϣ����[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CreateFields(const UGFieldInfos& fieldInfos);
		
		//! \brief ͨ��FieldInfo�����ֶΡ�
		//! \param fieldInfo �ֶ���Ϣ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CreateField(const UGFieldInfo& fieldInfo);
		
		//! \brief �����ֶΡ�
		//! \param strName �ֶ�����[in]��
		//! \param nType �ֶ�����[in]��
		//! \param nSize �ֶγ���(�ֽ�)[in]��
		//! \param nAttributes �ֶ�����[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool CreateField(const UGString& strName,UGFieldInfo::FieldType nType,
			UGint nSize,UGint nAttributes = 0);
		
		//! \brief ͨ���ֶ�����ɾ���ֶΡ�
		//! \param strName �ֶ�����[in]��
		//! \return ɾ���ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool DeleteField(const UGString& strName);
		
		//! \brief ͨ��������ɾ���ֶΡ�
		//! \param nIndex ������[in]��
		//! \return ɾ���ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool DeleteField(UGint nIndex);
		
		//! \brief �ռ������ֶε���Ϣ��
		//! \param fieldInfos �ֶ���Ϣ����[in]��
		//! \param bSystemFieldExcluded �Ƿ��ϵͳ�ֶ��ų�����[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos,
			UGbool bSystemFieldExcluded = FALSE);
		
		//! \brief ͨ���ֶ�����ȡ�ֶ���Ϣ��
		//! \param strName �ֶ�����[in]��
		//! \param fieldInfo �ֶ���Ϣ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetFieldInfo(const UGString& strName,
			UGFieldInfo& fieldInfo);
		
		//! \brief ͨ��������ȡ�ֶ���Ϣ��
		//! \param nIndex ������[in]��
		//! \param fieldInfo �ֶ���Ϣ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool GetFieldInfo(UGint nIndex,
			UGFieldInfo& fieldInfo);
		
		//! \brief ͨ���ֶ��������ֶ���Ϣ��
		//! \param strName �ֶ���[in]��
		//! \param fieldInfo �ֶ���Ϣ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool SetFieldInfo(const UGString& strName,
			const UGFieldInfo& fieldInfo);
		
		//! \brief ͨ�����������ֶ���Ϣ��
		//! \param nIndex ������[in]��
		//! \param fieldInfo �ֶ���Ϣ[in]��
		//! \return �����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool SetFieldInfo(UGint nIndex,
			const UGFieldInfo& fieldInfo);
		
		//! \brief ��ȡ�ֶθ�����
		//! \return �ֶθ�����
		//! \remarks ��
		//! \attention ��
		virtual UGint GetFieldCount();
		
		//! \brief ɾ�������������ݡ�
		//! \return ɾ���ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool Truncate();
		
		//! \brief ͳ���ֶ�ֵ��
		//! \param strField Ҫͳ�Ƶ��ֶ�[in]��
		//! \param nMode ͳ�Ʒ�ʽ[in]��
		//! \return ͳ�ƽ��,��UGStatisticModeͳ�Ʒ�ʽ����0��
		//! \remarks ��UGStatisticModeͳ�Ʒ�ʽ����0��
		//! \attention ��
		virtual UGVariant Statistic(const UGString& strField,
			UGStatisticMode nMode);
		
		//! \brief �����ֶε�ֵ������
		//! \param &strFieldName �ֶ���[in]��
		//! \param varKeys ��ͬ��ֵ�ļ���[out]��
		//! \return �����ɹ�����0,ʧ�ܷ��ظ�����
		//! \remarks ��
		//! \attention ��
		virtual UGint CalculateUniqueValues(const UGString &strFieldName,
			UGArray<UGVariant>& varKeys);
		
		//! \brief ������SQL��ѯ��¼����,����Register��
		//! \return �ɹ�����Register����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool ComputeRecCount();
		
		//! \brief ��ȡ���ռ������ֽڴ�С��
		//! \return ���ռ������ֽڴ�С��
		//! \remarks ��
		//! \attention ��
		virtual UGint GetMaxGeoSize();
		
		//! \brief �������ռ������ֽڴ�С��
		//! \param nMaxGeoSize ���ռ������ֽڴ�С[in]��
		//! \return ���óɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool SetMaxGeoSize(UGint nMaxGeoSize);
		
		//! \brief �õ�ʱ�����ݵ�ע��ʱ�䡣
		//! \return ʱ�����ݵ�ע��ʱ�䡣
		//! \remarks ��
		//! \attention ��
		virtual UGTime GetRegistSequenceTime();
		
		//! \brief �õ�ʱ�����ݵ����¸���ʱ�䡣
		//! \return ʱ�����ݵ����¸���ʱ�䡣
		//! \remarks ��
		//! \attention ��
		virtual UGTime GetLUSequenceTime();
		
		//! \brief ͨ��ID����ɾ�����ݼ��еļ�¼��
		//! \param pIDs ID����ָ��[in]��
		//! \param nCount Ҫɾ���ļ�¼��������ID����ĸ������[in]��
		//! \return ɾ���ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount);
		
		//! \brief ׷�Ӽ�¼��
		//! \param pSrcRecordset Դ���ݼ�[in]��
		//! \param bShowProgress  �Ƿ���ʾ��������Ĭ����ʾ[in]��
		//! \param strTileName ͼ������,Ĭ��Ϊ��[in]��
		//! \return ׷�Ӽ�¼�ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool Append(UGRecordset* pSrcRecordset,UGbool bShowProgress = TRUE,UGString strTileName = "");
		

		//! \brief �ز��������������ݼ���Ч��
		//! \param dTolerance [in]��
		//! \param bShowProgress �Ƿ���ʾ��������Ĭ����ʾ[in]��
		//! \return �ز����ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool Resample(UGdouble dTolerance,
			UGbool bShowProgress=TRUE);	
		
		//! \brief �õ���¼��������
		//! \return ��¼��������
		//! \remarks ��
		//! \attention ��
		virtual UGint GetRecordsetCount();
		
		//! \brief ����ָ�����������ݼ�ָ�롣
		//! \param nIndex ������[in]��
		//! \return ���ݼ�ָ�롣
		//! \remarks ��
		//! \attention ��
		virtual UGRecordset* GetRecordsetAt(UGint nIndex);
		
		//! \brief ͨ�������ͷż�¼����
		//! \param nIndex ������[in]��
		//! \return �ͷųɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool ReleaseRecordset(UGint nIndex);
		
		//! \brief ͨ�������ͷż�¼����
		//! \param pRecordset ���ݼ�ָ��in]��
		//! \return �ͷųɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool ReleaseRecordset(UGRecordset *pRecordset);
		
		//! \brief �����Ƿ�ÿ���������Լ��ķ��
		//! \param nOption [in]��
		//! \param bHas �Ƿ�ÿ���Լ��ķ��[in]��
		//! \remarks ��
		//! \attention ��
		virtual void SetFlag(UGint nOption,UGbool bHas);
		
		//! \brief �ж��ֶ����Ƿ���Ч��
		//! \param strFieldName [in]��
		//! \return ��Ч����TRUE,��Ч����FALSE��
		//! \remarks ��
		//! \attention ��
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

protected:
		//! \brief �����ռ�����
		//! \param nType �ռ��������ͣ�Ĭ��û��IdxNone [in]��
		//! \param bShowProgressCtrl �Ƿ���ʾ������,Ĭ����ʾ[in]��
		//! \return ���������ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks
		//! \attention ��
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

		//! \brief ����ռ�������
		//! \return ��������ɹ�����TRUE,ʧ�ܷ���FALSE��
		//! \remarks ��
		//! \attention ��
		virtual UGbool DropSpatialIndex();
		
		//! \brief �Ƿ���Ҫ�ؽ��ռ�������
		//! \return ��Ҫ�ؽ�����TRUE,����Ҫ����FALSE��
		//! \remarks ���ݿռ�������ļ�¼����Ŀ�жϡ�
		//! \attention ��
		virtual UGbool IsSpatialIndexDirty();

		//! \brief �����ݵĿռ���������ͳ�Ʒ�����
		//! \param pDs ����Դָ��[in]��
		//! \return �Ƿ�ɹ�ͳ��,�ɹ����ع�TRUE,���򷵻�FALSE��
		virtual UGbool StatisticIndex(UGDataSource *pDs);

		//! \brief ���ؿռ�������ļ�¼����Ŀ��Ϊ�Ƿ���Ҫ�ؽ��ռ������ṩ�ο���
		//! \return �ռ�������ļ�¼����Ŀ��
		//! \remarks ��
		//! \attention ��
		virtual UGint GetDirtyRecordCount();

public:
	/// \brief �����ݿ��ж�ȡ��ǰ���ݼ���Bounds��Ϣ
	/// \remarks �˺�����CDatasetVector::GetBounds�������𣬴˺����Ǵ����ݿ��ж�ȡ���õ��������µ�Bounds����������ֱ�Ӵ��ڴ��ж�ȡm_DatasetInfo�д洢��Bounds��Ϣ���ٶ�Ҫ��ö�
	/// \sa	CDatasetVector::GetBounds
	UGRect2D GetBoundsDirectly();
	
	UGbool RegisterUser(UGint nLogID,UGbool bRecordsetLevel = FALSE);
	
	void CheckError() const;
	
	UGbool CanTransact();
		
	UGbool GetCacheFile(UGString &strFileName,UGint nLibTileID);
	
	UGbool QueryFieldInfos();
	
	UGString CheckFieldName(UGString strFieldName);

private:
	/// \brief ˢ�µ�ǰ���ݼ���ѡ����Ϣ
	/// \sa RegisterOption, UnRegisterOption, CSmDataset::GetOptions
	UGbool RefreshOption();
	
	
	
public:
	UGFieldInfos m_fieldInfos;
	UGDBRTree * m_pRTreeIndex;

private:
	UGint m_nMyOption;
	UGint m_nState;
	UGFileStream m_IndexFile;

	UGMutex m_mutex;
	UGMutex m_nOpenmutex;
};

}
#endif // !defined(UGUdbDatasetVector_H)
