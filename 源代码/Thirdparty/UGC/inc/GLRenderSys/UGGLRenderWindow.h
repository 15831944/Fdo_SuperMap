/* 
	\file UGGLRenderWindow.h
	\brief GL�������ļ���
	\author zhangyl luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGGLRENDERWINDOW_H__AD8A9CEA_3B6A_46DB_B7C8_DC094C053271__INCLUDED_)
#define AFX_UGGLRENDERWINDOW_H__AD8A9CEA_3B6A_46DB_B7C8_DC094C053271__INCLUDED_

#include "GLRenderSys/UGGLPrerequisites.h"
#include "Scene/UGRenderWindow.h"

namespace UGC
{

//! \brief GL�����ࡣ
class GLRENDERSYS_API UGGLRenderWindow : public UGRenderWindow
{
public:

	//! \brief ���캯����
	UGGLRenderWindow();	
	
	//! \brief ����������
	virtual ~UGGLRenderWindow();	
	
	//! \brief �������ں�����
	//! \param name ����[in]��
	//! \param hWnd �ⲿ���[in]��
	//! \param *miscParams ���ò����б�[in]��
	virtual void Create(UGString name, Window hWnd, NameValuePairList *miscParams);	
	
	//! \brief ����ǰ�󻺴档
	//! \param waitForVSync trueΪ�ȴ���ֱˢ�£�falseΪ���ȴ�[in]��
	void SwapBuffers(UGbool waitForVSync);	

protected:
	
	//! \brief ����GL��Դ��
	void CreateGLResources();	
	//! \brief �ͷź�����
	void Destroy(void);	
	
	//! \brief �ͷ�GL��Դ������
	void DestroyGLResources();	

protected:

	//! \brief OpenGL�����ľ��
	GLContext m_glcontext;

	//! \brief ����������ʽ
	VisualInfo m_VisualInfo;	

};

}


#endif // !defined(AFX_UGGLRENDERWINDOW_H__AD8A9CEA_3B6A_46DB_B7C8_DC094C053271__INCLUDED_)
