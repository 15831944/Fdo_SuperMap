/* 
	\file UG3DStyle.h
	\brief �ļ����ݵļ�Ҫ������
	\author �ļ�����
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

// UG3DStyle.h: interface for the UG3DStyle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG3DSTYLE_H__726C9B52_917E_4FA3_8C40_E9CBE4AE5DA3__INCLUDED_)
#define AFX_UG3DSTYLE_H__726C9B52_917E_4FA3_8C40_E9CBE4AE5DA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGColorValue.h"
namespace UGC
{
//! \brief
enum UG3DPointType
{
	PT_SIMPLE,
	PT_ICON,
	PT_ENTITY
};
//! \brief ��ļ�Ҫ˵����
//! \remarks ��ע��Ϣ��
class SCENE_API UG3DPointStyle  
{
public:
	//! \brief ���캯��
	UG3DPointStyle();
	//! \brief ��������
	virtual ~UG3DPointStyle();
	//! \brief �õ���������ɫ
	UGColorValue GetPointColor();
	//! \brief �õ������Ĵ�С
	UGReal      GetPointSize();
	//! \brief �õ�����������
	UG3DPointType	GetPointType();
	//! \brief �õ�ͼ�����ʹ�õ�ͼ���·��
	UGString    GetPointIconPath();
	//! \brief �õ�ģ�͵���ʹ�õ�ģ�͵�·��
	UGString    GetPointModelPath();
	//! \brief 
	UGbool		IsPointSmooth();
	//! \brief
	UGbool 		IsPointSizeAutoChanged();
	//! \brief
	UGReal*		GetPointQuadratic();
	//! \brief ����Ƿ����˸ı䣬������ڿ���ͼ��ģ�͵ȵĸ���
	UGbool		IsIconChanged();
	//! \brief
	UGbool		IsModelChanged();
	
	//! \brief ���õ���������
	void		SetPointType(UG3DPointType enPointType);
	//! \brief ����ͼ�����ʹ�õ�ͼ���·��
	void		SetPointIconPath(const UGString& strIconPath);
	//! \brief ����ģ�͵���ʹ�õ�ģ�͵�·��
	void		SetPointModelPath(const UGString& strModelPath);
	//! \brief ���õ�������ɫ
	void		SetPointColor(const UGColorValue& color);
	//! \brief ���õ����Ĵ�С
	void		SetPointSize(UGReal fSize);
	//! \brief ���õ�Ĵ�С�����ı�Ĳ������ӣ���ͼ�����Ч
	void		SetQuadratic(UGReal a,UGReal b,UGReal c);
	//! \brief ����
	void		SetPointSmooth(UGbool bSmooth);
	//! \brief 
	void		SetPointSizeAutoChanged(UGbool bChanged);
	//! \brief 
	void		SetIconChanged(UGbool bChanged);
	//! \brief
	void		SetModelChanged(UGbool bChanged);


private:
	//! \brief ͼ�����ʹ�õ�ͼ��
	UGString m_strPointIcon;
	//! \brief ģ�͵���ʹ�õ�ģ��
	UGString m_strPointModel;
	//! \brief �����ɫ
	UGColorValue m_PointColor;
	//! \brief ��Ĵ�С
	UGReal       m_fPointSize;
	//! \brief ������� 
	UG3DPointType m_enPointType;
	//! \brief ��Ĵ�С�Ƿ��������ı䣬��ͼ�����Ч
	UGbool m_bSizeChanged;
	//! \brief ��Ĵ�С�����ı�Ĳ������ӣ���ͼ�����Ч
	UGReal  m_Quadratic[3];
	//! \brief ����Բ�ε㻹�Ƿ��͵㣬����ͨ����Ч��ΪTRUE��ʾԲ�ε�
	UGbool m_bSmooth;
	//! \brief
	UGbool m_bIconChanged;
	//! \brief 
	UGbool m_bModelChanged;
};
//! \brief ��ļ�Ҫ˵����
//! \remarks ��ע��Ϣ��
class SCENE_API UG3DLineStyle  
{
public:
	//! \brief ���캯��
	UG3DLineStyle();
	//! \brief ��������
	virtual ~UG3DLineStyle();
	//! \brief �õ��߶������ɫ
	UGColorValue GetLineColor();
	//! \brief �õ��߶���Ŀ��
	UGReal		 GetLineWidth();
	//! \brief �����߶������ɫ
	void		 SetLineColor(UGColorValue color);
	//! \brief �����߶���Ŀ��
	void		 SetLineWidth(UGReal fWidth);
private:
	//! \brief �߶������ɫֵ
	UGColorValue m_LineColor;
	//! \brief �߶���Ŀ��ֵ
	UGReal	     m_fLineWidth;
};

}

#endif // !defined(AFX_UG3DSTYLE_H__726C9B52_917E_4FA3_8C40_E9CBE4AE5DA3__INCLUDED_)
