// UGRegionSelect.h: interface for the UGRegionSelect class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGRegionSelect.h
   **************************************************************************************
    \author   �¹���
    \brief    �����ѡ���࣬���ڷŴ���С�����Ρ�Բ�Ρ������ѡ�����ʾ��                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGREGIONSELECT_H__669C9A60_C4D6_483E_892D_6575FB1A128A__INCLUDED_)
#define AFX_UGREGIONSELECT_H__669C9A60_C4D6_483E_892D_6575FB1A128A__INCLUDED_

#include "Geometry/UGGeoRegion.h"

namespace UGC {

class UGGraphics;
class UGMapWnd;

class EDITOR_API UGRegionSelect  
{
public:
	enum
	{
		Rectangle,		//����ѡ��
		Circle,			//Բѡ��
		Polygon		//�����ѡ��
	};
public:
	UGRegionSelect();
	virtual ~UGRegionSelect();
	
public:
	UGbool IsTrackingEnable();
	UGbool IsTracking();

	void OnDraw(UGGraphics* pGraphics);
	void StartTracking(UGMapWnd* pMapWnd, UGint nSelectType);
	void EndTracking(UGGraphics* pGraphics, UGbool bJava = false);	

	UGbool AddHandle(UGGraphics* pGraphics, const UGPoint2D& point, UGbool bJava = false);
	UGbool MoveHandle(UGGraphics* pGraphics, const UGPoint2D& point, UGbool bJava = false);
	void RemoveAll();

	UGbool ConvertToGeoRegion(UGGeoRegion& region);
	UGbool ConvertToRect(UGRect2D& rect);

	UGbool ComputeBounds();	
	UGRect2D GetBounds();

protected:
	UGbool InvalidRect(UGGraphics* pGraphics, UGbool bJava = false);

protected:
	UGint m_nType;				//����:Rectangle,Circle,Polygon
	UGArray<UGPoint2D> m_Points;	//���ٿ�ʼ���������㼯�ĵ�������
	UGPoint2D m_pntLastMove;	//���һ����
	UGbool m_bIsTracking;		//�ж��Ƿ����ڸ���
	UGbool m_bTrackingEnable;	//�Ƿ���Ը���
	UGRect2D m_rcBounds;		//ˢ�·�Χ
	UGMapWnd *m_pMapWnd;

};

}

#endif // !defined(AFX_UGREGIONSELECT_H__669C9A60_C4D6_483E_892D_6575FB1A128A__INCLUDED_)
