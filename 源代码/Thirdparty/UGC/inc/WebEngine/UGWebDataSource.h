//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWMSDataSource.h
//!  \brief WMSEngine ������Դ�Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWEBDATASOURCE_H
#define UGWEBDATASOURCE_H

#include "Base/ugexports.h"
#include "Engine/UGDataSource.h"
#include "WebEngine/UGWebLayerInfo.h"
#include "WebEngine/UGWebServiceParser.h"

namespace UGC 
{
class UGWebLayersInfo;
class UGWebServiceParse;

//! \brief ��������Դ������Դ�ࡣ
//! \remarks
class WEBENGINE_API UGWebDataSource : public UGDataSource  
{
	friend class UGWFSRecordset;
	friend class UGWMSRaster;
public:
	UGWebDataSource();
	
	UGWebDataSource(UGDsConnection dsConn);
	virtual ~UGWebDataSource();
	
	//! \brief ������Դ,��ҪԤ�����ú�������Ϣ��
	//! \return ���سɹ���ʧ�ܡ�
	virtual UGbool Open();
	
	//! \brief ��������Դ����Ҫ�趨��������Ϣ��
	//! \return �����ɹ�����TRUE,ʧ�ܷ���False��
	virtual UGbool Create();
	
	//!  \brief ����Դ�Ƿ����������
	virtual UGbool IsConnected();
	
	//!  \brief �����������ݿ�,��ˢ�����ݼ���
	virtual UGbool Connect();
	
	//! \brief �ر�����Դ��
	//! \return ���سɹ���ʧ�ܡ�
	virtual void Close();
	
	//! \brief �ж�����Դ�Ƿ�򿪡�
	//! \return ����Դ״̬��
	virtual UGbool IsOpen();
	
	//! \brief �Ƿ���ִ��ĳЩ������������
	//! \param nAbility ����֧�ֵ�����[in]��
	//! \return �Ƿ�֧�֣��Ƿ���TRUE ���򷵻�FALSE��
	virtual UGbool HasAbility(UGEngAbility nAbility) const ;
	
	//! \brief �Ƿ�֧���ض��Ĳ�����
	//! \param nAction ����֧�Ĳ���[in]��
	//! \return �Ƿ�֧�֣��Ƿ���TRUE ���򷵻�FALSE��
	virtual UGbool IsSupport(UGEngAction nAction) const ;
	
	//! \brief ��ȡ������ʱ�䡣
	//! \return ������ʱ�䡣
	virtual UGTime GetDateLastUpdated() const ;
	
	//!  \brief ��ȡ����ʱ��
	virtual UGTime GetDateCreated() const;
	
	//! \brief �õ��������ơ�
	//! \return �������ơ�
	virtual UGString GetEngineName();
	
	//! \brief ����������Ϣ��
	//! \return �Ƿ񱣴�ɹ����Ƿ���TRUE ���򷵻�FALSE����
	virtual UGbool SaveInfo();
	
	//! \brief �޸����롣
	//! \param strNewPassword [in]��
	//! \return �Ƿ��޸ĳɹ����Ƿ���TRUE ���򷵻�FALSE��
	virtual UGbool ChangePassword(const UGString& strNewPassword);		
	
	//! \brief ��ʼ����
	//! \return �Ƿ�����ɹ����Ƿ���TRUE ���򷵻�FALSE��
	virtual UGbool BeginTrans();
	
	//! \brief �ύ����
	//! \return �Ƿ�����ɹ����Ƿ���TRUE ���򷵻�FALSE��
	virtual void Commit();
	
	//! \brief ��������
	//! \return �Ƿ�����ɹ����Ƿ���TRUE ���򷵻�FALSE��
	virtual void Rollback();
	
	//! \brief ����ʧ�����ݼ���
	//! \param vInfo ʧ�����ݼ���Ϣ[in]��
	//! \return ʧ�����ݼ���
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);
	
	//! \brief �����������ݼ���
	//! \param strName �������ݼ���[in]��
	//! \return �������ݼ���
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);
	
	//! \brief ����դ�����ݼ���
	//! \param rInfo դ�����ݼ���Ϣ[in]��
	//! \return դ�����ݼ���
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);
	
	//! \brief ɾ�����ݼ���
	//! \param strName ���ݼ�����[in]��
	//! \return �Ƿ�����ɹ����Ƿ���TRUE ���򷵻�FALSE��
	virtual UGbool DeleteDataset(const UGString& strName);
	
	virtual UGbool IsSupport(UGDataset::DatasetType nDtType) const;
public:
	
	//! \brief �õ���ǰ�������е�ͼ�㼰ͶӰ���͡�
	//! \param layerinfos ����ͼ�����Ϣ����[out]��
	//! \param arySRS ����Դ֧�ֵ�ͶӰ��������[out]��
	//! \return �Ƿ�õ��ɹ����Ƿ���TRUE ���򷵻�FALSE��
	UGbool GetServiceInfo(UGWebLayersInfo& layerinfos, UGArray<UGString>& aryCRS);
	
	//! \brief �õ�����ο�ϵ�ַ�����
	//! \return ����ο�ϵ�ַ�����
	UGString GetCRS(){return m_strCRS;}
	
	//! \brief ��������ο�ϵ�ַ�����
	//! \return �Ƿ����óɹ����Ƿ���TRUE ���򷵻�FALSE��
	void SetCRS(const UGString& strCRS){m_strCRS = strCRS;}


	//! \brief �������ݼ��Ƿ�򿪻�����ơ�
	//! \param bIsCached �Ƿ�򿪻������[in]��
	//! \return TRUEΪ�򿪻��塣
	void SetCached(const UGbool& bIsCached){m_bIsCached = bIsCached;}		

	//! \brief ���ݼ��Ƿ�򿪻�����ơ�
	//! \return TRUEΪ�򿪻��塣
	UGbool IsCached(){return m_bIsCached;}
	
	//	protected:
private:
	
	//! \brief ����ĳ��URL�Ƿ��ܹ��ɹ�����GetCapbility����
	//! \param strGetCapbilityURL GetCapbility����URL[in]��
	//! \return �Ƿ�����ɹ����ɹ�����TRUE ���򷵻�FALSE��
	UGbool CheckGetCapbility(UGString strGetCapbilityURL);		
	
	//! \brief �õ������õ���ʱ�ļ���
	//! \param pDataSourceConnection ����Դָ��[in]��
	//! \param strFilePath �ļ�·��[in]��
	//! \return �õ��ɹ�����TRUE,ʧ�ܷ���FALSE��
	//! \remarks ���ú�������ɾ����
	UGbool GetCapabilitiesFile(UGDsConnection * pDSConn, 
		UGString& strFilePath);
	
	// 
	//! \brief ������������Դ����Ϣ��
	//! \param strFilePath �ļ�·��[in]��
	//! \return �Ƿ�����ɹ����ɹ�����TRUE ���򷵻�FALSE��
	//! \remarks ��
	//! \attention ��
	UGbool ParseCapabilities(UGString &strFilePath);
	
	//! \brief ��CRS�ַ����õ�ͶӰ����ϵ��
	//! \param Prj ͶӰ����ϵ����[out]��
	//! \param strCRS Web����Դ�Ŀռ�ο�ϵ�ַ���[in]��
	//! \return �Ƿ�õ��ɹ����ɹ�����TRUE ���򷵻�FALSE��
	UGbool GetProjectionByName(UGPrjCoordSys& Prj, const UGString& strCRS);

public:
	//! \brief URL��
	//! \remarks URL��
	//! \brief http://maps.supermap.com:7070/ogc3/smwms?REQUEST=GetCapabilities&SERVICE=WMS&VERSION=1.3.0
	//UGString m_strURL;
	
	//! \brief ����������
	//! \remarks ����������������IP��ַ��
	//! \brief maps.supermap.com.  ��  220.194.106.169��
	UGString m_strHost;
	
	//! \brief �˿ںš�
	//! \remarks Ĭ��Ϊtcp 80 �˿ڡ�
	//! \brief :7070
	UGushort m_nPort;			
	
	//! \brief ����·����
	//! \remarks �������ݷ��������Web�������������·����
	//! \brief /ogc3/smwms
	UGString m_strPath;
	
	//! \brief WMS��WCS��WFS�淶�İ汾�š�
	//! \remarks �ص�2007��6��18�գ�WMS�淶�����°汾��1.3.0 , WFS�����°汾�汾�� 1.1.1 ��
	//! \brief VERSION=1.3.0&
	UGString m_strVersion;
	
	//! \brief ��������Դ��ͼ����
	//! \remarks �Ǳ�׼,SuperMap����,��Ӧ��IS Java�����ĵ�ͼ����
	//! \brief SERVICENAME=World&
	UGString m_strMapName;
	
	//! \brief ����Դ������ο�ϵ��
	//! \remarks ���Web����Դ������ο�ϵ��
	UGString m_strCRS;

	//! \brief ����Դ�ı߽硣
	//! \remarks ���Web����Դ������ο�ϵ�߽硣
	UGRect2D m_rcBounds;
	
	//! \brief ����Դͼ�㼯����Ϣ��
	//! \remarks �����鱣���˵�ǰ��������ĳһ��ͼ������ͼ�����Ϣ��
	UGWebLayersInfo m_layersInfo;
	
	//! \brief WMS֧�ֵ�Ӱ���ʽ,��WFS֧�ֵ�GML�İ�ʽ����
	//! \remarks ����֧��png��bmp��jpg ��ʽ��
	UGArray<UGString> m_AryFormat;
	
	//! \brief �������ݽ�������
	//! \remarks ʧ��դ�������������ͬ��
	UGWebServiceParser* m_pWebParse;
	
	//! \brief �Ƿ񻺳��������ݡ�
	//! \remarks ��ע��Ϣ��
	UGbool m_bIsCached;
};

extern "C" WEBENGINE_API UGDataSource* CreateDataSource();	
}
#endif // !defined(UGWEBDATASOURCE_H)
