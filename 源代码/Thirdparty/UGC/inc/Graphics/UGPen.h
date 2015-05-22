// UGPen.h: interface for the UGPen class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGPen.h   
   **************************************************************************************
    \author   ���������¹���
    \brief    ���ʻ���                                                               
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGPEN_H__EBBA00AA_4E20_4A52_A2BD_B6EB9A207829__INCLUDED_)
#define AFX_UGPEN_H__EBBA00AA_4E20_4A52_A2BD_B6EB9A207829__INCLUDED_

#include "Base/ugdefs.h"
// ���µĺ궨����X11��UGC�п��ܻ��г�ͻ.
// ��ȡ���궨��, ֱ��ʹ������.
#ifdef CapSquare
#undef CapSquare
#endif

#ifdef CapRound
#undef CapRound
#endif

#ifdef CapButt
#undef CapButt
#endif

#ifdef JoinRound
#undef JoinRound
#endif

#ifdef JoinMiter
#undef JoinMiter
#endif

#ifdef JoinBevel
#undef JoinBevel
#endif

namespace UGC
{

class GRAPHICS_API UGPen  
{
public:
	enum CapStyle				//! \brief �߶ζ˿�����
	{
		CapRound = 0,			//! \brief �˿�ΪԲ��
		CapSquare = 1,			//! \brief �˿�Ϊ������
		CapFlat = 2			    //! \brief �˿�Ϊƽ��		
	};
	enum JoinStyle
	{
		//! \brief �߶���������
		JoinRound = 0,			//! \brief ��round��ʽ�ཻ		
		JoinBevel = 1,			//! \brief ��bevel��ʽ�ཻ
		JoinMiter = 2			//! \brief ��miter��ʽ�ཻ
	};
	enum PenStyle
	{
		//! \brief Windows֧�ֵĻ�������
		PenSolid = 0,			//! \brief ����Ϊʵ��
		PenDash = 1,			//! \brief ����Ϊ�����
		PenDot = 2,				//! \brief ����Ϊ�����
		PenDashDot = 3,			//! \brief ��һ�����ߺ�һ������Ϊһ����Ԫ��ɵ�����
		PenDashDotDot = 4,		//! \brief ��һ�����ߺ���������Ϊһ����Ԫ��ɵ�����
		PenNull = 5				//! \brief �޻���
	};
public:
	struct UGPenData            //! \brief ���ʵ���������
	{		
		UGint nStyle;           //! \brief ���ʵ�����
		UGint nWidth;           //! \brief ���ʵĿ��
		UGColor clrColor;       //! \brief ���ʵ���ɫ
		UGint nCapStyle;        //! \brief �߶εĶ˿�����
		UGint nJoinStyle;       //! \brief �߶ε��ཻ����
		UGPenData()
		{					
			nStyle = PenSolid;
			nWidth = 0;
			clrColor = UGRGB(0, 0, 0);
			nCapStyle = CapRound;
			nJoinStyle = JoinRound;
		}
	};

protected:
	UGPen();
public:
	virtual ~UGPen();
	
	//! \brief ����һ��UGPen����
	virtual UGbool Create() = 0;
	//! \brief ����һ��UGPen����
	//! \param ������ˢ�������б� 
	virtual UGbool Create(const UGPenData& PenData) = 0;
	//! \brief ����һ��UGPen����
	//! \param nStyle     ���ʵ�����
	//! \param nWidth     ���ʵĿ��
	//! \param clrColor   ���ʵ���ɫ
	//! \param nCapStyle  �߶εĶ˿�����
	//! \param nJoinStyle �߶ε��ཻ����
	virtual UGbool Create(
					UGint nStyle,
					UGint nWidth = 0,
					UGColor clrColor = UGRGB(0, 0, 0),
					UGint nCapStyle = 0,
					UGint nJoinStyle = 0) = 0;
	
	//! \brief ɾ������
	virtual void DeleteObject() = 0;
	
	virtual void GetPenData(UGPenData& PenData);
		
	//! \brief ��ȡ��������(��ʵģʽ)
	virtual UGint GetStyle() const;
	//! \brief ���û�������(��ʵģʽ)
	//! \param nPenStyle ���ʵ�����(��ʵģʽ)
	virtual void SetStyle(UGint nPenStyle);
	//! \brief ��ȡ�߿�
	virtual UGint GetWidth() const;
	//! \brief �����߿�
	//! \param nLineWidth �߿�
	virtual void SetWidth(UGint nLineWidth);
	//! \brief ��ȡ����ɫ
	virtual UGColor GetColor() const;
	//! \brief ��������ɫ
	//! \param clrColor ����ɫ
	virtual void SetColor(UGColor clrColor);
	//! \brief ��ȡ��ͷ��ʽ
	virtual UGint GetCap() const;
	//! \brief ���ý�ͷ��ʽ
	//! \param nCapStyle ��ͷ����ʽ
	virtual void SetCap(UGint nCapStyle);	
	//! \brief ��ȡ���ӵ���ʽ
	virtual UGint GetJoin() const;
	//! \brief ���ý��ӵ���ʽ
	//! \param nJoinStyle ���ӵ����ʽ
	virtual void SetJoin(UGint nJoinStyle);	

	//! \brief ��ȡʵ�ʶ���
	void* GetNative() const;
	//! \brief ����ʵ�ʶ���
    //! \param pNative ʵ�ʶ���
	void SetNative(void* pNative);
	//! \brief ��ȡ��ʾ�������� 
	virtual UGint GetGraphicsType();
	
protected:
	UGPenData m_PenData;
	void* m_pNative;

	UGint m_nGraphicsType;	
};

}
#endif // !defined(AFX_UGPEN_H__EBBA00AA_4E20_4A52_A2BD_B6EB9A207829__INCLUDED_)
