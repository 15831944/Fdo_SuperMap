/* 
	\file UGRenderableObjectList.h
	\brief ����Ⱦ�����б����ļ�
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGRENDERABLEOBJECTLIST_H__260EEE73_E53A_4651_9778_2B09D6187D01__INCLUDED_)
#define AFX_UGRENDERABLEOBJECTLIST_H__260EEE73_E53A_4651_9778_2B09D6187D01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Base/UGThread.h"
#include "Scene/UGRenderable.h"

namespace UGC 
{

//! \brief ����Ⱦ�����б���������࣬����ͬ����������
//! \remarks ��ע��Ϣ��
class SCENE_API  SyncRenderObjectArray
{
public:
	//! \brief ���캯��
	SyncRenderObjectArray(){};
	//! \brief ��������
	virtual ~SyncRenderObjectArray(){};
	//! \brief ����
	void   Lock(){m_mutex.lock();};
	//! \brief ����
	void   Unlock(){m_mutex.unlock();};
public:
	//! \brief ��������Ա
	UGMutex m_mutex;
	//! \brief �����Ա
	UGArray<UGRenderable*> m_Array;

	
};
//! \brief ����Ⱦ�����б���������࣬�����첽��������
class SCENE_API UGRenderableObjectList : public UGRenderable
{
public:
	//! \brief ���캯��
	UGRenderableObjectList();
	//! \brief ��������
	virtual ~UGRenderableObjectList();
	//! \brief ��ʼ��
	virtual void Initialize();
	//! \brief ���º������ڸ����߳��е���
	virtual void Update();
	//! \brief ��Ⱦ����������Ⱦ�߳��е���
	virtual void Render();
	//! \brief �ͷ�����
	virtual void Release();
	//! \brief ���һ����Ⱦ����
	void Add(UGRenderable *ro);
	//! \brief �Ƴ�������Ⱦ����
	void RemoveAll();
	//! \brief ���ö����Ƿ�ɼ�
	void SetLayerHide(UGString strName, UGbool bHide);
	//! \brief �ж϶����Ƿ�ɼ�
	UGbool IsLayerHide(UGString strName);
	//! \brief ���ݱ�־���ƻ�ȡ����Ⱦ����
	UGRenderable* GetRenderObject(const UGString& strName);
	//! \brief �������
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);

private:
	//! \brief �������п���Ⱦ�����ͬ�������Ա
	SyncRenderObjectArray m_Children;

};
}
#endif // !defined(AFX_UGRENDERABLEOBJECTLIST_H__260EEE73_E53A_4651_9778_2B09D6187D01__INCLUDED_)
