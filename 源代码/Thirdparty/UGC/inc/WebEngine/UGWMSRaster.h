//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWMSRaster.h
//!  \brief UGWMSRaster �Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWMSRASTER_H
#define UGWMSRASTER_H

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Engine/UGDatasetRaster.h"
#include "Engine/UGWebDatasetRaster.h"
#include "WebEngine/UGWebLayerInfo.h"

namespace UGC{

//! \brief WMS���ݼ��ࡣ
//! \remarks WMS�����ݼ���
class WEBENGINE_API UGWMSRaster :public UGWebDatasetRaster  
{
public:
	UGWMSRaster();

	UGWMSRaster(UGDatasetRasterInfo& rInfo);

	virtual ~UGWMSRaster();

public:
	//! \brief �õ������ڴ��դ�����ݼ���
	//! \param strURL ��Web����Դ�����URL[in]��
	//! \return դ�����ݼ�ָ�롣
	//! \remarks �������غ������ɴ˺�����װ��
	virtual UGDatasetRaster* GetDatasetRaster(UGString strURL);

	//! \brief �õ������ڴ��դ�����ݼ�,���ڷŴ���Сƽ�Ʋ���������
	//! \param rcBound ����Ӱ���������Χ[in]��
	//! \param dWidth ����Ӱ��Ŀ��,��λ����[in]��
	//! \param dHeight ����Ӱ��ĸ߶�,��λ����[in]��
	//! \param strFormat ����Ӱ��ĸ�ʽ[in]��
	//! \return դ�����ݼ�ָ�롣
	virtual UGDatasetRaster* GetDatasetRaster(UGRect2D rcBound,
		UGint dWidth,UGint dHeight,UGString strFormat ="image/png");
 	
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

	//! \brief ���õ�ǰ���ݼ�������ͼ�㡣
	//! \param arySrc Դͼ����Ϣ����[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool SetAllLayers(const UGWebLayersInfo& arySrc);
	
	//! \brief �õ���ǰ���ݼ�������ͼ�㡣
	//! \param aryDest Ŀ��ͼ����Ϣ����[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool GetAllLayers(UGWebLayersInfo& aryDest) const;	

	//! \brief ���õ�ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param arySrc Դͼ����Ϣ����[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool SetVisibleLayers(const UGWebLayersInfo& arySrc);	

	//! \brief �õ���ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param aryDest Ŀ��ͼ����Ϣ����[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,���򷵻�FALSE��
	UGbool GetVisibleLayers(UGWebLayersInfo& aryDest) const;	

private:
	//! \brief �õ�ͼ����Ϣ�ı߽�����ϡ�
	//! \param layersInfo ͼ����Ϣ����[in]��
	//! \return �߽���Ρ�
	//! \remarks ����ͼ����Ϣ�ж���߿���ЩҲ���ϲ������շ��ؽ���
	UGRect2D GetLayersBoundUnion(const UGWebLayersInfo& layersInfo) const;

	//! \brief �õ��ɼ�ͼ���URL��ѯѡ��,��ʽΪLayers = Layer1,Layer2,Layer3&amp;��
	//! \param layersSrc ͼ����Ϣ����[in]��
	//! \return Layers URL��ѯѡ�
	//! \remarks ��ʽΪLAYERS = Layer1,Layer2,Layer3&amp;��
	//! \attention ��
	UGString GetLayersURLValue(const UGWebLayersInfo& layersSrc) const;

	//! \brief �õ��ɼ�ͼ���URL��ѯѡ��,��ʽΪLayers = Layer1,Layer2,Layer3&amp;��
	//! \param layersSrc ͼ��������[in]��
	//! \return Layers URL��ѯѡ�
	//! \remarks ��ʽΪLAYERS = Layer1,Layer2,Layer3&amp;��
	//! \attention ��
	UGString GetLayersURLValue(const UGArray<UGString>& layersSrc) const;

	//! \brief �õ�ͼ������Χ��URL��ѯѡ�
	//! \param rcSrc ���ο����[in]��
	//! \return BBOX URL��ѯѡ�
	//! \remarks ��ʽΪ BBOX=-165.270004272461,-54.7538909912109,177.130187988281,83.1083221435547&amp��
	//! \attention ��
	UGString GetBBoxURLValue(const UGRect2D& rcSrc) const;
	
protected:
	//! \brief ��ǰ���ݼ�������ͼ����Ϣ���ϡ�
	//! \remarks ��ע��Ϣ��
	UGWebLayersInfo m_aryAllLayers;

	//! \brief ��ǰ���ݼ��Ŀɼ�ͼ����Ϣ���ϡ�
	//! \remarks ��ע��Ϣ��
	UGWebLayersInfo m_aryVisibleLayers;
public:
	UGString m_strOLResCapabilities;

	UGString m_strOLResGetMap;

	UGString m_strOLResGetFeatureInfo;

	UGString m_strOLResDescribeLayer;

	UGString m_strOLResGetLegendGraphic;
};

}
#endif // !defined(UGWMSRASTER_H)
