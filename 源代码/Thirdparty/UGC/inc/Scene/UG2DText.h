/* 
	\file UG2DText.h
	\brief �ļ����ݵļ�Ҫ������
	\author �ļ�����
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/


// UG2DText.h: interface for the UG2DText class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG2DTEXT_H__80FFDD9F_A58F_4FE5_9453_AE3832C81569__INCLUDED_)
#define AFX_UG2DTEXT_H__80FFDD9F_A58F_4FE5_9453_AE3832C81569__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"
#include "Scene/UGColorValue.h"

namespace UGC
{
//! \brief ��ļ�Ҫ˵����
//! \remarks ��ע��Ϣ��
class SCENE_API UG2DText : public UGRenderObject
{
public:
	//! \brief 
	UG2DText();
	//! \brief 
	UG2DText(const UGString& strText,const UGVector3R& vecPos);	
    //! \brief 
	virtual ~UG2DText();
	//! \brief 
	void SetText(const UGString&  strText);
	//! \brief ע�����ﴫ���ǿռ����꣬���Ǿ�γ�����꣬���Ծ�γ�����������������ת��
	void SetTextPos(UGReal x,UGReal y,UGReal z);
	//! \brief 
	void SetTextPos(const UGVector3R& vecPos);
	//! \brief
	UGVector3R GetTextPos();
	//! \brief
	void Render();
	//! \brief
	UGString GetText();
private:
	//! \brief �ı���
	UGString m_strText;
	//! \brief �������ά�ռ�������Ǿ�γ������
	UGVector3R m_vecPos;
};
}

#endif // !defined(AFX_UG2DTEXT_H__80FFDD9F_A58F_4FE5_9453_AE3832C81569__INCLUDED_)
