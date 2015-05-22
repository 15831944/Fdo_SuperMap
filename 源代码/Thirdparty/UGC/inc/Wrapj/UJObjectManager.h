// UJObjectManager.h: interface for the UJObjectManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UJOBJECTMANAGER_H__890A573A_5B5E_4F98_B96A_F0E2FD96C91E__INCLUDED_)
#define AFX_UJOBJECTMANAGER_H__890A573A_5B5E_4F98_B96A_F0E2FD96C91E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Wrapj/SuperMapStubH.h"
#include "Base/UGLogFile.h"


// Wrapper class for ugc class that can be create
class CCreatableObject 
{
public:
	virtual UGlong CreateObject();
	virtual void DeleteObject(UGlong hInstacePtr);
};



// template class act as single entry for construct ugc class 
template<class T>
class CTemplateObject : public CCreatableObject
{
public:
//	CTemplateObject();

	UGlong CreateObject();
	void DeleteObject(UGlong hInstacePtr);

};


template <class T>
UGlong CTemplateObject<T>::CreateObject()
{
	return (UGlong) new T();
}

template <class T>
void CTemplateObject<T>::DeleteObject(UGlong hInstacePtr)
{
	T* pT = (T*)hInstacePtr;
	if (pT!=NULL) {
		delete pT;
		//pT = NULL;
	}
	
	
}

// ȫ�ֽ�һ���������ڴ�����
class UJObjectManager  
{
public:
	UJObjectManager();
	virtual ~UJObjectManager();
public:
	void ReleaseAll();
	UGlong CreateObject(UGlong classID);	
	
	UGbool RegisterObject(UGlong hInstance, UGlong classID);

	UGbool RegisterObject(UGlong hInstance, UGString className);

	
	UGbool RegisterGeometryObject(UGGeometry* pGeo);

	UGint DeleteObject(UGlong hInstance, UGlong classID);

	UGint RemoveObjectFromMap(UGlong hInstacePtr, UGlong classID);
	//��delete��һ���ĵ��ǣ�����ӿ�ֻ�Ǵ�map���Ƴ���Ӧ�ļ�¼������ɾ��ָ�룬Ҳ����˵
	//��ĳ������£�new�����Ķ�����Ҫɾ����ʱ�򣬵�������ӿڣ���ô�Ժ���������
	//���ᱻɾ������������ӿ�һ��Ҫȷ�����������Ĳ��������ͷ��ˣ�add by xll

private:
	UGDict<UGlong, UGlong> m_ObjectHeap;	
	// keyΪCreateObject�����Ķ���valueΪCreateObjectʹ�õ�CTemplateObject����
	UGbool m_bDeleteObject;
	UGbool m_bCreateObject;
	//��������������Ҫ������߳���ͬʱnew����java�������ͬʱ���ͷŶ����ʱ����map������Ƴ�keyֵ��ʱ��
	//��ͻ�����⣬һ��Ҫ������������ܶ�����  add by xll 06.3.9


};

UGlong GetIndexFromGeometryType(UGGeometry::Type geoType);
UGlong GetIndexFromClassName(UGString strClassName);
UJObjectManager * GetObjectManager();

#endif // !defined(AFX_UJOBJECTMANAGER_H__890A573A_5B5E_4F98_B96A_F0E2FD96C91E__INCLUDED_)
