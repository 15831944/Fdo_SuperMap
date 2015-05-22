//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWebServiceParse.h
//!  \brief UGWebServiceParse �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWEBSERVICEPARSE_H
#define UGWEBSERVICEPARSE_H

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Engine/UGDataset.h"

#define DEFAULT_CRS_NAME	"EPSG:4326"
#define DEFAULT_SRS_NAME	"EPSG:4326"

namespace UGC{

class UGWebDataSource;
class UGWebLayersInfo;

//! \brief ��������Դ�Ľ������ࡣ
class WEBENGINE_API UGWebServiceParser  
{
public:
	UGWebServiceParser();
	UGWebServiceParser(const UGString& strParseFilePath);
	
	virtual ~UGWebServiceParser();
	
public:
	
	//! \brief �����������ݷ�������������
	//! \param Layers ͼ����Ϣ����[out]��
	//! \param strVersion ��������Դ�汾[out]��
	//! \param strFormats ������֧�ֵ�ͼƬ��ʽ[out]��
	//! \param strMap Title����[out]��
	//! \param aryCRS ����ο�ϵ����[out]��
	//! \return �Ƿ�����ɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool ParseCapabilities(UGWebLayersInfo& Layers,
		UGString& strVersion,
		UGArray<UGString>& strFormats,
		UGString& strMap,
		UGArray<UGString>& aryCRS) = 0;
	
	//! \brief ����ͼ����Ϣ����ͼ�㡣
	//! \param Datasets ������ͼ�㼯��[out]��
	//! \param Lys �����õ���ͼ����Ϣ[in]��
	//! \param strMap ���ͼ��ϲ�Ϊһ��ͼ��ʱ��ͼ����[in]��
	//! \return �Ƿ񴴽��ɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool CreateLayer(UGDatasets& Datasets,
		const UGWebLayersInfo& Lys,
		const UGString& strMap) = 0;
	
public:
	//! \brief ���ý����ļ���·����
	//! \param strParseFilePath �����ļ���·��[in]��
	void SetParseFilePath(const UGString& strParseFilePath);
	
	//! \brief �õ������ļ���·����
	//! \return �����ļ���·������
	UGString GetParseFilePath();
	
	//! \brief ���ý��������õ�����Դ��
	//! \param pDs ����Դָ��[in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool SetServerPtr(UGWebDataSource* pDs);
	
	
	//! \brief ͨ������URL������������Ϣ��
	//! \param strConn ����URL�ַ���[in]��
	//! \param &strHost ��������IP��ַ[out]��
	//! \param &strPath �������ݷ��������Web�������������·����[out]��
	//! \param &strService �������ݷ�������[out]��
	//! \param &strMapName ��������Դ��ͼ����,�Ǳ�׼,SuperMap����[out]��
	//! \param &strVersion ��������ִ�й淶�İ汾��[out]��
	//! \param &nPort �˿ں�[out]��
	//! \return �Ƿ�����ɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
	UGbool ParseServerInfo(UGString strConn,
		UGString &strHost,			
		UGString &strPath,			
		UGString &strService,		
		UGString &strMapName,		
		UGString &strVersion,
		UGushort &nPort);		
	
	
protected:
	//! \brief Ҫ�����ļ���·����
	UGString m_strParseFile;
	
	//! \brief ����Դָ�롣
	UGWebDataSource* m_pDs;
	
};
	
}
#endif // !defined(UGWEBSERVICEPARSE_H)
