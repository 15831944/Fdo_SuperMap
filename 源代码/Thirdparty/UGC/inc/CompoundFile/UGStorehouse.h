/*! \file UGStorehouse.h
 *  \brief SuperMap Structure Storage �����ĵ���
 *  \author ���䳬,�¿���
 *  \bug

 *	<b>����˵����</b>\n
	<em>1��2003-11-1 �״���ɴ����д.\n</em>
*/ 
#if !defined(AFX_SMSSSTOREHOUSE_H__813097E5_AA81_4CF3_991C_4BCA52D7800F__INCLUDED_)
#define AFX_SMSSSTOREHOUSE_H__813097E5_AA81_4CF3_991C_4BCA52D7800F__INCLUDED_

#include "UGBlockManager.h"
#include "UGFolder.h"


namespace UGC{

/// \brief �ļ���ʶ��"SMSS"
const UGuint STORE_HOUSE_FLAG =	0x83778383;  

/// \brief �ļ��汾��,2003-10-20
const UGuint STORE_HOUSE_VERSION = 20031020;  

/// \brief �����ĵ��࣬�ṩ�������򿪣�����ȹ��ܡ�
/// \remark SuperMap Structure Storage (SSS)����������һ����ͨ���ļ���ʵ��
/// \remarks �����Ŀ¼�ṹ��һ��Ŀ¼�¿��Ծ��ж����Ŀ¼�����ļ�
class COMPOUNDFILE_API UGStorehouse 
{
public:	
	UGStorehouse();
	~UGStorehouse();
	static const UGuint m_FileHeaderSize; //8192
public:
	UGbool Create(const UGString& strName,UGint nBlockSize=8192);

	UGbool Open(const UGString& strName,UGStreamDirection nFlag);

	void Close(UGbool bAutoSave=true);

	UGbool Save();

	UGbool IsOpen() const;	

	UGFolder *GetRootFolder();
	const UGFileDisk* GetFile() const;

protected:
	UGBlockManager m_BlockManager;

	//��Ŀ¼
	UGFolder m_RootFolder;

	//��Ϣ�ļ�����
	//����������ļ����ļ��е���Ϣ������������
	UGFileLogical m_InfoFile;

private:
	UGFileDisk* m_pFile;
	
	UGuint m_nOpenFlag;
};

}
#endif // !defined(AFX_SMSTOREHOUSE_H__813097E5_AA81_4CF3_991C_4BCA52D7800F__INCLUDED_)
