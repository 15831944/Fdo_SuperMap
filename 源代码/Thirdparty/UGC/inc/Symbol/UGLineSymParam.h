// UGLineSymParam.h:

#ifndef UG_LINESYMPARAM_H
#define UG_LINESYMPARAM_H

#include "Graphics/UGGraphics.h"

namespace UGC 
{
	
class UGLineSymbolBase;
class UGMarkerSymbolLib;

class UGPen;
class UGBrush;
class UGFont;
	
	/** ���͵���ʾ���������а���������ò���(��ɫ���߿�������) 
	    @remarks
	       ���ⲿ���Զ����ͽ���һЩ������ã�������
		   1. ������ɫ��
		   2. ���Ϳ�ȣ�
		   3. ���ű�����
		   ���߻���ʱ��������Щ�����������д�����Ӧ�Ļ��ʽ��л��ƣ�
		   ע����������ڲ��Ѿ��̶�����ɫ���ȣ�
		       �ڻ���ʱ����ʹ���ڲ��̶�����ɫֵ��̶��Ŀ��ֵ;
			   �Ͳ�������Щ�ⲿ���õ���ɫ���ȣ�
	*/
class SYMBOL_API UGLineSymParam  
{
public:
	//! ���߻��ƹ����У�Ҫʹ�õ���GDI����
	struct UGGraphicsObjects
	{
		UGGraphicsObjects();
		~UGGraphicsObjects();

		void  NewPen();
		void  NewBrush();
		void  NewFont();

		UGPen*   m_pOldPen;
		UGBrush* m_pOldBrush;
		UGFont*  m_pOldFont;

		//! UGC���������洴��(new)��GDI����ʹ�ú���Ҫ�Լ����ͷ�
		UGPen*   m_pNewPen;
		UGBrush* m_pNewBrush;
		UGFont*  m_pNewFont;

		UGint    m_nOldTxtAlign;
		UGint    m_nOldBkMode;
		UGColor  m_nOldTxtClr;
	};

public:
	UGLineSymParam();
	~UGLineSymParam();
	
public:
	void SetDefaultPen(UGPen* pDefaultPen);
	UGPen* GetDefaultPen() const;
	
	void SetPenWidth(UGint nPenWidth);
	UGint GetPenWidth() const;
	
	void SetPenColor(UGColor color);
	UGColor GetPenColor() const;
	
	void SetScale(UGdouble dScale);
	UGdouble GetScale() const;
	
	void SetHighlight(UGbool bHighlight = true);
	UGbool IsHighlight() const;

	UGPoints& GetPointsBuffer();
	
	UGMarkerSymbolLib* GetMarkerSymbolLib() const;
	void SetMarkerSymbolLib(UGMarkerSymbolLib *pMarkerSymLib);

	//! \brief �Ƿ���Ҫ���²�������Ҫ���ڻ������͵�ʱ��
	UGbool IsNeedSampling();
	void   SetNeedSampling(UGbool bNeedSampling);

	UGGraphicsObjects& GetGraphicsObject();
	
	void Release();

	UGint m_nCrossroadIndex;
	
protected:
	//! ȱʡ����(���ⲿ�����ô��ݽ�����)
	UGPen*           m_pDefaultPen;

	//! �ⲿ���������õ�����ɫ
	UGColor          m_PenClr;

	//! �ⲿ���������õ��߿��
	UGint            m_nPenWidth;

	//! ���ͷ������ŵı���
	UGdouble         m_dScale;

	//! �Ƿ��Ǹ�����ʾ
	UGbool           m_bHighlight;

	//! ��������ʱ���Ƿ�Ҫ�����߶������ݽ����ز���
	UGbool           m_bNeedSampling;

	//! �ڴ滺������������������ʾʱ��ʱ����ʹ��
	UGPoints m_PointBuf;
	
	//! ����ſ⣬���������͵���չ�����е��Զ���token(�Զ���tokenʹ��һ�������������)
	UGMarkerSymbolLib* m_pMarkerSymLib;

	//! �������ͷ��ŵĻ��߻��ƹ����м�¼�´���GDI�����graphicsѡ���¶���ǰ��ԭ����old����
	//! ��̬��Ա���������������й���һ�ݾ͹���
	//modified by xielin 2007-12-27 ����Ҫ֧�ֶ��̣߳�ȫ�־Ͳ����ˣ��ĵ�
	UGLineSymParam::UGGraphicsObjects ms_GObjects;

};
	
}

#endif
