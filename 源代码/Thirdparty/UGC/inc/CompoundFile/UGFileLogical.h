/*============================================================
 ��Ŀ����                   eSuperMap 2.0
 ��  λ��                   ������ͼ������Ϣ�������޹�˾
 ����޸�ʱ�䣺				���ļ�����Ϊ׼
-------------------------------------------------------------------------------------
 ��Ҫ������                1. ���ʹ�÷�ΧΪeSuperMap GIS����������Ա��δ����ɲ������Դ�����
                           2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
-------------------------------------------------------------------------------------
 �ļ�����                   SeFile.h SeFile.cpp
 ��  ����                   UGFileLogical
 ��  �ࣺ                   ��
 ��  �ࣺ                   ��
 ����˵����                 pmf�߼��ļ���
 ����˵����                 
 ע�⣺                  
============================================================*/

#if !defined(AFX_SMSSFile_H__381A7817_0336_4A9F_8F9E_A36ADFDED596__INCLUDED_)
#define AFX_SMSSFile_H__381A7817_0336_4A9F_8F9E_A36ADFDED596__INCLUDED_

#include "Base/UGString.h"
#include "Base/UGArray.h"

namespace UGC {

const UGchar T_FOLDER = 0x01;
const UGchar T_FILE = 0x10;

class UGBlockManager;
class UGFolder;

// modified by zengzm 2007-4-7 UGFile��Base��UGFile ����, ��˻�һ������
//class COMPOUNDFILE_API UGFile
class COMPOUNDFILE_API UGFileLogical
{
	friend class UGStorehouse;
public:
	UGFileLogical();
	~UGFileLogical();

private:
	UGFileLogical(const UGFileLogical& src);	
	UGFileLogical& operator =(const UGFileLogical &src);
	void ApplyBlock( UGint nCount = 1 );

public:
	
	void Destroy();
	
	void WriteInfo(UGFileLogical *pInfoFile , UGint nVersion);
	
	void ReadInfo(UGFileLogical *pInfoFile ,  UGint nVersion);

	//�򿪱����˿���Ϣ���ļ�
	UGbool Open( const UGString& strFileName, const UGFolder* pFolder);

	UGuint Read( void* lpBuf, UGuint nCount );
	
	void Write( const void* lpBuf, UGuint nCount );

	//��ȡ�������(����һ��block size)
	

	//���ڴ����޸ĵ����ݱ��浽�ļ�
	void Flush();
	
	void Close();
	
	UGuint SeekToEnd();
	
	void SeekToBegin();

	UGuint Seek( UGint lOff, UGuint nFrom );
	
	UGuint GetLength() const;

	void SetLength( UGuint dwNewLen );
	
	void SetFileName( const UGString& strNewName );
	
	UGString GetFileName() const;
	
	UGuint GetPosition() const;	
	
	UGbool IsOpen();

	void SetBlockManager( UGBlockManager* pBlockManager );

	UGint GetSize() const;

public://static functions

	//size �����ַ���ռ�ֽ�����
	static UGbool ReadString(UGFileLogical *pFile,UGString & strInfo);

	//��д���ַ���ռ�ֽ���
	static UGbool WriteString(UGFileLogical *pFile,UGString & strInfo);

protected:	
	//�ļ�������������Ϣ�ļ���
	UGString m_strName;
		
	//�ļ�ָ���λ��
	UGint m_nPosition;

	//�ļ��Ĵ�С
	UGint m_nLength;

	//���һ�����ݿ�ʣ��ռ�
	UGint m_nLastBlank;

	//�Ƿ�򿪵ı�־
	UGbool m_bOpen;

	//������---------------------------------------------
	UGuchar *m_pDataBuffer;

	//���ڶ�ȡ�Ŀ������
	UGint m_nCachedBlockIndex;

	//�ļ�ռ�ÿ����Ϣ����������Ϣ�ļ���
	UGArray<UGint> m_arBlocks;
	
	//���������ָ��
	UGBlockManager* m_pBlockManager;
};

inline UGuint UGFileLogical::GetPosition() const
{
	return m_nPosition;
}

inline UGString UGFileLogical::GetFileName() const
{
	return m_strName;
}
	
inline UGuint UGFileLogical::SeekToEnd()
{
	m_nPosition = m_nLength;
	return m_nPosition;
}

inline void UGFileLogical::SeekToBegin()
{
	m_nPosition = 0;
}

inline UGuint UGFileLogical::GetLength() const
{
	return m_nLength;
}

inline void UGFileLogical::SetBlockManager(UGBlockManager* pBlockManager)
{
	m_pBlockManager = pBlockManager;
}

}
#endif // !defined(AFX_SeFile_H__381A7817_0336_4A9F_8F9E_A36ADFDED596__INCLUDED_)
