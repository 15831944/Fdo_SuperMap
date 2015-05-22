// UGGeoEvent.h: interface for the UGGeoEvent class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGGeoEvent.h
   **************************************************************************************
    \author   �¹���
    \brief    ����ͼ���¼������ࡣ                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGGEOEVENT_H__6A5EEB50_CB05_4157_8707_8B9B17A9DE1D__INCLUDED_)
#define AFX_UGGEOEVENT_H__6A5EEB50_CB05_4157_8707_8B9B17A9DE1D__INCLUDED_

#include "Geometry/UGGeometry.h"
#include "Engine/UGDatasetVector.h"

namespace UGC {

class MAP_API UGGeoEvent  
{
public:
	UGGeoEvent(UGRecordset* pRecordset );
	virtual ~UGGeoEvent();

public:	
	//! \brief ��ȡ�ü��ζ���
	UGGeometry* GetGeometry()const;
	//! \brief ���ö�Ӧ���ζ���
	/**
	\return ���ü��ζ����Ƿ�ɹ�
	*/
	UGbool SetGeometry(const UGGeometry* pGeometry);
	//! \brief ���ü��ζ����Ӧ�ķ��
	void SetStyle(const UGStyle& style);
	//! \brief �ͷż��ζ���
	void ReleaseGeometry();
	//! \brief ���ζ����ƶ���
	void MoveTo(UGdouble dx, UGdouble dy);	
	//! \brief ���ζ����ƶ�
	void Move(UGdouble dx, UGdouble dy);	

	//! \brief �õ����ζ���ı�ǩ
	UGString GetTag()const;
	//! \brief ���ü��ζ���ı�ǩ
	void SetTag(const UGString& strTag);

//	UGPoint2D GetCurPos()const;
//	void SetCurPos(const UGPoint2D& pntCurPos);

public:
	UGRecordset* m_pRecordset; 
	UGint m_nSmid;
	UGString m_strTag;		//! \brief ��ǩ
//	UGPoint2D m_pntCurPos;	//��ǰλ��

};

}

#endif // !defined(AFX_UGGEOEVENT_H__6A5EEB50_CB05_4157_8707_8B9B17A9DE1D__INCLUDED_)
