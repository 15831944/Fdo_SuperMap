/* 
	\file UGD3D9RenderWindow.h
	\brief �����ࡣ
	\author zhangyl  luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/
	
#if !defined(AFX_UGD3D9RENDERWINDOW_H__FE82B3D4_7CA9_41F6_9A74_AF0EBE45ED74__INCLUDED_)
#define AFX_UGD3D9RENDERWINDOW_H__FE82B3D4_7CA9_41F6_9A74_AF0EBE45ED74__INCLUDED_


#include "Scene/UGRenderWindow.h"
#include "D3dRenderSys/UGD3D9Driver.h"
#include "Scene/UGConfigOptionMap.h"

namespace UGC
{

//! \brief �����ࡣ
class UGD3D9RenderWindow : public UGRenderWindow  
{

public:

	//! \brief ���������캯����
	//! \param *pDriver �豸ָ��[in]��
	UGD3D9RenderWindow(UGD3D9Driver *pDriver);	
	
	//! \brief ����������
	virtual ~UGD3D9RenderWindow();	
	
	//! \brief ��ȡD3D�豸����
	//! \return D3D�豸����
	LPDIRECT3DDEVICE9 GetD3DDevice();	
	
	//! \brief ��ȡ�Զ������ԡ�
	//! \param name ����[in]��
	//! \param pData ����ָ��[in]��
	void GetCustomAttribute( const UGString& name, void* pData );	
	
	//! \brief �������ڡ�
	//! \param name ����[in]��
	//! \param hWnd �ⲿ���[in]��
	virtual void Create(UGString name, Window hWnd, NameValuePairList *miscParams);	
	
	//! \brief ����D3D��
	void Destroy(void);	
	
	//! \brief ����D3D��Դ��
	void DestroyD3DResources();	
	
	//! \brief ����ǰ��̨���档
	//! \param waitForVSync [in]��
	void SwapBuffers( UGbool waitForVSync );	

	//! \brief ��ȡD3D��ʾ������
	//! \return ��ʾ�����ṹ��ָ�롣
	D3DPRESENT_PARAMETERS* GetPresentationParameters(void);	
	

protected:	
	
	//! \brief ����D3D��Դ��
	void CreateD3DResources(NameValuePairList *miscParams);	

protected:
	
	//! \brief D3D�豸����
	UGD3D9Driver *m_pDriver;			// D3D9 driver
	
	//! \brief D3D��ʾ�����ṹ�塣
	D3DPRESENT_PARAMETERS m_d3dpp;
	
	//! \brief �Ƿ�ֱ��ʾ��
	UGbool m_bVSync;

	//! \brief FSAA����(���ز�������)��
	D3DMULTISAMPLE_TYPE m_FSAAType;

	//! \brief FSAA������
	DWORD m_FSAAQuality;
	
	UGbool m_bUseNVPerfHUD;
};

}
#endif // !defined(AFX_UGD3D9RENDERWINDOW_H__FE82B3D4_7CA9_41F6_9A74_AF0EBE45ED74__INCLUDED_)
