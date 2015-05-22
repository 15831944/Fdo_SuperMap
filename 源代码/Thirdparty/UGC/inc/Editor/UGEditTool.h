// UGEditTool.h: interface for the UGEditTool class.
//=====================================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 2.0
// ��  �ߣ�			�ιظ�
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSupermap GIS����������Ա��δ����ɲ������Դ�����
//					2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����			UGEditTool.h
// ��  ����			UGEditTool��UGEditSelectTool��UGEditFixHandleTool��UGEditSingleObjTool��UGEditSubTextTool
// ��  �ࣺ			UGEditSelectTool-->UGEditTool
//					UGEditFixHandleTool-->UGEditTool
//					UGEditSingleObjTool-->UGEditTool
//					UGEditSubTextTool-->UGEditTool
// ��  �ࣺ			
// ����˵����		������ֱ༭�������Ϣ
// ����˵����		
//=====================================================================================

#if !defined(AFX_UGEDITTOOL_H__87F97B9D_527B_4539_A119_32ABBECC8E1F__INCLUDED_)
#define AFX_UGEDITTOOL_H__87F97B9D_527B_4539_A119_32ABBECC8E1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Base/UGList.h"
#include "Algorithm/UGRect2D.h"
#include "Graphics/UGGraphics.h"
#include "Geometry/UGEditType.h"
#include "Map/UGLayer.h"


#define UG_EDIT_TRACKING_MOVE	0
#define UG_EDIT_TRACKING_LEFT	1
#define UG_EDIT_TRACKING_RIGHT	2

namespace UGC {

class UGEditToolPack;
class UGEditObj;
class UGRasterToVector;
class UGEditCompoundTool;
class EDITOR_API UGEditTool  
{
public:
	UGEditTool();
	virtual ~UGEditTool();
public:
// Virtual Implementation
	virtual UGbool OnRButtonDblClk(UGGraphics *pGraphics,UGuint nFlags, UGPoint point);
    virtual UGbool OnRButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);     //�༭��������Ҽ��������Ϣ����
    virtual UGbool OnRButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);   //�༭��������Ҽ����µ���Ϣ����
    virtual UGbool OnLButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);     //�༭�����������������Ϣ����
    virtual UGbool OnLButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);   //�༭�������������µ���Ϣ����
    virtual UGbool OnLButtonDblClk( UGGraphics *pGraphics, UGuint nFlags, UGPoint point); //�༭����������˫������Ϣ����
    virtual UGbool OnMouseMove( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);		//�༭��������ƶ�����Ϣ����
    virtual UGbool OnSetCursor( UGuint nHitTest, UGuint message);             //��������λ�����ı������״ 
    virtual UGbool OnKeyDown( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);//������Ϣ����Ӧ
    virtual UGbool OnChar( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);   //������Ϣ����Ӧ
    virtual UGbool OnDraw( UGGraphics *pGraphics);       //��ָ���豸�л����༭����   
    virtual UGbool OnKillFocus( UGGraphics *pGraphics ); //ʧȥ����
    virtual UGbool Clear( UGGraphics *pGraphics );       //����༭����

    virtual UGbool OnUndo( UGGraphics *pGraphics);       //��������  
    virtual UGbool OnRedo( UGGraphics *pGraphics);       //�ָ�����

// Real Implementation
    UGbool AttachToolPack( UGEditToolPack* pToolPack );  //��ָ����UGEditToolPack��������ϵ

	virtual UGbool IsUndoToolEnabled();		//�ж��Ƿ���Գ�����һ������
	virtual UGbool IsRedoToolEnabled();		//�ж��Ƿ���Իָ���һ������

	virtual UGbool EditCompleted(UGGraphics *pGraphics);   //����һ������ı༭�������



	
//�жϸÿ��Ƶ��Ƿ���ѡ�п��Ƶ�ķ�Χ֮��
//nHandle:��ǰ���Ƶ���
	virtual UGbool IntheSeletPointsRange( UGint nHandle );
// �����������Sizeingʱ���õģ�����ʹ��Ӿ��γ�Ϊ������   *note19991202
    virtual void MakeSquareBoundConer( UGGraphics* pGraphics, UGGeometry* pEditObj, UGint nHandle, UGPoint2D& pnt2D );

	//ͨ���༭���ͻ�ȡ�����༭�ĵ������������Զ�����󣬾��ô���ĵ������
	UGint GetEndEditDragCountFromType(UGint nType);
	//added by xielin 2007-04-25 �ѱ༭�����һЩ�����ŵ�������ʵ��  end
//Attribute
protected:  //��Ϊ������Ա�����������Σ�2000.12.18
    // Undo buffer is a stack which bottom is open
	//deleted by xielin ^_^
    // UGEditUndoBuffer  m_UndoBuffer; //����������
	//deleted by xielin end ^_^
    UGEditToolPack*   m_pToolPack;  //ָ��༭���߰���ָ��
    UGPoint2D           m_pnt2DDown;  //��¼��갴��ʱ������
    UGPoint2D           m_pnt2DLast;  //��¼���ſ�ʱ������
	UGPoint2D			m_pnt2DMouseMove;  //��¼����ƶ�ʱ�������

	UGArray<UGPoint2D> m_arrayPnts;  //������¼������ĵ�
	UGArray<UGPoint2D> m_arrayUndoPnts; //������¼undo�ĵ㣨���ƶ�������У�
public:
    UGGeometry*        m_pEditObj;   //ָ��༭�����ָ�� 
	UGGeometry*		   m_pAssistantObj;  //ָ�����߶����ָ��
	//added by xielin 2007-05-11 ����һ�����������飬�������渨��������
	UGArray<UGEditType::EditAssistantPoint> m_arrayAssistantPoints;

public:
	virtual UGGeometry * GetEditObj();

	

	static void HilightRecordset(										//������ʾ��¼��
								UGGraphics *pGraphics,							//�豸������ָ��
								UGRecordset *pRs,					//��¼��
								UGDrawParamaters *pDrawParamater,  //��ͼ���Ʋ���
								UGStyle *pGeoStyle);            //�������
	static void DrawDotLine(				//������
							UGGraphics *pGraphics,		//�豸	
							UGPoint pntHead, //���
							UGPoint pntTail,	//�յ�
							UGlong crPen);

	static void DrawControlPoint(				//�����Ƶ�
								UGGraphics *pGraphics,       //�豸������ָ��
								UGPoint point,	//�����
								UGColor crPen);  

	static void DrawHandleRect(				//���༭�ֱ�
								UGGraphics *pGraphics,       //�豸������ָ��
								UGRect rect,	//���귶Χ
								UGbool bEditable = TRUE,
								UGint nHandleType = UGEditType::NormalHandle);//�Ƿ�ɱ༭

	static void DrawRotationRect(				//����ת�ֱ�
								UGGraphics *pGraphics,       //�豸������ָ��
								UGRect rect,	//���귶Χ
								UGbool bEditable = TRUE);//�Ƿ�ɱ༭
								  
	

    UGint                 m_DragHandle;//���������ͨ���þ������ȷ���û�������ʲô���� 
	UGEditCompoundTool* m_pMainEditTool;//�༭����߻򸴺϶���ʱ��������,Ӧ�ö���ΪUGEditCompoundTool���ȶ���ΪUGEditTool��
	
};

class EDITOR_API UGEditSelectTool : public UGEditTool
{
//Constructer
public:
    UGEditSelectTool();
    virtual ~UGEditSelectTool();
//Implementation
public:
    virtual UGbool OnRButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point); //ѡ���������Ҽ��������Ϣ����
    virtual UGbool OnRButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ���������Ҽ����µ���Ϣ����
    virtual UGbool OnLButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ������������������Ϣ����
    virtual UGbool OnLButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ��������������µ���Ϣ����
    virtual UGbool OnLButtonDblClk( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ�����������˫������Ϣ����
    virtual UGbool OnMouseMove( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ���������ƶ���Ϣ
    virtual UGbool OnSetCursor( UGuint nHitTest, UGuint message);//ѡ�������״
    virtual UGbool OnKeyDown( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);//ѡ�񰴼���Ϣ����
    virtual UGbool OnDraw( UGGraphics *pGraphics);//����ѡ�����

	UGbool IsMirrorToolEnabled();//ѡ��Ķ����Ƿ���������
    UGbool OnMirror( UGGraphics *pGraphics, int nMirrorType );//����ѡ�����  
	
	//���漸���ӿڵĹ�����mapwnd��ʵ���ˣ�����Ͳ�ʵ���ˡ�
	UGbool IsCutToolEnabled();//�Ƿ���������
	UGbool IsDeleteToolEnabled();//�Ƿ�����ɾ��
	UGbool IsCopyToolEnabled();//�Ƿ���������
	UGbool IsPasteToolEnabled();//�Ƿ�����ճ��
    UGbool OnCut( UGGraphics *pGraphics );//���ж���
    UGbool OnDelete( UGGraphics *pGraphics );//ɾ������
    UGbool OnCopy();//���ƶ���
    UGbool OnPaste( UGGraphics *pGraphics );//ճ������
	//���漸���ӿڵĹ�����mapwnd��ʵ���ˣ�����Ͳ�ʵ���ˡ�
    virtual UGbool OnUndo( UGGraphics *pGraphics );//ȡ������
    virtual UGbool OnRedo( UGGraphics *pGraphics );//�ָ�����
// Real Implementation
    UGbool ClearParam();//������в���
	virtual UGbool ClearSelection();       //����༭����
// Static Implementation
	//deleted by xielin ^_^
    //��ӦTimmer��Ϣ
	//static VOID CALLBACK UGEditSelectTool::TimerProc(  HWND hwnd, UGuint uMsg, UGuint lpThis, DWORD dwTime );
	//deleted by xielin ^_^ end 
//Attribute
public:
	UGbool PntInRotateBaseRect(          //����һ�����Ƿ�����ת���㷶Χ֮��
		UGPoint pntHittest);            //���Ե�

	virtual UGGeometry* GetEditObj();
    UGGeometry*        m_pEditObjBak;//�༭����ı���
    UGGeometry*        m_pCopyedObj;//���ƶ���ʱ���渴�ƶ���
	//modified by xielin ^_^
	UGList<UGGeometry*>        m_Selection;//ѡ�б༭�������鱸��
	//modified by xielin end ^_^
    UGuint               m_editSelType;//ѡ������
    UGRect       m_skewBound;  //��Ӿ��Σ�����û���õ���
	UGRect2D				m_rectPosition;//�ı������С
	UGint                 m_nDragNodeBegin;//ѡ�е���ʼ�ڵ�
    UGint                 m_nDragNodeEnd;//ѡ�е�β�ڵ�
    UGuint                m_uDragNodeMode;//��קģʽ
    clock_t                m_dwTickCount;//����ʱ����Ϣ
	
	UGPoint2D			m_pntRotateBase;//��ת����
	//double				m_dAngleRotateStart;//��ת��ʼ��
protected:
	void MoveHandle(				//�ƶ����Ƶ��Ըı����Ĵ�С	
		UGGraphics *pGraphics,					//�豸������
		UGint &nHandle,				//���Ƶ�ľ��
		const UGPoint2D &pntOld,		//���Ƶ�ԭ��������
		const UGPoint2D &pntNew		//���Ƶ����ڵ�����
		);//ADD BY LITAO �������Σ�20001/2/7
};

class EDITOR_API UGEditSingleObjTool : public UGEditTool
{
//Constructer
public:
    UGEditSingleObjTool ();
    virtual ~UGEditSingleObjTool ();
//Implementation
public:
	virtual UGbool OnRButtonDblClk(UGGraphics *pGraphics,UGuint nFlags, UGPoint point);
    virtual UGbool OnRButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point); //ѡ���������Ҽ��������Ϣ����
    virtual UGbool OnRButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ���������Ҽ����µ���Ϣ����
    virtual UGbool OnLButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ������������������Ϣ����
    virtual UGbool OnLButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ��������������µ���Ϣ����
    virtual UGbool OnLButtonDblClk( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ�����������˫������Ϣ����
    virtual UGbool OnMouseMove( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ���������ƶ���Ϣ
    virtual UGbool OnSetCursor( UGuint nHitTest, UGuint message);//ѡ�������״
    virtual UGbool OnKeyDown( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);//ѡ�񰴼���Ϣ����
    virtual UGbool OnDraw( UGGraphics *pGraphics); //��ָ���豸�л����༭����   
    virtual UGbool OnUndo( UGGraphics *pGraphics); //��������
    virtual UGbool OnRedo( UGGraphics *pGraphics); //�ָ�����
//Attribute
	virtual UGbool EditCompleted(UGGraphics *pGraphics); //����һ������ı༭�������


	//added by xielin 2007-04-25 �ѱ༭�����һЩ�����ŵ�������ʵ�� 
	
	//�жϸÿ��Ƶ��Ƿ���ѡ�п��Ƶ�ķ�Χ֮��
	//nHandle:��ǰ���Ƶ���
    virtual UGbool IntheSeletPointsRange( UGint nHandle );
	//added by xielin 2007-04-25 �ѱ༭�����һЩ�����ŵ�������ʵ��  end

	//! \brief ���¼��㸨���ߺ͸����㣨��mousemove�ͻ���������ʱ��Ҫ�õ���
	UGbool CalAssistantLineAndAssistantPoint();
public:
	void SetPathObjSubShape(UGbyte subShape);
	//ͨ���༭�����ʹ���һ��Geometry���󣬴����Ķ���ŵ���Ա����m_pEditObj
	UGbool CreateEditObjFromEditType(UGint nType);
	
    UGbool                m_bAutoAddPoint;//�Ƿ��Զ������
    UGbool                m_bSubMode;//�Ƿ�༭�Ӷ���ģʽ
	//deleted by xielin ^_^
	UGRasterToVector*	m_pSmRasToVec;//���Զ�ʸ��������
	//deleted by xielin end ^_^
	UGbool				m_bFreeLineStart;//���ɻ��߿�ʼ
	UGlong				m_nFreeLineStartIndex;//���ɻ��߿�ʼλ��
	UGLayer*			m_pHatchLayer;//����Hatch��ͼ��
};

class EDITOR_API UGEditSubTextTool : public UGEditTool
{
//Constructer
public:
    UGEditSubTextTool ();
    virtual ~UGEditSubTextTool ();
//Implementation
public:
// Virtual Implementation
	virtual UGbool OnRButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point); //ѡ���������Ҽ��������Ϣ����
    virtual UGbool OnRButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ���������Ҽ����µ���Ϣ����
    virtual UGbool OnLButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ������������������Ϣ����
    virtual UGbool OnLButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ��������������µ���Ϣ����
    virtual UGbool OnLButtonDblClk( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ�����������˫������Ϣ����
    virtual UGbool OnMouseMove( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//ѡ���������ƶ���Ϣ
    virtual UGbool OnSetCursor( UGuint nHitTest, UGuint message);//ѡ�������״
	virtual UGbool OnChar( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);   //������Ϣ����Ӧ
	virtual UGbool OnKeyDown( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);//������Ϣ����Ӧ
    virtual UGbool OnDraw( UGGraphics *pGraphics); //��ָ���豸�л����༭����   
    virtual UGbool OnKillFocus( UGGraphics *pGraphics );//����ʧȥ������Ϣ
    virtual UGbool OnUndo( UGGraphics *pGraphics); //��������
    virtual UGbool OnRedo( UGGraphics *pGraphics); //�ָ�����
	virtual UGbool IsUndoToolEnabled();		//�ж��Ƿ���Գ�����һ������
	virtual UGbool IsRedoToolEnabled();		//�ж��Ƿ���Իָ���һ������	
// Real Implementation



	//added by xielin 2007-04-25 �ѱ༭�����һЩ�����ŵ�������ʵ��  end
//Attribute
public:
	//deleted by xielin ^_^
	//void TextEditCallBack(LPVOID pThis);
	//deleted by xielin ^_^ end 
	void SaveInputText();
	UGGeoText * HitTest(       //�ж��Ƿ�ѡ��ע�Ƕ����ǵĻ��ͱ༭��
		UGPoint2D pntHitTest);

    UGbool        m_bSubMode;//�Ƿ���Ӷ������

	UGint m_nSubTextAngle;  //������ע��ʱ����Ҫ�Ƚ�ע�ǵ�m_nRotateAngle����Ϊ0������Ҫ�Ƚ�ԭ���ĽǶȱ��棬�Ա����������ָ�
};

}

#endif // !defined(AFX_UGEDITTOOL_H__87F97B9D_527B_4539_A119_32ABBECC8E1F__INCLUDED_)
