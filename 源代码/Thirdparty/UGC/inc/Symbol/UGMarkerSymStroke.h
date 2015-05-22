// UGMarkerSymStroke.h: 

#ifndef UG_MARKERSYMSTROKE_H
#define UG_MARKERSYMSTROKE_H

#include "UGMarkerSymParam.h"
#include "UGBitmapStroke.h"
#include "UGIconStroke.h"

namespace UGC 
{

/** ����ŵĹ���Ҫ��Stroke( ��Ϊ���ʻ� )
	@remarks
		1��һ��������ɶ���ʻ����ɣ�
		2���ʻ���Ϊ��״����״����״���ı��ʻ��Ĵ��ࣻ
		3��ÿ�ֱʻ����ɸ�����Ҫ�����Լ������ԣ��磺�߿���ɫ�����ȣ�
		4��ÿ���ʻ����п��Ƶ㣬���ڲ�ͬ�ıʻ�����ӵ�еĿ��Ƶ�ĸ�����һ��
		   ��Щ���Ƶ�����m_SymPoints��
*/
class SYMBOL_API UGMarkerSymStroke  
{     
public:

	//����űʻ�֧�ֵ�����(12��) -->����˳���SFC5.0����һ��
	enum StorkeType
	{  
		//��״
		ST_Point     = 0,   //��

        //��״
		ST_Polyline  = 1,   //����
		ST_Arc       = 2,   //����

		//��״
		ST_Polygon   = 3,   //�����
		ST_Ellipse   = 4,   //��Բ
		ST_Rectangle = 5,   //����
		ST_Roundrect = 6,   //Բ�Ǿ���

		//�ı�
		ST_Text      = 7,   //�ı�ע��   
		
		ST_Pie       = 8,   //����
		ST_Chord     = 9,   //����			
		
		//դ����չ����
		ST_Bitmap    = 10,  //����λͼ 
		ST_Icon      = 11   //����ͼ��

	};
	
	enum BrushStyle//��״�ʻ���������� (8��)
	{           
		BS_Solid      = 0,	// ʵ��仭ˢ
		BS_Null       = 1,	// �޻�ˢ
		BS_Vertical   = 2,	/* ||||| */
		BS_Horizontal = 3,	/* ----- */
		BS_Fdiagonal  = 4,	/* \\\\\ */
		BS_Bdiagonal  = 5,	/* ///// */
		BS_Cross      = 6,	/* +++++ */
		BS_Diagcross  = 7,	/* xxxxx */
	};
	
	enum PenStyle //��״�ʻ��Ļ�������(4��)
	{
		PS_Solid   = 0,
		PS_Dash    = 1,
		PS_Dot     = 2,
		PS_DashDot = 3
	};
	
public:
	UGMarkerSymStroke();
	~UGMarkerSymStroke();
	UGMarkerSymStroke(const UGMarkerSymStroke& rhs);
	UGMarkerSymStroke& operator = (const UGMarkerSymStroke& rhs);
	
public:	
	//! \brief ��ȡ����
	UGbool Load(UGStream& stream, UGuint nVersion = 0);
	//! \brief �洢����
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

	//! ���ƺ���
	/**
	\param graphics  ���Ƶ�����ͼ[in]
	\param symParam  ���Ʋ���[in]
	*/
	void   Draw(UGGraphics& graphics, UGMarkerSymParam& symParam) const;

public:
	//! ����¼�
	/**
	\param pntHitTest	�����λ��[in]
	\param symParam		����Ų���[in]
	\param nTolerance	����[in]
	\return 
	*/
	UGbool HitTest(const UGPoint& pntHitTest, UGMarkerSymParam& SymParam, UGint nTolerance) const;
	
	//! �õ���������
	StorkeType GetType() const;
	//! ���÷�������
	void  SetType(StorkeType type);

	//! �Ƿ�̶����Ż�����ɫ
	UGbool IsFixedPenColor() const;
	//! �Ƿ�̶����Ż�ˢ��ɫ
	UGbool IsFixedBrushColor() const;
	//! �Ƿ�̶������ı���ɫ
	UGbool IsFixedTextColor() const;
	//! \brief ������бʻ�����ʱ�õ��Ƿ�̶��ʻ������Ϣ��
	/**
	�õ��Ƿ�̶����ʣ�ʵ�ַ��ſ�ȵĹ̶���
	\remarks �Է����й̶���ȵ�ʵ�֣���ѭ���ŵ����ȼ����ڷ����бʻ������ȼ�������ڷ�����Ϣ��ѡ��̶����ſ�ȣ�����������бʻ������Ƿ����ù̶���ȶ�����Ϊ�̶���ȣ����������û��ѡ��̶���ȣ����ڷ����еıʻ���Ϣ��ȡʱ��ȷ�������ʻ��Ŀ���Ƿ�̶���
	*/
	UGbool IsFixedPenWidth() const;
	//! \brief ������бʻ�����ʱ�õ��Ƿ�̶��ʻ�͸������Ϣ��
	UGbool IsFixedTransPercent() const;
	//! \brief ������бʻ�����ʱ�õ��Ƿ�̶��ʻ�������Ϣ��
	UGbool IsFixedGradient() const;
	
	//! \brief ���õ�����бʻ�����ʱ�Ƿ�̶��ʻ������Ϣ��
	/**
	�����Ƿ�̶����ʡ�
	\remarks �Է����й̶���ȵ�ʵ�֣���ѭ���ŵ����ȼ����ڷ����бʻ������ȼ�������ڷ�����Ϣ��ѡ��̶����ſ�ȣ�����������бʻ������Ƿ����ù̶���ȶ�����Ϊ�̶���ȣ����������û��ѡ��̶���ȣ����ڷ����еıʻ���Ϣ��ȡʱ��ȷ�������ʻ��Ŀ���Ƿ�̶���
	*/
	void SetFixedPenColor(UGbool bFixed);
	//! �����Ƿ�̶����Ż�ˢ��ɫ
	void SetFixedBrushColor(UGbool bFixed);
	//! �����Ƿ�̶������ı���ɫ
	void SetFixedTextColor(UGbool bFixed);
	//! �����Ƿ�̶����ſ��
	void SetFixedPenWidth(UGbool bFixed);
	//! \brief ���õ�����бʻ�����ʱ�Ƿ�̶�͸����
	void SetFixedTransPercent(UGbool bFixed);
	//! \brief ���õ�����бʻ�����ʱ�Ƿ�̶�����Ч��
	void SetFixedGradient(UGbool bFixed);
	
	//! �õ����Ż��ʿ��
	UGuchar  GetPenWidth() const;	
	//! �õ����Ż�����ɫ
	UGColor  GetPenColor() const;	
	//! �õ����Ż�ˢ��ɫ
	UGColor  GetBrushColor() const;
	//! �õ������ı���ɫ
	UGColor  GetTextColor() const;
	//! �õ����Ż��ʷ��
	PenStyle GetPenStyle() const;	
	//! �õ����Ż�ˢ���
	BrushStyle GetBrushStyle() const;
	//! �õ�������������
	const UGString& GetFontName() const;
	//! �õ�������������
	const UGString& GetTxtNotes() const;

	UGBitmapStroke* GetBitmapStroke() const;
	UGIconStroke*   GetIconStroke() const;

	void SetPenWidth(UGuchar nPenWidth);
	void SetPenColor(UGColor color);
	void SetBrushColor(UGColor color);
	void SetTextColor(UGColor color);
	void SetPenStyle(PenStyle nStyle);
	void SetBrushStyle(BrushStyle nStyle);	
	void SetFontName(const UGString& strFontName);
	void SetTxtNotes(const UGString& strTxtNotes);
	
	void MakeDefault();
	
	UGint GetCountOfPoints() const;		
	void  Add(const UGSymPoint& symPoint);
	void  InsertAt(UGint nIndex, const UGSymPoint& symPoint);
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	void  RemoveAll();
	
	void SetAt(UGint nIndex, UGSymPoint symPoint);	
	UGSymPoint GetAt(UGint nIndex);

	//! �ñʻ����ֽ���(���ڸ�������Ϊ5.0��ʽ)
	UGint GetStrokeBytesNum() const;
	
	
	//! \brief ����ʻ���bounds dongfei 2007-03-28
	/**
	\return ���رʻ��ķ�Χ���Է��ŵ�����ϵ��0-255��Ϊ�ο� 
	*/
	void GetStrokeRect(UGRect  * pRect);

	//! \brief ����͸����
	void SetTransPercent(UGint nTransPercent);
	UGint GetTransPercent();

	//! \brief ���ý������
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
	void  ClearUp();

protected:
	//------�ļ���ȡ��غ���-------------------
	//! \brief ��ȡ�õ��ʻ��е����ݡ���Ϣ��
	/**
	\param stream  ���ſ��ļ��ʻ�����������Ϣ[in]
	\return ��ȡ�Ƿ�ɹ���
	\remarks UGC�ڶ��汾��ͬ��һ�汾��Ȼ�����ͬ��ֻ�Ƕ���һ���Ƿ�̶��ʻ���ȵ�������Ϣm_bPenFixedWidth�Ķ�ȡ��
	*/
	UGbool Load_Version2007(UGStream& stream);
	//! \brief ����ʻ���Ϣ���浽���ļ��С�
	/**
	\param stream  ���ſ��ļ��ʻ�����������Ϣ[out]
	\return �����Ƿ�ɹ���
	\remarks UGC�ڶ��汾��ͬ��һ�汾��Ȼ�����ͬ��ֻ�Ƕ���һ���Ƿ�̶��ʻ���ȵ�������Ϣm_bPenFixedWidth�ı��档
	*/
	UGbool Save_Version2007(UGStream& stream) const;

	//! UGC��һ�汾
	UGbool Load_Version2005(UGStream& stream);
	UGbool Save_Version2005(UGStream& stream) const;

	UGbool Load_Version2003(UGStream& stream);
	UGbool Save_Version2003(UGStream& stream) const;

	UGbool LoadDetails(UGStream& stream, UGuint nVersion = 0);
	UGbool LoadDetails2007(UGStream& stream, UGuint nVersion = 0);
	UGbool LoadDetails2005(UGStream& stream, UGuint nVersion = 0);
	UGbool SaveDetails(UGStream& stream, UGuint nVersion = 0) const;
	UGbool SaveDetails2007(UGStream& stream, UGuint nVersion = 0) const;
	UGbool SaveDetails2005(UGStream& stream, UGuint nVersion = 0) const;


protected:
	//! ���Ƶ㡢�ߡ������(�����ֱʻ��Ļ��Ʒ�ʽ����)
	void DrawPoints(UGGraphics& graphics, UGMarkerSymParam& symParam) const;

	//! ����Arc��Pie��Chord��Ellipse
	void DrawEllipseArcWithRotation(UGGraphics& graphics, UGMarkerSymParam& symParam) const;
	void DrawEllipseArcWithoutRotation(UGGraphics& graphics, UGMarkerSymParam& symParam) const;

	void      DrawRect(UGGraphics& graphics, UGMarkerSymParam& symParam) const;
	void DrawRoundRect(UGGraphics& graphics, UGMarkerSymParam& symParam) const;

	void      DrawText(UGGraphics& graphics, UGMarkerSymParam& symParam) const;
	void     DrawImage(UGGraphics& graphics, UGMarkerSymParam& symParam) const;

protected:
	//! ����Բ�Ǿ���
	void BuildRoundRect(UGSymPoint*& pPoints, UGint& nPntCount, 
		                  const UGSymPoint& ptUpLeft, const UGSymPoint& ptLowRight,
						  UGint nWidth, UGint nHeight ) const;

	//! ����Arc��Pie��Chord��Ellipse�Ļ���
	void BuildArc(UGPoint*& pPoints, UGint& nPntCount) const;

	void BuildArc2(UGSymPoint*& pPoints, UGint& nPntCount) const;

	//! \brief ����һ�����Σ����ǡ�point1��point2��Χ���Ρ���4����ͬʱ��ѭһ���ķ�����
	//! \remarks ����ST_Arc����ʾʱ��Ҫ��2�����Ƶ�������������
	UGRect ConvertEllipseRect(const UGPoint& point1, const UGPoint & point2, UGbool bGraphicsYAxisUp ) const;

	//! �����ʻ�����ʱ�İ뾶(���ڵ�ʻ��Ļ��ƺ͵�ʻ���HitTest)
	UGint CalcPointRadius() const;

protected:

	//! ���ݲ���param�Լ��ʻ����ڲ�����������Graphics����GDI����(���ʡ���ˢ������)
	void PrepareGraphics(UGGraphics& graphics, UGMarkerSymParam& param) const;
	//! �ָ�Graphics
	void RestoreGraphics(UGGraphics& graphics, UGMarkerSymParam& param) const;
	
	//! ����stroke��param�еĲ�����������Ӧ�Ļ��ʡ���ˢ(����PrepareGraphics�б�����)
	void PrepareNewPen(UGGraphics& graphics, UGMarkerSymParam& param) const;
	void PrepareNewBrush(UGGraphics& graphics, UGMarkerSymParam& param) const;
	//! \brief �ж��Ƿ���ƽ���Ч��
	/**
	\param symParam        ���Ʋ���[in]
	\param EndColor        ����ɫ[in\out]
	\param dRadian         �Ƕ� [in\out]
	\param nHOffsetCenter  ˮƽƫ�� [in\out]
	\param nVOffsetCenter  ��ֱƫ�� [in\out]
	\param nType           �������� [in\out]
	\return �Ƿ���ƽ���
	*/
	UGbool IsDrawGradient(UGMarkerSymParam& symParam,UGColor& EndColor,UGdouble& dRadian,UGint& nHOffsetCenter,UGint& nVOffsetCenter,UGint& nType,UGColor& PenColor)const;

	//! ��stroke�����Brush���ת��ΪUGBrush�ķ��
	UGBrush::BrushStyle StrokeBs2UGBs(UGMarkerSymStroke::BrushStyle StrokeBs) const;

	//! �����ַ���strSrc��ͳ�����е��������Լ���Щ�е��ַ����������ֵ
	void ParseTextNotes(const UGString& strSrc, UGArray<UGString>& Lines, UGint& nMaxCharCount)const;

	//! ���㡺��pnt�͵�pntOrgin�����ߡ���ˮƽ��֮��ĽǶ�ֵ(-pi��pi����λΪ����)����x��������Ϊ��ʼ�Ƕȣ���ʱ�뷽��
	UGdouble CalculateAngle(UGdouble pntOrgX, UGdouble pntOrgY, UGdouble pntX, UGdouble pntY) const
	{
		UGdouble dAngle = atan2( pntY - pntOrgY, pntX - pntOrgX  );
		if ( dAngle < 0 )
		{
			dAngle += 2 * PI;
		}

		return dAngle;
	}

	//! ������Բ���ϵĵ�
	void CalculateEllipsePoint(UGdouble a, UGdouble b, UGdouble x0, UGdouble y0, UGdouble dParamRadian, UGSymPoint& ptResult ) const
	{
		// ��Բ���ض� ������(���ȵ�λ) �ĵ������
		// ��Բ����: [(x-x0)^2 / a^2] + [(y-y0)^2 / b^2] = 1
		// ��Ϊ: x = x0 + a*cos(alpha)
		//		 y = y0 + b*sin(alpha)

		ptResult.x = UGROUND ( x0 + a * cos(dParamRadian) );

		//ע������Y���������µ�����ϵ�������ü�
		ptResult.y = UGROUND ( y0 - b * sin(dParamRadian) );
	}

	//! �õ��ɵ�pt1��pt2ȷ���ľ���(ע:����ϵy���ᳯ��)�����Ͻǵĵ�(������DrawText��)
	void GetRectTopLeftPnt(const UGSymPoint& pt1, const UGSymPoint& pt2, UGSymPoint& ptTopLeft) const;

protected:
	/*   8 7 6 5 4 3 2 1---------- 1 ������ɫ�Ƿ�̶�--(��1λ�����λ)
		 | | | | | | +------------ 2 ��ˢ��ɫ�Ƿ�̶�--(��2λ)
		 | | | | | +-------------- 3 ���ʷ��(4��)--(3��4����λ����ʾ4��״̬)
		 | | | | +---------------- 4 
		 | | | +------------------ 5 BrushStyle(8��)--(5��6��7����λ����ʾ8��״̬)
		 | | +-------------------- 6 
		 | +---------------------- 7 
		 +------------------------ 8 IsFixedTextColor--(��8λ�����λ) */
	//! ���Ժ�����
	UGuchar               m_nProperties;   //�ʻ�������ѡ��(����ͼ)
	//! \brief �����Ƿ�̶����ſ�ȡ�
	/**
	\remarks Ĭ��Ϊfalse�����̶���
	*/

	/*   8 7 6 5 4 3 2 1---------- 1 ���ʿ���Ƿ�̶�-------(��1λ�����λ)
		 | | | | | | +------------ 2 �ʻ���͸��Ч���Ƿ�̶�-(��2λ)
		 | | | | | +-------------- 3 �ʻ�����Ч���Ƿ�̶�����(����λ)
		 | | | | +---------------- 4 
		 | | | +------------------ 5 
		 | | +-------------------- 6 
		 | +---------------------- 7 
		 +------------------------ 8 */
	//! ���Ժ�����
	UGuchar               m_nProperties2;
	StorkeType            m_emType;        //�ʻ�������

	//! ���ʺͻ�ˢ
	UGuchar              m_PenWidth;       //���ʵĿ��(��λ��0.01mm)
	UGColor              m_PenColor;       //������ɫ
	UGColor              m_BrushColor;     //��ˢ��ɫ

	//! \brief ���潥�����ز���
	UGColor              m_EndColor;       //����ı���ɫ
	UGdouble             m_dRadian;        //����ĽǶ�
	UGint                m_nHOffsetCenter; //�����ˮƽƫ����
	UGint                m_nVOffsetCenter; //�������ֱƫ����
	UGint				 m_nGradientType;  //���������
	
	//! �ı�
	UGColor              m_TextColor;
	UGString             m_strFontName;
	UGString             m_strNotes;

	//! ��չ�ʻ�
	UGBitmapStroke*      m_pBitmapStroke;  //դ��ʻ���ָ�룺ֻ��դ����ŵ�����
	UGIconStroke*        m_pIconStroke;    //Icon�ʻ���ָ�룺ֻ��Icon��������

	//! ���Ƶ�����
	UGArray<UGSymPoint>  m_SymPoints;      //һ���ʻ��Ŀ��Ƶ������
	UGint m_nTransPercent;                 //�ʻ���͸���� 
	
};


}

#endif


