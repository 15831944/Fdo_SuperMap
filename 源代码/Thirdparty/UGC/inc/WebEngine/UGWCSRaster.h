//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWCSRaster.h
//!  \brief UGWCSRaster �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br>  
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWCSRASTER_H
#define UGWCSRASTER_H

#include "Base/ugexports.h"
#include "Engine/UGWebDatasetRaster.h"
#include "WebEngine/UGWebLayerInfo.h"

namespace UGC
{

//! \brief Coverage�ķ�Χֵ��
//! \remarks ͨ��������ʾ����ֵ��
struct AxisDescription
{
	//! \brief ����������
	UGString m_strAxisName;
	
	//! \brief ��������Сֵ��
	UGint m_nMin;
	
	//! \brief ���������ֵ��
	UGint m_nMax;

	//! \brief ��Чֵ
	UGint m_nNullVal;
};

//! \brief Coverage�ķ�Χֵ���顣
typedef UGArray<AxisDescription> AxisDescriptions;

//! \brief WCS���ݼ��ࡣ
//! \remarks WCS�����ݼ���
class WEBENGINE_API UGWCSRaster : public UGWebDatasetRaster  
{
public:
	UGWCSRaster();

	UGWCSRaster(UGDatasetRasterInfo& rInfo);

	virtual ~UGWCSRaster();

public:
	//! \brief �õ������ڴ��դ�����ݼ���
	//! \param strGetCoverageURL ��Web����Դ�����URL[in]��
	//! \return դ�����ݼ�ָ�롣
	//! \remarks �������غ������ɴ˺�����װ��
	virtual UGDatasetRaster* GetDatasetRaster(UGString strGetCoverageURL);

	//! \brief �õ������ڴ��դ�����ݼ�,���ڷŴ���Сƽ�Ʋ���������
	//! \param rcQueryBound ����Ӱ���������Χ[in]��
	//! \param dWidth ����Ӱ��Ŀ��,��λ����[in]��
	//! \param dHeight ����Ӱ��ĸ߶�,��λ����[in]��
	//! \param strFormat ����Ӱ��ĸ�ʽ[in]��
	//! \return դ�����ݼ�ָ�롣
	virtual UGDatasetRaster* GetDatasetRaster(UGRect2D rcQueryBound,
		UGint dWidth,UGint dHeight,UGString strFormat ="png");

	//! \brief �õ�����Դ������ͼ�������顣
	//! \param aryLayerNames ͼ��������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool GetAllLayerNames(UGArray<UGString>& aryLayerNames);

	//! \brief �õ�����Դ������ͼ��������顣
	//! \param aryLayerTitles ͼ���������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetAllLayerTitles(UGArray<UGString>& aryLayerTitles);

	//! \brief �õ�����Դ������ͼ�������顣
	//! \param aryLayerIndexes ͼ��������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetAllLayerIndexes(UGArray<UGint>& aryLayerIndexes);	
	
	//! \brief �õ����пɼ�ͼ�������顣
	//! \param aryLayerNames �ɼ�ͼ��������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerNames(UGArray<UGString>& aryLayerNames);	

	//! \brief �õ����пɼ�ͼ��������顣
	//! \param aryLayerTitles �ɼ�ͼ��ͼ���������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerTitles(UGArray<UGString>& aryLayerTitles);

	//! \brief �õ����ݼ����пɼ���ͼ���ż��ϡ�
	//! \param aryLayerIndexes �ɼ�ͼ��������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerIndexes(UGArray<UGint>& aryLayerIndexes);

	//! \brief ���õ�ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param aryLayerIndexes Դͼ��������[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	virtual UGbool SetVisibleLayers(const UGArray<UGint>& aryLayerIndexes);	

	//! \brief ���õ�ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param aryLayerNames Դͼ����Ϣ����[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	virtual UGbool SetVisibleLayers(const UGArray<UGString>& aryLayerNames);	
public:
	//! \brief ���ô����ݼ���Ӧ��FeatureTypeInfo����Ϣ��
	//! \param layerSrc ��������Դͼ����Ϣ[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool SetCoverageLayer(const UGWebLayerInfo& layerSrc);	

	//! \brief �õ����ݼ���Ӧ��FeatureTypeInfo����Ϣ��
	//! \param layerDest ��������Դͼ����Ϣ[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool GetCoverageLayer(UGWebLayerInfo& layerDest) const;
	
	//! \brief �����õ���ǰCoverage�õ�ͼ�����ϸ��Ϣ��
	//! \param strDescribeXMLPath DescribeCoverage�����XML�ļ����ڵ�·��[in]��
	//! \return �Ƿ�ɹ�����,�ɹ�����TRUE,ʧ�ܷ���FALSE����
	UGbool ParseCoverage(UGString strDescribeXMLPath = "");	
private:
	//! \brief ͨ��GetCoverage�����XML�ļ������ڴ�����Դ��
	//! \param strGetCoverageXMLPath GetCoverage�����XML�ļ���ַ[in]��
	//! \param strImageFormat �����Ӱ���ʽ[in]��
	//! \return �ڴ�����Դָ�롣
	UGDataSource* CreatDataSource(const UGString& strGetCoverageXMLPath, 
		UGRect2D rcGeoRef = UGRect2D(0,0,0,0) ,UGString strImageFormat ="");

	UGDatasetRaster* GetDatasetRaster(UGString strGetCoverageURL,
		 UGRect2D rcGeoref);
	//! \brief �õ�ͼ������Χ��URL��ѯѡ�
	//! \return BBOX URL��ѯѡ�
	//! \remarks ��ʽΪ BBOX=-165.270004272461,-54.7538909912109,177.130187988281,83.1083221435547&amp��
	UGString GetBBoxURLValue(UGRect2D rcSrc) const;
public:
	//! \brief WFS����Դ��ͼ����Ϣ��
	//! \remarks ��ע��Ϣ��
	UGWebLayerInfo m_coverageLayer;
	
	//! \brief WCSͼ��֧�ֵ����ꡣ
	AxisDescriptions m_aryAxis;

	//! \brief WCSͼ��֧�ֵĲο�ϵ������Ϣ���顣
	UGCRSBounds m_arySuportCRSBound;

	//! \brief spatialDomain�Ĳο�ϵ������Ϣ
	UGCRSBound m_spatialDomainEVlp;

	//! \brief Ӱ��ԭ��ȡ�
	UGint m_ImageWith;

	//! \brief Ӱ��ԭ�߶ȡ�
	UGint m_ImageHight;

	//! \brief WCSͼ��֧�ֵĿռ������
	UGStrings m_aryInterpolations;

	UGString strOLResCapabilities;

	UGString strOLResDescribeCoverage;

	UGString strOLResGetCoverage;
};

}
#endif // !defined(UGWCSRASTER_H)
