/* 	\file UGFileStream.h
	\brief �ļ�����
	\author Fox����������־��
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
	\sa UGStream UGMemoryStream��
*/

/*	�޸ļ�¼ 1
	�޸��ˣ���־��
	�޸�ԭ�����ӶԳ���4G�����Ĺ���
	�����޸ģ���Position��int32��Ϊint64
	�޸�ʱ�䣺2004-7-12

   �޸ļ�¼ 2
	�޸��ˣ�  ����
	�޸�ԭ�����Ӷ��ļ���˫��Ĳ�����Ҳ������һЩ�ӿڣ��޸���ԭ��һЩbug��ͬʱ���������ܵ��Ż�
	�����޸ģ����忴ͷ�ļ���ע��
	����޸�ʱ�䣺2005-6-17
*/

#ifndef UGFILESTREAM_H
#define UGFILESTREAM_H
#include "UGStream.h"

namespace UGC {

//! \brief �ļ�����
/**	�����UGStreamSaveģʽ���ļ�ʱ��ֻ�����ļ��б������ݣ��������ļ��ж�ȡ���ݣ�
�����UGStreamLoadģʽ���ļ�ʱ��ֻ�ܶ�ȡ�ļ���ֻ����UGStreamLoadSaveģʽ���ļ������Զ�Ҳ����д��
��1������ֻдģʽ��
 UGFileStream fileStream;
 UGString strFileName  = "D:/Data/file/fileStreamLoad.txt";
 UGchar pch[10];
 for( i = 0; i < 10; i++)
 {
  pch[i] = 'a' + i;
 }
 if (fileStream.Open(strFileName, UGStreamSave)) //����ļ����ڣ��ļ�������ݽ���ʧ
 {
  fileStream.Save(pch, 10);//��ȷ
  fileStream.SetPosition(5, UGFromStart);
  fileStream.Load(pch, 4); //�����ͻ��������
  fileStream.Close();
 }
��2������ֻдģʽ��
 UGFileStream fileStream;
 UGString strFileName  = "D:/Data/file/fileStreamLoad.txt";
 UGchar pch[10];
 for( i = 0; i < 10; i++)
 {
  pch[i] = 'a' + i;
 }
 if (fileStream.Open(strFileName, UGStreamLoad)) 
 {
  fileStream.Load(pch, 10);//��ȷ
  fileStream.Save(pch, 4); //�������ﲻ�ܰѴ�����д���ļ���
  fileStream.Close();
 }
��3�����ö�дģʽ��
 UGFileStream fileStream;
 UGString strFileName  = "D:/Data/file/fileStreamLoad.txt";
 UGchar pch[10];
 for( i = 0; i < 10; i++)
 {
  pch[i] = 'a' + i;
 }
 if (fileStream.Open(strFileName, UGStreamLoadSave))
 {
  fileStream.Save(pch, 10); //��pch�е����ݱ������ļ�����ԭ���ļ����ڣ������ļ��������ݣ����޸�ԭ��������
  fileStream.SetPosition(0, UGFromStart);
  fileStream.Load(pch, 10);//��ȷ
  fileStream.Close();
 }
*/
class BASE_API UGFileStream : public UGStream  
{
public:	
	UGFileStream();
	virtual ~UGFileStream();	
	
	//! \brief ���ļ�����
	/** \param filename ָ���ļ���[in]��
		\param save_or_load ָ���򿪵ķ�ʽ��ֻ����ֻд���д[in]��
		\param size ����Ĵ�С[in]��
	*/
	UGbool Open(const UGchar* filename, UGStreamDirection save_or_load, UGuint size=8192);			

	//! \brief �ر��ļ�����
	virtual UGbool Close();
	
	//! \brief �����ļ�ָ���λ�ã���������ļ���С���ᵼ���ļ�������
	/** \param offset ƫ����[in]��
		\param whence ��ʼλ��[in]��
	*/
	virtual UGbool SetPosition(UGlong offset,UGWhence whence=UGFromStart);	
	
	//! \brief �õ��ļ����� add by aiguo
	virtual UGulong GetLength();

	// added by zengzm 2005-09-09
	//! \brief �ж��Ƿ��ѵ��ļ�β
	virtual UGbool IsEOF() const;


	//! \brief �ж��ļ����Ƿ��ڴ�״̬��
	/** \return ��״̬����true,�ر�״̬����false��
	*/
	UGbool IsOpen() const;

	/// Save single items to stream
	UGFileStream& operator<<(const UGuchar& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGchar& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGushort& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGshort& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGuint& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGint& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGfloat& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGdouble& v){ UGStream::operator<<(v); return *this; }
#ifdef UG_LONG
	UGFileStream& operator<<(const UGlong& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGulong& v){ UGStream::operator<<(v); return *this; }
#endif
	
	/// Save arrays of items to stream
	UGFileStream& Save(const UGuchar* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGchar* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGushort* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGshort* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGuint* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGint* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGfloat* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGdouble* p,UGuint n){ UGStream::Save(p,n); return *this; }
#ifdef UG_LONG
	UGFileStream& Save(const UGlong* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGulong* p,UGuint n){ UGStream::Save(p,n); return *this; }
#endif
	
	/// Load single items from stream
	UGFileStream& operator>>(UGuchar& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGchar& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGushort& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGshort& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGuint& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGint& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGfloat& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGdouble& v){ UGStream::operator>>(v); return *this; }
#ifdef UG_LONG
	UGFileStream& operator>>(UGlong& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGulong& v){ UGStream::operator>>(v); return *this; }
#endif
	
	/// Load arrays of items from stream
	UGFileStream& Load(UGuchar* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGchar* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGushort* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGshort* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGuint* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGint* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGfloat* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGdouble* p,UGuint n){ UGStream::Load(p,n); return *this; }
#ifdef UG_LONG
	UGFileStream& Load(UGlong* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGulong* p,UGuint n){ UGStream::Load(p,n); return *this; }
#endif

private:
	UGint file;
protected:
	virtual UGuint WriteBuffer(UGuint count);
	virtual UGuint ReadBuffer(UGuint count);
	//{{Add by aiguo ��Ҫ�ǽ����UGStreamLoadSaveģʽ�£�Load��Save���ҵ����⣬������Ҫ������һЩ��־������Load��Save.
	virtual void SetSignLoadSave(UGint nSign);
	//}}
};

}

#endif

