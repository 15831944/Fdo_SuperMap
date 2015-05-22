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
// �ļ�����			SmRefTranslator.h
// ��  ����			UGRefTranslator
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		����ϵת��������(����ͶӰ�任������ϵ�任)
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

#if !defined(UGC_SMREFTRANSLATOR_H__9153EB7D_C880_4A7B_8184_754D69D0FDF0__INCLUDED_)
#define UGC_SMREFTRANSLATOR_H__9153EB7D_C880_4A7B_8184_754D69D0FDF0__INCLUDED_


#include "Base/UGErrorObj.h"

#include "UGPrjTranslator.h"
#include "UGGeoTranslator.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGPoint3D.h"



namespace UGC{


class PROJECT_API UGRefTranslator  
{
public:
	enum EmTransType
	{
		XY1ToXY2	= 0,//m_PJCoordSysSrc ͶӰ����-->m_PJCoordSysDes ͶӰ���� 
		XY1ToGeo2	= 1,//m_PJCoordSysSrc ͶӰ����-->m_PJCoordSysDes ����γ����
		Geo1ToXY2	= 2,//m_PJCoordSysSrc ����γ����-->m_PJCoordSysDes ͶӰ����
		Geo1ToGeo2	= 3,//m_PJCoordSysSrc ����γ����-->m_PJCoordSysDes ����γ����

		XY1ToGeo1	= 4,//m_PJCoordSysSrc ͶӰ����-->m_PJCoordSysSrc ����γ����
		Geo1ToXY1	= 5,//m_PJCoordSysSrc ����γ����-->m_PJCoordSysSrc ͶӰ����
		
		XY2ToGeo2	= 6,//m_PJCoordSysDes ͶӰ����-->m_PJCoordSysDes ����γ����
		Geo2ToXY2	= 7 //m_PJCoordSysDes ����γ����-->m_PJCoordSysDes ͶӰ����
		
	};
	//! \brief Ĭ�Ϲ��캯��
	UGRefTranslator();
	virtual ~UGRefTranslator();
	//! \brief ͨ��Դ�ο�ϵ��Ŀ��ο�ϵ����ο�ϵת��������
	UGRefTranslator(UGSpatialRef* pSpatialRefSrc,UGSpatialRef* pSpatialRefDes);

	//! \brief ��������ת��
	UGbool Translate(UGdouble& x, UGdouble& y, UGdouble& dH,  UGbool bForward = true);
	UGbool Translate(UGdouble& x, UGdouble& y, UGbool bForward = true);
	UGbool Translate(UGPoint2D* pPoints, UGlong nPointCount,UGbool bForward = true);
	UGbool Translate(UGPoint3D* pPoints, UGlong nPointCount,UGbool bForward = true);

	//! \brief ����Ŀ��ο�ϵ�ĵ�������
	//! \remarks ��������Ŀ��ο�ϵΪĳ���ض���������ϵ ��������Ŀ������ϵ�еĵ�������ϵ
	UGint SetGeoCoordSysDes(const UGGeoCoordSys& GeoCoordSysDes);	
	//! \brief ����Դ�ο�ϵ�ĵ�������
	UGint SetGeoCoordSysSrc(const UGGeoCoordSys& GeoCoordSysSrc);

	//! \brief ����Ŀ��ͶӰ����ϵ
	UGint SetPrjCoordSysDes(const UGPrjCoordSys& PrjCoordSysDes);
	//! \brief ��ȡĿ��ͶӰ����ϵ
	const UGPrjCoordSys& GetPrjCoordSysDes();
	
	//! \brief ����ԴͶӰ����ϵ
	UGint SetPrjCoordSysSrc(const UGPrjCoordSys& PrjCoordSysSrc);	
	//! \brief ��ȡԴͶӰ����ϵ
	const UGPrjCoordSys& GetPrjCoordSysSrc();	

	//! \brief ���õ�������ת����ʽ
	void SetGeoTransMethod(EmGeoTransMethod nGeoTransMethod);
	//! \biref ��ȡ��������ת����ʽ
	EmGeoTransMethod GetGeoTransMethod(); 
	//! \brief ��ȡת����״̬
	/**
	//return lResult = -1;// �����ܵķ���ֵ
			lResult = 0;// Դ����ϵΪ��
			lResult = 1;// Դ����ϵΪͶӰ����ϵ��Ŀ������ϵΪ��
			lResult = 2;// Դ����ϵ��ΪͶӰ����ϵ��Ŀ������ϵΪ��
			lResult = 3;// Դ����ϵ��Ŀ������ϵ��һ����ƽ������ϵ
			lResult = 4;// ��γ�� ==> ��γ��,�ο�ϵת��
			lResult = 5;// ��γ�� ==> ��γ��,����ϵ��ͬ
			lResult = 6;// ��γ�� ==> ͶӰ��ͬʱ�任����ϵ
			lResult = 7; // ��γ�� ==> ͶӰ������ϵ��ͬ
			lResult = 8; // ͶӰ ==> ��γ�ȣ�����ϵ��ͬ
			lResult = 9; // ͶӰ ==> ��γ�ȣ�����ϵ��ͬ
			lResult = 10; // ͶӰ==>ͶӰ������ϵ��ͬ
			lResult = 11; // ͶӰ==>ͶӰ������ϵ��ͬ
			lResult = 12; // ͶӰ==>ͶӰ������ϵ��ͬ������
			lResult = 13; ͶӰ==>ͶӰ������ϵ��ͬ,ͶӰ������ͬ�����굥λ��ͬ
	*/
	UGint GetTranslatorSatus();
	//! \brief �Ƿ����ת��
	UGbool IsValid();

	//! \brief ���õ�������ϵת����������
	void SetGeoTransParams (const UGGeoTransParams& GeoTransParams);

	//! \brief ��ȡ��������ϵת����������
	UGGeoTransParams&  GetGeoTransParams ();

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

protected:
	UGint Schedule();

protected:
	UGint m_lStatus;
	EmGeoTransMethod m_nGeoTransMethod;

	UGPrjCoordSys  m_PrjCoordSysSrc;
	UGPrjCoordSys  m_PrjCoordSysDes;
	
	UGPrjTranslator m_PrjTranslator1;
	UGPrjTranslator m_PrjTranslator2;
	
	UGGeoTranslator m_GeoTranslator;

	double m_dUnitRatio;// Դ����ϵ��λ��Ŀ������ϵ��λ�ı���
	
//	UGGeoTranslator m_GeoTranslator1;
//	UGGeoTranslator m_GeoTranslator2;
};


}//namespace UGC


#endif // !defined(UGC_SMREFTRANSLATOR_H__9153EB7D_C880_4A7B_8184_754D69D0FDF0__INCLUDED_)
