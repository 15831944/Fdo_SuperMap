

#ifndef UG_SYMPOINT_H
#define UG_SYMPOINT_H

#include "Base/ugdefs.h"
#include "Base/UGStream.h"

namespace UGC 
{
/** UGSymPoint����ŵ������		
	@remarks
		1.���ŵĶ����������߼��������ɣ�
		  ���ǽ����֮Ϊ���������ϵͳ(Point-Symbol Coordinat System)��
		2.�߼���������x������Ϊ����y������Ϊ����
		3.�߼�����ķ�ΧΪ256*256(Ŀǰ��ʱ������ô���Ժ���Ҫ��ʱ������չ)��
*/
class SYMBOL_API UGSymPoint  
{
public:
	//ʹ��UGuchar�������ͣ��������귶ΧΪ��256��256
	UGuchar x;
	UGuchar y;
	
public:
	UGSymPoint():x(0),y(0){}
	UGSymPoint(UGuchar xx, UGuchar yy):x(xx),y(yy){}

	//���������࣬������Ĭ�ϵķ�ʽ�Ѿ��㹻ʤ����
	//UGSymPoint(const UGSymPoint& symPoint);	
	//void operator = (const UGSymPoint& symPoint);	

	UGbool operator == (const UGSymPoint& rhs)
	{
		return x == rhs.x && y == rhs.y ;
	}

	UGbool operator != (const UGSymPoint& rhs)
	{
		return x != rhs.x || y != rhs.y ;
	}
	
	void Offset(UGuchar xOffset, UGuchar yOffset)
	{
		this->x += xOffset;
		this->y += yOffset;
	}

	friend SYMBOL_API UGStream& operator<<(UGStream& stream, const UGSymPoint& point)
	{
		stream << point.x << point.y;
		return stream;
	}

	friend SYMBOL_API UGStream& operator>>(UGStream& stream, UGSymPoint& point)
	{
		stream >> point.x >> point.y;
		return stream;
	}

	// for Debug Testing
	inline friend std::ostream& operator << ( std::ostream& o, const UGSymPoint& pt )
	{
		o << "UGSymPoint(" << pt.x << ", " << pt.y << ")";
		return o;
	}
};
	
}

#endif


