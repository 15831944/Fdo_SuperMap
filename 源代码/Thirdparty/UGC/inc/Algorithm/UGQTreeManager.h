//=====================================================================================
// ��Ŀ����			SuperMap Foundation Class (SFC) Library 2.0
// ��  �ߣ�			����,
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	06/21/1999
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSuperMap GIS����������Ա��δ����ɲ������Դ�����
//					2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����			UGQTreeManager.h
// ��  ����			UGQTreeManager
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		 �����й��Ĳ����������ࡣ
// ����˵����		������Ҫ���ڴ��������ֲ���ʾʱ��ѡ��Ҫ��ʾ�Ķ����Լ��������ļ��������ݿ�ʱ��
//					�Զ�ά����ı��뽨��ÿһ��������������Ա���ҡ����������ļ��������ݿ�ʱ��
//					�����ô����ṩ�Ľӿڴ����û�ʹ��SQL�������Լ������Լ�����Ŀռ����ݿ�Ĳ�����
//------------------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////////
//ʹ�÷�����
//------------------------------------------------------------------------------------------------
//�����˴���Ķ��������SetEntireBounds()����ȷ���������ľ��Σ�����ʹ�����к�����
//		GetIndex()
//		GetRect()
//		Separete()
//------------------------------------------------------------------------------------------------
//����Create()�������������Ĵ洢�ṹ�������ʹ�����к�����
//		Add()
//		Delete()
//		GetKeyNum()
//------------------------------------------------------------------------------------------------
//������SetEntireBounds()����ȷ���������ľ�������Create()�������������Ĵ洢�ṹ�����ʹ�����к�����
//		GetKeys()
//------------------------------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////
/* �޸�˵����
 *		2007.09.24	guohui	Ϊ��ͷ�ļ����ע��
 */
#if !defined(SMQTREEMANAGER_H)
#define SMQTREEMANAGER_H

#include "Base/UGString.h"
#include "UGRect2D.h"
#include "UGQTree.h"

namespace UGC {

class ALGORITHM_API UGQTreeManager
{
public:

	//! \brief 		ȱʡ���캯��
	//! \return 	void
	UGQTreeManager();

	//! \brief 		��������
	//! \return 	void
	virtual ~UGQTreeManager();

public:

	//! \brief 		
	//! \return 	
	//! \param 		
	//! \remarks 	

	//! \brief 		��ȡ���ݴ�С
	//! \return 	UGint
	UGint GetDataSize();

	//! \brief 		��ѯrcBound��Χ�ڵ����н��
	//! \return 	UGbool
	//! \param 		rcBound			��ѯ��bounds
	//! \param 		arCertainIDs	�϶��ڷ�Χ�ڵĽ��
	//! \param 		arMaybeIDs		�����ڷ�Χ�ڵĽ��
	//! \remarks 	
	UGbool Query(const UGRect2D& rcBound,UGArray<UGint>& arCertainIDs,UGArray<UGint>& arMaybeIDs);
	
	//! \brief 		��ĳ���ڵ��ϼ���һ����ֵ��
	//! \return 	void
	//! \param 		Index		�������.Index����GetIndex()�����õ��ģ���һ��15�����������.
	//! \param 		Key			��ֵ.Key����һ������ļ�ֵ��
	//! \remarks 	��Ҫ���� create() �����������
	void Add(UGint Index,UGuint Key);				

	//! \brief 		�������Ĵ洢�ṹ
	//! \return 	UGbool
	//! \param 		nSep	���������λ��ִ��������������Ĳ��� = nSep + 1��
	//! \remarks 	
	UGbool Create(UGint nSep);			

	//! \brief 		ɾ�����������
	//! \return 	void
	//! \remarks 	��Ҫ������ create() �����������������
	void Delete();

	//! \brief 		ɾ��һ���ڵ��ϵ����м�ֵ
	//! \return 	void
	//! \param 		Index	�ڵ�����
	//! \remarks 	��Ҫ������ create() �����������������
	void Delete(UGint Index);

	//! \brief 		ɾ��һ���ڵ��ϵ�ĳһ����ֵ
	//! \return 	void
	//! \param 		Index	�ڵ�����
	//! \param 		Key		��ֵ
	//! \remarks 	��Ҫ������ create() ������������������������û�ɾ�����ݿ��е�ĳЩ����ʱ���Ƕ����ݿ�Ĵ���
	void Delete(UGint Index,UGuint Key);

	//! \brief 		�õ�һ������������ֵ��
	//! \return 	UGint
	//! \param 		Point	������
	//! \remarks 	��Ҫ������SetEntireBounds()����ȷ���������ľ���
	UGint GetIndex(const UGPoint2D &Point);

	//! \brief 		�õ�һ�����������ֵ
	//! \return 	UGint
	//! \param 		ItemRect	�����������Σ�
	//! \remarks 	��Ҫ������SetEntireBounds()����ȷ���������ľ���
	UGint GetIndex(UGRect2D ItemRect);

	//! \brief 		�õ������Ѽ���Ķ��������
	//! \return 	UGint
	//! \remarks 	��Ҫ������create()�����������������
	UGint GetKeyNum();

	//! \brief 		�õ�һ������ֵ������ľ���
	//! \return 	UGbool
	//! \param 		Index		����ֵ
	//! \param 		Rect		���صľ���
	//! \remarks 	��Ҫ������SetEntireBounds()����ȷ���������ľ���
	UGbool GetRect(UGint Index,UGRect2D &Rect);
	
	//! \brief 		���������ľ��εĴ�С
	//! \return 	void
	//! \param 		rc2Entire	���η�Χ
	//! \remarks 	�Ժ���Խ���ȡ����ֵ�ȵĲ���
	void SetEntireBounds(UGRect2D rc2Entire);

	//! \brief 		��ȡ�������εĴ�С
	//! \return 	UGRect2D
	//! \remarks 	
	UGRect2D GetEntireBounds() const;

	//! \brief 		�Ƿ�Ϊ��
	//! \return 	UGbool
	//! \remarks 	
	UGbool IsEmpty();

	//! \brief 		��R�����ݱ��浽�ڴ�������
	//! \return 	UGbool
	//! \param 		arData	��������R�������顣
	//! \remarks 	
	UGbool Store(UGMemoryStream& arData);

	//! \brief 		���ڴ�����������R�����ݲ�����R����
	//! \return 	UGbool
	//! \param 		arData	R������
	//! \remarks 	
	UGbool Load(UGMemoryStream &arData);

protected:		// ���ѯ��صĺ���

	//! \brief 		������ѯ����
	//! \return 	UGString
	//! \param 		rcBound			��ѯ��Χ
	//! \remarks 	
	UGString BuildFilter(const UGRect2D& rcBound);

	//! \brief 		�õ�ĳһ�����η�ΧtheRect�ڵĶ���ļ�ֵǰ��׼������
	//! \return 	void
	//! \param 		theRect			��ѯ��Χ
	//! \param 		nSep			ָ���˽�����������ε���С�����ٻ��ֶ��ٴ�
	//! \param 		nabsSep			ָ���˵���theRect���α��ָ�������α��ָ���nSep�ζ��γɵ�С���εĴ�С��ʱ���ֹͣ�ٷָ��ˡ�
	//! \remarks 	��׼���õ�ĳһ�����η�ΧtheRect�ڵĶ���ļ�ֵǰ���á�	
	//				��Ҫ������SetEntireBounds()����ȷ���������ľ��Σ���Ҳ��Ҫ������ create()�����������������	
	void PrepareGetKeys(UGRect2D theRect,UGint nSep,UGint nabsSep);

	//���������Ѿ��ҵ��ļ�ֵ�ĺ�����
	/////////////////////////////////////////////////////////////////////////
	//�õ���һ���϶���ָ�������еĶ����Keyֵ�������ȵ���PrepareGetKeys()������
	UGbool GetNextCertainKey(UGuint &Key);

	//! \brief 		�õ���һ��������ָ�������еĶ����Keyֵ
	//! \return 	UGbool
	//! \param 		Key			��ȡ�ļ�ֵ
	//! \remarks 	�����ȵ���PrepareGetKeys()������
	UGbool GetNextMaybeKey(UGuint &Key);
	
	//! \brief 		�õ���һ��������ָ�������еĶ����Keyֵ
	//! \return 	UGbool
	//! \param 		Key			��ȡ�ļ�ֵ
	//! \remarks 	
	UGbool GetNextHoldKey(UGuint &Key);

	//! \brief 		��ָ����ܵļ�ֵ�Ĺ�������һ�����ܵļ�ֵ��
	//! \return 	UGbool
	//! \param 
	//! \remarks
	UGbool MaybeKeysMoveFirst();

	//! \brief		��ָ��϶��ļ�ֵ�Ĺ�������һ���϶��ļ�ֵ��
	//! \return 	UGbool
	//! \param 
	//! \remarks
	UGbool CertainKeysMoveFirst();

private:

	//! \brief		�õ�һ������ֵ����Ľڵ�ĸ��ڵ������ֵ��
	//! \return 	UGint
	//! \param		Index		����
	//! \remarks
	UGint GetParent(UGint Index);

	//! \brief		�õ�һ������ֵ������Ľڵ�Ϊ�������ϵĽڵ�����Ӧ�������ķ�Χ��
	//! \return 	UGbool
	//! \param		Index			����
	//! \param		nMinSubIndex	��С����
	//! \param		nMaxSubIndex	�������
	//! \remarks
	UGbool GetIndexRange(UGint nIndex,UGint& nMinSubIndex,UGint& nMaxSubIndex);

	//! \brief		�õ�һ������ֵ������Ľڵ�Ϊ�������ϵĽڵ�����Ӧ�������ķ�Χ
	//! \return 	UGbool
	//! \param		baseIndex		����
	//! \param		nMinSubIndex	��С����
	//! \param		nMaxSubIndex	�������
	//! \remarks	Ҫ��Seperate()�����õ���Certain�������е���������ʹ�á�
	UGbool GetIndexPro(UGint baseIndex,UGint& MinIndex,UGint& MaxIndex);
//{{ by guohui 2007.09.30 �ⲿ�޷�ʹ�� ��ʱ���
//	//! \brief		��ȡ����ֵ
//	//! \return 	void
//	//! \param		theRect			
//	//! \param		pHoldArray		
//	//! \param		pMaybeArray		
//	//! \param		pCertainArray	
//	//! \param		nSep			
//	//! \param		nabsSep			
//	//! \remarks	��GetKeys()�������ƣ�����ͬ���ǵõ���������ֵ���û����Ը�������ֵ�����ݿ��в�ѯ��Ӧ
//	//				�Ķ�����Ҫ������SetEntireBounds()����ȷ���������ľ��Ρ�
//	void Separete(UGRect2D theRect,
//				UGArray<UGint> *pHoldArray,
//				UGArray<UGint>* pMaybeArray,
//				UGArray<UGint>* pCertainArray ,
//				UGint nSep,
//				UGint nabsSep);
//}} by guohui 2007.09.30 �ⲿ�޷�ʹ�� ��ʱ���

	//! \brief		�õ����ĸ�����Ľ��ް�Χ�ŵ����е���������ֵ���������������С�
	//! \return 	void
	//! \param		CurIndex			
	//! \param		nLayer		
	//! \param		left		
	//! \param		top	
	//! \param		right			
	//! \param		bottom			
	//! \param		pHoldArray			
	//! \param		pMaybeArray			
	//! \param		pCertainArray			
	//! \remarks	
	void GetInnerIndex(UGint CurIndex,
						UGint nLayer,
						double left,
						double top,
						double right,
						double bottom,
						UGArray<UGint> *pHoldArray,
						UGArray<UGint> *pMaybeArray,
						UGArray<UGint> *pCertainArray);

//�÷�ͬ�����ķ���--GetKeys()һ����ֻ��Ϊ�˶�����Index��ͬ�Ĵ���ŷֳ���������洢

	//! \brief		�õ�һ������ֵ����������λ�ڵĲ���
	//! \return 	UGbool
	//! \param		Index			����
	//! \param		nLayer			���ز���
	//! \remarks	Ҫ��Seperate()�����õ���Certain�������е���������ʹ�á�
	UGbool GetLayer ( UGint Index,UGint& nLayer );

	//! \brief		
	//! \return 	
	//! \param		
	//! \param		
	//! \remarks	
	void GetNextIndex(UGbool bLeft,UGint& CurLayer,UGint& CurIndex);

	//! \brief		
	//! \return 	
	//! \param		
	//! \param		
	//! \remarks	
	UGRect2D GetNextRect(UGint Index,
						UGint CurLayer,
						UGint CurIndex,
						UGRect2D CurRect);
	
	
private:
	
	//-------- �ڵõ�ѡ�еĶ���ʱ�õ���˽�б�����
	UGbool			m_bHoldKeys				;
	UGArray<UGint> *m_pCertainArray			;		//	��ѯ���Ľ�������
	UGint			m_Certain_CurIndexPos	;		//	����ĵ�ǰλ��
	UGint			m_Certain_CurIndex		;		//	��ǰ���Ĳ������ı��� m_Certain_CurIndex = m_pCertain[m_Certain_CurIndexPos];
	UGint			m_Certain_Max			;
	UGint			m_Certain_Min			;
	UGArray<UGint>* m_pCertain_CurKeyArray	;		//	��ǰ����е�Keys,m_pCertain_CurKeyArray = m_theTree.GetKeys(m_Certain_CurIndex);
	UGint			m_Certain_CurKeyPos		;
	UGArray<UGint> *m_pHoldArray			;
	UGint			m_Hold_CurIndex			;
	UGArray<UGint> *m_pHold_CurKeyArray		;
	UGint			m_Hold_CurKeyPos		;
	UGArray<UGint> *m_pMaybeArray			;
	UGint			m_Maybe_CurIndexPos		;
	UGint			m_Maybe_CurIndex		;
	UGint			m_Maybe_Max				;			
	UGint			m_Maybe_Min				;
	UGArray<UGint>* m_pMaybe_CurKeyArray	;
	UGint			m_Maybe_CurKeyPos		;
private:  
	
	UGRect2D		m_rc2Entire				;		//	�����ľ��εĴ�С
	UGQTree			m_theTree				;		//	�Ĳ���������Ķ���
};

}

#endif // !defined(SMQTREEMANAGER_H__BF7FEB36_1177_11D3_A5F0_0080C8EE6140__INCLUDED_)

