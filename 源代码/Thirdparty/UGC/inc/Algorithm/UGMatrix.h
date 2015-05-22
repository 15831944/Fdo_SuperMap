/*! \file 		UGMatrix.h
*   \brief 		��������� 
*   \remarks 	 
*   \author 	LIWENLONG 
*   \attention
*   Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br> 
*        All Rights Reserved 

*    <b>����˵����</b><br> 
	   \Version caogf  �ŵ�Algorithm��������
*/ 

// UGMatrix.h: interface for the UGMatrix class.
//
//////////////////////////////////////////////////////////////////////

#include "Base/ugdefs.h"
#include "Base/UGString.h"

#if !defined(UGMATRIX_H)
#define UGMATRIX_H

namespace UGC {

class ALGORITHM_API UGMatrix  
{
public:
	UGMatrix();
	UGMatrix(UGint nRow,UGint nColumn);
	virtual ~UGMatrix();

public:

	//! \brief 		
	//! \return 	void
	//! \param 		strFileName
	//! \remarks 	���ӿ���ʱû��ʵ��	
	void display(UGString& strFileName);

	//! \brief 		
	//! \return 	void
	//! \param 		Element
	//! \param 		nIndex
	//! \remarks 		
	void PutElement(UGdouble Element,UGint nIndex);

	//! \brief 		store matrix element(i,j) in the array.
	//! \return 	matrix
	//! \param 		Element
	//! \param 		i
	//! \param 		j
	//! \remarks 		
	void PutElement(UGdouble Element,UGint i,UGint j);

	//! \brief 		retrieve matrix elemnent (i,j) from array.
	//! \return 	matrix
	//! \param 		i
	//! \param 		j
	//! \remarks 		
	UGdouble GetElement(UGint i,UGint j) const;
	
	//operatre attribute
	UGint GetColumnCount();
	UGint GetRowCount();
	UGbool ReInit(UGint nRow,UGint nColumn);

	//matrix arithmetic oprations

	//! \brief 		�������
	//! \return 	UGbool
	//! \param 		BaseMatrix		�Ӿ���
	//! \param 		SumtMatrix		���صĺ;���
	//! \remarks 
	
	/*	reason:	����const			By: guohui	time: 2005-10-31 14:33:45	*/	
	UGbool AddMatrix(const UGMatrix& BaseMatrix,UGMatrix& SumtMatrix)const;

	//! \brief 		�������
	//! \return 	UGbool
	//! \param 		BaseMatrix		�˾���
	//! \param 		Product			���صĳ˻�����
	//! \remarks 		
	UGbool MulMatrix( const UGMatrix& BaseMatrix,UGMatrix& Product) const ;

	//! \brief 		������ת��
	//! \return 	UGbool
	//! \param 		BaseMatrix
	//! \param 		Transpose		���ص�ת����
	//! \remarks 		
	UGbool TranMatrix( const UGMatrix& BaseMatrix,UGMatrix& Transpose) const ;

	//! \brief 		������ת��
	//! \return 	UGbool
	//! \param 		&Transpose		���ص�ת����
	//! \remarks 		
	UGbool TranMatrix(UGMatrix &Transpose)const;

	//! \brief 		��BaseMatrix��������
	//! \return 	UGbool
	//! \param 		BaseMatrix		���������
	//! \remarks 	ȫѡ��Ԫ��˹-Լ����	
	UGbool InvsMatrix( UGMatrix& BaseMatrix);

	//! \brief 		�������
	//! \return 	UGbool
	//! \param 		BaseMatrix
	//! \param 		SubMatrix
	//! \remarks 		
	UGbool SubMatrix( const UGMatrix& BaseMatrix,UGMatrix& SubMatrix) const;

	//! \brief 		�������
	//! \return 	UGint
	//! \param 		a
	//! \remarks 		
    UGint ChiResolve(UGMatrix& a);
	
	//! \brief 		�������
	//! \return 	UGint
	//! \param 		
	//! \remarks 		
	UGint ChiResolve();

	//! \brief 		���о���д�ɶԽ�����
	//! \return 	UGbool
	//! \param 		&DiagonMatrix
	//! \remarks 		
    UGbool CreateDiagonMatrix(UGMatrix &DiagonMatrix);

	//! \brief 		��ԭϵ��������ƫ��������ϵ����
	//! \return 	UGbool
	//! \param 		Coefficient			ԭϵ������
	//! \param 		TargetCoefficient	ƫ��������ϵ����
	//! \remarks 		
	UGbool CalDerivate(UGMatrix& Coefficient,UGMatrix& TargetCoefficient);

	//! \brief 		��˹��Ԫ�������Է�����(����Ϊ a*X = b���Ᵽ����b��)
	//! \return 	UGint
	//! \param 		a		˫����ʵ�Ͷ�ά���飬���Ϊn*n,���n*n��ʵ����A
	//! \param 		b		��������,���Ϊn;���ط�����Ľ�����
	//! \remarks    0,ʧ��;1�ɹ�		
	UGint CalGause(UGMatrix& a,UGMatrix& b);

	//! \brief 		һ��ʵ���������ֵ�ֽ�
	//! \return 	UGint
	//! \param 		a		˫����ʵ�Ͷ�ά���飬���Ϊm*n,���m*n��ʵ����A������ʱ��Խ��߸�������ֵ������Ԫ�ؾ�Ϊ��
	//! \param 		u		˫����ʵ�Ͷ�ά���飬���Ϊm*m,����ʱ�������������U
	//!	\param 		v		˫����ʵ�Ͷ�ά���飬���Ϊn*n,����ʱ�������������V
	//! \param 		eps		˫����ʵ�ͱ����������ľ���Ҫ��
	//! \param 		ka		���ͱ�������ֵΪmax(m,n)+1
	//! \remarks 	��˹�ɶ���(Householder)�任������QR�㷨	
	UGint QYResolve(UGMatrix& a,UGMatrix& u,UGMatrix& v,UGdouble eps,UGint ka);

	//! \brief 		������������ֵ�ֽ⣺
	//! \return 	UGint
	//! \param 		a
	//! \param 		aa
	//! \param 		eps
	//! \param 		u
	//! \param 		v
	//! \param 		ka
	//! \remarks 		
	UGint RQYResolve(UGMatrix& a,UGMatrix& aa,UGdouble eps,UGMatrix& u,UGMatrix& v,UGint ka);

	//! \brief 		���ù������󳬶�������AX=B����С���˽⣬AΪm*n(m>=n)�������������޹أ���m=nʱ��Ϊ�����Դ�������
	//! \return 	UGint
	//! \param 		a
	//! \param 		b
	//! \param 		x
	//! \param 		aa
	//! \param 		eps
	//! \param 		u
	//! \param 		v
	//! \param 		ka
	//! \remarks 		
	UGint CalQYMinMulti(UGMatrix& a,UGMatrix& b,UGMatrix& x,UGMatrix& aa,double eps,UGMatrix& u,UGMatrix& v,UGint ka);

	//! \brief 		��ֵ
	void operator = (const UGMatrix &Matrix);

	//! \brief 		ȡԪ��
	UGdouble& operator [] (const UGint nIndex );

protected:
	void ppp(UGMatrix& a,double* e,double* s,UGMatrix& v);
	void sss(UGdouble* fg,UGdouble* cs);

protected:
	UGint m_nRow;            //����
	UGint m_nCol;            //����
	UGdouble *m_pdArray ;     //stores the element of Matrix in the array. 

};

}

#endif
