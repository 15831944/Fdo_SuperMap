//-------------------------------------------------------------------------------------
// �ļ�����			UGPoint.h
// ��  ����			UGPoint
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		�����(һ��������Ļ����)
// ����˵����		
//------------------------------------------------------------------------------------------------
/*! ����˵��
*    2007.09.21 guohui	��ͷ�ļ�������ϸע��
*/ 

#ifndef UGPOINT_H
#define UGPOINT_H
#include "Base/ugdefs.h"
#include "UGSize.h"
#include "Base/UGStream.h"
#include "Base/UGArray.h"

namespace UGC {

class UGSize;

class ALGORITHM_API UGPoint  
{
public:
	UGint x;
	UGint y;
public:

	//! \brief 		ȱʡ���캯��
	UGPoint();

	//! \brief 		���ι��캯��
	//! \return 	
	//! \param 		xx			������
	//! \param 		yy			������
	//! \remarks 		
	UGPoint(UGint xx,UGint yy);	

	//! \brief 		�������캯��
	//! \return 	
	//! \param 		s			
	//! \remarks 		
	UGPoint(const UGSize& s);

	//! \brief 		�Ƶ���ת
	//! \return 	void
	//! \param 		pntAnchor	���ĵ�
	//! \param 		dRadian		��ת�Ƕ�(����)
	//! \remarks 	
	void Rotate(const UGPoint& pntAnchor, double dRadian);

	//! \brief 		�Ƶ���ת
	//! \return 	void
	//! \param 		pntAnchor	���ĵ�
	//! \param 		dCos		����ֵ
	//! \param 		dSin		����ֵ
	//! \remarks 	
	void Rotate(const UGPoint& pntAnchor, double dCos, double dSin);

	//! \brief 		��ƫ��
	//! \return 	void
	//! \param 		szValue		ƫ����
	//! \remarks 	
	void Offset(const UGSize &szValue);

	//! \brief 		��ƫ��
	//! \return 	void
	//! \param 		nOffsetX	������ƫ��
	//! \param 		nOffsetY	������ƫ��
	//! \remarks 	
	void Offset(UGint nOffsetX, UGint nOffsetY);

	//! \brief 		���� == 
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator==(const UGPoint& p,const UGPoint& q);

	//! \brief 		���� != 
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator!=(const UGPoint& p,const UGPoint& q);			

	//! \brief 		���� = 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& operator=(const UGSize& s);		

	//! \brief 		���� += 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& operator+=(const UGPoint& p);

	//! \brief 		���� += 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& operator+=(const UGSize& s);

	//! \brief 		���� -= 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& operator-=(const UGPoint& p);

	//! \brief 		���� -= 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& operator-=(const UGSize& s);	

	//! \brief 		���� -(ȡ�෴��) 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint operator-();		

	//! \brief 		���� +
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator+(const UGPoint& p,const UGPoint& q);

	//! \brief 		���� +
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator+(const UGPoint& p,const UGSize& s);
	
	//! \brief 		���� +
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator+(const UGSize& s,const UGPoint& p);	
	
	//! \brief 		���� -
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator-(const UGPoint& p,const UGPoint& q);

	//! \brief 		���� -
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator-(const UGPoint& p,const UGSize& s);

	//! \brief 		���� -
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator-(const UGSize& s,const UGPoint& p);
	
	//! \brief 		���� <<
	//! \return 	UGStream
	//! \remarks 	
	friend ALGORITHM_API UGStream& operator<<(UGStream& store,const UGPoint& p);	

	//! \brief 		���� >>
	//! \return 	UGStream
	//! \remarks 	
	friend ALGORITHM_API UGStream& operator>>(UGStream& store,UGPoint& p);
	
};

typedef UGArray<UGPoint> UGPoints;
	
}

#endif


