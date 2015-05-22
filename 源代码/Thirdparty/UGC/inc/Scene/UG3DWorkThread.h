/**  \file UG3DWorkThread.h
   \brief   �����߳�
   \auothor malq
   \attetion ��ģ�Ͳ��ö��̼߳���,���߳�������Ⱦ����
             �����߳������޸ļ�ʱ���¶������
   Copyright(c) 1996-2007 SuperMap GIS Technolgoies, Inc<br>
   All Rights Reserved
   \version 2.0
   <b>����˵����</b>\n
	<em>1����һ��˵����\n
	<em>2���ڶ���˵����\n
*/
#if !defined(AFX_UG3DWORKTHREAD_H__A06B2C3A_96B8_42C0_9095_B708C208B766__INCLUDED_)
#define AFX_UG3DWORKTHREAD_H__A06B2C3A_96B8_42C0_9095_B708C208B766__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Base/UGThread.h"

namespace UGC 
{

//! \brief 3D�����߳�
/**
  UG3DWorkThread �����ڻ���UGThread
  ��Ҫ���ڼ�ʱ������Ⱦ�������
*/
class SCENE_API UG3DWorkThread : public UGThread
{

public:

	//! \brief ���캯��
	/**
	  \param *pScene    ��������ָ��
	  \param *pDrawArgs ��Ⱦ����
	*/
	UG3DWorkThread(UGRoot *pRoot);
	
	//! \brief ��������
	virtual ~UG3DWorkThread();

protected:
	
	//! \brief ��д����run����
	/**
	  ��Ҫ����UGScene��DrawArgs����
	  ��Ҫ���ڼ�ʱ������Ƭ�зֵ�ʵʱ�仯
	*/
	UGint run();
	
	UGRoot *m_pRoot;

};

}

#endif // !defined(AFX_UG3DWORKTHREAD_H__A06B2C3A_96B8_42C0_9095_B708C208B766__INCLUDED_)
