// Install.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#include "LangSetup.h"
// CInstallApp:
// �йش����ʵ�֣������ Install.cpp
//

class CInstallApp : public CWinApp
{
public:
	CInstallApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
public:
	CLangSetup m_lsetup;
	//
	LANGID m_wdCurrentLocaleID;
};

extern CInstallApp theApp;