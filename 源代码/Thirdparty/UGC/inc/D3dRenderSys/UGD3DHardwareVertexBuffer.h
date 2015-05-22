/* 
	\file UGD3DHardwareVertexBuffer.h
	\brief Ӳ�����㻺����
	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGD3DHARDWAREVERTEXBUFFER_H__E37468E5_451A_4FE4_94B1_ED9C639F3FEC__INCLUDED_)
#define AFX_UGD3DHARDWAREVERTEXBUFFER_H__E37468E5_451A_4FE4_94B1_ED9C639F3FEC__INCLUDED_

#include "D3dRenderSys/UGD3D9Prerequisites.h"
#include "Scene/UGHardwareVertexBuffer.h"

namespace UGC 
{

//! \brief Ӳ�����㻺���ࡣ
class D3DRENDERSYS_API UGD3DHardwareVertexBuffer : public UGHardwareVertexBuffer
{

public:
	
	//! \brief ���캯����
	UGD3DHardwareVertexBuffer();	
	
	//! \brief ����������
	virtual ~UGD3DHardwareVertexBuffer();	

public:
	
	//! \brief ��ȡ���㻺�塣
	//! \return ���㻺�塣
	LPDIRECT3DVERTEXBUFFER9 getD3D9VertexBuffer(void) const;	

protected:
	
	//! \brief ���㻺�塣
	LPDIRECT3DVERTEXBUFFER9 m_lpD3DBuffer;

};

}

#endif // !defined(AFX_UGD3DHARDWAREVERTEXBUFFER_H__E37468E5_451A_4FE4_94B1_ED9C639F3FEC__INCLUDED_)
