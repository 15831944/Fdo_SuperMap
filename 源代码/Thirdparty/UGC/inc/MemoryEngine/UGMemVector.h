//=====================================================================================
// ��Ŀ����			SuperMap Foundation Class (SFC) Library 5.0
// ԭ���ߣ�			���ܿ�
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSuperMap GIS����������Ա��δ����ɲ������Դ�����
//					2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����			UGMemVector.h,UGMemVector.cpp
// ��  ����			UGMemVector
// ��  �ࣺ			UGDatasetVector
// ��  �ࣺ			
// ����˵����		�ڴ�ʸ�����ݼ�
// ����˵����		
//=====================================================================================

#if !defined(UGMEMVECTOR_H)
#define UGMEMVECTOR_H

#include "Engine/UGDatasetVector.h"
#include "Geometry/UGGeometry.h"
#include "Base/UGBitArray.h"
#include "Base/UGFileStream.h"

namespace UGC
{
class UGMemDataSource;

class MEMENGINE_API UGMemVector : public UGDatasetVector  
{
	friend class UGMemRecordset;

public:
	enum SQL_OPERATOR
	{
		opEqual = 0,	//! =	Equal
		opLT	= 1,	//! <	Less Than
		opGT	= 2,	//! <	Greater Than
		opLTOE	= 3,	//! >=	Less Than Or Equal
		opGTOE	= 4,	//! <=	Greater Than Or Equal
		opNE	= 5,	//! !=	Not Equal
		opLike	= 6,	//! like	Like
	};
	enum SQL_FILTER_REL
	{
		relAND = 0,
		relOR = 1,
	};

	struct UG_MEM_VECTOR_FIELD
	{
		UGFieldInfo fieldInfo;
		UGArray<UGVariant> aryValues;

		void operator =(const UG_MEM_VECTOR_FIELD &VectorField)
		{
			fieldInfo = VectorField.fieldInfo;
			aryValues.Copy(VectorField.aryValues);
		}
	};

	typedef UGArray<UG_MEM_VECTOR_FIELD> UG_MEM_VECTOR_FIELDS;

	struct UG_MEM_VECTOR_EXPRESSION
	{
		UGString strFieldName;
		SQL_OPERATOR op;
		UGString strValue;
		SQL_FILTER_REL rel;
		UG_MEM_VECTOR_EXPRESSION * pNext;
		UG_MEM_VECTOR_EXPRESSION * pChild;
		UG_MEM_VECTOR_EXPRESSION * pParent;

		UG_MEM_VECTOR_EXPRESSION()
		{
			strFieldName = "";
			op = opEqual;
			rel = relOR;
			strValue = "";
			pNext = NULL;
			pChild = NULL;
			pParent = NULL;
		}
		~UG_MEM_VECTOR_EXPRESSION()
		{
			if(pChild != NULL)
			{
				delete pChild;
				pChild = NULL;
			}
			if(pNext != NULL)
			{
				delete pNext;
				pNext = NULL;
			}
		}
	};

public:
	UGMemVector();
	UGMemVector(UGMemDataSource *pDataSource);
	virtual ~UGMemVector(); 
	
	//! �����ݼ�
	virtual UGbool Open();

	//! �ر����ݼ�
	virtual void Close();

	//! ����������ʱ��
	virtual UGTime GetDateLastUpdated();

	//! ���ش���ʱ��
	virtual UGTime GetDateCreated();

	//! ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName);

	//! �������ݼ���Ϣ
	virtual UGbool SaveInfo();

	//! ˢ�����ݼ���Ϣ
	virtual UGbool RefreshInfo();

	//! ��ѯ���ͼ����һ��ͼ��������
	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
		UGArray<UGString> & arFields,UGdouble dGranule);

	//! ͨ�����η�Χ��ѯͼ�����
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
		UGArray<UGint>& arLibTileIDs);

	//! �õ�һ��ͼ������Ϣ
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
		UGint& nRecCount,UGint& nVersion);

	
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

	//! �����ռ�����
	virtual UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);
	//! ����ռ�����
	virtual UGbool DropSpatialIndex();
	//! �Ƿ���Ҫ�ؽ��ռ�����
	virtual UGbool IsSpatialIndexDirty();
	//! ���ؿռ�������ļ�¼����Ŀ��Ϊ�Ƿ���Ҫ�ؽ��ռ������ṩ�ο�
	virtual UGint GetDirtyRecordCount();

	//! ����ͨ����
	virtual UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName);
	//! ɾ������
	virtual UGbool DropIndex(const UGString& strIndexName);


	//! R����������
	virtual UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
	virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);

	//! �ռ������е��ֶ���
	virtual UGString GetGeoColName() const;

	//! �Ƿ��м������ݣ�����Tablur���ݼ������м�������
	virtual UGbool HasGeometry() const;

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

	//! ͨ��ID����ɾ�����ݼ��еļ�¼
	virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount);

	//! ׷�Ӽ�¼
	virtual UGbool Append(UGRecordset* pSrcRecordset, 
		UGbool bShowProgress = TRUE,UGString strTileName = "");

	//! ׷���������ݼ���¼
	virtual UGbool AppendNetwork(UGRecordset *pNetRecordset,
		UGbool bShowProgress = TRUE);
	//! ���ؼ�¼������
	virtual UGint GetRecordsetCount();

	//! ����ָ�����������ݼ�ָ��
	virtual UGRecordset* GetRecordsetAt(UGint nIndex);

	//! ͨ�������ͷż�¼��
	virtual UGbool ReleaseRecordset(UGint nIndex);

	//! ͨ�������ͷż�¼��
	virtual UGbool ReleaseRecordset(UGRecordset *pRecordset);

	//! �����Ƿ�ÿ���������Լ��ķ��
	virtual void SetFlag(UGint nOption,UGbool bHas);

	//! �ж��ֶ����Ƿ���Ч
	virtual UGbool IsAvailableFieldName(const UGString& strFieldName);

	//! �õ�δ��ռ�õ��ֶ���
	virtual UGString GetUnoccupiedFieldName(const UGString& strFieldName);

	//! �õ�ͼ������ͼ������	
	virtual UGString GetMiniatureDtName();
	
	//! �ҵ�����Ŀռ����
	//virtual UGGeometry* FindClosestGeometry(const UGPoint2D& pntHitTest,
	//	DistanceType nType);	
		
	//! ͨ������ȡ�ֶ���
	virtual UGString GetFieldNameBySign(FieldSign nSign);
	
	//! �����ֶε����
	virtual UGbool SetFieldSign(const UGString& strFieldName,FieldSign nSign);

		//! ����������
	virtual UGbool CheckOut();
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

		//! ʱ�����ݵ�ע��ʱ��
	virtual UGTime GetRegistSequenceTime();

	//! ʱ�����ݵ����¸���ʱ��
	virtual UGTime GetLUSequenceTime();
	
		//! �ز��������������ݼ���Ч
	virtual UGbool Resample(UGdouble dTolerance,
		UGbool bShowProgress=TRUE);

	virtual UGbool CanUpdate();

public:
	//!�������ݼ�
	UGbool Create(UGMemVector *pDatasetParent,const UGDatasetVectorInfo & vInfo);

	UGbool Delete(UGint nID);
	UGint GetID();
	UGbool SeekID(UGint nID);
	UGbool GetFieldValue(UGint nFieldIndex, UGVariant & varValue);
	UGbool GetFieldValue(const UGString & strFieldName, UGVariant & varValue);
	UGbool SetFieldValue(UGint nFieldIndex, const UGVariant &varValue);
	UGbool SetFieldValue(const UGString & strFieldName, const UGVariant & varValue);
	UGbool GetGeometry(UGGeometry *& pGeometry);
	UGbool GetGeometryDirect(UGGeometry *& pGeometry);
	UGbool SetGeometry(UGGeometry &geometry);
	UGint AddNew();

	UGint GetIDsByBounds(const UGRect2D &rc2Bounds, UGArray<UGint> & aryIDs);
	UGint GetIDsByFilter(const UGString & strFilter, UGArray<UGint> & aryIDs);

	UGbool Save2File(UGString strFileName,UGTime tCurrentTime);
	UGbool LoadFromFile(UGString strFileName,UGTime tCurrentTime);
	UGbool SetDatetimeLastUpdate(UGTime dateTime);

private:
	UGbool SaveDatasetInfo(UGFileStream &stream);
	UGbool ReadDatasetInfo(UGFileStream &stream);
	UGbool SaveFieldInfo(UGFileStream &stream,UGFieldInfo &fieldInfo);
	UGbool ReadFieldInfo(UGFileStream &stream,UGFieldInfo &fieldInfo);

protected:
	UGFieldInfos m_fieldInfos;

	/// \brief �����ݼ�ָ��
	/// \remark	����Node��TINVertexͼ��ʹ��,��ͨͼ��ΪNULL
	UGMemVector	*m_pDatasetParent;

	UG_MEM_VECTOR_FIELDS m_structFields;
	UGint m_nIDFieldIndex;
	UGArray<UGGeometry*> m_Geometrys;
	UGBitArray m_aryDelFlag;
	UGint m_nMaxID;

	UGint m_nCurrentIndex;

	UGint m_nRecordCount;

	UGTime m_dateTimeLastUpdate;
};

}

#endif // !defined(UGMEMVECTOR_H)
