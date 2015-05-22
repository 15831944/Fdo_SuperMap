// UGFileImageGeoRefSmc.h: interface for the UGFileImageGeoRefSmc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEIMAGEGEOREFSMC_H__C578A11B_CDE7_46D7_87A4_B54B960B7E6D__INCLUDED_)
#define AFX_UGFILEIMAGEGEOREFSMC_H__C578A11B_CDE7_46D7_87A4_B54B960B7E6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DataExchange/UGFileImageGeoRef.h"

namespace UGC
{
class UGFileImageGeoRefSmc : public UGFileImageGeoRef  
{
public:
	UGFileImageGeoRefSmc();
	virtual ~UGFileImageGeoRefSmc();
	
public:
	//! brief ��strRefFileName��Ϊ��ȷ�ĺ�׺���������������ʵ��
	virtual void SetExtName(UGString& strRefFileName);
	
	//! brief д���ο��ļ�
	virtual UGbool WriteGeoRefInfo(UGRect2D rectBounds, UGlong lUnit);
	
	//! brief ��ȡ�ο��ļ�
	virtual UGbool ReadGeoRefInfo(UGRect2D &rectBounds, UGlong &lUnit);
	
protected:
	//������������ʵ�ֵ�λ�ڷ��ź���ֵ֮����໥ת������Ϊ����Ӱ��ο��ļ��ĸ�ʽ��ͬ����������ɸ��������Լ�ʵ�֡�
	
	//! brief ֪����λ���ַ���ʾ��ת��Ϊ��ֵ��ʽ����supermap�Ĺ涨���ݣ�
	virtual UGlong UnitConvert(UGString strUnit); 
	
	//! brief ֪����λ����ֵ��ʾ��ʽ����supermap�Ĺ涨���ݣ���ת��Ϊ�ַ���ʽ
	virtual UGString UnitConvert(UGlong lUnit);
};
}

#endif // !defined(AFX_UGFILEIMAGEGEOREFSMC_H__C578A11B_CDE7_46D7_87A4_B54B960B7E6D__INCLUDED_)
