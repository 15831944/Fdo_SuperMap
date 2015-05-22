// UGTheme.h: interface for the UGTheme class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGTheme.h 
   **************************************************************************************
    \author   �¹���
    \brief    ר��ͼ���࣬����ר��ͼ������������                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEME_H__AEAB0616_AD6A_4049_9C12_07AE84BC1270__INCLUDED_)
#define AFX_UGTHEME_H__AEAB0616_AD6A_4049_9C12_07AE84BC1270__INCLUDED_

#include "Engine/UGDataSource.h"
#include "Base/UGDict.h"
#include "Base/UGHashCode.h"

namespace UGC {

#define UG_THEME_MAX_VALUE_COUNT	256

class MAP_API UGTheme  
{
public:
	enum UGClassType
	{
		ctEqualDistance,
		ctExtraction,
		ctStdev,
		ctLogarithm,
		ctQuantile,
		ctCustomInterval
	};
	enum UGThemeType //ר��ͼ����
	{
		ttNone =			0,
		ttUnique = 			1,			//UNIQUEר��ͼ
		ttRange	 = 			2,			//RANGEר��ͼ
		ttGraph	 = 			3,			//GRAPHר��ͼ
		ttGraduatedSymbol = 4,			//GRADUATED_SYMBOLר��ͼ
		ttDotDensity =		5,			//DENSITYר��ͼ
//		ttSymbolShade =		6,			//SYMBOL_SHADEר��ͼ
		ttLabel	=			7,			//LABELר��ͼ
		ttCustom =			8,			//CUSTOMר��ͼ
		ttGridUnique = 		11,			//GRIDUNIQUEר��ͼ
		ttGridRange	 = 		12			//GRIDRANGEר��ͼ
	};
	enum UGThemeGraduatedMode
	{
		gmConstant,
		gmSquareRoot,
		gmLogarithm
	};
	enum UGThemeDataType
	{
		tvRecordset,
		tvExternal,
		tvMixed
	};

public:
	UGTheme();
	virtual ~UGTheme();

public:
	//! \brief ר��ͼ�Ƿ���Ч
	virtual UGbool IsValid()const = 0;
	//! \brief ��ȡר��ͼ�ֶ�
	virtual UGString GetFieldName(UGbool bAddExpression = true)const = 0;
	//! \brief �鿴ѡ���ֶ��Ƿ�Ϸ�
	virtual UGbool CheckFieldType(UGint nType);
	//! \brief ר��ͼ����ΪXML��Ϣ
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief ר��ͼ��ȡXML��Ϣ
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief ��ȡר��ͼ�����hashcode
	virtual UGint GetHashCode() const = 0;

	//! \brief �����ⲿֵ
	void SetExternalValue(const UGString& strKey, const UGString& strExternalValue);
	//! \brief �õ��ⲿֵ
	UGbool GetExternalValue(const UGString& strKey, UGString& strExternalValue)const;
	//! \brief ����ⲿֵ
	void ClearExternalData();
	
	//! \brief �õ����ɼ�����	
	UGdouble GetVisibleScaleMax()const;							
	//! \brief �õ���С�ɼ�����	
	UGdouble GetVisibleScaleMin()const;						
	//! \brief �������ɼ�����
	void SetVisibleScaleMax(UGdouble dVisibleScaleMax);		
	//! \brief ȡ�����ɼ�����
	void CancelVisibleScaleMax();							
	//! \brief ������С�ɼ�����
	void SetVisibleScaleMin(UGdouble dVisibleScaleMin);		
	//! \brief ȡ����С�ɼ�����
	void CancelVisibleScaleMin();							

	//! \brief �Ƿ�ɼ���Χ��
	UGbool IsVisibleScale(UGdouble dScale)const;
	//! \brief �Ƿ�ɼ�
	UGbool IsVisible()const;
	//! \brief �����Ƿ�ɼ�
	void SetVisible(UGbool bVisible = true);

	//! \brief �õ�ר��ͼ����
	UGString GetCaption()const;
	//! \brief ����ר��ͼ����
	void SetCaption(const UGString& strCaption );

	//! \brief �õ�ר��ͼ����
	UGint GetType()const;

	//! \brief �õ�ר��ͼ��������
	UGint GetDataType()const;
	//! \brief ����ר��ͼ��������
	void SetDataType(UGint nDataType);

	//! \brief ר��ͼ�Ƿ��޸�
	UGbool IsModified()const;
	//! \brief ����ר��ͼ�Ƿ��޸�
	void SetModifiedFlag(UGbool bModified = true);

	//! \brief ����ת��double��
	static UGbool Variant2Double(const UGVariant& var, double& dKey);
	//! \brief ����ת���ַ���
	static UGString Variant2String(const UGVariant& var); //�������ַ���
	//! \brief ת��ר��ͼ��������
	/**
	\param nThemeType				���Ͷ�Ӧ��intֵ[in]
	\return ��Ӧ���ַ�������
	*/
	static UGString ConvertThemeType(UGint nThemeType);
	//! \brief ת��ר��ͼ��������
	/**
	\param strThemeType		���Ͷ�Ӧ���ַ�������[in]
	\return ��Ӧ��intֵ
	*/
	static UGint ConvertThemeType(const UGString& strThemeType);

	//! \brief ����ר��ͼ��������
	void SetName(UGString strLayerName) {m_strName = strLayerName;};

	//! \brief �õ�ר��ͼ��������
	UGString GetName() {return m_strName;};
	
	
protected:  
	void Swap(const UGTheme& theme);

protected:  
	UGbool m_bModified;
	UGint m_nType;		// ר��ͼ����
	UGint m_nDataType; // 1,���Ա�2���ⲿ�û���������,����Ϊ�Ժ�Ԥ��
	UGDict<UGString,UGString> m_ExternalData; // �ֶ�(���ʽ)ֵ���ⲿ�������ݵĶ�Ӧ	
	
	UGString m_strCaption; //caption for this thematic map
	UGbool m_bVisible;

	UGdouble m_dVisibleScaleMax;	//����ͼ�����ߴ��ڸ�ֵ��ʱ�򣬱�ͼ�㲻��ʾ������ֵС�ڵ���0�����������Ч��Ĭ��Ϊ0
	UGdouble m_dVisibleScaleMin;	//����ͼ������С�ڸ�ֵ��ʱ�򣬱�ͼ�㲻��ʾ������ֵС�ڵ���0�����������Ч��Ĭ��Ϊ0

	UGString m_strName;
	

};

}

#endif // !defined(AFX_UGTHEME_H__AEAB0616_AD6A_4049_9C12_07AE84BC1270__INCLUDED_)
