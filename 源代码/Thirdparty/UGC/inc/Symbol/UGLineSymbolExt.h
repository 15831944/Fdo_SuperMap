#ifndef UGLINESYMBOLEXT_H
#define UGLINESYMBOLEXT_H

#include "Graphics/UGGraphics.h"
#include "Algorithm/UGPoint2D.h"

// yujiang
#define hypot _hypot

namespace UGC {
	
class UGLineSymParam;
class UGMarkerSymbolLib;

/** ������չ(UGLineSymbolExt)��һ��������չ��1~5��Token���(Ŀǰ���ֻ֧��5��)
	@remarks
	1��ϵͳ�ṩ9���ڲ���������η������£�
		Token_Arrow	      --->������ͷ	  
		Token_ArrowSolid  --->ʵ����ͷ
		Token_Arrow3	  --->40%����ͷ 
		Token_Arrow4	  --->60%����ͷ 
		Token_Rhombic	  --->ʵ�������(��)
		Token_Ellipse	  --->�������Բ(��)
		Token_Rect		  --->��������(��)
		Token_EllipseSolid--->ʵ�����Բ(��)
		Token_RectSolid	  --->ʵ������(��)

     2������ʹ��9���ڲ���������η�;
		Ҳ����ʹ�õ���ſ��еĵ������Ϊ�Զ������չ���η�(CustomizedToken)��
	
	 3��ϵͳ�н�֧����չ���η���5�ֲַ�λ�ã����£�
        Token_Head           --->�ײ� 		    
		Token_Tail           --->β��
		Token_MiddlePoint    --->�м�ڵ�
		Token_LineCenter     --->�߶�����
		Token_PolyLineCenter --->��������

     4��һ��UGLineSymbolExt�����Դ洢5����ͬλ�õ�token������Ϣ(UGExtTokenData)��
		һ��token������Ϣ��¼��token�ģ�
		1.�߶ȣ�2.��ȣ�3.��ת�Ƕȣ�
		4.ͼ�η���ID;

     5��5��λ�õ�Token������Ϣ��m_TokenDatas�а�����˳��洢
		(note:��ĳ��λ����û��Token�Ļ����Ͳ��洢Token������Ϣ)��
		  Token_Head           = 0,  //�ײ�
		  Token_Tail           = 1,  //β��
		  Token_MiddlePoint    = 2,  //�м�ڵ�
		  Token_LineCenter     = 3,  //�߶�����
		  Token_PolyLineCenter = 4   //��������
*/
class SYMBOL_API UGLineSymbolExt  
{
	
public:
    //! �ڲ���������η�������ID
	enum TokenID
	{
		    Token_NULL             = 0,
			Token_Arrow		       = 1,   //��������ͷ
			Token_ArrowSolid        = 2,   //����ͷ
			Token_Arrow3	       = 3,   //40%����ͷ
			Token_Arrow4	       = 4,   //60%����ͷ
			Token_Rhombic	       = 5,   //���������
			Token_Ellipse	       = 6,   //��������Բ
			Token_Rect		       = 7,   //����������
			Token_EllipseSolid     = 8,   //�������Բ
			Token_RectSolid	       = 9,   //��������
			Token_Customized_Start = 10   //���ڵ���Token_Customized_Start��TokenID���Զ�������
	};	
	
    //! ���η����ڵ�λ��
	enum TokenPos
	{
			TPos_Head           = 0,  //�ײ�
			TPos_Tail           = 1,  //β��
			TPos_MiddlePoint    = 2,  //�м�ڵ�
			TPos_SegmentCenter  = 3,  //�߶�����
			TPos_PolyLineCenter = 4,  //��������
			Token_Supported_Max  = 5   //ϵͳ֧�ֵ��������ı�־ 
	};
	
public:
	//! ������չ���η���������Ϣ
	struct UGExtTokenData
	{
		UGuchar  m_nWidth;     /// ���(��λ:0.1mm)
		UGuchar  m_nHeight;    /// �߶�(��λ:0.1mm)
		UGshort  m_nRotation;  /// ��ת�Ƕ�(��λ:0.1��)
		UGint    m_nTokenID;   /// m_nTokenID>=Token_ID_End(10) ��ʾʹ���Զ���ĵ����
		
		UGExtTokenData()
		{
			memset( this, 0, sizeof(UGExtTokenData) );
		}
	};
	
	public:
		UGLineSymbolExt();
		~UGLineSymbolExt();
		
	public:
		UGbool Load(UGStream& stream, UGuint nVersion = 0);
		UGbool Save(UGStream& stream, UGuint nVersion = 0) const;
		void Draw(UGGraphics& graphics, const UGPoint* pPoints, UGint nCount, const UGLineSymParam& params);
		
		//! �Ƿ������Token���Ŵ���
		UGbool IsContainingTokens();
		
		//! ���m_nTokenPosInfo�ϵĶ�Ӧ��pos�����ı�־λ���ж��ڸ�λ�����Ƿ���Token����
		UGbool IsHavingTokenAt(TokenPos pos) const;
		
		//! �õ�posλ�ö�Ӧ��Token������Ϣ��m_TokenDatas�е���������û�з���-1
		UGint TokenPos2DataIndex(TokenPos pos) const;
		
		//! ���ظ�������չ�е�Token�ĸ���
		UGint GetTokenCount() const;
		
		UGbool GetExtTokenData(TokenPos pos, UGExtTokenData& Data) const;
		void SetExtTokenData(TokenPos pos, const UGExtTokenData& Data);
		
		UGbool RemoveExtTokenData(TokenPos pos);
		UGuchar GetExtTokenPosInfo() const;
		
		UGbool MovePointSymID(UGint nAddNum);
		UGbool IsUsedPointSym(UGint nSymID) const;
		//! �Ƿ�������Զ����Token(�Զ����TokenҲ��ʹ���˵���ŵ�Token)
		UGbool IsContainCustomizedToken() const;  
		void Clear();
		
	protected:
		//! ����Tokenλ����Ϣ�ı�־λ
		void SetPosInfoFlag(TokenPos pos, UGbool bSetting = TRUE);
		void AddTokenData(TokenPos pos, const UGExtTokenData& Data);
		
	protected:
	    //! ��һ���߶εĳ���
	    inline UGdouble SegmentLength(UGdouble xPntStart, UGdouble yPntStart, 
								      UGdouble xPntEnd, UGdouble yPntEnd);
		//! ���߶��ϵ�ĳ���㣬�õ�ƫ���߶����(PntStart)�ľ���ΪoffsetLen(�������Ϊ�������Ƿ������ӳ����ϵĵ�)
		inline UGPoint2D CalcOffsetPntOnSegment(UGdouble xPntStart, UGdouble yPntStart, 
			                                    UGdouble xPntEnd,   UGdouble yPntEnd, UGdouble offsetLen);
		//! ��ֱ���߶�, ���ΪpntAnchor, �߶�Ϊ dHeight �ĵ������
		inline UGPoint2D CalcVerticalPntOfSegment( UGdouble xPntStart,  UGdouble yPntStart, 
			                                       UGdouble xPntEnd,    UGdouble yPntEnd, 
			                                       UGdouble xPntAnchor, UGdouble yPntAnchor, 
			                                       UGdouble dHeight );

		// ����һ�����ߵ����ĵ��λ�ã����������ĵ����ڵ��߶ε�������
		UGint CalcPolyLineCenter(const UGPoint* pPoints, UGint nCount, UGPoint2D& ptCenter );
		
		//! ������ͷ�����ݲ�����������Ƽ�ͷ�����3����4�����Ƶ㣬�洢��pntsBuf��
		void CreateArrow(  UGGraphics& graphics, UGPoints& pntsBuf, const UGExtTokenData& TokenData, UGdouble dIndentRatio/*��ͷβ�˵���������ϵ��*/,
			               UGdouble dScaleRatio/*��С�����ű���*/, const UGPoint2D& ptAnchor, const UGPoint2D& ptStart, const UGPoint2D& ptEnd );

		//! �������Σ�
		void CreateRhombic( UGGraphics& graphics, UGPoints& pntsBuf, const UGExtTokenData& TokenData,UGdouble dScaleRatio/*��С�����ű���*/,
			               const UGPoint2D& ptAnchor, const UGPoint2D& ptStart, const UGPoint2D& ptEnd );

		//! ��������
		void CreateRect( UGGraphics& graphics, UGPoints& pntsBuf, const UGExtTokenData& TokenData,UGdouble dScaleRatio/*��С�����ű���*/,
			               const UGPoint2D& ptAnchor, const UGPoint2D& ptStart, const UGPoint2D& ptEnd );

		
		
	protected:
		UGPen* CreateNewPen( UGGraphics& graphics, UGuint width, UGColor color );
		UGBrush* CreateNewBrush( UGGraphics& graphics, UGColor color ); 
		
		
		void DrawTokens(UGGraphics& graphics, const UGPoint* pPoints, UGint nCount, 
			const UGLineSymParam& DrawingParam, TokenPos pos, const UGExtTokenData& TokenData);
		
		//����װ��
		//! graphics-��ͼ����
		//! TokenData-װ��
		//! DrawingParam-���Ʋ���
		//! ptAnchor-װ�λ���λ��
		//! ptStart-װ�������߶ε����
		//! ptEnd-װ�������߶ε��յ�
		void DrawOneToken(UGGraphics& graphics,
			const UGExtTokenData& TokenData,
			const UGLineSymParam& DrawingParam,
			const UGPoint2D& ptAnchor,
			const UGPoint2D& ptStart,
			const UGPoint2D& ptEnd );

		//! �����Զ������(���������DrawOneToken�Ĳ�������һ��)
		void DrawCustomizedToken(UGGraphics& graphics,
			const UGExtTokenData& TokenData,
			const UGLineSymParam& DrawingParam,
			const UGPoint2D& ptAnchor,
			const UGPoint2D& ptStart,
			const UGPoint2D& ptEnd);
		
	protected:
		/** Tokenλ����Ϣ��������5������λ��¼��5��λ�����Ƿ���Token
	     7 6 5 4 3 2 1 0---------- 0 �ײ�(Token_Head) 	
		       | | | +------------ 1 β��(Token_Tail)
		       | | +-------------- 2 �м�ڵ�(Token_MiddlePoint)
		       | +---------------- 3 �߶�����(Token_LineCenter)
		       +------------------ 4 ��������(Token_PolyLineCenter)
		*/
		UGuchar m_nTokenPosInfo;

		//! �����5��Token��Ϣ������m_nTokenPos�ı�־λ����ȡ��Ӧ��
		UGArray<UGExtTokenData> m_TokenDatas;
};
	
inline UGdouble UGLineSymbolExt::SegmentLength(UGdouble xPntStart, UGdouble yPntStart, 
													  UGdouble xPntEnd,   UGdouble yPntEnd )
{
	UGdouble dLen = hypot( xPntEnd - xPntStart, yPntEnd - yPntStart );
	if ( UGIS0(dLen) ) 
	{
		return 0;
	}
	
	return dLen;
}
	
inline UGPoint2D UGLineSymbolExt::CalcOffsetPntOnSegment(UGdouble xPntStart, UGdouble yPntStart, 
														UGdouble xPntEnd, UGdouble yPntEnd, UGdouble offsetLen)
{// ���߶��ϵ�ĳ���㣬�õ�ƫ���߶����һ������
	// offsetLen�п����Ǹ�ֵ��Ϊ��ֵ�������߶��Ϸ������ӳ����ϵĵ�

	UGdouble deltX = xPntEnd - xPntStart;
	UGdouble deltY = yPntEnd - yPntStart;

	//��һ���жϣ�add by xll
	if(UGIS0(deltX) && UGIS0(deltY))
	{
		return UGPoint2D( xPntEnd,yPntEnd); 
	}
	//UGASSERT( !( UGIS0(deltX) && UGIS0(deltY) ) ); // ���ܶ�Ϊ0��

	UGdouble ratio = offsetLen / hypot(deltX, deltY);
	
	return UGPoint2D( xPntStart + ratio * deltX , 
			          yPntStart + ratio * deltY ); 
}

inline UGPoint2D UGLineSymbolExt::CalcVerticalPntOfSegment( UGdouble xPntStart,  UGdouble yPntStart, 
										   UGdouble xPntEnd,    UGdouble yPntEnd, 
										   UGdouble xPntAnchor, UGdouble yPntAnchor, 
										   UGdouble dHeight )
{
	//�����(xPntAnchor,yPntAnchor)���߶��ϵ�

	UGdouble deltX = xPntEnd - xPntStart;
	UGdouble deltY = yPntEnd - yPntStart;

	UGdouble ratio = dHeight / hypot(deltX, deltY);

	return UGPoint2D( xPntAnchor - ratio * deltY , 
					  yPntAnchor + ratio * deltX );
}

}

#endif

