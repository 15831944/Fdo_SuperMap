// UGTexture.h: interface for the UGTexture class.
// by-malq
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTEXTURE_H__7BE6E4FE_7CC0_49A7_8592_672F01686416__INCLUDED_)
#define AFX_UGTEXTURE_H__7BE6E4FE_7CC0_49A7_8592_672F01686416__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"

namespace UGC
{
class SCENE_API UGTexture  
{
	class SCENE_API UGTextureData
	{
	public:
		UGTextureData()
		{
			m_pBuffer=NULL;
			m_nWidth=0;
			m_nHeight=0;
			m_enFormat=PF_UNKNOWN;
		}
		virtual ~UGTextureData()
		{
			 Release();
		}
		void Release()
		{
			if (m_pBuffer!=NULL) 
			{
				delete []m_pBuffer;
				m_pBuffer=NULL;
				m_nWidth=0;
				m_nHeight=0;
				m_enFormat=PF_UNKNOWN;
			}
		}
	public:
		UGuchar* m_pBuffer;
		UGuint m_nHeight;
		UGuint m_nWidth;
		UG3DPixelFormat m_enFormat;

	};
public:
	UGTexture();
	UGTexture(const UGString& strImgPath);
	virtual ~UGTexture();

	//! \brief �������ID��һ��ʹ��ʱ����һ������������Ѵ�����������������������״̬��
	//! \param nTextureID �������ID[in]��
	//! \remarks D3D��GL��ʵ�֡�		
	virtual void BindTexture()  = 0;
	//! \brief ɾ������
	//! \param nTextureID �������ID[in]��
	//! \remarks D3D��GLʵ�ְ汾��һ�£�GLΪ��EndFrame�в�ɾ������D3Dֱ��ɾ������
	//! \attention ����ȷ��һ�¸ú������ܡ�
	virtual void DeleteTexture(UGbool bReleaseImgData=TRUE) = 0;
	//! \brief �����������ݡ�
	//! \param TextrueData �������ݶ���[in]��
	//! \return �������ID��
	virtual void LoadTexture(UGbool bReleaseImgData=TRUE) = 0;

	//	 Ŀǰ��֧��2ά��������ͼ���ʽͳһ��RGBA	
	UGbool IsLoaded();
	UGbool LoadImageData(const UGString& strFilePath);
	UGbool LoadImageData();

	virtual void ReleaseImgData();


	UGuint GetLoadType(const UGString& strExt);
	UG3DPixelFormat IlFormat2ScnFormat( UGint ImageFormat,  UGint BytesPerPixel );
	UG3DPixelFormat ImgFormat2ScnFormat(PixelFormat pf);
	PixelFormat ScnFomat2ImgFormat(UG3DPixelFormat pf);
	void SetTextureData(UGint nWidth,UGint nHeight,UGuchar* pData);
	void FlipTexture();
	UGuint GetBindID();
	// �������ü���
	void AddRef();
	// ��С���ü���
	void DecRef();
	// �õ����ü���
	UGint GetRef(); 
	// malq-2007-9-6-��ʱ��ӣ�ֻ��Ϊ��ȥ�����ݵ���Ч�İ�ɫ���ز���
	void TransparentInvalid();
	//! \brief ��ȡ�����Ƿ����ظ�ģʽ��
	//! \return TRUEΪ�ǣ�FALSEΪ��
	UGbool IsTextureRepeatMode();
	//! \brief ��������ģʽΪ�ظ�ģʽ��
	//! \param bRepeat TRUEΪ�����ظ�ģʽ��FALSEΪ���ظ�ģʽ[in]��
	void   SetTextureRepeatMode(UGbool bRepeat);
	
public:
	UGString m_strTexFilePath;

protected:
	void RescaleNPower2();
	void ScaleImage(UGint nNewWidth,UGint nNewHeight);
	UGTextureData m_TextureData;
	UGuint m_nBindID;
	UGbool m_bLoadedImg;
	UGint m_nRefAdd;//���ü���

	//! \brief ��־�����Ƿ����ظ���ͼģʽ��
	//! \remarks TRUEΪ�ǣ�FALSEΪ���ǡ�
	UGbool  m_bTextureRepeatMode;
};
/*

*/



/*
UGDict<UGString,UGTexture*> g_TextureManager;
UGDict<UGString,UGMaterial*>g_MaterialManager;
UGMaterial* FindMaterial(const UGString& strName)
{
	UGDict<UGString,UGMaterial*>::POSITION pos=g_MaterialManager.GetStartPosition();
	UGMaterial* pMaterial=NULL;
	while(!g_MaterialManager.IsEOF(pos))
	{
		UGString key;
		UGMaterial* pTemp=NULL;
		g_MaterialManager.GetNextAssoc(pos,key,pTemp);
		if (pTemp!=NULL && pTemp->m_strName.Compare(strName)==0) 
		{
			pMaterial=pTemp;
			break;
		}
	}
	return pMaterial;
}
UGMaterial* FindTexture(const UGString& strName)
{
	UGDict<UGString,UGTexture*>::POSITION pos=g_TextureManager.GetStartPosition();
	UGTexture* pTexture=NULL;
	while(!g_TextureManager.IsEOF(pos))
	{
		UGString key;
		UGTexture* pTemp=NULL;
		g_TextureManager.GetNextAssoc(pos,key,pTemp);
		if (pTemp!=NULL && pTemp->m_strName.Compare(strName)==0) 
		{
			pTexture=pTemp;
			break;
		}
	}
	return pTexture;
}
*/

}
#endif // !defined(AFX_UGTEXTURE_H__7BE6E4FE_7CC0_49A7_8592_672F01686416__INCLUDED_)
