// UGMarkerSymParam.h: 

#ifndef UG_MARKERSYMPARAM_H
#define UG_MARKERSYMPARAM_H

#include "UGSymPoint.h"
#include "Algorithm/UGPoint.h"

namespace UGC 
{

class UGPen;
class UGBrush;
class UGFont;
class UGRgn;


/** ���������ת������ʾ����
	@remarks
		������2�����ã�
		1������������֮ǰ����������ת������Transform()��
		   ������ŵĶ��������ת��Ϊ�����ϵ��߼����ꣻ
		2����¼������ʾʱ��һЩ���Ʋ��������£�
				    m_Color --> ������ʾ����ɫ   
			   m_bHighlight --> �����Ƿ�Ҫ������ʾ
				m_pntAnchor --> ����ԭ������ʾ�����еĶ�Ӧ��(��ΪAnchor������ʾ������)
			 m_nDisplaySize --> ��������ʾ�豸����Ҫ��ʾ�Ĵ�С(��λ����ʾ�豸��ӳ��ģʽ��ȷ��)
				   m_dAngle --> ������ת�ĽǶ�(��λ:��)
				   m_dScale --> ������ʾ���ŵı���ϵ��(����m_nDisplaySize�Ĵ�С����������)
		   �ⲿ�ڵ��õ���ŵĻ��ƺ���UGPointSymbol::Draw()֮ǰ��Ҫ��
		   �趨�����е���Щ��ʾ���Ʋ������趨���ٴ��ݸ�Draw����
*/
class SYMBOL_API UGMarkerSymParam  
{
public:

	/** �����ݽṹ�����ڵ���űʻ����ƹ����У���¼�´�����GDI����ָ��
	*/
	struct UGGraphicsObjects
	{
		UGGraphicsObjects();
		//deleted by xielin ��������������release�±���drawing���̱��벻����ԭ�򻹲�����������޸ĳ��ṩdeleteall�������������һ�����ͷ�
		//~UGGraphicsObjects();

		void NewPen();
		void NewBrush();
		void NewFont();
		void NewRgn();
		void DeleteAll();

		UGPen*   m_pOldPen;
		UGBrush* m_pOldBrush;
		UGFont*  m_pOldFont;

		//! UGC���������洴��(new)��GDI����ע�⣺ʹ�ú���Ҫ�Լ����ͷ�
		UGPen*   m_pNewPen;
		UGBrush* m_pNewBrush;
		UGFont*  m_pNewFont;

		//! ΪHitTest��׼����Rgn,�����ڵ���ŵ�HitTest��,���ᱻѡ�뵽graphics��
		UGRgn*  m_pNewRgn;

	};

public:
	UGMarkerSymParam();
	//added by xielin ������������
	~UGMarkerSymParam();
public:	
	void SetAngle(UGdouble dAngle)
	{
		m_dAngle = dAngle;
	}

	UGdouble GetAngle() const
	{
		return m_dAngle;
	}
	
	void SetAnchor(const UGPoint& pntAnchor)
	{
		m_pntAnchor = pntAnchor;
	}

	const UGPoint& GetAnchor() const
	{
		return m_pntAnchor;
	}
	
	void SetColor(UGColor color)
	{
		m_Color = color;
	}

	UGColor GetColor() const
	{
		return m_Color;
	}
	
	void SetScale(UGdouble dScale,UGdouble dScaleX=0)
	{
		m_dScale = dScale;
		//{{ �������x��������ű���ϵ�� modified by dongfei 2007-03-29
		m_dScaleX = dScaleX;
		//}} �������x��������ű���ϵ�� modified by dongfei 2007-03-29
	}

	UGdouble GetScale() const
	{
		return m_dScale;
	}
	//! \brief ��ȡX��������ű���ϵ�� added by dongfei 2007-03-29
	UGdouble GetScaleX() const
	{
		return m_dScaleX;
	}
	void SetHighlight(UGbool bHighlight = true)
	{
		m_bHighlight = bHighlight;
	}

	UGbool IsHighlight() const
	{
		return m_bHighlight;
	}

	void SetDisplaySize(UGint nSize)
	{
		m_nDisplaySize = nSize;
	}

	UGint GetDisplaySize() const
	{
		return m_nDisplaySize;
	}

	void SetPointSymOrg(const UGSymPoint& pntOrg)
	{
		m_pntPointSymOrg = pntOrg;
	}
	
	const UGPoint* GetPointBuffer() const
	{
		return m_PointBuf.GetData();
	}

	UGPoints& GetBuffer()
	{
		return m_PointBuf;
	}

	UGint GetPointCount() const
	{
		return m_PointBuf.GetSize();
	}

	void SetDeviceYAxisDirection(UGbool bYAxisUp)
	{
		m_bDeviceAxisYUp = bYAxisUp;
	}

	UGbool IsDeviceYAxisUp()
	{
		return m_bDeviceAxisYUp;
	}

	UGMarkerSymParam::UGGraphicsObjects& GetGraphicsObject()
	{
		return ms_GObjects;
	}

	const UGMarkerSymParam::UGGraphicsObjects& GetGraphicsObject() const
	{
		return ms_GObjects;
	}
	
	/** �����ŵġ��㶨�����꡻ת��Ϊ��ʾ�����ڵġ���ʾ�߼����꡻
		pSymPoints: �㶨������
		nCount��    ��ĸ���
		bRotate��   �Ƿ���ת
	*/
	void Transform(const UGSymPoint* pSymPoints, UGint nCount, UGbool bRotate = TRUE );
	void Transform(const UGPoint* pPoints, UGint nCount, UGbool bRotate = TRUE );

	//added by lugw 2007-04-16
	//! \brief ���ŵ�͸����
	void SetTransPercent(UGint nTransPercent);
	UGint GetTransPercent();

	//! \brief ���ŵĽ����������
	void SetGradientEndColor(UGColor EndColor);
	UGColor GetGradientEndColor();

	void SetGradientRadian(UGdouble dRadian);
	UGdouble GetGradientRadian();

	void SetGradientHOffsetCenter(UGint nHOffsetCenter);
	UGint GetGradientHOffsetCenter();

	void SetGradientVOffsetCenter(UGint nVOffsetCenter);
	UGint GetGradientVOffsetCenter();

	void SetGradientGradientType(UGint nType);
	UGint GetGradientGradientType();

protected:

	UGdouble Minus(UGdouble value)
	{
		//�����ʾ�豸Y�����������ϣ���ȡ��ֵ������ȡ��ֵ
		return m_bDeviceAxisYUp ? -value : value;
	}
	
private:
    //! ������ʾ����ɫ
 	UGColor m_Color;

	//! �����Ƿ�Ҫ������ʾ
	UGbool  m_bHighlight;

	//! ����ԭ������ʾ�����еĶ�Ӧ�㣬Ҳ���Ƿ�����Ҫ��ʾ��λ��(��ΪAnchor������ʾ������)
	UGPoint m_pntAnchor; 

	//! ��������ʾ�豸����Ҫ��ʾ�Ĵ�С(��λ����ʾ�豸��ӳ��ģʽ��ȷ��)
	UGint m_nDisplaySize;

	//! ������ת�ĽǶ�(��λ:��)
	UGdouble m_dAngle;

	//! ������ʾ���ŵı���ϵ��(����m_nDisplaySize�Ĵ�С����������)
	UGdouble m_dScale;   
	//! brief ���һ��X��������ű���ϵ�������Ϊ0���������m_dScale��ͬ��ϵ������ʱ
	//m_dScale��ʾ�������ŵı���ϵ������Ϊ0����m_dScale�Ǹ߶ȵı���ϵ�� added by dongfei 
	//2007-03-29
	UGdouble m_dScaleX;

	//! ��ʾ�豸����ϵY���Ƿ�����(���ڽ����ŵ㶨������ת������ʾ�߼�����,��Transform()�������õ�)
	UGbool m_bDeviceAxisYUp; 

	//! ������ڷ�������ϵͳ�е�ԭ��(���ŵ�����ת��ʱ��Ҫ�����Ϣ,��Transform()�������õ�)
	UGSymPoint m_pntPointSymOrg;
	
	//! �߼��㴮���壬�������ת������߼������(UGSymPoint-->UGPoint)
	UGPoints m_PointBuf;

	//modified by xielin 2007-12-27 ����Ҫ֧�ֶ��̣߳�ȫ�־Ͳ����ˣ��ĵ�
	//! ���ڵ���Ż��ƹ����м�¼�´���GDI�����graphicsѡ���¶���ǰ��ԭ����old����
	//! ��̬��Ա���������������й���һ�ݾ͹���
	UGMarkerSymParam::UGGraphicsObjects ms_GObjects;
	
	//! \brief ���ŵ�͸����
	UGint m_nTransPercent;

	//! \brief ���ŵĽ�����ز���
	UGColor              m_EndColor;       //����ı���ɫ
	UGdouble             m_dRadian;        //����ĽǶ�
	UGint                m_nHOffsetCenter; //�����ˮƽƫ����
	UGint                m_nVOffsetCenter; //�������ֱƫ����
	UGint				 m_nGradientType;  //���������
};

}

#endif
