// UGLineSymbolBaseDrawer.h: 

#ifndef UG_LINESYMBOLBASE_DRAWER_H
#define UG_LINESYMBOLBASE_DRAWER_H

#include "Algorithm/UGPoint2D.h"
#include "UGPolylineParam.h"
#include "Base/UGThread.h"
#include "Symbol/UGMarkerSymbol.h"
namespace UGC
{
	class UGGraphics;
	class UGLineSymParam; 
	class UGLineSymbolBase;

/** ���ͻ��ߵĻ���������װ���Ƶ�ʵ��ϸ�ڣ��ṩ����BaseLien���ƵĽӿ�
	@remarks
	   ϵͳ�л���(BaseLine)��49�ַ�����ͣ���ͬ���Ļ��Ʒ�������ܴ�
	���ݻ��Ʒ��������Դ��°���Щ���߷ֳ�3������:		   
	
	1������ʵģʽ��
	   ���ڵ����ߺͽ�����, ��Ҫ��������, ��Ϊ���ǲ�������ʵģʽ����ѭ��
	   DSV_ELECTRIC            -->�����߶� 
	   DSV_ELECTRICEX          -->�����߶�(���м���)
	   DSV_ELECTRIC_SPECIAL    -->�����߶�(����)
	   DSV_ELECTRICEX2         -->�����߶�(Բ��)

	2����ʵģʽ��-->������ʵģʽ����ѭ������
	   ��ʵģʽ�ͻ��Ƶķ������������ߣ�����ʼ�㵽�����㣬���ճ��ȣ�����ѭ�������ɸû��߶����
	��ʵģʽ��ע����ǣ�һ�����߶�(һ�������ж������߶�)�����û�а�ĳ��ģʽ���ֻ��꣬
	��ô����һ�����߶���Ҫ���Ż��ơ�
	�൱�ڰ�����������ֱ��һ��ֱ�߶Σ�Ȼ���ͷ��βѭ���ذ�����ʵģʽָ���ĳ�����������
	��������

	3��ƽ������
		DSV_DOUBLEPARELLEL     -->ƽ��˫��(���Ķ���)
		DSV_LEFTPARELLEL       -->ƽ��˫��(�ϱ߶���)
		DSV_RIGHTPARELLEL      -->ƽ��˫��(�±߶���)
	����ƽ�����ͷ��Ļ���, ���뵥������(�ȹ����ƽ����, Ȼ���ٰ�����ʵģʽ����ѭ������)	
*/
	

class UGLineSymbolBaseDrawer
{
public:
    UGLineSymbolBaseDrawer();
	~UGLineSymbolBaseDrawer();

public:
	//! ���ò���ʼ�����������ڲ�����(ע������ToDraw()����֮ǰһ��Ҫ�ȵ��øú������趨���ڲ�����)
	void InitInternalParam(UGLineSymbolBase* pBaseLine, UGGraphics* pGraphics, UGLineSymParam* pDrawParam);

	//! �����Ψһ���ƽӿڣ�pPoints�д洢�����������������
	void ToDraw(const UGPoint* pPoints, UGint nCount);

protected:
	enum DrawingType
	{
		DT_Modely,       //��ʵģʽѭ������
		DT_NonModely,    //����ʵģʽ����
		DT_Parellelly    //ƽ���߻���
	};
	
	struct ModeLenPair
	{
		UGdouble m_SolidPartLen;  //ʵ���ֵĳ���
		UGdouble m_EmptyPartLen;  //�鲿�ֵĳ���
	};
	
	/*{--------------------------������Ƶĺ���-------------------------------*/
	//! ���������ƺ���(�������͵Ļ��Ʒ�����ƽ���߻���+��ʵģʽѭ������+����ʵģʽ����)
	void DrawNonModely(const UGPoint* pPoints, UGint nCount);
	void DrawModely(const UGPoint* pPoints, UGint nCount);
	void DrawParellelly(const UGPoint* pPoints, UGint nCount);

	//! ����ģʽ��һ�����֡��鲿�ֻ�ʵ���֡�(����DrawModely()�б�����)
	UGbool DrawOneModePart(const UGPoint* pPoints, UGint nPntCount, 
		                   UGbool bSolidPartOrEmptyPart, UGdouble dModePartLen, 
						   UGint& curSegIndex, UGdouble& curSegRemainLen, UGPoint2D& pntFrom);

	enum ModePartState
	{  //�ڻ���һ��ģʽ�߶�ʱ��ģʽ�߶ε����ֻ���״̬
	   //����DrawOneModePart()�к�DrawLine()��
		MPS_WholePart,  //���β���
		MPS_FrontPart,  //ǰ�β���
        MPS_MiddlePart, //�м䲿��
		MPS_RearPart    //��β���
	};
	//! ����һ�����ߡ������л���ݻ��ߵķ�����ͣ����Ʋ�ͬ���͵�����(����DrawOneModePart()�б�����)
	void DrawLine( const UGPoint2D& pntFrom, const UGPoint2D& pntTo , 
		           UGdouble PartLen, ModePartState ePartState, UGbool bSolidPart );

	//! Ϊģʽ��ʼѭ��������׼������(����DrawModely()����)
	void DoPrepareForModelyDraw(const UGPoint* pPoints, UGint nCount);

	/*}--------------------------������Ƶĺ���-------------------------------*/

	
protected:
	/*{----------------------����ƫ�Ƶĺ���-------------------------------*/
	
	//! ����ƫ��
	void ProcessOffSet(const UGPoint* pOriginalPoints, UGint nOriginalCount, UGPoints& offsetPointArry);

	//! �������ƫ�ƣ�����ProcessOffSet()�б�����
	void HoriOffSet(const UGPoint* pOriginalPoints, UGint nOriginalCount, UGPoints& offsetPointArry);

	//! ��������ƫ�ƣ�����ProcessOffSet()�б�����
	void VertOffSet(const UGPoint* pOriginalPoints, UGint nOriginalCount, UGPoints& offsetPointArry);

	//! ����ƽ����(����VertOffSet��DrawParellelly()�б�����)
	UGbool CalcParallel(const UGPoint *lpPoints, UGint nPntCount, UGdouble dWidth, UGPoints& pntParallels);

	//! ������ȥ��(����CalcParallel�б�����)
	UGbool LampHouseSmooth(const UGPoint* lpPoints, UGint nCount, UGdouble dTolerance, UGPoints &arrPoints);

	/*}----------------------����ƫ�Ƶĺ���-------------------------------*/


protected:
	//! ���ݻ��Ʋ���DrawingParam�Լ����߱���Ĳ�����������Graphics��GDI����ͬʱ��ԭ����GDI����ָ���¼����
	void PrepareGraphics();
	//! �ָ�Graphics
	void RestoreGraphics();

	//! ����3��������PrepareGraphics()�б����ã�׼���µ�GDI����
	void PrepareNewPen();
	void PrepareNewBrush();
	void PrepareNewFont();

	//! \brief ������ʵ���ĳ��ȣ�ʵ�������Ļ���
	/**
	\param dtotalModeLens  ����һ�����ڵĳ���[in]
	\param dScale  ������ʵ����������[out]
	\return �Ƿ�����ɹ�
	*/
	UGbool AdjustModeLenPair(UGdouble& dtotalModeLens,UGdouble& dScale);

protected:
	//// 3������ƫ���Լ�ģʽ����ʱ�ĸ�������
	//! ��һ���߶εĳ���
	UGdouble SegmentLength(UGdouble xPntStart, UGdouble yPntStart, 
								  UGdouble xPntEnd, UGdouble yPntEnd);
	//! ���߶��ϵ�ĳ���㣬�õ�ƫ���߶����(PntStart)�ľ���ΪoffsetLen(�������Ϊ�������Ƿ������ӳ����ϵĵ�)
	UGPoint2D CalcOffsetPntOnSegment(UGdouble xPntStart, UGdouble yPntStart, 
											UGdouble xPntEnd,   UGdouble yPntEnd, UGdouble offsetLen);
	//! ��ֱ���߶�, ���ΪpntAnchor, �߶�Ϊ dHeight �ĵ������
	UGPoint2D CalcVerticalPntOfSegment( UGdouble xPntStart,  UGdouble yPntStart, 
											   UGdouble xPntEnd,    UGdouble yPntEnd, 
											   UGdouble xPntAnchor, UGdouble yPntAnchor, 
											   UGdouble dHeight );

	//! ���� ���������� ������(����DrawGradient()�б�ʹ��)
	void CalculateGradient( const UGPoint* lpPoints, UGint nCount,
							UGdouble dStartWidth, UGdouble dEndWidth, 
							UGPoints &arrLeftPoints, UGPoints &arrRightPoints);

protected:
	//! ��ʲô��������(�ɻ��ߵķ��������ȷ����)
    DrawingType IsWhatDrawingType();

	//! ���ȵ��߼�ת������(0.1mm�ĵ�λ���߼���λ��ͬʱ��������)
	UGdouble LOMETRIC2LPWithScaling(UGint nLOMETRICLen);

	//! �����Ƿ���Ҫ����ƫ�ƴ���(�ڲ���������)
	UGbool IsBaseLineNeedHoriOffset();
	UGbool IsBaseLineNeedVertOffset();


protected:  //�����Ǹ��־��������͵Ļ��ƺ���
	
	//���ƽ�����
	void DrawGradient(const UGPoint* pPoints, UGint nCount);
	
	//! ���Ƶ����߼�ͷ
	void DrawElectricArrow(const UGPoint2D& pntFrom, const UGPoint2D& pntTo );
	
	//! ���Ƶ�����
	void DrawElectric(const UGPoint* pPoints, UGint nCount);
	
	//! ���Ƶ�����(����)
	void DrawElectricSpecial(const UGPoint* pPoints, UGint nCount);
	
	//! ���Ƶ�����(Բ��)
	void DrawElectricWithCircle(const UGPoint* pPoints, UGint nCount);

	//! ���ƶ�����
	void DrawShortVert(const UGPoint2D& pntAnchor);

	//! �������½�����
	void DrawUpDownCross(const UGPoint2D& pntAnchor, UGbool bSolidPart);

	//! ������б��
	void DrawBevel(const UGPoint2D& pntStart, const UGPoint2D& pntEnd,
		           ModePartState ePartState, UGdouble PartLen );
	//! ������б���½�����
	void DrawBevelUpDownCross(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, UGbool bSolidPart, 
		                      ModePartState ePartState, UGdouble PartLen);

	//! ���Ƽ�ͷ
	void DrawArrow(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
		           ModePartState ePartState, UGdouble PartLen);

	//! ���Ʋ�����(�鲿����Ҫ����)
	void DrawWaveLine(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
		              UGbool bSolidPart, ModePartState ePartState);

	//! ���Ƴ��Ƿ���(�鲿����Ҫ����)
	void DrawGreatWall(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, UGbool bSolidPart);

	//! ���Ƴ�����(�鲿�ֲ��û�)
	void DrawBox(const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! ���ƽ������(�鲿�ֲ��û�)
	void DrawCrossSymbol(const UGPoint2D& pntStart, const UGPoint2D& pntEnd);
	//! ���ƽ������(�鲿����Ҫ���ģ�ֻ���DSV_VCROSSUPDOWN)
	void DrawCrossSymbolUpDown(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, UGbool bSolidPart);

	//! ���ư�Բ��
	void DrawArc(const UGPoint2D& pntStart, const UGPoint2D& pntEnd);
	//! ���ư�Բ��(ֻ���DSV_VBIARCUPDOWN)
	void DrawArcUpDown(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, UGbool bSolidPart = TRUE);

	//! �������Բ
	void DrawCircle(const UGPoint2D& pntStart, const UGPoint2D& pntEnd);
	//! �������Բ(ֻ���DSV_VCIRCLEUPDOWN)
	void DrawCircleUpDown(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, UGbool bSolidPart = TRUE);

	//! ���ƴ���ͷ�Ķ̺���
	void DrawDashWithArrow(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, ModePartState ePartState);
	
	//! �����ַ�
	void DrawCharacter(const UGPoint2D& pntFrom, const UGPoint2D& pntTo);

	//! �����Զ������
	void DrawSymbol(const UGPoint2D& pntFrom, const UGPoint2D& pntTo);

private:
	//! ����
	UGGraphics* m_pGraphics;

	//! ���Ʋ���
	UGLineSymParam* m_pDrawingParam;

	//! ���͵Ļ��ߣ��û������Դ˻��ߵĲ���ȥ����
	UGLineSymbolBase* m_pBaseLine;

	//! ���ź�Ļ��ߵĴ�ֱ�����ϵ��߼��߶�(ֻ����һ�α�����������ѭ��������ʹ�ã����Ч��)
	UGdouble m_nLogicalVertLenWithScaling;

	//modified by xielin 2007-12-27 ����Ҫ֧�ֶ��̣߳�ȫ�־Ͳ����ˣ��ĵ�
	//! ���ź�Ļ���ģʽ���߼�����(ֻ����һ�α�����������ѭ��������ʹ�ã����Ч��)
	UGArray<ModeLenPair> m_LogModeLens;

	//modified by xielin 2007-12-27 ����Ҫ֧�ֶ��̣߳�ȫ�־Ͳ����ˣ��ĵ�
	//! ���ߵĲ�������������ѭ������ģʽ����ʱ������Ƶ�
	UGPolylineParam  m_PolylineParam;
	
	//! ���ƹ����еĸ�����������־�Ƿ��Ǹտ�ʼ��������(������DrawWaveLine()��DrawGreatWall()��)
	UGbool m_bPolyLineStart;

	//! ���ƹ����еĸ�����������ǰ�߶��Ѿ������Ƶĳ���(������DrawOneModePart()��)
	UGdouble  m_dLenHaveDrawnOnCurSegment;

	//! 4���ڲ���ʱ���������(�����ڸ����������͵Ļ��ƹ�������ʱ�����м����������)
	UGPoint2D m_BufferPnt1;
	UGPoint2D m_BufferPnt2;
	UGPoint2D m_BufferPnt3;
	UGPoint2D m_BufferPnt4;

	//! �����ַ��ͻ���ʱ�ĸ�������������һ�κ󱣴�������Ա�ѭ�����ƹ����в����ټ��㣬ֱ������ʹ��
	UGint m_nFontHeight;	

	//! �����Զ����ͻ���ʱ�ĸ�������,
	UGMarkerSymbol* m_pSymbol;
	UGMarkerSymParam* m_pSymParamForSymbol;

	//xll test ^_^
	UGMutex m_mutex;
	
private:
	//! ��ֹ�����͸���(not implemented)
	UGLineSymbolBaseDrawer(const UGLineSymbolBaseDrawer& rhs);
	UGLineSymbolBaseDrawer& operator=(const UGLineSymbolBaseDrawer& rhs);
};

	
}

#endif


