//========================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//------------------------------------------------------------------------
//��Ȩ����:         ��Ȩ���� 1996-2003 ������ͼ������Ϣ�������޹�˾����������Ȩ�� 
//	                Copyright (c) 1996-2003 The SuperMap GIS Technologies, Inc. 
//	                All rights reserved
// ��Ҫ������		1. 
//					2. 
//					
//------------------------------------------------------------------------
// �ļ�����			UGProjection.h
// ��  ����			UGProjection
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		ͶӰ��������
// ����˵����		
/*-------------------------------------�汾����---------------------------
V 0.92
��    �ߣ��������ߣ����޸��ߣ�����
������ڣ�2002��10��20��
����˵����

V 0.91
��    �ߣ��������ߣ����޸��ߣ�����
������ڣ�2001��7��20��
����˵����

V 0.9 
ԭ����  ��������
������ڣ�
========================================================================*/

#if !defined(UGC_SMPROJECTION_H__0EBE9968_FA20_4C93_A922_7DAD98A06FF5__INCLUDED_)
#define UGC_SMPROJECTION_H__0EBE9968_FA20_4C93_A922_7DAD98A06FF5__INCLUDED_


//// #include "SmImport.h"

#include "Base/UGThread.h"
#include "Base/UGString.h"

#include "UGPjCon.h"

namespace UGC{


class PROJECT_API UGProjection  
{
	friend class UGPrjFactory;
public:
	//! \brief Ĭ�Ϲ��캯��
	UGProjection();
	//! \brief ����ͶӰ��ʽ���͹���ͶӰ��ʽ����
	UGProjection(EmPrjObjectType eTypeID);
	virtual ~UGProjection();
	UGProjection(const UGProjection& Projection);
	UGProjection& operator = (const UGProjection& Projection);
	UGbool operator == (const UGProjection& Projection) const;
	UGbool operator != (const UGProjection& Projection) const;
	
	//! \brief ��ȡͶӰ��ʽ����
	EmPrjObjectType GetProjectionType() const;
	//! \brief ����ͶӰ��ʽ���Ͳ��ع�ͶӰ��ʽ����
	UGbool SetTypeID(EmPrjObjectType nTypeID);

	//! \brief ��ȡͶӰ��ʽ����
	UGString GetProjectionName() const;

	//! \brief ���ΪXML�ַ���
	UGString ToXML(UGint nVersion = 0) const;
	//! \brief ��ȡXML�ַ���ΪͶӰ��ʽ����
	UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

	//! \brief �������ļ���ȡͶӰ��ʽ��Ϣ dongfei 2007-04-04	
	UGbool FromConfigure( EmPrjObjectType nTypeID,UGint nVersion = 0);


private:
	EmPrjObjectType m_eTypeID;
	UGString m_strName;
	UGMutex	 m_mutex;
};

}//namespace UGC



#endif // !defined(UGC_SMPROJECTION_H__0EBE9968_FA20_4C93_A922_7DAD98A06FF5__INCLUDED_)
