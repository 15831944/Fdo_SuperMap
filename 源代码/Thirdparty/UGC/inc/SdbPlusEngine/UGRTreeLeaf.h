/*! \file UGRTreeLeaf.h
 *  \brief R��Ҷ����ඨ�塣
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/  

#if !defined(AFX_SMRTREELEAF_H__60DCDD23_A57A_406F_B2A3_B9160FF5B5A1__INCLUDED_)
#define AFX_SMRTREELEAF_H__60DCDD23_A57A_406F_B2A3_B9160FF5B5A1__INCLUDED_


#include "UGRTreeNode.h"

namespace UGC{

/// \brief R��Ҷ����࣬����е�Ԫ����ID����
/// \remarks ����UGRTreeNode
class UGRTreeLeaf : public UGRTreeNode  
{
public:
	UGRTreeLeaf();
	virtual ~UGRTreeLeaf();

public:
	/// \brief �ѽ������ݱ��浽�ڴ������С�
	/// \param arData ��������������顣
	/// \return �ɹ��򷵻�TRUE��
	virtual UGbool Store(UGMemoryStream& arData);

	/// \brief ���ڴ�����������������ݡ�
	/// \param arData �����Ž�����ݡ�
	/// \return  �ɹ��򷵻�TRUE��	
	virtual UGbool Load(UGMemoryStream &arData);

	/// \brief ��ȡ�����Ԫ�ص�����
	/// \return �����Ԫ�ص�����
	virtual UGint GetEntryCount();

	/// \brief ��ȡ���ռ���ڴ���ֽ���
	/// \return ���ռ���ڴ���ֽ���
	virtual UGint GetDataSize();
	
	/// \brief ��ȡ�ý���µ����ж����ID
	/// \param arIDs ���������ȡ����ID
	/// \return �ɹ��򷵻�TRUE��
	virtual UGbool GetAllIDs( UGArray<UGint> &arIDs );

	/// \brief �ڽ���²�ѯ
	/// \param rcBound ��ѯ�ķ�Χ
	/// \param arIDs ��ѯ�Ľ��ID����
	/// \return  ��ѯ���Ķ��������
	virtual UGbool Query(const UGRect2D& rcBound, UGArray<UGint> &arCertainIDs, UGArray<UGint> &arMaybeIDs);

	/// \brief ��ȡ��������
	/// \return ��������
	/// \remarks ����ֵ��2
	virtual UGuchar GetType();

public:
	/// \brief ��ȡID�����ָ��
	/// \return ID�����ָ��
	UGArray<UGint>* GetIDArray() const;
	
protected:
	/// \brief ID�����ָ��
	UGArray<UGint>* m_pIDs;

};


}

#endif // !defined(AFX_SMRTREELEAF_H__60DCDD23_A57A_406F_B2A3_B9160FF5B5A1__INCLUDED_)
