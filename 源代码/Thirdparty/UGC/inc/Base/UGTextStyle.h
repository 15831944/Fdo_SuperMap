
/*!
   **************************************************************************************
    \file     UGTextStyle.h
   **************************************************************************************
    \author   �¹���
    \brief    �ı������                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-07-06  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#ifndef UGTEXTSTYLE_H
#define UGTEXTSTYLE_H

#include "ugdefs.h"
#include "UGString.h"

namespace UGC {

//! \brief �ı������
class BASE_API UGTextStyle  
{
public:
	UGTextStyle();
	UGTextStyle(const UGTextStyle& textStyle);
	virtual ~UGTextStyle();

	void operator=(const UGTextStyle& textStyle);
	UGbool operator==(const UGTextStyle& textStyle);
	UGbool operator!=(const UGTextStyle& textStyle);

public:
	//! �õ�������ɫ
	UGColor GetForeColor() const;
	//! ����������ɫ
	void SetForeColor(UGColor foreColor);

	//! ����ɫ����Ӱɫ�����ɫ
	UGColor	GetBackColor() const;
	//! ���ñ���ɫ,ͬʱҲ����Ӱɫ�����ɫ
	void SetBackColor(UGColor backColor);

	//! �õ���ת�Ƕȣ��Զ�Ϊ��λ����ʱ�뷽��
	UGdouble GetAngle() const;
	//! ������ת�Ƕȣ��Զ�Ϊ��λ����ʱ�뷽��	
	void SetAngle(UGdouble dAngle);

	//! �õ������ȣ�����λ
	UGdouble GetWidth() const;
	//! ���������ȣ�����λ
	void SetWidth(UGdouble dWidth);

	//! �õ�����߶ȣ�����λ
	UGdouble GetHeight() const;
	//! ��������߶ȣ�����λ
	void SetHeight(UGdouble dHeight);

	//! �õ���������		
	UGString GetFaceName() const;
	//! ������������
	void SetFaceName(const UGString& strFaceName);

	//! �õ����з����Ϣ:���壬б�壬͸��������,���е�
	UGint GetStyle() const;			
	//! �������еķ�񣬸߼��û�ʹ��!
	void SetStyle(UGint nStyle);	
	
	//! �Ƿ����
	UGbool IsBold() const;	
	//! �����Ƿ����
	void SetBold(UGbool bBold = true);				

	//! �Ƿ��»���
	UGbool IsUnderline() const;
	//! �����Ƿ��»���
	void SetUnderline(UGbool bUnderline = true);		

	//! �Ƿ�б��
	UGbool IsItalic() const;	
	//! �����Ƿ�б��
	void SetItalic(UGbool bItalic = true);			

	//! �Ƿ�ɾ����
	UGbool IsStrikeOut() const;		
	//! �����Ƿ�ɾ����
	void SetStrikeOut(UGbool bStrikeOut = true);

	//! �õ����뷽ʽ
	UGbyte GetAlign() const;				
	//! ���ö��뷽ʽ
	void SetAlign(UGbyte nAlign = 0);				

	//! �õ��ı��ıʻ����
	UGint GetWeight() const;		
	//! �����ı��ıʻ����			
	void SetWeight(UGint nWeight);	
			
	//! �Ƿ�̶���С
	UGbool IsFixedSize() const;			
	//! �̶���С�����岻���ͼ�����Ŷ�����
	void SetFixedSize(UGbool bFixedSize=true);			
	
	//! �̶���С�ĳߴ磬mm��λ
	UGdouble GetSizeForFixed() const;			
	//! ���ù̶���С�ĳߴ磬mm��λ
	void SetSizeForFixed(UGdouble dSize);		

	//! �Ƿ񱳾���͸��, ע����,true��ʾ��͸��!!
	UGbool IsBackOpaque() const;				
	//! �����Ƿ񱳾���͸��
	void SetBackOpaque(UGbool bBackOpaque = false);				
	
	//! �Ƿ���ʾ���
	UGbool IsHalo() const;			
	//! �����Ƿ���ʾ���
	void SetHalo(UGbool bHalo = true);		
	
	//! �Ƿ���ʾ��Ӱ
	UGbool IsShadow() const;	
	//! �����Ƿ���ʾ��Ӱ
	void SetShadow(UGbool bShadow = true);			
	
	UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	UGString ToXML(UGint nVersion = 0) const;

	//! \brief ��ȡ�ı��������hashcode
	UGint GetHashCode() const;

	//! \brief ��ȡ/�����ʼ�Ч��,����60��֮�䣬Ŀǰֻ�Ա�ǩר��ͼ��Ч��������Ƕ�Ϊ��λ
	UGdouble GetItalicAngle() const;
	void SetItalicAngle(UGdouble nItalicAngle);
	
private:
	UGColor		m_ForeColor;			//! ������ɫ
	UGColor		m_BackColor;			//! ����ɫ����Ӱɫ�����ɫ
	UGint		m_nAngle;				//! ��ת�Ƕȣ���0.1��Ϊ��λ,x����������Ϊ��ʼ����ʱ�뷽��
	UGint		m_nItalicAngle;			//! ��ת�Ƕȣ���0.1��Ϊ��λ,x����������Ϊ��ʼ����ʱ�뷽��
	UGdouble	m_dWidth;				//! �����ȣ�����λ
	UGdouble	m_dHeight;				//! ����߶ȣ�����λ
	UGString	m_strFaceName;			//! ��������
	UGint		m_nStyle;				//! ���:���壬б�壬͸��������,���е�	
};

}

#endif
