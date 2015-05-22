//-------------------------------------------------------------------------------------
// �ļ�����			UGSize2D.h
// ��  ����			UGSize2D
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		
// ����˵����		
//=====================================================================================
/* �޸�˵����
 *		2007.09.21	guohui	Ϊ��ͷ�ļ����ע��
 */

#ifndef UGSIZE2D_H
#define UGSIZE2D_H
#include "Base/ugdefs.h"

namespace UGC {

class ALGORITHM_API UGSize2D  
{
public:
	UGdouble cx;
	UGdouble cy;
public:
	
	//! \brief 		ȱʡ���캯��
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGSize2D();	

	//! \brief 		���ι��캯��
	//! \return 	void
	//! \param 		cx		������
	//! \param 		cy		������
	//! \remarks 	
	UGSize2D(UGdouble dx,UGdouble dy);
	
	//! \brief 		����==
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator==(const UGSize2D& s,const UGSize2D& t);

	//! \brief 		����!=
	//! \return 	UGbool
	//! \remarks 		
	friend ALGORITHM_API UGbool operator!=(const UGSize2D& s,const UGSize2D& t);	

	//! \brief 		���� +=
	//! \return 	UGSize2D
	//! \remarks 	
	UGSize2D& operator+=(const UGSize2D& s);

	//! \brief 		���� -=
	//! \return 	UGSize2D
	//! \remarks 	
	UGSize2D& operator-=(const UGSize2D& s);	

	//! \brief 		���� *=
	//! \return 	UGSize2D
	//! \remarks 	
	UGSize2D& operator*=(UGdouble c);

	//! \brief 		���� /=
	//! \return 	UGSize2D
	//! \remarks 	
	UGSize2D& operator/=(UGdouble c);	

	//! \brief 		���� -
	//! \return 	UGSize2D
	//! \remarks 	
	UGSize2D operator-();	

	//! \brief 		���� +
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator+(const UGSize2D& s,const UGSize2D& t);

	//! \brief 		���� -
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator-(const UGSize2D& s,const UGSize2D& t);

	//! \brief 		���� *
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator*(const UGSize2D& s,UGdouble c);

	//! \brief 		���� *
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator*(UGdouble c,const UGSize2D& s);

	//! \brief 		���� /
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator/(const UGSize2D& s,UGdouble c);

	//! \brief 		���� /
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator/(UGdouble c,const UGSize2D& s);
};

}

#endif
