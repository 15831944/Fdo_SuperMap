// UGFileImageGeoRefTfw.h: interface for the UGFileImageGeoRefTfw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEIMAGEGEOREFTFW_H__3E03ADDD_C9F3_4A28_A1D2_55CD7F74FB49__INCLUDED_)
#define AFX_UGFILEIMAGEGEOREFTFW_H__3E03ADDD_C9F3_4A28_A1D2_55CD7F74FB49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UGFileImageGeoRef.h"

namespace UGC {

class UGFileImageGeoRefTfw : public UGFileImageGeoRef  
{
public:
	UGFileImageGeoRefTfw();
	virtual ~UGFileImageGeoRefTfw();

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
#endif // !defined(AFX_UGFILEIMAGEGEOREFTFW_H__3E03ADDD_C9F3_4A28_A1D2_55CD7F74FB49__INCLUDED_)
