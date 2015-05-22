/*! \file UGRTree.h
 *  \brief R����Ķ���.
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/   

#ifndef _INC_SMRTREE_3E9E4B130220_INCLUDED
#define _INC_SMRTREE_3E9E4B130220_INCLUDED

#include "Base/UGArray.h"
#include "Algorithm/UGRect2D.h"

#include "UGRTreeNode.h"


namespace UGC{

class UGRTreeBranch;


///	\brief	UGRTree���ṩR���Ĵ���,��ѯ,����,��ȡ�ȹ��ܡ�
/// \remark	R����ʵ�ַ����봫ͳ��R���кܴ�ͬ,�ڵ�Ļ��ָ��Ӻ���
class UGRTree 
{
public:
	/// \brief Ĭ�Ϲ��캯��
	UGRTree();
	/// \brief Ĭ����������
	virtual ~UGRTree();

public: 
	
	/// \brief ����һ��R��
	/// \param pItems ��������R�������ж����Bound��ID�����顣
	/// \param rcBound ���ж���Χ��
	/// \param nQuality R����������ȡֵ��Χ[1,10],ֵԽС��R������Խ�ߣ�����ʱ��ҲԽ����
	/// \return �����ɹ�����TRUE,���򷵻�FALSE.
	/// \remarks ������������Ժ������µ�R��ǰ����ɾ��ԭ����R��
	UGbool Create( UGRTreeNodeItems* pItems,const UGRect2D& rcBound, UGuint nQuality = 5, UGbool bPointDataset = false );

	/// \brief ɾ��R���е�һ������
	/// \param UGRect2D ����ķ�Χ
	/// \param nID �����ID
	UGbool Delete(const UGRect2D& rcBounds,UGint nID);

	/// \brief ����R�����ͷ�ռ�õ��ڴ档
	void Destroy();
	
	/// \brief ��R���в�ѯ
	/// \param rcBound ��ѯ�ķ�Χ
	/// \param arIDs ��ѯ�Ľ��ID����
	/// \return  ��ѯ���Ķ��������
	UGint Query(const UGRect2D& rcBound, UGArray<UGint> &arCertainIDs, UGArray<UGint> &arMaybeIDs );

	/// \brief �õ�R���ķ�Χ
	/// \return  R�������ķ�Χ
	UGRect2D GetBound();

	/// \brief �õ�R��ռ���ڴ�Ĵ�С
	/// \return  R��ռ���ڴ�����������ֽ�Ϊ��λ��
	UGint GetDataSize();

	/// \brief ���ڴ�����������R�����ݲ�����R����
	/// \param arData R�����ݡ�
	/// \return  �ɹ��򷵻�TRUE��
	UGbool Load(UGMemoryStream &arData);

	/// \brief ��R�����ݱ��浽�ڴ������С�
	/// \param arData ��������R�������顣
	/// \return  �ɹ��򷵻�TRUE��
	UGbool Store(UGMemoryStream& arData);

//#ifdef DEBUG
	/// \brief ����ʹ�ã�ȡ��R������Ҷ�ӽڵ�ķ�Χ��
	void GetAllLeafBounds( UGArray<UGRect2D> &arBounds );
	
	/// \brief ����ʹ�ã�ȡ��R������Ҷ�ӽڵ�ķ�Χ��
	void GetAllLeafBounds2( UGArray<UGRect2D> &arBounds );
//#endif

protected:
	/// \brief	R���ĸ���㣬������ͨ�Ķ���
	UGRTreeBranch* m_pRootNormal;
	/// \brief	R���ĸ���㣬����ϴ�Ķ���
	UGRTreeBranch* m_pRootBig;

};

}

#endif /* _INC_SMRTREE_3E9E4B130220_INCLUDED */
