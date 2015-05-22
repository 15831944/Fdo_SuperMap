#ifndef UGDATASOURCE_H
#define UGDATASOURCE_H

/*!
   **************************************************************************************
    \file     UGDataSource.h
   **************************************************************************************
    \author   ���ܿ�
    \brief    ����Դ����Ļ��࣬���������е�����Դ����Ҫ�ӱ�������������ʵ�ֱ������� 
              ��Ĵ��麯����                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-04-26  ���ܿ�    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/



#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "UGDsConnection.h"
#include "Base/UGTime.h"
#include "ugeng.h"
#include "UGDataset.h"
#include "UGDatasetVectorInfo.h"
#include "UGDatasetRasterInfo.h"
#include "UGDatasetVector.h"
#include "UGDatasetRaster.h"
#include "UGEngDefs.h"
#include "UGTopoDataset.h"


namespace UGC {

//! \brief �洢�����ռ������Ϣ
struct UGWorkspaceInfo
{
	UGint nVersion;
	UGString strWorkspaceName;
	UGString strUser;
};


class UGMetadata;
class UGEngineProc;
//! ����Դ��
class ENGINE_API UGDataSource
{
public:
	//! ���캯��
	UGDataSource();

	//! ��������
	virtual ~UGDataSource();

	enum InvalidNameState
	{
		nsIsEmpty,			//����Ϊ��
		nsBeyondLimit,		//���ȳ���30���ֽ�
		nsInvalidChar,		//�зǷ��ַ�
		nsHasAgainName,		//������
		nsPrefixIsSM,		//ǰ�����ַ���"sm"
		nsPrefixError,		//��һ���ַ�Ϊ���ֻ��»���
		nsAgainsystemName	//��ϵͳ���Ƴ�ͻ
	};	//���ݼ��������ֶ�������������

public:

	//========================================================
	//! \brief 		��ȡ��ǰ����Դ���ڵ�Schema
	//! \return 	UGString
	UGString GetSchema() const;

	//! ��ȡ����Դ������Ϣ,����Ϊ��������,
	//! ���Կ��Ը�����������Ϣ
	UGDsConnection& GetConnectionInfo() {
		return m_Connection;
	}

	//! ִ��SQL��䣬��Ҫ���������ݿ⼶ִ�е����ݲ���
	virtual UGbool Execute(const UGString& strSQL) {
		return FALSE;
	}
	
	//! ��������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Create() =0;

	//! ������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Open() =0;

	//! ����Դ�Ƿ����������
	virtual UGbool IsConnected() =0;

	//! �����������ݿ�,��ˢ�����ݼ���
	virtual UGbool Connect() =0;

	//! �ر�����Դ
	virtual void Close() =0;
	
	//! �ж�����Դ�Ƿ��Ѿ���
	UGbool IsOpen() const{
		return m_bOpened;
	}

	//! ��ȡ������ʱ��
	virtual UGTime GetDateLastUpdated() const =0;

	//! ��ȡ����ʱ��
	virtual UGTime GetDateCreated() const =0;

	//! ����������Ϣ
	virtual UGbool SaveInfo() =0;

	//! �޸�����
	virtual UGbool ChangePassword(const UGString& strNewPassword) =0;

	//! ɾ�����ݼ�(ͨ������)
	virtual UGbool DeleteDataset(const UGString& strName) =0;

	//! ͨ��DatasetVectorInfo�������ݼ�
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo) =0;

	//! ͨ��DatasetVectorInfo�������ݼ�
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName) =0;
	//! ͨ��DatasetRasterInfo�������ݼ�
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo) =0;

	//! �������ݼ�,��Ҫ����CreateDatasetFrom�½����ݼ�strDestDatasetName
	virtual UGDataset* CopyDataset(UGDataset* pSrcDataset, 
		const UGString& strDestDatasetName,
		UGDataCodec::CodecType nCodeType = UGDataCodec::encNONE,
		UGbool bBuildIndexOrPyramid = FALSE);

	//! \brief �õ�Ԫ���ݿ�
	//! \return �ǿձ�ʾ֧��Ԫ���ݲ���
	//! \remarks 
	//! \attention 
	virtual UGMetadata * GetMetaData();	

	virtual UGEngineProc * GetEngineProc();
public:
	//! \brief �����ռ������ؽӿ�
	virtual UGbool SaveWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *pbyte,UGint nbyteSize);
	virtual UGbool LoadWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *&pbyte,UGint &nbyteSize);
	virtual UGbool GetWorkspaceInfo(UGDsConnection conn, UGArray<UGWorkspaceInfo> &wksInfos);
	virtual UGbool DeleteWorkspaceInfo(UGDsConnection conn, UGString strWksName);

	//�汾����
	virtual UGbool CreateDataVersion(UGString &strVersionName,UGString &strDescription);
	virtual UGbool DeleteDataVersion(UGString &strVersionName);	
	virtual UGbool SetCurrentVersion(UGString &strVersionName);	
	virtual UGbool SetCurrentVersion(UGint nVersionID);	
	virtual UGbool GetDataVersionInfos(UGArray<UGDataVersionInfo> &aryDataVersionInfos);

public:
	//! ��ȡ����(ͨ����ȡ������ϢҲ���Եõ�����)
	UGString GetPassword() const {
		return m_Connection.m_strPassword;
	}

	//! ��ȡ����Դ����
	UGString GetName() const ;

	//! ��ȡ��������
	UGEngineType GetEngineType() const{
		return m_Connection.m_nEngineType;
	}

	//! ��ȡ��������
	virtual UGString GetEngineName() const ;

	//! ����һ������Դ��Ŀǰû�е����ݼ�����
	virtual UGString GetUnoccupiedDatasetName(const UGString& strDatasetName);

	//! �ж����ݼ������Ƿ�Ϸ�
	virtual UGbool IsAvailableDatasetName(const UGString& strDatasetName,InvalidNameState& nState);

	virtual UGint GetVersion();

	UGbool IsModified();
	void SetModifiedFlag(UGbool bModified = TRUE);

	//========================================================
	//! \brief 		�ж�����Դ�Ƿ�Ϊֻ��
	//! \return 	UGbool
	UGbool IsReadOnly() const {
		return m_Connection.m_bReadOnly;
	}
	
	//========================================================
	//! \brief 		�ж�����Դ�Ƿ�Ϊ��ռ��ʽ��
	//! \return 	UGbool
	UGbool IsExclusive() const {
		return m_Connection.m_bExclusive;
	}
	
	//========================================================
	//! \brief 		�ж�����Դ�Ƿ�ʹ�������
	//! \return 	UGbool
	UGbool IsEncrypt() const {
		return m_Connection.m_bEncrypt;
	}

	//========================================================
	//! \brief 		�ж�����Դ�Ƿ����Զ�����
	//! \return 	UGbool
	UGbool IsAutoConnect() const {
		return m_Connection.m_bAutoConnect;
	}

	//========================================================
	//! \brief 		��������Դ���Զ�����ѡ��
	//! \return 	void
	//! \param 		bAutoConnect
	void SetAutoConnect(UGbool bAutoConnect) {
		m_Connection.m_bAutoConnect = bAutoConnect;
	}
	
	
	//========================================================
	//! \brief 		��ȡ����Դ�ı���
	//! \return 	UGString
	UGString GetAlias() const {
		return m_Connection.m_strAlias;
	}

	//========================================================
	//! \brief 		��������Դ�ı���
	//! \return 	void
	//! \param 		strAlias
	void SetAlias(const UGString& strAlias) {
		m_Connection.m_strAlias = strAlias;
	}
	
	//! �Ƿ���ִ��ĳЩ����������
	virtual UGbool HasAbility(UGEngAbility nAbility) const {
		return FALSE;
	}

	//! �Ƿ�֧���ض��Ĳ���
	virtual UGbool IsSupport(UGEngAction nAction) const {
		return FALSE;
	}

	virtual UGbool IsSupport(UGDataset::DatasetType nDtType) const;

	//! �������ݼ�����
	UGint GetDatasetCount() const {
		return m_Datasets.GetSize();
	}

	//! ͨ����ŷ������ݼ�ָ��
	UGDataset* GetDataset(UGint nIndex) const {		
		return m_Datasets[nIndex];
	}

	//! ����ָ�����Ƶ����ݼ�ָ��
	UGDataset* GetDataset(const UGString& strDatasetName) const;
	
	//========================================================
	//! \brief 		�жϴ�����ֶ���������Ƿ����
	//! \return 	UGbool
	//! \param 		strFieldOrTableName
	//! \param 		nInvalidStata
	UGbool IsValidFieldOrTableName(const UGString& strFieldOrTableName, UGint& nInvalidStata);

	//========================================================
	//! \brief 		��������Դ��ͶӰ��Ϣ
	//! \param 		UGPrjCoordSys ͶӰ��Ϣ
	void SetPrjCoordSys(const UGPrjCoordSys &PrjCoordSys);
	
	//========================================================
	//! \brief 		��ȡ����Դ��ͶӰ��Ϣ
	//! \return 	UGPrjCoordSys ��ȡ������ͶӰ��Ϣ
	const UGPrjCoordSys& GetPrjCoordSys();

	UGbool PJConvert( UGRefTranslator *pRefTranslator);		//ͶӰת��
	UGbool PJForward( UGPrjCoordSys *pPrjCoordSys );		//�������굽ͶӰ����
	UGbool PJInverse();										//ͶӰ���굽��������

	//!Recordset to Dataset
	UGDatasetVector * RecordsetToDataset(UGRecordset *pRecord,UGString strNewDatasetName);

	void SetDescription(UGString strDesc){m_strDescription = strDesc; SetModifiedFlag();};

	UGString GetDescription(){return m_strDescription;};

	UGint GetDataversionID(){return m_nDataVersionID;};

	//! ͨ��Template�������ݼ�
	virtual UGDataset* CreateDatasetFrom(const UGString &strNewName,
		UGDataset * pReferenceDataset,UGDataCodec::CodecType nType);
	
	//! ��ʼ����
	virtual UGbool BeginTrans() {
		return FALSE;
	}

	//! �ύ����
	virtual void Commit() {}

	//! ��������
	virtual void Rollback() {}

	//! �ж������Ƿ�ʼ 
	UGbool IsTransStarted() const {
		return m_bTransStarted;
	}
	//========================================================
	//! \brief 		�ж�����Դ�Ƿ�֧�ֶ��������
	//! \return 	UGbool
	UGbool IsTransacted() const {
		return m_Connection.m_bTransacted;
	}

	//! UndoCheckOut
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut) {
		return FALSE;
	}

	//! CheckIn
	virtual UGbool CheckIn(UGbool bKeepCheckedOut) {
		return FALSE;
	}

	//! CheckOut
	virtual UGbool CheckOut() {
		return FALSE;
	}

	//! Login
	virtual UGbool Login(const UGString& strName,
		const UGString& strPassword) {
		return FALSE;
	}

	//! �ж��Ƿ��Ѿ���¼
	virtual UGbool IsLogged() const {
		return m_bLoged;
	}

	//! �˳�
	virtual void LogOff() {
		m_bLoged = FALSE;
	}
		
	//========================================================
	//! \brief 		�ж�����Դ�Ƿ����Զ�CheckOutѡ��
	//! \return 	UGbool
	UGbool IsAutoCheckOut() const;

	//========================================================
	//! \brief 		��������Դ���Զ�CheckOutѡ��
	//! \return 	void
	//! \param 		bAutoCheckOut
	void SetAutoCheckOut(UGbool bAutoCheckOut);

	//! \brief �õ�����ϵͳ�������л��ֶ��е����ֵ added by yanmb 2007.06.07
	virtual UGint GetMaxTableID(){
		return -100000;
	}
	virtual UGint GetFieldMaxValue(const UGString &strTableName, const UGString &strFieldName){
		return -100000;
	}

protected:	
	//! \brief ͬ���渴��
	virtual UGDataset * CopyDatasetLocal(UGDataset *pSrcDataset,
		const UGString &strDestDatasetName, 
		UGDataCodec::CodecType nCodeType = UGDataCodec::encNONE,
		UGbool bBuildIndxOrPyramid = FALSE);

protected:
	//! ������Ϣ
	UGDsConnection m_Connection;
	//! �ж��Ƿ��
	UGbool m_bOpened;	

	UGArray<UGDataset*> m_Datasets;
	//std::vector<UGint> m_IArray;
	//! \brief 		����Դ��ͶӰ��Ϣ
	UGPrjCoordSys m_PrjCoordSys;

	//���ݵ����汾
	UGint m_nVersion;
	//���ݵ�С�汾
	UGint m_nMinorVersion;
	//VersionDate
	UGint m_nVersionDate;

	//! ������Ϣ
	UGString m_strDescription;
	//! �Ƿ����
	UGbool m_bModified;

	//! ��ǰ�汾ID
	UGint m_nDataVersionID;
	
	//! �ж��Ƿ��Զ�CheckOut
	UGbool m_bAutoCheckOut;
	
		//! �����Ƿ�����
	UGbool m_bTransStarted;
	
		//! �ж��Ƿ��Ѿ���½������
	UGbool m_bLoged;
};

}

#endif

