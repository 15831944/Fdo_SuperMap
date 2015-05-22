/*!  \file	 UGCursor.h
*  \brief	 �����
*  \author	 zengzm
*  \attention 
*  Copyright(c) 1996-2005 SuperMap GIS Technologies, Inc.<br>
*  All Rights Reserved
*/


#if !defined(AFX_UGCURSOR_H__BA0D55BD_3573_442B_B4B5_6FF977F71203__INCLUDED_)
#define AFX_UGCURSOR_H__BA0D55BD_3573_442B_B4B5_6FF977F71203__INCLUDED_

#include "ugdefs.h"

namespace UGC {


//! \brief �����
class BASE_API UGCursor  
{
public: 
	//! \brief �������
	enum Type
	{
		Wait // �ȴ�
		// �����Ժ�����Ҫ������
	};

public:
	//! \brief ���캯��, ����ָ�����͵Ĺ��
	//! \param pNative Graphics��Nativeָ�룬Cursor����ʾ��ʱ����Ҫʹ��
	//! \param eType ��������,Ŀǰ��֧�ֵȴ����
	UGCursor(void* pNative, Type eType=Wait);
	//! \brief ��������, �ָ�ԭ�й��
	~UGCursor();

	//! \brief �ֶ��ָ�ԭ�й��
	void Restore();

private:
	void* m_handlePrev;
	void* m_pGraphicsNative;

};

}

#endif // !defined(AFX_UGCURSOR_H__BA0D55BD_3573_442B_B4B5_6FF977F71203__INCLUDED_)
