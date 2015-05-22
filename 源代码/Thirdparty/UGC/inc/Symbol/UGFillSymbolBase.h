/**  \file UGFillSymbolBase.h
   \brief ʵ�����������Ӳ����
   \author lugw
   \attention Ϊ��ʵ�ֶ����䣬���Խ�ԭ�ȵ�UGFillSymbol��һ���ΪUGFillSymbolBase�������������ع��ܣ���ԭ�ȵ�UGFillSymbol��������ӣ����Ƶȹ���
   Copyright(c) 1996-2007 SuperMap GIS Technologies, Inc.<br>
   All Rights Reserved.
 */

#ifndef UGFILLSYMBOLBASE_H
#define UGFILLSYMBOLBASE_H

#include "UGSymbol.h"
#include "UGMarkerSymFill.h"
#include "UGFillSymParam.h"

namespace UGC {
	
class SYMBOL_API UGFillSymbolBase
{

public:

	enum FS_RESOLUTION		//! �ֱ��ʣ�
	{
		FS_72DPI = 72,
		FS_81DPI = 81,
		FS_96DPI = 96,
		FS_127DPI = 127,
		FS_150DPI = 150,
		FS_200DPI = 200,
		FS_254DPI = 254
	};

	enum FillSymbolType
	{
		FST_BITMAP = 0,		//! bmp ���
		FST_POINTSYMBOL = 1	//! ��������
	};

	enum RenderImageType
	{
		RIT_NORMAL = 0,		//! Image ���
		RIT_AND = 1,		//! Image And ���
		RIT_OR = 2			//! Image Or ���
	};	

public:
	UGFillSymbolBase();
	virtual ~UGFillSymbolBase();
	UGFillSymbolBase( UGFillSymbolBase& symbol);
	virtual UGFillSymbolBase& operator = ( UGFillSymbolBase& symbol);
	
public:
	//! \brief �õ��������
	UGint GetType() const;
	//! \brief �����������
	void  SetType(UGbyte eType);

	//! \brief �õ��ֱ���
	UGint GetResolution()const;
	//! \brief ���÷ֱ���
	void SetResolution(UGint nResolution);

	//! \brief ���õ���������Ϣ
	void SetMarkerSymFill(UGMarkerSymFill* pMarkerSymFill);
	//! \brief �õ�����������Ϣ
	UGMarkerSymFill* GetMarkerSymFill() const;

	//! \brief �õ�դ����������Ϣ
	const UGImage::UGImageData* GetImageData() const;
	//! \brief �������Ϣ��Ⱦ��ת���ʺ�Graphics���Ƶ�image
	/**
	\param graphics			���Ƶ���graphics[in]
	\param FillSymParam		������[in]
	\param nRenderImageType �������[in]
	\return �����Image��Ϣ
	*/
	UGImage* Render(UGGraphics& graphics, UGFillSymParam& FillSymParam, UGint nRenderImageType);
	//! \brief ���
	void Clear();
	//! \brief �����Ƿ�͸��
	UGbool EnableBackTransparent();
	//! \brief ����λͼ��Ϣ
	UGbool SaveBitmap(UGStream& stream, UGint nFileSize) const;
	//! \brief ��ȡλͼ��Ϣ
	UGbool LoadBitmap(UGStream& stream);
	//! \brief ��ȡ�������Ϣ
	UGbool LoadMarkerSymFill(UGStream& stream);

	//! \brief ��ȡָ��λͼ��������
	UGbool LoadBitmap(const UGString& strFileName);
	//! \brief ����������Ϊλͼ
	/**
	\param strFileName		���·��[in]
	\param pSymLib			���Ϊ�������䣬ָ���õ���Ŷ�Ӧ�ĵ���ſ�[in]
	\param clrFront			ǰ��ɫ[in]
	\param clrBack			����ɫ[in]
	\return �Ƿ�ת���ɹ�
	*/
	UGbool SaveBitmap(const UGString& strFileName, 
		UGMarkerSymbolLib* pSymLib = NULL,
		UGColor clrFront = UGRGB(0,0,0), 
		UGColor clrBack = UGRGB(255,255,255));
	
	//! \brief �Ƿ�̶�ǰ��ɫ
	UGbool IsFixedForeColor()const;
	//! \brief �Ƿ�̶�����ɫ
	UGbool IsFixedBackColor()const;

	//! \brief �õ�ǰ��ɫ
	UGColor GetForeColor() const;
	//! \brief ����ǰ��ɫ
	void    SetForeColor(UGColor color);
	//! \brief �õ�����ɫ
	UGColor GetBackColor() const;
	//! \brief ���ñ���ɫ
	void    SetBackColor(UGColor color);

	//! \brief �����Ƿ�̶�ǰ��ɫ
	void SetFixedForeColor(UGbool bFixed);
	//! \brief �����Ƿ�̶�����ɫ
	void SetFixedBackColor(UGbool bFixed);

protected:
	UGint GetBitmapSize() const;

protected:
	UGbyte m_eType;
	UGint m_nResolution;
	UGImage::UGImageData* m_pImageData;
	UGMarkerSymFill* m_pMarkerSymFill;
	/*   8 7 6 5 4 3 2 1---------- 1  fore�Ƿ�̶�
		 | | | | | | +------------ 2  back�Ƿ�̶�
		 | | | | | +-------------- 3 
		 | | | | +---------------- 4 
		 | | | +------------------ 5 
		 | | +-------------------- 6 
		 | +---------------------- 7 
		 +------------------------ 8 */
	UGuchar m_nProperties;
	UGColor m_ForeColor;
	UGColor m_BacColor;
};

}

#endif
