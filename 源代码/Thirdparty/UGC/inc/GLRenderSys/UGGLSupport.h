/**  \file UGGLSupport.h
   \brief   ����OpenGL�汾��Ϣ�Լ���ά��ʾЧ��֧�̶ֳ�
   \auothor malq
   \attetion
   Copyright(c) 1996-2007 SuperMap GIS Technolgoies, Inc<br>
   All Rights Reserved
   \version 2.0
   <b>����˵����</b>\n
	<em>1����һ��˵����\n
	<em>2���ڶ���˵����\n
*/

#if !defined(AFX_UGGLSUPPORT_H__2BCCA983_4E86_4CDB_A75C_FD151B10C754__INCLUDED_)
#define AFX_UGGLSUPPORT_H__2BCCA983_4E86_4CDB_A75C_FD151B10C754__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "GLRenderSys/UGGLPrerequisites.h"
#include "Scene/UGConfigOptionMap.h"


namespace UGC 
{

//! \brief ����OpenGL�汾��Ϣ�Լ��Կ���Ϣ	
class GLRENDERSYS_API UGGLSupport  
{

public:

	//! \brief ���캯��
	UGGLSupport();

	//! \brief ��������
	virtual ~UGGLSupport();
	
	//! \brief �ж��Ƿ�֧�ֶ�������
	UGbool HasMultiTexture(void);

	//! \brief ����Ƿ�Ϊ�Ϸ���OpenGL�汾��
	UGbool CheckMinGLVersion(const UGString& version);

	//! \brief ����Ƿ�Ϊ�Ϸ�����չ��
	UGbool CheckExtension(const UGString& extension);
	
	//! \brief ��ȡϵͳ��չ�����Ϣ
	void InitializeExtentions(void);

	//! \brief ��ȡ���������
	const GLint GetMaxTextureSize();
	
	const GLfloat GetMaxPointSize();

	//! \brief ��ȡ���ò�����
	//! \return ���ò���Map��
	UGConfigOptionMap& GetConfigOptions();
	
	//! \brief �������ò�����
	//! \param &name ����[in]��
	//! \param &value ֵ[in]��
	void SetConfigOption(const UGString &name, const UGString &value);	
	
	//! \brief �������á�
	void AddConfig();	
	
	//! \brief ��ʼ��WGL��
	void InitialiseWGL();	
	//! \brief ˢ�����á�
	void RefreshConfig();	
	
	//! \brief �ú������á�
	static LRESULT CALLBACK DummyWndProc(HWND hwnd, UINT umsg, WPARAM wp, LPARAM lp);	
	
protected:
	
	//! \brief Stored options
    UGConfigOptionMap m_Options;
	
	//! \brief ��ʾģʽ�б�
	UGList<DEVMODE> m_DevModes;

	//! \remarks FSAA�б�
	UGList<UGint> m_FSAALevels;

private:

	//! \brief ��չ�б�
	UGList<UGString> m_ExtensionList;
	//! \brief �汾��
	UGString m_strVersion;
	//! \brief ����
	UGString m_strVender;
	//! \brief �Ƿ��ʼ��
	UGbool m_bInited;

};

}

#endif // !defined(AFX_UGGLSUPPORT_H__2BCCA983_4E86_4CDB_A75C_FD151B10C754__INCLUDED_)
