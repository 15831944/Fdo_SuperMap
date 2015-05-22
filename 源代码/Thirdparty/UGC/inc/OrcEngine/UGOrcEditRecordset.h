/*! \file	 UGOrcEditRecordset.h
 *  \brief	 �ɱ༭��ѯ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOrcEditRecordset.h,v 1.12 2008/03/06 07:24:19 zhouqin Exp $
 */

#ifndef UGORCEDITRECORDSET_H
#define UGORCEDITRECORDSET_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "UGOrcRecordset.h"
#include "Base/UGVariant.h"
#include "UGOCIConnection.h"
#include "UGOCICursor.h"
#include "UGOCIDefine.h"
#include "UGOrcDatasetVector.h"

namespace UGC {

class ORCENGINE_API UGOrcEditRecordset : public UGOrcRecordset  
{
public:
	UGOrcEditRecordset();
		
	UGOrcEditRecordset(UGOrcDatasetVector* pDataset);

	virtual ~UGOrcEditRecordset();

public:
	/// \brief ����µļ�¼
	/// \param	[in]	pGeometry	Ҫ��ӵļ�¼�Ŀռ�����ָ��
	/// \return	�����ӳɹ��������¼�¼��ID, ���ʧ�ܣ�����-1
	/// \note	
	/// \@li	���Ҫ���Tabular��¼����pGeometry��ΪNULL����
	/// \@li	AddNew������ҪUpdate������Ч
	/// \attention	���ʧ�ܣ����ܵ���Update��CancelUpdate.
	//virtual long AddNew(CElemGeometry *pGeometry);
	//�ɹ������ط�0ֵ�����bReturnID=true,���ص����¶����IDֵ��ʧ�ܣ�����-1�����ʧ�ܣ����ܵ���Update��CancelUpdate.
	virtual UGint AddNew(UGGeometry *pGeometry,UGbool bReturnID=FALSE);

	/// \brief ɾ����ǰ��¼���е����м�¼
	/// \return  ɾ�������ɹ����
	/// \remarks  �����ǰ��¼���м�¼���ܶ�Ļ����˲������ܱȽ��������Ҫɾ�����ݼ��е����м�¼������ʹ��CDatasetVector::Truncate()����
	/// \sa Delete, COrcPlusDatasetVector::Truncate
	virtual UGbool DeleteAll();		//ɾ�����еļ�¼

	/// \brief �����ֶο�����ֵ
	/// \param strSrcField	Դ�ֶε����ƣ�Ҳ�����Ǳ��ʽ���磺Field1*3+2
	/// \param strDestField	Ŀ���ֶε����ƣ�ֻ�������ݼ����Ѿ����ڵ��ֶ�
	/// \return  ���������ɹ����
	/// \sa COrcPlusDatasetVector::UpdateField
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);	

	/// \brief �õ���ǰSmIDֵ
	/// \return  ��ǰSmIDֵ
	/// \sa Create
	virtual UGint GetID();

	/// \brief �رյ�ǰ��¼��
	/// \note �ͷ�ռ�õ���Դ
	virtual void Close();

	/// \brief �õ���ǰ��¼���ζ�������ָ��
	/// \param geometry	�������ζ��������ָ��
	/// \note geometryָ���ں����ڷ��䣬����Ҫ������delete
	/// \sa	SetGeometry
	virtual UGbool GetGeometry(UGGeometry *&geometry);

	/// \brief �õ���ǰ��¼���ζ���ķ�Χ
	/// \param rc2Bounds	���ζ���Ķ�ά��Χ
	/// \param dMinZ		���ζ������С�߳�(������������������)
	/// \param dMaxZ		���ζ�������߳�(������������������)
	/// \sa	GetGeometry
	virtual UGbool GetGeometryBounds(UGRect2D &rc2Bounds,
		UGdouble& dMinZ,UGdouble& dMaxZ);

	/// \brief ͨ���ֶ����õ���ǰ��¼ָ���ֶε�ֵ
	/// \param strName		�ֶ�����
	/// \param varValue		�ֶε�ֵ
	/// \sa	SetFieldValue
	virtual UGbool GetFieldValue(const UGString& strName,
		UGVariant& varValue );

	/// \brief ͨ���ֶ�λ�������õ���ǰ��¼ָ���ֶε�ֵ
	/// \param nIndex		�ֶ�λ������
	/// \param varValue		�ֶε�ֵ
	/// \sa	SetFieldValue
	virtual UGbool GetFieldValue(UGint nIndex,
		UGVariant& varValue );

	/// \brief �޸ĵ�ǰ�ռ�����
	/// \param geometry		�µĿռ����ݵ�ָ��
	/// \sa	GetGeometry
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

	/// \brief ��ѯ��ǰ��¼��˭����(������)
	/// \return �������û�����
	/// \sa	CheckOut, CheckIn, UndoCheckOut
	virtual UGString GetRecordCheckedBy();

	//��¼����
	/// \brief	����ǰ�����ı༭�������µ����ݿ�
	/// \remark	��ҪUpdate�ı༭������
	/// @li	AddNew
	/// @li	SetFieldValue
	/// @li	SetGeometry
	/// \attention	Delete��DeleteAll��������ҪUpdate
	/// \sa	Edit, CancelUpdate, AddNew, SetFieldValue, SetGeometry, Delete, DeleteAll
	virtual UGint Update();
	
	
	/// \brief ˢ�µ�ǰ��¼������
	/// \attention	ֻ�в�ѯ����Ϊdynasetʱ�ſ��Ե��ô˷���
	/// \sa Refresh
	virtual void FlushCurrentRecord();

	UGint GetFieldBufferPos(const UGString& strFieldName, 
		UGint &nFieldIndex);


	/// \brief ����µļ�¼
	/// \param	[in]	pGeometry	Ҫ��ӵļ�¼�Ŀռ�����ָ��
	/// \return	�����ӳɹ��������¼�¼��ID, ���ʧ�ܣ�����-1
	/// \note	���Ҫ���Tabular��¼����pGeometry��ΪNULL����
	/// \attention	���ʧ�ܣ����ܵ���Update��CancelUpdate.
	virtual UGbool Delete();
	

	//״̬
	/// \brief �жϵ�ǰ��¼���Ƿ�֧�ֱ༭����
	/// \remarks ���¼������������༭��
	/// @li		���ݼ�ѡ��ΪReadOnly
	/// @li		������ѯʱ
	/// \sa Edit, AddNew, Update
	virtual UGbool CanUpdate();


	/// \brief �ж��Ƿ������ǰ��¼����׷���µļ�¼
	/// \remarks ���¼������������׷��:
	/// @li		���ݼ�ѡ��ΪReadOnly
	/// @li		������ѯʱ
	/// \sa Edit, AddNew, Update
	virtual UGbool CanAppend();

	
	/// \brief	ȡ����ǰ�����ı༭����
	/// \remark	����ȡ���ı༭�����У�
	/// @li	AddNew
	/// @li	SetFieldValue
	/// @li	SetGeometry
	/// \attention	Delete��DeleteAll��������CancelUpdate
	/// \sa	Edit, Update, AddNew, SetFieldValue, SetGeometry, Delete, DeleteAll
	virtual UGbool CancelUpdate();
	
	/// \brief	������ʼ�༭����
	/// \remark	���²�����Ҫ����Edit�����ִ��
	/// @li	AddNew
	/// @li	SetFieldValue
	/// @li	SetGeometry
	/// \attention	Delete��DeleteAll��������ҪEdit
	/// \sa	Update, CancelUpdate, AddNew, SetFieldValue, SetGeometry, Delete, DeleteAll
	virtual UGbool Edit();
	
	
	//! \brief 		��ͨ��ѯ�����������Բ�ѯ��������ѯ�����,�����Ĭ��ȫ����ѯ
	//! \return 	UGbool
	//! \param 		querydef
	//! \remarks 		
	virtual UGbool CreateWithGeneral(const UGQueryDef& querydef);

	/// \brief ����ָ���Ŀռ䷶Χ����Bounds���ƵĲ�ѯ
	/// \param [in]	querydef	��ѯ�����ں���ѯ�ĸ���������ѡ���
	/// \note	ֻ��querydef.m_nOptions == CSmQuerydef::Boundsʱ�Ż���ô˺���
	/// \sa CSmQuerydef, Create, CreteWithGeneral, CreateWithIDs, CreateWithSpatialQuery
	virtual UGbool CreateWithBounds(const UGRect2D& rc2Bounds, 
		UGint nOptions,UGint nMode);

	/// \brief ����ָ����ID������в�ѯ
	/// \param [in]	querydef	��ѯ�����ں���ѯ�ĸ���������ѡ���
	/// \note	ֻ��querydef.m_nOptions == CSmQuerydef::IDsʱ�Ż���ô˺���
	/// \sa CSmQuerydef, Create, CreteWithGeneral, CreateWithBounds, CreateWithSpatialQuery
	virtual UGbool CreateWithIDs(UGint *pIDs,UGint nCount,UGint nOptions,UGint nMode,UGString strFieldName,UGbool bRTree = FALSE);


private:
	UGString BuildGeneralSqlWithIDs();
	UGbool IsFieldModifyed(const UGString &strFieldName);
	UGint PrepareForUpdateWithLT(UGint nLogID);
	void RebindGeoBuffer();
	
	//! \brief AddNew֮�������õ��ֶ�ֵ��������������
	//! \param strName [in] �ֶ�����
	//! \param varVal [out] �ֶ�ֵ
	//! \return ��Ҫ˼·��Ҫ����AddNew֮���Ч����һ��AddNew��ô�α����AddNew��λ�á�
	UGbool GetAddNewFieldValue(const UGString& strName,UGVariant& varVal);

	void ReAllocGeoBuffer(UGint nRawSize);

	/// \brief �����񻷾��µ�Delete����
	/// \sa	Delete
	UGbool DeleteWithLT();

	UGbool DeleteWithDV();

	/// \brief ���ݹ���õ�SQL���ִ�е�һ�����ݶ�ȡ����
	/// \param [in]	strSQL ����õ�SQL���
	UGbool FetchData(const UGString & strSQL);
	
	UGbool FetchIDs();

	UGint X_UpdateDataVersion();

protected:	
	UGString m_strSetField;
	
	UGshort   m_nPrevEditMode;
	
	/// \brief ��ȡ����ʱ��DefineĿ��
	UGOCIBind m_OCIBind;
	
	UGArray<UGint> m_IDs;
	
	UGint m_nBufferSize;
	UGint m_nBufferGeoSize;
	UGint m_nCurrentID;
	UGint m_nCurrentDataIndex;
	UGint m_nCurrentGeoSize;
	
	UGOCICursor m_EditCursor;
	
	UGFieldInfos m_PrevModifiedFieldInfos;
	UGFieldInfos m_CurrentModifiedFieldInfos;
	UGOCIBinds m_PrevBindInfos;
	UGOCIBinds m_CurrentBindInfos;
	UGRect2D m_rc2New;
	UGRect2D m_rc2Old;

	/// \brief ��ǰ�α��еĿռ����
	// ������ Ϊ����ʱ�洢����༭���Ķ���Ŀǰ��ʱ����һ�ݣ���ֹ����ɾ����
	UGGeometry* m_pGeometry;

private:
	UGbyte * m_pEditAttrBuffer;
	UGbyte * m_pEditGeoBuffer;
	UGint m_nUpdateID;
	UGbool m_bReBind;



};

}

#endif

