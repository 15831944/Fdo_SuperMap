 //=====================================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
//��Ȩ����:         ��Ȩ���� 1996-2003 ������ͼ������Ϣ�������޹�˾����������Ȩ�� 
//	                Copyright (c) 1996-2003 The SuperMap GIS Technologies, Inc. 
//	                All rights reserved

// ��Ҫ������		1. 
//					2. 
//					
//-------------------------------------------------------------------------------------
// �ļ�����			UGSpheroid.h 
// ��  ����			UGSpheroid
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		���������嶨��
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

#if !defined(UGC_SMSPHEROID_H__82E32637_BEBE_4772_A8A7_BAA2E786E35F__INCLUDED_)
#define UGC_SMSPHEROID_H__82E32637_BEBE_4772_A8A7_BAA2E786E35F__INCLUDED_


//// #include "SmImport.h"
#include "Base/UGThread.h"
#include "Base/UGString.h"

#include "UGPjCon.h"

namespace UGC{


class PROJECT_API UGSpheroid  
{
	friend class UGPrjFactory;
public:
	//! \brief Ĭ�Ϲ��캯��
	UGSpheroid();
	//! \brief �������������͹������������
	UGSpheroid(EmSpheroidType nTypeID );
	
	//! \brief ���ݳ��᳤�ȡ����ʺ����������ƹ������������
	UGSpheroid(UGdouble dAxis, UGdouble dFlatten, 
		UGString strName);
	UGSpheroid(const UGSpheroid& Spheroid);
	virtual ~UGSpheroid();

	UGSpheroid& operator=(const UGSpheroid& Spheroid);
	UGbool operator==(const UGSpheroid& Spheroid) const;
	UGbool operator != (const UGSpheroid& Spheroid) const;

	//! \brief ��ȡ����������
	EmSpheroidType GetTypeID() const;
	//! \brief ��������������
	void SetTypeID(EmSpheroidType nTypeID);

	//! \brief ��ȡ�����峤�᳤��
	UGdouble GetAxis() const;
	//! \brief ���������峤�᳤��
	UGbool SetAxis(UGdouble dAxis);
	//! \brief ��ȡ����������
	UGString GetName() const;
	//! \brief ��������������
	void SetName(const UGString& strName);
	//! \brief ��ȡ���������
	UGdouble GetFlatten() const;
	//! \brief �������������
	UGbool SetFlatten(UGdouble dFlatten);

	//! \brief ���ΪXML�ַ���
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ַ�����ȡ��������Ϣ
	UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

	//! \brief �������ļ���ȡ��������Ϣ dongfei 2007-04-04	
	UGbool FromConfigure(EmSpheroidType nTypeID,UGint nVersion = 0);

protected:	
	EmSpheroidType m_eTypeID;   // �����������
	UGdouble  m_dAxis;   // ���򳤰���(����뾶)
	UGdouble  m_dFlatten;// ����
	UGString m_strName;// ����

	UGMutex	 m_mutex;
};

}//namespace UGC



#endif // !defined(UGC_SMSPHEROID_H__82E32637_BEBE_4772_A8A7_BAA2E786E35F__INCLUDED_)
