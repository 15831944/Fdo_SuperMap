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
// �ļ�����			SmHorizonDatum.h
// ��  ����			UGHorizonDatum
// ��  �ࣺ			UGDatum
// ��  �ࣺ			

// ����˵����		���ˮƽ����ϵ����
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

#if !defined(UGC_SMHORIZONDATUM_H__5081C85C_BFE6_4BB0_891B_F59372DE57A6__INCLUDED_)
#define UGC_SMHORIZONDATUM_H__5081C85C_BFE6_4BB0_891B_F59372DE57A6__INCLUDED_


//// #include "SmImport.h"
#include "Base/UGThread.h"
#include "Base/UGString.h"

#include "UGDatum.h"
#include "UGSpheroid.h"

namespace UGC{



class PROJECT_API UGHorizonDatum : public UGDatum  
{
	friend class UGPrjFactory;
public:
	//! \brief Ĭ�Ϲ��캯��
	UGHorizonDatum();
	//! \brief ����ˮƽ�ο�ϵ���͹���ˮƽ�ο�ϵ
	UGHorizonDatum(EmHorizonDatumType m_nTypeID );
	//! \brief ���������������ˮƽ�ο�ϵ���ƹ���ˮƽ�ο�ϵ
	UGHorizonDatum(const UGSpheroid& Spheroid,const UGString& strName);
	UGHorizonDatum(const UGHorizonDatum& HorizonDatum);
	
	UGHorizonDatum& operator =  (const UGHorizonDatum& HorizonDatum);
	UGbool operator == (const UGHorizonDatum& HorizonDatum) const;
	UGbool operator != (const UGHorizonDatum& HorizonDatum) const;

	virtual ~UGHorizonDatum();
	//! \brief ����ˮƽ�ο�ϵ����
	//! \remarks ����ˮƽ�ο�ϵ���ͺ󣬻���ݴ��������¹���ˮƽ�ο�ϵ
	UGbool SetTypeID(EmHorizonDatumType nTypeID);
	//! \brief ��ȡˮƽ�ο�ϵ����
	EmHorizonDatumType GetTypeID() const;

	//! \brief ��ȡ�ο�ϵ����
	UGString GetDatumName() const;
	//! \brief ���òο�ϵ����
	void SetDatumName(const UGString& strName);

	//! \brief ��ȡ���������
	const UGSpheroid& GetSpheroid() const;
	//! \brief �������������
	UGbool SetSpheroid(const UGSpheroid& spheroid);
	
	//! \brief ���ΪXML�ַ���
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ַ�������ˮƽ�ο�ϵ
	UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

//	UGString ToXMLEx(UGint nVersion = 0)const;
	
	//! \brief �������ļ���ȡͶӰ����ϵ��Ϣ dongfei 2007-04-04	
	UGbool FromConfigure(EmHorizonDatumType nTypeID,UGint nVersion = 0);

protected:	
	EmHorizonDatumType m_eTypeID;//����
	UGString m_strName;//����
	UGSpheroid m_Spheroid;//�������

	UGMutex m_mutex;
};

}//namespace UGC


#endif // !defined(UGC_SMHORIZONDATUM_H__5081C85C_BFE6_4BB0_891B_F59372DE57A6__INCLUDED_)
