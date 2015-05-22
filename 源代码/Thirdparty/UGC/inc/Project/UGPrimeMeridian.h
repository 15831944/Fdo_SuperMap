//========================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	�԰汾�����������Ϊ׼
//------------------------------------------------------------------------
//��Ȩ����:         ��Ȩ���� 1996-2003 ������ͼ������Ϣ�������޹�˾����������Ȩ�� 
//	                Copyright (c) 1996-2003 The SuperMap GIS Technologies, Inc. 
//	                All rights reserved

// ��Ҫ������		1. 
//					2. 
//					
//------------------------------------------------------------------------
// �ļ�����			UGPrimeMeridian.h
// ��  ����			UGPrimeMeridian
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		���������߶���
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

#if !defined(UGC_SMPRIMEMERIDIAN_H__4FF3AA98_8D8B_43C7_8ED4_1F619E70CCC5__INCLUDED_)
#define UGC_SMPRIMEMERIDIAN_H__4FF3AA98_8D8B_43C7_8ED4_1F619E70CCC5__INCLUDED_


//// #include "SmImport.h"
#include "Base/UGThread.h"
#include "Base/UGString.h"

#include "UGPjCon.h"

namespace UGC{

class PROJECT_API UGPrimeMeridian  
{
	friend class UGPrjFactory;
public:
	//! \brief Ĭ�Ϲ��캯��
	UGPrimeMeridian();
	//! \brief �������뾭�����͹������뾭�߶���
	UGPrimeMeridian(EmPrimeMeridianType nTypeID );
	//! \brief �������뾭��ֵ�����뾭�����ƹ������뾭�߶���
	UGPrimeMeridian(UGdouble dValue,UGString strName = "");
	UGPrimeMeridian(const UGPrimeMeridian& PrimeMeridian);

	UGPrimeMeridian& operator = (const UGPrimeMeridian& PrimeMeridian);
	UGbool operator == (const UGPrimeMeridian& PrimeMeridian) const;
	UGbool operator != (const UGPrimeMeridian& PrimeMeridian) const;
	
	//! \brief �������뾭������
	//! \remarks �������뾭�����ͺ� ����ݴ��������¹������뾭�߶���
	UGbool SetTypeID(EmPrimeMeridianType nTypeID);
	
	//! \brief ��ȡ���뾭������
	EmPrimeMeridianType GetTypeID() const;
	
	//! \brief ��ȡ���뾭��ֵ
	UGdouble GetValue() const;
	//! \brief �������뾭��ֵ
	UGbool SetValue(UGdouble dValue);

	//! \brief ��ȡ���뾭������
	UGString GetName() const;
	//! \brief �������뾭������
	void SetName(const UGString& strName);

	virtual ~UGPrimeMeridian();
	
	//! \brief ���ΪXML�ַ���
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ַ�����ȡΪ���뾭�߶���
	UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

	//! \brief �������ļ���ȡ����������Ϣ dongfei 2007-04-04
	UGbool FromConfigure(EmPrimeMeridianType nTypeID,UGint nVersion = 0);

protected:
	UGString				m_strName;
	UGdouble				m_dValue;
	EmPrimeMeridianType		m_eTypeID;
	UGMutex					m_mutex;
};

}//namespace UGC


#endif // !defined(UGC_SMPRIMEMERIDIAN_H__4FF3AA98_8D8B_43C7_8ED4_1F619E70CCC5__INCLUDED_)
