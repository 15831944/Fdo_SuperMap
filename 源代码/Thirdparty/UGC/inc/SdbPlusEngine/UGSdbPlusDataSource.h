// SmDataSource.h: interface for the UGSdbPlusDataSource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDBDATASOURCEPlus_H__F53EF3A0_08FE_11D3_92D1_0080C8EE62D1__INCLUDED_)
#define AFX_SDBDATASOURCEPlus_H__F53EF3A0_08FE_11D3_92D1_0080C8EE62D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/UGTime.h"
#include "CompoundFile/UGFileLogical.h"
#include "CompoundFile/UGFolder.h"
#include "CompoundFile/UGStorehouse.h"
#include "Engine/UGDataSource.h"

#include "UGSdbDataSourceInfo.h"
#include "UGSdbPlusDatasetVector.h"
#include "UGSdbPlusRecordset.h"


namespace UGC{

class UGSdbPlusDatasetRaster;
class UGSdbPlusDatasetVector;


class SDBPLUSENGINE_API UGSdbPlusDataSource : public UGDataSource  
{
	friend class UGSdbPlusDatasetVector;
	friend class UGSdbPlusDatasetRaster;
	friend class UGSdbPlusRecordset;

public://constructors
	UGSdbPlusDataSource();
	virtual ~UGSdbPlusDataSource();

public:	

	//����Դ�������򿪡��ر�
	//! ��������Դ,��ҪԤ�����ú�������Ϣ
	UGbool Create();

	//! ������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Open();

	//! �ر�����Դ
	virtual void Close();

	/*
	UGbool Create(const UGString &strDataSourceName, UGuint dwOptions = smdsExclusive, const UGString& strPassword = (""));	//for more information about "dwOptions", see above...
	UGbool Open(const UGString &strDataSourceName, UGuint dwOptions = smdsExclusive, const UGString& strPassword = (""));	//for more information about "dwOptions", see above...
	UGbool Open(const UGString &strDataSourceName,
				UGbool bReadOnly = FALSE,
				UGbool bExclusive = TRUE,
				UGbool bTransacted = FALSE,
				UGbool bEncrypt = FALSE,
				const UGString& strPassword = (""));

	virtual UGbool Open(UGDsConnection *pDsConnection = NULL);

	void Close();
	*/

	UGbool SaveInfo();

	//����Դ����
	UGString GetEngineName();			//�������ƣ���ʹ���ַ�����Դ
	UGTime GetDateLastUpdated() const;	//����������ʱ��
	UGTime GetDateCreated() const;		//���ش���ʱ��

	//! ִ��SQL��䣬��Ҫ���������ݿ⼶ִ�е����ݲ���
	UGbool Execute(const UGString& strSQL);

	UGDatasetVector* CreateDatasetVector(const UGDatasetVectorInfo& vInfo);

	UGDatasetTopo* CreateDatasetTopo(UGString strName);

	//����դ��ͼ��
	UGDatasetRaster* CreateDatasetRaster(const UGDatasetRasterInfo& rInfo);

	//���ݼ�ɾ��
	UGbool DeleteDataset(const UGString& strName);

/*	//Ԫ������������
	UGString GetDescription();									//����Ԫ��������
	void ResetDescription();									//���ԭ�е�Ԫ��������
	void SetDescription(UGString &strDesc);			//׷��Ԫ���������ַ��������е�Ԫ���������ַ�������
*/

	//����ݽ��ͳ���,SDB5.0�Ȳ��ṩ�������ܡ�
	UGbool BeginTrans();		
	void Commit();
	void Rollback();

	/// \brief Is the file a SDB 5.0 File?
	/// \param strPathName, the file path name.
	/// \return TRUE if the file is a SDB 5.0 file.
	static UGbool IsSdb5File(const UGString& strPathName);

	//! ����Դ�Ƿ����������
	virtual UGbool IsConnected();

	//! �����������ݿ�,��ˢ�����ݼ���
	virtual UGbool Connect();

	virtual UGbool IsSupport(UGDataset::DatasetType nDtType) const;
public: // methods
	void SetLogLevel(int nLevel);
	int GetLogLevel();
	UGbool WriteLog(UGString &strDatasource,UGString &strdataset,UGString& strActionCode,int nReturnCode,UGString& strActionDesc);
	
	UGbool QueryMetaData(const CStringList& listValue,CStringList &listResult,const int nOption=0);

	UGbool Query(UGQueryDef& QueryDef,UGString& strNewDtName);
	
	virtual UGbool Compact(UGbool bShowProgress=TRUE);
	virtual UGbool CompactDatabase( LPCTSTR lpszSrcName, LPCTSTR lpszDestName, LPCTSTR lpszLocale, int nOptions, LPCTSTR lpszPassword);
	virtual UGbool CompactDatabase( LPCTSTR lpszSrcName, LPCTSTR lpszDestName, LPCTSTR lpszLocale = dbLangGeneral, int nOptions = 0 );
	virtual	UGbool RepairDatabase( LPCTSTR lpszName,UGString strPassword =(""));  //�޸����ݿ� 
	virtual UGbool IsSupport(UGEngAction dwEngAction);	//�Ƿ�֧��ָ���Ĳ���(�˴����õĲ�����BeginTrans/CommitTrans/Rollback/LoginLongTrans/LogoutLongTrans)

	UGbool HasPassword(const UGString &strDataSourceName);
	UGbool ChangePassword(const UGString& strNewPassword);

public:
	
	virtual UGMetadata* GetMetaData();

protected://attributes
	
	CDaoDatabase	m_FileSDD;		//Access mdb file
	UGStorehouse m_FileSDB;		//SSS file

	UGFolder *m_pFolderDatasets; //Datasets Folder
	UGFolder *m_pFolderInfo;		// Info Folder
	UGFileLogical *m_pFileInfo;		//Info file in Info Folder
	UGFileLogical *m_pFileProj;		//Projection file  in Info Folder

	UGSdbDataSourceInfo m_DataSourceInfo;

protected:

	UGbool RepairDatasetRaster(UGSdbPlusDatasetRaster *pDatasetRaster);
	UGbool RepairDatasetVector(UGSdbPlusDatasetVector *pDatasetVector);

	//���
	UGbool FillDatasets();
	UGbool ReadDatasetInfo(UGSdbPlusDatasetVector* pDatasetVector);
	
	//����ת��
//	UGuint SmOptToSdbOpt(UGuint dwOptions);	//Supermap => SSS file
//	void SmOptToMdbOpt(UGuint dwOptions,UGbool &bExclusive, UGbool &bReadOnly);	//Supermap => MDB

	UGbool CopyZippedRasterLocal(UGDatasetRaster* pSrcDataset,UGDatasetRaster* pDestDataset);

	//���ظ������ݼ�strSrcDatasetName����ǰ����Դ��ΪstrDestDatasetName�����ݼ���
	virtual UGDataset * CopyDatasetLocal(UGDataset *pSrcDataset,
		const UGString &strDestDatasetName, 
		UGDataCodec::CodecType nCodeType = UGDataCodec::encNONE,
		UGbool bBuildIndxOrPyramid = FALSE);


};

extern "C" SDBPLUSENGINE_API UGDataSource* CreateDataSource();

//extern "C" ORCENGINE_API void StartupDao360();
// added by zengzm 2005-9-12 ���Թر� Dao36
extern "C" SDBPLUSENGINE_API void BeforeSdxUnload();

}

#endif // !defined(AFX_SDBATASOURCEPlus_H__F53EF3A0_08FE_11D3_92D1_0080C8EE62D1__INCLUDED_)

