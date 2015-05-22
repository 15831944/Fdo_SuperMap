// UGMap.h: interface for the UGMap class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGMap.h   
   **************************************************************************************
    \author   �¹���
    \brief    ��ͼ�࣬�����ͼ��ʾ�����Ĺ���                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGMAP_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_)
#define AFX_UGMAP_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_

#include "UGLayers.h"
#include "UGTrackingLayer.h"
#include "Project/UGSpatialRef.h"

namespace UGC {

class MAP_API UGMapVersionManager  
{
public:
	UGMapVersionManager();
	virtual ~UGMapVersionManager();
};

extern MAP_API UGMapVersionManager g_MapVersionManager;


//! \brief MapOpened�¼��ص�����
typedef void (UGSTDCALL *MapOpenedProc)(UGlong pWnd);

class MAP_API UGMap  
{
public:
	UGMap();
	UGMap(const UGMap& Map);
	virtual ~UGMap();
	UGMap& operator = (const UGMap &Map);

	enum OnTopType
	{
		LabelOnTop = 1,                    //��ǩ�ö�
		GraphOnTop = 2,                    //ͳ��ר��ͼ�ö�
		GraduatedSymbolOnTop = 4,          //�ȼ������ö�
	};

public:
	//! \brief  �빤���ռ佨����ϵ,���ù����ռ�
	void SetWorkspace(UGWorkspace *pWorkspace);
	//! \brief  �õ����ù����ռ�
	UGWorkspace* GetWorkspace()const;

	//! \brief  ��ʼ����ͼģʽ
	void MapModeInitialize(UGGraphics* pGraphics, const UGRect& rcDevBounds);
	//! \brief  �洢��ͼģʽ
	void MapModeRestore(UGGraphics* pGraphics);

	//! \brief  �õ���ͼ����
	UGString GetName()const;
	//! \brief  �õ���ͼ������Ϣ
	UGString GetDescription()const;
	//! \brief  ���õ�ͼ������Ϣ
	void SetDescription(const UGString& strDescription);

	//! \brief  �������ó�ʼ��״̬
	void Reset();
	//! \brief  ����ˢ�±�־
	void SetRefreshFlag(UGbool bRefresh = true);

	//! \brief  ���ø��±�־
	void SetModifiedFlag(UGbool bModified = true);
	//! \brief  �Ƿ����
	UGbool IsModified()const;

	//! \brief  ���õ�ͼͶӰ��Ϣ
	void SetPrjCoordSys(const UGPrjCoordSys& PrjCoordSys);
	const UGPrjCoordSys& GetPrjCoordSys();
	void SetPrjCoordSysUnit(UGlong nUnits);
	UGlong GetPrjCoordSysUnit();

	//! \brief  �õ���ɫģʽ
	UGint GetColorMode()const;
	//! \brief  ������ɫģʽ
	void SetColorMode(UGint nColorMode);

	//! \brief  �Ƿ��ı��̶��Ƕ�
	UGbool IsTextFixedAngle()const;
	//! \brief  ����Ϊ�ı��̶��Ƕ�
	void SetTextFixedAngle(UGbool bTextFixedAngle = true);
	//! \brief  �Ƿ���Ź̶��Ƕ�
	UGbool IsMarkerFixedAngle()const;
	//! \brief  ����Ϊ���Ź̶��Ƕ�
	void SetMarkerFixedAngle(UGbool bMarkerFixedAngle = true);
	
	//���ı����߷ֿ�����SFC����һ��
	//UGbool IsSmoothingMode()const;									
	//void SetSmoothingMode(UGbool bSmoothingMode = true);
	//! \brief  �Ƿ�Ϊ�߹⻬ģʽ
	UGbool IsLineSmoothingMode()const;
	//! \brief  �����߹⻬ģʽ
	void SetLineSmoothingMode(UGbool bSmoothingMode = true);			
	//! \brief  �Ƿ�Ϊ�ı��⻬ģʽ
	UGbool IsTextSmoothingMode()const;									
	//! \brief  �����ı��⻬ģʽ
	void SetTextSmoothingMode(UGbool bSmoothingMode = true);			
	
	//! \brief ����\��ȡ��ͼƽ����ʾ������¼�� dongfei 2007-03-26
	void SetSmoothingMaxRecord(UGint nRecordCount);	
	UGint GetSmoothingMaxRecord()const;

	//! \brief   �Ƿ�������ʾ�ص��ı� 
	UGbool IsAllowTextOverlap()const;
	//! \brief   ����Ϊ�����ص��ı�
	void SetAllowTextOverlap(UGbool bAllowTextOverlap = false);		
	//! \brief   �Ƿ�̶��ı�����
	UGbool IsFixedTextOrientation()const;							
	//! \brief   ����Ϊ�̶��ı�����
	void SetFixedTextOrientation(UGbool bFixedTextOrientation = true);	

	//! \brief   �Ƿ��ǩר��ͼ�ö�	
	UGbool IsLabelAlwaysOnTop()const;								
	//! \brief   ���ñ�ǩר��ͼ�ö�
	void SetLabelAlwaysOnTop(UGbool bLabelAlwaysOnTop = false);		

	//! \brief   ���õȼ��ֶ�ר��ͼ�ö�
	void SetGraduatedSymbolAlwaysOnTop(UGbool bGraduatedSymbolAlwaysOnTop = false);
	//! \brief   �Ƿ�ȼ��ֶ�ר��ͼ�ö�
	UGbool IsGraduatedSymbolAlwaysOnTop()const;
	
	void SetGraphAlwaysOnTop(UGbool bGraphAlwaysOnTop = false);
	//! \brief   �Ƿ�ȼ��ֶ�ר��ͼ�ö�
	UGbool IsGraphAlwaysOnTop()const;

	//! \brief   �Ƿ�Ϊ��һ�λ���
	UGbool IsFirstTimeDraw() const;

	//! \brief   �õ���С�ɼ��ı���С
	UGdouble GetMinVisibleTextSize()const;
	//! \brief   ������С�ɼ��ı���С
	void SetMinVisibleTextSize(UGdouble dVisibleTextSizeMin);		
	//! \brief   �õ����ɼ��ı���С
	UGdouble GetMaxVisibleTextSize()const;							
	//! \brief   �������ɼ��ı���С
	void SetMaxVisibleTextSize(UGdouble dVisibleTextSizeMax);		

	//! \brief   �Ƿ�̬ͶӰ
	UGbool IsProjectionOnTheFly()const;									
	//! \brief   ���ö�̬ͶӰ
	void SetProjectionOnTheFly(UGbool bProjectionOnTheFly = true);		

	//! \brief   �ж��Ƿ���æµ�׶Σ��Ƿ������жϵȲ���
	UGbool IsBusy()const;							
	//! \brief   ���ô���æµ�׶Σ��������жϵȲ���
	void SetBusy(UGbool bBusy = true);	

	UGbool IsBusyEnable()const;							
	void SetBusyEnable(UGbool bBusyEnable = true);	

	//! \brief   �õ��������
	const UGStyle& GetBkStyle()const;								
	//! \brief   ���ñ������
	void SetBkStyle(const UGStyle& style);							
	//! \brief   �õ���ת�Ƕ�
	double GetAngle()const;											
	//! \brief   ������ת�Ƕ�
	void SetAngle(double dAngle);									

	//! \brief   �Ƿ���Ʊ���
	UGbool IsPaintBackground() const;
	//! \brief   �����Ƿ���Ʊ���
	void SetPaintBackground(UGbool bPaintBackground = true);
	
	//! \brief   ��ȡ��ͼ��XML��Ϣ
	UGbool FromXML(const UGString& strXML, UGbool bIgnoreLayerCaption = true, UGint nVersion = 0);
	//! \brief   �����ͼΪXML
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief   �򿪹����ռ���ָ���ĵ�ͼ
	UGbool Open(const UGString& strMap);
	//! \brief   ���Ϊ�����ռ���ָ���ĵ�ͼ
	UGbool SaveAs(const UGString& strMap, UGbool bOverWrite = false);	
	//! \brief   �����ͼ
	UGbool Save();

	//! \brief   �ж��Ƿ���selection��Ҫ����
	UGbool RequireHignlightSelection();
	//! \brief   ��������ͼ���m_Selection
	void HignlightSelection(UGGraphics* pGraphics);
	//! \brief   ���Ʊ���
	UGbool PaintBackground(UGGraphics* pGraphics, UGRect rcErase);
	//! \brief   ���Ƶ�ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param rcDevBounds				������Ƶ��豸��Χ[in]
	\param rcInvalid				��û���õ�[in]
	\param bIsPrinting				�Ƿ��ӡ[in]
	\param bIsPrinting				�Ƿ����һҳ�Ĵ�ӡ��С��ֻ���ڴ�ӡ[in]
	\param bMapModeInitialize		�Ƿ��ʼ����ͼģʽ[in]
	\param pProgress				����������[in]
	\param bOnlyPaintBackground		�Ƿ�ֻ���Ʊ���
	\return �����Ƿ�ɹ�
	*/
	UGbool OnDraw(UGGraphics* pGraphics, UGRect rcDevBounds, UGRect rcInvalid, UGbool bIsPrinting = false, UGbool bFitToPage = false, UGbool bMapModeInitialize = true,UGProgress* pProgress = NULL,UGbool bOnlyPaintBackground = false);
	//! \brief   ���Ƶ�ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param rcDevBounds				������Ƶ��豸��Χ[in]
	\param rcMapBounds				��ͼ��Χ[in]
	\param dPrintScale				���ô�ӡ�ı���[in]
	\param bCentered				�Ƿ��ջ��Ƶ��豸��Χ�����Ĵ�ӡ[in]
	\param bMapModeInitialize		�Ƿ��ʼ����ͼģʽ[in]
	\param bPaintBackground			�Ƿ��ӡ����[in]
	\return ��ӡ�Ƿ�ɹ�
	*/
	UGbool OnPrint(UGGraphics* pGraphics, UGRect rcDevBounds, const UGRect2D& rcMapBounds, UGdouble dPrintScale, UGbool bCentered = true, UGbool bMapModeInitialize = true, UGbool bPaintBackground = false);
	//! \brief   ���Ƽ��ζ���
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param pGeometry				���Ƶļ��ζ���[in]
	\param pStyle					���Ʒ��[in]
	\return 
	*/
	UGbool DrawGeometry(UGGraphics* pGraphics, UGGeometry* pGeometry, UGStyle* pStyle = NULL);

	//! \brief   ���Ϊ��ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param rcBounds					����ͼƬ��С[in]
	\param bNoBackground			�Ƿ���Ʊ���[in]
	\param bClipContent				û���õ�[in]
	\param bCopyFromCache			û���õ�[in]
	\param bEntireMap 				�Ƿ��������[in]
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputMap(UGGraphics* pGraphics, UGRect rcBounds, UGbool bNoBackground = false, UGbool bClipContent = false, UGbool bCopyFromCache = false,UGbool bEntireMap = false);

	//! \brief   �������ͼ��
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param rcBounds					����ͼƬ��С[in]
	\param nTransparentColor		͸��ɫ������ɫ��[in]
	\param bClipContent				û���õ�[in]
	\param bEntireMap 				�Ƿ��������[in]
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputTrackingLayer(UGGraphics* pGraphics, UGRect rcBounds, UGColor nTransparentColor = UGRGB(1,1,1), UGbool bClipContent = false, UGbool bEntireMap = false);

	//! \brief   ���Ϊ��ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param szBitmap					����ͼƬ��С[in]
	\param strFileName				ͼƬ�����·��������[in]
	\param nImageType				ͼƬ����[in]
	\param bEntireMap				�Ƿ��������[in]
	\param nCompress  				�Ƿ�ѹ��[in]
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputMapToFile(UGGraphics* pGraphics, UGSize szBitmap, const UGString& strFileName, UGint nImageType, UGbool bEntireMap = false, UGint nCompress = 100);
	//! \brief   ���Ϊ��ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param pDestDataSource			���Ƶ�����Դ[in]
	\param strDatasetName			���Ƶ�����Դ�����ݼ���[in]
	\param dResolution				���Ƶı���[in]
	\param rcBounds					��ʾ��Χ[in]
	\param bShowProgress   			�Ƿ���ʾ������[in]
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGDatasetRaster* OutputMapEx(UGGraphics* pGraphics, UGDataSource* pDestDataSource, const UGString& strDatasetName, double dResolution, UGRect2D& rcBounds, UGbool bShowProgress = true);
	//! \brief   ���Ϊ��ͼ
	/**
	\param pGraphics				���Ƶ���Graphics[in]
	\param strFileName				ͼƬ���·��������[in]
	\param rcBounds					��ʾ��Χ[in]
	\param nDPI						ͼƬ����[in]
	\param bShowProgress 			�Ƿ���ʾ������[in]
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputMapToBMP(UGGraphics* pGraphics, const UGString& strFileName, UGRect2D& rcBounds, UGint nDPI = 200, UGbool bShowProgress = true);
	//! \brief   �����ͼΪeps�ļ�
	/**	
	\param strFileName				ͼƬ���·��������[in]	
	\param bTextToVector				�Ƿ�����ʸ����[in]	
		\param bEntireMap				�Ƿ�ȫ�����[in]	
	\return �����ͼ�Ƿ�ɹ�
	*/
	UGbool OutputMapToEPS(UGSize szBitmap, const UGString& strFileName, UGbool bTextToVector = false, UGbool bEntireMap = false);
	//! \brief   �õ���ͼ������
	UGdouble GetScale()const;
	//! \brief   ���õ�ͼ������
	void SetScale(UGdouble dScale);
	//! \brief   �õ���ͼ���ĵ�
	UGPoint2D GetCenter()const;										
	//! \brief   ���õ�ͼ���ĵ�
	void SetCenter(const UGPoint2D& pntCenter);						

	//! \brief   ƽ��
	void Pan(UGdouble dOffsetX, UGdouble dOffsetY);
	//! \brief   �Ŵ���С
	void Zoom(UGdouble dZoomRatio);
	//! \brief   ����
	UGbool ViewEntire(const UGRect rcDevice = UGRect(0,0,0,0));
	
	//! \brief   ��ȡ��ͼ��Χ
	UGRect2D GetBounds();
	//! \brief   �õ���ͼ��ʾ��Χ
	UGRect2D GetViewBounds();
	//! \brief   ���õ�ͼ��ʾ��Χ
	void SetViewBounds(const UGRect2D& rcMapViewBounds);

	//! \brief   ������¼�
	UGbool HitTest(UGPoint2D pntHitTest, UGdouble dTolerance, UGbool bAppendMode = false, UGbool bControlMode = false);
	//! \brief   �õ�������
	UGDrawing* GetDrawing();

	//added by xielin 2007-04-13
	//! \brief �����Ƿ������ͼ��༭ģʽ 
	void SetMultiLayerEditEnable(UGbool bMultiLayerEditEnable);
	//added by xielin 2007-04-13
	//! \brief �����Ƿ������ͼ��༭ģʽ 
	UGbool IsMultiLayerEditEnable();


	
	//added by xielin 2007-04-13
	//! \brief �����Ƿ�����༭��������ʾ 
	void SetShowTrackingTooltips(UGbool bTrackingTooltips);
	//added by xielin 2007-04-13
	//! \brief �����Ƿ�����༭��������ʾ 
	UGbool IsShowTrackingTooltips();
	
	//added by xielin 2007-04-13

	//! \brief ���õ�ǰͼ�㣬���ڶ�ͼ��༭���ڶ�ͼ��༭�У���Ϊ������ͼ��ͬʱ�༭������趨��ǰͼ�����ӵĶ���ͷŵ�
	//! ���õĵ�ǰͼ���У���������õ�ǰͼ�㣬Ĭ�Ͼ��ǿɱ༭�ĵ�һ��ͼ�� 
	void SetCurrentLayer(UGLayer* pLayer);

	//added by xielin 2007-04-13
	//! \brief ��ȡ��ǰͼ�㣬���ڶ�ͼ��༭���ڶ�ͼ��༭�У���Ϊ������ͼ��ͬʱ�༭������趨��ǰͼ�����ӵĶ���ͷŵ�
	//!���õĵ�ǰͼ���У���������õ�ǰͼ�㣬Ĭ�Ͼ��ǿɱ༭�ĵ�һ��ͼ�� 
	UGLayer* GetCurrentLayer();

	//! \brief ��ȡ��ͼ�����hashcode
	UGString GetHashCode(UGint nImageFileType) const;

	//! \brief �õ������Ƿ�ʹ����ʾ�ü�����
	UGbool IsDisplayClip() const;						
	//! \brief �õ��Ƿ�ʹ����ʾ�ü�����
	void SetDisplayClip(UGbool bIsDisplayClip);			

	//! \brief �õ���ʾ�ü�����
	void GetDisplayClipRegion(UGGeoRegion& geoClipRegion);
	//! \brief �õ��Ƿ�ʹ����ʾ�ü�����
	void SetDisplayClipRegion(UGGeoRegion& geoClipRegion);

	//! \brief �Ƿ���ʾ�û�ָ����Χ
	UGbool IsUserEntireBounds();
	//! \brief �趨�Ƿ���ʾ�û�ָ����Χ
	void SetIsUserEntireBounds(UGbool bIsUserEntireBounds);

	//! \brief �õ��û�ָ����ʾ��Χ
	UGRect2D GetUserEntireBounds();
	//! \brief �û�ָ����ʾ��Χ
	void SetUserEntireBounds(const UGRect2D& rc2UserEntireBounds);

	//! \brief �����û�ָ����ʾ����
	void SetDisplayScales(UGArray<UGdouble> arrDisplayScales);
	//! \brief �õ��û�ָ����ʾ����
	void GetDisplayScales(UGArray<UGdouble>& arrDisplayScales);
	//! \brief �Ƿ�����û���ʾ����
	void SetDisplayByScales(UGbool bDisplayByScales);
	//! \brief �����Ƿ�����û���ʾ����
	UGbool IsDisplayByScales() const;
	//! \brief ��ȡ/��������ʾ�Ķ������ڵ�������������ڵ�Ķ���Ͳ���ʾ
	UGint GetMaxVisibleVertex() const;
	void SetMaxVisibleVertex(UGint nMaxVisibleVertex);

	//added by xielin 2007-11-15 ����һ���ӿڣ��������û���ͼ����Ƿ������ͷż�¼��
	//! \brief ��ȡ/���û���ͼ����Ƿ������ͷż�¼����Ĭ��iserver��Ʒ�����ͷţ���������Ʒ�������ͷţ���Ϊ��׽��ѡ�񶼻��õ���ʾ�ļ�¼��
	void SetReleaseDisplayRecordset(UGbool bRelease = true);
	UGbool IsReleaseDisplayRecordset();
	
protected:	
	void ZoomWhenFirstViewMap();
	void SetMapOpenedFunc(MapOpenedProc pMapOpenedFunc, UGlong pMapWnd);
	void SendMapOpenedFunc();
public:
	UGLayers m_Layers;
	UGTrackingLayer m_TrackingLayer;
	UGint m_nMarginWidthViewEntire;
	//deleted by xielin 2007-05-16 ��Ϊÿ��layer����һ��m_Selection,�ó�Ա����������
	//UGSelection	m_Selection;
	//added by xielin 2007-08-21 
	//! \brief �жϵ�ͼ�Ƿ�����ˢ�¡��������»��ƶ����ˡ��ڱ༭��ʱ���õ�
	UGbool m_bRefresh;
	MapOpenedProc m_MapOpenedFunc;

protected:	
	UGDrawing m_Drawing;

public:
	UGString m_strName;

protected:	
	UGString m_strDescription;			//ͼ������
	
	UGbool m_bForceToRefresh;
	UGbool m_bModified;
	UGPrjCoordSys m_PrjCoordSys;

	UGbool m_bAllowTextOverlap;			//�����ı�����
	UGuint m_unOnTop;
	//UGbool m_bLabelAlwaysOnTop;			//��ǩר��ͼ�ö�
	//UGbool m_bGraduatedSymbolAlwaysOnTop;//�ȼ�����ר��ͼ�ö�
	//UGbool m_bGraphAlwaysOnTop;			//ͳ��ר��ͼ�ö�
	UGbool m_bFirstTimeDraw;	

	UGint m_nPreMapMode;
	UGPoint m_pntWndOrg;

	UGbool m_bPaintBackground;

	//added by xielin 2007-04-13  
	//! \brief ������ʾ�༭�����е���ʾ 
	UGbool m_bShowTrackingTooltips;

	UGbool m_bDisplayByScales;
	UGArray<UGdouble> m_arrDisplayScales;

	
	UGlong m_pMapWnd;
};

}

#endif // !defined(AFX_UGMAP_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_)
