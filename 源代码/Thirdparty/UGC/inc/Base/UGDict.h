/* 
	\file UGDict.h
	\brief �ֵ��ࡣ
	\author �ļ�����
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGDICT_H
#define UGDICT_H
#include "ugdefs.h"

namespace UGC {

#define UGLess std::less
#define UGGreater std::greater

//! \brief �ֵ��ࡣ
//! \remarks ������MFC�е�CMap,�ڲ�����stl��mapʵ�֡�
template<typename Key, typename T, class Compare = std::less<Key> >
class  UGEXPORT UGDict 
{
public:
	typedef typename std::map<Key,T,Compare>::const_iterator POSITION;
	
public:
	//! \brief Ĭ�Ϲ��캯����
	UGDict()	
	{

	}

	//! \brief �õ�Ԫ�ظ�����
	//! \return ����Ԫ�ظ�����
	UGint GetCount() const	
	{
		return (UGint)m_dict.size();
	}

	//! \brief �ж��Ƿ�Ϊ�ա�
	//! \return �շ���true;�ǿշ���false��
	UGbool IsEmpty() const	
	{
		return m_dict.empty();
	}

	//! \brief ����һ���ֵ俽����
	//! \param src ���ڿ������ֵ�[in]��
	void Copy(const UGDict<Key,T,Compare>& src)	
	{
		*this=src;
	}

	//! \brief ����ָ��key��valueԪ�ء�
	//! \param key Ҫ���ҵ�key[in]��
	//! \param rValue �õ���Ԫ��[out]��
	//! \return ���ҳɹ�����true;���ɹ�����false��
	UGbool Lookup(const Key& key,T& rValue) const	
	{
		POSITION it=m_dict.find(key);		
		if(it!=m_dict.end())
		{
			rValue = it->second;
			return TRUE;
		}
		return FALSE;
	}

	//! jifang �����08/18/2005.
	//! \brief ͨ��keyֱ�Ӳ��ҵ�Ԫ�ص�ָ�롣
	//! \param key Ҫ���ҵ�keyֵ[in]��
	//! \return �ҵ��򷵻�ָ��UGDict�ڲ���Ԫ�ص�ָ��, ���ǿ���;��û�鵽, �򷵻ؿ�ָ�롣
	const T* Lookup(const Key &key) const	
	{
		POSITION it=m_dict.find(key);		
		if(it!=m_dict.end())
		{
			return (const T*)(&it->second);
		}
		return NULL;
	}	

	//! \brief ��ָ����key����ָ����Ԫ�ء�
	//! \param key ָ���ļ�ֵ[in]��
	//! \param newValue ָ����Ԫ��[in]��
	void SetAt(const Key& key,const T& newValue)	
	{
		operator[](key)=newValue;
	}

	//! \brief ͨ��ָ����key�õ���ӦԪ�ص����á�
	//! \param key ָ����keyֵ[in]��
	//! \return ���ض�ӦԪ�ص����á�
	const T& operator[](const Key& key) const	
	{
		return m_dict.operator [](key);
	}

	//! \brief ͨ��ָ����key�õ���ӦԪ�ص����á�
	//! \param key ָ����keyֵ[in]��
	//! \return ���ض�ӦԪ�ص����á�
	T& operator[](const Key& key) 
	{
		return m_dict.operator [](key);
	}

	//! \brief �Ƴ�keyֵ��Ӧ��Ԫ�ء�
	//! \param key Ҫ�Ƴ���keyֵ[in]��
	//! \return �ɹ�����true;ʧ�ܷ���false��
	UGbool RemoveKey(const Key& key)	
	{
		return m_dict.erase(key)>0;
	}

	//! \brief �Ƴ�����Ԫ��
	void RemoveAll()
	{
		m_dict.clear();
	}

	//! \brief �õ���ʼλ�á�
	//! \return ���ؿ�ʼλ�á�
	//! \remarks �õ���ʼλ�ú�,��ͨ��GetNextAssoc�����Ϳ���һ������һ���õ��ֵ������е�Ԫ��
	//! \attention ע��ʹ��IsEOF�����жϲ�Ҫ�����ֵ�ķ�Χ
	POSITION GetStartPosition() const	
	{
		return m_dict.begin();
	}

	//! \brief �жϴ����λ���Ƿ����ֵ�β��
	//! \param pos Ҫ�жϵ�λ��[in]��
	//! \return ����ѵ��ֵ�β�򷢻�true;���򷵻�false��
	UGbool IsEOF(POSITION pos) const	
	{
		return pos==m_dict.end();
	}

	//! \brief �õ�ָ��pos��key��Ԫ��,����pos�ƶ�����һ��λ��
	//! \param rNextPosition ָ����λ��[in]��
	//! \param rKey �õ���key[out]��
	//! \param rValue �õ���Ԫ��[out]��
	void GetNextAssoc(POSITION& rNextPosition,Key& rKey,T& rValue) const	
	{
		UGASSERT(!IsEOF(rNextPosition));		
		rKey = rNextPosition->first;
		rValue = rNextPosition->second;
		++rNextPosition;
	}

private:
	std::map<Key,T,Compare> m_dict;
};

}

#endif


