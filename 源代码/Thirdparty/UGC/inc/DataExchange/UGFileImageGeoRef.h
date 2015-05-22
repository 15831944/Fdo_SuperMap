// UGFileImageGeoRef.h: interface for the UGFileImageGeoRef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEIMAGEGEOREF_H__D14F5D26_D913_4F71_8A44_10E64926CAEB__INCLUDED_)
#define AFX_UGFILEIMAGEGEOREF_H__D14F5D26_D913_4F71_8A44_10E64926CAEB__INCLUDED_

#include "Algorithm/UGRect2D.h"
#include "Base/UGString.h"

namespace UGC {


class UGFileImageGeoRef
{
public:
	UGFileImageGeoRef();
	virtual ~UGFileImageGeoRef();
public:
	enum
	{
		GeoRefFile_NONE= 0, //�û�û��ָ��Ӱ������ο��ļ�������
		GeoRefFile_DOM = 1, //����Ϊ dom, ������������ļ�
		GeoRefFile_TFW = 2, //����Ϊ tfw, TIFF���������ļ�
		GeoRefFile_SMC = 3, //����Ϊ smc��supermap�Զ��壬xml�ĵ���
		GeoRefFile_GB = 4//�����Ĺ�����������ļ��������dom����ǰ�������⣬�ļ���׺��img
	};

public:
	//! brief ��strRefFileName��Ϊ��ȷ�ĺ�׺���������������ʵ��
	virtual void SetExtName(UGString& strRefFileName) = 0;
	
	//! brief �򿪲ο��ļ�
	UGbool Open(UGString strRefFileName, UGString strImageFileName);
	
	//! brief ���øߡ�������ר�ã�
	void SetHeightWidth(UGlong nImageHeight, UGlong nImageWidth);
	
	//! brief ���òο��ļ�����
	void SetType(UGint nType );

	//! brief д���ο��ļ�
	virtual UGbool WriteGeoRefInfo(UGRect2D rectBounds, UGlong lUnit) = 0;
	
	//! brief ��ȡ�ο��ļ�
	virtual UGbool ReadGeoRefInfo(UGRect2D &rectBounds, UGlong &lUnit) = 0;
	
protected:
	//! brief Ҫ��ȡ�������ɵ�Ӱ���������ο��ļ���ȫ·��
	UGString m_strRefFileName; 

	//! brief ��Ӧ��Ҫ��ȡ�������ɵ�Ӱ���ļ�������
	UGString m_strImageFileName;

	//! brief Ӱ��߶�
	UGlong m_nImageHeight;

	//! brief Ӱ����
	UGlong m_nImageWidth;
	
	//! brief �ο��ļ�����
	UGint m_nType;
	
protected:
	//������������ʵ�ֵ�λ�ڷ��ź���ֵ֮����໥ת������Ϊ����Ӱ��ο��ļ��ĸ�ʽ��ͬ����������ɸ��������Լ�ʵ�֡�
	
	//! brief ֪����λ���ַ���ʾ��ת��Ϊ��ֵ��ʽ����supermap�Ĺ涨���ݣ�
	virtual UGlong UnitConvert(UGString strUnit) = 0; 
	
	//! brief ֪����λ����ֵ��ʾ��ʽ����supermap�Ĺ涨���ݣ���ת��Ϊ�ַ���ʽ
	virtual UGString UnitConvert(UGlong lUnit) = 0;

};

}

#endif // !defined(AFX_UGFILEIMAGEGEOREF_H__D14F5D26_D913_4F71_8A44_10E64926CAEB__INCLUDED_)
