// UGWGraphicsFactory.h: interface for the UGWGraphicsFactory class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGWGraphicsFactory.h
   **************************************************************************************
    \author   ���������¹���
    \brief    Windowsͼ����ʾ������                                                  
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGWGRAPHICSFACTORY_H__FE0DA47F_9B1F_45AB_BB2C_AE19E3B6A332__INCLUDED_)
#define AFX_UGWGRAPHICSFACTORY_H__FE0DA47F_9B1F_45AB_BB2C_AE19E3B6A332__INCLUDED_

#include "Graphics/UGGraphicsFactory.h"

namespace UGC
{

extern "C" WGRAPHICS_API UGGraphicsFactory * CreateGraphicsFactory();

class WGRAPHICS_API UGWGraphicsFactory : public UGGraphicsFactory  
{
public:
	UGWGraphicsFactory();
	virtual ~UGWGraphicsFactory();

public:
	virtual UGint GetType();
	virtual UGString GetName();
	virtual UGGraphics* NewGraphics();
	virtual UGBrush* NewBrush();
	virtual UGFont* NewFont();
	virtual UGImage* NewImage();
	virtual UGPen* NewPen();
	virtual UGRgn* NewRgn();

};

}

#endif // !defined(AFX_UGWGRAPHICSFACTORY_H__FE0DA47F_9B1F_45AB_BB2C_AE19E3B6A332__INCLUDED_)
