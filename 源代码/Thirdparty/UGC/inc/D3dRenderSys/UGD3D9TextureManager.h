/* 
	\file UGD3D9TextureManager.h
	\brief D3D��������ࡣ
	\author zhangyl luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGD3D9TEXTUREMANAGER_H__B57DCB1F_DB41_4255_BF5F_0C3751BF2801__INCLUDED_)
#define AFX_UGD3D9TEXTUREMANAGER_H__B57DCB1F_DB41_4255_BF5F_0C3751BF2801__INCLUDED_

#include "D3dRenderSys/UGD3D9Prerequisites.h"
#include "Scene/UGTextureManager.h"

namespace UGC
{

//! \brief �����������ࡣ
class D3DRENDERSYS_API UGD3D9TextureManager : public UGTextureManager
{

public:
	
	//! \brief ���캯����
	UGD3D9TextureManager();	
	
	//! \brief ���������캯����
	//! \param m_pD3DDevice �豸����[in]��
	//! \param pppTexture ����������ָ��[in]��
	UGD3D9TextureManager(LPDIRECT3DDEVICE9 m_pD3DDevice, LPDIRECT3DTEXTURE9* pppTexture);	
	
	//! \brief ����������
	virtual ~UGD3D9TextureManager();	

public:

	//! \brief ��ȡ�������
	//! \param strTextureName �����������[in]��
	virtual UGTexture* GetTexture(const UGString& strTextureName);	
	
	//! \brief ɾ����������
	virtual void DeleteUnusedTextures();	

protected:
	
	//! \brief �豸����
	LPDIRECT3DDEVICE9 m_pD3DDevice;

	//! \brief ���������׵�ַ��
	LPDIRECT3DTEXTURE9* m_ppTexture;	
	
};

}
#endif // !defined(AFX_UGD3D9TEXTUREMANAGER_H__B57DCB1F_DB41_4255_BF5F_0C3751BF2801__INCLUDED_)
