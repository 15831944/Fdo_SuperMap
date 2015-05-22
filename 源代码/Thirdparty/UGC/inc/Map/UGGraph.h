// UGGraph.h: interface for the UGGraph class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGGraph.h 
   **************************************************************************************
    \author   �¹���
    \brief    ͳ��ͼͼ���࣬����ͳ��ͼ��ʾ�Ͳ�������                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGGRAPH_H__CF2642C9_F414_4403_BA26_CE72B9E54AAB__INCLUDED_)
#define AFX_UGGRAPH_H__CF2642C9_F414_4403_BA26_CE72B9E54AAB__INCLUDED_

#include "UGGraphItem.h"
#include "Geometry/UGGeometry.h"
#include "Drawing/UGDrawing.h"
#include "Base/UGTextStyle.h"
namespace UGC {

	struct ItemValues 
	{
		UGint nIndex;
		UGdouble* pItemValues;
		UGint nCount;
		ItemValues()
		{
			nIndex = -1;
			pItemValues = NULL;
			nCount = 1;
		};
	};

	struct HitTestInfo 
	{
		UGPoint2D pntHitTest;
		UGArray<UGGeoText> geoTextArray;
	};



class UGThemeGraph;

class MAP_API UGGraph  
{
	friend class UGThemeGraph;
public:	
	enum UGGraphType		//! \brief ͳ��ͼ����
	{
		gtArea = 0,	//! \brief ���ͼ
		gtStep = 1,	//! \brief ����ͼ
		gtLine = 2,	//! \brief ����ͼ
		gtPoint = 3,//! \brief ��״ͼ	
		gtBar = 4,	//! \brief ��״ͼ
		gtBar3D = 5,//! \brief ��ά��״ͼ
		gtPie = 6,	//! \brief ��ͼ
		gtPie3D = 7,//! \brief ��ά��ͼ
		gtRose = 8,	//! \brief õ��ͼ
		gtRose3D = 9, //! \brief ��άõ��ͼ
		gtPyramidBar = 10,	  //! \brief  ������ר��ͼ-����
		gtPyramidPolygon = 11,//! \brief  ������ר��ͼ-����
		gtStackedBar = 12,		//! \brief 
		gtStackedBar3D = 13,	
		gtRing = 14,			//! \brief  ��״
		
	};

	enum UGGraphTextFormat		//! \brief ͳ��ͼ�ı���ʽ
	{
		gtfPercent = 1,			//! \brief �ٷ���
		gtfValue = 2,			//! \brief ��ʵ��ֵ
		gtfCaption = 3,			//! \brief ����
		gtfCaptionPercent = 4,	//! \brief ����+�ٷ���	
		gtfCaptionValue = 5	//! \brief ����+��ʵ��ֵ		
	};

	enum UGGraphDataValue		//! \brief ͳ��ͼ����
	{
		allPositive = 1,         //! \brief ȫΪ����
		allNegative= 2,			//! \brief ȫΪ��ֵ
		others = 3,			    //! \brief ����
	};


public:
	UGGraph();
	virtual ~UGGraph();
	UGGraph(const UGGraph& Graph);	
	UGGraph& operator = (const UGGraph& Graph);	

public:
	//! \brief ������UGDrawing
	/*
	\remarks �����ı����õ�ʱ����ҪUGDrawing�����ж��Ƿ�ѹ�ǣ�����Ҫ�ȹ�����UGDrawing����
	*/
	UGbool AttachDrawing(UGDrawing* pDrawing);
	//! \brief ͳ��ר��ͼתΪ���ζ���
	/**
	\param pdValues			����ֵ[in]
	\param unValueCount		�θ���[in]
	\param pntAnchorPoint	ê��[in]
	\param szGraph			ͼ�δ�С[in]
	\param ItemValuesArray	��ά����[in]
	\return ����ת�ɵļ��ζ���
	\remarks ItemValuesArray��Ϣֻ������״ͼ��ά����ʱ��Ҫ
	*/
	UGGeometry* ConvertToGeometry(UGdouble *pdValues, UGuint unValueCount, const UGPoint& pntAnchorPoint, const UGSize& szGraph, UGArray<ItemValues*> ItemValuesArray = UGArray<ItemValues*>(0));
	//! \brief ���û��Ʋ���
	void SetDrawParamaters(UGDrawParamaters *pDrawParam);

	//! \brief ͳ��ͼ�ֶα��ʽ��������
	//! \brief ������ж�
	void RemoveAll();
	//! \brief �����ֶ�
	UGint Add(const UGString& strExpression);
	//! \brief �����ֶε�λ��
	UGbool Swap(UGint nOldIndex, UGint nNewIndex);
	//! \brief ɾ��ĳ�ֶ�
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);

	//! \brief ��ȡ�ֶθ���
	UGint GetCount()const;
	//! \brief �����ֶθ���
	void SetCount(UGint nItemCount);	


	//! \brief ��ȡĳ�ֶα��ʽ
	UGString GetExpressionAt(UGint nIndex)const;
	//! \brief ����ĳ�ֶα��ʽ
	void SetExpressionAt(UGint nIndex, const UGString& strExpression );

	//! \brief ��ȡĳ�ֶα���
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief ����ĳ�ֶα���
	void SetCaptionAt(UGint nIndex, const UGString& strCaption);

	//! \brief ��ȡĳ�ֶη��
	const UGStyle& GetStyleAt(UGint nIndex)const;
	//! \brief ����ĳ�ֶη��
	void SetStyleAt(UGint nIndex, const UGStyle& style);

	//! \brief ��ȡĳ�ֶη�����飬��ά�������õ�
	const UGArray<UGStyle>& GetStyleArrayAt(UGint nIndex)const;
	//! \brief ����ĳ�ֶη�����飬��ά�������õ�
	void SetStyleArrayAt(UGint nIndex, const UGArray<UGStyle>& styleArray);
	
	//! \brief ����ͳ��ͼ
	/**
	\param pDrawing			������[in]
	\param pRecord			���Ƶļ�¼��[in]
	\param pValues			����ֵ[in]
	\param unValueCount		ֵ�ĸ���[in]
	\param pntAnchorPoint	���Ƶ�ê��[in]
	\param szGraph			���ƵĴ�С[in]
	\param ItemValuesArray	��״ͼ��ά�����ֵ[in]
	\return ����ת�ɵļ��ζ���
	\remarks �����Ƿ�ɹ�
	*/
	UGbool Draw(UGDrawing *pDrawing,UGRecordset* pRecord, UGdouble *pValues, UGuint unValueCount, const UGPoint& pntAnchorPoint, const UGSize& szGraph,UGArray<ItemValues*> ItemValuesArray = UGArray<ItemValues*>(0));

	//! \brief nGraphType Ϊͳ��ͼ���ͣ���ȡֵ��ΧΪenum Type������ֵ
	void SetGraphType(UGint nGraphType);		
	//! \brief �õ�ͳ��ͼ����
	UGint GetGraphType()const;						
	
	//! \brief ������״ͼ���
	void SetBarWidth(UGint nBarWidth );
	//! \brief �õ���״ͼ���
	UGint GetBarWidth()const;

	//! \brief �õ�Ĭ����ɫ
	UGColor GetDefaultColor()const;
	//! \brief ����Ĭ����ɫ
	void SetDefaultColor(UGColor color);

	//! \brief �õ���ʼ�Ƕ�
	UGint GetStartAngle()const;
	//! \brief ������ʼ�Ƕ�
	void SetStartAngle(UGint nStartAngle);

	//! \brief �Ƿ�̶���С
	UGbool IsFixedSize()const;
	//! \brief �����Ƿ�̶���С
	void SetFixedSize(UGbool bFixedSize = false);

	UGbool IsBarLie()const;
	void SetBarLie(UGbool bBarLie = false);

	//! \brief �ж��Ƿ񻭳�������
	UGbool IsShowAxes()const;							
	//! \brief �����Ƿ񻭳�������;
	void SetShowAxes(UGbool bShowAxes = true);			

	//! \brief  �ж��Ƿ񻭳��������ı�
	UGbool IsShowAxesText()const;						
	//! \brief  �����Ƿ񻭳��������ı�
	void SetShowAxesText(UGbool bShowAxesText = true);	
	//! \brief  �õ��������ı����
	UGTextStyle GetAxesTextStyle()const;				
	//! \brief  �����������ı����
	void SetAxesTextStyle(const UGTextStyle& TextStyle);
	
	//! \brief  �õ���������ʱ�Ƿ񻭳�����
	UGbool IsShowAxesGrid()const;					
	//! \brief  ���û�������ʱ�Ƿ񻭳�����
	void SetShowAxesGrid(UGbool bShowAxesGrid = false);
	
	//! \brief  �õ��ֶ��ı����
	UGbool IsShowItemText()const;						
	//! \brief  �����ֶ��ı����
	void SetShowItemText(UGbool bShowItemText = true);	

	//! \brief  �õ��ֶ��ı����
	UGTextStyle GetItemTextStyle()const;				
	//! \brief  �����ֶ��ı����
	void SetItemTextStyle(const UGTextStyle& TextStyle);

	//! \brief �õ��ı���ʽ
	UGint GetItemTextFormat()const;						
	//! \brief �����ı���ʽ
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
	\remarks Ĭ���²���ʾ��ֵ��
	\remarks ��ֵ����ԭ�򣺣�ʼ�մ���ֵ������������ͼ������ͼ������ͼ����״ͼ����״ͼ����ά��״ͼ���������ᣩ���ư������᷽��
	\remarks ���û�ѡ���Ƿ������ڱ�ͼ����ά��ͼ��õ��ͼ����άõ��ͼ��������ר��ͼ-���Ρ�������ר��ͼ-���Σ�����û�ѡ��֧�ָ�ֵ����ֵ����ֵ��������Excel���������֧�ָ�ֵ���򲻶�����л���
	*/
	void SetSupportNegative(UGbool bNegative = false);

	//! \brief ����/�����Ƿ���ʾǣ���� added by dongfei 2007-04-17
	void		SetAllowLeaderLine(UGbool bAllowLeaderLine){m_bAllowLeaderLine = bAllowLeaderLine;};
	UGbool		IsAllowLeaderLine()const {return m_bAllowLeaderLine;};
	//! \brief ����/����ǣ���߷ָ�
	void		SetLeaderLineStyle(UGStyle & style){m_LeaderLineStyle = style;};
	UGStyle		GetLeaderLineStyle()const {return m_LeaderLineStyle;};
	void		SetTextOffset(UGdouble offsetX,UGdouble offsetY);
	void		SetTextOffset(UGSize2D size);
	UGSize2D	GetTextOffset()const {return m_szOffset;};
	//! \brief ��/дxml
	virtual UGString ToXML(UGint nVersion = 0)const;
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief ���ñ��û������
	void SetTextBuffer(UGSize2D& sz) {m_szBuffer = sz;};
	void SetTextBuffer(UGdouble dBufferX, UGdouble dBufferY) 
	{
		m_szBuffer.cx = dBufferX;
		m_szBuffer.cy = dBufferY;
	}
	UGSize2D	GetTextBuffer()const {return m_szBuffer;};

	//added by lugw 2007-05-09 �����Ӧ����غ���
	//! \brief ר��ͼ�����Ӧ
	/**
	\param pHitTestInfo    �������Ϣ[in/out]
	\param pDrawing        ������Ϣ[in]
	\param pValues         ��������[in]
	\param unValueCount    ���Ƹ���[in]
	\param pntAnchorPoint  ����ê��[in]
	\param szGraph         ���ƴ�С[in]
	\remarks Ĭ���²���ʾ��ֵ��
	*/
	UGbool HitTest(HitTestInfo* pHitTestInfo, UGDrawing *pDrawing, UGdouble *pValues, UGuint unValueCount, const UGPoint& pntAnchorPoint, const UGSize& szGraph,UGArray<ItemValues*> ItemValuesArray = UGArray<ItemValues*>(0));
	
	//! \brief ר��ͼ��ͼ�������Ӧ
	/**
	\param pHitTestInfo    �������Ϣ[in/out]
	\param pDrawing        ������Ϣ[in]
	\param pValues         ��������[in]
	\param unValueCount    ���Ƹ���[in]
	\param pntAnchorPoint  ����ê��[in]
	\param szGraph         ���ƴ�С[in]
	\remarks Ĭ���²���ʾ��ֵ��
	*/
	UGbool HitTestGeometry(HitTestInfo* pHitTestInfo ,UGdouble *pdValues, UGuint unValueCount, const UGPoint& pntAnchorPoint, const UGSize& szGraph, UGArray<ItemValues*> ItemValuesArray = UGArray<ItemValues*>(0));

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

	//! \brief �õ�õ��ͼ�ε����ýǶ�
	UGint GetRoseAngle()const;
	//! \brief ����õ��ͼ�εĽǶ�
	void SetRoseAngle(UGint nRoseAngle);

	//! \brief ��ȡָ��Item
	const UGGraphItem& GetItem(UGint nIndex)const;

	void Insert(const UGString& strExpression,UGint nIndex);


protected:
	UGRect GetBoundingRect(UGPoint pntGraph, UGSize szGraph);	//! \brief ͳ��ͼ�����
	UGRect GetCircleSize(UGSize szGraph);						//! \brief ��ͼ,õ��ͼ����򣬱�����ͳ��ͼ�����СһЩ.
	UGdouble GetThickness(UGSize szGraph, UGuint unItemCount);	//! \brief ͳ��ͼ�Ŀ�ȣ������СһЩ

	void MaxMin(UGdouble *pValues, UGuint unItemCount);			//! \brief ����ͳ�����ݵ�������Сֵ(m_minValue,m_maxValue)
	UGString GetItemString(UGdouble dValue, UGint nIndex);

	//! \brief  �����ǻ��ƺ���
protected:
	//! \brief  �滭������
	void DrawAxes(UGDrawing *pDrawing, UGPoint pntAnchorPoint, UGSize szGraph, UGuint unItemCount);
	void DrawAxes(UGDrawing *pDrawing, UGPoint pntAnchorPoint, UGSize szGraph);
	void DrawAxes3D(UGDrawing *pDrawing, UGPoint pntAnchorPoint, UGSize szGraph, UGuint unItemCount);
	void DrawAxes3D(UGDrawing *pDrawing, UGPoint pntAnchorPoint, UGSize szGraph);	

	//! \brief ��ʾ����ר��ͼ��ͳһ����˵����
	/*
	\param UGGraphics *pGraphics: ��ʾGraphics
	\param UGdouble *pValues ͳ����������
	\param UGuint unItemCount: ͳ���������鳤��
	\param UGPoint pntGraph : ͳ��ͼ�Ķ�λ��(���ĵ�)
	\param UGSize szGraph : ͳ��ͼ��С
	**
	*/
	UGbool DrawRose3D(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawRose(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawPoint(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawLine(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawArea(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawStep(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	
	UGbool DrawBar(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawBar3D(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawPie(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawPie3D(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);

	//{{
	UGbool DrawPyramidBar(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawPyramidPoly(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);

	UGbool DrawStackBar(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawStackBar3D(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	//}}

	//������תGeometry����
protected:
	//ת������ΪGeometry
	UGGeometry* AxesToGeometry(UGPoint pntAnchorPoint, UGSize szGraph, UGint unItemCount);
	UGGeometry* Axes3DToGeometry(UGPoint pntAnchorPoint, UGSize szGraph, UGint unItemCount);

	/*
	\param UGdouble *pValues ͳ����������
	\param UGuint unItemCount: ͳ���������鳤��
	\param UGPoint pntGraph : ͳ��ͼ�Ķ�λ��(���ĵ�)
	\param UGSize szGraph : ͳ��ͼ��С
	**
	*/
	UGGeometry* Rose3DToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph,HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* RoseToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph,HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* PointToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* LineToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGGeometry* AreaToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* StepToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	
	UGGeometry* BarToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, UGArray<ItemValues*> ItemValuesArray = UGArray<ItemValues*>(0), HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* Bar3DToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* PieToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* Pie3DToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);

	UGGeometry* PyramidBarToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* PyramidPolyToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);

	UGGeometry* StackBarToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* StackBar3DToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* RingToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	//! \brief ��ǣ������ӵ����϶�����
	/**	
	\param pCompound  �����ǣ���ߵĸ��϶���
	\return	����ƫ�ƺ�ĵ㣬�����ֶ�λ��	
	*/
	UGbool	 AddLeaderLine(UGGeoCompound * pCompound, UGPoint& pntFrom, UGPoint& pntTo);
	//! \brief ѡȡ�ı����õ�λ��
	/**	
	\param pOffset		�����ǣ���ߵĸ��϶���
	\param pTheme		����ר��ͼ��������ƫ�ƺ��bounds
	\param pGeoText		��ѡȡλ�õ��ı�
	\param pDrawing		���øö����ж��Ƿ�ѹ��
	\param szBuffer		����ѹ�ǵĻ������
	\return	���ر��ú�����ֶ�λ��	
	*/
	UGint SelectTextPos(const UGSize2D *pOffset, UGThemeGraph *pTheme, UGGeoText* pGeoText,UGSize2D szBuffer = UGSize2D(-1.0,-1.0));
protected:
	inline UGColor DarkColor(UGColor color, UGdouble dRatio);		//! \brief ����ɫ�䰵��
	UGint GetMinUnit(UGdouble& dUnit);							//! \brief  �õ�һ���̶ȵ�λ�Ĵ�С,���ض��ٸ��̶ȵ�λ�����Ϊ0�Ͳ��ɹ�
	
//Attributes
protected:	
	UGArray<UGGraphItem> m_Items;
	UGint m_nType;					//! \brief  make type member var	
	
	UGint m_nStartAngle;			//! \brief  ��ͼ��õ��ͼ�ȵ���ʼ�Ƕȣ�Ĭ��Ϊ0(0.1��)
	UGint m_nBarWidth;				//! \brief  ��״ͼ�������߼����꣩
	UGColor m_DefaultColor;			//! \brief  Ĭ�ϵ���ɫ
	UGint m_TextFormat;				//! \brief  �ı���ʽ		
	UGuint m_unOptions;				//! \brief  ����ѡ��

//! \brief  ����Ϊ��ʱʹ������
protected:	
	UGDrawParamaters* m_pDrawParam; //! \brief  ��ͼ��ʾ����,Ϊ�˼����ı���ʾ��С
	UGTextStyle m_ItemTextStyle;	//! \brief  ÿ��������ı����
	UGTextStyle m_ThemeTextStyle;	//! \brief  ����ͳ��ͼ���ı����	
	UGdouble m_dMinValue;			//! \brief ͳ�����ݵ���Сֵ
	UGdouble m_dMaxValue;			//! \brief ͳ�����ݵ����ֵ
	UGdouble m_dSum;				//! \brief ͳ�����ݵ��ܺ�
	//! \brief added by lugw ��������������֧�ָ�ֵ�Ļ����������Ҫ�õ�����¼���ݵ������Сֵ,��ʱ����������СֵΪ�����ֵ�������Сֵ
	UGint m_bNegative;
	UGdouble m_dMinValueN;           //! \brief ͳ�����ݵ���Сֵ
	UGdouble m_dMaxValueN;           //! \brief ͳ�����ݵ����ֵ
	
	UGbool   m_bAllowLeaderLine;	 //! \brief �Ƿ���ʾǣ���� added by dongfei 2007-04-17
	UGSize2D m_szOffset;			 //! \brief �ı���ƫ����
	UGStyle  m_LeaderLineStyle;		 //! \brief ǣ���߷��
	UGSize2D m_szBuffer;			 //! \brief ���û��巶Χ

	UGDrawing* m_pDrawing;			//! \brief �����ж��Ƿ�ѹ�� 

	UGint m_nRoseAngle;
	UGRecordset* m_pRecordet;
};

}

#endif // !defined(AFX_UGGRAPH_H__CF2642C9_F414_4403_BA26_CE72B9E54AAB__INCLUDED_)
