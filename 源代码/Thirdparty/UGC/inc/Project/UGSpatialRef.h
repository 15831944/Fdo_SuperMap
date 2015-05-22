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
// �ļ�����			UGSpatialReference.h 
// ��  ����			UGSpatialRef
// ��  �ࣺ			
// ��  �ࣺ			UGGeoCoordSys,UGPrjCoordSys

// ����˵����		�ռ�����ϵ
// ����˵����		
/*-------------------------------------�汾����---------------------------

$Revision: 1.15 $
$Log: UGSpatialRef.h,v $
Revision 1.15  2007/12/17 08:13:38  dongfei
���ע��

Revision 1.14  2007/06/18 02:39:55  dongfei
uglong��Ϊugint��

Revision 1.13  2006/03/01 06:19:46  chengx
�޸�ͶӰ����ϵȡ��λ��������

Revision 1.12  2005/07/18 15:25:09  zhangli
1 ����m_nDistUnit������ʱʹ�õľ��뵥λ
2 ����GetDistUnit��SetDistUnit,�������þ��뵥λ

$Author: dongfei $
$Date: 2007/12/17 08:13:38 $

========================================================================*/

#if !defined(UGC_SMSPATIALREFERENCE_H__B8DFF466_4800_4E68_B538_BD85A315A15C__INCLUDED_)
#define UGC_SMSPATIALREFERENCE_H__B8DFF466_4800_4E68_B538_BD85A315A15C__INCLUDED_

//// #include "SmImport.h"

#include "Base/UGString.h"
#include "Project/UGPjCon.h"

namespace UGC{


class PROJECT_API UGSpatialRef
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGSpatialRef();
	virtual ~UGSpatialRef();

	virtual UGSpatialRef& operator = (const UGSpatialRef& SpatialRef);
	virtual UGbool operator == (const UGSpatialRef& SpatialRef) const; 
	virtual UGbool operator != (const UGSpatialRef& SpatialRef) const;
	
	//! \brief ���浽�ļ�
	virtual UGbool SaveToArray(const UGString& strFileName);
	//! \brief ���ļ�����
	virtual UGbool LoadFromArray(const UGString& strFileName); 

	//! \brief ���ΪXML�ַ���
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ַ������ؿռ�����ϵ
	virtual UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

	//! \brief ����������ȡ�ռ�����ϵ��Ϣ
	virtual UGbool SetData(UGStream& prjstream,UGint nVersion=0); // Load from stream
	//! \brief ���ռ�����ϵ��Ϣ�����������
	virtual UGbool GetData(UGStream& prjstream,UGint nVersion=0);   // save to stream

	//! \brief ��ȡ�ռ�����ϵ����
	UGString GetName() const;			
	//! \brief ���ÿռ�����ϵ����
	virtual void SetName(const UGString& strName);
	//! \brief ��ȡ�ռ�����ϵ����
	EmSpatialRefType GetSpatialRefType() const;
	//! \brief ���ÿռ�����ϵ����
	virtual void SetSpatialRefType(EmSpatialRefType eType);

	//! \brief ��ȡ�ռ�����ϵ��λ
	virtual UGint GetUnit() const;
	//! \brief ��ȡ�ռ�����ϵ���㵥λ
	virtual UGint GetDistUnit() const;
//	virtual void SetUnit(UGint nUnit);
	//! \brief ���ÿռ�����ϵ��λ
	virtual void SetUnit(UGint nUnit);
	//! \brief ���ÿռ�����ϵ���㵥λ
	virtual void SetDistUnit(UGint nUnit);
	//! \brief ��ȡ�ռ�����ϵ������Ϣ
	UGString GetDescription() const;
	//! \brief ���ÿռ�����ϵ������Ϣ
	virtual void SetDescription(const UGString& strDescription);

//	enum ReferenceType
//	{
//		Plannar = 0,
//      Geography = 1,
//	    Project = 2,
//  };

protected:
	UGString m_strName;			// ����ϵ����
	UGString m_strDescription;	// ����ϵ����

	EmSpatialRefType m_eType;	 //����ϵ��־�ţ�
					 // ��������ƽ������ϵ����������ϵ��ͶӰ����ϵ
	                 // ��������Ե����ô���һ�������ʡ�
	
	//UGint   m_nTypeID;//����ϵ���ͺţ�����Ψһ��־�������ϵ	
	
	//UGUnit m_Unit;	 
	UGint m_nUnit;      // ����ϵ��λ
	UGint m_nDistUnit;  // ����ϵ���뵥λ��ֻ��Ϊ���ȵ�λ

};


}//namespace UGC



#endif // !defined(UGC_SMSPATIALREFERENCE_H__B8DFF466_4800_4E68_B538_BD85A315A15C__INCLUDED_)
