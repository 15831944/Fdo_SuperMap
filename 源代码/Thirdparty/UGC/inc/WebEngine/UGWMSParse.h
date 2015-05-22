//////////////////////////////////////////////////////////////////////////
//!  \file UGWMSParse.h
//!  \brief UGWMSParse �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br>
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWMSPARSE_H
#define UGWMSPARSE_H

#include "WebEngine/UGWebServiceParse.h"

namespace UGC{
	
	
	class WEBENGINE_API UGWMSParse : public UGWebServiceParse
	{
	public:
		UGWMSParse();
		virtual ~UGWMSParse();
		
	public:
		//! \brief ����ͼ��������
		//! \param Layers ͼ����Ϣ����[out]��
		//! \param strVersion ��������Դ�汾[out]��
		//! \param strFormats ������֧�ֵ�ͼƬ��ʽ[out]��
		//! \param strMap Title����[out]��
		//! \param arySRS �ռ�ο�ϵ����[out]��
		//! \return �Ƿ�����ɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
		virtual UGbool ParseCapabilities(UGWebLayerInfos& Layers,
			UGString& strVersion,
			UGArray<UGString>& strFormats,
			UGString& strMap,
			UGArray<UGString>& arySRS);
		
		//! \brief ����ͼ����Ϣ����ͼ�㡣
		//! \param Datasets ������ͼ��[out]��
		//! \param Lys �����õ���ͼ����Ϣ[in]��
		//! \param strMap ���ͼ��ϲ�Ϊһ��ͼ��ʱ��ͼ����[out]��
		//! \return �Ƿ񴴽��ɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
		virtual UGbool CreateLayer(UGDatasets& Datasets,
			const UGWebLayerInfos& Lys,
			const UGString& strMap);
	};
	
}
#endif // !defined(UGWMSPARSE_H)
