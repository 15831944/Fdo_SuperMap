// UGMapWnd.h: interface for the UGMapWnd class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGMapWnd.h
   **************************************************************************************
    \author   �¹���
    \brief    ��ͼ����ģ���࣬�����ͼ�Ļ��Ƽ���ͼ���ڵ���Ϣ����                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGMAPWND_H__68C39D42_D336_4C1A_8C4D_FCEB87806120__INCLUDED_)
#define AFX_UGMAPWND_H__68C39D42_D336_4C1A_8C4D_FCEB87806120__INCLUDED_

#include "Map/UGMap.h"
#include "Editor/UGEditToolPack.h"
#include "Editor/UGRegionSelect.h"
#include "Base/ugplatform.h"
#include "Engine/UGDataHistory.h"

namespace UGC {

// by zengzm 2007-3-26 ��__stdcall���嵽ugplatform��
typedef void (UGSTDCALL *INVALIDATEPROC)(UGlong pData);
//#ifdef WIN32
//typedef void (__stdcall *INVALIDATEPROC)(UGuint pData);
//#else
//typedef void (*INVALIDATEPROC)(UGuint pData);
//#endif
//added by xielin 2007-06-05 ����mapwnd���¼����ûص�������ʵ��
//! \brief BeforeGeometryDeleted�¼��ص�����
typedef void (UGSTDCALL *BeforeGeometryDeletedProc)(UGlong pWnd,UGbool& bCancel,UGint nGeometryID,UGLayer* pLayer);
//! \brief AfterGeometryAdded �¼��ص�����
typedef void (UGSTDCALL *AfterGeometryAddedProc)(UGlong pWnd,UGint nGeometryID,UGLayer* pLayer);
//! \brief AfterGeometryModified �¼��ص�����
typedef void (UGSTDCALL *AfterGeometryModifiedProc)(UGlong pWnd,UGint nGeometryID,UGLayer* pLayer);
//! \brief BeforeGeometryModified �¼��ص�����
typedef void (UGSTDCALL *BeforeGeometryModifiedProc)(UGlong pWnd,UGbool& bCancel,UGint nGeometryID,UGLayer* pLayer);
//! \brief BeforeTrackingLayerDraw �¼��ص�����
typedef void (UGSTDCALL *BeforeTrackingLayerDrawProc)(UGlong pWnd,UGbool& bCancel,UGGraphics* pGraphics);
//! \brief AfterTrackingLayerDraw �¼��ص�����
typedef void (UGSTDCALL *AfterTrackingLayerDrawProc)(UGlong pWnd,UGGraphics* pGraphics);
//! \brief BeginEditHandle �¼��ص�����
typedef void (UGSTDCALL *BeginEditHandleProc)(UGlong pWnd,UGbool& bCancel,UGint nHandle,
											  UGdouble dx,UGdouble dy);
//! \brief MovingEditHandle �¼��ص�����
typedef void (UGSTDCALL *MovingEditHandleProc)(UGlong pWnd,UGbool& bCancel,UGint nHandle,
											  UGdouble dx,UGdouble dy);
//! \brief EditHandleCanceled �¼��ص�����
typedef void (UGSTDCALL *EditHandleCanceledProc)(UGlong pWnd,UGint nHandle);
//! \brief EndEditHandle �¼��ص�����
typedef void (UGSTDCALL *EndEditHandleProc)(UGlong pWnd,UGint nHandle,
											  UGdouble dx,UGdouble dy);
//! \brief GeometrySelected �¼��ص�����
typedef void (UGSTDCALL *GeometrySelectedProc)(UGlong pWnd,UGint nSelectedGeometryCount);
//! \brief Tracking �¼��ص�����
typedef void (UGSTDCALL *TrackingProc)(UGlong pWnd,UGdouble dx,UGdouble dy,UGint nButtonClicked,
											   UGdouble dCurrentLength,UGdouble dCurrentAngle,UGdouble dTotalLength,
											   UGdouble dTotalArea);
//! \brief Tracked �¼��ص�����
typedef void (UGSTDCALL *TrackedProc)(UGlong pWnd);

//! \brief AfterPointInput �¼��ص�����
typedef void (UGSTDCALL *AfterPointInputProc)(UGlong pWnd,UGdouble& dx,UGdouble& dy,UGdouble& dz);

//! \brief BeforeMapDraw �¼��ص�����
typedef void (UGSTDCALL *BeforeMapDrawProc)(UGlong pWnd,UGbool& bCancel,UGGraphics* pGraphics);

//! \brief AfterMapDraw �¼��ص�����
typedef void (UGSTDCALL *AfterMapDrawProc)(UGlong pWnd,UGGraphics* pGraphics);


class EDITOR_API UGMapWnd  
{

	friend class UGEditToolPack;
public:
	enum UGMarginPanMode
	{
		Other		=0,
		Left		=1,
		Top			=2,
		Right		=3,
		Bottom		=4,
		TopLeft		=5,
		TopRight	=6,
		BottomRight	=7,
		BottomLeft	=8
	};
	// ѡ��ģʽ
	enum UGSelectionMode
	{
		smContainCentroid,		//��������
		smAreaIntersect,		//����ཻ
		smContainObject		//��������
	};

	//added by xielin 2007-06-19 ���������״ö�ٱ����������״�Ĵ�������ugc�д����ϲ����������״��ʱ��ֱ��ͨ��һ��������ȡö�ٱ����Ϳ��ԣ������ʡ������
	enum UGCursorShape
	{
		ecBusy = 1,				//æ���
		ecArrow,				//��ͨ��ͷ���
		ecMarginPanLeft,		//�Զ�����������
		ecMarginPanRight,		//�Զ��������ҹ��
		ecMarginPanTop,			//�Զ��������Ϲ��
		ecMarginPanBottom,		//�Զ��������¹��
		ecMarginPanTopLeft,		//�Զ��������Ϲ��
		ecMarginPanTopRight,	//�Զ��������Ϲ��
		ecMarginPanBottomRight,	//�Զ��������¹��
		ecMarginPanBottomLeft,	//�Զ��������¹��
		ecZoomFree,				//�������Ź��
		ecZoomFree2,			//�������Ź��
		ecPan,					//ƽ�ƹ��
		ecPan2,					//ƽ�ƹ��
		ecZoomIn,				//�Ŵ���
		ecZoomOut,				//��С���
		ecPointModeSelect,		//��ѡ���
		ecPointModeSelectTrue,	//����ѡ���
		ecRectModeSelect,		//����ѡ����
		ecCircleModeSelect,		//Բ��ѡ����
		ecRegionModeSelect,		//�����ѡ����
		ecLineModeSelect,		//����ѡ����
		ecDrawPoint,			//���Ƶ���
		ecDrawLineSect,			//����ֱ�߹��
		ecDrawPolyLine,			//�������ߡ����Զ�ʸ�����ߵȹ��
		ecDrawEllipseArc,		//������Բ�����
		ecDrawArc3P,			//�������㻡���
		ecDrawCurve,			//�������߹�꣬����b������cardinal����������
		ecDrawRectangle,		//���ƾ��ι��
		ecDrawRoundRect,		//����Բ�Ǿ��ι��
		ecDrawCircle,			//����Բ��Բ���
		ecDrawCircle3P,			//��������Բ���
		ecDrawCircle2P,			//��������Բ���
		ecDrawEllipse,			//������Բ���
		ecDrawObliqueEllipse,	//����б��Բ���
		ecDrawPolyGon,			//���ƶ���Ρ����Զ�ʸ������ȹ��
		ecDrawText,				//�����ı����
		ecDrawStreamText,		//��������ע�ǹ��
		ecDrawParallel,			//����ƽ���߹��
	    ecCross,				//ʮ�ֹ��
        ecRotation,				//��ת���
        ecBeam,					//���ֹ��
        ecMove,					//�ƶ����
		ecNorthSouth,			//�ϱ��ƶ����
		ecWestEast,				//�����ƶ����
		ecNorthwestSoutheast,	//����<->�����ƶ����
		ecNortheastSoutnwest,	//����<->�����ƶ����
		ecCrossSnapPoint,		//�㲶׽���
		ecCrossSnapVertex,		//���㲶׽���
		ecCrossSnapMidpoint,	//�߶��е㲶׽���
		ecCrossSnapLine,		//���ϲ�׽���
		ecCrossSnapVertical,	//��ֱ��׽���
		ecCrossSnapParallel,	//ƽ�в�׽���
		ecMoveRotateBase,		//��ת������
	};

public:
	UGMapWnd();
	virtual ~UGMapWnd();

public:	
	void Initialize(UGbool bInitEditEnvironment = true);
	void Reset(UGbool bClearWorkspace = false);
	void SetEditEnvironment();							//���ñ༭����
	UGWorkspace* GetWorkspace();						//ȡ�ù����ռ�
	void AttachWorkspace(UGWorkspace *pSmWorkspace);	//�빤���ռ佨����ϵ
	void OnClose();

	UGbool IsEditEnabled()const;								//��ǰ��ͼ�Ƿ�ɱ༭
	//���������ȷ����ͼ��ѡ�ж���
	UGbool HitTest(UGPoint2D pntHitTest, UGbool bAppendMode = false, UGbool bControlMode = false);
	UGbool IsHittestBorderOnly()const;
	void SetHittestBorderOnly(UGbool bBorderOnly = true);	
	UGbool IsHotKeyEnabled() const;
	void SetHotKeyEnabled(UGbool bEnabled);

	void ViewEntire(const UGRect rcDevice = UGRect(0,0,0,0));									//ȫ����ʾ��ͼ
	void Pan(UGdouble dOffsetX, UGdouble dOffsetY);	//ƽ��
	void Zoom(UGdouble dZoomRatio);						//�Ŵ���С
	void SetCenter(const UGPoint2D& pnt2Center);		//���õ�ͼ���ĵ�
	void SetScale(UGdouble dScale);					//���ñ�����
	UGPoint2D GetCenter()const;								//ȡ�����ĵ�

	void Refresh();									//ˢ��
	void RefreshTrackingLayer(UGbool bValidateRect = false);//ˢ�¸���ͼ��
	UGbool OnDraw(UGGraphics* pGraphics, UGRect rcDevBounds, UGRect rcInvalid, UGbool bIsPrinting = false, UGbool bFitToPage = false);
	UGbool OnPrint(UGGraphics* pGraphics, UGRect rcDevBounds, const UGRect2D& rcMapBounds, UGdouble dPrintScale, UGbool bCentered = true, UGbool bPaintBackground = false);
	
	UGint GetUserAction();			//ȡ�õ�ǰ�ĵ�ͼ����
	void SetUserAction(UGint nUserAction, UGint nEditUserAction = 0);
	UGint SetSubAction(UGint nSubAction);

	void OnLayersModified(UGLayer* pLayer, UGuint nModifyLayerFlag);
	void OnMapOpened();

	UGbool OnChar(UGGraphics* pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);
	UGbool OnKeyDown(UGGraphics* pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);
	UGbool OnLButtonDblClk(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnLButtonDown(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnLButtonUp(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnMouseMove(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnMouseWheel(UGGraphics* pGraphics, UGuint nFlags, UGshort zDelta, UGPoint point);
	UGbool OnRButtonDblClk(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnRButtonDown(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnRButtonUp(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnSize(UGGraphics* pGraphics, const UGRect& rcNewClient);

	UGint GetSelectionMode()const;
	void SetSelectionMode(UGint nSelectionMode); 
	
	UGdouble GetSelectionTolerance()const;
	void SetSelectionTolerance(UGdouble dSelectionTolerance); 

	UGRect GetClipRect()const;
	void SetClipRect(const UGRect &rcClipRect);

	//ײǽ����
	void CheckMarginPanMode(UGPoint point);

	UGRect2D GetBounds();
	UGRect2D GetViewBounds();
	void SetViewBounds(const UGRect2D& rcMapViewBounds);
	
	//deleted by xielin 2007-05-16 ���ﲻ����selection��
	//UGSelection* GetSelection();
	UGEditToolPack* GetEditToolPack();//ȡ�ñ༭���߰�

	UGbool SelectWithCircle(const UGPoint2D &pnt2Center, UGdouble dRadius, UGbool bShiftMode = false, UGbool bControlMode = false);
	UGbool SelectWithRect(const UGRect2D &rcSelection, UGbool bShiftMode = false, UGbool bControlMode = false);
	UGbool SelectWithRegion(UGGeoRegion &regSelection, UGbool bShiftMode = false, UGbool bControlMode = false);
	
	UGint GetMarginPanWidth();						//ײǽ���α߿�
	void SetMarginPanWidth(UGint nMarginPanWidth);	

	UGint GetMarginPanMode();						//ײǽ����ģʽ

	UGdouble GetMarginPanPercent();					//ײǽ���ΰٷֱ�
	void SeMarginPanPercent(UGdouble dMarginPanPercent);	

	UGbool IsMarginPanEnable();					//ײǽ�������
	void SetMarginPanEnable(UGbool bMarginPanEnable);	

	UGbool IsCursorBusy()const;							
	void SetCursorBusy(UGbool bCursorBusy = true);	

	UGbool IsBusyCursorEnable()const;							
	void SetBusyCursorEnable(UGbool bBusyCursorEnable = true);	

	void SetInvalidateFunc(INVALIDATEPROC pInvalidateFunc, UGlong pWnd);	
	void SetDrawCallBackFunc(DRAWCALLBACKPROC pDrawCallBackFunc, UGlong pWnd);
	void SetDrawPaintFunc(DRAWPAINTPROC pDrawPaintFunc, UGlong pPaintWnd);
	
	void SendInvalidateFunc();

	//added by xielin 2007-04-30 
	//! \brief ������չ����ı༭�����ĵ���������ﵽ����������������ͽ������ƹ���
	//! \param nCount �����µĵ���
	void SetEndEditDragCount(UGint nCount);

	//modified by xielin 2007-09-12 ��Ϊundo�Ȳ�����Ҫȥˢ��graphics�����graphics���Ǵ��ⲿ����Ƚϱ���
	//��ô�޸�һ�½ӿڣ��ⲿ���õ�ʱ����봫��graphics
	//added by xielin 2007-05-15
	//! \brief ɾ��ѡ�ж���
	UGbool OnDelete(UGGraphics* pGraphics);
	//! \brief �Ƿ���Լ���
	UGbool CanCut();
	//! \brief �Ƿ����ճ��
	UGbool CanPaste();
	//! \brief �Ƿ���Կ���
	UGbool CanCopy();
	//! \brief �Ƿ�����ظ�
	UGbool CanRedo();
	//! \brief �Ƿ���Գ���
	UGbool CanUndo();
	//! \brief ����
	UGbool Cut(UGGraphics* pGraphics);//
	//! \brief ճ��
	UGbool Paste(UGGraphics* pGraphics);
	//! \brief ����
	UGbool Copy(UGGraphics* pGraphics);
	//! \brief ����
	UGbool Redo(UGGraphics* pGraphics);
	//! \brief �ָ�
	UGbool Undo(UGGraphics* pGraphics);
	
	//! \brief �����Ƿ���java�����ڵ��ã�ע�⣬�����java���ã�һ��Ҫ��wrapj������һ�£���Ϊjava��.net��ˢ�»��Ʋ�һ��
	void SetUsedByJava(UGbool bJava = true);
	
	//! \brief �����Ƿ�java�����ڵ���
	UGbool GetUsedByJava();

	//�ص�����������ʵ��mapwnd���¼�
	void SetBeforeGeometryDeletedFunc(BeforeGeometryDeletedProc pBeforeGeometryDeletedFunc,UGlong pWnd);
	void SetAfterGeometryAddedFunc(AfterGeometryAddedProc pAfterGeometryAddedFunc,UGlong pWnd);
	void SetAfterGeometryModifiedFunc(AfterGeometryModifiedProc pAfterGeometryModifiedFunc,UGlong pWnd);
	void SetBeforeGeometryModifiedFunc(BeforeGeometryModifiedProc pBeforeGeometryModifiedFunc,UGlong pWnd);
	void SetBeforeTrackingLayerDrawFunc(BeforeTrackingLayerDrawProc pBeforeTrackingLayerDrawFunc,UGlong pWnd);
	void SetAfterTrackingLayerDrawFunc(AfterTrackingLayerDrawProc pAfterTrackingLayerDrawFunc,UGlong pWnd);
	void SetBeginEditHandleFunc(BeginEditHandleProc pBeginEditHandleFunc,UGlong pWnd);
	void SetMovingEditHandleFunc(MovingEditHandleProc pMovingEditHandleFunc,UGlong pWnd);
	void SetEditHandleCanceledFunc(EditHandleCanceledProc pEditHandleCanceledFunc,UGlong pWnd);
	void SetEndEditHandleFunc(EndEditHandleProc pEndEditHandleFunc,UGlong pWnd);
	void SetGeometrySelectedFunc(GeometrySelectedProc pGeometrySelectedFunc,UGlong pWnd);
	void SetTrackingFunc(TrackingProc pTrackingFunc,UGlong pWnd);
	void SetTrackedFunc(TrackedProc pTrackedFunc,UGlong pWnd);
	void SetAfterPointInputFunc(AfterPointInputProc pAfterPointInputFunc,UGlong pWnd);
	void SetBeforeMapDrawFunc(BeforeMapDrawProc pBeforeMapDrawFunc,UGlong pWnd);
	void SetAfterMapDrawFunc(AfterMapDrawProc pAfterMapDrawFunc,UGlong pWnd);

	void SendBeforeGeometryDeletedFunc(UGbool& bCancel,UGint nGeometryID,UGLayer* pLayer);
	void SendAfterGeometryAddedFunc(UGint nGeometryID,UGLayer* pLayer);
	void SendAfterGeometryModifiedFunc(UGint nGeometryID,UGLayer* pLayer);
	void SendBeforeGeometryModifiedFunc(UGbool& bCancel,UGint nGeometryID,UGLayer* pLayer);
	void SendBeforeTrackingLayerDrawFunc(UGbool& bCancel,UGGraphics* pGraphics);
	void SendAfterTrackingLayerDrawFunc(UGGraphics* pGraphics);
	void SendBeginEditHandleFunc(UGbool& bCancel,UGint nHandle,
											  UGdouble dx,UGdouble dy);
	void SendMovingEditHandleFunc(UGbool& bCancel,UGint nHandle,
											  UGdouble dx,UGdouble dy);
	void SendEditHandleCanceledFunc(UGint nHandle);
	void SendEndEditHandleFunc(UGint nHandle,UGdouble dx,UGdouble dy);
	void SendGeometrySelectedFunc(UGint nSelectedGeometryCount);
	void SendTrackingFunc(UGdouble dx,UGdouble dy,UGint nButtonClicked,
											   UGdouble dCurrentLength,UGdouble dCurrentAngle,UGdouble dTotalLength,
											   UGdouble dTotalArea);
	void SendTrackedFunc();
	void SendAfterPointInputFunc(UGdouble& dx,UGdouble& dy,UGdouble& dz);
	void SendBeforeMapDrawFunc(UGbool& bCancel,UGGraphics* pGraphics);
	void SendAfterMapDrawFunc(UGGraphics* pGraphics);
	//�ص�����������ʵ��mapwnd���¼� end
	
	//!brief ��������Ŵ�����ѡ��Ȳ���ʱ��tracking�ϻ��Ƶķ��
	void SetTrackingZoomAndSelectStyle(const UGStyle& style);
	//!brief ��������Ŵ�����ѡ��Ȳ���ʱ��tracking�ϻ��Ƶķ��
	const UGStyle&  GetTrackingZoomAndSelectStyle();
	//!brief �����Ƿ����¼���Ĭ��Ϊtrue
	void SetNeedSendEvent(UGbool bNeedSendEvent = true);
	//!brief �����Ƿ������˷����¼�
	UGbool IsNeedSendEvent();

	//�༭��صķ������

	//!brief ���ý���ʽ���Ƽ��ζ���ʱ����ɫ
	void SetTrackingStyle(const UGStyle& style);
	//!brief ���ؽ���ʽ���Ƽ��ζ���ʱ����ɫ
	const UGStyle& GetTrackingStyle();

	//!brief ���ò�׽�ߵ���ɫ
	void SetSnapedLineColor(UGColor color);
	//!brief ���ز�׽�ߵ���ɫ
	const UGColor GetSnapedLineColor();

	//!brief ���ò�׽���ĵ����ɫ
	void SetSnapedPointColor(UGColor color);
	//!brief ���ز�׽���ĵ����ɫ
	const UGColor GetSnapedPointColor();
	
	//!brief ���þ��岶׽�Ĳ�׽�����񣬱������õ��ڵ��ϵĲ�׽���,ע�⣬�ڲ�ʵ���Ǹ�����һ��pStyle����ָ���ⲿ�Լ������ͷ�
	void SetSnapedStyle(UGint nSnapType,UGStyle* pStyle);

	//!brief ��ȡ���岶׽�Ĳ�׽�����񣬱����ȡ���ڵ��ϵĲ�׽�����������ã�Ĭ�϶���NULL��ע�⣬���ص����ڲ�ָ�����ã��벻Ҫ�ⲿ�ͷ�
	UGStyle* GetSnapedStyle(UGint nSnapType);

	//!brief ���û��ƶ���ʱ�����ߵķ��
	void SetAssistantLineStyle(const UGStyle& style);
	//!brief ���ػ��ƶ���ʱ�����ߵķ��
	const UGStyle& GetAssistantLineStyle();
	//!brief ���û��ƶ����Ĭ�Ϸ�񣬸÷�񽫱��浽������
	void SetDefaultStyle(const UGStyle& style);
	//!brief ��ȡ���ƶ����Ĭ�Ϸ�񣬸÷�񽫱��浽������
	const UGStyle& GetDefaultStyle();
	//�༭��صķ������ end

	//!brief ���������״����Ҫ���ڲ�ʹ�ã��ڽ���ʽ�༭��ʱ�����������״ö�ٱ���
	void SetCursorShape();
	//!brief ��ȡ�����״����Ҫ���ⲿʹ�ã��ڽ���ʽ�༭��ʱ��ͨ���ú����������ö�ٱ������ϲ���������Ӧ�����״
	UGMapWnd::UGCursorShape GetCursorShape();

	//!brief �Ƿ񿪷ű༭ģ�飬�����Ժ����������ͼ��Ŀɱ༭״̬��Ҳ�޷��༭,Ĭ��ֵΪtrue
	void SetOpenEditMode(UGbool bOpenEditMode = false);
	UGbool IsOpenEditMode();
public:
	UGMap m_Map;
	UGRegionSelect m_RgnSelect;				//���Ρ�Բ�Ρ������ѡ��ʹ�õ�ѡ������
	UGRegionSelect m_RgnZoom;				//ZoomIn��ZoomOutʹ�õ�ѡ������ 
	UGbool m_bFireMapEvent;//�Ƿ���Ҫ���Ϳؼ����¼���Ϣ,added by xielin ��ͼ�༭��ʱ�����ã������ûص�������������Ϣ
	//added by xielin 2007-05-22 ��ʷ����
	UGDataHistory* m_pDataHistory;
protected:
	INVALIDATEPROC m_pInvalidateFunc;

public:
	UGlong m_pView;
protected:
	
	//!brief ��ʷ��¼�޸ĺ�(����/����),��Ҫˢ�µ�ͼ��ѡ��״̬,����������������������
	UGbool RefreshEditDataHistory();
	
	//!brief ʰȡ���󣬷ŵ�toolpack�У�Ҫ���Ƕ�ͼ��༭�����
	UGbool PickObjects(UGGraphics* pGraphics); 

	//!brief ���ö���ѡ�б༭ʱ�������״���ڲ�ʹ�ã������⿪�ţ���Ҫ��SetCursorShape��ʹ��,����ֵ��ʾ�Ƿ������ö���༭�����״
	UGbool SetEditCursorShape();
protected:
	UGEditToolPack m_EditToolPack;

	UGint m_nSelectionMode;
	UGint m_nMaxSelBufSize;			//���ѡ�񼯵Ļ�������С
	UGint m_nToleranceSelection;

	UGint m_nMarginPanWidth;					//ײǽ���α߿�
	UGint m_nMarginPanMode;						//ײǽ����ģʽ
	UGdouble m_dMarginPanPercent;				//ײǽ���ΰٷֱ�
	UGbool m_bMarginPanEnable;					//ײǽ�������
		
	UGPoint m_pntLastPoint;
	UGbool m_bLBtnDown;
	UGbool m_bHotKeyEnabled;
	UGbool m_bNewObjAutoSelected;				//����ӵĶ����Ƿ�������ѡ��
	UGbool m_bHittestBorderOnly;

	UGRect m_rcClipRect;

	UGString m_strCopyDsFileName ;              //����ճ����ʱ�򱣴��udb����Դ�ļ���
	UGString m_strCopyDsAlias;					//����ճ����ʱ�򱣴��udb����Դ����

	//! \brief �����Ƿ���java�����ڵ��ã�ע�⣬�����java���ã�һ��Ҫ��wrapj������һ�£���Ϊjava��.net��ˢ�»��Ʋ�һ��
	UGbool m_bIsJava;					
	
	//�¼���ر���
	UGlong m_pEventView;  //�����¼��ص������Ķ���ָ�룬ͳһΪһ���ɣ���ʡ�ڴ�
	BeforeGeometryDeletedProc m_pBeforeGeometryDeletedFunc;
	AfterGeometryAddedProc m_pAfterGeometryAddedFunc;
	AfterGeometryModifiedProc m_pAfterGeometryModifiedFunc;
	BeforeGeometryModifiedProc m_pBeforeGeometryModifiedFunc;
	BeforeTrackingLayerDrawProc m_pBeforeTrackingLayerDrawFunc;
	AfterTrackingLayerDrawProc m_pAfterTrackingLayerDrawFunc;
	
	BeginEditHandleProc m_pBeginEditHandleFunc;
	MovingEditHandleProc m_pMovingEditHandleFunc;
	EditHandleCanceledProc m_pEditHandleCanceledFunc;
	GeometrySelectedProc m_pGeometrySelectedFunc;
	TrackingProc m_pTrackingFunc;
	TrackedProc m_pTrackedFunc;
	EndEditHandleProc m_pEndEditHandleFunc;
	AfterPointInputProc m_pAfterPointInputFunc;
	BeforeMapDrawProc m_pBeforeMapDrawFunc;
	AfterMapDrawProc m_pAfterMapDrawFunc;
	//�¼���ر��� end

	//added by xielin 2007-06-13
	//!brief ���������û���LButtonDown���¼��д����Graphics����Ϊ�ڻ��˵Ȳ�����Ҫ�õ�
	UGGraphics* m_pUserGraphics;

	UGPoint3D m_pnt3DInput;

	//!brief ����Ŵ���С��ѡ��ʱ��ķ��
	UGStyle m_ZoomAndSelectStyle;
	//!brief ���ƶ���ķ�񣬱��浽������
	UGStyle m_DefaultStyle;
	//!brief ���������״ö�ٱ���
	UGCursorShape m_nCursorShape; 
	
	//!brief ��һ�����������������Ƿ񿪷ű༭ģ�飬�����Ϊfalse�������Ƿ�����ͼ��ɱ༭���������ű༭ģ��
	//2.0�о��Ȳ����ű༭ģ�飬
	UGbool m_bOpenEditMode;
	
	

};

}

#endif // !defined(AFX_UGMAPWND_H__68C39D42_D336_4C1A_8C4D_FCEB87806120__INCLUDED_)
