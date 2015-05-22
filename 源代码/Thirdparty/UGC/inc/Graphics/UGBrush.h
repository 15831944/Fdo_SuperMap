// UGBrush.h: interface for the UGBrush class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGBrush.h 
   **************************************************************************************
    \author   ���������¹���
    \brief    ��ˢ����                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGBRUSH_H__B12A270F_FBBC_4892_BC1C_F65122F24B83__INCLUDED_)
#define AFX_UGBRUSH_H__B12A270F_FBBC_4892_BC1C_F65122F24B83__INCLUDED_

#include "Algorithm/UGSize.h"

namespace UGC
{

class UGImage;

class GRAPHICS_API UGBrush  
{
public:
	enum BrushStyle
	{
		//! \brief Windows֧�ֵĻ�ˢ����
		BrushSolid = 0,			//! \brief ʵ��仭ˢ
		BrushNull = 1,			//! \brief �޻�ˢ

		BrushDownward = 2,		//! \brief ///// 
		BrushCross = 3,			//! \brief +++++ 
		BrushCross45 = 4,		//! \brief xxxxx 
		BrushUpward = 5,		//! \brief \\\\\ 

		BrushHorizontal = 6,	//! \brief ----- 
		BrushVertical = 7,		//! \brief ||||| 
		
		BrushTile = 8,			//! \brief ���ͼƬ
		//! \brief gradient
		BrushGradientLinear = 10, //! \brief бֱ��
		BrushGradientRadial = 11, //! \brief б����
		BrushGradientConical = 12,//! \brief б׶��
		BrushGradientSquare = 13  //! \brief б����
	};

	struct UGBrushData              //! \brief ��ˢ������
	{   
		UGint nStyle;               //! \brief ��ˢ����״
		UGColor clrColor;           //! \brief ��ˢ����ɫ
		UGint nOpacity;             //! \brief ��ˢ�Ƿ�͸��
		UGint nGradientAngle;       //! \brief ��ˢ�Ľ����Ƕ�
		UGSize szGradientOffset;    //! \brief ��ˢ�Ľ�������ƫ����
		UGImage* pImage;            //! \brief ��ˢ�����ͼƬ   

		UGBrushData()               //! \brief Ĭ�ϵĻ�ˢ������
		{
			nStyle = BrushSolid; 
			clrColor = UGRGB(255,255,255); 
			nOpacity = 100;
			nGradientAngle = 0;
			szGradientOffset = UGSize(0,0);
			pImage = NULL;
		}
	};

protected:
	UGBrush();
public:
	virtual ~UGBrush();
	
	//! \brief ����һ��UGBrush����
	virtual UGbool Create() = 0;
	//! \brief ����һ��UGBrush����
	//! \param BrushData ������ˢ����������б�.
	virtual UGbool Create(const UGBrushData& BrushData) = 0;
	//! \brief ����һ��UGBrush����
	//! \param nStyle ��ˢ������ ,ʵ��,����
	//! \param clrColor ��ˢ����ɫ.
	//! \param nOpacity ��ˢ�Ƿ�͸��
	//! \param nGradientAngle ��ˢ�Ľ����Ƕ�
	//! \param szGradientOffset ��ˢ�Ľ�������ƫ����
	//! \param pImage ��ˢ�����ͼƬ
	virtual UGbool Create(UGint nStyle, UGColor clrColor, 
						UGint nOpacity = 100,
						UGint nGradientAngle = 0,
						UGSize szGradientOffset = UGSize(0, 0),
						UGImage* pImage = NULL) = 0;
	
	//! \brief ɾ������
	virtual void DeleteObject() = 0;
	//! \brief ��ȡBrushData����
	//! \param BrushData ���صĵ�BrushData����
	virtual void GetBrushData(UGBrushData& BrushData);			

	//! \brief ��ȡ��ˢ�����ģʽ
	virtual UGint GetStyle() const;
	//! \brief ���û�ˢ�����ģʽ
	//! \param nBrushStyle ��ˢ�����ģʽ
	virtual void SetStyle(UGint nBrushStyle);		
	//! \brief ��ȡ��ˢ����ɫ
	virtual UGColor GetColor() const;
	//! \brief ���û�ˢ����ɫ
	//! \param clrColor ��ˢ����ɫ
	virtual void SetColor(UGColor clrColor);
    //! \brief ��ȡ��ˢ�����ͼƬ
	virtual UGImage* GetImage() const;
	//! \brief ���û�ˢ�����ͼƬ
	//! \param pImage ����ͼƬ
	virtual void SetImage(UGImage* pImage);

	//! \brief ��ȡ��ˢ�Ĳ�͸����
	virtual UGint GetOpacity() const;
	//! \brief ���û�ˢ�Ĳ�͸����
	//! \param nOpacity ��ˢ��͸����
	virtual void SetOpacity(UGint nOpacity);	
	//! \brief ��ȡ�����Ƕ�
	virtual UGint GetGradientAngle() const;
	//! \brief ���ý����Ƕ�
	//! \param nAngle �����Ƕ�
	virtual void SetGradientAngle(UGint nAngle);	
	//! \brief ��ȡ��������ƫ����
	virtual UGSize GetGradientOffset() const;
	//! \brief ���ý�������ƫ����
	//! \param offset ��������ƫ����
	virtual void SetGradientOffset(const UGSize& offset);
	
	//! \brief ��ȡʵ�ʶ���
	void* GetNative() const;
	//! \brief ����ʵ�ʶ���
	//! \param pNative ʵ�ʶ���
	void SetNative(void* pNative);
	//! \brief ��ȡ��ʾ��������
	virtual UGint GetGraphicsType();
	
protected:
	UGBrushData m_BrushData;
	void *m_pNative;
	UGint m_nGraphicsType;	
};
}
#endif // !defined(AFX_UGBRUSH_H__B12A270F_FBBC_4892_BC1C_F65122F24B83__INCLUDED_)
