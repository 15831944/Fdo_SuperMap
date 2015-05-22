// UGOrcCacheRecordset.h: interface for the UGOrcCacheRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCCACHERECORDSET_H__60D395E7_A724_492F_A4F8_721C3485CD29__INCLUDED_)
#define AFX_UGORCCACHERECORDSET_H__60D395E7_A724_492F_A4F8_721C3485CD29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UGOrcRecordset.h"
#include "Base/UGArray.h"
#include "Base/UGVariant.h"
#include "Base/UGFileStream.h"
#include "Algorithm/UGRect.h"

namespace UGC {

//ColumnValues�洢һ�е�����
class UGColumnValues
{
public:
	UGString strFieldName;
	UGArray<UGVariant> varValues;
	void operator =(UGColumnValues colValues)
	{
		strFieldName = colValues.strFieldName;
		varValues.SetSize(colValues.varValues.GetSize());
		for(UGint i=0;i<colValues.varValues.GetSize();i++)
		{
			varValues[i] = colValues.varValues[i];
		}
	};
};

typedef UGArray<UGColumnValues> DtAttrValues;

class UGOrcCacheRecordset : public UGOrcRecordset  
{
public:
	UGOrcCacheRecordset();
	UGOrcCacheRecordset(UGOrcDatasetVector * pDataset);
	virtual ~UGOrcCacheRecordset();

private:
	//��������������������ڽ��������ݼ��ص��ڴ��У�����ٶ�
	UGbool LoadColAttrValues(const UGString &strColName);
	void ReleaseColAttrValues(const UGString &strColName);
	void ReleaseAllAttrValues();

	UGbool RefreshCurrentIdxItem();
	UGbool FetchData(const UGString &strSQL);
	ub2 GetOCIType(UGint nDAOType);

public:
	virtual UGbool GetWordRectBounds(UGRect & rcWdRectBounds);
	
	UGbool Open(UGArray<UGString>& aryField);
	
public:
	//! ��ĳ��ͳ�Ʒ���ͳ��ĳ���ֶ�
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);

	//! ��ȡ��ǰ��¼��ID
	virtual UGint GetID();
	
	//! �жϵ�ǰ��¼ָ���Ƿ�ָ��ͷ
	virtual UGbool IsBOF();
	
	//! �жϵ�ǰ��¼ָ���Ƿ�ָ��β
	virtual UGbool IsEOF();
	
	//! �رռ�¼��
	virtual void Close();

//	virtual UGbool IsEmpty() ;	//�Ƿ��¼��Ϊ��(û�м�¼)
	
	//! ȡ�ü��ζ��󣬷��صļ��ζ���ָ���ں����ڷ����ڴ棬
	//! ���渺��ɾ������������ڴ�й©
	virtual UGbool GetGeometry(UGGeometry*& pGeometry);
	
	//! ͨ���ֶ�����ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(const UGString& strName,
		UGVariant& varVal);
	
	//! ͨ��������Ż�ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(UGint nIndex,
		UGVariant& varVal);

//	virtual BOOL GetGeometryBounds(CRect2D &rc2Bounds,double& dMinZ,double& dMaxZ);	//ȡ�ü��ζ������άBounds
	
	//! ������Ӧ����,��ǰ������ƶ���¼ָ��
	virtual UGbool Move(UGint nRows);
	
	//! �ƶ���¼ָ�뵽��ǰ
	virtual UGbool MoveFirst();
	
	//! �ƶ���¼ָ�뵽���
	virtual UGbool MoveLast();
	
	//! �����ƶ�һλ��¼ָ��
	virtual UGbool MoveNext();
	
	//! �����ƶ�һλ��¼ָ��
	virtual UGbool MovePrev();
	
	//! �ƶ���¼ָ�뵽ָ��λ��
	virtual UGbool MoveTo(UGint nRow);
	
	//! ͨ��ID��λ��¼ָ��
	virtual UGbool SeekID(UGint nID);

	//���� 
	UGString GetFilter() const {return m_strFilter;}

	//! ��ȡ��¼����
	virtual UGint GetRecordCount();

	//! ˢ�¼�¼
	virtual void FlushCurrentRecord();

	//! �����¼���ķ�Χ
	virtual UGbool ComputeBounds(UGRect2D &rc2Bounds,
		UGdouble &dMinZ,UGdouble &dMaxZ);

private:
	DtAttrValues m_attrValues;
	UGRect2D m_rc2Bounds;
	UGint m_nCurrentPos;
	
	UGOCIBind m_OCIBind;
	
	UGint m_nCurrentID;
	
	UGint m_nTotalGeoLen;
	UGFileStream m_DataFile;
	UG_DATA_CACHE_FILE_HEADER m_dfh;
	UG_INDEX_CACHE_FILE_HEADER m_ifh;
	UG_SUPER_INDEX_ITEM  m_CurIndexItem;

	UGbyte * m_pIndexData;
	UGbyte * m_pGeoData;

public:		
	//�ҵĹ��вƲ�
	UGint m_nLibTileID;
};

}
#endif // !defined(AFX_UGORCCACHERECORDSET_H__60D395E7_A724_492F_A4F8_721C3485CD29__INCLUDED_)
