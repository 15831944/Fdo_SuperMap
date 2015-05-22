// SdbRecordset.h: interface for the UGSdbPlusRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDBRECORDSETPlus_H__017098A9_099E_11D3_92D2_0080C8EE62D1__INCLUDED_)
#define AFX_SDBRECORDSETPlus_H__017098A9_099E_11D3_92D2_0080C8EE62D1__INCLUDED_

#if _MSC_VER > 1000 
#pragma once 
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Base/UGVariant.h"
#include "Engine/UGRecordset.h"
#include "Engine/UGQueryDef.h"
#include "Engine/UGDatasetVectorInfo.h"

//#define SURVEYVERSION//added by shiww,����ɾ��,��ϵͳû��Ӱ��,���û����ú�
#define WM_RECORDSETSTATE WM_USER+2000
#define dbEditOfGeometry 3	//dbEditInProgress��һ��,�������ռ����ݵĸ���
//=======================================================
// �����̸���Ĺ�ϵ�������ƺ��ܸ��ӣ���ʵ�ܼ�...
// ��鿴Readme.txt�ļ����й�˵��
//=======================================================

namespace UGC {

class UGSdbPlusDatasetVector;
class UGFileLogical;

class SDBPLUSENGINE_API UGSdbPlusRecordset : public UGRecordset  
{
	
public:
	UGSdbPlusRecordset();
	UGSdbPlusRecordset(UGSdbPlusDatasetVector *pDataset);
	~UGSdbPlusRecordset();

public:		//method
	UGbool HasField(UGString strFieldName);

	UGint GetID();	//��ǰ��¼ID
	UGbool IsEmpty();	//�Ƿ��¼��Ϊ��(û�м�¼)
	UGbool IsBOF();	//��ǰ��¼ָ���Ƿ�ָ��ͷ
	UGbool IsEOF();	//��ǰ��¼ָ���Ƿ�ָ��β

	void Close();	//�ر�
	
	//���ֶ�ֵ 
	UGbool GetFieldValue(const UGString &strName, UGVariant& varValue );	//�����ֶ����õ��ֶ�ֵ
	UGbool GetFieldValue( UGint nIndex, UGVariant& varValue );	//�����ֶ���ŵõ��ֶ�ֵ
	UGbool GetGeometryDirect(UGGeometry* &geometry);	//�����治֧��!!!
	UGbool GetGeometry(UGGeometry *&geometry);	//�õ�geometry��ָ��,�������ע��ɾ��
	UGbool GetGeometryBounds(UGRect2D &rc2Bounds,double& dMinZ,double& dMaxZ);	//�õ���άBounds,��ά����dMinZ��MaxZ������

	//д�ֶ�ֵ
	UGbool SetFieldValue(const UGString &strName, const UGVariant& varValue);	//Set SDD field value according to field name
	UGbool SetFieldValue(UGint nOrdinal, const UGVariant& varValue);	//Set SDD field value according to field index
	UGbool SetFieldValue(const UGString &strName, const UGString &strValue); //Set SDD field value as string according to field name
	UGbool SetFieldValue(UGint nOrdinal, const UGString &strValue);	//Set SDD field value as string according to field index
	UGbool SetFieldValueNull(const UGString &strName);	//Set SDD field value to NULL according to field name
	UGbool SetFieldValueNull(UGint nOrdinal);	//Set SDD field value to NULL according to field index
	virtual UGbool SetGeometry(UGGeometry &geometry);	//set geometry

	//����
	UGbool FindFirst(const UGString &strFilter) ;		//Locates the first record in a dynaset-type or snapshot-type recordset that satisfies the specified criteria and makes that record the current record.
	UGbool FindLast(const UGString &strFilter) ;		//Locates the last record in a dynaset-type or snapshot-type recordset that satisfies the specified criteria and makes that record the current record.
	UGbool FindNext(const UGString &strFilter) ;		//Locates the next record in a dynaset-type or snapshot-type recordset that satisfies the specified criteria and makes that record the current record.
	UGbool FindPrev(const UGString &strFilter) ;		//Locates the previous record in a dynaset-type or snapshot-type recordset that satisfies the specified criteria and makes that record the current record.

	UGbool Move(UGint nRows);	//Position the recordset nRows records from the current record
	UGbool MoveFirst();		//Positions the current record on the first record in the recordset. 
	UGbool MoveLast();		//Positions the current record on the last record in the recordset. 
	UGbool MoveNext();		//Positions the current record on the next record in the recordset .
	UGbool MovePrev();		//Positions the current record on the previous record in the recordset.

	UGbool MoveTo(UGint nRows);	//Position the recordset nRows records from the first record
	UGbool SeekID(UGint nID);	//Positions the current record on the one which SmId==nID

	//����
	UGString GetFilter() ;	//return the property fileter of query
	UGint GetRecordCount();	//return the record count in itself

	//�ֶ�
	UGbool GetFieldInfos(UGFieldInfos &fieldInfos/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);	//Get all fieldinfos
	UGbool GetFieldInfo(const UGString &strName, UGFieldInfo &fieldInfo/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);	//Get fieldinfo according to the field name
	UGbool GetFieldInfo(UGint nIndex, UGFieldInfo &fieldInfo/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);	//Get fieldinfo according to the field index
	UGint GetFieldCount();	//Get SDD fields coutn,not including Geometry

	//��¼����
	//dbEditNone(0) -- No editing operation is in progress. 
	//dbEditInProgress(1) -- Edit has been called. 
	//dbEditAdd(2) -- AddNew Edithas been called. 
	short GetEditMode();	//ȡ��EditMode,�������

	//! \brief �����¼�¼,�ɹ�������TRUEֵ��ʧ�ܷ���FALSEֵ��
	//! \param *pGeometry [in] ��ӵ�Geometryָ��
	//! \param bReturnID=FALSE [in] �˲����Ѿ��������á�
	//! \return True �� False ��ֵ
	//! \remarks �����õ��¶����ID����ô���ϵ���GetId����
	virtual UGint AddNew(UGGeometry *pGeometry,UGbool bReturnID=FALSE);	
	virtual UGbool Edit();	//SetXXXǰ��Ҫ����Edit״̬
	virtual UGint Update();	//Addnew��SetXXX����,ע��ռ�����updateǰ����ɾ��
	virtual UGbool CancelUpdate();//ȡ��Update
	virtual UGbool Delete();	//��¼ɾ��
	virtual UGbool DeleteAll();		//ɾ�����еļ�¼
	virtual void FlushCurrentRecord();	//��¼ˢ��
	virtual UGbool Refresh();			//ˢ�¼�¼��
	
	//״̬
	UGbool CanTransact() const;	//return the status of transacted
	UGbool CanUpdate();	//return the status of updatable
	UGbool CanAppend();	//return the status of appendable
	virtual UGbool IsSupport(UGEngAction nAction);


	//������
	UGbool ComputeBounds(UGRect2D &rc2Bounds,double &dMinZ,double &dMaxZ);	//���㱾Recordset��Bounds,ͨ���������÷��ؽ��
	UGVariant Statistic(const UGString& strField,UGStatisticMode nMode);		//ͳ�ƹ���
	UGbool CopyField(const UGString& strSrcField,const UGString& strDestField); //�ֶ�ֵ������strSrcField��strDestField���붼�������ֶ�����ƥ�䣬�ֶ�����ƥ���ο�CDatasetVector.h
	
	//! �ǳ�����״̬�µ�����
	virtual UGbool Lock();

	//! �ǳ�����״̬�µĽ���
	virtual UGbool UnLock();

	//! �õ���ǰ��¼��˭��������
	virtual UGString GetRecordCheckedBy();

	virtual UGbool UndoCheckOutCurrent(UGbool bKeepCheckedOut);
	virtual UGbool CheckInCurrent(UGbool bKeepCheckedOut);
	virtual UGbool CheckOutCurrent();
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool CheckOut();
	
//	UGbool Export2Txt(UGString strFileName,		//�õ����ı��ļ���·��������
//					   double dGridSize,		//*************************
//					   UGString strTerminate = "--$",		//���Լ���ֽڶεļ����
//					   UGint nMinSmID = 1			//��ʼ��SmID
//					   );		
//	UGbool ExportSqlPlusTxt(UGString strFileName,		//�õ����ı��ļ���·��������
//						  UGint & nRecordCount,
//						   UGRect2D & rc2Bounds,		//*************************
//						   UGString strTerminate = "--$", /*= '--$'*/		//���Լ���ֽڶεļ����
//						   UGint nMinSmID = 1,			/* = 0 */
//						  UGbool bShowProgressCtrl = TRUE
//						  );
//	UGbool ExportSybaseTxt( UGString strFileName,		//�õ����ı��ļ���·��������
//						   UGint & nRecordCount,
//						   UGRect2D & rc2Bounds,		//*************************
//						   UGString strTerminate = "--$", /*= '--$'*/		//���Լ���ֽڶεļ����
//						   UGint nMinSmID = 1			/* = 0 */
//						   );

protected:	//attribute

//	UGQueryDef m_querydef;

	CDaoRecordset m_Recordset;			//��ѯMDBʱʹ��
	UGSdbPlusRecordset *m_prsTINVertex;	//TINͼ���ѯTINVertexͼ��˵�Ŀռ�����

	BYTE *m_pInSplFilter;			//�洢������־,��bit�洢
									//ÿһbit��Ӧ��DatasetVector�е�һ����¼����
									//1 -- ѡ��,0 -- δѡ��
	
	UGint m_nCurrentPos;				//��ǰ��¼
	UGint m_nRecordCount;			//��¼��
	UGint m_nFirst,m_nLast;			//��һ�������һ����¼ָ��
	UGint m_nAbsolutePosition;		//��ǰ����λ�ã�����Recordset�д��ڵڼ���,ע�⣬����0��ʼ��
	
	UGFieldInfos m_FieldInfos;
	
	UGGeometry *m_pGeometry;		//�洢AddnewʱpGeometry��ָ��,Update��ʱ����̲��¿�

	UGuchar *m_pZipBuffer;				//ѹ��������������ÿ��ѹ�����·����ڴ�
	UGuint m_lZipBfrLen;		//ѹ����������С

	UINT m_uRecordsetType;
	UGString m_strIDFieldName;		//SmID�ֶε����ƣ�һ����SmID,����ұ�Ϳ�����table.smid

	UGuint m_dwStates;				// byte0:editmode
									// byte1:edit changed
									// byte2:some options,such as send message to suery,read node color
									// byte3:reserved
	void SetEditMode(BYTE nEditMode);
	UGbool GetFirstChanged() const;
	void SetFirstChanged(UGbool bValue);
	UGbool GetLastChanged() const;			//��һ�������һ����¼ָ��ı��־
	void SetLastChanged(UGbool bValue);		
	UGbool GetEmptyChanged() const;			//��¼���ձ���ձ�־
	void SetEmptyChanged(UGbool bValue);		
	
	UGbool GetNeedReadNodeColor() const;		//�Ƿ���Ҫ��ȡ��ͼ���нڵ���ɫ�ֶ�
	void SetNeedReadNodeColor(UGbool bValue);		//�Ƿ���Ҫ��ȡ��ͼ���нڵ���ɫ�ֶ�

protected:
	
	//Recorset�Ƿ��
	UGbool IsOpen();

	//��ӦDataset��Query����,��Ӧ����CreateWith...�������TINͼ��,��������һ����TINVertex�Ĳ�ѯ
	UGbool Create(const UGQueryDef &querydef);	
	UGbool CreateWithGeneral(const UGQueryDef &querydef);	//��ͨ��ʽ��ѯ,
	UGString BuildSql(const UGQueryDef &querydef);	//����Querydef��ѡ���SDD��sql��ѯ���

	UGbool CreateWithBounds(const UGRect2D &rc2Bounds,UGint nOptions,UGint nMode,UGString strFilter=(""),UGString strSort=(""));	//Bounds��ѯ
	//��������������CreateBounds()����
	void CheckCertainKeys(UGArray<UGint>& arCertainKeys,UGbool bQualification,UGint* plFilterIDs=NULL,UGint nFilterCount=0);
	void CheckMaybeKeys(UGArray<UGint>& arMaybeKeys,UGRect2D& rc2Bounds,UGbool bQualification,UGint* plFilterIDs=NULL,UGint nFilterCount=0);

	UGbool CreateWithIDs(UGint *pIds,UGint nCount,UGint nOptions,UGint nMode);	//IDs��ѯ

	UGbool GetGeometryDirectly(UGint nIndex,UGGeometry* &pGeometry);	//�����ļ���λ�ö�ȡGeometry
	UGbool GetGeometryBoundsDirectly(UGint nIndex,UGRect2D &rc2Bounds,double& dMinZ,double& dMaxZ);	//�����ļ���λ�ö�ȡGeometry Bounds

	//���ݼ���պ�λ
	void ResetAfterEmpty();

	//��������
	UGbool UpdateAfterAddNew();			//AddNew�Ժ����
	UGbool UpdateAfterEditOfGeometry();	//SetGeometry�Ժ����
	UGint CompressGeometryData(UGbool& bZipFlag,UGint& nSizeBeforeZip);	//ѹ��Geometry�����ݣ�����������������������������á�

	UGbool InitSpatialFilterFlag();  //��ʼ����Ϊm_pInSplFilter����ռ�
	inline void SetSpatialFilterFlag(UGint nRows,UGbool bIn);	//���ô洢������־
	inline UGbool GetSpatialFilterFlag(UGint nRows);	//�õ��洢������־

	//��������������TINͼ���й�
//	UGbool AppendTinVertex(CGeoTriangle *pTriangle,UGint *pTinVertexNo);	//��TinVertex��ͼ���м���������Ŀռ�����,�����ؼ����ļ�¼��	
//	UGbool GetTinVertexFromNo(UGint nNo,CPoint3D *pPoint3D,float *pNormal,COLORREF& color);//��PointGLͼ���и��ݵ�����кŴ�m_stmTinVertex��ȡ�õ������ͷ��������Լ������ɫ��

	//�ָ�ɾ���ļ�¼
	//const UGint & nID,��¼��ID
	//UGGeometry *pGeometry	//���ζ���
	//CDaoRecordset *pRs;		//Undo���ݼ�
	UGbool Restore(const UGint & nID, UGGeometry *pGeometry,CDaoRecordset *pRs);
	
	UGbool SeekSmID(UGint nID);  //�� m_Recordset��ָ���ƶ���SmId = nID ��λ��
	
	static UGbool IsQueryAll(const UGQueryDef& querydef);
	UGbool CanOpenTableMode();  //�ܷ���dbOpenTableģʽ��

	 //�����ֶ����ͣ�ת�������ֵ
	static UGbool ChangeVariantType(UGVariant& varValue,short nFieldType);
	static UGbool Ole2UG(const COleVariant& varValue,UGVariant& ugVar);
	static UGbool UG2Ole(const UGVariant& ugVar,COleVariant& varValue,int nCharset);
	static void UG2Dao(const UGFieldInfo& fieldInfo, CDaoFieldInfo& daoFieldInfo);
	static void Dao2UG(CDaoFieldInfo& daoFieldInfo, UGFieldInfo& fieldInfo);

	//static void ReadGeometry(UGFileLogical*pFile, UGGeometry* pGeometry);
	static void ReadGeoData(UGFileLogical*pFile, UGGeometry* pGeometry);

	static void WriteGeometry(UGFileLogical*pFile, UGGeometry* pGeometry);
	static void WriteGeoStyle(UGFileLogical* pFile, UGGeometry* pGeometry);
	// ֻд��Geo Data���ֵ�����
	static void WriteGeoData(UGFileLogical* pFile, UGGeometry* pGeometry);

	static UGbool HasBounds(UGGeometry* pGeometry);
	static UGbool Has3DBounds(UGGeometry* pGeometry);

//	void GetRecordHeader(UGGeometry* pGeometry, UGRecordHeader* pRecordHeader);

	// ����, �ڲ��� ������Saveһ��, Ȼ��Size
	static UGint GetGeoDataSize(UGGeometry* pGeometry);

	//UGbool UGSdbPlusRecordset::AppendTinVertex(UGGeoTriangle *pTriangle,UGint *pTINVertexNo);

	static void CheckBounds(UGDatasetVectorInfo& datasetInfo, const UGRect2D& bounds);
	static void CheckBounds(UGDatasetVectorInfo& datasetInfo, const UGRect2D& bounds, 
							double dMinZ, double dMaxZ);

	static void UnionBounds(UGRect2D &rc2Bounds, double &dMinZ, double &dMaxZ,
					const UGRect2D &rc2ObjBounds, double dObjMinZ, double dObjMaxZ, UGbool bInit);

private:
	UGbool m_bCalculateAreaAndLengthWhenAddNew;

	//����ͳ��ʱ�������Ҫ������һ����ʱ��
	CDaoTableDef* m_pStatisticTable;		//ͳ������ʱ��
	UGbool CreateStaticTable();				//������ʱͳ�Ʊ�
					
	UGbool WriteLog(UGString strActionCode, int nReturnCode, UGString strActionDesc);
	int GetLogLevel();

	friend class UGSdbPlusDatasetVector;
	friend class UGSdbPlusDataSource;
//	friend class CSmUndoRecordset;
//	friend class CSmEditHistory;

};

inline void UGSdbPlusRecordset::SetEditMode(BYTE nEditMode)
{
	m_dwStates &= 0xffffff00;
	m_dwStates = m_dwStates + nEditMode;
}

//����EditMode
inline short UGSdbPlusRecordset::GetEditMode() 
{
	//dbEditOfGeometry��Edit��SetGeometryʱRecordset��״̬
	BYTE nEditMode = BYTE(m_dwStates & 0x000000ff);
	return nEditMode;

};

inline UGbool UGSdbPlusRecordset::GetFirstChanged() const
{
	return (m_dwStates & 0x00000100)!=0;
}

inline void UGSdbPlusRecordset::SetFirstChanged(UGbool bValue)
{
	if(bValue)
	{
		m_dwStates |= 0x00000100;
	}
	else
	{
		m_dwStates &= ~(0x00000100);
	}

}

inline UGbool UGSdbPlusRecordset::GetLastChanged() const
{
	return 	(m_dwStates & 0x00000200)!=0;
	
}

inline void UGSdbPlusRecordset::SetLastChanged(UGbool bValue)
{
	if(bValue)
	{
		m_dwStates |= 0x00000200;
	}
	else
	{
		m_dwStates &= ~(0x00000200);
	}
}

inline UGbool UGSdbPlusRecordset::GetEmptyChanged() const
{
	return	(m_dwStates & 0x00000400)!=0;
}

inline void UGSdbPlusRecordset::SetEmptyChanged(UGbool bValue)
{
	if(bValue)
	{
		m_dwStates |= 0x00000400;
	}
	else
	{
		m_dwStates &= ~(0x00000400);
	}
}


inline UGbool UGSdbPlusRecordset::GetNeedReadNodeColor() const
{
	return	(m_dwStates & 0x00010000)!=0;
}

inline void UGSdbPlusRecordset::SetNeedReadNodeColor(UGbool bValue)
{
	if(bValue)
	{
		m_dwStates |= 0x00020000;
	}
	else
	{
		m_dwStates &= ~(0x00020000);
	}
}

}

#endif // !defined(AFX_SDBRECORDSETPlus_H__017098A9_099E_11D3_92D2_0080C8EE62D1__INCLUDED_)


