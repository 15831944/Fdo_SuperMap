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
// �ļ�����			SmPrjParams.h
// ��  ����			UGPrjParams
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

#if !defined(UGC_SMPRJPARAMS_H__565B113E_EA70_4EC2_B1B5_9140AD14D73B__INCLUDED_)
#define UGC_SMPRJPARAMS_H__565B113E_EA70_4EC2_B1B5_9140AD14D73B__INCLUDED_


#include "Base/UGString.h"
#include "UGPjCon.h"



namespace UGC{



class PROJECT_API UGPrjParams  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGPrjParams();
	virtual ~UGPrjParams();

	UGPrjParams&  operator = (const UGPrjParams& PrjParams);
	UGbool  operator == (const UGPrjParams& PrjParams) const;
	UGbool  operator != (const UGPrjParams& PrjParams) const;
	
	/*
//	UGProjection GetProjection();
//	void		SetProjection(const UGProjection& prj);
	UGint		GetParamsCount(EmPrjObjectType prjType);
	UGString	GetParamName(UGint nIndex,EmPrjObjectType prjType);
	UGdouble		GetParamValue(UGint nIndex,EmPrjObjectType prjType);
	void		SetParamValue(UGint nIndex,UGdouble nValue,EmPrjObjectType prjType);
	*/
	//! \brief ���ΪXML�ַ���
	UGString ToXML(UGint nVersion = 0) const;
	//! \brief ��XML�ַ����ж���
	UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

public:
//	UGProjection m_Projection;

	UGdouble m_dFalseEasting;			//  0 False easting (X0)
	UGdouble m_dFalseNorthing;		//  1 False northing (Y0)
	UGdouble m_dCentralMeridian;		//  2 Central meridian, Longitude of origin (LON0)
	UGdouble m_dCentralParallel;		//  6 Central parallel, Latitude of origin	(LAT0)

	UGdouble m_dStandardParallel1;	//  3 Standard parallel 1, Latitude of 1st point (LAT1)
	UGdouble m_dStandardParallel2;	//  4 Standard parallel 2, Latitude of 2nd point (LAT2)

	UGdouble m_dScaleFactor;			//  5 Scale factor
	UGdouble m_dAzimuth;				//  7 Azimuth

	UGdouble m_dFirstPointLongitude;		//  8 Longitude of 1st point (LON1)
	UGdouble m_dSecondPointLongitude;		//  9 Longitude of 2nd point  (LON2)
};


}//namespace UGC



#endif // !defined(UGC_SMPRJPARAMS_H__565B113E_EA70_4EC2_B1B5_9140AD14D73B__INCLUDED_)
