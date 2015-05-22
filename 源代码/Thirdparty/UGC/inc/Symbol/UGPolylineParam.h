
// UGPolylineParam.h

/*!
   **************************************************************************************
    \file     UGPolylineParam.h
   **************************************************************************************
    \author   ֣Ԫ��
    \brief    ���߶β����ࡻ�͡����߲����ࡻ��
	          ��2�������ڸ��������ͻ��߻�����UGLineSymbolBaseDrawer��ʵ�ֻ��ߵ�ģʽѭ�����ƣ�
			  ��ѭ������ģʽ֮ǰ���Ȱ����ߵĲ�������ã�������ѭ������ʱ����ظ����㣬
			  ����ҪĿ������߻���Ч�ʣ�
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-07-18  ֣Ԫ��    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#ifndef UG_POLYLINEPARAM_H
#define UG_POLYLINEPARAM_H

#include "Algorithm/UGPoint.h"
#include "Algorithm/UGPoint2D.h"
#include "Base/UGThread.h"

namespace UGC
{

// ��������ʱ, ��Ҫ��һЩ����,��ǰ�����, ����߻���Ч��

/** �߶β�������¼һ���߶ε�x��y�����ϵļ�࣬�Լ�����
    @remarks
	   
*/
struct UGSegmentParam
{

private:
	//modified by xielin 2007-12-27 ����Ҫ֧�ֶ��̣߳�ȫ�־Ͳ����ˣ��ĵ�
	//! ������Ϊ��CalcVPoint()��CalcHPoint()����ʱ���ط�����ʱ���������һ��Ч�ʣ���2����������ϵͳ��Ƶ������
	//UGdouble ratio;

public:
	UGdouble m_dx;
	UGdouble m_dy;
	UGdouble m_dLen;
	
	UGSegmentParam() : m_dx(0), m_dy(0), m_dLen(0){}
    
	//! ���������߶ε�������򷴷���(dLengthΪ��ֵ), ���ΪptStart, ����ΪdLength�ĵ������
	UGPoint2D CalcHPoint(UGdouble xPtStart, UGdouble yPtStart, UGdouble dLength) const;
	
	//! ���㴹ֱ�߶�, �����ΪptAnchor, �߶�Ϊ dHeight �ĵ������
	UGPoint2D CalcVPoint(UGdouble xPtAnchor, UGdouble yPtAnchor, UGdouble dHeight) const;
	
	
};


class UGPolylineParam
{
public:

	UGPolylineParam();
	
	UGdouble GetTotalLength();

	const UGSegmentParam& GetSegParam(UGint nIndex) const;
	UGSegmentParam& GetSegParam(UGint nIndex);

	const UGSegmentParam& GetCurrentSegParam() const;
	void SetCurrentSegIndex(UGint nCurSegIndex);

	void CalculateParams(const UGPoint* pPoints, UGint nPntCount);

private:
	//! ���ߵ��߶β����ļ���
	UGArray<UGSegmentParam> m_SegParams;
	
	//! ���ߵ����峤��
	UGdouble m_dTotalLength;

	//! ��ǰ���ڴ�����߶�������
	UGint m_nCurSegIndex;

	//added by xielin 2007-12-27 ����һ��
	UGMutex m_mutex;
	
};


}// namesapce UGC

#endif

