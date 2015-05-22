// UGFileDisk.h: interface for the UGFileDisk class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEDISK_H__4F97CCA5_FFAB_4C66_AEED_9A8EA686FDDE__INCLUDED_)
#define AFX_UGFILEDISK_H__4F97CCA5_FFAB_4C66_AEED_9A8EA686FDDE__INCLUDED_

#include "Base/UGString.h"
#include "Base/UGFileStream.h"

namespace UGC{

class COMPOUNDFILE_API UGFileDisk  
{
public:
	UGFileDisk();
	~UGFileDisk();
protected:
	// modified by zengzm 2007-4-6 ��������ǰ��file��ʵ��, ��������Ǹ����ĵ���, Ҳ��Ҫ���ƽ̨,��FileStream����̫��
	// modified by zengzm 2007-3-26 ��UGFileStream��ʵ��
	int m_file;
	//UGFileStream m_file;

public:
	UGbool Open(const UGString& strName, UGStreamDirection nDirection);
	UGbool IsOpen() const;
	void Close();

	UGlong Seek(UGlong nOffset,UGWhence whence);
	UGlong GetPosition();
	UGlong GetLength();
	void SetLength(UGlong nLength);
	
	UGint Read(UGuchar* p,UGint nSize);
	void Write(UGuchar* p,UGint nSize);

	UGbool Flush();
};

}
#endif // !defined(AFX_UGFILEDISK_H__4F97CCA5_FFAB_4C66_AEED_9A8EA686FDDE__INCLUDED_)
