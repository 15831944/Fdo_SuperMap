/**  \file UGRenderWindow.h
   \brief   ��ƽ̨������
   \auothor malq
   \attetion Ŀǰ��û����ȫʵ�ֿ�ƽ̨��
             ��һЩ����ֱ����window���
			 ���ڹ����Ľ�
   Copyright(c) 1996-2007 SuperMap GIS Technolgoies, Inc<br>
   All Rights Reserved
   \version 2.0
   <b>����˵����</b>\n
	<em>1����һ��˵����\n
	<em>2���ڶ���˵����\n
*/
#if !defined(AFX_UGRENDERWINDOW_H__951EEDAF_4364_4D61_A736_9DCC181F5F52__INCLUDED_)
#define AFX_UGRENDERWINDOW_H__951EEDAF_4364_4D61_A736_9DCC181F5F52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UG3DWorkThread.h"
#include "Scene/UG3DWindowTypes.h"
#include "Scene/UGRenderTarget.h"


namespace UGC
{

typedef UGDict<UGString, UGString> NameValuePairList;

//! \brief ��Ⱦ������
/**
  ��Ⱦ��������������봰����ز���
*/
class SCENE_API UGRenderWindow : public UGRenderTarget
{
public:
	enum UGMap3DUserAction
	{	
		ua3DNull				=0,	// ʲôҲ����
		ua3DPickModel		    =1,	// ѡ��ģ��
		ua3DPickVector          =2  // ѡ��ʸ������
	};
public:	
	//! \brief ���캯��
	UGRenderWindow();
	//! \brief ��������
	virtual ~UGRenderWindow();		
	
	virtual void Create(UGString name, Window hWnd, NameValuePairList *miscParams) = 0;
	virtual void Destroy(void) = 0;
	
	//! \brief ������Ⱦ��������
	void Update();
	void Update(UGbool bSwapBuffers);	
	virtual void SwapBuffers(UGbool waitForVSync = true) = 0;

	//! \brief �������¼�������
	/**
	  \param nFlags   ��������[in]
	  \param zDelta   ��������[in]
	  \param pt       ����λ��[in]
	*/
	void OnMouseWheel(UGuint nFlags, UGshort zDelta, UGPoint pt);
	
	//! \brief ����ƶ��¼�������
	/**
	  \param nFlags  ��������[in]
	  \param point   �������λ��[in]
	*/
	void OnMouseMove(UGuint nFlags, UGPoint point);

	//! \brief �����������¼�������
	/**
	  \param nFlags ��������[in]
	  \param point  �������λ��[in]
	*/
	void OnLButtonDown(UGuint nFlags, UGPoint point);

	//! \brief ������̧���¼�������
	/**
	  \param nFlags ��������[in]
	  \param point  �������λ��[in]
	*/
	void OnLButtonUp(UGuint nFlags, UGPoint point);
	
	//! \brief ����Ҽ������¼�������
	/**
	  \param nFlags ��������[in]
	  \param point  �������λ��[in]
	*/
	void OnRButtonDown(UGuint nFlags, UGPoint point);

	//! \brief ����Ҽ�̧���¼�������
	/**
	  \param nFlags ��������[in]
	  \param point  �������λ��[in]
	*/
	void OnRButtonUp(UGuint nFlags, UGPoint point);

	//! \brief ������˫���¼�������
	/**
	  \param nFlags ��������[in]
	  \param point  �������λ��[in]
	*/
	void OnLButtonDblClk(UGuint nFlags, UGPoint point);

	//! \brief ����Ҽ�˫���¼�������
	/**
	  \param nFlags ��������[in]
	  \param point  �������λ��[in]
	*/
	void OnRButtonDblClk(UGuint nFlags, UGPoint point);

	//! \brief ���ڸı��С�¼�������
	/**
	  \param cx  ���ڿ��
	  \param cy  ���ڸ߶�
	*/
	void OnSize(UGint cx, UGint cy);
	
	//! \brief ���¼��¼�������
	/**
	  \param nChar   ���¼���ֵ[in]
	  \param nRepCnt ���¸ü�����[in]  ����û��ʹ�õ�????
	  \param nFlags  ?????
	*/
	void OnKeyDown(UGuint nChar, UGuint nRepCnt, UGuint nFlags);
	
	
	//! \brief ���ù������ٶ�����
	/**
	  \param dblVKOperatorRatio  �������ٶ�����
	*/
	void SetVKOperatorRation(UGdouble dblVKOperatorRatio);
	
	//! \biref ����˳��ʱ����ת�ٶ�����
	/**
	  \param dblRotateClockwiseRatio ˳��ʱ����ת�ٶ�����
	*/
	void SetRotateClockwiseRatio(UGdouble dblRotateClockwiseRatio);
	
	//! \brief ����������ת�ٶ�����
	/**
	  \param dblRotateUpDownRatio  ���·�ת�ٶ�����
	*/
	void SetRotateUpDownRatio(UGdouble dblRotateUpDownRatio);
	
	//! \brief ���÷Ŵ���С�ٶ�����
	/**
	  \param  dblZoomRatio  �Ŵ���С�ٶ�����
	*/
	void SetZoomRatio(UGdouble dblZoomRatio);
	// �õ���Ⱦ�������Ⱦ�豸
	Display3D GetDisplay();
	// ������Ⱦ���ڵ����� 
	void SetRenderTargetsFont(const UGTextStyle& textStyle);

	UGMap3DUserAction SetUserAction(UGMap3DUserAction action);	
	UGbool   IsNullUserAction();

protected:
	UGMomentumCamera *GetActiveCamera();

protected:
	UGPoint m_pntLastMousePosition;
	
	UGbool m_bLeftMouseButtonDown;
	UGbool m_bLeftMouseButtonUp;
	
	//! \brief��¼����ʱ��
	//! \remark �����жϲ�������
	UGlong m_nLeftMouseDownTime;
	UGlong m_nLeftMouseUpTime;

	UGbool m_bRightMouseButtonDown;
	//! \brief ��갴�¿�ʼλ��
	UGPoint m_pntMouseDownStartPosition;
	UGPoint m_pntMouseUpStartPosition;
	
	//! \brief ����Ƿ���ק
	UGbool m_bMouseDragging;	
	
	//! \brief �������ٶ�����
	UGdouble   m_dblVKOperatorRatio;
	//! \brief ˳��ʱ����ת�ٶ�����
	UGdouble   m_dblRotateClockwiseRatio;
	//! \brief ���·�ת�ٶ����� 
	UGdouble   m_dblRotateUpDownRatio;
	//! \brief �Ŵ���С�ٶ�����
	UGdouble   m_dblZoomRatio;

	//! \brief ���ھ��
	Window m_wnd;
	//! \brief �豸���
	Display3D m_hDisplay;
	//! \brief �豸ʹ�õ�����
	Font3D    m_hFont;

	UGMap3DUserAction m_emUserAction;
	
	

};

}
#endif // !defined(AFX_UGRENDERWINDOW_H__951EEDAF_4364_4D61_A736_9DCC181F5F52__INCLUDED_)
