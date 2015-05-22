// UGTrackingLayer.h: interface for the UGTrackingLayer class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGTrackingLayer.h
   **************************************************************************************
    \author   �¹���
    \brief    ����ͼ���࣬��һ���ڴ�ͼ�㣬����������ͼ��������棬������ʱ�������ʾ��                                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTRACKINGLAYER_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_)
#define AFX_UGTRACKINGLAYER_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_

#include "UGGeoEvent.h"
#include "Base/UGList.h"
#include "Drawing/UGDrawing.h"

namespace UGC {

class MAP_API UGTrackingLayer  
{
public:
	UGTrackingLayer();
	virtual ~UGTrackingLayer();

public:
	//! \brief  ����¼�
	UGint HitTest(const UGPoint2D& pntHitTest, UGdouble dTolerance);

	//! \brief  �Ƿ�ɼ�
	UGbool IsVisible()const;
	//! \brief  �����Ƿ�ɼ�
	void SetVisible(UGbool bVisible = true);

	//! \brief  �Ƿ��ѡ��
	UGbool IsSelectable()const;
	//! \brief  �����Ƿ��ѡ��
	void SetSelectable(UGbool bSelectable = false);

	//! \brief  �Ƿ�ɱ༭
	UGbool IsEditable()const;
	//! \brief  �����Ƿ�ɱ༭
	void SetEditable(UGbool bEditable = false);

	//! \brief  �Ƿ�ɲ�׽
	UGbool IsSnapable()const;
	//! \brief  �����Ƿ�ɲ�׽
	void SetSnapable(UGbool bSnapable = false);

	//! \brief �Ƿ��������ͼ������Ŷ�����
	UGbool IsSymbolScalable()const;
	//! \brief ���÷����Ƿ������
	void SetSymbolScalable(UGbool bSymbolScalable = false);

	//! \brief �Ƿ������ı�����
	UGbool IsAllowTextOverlap()const;
	//! \brief �����ı�����
	void SetAllowTextOverlap(UGbool bAllowTextOverlap = true);

	//! \brief ���Ҷ�Ӧ��ǩ�ĸ��ٲ����
	/**
	\return  ��Ӧ��ǩ������
	*/
	UGint Find(const UGString &strTag, UGint nFromIndex = 0) const;
	//! \brief ���Ҷ�Ӧ���ζ���ĸ��ٲ����
	/**
	\return  ��Ӧ���ζ��������
	*/
	UGint Find(const UGGeometry* pGeometry, UGint nFromIndex = 0);

	//! \brief �Ƴ�ָ����ǩ�Ķ���
	UGbool Remove(const UGString &strTag, UGint nFromIndex = 0);
	//! \brief �Ƴ�ָ�������Ķ���
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief ���Ӽ��ζ��󵽸��ٲ�
	UGGeoEvent* Add(const UGGeometry* pGeometry, const UGString &strTag);
	//! \brief �õ�ָ�������ĸ��ٲ����
	UGGeoEvent* GetAt(UGint nIndex) const;
	//! \brief �Ƴ����ٲ����ж���
	void RemoveAll();
	//! \brief ��ȡ�������
	UGint GetCount()const;

	//! \brief ����ָ����������ı�ǩ
	void SetTagAt(UGint nIndex, const UGString &strTag);

	//! \brief ���Ƹ��ٲ�
	UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing);

	//! \brief ����ָ�����ַ�����
	void SetCharset(UGTextCodec::Charset nCharset);
	//! \brief �õ�ָ�����ַ�����
	UGTextCodec::Charset GetCharset()const;

	//! \brief �õ������Ŵ�С
	UGdouble GetMaxMarkerSize() const;
	//! \brief �õ���Ч����
	UGRect2D GetInvalidRect() const;
	//! \brief ������Ч����
	void SetInvalidRect(const UGRect2D& rcInvalid);

	UGdouble GetSymScaleDefinition() const;
	void SetSymScaleDefinition(UGdouble dSymScaleDefinition);

	UGdouble CalculateSymbolScale(UGdouble dScale) const;
	void SetDrawing(UGDrawing* pDrawing);
	
	//! \brief ��ȡ���ԭ���ģʽ
	UGint GetFillOrgMode() const;					
	//! \brief �������ԭ��ģʽ
	void SetFillOrgMode(UGint nFillOrgMode);		
	UGbool BuildSpatialIndex(UGSpatialIndexInfo  &spatial);

	//! \brief ��ʼ����
	UGbool BeginTrans() ;
	
	//! \brief �ύ����
	void Commit() ;
	
	//! \brief ��������
	void Rollback();
	
	//! \brief �ж������Ƿ�ʼ 
	UGbool IsTransStarted() ;
	
	//added by xielin 2007-10-17 �����Ż����ٲ����ʾ�ٶ�
	//! \brief ��ʾ��ʱ���Ƿ��ն�������������ʾ��Ĭ�ϰ��ն�������������ʾ�������Դ󲿷ֵĸ���Ӧ�ã�һ�����ٵ�һ����ע��ע�ⲻҪŪ�ɸ��϶��󣩣�����߻����ٶ�
	void SetOrderByGeometryType(UGbool bOrderByGeometryType=true);
	//! \brief �����Ƿ��ն�������������ʾ
	UGbool IsOrderByGeometryType();

	//! \brief  �Ƿ�Ϊ�߹⻬ģʽ
	UGbool IsLineSmoothingMode()const;
	//! \brief  �����߹⻬ģʽ
	void SetLineSmoothingMode(UGbool bSmoothingMode = true);			
	//! \brief  �Ƿ�Ϊ�ı��⻬ģʽ
	UGbool IsTextSmoothingMode()const;									
	//! \brief  �����ı��⻬ģʽ
	void SetTextSmoothingMode(UGbool bSmoothingMode = true);		

private:
	//modified by lugw 2007-05-11 �˺�����Ϊ˽�У��ⲿ�ݲ�ʹ��
	void SetGeometryAt(UGint nIndex, const UGGeometry* pGeometry);
	//! \brief �����ڴ�����Դ,�����Ա����Դ��Ϊ�գ�����true��Ϊ�շ���false
	UGbool CreateMemoryDs();

protected:
	UGDrawing* m_pDrawing;
	UGRect2D m_rcInvalid;
	UGdouble m_dMaxMarkerSize;//���ķ��ŵĴ�С�����ǱƲ����ѵģ�������ʱά��
	UGuint m_unOptions;
	UGList<UGGeoEvent*> m_Events;

	UGDataSource* m_pDs;
	UGDatasetVector* m_pDv;
	UGRecordset* m_pRecordset; 

	UGTextCodec::Charset m_nCharset;
	UGdouble m_dSymScaleDefinition;	//�������ű�����
	UGint m_nFillOrgMode;
	UGbool m_bOrderByGeometryType;
	UGbool m_bLineSmoothingMode;
	UGbool m_bTextSmoothingMode;

	UGMutex m_mutex;
};

}

#endif // !defined(AFX_UGTRACKINGLAYER_H__DC6194D6_CDEC_4A74_8522_AC23C8C202F5__INCLUDED_)
