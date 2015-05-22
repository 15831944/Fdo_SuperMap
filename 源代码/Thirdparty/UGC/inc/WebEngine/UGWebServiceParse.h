//////////////////////////////////////////////////////////////////////////
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


namespace UGC{
	
	class UGWebDataSource;
	class UGWebLayerInfos;
	
	class WEBENGINE_API UGWebServiceParse  
	{
	public:
		UGWebServiceParse();
		UGWebServiceParse(const UGString& strParseFilePath);
		
		virtual ~UGWebServiceParse();
		
	public:
		
		//! \brief ����ͼ��������
		//! \param Layers ͼ����Ϣ����[out]��
		//! \param strVersion ��������Դ�汾[out]��
		//! \param strFormats ������֧�ֵ�ͼƬ��ʽ�б�[out]��
		//! \param strMap û����[out]��
		//! \param strSRS �ռ�ο�ϵ[out]��
		//! \return �Ƿ�����ɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
		virtual UGbool ParseCapabilities(UGWebLayerInfos& Layers,
			UGString& strVersion,
			UGArray<UGString>& strFormats,
			UGString& strMap,
			UGArray<UGString>& arySRS) = 0;
		
		//! \brief ����ͼ����Ϣ����ͼ�㡣
		//! \param Datasets ������ͼ�㼯��[out]��
		//! \param Lys �����õ���ͼ����Ϣ[in]��
		//! \param strMap ���ͼ��ϲ�Ϊһ��ͼ��ʱ��ͼ����[in]��
		//! \return �Ƿ񴴽��ɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
		virtual UGbool CreateLayer(UGDatasets& Datasets,
			const UGWebLayerInfos& Lys,
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
		
		//! \brief ���������ַ�����
		//! \param strConn �����ַ���[in]��
		//! \param &strHttpServer [out]��
		//! \param &strServerPage [out]��
		//! \param &strDataBase [out]��
		//! \param &strServerName [out]��
		//! \param &strVersion [out]��
		//! \param &nPort [out]��
		//! \return �Ƿ�����ɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
		UGbool ParseServerInfo(UGString strConn,
			UGString &strHttpServer,
			UGString &strServerPage,
			UGString &strDataBase,
			UGString &strServerName,
			UGString &strVersion,
			UGlong &nPort);
		
		
	protected:
	//! \brief Ҫ�����ļ���·����
		UGString m_strParseFile;

	//! \brief ����Դָ�롣
		UGWebDataSource* m_pDs;
		
	};
	
}
#endif // !defined(UGWEBSERVICEPARSE_H)
