// UGFileImageGeoRefDom.h: interface for the UGFileImageGeoRefDom class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEIMAGEGEOREFDOM_H__A1E62B1B_5384_46E8_9A8A_34DE554A511A__INCLUDED_)
#define AFX_UGFILEIMAGEGEOREFDOM_H__A1E62B1B_5384_46E8_9A8A_34DE554A511A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DataExchange/UGFileImageGeoRef.h"
namespace UGC {

class UGFileImageGeoRefDom : public UGFileImageGeoRef  
{
public:
	UGFileImageGeoRefDom();
	virtual ~UGFileImageGeoRefDom();

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
#endif // !defined(AFX_UGFILEIMAGEGEOREFDOM_H__A1E62B1B_5384_46E8_9A8A_34DE554A511A__INCLUDED_)
