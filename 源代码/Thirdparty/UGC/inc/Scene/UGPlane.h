// UGPlane.h: interface for the UGPlane class.
//
//////////////////////////////////////////////////////////////////////
/* 
	\file UGPlane.h
	\brief UGC��άƽ����ͷ�ļ���
	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGPLANE_H__FB442292_3E4D_49F8_A98D_245EE80AE3B2__INCLUDED_)
#define AFX_UGPLANE_H__FB442292_3E4D_49F8_A98D_245EE80AE3B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGVector3R.h"

namespace UGC 
{
//! \brief ��άƽ���࣬���Ӿ�����ʹ�á�
//! \remarks 
	
class SCENE_API UGPlane  
{
public:
	UGPlane();
	UGPlane(const UGVector3R& vec,UGReal fDistance);
	virtual ~UGPlane();
	void Normalize();

	//! \brief ��ȡָ���ĵ㵽��ƽ��ľ���ֵ��
	//! \param vPoint ָ������ά�ռ��еĵ�λ��[in]��
	//! \return ���ؼ�������ľ��롣
	UGReal GetDistance(const UGVector3R& vPoint)const;

	//! \brief ��Ա�ļ�Ҫ˵����
	//! \remarks ��ע��Ϣ��
	UGVector3R m_vNormal;
	UGReal m_fDistance;
};
}
#endif // !defined(AFX_UGPLANE_H__FB442292_3E4D_49F8_A98D_245EE80AE3B2__INCLUDED_)
