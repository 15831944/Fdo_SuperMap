/*! \file UGBlockManager.h
 *  \brief �����͹�����.
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/   

#if !defined(AFX_SMSSBLOCKMANAGER_H__66F92503_D443_4EA0_926B_637F819C18D3__INCLUDED_)
#define AFX_SMSSBLOCKMANAGER_H__66F92503_D443_4EA0_926B_637F819C18D3__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "UGFileDisk.h"

namespace UGC{


///	\brief	UGBlockManager���ṩ�ļ���ķ��䣬����ͻ��չ��ܡ�
/// \remark	��Ĵ�С���Ը�������������ã�Ĭ����8k��
class UGBlockManager  
{
	friend class UGStorehouse;
public:
	///	\brief Ĭ�Ϲ��캯��
	UGBlockManager();
	///	\brief Ĭ����������
	virtual ~UGBlockManager();

private:
	///	\brief �������캯������ʵ��
	UGBlockManager(const UGBlockManager &src);
	///	\brief Ĭ�ϸ�ֵ��������ʵ�� 
	UGBlockManager &operator=(const UGBlockManager &src);

public:
	/// \brief ��������
	/// \param nBlockCount �������Ŀ���
	/// \param arBlockNums ��������Ŀ��ID����
	/// \return ����ɹ��򷵻�true,���򷵻�false.
	/// \remarks ����пտ�����ú���Ŀտ飬�տ鲻���͵��ļ�������
	UGbool AllocBlock( UGint nBlockCount, UGArray<UGint>& arBlockNums );

	/// \brief �ͷ�һ����
	/// \param nBlockID ��Ҫ�ͷŵĿ��ID
	/// \return �ɹ��򷵻�true,���򷵻�false
	/// \remarks �ͷſ鲢û���ͷ��ļ��ռ䣬�����´μ����������ʹ�á�
	UGbool FreeBlock( UGint nBlockID );	

public: //inline ����
	
	/// \brief ��ȡ����ռ�ڴ���ֽ���
	/// \return ����ռ�ڴ���ֽ���
	UGint GetSize();

	/// \brief ��ȡ�ļ���ָ��
	/// \return �ļ���ָ��
	/// \remarks �ⲿ����ɾ����ȡ������ָ��
	/// \remark inline����
	UGFileDisk *GetFile() const;

	/// \brief ��ȡ�ֿ���ֽ���
	/// \return �ֿ���ֽ���
	/// \remarks �ֿ���ֽ����ڴ����ļ���ʱ��ָ�����Ժ����޸ġ�
	/// \remark inline����
	UGint GetBlockSize() const;

	/// \brief ��ȡ�ֿ�����
	/// \return �ֿ�����
	/// \remarks �����Ѿ�ʹ�õĿ�ͿյĿ�
	/// \remark inline����
	UGint GetBlockCount() const;

protected: 
	/// \brief �ļ�ָ��
	UGFileDisk *m_pFile;

	/// \brief �տ��������
	UGArray<UGint> m_arFreeBlocks;

	/// \brief �ܿ���,�����Ѿ�ʹ�õĿ�ͿյĿ顣	
	UGint m_nBlocksCount;

	/// \brief ��Ĵ�С
	UGint m_nBlockSize;
};


inline UGFileDisk *UGBlockManager::GetFile() const
{
	return m_pFile;
}

inline UGint UGBlockManager::GetBlockCount() const
{
	return m_nBlocksCount;
}

inline UGint UGBlockManager::GetBlockSize() const 
{
	return m_nBlockSize;
}

}

#endif // !defined(AFX_SMBLOCKMANAGER_H__66F92503_D443_4EA0_926B_637F819C18D3__INCLUDED_)
