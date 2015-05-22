// UGLayer.h: interface for the UGLayer class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGLayer.h 
   **************************************************************************************
    \author   �¹���
    \brief    ͼ���࣬�������ݼ�������ʾ��ר��ͼ��ʾ��                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGLAYER_H__A4B430F7_6A63_4275_BB13_EF15BA12DDAD__INCLUDED_)
#define AFX_UGLAYER_H__A4B430F7_6A63_4275_BB13_EF15BA12DDAD__INCLUDED_

#include "Drawing/UGDrawing.h"
#include "Engine/UGDataSource.h"
#include "UGThemeUnique.h"
#include "UGThemeRange.h"
#include "UGThemeLabel.h"
#include "UGThemeGraph.h"
#include "UGThemeCustom.h"
#include "UGThemeDotDensity.h"
#include "UGThemeGraduatedSymbol.h"
#include "UGThemeGridUnique.h"
#include "UGThemeGridRange.h"
#include "UGThemes.h"
#include "UGSelection.h"
#include "Geometry/UGTINBlock.h"

#include "Base/UGList.h"

namespace UGC {

class UGProgress;
class UGLayers;

//! \brief AfterGeometryDraw �¼��ص�����
typedef void (UGSTDCALL *AfterGeometryDrawProc)(UGlong pWnd,UGString strLayerName,UGint nGeometryID,UGGraphics* pGraphics);
//! \brief BeforeGeometryDraw �¼��ص�����
typedef void (UGSTDCALL *BeforeGeometryDrawProc)(UGlong pWnd,UGbool& bCancel,UGString strLayerName,UGint nGeometryID,UGGraphics* pGraphics);

typedef UGArray<UGbyte> UGbyteArray;

enum UGLayerOptions
{
	UG_LO_VISIBLE						=	0x00000001,	//�Ƿ���ʾ
	UG_LO_SELECTABLE					=	0x00000002,	//�Ƿ��ѡ��
	UG_LO_EDITABLE						=	0x00000004,	//�Ƿ�ɱ༭
	UG_LO_SNAPABLE						=	0x00000008,	//�Ƿ�ɲ�׽
	UG_LO_SYMBOL_SCALABLE				=	0x00000010,	//�Ƿ����ŷ���
	UG_LO_LINE_ADJUST   				=	0x00000100,	//�Ƿ�������ʾ������ʵ��
	UG_LO_KEEP_ORDER					=	0x00000020,	//�Ƿ�����ʾ��ʱ��ID����,ֻ��SDX����������Ч(SDB,DGN�Ѿ�Ĭ�ϰ���ID����)
	UG_LO_IS_3D							=	0x00000040,	//�Ƿ���3D������������ʾ�����������ʾ������Ҫ�趨�߶��ֶ� m_strHeightField
	UG_LO_IS_MODIFIED					=   0x00000080, //�Ƿ��Ѿ��޸ģ��Ƿ���Ҫ����

	UG_LO_DATABASE_MODE					=	0x00040000, //�Ƿ������ݿ��������ݣ���SDB���Ӧ
	UG_LO_SPATIAL_DB_MODE				=	0x00080000, //�Ƿ���SuperMap�����ݿ�����
	UG_LO_NEED_CK_GEO_BOUND				=	0x00100000,	//�Ƿ�����ʾ��ʱ����Ҫ���bounds
	
	UG_LO_EDITABLE_LOCK					=   0x00200000, //�༭����
	UG_LO_IS_VIRTUAL					=   0x01000000, //�Ƿ�������ͼ�� 
	UG_LO_USE_LAYER_CACHE				=   0x02000000, //false:����Ҫͼ�㻺�棬true����Ҫͼ�㻺��
	UG_LO_CACHE_NEED_REFRESH			=   0x04000000, //ͼ�㻺���Ƿ���Ҫˢ��
	UG_LO_ALLOW_TEXT_OVERLAP			=	0x10000000,	//�Ƿ�������ʾ�ص��ı�
	UG_LO_IS_ORDER_OVERLAP		    	=   0x20000000,	//�Ƿ���ͼ���ڵĶ���ѹ��˳�� added by dongfei 2007-04-27

	UG_LO_IS_DISPLAYCLIP				=   0x40000000, //�Ƿ�ʹ����ʾ�ü�����
	UG_LO_CROSSROAD_OPTIMIZED			=   0x80000000, //�Ƿ�ʹ�õ�·�Ż���ʾ
};

struct ScaleStyle
{	
	UGdouble dMinScale;
	UGdouble dMaxScale;
	UGStyle  style;
} ;

class MAP_API UGLayer  
{
public:
	enum UGLayerType
	{
		UG_Layer_Normal                     = 1,//��ͨͼ��
		UG_Layer_NetworkLine                = 2,//�����߲�
		UG_Layer_NetworkPoint               = 3,//������
		UG_Layer_TopoParent                 = 4,//���˴��󸸲�
		UG_Layer_TopoLayer                  = 5,//���˴������ݲ�
		UG_Layer_TopoPointError             = 6,//���˴�����
		UG_Layer_TopoPointException         = 7,//���˴�����
		UG_Layer_TopoLineError              = 8,//���˴����߲�
		UG_Layer_TopoLineException          = 9,//���˴����߲�
		UG_Layer_TopoRegionError            = 10,//���˴������
		UG_Layer_TopoRegionException        = 11,//���˴������
		UG_Layer_TopoDirty                  = 12,//������������ûʹ��
		//�޸ĺ������Ӳ������
		//UG_Layer_Child                      = 13,//�Ӳ�
	};
	


public:
	UGLayer();
	virtual ~UGLayer();
	UGLayer(const UGLayer& layer);	
	UGLayer& operator =(const UGLayer& layer);	

public:	
	//*********����Options***********//
	//! \brief ĳ��ѡ���Ƿ����
	UGbool Enable(UGuint unOptions);
	//! \brief �Ƿ�����ĳ��ѡ��
	UGbool IsSupportOptions(UGuint unOptions);
	//! \brief ����ʹ��ĳ��ѡ��
	virtual void SetOptions(UGuint unOptions);
	//! \brief ���ý���ĳ��ѡ��
	virtual void UnsetOptions(UGuint unOptions);	
	//! \brief �õ�ͼ��ѡ�����õ���Ϣ
	UGuint GetOptionsInfo();
	//! \brief ����ͼ��ѡ�����Ϣ
	void SetOptionsInfo(UGuint unOptions);

	//! \brief �Ƿ���ʾ
	UGbool IsVisible()const;
	//! \brief ����Ϊ����ʾ
	void SetVisible(UGbool bVisible = true);

	//! \brief �Ƿ����ѡ��
	UGbool IsSelectable()const;	
	//! \brief ����Ϊ��ѡ��
	void SetSelectable(UGbool bSelectable = true);			

	//! \brief �Ƿ���Ա༭
	UGbool IsEditable()const;
	//! \brief  �����Ƿ���Ա༭
	/**
	\remarks �������ڲ�ʹ�ã��ⲿ�͵���UGLayers::SetEditableLayer��added by xielin 2007.8.9
	*/
	void SetEditable(UGbool bEditable = true);

	//! \brief �Ƿ���Բ�׽
	UGbool IsSnapable()const;									// �Ƿ���Բ�׽
	//! \brief ����Ϊ�ɲ�׽
	void SetSnapable(UGbool bSnapable = true);				// 

	//! \brief �Ƿ������༭
	UGbool IsEditableLock()const;
	//! \brief ���������༭
	void SetEditableLock(UGbool bEditableLock = true);   

	//! \brief �Ƿ��������ͼ������Ŷ�����
	UGbool IsSymbolScalable()const;
	//! \brief ���÷��ſ�����
	void SetSymbolScalable(UGbool bSymbolScalable = true);

	//! \brief ���ͻ���ʱ�Ƿ�������ʾ��ʵ����
	/**
	�õ��Ƿ�������ʾ��ʵ����
	\return �Ƿ�������ʾ��ʵ����1�����ǣ�0�����Ĭ��Ϊ1��
	*/
	UGbool IsLineAdjust() const;
	//! \brief ���ͻ���ʱ����������ʾ��ʵ����
	/**
	�趨�Ƿ�������ʾ��ʵ�����ڷŴ���Сʱ����������ʾ���͡�
	\param bFixed  �Ƿ�������ʾ��ʵ��[in]
	\remarks Ĭ���»������ͻ���ô˷�����
	*/
	void SetLineAdjust(UGbool bLineAdjust = true);

	//! \brief �Ƿ������ʾʱ����ID����
	UGbool IsKeepOrder()const;	
	//! \brief ���ö�����ʾʱ���Ƿ�ID����
	void SetKeepOrder(UGbool bKeepOrder = true);		

	//! \brief �Ƿ������ı�����
	UGbool IsAllowTextOverlap()const;							
	//! \brief �����ı�����
	void SetAllowTextOverlap(UGbool bAllowTextOverlap = true);

	//! \brief ��ͼ��������Ƿ��޸Ĺ�
	UGbool IsModified()const;		
	//! \brief ����ͼ���޸ı�־
	void SetModifiedFlag(UGbool bModified = true);

	//! \brief �����Ƿ�����ͼ�㻺����
	UGbool IsAllowCache()const;		
	//! \brief �����Ƿ�����ͼ�㻺����
	void SetAllowCache(UGbool bCache = true);				
	
	//! \brief ȡ��ͼ��ˢ�±��
	UGbool GetRefreshFlag()const;								
	//! \brief ����ͼ��ˢ�±�־��ǿ��ˢ��ͼ��
	void SetRefreshFlag(UGbool bRefresh = true);			
	
	//! \brief ͼ��Ļ������Ƿ����
	UGbool IsCacheAvailable()const;						
	//*********��ʾ����Options***********//

	//! \brief �õ�դ��͸����
	UGint GetRasterOpaqueRate()const;					
	//! \brief ����դ��͸����
	void SetRasterOpaqueRate(UGint nRasterOpaqueRate);		
	
	//! \brief ����ͼ����
	void SetStyle(const UGStyle& style);
	//! \brief �õ�դ��͸����
	const UGStyle& GetStyle()const;

	//! \brief �õ�ͼ���ѯ���
	const UGQueryDef& GetQueryDef()const;
	//! \brief �õ�ͼ���ѯ���
	/**
	\param QueryDef  ��ѯ���[in\out]
	*/
	void GetQueryDef(UGQueryDef& QueryDef)const;	
	//! \brief ����ͼ���ѯ���
	void SetQueryDef(UGQueryDef& QueryDef);
	//! \brief �������ݼ���ά���������0ά������1ά������2ά����������-1
	UGint GetDimension()const;								
	
	//! \brief �������ר��ͼ�������Ƿ�Ϸ�
	/**
	\param strExpression   �ֶα��ʽ[in]
	\remarks ������ѯ����������ֵ����,���ʧ��,����0
	*/
	UGint CheckThemeExpression(const UGString& strExpression);
	//! \brief ���¼���Bounds
	UGRect2D RecalcBounds(UGDrawParamaters *pDrawParam, UGbool bComputeDatasetBounds = false);

	//! \brief ����XML��Ϣ
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief ��ȡXML��Ϣ
	UGbool FromXML(const UGString& strXML,UGbool bIgnoreCaption = true, UGint nVersion = 0);

	//! \brief �õ�����,���û����Ϊ��
	UGLayer* GetParentLayer()const;
	//! \brief ���������ͼ�㣬���ؽڵ�ͼ��
	UGLayer* GetChildLayer()const;						

	//! \brief ���ø���,���û����Ϊ��
	void SetParentLayer(UGLayer* pLayer);
	//! \brief ���������ͼ�㣬���ýڵ�ͼ��
	void SetChildLayer(UGLayer* pLayer);								
	
//	UGString GetName()const;										// ͼ����

	//! \brief  ����������Ϣ
	void SetDescription(const UGString&  strDescription);		
	//! \brief ��ȡͼ��������Ϣ
	UGString GetDescription()const;								

	//! \brief �������ݼ�����
	void SetDatasetName(const UGString&  strDatasetName);		
	//! \brief ��ȡ���ݼ�����
	UGString GetDatasetName()const;								

	//! \brief ��������Դ����
	void SetDataSourceAlias(const UGString& strDataSourceAlias);	
	//! \brief ��ȡ����Դ����
	UGString GetDataSourceAlias()const;								

	//! \brief ����ͼ�����
	void SetCaption(const UGString&  strCaption);		
	//! \brief ��ȡͼ�����
	UGString GetCaption()const;								

	//! \brief ��ȡͼ����������
	UGdouble GetVisibleScaleMax()const;
	//! \brief ��ȡͼ����С������
	UGdouble GetVisibleScaleMin()const;
	//! \brief ����ͼ����������
	void SetVisibleScaleMax(UGdouble dVisibleScaleMax);
	//! \brief ȡ��ͼ����������
	void CancelVisibleScaleMax();
	//! \brief ����ͼ����С������
	void SetVisibleScaleMin(UGdouble dVisibleScaleMin);
	//! \brief ȡ��ͼ����С������
	void CancelVisibleScaleMin();

	//! \brief ��������ͼ����Ϣ
	void Reset();	

	//! \brief ���ͼ�㲻����ʾ��Geometry��ID
	void AddInvisibleGeoID(UGint nID);
	//! \brief ���ͼ�㲻����ʾ��Geometry��IDs
	void ClearInvisibleGeoIDs();
	
	//! \brief �����ʾ�õļ�¼��
	void ClearDisplayRecordset();						
	//! \brief �ͷ����м�¼�����ڹر����ݼ����޸����ݼ��Ӷνṹ֮ǰ�������
	void ClearRecordsets();									
	//! \brief ����༭�õļ�¼��	
	void ClearEditRecordset();								
	//! \brief ׼����ʾ�õļ�¼��,UGQueryDef *pQueryDef�Ǳ༭��¼����ѯ��������
	void PrepareEditRecordset(UGQueryDef *pQueryDef = NULL);
	//! \brief ���ñ༭�õļ�¼��
	void SetEditRecordset(UGRecordset *pEditRecordset);
	//! \brief �õ��༭�õļ�¼��
	UGRecordset* GetEditRecordset() const;
	//! \brief �õ���ʾ�õļ�¼��
	UGRecordset* GetDisplayRecordset() const;

	//! \brief �����ݼ���������
	void SetDataset(UGDataset *pDataset, UGbool bInit = true);
	//! \brief ��ȡ��ǰ���ӵ����ݼ�	
	UGDataset* GetDataset()const;	

	//! \brief �жϵ�ǰ���������Ƿ���Ҫ��ʾͼ��(ʹ�ã�m_dVisibleScaleMax��m_dVisibleScaleMin�ж�)
	UGbool IsVisibleScale(UGdouble dScale)const;
	//! \brief ���ͼ���¼�
	/**
	\param pntHitTest           �����Ӧ�㣬��������[in]
	\param dTolerance           �������[in]
	\param Selection            [in]
	\param nByPassCount         [in]
	\param pDrawing             ������[in]
	\return                     ����ɹ�����true����֮Ϊfalse
	*/
	virtual UGbool HitTest(const UGPoint2D& pntHitTest, UGdouble dTolerance, UGSelection &Selection, UGint &nByPassCount, UGDrawing *pDrawing);
	//! \brief ������ŵĴ�С
	/**
	\param dScale           ������[in]
	\return                 �������ŵı���
	*/
	UGdouble CalculateSymbolScale(UGdouble dScale)const;

	//! \brief �õ�ϵͳ������
	UGdouble GetSymScaleDefinition() const;
	//! \brief ����ϵͳ������
	void SetSymScaleDefinition(UGdouble dSymScaleDefinition);
	
	//! \brief ��ȡ���ԭ���ģʽ
	UGint GetFillOrgMode() const;				
	//! \brief �������ԭ��ģʽ
	void SetFillOrgMode(UGint nFillOrgMode);		
	
	//! \brief ��ȡ��С��ʾ��С
	UGdouble GetMinimumVisible() const;				
	//! \brief ������С��ʾ��С
	void SetMinimumVisible(UGdouble dMinimumVisible);	

	//! \brief ����ͼ��
	/**
	\param pGraphics			���Ƶ���Graphics[in]
	\param pDrawing				������[in]
	\param pRecordSet           ���Ƶļ�¼��[in]
	\param bSingle              ��¼���Ƿ����ɸ�ͼ���Լ�ʹ��[in]
	\return                     ���Ƴɹ�����true����֮Ϊfalse
	*/
	UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing, UGRecordset* pRecordSet, UGbool bSingle = false,UGProgress* pProgress = NULL);

	//! \brief ת��ר��ͼΪ�������ݼ�
	UGbool ConvertThemeToDataset(UGDrawing* pDrawing, UGDatasetVector *pDatasetCAD, UGbool bProgress = true);
	//added by xielin 2007-04-13
	//! \brief ����ͼ���е�ѡ�� 
	UGSelection* GetSelection();

	//added by lugw 2007-04-12
	//! \brief  ����ֶ�����
	/**
	\param pntHitTest           �����Ӧ�㣬��������[in]
	\param pThemeLabel          ��ѡ��ǩר��ͼ[in]
	\param pGraphics            pDrawing���ж�Ӧ��pGraphics[in]
	\param pDrawing             ������Ϣ[in]
	\param geoTextArray         ѡ�б�ǩ���ֶα�ǩ��Ϣ[in/out]
	\param strFieldExpression   �����ѯ���ֶα��ʽ��Ĭ��Ϊ��
	\return                     �ɹ�����true����֮Ϊfalse
	\remarks                    ���ڲ�ѯ���geoTextArray������û�ֻ��Ҫ�õ�ѡ�б�ǩ���ֶ���Ϣ��������齫ÿ����ǩ����Ϣ��GeoText����ʽ���������ֶα��ʽ��Ϊ�ն��ұ��ʽ��ȷ�������鰴�գ������������ı�ǩ��Ϣ���ñ�ǩ���ֶα��ʽ��ֵ������ʽ��������ڴ�Bounds�µı�ǩ��
	*/
	UGbool HitTestThemeLable(const UGPoint2D& pntHitTest,/*UGThemeLabel* pThemeLabel,*/UGGraphics* pGraphics, UGDrawing *pDrawing,UGArray<UGGeoText>& geoTextArray,UGString strFieldExpression = (""));

	//! \brief ���Tinͼ���¼�
	/**
	\param pntHitTest           �����Ӧ�㣬��������[in]
	\param dTolerance           �������[in]
	\param triInfo				����Tin��������Ϣ[in\out]
	\param pDrawing             ������[in]
	\return                     ����ɹ�����true����֮Ϊfalse
	*/
	UGbool HitTestTinBlock(const UGPoint2D& pntHitTest,UGdouble dTolerance, TriInfo& triInfo, UGDrawing *pDrawing);
	
	//added by dongfei 2007-04-24 
	//! \brief ����/���� ͼ����
	void SetName(UGString strLayerName);
	UGString GetName()const {return m_strName;};
	//! \brief ����/�����ض���������ͼ����
	void SetStyle(UGdouble dMinScale,UGdouble dMaxScale,const UGStyle& style);
	const UGStyle GetStyle(UGdouble dScale);
	//! \brief ɾ�����з�Ĭ�Ϸ��(����Ĭ��)
	void RemoveAllStyle();
	//! \brief ��ȡ������(������Ĭ�Ϸ��)
	UGint GetStyleCount()const {return m_scaleStyle.GetSize();};
	//! \brief ��ȡ����ָ���������·��
	void GetScalStyle(UGArray<ScaleStyle>& styles){styles = m_scaleStyle;};
	//! \brief ����/��ȡ��ѯ�����ֶ�,�ýӿ���Ҫ���ڵ���ͬһ��ͼ�㼸�ζ���ĵ��ǹ�ϵ�����ֶ��������Ϊ�Զ������ֶ�
	UGbool SetOrderField(UGString strField);
	//! \brief ����/����Ƿ�ĳһ�ֶ�(��SmID)˳���ѯ
	UGString GetOrderField();
	//! \brief �Ѹ���ID�ŵĶ���ŵ���ǰ��
	UGbool BringToFront(UGlong nID);
	//! \brief �Ѹ���ID�ŵĶ���ŵ������
	UGbool SendToBack(UGlong nID);
	//! \brief ����ͼ��ѹ�Ǵ���
	void SetOrderOverlap(UGbool bOrderOverlap = true);
	//! \brief �Ƿ��ͼ��ѹ�Ǵ���
	UGbool IsOrderOverlap();
	
	//! \brief ���ζ����Ƿ�ɼ�
	/**
	\param pGeometry             ���ζ���[in]
	\param dMinimumVisible       ��С��ʾ������[in]
	\return                      �ɼ�����true����֮Ϊfalse
	*/
	UGbool IsGeometryVisible(UGGeometry *pGeometry, UGdouble dMinimumVisible)const;

	//! \brief ���ζ����Ƿ�ɼ�
	/**
	\param pGraphics            ���Ƶ���Graphics[in]
	\param pDrawing				������[in]
	\param querfdef				�õ��Ĳ�ѯ���[in]
	\return                     �ɹ�����true����֮Ϊfalse
	*/
	UGbool PrepareQueryDef(UGGraphics* pGraphics, UGDrawing* pDrawing, UGQueryDef*& querfdef);

	//added by lugw 2007-06-05 
	//! \brief �õ�ͼ������
	UGint GetType();
	//! \brief ����ͼ������
	void SetType(UGint nType);

	//! \brief ���ø�ͼ������
	void SetParentDsName(UGString strName);
	//! \brief �õ���ͼ������
	UGString GetParentDsName();

	//! \brief ���ζ���������Ļص�����
	void SetAfterGeometryDrawFunc(AfterGeometryDrawProc pAfterGeometryDrawFunc,UGlong pWnd);
	//! \brief ���ζ������ǰ�Ļص�����
	void SetBeforeGeometryDrawFunc(BeforeGeometryDrawProc pBeforeGeometryDrawFunc,UGlong pWnd);
	void SendAfterGeometryDrawFunc(UGString strLayerName,UGint nGeometryID,UGGraphics* pGraphics);
	void SendBeforeGeometryDrawFunc(UGbool& bCancel,UGString strLayerName,UGint nGeometryID,UGGraphics* pGraphics);

	//! \brief �õ�դ��͸����
	UGint GetOpaqueRate();	
	//! \brief ����դ��͸����
	void SetOpaqueRate(UGint nOpaqueRate);	
	
	//! \brief �õ�����
	UGint GetBrightness();
	//! \brief ��������
	void SetBrightness(UGint nBrightness);

	//! \brief �õ��Աȶ�
	UGint GetContrast();
	//! \brief ���öԱȶ�
	void SetContrast(UGint nContrast);

	//! \brief �Ƿ񱳾�͸��
	UGbool IsRasterBackTransparent() const;
	//! \brief �����Ƿ񱳾�͸��
	void SetRasterBackTransparent(UGbool bBackTransparent);

	//! \brief �õ�������ɫ����
	UGbyte GetRasterBackColorTolerance() const;
	//! \brief ���ñ�����ɫ����
	void SetRasterBackColorTolerance(UGbyte nBackColorTolerance);

	//! \brief �õ�դ�񱳾�ɫ
	UGColor GetImageBackColor() const;
	//! \brief ����դ�񱳾�ɫ
	void SetImageBackColor(UGColor crBack);

	//! \brief �õ���ֵ���
	UGColor GetGridNoDataColor() const;
	//! \brief ������ֵ���
	void SetGridNoDataColor(UGColor crNoDataColor);
	
	//! \brief �õ������Ƿ�ʹ����ʾ�ü�����
	UGbool IsDisplayClip() const;							
	//! \brief �õ��Ƿ�ʹ����ʾ�ü�����
	void SetDisplayClip(UGbool bIsDisplayClip);		

	//! \brief �Ƿ��Ż�ʮ��·��
	UGbool IsCrossroadOptimized()const;
	//! \brief �����Ƿ��Ż�ʮ��·��
	void SetCrossroadOptimized(UGbool bIsCrossroadOptimized);
	//! \brief �ڲ����ú���
	void SetLayers(UGLayers *pLayers);

	//! \brief ��ȡ�������ݼ�����ͼ��
	UGbool GetWebSubLayers(UGArray<UGString>& aryLayerNames) const;
	//! \brief �����������ݼ�����ͼ���Ƿ�ɼ�����
	void SetWebSubLayersVisble(const UGbyteArray& arrLayersVisible);
	//! \brief �õ��������ݼ�����ͼ���Ƿ�ɼ�����
	void GetWebSubLayersVisble(UGbyteArray& arrLayersVisible) const;

	UGColorTable m_ColorsetTable;

protected:
	UGbool OnDrawRaster(UGGraphics* pGraphics, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	UGbool OnDrawVector(UGGraphics* pGraphics, UGDrawing *pDrawing,UGProgress* pProgress = NULL);

	UGbool OnDrawThemeNone(UGDrawing *pDrawing,UGProgress* pProgress = NULL);	
	UGbool OnDrawThemeStyle(UGThemeStyle* pThemeStyle, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	UGbool OnDrawThemeGraph(UGThemeGraph* pThemeGraph, UGDrawing *pDrawing,UGProgress* pProgress = NULL);	
	UGbool OnDrawThemeGraduatedSymbol(UGThemeGraduatedSymbol* pThemeGraduatedSymbol, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	UGbool OnDrawThemeDotDensity(UGThemeDotDensity* pThemeDotDensity, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	UGbool OnDrawThemeLabel(UGThemeLabel* pThemeLabel, UGDrawing *pDrawing,UGProgress* pProgress = NULL);

	UGbool OnDrawThemeNoneCrossroad(UGDrawing *pDrawing);

	UGbool OnDrawStyleThemeCrossroad(UGThemeUnique *pThemeUnique, UGDrawing *pDrawing);

	UGbool IsCancelByUser(UGDrawing *pDrawing) const; 
	UGbool IsVisibleByGeoID(const UGint& nID)const;

	UGbool ThemeStyleToDataset(UGThemeStyle *pThemeStyle, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeDotDensityToDataset(UGThemeDotDensity *pThemeDotDensity, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeGraphToDataset(UGThemeGraph *pThemeGraph, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeGraduatedSymbolToDataset(UGThemeGraduatedSymbol *pThemeGraduatedSymbol, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeLabelToDataset(UGThemeLabel *pThemeLabel, UGRecordset *pRecordset, UGDrawing *pDrawing, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGGeometry* ThemeLabelBackToGeometry(UGThemeLabel *pThemeLabel, UGGeoText* pGeoText, UGDrawParamaters *pDrawParam,const UGPoint2D& pntObjCenter);
	UGGeometry* LabelBoundsToGeometry(const UGRect2D& rcBounds, const UGPoint2D& pntCentroid, UGdouble dAngle, UGint nLabelBackType, const UGStyle& backStyle,  UGDrawParamaters *pDrawParam);
	//added by dongfei 2007-04-23
	//! \brief ����ǣ���߶�������������ں���Ҫǣ���ߵĶ�����
	/*
	\param rect			��Ҫǣ���߶������Ӿ���
	\param pntFrom      ǣ������ʼ��  
	\param pntAnchor		��ת����
	\param dAngle	          ��ת�Ƕ�
	\return				ǣ���ֶ��� Ϊ��ʼ��;������ĵ㸽������Χ�ɵĵ���������		
	\remarks			��Ҫ�ⲿ�ͷŷ��ص�region			
	*/	
	UGGeoRegion* GetLeaderObject(const UGRect2D& rect,const UGPoint2D& pntFrom, const UGPoint2D& pntAnchor, UGdouble dAngle);

	
public:	
	UGThemes m_Themes;

	UGTheme* m_pTheme;
	//added by xielin 2007-04-13
	//! \brief ��ͼ��༭ģʽ�£�ÿ��Layer����һ��selection 
	UGSelection m_Selection;  
	
	//! \brief ͼ���Ƿ��ܻ��Ƶı�������������������Ƹ�ͼ���Ƿ���Ի���
	//�Ժ����ͼ�㣬�ж�visibleΪtrue�����Ҹñ���Ϊtrue��������Ƶ�ԭ����
	//��Ϊsfc�е�ͼ������е�ֵר��ͼ����ȡ��ugc�зֲ㣬����Ϊ���Ż�����Ҫ����ԭʼ
	//ͼ���visibleΪfalse�����������͵��±��湤���ռ��ʱ��ͼ��״̬�ʹ���
	//(��ȡhashcode��ʱ��Ҳ���ˣ������Ծ����Ӹñ�����ר���������ƣ�����ȥ�ı�ͼ��Ŀɼ�״̬
	//UGbool m_bCanDraw;
	UGArray<UGint> m_arrInvisibleGeoIDs;   // ͼ���в��ɼ��ļ��ζ����ID--Add by litao,2001/8/3
protected:
	//! \brief ��0.1mmΪ��λ
	UGint m_nMinimumVisible;
	
	UGRecordset *m_pDisplayRecordset;	
	UGRecordset *m_pEditRecordset;		
	UGStyle m_Style;					// ͼ����ʾ���
public:
	UGQueryDef m_QueryDef;
protected:	
	UGString m_strDescription;			// ͼ������
	UGString m_strCaption;				// caption for this layer
	UGString m_strDataSourceAlias;		// �����ͼ������ݼ����ڵ�����Դ����
	UGString m_strDatasetName;

	UGdouble m_dVisibleScaleMax;		// ����ͼ�����ߴ��ڸ�ֵ��ʱ�򣬱�ͼ�㲻��ʾ������ֵ����0�����������Ч��Ĭ��Ϊ0
	UGdouble m_dVisibleScaleMin;		// ����ͼ������С�ڸ�ֵ��ʱ�򣬱�ͼ�㲻��ʾ������ֵ����0�����������Ч��Ĭ��Ϊ0
	UGdouble m_dSymScaleDefinition;		// �����ͼ�ķ�������ͼ�����Ŷ����ţ�����ͼ�����ߵ��ڸ�ֵ��ʱ��ͼ��ķ��Ű�geoStyle�ķ��Ŵ�С��ʾ

	UGLayer* m_pParentLayer;
	UGLayer* m_pChildLayer;
	UGDataset *m_pDataset;
	UGuint m_unOptions;

	UGint m_nFillOrgMode;					// ��ˢԭ��ģʽ
	UGbool m_bSingle;
	UGint m_nType;
	UGString m_strParentDsName;
	
	
	
	//added by dongfei 2007-04-24
	//! \brief ͼ���� ��һ���ǡ����ݼ�@����Դ����
	UGString m_strName;
	//! \brief ��ͬ�������µķ��
	UGArray<ScaleStyle> m_scaleStyle;
	UGString m_strOrderField;
	
	UGchar m_btBrightness;	// դ��ͼ�����ȣ�ֵ��ΧΪ-100��100����������Ϊ������������Ϊ��
	UGchar m_btContrast;		// դ��ͼ��Աȶȣ�ֵ��ΧΪ-100��100����ǿ�Աȶ�Ϊ���������Աȶ�Ϊ��
	UGbyte m_btOpaqueRate;			// ��͸����0----100% 100Ϊ��͸����0Ϊ��ȫ͸����ֻ��դ�����ݼ���Ч

	UGColor m_ImageBackColor;  // դ�񱳾�ɫ��
	UGColor m_GridNoDataStyle; // ��ֵ���
	UGbool m_bRasterBackTransparent; // ����͸����
	UGbyte m_btBackColorTolerance; // ������ɫ����

	AfterGeometryDrawProc m_pAfterGeometryDrawFunc;
	BeforeGeometryDrawProc m_pBeforeGeometryDrawFunc;

	UGlong m_pEventView;  //�����¼��ص������Ķ���ָ�룬ͳһΪһ���ɣ���ʡ�ڴ�
	//added by xielin 2007-09-29 ��¼���ڵ�ͼ�㼯�ϣ������޸�ͼ��������༭״̬��
	//ͨ��Layers�лص�����֪ͨ��Ӧ��ģ��
	UGLayers* m_pLayers; 

	UGbyteArray m_arrWebLayersVisible;
};

}

#endif // !defined(AFX_UGLAYER_H__A4B430F7_6A63_4275_BB13_EF15BA12DDAD__INCLUDED_)
