
/*!
   **************************************************************************************
    \file     UGFillSymbol.h
   **************************************************************************************
    \author   �¹���
    \brief    �������ࡣ                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-23  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
   \version 2.0
   <b>����˵����</b>\n
   <em>1������ʵ���Ӳ����Ĺ��ܣ�����������һ���Ӳ�����UGFillSymbolBase���У���ϸ�鿴�������в鿴\n
   <em>2�����յ���ź��߷��ŵĹ���ʽ��Ŀǰ������Ҫ�������Ӳ�Ĺ������Ƶȹ��ܣ������������ŵĴ洢��Ҫ�ŵ�UGFillSymbolBase���й����ڶ�ȡ�����ϼ�����ǰ��FillSymbolLib�����±�֤��ȡ�ʹ洢�����Ӳ�UGFillSymbolBase�е����ݣ�ͬʱ������ǰ�ĸ�ʽ��\n
*/



#ifndef UGFILLSYMBOL_H
#define UGFILLSYMBOL_H

#include "UGSymbol.h"
#include "UGMarkerSymFill.h"
#include "UGFillSymParam.h"
#include "Symbol/UGFillSymbolBase.h"

namespace UGC {

class SYMBOL_API UGFillSymbol : public UGSymbol
{
public:
	enum RenderImageType
	{
		RIT_NORMAL = 0,		//! Image ���
		RIT_AND = 1,		//! Image And ���
		RIT_OR = 2			//! Image Or ���
	};	

public:
	UGFillSymbol();
	virtual ~UGFillSymbol();
	UGFillSymbol(const UGFillSymbol& symbol);
	virtual UGFillSymbol& operator = (const UGFillSymbol& symbol);

public:
	//! \brief ������������Ϣ
	virtual UGbool Load(UGStream& stream, UGuint nVersion = 0);
	//! \brief ������������Ϣ
	virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

	//! \brief ���ƶ�������
	/**
	\param graphics			���Ƶ���graphics[in]
	\param FillSymParam		������[in]
	\param pPoints			����[in]
	\param nCount			�����[in]
	*/
	void Polygon(UGGraphics& graphics, UGFillSymParam& FillSymParam,
				const UGPoint* pPoints, UGint nCount);
	//! \brief ���ƶ����������
	/**
	\param graphics			���Ƶ���graphics[in]
	\param FillSymParam		������[in]
	\param pPoints			����ָ��[in]
	\param pPointCount		��������ÿ��ĵ����[in]
	\param nCount			����[in]
	*/
	void PolyPolygon(UGGraphics& graphics, UGFillSymParam& FillSymParam, 
				const UGPoint* pPoints,	const UGint* pPointCount, UGint nCount);
	//! \brief ���ƾ������
	/**
	\param graphics			���Ƶ���graphics[in]
	\param FillSymParam		������[in]
	\param rect				������[in]
	*/
	void Rectangle(UGGraphics& graphics, UGFillSymParam& FillSymParam, const UGRect& rect);

	//! \brief �õ������ŵ�nIndex���ӷ��ŵ����ͣ�Ĭ��Ϊ0
	UGint GetType(UGint nIndex = 0) const;

	//! \brief ���������ŵ�nIndex���ӷ��ŵĵ������Ϣ
	void SetMarkerSymFill(UGMarkerSymFill* pMarkerSymFill,UGint nIndex = 0);
	//! \brief �õ������ŵ�nIndex���ӷ��ŵĵ������Ϣ
	UGMarkerSymFill* GetMarkerSymFill(UGint nIndex = 0) const;

	//! \brief �õ������ŵ�nIndex���ӷ��ŵķֱ���
	UGint GetResolution(UGint nIndex = 0) const;
	//! \brief ���������ŵ�nIndex���ӷ��ŵķֱ���
	void SetResolution(UGint nResolution,UGint nIndex = 0);
	//! \brief ����һλͼ
	UGbool LoadBitmap(const UGString& strFileName);
	//! \brief �����λͼ��Ϣ
	/**
	\param strFileName		���·��[in]
	\param pSymLib			���Ϊ�������䣬ָ���õ���Ŷ�Ӧ�ĵ���ſ�[in]
	\param nIndex			��nIndex�ӷ���[in]
	\param clrFront			ǰ��ɫ[in]
	\param clrBack			����ɫ[in]
	\return �Ƿ�ת���ɹ�
	*/
	UGbool SaveBitmap(const UGString& strFileName,
		        UGMarkerSymbolLib* pSymLib = NULL,
		        UGint nIndex = 0,
				UGColor clrFront = UGRGB(0,0,0), 
				UGColor clrBack = UGRGB(255,255,255));
	const UGImage::UGImageData* GetImageData(UGint nIndex = 0) const;
	//! \brief  ��Ⱦ��Ҫ���ķ���
	/**
	\param graphics          ���Ƶ���ʾ����[in]
	\param FillSymParam      ���Ʋ���[in]
	\param nRenderImageType  ��������[in]
	\return ������Ⱦ�õ���Image
	*/
	UGImage* Render(UGGraphics& graphics, UGFillSymParam& FillSymParam, UGint nRenderImageType);
	//! \brief  ������ݣ������ڴ��ͷ�
	void Clear();
	UGbool EnableBackTransparent(UGint nIndex = 0);

	//! \brief  �õ��Ӳ����
	UGint GetCountOfFillSymbolBase()const;	
	//! \brief  �õ���nIndex�Ӳ�ָ��
	/**
	\param nIndex     �Ӳ������[in]
	\return ���ظò�ָ��
	*/
	UGFillSymbolBase* GetFillSymbolBaseAt(UGint nIndex)const;

	//! \brief  ���ĳһ��
	void AddFillSymbolBase(UGFillSymbolBase* pBaseFillSymbol);
	//! \brief  ���ĳһ��
	void AddFillSymbol(UGFillSymbol* pFillSymbol);

	//! \brief  �Ƴ�ĳһ��
	UGbool RemoveFillSymbolBase(UGint nIndex);
	//! \brief  �Ƴ�ĳһ��
	UGbool RemoveFillSymbolBase(UGFillSymbolBase* pBaseFillSymbol);

protected:
	UGint GetBitmapSize(const UGImage::UGImageData* pImageData) const;
	UGbool SaveBitmap(UGStream& stream, UGint nFileSize, const UGImage::UGImageData* pImageData) const;
	UGbool LoadBitmap(UGStream& stream,UGint nIndex,UGint nResolution);
	UGbool LoadMarkerSymFill(UGStream& stream,UGint nIndex);
	UGbool RegionWithImage(UGGraphics& graphics, UGFillSymParam& FillSymParam, UGRgn *pRgn, UGbool bRect = false);
	void PrepareFillSymParam(UGFillSymParam& subFillSymParam,const UGFillSymParam& FillSymParam,UGFillSymbolBase* pBaseFillSymbol)const;
	//! ͸������λͼ��������һ����ɫ(�ɲ���clrTransparentָ��)����ڱ���ͼ͸����ʾ
	void TransparentDraw(UGGraphics& graphics, UGImage* pImgSrc, 
		                 UGint xStart, UGint yStart, UGColor clrTransparent, UGint nTransPercent = 100) const;

protected:
	UGArray<UGFillSymbolBase* > m_pFillSymbolBase;
	
};

}

#endif


