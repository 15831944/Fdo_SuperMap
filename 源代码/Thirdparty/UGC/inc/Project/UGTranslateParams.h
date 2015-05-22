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
// �ļ�����			UGTranslateParams.h
// ��  ����			UGGeoTransParams
// ��  �ࣺ			
// ��  �ࣺ			

// ����˵����		����ϵ�仯ʹ�õĲ�����
// ����˵����		
/*-------------------------------------�汾����---------------------------


$Revision: 1.7 $
$Log: UGTranslateParams.h,v $
Revision 1.7  2007/12/17 08:13:38  dongfei
���ע��

Revision 1.6  2007/11/15 10:52:53  dongfei
*** empty log message ***

Revision 1.5  2005/07/18 15:24:04  zhangli
�����ļ�˵����ע��

$Author: dongfei $
$Date: 2007/12/17 08:13:38 $
========================================================================*/
#if !defined(UGC_SMTRANSLATEPARAMS_H__3173CAC9_B797_44C0_AC30_5F8888E57F0F__INCLUDED_)
#define UGC_SMTRANSLATEPARAMS_H__3173CAC9_B797_44C0_AC30_5F8888E57F0F__INCLUDED_


//// #include "SmImport.h"

#include "Base/UGString.h"
#include "UGPjCon.h"



namespace UGC{


class PROJECT_API UGGeoTransParams		//  GeoTransParamsDefault;
{
public:
	//! \brief Ĭ�Ϲ��캯��
	UGGeoTransParams();
	//! \brief �������캯��
	UGGeoTransParams(const UGGeoTransParams& GeoTransParams);
	virtual ~UGGeoTransParams();
	
	UGGeoTransParams& operator = (const UGGeoTransParams& GeoTransParams);
	UGbool  operator == (const UGGeoTransParams& GeoTransParams);
	UGbool  operator != (const UGGeoTransParams& GeoTransParams);
	UGGeoTransParams operator- ()const;
	
	//! \brief ����ת����ʽ��ȡ��������ת���Ĳ������� Ŀǰ��δʵ��	
	UGint		GetParamsCount(EmGeoTransMethod prjType);
	//! \brief ����ת����ʽ����Ż�ȡ�������� ��δʵ��
	UGString	GetParamName(UGint nIndex,EmGeoTransMethod prjType);
	//! \brief ����ת����ʽ����Ż�ȡ����ֵ ��δʵ��
	UGdouble	GetParamValue(UGint nIndex,EmGeoTransMethod prjType);
	//! \brief ����ת����ʽ��������ò���ֵ ��δʵ��
	void		SetParamValue(UGint nIndex,UGdouble nValue,EmGeoTransMethod prjType);
	//! \brief ���ΪXML�ַ���
	UGString	ToXML(UGint nVersion = 0);
	//! \brief ��XML�ַ�����ȡ��������ת������
	UGbool		FromXML(const UGString& strPrjXml,UGint nVersion = 0);
public:
	UGdouble m_dTranslateX;		//  0 X-axis translation ------ Geographic Transforms
	UGdouble m_dTranslateY;		//  1 Y-axis translation
	UGdouble m_dTranslateZ;		//  2 Z-axis translation
	UGdouble m_dRotateX;			//  3 X-axis rotation
	UGdouble m_dRotateY;			//  4 Y-axis rotation
	UGdouble m_dRotateZ;			//  5 Z-axis rotation
	UGdouble m_dScaleDifference;	//  6 Scale difference
};


}//namespace UGC


#endif // !defined(UGC_SMTRANSLATEPARAMS_H__3173CAC9_B797_44C0_AC30_5F8888E57F0F__INCLUDED_)
