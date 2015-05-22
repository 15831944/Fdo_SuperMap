/* 
	\file UG3DLine.h
	\brief �ļ����ݵļ�Ҫ������
	\author �ļ�����
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

// UG3DLine.h: interface for the UG3DLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG3DLINE_H__C0BC817F_7532_486E_94B7_4A6B91963C78__INCLUDED_)
#define AFX_UG3DLINE_H__C0BC817F_7532_486E_94B7_4A6B91963C78__INCLUDED_

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
class SCENE_API UG3DLine: public UGRenderObject
{
public:
	//! \brief ���캯��
	UG3DLine();
	//! \brief ��������
	virtual ~UG3DLine();
	//! \brief ��ʼ��
	void Initialize();
	//! \brief ����
	void Update();
	//! \brief
	void Render();
	//! \brief �ͷ�
	void Release();
	//! \brief ע��ú���������ǿռ����꣬�����Ǿ�γ�������ͶӰ����
	void CreateLine(UGVector3R* pPoints,UGint* pPolyCount,UGint nSubCount);
	//! \brief ע��ú���������ǿռ����꣬�����Ǿ�γ�������ͶӰ���� 
	void CreateLine(UGVector3R* pVectors,UGint nNumPoints);
	//! \brief
	void SetLineStyle(UG3DLineStyle* m_pLineStyle);
	//! \brief
	UG3DLineStyle* GetLineStyle();

	virtual UGbool InterSectWithRadial(const UGVector3R& nearPos, const UGVector3R& farPos);
	UGbool InsectLineWithRadial(UGVector3R lineStart, UGVector3R lineEnd, const UGVector3R& nearPos, const UGVector3R& farPos);
	virtual void SetPickStatus(UGbool status);

	//��������Ϊ������ӿ���ʱ�ӵģ�6.0�ĵ�
	UG3DLine *GetSubLine();
private:
	//! \brief
	UGList<UG3DLine*>m_SubList;
	//! \brief ע��������ָ�������洫��ģ�UG3DLine�������ͷ�
	UG3DLineStyle* m_pLineStyle;


	UGVector3R tmpLineStart;
	UGVector3R tmpLineEnd;
	UGVector3R tmpLineIntersectPoint;

 
};
}
#endif // !defined(AFX_UG3DLINE_H__C0BC817F_7532_486E_94B7_4A6B91963C78__INCLUDED_)
