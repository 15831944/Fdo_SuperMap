/* 
	\file UGGLTexture.h
	\brief GL�����ࡣ
	\author zhangyl luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGGLTEXTURE_H__39CECD8E_D6E2_4170_9BB7_836B7F219212__INCLUDED_)
#define AFX_UGGLTEXTURE_H__39CECD8E_D6E2_4170_9BB7_836B7F219212__INCLUDED_

#include "GLRenderSys/UGGLPrerequisites.h"
#include "Scene/UGTexture.h"

namespace UGC
{

//! \brief GL�����ࡣ
class GLRENDERSYS_API UGGLTexture : public UGTexture
{
public:

	//! \brief ���캯����
	UGGLTexture();	
	
	//! \brief ���������캯����
	//! \param strImgPath ·��[in]��
	//! \param *pGLSupport GL֧�ֶ���ָ��[in]��
	UGGLTexture(const UGString& strImgPath, UGGLSupport *pGLSupport);	
	
	//! \brief ����������
	virtual ~UGGLTexture();	

public:

	//! \brief ������
	virtual void BindTexture();	
	
	//! \brief ��������
	//! \param bReleaseImgData ȱʡΪTRUE���ͷ�ͼ������[in]��
	virtual void LoadTexture(UGbool bReleaseImgData=TRUE) ;	
	
	//! \brief ɾ������
	//! \param bReleaseImgData ȱʡΪTRUE���ͷ�ͼ������[in]��
	virtual void DeleteTexture(UGbool bReleaseImgData=TRUE) ;	

private:
	
	//! \brief GLSupportָ�롣
	UGGLSupport *m_pGLSupport;

};

}
#endif // !defined(AFX_UGGLTEXTURE_H__39CECD8E_D6E2_4170_9BB7_836B7F219212__INCLUDED_)
