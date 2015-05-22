// UGThemeLabel.h: interface for the UGThemeLabel class.
//
//////////////////////////////////////////////////////////////////////

/**
   **************************************************************************************
    \file     UGThemeLabel.h
   **************************************************************************************
    \author   �¹���
    \brief    ��ǩר��ͼ�ࡣ                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMELABEL_H__5FD9A9BE_3A6F_4D8D_9BF0_EEDFA9C7B072__INCLUDED_)
#define AFX_UGTHEMELABEL_H__5FD9A9BE_3A6F_4D8D_9BF0_EEDFA9C7B072__INCLUDED_

#include "UGThemeSymbol.h"
#include "Base/UGTextStyle.h"
//#include "Geometry/UGGeoText.h"
#include "UGLayer.h"

namespace UGC {

//added by lugw 2007-04-02  ʵ�ֱ�ǩר��ͼ�е����ı�������ù��ܣ����÷�Χ�ֶε���ͬ����
class MAP_API UGLabelTextStyle  
{
public:
	UGLabelTextStyle();
	~UGLabelTextStyle();
	UGLabelTextStyle(const UGLabelTextStyle& TextStyle);
	UGLabelTextStyle& operator = (const UGLabelTextStyle& TextStyle);

public:
	UGbool m_bVisible;				//! \brief �ɼ�
	UGString m_strCaption;			//! \brief ����
	UGTextStyle m_TextStyle;				//! \brief ���

};

#define LABEL_DIVISION "[/]"

class MAP_API UGThemeLabel : public UGThemeSymbol  
{
public:
	enum UGLabelBackType		//! \brief ��������
	{
		NoneBG = 0,				//! \brief  �ձ���
		Rect = 1,				//! \brief  ���α���
		RoundRect = 2,			//! \brief  Բ�Ǿ��α���
		Ellipse = 3,			//! \brief  ��Բ�α���
		Diamond = 4,			//! \brief  ���α���
		Triangle = 5,			//! \brief  �����α���
		Circle = 6,			    //! \brief  Բ�α���
		Marker = 100			//! \brief  ���ű���
	};

	enum UGLabelOverLengthMode
	{
		UGOverLengthNone    = 0,   //! \brief ������
		UGOverLengthOmit    = 1,   //! \brief ʡ��
		UGOverLengthNewline = 2,   //! \brief ����
	};

	//added by lugw 2007-04-03 ���շ�Χר��ͼ�ֶε���������
//	enum UGClassType
//	{
//		ctEqualDistance,
//		ctExtraction,
//		ctStdev,
//		ctLogarithm,
//		ctQuantile,
//		ctCustomInterval
//	};

	enum LabelLineDirection		                            //! \brief  ��������ģʽ
	{
		UGDirectionAlongLine = 0,							//! \brief  ���߷�����
		UGDirectionLeftTopToRightBottom = 1,				//! \brief  ���ϵ��£�������
		UGDirectionRightTopToLeftBottom = 2,				//! \brief  ���ϵ��£����ҵ���
		UGDirectionLeftBottomToRightTop = 3,				//! \brief  ���µ��ϣ�������
		UGDirectionRightBottomToLeftTop = 4,				//! \brief  ���µ��ϣ����ҵ���
	};

public:
	UGThemeLabel();
	virtual ~UGThemeLabel();
	UGThemeLabel(const UGThemeLabel& ThemeLabel);
	UGThemeLabel& operator = (const UGThemeLabel& ThemeLabel);

public:
	//! \brief  ��ǩר��ͼ�Ƿ���Ч
	virtual UGbool IsValid()const;
	//! \brief  ��ǩר��ͼ����ΪXML��Ϣ
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief  ��ǩר��ͼ��ȡXML��Ϣ
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief  ��ǩר��ͼ����ֶ��Ƿ�Ϸ�
	virtual UGbool CheckFieldType(UGint nType);
	//! \brief  ��ǩר��ͼ��ȡ�ֶ�
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;
	//! \brief  ����������ʽʱ���ֶ���
	UGbool GetFieldNames(UGArray<UGString>& arrExpressions,UGbool bAddExpression = true)const;
	
	//! \brief  ��ǩר��ͼ��ȡX��ƫ��
	virtual UGString GetOffsetXFieldName(UGbool bAddExpression = true)const;
	//! \brief  ��ǩר��ͼ��ȡY��ƫ��
	virtual UGString GetOffsetYFieldName(UGbool bAddExpression = true)const;

	//! \brief  ��ǩר��ͼ�Ƿ����߱��
	UGbool IsAlongLine()const;
	//! \brief  �����Ƿ����߱��
	void SetAlongLine(UGbool bAlongLine = false);

	//! \brief  �Ƿ�̶��Ƕ�
	UGbool IsFixedAngle()const;
	//! \brief  �����Ƿ�̶��Ƕ�
	void SetFixedAngle(UGbool bFixedAngle = false);

	//! \brief  �Ƿ����С����
	UGbool IsIgnoreLittleObject()const;
	//! \brief  �����Ƿ����С����
	void SetIgnoreLittleObject(UGbool bIgnoreLittleObject);

	//! \brief  �Ƿ����ཻ
	UGbool IsSelfOverlap()const;
	//! \brief  �����Ƿ����ཻ
	void SetSelfOverlap(UGbool bAlongLine = false);
	
	//! \brief  �õ��ֶα��ʽ
	UGString GetExpression()const;
	//! \brief  �����ֶα��ʽ
	void SetExpression(const UGString& strExpression);

	//! \brief  �õ�������
	const UGTextStyle& GetLabelStyle()const;
	//! \brief  ����������
	void SetLabelStyle(const UGTextStyle& LabelStyle);
	
	//! \brief  �õ��������
	const UGStyle& GetBackStyle()const;
	//! \brief  ���ñ������
	void SetBackStyle(const UGStyle& style);
	
	//! \brief  �õ���������
	UGint GetBackType()const;
	//! \brief  ���ñ�������
	void SetBackType(UGint nBackType);
	//! \brief  �õ���������
	UGbool IsHasSpecialKey()const;
	
	//! \brief  ��������ǩ�ӿ�
	//! \brief  �õ�������ǩ��������
	UGint GetOverLengthModeType()const;
	//! \brief  ���ó�����ǩ��������
	void SetOverLengthModeType(UGint nTextLengthLimit);
	//! \brief  �õ�������ǩ��������
	UGint GetTextLengthLimit()const;
	//! \brief  ���ó�����ǩ��������
	void SetTextLengthLimit(UGint nTextLengthLimit);
	
	/*********************************************
	************Ϊ��ͳ��ר��ͼҲ�ܱ���************
	*****���õ�һЩ��������������ThemeSymbol******
	**********************************************/

	//! \brief added by dongfei 2007-04-14 
	/*
	**����/��ȡ�˱�ǩר��ͼ�����ȼ�
	*/
	void  SetThemePriority(UGint nPriority){m_nThemePriority = nPriority;};
	UGint GetThemePriority(){return m_nThemePriority;};

	//added by lugw 2007-04-02 �ṩ����ÿ����ǩ�ķ�񣬲������Ʒ�Χ�ֶεķ�ʽ������Ч�ʿ��ǣ�Ĭ���²�ʹ�ô˷�����ȡ�ı����ֻ�����û�ѡ��ʹ�õ��������ı����ʱ���á�
	//! \brief  ����ֶ�����
	/**
	\param pDatasetV         ���ҵ����ݼ�[in]
	\param JoinItems         ��ҹ�������[in]
	\param strExpression     �ı��ֶεı��ʽ[in]
	\param arrValues         �������ݼ���Ӧ���ʽ���ֶ�ֵ[in/out]
	\return �ɹ��ֶ��򷵻�true����֮Ϊfalse
	*/
	UGbool CalculateExtremum(UGDatasetVector* pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression, UGArray<UGdouble>& arrValues);
	UGRecordset * QueryWithExpression(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression);
	//! \brief  ���������ı����ʱ�ṩ��Ĭ�ϵķ��ֶ�
	/**
	*/
	void MakeDefaultTextStyles(UG_ENUM_STOCK_GRADIENT_SET_STYLE nIndex);
	//! \brief  ���������ı����ʱ�ṩ��Ĭ��ʵ�ֺ���
	/**
	\param nClassType         �ֶ�����[in]
	\param nClasses           �ֶθ���[in]
	\param aryValues          ���ݼ����ֶ�ֵ[in]
	\teturn �ɹ�����true����֮Ϊfalse
	*/
	UGbool MakeDefault(UGint nClassType, UGint nClasses, const UGArray<UGdouble> &aryValues, UGDatasetVector* pDatasetV, const UGArray<UGJoinItem>& JoinItems,UGdouble dInterval = 0.0);
	//! \brief  �����ı����ı���
	/**
	*/
	void MakeDefaultTextCaptions();
	//! \brief  �����ı����ı���
	/**
	\param nIndex         ���ñ����������[in]
	\param strCaption     ���ñ���[in]
	*/
	void SetCaptionAt(UGint nIndex, const UGString& strCaption );
	//! \brief  �����ı����ı���
	/**
	\param nIndex         ���ñ����������[in]
	\return ����������Ӧ�ı���
	*/
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief  �����ı����ķֶη�Χ
	/**
	\param pValues      �ֶεĶ�ֵ[in]
	\param nValueCount  �ֶεĸ���[in]
	\return �ֶ��Ƿ�ɹ���true�ɹ���falseʧ��
	\remarks ���÷ֶ��Ƿ�ɹ�
	*/
	UGbool SetTextStylesRanges(UGdouble *pValues,UGint nValueCount);

	//! \brief  �õ����ʽ
	/**
	\param bAddExpression   �Ƿ���ʾ��ʵ�ֶ���[in]
	*/
	UGString GetTextFieldName(UGbool bAddExpression = true)const;
	//! \brief  ���Ҹ����ݼ��µ��ı����
	/**
	\param pRecordset     ��Ҫ��ѯ��pRecordset[in]
	\param Style          �õ���Recordset����Ӧ�ı��ʽ��ֵ[in/out]
	\return ������ϢΪ���ı���������Ƿ�Ϊ����ʾ����ʾΪtrue������ʾΪfalse
	*/
	UGbool FindTextStyle(UGRecordset *pRecordset, UGLabelTextStyle& Style)const;
	//! \brief  ���ҵ�����ֵ���ı����
	/**
	\param nValue        ���ֶεĶ�ֵ[in]
	\param UGTextStyle   �õ��ö�ֵ�µ��ı����[in]
	\return ������ϢΪ���ı���������Ƿ�Ϊ����ʾ����ʾΪtrue������ʾΪfalse
	*/
	UGbool FindTextStyle(UGdouble dValue,UGLabelTextStyle& TextStyle)const;

	//! \brief  ���õ�����ֵ���ı����
	/**
	\param nIndex        �������ڶε�����[in]
	\param UGTextStyle   �������ڶε��ı����[in]
	*/
	void SetTextStyleAt(UGint nIndex, const UGLabelTextStyle& TextStyle);
	//! \brief  �õ����ֶε��ı����
	/**
	\param nIndex        �������ڶε�����[in]
	\return ���ֶζ�Ӧ���ı����
	*/
	const UGLabelTextStyle& GetTextStyleAt(UGint nIndex)const;

	//! \brief  ���ֶ����Ƿ��ں���Χ�ڣ���0��256֮��
	/**
	\param nValueCount   �ֶεĸ���[in]
	\return �Ƿ�Ϊ����ֵ��trueΪ����falseΪ������
	*/
	UGbool IsValidValueCount(UGint nValueCount)const;
	//! \brief  ɾ�����зֶ�ֵ���ı������Ϣ
	void RemoveAll();

	//! \brief  �õ��ֶθ���
	/**
	\return �ֶθ���
	*/
	UGint GetCount();
	//! \brief  �õ��ֶ�ֵ�ĸ���
	/**
	\return �ֶ�ֵ����
	*/
	UGint GetValueCount()const;
	//! \brief  ���Ҹ÷ֶ�ֵ�Ƿ����
	/**
	\param dValue   ��Ҫ���ҵķֶ�ֵ[in]
	\return ���ظ��ֶ�ֵ���ڵ���������1���ʾ���ֶ�ֵ������
	*/
	UGint Find(UGdouble dValue)const;
	
	//! \brief  ����ı����Ͷ�Ӧ�ķֶ�ֵ
	/**
	\param dValue      �ֶε�ֵ[in]
	\param TextStyle   �ֶεķ��[in]
	\return ���طֶθ���
	*/
	UGint Add(UGdouble dValue, const UGLabelTextStyle& TextStyle);
	//! \brief  ɾ���ֶ�
	/**
	\param nIndex     ɾ���ֶε�������[in]
	\param nCount     ɾ���ֶθ���[in]
	\return ���ص�ǰ�Ķθ���
	*/
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief  ����ĳһ�ֶ�
	/**
	\param nIndex     ����ķֶε�������[in]
	\param dValue     ����ķֶ�ֵ[in]
	\param TextStyle  ����ķֶ�����Ӧ���ı����[in]
	\return ���غϲ�����
	*/
	UGbool InsertAt(UGint nIndex, UGdouble dValue, const UGLabelTextStyle& TextStyle);

	//! \brief  ��Ӻ͵õ��ֶ�ֵ
	/**
	\return ���غϲ�����
	*/
	UGdouble GetValueAt(UGint nIndex)const;
	void SetValueAt(UGint nIndex, UGdouble dValue);
	
	//! \brief  ���������ı����ʱ���õ��ֶ��������ʽ,�������ֶ����ƻ���ʽ
	/**
	*/
	UGString GetTextExpression()const;			
	void SetTextExpression(const UGString& strExpression);

	//! \brief  �õ��������ʽ,�������ֶ����ƻ���ʽ
	/**
	\remarks Ĭ��Ϊ����
	*/
	UGbool IsDescending()const;			
	void SetDescending(UGbool bDescending = false);	
	//! \brief  �ı��Ƿ�ɼ�
	/**
	\remarks Ĭ��Ϊ�ɼ�
	*/
	void SetTextVisibleAt(UGint nIndex, UGbool bVisible = true);
	UGbool IsTextVisibleAt(UGint nIndex)const;
	
	//! \brief  ��ȡ������ı������Ϣ��XML��ʽ
	/**
	\param nVersion  ��ȡ������İ汾��
	\remarks Ĭ��Ϊ�ɼ�
	*/
	UGString SingleTextStyleToXML(UGint nVersion = 0)const;
	UGbool SingleTextStyleFromXML(const UGString& strXML, UGint nVersion = 0);

	//! \brief  UGDouble���Ƴɷ�����ʽ��׼��
	/**
	\param strFieldValue �ֶα��ʽ����
	\param labelStyle    �ı����
	\param pntCentroid   ���Ƶ�λ�ã���������
	\param pDrawParam    ���Ʋ��������ڱ�����
	\return  ������Ƶķ�����ʽ�ĸ������ݼ�
	\remarks ��ʱ��û�п��Ŵ˽ӿ�
	*/
	UGGeoCompound *PrepareForFraction(UGdouble &dValue,UGTextStyle labelStyle ,UGPoint2D &pntCentroid,UGDrawParamaters *pDrawParam);
	//! \brief  UGString���Ƴɷ�����ʽ��׼��
	/**
	\param strFieldValue �ֶα��ʽ����
	\param labelStyle    �ı����
	\param pntCentroid   ���Ƶ�λ�ã���������
	\param pDrawParam    ���Ʋ��������ڱ�����
	\return  ������Ƶķ�����ʽ�ĸ������ݼ�
	*/
	//�޸Ĳ���strFieldValueΪUGArray<UGString>����
	UGGeoCompound *PrepareForFraction(UGArray<UGString> &strFieldArray,UGTextStyle labelStyle ,UGPoint2D &pntCentroid,UGDrawParamaters *pDrawParam);
	//UGGeoCompound *PrepareForFraction(UGString &strFieldValue,UGTextStyle labelStyle ,UGPoint2D &pntCentroid,UGDrawParamaters *pDrawParam);

	void SetLabelAlwaysOnTop(UGbool bAlwaysOnTop);
	UGbool IsLabelAlwaysOnTop()const;

	//! \brief  ��ֵ�����ݵĸ�ʽ
	UGString GetNumFormat() const;
	void SetNumFormat(const UGString& strNumFormat);

	UGString Variant2String(const UGVariant& var); //! \brief �������ַ���

	//! \brief  ���������ı����󣬿�����ѭ����ע��ָ�������
	void MakeAlonglineText(const UGPoint2D& point, const UGString& strValue, UGTextStyle& labelStyle, 
									  UGGeoLine* pSubLine, UGArray<UGGeoText*>& arrTexts, UGDrawParamaters* pDrawParam);

	//! \brief  ѭ����ע�����ڳ��ȡ�
	UGdouble GetRepeatLength()const;
	void SetRepeatLength(UGdouble dRepeatLength);

	//! \brief  ���߱�עѭ����ע�����ڳ��ȡ����ڳ��ȣ�ֻ�������ı�ʱ��Ч��
	UGbool IsFixedRepeatLength()const;
	void SetFixedRepeatLength(UGbool bFixedRepeatLength);
	
	//! \brief  �ı���࣬��λΪ�ָߵı���������1����������Ϊ׼����ָ����������߱�ע��0��1֮����������ı�ע���߽Ƕȵĵ����ı���
	//! \brief  С�ڵ���0�Ͳ���Ĭ�ϵ����߱�ע��ֻ�����߱�ע�����á�
	void SetFontSpaceRatio(UGdouble dFontSpaceRatio);
	UGdouble GetFontSpaceRatio() const;

	//! \brief  �����߷������ͣ��������Ƿ���Ҫ����
	static void ChangeLineDirection(UGGeoLine* pSubLine, UGint nLineDirection);

	//! \brief  �����ı��ı�ע����ֻ�����߱�ע�����á�
	UGint GetLineDirection()const;
	void SetLineDirection(UGint nLineDirection);

	//! \brief  ��ǰ�ɼ�����ͼ����ʾ������ע������������ֵ����ľͲ���ʾ��
	UGint GetMaxTextNum()const;
	void SetMaxTextNum(UGint nMaxTextNum);



	UGDict<UGint, UGPoint2D> m_arrCustomLabel;
	//! \brief ��ȡר��ͼ�����hashcode
	virtual UGint GetHashCode() const;

	//! \brief �ַ�����ֳɵ��֣�Ӣ���Կո������
	static void StringToWordArray(const UGString, UGStrArray& strs);
	void SetLeaderLineToBack(UGbool bLeaderLineToBack);
	UGbool IsLeaderLineToBack();

protected:  
	void Swap(const UGThemeLabel& theme);
	//! \brief  ��Χר��ͼ�ֶη�ʽ
	void ClassifyWithCustomInterval(UGdouble dInterval, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithEqualDistance(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithExtraction(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithStdev(const UGArray<UGdouble> &arySrc);
	void Stdev(const UGArray<UGdouble> &arySrc, UGdouble &dMean, UGdouble &dStdev);
	void ClassifyWithLogarithm(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithQuantile(UGint nClasses, UGint nKeyCount, UGDatasetVector* pDatasetV, const UGArray<UGJoinItem>& JoinItems);

protected:	
	UGTextStyle	m_LabelStyle; 
	UGString m_strExpression;
	UGint m_nBackType;
	UGStyle m_BackStyle;

	//! \brief  ���浥�������ı����ʱ�ķֶ�ֵ�͸�����ֵ�ķ��
	UGArray<UGdouble > m_Values;
	UGArray<UGLabelTextStyle> m_RangeTextStyle;

public:
	UGbool m_bDescending;

protected:	
	UGString m_strTextExpression;

	//! \brief �ı��涨����
	UGint m_nTextLengthLimit;
	UGint m_nLabelOverLengthMode;
	
	UGbool m_bLabelAlwaysOnTop;
	UGString m_strNumFormat;
	UGdouble m_dRepeatLength;
	UGdouble m_dFontSpaceRatio;
	UGint m_nLineDirection;
	UGint m_nMaxTextNum;
	UGArray<UGString> m_arrExpression;
	UGbool m_bLeaderLineToBack;		//�Ƿ�ǣ���ߺϲ�����������
};

}

#endif // !defined(AFX_UGTHEMELABEL_H__5FD9A9BE_3A6F_4D8D_9BF0_EEDFA9C7B072__INCLUDED_)
