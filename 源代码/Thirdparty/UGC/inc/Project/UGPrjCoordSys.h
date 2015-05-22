//========================================================================//
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 0.9
// ��  �ߣ�			������
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//------------------------------------------------------------------------//
//��Ȩ����:         ��Ȩ���� 1996-2003 ������ͼ������Ϣ�������޹�˾����������Ȩ�� 
//	                Copyright (c) 1996-2003 The SuperMap GIS Technologies, Inc. 
//	                All rights reserved

// ��Ҫ������		1. 
//					2. 
//					
//------------------------------------------------------------------------//
// �ļ�����			SmPrjCoordSys.h
// ��  ����			UGPrjCoordSys
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		ͶӰ����ϵ����
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
#if !defined(UGC_SMPRJCOORDSYS_H__9F382146_8F1F_4F19_AA5C_79E6842EF0E3__INCLUDED_)
#define UGC_SMPRJCOORDSYS_H__9F382146_8F1F_4F19_AA5C_79E6842EF0E3__INCLUDED_

#include "Base/UGThread.h"
#include "Base/UGString.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGPoint3D.h"
#include "UGGeoCoordSys.h"
#include "UGPrjParams.h"
#include "UGProjection.h"

namespace UGC{


class PROJECT_API UGPrjCoordSys : public UGSpatialRef
{
	friend class UGPrjFactory;
public:
	//! \brief Ĭ�Ϲ��캯��
	UGPrjCoordSys();
	//! \brief ͨ��ͶӰ����ϵ���͹���ͶӰ����ϵ����
	UGPrjCoordSys(EmPrjCoordSysType nTypeID );
	//! \brief �������캯��
	UGPrjCoordSys(const UGPrjCoordSys& PrjCoordSys);
	//! \brief ͨ����������ϵ��ͶӰ��ʽ��ͶӰ��������ͶӰ����ϵ����
	/**
	\param GeoCoordSys ��������ϵ����[in]
	\param Projection ͶӰ��ʽ����[in]
	\param PrjParams ͶӰ����[in]
	*/
	UGPrjCoordSys(const UGGeoCoordSys& GeoCoordSys,
				   const UGProjection& Projection,
				   const UGPrjParams& PrjParams
				  // Utility::UGString strName = ""
				  );


	UGPrjCoordSys& operator = (const UGPrjCoordSys& PrjCoordSys);
	// �������������� hide �����ͬ��(��ͬ����) �ĺ���
	UGbool operator == (const UGSpatialRef& PrjCoordSys) const;
	UGbool operator != (const UGSpatialRef& PrjCoordSys) const;

	//! \brief �������ļ� ��δʵ��
	UGbool SaveToArray(const UGString& strFileName);
	//! \brief ���ļ���ȡ ��δʵ��
	UGbool LoadFromArray(const UGString& strFileName); 	
	
	//! \brief ����ͶӰ����ϵ����
	//! \brief �������ͺ󣬽�����������ع�ͶӰ����ϵ����
	UGbool SetTypeID(EmPrjCoordSysType nTypeID);
	
	//! \brief ��ȡͶӰ����ϵ����
	EmPrjCoordSysType GetTypeID() const;
	//! \brief ��ȡͶӰ��������
	const UGPrjParams &GetPrjParams() const;
	//! \brief ��ȡ��������������
	const UGGeoCoordSys& GetGeoCoordSys() const;	
	//! \brief ��ȡͶӰ��ʽ����
	const UGProjection &GetProjection() const;
//	UGString GetName() const;

	//! \brief ����ͶӰ��������
	UGbool SetPrjParams(const UGPrjParams& PrjParams);
	//! \brief ���õ�������ϵ����
	UGbool SetGeoCoordSys(const UGGeoCoordSys& GeoCoordSys);	
	//! \brief ����ͶӰ��ʽ����
	UGbool SetProjection(const UGProjection& Projection );
		
	//! \brief ��ȡ��������
	UGint GetParamsCount();
	//! \brief ͨ��������ȡ��������
	UGString GetParamName(UGint nIndex);
	//! \brief ͨ��������ȡ����ֵ
	UGdouble GetParamValue(UGint nIndex);
	//! \brief ͨ�����ƻ�ȡ����ֵ
	UGdouble GetParamValue(const UGString& strName);
	//! \brief ͨ���������ò���ֵ
	UGbool SetParamValue(UGint nIndex,UGdouble dValue);
	//! \brief ͨ���������ò���ֵ
	UGbool SetParamValue(const UGString& strName,UGdouble dValue);
	
	//! \brief ���任���ǴӾ�γ�ȱ任��ͶӰ����仯���Ǵ�ͶӰ����γ��
	UGbool Forward(UGPoint2D* pPoints, UGint nCount);
	UGbool Inverse(UGPoint2D* pPoints, UGint nCount);

	// ��ά��ת��ֻ�Ƕ����е�x,y��������ͶӰ�任����zֵ�����������
	// ��RefTranslator�У�zֵ��ʾ�̣߳��ڵ�������ϵ��ͬ������£��ǲ�������
	// ��һ����Ҫ���С��
	UGbool Forward(UGPoint3D* pPoints, UGint nCount); 
	UGbool Inverse(UGPoint3D* pPoints, UGint nCount);


	UGString ToXML(UGint nVersion = 0)const;
	UGbool FromXML(const UGString& strPrjXml,UGint nVersion = 0);

//	UGString ToXMLEx(UGint nVersion = 0)const;

	//! \brief �������ļ���ȡͶӰ����ϵ��Ϣ dongfei 2007-04-04	
	UGbool FromConfigure( EmPrjCoordSysType nTypeID,UGint nVersion = 0);
	
	//! \brief ����������ȡͶӰ����ϵ����
	UGbool SetData(UGStream& prjstream,UGint nVersion=0); // Load from stream
	//! \brief ��ͶӰ����ϵ���������������
	UGbool GetData(UGStream& prjstream,UGint nVersion=0);   // save to stream
	
	//! \brief ����ƽ������ϵ��λ��ͬʱ��ͶӰ����ϵ��������Ϊƽ������ϵ
	UGbool SetPlanar(UGint nUnits );		//ƽ������ϵ
	//! \brief ���õ�������ϵ ͬʱ����ͶӰ����ϵ����Ϊ��������ϵ
	UGbool SetEarth( UGGeoCoordSys& geogCs);//��������ϵ
	
	//! \brief ��ȡͶӰ����ϵ��λ
	virtual UGint GetUnit() const;
	//! \brief ��ȡͶӰ����ϵ���㵥λ
	virtual UGint GetDistUnit() const;
	//! \brief ����ͶӰ����ϵ��λ
	virtual void SetUnit(UGint nUnit);
	//! \brief ����ͶӰ����ϵ���㵥λ
	virtual void SetDistUnit(UGint nUnit);
	
	virtual ~UGPrjCoordSys();

protected:
	EmPrjCoordSysType m_eTypeID;

	UGGeoCoordSys m_GeoCoordSys;
	UGPrjParams m_PrjParams;
	UGProjection m_Projection;
	UGMutex		m_mutex;

static UGString ms_PrjParamNames[];	
};

}//namespace UGC


#endif // !defined(UGC_SMPRJCOORDSYS_H__9F382146_8F1F_4F19_AA5C_79E6842EF0E3__INCLUDED_)
