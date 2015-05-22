/*! \file	 UGUdbDataSource.h
 *  \brief	 Oracle Plus DataSource
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGUdbDataSource.h,v 1.12 2007/12/17 11:19:40 liwl Exp $
 */


#ifndef UGUdbDataSource_H
#define UGUdbDataSource_H

#include "Engine/UGDataSource.h"
#include "UdbEngine/UGUdbDatasetVector.h"
#include "Base/UGTime.h"
#include "UdbEngine/UGUdbRecordset.h"
#include "CppSQLite3.h"

namespace UGC {	

class UDBENGINE_API UGUdbDataSource : public UGDataSource
{
	friend class UGUdbDatasetVector;
	friend class UGUdbDatasetRaster;
	friend class UGUdbEditRecordset;
	friend class UGUdbRecordset;

public:
	UGTime GetCurServerTime();
	UGUdbDataSource();
	virtual ~UGUdbDataSource();	

	//��������Ϣ
	void CheckError() const;
	
	//! ִ��SQL��䣬��Ҫ���������ݿ⼶ִ�е����ݲ���
	virtual UGbool Execute(const UGString& strSQL);
	
	//! ��������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Create();
	
	//! ������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Open();

	//! �ر�����Դ
	virtual void Close();
		
	//! ��ȡ������ʱ��
	virtual UGTime GetDateLastUpdated() const ;

	//! ��ȡ����ʱ��
	virtual UGTime GetDateCreated() const ;

	//! ����������Ϣ
	virtual UGbool SaveInfo();

	//! �޸�����
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	//! ��ʼ����
	virtual UGbool BeginTrans();

	//! �ύ����
	virtual void Commit();

	//! ��������
	virtual void Rollback();

	//! �Ƿ���ִ��ĳЩ����������
	virtual UGbool HasAbility(UGEngAbility nAbility) const ;

	//! �Ƿ�֧���ض��Ĳ���
	virtual UGbool IsSupport(UGEngAction nAction) const ;

	//! ͨ��DatasetVectorInfo�������ݼ�
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);

	//! ͨ��DatasetVectorInfo�������ݼ�
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);

	//! ͨ��DatasetRasterInfo�������ݼ�
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);

	//! ɾ�����ݼ�(ͨ������)
	virtual UGbool DeleteDataset(const UGString& strName);
	
	//! UndoCheckOut
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

	//! CheckIn
	virtual UGbool CheckIn(UGbool bKeepCheckedOut) ;

	//! CheckOut
	virtual UGbool CheckOut() ;

	//! Login
	virtual UGbool Login(const UGString& strName,
		const UGString& strPassword);

	virtual void LogOff() ;

	//! �ж��Ƿ��Ѿ���¼
	virtual UGbool IsLogged() const {
		return m_bLoged;
	}

	virtual UGMetadata * GetMetaData();
	
	//! ����Դ�Ƿ����������
	virtual UGbool IsConnected();
			
	//! �����������ݿ�,��ˢ�����ݼ���
	virtual UGbool Connect();

	virtual UGbool IsSupport(UGDataset::DatasetType nDtType) const;

	CppSQLite3DB m_db;
private:
	UGbool X_SetDataSourceInfo(UGbool bAddNew = FALSE);
	UGbool X_ReadInfo();

	UGbool m_bConnected;	
	UGString m_strSchema;
};

extern "C" UDBENGINE_API UGDataSource* CreateDataSource();

}

#endif
