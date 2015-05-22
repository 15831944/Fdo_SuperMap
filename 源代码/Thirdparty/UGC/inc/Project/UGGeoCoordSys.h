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
// �ļ�����			SmGeoCoordSys.h
// ��  ����			UGGeoCoordSys
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		��������ϵ����
// ����˵����		�����ĸ����캯��
//			1		UGGeoCoordSys()//����һ��WGS84��������ϵ
//          2       UGGeoCoordSys(EmGeoCoordSysType nTypeID );����һ�����õ�������ϵ
//          3       ��������                       
//          4       ����һ���Զ���ĵ�������ϵ

//          SetTypeID(EmGeoCoordSysType nTypeID);����ͨ���������ͺ������õ�������ϵ��
//                                              ����


#if !defined(UGC_SMGEOCOORDSYS_H__93600E0A_9224_4165_B600_D5096E5BCCA6__INCLUDED_)
#define UGC_SMGEOCOORDSYS_H__93600E0A_9224_4165_B600_D5096E5BCCA6__INCLUDED_

#include "Base/UGThread.h"

#include "UGSpatialRef.h"
#include "UGPrimeMeridian.h"
#include "UGHorizonDatum.h"

namespace UGC{


class PROJECT_API UGGeoCoordSys  : public UGSpatialRef
{
	friend class UGPrjFactory;
public:
	//! \brief Ĭ�Ϲ��캯��	
	UGGeoCoordSys();//
	//! \brief ���ݵ�������ϵ���͹����������ϵ	
	UGGeoCoordSys(EmGeoCoordSysType nTypeID );
	//! \brief �������캯��
	UGGeoCoordSys(const UGGeoCoordSys& GeoCoordSys);
	//! \brief ����ˮƽ�ο�ϵ�����뾭�ߡ����굥λ�Լ�����ϵ���ƹ����������ϵ	
	/**
	\param HorizonDatum    ˮƽ�ο�ϵ[in]
	\param PrimeMeridian           ���뾭��[in]
	\param nUnit            ���굥λ�������������㵥λ[in]
	\param strName         ����ϵ����[in]
	*/
	UGGeoCoordSys(UGHorizonDatum& HorizonDatum,
				   UGPrimeMeridian& PrimeMeridian,
				   UGint nUnit,
				   UGString strName = "");

	UGGeoCoordSys& operator = (const UGGeoCoordSys& GeoCoordSys);
	// �������������� hide �����ͬ��(��ͬ����) �ĺ���
	UGbool operator == (const UGSpatialRef& GeoCoordSys) const;
	UGbool operator != (const UGSpatialRef& GeoCoordSys) const;

	//! \brief ���浽�ļ� ��δʵ��
	UGbool SaveToArray(const UGString& strFileName);
	//! \brief ���ļ���ȡ ��δʵ��
	UGbool LoadFromArray(const UGString& strFileName); 	
	
	virtual ~UGGeoCoordSys();
	
	//! \brief ���õ�������ϵ����
	/**
	\param nTypeID ��������ϵ����
	\return �������óɹ�����TRUE ���򷵻�FALSE
	\remarks ���ڵ������������ǵ�������ϵ��Ψһ��ʶ�� �����������ú����еĲ���Ҳ��Ӧ�仯��
	*/
	UGbool SetTypeID(EmGeoCoordSysType nTypeID);	
	//! \brief ���ص�������ϵ����
	EmGeoCoordSysType GetTypeID() const;

//	UGString GetName() const;

	//! \brief ��ȡˮƽ�ο�ϵ����
	/**
	\return ˮƽ�ο�ϵ
	*/
	const UGHorizonDatum &GetHorizonDatum() const;
	//! \brief ����ˮƽ�ο�ϵ
	/**
	\param datum ˮƽ�ο�ϵ [in]
	\return ���óɹ�����TRUE ���򷵻�FALSE
	*/
	UGbool SetHorizonDatum(const UGHorizonDatum& datum);

	//! \brief ��ȡ���뾭�߶���
	const UGPrimeMeridian& GetPrimeMeridian() const;
	//! \brief �������뾭�߶���
	/**
	\param primeMeridian ���뾭�� [in]
	\return ���óɹ�����TRUE ���򷵻�FALSE
	*/
	UGbool SetPrimeMeridian(const UGPrimeMeridian& primeMeridian);

	//! \ brief ���ΪXML�ַ���
	/**
	\param nVersion ���ΪXML�İ汾 Ĭ��Ϊ��ǰ�汾 [in]
	\return �����XML�ַ���
	*/
	UGString ToXML(UGint nVersion = 0)const;
	
	//! \brief ��XML�ַ�����ȡ
	/**
	\param strPrjXML �����XML�ַ���[in]
	\param nVersion ����XML�ַ����İ汾
	\return ����XML�ַ����ɹ������� ���򷵻ؼ�
	*/
	UGbool FromXML(const UGString& strPrjXml,UGint nVersion = 0);

	//! \brief dongfei 2007-04-03
	/* ����xml�ṹ��ͶӰ����ϵ��ֻ��ͶӰ��ʽ����������ϵ�����ͣ�������ʵ������
	 * ˮƽ�ο�ϵ���������ڵ�������ϵ��Ҳ��ͬ����ʽ ��Ҫ��Ϊ�˵������е�ͶӰ����ϵ����
	 * �����Ժ��ò���
	 */
//	UGString ToXMLEx(UGint nVersion = 0)const;
	
	//! \brief �������ļ���ȡ��������ϵ��Ϣ dongfei 2007-04-04	
	UGbool FromConfigure(EmGeoCoordSysType nTypeID,UGint nVersion = 0);

	//! \brief ����������������������ϵ
	UGbool SetData(UGStream& prjstream,UGint nVersion=0); // Load from stream
	//! \brief �����������ϵ��������
	UGbool GetData(UGStream& prjstream,UGint nVersion=0);   // save to stream

	
protected:
	UGHorizonDatum  m_HorizonDatum; //���ˮƽ����ϵ
	UGPrimeMeridian m_PrimeMeridian;//����������

//	UGString m_strName;
	EmGeoCoordSysType   m_eTypeID;
	UGMutex				m_mutex;
	
};

}//namespace UGC



#endif // !defined(UGC_SMGEOCOORDSYS_H__93600E0A_9224_4165_B600_D5096E5BCCA6__INCLUDED_)
