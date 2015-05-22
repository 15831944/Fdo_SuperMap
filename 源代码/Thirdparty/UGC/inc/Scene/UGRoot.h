// UGRoot.h: interface for the UGRoot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGROOT_H__03A35829_E853_4F08_82E9_704E50EF7DC1__INCLUDED_)
#define AFX_UGROOT_H__03A35829_E853_4F08_82E9_704E50EF7DC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGScene.h"
#include "Scene/UG3DWorkThread.h"
#include "Scene/UG3DWindowTypes.h"
#include "Scene/UGRenderWindow.h"
#include "Scene/UGSingleton.h"
namespace UGC
{

//! \brief �ض�����������,�ض��庯��ָ��	
typedef  UGRenderSys* (*CREATERENDERSYS)();

class SCENE_API UGRoot : public UGSingleton<UGRoot>
{
public:
	//! \brief ������Ⱦ��ʽö�ٳ���
	typedef enum _RenderSysType
	{
		RST_NONE = 0, 
			RST_OGL = 1, 
			RST_D3D = 2
	} RenderSysType;
public:
	UGRoot();
	virtual ~UGRoot();
	
	
public:
	UGScene &GetScene();
	//! \brief ���ʹ�ù���Դ�����������е��øú���
	void Fini();
	
	//! \brief ���ô�����Ⱦ����
	void SetRenderSysType(RenderSysType renderSysType);	
	
	//! \brief �õ�������Ⱦ����
	RenderSysType  GetRenderSysType();
	
	//! \brief ���д�����
	/**
	���������ɳ�����Ⱦ,�����Գ������д����ڸú��������
	\param lCount û���õ�,����ɾ��
	*/
	void OnApplicationIdle(UGlong lCount);		
	
	//! \brief ��ʼ��UGRenderWindow����
	UGRenderWindow *Initialize(Window hWnd);
	UGDict<RenderSysType, UGRenderSys*> &GetRenderSysMap();
	
	UGRenderSys* GetActiveRenderSys();
	
	void SetActiveRenderSys(UGRenderSys* pActiveRenderSys);	
	// �������е�RenderTargetΪͬһ������ 
	void SetRenderTargetsFont(const UGTextStyle& textStyle);
	
protected:
	
	void UpdateAllRenderTargets(void);		
	
	void CreateWorkThread();	
	
	//! \brief �����Ƿ����
	UGbool IsAppStillIdle();	
	UGRenderSys* SetupGLRenderSys();
	UGRenderSys* SetupD3DRenderSys();
	void SetupRenderSys();
	
public:
	
	//! \brief ��ǰ��Ⱦϵͳ
	static UGRoot& GetSingleton();
	
	
protected:
	//! \brief ��Ⱦ��������
	RenderSysType m_nRenderSysType;		
	
	UGDict<RenderSysType, UGRenderSys*> m_RenderSysMap;	
	
	UGRenderSys* m_pActiveRenderSys;
	
	//! \brief ��Ⱦ��̬����
	void* m_hRSLibHandle;
	UGDict<RenderSysType, void*> m_RSLibHandle;	 
	
	//! \brief �����߳�ָ��
	UG3DWorkThread *m_pWorkThread;
	
	UGScene m_Scene;
	
	
};
}
#endif // !defined(AFX_UGROOT_H__03A35829_E853_4F08_82E9_704E50EF7DC1__INCLUDED_)
