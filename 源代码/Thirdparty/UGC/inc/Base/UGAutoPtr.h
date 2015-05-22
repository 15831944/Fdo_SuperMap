/*! \file	 UGAutoPtr.h
 *  \brief	 ������ָ��
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGAutoPtr.h,v 1.9 2007/07/10 03:23:47 zengzm Exp $
 */

#if !defined(AFX_UGAUTOPTR_H__8844E5E9_172A_4931_913C_5B1322A01112__INCLUDED_)
#define AFX_UGAUTOPTR_H__8844E5E9_172A_4931_913C_5B1322A01112__INCLUDED_

#include "ugdefs.h"

namespace UGC {

//! \brief ������ָ��
template<typename T>
class UGEXPORT UGAutoPtr
{
private:
	//! \brief ��ֹ�������캯���͸�ֵ����
	UGAutoPtr(const UGAutoPtr& autoPtr);
	void operator=(const UGAutoPtr& autoPtr);

public:
	//! \brief ���캯��
	UGAutoPtr() {
		m_pData = NULL;
		m_bAutoDelete = FALSE;
	}

	//! \brief ��������
	~UGAutoPtr() {
		Release();
	}

public:
	//! \brief ��������ָ��
	//! \remarks ʹ��ʱ�������ʵ����������Ƿ�������ָ��ɾ���ڲ������ָ��
	void SetData(const T* pData, UGbool bAutoDelete) {
		Release(); // ��Releaseһ�£���֧��ѭ��ʹ��
		m_pData = pData;
		m_bAutoDelete = bAutoDelete;
	}
	
	const T* GetData() const
	{
		return m_pData;
	}
	
	//! \brief �Զ�ת������
	//operator const T*() const {
	//	return m_pData;
	//}

	//const T* operator->() {
	//	return m_pData;
	//}

	const T& operator[](UGint nIndex) {
		return m_pData[nIndex];
	}

	void Release(){
		if (m_bAutoDelete) {
			T* pData = (T*)m_pData;
			delete []pData;
		}
		m_pData = NULL;
		m_bAutoDelete = FALSE;
	}
		
private:
	const T* m_pData;
	UGbool m_bAutoDelete;
};

}

#endif 

