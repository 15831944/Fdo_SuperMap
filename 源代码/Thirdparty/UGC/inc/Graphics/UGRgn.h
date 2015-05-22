// UGRgn.h: interface for the UGRgn class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGRgn.h   
   **************************************************************************************
    \author   ���������¹���
    \brief    �ü��������                                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGRGN_H__0CE6353D_7685_473C_940D_381AE7E4FE1D__INCLUDED_)
#define AFX_UGRGN_H__0CE6353D_7685_473C_940D_381AE7E4FE1D__INCLUDED_

#include "Algorithm/UGRect.h"

namespace UGC
{

class GRAPHICS_API UGRgn  
{
public:
	struct UGRegionData
	{
		UGuint nCount;   //! \brief ������Ӷ���εĸ���
		UGuint nRgnSize; //! \brief ������ܹ���С
		UGRect rcBound;  //! \brief �������Ӿ���
		UGbyte* pRect;	 //! \brief ���������	
		UGRegionData()
		{
			nCount = 0;
			nRgnSize = 0;
			rcBound = UGRect(0,0,0,0);
			pRect = NULL;
		}
		virtual ~UGRegionData()
		{
			if(pRect != NULL)
			{
				delete pRect;
				pRect = NULL;
			}
		}
	};

	enum RgnCombineMode				// ���Combine��Ա������ѡ��,����Region����
	{					
		UGRGN_AND = 1,			// �߼������
		UGRGN_OR = 2,			// �߼������
		UGRGN_XOR = 3,			// �߼�������		
		UGRGN_DIFF = 4,			// 
		UGRGN_COPY = 5			// ��Copyѡ��һ��.
	};

protected:
	// �������ε�����
	UGRgn();
public:
	// destructor
	virtual ~UGRgn();

	//! \brief ����֮��ĸ���
	//! \param Rgn Ҫ�����Ƶ�����
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool Copy(const UGRgn& Rgn) = 0;
    //! \brief ����һ����������
    //! \param x1 ���ε����Ͻ�X����
    //! \param y1 ���ε����Ͻ�Y����
	//! \param x2 ���ε����½�X����
    //! \param y2 ���ε����½�Y����
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool CreateRect(UGint x1, UGint y1, UGint x2, UGint y2) = 0;
	//! \brief ����һ����������
    //! \param rect ���ݵľ��ζ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool CreateRect(UGRect &rect) = 0;
	//! \brief ����һ����Բ��
    //! \param x1 ���ݵľ��ε����Ͻ�X����
    //! \param y1 ���ݵľ��ε����Ͻ�Y����
	//! \param x2 ���ݵľ��ε����½�X����
    //! \param y2 ���ݵľ��ε����½�Y����
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool CreateElliptic(UGint x1, UGint y1, UGint x2, UGint y2) = 0;
    //! \brief ����һ����Բ������
    //! \param rect ���ݵľ��ζ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool CreateElliptic(UGRect &rect) = 0;
	//! \brief ����һ����Բ������
	//! \param x1 ���ݵľ��ε����Ͻ�X����
    //! \param y1 ���ݵľ��ε����Ͻ�Y����
	//! \param x2 ���ݵľ��ε����½�X����
    //! \param y2 ���ݵľ��ε����½�Y����
	//! \param x3 ��ԲԲ�ǵ�X����
    //! \param y3 ��ԲԲ�ǵ�Y����
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool CreateRoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3) = 0;
	//! \brief ����һ����Բ������
    //! \param rect ���ݵľ��ζ���
	//! \param point ��ԲԲ�ǵ�XY����
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool CreateRoundRect(UGRect &rect, UGPoint point) = 0;
    //! \brief ����һ�����������
    //! \param pPoints ����εĵ���ָ��
	//! \param point �ж��ٸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool CreatePolygon(const UGPoint* pPoints, UGint nCount) = 0;
	//! \brief ����������������
    //! \param pPoints ����εĵ���ָ��
	//! \param pPolyCounts ÿ������εĵ���
	//! \param nCount ����εĸ���
	//! \return ����ɹ�����TRUE,ʧ�ܷ���FALSE
	virtual UGbool CreatePolyPolygon(const UGPoint* pPoints, const UGint* pPolyCounts, UGint nCount) = 0;

	//! \brief ɾ��Rgn
	virtual void DeleteObject() = 0;

	//! \brief �����֮����
    //! \param Rgn1 ����1
	//! \param Rgn2 ����2
	//! \param nCombineMode �������
	virtual UGbool Combine(const UGRgn& Rgn1, const UGRgn& Rgn2, UGint nCombineMode) = 0;

	//! \brief ��ȡ����ı߿�
	//! \return ��������ı߿�һ������
	virtual UGRect GetBox() const = 0;

	//! \brief �ƶ�����
	//! \param x ��X���ƶ��ĳ���
	//! \param y ��Y���ƶ��ĳ���
	virtual void Offset(UGint x, UGint y) = 0;
	//! \brief �ƶ�����
	//! \param point �ƶ�������
	virtual void Offset(const UGPoint& point) = 0;
	
	//! \brief �ж����������Ƿ����
    //! \param Rgn �����Ƚϵľ���
	virtual UGbool IsEqual(const UGRgn& Rgn) const = 0;
	
	//! \brief �жϵ����������
	//! \param x ���жϵĵ��X����
	//! \param y ���жϵĵ��Y����
	virtual UGbool PtInRegion(UGint x, UGint y) const = 0;
	//! \brief �жϵ����������
	//! \param point ���жϵĵ������
	virtual UGbool PtInRegion(const UGPoint &point) const = 0;
    //! \brief �жϾ����Ƿ���������
	//! \param x1 ���жϵľ��ε����Ͻ�X����
    //! \param y1 ���жϵľ��ε����Ͻ�Y����
	//! \param x2 ���жϵľ��ε����½�X����
    //! \param y2 ���жϵľ��ε����½�Y����
	virtual UGbool RectInRegion(UGint x1, UGint y1, UGint x2, UGint y2) const = 0;
	//! \brief �жϾ����Ƿ���������
	//! \param rect ���жϵľ���
	virtual UGbool RectInRegion(const UGRect &rect) const = 0;
	//! \brief ��ȡ���������
	//! \param RgnData �����������ݵı���
	virtual UGbool GetRegionData(UGRegionData &RgnData) const = 0;

	//! \brief ��ȡʵ�ʶ���
	void* GetNative() const;
	//! \brief ����ʵ�ʶ���
	//! \param pNative �����õĶ���
	void SetNative(void* pNative);
	// ��ȡ��ʾ��������
	virtual UGint GetGraphicsType();
	
protected:
	
	void *m_pNative;
	UGint m_nGraphicsType;	
};

}
#endif // !defined(AFX_UGRGN_H__0CE6353D_7685_473C_940D_381AE7E4FE1D__INCLUDED_)
