#ifndef UGTOPODISKFILE_H
#define UGTOPODISKFILE_H

#include "Base/UGFileStream.h"
#include "Topology/UGTopoFile.h"

namespace UGC {

class TOPOLOGY_API UGTopoDiskFile : public UGTopoFile  
{
	UGFileStream m_DiskFile;
public:
	UGTopoDiskFile();
	virtual ~UGTopoDiskFile();
	
	UGchar m_TmpPath[255];
	UGchar m_TempFileName[255];
	
	//! \brief������ʱ�ļ�
	UGbool Open();
	//{{//////////////////////////////////////////////////////////////
	//! \brief �����ļ���¼��С�ͼ�¼��
	//! \details �ļ��ܳ���Ϊ(dRecordsCount * dRecordSize)
	//! \param dRecordSize �ļ���¼��С
    //! \param dRecordsCount �ļ���¼��
	void Set(UGuint dwRecordSize, UGuint dwRecordsCount);
	//}}//////////////////////////////////////////////////////////////
	
	//! \brief ƫ��
	//! \param lOff ��¼��ƫ����
    //! \param nFrom ƫ�Ƶ���ʼλ��CFile::Seek
	UGint Seek(UGint lOff, UGuint nFrom = UGFromStart);
	
	//{{�˺������ı䵱ǰ�ļ�ָ���λ�õ��ļ���ʼ///////////////////
	//! \param dwNewLen ��¼��
	void SetLength(UGuint dwNewLen);
	//}}///////////////////////////////////////////////////////////
	//�� \brief ���ؼ�¼��
	UGuint GetLength() const;
	
	//! \param nCount ��ȡ�ļ�¼��
	void Read(void* lpBuf, UGuint nCount = 1);
	//! \param nCount д��ļ�¼��
	void Write(const void* lpBuf, UGuint nCount = 1);
	
	//! \param nIndex ��¼�����ţ��ԣ�Ϊ��ʼ��
    //! \param nCount ��ȡ�ļ�¼��
	void ReadAt(void* lpBuf, UGuint nIndex, UGuint nCount = 1);
	//! \param nIndex ��¼�����ţ��ԣ�Ϊ��ʼ��
    //! \param nCount д��ļ�¼��
	void WriteAt(const void* lpBuf, UGuint nIndex, UGuint nCount = 1);
	
	void * operator[](UGuint nIndex);
	void Flush();
	void Close();
};

}

#endif
