/*!
   **************************************************************************************
    \file     UGList.h
   **************************************************************************************
    \author   ��־��
    \brief    List����ģ����                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-16  ��־��    ����VC8(.NET2005beta2)��list begin()����������-- ,		 
			 ��list end()����������--, �ʶ�ԭ��ʵ�ֻ����; �����˶Կ��ܳ���ط����ж�.	<br>
			 2007-4-16 1)����ע��, 2)�Ѵ�std::list�̳и�Ϊ���, 3) �޸Ĳ��ֽӿ�,ʹ֮���淶
			 4)���ӵ�Ԫ����			<br>
   **************************************************************************************
*/


#ifndef UGLIST_H
#define UGLIST_H
#include "ugdefs.h"

namespace UGC {

//! \brief ����ģ����
//! \remarks �ӿڲο�MFC��CList,�ڲ�����stl��listʵ��
template<typename T>
class UGEXPORT UGList
{
public:
	// zengzm �������޸�POSITION�Ķ���, ��ΪVC8��begin����--,�޷�ȷ���Ƿ��ѵ�����ͷ
	//typedef typename std::list<T>::iterator POSITION;
	typedef typename std::list<T>::iterator STD_POSITION;
	//! \brief ��List�ж�λ�õ���,����ֱ�ӹ���,����ͨ��UGList�����в���.
	struct POSITION
	{
		friend class UGList<T>;
	public:
		POSITION() {
			bIsBOF = false;
		}
	private:
		STD_POSITION it;
		// UGbool bIsEOF; // �Ƿ��ѵ�����β
		UGbool bIsBOF; // �Ƿ��ѵ�����ͷ

		POSITION(STD_POSITION it, UGbool bIsBOF=false){
			this->it = it;
			this->bIsBOF = bIsBOF;
		}
	};

public:
	//! \brief Ĭ�Ϲ��캯��
	UGList()
	{
	}
	
	//! \brief �õ�Ԫ�ظ���
	UGint GetCount() const
	{
		return (UGint)m_list.size();
	}

	//! \brief �ж��Ƿ�Ϊ��
	//! \return �շ���true;��Ϊ�շ���false
	UGbool IsEmpty() const
	{
		return m_list.empty();	
	}

	//! \brief �õ�ͷԪ��
	//! \return ����ͷԪ�ص�����,�������߿�ֱ���޸�
	T& GetHead()
	{
		UGASSERT(!IsEmpty());
		return m_list.front();
	}

	//! \brief �õ�ͷԪ��
	//! \return ����ͷԪ�ص�const����
    const T& GetHead() const
	{
		UGASSERT(!IsEmpty());
		return m_list.front();
	}

	//! \brief �õ�βԪ��
	//! \return ����βԪ�ص�����,�������߿�ֱ���޸�
    T& GetTail()
	{
		UGASSERT(!IsEmpty());
		return m_list.back();
	}

	//! \brief �õ�βԪ��
	//! \return ����βԪ�ص�const����
    const T& GetTail() const
	{
		UGASSERT(!IsEmpty());
		return m_list.back();
	}

	//! \brief �Ƴ�ͷԪ��
	//! \return ���ر��Ƴ���Ԫ��
	T RemoveHead()
	{
		UGASSERT(!IsEmpty());
		T f=m_list.front();
		m_list.pop_front();
		return f;
	}

	//! \brief �Ƴ�βԪ��
	//! \return ���ر��Ƴ���Ԫ��
    T RemoveTail()
	{
		UGASSERT(!IsEmpty());
		T t=m_list.back();
		m_list.pop_back();
		return t;
	}

	//! \brief ��ͷ������Ԫ��
	//! \param newElement Ҫ����ӵ�Ԫ��
	//! \return ��������Ԫ�ص�Position
	POSITION AddHead(const T& newElement)
	{
		m_list.push_front(newElement);
		return m_list.begin();
	}

	//! \brief ��β������Ԫ��
	//! \param newElement Ҫ����ӵ�Ԫ��
	//! \return ��������Ԫ�ص�Position
    POSITION AddTail(const T& newElement)
	{
		m_list.push_back(newElement);
		return --m_list.end();
	}

	//! \brief ��ͷ������һ������
	//! \param newList Ҫ����ӵ�����
	void AddHead(const UGList<T>& newList)
	{
		//UGASSERT(pNewList);
		m_list.insert(m_list.begin(),newList.m_list.begin(),newList.m_list.end());
	}

	//! \brief ��β������һ������
	//! \param newList Ҫ����ӵ�����
    void AddTail(const UGList<T>& newList)
	{
		//UGASSERT(pNewList);
		m_list.insert(m_list.end(),newList.m_list.begin(),newList.m_list.end());
	}
	
	//! \brief �Ƴ�����Ԫ��
	void RemoveAll()
	{
		m_list.clear();
	}

	//! \brief �õ�ͷ��λ��
	//! \return ����ͷ��λ��
	POSITION GetHeadPosition() const
	{				
		// return const_cast<UGList<T>*>(this)->begin();
		// ����������˼��: �Ȱ�m_list�ĳ�����ȥ��, Ȼ��õ�ָ��begin�ĵ�����
		// ������������Ƿ�const����, Ȼ�����POSITION������.
		// �������кü����ط��õ������ַ���,
		return POSITION( (const_cast< std::list<T>& >(m_list)).begin());
	}

	//! \brief �õ�β��λ��
	//! \return ����β��λ��
    POSITION GetTailPosition() const
	{
		// return --(const_cast<UGList<T>*>(this)->end());
		STD_POSITION itEnd = const_cast<std::list<T>&>(m_list).end();
		if (GetCount() == 0) {
			return POSITION(itEnd, true);
		}
		return POSITION(--itEnd);
	}

	//! \brief �ж�ĳλ���Ƿ��ѵ�����β
	//! \param position Ҫ�жϵ�λ��
	//! \return �ѵ�����β����true;���򷵻�false
	UGbool IsEOF(POSITION position) const
	{
		return position.it==const_cast<std::list<T>&>(m_list).end();
	}

	//! \brief �ж�ĳλ���Ƿ��ѵ�����ͷ
	//! \param position Ҫ�жϵ�λ��
	//! \return �ѵ�����ͷ����true;���򷵻�false
	UGbool IsBOF(POSITION position) const
	{
		return position.bIsBOF 
			|| (++position.it==const_cast<std::list<T>&>(m_list).begin());
	}
	
	//! \brief �õ�ĳλ�õ���һ��λ��
	//! \remarks ��λ�ò�����ͷλ�û���βλ��
	//! \param rPosition[in][out] ������λ��,�õ���һ����λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����
	T& GetNext(POSITION& rPosition)
	{
		UGASSERT(!(IsEOF(rPosition) || IsBOF(rPosition)));
		return *rPosition.it++;
	}

	//! \brief �õ�ĳλ�õ���һ��λ��
	//! \remarks ��λ�ò�����ͷλ�û���βλ��
	//! \param rPosition[in][out] ������λ��,�õ���һ����λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����
    const T& GetNext(POSITION& rPosition) const
	{
		UGASSERT(!(IsEOF(rPosition) || IsBOF(rPosition)));
		return *rPosition.it++;
	}

	//! \brief �õ�ĳλ�õ���һ��λ��
	//! \remarks ��λ�ò�����ͷλ�û���βλ��
	//! \param rPosition[in][out] ������λ��,�õ���һ����λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����
    T& GetPrev(POSITION& rPosition)
	{
		UGASSERT(!(IsEOF(rPosition) || IsBOF(rPosition)));
		if (rPosition.it == m_list.begin()) 
		{ // �����ͷ��, Ҫ��¼һ��, ���Ҳ�--��
			rPosition.bIsBOF = true; 
			return *rPosition.it;
		}
		return *rPosition.it--;
	}

	//! \brief �õ�ĳλ�õ���һ��λ��
	//! \remarks ��λ�ò�����ͷλ�û���βλ��
	//! \param rPosition[in][out] ������λ��,�õ���һ����λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����
    const T& GetPrev(POSITION& rPosition) const
	{
		UGASSERT(!(IsEOF(rPosition) || IsBOF(rPosition)));
		if (rPosition.it == m_list.begin()) 
		{ // �����ͷ��, Ҫ��¼һ��, ���Ҳ�--��
			rPosition.bIsBOF = true; 
			return *rPosition.it;
		}
		return *rPosition.it--;
	}
	
	//! \brief �õ�ĳλ�õ�ֵ
	//! \param position �����λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����
	T& GetAt(POSITION position)
	{
		UGASSERT(!(IsEOF(position) || IsBOF(position)));
		return *position.it;
	}

	//! \brief �õ�ĳλ�õ�ֵ
	//! \param position �����λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����
    const T& GetAt(POSITION position) const
	{
		UGASSERT(!(IsEOF(position) || IsBOF(position)));
		return *position.it;
	}

	//! \brief ����ĳλ�õ�ֵ
	//! \param position Ҫ����ֵ��λ��
	//! \param newElement Ҫ����λ�õ���ֵ
	void SetAt(POSITION pos, const T& newElement)
	{
		UGASSERT(!(IsEOF(pos) || IsBOF(pos)));
		*pos.it=newElement;
	}

	//! \brief �Ƴ�ĳλ�õ�Ԫ��
	//! \param position Ҫ�Ƴ���λ��
    void RemoveAt(POSITION position)
	{
		UGASSERT(!(IsEOF(position) || IsBOF(position)));
		m_list.erase(position.it);
	}
	
	//! \brief ��ĳλ��֮ǰ����һ��Ԫ��
	//! \param position Ҫ�����λ��
	//! \param newElement Ҫ�����Ԫ��
	//! \return ���ر�����Ԫ���������е�λ��
	POSITION InsertBefore(POSITION position,const T& newElement)
	{
		UGASSERT(!IsBOF(position));
		return m_list.insert(position.it,newElement);
	}

	//! \brief ��ĳλ��֮�����һ��Ԫ��
	//! \param position Ҫ�����λ��
	//! \param newElement Ҫ�����Ԫ��
	//! \return ���ر�����Ԫ���������е�λ��
    POSITION InsertAfter(POSITION position,const T& newElement)
	{
		UGASSERT(!IsEOF(position));
		return m_list.insert(++position.it,newElement);
	}

	//! \brief ��ͷ��ʼ����ֵ����ָ��������Ԫ�ص�λ��
	//! \param searchValue Ҫ���ҵ�Ԫ��
	//! \return ���ص�һ���ҵ���Ԫ�ص�λ��
	POSITION Find(const T& searchValue) const
	{
		return std::find(const_cast<std::list<T>&>(m_list).begin(),
			const_cast<std::list<T>&>(m_list).end(),searchValue);
	}

	//! \brief ��ָ����λ��֮��,��ʼ����ֵ����ָ��������Ԫ�ص�λ��
	//! \param searchValue Ҫ���ҵ�Ԫ��
	//! \param startAfter ָ�����ҵ�λ��(��λ�ò�������)
	//! \return ���ص�һ���ҵ���Ԫ�ص�λ��
    POSITION Find(const T& searchValue, POSITION startAfter) const
	{
		UGASSERT(!IsEOF(startAfter));
		return std::find(++startAfter.it,const_cast<std::list<T>&>(m_list).end(),searchValue);
	}
	
	//! \brief �õ�ָ��������Ԫ�ص�λ��
	//! \param nIndex ָ���Ĳ��ҿ�ʼ������
	//! \return �����ҵ���Ԫ�ص�λ��; �����������δ�ҵ�,�򷵻�βλ��
    POSITION FindIndex(UGint nIndex) const
	{		
		
		POSITION pos(const_cast<std::list<T>&>(m_list).begin());
		for(UGint i=0;i<nIndex;i++)
		{
			if(++pos.it==const_cast<std::list<T>&>(m_list).end())
				break;
		}
		return pos;
	}

private:
	//! \brief �ڲ�ʵ�ֲ���stl��list
	std::list<T> m_list;
};

}

#endif


