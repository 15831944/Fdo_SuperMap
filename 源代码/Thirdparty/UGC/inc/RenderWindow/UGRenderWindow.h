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

#include "Base/ugdefs.h"
#include "RenderWindow/UG3DWorkThread.h"
#include "RenderWindow/UG3DWindowTypes.h"
#include "Scene/UGScene.h"
#include "Scene/UGAngle.h"
#include "Scene/UGMathEngine.h"
#include "Scene/DrawArgs.h"
#include "Algorithm/UGPoint.h"

namespace UGC
{

//! \brief �ض�����������,�ض��庯��ָ��	
typedef  UGRenderSys* (*CREATEGLRENDERSYS)();
typedef  UGRenderSys* (*CREATED3DRENDERSYS)(Window hwnd);

//! \brief ��Ⱦ������
/**
  ��Ⱦ��������������봰����ز���
*/
class RENDERWINDOW_API UGRenderWindow
{

public:
	
	//! \brief ������Ⱦ��ʽö�ٳ���
	typedef enum _RenderSysType
	{
		RST_NONE = 0, 
		RST_OGL = 1, 
		RST_D3D = 2
	} RenderSysType;
	
	//! \brief ���캯��
	UGRenderWindow();

	//! \brief ��������
	virtual ~UGRenderWindow();
	
	//! \brief ���ʹ�ù���Դ�����������е��øú���
	void fini();

	//! \brief ��ʼ��UGRenderWindow����
	void Initialize();
	
	//! \brief ������Ⱦ��������
	void Update();

	//! \brief ��Ⱦ
	void Render();

	void SetupRenderSys(Window wnd);
	//! \brief ���ô�����Ⱦ����
	void SetRenderSysType(RenderSysType renderSysType);
	
	//! \brief �õ�������Ⱦ����
	RenderSysType  GetRenderSysType();

	//! \brief ��ȡ��Ⱦ��������
	DrawArgs &GetDrawArgs();

	//! \brief ��ȡ��������
	UGScene &GetScene();

	UGDict<RenderSysType, UGRenderSys*> &GetRenderSysList();

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
	
	//! \brief ���д�����
	/**
	  ���������ɳ�����Ⱦ,�����Գ������д����ڸú��������
	  \param lCount û���õ�,����ɾ��
	*/
	void OnApplicationIdle(UGlong lCount);	
	
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

private:
	//! \brief ��������
	void swapBuffers(void);

	//! \brief ׼��OpenGLʹ�û���
	/**
	  \remark   �������ֱ��ʹ��window����
	  \attetion ���߱���ƽ̨����
	            ���ڸĽ�
	*/
	UGbool makeCurrent(void) const;

	//! \brief ɾ��OpenGL����
	void KillGLWindow();
	//! \brief ��ʼ��windowʹ��OpenGL����
	UGbool InitGLWindow();
	
	//! \brief �����Ƿ����
	UGbool IsAppStillIdle();	
	UGRenderSys* SetupGLRenderSys();
	UGRenderSys* SetupD3DRenderSys();
protected:
    
	//! \brief �豸���
	Display3D m_dpy;

	//! \brief ���ھ��
	Window m_wnd;

	//! \brief OpenGL�����ľ��
	GLContext m_glcontext;

	//! \brief ����������ʽ
	VisualInfo m_VisualInfo;
    
	//! \brief ??? 
	void* m_hRSLibHandle;
	
	//! \brief ��갴�¿�ʼλ��
	UGPoint m_pntMouseDownStartPosition;
	
	//! \brief ����Ƿ���ק
	UGbool m_bMouseDragging;
	
	//!  \brief  ��Ⱦ����
	/**
	  \remark ���������ӵ�λ��(�������λ��)
	  ���ü�����Ⱦϵͳ��
	*/
	DrawArgs m_DrawArgs;

	//! \brief ������
	/**
	  �������,��Ⱦ�����б�,�������ݵ�
	*/
	UGScene m_Scene;
	
	//! \brief ��Ⱦ��������
	RenderSysType m_nRenderSysType;
	
	//! \brief �����߳�ָ��
	UG3DWorkThread *m_pWorkThread;

	UGDict<RenderSysType, UGRenderSys*> m_RenderSys;
	UGDict<RenderSysType, void*> m_RSLibHandle;	 
	
	//! \brief ������Ⱦϵͳ
	UGRenderSys* m_pActiveRenderSys;
	
	//! \brief �������ٶ�����
	UGdouble   m_dblVKOperatorRatio;
	//! \brief ˳��ʱ����ת�ٶ�����
	UGdouble   m_dblRotateClockwiseRatio;
	//! \brief ���·�ת�ٶ����� 
	UGdouble   m_dblRotateUpDownRatio;
	//! \brief �Ŵ���С�ٶ�����
	UGdouble   m_dblZoomRatio;
};

}
#endif // !defined(AFX_UGRENDERWINDOW_H__951EEDAF_4364_4D61_A736_9DCC181F5F52__INCLUDED_)
