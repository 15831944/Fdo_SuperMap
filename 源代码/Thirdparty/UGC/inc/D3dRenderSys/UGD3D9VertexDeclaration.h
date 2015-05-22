/* 
	\file UGD3D9VertexDeclaration.h
	\brief ���������ࡣ
	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGD3D9VERTEXDECLARATION_H__9B969F14_5DC9_458F_B0D8_5A51FE01E507__INCLUDED_)
#define AFX_UGD3D9VERTEXDECLARATION_H__9B969F14_5DC9_458F_B0D8_5A51FE01E507__INCLUDED_

#include "D3dRenderSys/UGD3D9Prerequisites.h"
#include "Scene/UGHardwareVertexBuffer.h"

namespace UGC 
{
	
//! \brief ���������ࡣ
class D3DRENDERSYS_API UGD3D9VertexDeclaration : public UGVertexDeclaration
{
public:

	//! \brief ���캯����
	UGD3D9VertexDeclaration();
	
	//! \brief ����������
	virtual ~UGD3D9VertexDeclaration();	

	//! \brief ��ȡ����������
	//! \return ����������
	LPDIRECT3DVERTEXDECLARATION9 GetD3DVertexDeclaration(void);	

protected:

	//! \brief �豸����
	LPDIRECT3DDEVICE9 m_lpD3DDevice;
	//! \brief ����������
	LPDIRECT3DVERTEXDECLARATION9 m_lpD3DDecl;
	//! \brief �Ƿ��ؽ���
	bool m_bNeedsRebuild;
};

}
#endif // !defined(AFX_UGD3D9VERTEXDECLARATION_H__9B969F14_5DC9_458F_B0D8_5A51FE01E507__INCLUDED_)
