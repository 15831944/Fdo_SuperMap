//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWMSParser.h
//!  \brief UGWMSParser �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWMSPARSER_H
#define UGWMSPARSER_H

#include "Base/ugexports.h"
#include "WebEngine/UGWebServiceParser.h"
#include "Base/UGDict.h"

namespace UGC{
	
//! \brief WMS����Դ�Ľ����ࡣ
//! \remarks WMS����Դ�Ľ����ࡣ
class WEBENGINE_API UGWMSParser : public UGWebServiceParser
{
public:
	UGWMSParser();
	UGWMSParser(const UGString& strFilePath);
	virtual ~UGWMSParser();
	
public:
	//! \brief ����WMS�������ݷ�������������
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
		UGArray<UGString>& aryCRS);
	
	//! \brief ����ͼ����Ϣ����ͼ�㡣
	//! \param Datasets ������ͼ��[out]��
	//! \param Lys �����õ���ͼ����Ϣ[in]��
	//! \param strMap ���ͼ��ϲ�Ϊһ��ͼ��ʱ��ͼ����[out]��
	//! \return �Ƿ񴴽��ɹ����ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool CreateLayer(UGDatasets& Datasets,
		const UGWebLayersInfo& Lys,
		const UGString& strMap);

	UGbool ParseOnlineResource(UGString& strOLResCapabilities, 
		UGString& strOLResGetMap,
		UGString& strOLResGetFeatureInfo,
		UGString& strOLResDescribeLayer,
		UGString& strOLResGetLegendGraphic);

	// ����һ��WMS�Ĺؼ����ֵ�
	UGDict<UGString,UGint>  m_dictKeyWords;
private:
	UGbool LoadDict();

	UGString TrimKeyWord(const UGString& strURL);
};
	
}
#endif // !defined(UGWMSPARSER_H)
