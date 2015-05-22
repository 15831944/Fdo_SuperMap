/*! \file UGRTreeNode.h
 *  \brief R�����������Լ�������͵Ķ��塣
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/  
#ifndef _INC_CSmRTREENODE_3E9E4B130201_INCLUDED
#define _INC_CSmRTREENODE_3E9E4B130201_INCLUDED

#include "Base/UGArray.h"
#include "Base/UGMemoryStream.h"
#include "Algorithm/UGRect2D.h"

namespace UGC{


/// \brief ����R������Ҫ������Ԫ�صĽṹ
class UGRTreeNodeItem
{
public:
	/// \brief �����ID
	UGint m_nID ;

	/// \brief ����ķ�Χ
	UGRect2D m_rcBound ;	
};

typedef UGArray<UGRTreeNodeItem> UGRTreeNodeItems;

/// \brief ����R���Ĺ����У��ָ��ߵ����ݽṹ
typedef struct tagRScanLineInfo
{
	tagRScanLineInfo()
	{
		dArea = 0.0;
		nNewCount = 0;
		nOldCount = 0;				
	}
	/// \brief �ָ��ߴ��������ж�������ܺ�
	UGdouble dArea;
	
	/// \brief �ָ����ұ߻����ϱߵĶ��������
	UGint nNewCount;
	
	/// \brief �ָ�����߻����±ߵĶ��������
	UGint nOldCount;
} RScanLineInfo;
 
/// \brief R����������
/// \remark CSmRTreeBranch��CSmRTreeLeaf��CSmRTreeBud�ĸ���
class UGRTreeNode 
{
public:
	UGRTreeNode();
	virtual ~UGRTreeNode();

public:
	/// \brief ��ȡ�����Ԫ�ص�����
	/// \return �����Ԫ�ص�����
	/// \remarks ���麯����������ʵ��
	virtual UGint GetEntryCount() = 0;

	/// \brief ��ȡ��������
	/// \return �������� 0�� bud��1�� branch��2�� leaf
	/// \remarks ���麯����������ʵ��
	virtual UGuchar GetType() = 0;
	
	/// \brief ��ȡ���ռ���ڴ���ֽ���
	/// \return ���ռ���ڴ���ֽ���
	/// \remarks ���麯����������ʵ��
	/// \remarks �����������ӽ��ռ�õ��ڴ��ֽ���
	virtual UGint GetDataSize() = 0;
	
	/// \brief �ѽ������ݱ��浽�ڴ������С�
	/// \param arData ��������������顣
	/// \return �ɹ��򷵻�TRUE��
	virtual UGbool Store(UGMemoryStream& arData);

	/// \brief ���ڴ�����������������ݡ�
	/// \param arData �����Ž�����ݡ�
	/// \return  �ɹ��򷵻�TRUE��
	virtual UGbool Load(UGMemoryStream &arData);

	/// \brief ��ȡ�ý���µ����ж����ID
	/// \param arIDs ���������ȡ����ID
	/// \return �ɹ��򷵻�TRUE��
	virtual UGbool GetAllIDs( UGArray<UGint> &arIDs );

	/// \brief ��ѯ�ý��
	/// \param rcBound ��ѯ�ķ�Χ
	/// \param arCertainIDs ��ѯ��ȷ�����ID����
	/// \param arMaybeIDs ��ѯ�Ŀ��ܽ��ID����
	/// \return  ��ѯ���Ķ��������
	virtual UGbool Query(const UGRect2D& rcBound, UGArray<UGint> &arCertainIDs, UGArray<UGint> &arMaybeIDs);

	/// \brief �жϽ���Ƿ���Ҫ�ָ�
	/// \param nMaxEntryCount �������������Ԫ������
	/// \return ��Ҫ�ָ��TRUE�����򷵻�FALSE
	/// \remarks �����Ԫ�ش��������������Ҫ�ָ�
	virtual UGbool NeedSplit( UGint nMaxEntryCount );

	/// \brief �ָ���
	/// \param nMaxItemCount �������������Ԫ������
	/// \param pScanLines ɨ��������
	/// \return �ָ�������µĽ��
	virtual UGRTreeNode* Split( UGint nMaxItemCount,RScanLineInfo *pScanLines);
	
	virtual UGRTreeNode* Split( UGint nMaxItemCount );
public:
	/// \brief ��ȡ���ķ�Χ
	/// \return ���ķ�Χ
	UGRect2D GetBound() const
	{
		return m_rcBound;
	}

	/// \brief ���ý��ķ�Χ
	/// \param ���ķ�Χ
	void SetBound(const UGRect2D& rcBound)
	{
		m_rcBound = rcBound;
	}

protected:
	/// \brief ���ķ�Χ
	UGRect2D m_rcBound;
};


}

#endif /* _INC_CSmRTREENODE_3E9E4B130201_INCLUDED */
