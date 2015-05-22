// UGGraphicsManager.h: interface for the UGGraphicsManager class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGGraphicsManager.h
   **************************************************************************************
    \author   �¹���
    \brief    ͼ����ʾ��̬�������                                                   
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGGRAPHICSMANAGER_H__7462DA56_C7AD_4864_8025_55756A95E4EC__INCLUDED_)
#define AFX_UGGRAPHICSMANAGER_H__7462DA56_C7AD_4864_8025_55756A95E4EC__INCLUDED_

#include "UGGraphicsFactory.h"

namespace UGC {

class GRAPHICS_API UGGraphicsManager  
{
public:
	struct UGGraphicsDefine
	{
		void* hHandle;
		UGGraphicsFactory *pGraphicsFactory;
		UGString strName;
		UGint nGraphicsType;
		
		UGGraphicsDefine()
		{		
			nGraphicsType = 0;
			pGraphicsFactory = NULL;
			hHandle = NULL;
			strName = ("");
		}
	};

public:
	UGGraphicsManager();
	virtual ~UGGraphicsManager();

public:
	// ���õ�ǰ����ʾ���棬 ������ȷ������true�����򷵻�false
	static UGint GetGraphicsCount();
	static UGbool SetCurGraphicsType(UGint nGraphicsType);
	static UGint GetCurGraphicsType();
	static UGString GetGraphicsName(UGint nGraphicsType);
	static UGGraphics* NewGraphics(UGint nGraphicsType = 0);
	static UGBrush* NewBrush(UGint nGraphicsType = 0);
	static UGFont* NewFont(UGint nGraphicsType = 0);
	static UGImage* NewImage(UGint nGraphicsType = 0);
	static UGPen* NewPen(UGint nGraphicsType = 0);
	static UGRgn* NewRgn(UGint nGraphicsType = 0);

private:
	UGGraphicsDefine* CheckGraphicsDefine(void* hHandle);
	UGGraphicsDefine* Find(UGint nGraphicsType);
	// װ�غ�ж�� ʵ����ʾ����
	void LoadGraphics();
	void UnloadGraphics();

private:
	UGArray<UGGraphicsDefine*> m_GraphicsDefines;
	UGint m_nCurGraphicsType; 	

};

extern GRAPHICS_API UGGraphicsManager g_GraphicsManager;

}

#endif // !defined(AFX_UGGRAPHICSMANAGER_H__7462DA56_C7AD_4864_8025_55756A95E4EC__INCLUDED_)
