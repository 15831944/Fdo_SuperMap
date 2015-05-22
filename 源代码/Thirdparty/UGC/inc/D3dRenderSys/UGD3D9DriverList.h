/* 
	\file UGD3D9DriverList.h
	\brief �豸�б�
	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGD3D9DRIVERLIST_H__063A8C6E_8C1D_4E93_9E84_624E400A723D__INCLUDED_)
#define AFX_UGD3D9DRIVERLIST_H__063A8C6E_8C1D_4E93_9E84_624E400A723D__INCLUDED_

#include "Base/UGList.h"
#include "D3dRenderSys/UGD3D9Driver.h"

namespace UGC
{

//! \brief �豸�б�
class D3DRENDERSYS_API UGD3D9DriverList  
{

private:

	//! \brief �豸�б�
	UGList<UGD3D9Driver> m_DriverList;

	//! \brief D3D����
	LPDIRECT3D9 m_pD3D;

public:
	
	//! \brief ���������캯����
	//! \param pD3D D3D����[in]��
	UGD3D9DriverList( LPDIRECT3D9 pD3D );

	//! \brief ����������
	~UGD3D9DriverList();

	//! \brief �о�������ʾģʽ��
	BOOL Enumerate();

	//! \brief ��ȡ�豸�б����豸������
	//! \return �豸������
	size_t Count() const;

	//! \brief ��ȡ�豸�б����豸��
	//! \param index ������[in]��
	UGD3D9Driver* Item( size_t index );

	//! \brief ��ȡ�豸�б����豸��
	//! \param &name ����[in]��
	UGD3D9Driver* Item( const UGString &name );

};


}
#endif // !defined(AFX_UGD3D9DRIVERLIST_H__063A8C6E_8C1D_4E93_9E84_624E400A723D__INCLUDED_)
