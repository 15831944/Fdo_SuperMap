// UGLayers.h: interface for the UGLayers class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGLayers.h
   **************************************************************************************
    \author   �¹���
    \brief    ͼ�㼯���࣬����ͼ��Ĺ���                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGLAYERS_H__4AF37668_F0B9_4C2D_B3A1_8E638AA1B00F__INCLUDED_)
#define AFX_UGLAYERS_H__4AF37668_F0B9_4C2D_B3A1_8E638AA1B00F__INCLUDED_

#include "UGLayer.h"
#include "Workspace/UGWorkspace.h"
#include "Map/UGLayersRecordsetsManager.h"

namespace UGC {
//added by xielin 
//! \brief ͼ����Ƶı��棬Ŀǰ��������֮ǰ�Ĳ�ѯʱ�䣬����ʱ�䣬���ƶ�����,դ�����ݲ�ѯʱ���Ϊ0��ȫ���㵽����ʱ����,�Ժ���Ϊ��λ
struct LayerDrawReport
{
	UGint nQueryTime;
	UGint nDrawTime;
	UGint nGeometryCount;
	LayerDrawReport()
	{
		nQueryTime = 0;
		nDrawTime = 0;
		nGeometryCount = 0;
	}
};

typedef void (*LayersModifiedProc)(UGLayer* pLayer, UGuint nModifyLayerFlag, UGlong pData);
//! \brief BeforeLayerDraw �¼��ص�����
typedef void (UGSTDCALL *BeforeLayerDrawProc)(UGlong pWnd,UGbool& bCancel,UGint nLayerIndex,UGGraphics* pGraphics);
//! \brief AfterLayerDraw �¼��ص�����
typedef void (UGSTDCALL *AfterLayerDrawProc)(UGlong pWnd,UGint nLayerIndex,UGGraphics* pGraphics,LayerDrawReport& layerDrawReport);

struct LayersForSaveSFC 
{
	UGLayer* pLayer;
	UGbool bDel;
	LayersForSaveSFC()
	{
		pLayer = NULL;
		bDel = false;
	}
};



class MAP_API UGLayers  
{
	friend class UGMap;
	friend class UGLayer;
public:
	//! �޸�ͼ���ʶ
	enum UGModifyLayerFlag	
	{
		mlAddLayer,					//! ���ͼ��
		mlDeleteLayer,				//! ɾ��ͼ��
		mlChangeEditLayer,			//! �ɱ༭ͼ��ı�
		mlChangeEditableLock		//! ͼ��༭�����ı�
	};

public:
	UGLayers();
	virtual ~UGLayers();
	UGLayers(const UGLayers &Layers);
	UGLayers& operator =(const UGLayers &Layers);

public:
	//!brief ���û��Ʋ���
	void SetDrawParam(UGDrawParamaters *pDrawParam);
	//!brief ����ͼ��
	UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing,UGProgress* pProgress = NULL);

	//!brief ����ͼ�������ݼ�����
	/**
	\param strOldName    ԭ���ݼ�����[in]
	\param strNewName    �޸ĵ����ݼ�����[in]
	\remarks �Ƿ����޸�
	*/
	UGbool OnDatasetNameChanged(const UGString &strOldName, const UGString &strNewName);
	//!brief ����ͼ��������Դ��������
	/**
	\param strOldAlias    ԭ����Դ����[in]
	\param strNewAlias    �޸ĵ�����Դ����[in]
	\remarks �Ƿ����޸�
	*/
	UGbool OnDataSourceAliasChanged(const UGString &strOldAlias, const UGString &strNewAlias);

	//!brief ��ͼ����ָ������Դ���������ݼ�����Ϊ��
	/**
	\param strDataSourceAlias    ԭ����Դ����[in]
	*/
	void OnDataSourceClose(const UGString &strDataSourceAlias);
	//!brief ��ͼ����ָ������Դ���������ݼ���
	/**
	\param strDataSourceAlias    ָ��ͼ������Դ����[in]
	\param pDataSource			 ָ��������Դ[in]
	*/
	void OnDataSourceOpen(const UGString &strDataSourceAlias,UGDataSource* pDataSource);

	//!brief  �Ƿ���ͼ���޸�
	UGbool IsModified()const;
	//!brief  ����ͼ���޸ı�־
	void SetModifiedFlag(UGbool bModified = true);	

	//!brief  ָ��ͼ���Ƿ����
	UGbool IsLayerExisted(const UGString &strName)const;
	//!brief  ָ��ͼ���Ƿ����
	UGbool IsLayerExisted(UGLayer *pLayer)const;
	//!brief  ����ͼ��ķ�Χ
	UGRect2D ComputeBounds(UGbool bComputeDatasetBounds = false);
	//!brief  �õ�ͼ��ķ�Χ
	UGRect2D GetBounds()const;

	//!brief  ����ͼ��Ϊ�ɱ༭
	//modified by xielin 2007-8-9 ��һ����������������ͼ��༭״̬Ϊfalse
	UGbool SetEditableLayer(UGint nIndex,UGbool bEditable = true);
	//!brief  �õ�ָ��ͼ����������
	UGint GetLayerIndex(const UGString &strName) const;
	//modified by dongfei 2007-04-24 ��Ϊ����ͼ����Ŀ�����޸Ĵ����ͼ������
	//!brief  �õ�ָ��ͼ�����ݼ�������ͼ��
	/**
	\param pDataset		ָ�����ݼ�[in]
	\param layersArr    ����������ͼ������[in/out]
	\remarks ���ϵ�ͼ����Ŀ
	*/
	UGint FindLayerWithDataset(UGDataset *pDataset,UGArray<UGLayer*>& layersArr) const;
	//!brief  �õ�ָ��ͼ������
	/**
	\param pLayer		ָ��ͼ��[in]
	\remarks ͼ������
	*/
	UGint FindLayer(UGLayer *pLayer) const;

	//!brief  �õ�ͼ�����
	UGint GetCount()const;
	//!brief  �������ͼ��
	void Clear();
	//modified by dongfei 2004-04-24 ����һ��Ĭ�ϲ�������ͼ����	
	//modified by xielin 2007-7-26 ����Դ�����Ͳ������ˣ��Լ������ݼ�ȡ��
	//!brief  ���ͼ��
	/**
	\param pDataset			ָ�����ݼ�[in]
	\param bAddToHead		�Ƿ��ö�[in]
	\param nType			ͼ������[in]
	\param strLayerName		ͼ����[in]
	\param pTheme			ͼ���ר��ͼ[in]
	\remarks �����ĸ�ͼ��
	*/
	UGLayer* AddDataset(UGDataset *pDataset,UGbool bAddToHead = true,UGint nType = UGLayer::UG_Layer_Normal,UGString strLayerName = "",UGTheme *pTheme = NULL);
//	UGLayer *AddDataset(UGDatasetVector *pDatasetV, const UGEventProperty& RouteEvent, UGbool bAddToHead = TRUE);
	//!brief  ɾ��ָ��ͼ��
	UGint RemoveAt(UGint nIndex, UGint nCount = 1, UGbool bComputeBounds = true);
	//!brief  ɾ������ͼ��
	void RemoveAll();

	//modified by xielin 2007-05-16 �����ͼ��༭���޸ķ��صĿɱ༭ͼ��Ϊһ��List
	//!brief  ��ȡ�༭ͼ�����
	UGList<UGLayer*> GetEditableLayer()const;
	//!brief  ��ȡָ������ͼ��
	UGLayer* GetLayerAt(UGint nIndex)const;
	//!brief  ��ȡָ�����Ƶ�ͼ��
	UGLayer* GetLayer(const UGString &strName)const;
	//added by dongfei 2004-04-24 
	//! \brief ��ȡͼ������Ӧ��һ��ͼ�� ��'#'ǰ���������ͬ
	UGint GetLayers(const UGString &strName,UGArray<UGLayer*>& pLayers)const;

	//! \brief �ƶ�ͼ��λ��
	/**
	\param nIndexFrom		��ʼλ[in]
	\param nIndexTo			�յ�λ[in]
	*/
	UGbool MoveTo(UGint nIndexFrom, UGint nIndexTo);
	//! \brief ָ�������ƶ����ײ�
	UGbool MoveBottom(UGint nIndex);
	//! \brief ָ����������һλ
	UGbool MoveDown(UGint nIndex);
	//! \brief ָ����������һλ
	UGbool MoveUp(UGint nIndex);
	//! \brief ָ��������������
	UGbool MoveTop(UGint nIndex);

	//! \brief ���ö�Ӧ�Ĺ����ռ�
	void SetWorkspace(UGWorkspace* pWorkspace);
	//! \brief �õ���Ӧ�Ĺ����ռ�
	UGWorkspace* GetWorkspace()const;

	//! \brief ʹͼ���е����ݼ���Ч
	UGbool ValidateDatasets();
//	void (UGLayers::*m_pLayersModified)(UGLayer* pLayer, UGuint nModifyLayerFlag);

	//! \brief ������XML
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��ȡXML��Ϣ
	UGbool FromXML(const UGString& strXML,UGbool bIgnoreCaption = true, UGint nVersion = 0);

	//! \brief �ص���������ͼ���޸�ʱ����
	void SetLayersModifiedFunc(LayersModifiedProc pLayersModifiedFunc, UGlong pMapWnd);

	//added by dongfei 2007-04-24
	//! \brief �ҳ�һ����ͼ�㼯��������ͼ�㲻ͬ������
	UGbool FindAvailableName(UGString& strLayerName)const;

	//! \brief �ҳ�һ����ͼ�㼯��������ר��ͼͼ�㲻ͬ��ר��ͼ���֣����ڻ���ר��ͼ��ʱ�����������ֻ�ȡ�ֶα���
	UGbool FindAvailableThemeName(UGString& strThemeName);

	//! \brief �ж�ͼ�����Ƿ���ͼ�㼯��������ͼ������ͬ
	UGbool IsvalidName(const UGString& strLayerName);

	//added by xielin 2007-04-13
	//! \brief �����Ƿ������ͼ��༭ģʽ 
	void SetMultiLayerEditEnable(UGbool bMultiLayerEditEnable);
	//added by xielin 2007-04-13
	//! \brief �����Ƿ������ͼ��༭ģʽ 
	UGbool IsMultiLayerEditEnable();

	//added by xielin 2007-04-13
	//! \brief ���õ�ǰͼ�㣬���ڶ�ͼ��༭���ڶ�ͼ��༭�У���Ϊ������ͼ��ͬʱ�༭������趨��ǰͼ�����ӵĶ���ͷŵ�
	//���õĵ�ǰͼ���У���������õ�ǰͼ�㣬Ĭ�Ͼ��ǿɱ༭�ĵ�һ��ͼ�� 
	void SetCurrentLayer(UGLayer* pLayer);

	//added by xielin 2007-04-13
	//! \brief ��ȡ��ǰͼ�㣬���ڶ�ͼ��༭���ڶ�ͼ��༭�У���Ϊ������ͼ��ͬʱ�༭������趨��ǰͼ�����ӵĶ���ͷŵ�
	//���õĵ�ǰͼ���У���������õ�ǰͼ�㣬Ĭ�Ͼ��ǿɱ༭�ĵ�һ��ͼ�� 
	UGLayer* GetCurrentLayer();
	
	//added by xielin 2007-05-16
	//! \brief �������ͼ���ѡ��
	void ClearLayersSelection();

	//added by xielin 2007-05-16
	//! \brief ��ȡ����ѡ�ж���ĸ���
	UGint GetSelectedGeometryCount();

	//added by lugw 2007-05-31
	//! \brief ������ǰ�ı�ǩר��ͼ�ö����ܣ���ר��ͼͼ�����ǰ��
	void AdjustableLayers(UGuint unOnTop);

	//!brief �����Ƿ����¼���Ĭ��Ϊtrue
	void SetNeedSendEvent(UGbool bNeedSendEvent = true);
	//!brief �����Ƿ������˷����¼�
	UGbool IsNeedSendEvent();

	void SetBeforeLayerDrawFunc(BeforeLayerDrawProc pBeforeLayerDrawFunc,UGlong pWnd);
	void SetAfterLayerDrawFunc(AfterLayerDrawProc pAfterLayerDrawFunc,UGlong pWnd);
		
	void SendBeforeLayerDrawFunc(UGbool& bCancel,UGint nLayerIndex,UGGraphics* pGraphics);
	void SendAfterLayerDrawFunc(UGint nLayerIndex,UGGraphics* pGraphics,LayerDrawReport& layerDrawReport);

	UGDataset* GetTopoLayerDs(UGDatasetTopo* pParentDataset, UGString strDatasetName)const;

	//�Ƿ�ͼ��ļ�¼��
	void ReleaseRecordset();

	UGbool m_bIsDisplayClip;
	UGGeoRegion m_DisplayClipRegion;

	UGbool m_bIsUserEntireBounds;
	UGRect2D m_rc2UserEntireBounds;	
	UGbool m_bRealeaseRecordSet;
protected:
	void CheckBounds(UGLayer *pLayer, UGbool bComputeDatasetBounds);

protected:
	LayersModifiedProc m_pLayersModifiedFunc;
	UGlong m_pMapWnd;
	UGbool m_bFireMapEvent;//�Ƿ���Ҫ���Ϳؼ����¼���Ϣ,added by xielin ��Ҫ��ͼ��Ļ����¼�
protected:
	//delete by xielin ������������ˣ�ɾ����
	//UGList<UGLayer*> m_EditableLayers;
	UGList<UGLayer*> m_Layers;
	UGArray<LayersForSaveSFC> m_LayersForSaveSFC;
	UGbool m_bModified;				//�Ƿ��޸�
	UGRect2D m_rcBounds;	
	UGbool m_bIsBoundsNull;			//ͼ���ǵ�Bounds֮���Ƿ�Ϊ��.m_rc2Bounds����ʾʱ����õġ�
									//һ��Ҫע�⣺m_rc2Bounds��Ϊ��ʱ��m_bIsBoundsNull��Ȼ����Ϊ��.
	UGWorkspace* m_pWorkspace;
	UGDrawParamaters *m_pDrawParam;
	
	//added by xielin 2007-04-13
	//! \brief �����ͼ��༭ģʽ 
	UGbool m_bMultiLayerEditEnable;
	//added by xielin 2007-04-13
	//! \brief ��ǰͼ�㣬���ڶ�ͼ��༭���ڶ�ͼ��༭�У���Ϊ������ͼ��ͬʱ�༭������趨��ǰͼ�����ӵĶ���ͷŵ�
	//���õĵ�ǰͼ���У���������õ�ǰͼ�㣬Ĭ�Ͼ��ǿɱ༭�ĵ�һ��ͼ�� 
	UGLayer* m_pCurrentLayer;        

	UGLayersRecordsetsManager m_RecordsetsManager;

	
	BeforeLayerDrawProc m_pBeforeLayerDrawFunc;
	AfterLayerDrawProc m_pAfterLayerDrawFunc;

public:
		UGlong m_pEventView;  //�����¼��ص������Ķ���ָ�룬ͳһΪһ���ɣ���ʡ�ڴ�
};

}

#endif // !defined(AFX_UGLAYERS_H__4AF37668_F0B9_4C2D_B3A1_8E638AA1B00F__INCLUDED_)
