//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWCSParser.h
//!  \brief UGWCSParser �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWCSPARSER_H
#define UGWCSPARSER_H

#include "Base/ugexports.h"
#include "WebEngine/UGWebServiceParser.h"

namespace UGC
{

//! \brief WCS����Դ�Ľ����ࡣ
//! \remarks WCS����Դ�Ľ����ࡣ
class WEBENGINE_API UGWCSParser : public UGWebServiceParser  
{
public:
	UGWCSParser();
	UGWCSParser(const UGString& strFilePath);
	virtual ~UGWCSParser();
public:
	//! \brief ����WCS�������ݷ�������������
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
		const UGWebLayersInfo& Layers,
		const UGString& strMap);
};

}
#endif // !defined(UGWCSPARSER_H)
