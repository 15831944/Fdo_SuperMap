// UGThemeDotDensity.h: interface for the UGThemeDotDensity class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeDotDensity.h
   **************************************************************************************
    \author   �¹���
    \brief    ���ܶ�ר��ͼ�ࡣ                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEDOTDENSITY_H__06A0D835_186A_4C11_9157_F6BBC8423E8A__INCLUDED_)
#define AFX_UGTHEMEDOTDENSITY_H__06A0D835_186A_4C11_9157_F6BBC8423E8A__INCLUDED_

#include "UGTheme.h"
#include "Drawing/UGDrawing.h"

namespace UGC {

class MAP_API UGThemeDotDensity : public UGTheme  
{
public:
	UGThemeDotDensity();
	virtual ~UGThemeDotDensity();
	UGThemeDotDensity(const UGThemeDotDensity& ThemeDotDensity);
	UGThemeDotDensity& operator = (const UGThemeDotDensity& ThemeDotDensity);

public:
	//! \brief ���ܶ�ר��ͼ�Ƿ���Ч
	virtual UGbool IsValid()const;
	//! \brief ���ܶ�ר��ͼ����ΪXML��Ϣ
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief ���ܶ�ר��ͼ��ȡXML��Ϣ
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief ���ܶ�ר��ͼ����ֶ��Ƿ�Ϸ�
	virtual UGbool CheckFieldType(UGint nType);
	//! \brief ���ܶ�ר��ͼ��ȡ�ֶ�����
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;

	//! \brief �õ��������ʽ,�������ֶ����ƻ���ʽ
	UGString GetExpression()const;						
	//! \brief �����������ʽ,�������ֶ����ƻ���ʽ
	void SetExpression(const UGString& strExpression );	

	//! \brief ���ܶ�ר��ͼת��Ϊ���ζ���
	/**
	\param pRegion			���Ͷ�Ӧ���ַ�������[in]
	\param pDrawParam		���Ͷ�Ӧ���ַ�������[in]
	\param dValue			������ֵ[in]
	\return ת���ļ��ζ���
	*/
	UGGeometry* ConvertToGeometry(UGGeoRegion* pRegion, UGDrawParamaters *pDrawParam, UGdouble dValue);
	
	UGdouble RecommendDotValue(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strFieldName);
	//! \brief ���Ƶ��ܶ�ר��ͼ
	/**
	\param pDrawing			���Ʋ���[in]
	\param pRegion			���Ƶ������[in]
	\param dValue			������ֵ[in]
	\return ת���ļ��ζ���
	*/
	UGbool Draw(UGDrawing *pDrawing, UGGeoRegion *pRegion, UGdouble dValue);
	
	//! \brief �õ������ķ���
	const UGStyle& GetMarkerStyle()const;
	//! \brief ���õ����ķ���
	void SetMarkerStyle(UGStyle& Style);

	//! \brief �õ�������ֵ
	UGdouble GetDotValue()const;
	//! \brief ���õ�����ֵ
	void SetDotValue(UGdouble dDotValue);
	
	//! \brief ��ȡר��ͼ�����hashcode
	virtual UGint GetHashCode() const;

protected:  
	void Swap(const UGThemeDotDensity& theme);
	UGbool DotFillRandom(UGDrawing *pDrawing, UGGeoRegion *pRegion, UGint nDotCount);
	
protected:
	UGStyle m_MarkerStyle;
	UGdouble m_dDotValue;
	UGString m_strExpression;

};

}

#endif // !defined(AFX_UGTHEMEDOTDENSITY_H__06A0D835_186A_4C11_9157_F6BBC8423E8A__INCLUDED_)
