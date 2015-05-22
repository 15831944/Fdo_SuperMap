// SmMemDataSource.h: interface for the UGMemDataSource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGMEMDATASOURCE_H)
#define UGMEMDATASOURCE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDataSource.h"

namespace UGC
{

extern "C" MEMENGINE_API UGDataSource* CreateDataSource();

class MEMENGINE_API UGMemDataSource : public UGDataSource  
{
public:
	UGMemDataSource();
	virtual ~UGMemDataSource();
	
	//! \brief ��������Դ,��ҪԤ�����ú�������Ϣ��
	/**
		����������ϸ������
	 	\return �����Ƿ�ɹ���������Դ���ɹ�����TRUE��ʧ�ܷ���FALSE��
	 	\remarks �ڴ�����Դ�Ĵ�����������Ĵ�������Դ��ֻ�Ǹı�������Դ��һЩ��ز�����
	*/
	virtual UGbool Create();

	//! \brief ������Դ,��ҪԤ�����ú�������Ϣ��
	/**
	����������ϸ������
		\return �����Ƿ�ɹ�������Դ���ɹ�����TRUE��ʧ�ܷ���FALSE��
		\remarks �ڴ�����Դ�Ĵ�����������Ĵ�����Դ��ֻ�Ǹı�������Դ��һЩ��ز�����
	*/
	virtual UGbool Open();

	//! \brief �ر�����Դ��
	/**
	����������ϸ������
		\remarks �ͷ�ȫ��Dataset,�����ڴ档
	*/
	virtual void Close();

	//! \brief ��ȡ������ʱ�䡣
	/**
	����������ϸ������
		\return ������ʱ�䡣
	*/
	virtual UGTime GetDateLastUpdated() const;

	//! \brief ��ȡ����ʱ�䡣
	/**
	����������ϸ������
		\return ����ʱ�䡣
	*/
	virtual UGTime GetDateCreated() const;

	//! \brief ����������Ϣ��
	/**
	����������ϸ������
		\return ���سɹ�TRUE��ʧ��FALSE��
		\remarks ��
	*/
	virtual UGbool SaveInfo();

	//! \brief �޸����롣
	/**
	����������ϸ������
		\param strNewPassword ϣ������Ϊ�����롣
		\return �����޸ĳɹ�TRUE��ʧ��FALSE��
	*/
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	//! \brief ͨ��DatasetVectorInfo�������ݼ���
	/**
	����������ϸ������
		\param vInfo ʧ�����ݼ���Ϣ��
		\return ʸ�����ݼ���ָ�롣
		\remarks ��
		\attention ��
		\sa ��
	*/
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);

	//! ͨ��DatasetRasterInfo�������ݼ�
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);

	//! ɾ�����ݼ�(ͨ������)
	virtual UGbool DeleteDataset(const UGString& strName);

	//! ����Դ�Ƿ����������
	virtual UGbool IsConnected();
	
	//! �����������ݿ�,��ˢ�����ݼ���
	virtual UGbool Connect();

public:
	virtual UGString GetEngineName() const; 
protected:
	virtual UGDataset * CopyDatasetLocal(UGDataset *pSrcDataset,
		const UGString &strDestDatasetName, 
		UGDataCodec::CodecType nCodeType = UGDataCodec::encNONE,
		UGbool bBuildIndxOrPyramid = FALSE);
};

}

#endif // !defined(UGMEMDATASOURCE_H)
