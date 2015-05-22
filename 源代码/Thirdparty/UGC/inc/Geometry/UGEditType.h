// UGEditType.h: interface for the UGEditType class.
//
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
// �ļ�����			UGEditType.h
// ��  ����			UGEditType
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		����SuperMap�еı༭����
// ����˵����		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITTYPE_H__87D77BB2_EE0B_4864_B131_DA7B320AC881__INCLUDED_)
#define AFX_UGEDITTYPE_H__87D77BB2_EE0B_4864_B131_DA7B320AC881__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace UGC {

typedef UGArray<UGPoint2D> UGPnt2DArray;
typedef UGArray<UGPnt2DArray*> UGLineArray;

class GEOMETRY_API UGEditType  
{
public:
	//�༭������״�����ͣ�
    enum EditToolShape{						
        ET_None             = 0,			//��
        ET_Selection        = 1,            //ѡ��
        ET_Point            = 21,           //�� 
        ET_LineSect         = 22,           //ֱ��
        ET_EllipseArc       = 23,			//��Բ��
        ET_PolyLine         = 24,			//����,֧��subaction
        ET_BezierCurve      = 25,			//��������,֧��subaction
        ET_Rectangle        = 26,			//����
        ET_RoundRect        = 27,			//Բ�Ǿ���
        ET_Parallelogram    = 28,			//ƽ���ı���
        ET_Circle           = 29,			//Բ��Բ
        ET_Ellipse          = 30,			//��Բ	
        ET_ObliqueEllipse      = 31,			//б��Բ
        ET_PolyGon          = 32,			//�����,֧��subaction
		ET_MulitiPoint		= 33,			//���
		//ET_ARC3P			= 33,	        //���㻡��Բ����
        ET_Text             = 34,			//ע��
        ET_BSpline          = 35,			//B����,֧��subaction
        //sET_SameDistline     = 36,			//��ֵ��
        ET_StreamText       = 37,			//����ע��	
		//ET_Mulitiline       = 38,           //�����,�ѷϳ�����ʹ��ET_PolyLineEx��ET_PolygonEx����
		ET_Path				= 39,           //·������֪����ô���룩
		ET_PolyLineEx       = 42,
		ET_PolygonEx        = 43,
		ET_Arc3P            = 44,           //���㻡
		ET_Circle3P         = 45,           //����Բ
		ET_Pie              = 46,           //�ɶ��� 
		ET_Circle2P			= 47,           //����Բ
		ET_Parallel         = 48,			//ƽ����,֧��subaction
		//ET_Custom           = 49,	        //��չ����

		ET_TrackPolyLine	= 55,			//���Զ�������
		ET_TrackBreak		= 56,			//���Զ����ٻ���
		ET_TrackPolyPolygon	= 57,			//������
		ET_FreeLine			= 58,			//���ʣ����ɻ��ߣ�֧��subaction		
        ET_Cardinal		    = 59,			//Cardinal���ߣ�֧��subaction
		ET_Hatch			= 60,			//Hatch��

		ET_SetSnapPoint		= 70,			//����ѡ�ж���Ĳ�׽�㣬�ƶ���ʱ��������õ������׽�㲶׽�������������
    };

    enum {
        EditTool_Select = 0,
        EditTool_FixHandle ,
        EditTool_DynHandle ,
        EditTool_Text      ,
    };

	//ѡ��ģʽ
    enum EditSelectMode{
        ESM_None,				//��
        ESM_Move,				//�ƶ�
        ESM_MoveNode,			//�ƶ��ڵ�
        ESM_Size,				//�ı��С
		ESM_MoveRotateBase,     //�ƶ���ת����
    };

	//����״̬
	enum EditTrackerState{
        ETS_Normal,		
        ETS_Selected,
        ETS_CtrlPoints
    };
	
	//�༭������ʽ
	enum EditAccessibilityAction{
        EAA_None,				//��
        EAA_EditPoint,			//�༭�ڵ�
        EAA_AddPoint,			//��ӽڵ�
        EAA_RgnMode,			
        EAA_LineMode
    };

	//ɾ���ڵ㷵��ֵ
    enum EditDelNodeReturnValue{
        EDHRV_NoChange,			//�ޱ䶯
        EDHRV_Deleted,			//�Ѿ���ɾ��
        EDHRV_DelObj,			//����ɾ��
    };

	//�ڵ�༭ģʽ
    enum EditDragNodeMode{
        EDHM_NoNode = 0,		//��
        EDHM_SingleNode = 1,	//�Ե����ڵ���в���
        EDHM_LessNode = 2,		//ѡ��ڵ㷽ʽ
        EDHM_MoreNode = 3,		//ѡ��ڵ㷽ʽ
    };

	//��������������
    enum EditUndoMode{
        EUNM_CanntUndo   ,		//�޷�����
        EUNM_NewObj      ,		//�¶���
        EUNM_DelObj      ,		//ɾ������
        EUNM_AddSubObj   ,		//����Ӷ���
        EUNM_DelSubObj   ,		//ɾ���Ӷ���
        EUNM_AddNode     ,		//��ӽڵ�
        EUNM_DelNode     ,		//ɾ���ڵ�
        EUNM_MoveNode    ,		//�ƶ��ڵ�
        EUNM_Move        ,		//�ƶ�����
        EUNM_Size        ,		//�ı�����С
        EUNM_Rotate      ,		//��ת����
		EUNM_CharChange  ,		//ע�Ƕ����ı������仯
        EUNM_SaveNewObj  ,		//�����µĶ���
        EUNM_SaveOldObj  ,		//����ɶ���
    };
    
	//��׽��������
    enum EditSnapObjType{
        ESOT_PointObj   ,		//�����
        ESOT_LineRgnObj ,		//�߻������
        ESOT_SpecialObj ,		//�������
    };
    
	//����ʽ
    enum EditMirrorType{
		EMiRT_Horizontal = 0,	//ˮƽ����
        EMiRT_Vertical   = 1,	//��ֱ����
        EMiRT_LeftTop    = 2,	//�����ϵ����¾���
        EMiRT_RightTop   = 3,	//�����µ����Ͼ���
    };

	enum 
	{
		ecArrow,				//��ͷ
        ecCross,				//ʮ��
        ecRotation,				//��ת
        ecBeam,					//����
        ecMove,					//�ƶ�
		ecNorthSouth,			//�ϱ��ƶ�
		ecWestEast,				//�����ƶ�
		ecNorthwestSoutheast,   //���������ϵ��ƶ�
		ecNortheastSoutnwest,   //���������ϵ��ƶ�
		ecCrossSnapPoint,		//�㲶׽
		ecCrossSnapVertex,		//���㲶׽
		ecCrossSnapMidpoint,	//�߶��е㲶׽
		ecCrossSnapLine,		//���ϲ�׽
		ecCrossSnapVertical,	//��ֱ��׽
		ecCrossSnapParallel,	//ƽ�в�׽
		ecMoveRotateBase,		//��ת����

    };//�༭���߹������

	//�༭handle�����ͣ���ʱ��Ϊ���࣬һ������ͨ��handle��һ���Ǹı�����ɫ��handle
	//��Ҫ���ڻ��εȶ����޸ĳ�����Ļ��Σ�һ���Ǹ��������ͣ���һ��С��
	enum EditHandleType
	{
		NormalHandle  = 1,
		LittleHandle  = 2,
		ControlHandle = 3,
	};

	//�༭�ĸ����㣬����������͸���������
	struct EditAssistantPoint {
		EditHandleType nType;
		UGPoint2D	pnt2D;
	};
};



}

#endif // !defined(AFX_UGEDITTYPE_H__87D77BB2_EE0B_4864_B131_DA7B320AC881__INCLUDED_)
