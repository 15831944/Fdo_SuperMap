//=====================================================================================
// ��Ŀ����			SuperMap Foundation Class (SFC) Library 2.0
// ��  �ߣ�			���ǣ��ιظ�
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSuperMap GIS����������Ա��δ����ɲ������Դ�����
//					2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����			SmQTree.h
// ��  ����			UGQTree
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		�����������Ĳ�������:���������ӽڵ㣬ɾ���ڵ�,������ 
// ����˵����		���ֻ֧��15���Ĳ���
//=====================================================================================
/* �޸�˵����
 *		2007.09.21	guohui	Ϊ��ͷ�ļ����ע��
 */
#if !defined(SMQTREE_H)
#define SMQTREE_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Base/UGMemoryStream.h"

namespace UGC{

class ALGORITHM_API UGQTree  
{
public:
	UGQTree();
	~UGQTree();
public: //method

	//! \brief 		����һ��nSep����Ĳ���
	//! \return 	UGbool
	//! \param 		nSep	�Ĳ�������	
	//! \remarks 	nSep��������[0,MAX_LAYER].������0��ʼ
	UGbool Create(UGint nSep);

	//! \brief 		ɾ��������
	//! \return 	void
	//! \remarks 	
	void Delete();				

	//! \brief		��R�����ݱ��浽�ڴ������С�
	//! \param		arData ��������R�������顣
	//! \return		UGbool 
	//! \remarks 	�ɹ��򷵻�TRUE��
	UGbool Store(UGMemoryStream& arData);

	//! \brief		���ڴ�����������R�����ݲ�����R����
	//! \param		arData R�����ݡ�
	//! \return		UGbool 
	//! \remarks 	�ɹ��򷵻�TRUE��
	UGbool Load(UGMemoryStream &arData,UGint& nPos);

	//! \brief		�ڽڵ�������һ����ֵ
	//! \param		Index �ڵ�������
	//! \param		key	  ��ֵ
	//! \return		UGbool 
	//! \remarks 	�ɹ��򷵻�TRUE��
	UGbool Add(UGint Index,UGuint Key);

	//! \brief		ɾ��һ���ڵ�
	//! \param		Index �ڵ�������
	//! \return		void
	void Delete (UGint Index);

	//! \brief		ɾ��һ���ڵ��ϵļ�ֵ
	//! \param		Index �ڵ�������
	//! \param		key	  ��ֵ
	//! \return		void
	void Delete(UGint Index,UGuint Key);
	
	//! \brief		�������ֵ�Ƿ�Ϸ�
	//! \param		Index �ڵ�������
	//! \return		UGbool 
	//! \remarks 	�ɹ��򷵻�TRUE��
	UGbool Check(UGint &Index);

	//! \brief		����������Ӧ�����µ�������С����ֵ
	//! \param		Index �ڵ�������
	//! \param		Min	  ��Сֵ
	//! \param		Max   ���ֵ
	//! \return		void
	void GetIndexBound(UGint Index,UGint &Min,UGint &Max);

	//! \brief		ȡ�ýڵ��ϵ����м�ֵ
	//! \param		Index �ڵ�������
	//! \return		UGArray<UGint>*
	//! \remarks 	����ָ�룬���治Ҫ�ͷ�(delete)��
	UGArray<UGint>* GetKeys(UGint Index);
	
	//! \brief		ȡ�ýڵ��ϵ����м�ֵ
	//! \param		Index �ڵ�������
	//! \return		void
	void GetKeys(UGint Index,UGArray<UGint> &Keys);

	//! \brief		����ת������ֵ
	//! \param		pArray ����
	//! \return		UGbool
	UGbool Convert(UGArray<UGint> *pArray);
	
public:	//properties

	//! \brief		��ȡ��С
	//! \return		UGint
	UGint GetDataSize();

	//! \brief		�Ƿ�Ϊ��
	//! \return		UGbool
	UGbool IsEmpty();		

	//! \brief		���
	//! \return		UGint
	UGint GetDeepth() const;

	//! \brief		��ֵ��Ŀ
	//! \return		UGint
	UGint GetKeyCount() const;

	//! \brief		�ڵ���Ŀ
	//! \return		UGint
	UGint GetIndexNumber();	

protected:
	UGint m_nKeyCount;
	UGint m_nMaxLayer;	
	UGArray<UGint>** m_pNodeData;
private:

	//! \brief		�ҵ����ڵ�
	//! \return		UGint
	UGint GetParent(UGint Index);

	//! \brief		��ȡ���м�ֵ
	//! \return		void
	void GetAllKeys(UGint Index,UGArray<UGint> &Keys,UGbool bLink);

	//! \brief		ת��15��
	//! \return		void
	UGbool Convert(UGint Index,UGint& ConvertedIndex);
};

}
#endif // !defined(SMQTREE_H__76970517_17D9_11D3_A60D_0080C8EE6140__INCLUDED_)
