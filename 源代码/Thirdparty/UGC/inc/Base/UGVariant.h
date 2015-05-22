/*! \file	 UGVariant.h
 *  \brief	 ������Ķ���
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGVariant.h,v 1.7 2007/11/19 09:59:18 pengliang Exp $
 */


#ifndef UGVARIANT_H
#define UGVARIANT_H

#include "ugdefs.h"
#include "UGString.h"
#include "UGTime.h"
#include "UGStream.h"

namespace UGC {

class BASE_API UGVariant  
{
public:
	//! ֧�ֵ�����
	enum VarType
	{ 
		Null			=	0, //! δ���������
		Byte			=	1, //! ���ֽ�����
		Short			=	2, //! ˫�ֽ���������
		Integer			=	3, //! ���ֽ���������
		Long			=	4, //! ���ֽ���������
		Float			=	5, //! ���ֽڸ�������
		Double			=	6, //! ���ֽڸ�������
		Time			=	7, //! ʱ������
		Binary			=	8, //! ����������
		String			=   9  //! �ַ���
	};

	//! ��������
	union VarValue
	{
		UGuchar bVal;
		UGshort sVal;
		UGint	iVal;
		UGlong  lVal;
		UGfloat fVal;
		UGdouble dVal;
		double   tVal; // UGTime���ڲ�ʵ��
		void* pVal;	//�洢UGString��UGMemeroyStream��ָ��
	};
	
public:
	//! Ĭ�Ϲ��캯��
	UGVariant();

	//! ��������
	~UGVariant();

	//! �������캯��
	UGVariant(const UGVariant& varSrc);

	//! �������캯��
	UGVariant(UGuchar bVal);
	UGVariant(UGshort sVal);
	UGVariant(UGint iVal);
	UGVariant(UGlong lVal);
	UGVariant(UGfloat fVal);
	UGVariant(UGdouble dVal);	
	UGVariant(const UGTime& tVal);
	UGVariant(const UGuchar* pData,UGint nSize);	
	UGVariant(const UGString& string);	
	
	//! ��ֵ������
	const UGVariant& operator=(const UGVariant& varSrc);
	const UGVariant& operator=(UGuchar bVal);
	const UGVariant& operator=(UGshort sVal);
	const UGVariant& operator=(UGint iVal);
	const UGVariant& operator=(UGlong lVal);
	const UGVariant& operator=(UGfloat fVal);
	const UGVariant& operator=(UGdouble dVal);
	const UGVariant& operator=(const UGTime& tVal);	
	const UGVariant& operator=(const UGString& string);

	//! ���ñ���ֵ
	void Set(UGuchar bVal);
	void Set(UGshort sVal);
	void Set(UGint iVal);
	void Set(UGlong lVal);
	void Set(UGfloat fVal);
	void Set(UGdouble dVal);	
	void Set(const UGTime& tVal);
	void Set(const UGuchar* pData,UGint nSize);	
	void Set(const UGString& string);	
	
	//! �ж��Ƿ���Ȼ򲻵�
	//! ���Ͳ����, ����Ϊ�����(COleVariant�Ĵ���ʽ)
	UGbool operator==(const UGVariant& varSrc) const;
	UGbool operator!=(const UGVariant& varSrc) const;
	UGbool operator<(const UGVariant& varSrc) const;

	//! ���
	void Clear();	

	//! ��ȡ��������
	VarType GetType() const {
		return m_nType;
	}

	//! ��ȡ����ֵ
	VarValue& GetValue() {
		return m_value;
	}

	const VarValue& GetValue() const {
		return m_value;
	}

	// Ӧ���Ҫ��, ����ת��Ϊdouble int ��UGString ����
	//! ת��Ϊdouble����
	UGdouble ToDouble() const;
	//! ת��Ϊint32 ����
	UGint ToInt() const;
	//! ת��Ϊint64 ����
	UGlong ToLong() const;
	//! ת��ΪString����
	UGString ToString() const;
	

private:
	
	//! ����Ϊ��
	void SetNull();
	
	//! ��������
	VarType m_nType;
	
	//! ����ֵ
	VarValue m_value;	
};

}

#endif


