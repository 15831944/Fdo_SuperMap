//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGHttpHelper.h
//!  \brief UGHttpHelper �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGHTTPHELPER_H
#define UGHTTPHELPER_H


#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGFileStream.h"
#include "Base/UGDict.h"
#include "Algorithm/UGRect2D.h"

namespace UGC
{
	
//! \brief Http���֣��ṩWeb����Դʹ�õ���Http���󼰽�������ز�����
//! \remarks ��ע��Ϣ��
class WEBENGINE_API UGHttpHelper
{
public:
	UGHttpHelper();

	virtual ~UGHttpHelper();

	enum RequestMethod
	{
		GET = 0,
		POST = 1
	};

	enum HttpFileType
	{
		CHARACTER = 0,
		BINARY = 1
	};

	enum ProtocolType
	{
		FTP = 1,
		GOPHER = 2,
		HTTP = 3
	};

	//! \brief ͨ��URL����õ���������Ӧ�ļ���
	//! \param strURL ������URL��ַ[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \param reqMmethod http����ʽ,post��get,Ĭ���ÿ�[in]��
	//! \param fileType �����ļ�����ʽ,�����ƻ��ı�,Ĭ���ÿ�[in]��
	//! \return ����õ����ļ�·�����ļ���,�������ʱ·����
	//! \remarks ��
	//! \attention ��
	static UGString RequestFile(UGString strURL, UGString strUser, 
								UGString strPasswd, RequestMethod reqMmethod, 
								HttpFileType fileType);

	//! \brief ͨ��URL����õ���������Ӧ�ļ������浽�궨·����
	//! \param strURL ������URL��ַ[in]��
	//! \param strDstPath ����õ����ļ��ĵ�ַ���ļ���[in]��
	//! \param strUser ��¼�������û���,���������ÿ�[in]��
	//! \param strPasswd ��¼������������,���������ÿ�[in]��
	//! \param reqMmethod http����ʽ,post��get,Ĭ���ÿ�[in]��
	//! \param fileType �����ļ�����ʽ,�����ƻ��ı�,Ĭ���ÿ�[in]��
	//! \return �Ƿ�ɹ��õ��ļ�,�ɹ�����TRUE,ʧ�ܷ���FALSE����
	//! \remarks ��
	//! \attention ��
	static UGbool RequestFile2(UGString strURL,UGString strDstPath, 
							   UGString strUser, UGString strPasswd, 
							   RequestMethod reqMmethod, HttpFileType fileType);

	//! \brief URL����������
	//! \param pstrURL URL�ַ���[in]��
	//! \param dwServiceType ����Э������[out]��
	//! \param strServer �������������IP��ַ[out]��
	//! \param strObject URL�е�Path�Ͳ�ѯѡ��[out]��
	//! \param nPort �˿ں�[out]��
	//! \return �Ƿ�����ɹ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	static UGbool UGParseURL(UGString strURL, UGuint& dwServiceType, 
							 UGString& strServer, UGString& strObject, 
							 UGushort& nPort );

	//! \brief URL����������
	//! \param pstrURL URL�ַ���[in]��
	//! \param dwServiceType ����Э������[out]��
	//! \param strServer �������������IP��ַ[out]��
	//! \param strPath URL�е�Path[out]��
	//! \param strPath URL�еĲ�ѯѡ��[out]��
	//! \param nPort �˿ں�[out]��
	//! \return �Ƿ�����ɹ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	static UGbool UGParseURL2(UGString strURL, UGuint& dwServiceType, 
							  UGString& strServer, UGString& strPath, 
							  UGString& strQuery, UGushort& nPort);

	//! \brief URL����������
	//! \param pstrURL URL�ַ���[in]��
	//! \param strServerPath URL�е�ServerName��Port��Path��[out]��
	//! \param strQuery URL�еĲ�ѯѡ��[out]��
	//! \return �Ƿ�����ɹ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	static UGbool UGParseURL3(UGString strURL, 
							  UGString& strServerPath, UGString& strQuery);	
	
	static UGbool URLtoKVPairs(const UGString& strURLsrc,
							   UGString& strBaseURL, UGDict<UGString,UGString>& dictQueryPairs);

	static UGbool KVPairstoURL(const UGString& strBaseURL, const UGDict<UGString,UGString>& dictQueryPairsUGString, 
							   UGString& strURLdes);

	//! \brief ��URL�еõ�������Ϣ��
	//! \param strURL �����URL�ַ���[in]��
	//! \param rcGeoRef ������Ϣ[out]��
	//! \return �Ƿ�����ɹ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	static UGbool GetBBox(const UGString& strURL,UGRect2D& rcGeoRef);

	//! \brief ����һ��OGC Web����Դ�������Ƿ�ɹ���
	//! \param strURL OGC Web����Դ������,����GetCapabilitys,DescribFeature��[in]��
	//! \param strUser Http���ʵ��û���[in]��
	//! \param strPasswd Http���ʵ�����[in]��
	//! \return �ɹ�����TRUE,ʧ�ܷ���FALSE����
	static UGbool CheckOGCRequest(UGString strURL,
								  UGString strUser = "",UGString strPasswd= "");

};
	
}
#endif // !defined(UGHTTPHELPER_H)
