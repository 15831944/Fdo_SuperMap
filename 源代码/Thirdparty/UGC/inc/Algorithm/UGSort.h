/* �޸�˵����
 *		2007.09.21	guohui	Ϊ��ͷ�ļ����ע��
 */
#ifndef UGSORT_H
#define UGSORT_H
#include "Base/ugdefs.h"

namespace UGC {

using namespace std;
template<typename T>

class UGEXPORT UGSort  
{
public:

	//! \brief				��������\n	
	//! \param pSort		ģ����ָ��
	//! \param nFIndex		��ʼ����
	//! \param nTIndex		��ֹnTIndex
	//! \param IsAscending	�Ƿ�����
	//! \remarks			�ɹ�:����pSort��[nFIndex,nTIndex]֮���Ԫ�ذ�IsAscending˳������
	//! \remarks			���T�����������ͣ���T�ڲ������ṩ"<"���ط�,���ǣ�
	static void QSort(T* pSort, UGint nFIndex, UGint nTIndex, UGbool IsAscending = TRUE)
	{
		std::sort(pSort+nFIndex, pSort+nTIndex+1);
		
		if (!IsAscending)
		{
			std::reverse(pSort+nFIndex,pSort+nTIndex+1);
		}
	}
	
	//! \brief				�ֲ���������\n	
	//! \param pSort		ģ����ָ��
	//! \param nFIndex		��ʼ����
	//! \param nMIndex		�м�����
	//! \param nCount		pSort�ĳ���
	//! \param IsAscending	�Ƿ�����
	//! \return				�ɹ�:����pSort��[nFIndex,nMIndex]֮���Ԫ�ذ�IsAscending˳������
	//! \remarks 			�÷����������������������򣬱������Ԫ�صĸ������ÿ��Էŵ�[nFIndex,nMIndex]��Χ
	//! \remarks 			�ڣ���[nMIndex��nCount)�е�Ԫ����δ������ģ����Ƕ�����ʵ�ʱ����������֮�⣻
	//! \remarks 			���T�����������ͣ���T�ڲ������ṩ"<"���ط�,���ǣ�
	static void PartialSort(T* pSort, UGint nFIndex, UGint nMIndex, UGint nCount, UGbool IsAscending = TRUE)
	{
		std::partial_sort(pSort+nFIndex, pSort+nMIndex+1, pSort+nCount);
		
		if (!IsAscending)//��û��ʵ��min_heap֮ǰ������ʵ�ְɣ�
		{
			std::sort(pSort+nFIndex, pSort+nCount);
			std::reverse(pSort+nFIndex,pSort+nCount);
			
			//=============����heapʵ��===============
			/*
			std::make_heap(pSort+nFIndex, pSort+nMIndex+1);
			for (UGint i=nMIndex+1; i < nCount; i++)
			{
				if ((*pSort) < (*(pSort+i)))
				{
					//_Pop_heap();
				}
			}
			std::sort_heap(pSort+nFIndex, pSort+nMIndex+1);
			std::reverse(pSort+nFIndex,pSort+nMIndex+1);*/
			//=============����heapʵ��===============
		}
	}
	
	//! \brief				�鲢����\n	
	//! \param pSort1,2		ģ����ָ��
	//! \param nFIndex1,2	��ʼ����
	//! \param nTIndex1,2	��ֹ����
	//! \param pSort		���ģ��ָ��
	//! \param IsAscending	�Ƿ�����
	//! \return	
	//! \remarks			��������������ļ���pSort1��pSort2���ϲ�����������һ�οռ�;���ý��Ҳ��һ���������С�
	//!						  ���T�����������ͣ���T�ڲ������ṩ"<"���ط�,���ǣ�
	static void MergeSort(T* pSort1, UGint nFIndex1, UGint nTIndex1,
						  T* pSort2, UGint nFIndex2, UGint nTIndex2,
						  T* pSort, UGbool IsAscending = TRUE)
	{
		std::merge(pSort1+nFIndex1, pSort1+nTIndex1+1,
					pSort2+nFIndex2, pSort2+nTIndex2+1, pSort);
		
		if (!IsAscending)
		{
			std::reverse(pSort, pSort + nTIndex1+1-nFIndex1 + nTIndex2+1-nFIndex2);
		}
	}
};


}

#endif


