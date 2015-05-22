/**  \file UGFraction.h
   \brief ʵ��һ��������Ĺ���
   \author lugw
   \attention 
   Copyright(c) 1996-2007 SuperMap GIS Technologies, Inc.<br>
   All Rights Reserved.
 */ 

#if !defined(AFX_UGFRACTION_H__E201903D_6704_44FE_B8C2_BFBCF64C37B2__INCLUDED_)
#define AFX_UGFRACTION_H__E201903D_6704_44FE_B8C2_BFBCF64C37B2__INCLUDED_

#include "ugdefs.h"
#include <math.h>

namespace UGC
{
	
class BASE_API UGFraction  
{
public:
	UGFraction();
	UGFraction(UGdouble& decimal,UGint nMaxNumber = 999);
	UGFraction(UGint nDenominator,UGint nNumerator,UGint nNegative);
	void operator = (const UGFraction &fraction);
	virtual ~UGFraction();

	//! \brief �õ������ķ���
	/**
	\param nNegative  �����ķ���
	*/
	UGint GetDenominator();
	//! \brief ���÷���������
	/**
	\param nNegative  �����ķ���
	*/
	void SetDenominator(UGint &nDenominator);

	//! \brief �õ������ķ�ĸ
	/**
	\param nNegative  ����������
	*/
	UGint GetNumerator();
	//! \brief ���÷����ķ�ĸ
	/**
	\param nNumerator  �����ķ�ĸ
	*/
	void SetNumerator(UGint &nNumerator);

	//! \brief �õ�����������
	/**
	\return ��������
	*/
	UGbool GetNegative();
	//! \brief ���÷���������
	/**
	\param nNegative  ����������
	*/
	void SetNegative(UGbool &nNegative);

private:
	//! \brief ����
	UGint m_nDenominator;
	//! \brief ��ĸ
	UGint m_nNumerator;
	//! \brief ����
	UGbool m_nNegative;

};


}

#endif // !defined(AFX_UGFRACTION_H__E201903D_6704_44FE_B8C2_BFBCF64C37B2__INCLUDED_)
