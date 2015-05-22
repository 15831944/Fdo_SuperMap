/*! \file UGRTreeBud.h
 *  \brief R��ѿ����ඨ�塣
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/  
#ifndef _INC_CSmRTreeBud_3E9E4B130213_INCLUDED
#define _INC_CSmRTreeBud_3E9E4B130213_INCLUDED

#include "UGRTreeNode.h"

namespace UGC{

class UGRTreeLeaf;


/// \brief R��ѿ����࣬����е�Ԫ����ָ��items����������
/// \remarks ����UGRTreeNode
class UGRTreeBud : public UGRTreeNode   
{
public:
	UGRTreeBud();
	virtual ~UGRTreeBud();

public:
	virtual UGRTreeNode* Split( UGint nMaxItemCount,RScanLineInfo *pScanLines) ;
	
	virtual UGRTreeNode* Split( UGint nMaxItemCount );

	virtual UGbool NeedSplit( UGint nMaxEntryCount );
	
	virtual UGint GetEntryCount();

	/// \brief ��ȡ��������
	/// \return ��������
	/// \remarks ����ֵ��0
	virtual BYTE GetType();

	virtual UGint GetDataSize();

public:
	/// \brief �ݱ��һ��leaf���
	/// \param pLeaf ָ���ݱ������һ��leaf������
	/// \return �ݱ�ɹ�����true�����򷵻�false
	UGbool GrowUp(UGRTreeLeaf* pLeaf);
	
	/// \brief ���ý�����������ָ���rtree��itemsָ��
	/// \param pIndexes ������������ָ��
	/// \param pItems rtree��itemsָ��
	/// \remarks �������ڴ棬ֻ�Ǽ򵥵�ָ�븳ֵ
	void SetItems( UGArray<UGint>* pIndexes, UGRTreeNodeItems* pItems );
	
	/// \brief ����������Ԫ�صķ�Χ
	/// \remarks 
	void CalculateBound();

protected:

	/// \brief ѡ��һ��������и���
	/// \param nMaxItemCount �������������Ԫ������
	/// \param pScanLines ɨ��������
	/// \param dPosition �и���λ��
	/// \param bVertical �и��߷��򣬺����������
	/// \param nOldCount �����и��߻��֣��ñ����Ľ������
	/// \param nNewCount �����и��߻��֣����Ƴ��Ľ������
	/// \return ѡ��ɹ�����true�����򷵻�false
	/// \remarks �ȽϺ�����Ѻ���������и��ߣ�ѡ��Ϻõ�һ��
	UGbool ChooseCutLine( UGint nMaxItemCount,RScanLineInfo *pScanLines,
						UGdouble& dPosition, UGbool& bVertical, 
						UGint& nOldCount, UGint& nNewCount );
	
	/// \brief ѡ��һ������������и���
	/// \param nMaxItemCount �������������Ԫ������
	/// \param pScanLines ɨ��������
	/// \param dPosition �и���λ��
	/// \param nOldCount �����и��߻��֣��ñ����Ľ������
	/// \param nNewCount �����и��߻��֣����Ƴ��Ľ������
	/// \return ѡ��ɹ�����true�����򷵻�false
	/// \remarks �Թ��и��ߵ����ж�����ɵ�bound�����СΪ��׼
	UGdouble ChooseVerticalCutLine( UGint nMaxItemCount,RScanLineInfo *pScanLines,
									UGdouble& dPosition,UGint& nOldCount, UGint& nNewCount );
	 
	/// \brief ѡ��һ������ĺ����и���
	/// \param nMaxItemCount �������������Ԫ������
	/// \param pScanLines ɨ��������
	/// \param dPosition �и���λ��
	/// \param nOldCount �����и��߻��֣��ñ����Ľ������
	/// \param nNewCount �����и��߻��֣����Ƴ��Ľ������
	/// \return ѡ��ɹ�����true�����򷵻�false
	/// \remarks �Թ��и��ߵ����ж�����ɵ�bound�����СΪ��׼
	UGdouble ChooseHorizontalCutLine( UGint nMaxItemCount, RScanLineInfo *pScanLines,
									UGdouble& dPosition,UGint& nOldCount, UGint& nNewCount );

	UGint GetOldItemCount( UGdouble dPosition, UGbool bVertical );
	UGint GetNewItemCount( UGdouble dPosition, UGbool bVertical );


	/// \brief �����и��ߵ�λ�úͷ����ж�һ������Ӧ�ñ��������Ǳ����ֵ��µĽ����
	/// \param rcBound ����ķ�Χ
	/// \param dPosition �и���λ��
	/// \param bVertical �и��߷��򣬺����������
	/// \return ����Ӧ�ñ����򷵻�true�����򷵻�false
	UGbool BeSaved( const UGRect2D& rcBound, UGdouble dPosition, UGbool bVertical );
	
protected:
	/// \brief ָ������Ԫ�ص������ָ��
	UGRTreeNodeItems* m_pItems ;
	
	/// \brief ָ��ý�������Ԫ������������
	/// \remark example: 
	/// \remark		��ȡ��nIndex��Ԫ��
	/// \remark		m_pItems->ElementAt(m_pIndexes->GetAt(nIndex))
	UGArray<UGint>* m_pIndexes;

};

}


#endif /* _INC_CSmRTreeBud_3E9E4B130213_INCLUDED */
