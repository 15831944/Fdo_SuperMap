// SmEditCompoundTool.h: interface for the UGEditCompoundTool class.
//
//////////////////////////////////////////////////////////////////////
//=====================================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 2.0
// ��  �ߣ�		    ����
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSupermap GIS����������Ա��δ����ɲ������Դ�����
//				    2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����	     SmEditCompoundTool.h
// ��  ����		 SmEditCompoundTool
// ��  �ࣺ		 UGEditTool
// ��  �ࣺ			
// ����˵����	 ���϶���༭����	
// ����˵����		
//=====================================================================================
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_UGEDITCOMPOUNDTOOL_H__E6084E9B_4146_4D16_B578_CE3B0C9B957F__INCLUDED_)
#define AFX_UGEDITCOMPOUNDTOOL_H__E6084E9B_4146_4D16_B578_CE3B0C9B957F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Editor/UGEditTool.h"
namespace UGC {

class EDITOR_API UGEditCompoundTool : public UGEditTool  //���϶���༭����
{
public:
	UGEditCompoundTool();
	virtual ~UGEditCompoundTool();
public:
	UGint m_nCurObjIndex;									 //��ǰ�༭��������	
	UGbool m_bEditGIS;									 //�Ƿ�༭GIS���ݼ�������������ձ༭�����Ķ����Ƿ��ǲ���������
	UGint m_lSubAction;									 //�ӱ༭���ߵ�����	
	UGbool m_bClosed;										//�Ƿ�պ�
protected:
	UGEditTool * m_pSubEditTool;                        //�ӱ༭����
public:
	UGbool  Merge();								//���Ӷ���ϲ�Ϊһ�������ζ���
	void SetSubEditTool(								//�����ӱ༭����								
						UGGraphics* pGraphics,						//�豸������ָ��
						UGlong lSubAction,                //�µ�SubAction 
						UGEditTool * pSubEditTool);	//�ӱ༭����
	UGEditTool * GetSubEditTool();					    //ȡ���ӱ༭����
public:
	virtual UGbool OnRButtonUp( UGGraphics* pGraphics, UGuint nFlags, UGPoint point); //ѡ���������Ҽ��������Ϣ����
    virtual UGbool OnRButtonDown( UGGraphics* pGraphics, UGuint nFlags, UGPoint point);//ѡ���������Ҽ����µ���Ϣ����
    virtual UGbool OnLButtonUp( UGGraphics* pGraphics, UGuint nFlags, UGPoint point);//ѡ������������������Ϣ����
    virtual UGbool OnLButtonDown( UGGraphics* pGraphics, UGuint nFlags, UGPoint point);//ѡ��������������µ���Ϣ����
    virtual UGbool OnLButtonDblClk( UGGraphics* pGraphics, UGuint nFlags, UGPoint point);//ѡ�����������˫������Ϣ����
    virtual UGbool OnMouseMove( UGGraphics* pGraphics, UGuint nFlags, UGPoint point);//ѡ���������ƶ���Ϣ
    virtual UGbool OnSetCursor( UGuint nHitTest, UGuint message);//ѡ�������״
    virtual UGbool OnKeyDown( UGGraphics* pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);//ѡ�񰴼���Ϣ����
    virtual UGbool OnDraw( UGGraphics* pGraphics); //��ָ���豸�л����༭����   
    virtual UGbool Clear( UGGraphics* pGraphics ); //����༭����
	virtual UGbool OnUndo( UGGraphics* pGraphics); //��������
    virtual UGbool OnRedo( UGGraphics* pGraphics); //�ָ�����

	virtual UGbool IsUndoToolEnabled();		//�ж��Ƿ���Գ�����һ������
	virtual UGbool IsRedoToolEnabled();		//�ж��Ƿ���Իָ���һ������
};

}

#endif // !defined(AFX_UGEDITCOMPOUNDTOOL_H__E6084E9B_4146_4D16_B578_CE3B0C9B957F__INCLUDED_)
