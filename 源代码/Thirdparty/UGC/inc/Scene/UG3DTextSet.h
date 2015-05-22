/* 
	\file UG3DTextSet.h
	\brief �ļ����ݵļ�Ҫ������
	\author �ļ�����
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

// UG3DTextSet.h: interface for the UG3DTextSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG3DTEXTSET_H__9C1775CA_8173_4FAD_AD3D_3AA21BA86C38__INCLUDED_)
#define AFX_UG3DTEXTSET_H__9C1775CA_8173_4FAD_AD3D_3AA21BA86C38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"
#include "Scene/UGColorValue.h"
#include "Scene/UG3DText.h"
#include "Base/UGThread.h"
#include "Engine/UGDataset.h"

namespace UGC
{
//! \brief ��ļ�Ҫ˵����
//! \remarks ��ע��Ϣ��
class SCENE_API UG3DTextSet:public UGRenderObject
{
public:
	//! \brief ���캯��
	UG3DTextSet();
	//! \brief ��������
	virtual ~UG3DTextSet();
	//! \brief
	virtual void Release();
	//! \brief
	virtual void Initialize();
	//! \brief
	virtual void Update();
	//! \brief
	virtual void Render();	
	//! \brief
	void RemoveAllText();
	//! \brief ����������ɫ
	void SetTextColor(const UGColorValue& textColor);
private:
	//! \brief ������ɫ
	UGColorValue m_TextColor;
	//! \brief
	UGList<UG3DText*>m_listText;

};
}
#endif // !defined(AFX_UG3DTEXTSET_H__9C1775CA_8173_4FAD_AD3D_3AA21BA86C38__INCLUDED_)
