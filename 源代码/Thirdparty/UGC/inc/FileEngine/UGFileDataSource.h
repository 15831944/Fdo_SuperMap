
/*!
    **************************************************************************************
     \file     UGFileDataSource.h
    **************************************************************************************
     \author   ����
     \project  FileEngine
     \brief    �ļ�����������Դ
     \remarks                                                                         <br>
    ----------------------------------------------------------------------------------<br>
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/

#if !defined(UGMEMDATASOURCE_H)
#define UGMEMDATASOURCE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDataSource.h"
#include "Engine/UGDataSource.h"
#include "DataExchange/UGImportParams.h"

namespace UGC
{

class FILEENGINE_API UGFileDataSource : public UGDataSource  
{
public:
	UGFileDataSource();
	virtual ~UGFileDataSource();

	//! ��������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Create();

	//! ������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Open();

	//! �ر�����Դ
	virtual void Close();

	//! ��ȡ������ʱ��
	virtual UGTime GetDateLastUpdated() const;

	//! ��ȡ����ʱ��
	virtual UGTime GetDateCreated() const;

	//! ����������Ϣ
	virtual UGbool SaveInfo();

	//! ɾ�����ݼ�(ͨ������)
	virtual UGbool DeleteDataset(const UGString& strName);

	//! �޸�����
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	//! ͨ��DatasetVectorInfo�������ݼ�
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);

	//! ͨ��DatasetVectorInfo�������ݼ�
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);

	//! ͨ��DatasetRasterInfo�������ݼ�
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);

	virtual UGMetadata* GetMetaData();

	//! ����Դ�Ƿ����������
	virtual UGbool IsConnected();
	
	//! �����������ݿ�,��ˢ�����ݼ���
	virtual UGbool Connect();

	//! brief ����Ĭ�ϵĲ���
	void AttatchParams(UGImportParams importParams);

public:
	virtual UGString GetEngineName() const; 

private:
	//! brief ����m_Connection�еĲ��� ���ⲿ�ļ�����
	UGbool Connect(const UGString& strServer, const UGString& strFileName);

	//! \brief �����ļ��� (UGDsConnection �� m_strServer) ��������Դ����
	void MakeCacheName();

	//! \brief �������Դ
	UGbool FillDataSource();

	//! brief ��MasterFile
	UGbool InitMasterFile();

	//! \brief ����xml
	void UpdateMasterFile();

	//! brief ����һ��xml�ļ�
	UGbool CreateMasterFile();

	//! brief ���� ��Ӧ�� Cache �Ƿ����
	UGbool IsCacheExist();

	//! brief �õ�һ��Ψһ��Cache��
	UGString GetUnOccupiedCacheName(UGString strCacheFileName);
	//! biief ��֤ Cache�Ƿ�Ψһ
	UGbool IsUnOccupiedCacheName(UGString strCacheFileName);


private:
	UGImportParams m_importParams;

	UGDataSource *m_pFileDataSource;

	//! \brief xml�ļ���������·����
	UGString m_strMasterFileName;
	
	//! \brief ��Ҫ�򿪵��ļ���������·����
	UGString m_strSourceFileName;

	//! \brief Cache�ļ���������·����
	UGString m_strCacheName;
};

extern "C" FILEENGINE_API UGDataSource* CreateDataSource();

}

#endif // !defined(UGMEMDATASOURCE_H)
