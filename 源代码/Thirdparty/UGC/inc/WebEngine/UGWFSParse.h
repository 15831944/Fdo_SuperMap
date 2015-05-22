//////////////////////////////////////////////////////////////////////////
//!  \file UGWFSParse.h
//!  \brief UGWFSParse �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br>
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWFSPARSE_H
#define UGWFSPARSE_H


#include "WebEngine/UGWebServiceParse.h"
#include "WebEngine/UGWebLayerInfo.h"
#include "WebEngine/UGWebDataSource.h"

namespace UGC{
	
	
	class WEBENGINE_API UGWFSParse : public UGWebServiceParse 
	{
	public:
		UGWFSParse();
		virtual ~UGWFSParse();
		
	public:
		//! \brief ����ͼ��������
		//! \param Layers ͼ����Ϣ����[out]��
		//! \param strVersion ��������Դ�汾[out]��
		//! \param strFormats ������֧�ֵ�ͼƬ��ʽ[out]��
		//! \param strMap û����[out]��
		//! \param arySRS �ռ�ο�ϵ����[out]��
		//! \return �Ƿ�����ɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
		virtual UGbool ParseCapabilities(UGWebLayerInfos& Layers,
			UGString& strVersion,
			UGArray<UGString>& strFormats,
			UGString& strMap,
			UGArray<UGString>& arySRS);
		
		//! \brief ����ͼ����Ϣ����ͼ�㡣
		//! \param Datasets ������ͼ��[out]��
		//! \param Layers �����õ���ͼ����Ϣ[in]��
		//! \param strMap ���ͼ��ϲ�Ϊһ��ͼ��ʱ��ͼ����[in]��
		//! \return �Ƿ񴴽��ɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
		virtual UGbool CreateLayer(UGDatasets& Datasets,
			const UGWebLayerInfos& Layers,
			const UGString& strMap);
		
	};
	
}
#endif // !defined(UGWFSPARSE_H)
