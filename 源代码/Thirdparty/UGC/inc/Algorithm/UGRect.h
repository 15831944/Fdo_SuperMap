//-------------------------------------------------------------------------------------
// �ļ�����			UGRect.h
// ��  ����			UGRect
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		����(һ��������Ļ����)
// ����˵����		������Ļ���꿪����ɡ�left<right,top<bottom
//------------------------------------------------------------------------------------------------
/*! ����˵��
*    2007.09.21 guohui	��ͷ�ļ�������ϸע��
*/ 
#ifndef UGRECT_H
#define UGRECT_H
#include "Base/ugdefs.h"
#include "UGPoint.h"

namespace UGC {

class ALGORITHM_API UGRect  
{
public:
	UGint left;
	UGint top;
	UGint right;
	UGint bottom;		
public:

	//! \brief 		ȱʡ���캯��
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGRect();	

	//! \brief 		���ι��캯��
	//! \return 	void
	//! \param 		l	��
	//! \param 		t	��
	//! \param 		r	��
	//! \param 		b	��
	//! \remarks 	�ײ㲻������ݽ��й���(����ȷ��left<right,top<bottom)��ϵ
	UGRect(UGint l,UGint t,UGint r,UGint b);
	
	//! \brief 		���ι��캯��
	//! \return 	void
	//! \param 		p	���Ͻ�����
	//! \param 		s	���εĴ�С
	//! \remarks 	
	UGRect(const UGPoint& p,const UGSize& s);

	//! \brief 		���ι��캯��
	//! \return 	void
	//! \param 		tl	���Ͻ�����
	//! \param 		br	���½�����
	//! \remarks 	
	UGRect(const UGPoint& tl,const UGPoint& br);	

	//! \brief 		���� ==
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator==(const UGRect& p,const UGRect& q);

	//! \brief 		���� !=
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator!=(const UGRect& p,const UGRect& q);
	
	//! \brief 		���þ��β���
	//! \return 	void
	//! \param 		l	��
	//! \param 		t	��
	//! \param 		r	��
	//! \param 		b	��
	//! \remarks 	
	void SetRect(UGint l,UGint t,UGint r,UGint b);

	//! \brief 		���þ��β���
	//! \return 	void
	//! \param 		tl	���Ͻ�����
	//! \param 		br	���½�����
	//! \remarks 	
	void SetRect(const UGPoint& tl,const UGPoint& br);

	//! \brief 		��������Ϊ��
	//! \return 	void
	//! \remarks 	��������0
	void SetEmpty();

	//! \brief 		�����Ƿ�Ϊ��
	//! \return 	UGbool
	//! \remarks 	���������left<right,top<bottom������Ϊ��
	UGbool IsEmpty();

	//! \brief 		�����Ƿ�Ϊδ��ʼ��
	//! \return 	UGbool
	//! \remarks 	���������left<right,top<bottom������Ϊ��
	UGbool IsNull();

	//! \brief 		���εĿ��
	//! \return 	UGint
	//! \remarks 	�п���Ϊ����
	UGint Width() const;

	//! \brief 		���εĿ��
	//! \return 	UGint
	//! \remarks 	�п���Ϊ����
	UGint  Height() const;

	//! \brief 		���ε����Ͻǵ�
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& TopLeft();

	//! \brief 		����const���͵����Ͻ�
	//! \return 	UGPoint
	//! \remarks 	�������rectΪconst���ͣ��򽫵��ñ��ӿ�
	const UGPoint& TopLeft() const;	

	//! \brief 		����const���͵����½�
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& BottomRight();		

	//! \brief 		����const���͵����½�
	//! \return 	UGPoint
	//! \remarks 	�������rectΪconst���ͣ��򽫵��ñ��ӿ�
	const UGPoint& BottomRight() const;
	
	//! \brief 		��ȡ���ε����ĵ�
	//! \return 	UGPoint
	//! \remarks 	���ζԽ��ߵĽ���
	UGPoint CenterPoint() const;
	
	//! \brief 		��ȡ���εĴ�С
	//! \return 	UGSize
	//! \remarks 	
	UGSize Size() const;

	//! \brief 		��������ֵ
	//! \return 	void
	//! \remarks 	
	void SwapLeftRight();

	//! \brief 		�����ϡ���ֵ
	//! \return 	void
	//! \remarks 	
	void SwapTopBottom();	

	//! \brief 		���Ƿ��ھ�����
	//! \return 	UGbool
	//! \param 		p	�����
	//! \remarks 	
	UGbool PtInRect(const UGPoint& p) const;

	//! \brief 		����r�Ƿ�����ڱ�������
	//! \return 	UGbool
	//! \param 		r	����
	//! \remarks 	
	UGbool Contains(const UGRect& r) const;

	//! \brief 		�������Ƿ��ھ���r��
	//! \return 	UGbool
	//! \param 		r	����
	//! \remarks 	
	UGbool Withins(const UGRect& r) const;

	//! \brief 		�����������r�Ƿ��ཻ
	//! \return 	UGbool
	//! \param 		r	����
	//! \remarks 	
	UGbool Intersects(const UGRect& r) const;


	//! \brief 		���б�ת����ȷ��left<=right,top<=bottom
	//! \return 	void
	//! \remarks 	
	void Normalize();
	
	//! \brief 		�Ծ��ν���ƫ��
	//! \return 	void
	//! \param 		x	������ƫ����
	//! \param 		y	������ƫ����
	//! \remarks 	
	void Offset(UGint x,UGint y);
	
	//! \brief 		�Ծ��ν���ƫ��
	//! \return 	void
	//! \param 		s	��������ƫ����
	//! \remarks 	
	void Offset(const UGSize& s);
	
	//! \brief 		�Ծ��ν���ƫ��
	//! \return 	void
	//! \param 		p	��������ƫ����
	//! \remarks 	
	void Offset(const UGPoint& p);

	//! \brief 		�Ծ��ν��зŴ�
	//! \return 	void
	//! \param 		margin	���ݷŴ���
	//! \remarks 	
	void Inflate(UGint margin);

	//! \brief 		�Ծ��ν��зŴ�
	//! \return 	void
	//! \param 		hormargin	������Ŵ���
	//! \param 		vermargin	������Ŵ���
	//! \remarks 	
	void Inflate(UGint hormargin,UGint vermargin);

	//! \brief 		�Ծ��ν��зŴ�
	//! \return 	void
	//! \param 		leftmargin	
	//! \param 		topmargin	
	//! \param 		rightmargin	
	//! \param 		bottommargin
	//! \remarks 	
	void Inflate(UGint leftmargin,UGint topmargin,UGint rightmargin,UGint bottommargin);
	
	//! \brief 		�Ծ��ν�����С
	//! \return 	void
	//! \param 		margin	������С��
	//! \remarks 	
	void Deflate(UGint margin);

	//! \brief 		�Ծ��ν�����С
	//! \return 	void
	//! \param 		hormargin	��������С��
	//! \param 		vermargin	��������С��
	//! \remarks 	
	void Deflate(UGint hormargin,UGint vermargin);

	//! \brief 		�Ծ��ν�����С
	//! \return 	void
	//! \param 		leftmargin	
	//! \param 		topmargin	
	//! \param 		rightmargin	
	//! \param 		bottommargin
	//! \remarks 	
	void Deflate(UGint leftmargin,UGint topmargin,UGint rightmargin,UGint bottommargin);

	//! \brief 		���κϲ�
	//! \return 	void
	//! \param 		p	
	//! \remarks 	
	void Union(const UGPoint& p);

	//! \brief 		���κϲ�
	//! \return 	void
	//! \param 		r	
	//! \remarks 	
	void Union(const UGRect& r);	

	//! \brief 		������
	//! \return 	void
	//! \param 		r	
	//! \remarks 	
	void Intersection(const UGRect& r);

};

}

#endif 


