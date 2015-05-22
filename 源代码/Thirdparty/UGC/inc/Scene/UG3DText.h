/* 
	\file UG3DText.h
	\brief �ļ����ݵļ�Ҫ������
	\author �ļ�����
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

// UG3DText.h: interface for the UG3DText class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTEXT_H__8284F63B_BBB9_46D8_BE44_44190C2E8662__INCLUDED_)
#define AFX_UGTEXT_H__8284F63B_BBB9_46D8_BE44_44190C2E8662__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include "Scene/UGColorValue.h"

namespace UGC
{

	//! \brief
	typedef enum Text3DType
	{
		TEXT_2D,
		TEXT_3D
	};
	//! \brief ��ļ�Ҫ˵����
	//! \remarks ��ע��Ϣ��
	class SCENE_API UG3DText: public UGRenderable, public UGMovableObject 
	{
		public:
			//! \brief ���캯��
			UG3DText();
			//! \brief ��������
			virtual ~UG3DText();

			//! \brief �����ǲ�ͬ��Ч��,�������� 
			//void SetFont(HFONT hFont);
			//! \brief
			void Initialize();
			//! \brief
			void Update();
			//! \brief
			void Render();
			//! \brief
			void Release();
			//! \brief
			void SetText(const UGString&  strText);
		public:
			//! \brief �߿���ɫ
			UGColorValue m_OutlineColor;
			//! \brief ������ɫ
			UGColorValue m_TextColor;  
			
		//	HFONT    m_hFont; //����
			//! \brief �ı���
			UGString m_strText;

			//! \brief
			Text3DType m_Text3DType;
			//! \brief
			UGint* m_pCharList;		

	};

}

#endif // !defined(AFX_UGTEXT_H__8284F63B_BBB9_46D8_BE44_44190C2E8662__INCLUDED_)
