/* 
	\file UGD3D9Texture.h
	\brief D3D��������ࡣ
	\author ������  luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/


#if !defined(AFX_UGD3D9TEXTURE_H__0D158FAF_52C9_4755_BF83_A3473C71015F__INCLUDED_)
#define AFX_UGD3D9TEXTURE_H__0D158FAF_52C9_4755_BF83_A3473C71015F__INCLUDED_

#include "D3dRenderSys/UGD3D9Prerequisites.h"
#include "Scene/UGTexture.h"

namespace UGC
{

//! \brief D3D�����ࡣ
class UGD3D9Texture : public UGTexture
{
	
public:
	
	//! \brief ���캯����
	UGD3D9Texture();	
	//! \brief ���в������캯����
	//! \param strImgPath ����ͼƬ·��[in]��
	//! \param pD3DDevice D3D�豸����[in]��
	//! \param ppTexture ������󼯺�ָ��[in]��
	UGD3D9Texture(const UGString& strImgPath, LPDIRECT3DDEVICE9 pD3DDevice, LPDIRECT3DTEXTURE9* ppTexture);	
	//! \brief ����������
	virtual ~UGD3D9Texture();	


public:
	//! \brief ������
	virtual void BindTexture();

	//! \brief �����������ݡ�
	//! \param bReleaseImgData=TRUE �Ƿ��ͷ�ͼƬ����[in]��
	virtual void LoadTexture(UGbool bReleaseImgData=TRUE) ;
	
	//! \brief ɾ������
	//! \param bReleaseImgData=TRUE [in]��
	virtual void DeleteTexture(UGbool bReleaseImgData=TRUE) ;	

private:

	//! \brief ��������ID��
	//! \return ����ID ��
	UGuint GenTextureID();	

protected:

	//! \brief �豸����
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	//! \brief ��������ָ�롣
	LPDIRECT3DTEXTURE9* m_ppTexture;	
};

}
#endif // !defined(AFX_UGD3D9TEXTURE_H__0D158FAF_52C9_4755_BF83_A3473C71015F__INCLUDED_)
