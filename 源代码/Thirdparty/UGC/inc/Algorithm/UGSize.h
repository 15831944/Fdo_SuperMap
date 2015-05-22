//-------------------------------------------------------------------------------------
// �ļ�����			UGSize.h
// ��  ����			UGSize
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		
// ����˵����		
//=====================================================================================
/* �޸�˵����
 *		2007.09.21	guohui	Ϊ��ͷ�ļ����ע��
 */

#ifndef UGSIZE_H
#define UGSIZE_H
#include "Base/ugdefs.h"

namespace UGC {

class ALGORITHM_API UGSize  
{
public:
	UGint cx;
	UGint cy;
public:

	//! \brief 		ȱʡ���캯��
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGSize();	

	//! \brief 		���ι��캯��
	//! \return 	void
	//! \param 		ww		������
	//! \param 		hh		������
	//! \remarks 	
	UGSize(UGint ww,UGint hh);

	//! \brief 		����==
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator==(const UGSize& s,const UGSize& t);

	//! \brief 		����!=
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator!=(const UGSize& s,const UGSize& t);	

	//! \brief 		���� +=
	//! \return 	UGSize
	//! \remarks 	
	UGSize& operator+=(const UGSize& s);

	//! \brief 		���� -=
	//! \return 	UGSize
	//! \remarks 	
	UGSize& operator-=(const UGSize& s);	

	//! \brief 		���� -
	//! \return 	UGSize
	//! \remarks 	
	UGSize operator-();	

	//! \brief 		���� +
	//! \return 	UGSize
	//! \remarks 	
	friend ALGORITHM_API UGSize operator+(const UGSize& s,const UGSize& t);

	//! \brief 		���� -
	//! \return 	UGSize
	//! \remarks 	
	friend ALGORITHM_API UGSize operator-(const UGSize& s,const UGSize& t);
	
};

}

#endif 


