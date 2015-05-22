// UGMarkerSymbol.h

#ifndef UGMARKERSYMBOL_H
#define UGMARKERSYMBOL_H

#include "Base/UGArray.h"

#include "UGSymbol.h"
#include "UGSymPoint.h"
#include "UGMarkerSymParam.h"	//�ڸ�ͷ�ļ��а���������Ϊ����������ʹ��ʱ�ķ���
								//��Ϊʹ��UGMarkerSymbolʱͨ������ʹ��UGMarkerSymParam
#include "UGMarkerSymStroke.h"     // ��ɵ���ŵıʻ�Stroke

namespace UGC {


class UGGraphics;
//class UGMarkerSymStroke;

/** UGMarkerSymbol �����
	@remarks
		1��һ����������ɶ���ʻ�(Stroke)��ɵģ�
		2����������Լ��ľֲ�����ϵ(��������)���μ�UGSymPoint�е�˵��;
*/
class SYMBOL_API UGMarkerSymbol : public UGSymbol
{
public:
	UGMarkerSymbol();
	UGMarkerSymbol(UGint id);
	virtual ~UGMarkerSymbol();

	UGMarkerSymbol(const UGMarkerSymbol& rhs);
	virtual UGMarkerSymbol& operator = (const UGMarkerSymbol& rhs);
	
public:
	//! �Ӹ���̳ж����Ķ�д���ܺ���
	virtual UGbool Load(UGStream& stream, UGuint nVersion = 0);
	virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

protected:
	//! UGC��һ�汾
	UGbool Load_Version2005(UGStream& stream);
	UGbool Save_Version2005(UGStream& stream) const;

	//! \brief ��ȡ�õ����ſ��е����ݡ���Ϣ��
	/**
	\param stream  ���ſ��ļ�����������Ϣ[in]
	\return ��ȡ�Ƿ�ɹ���
	\remarks UGC�ڶ��汾��ͬ��һ�汾��Ȼ�����ͬ��ֻ�Ƕ���һ���Ƿ�̶����ſ�ȵ�������Ϣm_bPenFixedWidth�Ķ�ȡ��
	*/
	UGbool Load_Version2007(UGStream& stream);
	//! \brief ���������Ϣ���浽���ļ��С�
	/**
	\param stream  ���ſ��ļ�����������Ϣ[out]
	\return �����Ƿ�ɹ���
	\remarks UGC�ڶ��汾��ͬ��һ�汾��Ȼ�����ͬ��ֻ�Ƕ���һ���Ƿ�̶����ſ�ȵ�������Ϣm_bPenFixedWidth�ı��档
	*/
	UGbool Save_Version2007(UGStream& stream) const;

	//! SFC5.0�汾
	UGbool Load_Version2003(UGStream& stream);
	UGbool Save_Version2003(UGStream& stream) const;

public:
	void Draw(UGGraphics& Graphics, UGMarkerSymParam& SymParam) const;
	UGbool HitTest(const UGPoint& pntHitTest,
			       UGMarkerSymParam& SymParam,
				   UGint nTolerance) const;
	
	/** �жϵ�����Ƿ�Ϊդ�����(��ʻ�����Bitmap��Icon���͵ıʻ�) */
	UGbool IsRaster() const;

	/** ��symSource�ϲ����÷�����
		������symSource�е����еıʻ����Ƶ��÷�����
	*/
	UGbool Merge(const UGMarkerSymbol& symSource);
	
	UGint GetDefaultSize() const;
	void SetDefaultSize(UGint nDefaultSize);
	
	UGSymPoint GetOrgPoint() const;
	void SetOrgPoint(const UGSymPoint& symPoint);

	//! \brief ����Ż���ʱ�õ��Ƿ�̶����ſ����Ϣ��
	/**
	�õ��Ƿ�̶����ʣ�ʵ�ַ��ſ�ȵĹ̶���
	*/
	UGbool IsFixedPenWidth() const;
	//! \brief ����Ż���ʱ�����Ƿ�̶����ſ�ȡ�
	/**
	�趨�Ƿ�̶����ſ�ȣ�ʵ���ڷŴ���Сʱ���ſ�ȹ̶����䡣
	\param bFixed  �Ƿ�̶����ſ��[in]
	*/
	void SetFixedPenWidth(UGbool bFixed);
	
	//----��ʻ�Stroke��صĲ���------
	UGbool IsEmpty() const;
	UGint GetCountOfStrokes() const;
	void  Add(UGMarkerSymStroke* pSymStroke);
	UGMarkerSymStroke* GetAt(UGint nIndex) const;
	void  InsertAt(UGint nIndex, UGMarkerSymStroke* pSymStroke);

	//�ӹ����б��������ͬʱ�����ͷ��ڴ�ռ�
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	void RemoveAll();
	void MakeDefault();
	
	//! \brief ������ŵķ�Χ����0-255������ϵ�ڣ�added by dongfei 2007-03-29
	void CalcSymRect(UGRect* pRect);
	//! \brief ���ݷ��ŵ����ű���ϵ������(255,255)��Χ�����ű���ϵ��
	//added by dongfei 2007-03-29
	void SymBacktoBounds(UGdouble &dScale,UGdouble &dScaleX);
	//! \brief ������ŵķ�Χ���豸���꣩
	//added by xielin 2007-07-20
	UGRect CalBounds(const UGPoint &pntAnchor,UGdouble dSize);

protected:
	// ���߼�����LogPtת��Ϊ����ŵĶ�������ϵ�е�����SymPt( ����HitTest )
	void LogPt2SymPt(const UGPoint& LogPt, UGPoint& SymPt, UGMarkerSymParam& SymParam)const;
	
protected:
	//! ȱʡ�Ĵ�С
	UGint      m_nDefaultSize;
	//! ԭ��
	UGSymPoint m_pntOrg;
	//! \brief �����Ƿ�̶����ſ�ȡ�
	/**
	\remarks Ĭ��Ϊfalse�����̶���
	*/
	UGbool m_bPenFixedWidth;

	//! ��ɵ���ŵıʻ�Stroke
	UGArray<UGMarkerSymStroke*> m_Strokes;
};

}

#endif

