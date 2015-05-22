/*! \file	 UGArray.h
*	\brief	 ������
*	\author	 ��ͬ��
*	\attention 
*	Copyright(c) 1996-2005 SuperMap GIS Technologies, Inc.<br>
*	All Rights Reserved
*	\version ��־��  2005-5-8 ����Capacity�Ĵ���;
						RemoveAll�������������ʣ��ռ�;
						������Ӧע��;
*/

#ifndef UGARRAY_H
#define UGARRAY_H
#include "ugdefs.h"

namespace UGC {

//! \brief ������
//! \remarks �ڲ�����STL��vectoryʵ��
template<typename T>
class UGEXPORT UGArray
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGArray() { }	

	//! \brief Ԥ��������nSize��Ԫ��(ÿ��Ԫ��ΪĬ�Ϲ���)
	//! \param nSize Ԥ���Ԫ�ظ���, ������ڵ���0
	//! \remarks explicit�����������εĴ�����ת��Ϊ��������
	explicit UGArray(UGint nSize) 
	{
		UGASSERT(nSize>=0);
		m_array.resize(nSize);
	}

	//! \brief Ԥ��������nSize��Ԫ��(Ĭ�Ϲ���), Ĭ��ֵΪelem
	//! \param nSize Ԥ���Ԫ�ظ���, ������ڵ���0
	//! \param elem Ԥ��Ԫ�ص�Ĭ��ֵ
	UGArray(UGint nSize, const T& elem)
	{
		UGASSERT(nSize>=0);
		m_array.resize(nSize,elem);
	}

public:
	//! \brief �õ�ĿǰUGArray�����пռ�(�����Ѿ�ʹ�õĺͱ�����)�������ɵ�Ԫ�صĸ���
	//! \return �����������пռ�����ɵ�Ԫ�ظ���
	UGint GetCapacity() const
	{
		return m_array.capacity();
	}

	//! \brief ȷ��UGArray���㹻���ڴ�ռ�洢 ָ����Ԫ�ظ���
	//! \param nCapacity ָ�������ɵ�Ԫ�ظ���,������ڵ���0
	//! \remarks ���ԭ�пռ䲻��, �ڴ�ռ������, �����ӵĿռ䲻�����TYPE�Ĺ��캯��
	//! ���ԭ�пռ��ָ���Ĵ�, Ҳ�����ͷſռ�
	void SetCapacity(UGint nCapacity)
	{
		UGASSERT(nCapacity >= 0);
		m_array.reserve(nCapacity);
	}

	//! \brief ���������һ��Ԫ��
	//! \param newElement ���ӵ�Ԫ��
	//! \return �������Ԫ�ص�����
	UGint Add(const T& newElement)
	{
		m_array.push_back(newElement);
		return (UGint)m_array.size()-1;
	}

	//! \brief �������������ָ��������Ԫ��
	//! \param pData Ҫ���ӵ�Ԫ��ָ��
	//! \param nSize Ҫ���ӵ�Ԫ�ظ���
	//! \return ���ؼ���Ԫ�ص���ʼ����
	UGint Append(const T* pData, UGint nSize)
	{
		UGint nOldSize=(UGint)m_array.size();
		m_array.insert(m_array.end(),pData,pData+nSize);
		return nOldSize;
	}

	//! \brief �������������һ������
	//! \brief src Ҫ���ӵ�����
	//! \return ���ؼ����������ʼ����
	UGint Append(const UGArray<T>& src)
	{
		UGint nOldSize=(UGint)m_array.size();
		m_array.insert(m_array.end(),src.m_array.begin(),src.m_array.end());
		return nOldSize;
	}

	//! \brief ���鿽��,ԭ�������ݱ�����
	//! \param src ���������
	void Copy(const UGArray<T>& src)
	{
		*this=src;
	}

	//! \brief �õ������ڲ�ָ��(��ַ����)
	//! \return ���������ڲ�ָ��(��ַ����)
	const T* GetData() const
	{
		// modified by zengzm 2005.7.28 
		// dotnet �е�stl vector, ���Ϊ��, �����(*begin())�ᵼ�³������
		// �ʶ�����һ���ж�
		//return &(*begin());
		if (GetSize() > 0)
		{
			return &(*m_array.begin());
		}
		else 
		{
			return NULL;
		}
	}

	//! \brief �õ������ڲ�ָ��(��ַ����)
	//! \return ���������ڲ�ָ��(��ַ����)
	T* GetData()
	{
		// modified by zengzm 2005.7.28 
		// dotnet �е�stl vector, ���Ϊ��, �����(*begin())�ᵼ�³������
		// �ʶ�����һ���ж�
		//return &(*begin());
		if (GetSize() > 0)
		{
			return &(*m_array.begin());
		}
		else 
		{
			return NULL;
		}
	}

	//! \brief �õ����õ�Ԫ�صĸ��� ��һ, ���±�ֵ ����ȡ�����ֵ; 
	//! \return �����������±�ֵ
	//! \attention ע��: ��� ����Ϊ��, �� ���� -1
	UGint GetUpperBound() const
	{
		return (UGint)m_array.size()-1;
	}
		
	//! \brief �õ����õ�Ԫ�صĸ���
	UGint GetSize() const
	{
		return (UGint)m_array.size();
	}

	//! \brief �ͷŶ�����ڴ�ռ�
	//! \remarks ��size֮��capacity�Ŀռ�ᱻ�ͷ�
	//! \attention �ڲ����ÿ�������һ����ͬ������,Ȼ�󽻻��ķ�ʽʵ�ֵ�,
	//! ��˻��ƻ�֮ǰ���ڴ�, ����֮ǰGetData��ָ���Ϊ�Ƿ�, �ʶ����Ƽ�ʹ��.
	void FreeExtra()
	{
		if(m_array.capacity()>m_array.size()) {
			std::vector<T> vctTemp(m_array.begin(),m_array.end());
			m_array.swap(vctTemp);
		}
	}

	//! \brief �õ�ָ��λ��Ԫ�ص�����
	//! \param nIndex ָ����λ��
	//! \return ���ظ�λ��Ԫ�ص�����
	T& ElementAt(UGint nIndex)
	{
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		return m_array.at(nIndex);
	}

	//! \brief �õ�ָ��λ��Ԫ�ص�const����
	//! \param nIndex ָ����λ��
	//! \return ���ظ�λ��Ԫ�ص�const����
	const T& ElementAt(UGint nIndex) const
	{
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		return m_array.at(nIndex);
	}

	//! \brief �õ�ָ��λ��Ԫ�ص�����
	//! \param nIndex ָ����λ��
	//! \return ���ظ�λ��Ԫ�ص�����
	T& operator[](UGint nIndex)
	{
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		return m_array.at(nIndex);
	}

	//! \brief �õ�ָ��λ��Ԫ�ص�const����
	//! \param nIndex ָ����λ��
	//! \return ���ظ�λ��Ԫ�ص�const����
	const T& operator[](UGint nIndex) const
	{
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		return m_array.at(nIndex);
	}
	
	//! \brief �õ�ָ��λ��Ԫ�صĿ���
	//! \param nIndex ָ����λ��
	//! \return ���ظ�λ��Ԫ�صĿ���
	T GetAt(UGint nIndex) const
	{				
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		return m_array.at(nIndex);
	}
	
	//! \brief ��ָ��λ������Ԫ��(�滻ԭ��Ԫ��)
	//! \remarks ָ��λ�ñ���������size��Χ֮��
	//! \param nIndex ָ����λ�� 
	//! \param newElement Ҫ���õ�Ԫ��
	void SetAt(UGint nIndex, const T& newElement)
	{			
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		m_array.at(nIndex) = newElement;
	}
	
	//! \brief ��ָ��λ������Ԫ��(�滻ԭ��Ԫ��)
	//! \remarks ���ָ��λ�ô�������size,������Զ�����
	//! \param nIndex ָ����λ�� 
	//! \param newElement Ҫ���õ�Ԫ��
	void SetAtGrow(UGint nIndex,const T& newElement)
	{
		UGASSERT(nIndex >= 0);		
		if(nIndex>=(UGint)m_array.size())
		{
			m_array.resize(nIndex+1);
		}
		m_array.at(nIndex) = newElement;
	}
	
	//! \brief ����UGArray���ڴ�ռ�Ϊ nNewSize, 
	//! \remarks ���ԭ�пռ䲻��, �ڴ�ռ������, 
	//! ���ӵĿռ�����TYPE��Ĭ�Ϲ��캯��(�����newElement)
	//! ���ԭ�пռ��ָ���Ĵ�, �����ͷſռ�,�� ��ָ���Ŀռ�֮���Ԫ�ؾ���Ч��
	//! ���Ҫǿ���ͷ��ڴ�,�����FreeExtra(),�ͷŶ�����ڴ�ռ�,
	//! \param nNewSize ָ�����µ�Ԫ�ظ���
	void SetSize(UGint nNewSize)
	{
		UGASSERT(nNewSize>=0);		
		m_array.resize(nNewSize);
	}	
	
	//! \brief �Ƴ�����Ԫ��,ͬʱ������пռ�
	void RemoveAll()
	{
		m_array.clear(); 		
		FreeExtra();
	}

	//! \brief �Ƴ�ָ��λ��,ָ��������Ԫ��
	//! \remarks ָ��λ�ñ��������鷶Χ��
	//! \param nIndex Ҫ�Ƴ���Ԫ��λ��
	//! \param nCount Ҫ�Ƴ���Ԫ�ظ���,Ĭ��Ϊ1
	//! \return �����Ƴ���Ԫ�ظ���
	UGint RemoveAt(UGint nIndex,UGint nCount=1)
	{
		UGASSERT(nIndex>=0);
		nCount = UGMAX(nCount,0);
		if(nCount == 0)
		{
			return 0;
		}

		UGint nSize=(UGint)m_array.size();
		if(nIndex >= nSize)
		{
			return 0;
		}

		// modified by zengzm 2005-9-12 �����ж�,��ֹnCount<0
		UGint nEnd=nIndex+nCount;
		if(nEnd>nSize)
		{
			nEnd=nSize;
		}
		m_array.erase(m_array.begin()+nIndex,m_array.begin()+nEnd);
		return nEnd - nIndex;
	}
	
	//! \brief ��ָ��λ��֮ǰ,����ָ��������Ԫ��
	//! \remarks ���ָ��λ�ò������鷶Χ��,���Զ�������[0,size]
	//! \param nIndex ָ����λ��
	//! \param newElement ָ����Ԫ��
	//! \param nCount Ҫ�����Ԫ�ظ���,Ĭ��Ϊ1
	void InsertAt(UGint nIndex,const T& newElement,UGint nCount=1)
	{				
		UGint nSize=(UGint)m_array.size();
		nIndex=UGCLAMP(0,nIndex,nSize);
		if(nCount>0) 
		{
			m_array.insert(m_array.begin()+nIndex,nCount,newElement);
		}				
	}

	//! \brief ��ָ��λ��֮ǰ,����ָ��������Ԫ��
	//! \remarks ���ָ��λ�ò������鷶Χ��,���Զ�������[0,size]
	//! \param nIndex ָ����λ��
	//! \param pNewElement ָ����Ԫ��ָ��
	//! \param nCount Ҫ�����Ԫ�ظ���
	void InsertAt(UGint nIndex,const T* pNewElement,UGint nCount)
	{				
		UGint nSize=(UGint)m_array.size();
		nIndex=UGCLAMP(0,nIndex,nSize);
		if(nCount>0 && pNewElement) 
		{
			m_array.insert(m_array.begin()+nIndex,pNewElement,pNewElement+nCount);
		}				
	}
	
	//! \brief ��ָ��λ��,����һ���µ�����
	//! \remarks ���ָ��λ�ò������鷶Χ��,���Զ�������[0,size]
	//! \param nIndex ָ����λ��
	//! \param newArray Ҫ���������
	void InsertAt(UGint nIndex, const UGArray<T>& newArray)
	{		
		//UGASSERT(pNewArray != NULL);
		UGint nSize=(UGint)m_array.size();
		nIndex=UGCLAMP(0,nIndex,nSize);
		m_array.insert(m_array.begin()+nIndex,newArray.m_array.begin(),newArray.m_array.end());
	}

	//! \brief �õ��ڲ�STL����, �ⲿһ�㲻Ҫʹ��
	//! \return �����ڲ�STL����
	std::vector<T>& Inner()
	{
		return m_array;
	}

private:
	//! \brief �ڲ�����STL��vectorʵ��
	std::vector<T> m_array;
};

}

#endif
