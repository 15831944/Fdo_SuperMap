//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWMSLayerInfo.h
//!  \brief UGWMSLayerInfo �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWMSLAYERINFO_H
#define UGWMSLAYERINFO_H

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Algorithm/UGRect2D.h"
#include "Engine/UGDatasetVectorInfo.h"

namespace UGC
{
	
//! \brief �ο�ϵ�����ṹ��
//! \remarks Webͼ�������ο�ϵ����������Χ��Ϣ��
struct UGCRSBound
{
	//! \brief ͼ�������ο�ϵ��
	UGString m_strCRSName;
	
	//! \brief ͼ���������Χ��
	UGRect2D m_rcBound;
};

//! \brief �ο�ϵ�������ϡ�
//! \remarks ���ڴ��һ��Webͼ���ж������ο�ϵ����������Χ��Ϣ�������
class WEBENGINE_API UGCRSBounds : public UGArray<UGCRSBound>
{
public:
	UGCRSBounds();
	~UGCRSBounds();
	
	//! \brief �õ��ο�ϵ���������е�ĳ���ο�ϵ��������Χ��
	//! \param CRSBounds �ο�ϵ��������[in]��
	//! \param m_strCRSName ����ο�ϵ��[in]��
	//! \return �ο�ϵ�������ϡ�
	//! \remarks ͼ���������Χ��
	//! \attention ��
	static UGRect2D GetCRSBoundByName(const UGCRSBounds& CRSBounds, 
		const UGString& strCRSName);
};


//! \brief ��������Դͼ����Ϣ��
//! \remarks ��ע��Ϣ��	
class WEBENGINE_API UGWebLayerInfo  
{
public:
	UGWebLayerInfo();
	UGWebLayerInfo(const UGWebLayerInfo& srcLayer);
	virtual ~UGWebLayerInfo();
	
	UGWebLayerInfo& operator=(const UGWebLayerInfo& srcLayer);
	UGbool operator==(const UGWebLayerInfo& layer) const;
	UGbool operator!=(const UGWebLayerInfo& layer) const;
	
public:
	//! \brief ͼ��������ӦName��ǩ��
	UGString m_strLayerName;	
	
	//! \brief ͼ����⣬��ӦTitle��ǩ��
	UGString m_strLayerTitle;
	
	//! \brief ͼ��ժҪ��Ϣ����ӦAbstract��ǩ��
	UGString m_strAbstract;	
	
	//! \brief ͼ�������ο�ϵ��������Χ�ļ��ϡ�
	UGCRSBounds m_CRSBounds;
	
	//! \brief WCS��֧�ֵĸ�ʽ��
	UGArray<UGString> m_aryFormart;
	
};

//! \brief ��������Դͼ����Ϣ���ϡ�
class WEBENGINE_API UGWebLayersInfo : public UGArray<UGWebLayerInfo>
{
public:
	UGWebLayersInfo();
	~UGWebLayersInfo();
	
	//! \brief ͼ�㼯�ϵ�����ο�ϵ��
	//! \remarks ��1.3 �汾��ǰ����ο�ϵ��Ӣ��д��SRS��
	UGString m_strCRS;
	
	//! \brief ͼ�㼯�ϵı��⣬��ӦTitle��ǩ��
	UGString m_strTitle;
};
	
}
#endif // !defined(UGWMSLAYERINFO_H)
