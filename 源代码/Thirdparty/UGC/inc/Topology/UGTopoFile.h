#ifndef UGTOPOFILE_H
#define UGTOPOFILE_H

#include "Base/UGStream.h"

namespace UGC {
	
class TOPOLOGY_API UGTopoFile
{
public:
	UGTopoFile();
	virtual ~UGTopoFile();
	
	virtual UGbool Open() = 0;
	
	//{{//////////////////////////////////////////////////////////////
	//dRecordSizeΪ�ļ���¼��С��dRecordsCountΪ��¼��
	//�ļ��ܳ���Ϊ(dRecordsCount * dRecordSize)
	virtual void Set(UGuint dwRecordSize, UGuint dwRecordsCount) = 0;
	//}}//////////////////////////////////////////////////////////////
	
	// lOff	Ϊ��¼��ƫ������nFrom ����CFile::Seek
	virtual UGint Seek(UGint lOff, UGuint nFrom = UGFromStart) = 0;
	
	//{{�˺������ı䵱ǰ�ļ�ָ���λ�õ��ļ���ʼ///////////////////
	//dwNewLenΪ��¼��
	virtual void SetLength(UGuint dwNewLen) = 0;
	//}}///////////////////////////////////////////////////////////
	//���ؼ�¼��
	virtual UGuint GetLength() const = 0;
	
	//nCountΪ��ȡ�ļ�¼��
	virtual void Read(void* lpBuf, UGuint nCount = 1) = 0;
	//nCountΪд��ļ�¼��
	virtual void Write(const void* lpBuf, UGuint nCount = 1) = 0;
	
	//nIndexΪ��¼�����ţ���0Ϊ��ʼ����nCountΪ��ȡ�ļ�¼��
	virtual void ReadAt(void* lpBuf, UGuint nIndex, UGuint nCount = 1) = 0;
	//nIndexΪ��¼�����ţ���0Ϊ��ʼ����nCountΪд��ļ�¼��
	virtual void WriteAt(const void* lpBuf, UGuint nIndex, UGuint nCount = 1) = 0;
	
	virtual void Flush() = 0;
	virtual void Close() = 0;
	
protected:
	UGuint m_dwRecordSize;
	UGuint m_dwRecordsCount;
	UGuint m_nCurrentIndex;
};

}

#endif
