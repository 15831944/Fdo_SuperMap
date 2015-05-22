/**  \file UGLayersRecordsetsManager.h
   \brief ʵ��Layers�м�¼���Ĺ���
   \author lugw
   \attention 
   Copyright(c) 1996-2007 SuperMap GIS Technologies, Inc.<br>
   All Rights Reserved.
 */ 

#if !defined(AFX_UGLAYERSRECORDSETSMANAGER_H__EE094C5F_85C5_441B_9AB8_CCA855D24FEE__INCLUDED_)
#define AFX_UGLAYERSRECORDSETSMANAGER_H__EE094C5F_85C5_441B_9AB8_CCA855D24FEE__INCLUDED_

#include "Base/ugdefs.h"
#include "UGLayer.h"


namespace UGC
{

	struct UGRecordsetWithLayer 
	{
		UGRecordset* pRecordset;
		UGArray<UGLayer*> pLayerArray;
		UGRecordsetWithLayer()
		{
			pRecordset = NULL;
			pLayerArray.RemoveAll();
		};
	};

	struct UGDatasetWithRecordset
	{
		UGDatasetVector* pDv;
		UGArray<UGRecordsetWithLayer> pRecordsetArray;
		UGDatasetWithRecordset()
		{
			pDv = NULL;
			pRecordsetArray.RemoveAll();
		};
	};

class UGLayersRecordsetsManager  
{
public:
	UGLayersRecordsetsManager();
	virtual ~UGLayersRecordsetsManager();
	//! \brief �õ���Ӧͼ���Recordset���ڲ��������Recordset
	/**
	����������ϸ����
	\param Layers       ��Layers�µ�����ͼ��[in] 
	\param pos          ��ǰ���Ʋ�λ��[in]
	\param pLayer       ��ǰ���Ʋ�[in]
	\param pGraphics    ��ǰ��ʾ����[in]
	\param pDrawing     ��ǰ���Ʋ���[in]
	\param bTemp        �ü�¼���Ƿ�Ϊ��ʱ[in/out]
	\return �ò��¼��
	*/
	UGRecordset* FindRecordsetWithLayer(UGList<UGLayer*> Layers, UGLayer* pLayer, UGGraphics* pGraphics, UGDrawing *pDrawing, UGbool& bTemp);

	//! \brief ��ȡ��ǰ��ͼ����ļ�¼����С
	UGuint GetSize();
	//! \brief ��յ�ͼ���еļ�¼��
	void RemoveAll();

protected:

	UGbool GetQueryDef(UGList<UGLayer*> Layers, UGLayer* pLayer, UGGraphics* pGraphics, UGDrawing *pDrawing, UGRecordsetWithLayer& RecordsetWithLayerTemp);
	UGbool AddRecordsetWithLayer(UGRecordsetWithLayer& RecordsetWithLayerTemp,UGbool bFindDv);

	UGbool AppendQueryDefFields(UGQueryDef& qfTo,UGQueryDef& qfFrom);

private:
	UGArray<UGDatasetWithRecordset> m_pDatasetWithRecordset;
	UGArray<UGDatasetVector*> m_pDifDatasetsVector;
	UGuint m_nSize;
};

}

#endif // !defined(AFX_UGLAYERSRECORDSETSMANAGER_H__EE094C5F_85C5_441B_9AB8_CCA855D24FEE__INCLUDED_)
