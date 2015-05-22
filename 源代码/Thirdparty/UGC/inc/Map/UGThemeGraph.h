// UGThemeGraph.h: interface for the UGThemeGraph class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeGraph.h
   **************************************************************************************
    \author   �¹���
    \brief    ͳ��ר��ͼ�ࡣ                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEGRAPH_H__BF50002A_00EF_41B1_B119_14ADACC6FB9A__INCLUDED_)
#define AFX_UGTHEMEGRAPH_H__BF50002A_00EF_41B1_B119_14ADACC6FB9A__INCLUDED_

#include "UGThemeSymbol.h"
#include "UGGraph.h"
#include "UGLayer.h"

namespace UGC {

class MAP_API UGThemeGraph : public UGThemeSymbol  
{
public:
	UGThemeGraph();
	virtual ~UGThemeGraph();
	UGThemeGraph(const UGThemeGraph& ThemeGraph);
	UGThemeGraph& operator = (const UGThemeGraph& ThemeGraph);

public:
	//! \brief ר��ͼ�Ƿ���Ч
	/**
	ר��ͼ�Ƿ���Ч
	*/
	virtual UGbool IsValid()const;
	//! \brief ר��ͼ������Ϣ����XML��ʽ
	/**
	*/
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��XML�ж�ȡר��ͼ��Ϣ
	/**
	*/
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief ����ѯ�ֶ��Ƿ�Ϊ��Ч����
	/**
	*/
	virtual UGbool CheckFieldType(UGint nType);
	//! \brief ��ȡ��ѯ�ֶ�
	/**
	*/
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;

	//! \brief ��ȡX����ƫ����
	/**
	*/
	virtual UGString GetOffsetXFieldName(UGbool bAddExpression = true)const;
	//! \brief ��ȡY����ƫ����
	/**
	*/
	virtual UGString GetOffsetYFieldName(UGbool bAddExpression = true)const;

	//! \brief ��ȡ��ѯ�ֶ���
	/**
	*/
	UGbool GetFieldName(UGArray<UGString>& strArray)const; 
	//! \brief ��Recordsetת��Ϊ��Ӧ��Geometry
	/**
	\param pRecordset ��ѡ�ļ�¼��[in]
	\param point      ���Ƶ�[in]
	\param pDrawParam ���Ʋ���[in]
	\remarks ��Ҫ���Ƶ�Geometry
	*/
	UGGeometry *ConvertToGeometry(UGRecordset *pRecordset, const UGPoint2D &point, UGDrawParamaters *pDrawParam);
	
	//! \brief ����ͳ��ר��ͼ��������ƶ���Ļ��Ʋ���������Ĭ�ϲ�����С
	/**
	\param pDrawParam ���Ʋ���[in]
	*/
	void SetDrawParamaters(UGDrawParamaters *pDrawParam);
	//! \brief ʵ�ֶ�ר��ͼ��ĳ���������
	/**
	\param pDrawing       ������[in] 
	\param pRecordset     ��¼��[in]
	\param point          ���Ƶ�[in]
	\param pntAnchor	���ƶ�λ��[in]
	\param szOffset       ƫ����[in]
	\param pHitTestInfo   �Ƿ��е����Ϣ[in]
	\remarks 
	*/
	UGbool DrawTheme(UGDrawing *pDrawing, UGRecordset *pRecordset, const UGPoint2D &point, const UGPoint2D &pntAnchor, UGSize2D szOffset,HitTestInfo* pHitTestInfo = NULL);
	//! \brief ʵ�ֶ�ר��ͼ��ĳ��ֵ���л���
	/**
	\param pDrawing        ������[in] 
	\param pValues         ������ƵĶ�ֵ[in]
	\param unItemCount     �εĸ���[in]
	\param pntAnchorPoint  ê��[in]
	\param szGraph         ���ƴ�С[in]
	*/
	UGbool DrawItem(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntAnchorPoint, UGSize szGraph);
	//! \brief Ϊ����������Ĭ�Ϸ��
	/**
	*/
	UGbool MakeDefaultStyles();
	//! \brief ����ͳ��ר��ͼ�����εļ�ֵ��������εĴ�С
	/**
	\param pDatasetV      �����ʸ�����ݼ�[in] 
	\remarks 
	*/
	UGbool CalculateExtremum(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems);
	//! \brief ��鼫ֵ������Ч
	/**
	*/
	UGbool IsValidExtremum()const;
	
	// ͳ��ͼ�ֶα��ʽ��������
	//! \brief ɾ�����жε���ֵ
	/**
	*/
	void RemoveAll();
	//! \brief ����ĳ�ֶα��ʽ
	/**
	*/
	UGint Add(const UGString& strExpression);
	//! \brief ����ͳ��ר��ͼ������λ��
	/**
	*/
	UGbool Swap(UGint nOldIndex, UGint nNewIndex);	
	//! \brief ɾ��ĳ����
	/**
	*/
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief �õ��ε�����
	/**
	*/
	UGint GetCount()const;
	//! \brief ���öε�����
	/**
	*/
	void SetCount(UGint nCount);	
	
	//! \brief �õ�ָ���ֶεı��ʽ
	/**
	*/
	UGString GetExpressionAt(UGint nIndex)const;
	//! \brief ����ĳ�ε��ֶα��ʽ
	/**
	*/
	void SetExpressionAt(UGint nIndex, const UGString& strExpression );

	//! \brief �õ�ĳ�εı���
	/**
	*/
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief ����ĳ�εı���
	/**
	*/
	void SetCaptionAt(UGint nIndex, const UGString& strCaption);

	//! \brief �õ�ĳ�ֶεķ��
	/**
	*/
	const UGStyle& GetStyleAt(UGint nIndex)const;
	//! \brief ����ĳ�εķ��
	/**
	*/
	void SetStyleAt(UGint nIndex, const UGStyle& style);
	
	//added by lugw 2007-04-28 �Զ�ά�ֶη�������ṩ�ӿ�
	//! \brief ����ĳ�εĶ�ά�ֶη��
	/**
	\param nIndex      �ֶ�����[in] 
	\param styleArray  ���ֶθ������ֶεķ������[in] 
	*/
	const UGArray<UGStyle>& GetStyleArrayAt(UGint nIndex)const;
	void SetStyleArrayAt(UGint nIndex, const UGArray<UGStyle>& styleArray);

	//! \brief ����ͳ��ͼ��������
	/**
	*/
	void SetGraphType(UGint nGraphType);		//nGraphType Ϊͳ��ͼ���ͣ���ȡֵ��ΧΪenum Type������ֵ
	//! \brief �õ�ͳ��ͼ��������
	/**
	*/
	UGint GetGraphType()const;						//nGraphType Ϊͳ��ͼ���ͣ���ȡֵ��ΧΪenum Type������ֵ
	
	//! \brief ������״ͼ���
	/**
	*/
	void SetBarWidth(UGdouble dBarWidth );
	//! \brief �õ���״ͼ���
	/**
	*/
	UGdouble GetBarWidth()const;

	//! \brief �õ�Ĭ�Ϸ���µ���ɫ
	/**
	*/
	UGColor GetDefaultColor()const;
	//! \brief ����Ĭ�Ϸ���µ���ɫ
	/**
	*/
	void SetDefaultColor(UGColor color);	

	//! \brief �õ���ֵ�͵���Сֵ
	/**
	*/
	UGdouble GetMinSumSize()const;
	//! \brief ���ö�ֵ�͵���Сֵ
	/**
	*/
	void SetMinSumSize(UGdouble dMinSumSize );
	
	//! \brief �õ���ֵ�͵����ֵ
	/**
	*/
	UGdouble GetMaxSumSize()const;
	//! \brief ���ö�ֵ�͵����ֵ
	/**
	*/
	void SetMaxSumSize(UGdouble dMaxSumSize );

	//! \brief �õ���ʼ�Ƕ�
	/**
	*/
	UGdouble GetStartAngle()const;
	//! \brief ������ʼ�Ƕ�
	/**
	*/
	void SetStartAngle(UGdouble dStartAngle);

	//! \brief ���÷ּ�ģʽ
	/**
	*/
	void SetGraduatedMode(UGint nGraduatedMode);
	//! \brief �õ��ּ�ģʽ
	/**
	*/
	UGint GetGraduatedMode()const;
	
	//! \brief �Ƿ�̶���С
	/**
	*/
	UGbool IsFixedSize()const;
	//! \brief �����Ƿ�̶���С
	/**
	*/
	void SetFixedSize(UGbool bFixedSize = false);

	UGbool IsBarLie()const;
	void SetBarLie(UGbool bBarLie = false);

	//! \brief �õ������Ƿ����������
	/**
	*/
	UGbool IsShowAxes()const;							
	//! \brief �����Ƿ����������
	/**
	*/
	void SetShowAxes(UGbool bShowAxes = true);			

	//! \brief �õ������Ƿ񻭳��������ı�
	/**
	*/
	UGbool IsShowAxesText()const;
	//! \brief �����Ƿ񻭳��������ı�
	/**
	*/
	void SetShowAxesText(UGbool bShowAxesText = true);	
	//! \brief �õ������Ƿ񻭳��������ı����
	/**
	*/
	const UGTextStyle& GetAxesTextStyle()const;			
	//! \brief �����Ƿ񻭳��������ı����
	/**
	*/
	void SetAxesTextStyle(UGTextStyle& TextStyle);		
	
	//! \brief �õ������Ƿ񻭳�����������
	/**
	*/
	UGbool IsShowAxesGrid()const;						
	//! \brief �����Ƿ񻭳�����������
	/**
	*/
	void SetShowAxesGrid(UGbool bShowAxesGrid = false);	
	
	//! \brief �õ��ֶ��ı����
	/**
	*/
	UGbool IsShowItemText()const;						
	//! \brief �����ֶ��ı����
	/**
	*/
	void SetShowItemText(UGbool bShowItemText = true);	
	//! \brief �õ��ֶ��ı����
	/**
	*/
	const UGTextStyle& GetItemTextStyle()const;
	//! \brief �����ֶ��ı����
	/**
	*/
	void SetItemTextStyle(UGTextStyle& TextStyle);

	//! \brief �õ��ı���ʽ
	/**
	*/
	UGint GetItemTextFormat()const;							
	//! \brief �����ı���ʽ
	/**
	*/
	void SetItemTextFormat(UGint TextFormat);
	
	//! \brief ר��ͼ�����Ƿ���ʾ��ֵ
	/**
	�õ��Ƿ���ʾ��ֵ��
	\return �Ƿ���ʾ���Ƹ�ֵ��1�����ǣ�0�����Ĭ��Ϊ��
	*/
	UGbool IsSupportNegative() const;
	//! \brief ר��ͼ�����Ƿ���ʾ��ֵ
	/**
	�趨�Ƿ���ʾ��ֵ��
	\param bFixed  �Ƿ���ʾ���Ƹ�ֵ[in]
	\remarks Ĭ������ʾ��ֵ��
	\remarks ��ֵ����ԭ�򣺣�ʼ�մ���ֵ������������ͼ������ͼ������ͼ����״ͼ����״ͼ����ά��״ͼ���������ᣩ���ư������᷽��
	\remarks ���û�ѡ���Ƿ������ڱ�ͼ����ά��ͼ��õ��ͼ����άõ��ͼ��������ר��ͼ-���Ρ�������ר��ͼ-���Σ�����û�ѡ��֧�ָ�ֵ����ֵ����ֵ��������Excel���������֧�ָ�ֵ���򲻶�����л���
	*/
	void SetSupportNegative(UGbool bNegative = true);
	
	//! \brief ����/����ƫ�����ֻ���ͳ��ͼ��
	/*
	**added by dongfei 2007-04-17
	*/
	UGbool	IsTextOffset() {return m_bTextOffset;};
	void	SetTextOffset(UGbool bText) {m_bTextOffset = bText;};
	
	//! \brief ͳ��ר��ͼ�����Ӧ
	/*
	\param pntHitTest    ���λ��[in]
	\param pDrawing      ���Ʋ���[in]
	\param pLayer        ר��ͼ���ڲ�[in]
	\param geoTextArray  �����ֶ���Ϣ[in/out]
	**
	*/
	UGbool HitTest(const UGPoint2D& pntHitTest,UGDrawing *pDrawing,UGLayer* pLayer,UGArray<UGGeoText>& geoTextArray);

	//! \brief ͳ��ר��ͼ����ķֶ�ר��ͼ��Ϣ
	/*
	\param nIndex         ��������[in]
	\return ������ķֶ�ר��ͼ��Ϣ
	**
	*/
	UGThemeRange& GetItemThemeRangeAt(UGint nIndex)const;
	//! \brief ͳ��ר��ͼ����ķֶ�ר��ͼ�Ƿ����
	/*
	\param nIndex         ��������[in]
	\return �Ƿ���ڷֶ�
	**
	*/
	UGbool IsItemThemeRangeExistAt(UGint nIndex)const;
	//! \brief ͳ��ר��ͼ����ķֶ�ר��ͼ��Ϣ
	/*
	\param nIndex         ��������[in]
	\param pThemeRange    ��������ֶ�ר��ͼ��Ϣ[in]
	**
	*/
	void SetItemThemeRangeAt(UGint nIndex,UGThemeRange& pThemeRange);
	
	//! \brief ��ȡר��ͼ�����hashcode
	virtual UGint GetHashCode() const;
	
	//! \brief ����ͳ��ר��ͼ�Ƿ��ö�
	/*
	*/
	void SetGraphAlwaysOnTop(UGbool bAlwaysOnTop);
	//! \brief �õ�ͳ��ר��ͼ�Ƿ��ö�
	/*
	*/
	UGbool IsGraphAlwaysOnTop()const;

	//! \brief �õ�ͳ��ר��ͼõ��ͼ�ε�õ��Ƕ�
	/*
	*/
	UGdouble GetRoseAngle()const;
	//! \brief ����ͳ��ר��ͼõ��ͼ�ε�õ��Ƕ�
	/*
	*/
	void SetRoseAngle(UGdouble dRoseAngle);

	UGDict<UGint, UGPoint2D> m_arrCustomGraph;

	//! \brief �����ⲿֵ
	void SetExternalValue(const UGString& strItemExpression, const UGString& strKey, const UGString& strExternalValue);

	//! \brief ��ȡָ��Item
	const UGGraphItem& GetItem(UGint nIndex)const;

	void Insert(const UGString& strExpression,UGint nIndex);
	


protected:  
	void Swap(const UGThemeGraph& theme);	
	UGSize2D CalculateGraphSize(UGdouble dSumValue);

	//! \brief �õ��ⲿֵ
	UGbool GetExternalValue(const UGString& strItemExpression, const UGString& strKey, UGString& strExternalValue)const;

protected:	
	UGGraph m_Graph;				// ͳ��ͼ����
	UGdouble m_dBarWidth;			// ��״ͼ���	
	UGdouble m_dMaxSum;				// �ֶ�֮�͵����ֵ
	UGdouble m_dMinSum;				// �ֶ�֮�͵���Сֵ	
	UGdouble m_dSqrtMaxSum;			// == sqrt(m_dMaxSum)
	UGdouble m_dSqrtMinSum;			// == sqrt(m_dMinSum)
	UGdouble m_dLogMaxSum;			// == log(m_dMaxSum)
	UGdouble m_dLogMinSum;			// == log(m_dMinSum)	

	UGSize2D m_szMin;				// ͼ����С�ߴ磨�������꣩
	UGSize2D m_szMax;				// ͼ�����ߴ磨�������꣩	
	
	UGTextStyle m_ItemTextStyle;	// ÿ��������ı����
	UGTextStyle m_ThemeTextStyle;	// ����ͳ��ͼ���ı����	
	UGbool		m_bTextOffset;		// ����ƫ�ƻ�������ͳ��ͼ��ƫ��
	UGbool m_bAlwaysOnTop;

	typedef UGDict<UGString,UGString> UGGraphDict;
	UGDict<UGString,UGGraphDict> m_GraphExternalData;

};

}

#endif // !defined(AFX_UGTHEMEGRAPH_H__BF50002A_00EF_41B1_B119_14ADACC6FB9A__INCLUDED_)
