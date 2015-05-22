/*! \file	 UGRecordset.h
 *  \brief	 ��¼���ඨ���ļ�
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRecordset.h,v 1.11 2007/11/07 03:15:50 liwl Exp $
 */

#ifndef UGRECORDSET_H
#define UGRECORDSET_H

#include "Algorithm/UGRect2D.h"
#include "UGQueryDef.h"
#include "ugeng.h"
#include "Base/UGVariant.h"
#include "Base/UGString.h"
#include "Geometry/UGGeometry.h"
#include "UGFieldInfo.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRectUInt.h"
#include "Geometry/UGGeoCompound.h"
#include "UGTableRecordset.h"

namespace UGC {

class UGDatasetVector;

//! ��¼����
class ENGINE_API UGRecordset :public UGTableRecordset
{
public:
	//! �༭ģʽ
	enum EditMode {
		EditNone			= 0x00000000, //! δ���κα༭
		EditAdd				= 0x00000001, //! ��ִ�й�AddNew����
		EditInProgress		= 0x00000002, //! ���ڱ༭
		EditSetFieldValue	= 0x00000004, //! �Ѹ����������� 
		EditSetGeometry		= 0x00000008, //! ��ִ�й�SetGeometry����
		EditDeleted			= 0x00000010  //! ��ɾ����¼
	};
	
public:
	//! ���캯��
	UGRecordset();
	//! ��������
	virtual ~UGRecordset();
public:
	//! ��ȡ��¼����Ӧ�����ݼ�
	UGDatasetVector* GetDataset() const {
		return m_pDataset;
	}
	
	//! �ж��Ƿ�����������
	UGbool HasDBInfo() {
		return (m_QueryDef.m_nOptions & UGQueryDef::Attribute);
	}

	//! �ж��Ƿ��м�������
	UGbool HasGeometry() {
		return (m_QueryDef.m_nOptions & UGQueryDef::Geometry);
	}
	
	//! ɾ�����м�¼
	virtual UGbool DeleteAll() =0;

	//! ��ĳ��ͳ�Ʒ���ͳ��ĳ���ֶ�
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode) =0;

	//! ˢ�¼�¼��,һ��������²�ѯһ��
	virtual UGbool Refresh() =0;

	//! �����ֶ�ֵ,strSrcField��
	//! strDestField���붼�������ֶ�����ƥ��
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField) =0;
	
	//! ��ȡ��ǰ��¼��ID
	virtual UGint GetID() = 0;

	//! ֱ�Ӷ������ζ����ָ��,���ڰ��������ݶ������ڴ��е�����(��dgn)��˵��
	//! ����Ҫ�������ζ�������Ҳ��Ҫȥɾ����,�������Լӿ�����ٶ�
	virtual UGbool GetGeometryDirect(UGGeometry*& pGeometry) =0;

	//! ȡ�ü��ζ��󣬷��صļ��ζ���ָ���ں����ڷ����ڴ棬
	//! ���渺��ɾ������������ڴ�й©
	virtual UGbool GetGeometry(UGGeometry*& pGeometry) =0;

	//! ȡ�ü��ζ������άBounds
	UGbool GetGeometryBounds(UGRect2D &rc2Bounds,
		double& dMinZ,double& dMaxZ) {
		UGGeometry* pGeometry = NULL;
		GetGeometry(pGeometry);
		if(pGeometry) {
			rc2Bounds = pGeometry->GetBounds();
			delete pGeometry;
			return TRUE;
		}
		return FALSE;
	}

	//! ���õ�ǰ��¼�ļ��ζ���
	virtual UGbool SetGeometry(UGGeometry &geometry) =0;

	UGbool IsEmpty();

	//! ͨ��ID��λ��¼ָ��
	virtual UGbool SeekID(UGint nID) =0;

	//! ���£��ύ�޸�
	virtual UGint Update() =0;

	//! ȡ���޸�
	virtual UGbool CancelUpdate() =0;
	
	//! ��ʼ�޸�����
	virtual UGbool Edit() =0;

	//! ��ȡ��ǰ�༭ģʽ
	EditMode GetEditMode() const {
		return m_nEditMode;
	}
	
	//! \brief �����¼�¼,�ɹ�������TRUEֵ��ʧ�ܷ���FALSEֵ��
	//! \param *pGeometry [in] ��ӵ�Geometryָ��
	//! \param bReturnID=FALSE [in] �˲����Ѿ��������á�
	//! \return True �� False ��ֵ
	//! \remarks �����õ��¶����ID����ô���ϵ���GetId����
	virtual UGint AddNew(UGGeometry *pGeometry,
		UGbool bReturnID=FALSE) =0;

	//! ɾ����ǰ��¼
	virtual UGbool Delete() =0;

	//! ˢ�¼�¼
	virtual void FlushCurrentRecord() =0;
	
	//! �Ƿ�֧������
	virtual UGbool CanTransact() const =0;

	//! �Ƿ�ɸ���
	virtual UGbool CanUpdate() =0;	

	//! �Ƿ�����
	virtual UGbool CanAppend() =0;

	//! �Ƿ�֧��ָ���Ĳ���
	virtual UGbool IsSupport(UGEngAction nAction) =0;

	//! �����¼���ķ�Χ
	virtual UGbool ComputeBounds(UGRect2D &rc2Bounds,
		UGdouble &dMinZ,UGdouble &dMaxZ) =0;

	//! ��Boundsȡ��
	virtual UGbool GetUIntRectBounds(UGRectUInt& rcUIntRect);

	//! ���ò�ѯ����
	void SetQueryDef(const UGQueryDef& querydef) {
		m_QueryDef = querydef;
	}

	//! ��ȡ��ѯ����
	void GetQueryDef(UGQueryDef & querydef) const
	{
		querydef = m_QueryDef;
	}

	UGQueryDef::QueryOption GetOptions() const
	{
		return m_QueryDef.m_nOptions;
	}

	//���Ҫ�ӽ��������������Ƿ�Ϸ�
	UGbool IsGeometryTypeValid(UGGeometry::Type& geoType);

	//! \brief ����XML��ʽ����Ϣ
	UGString ToXML(UGGeometry::GMLVersionType versionType, UGint nPace = 0);
	
	//! \brief ��XML�ַ���������Geometry
	UGbool FromXML(const UGString& strXML,UGGeometry::GMLVersionType versionType);

#if PACKAGE_TYPE==PACKAGE_UGC
	
	//! �ǳ�����״̬�µ�����
	virtual UGbool Lock() =0;

	//! �ǳ�����״̬�µĽ���
	virtual UGbool UnLock() =0;
	
	//! �õ���ǰ��¼��˭��������
	virtual UGString GetRecordCheckedBy() = 0;

	virtual UGbool UndoCheckOutCurrent(UGbool bKeepCheckedOut) =0;	
	virtual UGbool CheckInCurrent(UGbool bKeepCheckedOut) =0;
	virtual UGbool CheckOutCurrent() =0;
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut) =0;
	virtual UGbool CheckIn(UGbool bKeepCheckedOut) =0;
	virtual UGbool CheckOut() =0;

#endif // end declare ugc sdk
protected:	
	//! ��¼����Ӧ�����ݼ�
	UGDatasetVector* m_pDataset;

	//! ��ǰ�༭ģʽ
	/// \brief ��ǰ�༭״̬
	/// @li	0 -- EditNone			δ���κα༭
	/// @li	1 -- EditInProgress		���ڱ༭
	/// @li	2 -- EditAdd			��ִ�й�AddNew����
	/// @li	3 -- EditOfGeometry		��ִ�й�SetGeometry����
	EditMode m_nEditMode;
public:
	//! ��ѯ����
	UGQueryDef m_QueryDef;
};

//! ��¼��������
class ENGINE_API UGRecordsets : public UGArray<UGRecordset*>
{
public:
	//! ������еļ�¼��(�ͷ�Recordsetָ��)
	void ReleaseAll();
};

}

#endif


