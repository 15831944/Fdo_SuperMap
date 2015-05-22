//=====================================================================================
// ��Ŀ����			SuperMap Foundation Class (SFC) Library 2.0
// ��  �ߣ�			����
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSuperMap GIS����������Ա��δ����ɲ������Դ�����
//					2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����			UGHeap.h
// ��  ����			UGHeap
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		������ 
// ����˵����		
//=====================================================================================
//{{ by guohui 2007.09.29 ���ӶԸ����˵��
//		���������������һ�֣�����ѡ�����򡣶ѵĶ����ǣ���n���ڵ��˳��洢����ȫ�������У�����
//  ���еķ�Ҷ�ڵ㶼С��(����)���ĺ��ӽ��ֵ֮��Ҳ�����κ�һ����Ҷ���ֵ��С��(����)����ȫ�����
//  ����ֵ���ͳƸö�����Ϊһ��С����(�󶥶�)����洢˳��Ϊr[0],r[1]...r[n-1],r[0]Ϊ�Ѷ���r[n]
//  Ϊ�ѵס�
//
//
//
//
//}} by guohui 2007.09.29 ���ӶԸ����˵��
#if !defined(UGQHEAP_H)
#define UGQHEAP_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"

namespace UGC{

class ALGORITHM_API UGQHeap
{
public:

	//! \brief 		���ι��캯��
	//! \return 	
	//! \param 		pnHeapIndex	������
	//! \param 		dCost		����
	//! \remarks 	
	UGQHeap(UGint* pnHeapIndex,UGdouble* dCost, UGbool bSmall = TRUE);
	
	//! \brief 		��������
	//! \return 	
	//! \param 		
	//! \remarks 	
	~UGQHeap();

	//! \brief 		�����С�ķѵ�����
	//! \return 	UGint	ʧ�ܷ���-1
	//! \param 		
	//! \remarks 	
	UGint GetMinCostIndex();

	//! \brief 		����һ����
	//! \return 	
	//! \param 		lItem		��
	//! \remarks 	
	void Insert(const UGint lItem);

	//! \brief 		����һ������ϸ��£�
	//! \return 	
	//! \param 		lIndex		������
	//! \remarks 	
	void Update(const UGint lIndex);

	//! \brief 		����һ������¸��£�
	//! \return 	
	//! \param 		lIndex		������
	//! \remarks 	
	void UpdateEx(const UGint lIndex);

	//! \brief 		��ô�С
	//! \return 	
	//! \param 		
	//! \remarks 	
	UGint GetSize();

private:

	//! \brief 		�ȽϺ���
	//! \return 	
	//! \param 		nNode1		�ڵ�1
	//! \param 		nNode2		�ڵ�2
	//! \remarks 	
	UGbool Compare(const UGint nNode1,const UGint nNode2);
private:

	//! \brief 		��������
	UGArray <UGint> m_SearchedList;

	//! \brief 		����
	UGdouble* m_pdCost;

	//! \brief 		������
	UGint*	m_pnHeapIndex;

	//! \brief      �Ƿ���С���� 
	UGbool m_bSmall;
};

}
#endif // !defined(UGQHEAP_H)
