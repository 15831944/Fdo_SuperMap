// UGThemeSymbol.h: interface for the UGThemeSymbol class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeSymbol.h
   **************************************************************************************
    \author   �¹���
    \brief    ����ר��ͼ�࣬����ͨ���������ĵ�����ʾͼ�ε�ר��ͼ�඼ͨ����������                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMESYMBOL_H__12471BD8_C034_4AEB_ABDD_174C09E209D4__INCLUDED_)
#define AFX_UGTHEMESYMBOL_H__12471BD8_C034_4AEB_ABDD_174C09E209D4__INCLUDED_

#include "UGTheme.h"
#include "Geometry/UGGeoText.h"
#include "Drawing/UGDrawing.h"

#define	UG_THEME_OPTIONS_GRADUATED_MODE		0x000000ff	// �ּ���ʽλ����ģ��

#define UG_THEME_OPTIONS_ENABLE_FLOW		0x00000100	// �Ƿ�����
#define UG_THEME_OPTIONS_SHOW_LEADERLINE	0x00000200	// �Ƿ���ʾǣ����
#define UG_THEME_OPTIONS_AUTO_AVOID			0x00000400	// �Ƿ��Զ�����

#define	UG_THEME_OPTIONS_ENABLE_NEGATIVE	0x00000800	// �Ƿ���ʾ��ֵ
#define UG_THEME_OPTIONS_ENABLE_ZERO		0x00800000	// �Ƿ���ʾ��ֵ

#define UG_THEME_OPTIONS_ALONG_LINE			0x00001000	// �Ƿ�����
#define UG_THEME_OPTIONS_FIXED_ANGLE		0x00002000	// �Ƿ�̶��Ƕ�
#define UG_THEME_OPTIONS_IGNORE_OBJECT		0x00008000	// �Ƿ����С����
#define SM_THEME_LABEL_OPTIONS_FIXED_REPEAT 0x00400000	// �Ƿ�̶�
#define UG_THEME_OPTIONS_SELF_OVERLAP		0x01000000	// �Ƿ����ཻ

#define UG_THEME_OPTIONS_FIXED_OFFSET		0x00004000	// �Ƿ�̶�ƫ��

#define UG_THEME_OPTIONS_SHOW_AXES			0x00010000
#define UG_THEME_OPTIONS_SHOW_AXESTEXT		0x00020000
#define UG_THEME_OPTIONS_SHOW_ITEMTEXT		0x00040000
#define UG_THEME_OPTIONS_SHOW_AXESGRID		0x00080000
#define UG_THEME_OPTIONS_BAR_LIE			0x00100000
#define UG_THEME_OPTIONS_FIXED_SIZE			0x00200000


namespace UGC {


//const UGdouble dtan30 = 0.57735026918962576450914878050196;
const UGdouble dtan60 = 1.7320508075688772935274463415059;

class MAP_API UGThemeSymbol : public UGTheme  
{
public:
	typedef	enum				//ע��ѡȡ�ı�עλ�� added by dongfei 2007-04-10
	{
		UG_POS_TOPLEFT = 0,		
		UG_POS_TOPCENTER = 1,
		UG_POS_TOPRIGHT = 2,
		UG_POS_CENTERLEFT = 3,
		UG_POS_CENTER = 4,
		UG_POS_CENTERRIGHT = 5,
		UG_POS_BOTTOMLEFT = 6,
		UG_POS_BOTTOMCENTER = 7,
		UG_POS_BOTTOMRIGHT = 8
	}   emTextPositionType;

public:
	UGThemeSymbol();
	virtual ~UGThemeSymbol();

public:
	//! \brief  �õ�X��ƫ��
	virtual UGString GetOffsetXFieldName(UGbool bAddExpression = true)const = 0;
	//! \brief  �õ�Y��ƫ��
	virtual UGString GetOffsetYFieldName(UGbool bAddExpression = true)const = 0;

	//! \brief  �õ���Ӧ��¼����ƫ��
	UGSize2D FindOffset(UGRecordset *pRecordset)const;
	//! \brief  ���ƫ���ֶ��Ƿ�Ϸ�
	UGbool CheckOffsetFieldType(UGint nType);

	//! \brief  �õ�X��ƫ�Ƶı��ʽ
	UGString GetOffsetXExpression()const;
	//! \brief  ����X��ƫ�Ƶı��ʽ
	void SetOffsetXExpression(const UGString& strOffsetXExpression);

	//! \brief  �õ�Y��ƫ�Ƶı��ʽ
	UGString GetOffsetYExpression()const;
	//! \brief  ����Y��ƫ�Ƶı��ʽ
	void SetOffsetYExpression(const UGString& strOffsetYExpression);
	
	//! \brief  �Ƿ�̶�ƫ����
	UGbool IsFixedOffset()const;
	//! \brief  �����Ƿ�ƫ��
	void SetFixedOffset(UGbool bFixedOffset = false);

	//! \brief  �Ƿ�������ʾ
	UGbool IsEnableFlow()const;
	//! \brief  �����Ƿ�������ʾ
	void SetEnableFlow(UGbool bEnableFlow = true);

	//! \brief  �Ƿ��Զ�����
	UGbool IsAutoAvoid()const;
	//! \brief  �����Ƿ��Զ�����
	void SetAutoAvoid(UGbool bAutoAvoid = false);

	//! \brief  �Ƿ���ʾǣ����
	UGbool IsShowLeaderLines()const;
	//! \brief  �����Ƿ���ʾǣ����
	void SetShowLeaderLines(UGbool bShowLeaderLines = false);

	//! \brief  �õ�ǣ���߷��
	const UGStyle& GetLeaderLineStyle()const;
	//! \brief  ����ǣ���߷��
	void SetLeaderLineStyle(const UGStyle& Style);	
	
	//added by lugw 2007-03-12 �ṩ�̶�ͳ��ͼ�ӿ�
	//! \brief  �����Ƿ�̶�ͳ��ͼ����ͼ����
	/**
	\param bFixedGraph  �Ƿ�̶�ͳ��ͼ[in]
	\remarks ȱʡֵΪfalse�����̶�
	*/
	void SetFixedGraph(UGbool bFixedGraph = false);
	//! \brief  �õ��Ƿ�̶�ͳ��ͼ����ͼ����
	/**
	\return �õ��Ƿ�̶���ֵ
	*/
	UGbool IsFixedGraph() const;

	//! \brief  added by dongfei 2007-04-12
	/*	����/�������ֱ��õĻ������
	**
	*/
	void SetBuffer(UGdouble dBufferX,UGdouble dBufferY)
	{
		m_dBufferX = dBufferX;
		m_dBufferY = dBufferY;
	}
	UGdouble GetBufferX(){return m_dBufferX;};
	UGdouble GetBufferY(){return m_dBufferY;};

	//! \brief �������ֺ�ѡλ�õ����ȼ�  added by dongfei 2007-04-09
	/*
	**�������ȼ���Ϊ0-9����0�������Ǹú�ѡλ�ã�1-9�����ȼ����ν��� ���ظ�����ͬһ���ȼ���
	*/
	void SetPosPriority(UGuint* pPosPriority);
	void SetTopLeftPriority(UGuint priority = 1)			{m_uPosPriority[0] = priority;};
	void SetTopCenterPriority(UGuint priority = 1)			{m_uPosPriority[1] = priority;};
	void SetTopRightPriority(UGuint priority = 1)			{m_uPosPriority[2] = priority;};
	void SetCenterLeftPriority(UGuint priority = 1)			{m_uPosPriority[3] = priority;};
	void SetCenterPriority(UGuint priority = 1)				{m_uPosPriority[4] = priority;};
	void SetCenterRightPriority(UGuint priority = 1)		{m_uPosPriority[5] = priority;};
	void SetBottomLeftPriority(UGuint priority = 1)			{m_uPosPriority[6] = priority;};
	void SetBottomCenterPriority(UGuint priority = 1)		{m_uPosPriority[7] = priority;};
	void SetBottomRightPriority(UGuint priority = 1)		{m_uPosPriority[8] = priority;};

	void	GetPosPriority(UGArray<UGuint>& posPriorityArray);
	UGuint	GetPosPriority(UGint index)		{return m_uPosPriority[index];};
	UGuint	GetTopLeftPriority()			{return m_uPosPriority[0];};
	UGuint	GetTopCenterPriority()			{return m_uPosPriority[1];};
	UGuint	GetTopRightPriority()			{return m_uPosPriority[2];};
	UGuint	GetCenterLeftPriority()			{return m_uPosPriority[3];};
	UGuint	GetCenterPriority()				{return m_uPosPriority[4];};
	UGuint	GetCenterRightPriority()		{return m_uPosPriority[5];};
	UGuint	GetBottomLeftPriority()			{return m_uPosPriority[6];};
	UGuint	GetBottomCenterPriority()		{return m_uPosPriority[7];};
	UGuint	GetBottomRightPriority()		{return m_uPosPriority[8];};
	//! \brief added by dongfei 2007-04-10
	/*
	**����ע�ǵĺ�ѡ���λ�����¼���ע�ǵ���ʾλ��
	*/
	void  ReCalcTextPos(const UGSize2D *szOffset, UGGeoText* pGeoText, emTextPositionType emTextPos);
	void  ReCalcRectPos(UGRect *pRect, const UGSize& szOffset, emTextPositionType emTextPos);
	//! \brief added by dongfei 2007-04-10
	/*
	** �Ӻ�ѡλ����ѡ��ע�Ǳ�ע��λ�ã�Ϊ0�򲻱�ע��1-9��Ӧλ������
	**													 ___________ 
	**													|1	|2  |3  |
	**													|___|___|___|
	**													|4	|5  |6  |				
	**													|___|___|___|
	**													|7  |8  |9  |	
	**													|___|___|___|
	\param pOffset ��������ڶ�λ���ƫ����
	\param pGeoText �趨λ�����֣����ֶ��������Ķ��룬����ƫ��
	*/
	UGint SelectLabelPos( UGGeoText* pGeoText,UGDrawing *pDrawing,const UGSize2D *pOffset,UGSize2D szBuffer = UGSize2D(-1.0,-1.0),UGbool bChangeTextStyle = true);
	UGint SelectLabelPos( UGGeoCompound* pCompound, UGDrawing *pDrawing,const UGSize2D *pOffset, const UGPoint2D& pntCentroid, const UGTextStyle& textstyle);
	//���ʹ���߼����� ���������߼�����Ƚ� �������Ҫת���߼������
	UGint SelectRectPos(UGRect* pRect,UGDrawing *pDrawing,const UGSize& szOffset,UGSize szBuffer = UGSize(-1,-1));

	//! \brief ��ȡר��ͼ�����hashcode
	virtual UGint GetHashCode() const = 0;

	void GeometryOffsetByAlign(UGGeoCompound* pCompound, const UGPoint2D& pntCentroid, UGint nAlign);
protected:  
	void Swap(const UGThemeSymbol& theme);	

protected:	
	UGString m_strOffsetXExpression;
	UGString m_strOffsetYExpression;
	UGStyle m_LeaderLineStyle;	
	UGuint m_unOptions;					//������ǩ���Զ����õ�ѡ��
	//! \brief  �����Ƿ�̶�ͳ��ͼ��Ϣ
	/**
	\remarks Ĭ��Ϊ��ֵΪ0
	*/
	UGbool m_bFixedGraph;

	UGuchar m_uPosPriority[9];	//added by dongfei 2007-04-09 ���ֺ�ѡλ�õ����ȼ� 
								//��ѡλ���������еĴ��˳���� 
								//						 ___________ 
								//						|1	|2  |3  |
								//						|___|___|___|
								//						|4	|5  |6  |				
								//						|___|___|___|
								//						|7  |8  |9  |	
								//						|___|___|___|
	//added by dongfei 2007-04-12
	UGdouble	m_dBufferX;				//x�����ϱ��õĻ������
	UGdouble	m_dBufferY;				//y�����ϱ��õĻ������
	UGchar		m_nThemePriority;		//ר��ͼ�����ȼ� Ĭ��Ϊ0�����ȼ���ͣ�1����ߣ��������֧�ֵ�255�� 1-255�����ȼ����ν���

};

}

#endif // !defined(AFX_UGTHEMESYMBOL_H__12471BD8_C034_4AEB_ABDD_174C09E209D4__INCLUDED_)
