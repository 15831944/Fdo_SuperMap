/* 
	\file UGMemoryStream.h
	\brief �ڴ�����
	\author Fox����������־��
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
	\sa UGStream UGFileStream��
*/

/*	�޸ļ�¼ 1
	�޸��ˣ���־��
	�޸�ԭ�����ӶԳ���4G�����Ĺ���
	�����޸ģ���Position��int32��Ϊint64
	�޸�ʱ�䣺2004-7-12

    �޸ļ�¼ 2
	�޸��ˣ�  ����
	�޸�ԭ�����Ӷ�����˫��Ĳ�����Ҳ������һЩ�ӿڣ��޸���ԭ��һЩbug��ͬʱ���������ܵ��Ż�
	�����޸ģ����忴ͷ�ļ���ע��
	����޸�ʱ�䣺2005-6-17

*/

#ifndef UGMEMORYSTREAM_H
#define UGMEMORYSTREAM_H
#include "UGStream.h"

namespace UGC {

//! \brief �ڴ���
/**	\remarks ʹ�÷�����
1����������ڴ棬���ڴ�������������ڴ棬���磺
 {
  UGint i = 0;
  UGuchar pch[20];
  UGuchar pch2[20];
  for(i = 0; i < 20; i++)
  {
   pch2[i] = 'z' -i; 
  }
  UGMemoryStream memStream;
  if (memStream.Open(UGStreamSave, 20, pch))
  {
   memStream.Save(pch2, 20);
   nPos =  memStream.GetPosition();
   memStream.Close();
  }
 }

2�����ڲ������ڴ棬����ڴ��������ݵ����Ӷ����ӣ����磺
 {
  UGint i = 0;
  UGuchar pch[20];
  for(i = 0; i < 20; i++)
  {
   pch[i] = 'z' -i; 
  }
  UGMemoryStream memStream;
  if (memStream.Open(UGStreamSave, NULL))
  {
   memStream.SetSpace(20); //���û���Ĵ�С
   memStream.Save(pch, 20);   
   memStream.Close();
  }
 }

 2���ö�д��ʽ�����ڴ��������磺
 UGMemoryStream stream;
 stream.Open(UGStreamLoadSave);
 UGString str = "abc";
  stream << str;
 stream.SetPosition(0);
 UGString str2;
 stream >> str2;
 assert(str1 == str2);
*/
class BASE_API UGMemoryStream : public UGStream 
{
private:
	// added by zengzm 20087-4-26 �������, ��ʵ��, ���ⲻ��ʹ��
	UGMemoryStream(const UGMemoryStream& ms);
	UGMemoryStream& operator=(const UGMemoryStream& ms);

public:	
	UGMemoryStream();		

	//{{����������ӿ� by aiguo
	//UGbool Open(UGStreamDirection save_or_load,UGuchar* data);	
	//UGbool Open(UGStreamDirection save_or_load, UGuint size, UGuchar* data);
	//}}����������ӿ� by aiguo

	//========================================================
	//! \brief 		���ڴ���������ָ��ÿ�η���buffer��size��Ҳ�����û�����һ���ڴ�
	//! \return 	UGbool    ��ȷ����True�����󷵻�False
	//! \param 		save_or_load �򿪵�ģʽ������֧������ģʽ��only save, only load and saveOrload
	//! \param 		size  ����buffer��С�������������ܺ���Ҫ���ڴ����Ĵ�Сÿ����size����
	//! \param 		data  �������Ҳ����Ҫ���û��������洫����һ���ڴ棬���ڴ�������������ڴ棬
	//                         ����û�������һ���ڴ棬��ô��Ҫ��sizeЭͬ������size�������洫�����Ĵ�С
	//! \remarks 	���ڴ���������ָ��ÿ��buffer������size��Ҳ�����û�����һ���ڴ�
	UGbool Open(UGStreamDirection save_or_load, UGuint size=1024, UGuchar* data=NULL);	


	//========================================================
	//! \brief 		�õ��ڴ�����ָ��data������buffer�ĳ���
	//              ͬʱҪ����·�˵���:Take�����ڴ�������븺���ͷ�,������ڴ�й¶
	//! \return 	void  û�з���ֵ
	//! \param 		data  �����ڴ���������ָ��
	//! \param 		size  ��������buffer��size(������Ҫע��:������buffer�Ĵ�С,����ʵ�����ݵĳ���)
	//					  ʵ�����ݳ��ȿɵ���GetLength�õ���
	//					  �����Saveģʽ�������Ե���GetPosition������Ѿ��洢�����ݵĴ�С
	//! \remarks 	�õ��ڴ�����ָ��data������buffer�ĳ���	
	void TakeBuffer(UGuchar*& data,UGuint& size);	


	//========================================================
	//! \brief 		������ڴ���һ���ڴ棬��ʱ�ڴ����� ��ԭ���ڴ����е������ͷ�
	//! \return 	void
	//! \param 		*data  ���������һ���ڴ治��Ϊ��
	//! \param 		size   ��������ڴ�Ĵ�С��
	//! \remarks 	Ҫע����ǣ���������ڴ潻�����ڴ������ڴ����͸���Ϊά��������Ȼ�����ͷ��ˣ�����
	//              ��ô��ͻ��ʣ����������һ���ջ�еĶ�������ô��������������𣿣�����
	//              ������ʣ�����ô�죬û�а취���𣿣���
	//              �Ǻǣ��취���еģ� �ó������������TakeBuffer�ˣ�������ڴ潻�������������������Ϳ����ˣ���������ð�������
	void GiveBuffer(UGuchar *data,UGuint size);	


	//========================================================
	//! \brief 		�ر���
	//! \return 	UGbool �ɹ�����True,ʧ�ܷ���False
	virtual UGbool Close();	


	//========================================================
	//! \brief 		���õ�ǰָ���λ�á�
	/** \remark		���Ҫ���õ�λ�ó����ڴ�ռ��С�����ڴ��������У��ᵼ���ڴ�ռ����·��䣬
		�ڴ�ռ䲻Ϊ�����У������ᴦ��Full״̬
		\param offset ƫ����[in]��
		\param whence ƫ��������ʼλ��[in]��
	*/
	virtual UGbool SetPosition(UGlong offset,UGWhence whence=UGFromStart);


	//========================================================
	//! \brief 		�õ�����ʵ����Ч���ݵĳ��ȣ�С�ڵ����ڴ�ռ䣩 add by aiguo
	virtual UGulong GetLength();


	//========================================================
	//! \brief 		�õ��ڴ����е�����ָ��, ���·��Ҫע�����: ��������ô�����,����ͨ��GetLength���õ����ݵĳ��� 
	//              ���治��Ҫ�ͷ�, ���ر������Զ��ͷ�����ڴ�
	//! \return 	UGuchar*  �����ڴ������׵�ַ
	//! \remarks 	�õ��ڴ����е�����ָ��,���ʵ�����ݳ���Ϊ0, ����NULLָ��	
	virtual UGuchar* GetData() const;
		
	UGMemoryStream& operator<<(const UGuchar& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGchar& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGushort& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGshort& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGuint& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGint& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGfloat& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGdouble& v){ UGStream::operator<<(v);  return *this; }
#ifdef UG_LONG
	UGMemoryStream& operator<<(const UGlong& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGulong& v){ UGStream::operator<<(v);  return *this; }
#endif
	
	/// Save arrays of items to stream
	UGMemoryStream& Save(const UGuchar* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGchar* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGushort* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGshort* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGuint* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGint* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGfloat* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGdouble* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
#ifdef UG_LONG
	UGMemoryStream& Save(const UGlong* p,UGuint n){ UGStream::Save(p,n);  return *this; }
	UGMemoryStream& Save(const UGulong* p,UGuint n){ UGStream::Save(p,n);  return *this; }
#endif
	
	/// Load single items from stream
	UGMemoryStream& operator>>(UGuchar& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGchar& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGushort& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGshort& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGuint& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGint& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGfloat& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGdouble& v){ UGStream::operator>>(v); return *this; }
#ifdef UG_LONG
	UGMemoryStream& operator>>(UGlong& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGulong& v){ UGStream::operator>>(v); return *this; }
#endif
	
	/// Load arrays of items from stream
	UGMemoryStream& Load(UGuchar* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGchar* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGushort* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGshort* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGuint* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGint* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGfloat* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGdouble* p,UGuint n){ UGStream::Load(p,n); return *this; }
#ifdef UG_LONG
	UGMemoryStream& Load(UGlong* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGulong* p,UGuint n){ UGStream::Load(p,n); return *this; }
#endif
	
protected:
	virtual UGuint WriteBuffer(UGuint count);
	virtual UGuint ReadBuffer(UGuint count);
	
	//{{Add by aiguo ��Ҫ�ǽ����UGStreamLoadSaveģʽ�£�Load��Save���ҵ����⣬������Ҫ������һЩ��־������Load��Save.
	virtual void SetSignLoadSave(UGint nSign);
	//}}

	//{{add by aiguo Ϊ�����Ч�����ӵı����� ԭ��ʵ�ֵ�Ч��̫����ԭ���ǣ�
	//���д����ֽڳ��ȴ��ڵ�ǰ��bufferʱ�����·���Ĵ�С��ԭ���Ĵ�С���ϵ�ǰҪд��Ĵ�С������Ч�ʾͱȽϵ�
	//��һ�����˵����ӣ����ÿ��дһ���ֽڽ�ȥ����ôÿ�ζ���Ҫ���·���ռ䣬����������ģ�����foxҲ������ˣ��Ǻǣ�
	UGint m_nBufferSize;
	//}}Ϊ�����Ч�����ӵı����� ԭ��ʵ�ֵ�Ч��̫��
};

}

#endif

