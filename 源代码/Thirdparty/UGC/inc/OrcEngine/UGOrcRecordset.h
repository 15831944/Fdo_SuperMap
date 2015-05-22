/*! \file	 UGOrcRecordset.h
 *  \brief	 Oracle Plus��¼����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOrcRecordset.h,v 1.26 2008/01/02 05:09:13 liwl Exp $
 */

#ifndef UGORCRECORDSET_H
#define UGORCRECORDSET_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Engine/UGRecordset.h"
#include "Base/UGVariant.h"
#include "UGOCIConnection.h"
#include "UGOCICursor.h"
#include "UGOCIDefine.h"
#include "UGOrcDatasetVector.h"

namespace UGC {

class ORCENGINE_API UGOrcRecordset : public UGRecordset
{
public:
	UGOrcRecordset();

	UGOrcRecordset(UGOrcDatasetVector* pDataset);

	virtual ~UGOrcRecordset();	

public:
	//! ɾ�����м�¼
	virtual UGbool DeleteAll();

	//! ��ĳ��ͳ�Ʒ���ͳ��ĳ���ֶ�
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);

	//! ˢ�¼�¼��,һ��������²�ѯһ��
	virtual UGbool Refresh();

	//! �����ֶ�ֵ,strSrcField��
	//! strDestField���붼�������ֶ�����ƥ��
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);	
	
	//! ��ȡ��ǰ��¼��ID
	virtual UGint GetID();

	//! �жϵ�ǰ��¼ָ���Ƿ�ָ��ͷ
	virtual UGbool IsBOF();

	//! �жϵ�ǰ��¼ָ���Ƿ�ָ��β
	virtual UGbool IsEOF();
	
	//! �رռ�¼��
	virtual void Close();

	//! ֱ�Ӷ������ζ����ָ��,���ڰ��������ݶ������ڴ��е�����(��dgn)��˵��
	//! ����Ҫ�������ζ�������Ҳ��Ҫȥɾ����,�������Լӿ�����ٶ�
	virtual UGbool GetGeometryDirect(UGGeometry*& pGeometry);

	//! ȡ�ü��ζ��󣬷��صļ��ζ���ָ���ں����ڷ����ڴ棬
	//! ���渺��ɾ������������ڴ�й©
	virtual UGbool GetGeometry(UGGeometry*& pGeometry);

	//! ͨ���ֶ�����ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(const UGString& strName,
		UGVariant& varVal);

	//! ͨ��������Ż�ȡ�ֶ�ֵ
	virtual UGbool GetFieldValue(UGint nIndex,
		UGVariant& varVal);

	//! ���õ�ǰ��¼�ļ��ζ���
	virtual UGbool SetGeometry(UGGeometry &geometry);
	
	//! ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGVariant& varVal);
	
	//! ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGString& strVal);
	
	//! ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ��������
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGVariant& varVal);

	//! ͨ������������õ�ǰ��¼���ֶ�ֵ,ֵΪ�ַ�������
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGString& strVal);	

	//! ͨ���ֶ��������ֶ�ֵΪ��
	virtual UGbool SetFieldValueNull(const UGString& strName);	

	//! ͨ�����������ֶ�ֵΪ��
	virtual UGbool SetFieldValueNull(UGint nIndex);

	//! �ڼ�¼�����ٴβ�ѯ,���ҷ��������ĵ�һ����¼
	virtual UGbool FindFirst(const UGString& strFilter);
	
	//! �ڼ�¼�����ٴβ�ѯ,���ҷ������������һ����¼
	virtual UGbool FindLast(const UGString& strFilter);

	//! �ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	virtual UGbool FindNext(const UGString& strFilter);

	//! �ڼ�¼�����ٴβ�ѯ,���ҷ�����������һ����¼
	virtual UGbool FindPrev(const UGString& strFilter);

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

	//! ��ȡ��¼����
	virtual UGint GetRecordCount();

	//! �ռ������ֶε���Ϣ
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos);
	
	
	//! ͨ���ֶ�����ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(const UGString& strName,
		UGFieldInfo& fieldInfo) ;
	
	//! ͨ������ȡ�ֶ���Ϣ
	virtual UGbool GetFieldInfo(UGint nIndex,
		UGFieldInfo& fieldInfo);
	
	//! ��ȡ�ֶθ���
	virtual UGint GetFieldCount();
	
	//! ���£��ύ�޸�
	virtual UGint Update();

	//! ȡ���޸�
	virtual UGbool CancelUpdate();
	
	//! ��ʼ�޸�����
	virtual UGbool Edit();
	
	//! ����¼�¼
	virtual UGint AddNew(UGGeometry *pGeometry,
		UGbool bReturnID=FALSE);

	//! ɾ����ǰ��¼
	virtual UGbool Delete();

	//! ˢ�¼�¼
	virtual void FlushCurrentRecord();
	
	//! �Ƿ�֧������
	virtual UGbool CanTransact() const;

	//! �Ƿ�ɸ���
	virtual UGbool CanUpdate();

	//! �Ƿ�����
	virtual UGbool CanAppend();

	//! �Ƿ�֧��ָ���Ĳ���
	virtual UGbool IsSupport(UGEngAction nAction);

	//! �����¼���ķ�Χ
	virtual UGbool ComputeBounds(UGRect2D &rc2Bounds,
		UGdouble &dMinZ,UGdouble &dMaxZ);	

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

	//! ����������ѯ
	virtual UGbool GetForeignKeysVal(UGArray<UGString> &aryForeignKeys,UGArray<UGVariant> &aryVal);
	virtual UGbool FetchForeignKeysVal(UGArray<UGVariant> &aryVal);

public:
	virtual UGString BuildBoundsSQL(const UGRect2D& rc2Bounds);
	
	/// \brief ����General��ѯ��SQL���
	virtual UGString BuildGeneralSQL();
	
	/// \brief ���죬��SmID�ֶ���ID��ѯ��SQL���,
	virtual UGString BuildIDsSQL(UGint *pIDs,UGint nCount,UGString &strFieldName,UGbool bRTree = FALSE);


	virtual UGbool CreateWithGeneral(const UGQueryDef& querydef);

	/// \brief ����ָ���Ŀռ䷶Χ����Bounds���ƵĲ�ѯ
	/// \param [in]	querydef	��ѯ�����ں���ѯ�ĸ���������ѡ���
	/// \note	ֻ��querydef.m_nOptions == CSmQuerydef::Boundsʱ�Ż���ô˺���
	/// \sa CSmQuerydef, Create, CreteWithGeneral, CreateWithIDs
	virtual UGbool CreateWithBounds(const UGRect2D& rc2Bounds, 
		UGint nOptions,UGint nMode);

	/// \brief ����ָ����ID����,��ָ�����ֶν��в�ѯ
	/// \param [in]	*pIDs      IDsָ��
	/// \param [in]	nCount     ID�ĸ���
	/// \param [in]	nOptions   
	/// \param [in]	nMode
	/// \param [in]	strFieldName �ֶΣ���һ����SmID
	/// \note	ֻ��querydef.m_nOptions == CSmQuerydef::IDsʱ�Ż���ô˺���
	/// \sa CSmQuerydef, Create, CreteWithGeneral, CreateWithBounds
	virtual UGbool CreateWithIDs(UGint *pIDs,UGint nCount,UGint nOptions,UGint nMode,UGString strFieldName,UGbool bRTree = FALSE);

public:

	UGString GetFilter() const {return m_strFilter;}
	
	void CheckError() const;

	UGbool Create(const UGQueryDef& queryDef);

	UGbool RefreshPos();

	UGbool IsOpen() const;

	/// \brief �ͷŵ�ǰ�������ݺͿռ�������ռ���ڴ�
	void ClearBuffer();	

	// ��Ҫ���ռ�����Բ�ѯ
	void CheckFields(UGArray<UGString>& fields);

	/// \brief ���쳤����Filter
	UGString BuildLTFilter();

	UGint GetRealID();

	/// \brief �Ե�ǰ��ѯ�ֶν���һЩ��ʼ��������Ҫ�ǰ�SMID�ŵ���ǰ��
	UGbool InitFields();

	UGint StatisticRecordCount(const UGString& strSQL);

	/// \brief ���ݹ���õ�SQL���ִ�е�һ�����ݶ�ȡ����
	/// \param [in]	strSQL ����õ�SQL���
	UGbool FetchData(const UGString& strSQL);
	UGbool FetchData2(const UGString& strSQL);

	/// \brief ����ָ����DAO���ͷ��ض�Ӧ��OCI����
	/// \param [in]	nDAOType	DAO����
	/// \return  ��Ӧ��OCI����
	ub2 GetOCIType(UGint nDAOType);

	UGbool Create2(UGLinkItem &linkItem);

protected:
	/// \brief �жϵ�ǰ��¼�Ƿ��ѱ������û�����
	UGbool IsLockedByOthers();

	/// \brief �õ�������ǰ��¼�ĳ������û���ID
	UGint GetLockedUserID();

	UGbool SyncFieldinfos(UGFieldInfos & fieldInfos);

	UGbool InitLinkFields();

	UGbool PrepareLink();

	// ����QueryDefine���ж��Ƿ���Ҫ�����ѯ�ֶ�
	UGbool IsStatisticalQuery();

	UGbool IsEnableGranule();

	//���������Ĳ�ѯ
	UGString BuildDynamicSQL(UGRect2D SearchBounds);
	//��BuildDynamicSQL�е���
	UGString BuildFilterFromDynamic(UGRect2D SearchBounds);

	/// \brief ��ID������ʱ��
	/// \param [in]	pIDs IDָ��
	/// \param [in]	nCount ID����
	/// \return  �ɹ��񣬲���ȷ����ǰʹ�õ���ʱ�����š�
	UGbool  AddIDsToTempTable(UGint *pIDs,UGint nCount);
	//����SQL�����Ӿ�
//	UGString BuildSelectPart();
//	UGString BuildFromPart();
//	UGString BuildFilterPart();
//	UGString BuildGroupbyPart();
//	UGString BuildOrderbyPart();

	//��ȡSmKey=0������R����������ģ�ID
	UGbool GetNonRTreeIDs(UGRect2D rcBounds, UGArray<UGint> &aryIDs);

	//����ǰ汾���ݼ�����Ҫ���˵�D���ID���ٻ�ȡA���SmID
	UGbool RefineVersionTabIDs(UGRect2D rcBounds, UGArray<UGint> &aryItemIDs);

protected:
	/// \brief OCI���Ӷ���
	UGOCIConnection* m_pConnection;
	
	/// \brief ��ѯ�����ݼ�
	UGOrcDatasetVector* m_pOrgDataset;
	
	/// \brief ��ѯ�������
	UGString m_strFilter;

	// \brief �����Ӳ�ѯ���
	UGString m_strSmGdx;
	
	/// \brief �洢��ѯ��ID�������ʱ��
	UGshort m_nTempTableID;
	
	/// \brief Ҫ��ѯ���ֶ�
	UGArray<UGString> m_Fields;
	
	/// \brief ��������ֶ���Ϣ
	UGFieldInfos m_fieldInfos;
	
	// �洢��GEOMETRY����Ķ������ֶΣ�
	UGFieldInfos m_BinaryInfos;

	/// \brief ��ǰ������еļ�¼��Ŀ
	UGint m_nRecordCount;
	
	/// \brief һ��������������ռ�Ŀռ�
	UGint m_nAttrRowSize;
	
	/// \brief һ���пռ�������ռ�Ŀռ�
	UGint m_nGeoRowSize;
	
	/// \brief һ�δ����ݿ���ȡ�صļ�¼��
	UGint m_nOnceFetchCount;
	
	/// \brief ��ȡ����ʱ��DefineĿ��
	UGOCIDefines m_OCIDefines;
	
	/// \brief �Ѿ����ر��ػ����еļ�¼��
	UGint m_nCountHaveGot;
	
	
	/// \brief ��־��¼���Ƿ��Ѿ���
	UGbool m_bOpened;
	
	/// \brief ���α����
	UGOCICursor m_cursor;
	
	/// \brief ��ǰ�α����ڵ�λ��
	UGint m_nCurrentIndex;
	
	/// \brief �������α꿪ʼ��λ��
	UGint m_nBeginIndex;
	
	/// \brief �������α����λ��
	UGint m_nEndIndex;
	
	/// \brief ������ſռ����ݵĻ���
	/// \remarks �ռ��С����(m_nMaxGeometrySize*m_nFetchCount)
	UGuchar*	m_pGeoBuffer;
	
	//! \brief ������ſռ����ݵĻ���
	//! \attention �ռ��С����(m_nMaxGeometrySize*m_nFetchCount)
	UGuchar*	m_pAttrBuffer;

	UGArray<UGRecordset *> m_AryLinkRecords;

	//��������ר��
	UGOCIBinds m_OciDynamicIdxBinds;
	//��ѯ���grids
//	UGPoint m_GridLB0;
//	UGPoint m_GridRT0;
//	UGPoint m_GridLB1;
//	UGPoint m_GridRT1;
//	UGPoint m_GridLB2;
//	UGPoint m_GridRT2;
	UGArray<UGPoint> m_aryGrids;

	UGRect2D m_rcDynamicBounds;	//��ѯ���Bounds

	/// \brief ��������ֶ���Ϣ�ڲ�ʹ��
	UGFieldInfos m_fieldInfosSelf;
private:
	UGOCIBinds m_OciBinds;

};

}

#endif

