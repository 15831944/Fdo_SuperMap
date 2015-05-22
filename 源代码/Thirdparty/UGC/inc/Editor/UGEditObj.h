// UGEditObj.h: interface for the UGEditObj class.
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
// �ļ�����			UGEditObj.h
// ��  ����			UGEditObj��UGEditObList��UGDynPointList��UGEditFixHandleObj��UGEditDynHandleObj
// ��  �ࣺ			UGEditFixHandleObj-->UGEditObj
//					UGEditDynHandleObj-->UGEditObj
// ��  �ࣺ			
// ����˵����		UGEditObj������༭���࣬�ṩ����༭�Ļ�������
//                  UGEditObList���༭��������
//                  UGDynPointList����ά������
//					UGEditFixHandleObj���̶�����������ڸı�����С���ƶ��Ȳ���
//					UGEditDynHandleObj����̬����������ڱ༭�ڵ㣬��ӽڵ�Ȳ���
// ����˵����		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITOBJ_H__D54EB6A7_FAD5_4F29_BD46_1C5907AB4AC7__INCLUDED_)
#define AFX_UGEDITOBJ_H__D54EB6A7_FAD5_4F29_BD46_1C5907AB4AC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRect2D.h"
#include "Graphics/UGGraphics.h"
#include "Editor/UGEditToolPack.h"

namespace UGC {

class UGEditToolPack;

class EDITOR_API UGEditObj  
{
public:
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

public:
	UGEditObj( UGEditToolPack* pToolPack, UGuint shape);
	virtual ~UGEditObj();

public:
	//��¡һ���༭����
    virtual UGEditObj* Clone();
	
	//�����༭����
	virtual void Draw( UGGraphics* pGraphics);
	
	//��ñ༭����ľ������Ŀ
	//���ڹ̶��������Ϊ9�����˸ı��С��8�����Ƶ��һ����ת���Ƶ�
    virtual UGint  GetHandleCount();

	//���ݾ�������Ӧ���Ƶ��ֵ
	//nHandle:��ֵ����Ƶ�Ĺ�ϵ����ͼ                         
	//									1---+   	  +--2    	+----3	
	//                                      |         |         |  
	//                                      |         |         |  
	//										x---------x---------x     9
    //										|   ____________    |     |
    //										|  /            \   | x---+
	//									4---x |              |  x-----5
	//										|  \____________/   |
	//										|                   |
	//										x---------x---------x
	//										|		  |         |
	//										|		  |         |
	//								    6---+         +-----7   +-----8
	//point:�����Ӧ�Ŀ��Ƶ������ֵ
    virtual UGbool GetHandle( UGint nHandle, UGPoint2D& point);


	//�ƶ����Ƶ㵽ָ������
	//nHandle:���Ƶ���
	//point:���Ƶ�����
    virtual void MoveHandle( UGint nHandle, const UGPoint2D& point );

	//�ƶ����Ƶ㵽ָ������
	//pDC:�豸������ָ��
	//nHandle:���Ƶ���
	//point:���Ƶ���Ļ����
	//bInvalid���Ƿ��ػ�
    virtual void MoveHandle( UGGraphics* pGraphics, UGint nHandle, const UGPoint& point, UGbool bInvalid = TRUE );

	//�ƶ����Ƶ㵽ָ������
	//pDC:�豸������ָ��
	//nHandle:���Ƶ���
	//pnt:���Ƶ��ͼ����
	//bInvalid���Ƿ��ػ�
    virtual void MoveHandle( UGGraphics* pGraphics, UGint nHandle, const UGPoint2D& pnt, UGbool bInvalid = TRUE );

	//�ƶ������ı༭����Ŀ��Ƶ㵽ָ������
	//pDC:�豸������ָ��
	//pEditObj:�༭����
	//nHandle:���Ƶ���
	//pnt2D:���Ƶ��ͼ����
    virtual void MoveHandle( UGGraphics* pGraphics, UGEditObj* pEditObj, UGint nHandle, const UGPoint2D& pnt2D );
	
    
	// �����������Sizeingʱ���õģ�����ʹ��Ӿ��γ�Ϊ������   *note19991202
    virtual void MakeSquareBoundConer( UGGraphics* pGraphics, UGEditObj* pEditObj, UGint nHandle, UGPoint2D& pnt2D );

	//�ú���ֻ���ڶ�̬������󣬽ڵ�༭ʱ����������һ�����Ƶ�
	//nHandle:����λ��
	//point:��������Ļ����
    virtual void AddHandle( UGint nHandle, const UGPoint& point);
	
	//�ú���ֻ���ڶ�̬������󣬽ڵ�༭ʱ����������һ�����Ƶ�
	//nHandle:����λ��
	//point:�����ĵ�������
    virtual void AddHandle( UGint nHandle, const UGPoint2D& pnt2D);

	//�ú���ֻ���ڶ�̬������󣬽ڵ�༭ʱ����������һ�����Ƶ�
	//point:�����ĵ�������
    virtual void AddHandle( UGPoint2D& point);

	//deleted by xielin ^_^
	//�ú���ֻ���ڶ�̬�������ɾ���ڵ�༭����ѡ�еĽڵ�
	//pUndoElement:�ָ���ջԪ��
    //virtual UGuint DelNode( UGEditUndoElement* pUndoElement );
	//deleted by xielin end ^_^
	
	//�ú���ֻ���ڶ�̬�������ɾ���༭�����ָ���ڵ�
	//nHandle:�ڵ���
    virtual UGuint DelNode( UGint nHandle );

	//deleted by xielin ^_^
	//�ú���ֻ���ڶ�̬������󣬲���һ�����Ƶ㵽�༭������
	//pDC:�豸������ָ��
	//point:Ҫ��������Ļ����
	//pUndoElement:���ָ�����ջԪ��ָ��
	//virtual UGint  InsertPoint( UGGraphics* pGraphics, const UGPoint point, UGEditUndoElement* pUndoElement );
	//deleted by xielin end ^_^

	//��Ӧ�༭�����¼�����Ŀǰû����
    virtual void OnEditProperties();

	//���༭�����ƶ�һ��ָ������
	//pDC:�豸������ָ�룬�����ػ�����
	//sizeDelta:ƫ�ƾ��룬�ڴ�Ϊ��Ļ����
    virtual void MoveTo( UGGraphics* pGraphics, const UGSize& sizeDelta);

	//���༭�����ƶ�һ��ָ������
	//pDC:�豸������ָ�룬�����ػ�����
	//sizeDelta:ƫ�ƾ��룬�ڴ�Ϊ��������
    virtual void MoveTo( UGGraphics* pGraphics, const UGSize2D& sizeDelta);

	//�жϵ��Ƿ��ڶ�����
	//point:ѡȡ��
    virtual UGbool IsSelect( const UGPoint& point );

	//���ݾ��ֵ���õ�ǰ�Ĺ����״
	//nHandle:�������
    virtual UGint  GetHandleCursor(int nHandle);

	//���¼������ķ�Χ
    virtual UGbool RecalcBounds();

	//�ڻ�Բ�Ǿ��λ򻡶Σ�����Բ�Ǿ���Բ�ǵ������Ȼ򻡶εĻ���ʱ��ʹ���Ƶ�Ĺ켣ʼ���ڶ�����
	//nHandle:�������Ƶ���
	//point:���Ƶ����꣨��Ļ���꣩
	//nFlags:��ʱû��
    virtual void AdjustPoint( UGint nHandle, UGPoint& point, UGuint nFlags = 0X00 );

	//�ڻ�Բ�Ǿ��λ򻡶Σ�����Բ�Ǿ���Բ�ǵ������Ȼ򻡶εĻ���ʱ��ʹ���Ƶ�Ĺ켣ʼ���ڶ�����
	//nHandle:�������Ƶ���
	//point:���Ƶ����꣨�������꣩
	//nFlags:��ʱû��
    virtual void AdjustPoint( UGint nHandle, UGPoint2D& point, UGuint nFlags = 0X00 );

	//������Ҫ����Ŀ��Ƶ���Ŀ
    virtual UGlong GetSavePointsCount();

	//ȡ�ñ���Ŀ��Ƶ������
	//pPoints:����Ŀ��Ƶ��б�
    virtual void GetSavePoints( UGPoint2D* pPoints );
	
	//ȡ�ñ���Ŀ��Ƶ������,ͬʱ���ؿ��Ƶ����Ŀ
	//pPoints:����Ŀ��Ƶ��б�
	//nPoint:���Ƶ����Ŀ
	virtual void GetSavePoints( UGPoint2D*& pPoints, UGlong &nPointCount );

	//��������Ĵ�С
	//pDC:�豸������
	//pEditObj:���༭�Ķ���
	//rtNew:������·�Χ����Ļ���꣩
    virtual void Size( UGGraphics* pGraphics, UGEditObj* pEditObj, const UGRect& rtNew);

	//��������Ĵ�С
	//pDC:�豸������
	//pEditObj:���༭�Ķ���
	//rtNew:������·�Χ���������꣩
    virtual void Size( UGGraphics* pGraphics, UGEditObj* pEditObj, const UGRect2D& rtNew);

	//�ж����λ���Ƿ��䵽�˿��Ƶ��ϣ���ѡ�п��Ƶ�
	//point:���λ��
	//uThisDragMode:ѡ�п��Ƶ��ģʽ
    virtual UGint  HitTestHandle( UGPoint& point, UGuint uThisDragMode );

	//�жϸÿ��Ƶ��Ƿ���ѡ�п��Ƶ�ķ�Χ֮��
	//nHandle:��ǰ���Ƶ���
    virtual UGbool IntheSeletPointsRange( UGint nHandle );

	//���һ���ӱ༭����
	//pEditObj:�ӱ༭�����ָ��
    virtual UGbool AddSubObj( UGEditObj* pEditObj );

	//��ת�༭����
	//pDC:�豸������ָ��
	//pEditObj:�༭����ָ��
	//pntNew:��ת���Ƶ����λ��
	//pntOld:��ת���Ƶ����λ��
    virtual void Rotate( UGGraphics* pGraphics, UGEditObj* pEditObj,const UGPoint &pntRtOrg, const UGPoint& pntNew, const UGPoint& pntOld);

	//deleted by xielin ^_^
	//��������
    //virtual UGbool Undo( UGEditUndoElement* pUndoElement );
	//deleted by xielin end ^_^

	//deleted by xielin ^_^
	//�ظ�����
    //virtual UGbool Redo( UGEditUndoElement* pUndoElement );
	//deleted by xielin end ^_^

	//�ڶԶ���α༭ʱ�����ã�Ϊ�����ָ��λ�ò���һ���µĿ��Ƶ�
	//lSubLineIndex:�Ӷ�������
	//lVertexIndex:�ڵ�����
	//pnt2D:������Ƶ�����
    virtual UGbool InsertNewPoint( UGlong lSubLineIndex, UGlong lVertexIndex, const UGPoint2D& pnt2D);

	//����
	//nMirrorType:��������
	//nMirrorType:�μ�SmEditType
    virtual void Mirror( UGint /*nMirrorType*/ ){};

	//��ȡ������ܳ���
    virtual UGdouble GetTotalLength(){ return 0; };

	//��ȡ����������
    virtual UGdouble GetTotalArea(){ return 0; };

	//�����϶�����ת�Ŀ��Ƶ�
    virtual void DrawTracker( UGGraphics* pGraphics, UGuint state);
 
	//Real Implementation
	
	//��ö���Χ
	//rect:��Χ���������꣩
	virtual void GetPosition( UGRect2D& rect);
	
	//��ö���Χ
	//rect:��Χ����Ļ���꣩
    virtual void GetPosition( UGRect& rect);
	
	//���ݹ�������ÿ��Ƶ���
	//point:���λ�ã���Ļ���꣩
	//bSelected:
	//bPointEdit
    
	virtual UGint  HitTest( UGPoint& point, UGbool bSelected = TRUE, UGbool bPointEdit = TRUE );
	
	//���ݾ����ѯ���Ƶ�
	//nHandle  ���
	//point   ��ѯ���ĵ�
    UGbool GetHandle( UGint nHandle, UGPoint& point);
	
	//���ݾ����ѯ��Χ
	//nHandle  ���
	//rect   ��ѯ���ķ�Χ
    UGbool GetHandle( UGint nHandle, UGRect& rect);

	//���ݾ����ѯ�ϴ�Χ���˷�Χͨ����������ѡ�нڵ�
	//nHandle  ���
	//rect   ��ѯ���ķ�Χ
    UGbool GetLargeHandle( UGint nHandle, UGRect& rect);

	//����ָ�����ѯ��С��Χ���˷�Χͨ����������δѡ�нڵ�
	//point  ָ���㣨��Ļ���꣩
	//rect   ��ѯ���ķ�Χ
    void GetHandleRect( UGPoint& pnt, UGRect& rect);

	//���ݾ����ѯ�ϴ�Χ���˷�Χͨ����������ѡ�нڵ�
	//point  ָ���㣨��Ļ���꣩
	//rect   ��ѯ���ķ�Χ
    void GetLargeHandleRect( UGPoint& pnt, UGRect& rect);

	//�ж��Ƿ����Χ�㹻С�������ڿ��Բ���ʾ
	//rect:�������ڷ�Χ����Ļ���꣩
    UGbool RectTooSmall( const UGRect& rect);

	//�ж��Ƿ����Χ�㹻С�������ڿ��Բ���ʾ
	//rect:�������ڷ�Χ���������꣩
    UGbool RectTooSmall( const UGRect2D& rect);

	//��ȡ�༭�������״
    UGuint GetType(){ return m_editshape; };

    static UGdouble GetCAR(UGint nCoefficient, UGdouble fSegment);

	//{{��һ�龲̬����������ͼ��ת�������ߣ����������ߵĽڵ�����
	//pPntControls:����ͼ�εĹؼ��㣨���Ƶ㣩
	//pPntCurve:���صĽڵ�����
	//nCurvePoints:�ڵ����
    //static UGbool Cardinal ( UGPoint * pPntControls, UGPoint * pPntCurve, UGint nCurvePoints );
    //static UGbool Cardinal ( UGPoint2D * pPntControls, UGPoint2D * pPntCurve, UGint nCurvePoints );
    static UGbool Arc      ( UGPoint * pPntControls, UGPoint * pPntCurve, UGint nCurvePoints );
    static UGbool RoundRect( UGPoint * pPntControls, UGPoint * pPntCurve, UGint nCurvePoints );
    static UGbool Ellipse  ( UGPoint * pPntControls, UGPoint * pPntCurve, UGint nCurvePoints );
    static UGbool Arc      ( UGPoint2D * pPntControls, UGPoint2D * pPntCurve, UGint nCurvePoints );
    static UGbool RoundRect( UGPoint2D * pPntControls, UGPoint2D * pPntCurve, UGint nCurvePoints );
    static UGbool Ellipse  ( UGPoint2D * pPntControls, UGPoint2D * pPntCurve, UGint nCurvePoints );
	//}}��һ�龲̬����������ͼ��ת�������ߣ����������ߵĽڵ�����
	
	static UGbool ClipLinesectWithRect(			//��һ���߶��޶��ھ���������
						   UGPoint2D &pntBegin,  //�߶εĶ˵�
						   UGPoint2D &pntEnd,	//�߶εĶ˵�	
						   UGRect2D rcClip);		//�޶��ķ�Χ	
//Attribute
public:
	virtual void Resize(                 //�ı�༭����Ĵ�С
		UGEditObj *pEditObjBk,          //���ݵı༭����
		UGPoint2D pntOldOrg,              //����ԭ���Ĳο��� 
		UGPoint2D pntNewOrg,              //�µĲο���
		UGdouble dXRatio,                  //x�����ϵ���������
		UGdouble dYRatio);                 //y�����ϵ���������

    UGEditToolPack*       m_pToolPack;   //�༭���߰�ָ��
    UGuint                   m_editshape;   //�༭���ζ������״
    UGRect2D                m_rectPosition;//�༭����ĵ�ǰ��Χ
	UGStyle*	       m_pStyle;      //�༭����ķ��
	UGbool				   m_bCADObj;	  //�Ƿ�Ϊ����������

};

//deleted by xielin ^_^
//typedef CTypedPtrList<CObList, UGEditObj*> CEditObList;
//typedef CTypedPtrList<CPtrList, UGPoint2D*> CDynPointList;
//typedef CTypedPtrList<CPtrList, UGPoint3D*> C3DPointList;
//deleted by xielin end ^_^

}

#endif // !defined(AFX_UGEDITOBJ_H__D54EB6A7_FAD5_4F29_BD46_1C5907AB4AC7__INCLUDED_)
