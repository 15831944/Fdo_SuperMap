// UGEditToolPack.h: interface for the UGEditToolPack class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGEditToolPack.h
   **************************************************************************************
    \author   �¹���
    \brief    �༭���߰��࣬�����б༭��������ڣ��༭����ѡ�������ʾ��
			  ����ͼ�㶼��������ʾ��                                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGEDITTOOLPACK_H__5911E61C_A45F_4FC6_BD25_09F9F966F03F__INCLUDED_)
#define AFX_UGEDITTOOLPACK_H__5911E61C_A45F_4FC6_BD25_09F9F966F03F__INCLUDED_

#include "Map/UGMap.h"
#include "Editor/UGEditOperater.h"
#include "Editor/UGEditTool.h"
#include "Editor/UGEditCompoundTool.h"
#include "Algorithm/UGPoint.h"
#include "Editor/UGEditDef.h"
#include "Editor/UGEditSnapGrid.h"
#include "Editor/UGEditSnapBuffer.h"
#include "Editor/UGEditToolSnapPack.h"
#include "Base/UGDict.h"

namespace UGC {



// �༭�ֱ�ѡ�� cgx-2004-2-18
enum UGEditHandleOption
{
	UG_EHO_LEFTBOTTOM					=	0x00000001,	//���½�
	UG_EHO_BOTTOMCENTER					=	0x00000002,	//���е�
	UG_EHO_BOTTOMRIGHT					=	0x00000004,	//���½�
	UG_EHO_LEFTCENTER					=	0x00000008,	//���е�
	UG_EHO_RIGHTCENTER					=	0x00000010,	//���е�
	UG_EHO_TOPLEFT						=	0x00000020,	//���Ͻ�
	UG_EHO_TOPCENTER					=	0x00000040,	//���е�
	UG_EHO_TOPRIGHT						=	0x00000080,	//���Ͻ�
	UG_EHO_ROTATION						=	0x00000100,	//��ת
	UG_EHO_ROTATEBASE					=	0x00000200,	//��ת����
	UG_EHO_MOVE							=	0x00000400,	//�ƶ�
	UG_EHO_VERTEX						=	0x00000800,	//�༭����
};


//added by xielin 2007-05-24
//��ǰ�ı༭����,�������ֹ���,geometry����,�����id,�������ڵ�ͼ��
struct EditGeometry {
	UGGeometry* pGeometry;
	UGint nID;
	UGLayer* pLayer;
	EditGeometry()
	{
		nID = -1;
		pLayer = NULL;
		pGeometry = NULL;
	}
};

class EDITOR_API UGTrackParameter
{
public:
	UGTrackParameter();
	virtual ~UGTrackParameter();
public:
	UGdouble		m_dFilter;						//���˲�����ֵԽ���Խ�٣�
	UGlong		m_lSmooth;						//�⻬��������ֵ�ĵ�����
	UGlong		m_lColorTolerance;				//��ɫ����ֵ��
	UGbool		m_bAutoPan;						//�Ƿ��Զ�������
	UGColor	m_crRasterBack;					//ָ��դ�񱳾�ɫ��
	UGDatasetRaster *m_pDatasetRaster;			//դ�����ݼ�
};

class UGMapWnd;

class EDITOR_API UGEditToolPack  
{

	friend class UGMapWnd;
	//added by xielin 
	friend class UGEditTool;
    friend class UGEditCompoundTool;
    friend class UGEditSingleObjTool;
    friend class UGEditSelectTool;

	friend class UGEditOperater;
	//added by xielin end 
public:
	UGEditToolPack();
	virtual ~UGEditToolPack();

public:	
	void Reset();

	void SetUserAction(UGint nAction);
	UGint SetSubAction(UGint nSubAction);
	UGint GetUserAction();
	UGint GetSubAction();

	void AttachMapWnd(UGMapWnd* pMapWnd);
    UGbool SetEditEnvironment();
    UGbool ClearSelection(UGGraphics* pGraphics, UGbool bSave = false);         //���ѡ��
	UGbool OnDraw(UGGraphics* pGraphics, UGbool bDrawHandle = true, UGbool bDrawTool = true, UGbool bIsRefresh = false, UGbool bJava = false);
	UGbool InvalidRect(UGGraphics* pGraphics, const UGRect& rect, UGbool bDrawHandle = true, UGbool bDrawTool = false, UGbool bJava = false);

	UGImage* GetMemImage();
	UGGraphics* GetMemGraphics();	
	void InflateRect(UGRect& rect);

	//added by xielin ^_^
	UGbool OnRButtonDblClk(UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnRButtonUp    (UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnRButtonDown  (UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnLButtonUp    (UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnLButtonDown  (UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnLButtonDblClk(UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnMouseMove    (UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnSetCursor    (UGGraphics* pGraphics,UGuint nHitTest, UGuint message);
    UGbool OnKeyDown      (UGGraphics* pGraphics,UGuint nChar, UGuint nRepCnt, UGuint nFlags);
    UGbool OnChar         (UGGraphics* pGraphics,UGuint nChar, UGuint nRepCnt, UGuint nFlags);
	//deleted by xielin ^_^
	//UGbool OnKillFocus    (CWnd *pNewWnd);
	//deleted by xielin end ^_^
    //UGbool OnDraw         (UGGraphics* pGraphics, UGbool bDrawHandle = TRUE, UGbool bDrawTool = TRUE,UGbool bIsRefresh = FALSE);
	//deleted by xielin end ^_^
//  }}Afx_Win_Call������Ϣ����
	//added by xielin end ^_^


	//��׽������ú���
		
	//������ת�������㣬������ת��Ĳ�׽��
	//���ò�׽�����е��û��Զ���Ƕ�
    void SetUserAngle( UGdouble dAngle = 0 );

	//ȡ�ò�׽�����е��û��Զ���Ƕ�
    void GetUserAngle( UGdouble& dAngle );

	//���ò�׽����
    void SetSnapType( UGint uSnapType );
	
	//ȡ�ò�׽����
    UGint GetSnapType();

	//ȡ�ò�׽�����������ֵ
    UGint GetSnapBufferMaxSize();

	//���ò�׽�����������ֵ
    UGint SetSnapBufferMaxSize( UGint lSize );

	//ȡ�ò�׽�����������ֵ
    UGint GetSnapLayerMaxSize();

	//���ò�׽�����������ֵ
    UGint SetSnapLayerMaxSize( UGint lSize );

	//ȡ�ò�׽����
    UGdouble GetSnapTolerance();
	
	//��׽������ú��� end


protected:
	UGbool PrepareEditBoard(UGGraphics *pGraphics);
	UGbool ClearMapSelection();         //�����ͼѡ��

	//��׽��غ���
	

	//! \brief ���ò�׽����
    UGdouble SetSnapTolerance( const UGdouble& dTolerance );
	
	void SnapPoint(UGPoint2D &pnt2D);

	//! \brief ʵ�ֲ�׽
    void Snap(UGint                        uSnapPackType,
              UGPoint2D*                   pPntSnaping,
              UGint                        uChangedType = AFC_SNAP_CHANGED_NONE,
              UGGeometry*                pObj = NULL ,
              UGint                         nSnapHandle = 0 );

	//! \brief ���ò�׽����
    void SetSnapParam(UGint                uSnapPackType,
                      UGPoint2D*           pPntSnaping,
                      UGint                uChangedType = AFC_SNAP_CHANGED_NONE,
                      UGGeometry*        pObj = NULL ,
                      int                 nSnapHandle = 0 );

		
	//! \brief ���༭���߶ι�ĳһ��ʱ������׽���Ľڵ�ӵ�������
	//! \param point2D:��׽���ĵ������
	//! \param bPrev:�Ƿ�Ϊǰһ���߶�
    UGbool GetSnapAddPoint( UGPoint2D& pnt2D, int& nIndex, UGbool& bPrev );

	//! \brief ��������ȡ�ò�׽�ߺ�����Ӧ�Ľڵ������
    UGbool GetLineIndex( int& nIndex, UGint& lLineIndex, UGint& lVertexIndex );

	//! \brief ���һ�����Ƶ㵽��ǰ�༭������
	UGbool InsertPointToGeometry( const UGPoint2D& pnt2D );
	
	//! \brief �����׽����
    UGbool SnapClearDraw ( UGGraphics* pGraphics );

	//! \brief ������׽���
    UGbool SnapDraw      ( UGGraphics* pGraphics);

	//! \brief ������׽���
    UGbool SnapDrawExt   ( UGGraphics* pGraphics ,UGbool bDrawHandle=TRUE);

	//! \brief ��ָ���������ڵĲ�׽����ػ�
    UGbool UpdateReMakeSnap( UGRect2D& rc2D );

	//! \brief ���ɲ�׽����
    void SnapMakeGrid();

	//! \brief ���ɲ�׽����
	void SnapMakeGrid(UGLayer * pLayer, UGRecordset * pRecordset);

	//! \brief Ŀǰδ��
    void SnapMakeEdiObjGrid();

	//! \brief �����ߵĶ˵���
	void Point_On_LineStartOrEnd();

	//! \brief ��ͱ��ͼ�ص��غ�
    void Point_On_Point();

	//! \brief ���ڱ��ͼ������
    void Point_On_Line();

	//! \brief ��������ͼ�ص��е�
    void Point_In_Line_Middle();

	//! \brief ����������ͼ�ص��ӳ�����
    void Point_At_Line_Extend();

	//! \brief ������ͼ�ص�ˮƽ����ֱ
    void Point_Extend_On_Point();

	//! \brief ͬһ�߶γɹ̶��Ƕ�
    void Line_Fix_Angle();

	//! \brief �̶�����
    void Line_Fix_Length();

	//! \brief �ߺ�����ͼ���ཻ
    void Line_On_Point();

	//! \brief �߶�ˮƽ����ֱ
    void Line_Is_Horv();

	//! \brief ������ͼ���߶�ƽ��
    void Line_Parallel_Line();

	//! \brief ������ͼ���߶δ�ֱ
    void Line_Vertical_Line();

	//! \brief դ������
	void Raster_Middle();

	//! \brief դ���Ե��
	void Raster_Edge();

	//! \brief ѡ�ж���󣬿�������ѡ�ж���Ĳ�׽�㣬Ȼ���������׽������׽
	void SetUserSnapPoint(UGPoint2D pnt2D);

	//��׽��غ��� end

	//��ͼ�ı������Ӧ�Ĵ����磺�������ò�׽����
    UGbool OnMapChanged();

	//! \brief ����Ĭ�ϵĲ�׽���
	void DrawDefaultSnapStyle(UGGraphics* pGraphics,UGEditSnapElement* pElement);

protected:
	//! \brief 		����������ʾ���ڴ�Graphics��
	UGGraphics* m_pMemGraphics;
	//! \brief 		����������ʾ���ڴ�Image��
	UGImage* m_pMemImage;

	//! \brief ��ǰ���ڲ����ı༭ͼ�㣬��m_EditableLayers�е�һ������������ʱ��̬���õ�ǰ�����ı༭ͼ��
	//! \brief �������Ӷ�����ô��m_pCurEditLayer����m_pCurrentLayer�ȿ�
	UGLayer* m_pCurEditLayer;

	//! \brief ��ǰͼ�㣬��ӵĶ��󶼷��ڵ�ǰͼ����
	UGLayer* m_pCurrentLayer;

	//! \brief 		�ɱ༭ͼ��list�����ڶ�ͼ��༭ģʽ�� added by xielin 2007-04-13
	UGList<UGLayer*> m_EditableLayers;
	
	//! \brief 		��Դ���ָ�롣
	UGResources* m_pResources;
	//! \brief 		��ʾ������ָ�롣
    UGDrawing* m_pDrawing;
	
	
	//! \brief 		��ͼͼ�㼯�ϵ�ָ�롣
	UGLayers* m_pLayers;
	//! \brief 		��ͼģ�ⴰ�ڵ�ָ�롣
	UGMapWnd* m_pMapWnd;

	UGbool						m_bTrackingGeometryLocked;//�Ƿ������tracked�¼��������ж��Ƿ�����ͷ�trackGeometry! ��������,2001/4/13
	UGbool						m_bDelyReleaseTrackingGeometry;//�������ʱ�Ƿ��ͷ�trackGeometry ��������,2001/4/13
    
	// Snap 
    UGEditSnapPointGrid        m_SnapPointGrid;//��׽�����
    UGEditSnapLineGrid         m_SnapLineGrid;  //��׽�߸���
    UGEditSnapBuffer           m_SnapBuffer;   //�༭��׽���� 
    UGEditToolSnapPack         m_SnapParamPack;//�༭��׽���߰�
    //UGEditSnapLineChart        m_SnapLineChart;//��׽�߱�

public:
	//��׽����public�ĳ�Ա����
	UGdouble                       m_dUserAngle; //�̶��ǶȲ�׽ʱ�Ĺ̶��Ƕ�
	UGint                        m_uSnapType;//��ǰ�ĵ�ͼ����
    UGint                        m_lLocateZone;  // ��λ��
    UGint                        m_lSmallLine;   // ���ߴ�С
    UGbool                        m_bEditGeometry; //��׽ʱ�Ƿ��ϲ�׽��
	//��׽�ķ����������ƣ��ṩ�������ò�׽����ɫ����׽����ɫ�ı�������sfcһ����Ȼ���ṩһ��dict����������ÿ�ֲ�׽�ķ��
	//���Ƶ�ʱ�����ж�ĳ�ֲ�׽�Ƿ���dict��style��ΪNULL�������ΪNULL���Ͱ������style�����ƣ��������ͣ�����ŷ���
	//���ΪNULL���Ͱ��ղ�׽����ɫ����׽����ɫ�����ƣ�Ĭ��dict�е�style����NULL
	UGDict<UGint,UGStyle*> m_snapStyles;  //���в�׽���Ƶķ�񼯺�
	UGColor                    m_SnapLineColor; //��׽�ߵ���ɫ(��ò�ͬ�Ĳ�׽�����ò�ͬ�ķ������Ч������,�ȴ��޸�)
    UGColor                    m_SnapPntColor;//��׽�����ɫ(��ò�ͬ�Ĳ�׽�����ò�ͬ�ķ������Ч������,�ȴ��޸�))
    UGint                        m_lLogicZone;   
    UGint                        m_lSnapLayerMaxSize;//���׽ͼ����ӷ�Χ�ڶ������
    UGdouble                      m_dFixLength;   // �̶��߳�
    UGdouble                     m_dLocateZone;  // ��λ��
    UGdouble                      m_dSmallLine;   // ���ߴ�С
	UGint                         m_SnapSequence[AFC_SNAP_KIND_COUNT];//��׽����
	UGPoint2D					m_UserSetSnapPoint;   //�û����õ�ѡ�ж���Ĳ�׽��,�ƶ������죬��ת��ʱ��Ͱ���������õĲ�׽������׽�����������������׽
	UGbool						m_bUseSnapPoint;
	//��׽����public�ĳ�Ա���� end
protected:
 	void                        ( UGEditToolPack::* m_pSnapFunction[AFC_SNAP_KIND_COUNT] ) ( void );
    // image snap attributes
	
	

    UGint                        m_lImgZone;   // Ӱ��λ��
    UGint                        m_lImgMaxBackColor;
    UGint                        m_lImgMinBackColor;
    UGint                        m_lImgThinCount;
    UGdouble                      m_dImgGrad;
    
	UGuint                        m_edittoolshape;//�༭���ͣ����ζ������״
	UGuint 						m_uSubToolShape;//�ӹ�������
    UGuint                        m_eAccessibilityActionPointMode;//�ڵ�༭ģʽ
    
	
    UGEditSelectTool           m_SelectTool;//ѡ�񹤾�
    UGEditSingleObjTool        m_SingleObjTool;//�ڵ�༭�ͻ��ƶ��󹤾�
	UGEditCompoundTool	        m_CompoundTool;//���ϱ༭����

    UGEditOperater				m_EditOperater;//�༭����
    
	UGList<EditGeometry*>                 m_SelectedEditGeometrys;  //ѡ�б༭��������
	
    // editing attributes
	//{{����Ҫ֧��ͬʱѡ�ж������������Ҫ�������б༭�����ID,
	//������һ�������ID���ڴ�������������һ������ID--���Σ�2000.1.10
    
	UGint                       m_lCurEditGeometryID;//��ǰ�༭�����ID
	
	

	//}}����Ҫ֧��ͬʱѡ�ж������������Ҫ�������б༭�����ID,
	//������һ�������ID���ڴ�������������һ������ID--���Σ�2000.1.10
	
	UGRect2D						m_rectPosition;//ѡ�����ķ�Χ�������Σ�2001/2/6

	
    UGint                        m_lCurEditGeometryType;//��ǰ�༭���������
    UGbool                        m_bCurEditObjModified;//��ǰ�༭�����Ƿ������ı�
    
    UGbool                        m_bSnapNeedReMakeGrid;//�Ƿ���Ҫ���½�����׽����
    
    UGbool                        m_bNeedInvalid;//�Ƿ�Ҫˢ��
    UGRect2D                     m_rcNeedInvalid;//ˢ�·�Χ
    UGPoint2D                    m_pntNeedInvalid;//����µĵ�
    UGPoint                      m_MouseDevicePoint;
    // text attributes
    UGColor                    m_colorDrawingObj;
    // text attributes
    UGTextStyle                m_textparam;//ע�ǲ���
    // how many point do you want to make from each two point
    UGint                         m_nPointCountEach;//��������
    UGint                         m_nPixCountEach;//��������
    // geometry style
    UGStyle                 m_geoStyle;//�༭����ķ��
    UGStyle                 m_DrawGeoStyle;//���Ʒ��
	UGStyle					m_AssistantLineStyle;  //�����߷��
    // symbol attributes
	UGMarkerSymParam				m_symParam;//���Ų���
    UGMarkerSymParam          m_DrawsymParam;//��ͼ�ķ��ŷ��
	UGMarkerSymbol                   m_symbol;//����
	UGPoint2D m_pntInputed;      //����㣬�õ��¼���û���������꣬��m_bPointInputed
	UGbool m_bPointInputed;       //�Ƿ��������㣬������ڣ��ڴ���mousedown��Ϣʱ����m_pntImputed������Ļ��ѡȡ�ĵ�

	UGint       m_nEditCursorShape;//�༭������״
	UGbool m_bForceCancel;    //�ڽ���һЩ��ͼ�������磺����ͼ��ʱ����ǿ��ֹͣ����
protected:
	UGPoint2D m_pntOldMapCenter; //��һ�ε�ͼ��ת����
	UGdouble   m_dOldMapRotation; //��һ�ε�ͼ��ת�Ƕ�

	UGuint m_dwEditHandleOption; // �༭�ֱ�ѡ��
	UGbool m_bEditCancel;
	UGbool m_bNeedSendEditEvent;

	UGDrawParamaters*			m_pMapDrawParamaters;//��ͼ����
    UGDrawCache*				m_pMapDrawCache;//��ͼ����

	//ȡ�ø��ټ��ζ����ָ��
	UGGeometry *m_pTrackedGeometry;		//by sgf -- 1999.10.16

	UGArray<UGGeometry*> m_TrackerGeometrys; //����ʱ��Ŀ��Ƶ�ȶ������飬added by xielin 2007.4.3

	UGEditGeometryParam        m_structGeometryParam;

	UGbool m_bAutoBreak;          //�༭�߻��������ݼ�ʱ�Ƿ��Զ����

	UGbool m_bAutoAlongClip;		//�Ƿ��Զ��������߲ü�

	
	UGbool                        m_bNeedSendGeometryParam;

	UGint  m_nEndEditDragCount;

	
public:
	//! \brief ���ñ༭Handleѡ��
	UGbool IsEditHandleEnable(UGint dwHandleOption);
	void SetEditHandleEnable(UGint dwHandleOption,UGbool bEnable);

	//! \brief ��ȡ��ǰ�༭���������
    UGuint GetMapAction();

	//! \brief �жϸÿ��Ƶ��Ƿ���ѡ�п��Ƶ�ķ�Χ֮��
	//! \param nHandle:��ǰ���Ƶ���
	UGbool IntheSeletPointsRange(UGGeometry* pGeometry, UGint nHandle );
	
	//���º�����������ת��
	//MapToDevice:��������תΪ��Ļ����
	//DeviceToMap:��Ļ����תΪ��������
    //{{ change coordinate between map and mapmoded device_context, but not real wnd coordinate
	void MapToDevice(const UGSize2D & szSource, UGSize & szTarget);
	void DeviceToMap(const UGSize & szSource, UGSize2D & szTarget);
	void MapToDevice(const UGRect2D & rcSource, UGRect & rcTarget);
	void DeviceToMap(const UGRect & rcSource, UGRect2D & rcTarget);
	void MapToDevice(const UGPoint2D & pntSource, UGPoint & pntTarget);
	void DeviceToMap(const UGPoint & pntSource, UGPoint2D & pntTarget);
	UGlong MapToDevice(UGdouble lSize);
	UGdouble DeviceToMap(UGlong lSize);
    //}} change coordinate between map and mapmoded device_context, but not real wnd coordinate

	//! \brief ˢ��ѡ�����
    UGbool InvalidSelect(UGGraphics* pGraphics,UGbool bDrawHandle=TRUE);
	void CommitEdit(UGGraphics* pGraphics);          //ȷ�ϱ༭  //add by litao
	UGbool CalcSelPosition();				//����ѡ�ж����ܵķ�Χ�������Σ�2001/2/6
	//! \brief ˢ��ָ����Χ�ڵĵ�ͼ
    void UpdateMap( UGRect2D& rcInvalid );
	//{{Ϊ��֧�ֶ�������Resize,������º����������Σ�20001/2/6
	void Rotate(	         //��תѡ�ж���
		UGGraphics* pGraphics,            
		UGPoint pntRotateBase,//��ת����
		UGPoint pntNew,       //��ת�ſ���괦�ĵ� ����ֹ�㣩
		UGPoint pntOld);      //�������ʱ�ĵ㣨��ʼ�㣩
	//! \brief ˢ��ָ������
    UGbool InvalidObj( UGGraphics* pGraphics, UGGeometry* pEditObj, UGbool bReDraw = TRUE, UGbool bDrawHandle = FALSE );

	//! \brief ˢ��ָ������
    UGbool InvalidObj( UGGraphics* pGraphics, UGGeometry* pEditObj, UGRect& rtAdd, UGbool bDrawHandle = FALSE );

	//! \brief ��Բ�ȶ���ת��Ϊ����ʱ���ݳ��Ⱥ���������ж�Ӧ���ɶ��ٵ�
    UGdouble GetTolerenceDist();
	
	//! \brief ���ؼ�������ʱ��ÿ�ϵĲ�����Ŀ
    UGint  GetPointCountEach();

	UGdouble GetMapTolerenceSelect();

	//! \brief ͨ���༭���һ�����ζ���
    void GetGeoObjFromEditObj( UGGeometry** ppGeometry, UGGeometry** ppEditObj );// create a new geometry obj

	void UserAdjustInputPoint(	//�����û���������������
			UGdouble &dx,
			UGdouble &dy,
			UGdouble &dz,
			UGlong lFlag=0);//����ĵ����Ƿ�Ϊ��ά�㣬�����lFlag=1,����lFlag=0

	//! \brief ��ȡ�ڵ�༭ģʽ
    UGuint GetAccessibilityActionPointMode();

	//! \brief ���ýڵ�༭ģʽ
	UGbool SetAccessibilityActionPointMode( UGuint eMode);

// 	UGint HitTest(UGGeometry* pGeometry,UGPoint& point);//ȡ�����λ�ö�Ӧ���϶�����������Σ�2001/2/7

	//! \brief ���ݹ�������ÿ��Ƶ���
	//! \param point:���λ�ã���Ļ���꣩
	//! \param bSelected:
	//! \param bPointEdit
	UGint  HitTest(UGGeometry* pGeometry, UGPoint& point, UGbool bSelected = TRUE, UGbool bPointEdit = TRUE );
	
	UGint HitTestHandle( UGGeometry* pGeometry,UGPoint& point, UGint nThisDragMode );

	void DrawTracker(UGGraphics* pGraphics);//�������Ƶ㡪�����Σ�2000/2/7

	//added by xielin ^_^ ������һ�༭����Ŀ��Ƶ�,��obj�е�DrawTracker�ƶ���������
	//! \brief �����϶�����ת�Ŀ��Ƶ�
    void DrawTracker( UGGraphics* pGraphics,UGGeometry* pGeometry,UGuint state);

	UGGeometry * PickObject(  //ʰȡ���ζ���
		UGGraphics* pGraphics,			  //�豸������	
		UGPoint point		  //ѡ�е�	
		);// ����add by ����,2001/2/26 

	UGGeometry* PickSymbolAt(//ѡ�����еķ���
		UGGraphics* pGraphics,			 //�豸������	
		UGPoint point 		 //ѡ�е�	
		);// ����add by ����,2001/2/26 

	//! \brief �������ñ༭����
    void ResetEditingParam();                                                   // reset editing parameter such as: id,type

	//! \brief ɾ����ǰ�༭����
    UGbool DeleteCurEditObj( UGGraphics* pGraphics );                                          // delete the editing obj

	//! \brief ��ǰ�༭ʱ����״̬
	UGbool IsTrackEnable();					//by sgf -- 1999.10.16

	//! \brief �ͷŸ��ٵļ��ζ���
	void ReleaseTrackedGeometry();			//by sgf -- 1999.10.16

	//modified by xielin ��һ��geometry���������ڻ�ȡָ������ľ�������geometryΪnull���ͻ�ȡѡ�ж���ľ��
	UGint GetHandle(UGGeometry* pGeometry,UGint nHandle,UGRect& rect);//ȡ�þ����Ӧ�ľ�������

	//added by xielin ^_^ ��EditObj�ĺ�������������ʵ��
	//���ݾ����ѯ�ϴ�Χ���˷�Χͨ����������ѡ�нڵ�
	//nHandle  ���
	//rect   ��ѯ���ķ�Χ
    UGint GetLargeHandle( UGGeometry* pGeometry,UGint nHandle, UGRect& rect);

	//���ݾ����ѯ�ϴ�Χ���˷�Χͨ����������ѡ�нڵ�
	//point  ָ���㣨��Ļ���꣩
	//rect   ��ѯ���ķ�Χ
    void GetLargeHandleRect( UGPoint& pnt, UGRect& rect);



	void GetHandleRect(UGPoint& point,UGRect& rect);//ȡ�þ�����Ӧ��һ����������

	//modified by xielin ��һ��geometry���������ڻ�ȡָ������ľ�������geometryΪnull���ͻ�ȡѡ�ж���ľ��
	UGint GetHandle(UGGeometry* pGeometry,UGint nHandle,UGPoint2D &point);//ȡ�þ����Ӧ�ĵ㣨�������꣩

	//modified by xielin ��һ��geometry���������ڻ�ȡָ������ľ�������geometryΪnull���ͻ�ȡѡ�ж���ľ��
	UGint GetHandle(UGGeometry* pGeometry,UGint nHandle, UGPoint& point);//ȡ�þ����Ӧ�ĵ㣨��Ļ���꣩

	//! \brief ��ȡ�ı�����ı༭�ڵ�
	UGint GetGeoTextHandle(UGGeoText* pGeoText,UGint nHandle,UGPoint2D& point);

	//! \brief ȡ�õ�ǰ�ı༭����
    UGEditTool* FindEditTool();

	//! \brief �����Ƿ���Ա༭
	UGbool IsEditEnabled();

	//! \brief ����ĳ�ֱ༭�����Ƿ����
	UGbool IsEditToolEnabled(UGuint nEditToolType);

	void OnObjectPicked(										//���༭ͼ����ѡ�еĶ����Ϊ�༭״̬	 
					UGGraphics* pGraphics,								//��ͼ���ڵ���������ָ��
					UGSelection* pSmRandomSelection,	//ѡ��ָ��
					UGbool bReQuery=FALSE);					//�Ƿ����²�ѯ
	//�������������������������ע�⣡����������������������������//
	//��    ��ͨ������£�bRequery����Ϊfalse,��ʱ��������������ǿɱ༭ͼ��Ŀɱ༭���ݼ�(m_pEditableLayer-> ��//
	//��m_pEditRecordset)����û�б仯���ڽ���ʽ�༭�У������е�ѡ����ѡ��Բѡʱ������������ģ�������ʹ���� ��//
	//��ͨ����ķ�ʽ����CSmRandomSelection::FromRecrodset�����õ��ɱ༭ͼ���ѡ��ʱ����ͼ��ɱ༭���ݼ��ı� ��//
	//���ʱ��bReQuery����Ӧ����ΪTRUE!                                                                     ��//
	//������������������������������������������������������//


	//ͨ�����ζ�����ȡ��һ���༭����
    void GetEditObjFromGeoObj( UGGeometry* pGeometry, UGGeometry** ppEditObj );// create a new edit obj
	
	//�����༭����
	//pSmResources:��ǰ�����ռ��е���Դ����ָ��
	//pMapDrawParamaters:��ͼ�Ļ��Ʋ���
	//pMapDrawCache:��ͼ������
	//pMapRandomSelection:��ͼѡ�����ָ��
	//pListLayers:ͼ��ָ������
//    UGbool AttachDrawEnvironment(UGResources *pSmResources, 
//			UGDrawParamaters* pMapDrawParamaters,
//            UGDrawCache* pMapDrawCache,
//            UGSelection * pMapRandomSelection ,
//            UGLayers * pListLayers );


	UGbool IsSelected(UGGeometry* pEditObj);

	//! \brief ���һ���µı༭����
    UGbool AddNewEditObj( UGGraphics* pGraphics, UGGeometry* pEditObj );                      // by user create a new obj

	//! \brief ����ָ���ı༭����
    UGbool UpdateEditObj( UGGraphics* pGraphics, UGGeometry* pEditObj );                      // by user modify the editing obj (it is not save to map)
    
	//���༭���󱣴浽��ͼ
    UGbool SaveGeoObjIntoMap( UGGeometry* pEditObj );                            // save to map

	//���ñ༭���
	void SetEditCursorShape(UGint nCursorShape);

	//����༭����
    void ClearEditingTool();// clear the tool when user's action changed

		//���ؿɱ༭ͼ�������,����ǿ�ͼ��༭����ô��ȡ���ǵ�ǰͼ�㣬�ȴ���ӿ�ͼ��༭��� ^_^
	UGint  GetEditableLayerType();

	//���ü�¼�����༭ͼ�㣬����ǿ�ͼ��༭������Ҫ���޸ģ��ȴ���ӿ�ͼ��༭��� ^_^
	void SetEditRecordsetToLayer();

	//�ڵ�ͼ��ָ���ĵ㴦ȡһ������
    UGGeometry* ObjectAt(const UGPoint& point);

	void Clear();//������в���

	//! \brief ȡ����Ҫ���͵ı༭����
    UGbool GetNeedSendGeometryParam();
	
	//! \brief ������Ҫ���͵ı༭����
    UGbool SetNeedSendGeometryParam( UGbool bNeedSendGeometryParam );

	//! \brief ȡ�ñ༭����ı༭����
    void GetGeometryParam( UGEditGeometryParam& structGeometryParam );

	//! \brief ���ñ༭����ı༭����
    void SetGeometryParam( const UGEditGeometryParam& structGeometryParam );

	//! \brief ȡ�ñ༭����ı༭����
    void GetGeometryParam( UGPoint2D &pntCurrent, UGdouble &dCurrentLength, UGdouble &dCurrentAngle, UGdouble &dTotaleLength, UGdouble &dTotaleArea );

	//! \brief ���ñ༭����ı༭����
    void SetGeometryParam( const UGPoint2D &pntCurrent, UGdouble dCurrentLength = 0, UGdouble dCurrentAngle = 0, UGdouble dTotaleLength = 0, UGdouble dTotaleArea = 0 );

	//! \brief ���Ʊ༭��������ȡ��EditObj�еĻ���
	//! \brief ������������ʾ�Ƿ��ǻ���ѡ�ж��������ѡ�ж�����ѡ�ж����ͼ���������ƣ�������geometry��style������
	void DrawEditObj(UGGeometry* pGeometry,UGGraphics* pGraphics,UGbool bIsSelectionGeometry = true);
	
	//! \brief ������geometry�������ת����Ҫ����Ϊ����ŵ���ת�������������ת����ʽ��ͬ������ͳһ����һ��
	//! \brief ����ĵ�һ������Ϊ�޸ĵĶ��󣬵ڶ�������Ϊ���ݵĶ���
	void RotateGeometry(UGGeometry* pGeometry,UGGeometry* pGeoBak, UGPoint pntRotateBase, UGPoint pntNew, UGPoint pntOld);

	//! \brief �����������resize
	void ResizeGeometry(UGGeometry* pGeometry,UGGeometry* pGeoBak,UGint nDragHandle,UGPoint2D pnt2D);


	UGdouble GetTotalLength(UGGeometry* pGeometry);

	UGdouble GetTotalArea(UGGeometry* pGeometry);

	void GetPosition(UGGeometry* pGeometry,UGRect& rect);

	//! \brief ���ݾ��ֵ���õ�ǰ�Ĺ����״
	//! \param nHandle:�������
    UGint  GetHandleCursor(UGGeometry* pGeometry,UGint nHandle);

	//! \brief �жϸ��������Ƿ�ѡ��,��������豸����
	UGbool IsSelectedEditObj(UGGeometry* pGeometry,const UGPoint &point);

	//! \brief  ����༭�¼�����
	UGbool GetNeedSendEditEvent();
	void SetNeedSendEditEvent( UGbool bNeedSendEditEvent);

	UGint InsertPoint( UGGraphics* pGraphics, UGGeometry* pGeometry,const UGPoint point);


	//դ��ʸ����
	//! \brief  �Զ����ٲ���
	void SetTrackParameter(UGTrackParameter &TrackParameter);
	void GetTrackParameter(UGTrackParameter &TrackParameter);
	void AutoPan(UGPoint2D pntViewCenter);
	UGbool IsAutoTracking();
	//դ��ʸ���� end
	

	//! \brief �Ƿ���Լ���
	UGbool IsCutToolEnabled();

	//! \brief �Ƿ����ɾ��
	UGbool IsDeleteToolEnabled();

	//! \brief �Ƿ���Ա�����
	UGbool IsCopyToolEnabled();

	//! \brief �Ƿ�����ճ��
	UGbool IsPasteToolEnabled();

	//! \brief �Ƿ��ܹ�����
	UGbool IsUndoToolEnabled();

	//! \brief �Ƿ���Իָ�
	UGbool IsRedoToolEnabled();

	//! \brief ����
    UGbool OnCut(UGGraphics* pGraphics);

	//! \brief ɾ��
    UGbool OnDelete(UGGraphics* pGraphics);

	//! \brief �༭
    UGbool OnCopy(UGGraphics* pGraphics);

	//! \brief ճ��
    UGbool OnPaste(UGGraphics* pGraphics);

	//! \brief ����
    UGbool OnUndo(UGGraphics* pGraphics);

	//! \brief �ָ�
    UGbool OnRedo(UGGraphics* pGraphics);

	UGbool Break(                            //�����ݼ���Ѱ����ָ�������ཻ��Ȼ��ӽ��㽫��Ͽ�
		UGDatasetVector *pDtV,              //���ݼ�
		UGGeometry * pGeoBreak,         //������õļ��ζ���ֻ�����ߡ������
		UGSelection *pSelectionNew=NULL,//������ɶ���ѡ�� 
		UGbool bBreakSelf=TRUE,              //�Ƿ��϶�����ֻ�д�϶���Ϊ�߶���ʱ�˲��������ã�
		UGbool bUseEditHistory=TRUE);             //�Ƿ����EditHistory

	UGbool Clip(                             //�����ݼ���Ѱ����ָ�������ཻ�Ķ���Ȼ���ò�ѯ���Ķ�����ƶ�������вü�
		UGDatasetVector *pDtV,              //���ݼ�
		UGGeometry * pGeoClip);         //��Ҫ�ü����ζ���ֻ���������
										   //������󱻲ü����򷵻�TRUE,���û�б��ü��򷵻�FALSE 	

	//! \brief ȡ�ø��ٵļ��ζ���
	UGGeometry * GetTrackedGeometry();	//by sgf -- 1999.10.16


};

}

#endif // !defined(AFX_UGEDITTOOLPACK_H__5911E61C_A45F_4FC6_BD25_09F9F966F03F__INCLUDED_)
