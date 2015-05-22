/*! \file	 UGOrcDataSource.h
 *  \brief	 Oracle Plus DataSource
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOrcDataSource.h,v 1.22 2007/12/27 03:15:27 liwl Exp $
 */


#ifndef UGORCDATASOURCE_H
#define UGORCDATASOURCE_H

#include "Engine/UGDataSource.h"
#include "OrcEngine/UGOCIConnection.h"
#include "OrcEngine/UGCursorDataException.h"
#include "OrcEngine/UGCursorGeneralException.h"
#include "OrcEngine/UGOrcDatasetVector.h"
#include "Base/UGTime.h"
#include "OrcEngine/UGOrcRecordset.h"


namespace UGC {

class ORCENGINE_API UGOrcDataSource : public UGDataSource
{
	friend class UGOrcDatasetVector;
public:
	UGOrcDataSource();
	virtual ~UGOrcDataSource();	

	//���OCI������Ϣ
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

	//! ͨ��DatasetVectorInfo����Topo���ݼ�
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

	virtual UGEngineProc * GetEngineProc();

	//! ����Դ�Ƿ����������
	virtual UGbool IsConnected();

	//! �����������ݿ�,��ˢ�����ݼ���
	virtual UGbool Connect();

	//! \brief �����ռ������ؽӿ�
	virtual UGbool SaveWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *pbyte,UGint nbyteSize);
	virtual UGbool LoadWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *&pbyte,UGint &nbyteSize);
	virtual UGbool GetWorkspaceInfo(UGDsConnection conn, UGArray<UGWorkspaceInfo> &wksInfos);
	virtual UGbool DeleteWorkspaceInfo(UGDsConnection conn, UGString strWksName);

	//�汾����
	UGbool CreateDataVersion(UGString &strVersionName,UGString &strDescription);
	UGbool DeleteDataVersion(UGString &strVersionName);	
	UGbool SetCurrentVersion(UGString &strVersionName);	
	UGbool SetCurrentVersion(UGint nVersionID);	
	UGbool GetDataVersionInfos(UGArray<UGDataVersionInfo> &aryDataVersionInfos);	

public:
	UGTime GetCurServerTime();

	UGint GetLoggedUserID() {	
		if(!m_bLoged) return 0;
		return m_nLogID;
	}
	
	UGOCIConnection* GetConnection() const {
		return m_pConnection;
	}

	UGshort GetFreeTempTableID();

	void SetTempTableEngrossedFlag(UGint nTempTableID, 
					UGbool bEngrossed = TRUE);

	//�õ���Ч�ı���
	UGString ReviseTableName(UGString &strName);
protected:
	//! \brief ͬ���渴��
	virtual UGDataset * CopyDatasetLocal(UGDataset *pSrcDataset,
			const UGString &strDestDatasetName, 
			UGDataCodec::CodecType nCodeType = UGDataCodec::encNONE,
			UGbool bBuildIndxOrPyramid = FALSE);

private:
	UGbool Connect(const UGString& strServer, const UGString& strUser,const UGString& strPass,
		const UGint nMinConn, const UGint nMaxConn, const UGint nIncConn);

	UGbool OpenRegister50();
	UGbool OpenRegister51();
	UGbool OpenImgRegister50();
	UGbool OpenImgRegister51();

public:
	//! ��ǰ�û���ID
	UGint m_nUserID;

private:
	UGbool SetDataSourceInfo();
	UGbool ReadInfo();

	//��DeleteDataset()�е���
	UGbool DeleteSubDataset(UGDatasetVector *pDataset);
	UGbool U_UpdatetoUGC();
	UGOCIConnection* m_pConnection;
		
	//! �������û���ID
	UGint m_nLogID;
	
	UGbool m_bConnected;
	UGString m_strLoginName;

	UGuchar m_TempTableIDs[32];
};

extern "C" void CheckDataError(UGCursorDataException *e);
extern "C" void CheckGeneralError(UGCursorGeneralException *e);

extern "C" ORCENGINE_API UGDataSource* CreateDataSource();

}

#endif
