/* 
	\file UGD3D9Driver.h
	\brief D3D9�豸���ļ�
	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGD3D9DRIVER_H__96DC3D02_6239_462E_AEF1_C34547D47EBC__INCLUDED_)
#define AFX_UGD3D9DRIVER_H__96DC3D02_6239_462E_AEF1_C34547D47EBC__INCLUDED_

#include "Base/UGString.h"
#include "D3dRenderSys/UGD3D9Prerequisites.h"

namespace UGC
{

class UGD3D9VideoModeList;
class UGD3D9VideoMode;

//! \brief D3D�豸��
class D3DRENDERSYS_API UGD3D9Driver  
{

private:
	
	//! \brief ��������D3D�豸����,D3D�ӿڶ���
	LPDIRECT3D9 m_pD3D;

	//! \brief D3D�豸����
	LPDIRECT3DDEVICE9 m_pD3DDevice;

	//! \brief ��������Ŀ��
	unsigned int m_AdapterNumber;

	//! \brief ���ֲ�ͬ�������ṹ�塣
	D3DADAPTER_IDENTIFIER9 m_AdapterIdentifier;

	//! \brief ������ʾģʽ��
	D3DDISPLAYMODE m_DesktopDisplayMode;

	//! \brief ��Ա�ļ�Ҫ˵����
	//! \remarks ��ע��Ϣ��
	UGD3D9VideoModeList* m_pVideoModeList;

	//! \brief ��Ա�ļ�Ҫ˵����
	//! \remarks ��ע��Ϣ��
	unsigned int tempNo;

	//! \brief ��Ա�ļ�Ҫ˵����
	//! \remarks ��ע��Ϣ��
    static unsigned int driverCount;

public:

	//! \brief ���캯����
	UGD3D9Driver();		// Default


	//! \brief �������캯����
	//! \param &ob ��������[in]��
	UGD3D9Driver( const UGD3D9Driver &ob );	// Copy

	//! \brief ���������캯����
	//! \param pD3D �豸����[in]��
	//! \param adapterNumber ����������[in]��
	//! \param adapterIdentifer ��������Ϣ[in]��
	//! \param desktopDisplayMode ������ʵģʽ[in]��
	UGD3D9Driver( LPDIRECT3D9 pD3D, unsigned int adapterNumber, const D3DADAPTER_IDENTIFIER9& adapterIdentifer, const D3DDISPLAYMODE& desktopDisplayMode );
	
	//! \brief ����������
	~UGD3D9Driver();

	//! \brief ��ȡ�豸���ơ�
	UGString DriverName() const;


	//! \brief ��ȡ�豸������
	UGString DriverDescription() const;

	//! \brief ��ȡD3D����
	//! \return D3D����	
	LPDIRECT3D9 GetD3D() { return m_pD3D; }
	

	//! \brief ��ȡ�豸����
	//! \return �豸����
	LPDIRECT3DDEVICE9 GetD3DDevice() { return m_pD3DDevice; }

	
	//! \brief �����豸����
	//! \param pD3DDevice �豸����[in]��
	void SetD3DDevice(LPDIRECT3DDEVICE9 pD3DDevice) { m_pD3DDevice = pD3DDevice; }


	//! \brief ��ȡ������������
	//! \return ������������
	unsigned int GetAdapterNumber() const { return m_AdapterNumber; }

	//! \brief ��ȡ��������Ϣ��
	//! \return ��������Ϣ��
	const D3DADAPTER_IDENTIFIER9& GetAdapterIdentifier() const { return m_AdapterIdentifier; }


	//! \brief ��ȡ������ʾģʽ��
	//! \return ������ʾģʽ��
	const D3DDISPLAYMODE& GetDesktopMode() const { return m_DesktopDisplayMode; }

	//! \brief ��ȡ��ʾģʽ�б�
	//! \return ��ʾģʽ�б�
	UGD3D9VideoModeList* GetVideoModeList();
	
};

}
#endif // !defined(AFX_UGD3D9DRIVER_H__96DC3D02_6239_462E_AEF1_C34547D47EBC__INCLUDED_)
