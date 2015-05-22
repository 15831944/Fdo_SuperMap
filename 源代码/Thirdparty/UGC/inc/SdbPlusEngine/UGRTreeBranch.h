/*! \file UGRTreeBranch.h
 *  \brief R���ڲ������Ķ��塣
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/  
#ifndef _INC_CSmRTreeBranch_3E9E4B130207_INCLUDED
#define _INC_CSmRTreeBranch_3E9E4B130207_INCLUDED


#include "UGRTreeNode.h"

namespace UGC{

/// \brief R���ڲ�����࣬����е�Ԫ�����������
/// \remarks ����UGRTreeNode
class UGRTreeBranch : public UGRTreeNode    
{	
public:
	UGRTreeBranch();
	virtual ~UGRTreeBranch();

public:

	/// \brief �ѽ������ݱ��浽�ڴ������С�
	/// \param arData ��������������顣
	/// \return �ɹ��򷵻�TRUE��
	virtual UGbool Store(UGMemoryStream& arData);

	/// \brief ���ڴ�����������������ݡ�
	/// \param arData �����Ž�����ݡ�
	/// \param nPos �������nPosλ�ÿ�ʼ��ȡ����
	/// \return  �ɹ��򷵻�TRUE��
	virtual UGbool Load(UGMemoryStream &arData);

	/// \brief �жϽ���Ƿ���Ҫ�ָ�
	/// \param nMaxEntryCount �������������Ԫ������
	/// \return ��Ҫ�ָ��TRUE�����򷵻�FALSE
	/// \remarks �����Ԫ�ش��������������Ҫ�ָ�
	virtual UGbool NeedSplit( UGint nMaxEntryCount );
	
	/// \brief ��ȡ�����Ԫ�ص�����
	/// \return �����Ԫ�ص�����
	virtual UGint GetEntryCount();

	/// \brief ��ȡ��������
	/// \return ��������
	/// \remarks ����ֵ��1
	virtual UGuchar GetType();

public:

	/// \brief ��ȡ�ӽ���ָ��
	/// \param nIndex �ӽ�������
	/// \return ָ���������ӽ��ָ��
	/// \remarks �ⲿ����ɾ�����ص�ָ��
	UGRTreeNode* GetChildAt( UGint nIndex );

	/// \brief ���һ���ӽ��
	/// \param pChildNode Ҫ��ӵ��ӽ��ָ��
	/// \return ��Ӻ��ӽ�������
	UGint AddChild( UGRTreeNode* pChildNode );

	/// \brief ��㷱��
	/// \param nMaxItemCount �������������Ԫ������
	/// \param pScanLines ɨ��������
	/// \return ���ܳɹ�����true�����򷵻�false
	UGbool Breed( UGint nMaxItemCount,RScanLineInfo *pScanLines);

	/// \brief �����죬����µ�����������bud�Ľ���ݱ�Ϊleaf
	/// \return �ݱ�ɹ�����true�����򷵻�false
	UGbool GrowUp();

	/// \brief ��ȡ���ռ���ڴ���ֽ���
	/// \return ���ռ���ڴ���ֽ���
	/// \remarks �����������ӽ��ռ�õ��ڴ��ֽ���
	UGint GetDataSize();

	/// \brief �ڽ���²�ѯ
	/// \param rcBound ��ѯ�ķ�Χ
	/// \param arCertainIDs ��ѯ��ȷ�����ID����
	/// \param arMaybeIDs ��ѯ�Ŀ��ܽ��ID����
	/// \return  ��ѯ���Ķ��������			
	virtual UGbool Query(const UGRect2D& rcBound, UGArray<UGint> &arCertainIDs, UGArray<UGint> &arMaybeIDs);

	/// \brief ��ȡ�ý���µ����ж����ID
	/// \param arIDs ���������ȡ����ID
	/// \return �ɹ��򷵻�TRUE��
	UGbool GetAllIDs( UGArray<UGint> &arIDs );

public:
	/// \brief ����ʹ�ã�ȡ��R������Ҷ�ӽڵ�ķ�Χ��
	void GetAllLeafBounds( UGArray<UGRect2D> &arBounds );

protected:
	/// \brief �ӽ��ָ������
	UGArray<UGRTreeNode*> m_arChildren;

};

}

#endif /* _INC_CSmRTreeBranch_3E9E4B130207_INCLUDED */
