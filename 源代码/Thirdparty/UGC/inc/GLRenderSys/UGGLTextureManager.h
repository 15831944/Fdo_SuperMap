/* 
	\file UGGLTextureManager.h
	\brief ��������ࡣ
	\author zhangyl luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGGLTEXTUREMANAGER_H__7B82CFE2_B69C_4BF4_A8E9_79E44C2A0041__INCLUDED_)
#define AFX_UGGLTEXTUREMANAGER_H__7B82CFE2_B69C_4BF4_A8E9_79E44C2A0041__INCLUDED_

#include "GLRenderSys/UGGLPrerequisites.h"
#include "Scene/UGTextureManager.h"

namespace UGC
{

//! \brief ��������ࡣ
class GLRENDERSYS_API UGGLTextureManager : public UGTextureManager 
{
public:

	//! \brief ���������캯����
	//! \param *pGLSupport GLSupportָ��[in]��
	UGGLTextureManager(UGGLSupport *pGLSupport);	
	
	//! \brief ����������
	virtual ~UGGLTextureManager();	

public:

	//! \brief ��ȡ�������
	//! \param strTextureName ����[in]��
	//! \return �������ָ�롣
	virtual UGTexture* GetTexture(const UGString& strTextureName);	
	
	//! \brief ɾ����������
	virtual void DeleteUnusedTextures();	

private:

	//! \brief GL֧�ֶ���ָ�롣
	UGGLSupport *m_pGLSupport;

};

}
#endif // !defined(AFX_UGGLTEXTUREMANAGER_H__7B82CFE2_B69C_4BF4_A8E9_79E44C2A0041__INCLUDED_)
