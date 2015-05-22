//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWFSVector.h
//!  \brief UGWFSVector �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWFSVECTOR_H
#define UGWFSVECTOR_H

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Engine/UGDatasetVector.h"
#include "Engine/UGFieldInfo.h"
#include "Engine/UGWebDatasetVector.h"
#include "WebEngine/UGWebLayerInfo.h"

namespace UGC
{

//! \brief WFS���ݼ��ࡣ
//! \remarks WFS�����ݼ�
class WEBENGINE_API UGWFSVector :public UGWebDatasetVector 
{
public:
	UGWFSVector();
	UGWFSVector(UGDataSource *pDataSource);
	UGWFSVector(UGDatasetVectorInfo& vInfo);
	virtual ~UGWFSVector();

public:
	//! \brief ���ݲ�ѯ����õ��ڴ��¼����
	//! \param querydef ��ѯ����[in]��
	//! \return �ڴ��¼����
	UGRecordset* Query(const UGQueryDef& querydef);

	//! \brief ����WFS��GetFeature��URL����õ��ڴ��¼��,Ĭ�ϵȵ�EditRecordset��
	//! \param strURL WFS��GetFeature�����URL[in]��
	//! \return �ڴ��¼����
	UGRecordset* Query(const UGString &strURL);

	//! \brief ���ô����ݼ���Ӧ��FeatureTypeInfo��WFSͼ����Ϣ��
	//! \param arySrc ��������Դͼ����Ϣ[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool SetFeatureTypeInfo(const UGWebLayerInfo& layerSrc);	

	//! \brief �õ����ݼ���Ӧ��FeatureTypeInfo����Ϣ��
	//! \param aryDest ��������Դͼ����Ϣ[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool GetFeatureTypeInfo(UGWebLayerInfo& layerDest) const;	

	//! \brief �����õ����ݼ������Ͳ�д�뵽���ݼ���m_DatasetInfo��֧��
	//! \return �Ƿ�ɹ�����,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool ParseDatasetType();
private:


	//! \brief ����������Ϣ��ѯ�õ���¼����
	//! \param &rcQueryBound ��ѯ������󣬰���������Ϣ[in]��
	//! \return �ڴ��¼����
	//! \param bIsCached �Ƿ񻺳���������Դ[in]��
	UGRecordset* GetRecordsetVectorBounds(const UGQueryDef& queryBound, UGbool bIsCached);
	
	//! \brief ����IDs��ѯ�Ĳ�ѯ����õ���¼����
	//! \param queryIDs ��ѯ������󣬰�����ѯ��IDs[in]��
	//! \param bIsCached �Ƿ񻺳���������Դ[in]��
	//! \return �ڴ��¼����
	UGRecordset* GetRecordsetVectorIDs(const UGQueryDef& queryIDs, UGbool bIsCached);
	
	//! \brief ����General��ѯ�Ĳ�ѯ����õ���¼����
	//! \param queryGeneral ��ѯ������󣬰���General��ѯ�Ĳ���[in]��
	//! \param bIsCached �Ƿ񻺳���������Դ[in]��
	//! \return �ڴ��¼����	
	UGRecordset* GetRecordsetVectorGeneral(const UGQueryDef& queryGeneral, UGbool bIsCached);

	//! \brief ����GetFeauture�����URL�õ��ڴ����ݼ����ٲ�ѯ�õ��ڴ��¼����
	//! \param strURL GetFeauture�����URL[in]��
	//! \param queryDef ��ѯ�������[in]��
	//! \return �ڴ��¼����
	UGRecordset* GetRecordsetVector(UGString strGetFeatureURL,const UGQueryDef& queryDef);

	//! \brief �õ�ͼ����Ϣ�ı߽�����ϡ�
	//! \param layersInfo ͼ����Ϣ����[in]��
	//! \return �߽���Ρ�
	//! \remarks ����ͼ����Ϣ�ж���߿���ЩҲ���ϲ������շ��ؽ���
	UGRect2D GetLayersBoundUnion(const UGWebLayersInfo& layersInfo);

	//! \brief �õ��ɼ�ͼ���URL��ѯѡ�
	//! \param layersSrc ͼ����Ϣ����[in]��
	//! \return Layers URL��ѯѡ���ʽΪLayers = Layer1,Layer2,Layer3&amp;
	//! \remarks ��ʽΪLAYERS = Layer1,Layer2,Layer3&amp;��
	UGString GetLayersURLValue(UGWebLayersInfo layersSrc) const;

	//! \brief �õ��ɼ�ͼ���URL��ѯѡ�
	//! \param layersSrc ͼ��������[in]��
	//! \return Layers URL��ѯѡ�
	//! \remarks ��ʽΪLAYERS = Layer1,Layer2,Layer3&amp;��
	UGString GetLayersURLValue(UGArray<UGString> layersSrc) const;

	//! \brief �õ�ͼ������Χ��URL��ѯѡ�
	//! \return BBOX URL��ѯѡ�
	//! \remarks ��ʽΪ BBOX=-165.270004272461,-54.7538909912109,177.130187988281,83.1083221435547&amp��
	UGString GetBBoxURLValue(UGRect2D rcSrc) const;

	//! \brief �õ�IDs��ѯ��FeatureID URL��ѯѡ�
	//! \param *pIDs IDs����ָ��[in]��
	//! \param nCount IDs����[in]��
	//! \return FeatureID URL��ѯѡ���ʽΪFeatureID=state.1,state.2&amp;��
	//! \remarks ���磺FeatureID=state.1,state.2&��
	UGString GetFeatureIDURLValue(UGint *pIDs, UGint nCount) const;	

	//! \brief ͨ��GetFeature�����XML�ļ������ڴ�����Դ��
	//! \param strGetFeatureXMLPath GetFeature����õ���XML�ļ���ַ[in]��
	//! \param strDescribeXMLPath DescribeFeatureType����õ���XML�ļ���ַ[in]��
	//! \param versionGML ���������ʹ�õ���GML���ԺͰ汾[in]��
	//! \return �ڴ�����Դָ�롣
	UGDataSource* CreatDataSource(UGString strGetFeatureXMLPath, 
		UGString strDescribeXMLPath, UGGeometry::GMLVersionType versionGML);

	//! \brief �����õ���ǰFeatureType����Ӧ���ֶ���Ϣ���顣
	//! \param fieldInfos �����õ����ֶ���Ϣ����[in]��
	//! \param strTypeName �����õ���WFS���ݼ���[in]��
	//! \param edatasetType �����õ���WFS���ݼ�����[in]��
	//! \param strDiscribeXMLPath DescribeFeatureType����õ���XML�ļ���[in]��
	//! \return �Ƿ�ɹ�����,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	UGbool ParseFeatureType(UGFieldInfos& fieldInfos, UGString& strTypeName, 
		UGDataset::DatasetType& edatasetType, UGString strDescribeXMLPath);

	//! \brief ͨ��GetFeature�����XML�ļ��õ��ڴ�����Դ�ı߽��ͶӰ��
	//! \param CRSBound �ο�ϵ������Ϣ[in]��
	//! \param strDiscribeXMLPath GetFeature�����XML�ļ���ַ[in]��
	//! \return �Ƿ�ɹ�����,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	UGbool ParseFeatureBound(UGCRSBound& CRSBound, UGString strGetFeatureXMLPath);
protected:
	
	//! \brief WFS����Դ��ͼ����Ϣ��
	//! \remarks ��ע��Ϣ��
	UGWebLayerInfo m_featureTypeInfo;

	//! \brief ��ѯ��Ԫ��ǰ׺
	//! \remarks ���� FeatureID=state.1,state.2 ��ǰ׺����state��
	UGString m_strElementName;

	//! \brief ���ݼ��Ƿ񾭹�ת����
	//! \remarks ��ע��Ϣ��
	UGbool m_bHasTrans;

	//! \brief ���ݼ��Ƿ���¹��ֶ���Ϣ��
	UGbool m_bFieldsUpdated;

	UGString strOLResCapabilities;

	UGString strOLResDescribeFeatureType;

	UGString strOLResGetFeature;

	UGString strOLResTransaction;

	UGString strOLResLockFeature;

	UGString strOLResGetFeatureWithLock;
};

}
#endif // !defined(UGWFSVECTOR_H)
