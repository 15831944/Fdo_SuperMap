// UGWBrush.h: interface for the UGWBrush class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGWBrush.h
   **************************************************************************************
    \author   ���������¹���
    \brief    Windows��ˢ��                                                          
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGWBRUSH_H__DABFE627_2C7D_4317_AFEE_CEBE4167CA9B__INCLUDED_)
#define AFX_UGWBRUSH_H__DABFE627_2C7D_4317_AFEE_CEBE4167CA9B__INCLUDED_

#include "Graphics/UGBrush.h"

namespace UGC
{

class WGRAPHICS_API UGWBrush : public UGBrush  
{
public:
	UGWBrush();
	virtual ~UGWBrush();

	virtual UGbool Create();
	virtual UGbool Create(const UGBrushData& BrushData);
	virtual UGbool Create(UGint nStyle, UGColor clrColor, 
					UGint nOpacity = 100,
					UGint nGradientAngle = 0,
					UGSize szGradientOffset = UGSize(0, 0),
					UGImage* pImage = NULL);	
	virtual void DeleteObject();
private:
	UGbool m_bNeedRelease;	
};

}

#endif // !defined(AFX_UGWBRUSH_H__DABFE627_2C7D_4317_AFEE_CEBE4167CA9B__INCLUDED_)
