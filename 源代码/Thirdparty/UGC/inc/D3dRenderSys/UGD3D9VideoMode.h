/* 
	\file UGD3D9VideoMode.h
	\brief ��Ƶģʽ�ࡣ
	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGD3D9VIDEOMODE_H__262179DF_885A_49BE_92A2_B8D8C42E0FAE__INCLUDED_)
#define AFX_UGD3D9VIDEOMODE_H__262179DF_885A_49BE_92A2_B8D8C42E0FAE__INCLUDED_

#include "D3dRenderSys/UGD3D9Prerequisites.h"

namespace UGC
{

static unsigned int g_nModeCount = 0;

//! \brief ��Ƶģʽ�ࡣ
class D3DRENDERSYS_API UGD3D9VideoMode  
{

private:

	//! \brief ��ʾģʽ��
	D3DDISPLAYMODE m_DisplayMode;
	
	//! \brief ģʽ��Ŀ��
	unsigned int m_nModeNumber;

public:

	//! \brief ���캯����
	UGD3D9VideoMode() { m_nModeNumber = ++g_nModeCount; ZeroMemory( &m_DisplayMode, sizeof(D3DDISPLAYMODE) ); }
	
	//! \brief �������캯����
	UGD3D9VideoMode( const UGD3D9VideoMode &ob ) { m_nModeNumber = ++g_nModeCount; m_DisplayMode = ob.m_DisplayMode; }
	
	//! \brief ���������캯����
	//! \param d3ddm ��ʾģʽ[in]��
	UGD3D9VideoMode( D3DDISPLAYMODE d3ddm ) { m_nModeNumber = ++g_nModeCount; m_DisplayMode = d3ddm; }	
	
	//! \brief ����������
	~UGD3D9VideoMode()
	{
		g_nModeCount--;
	}
	
	//! \brief ��ȡ��ʾģʽ��
	//! \return ��
	unsigned int GetWidth() const { return m_DisplayMode.Width; }	
	
	//! \brief ��ȡ��ʾ�߶ȡ�
	//! \return �ߡ�
	unsigned int GetHeight() const { return m_DisplayMode.Height; }	
		
	//! \brief ��ȡ��ʽ��
	//! \return ��ʽ��
	D3DFORMAT GetFormat() const { return m_DisplayMode.Format; }	
	
	//! \brief ��ȡˢ��Ƶ�ʡ�
	//! \return ˢ��Ƶ�ʡ�
	unsigned int GetRefreshRate() const { return m_DisplayMode.RefreshRate; }	
	
	//! \brief ��ȡ��ɫ��ȡ�
	//! \return ��ɫ��ȡ�
	unsigned int GetColourDepth() const;	
	
	
	//! \brief ��ȡ��ʾģʽ��
	//! \return ��ʾģʽ��
	D3DDISPLAYMODE GetDisplayMode() const { return m_DisplayMode; }	
	
	//! \brief ����ˢ��Ƶ�ʡ�
	//! \param rr ��ֵ[in]��
	void IncreaseRefreshRate(unsigned int rr) { m_DisplayMode.RefreshRate = rr; } 	
		
	//! \brief ��ȡ������
	//! \return ������
	UGString GetDescription() const;	

};

}
#endif // !defined(AFX_UGD3D9VIDEOMODE_H__262179DF_885A_49BE_92A2_B8D8C42E0FAE__INCLUDED_)
