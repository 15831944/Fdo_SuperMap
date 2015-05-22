/* 
	\file UGStream.h
	\brief ��������࣬һ����Ϊ��ȡ�����������Ͳ���������ʵ������
	ʵ����ʱ���ڴ�������UGMemoryStream���ļ�������UGFileStream��
	����������ο�UGMemoryStream��UGFileStreamͷ�ļ���
	\author Fox����������־��
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
	\sa UGMemoryStream UGFileStream��
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

#ifndef UGSTREAM_H
#define UGSTREAM_H
#include "ugdefs.h"

namespace UGC {

//! \brief ���Ĳ���ģʽ
enum UGStreamDirection
{
	UGStreamDead=0,
	//! \brief ֻд
	UGStreamSave=1,
	//! \brief ֻ��
	UGStreamLoad=2,
	//! \brief ��д
	UGStreamLoadSave = 3  //add aiguo
};

//! \brief ����״̬
enum UGStreamStatus 
{
	//! \brief ״̬����
	UGStreamOK=0,
	//! \brief ��ȡʱ�ѵ�����β��
	UGStreamEnd=1,
	//! \brief д��ʱ���Ѿ�д��
	UGStreamFull=2,
	//! \brief ������д
	UGStreamNoWrite=3,
	//! \brief �����ɶ�
	UGStreamNoRead=4,
	//! \brief �ڴ�������
	UGStreamAlloc=5,
	//! \brief ���ڲ������ݸ�ʽ����
	UGStreamFormat=6,
	UGStreamFailure=7
};

//! \brief ��������λ�ã�SetPosition��ʱ����ʼλ�á�
enum UGWhence 
{
	//! \brief ��ʼ����
	UGFromStart=0,
	//! \brief ��ǰλ�á�
	UGFromCurrent=1,
	//! \brief ��β����
	UGFromEnd=2
};

//! \brief ��������࣬һ����Ϊ��ȡ�����������Ͳ���������ʵ������
/**
	\remarks ʵ����ʱ���ڴ�������UGMemoryStream���ļ�������UGFileStream��
*/
class BASE_API UGStream 
{
public:
	//! \brief Ĭ�Ϲ��캯����
	UGStream();	

	//! \brief ������������������Ϊ���麯������ΪUGStream������ʵ������
	virtual ~UGStream()=0;	
	
	//! \brief �ر�����
	virtual UGbool Close();
	
	//! \brief ����ˢ�£������ļ�����Ч�����ѻ����е�����д�뵽�ļ��С�
	virtual UGbool Flush();  	

	//! \brief �õ���ȫ���ռ�Ĵ�С���ļ���ʱ��ͬ���ڲ��������Ĵ�С��
	UGuint GetSpace() const;	

	//! \brief �������Ŀռ��С���ڴ���ʱֻ���ڿռ���������ʱʹ�ã��ļ���ʱ��ı仺������С��
	/** \param space ���õĿռ��Сֵ[in]��
		\attention ���ڴ��������ڴ�ռ䲻��������ʱ���ã��ᷢ��Assert����
	*/
	void SetSpace(UGuint space);  		

	//! \brief �õ���ǰ����״̬��
	UGStreamStatus GetStatus() const { return code; }  	

	//! \brief �ж����Ƿ��ѵ���β����Ҫ���ļ���ʹ��
	virtual UGbool IsEOF() const { return code!=UGStreamOK; }  

	//! \brief �������Ѿ�������ĳ�ִ���
	/** \param err ���õĴ�������[in]��
		\remarks һ�㲻��Ҫʹ�á�
	*/
	void SetError(UGStreamStatus err);  

	//! \brief �õ�����ֻ����ֻд���߶�д��
	UGStreamDirection GetDirection() const { return dir; }  	
	
	//! \brief �õ���ǰָ���λ�ã���byteΪ��λ��
	UGulong GetPosition() const { return pos; }  
	
	//! \brief ���õ�ǰָ���λ�á�
	/**
	���ļ��������Ҫ���õ�λ�ó���ԭ���ļ���С���ᵼ���ļ��������ӣ�
	���ڴ��������Ҫ���õ�λ�ó����ڴ�ռ��С�����ڴ��������У��ᵼ���ڴ�ռ����·��䣬
		�ڴ�ռ䲻Ϊ�����У������ᴦ��Full״̬
		\param offset ƫ����[in]��
		\param whence ƫ��������ʼλ��[in]��
	*/
	virtual UGbool SetPosition(UGlong offset,UGWhence whence=UGFromStart);	
	
	//{{ Add by aiguo
	//! \brief �����ļ������õ��ļ����ȣ������ڴ������õ�����ʵ����Ч���ݵĳ��ȣ�С�ڵ����ڴ�ռ䣩��
	virtual UGulong GetLength() { return m_lActualPos; };	
	//}}
	
	// deleted by zengzm 2006-3-9 �ı��Ƿ񽻻��ֽ�˳��Ķ���̫Σ�գ������ڲ��Լ��жϣ���ʱ���
	// void SwapBytes(UGbool s){ swap=s; }

	//! \brief �õ��Ƿ���Ҫ�����ֽ�˳��Ľ�����
	//! \remarks ���ǵ����ݶ�����LittleEndian��ʽ�洢����BigEndian��CPU����Ҫ�����ֽ�˳�򽻻���
	UGbool SwapBytes() const; 	
	
	UGStream& operator<<(const UGuchar& v);
	UGStream& operator<<(const UGchar& v){ return *this << reinterpret_cast<const UGuchar&>(v); }
	UGStream& operator<<(const UGushort& v);
	UGStream& operator<<(const UGshort& v){ return *this << reinterpret_cast<const UGushort&>(v); }
	UGStream& operator<<(const UGuint& v);
	UGStream& operator<<(const UGint& v){ return *this << reinterpret_cast<const UGuint&>(v); }
	UGStream& operator<<(const UGfloat& v){ return *this << reinterpret_cast<const UGuint&>(v); }
	UGStream& operator<<(const UGdouble& v);
#ifdef UG_LONG
	UGStream& operator<<(const UGlong& v){ return *this << reinterpret_cast<const UGdouble&>(v); }
	UGStream& operator<<(const UGulong& v){ return *this << reinterpret_cast<const UGdouble&>(v); }
#endif
	
	UGStream& Save(const UGuchar* p,UGuint n);
	UGStream& Save(const UGchar* p,UGuint n){ return Save(reinterpret_cast<const UGuchar*>(p),n); }
	UGStream& Save(const UGushort* p,UGuint n);
	UGStream& Save(const UGshort* p,UGuint n){ return Save(reinterpret_cast<const UGushort*>(p),n); }
	UGStream& Save(const UGuint* p,UGuint n);
	UGStream& Save(const UGint* p,UGuint n){ return Save(reinterpret_cast<const UGuint*>(p),n); }
	UGStream& Save(const UGfloat* p,UGuint n){ return Save(reinterpret_cast<const UGuint*>(p),n); }
	UGStream& Save(const UGdouble* p,UGuint n);
#ifdef UG_LONG
	UGStream& Save(const UGlong* p,UGuint n){ return Save(reinterpret_cast<const UGdouble*>(p),n); }
	UGStream& Save(const UGulong* p,UGuint n){ return Save(reinterpret_cast<const UGdouble*>(p),n); }
#endif
	
	UGStream& operator>>(UGuchar& v);
	UGStream& operator>>(UGchar& v){ return *this >> reinterpret_cast<UGuchar&>(v); }
	UGStream& operator>>(UGushort& v);
	UGStream& operator>>(UGshort& v){ return *this >> reinterpret_cast<UGushort&>(v); }
	UGStream& operator>>(UGuint& v);
	UGStream& operator>>(UGint& v){ return *this >> reinterpret_cast<UGuint&>(v); }
	UGStream& operator>>(UGfloat& v){ return *this >> reinterpret_cast<UGuint&>(v); }
	UGStream& operator>>(UGdouble& v);
#ifdef UG_LONG
	UGStream& operator>>(UGlong& v){ return *this >> reinterpret_cast<UGdouble&>(v); }
	UGStream& operator>>(UGulong& v){ return *this >> reinterpret_cast<UGdouble&>(v); }
#endif
	
	UGStream& Load(UGuchar* p,UGuint n);
	UGStream& Load(UGchar* p,UGuint n){ return Load(reinterpret_cast<UGuchar*>(p),n); }
	UGStream& Load(UGushort* p,UGuint n);
	UGStream& Load(UGshort* p,UGuint n){ return Load(reinterpret_cast<UGushort*>(p),n); }
	UGStream& Load(UGuint* p,UGuint n);
	UGStream& Load(UGint* p,UGuint n){ return Load(reinterpret_cast<UGuint*>(p),n); }
	UGStream& Load(UGfloat* p,UGuint n){ return Load(reinterpret_cast<UGuint*>(p),n); }
	UGStream& Load(UGdouble* p,UGuint n);
#ifdef UG_LONG
	UGStream& Load(UGlong* p,UGuint n){ return Load(reinterpret_cast<UGdouble*>(p),n); }
	UGStream& Load(UGulong* p,UGuint n){ return Load(reinterpret_cast<UGdouble*>(p),n); }
#endif

private:
	// modified by zengzm 2007-3-27 ��Ϊ��̬����,ֻ��Ҫ�ж�һ��,�������Ч��
	// static UGbool swap;
	// UGbool swap;
protected:
	UGuchar           *begptr;
	UGuchar           *endptr;
	UGuchar           *wrptr;
	UGuchar           *rdptr;
	// UGuint			 pos;
	UGulong			 pos;
	
	//�ļ���ʵ�ʳ���,��Ҫ�����ڴ��ļ���
	// modified by zengzm 2007-3-28 ��Ϊ�޷�����
	//UGlong m_lActualPos; //Add by aiguo
	UGulong m_lActualPos;
	
	UGStreamDirection  dir;
	UGStreamStatus     code;
	UGbool             owns;
	
	//Add by aiguo
	enum UGSignLoadSave 
	{
		UGSignStreamLoad =0,
		UGSignStreamSave =1
	};
	//{{//Add by aiguo,������UGStreamLoadSaveģʽ��Load��Save�ͱ�ʶ
	UGSignLoadSave     SignLoadSave; 
	//}}
private:
	UGStream(const UGStream&);
	UGStream &operator=(const UGStream&);
	
protected:
	// modified by zengzm 2007-3-9 ���������������ã����治ֱ��ʹ��
	UGbool Open(UGStreamDirection save_or_load, UGuint size=8192,  UGuchar* data=NULL);  	
	
	virtual UGuint WriteBuffer(UGuint count);
	virtual UGuint ReadBuffer(UGuint count);
	
	
	//{{Add by aiguo ��Ҫ�ǽ����UGStreamLoadSaveģʽ�£�Load��Save���ҵ����⣬������Ҫ������һЩ��־������Load��Save.
	virtual void SetSignLoadSave(UGint nSign);
	//}}
};


}

#endif


