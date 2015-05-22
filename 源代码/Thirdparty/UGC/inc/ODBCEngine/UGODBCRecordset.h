// UGODBCRecordset.h: interface for the UGODBCRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCRECORDSET_H__5FB2901F_798F_425F_BEA5_0BFB1321B7BA__INCLUDED_)
#define AFX_UGODBCRECORDSET_H__5FB2901F_798F_425F_BEA5_0BFB1321B7BA__INCLUDED_

#include "Engine/UGRecordset.h"
#include "ODBCEngine/UGODBCDatasetVector.h"
#include "ODBCEngine/UGODBCConnection.h"
#include "Algorithm/UGRect.h"


namespace UGC
{
class UGEXPORT UGODBCRecordset  : public UGRecordset
{
public:
	UGODBCRecordset();
	UGODBCRecordset(UGODBCDatasetVector *pDatasetVector);
	virtual ~UGODBCRecordset();

public:
	//! \brief  ɾ�����м�¼
	virtual UGbool DeleteAll();

	//! \brief  ��ĳ��ͳ�Ʒ���ͳ��ĳ���ֶ�
	//! \param��strField��Ҫͳ�Ƶ��ֶ���[in]
	//! \param	nMode     ͳ�Ƶ�ģʽ
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);

	//! \brief  ˢ�¼�¼��,һ��������²�ѯһ��
	virtual UGbool Refresh();

	//! \brief  �����ֶ�ֵ,
	//! \param SrcField��	Դ�ֶ���[in]
	//! \param strDestField Ŀ���ֶ���[in]
	//! �����ֶ������ݿ��б��붼�������ֶ�����ƥ��
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);
	
	//! \brief  ��ȡ��ǰ��¼��ID
	virtual UGint GetID();

	//! \brief �Ƿ��¼��Ϊ��(û�м�¼)
	virtual UGbool IsEmpty();

	//! \brief  �жϵ�ǰ��¼ָ���Ƿ�ָ��ͷ
	virtual UGbool IsBOF();

	//! \brief  �жϵ�ǰ��¼ָ���Ƿ�ָ��β
	virtual UGbool IsEOF();
	
	//! \brief �رռ�¼��
	virtual void Close();

	//! \brief  ֱ�Ӷ������ζ����ָ��,���ڰ��������ݶ������ڴ��е�����(��dgn)��˵��
	//! \brief  ����Ҫ�������ζ�������Ҳ��Ҫȥɾ����,�������Լӿ�����ٶ�
	virtual UGbool GetGeometryDirect(UGGeometry*& pGeometry);

	//! \brief  ȡ�ü��ζ��󣬷��صļ��ζ���ָ���ں����ڷ����ڴ棬
	//! \brief  ���渺��ɾ������������ڴ�й©
	virtual UGbool GetGeometry(UGGeometry*& pGeometry);

	//! \brief  ͨ���ֶ�����ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(const UGString& strName,
		UGVariant& varVal);

	//! \brief  ͨ��������Ż�ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(UGint nIndex,
		UGVariant& varVal);

	//! \brief  ���õ�ǰ��¼�ļ��ζ���
	virtual UGbool SetGeometry(UGGeometry &geometry);

	//! \brief  ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGVariant& varVal);
	
	//! \brief  ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGString& strVal);
	
	//! \brief  ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGVariant& varVal);

	//! \brief  ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGString& strVal);

	//! \brief  ͨ���ֶ��������ֶ�ֵΪ��
	virtual UGbool SetFieldValueNull(const UGString& strName);

	//! \brief  ͨ�����������ֶ�ֵΪ��
	virtual UGbool SetFieldValueNull(UGint nIndex);

	//! \brief  �ڼ�¼�����ٴβ�ѯ,���ҷ��������ĵ�һ����¼
	virtual UGbool FindFirst(const UGString& strFilter);
	
	//! \brief  �ڼ�¼�����ٴβ�ѯ,���ҷ������������һ����¼
	virtual UGbool FindLast(const UGString& strFilter);

	//! \brief  �ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	virtual UGbool FindNext(const UGString& strFilter);

	//! \brief  �ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	virtual UGbool FindPrev(const UGString& strFilter);

	//! \brief  ������Ӧ����,��ǰ������ƶ���¼ָ��
	virtual UGbool Move(UGint nRows);

	//! \brief  �ƶ���¼ָ�뵽��ǰ
	virtual UGbool MoveFirst();

	//! \brief  �ƶ���¼ָ�뵽���
	virtual UGbool MoveLast();

	//! \brief  �����ƶ�һλ��¼ָ��
	virtual UGbool MoveNext();

	//! \brief  �����ƶ�һλ��¼ָ��
	virtual UGbool MovePrev();

	//! \brief  �ƶ���¼ָ�뵽ָ��λ��
	virtual UGbool MoveTo(UGint nRow);

	//! \brief  ͨ��ID��λ��¼ָ��
	virtual UGbool SeekID(UGint nID);

	//! \brief  ��ȡ��¼����
	virtual UGint GetRecordCount();

	//! \brief  �ռ������ֶε���Ϣ
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos);
	
	//! \brief  ͨ���ֶ�����ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(const UGString& strName,
		UGFieldInfo& fieldInfo);
	
	//! \brief  ͨ������ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(UGint nIndex,
		UGFieldInfo& fieldInfo);
	
	//! \brief  ��ȡ�ֶθ���
	virtual UGint GetFieldCount();
	
	//! \brief  ���£��ύ�޸�
	virtual UGint Update();

	//! \brief  ȡ���޸�
	virtual UGbool CancelUpdate();
	
	//! \brief  ��ʼ�޸�����
	virtual UGbool Edit();

	//! \brief  ����¼�¼
	virtual UGint AddNew(UGGeometry *pGeometry,
		UGbool bReturnID=FALSE);

	//! \brief  ɾ����ǰ��¼
	virtual UGbool Delete();

	//! \brief  ˢ�¼�¼
	virtual void FlushCurrentRecord();
	
	//! \brief  �Ƿ�֧������
	virtual UGbool CanTransact() const;

	//! \brief  �Ƿ�ɸ���
	virtual UGbool CanUpdate();

	//! \brief  �Ƿ�����
	virtual UGbool CanAppend();

	//! \brief �Ƿ�֧��ָ���Ĳ���
	virtual UGbool IsSupport(UGEngAction nAction);

	//! \brief  �����¼���ķ�Χ
	virtual UGbool ComputeBounds(UGRect2D &rc2Bounds,
		UGdouble &dMinZ,UGdouble &dMaxZ);

	//! \brief  �ǳ�����״̬�µ�����
	virtual UGbool Lock();

	//! \brief  �ǳ�����״̬�µĽ���
	virtual UGbool UnLock();

	//! \brief  �õ���ǰ��¼��˭��������
	virtual UGString GetRecordCheckedBy();

	//! \brief  ��������غ���
	virtual UGbool UndoCheckOutCurrent(UGbool bKeepCheckedOut);	
	virtual UGbool CheckInCurrent(UGbool bKeepCheckedOut);
	virtual UGbool CheckOutCurrent();
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool CheckOut();

	//! \brief �õ���ǰ��¼���ζ���ķ�Χ
	//! \param rc2Bounds	���ζ���Ķ�ά��Χ
	//! \param dMinZ		���ζ������С�߳�(������������������)
	//! \param dMaxZ		���ζ�������߳�(������������������)
	//! \sa	GetGeometry
	virtual UGbool GetGeometryBounds(UGRect2D &rc2Bounds,
		UGdouble& dMinZ,UGdouble& dMaxZ);

	//! \brief  ����������ѯ
	virtual UGbool GetForeignKeysVal(UGArray<UGString> &aryForeignKeys,UGArray<UGVariant> &aryVal);
	//! \brief  ��ȡ�����ѯ��ֵ
	virtual UGbool FetchForeignKeysVal(UGArray<UGVariant> &aryVal);

	//! \brief  ���ݲ�ѯѡ���ȡID
	//! \param aryIDs	IDs����[out]
	//! \param queryDef	��ѯѡ��[in]
	UGbool GetIDsByQueryDef(UGArray<UGint> &aryIDs,UGQueryDef queryDef);

	//! \brief ����Numeric����Doubleֵ
	//! \param	Numeric��[in]
	//! \return Doubleֵ
	UGdouble Numeric2Double(SQL_NUMERIC_STRUCT &Numeric);

public:
	//! \brief ������¼��
	//! \param queryDef ��ѯѡ��[in]
	UGbool Create(const UGQueryDef& queryDef);

	//! \brief ��Ҳ�ѯ������¼��
	//! \param linkItem ��Ҳ�ѯѡ��
	UGbool Create2(UGLinkItem &linkItem);
	
	UGbool InitFields();

	//! \brief�汾���ݼ����˵�D���ID���ٻ�ȡA���ID
	//! \remark �汾��ѯʱ��Ҫ
	//! \param  rcBounds	��ѯ�ķ�Χ	[in]
	//! \param	aryItemIDs	�������ID��׷�ӵ���������[in/out]
	UGbool RefineVersionTabIDs(UGRect2D rcBounds, UGArray<UGint> &aryItemIDs);
protected:
	//! \brief �жϼ�¼���Ƿ��
	UGbool IsOpen();
	//! \brief General��ѯ
	//! \param queryDef ��ѯѡ��[in]
	virtual UGbool CreateWithGeneral(const UGQueryDef &querydef);
	//! \brief IDs��ѯ
	//! \param pIDs id����[in]
	//! \param��nCount��id��Ŀ[in]
	virtual UGbool CreateWithIDs(UGint *pIDs,UGint nCount,UGString &strFieldName);
	//! \brief Bounds��ѯ
	//! \param rc2Bounds ��ѯ��Χ[in]
	//! \param��nOptions��ѡ����Ϣ[in]
	virtual UGbool CreateWithBounds(const UGRect2D &rc2Bounds, UGint nOptions, UGint  nMode);

	//! \brief ������������ID
	//! \param strFilter  ��������[in]
	//! \param aryItemIDs IDs����[in]
	void EnhanceIDs(UGString &strFilter,UGArray<UGint> &aryItemIDs);

	//! \brief �����¼��Ŀ
	//! \param strSQL  SQL���[in]
	UGint StatisticRecordCount (const UGString& strSQL);

	//! \brief ����Bounds��ѯ��SQL���
	//! \param rc2Bounds  ��ѯ�ķ�Χ[in]
	UGString BuildBoundsSQL(const UGRect2D &rc2Bounds);
	//! \brief ����General��ѯ��SQL���
	UGString BuildGeneralSQL();
	UGString BuildLTFilter();
	
	//! \brief ���ֶν��й���
	//! \param��fields �ֶ�����[in]
	void CheckFields(UGArray<UGString> &fields);
	//! \brief ���ֶ���Ϣ���й���
	//! \param��cursor�����α������ֶ���Ϣ����[in]
	//! \param��fieldInfos �ֶ���Ϣ[out]
	UGbool OrganiseFields(UGODBCCursor &cursor,UGFieldInfos &fieldInfos);

	//! \brief �������
	UGODBCConnection * GetConnection();

	//! \brief ����ڴ�
	void ClearBuffer();
	//! \brief ˢ���ڴ�
	void ResetBuffer();

	//! \brief ˢ�¼�¼��
	UGbool RefreshPos();

	//! \brief  �汾���ݼ� ��ͼ���滻����
	UGString ReplaceTNameByVName(UGString strSQL);

	//! \brief  ��ұ��ѯ
	UGbool PrepareLink();

	//! \brief  ���������Ĳ�ѯ
	UGString BuildDynamicSQL(UGRect2D SearchBounds);

	//! \brief  ����ĳ��Χ����������
//	UGbool FindQueryGrids();

	//! \brief  ����QueryDefine���ж��Ƿ���Ҫ�����ѯ�ֶ�
	UGbool IsStatisticalQuery();

	//! \brief  �ж����ݼ��Ƿ��ǵ㼯
	UGbool IsEnableGranule();

	//! \brief ��ȡSmKey=0������R����������ģ�ID
	UGbool GetNonRTreeIDs(UGRect2D rcBounds, UGArray<UGint> &aryIDs);

	//! \brief ��ȡSmIDs,ͨ�������ֶε�ID��ѯ
	UGbool GetIDsByFieldQuery(UGint *pIDs,UGint nCount,UGString &strFieldName);
private:

	//! \brief ��ȡ����
	UGbool FetchData (const UGString & strSQL);

	//! \brief ��ұ��ȡ����
	UGbool FetchData2(const UGString & strSQL);

public:
	UGArray<UGRecordset *> m_AryLinkRecords;

protected:
	UGFieldInfos m_fieldInfos;
	// �������ֶεĴ���
	UGFieldInfos m_BinaryFieldInfos;
	UGbool m_bOpen;
	UGString m_strFilter;
	UGint m_nRecordCount;
	UGint  m_nCurrentIndex;

	UGArray<UGString> m_Fields;
	UGbool m_bStatistic;

	UGODBCCursor m_GeometryCursor;
	
	UGint	m_nAttrRowSize;
	UGbool	m_bQueryByID;
	UGint	*m_pIndicator;
	UGint *	m_pBindIDs;
	UGArray<UGint> m_arrIDs;
	UGint m_nGeoRowSize;
	UGuchar	*m_pAttrBuffer;
	UGuchar *m_pGeoBuffer;
	UGint m_nBeginIndex;
	UGint m_nEndIndex;
	UGint m_nOnceFetchCount;
	UGint m_nReturnRow;
	UGint m_nEditMode;

	UGint m_nGeoPos;
		
	UGint m_nBindFetchIDsCount;

	UGODBCBinds m_Binds;
	UGODBCBinds m_DefineBinds;

	// �����ѯ�����
	UGString m_strSql;
	UGODBCBinds m_aryDefine;

	// Dynamic��ѯ���grids
//	UGArray<UGRect> m_aryGrids;
	UGArray<UGPoint> m_aryGrids;
	// ��ѯ���Bounds
	UGRect2D m_rcDynamicBounds;

	UGString m_strDynamicSql;

};

}

#endif // !defined(AFX_UGODBCRECORDSET_H__5FB2901F_798F_425F_BEA5_0BFB1321B7BA__INCLUDED_)
