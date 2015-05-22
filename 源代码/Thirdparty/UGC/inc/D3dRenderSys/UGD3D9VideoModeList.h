/* 
	\file UGD3D9VideoModeList.h
	\brief ��Ƶģʽ�б��ࡣ
	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGD3D9VIDEOMODELIST_H__CDB38CE1_1C84_4D11_A346_202B293B7632__INCLUDED_)
#define AFX_UGD3D9VIDEOMODELIST_H__CDB38CE1_1C84_4D11_A346_202B293B7632__INCLUDED_

#include "Base/UGList.h"
#include "D3dRenderSys/UGD3D9Driver.h"
#include "D3dRenderSys/UGD3D9VideoMode.h"

namespace UGC
{
	
//! \brief ��Ƶģʽ�б��ࡣ
class D3DRENDERSYS_API UGD3D9VideoModeList  
{
private:

	//! \brief �豸����
	UGD3D9Driver* m_pDriver;

	//! \brief ��Ƶģʽ�б�
	UGList<UGD3D9VideoMode> m_ModeList;

public:
	
	//! \brief ���������캯����
	//! \param pDriver �豸����[in]��
	UGD3D9VideoModeList( UGD3D9Driver* pDriver );	
	
	//! \brief ����������
	~UGD3D9VideoModeList();	

	//! \brief ö��������Ƶģʽ��
	BOOL Enumerate();	

	//! \brief ��ȡ��Ƶģʽ��
	//! \param index ��Ƶģʽ����[in]��
	//! \return ��Ƶģʽ��
	UGD3D9VideoMode* Item( size_t index );	
	
	//! \brief ��ȡ�б�������
	size_t Count();	

	//! \brief ��ȡ��Ƶģʽ��
	//! \param &name ����[in]��
	//! \return ��Ƶģʽ��
	UGD3D9VideoMode* Item( const UGString &name );	

};

}
#endif // !defined(AFX_UGD3D9VIDEOMODELIST_H__CDB38CE1_1C84_4D11_A346_202B293B7632__INCLUDED_)
