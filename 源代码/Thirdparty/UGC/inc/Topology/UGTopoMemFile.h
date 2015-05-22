#ifndef TOPOMEMFILE_H
#define TOPOMEMFILE_H

#include "Base/UGMemoryStream.h"
#include "Topology/UGTopoFile.h"

namespace UGC {

class TOPOLOGY_API UGTopoMemFile : public UGTopoFile
{
	//UGMemoryStream m_MemFile;
	UGMemoryStream m_loadFile;
	UGMemoryStream m_saveFile;
	UGuchar * m_pBuffer;
public:
	UGTopoMemFile();
	virtual ~UGTopoMemFile();
	
	UGbool Open();

	//{{//////////////////////////////////////////////////////////////
	//dRecordSizeΪ�ļ���¼��С��dRecordsCountΪ��¼��
	//�ļ��ܳ���Ϊ(dRecordsCount * dRecordSize)
	void Set(UGuint dwRecordSize, UGuint dwRecordsCount);
	//}}//////////////////////////////////////////////////////////////

	// lOff	Ϊ��¼��ƫ������nFrom ����CFile::Seek
	UGint Seek(UGint lOff, UGuint nFrom = UGFromStart);

	//{{�˺������ı䵱ǰ�ļ�ָ���λ�õ��ļ���ʼ///////////////////
	//dwNewLenΪ��¼��
	void SetLength(UGuint dwNewLen);
	//}}///////////////////////////////////////////////////////////
	//���ؼ�¼��
	UGuint GetLength() const;
	
	//nCountΪ��ȡ�ļ�¼��
	void Read(void* lpBuf, UGuint nCount = 1);
	//nCountΪд��ļ�¼��
	void Write(const void* lpBuf, UGuint nCount = 1);

	//nIndexΪ��¼�����ţ��ԣ�Ϊ��ʼ����nCountΪ��ȡ�ļ�¼��
	void ReadAt(void* lpBuf, UGuint nIndex, UGuint nCount = 1);
	//nIndexΪ��¼�����ţ��ԣ�Ϊ��ʼ����nCountΪд��ļ�¼��
	void WriteAt(const void* lpBuf, UGuint nIndex, UGuint nCount = 1);

	void Flush();
	void Close();
};

}

#endif
