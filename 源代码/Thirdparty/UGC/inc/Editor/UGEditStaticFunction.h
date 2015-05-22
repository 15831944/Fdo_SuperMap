// UGEditStaticFunction.h: interface for the UGEditStaticFunction class.
//
//=====================================================================================
// ��Ŀ����			SuperMap Universal GIS class (UGC) Library 2.0
// ��  �ߣ�			�ιظ�
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSupermap GIS����������Ա��δ����ɲ������Դ�����
//					2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����			UGEditStaticFunction.h
// ��  ����			UGEditStaticFunction
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		�ṩһ��༭���õľ�̬����
// ����˵����		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITSTATICFUNCTION_H__0A92950C_5E53_423E_81D5_D4D500A9CAB0__INCLUDED_)
#define AFX_UGEDITSTATICFUNCTION_H__0A92950C_5E53_423E_81D5_D4D500A9CAB0__INCLUDED_

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRect2D.h"
#include "Graphics/UGGraphics.h"
#include "Geometry/UGGeoRegion.h"
#include "Symbol/UGMarkerSymParam.h"


namespace UGC {

class EDITOR_API UGEditStaticFunction  
{
public:
	UGEditStaticFunction();
	virtual ~UGEditStaticFunction();
	
	static UGuint GetWinTextAlign( UGuint align );
    static UGuint GetMyTexyAlign( UGuint align );
    static UGbool DrawText(UGGraphics * pGraphics, UGString & strText, UGPoint &pntOriginal, UGlong lTextWidth, UGlong lTextHeight,
		UGString strFontName, UGColor colorText, UGuint nAlign, UGlong nAngle, UGlong nStyle,UGlong nWeight, UGbyte btCharset = UGTextCodec::GB18030 );
    //modified by xielin test
	static void GetSymParamFromGeoStyle( UGMarkerSymParam& symParam, const UGStyle& geoStyle, const UGString& string );
    static void GetGeoStyleFromSymParam( const UGMarkerSymParam& symParam, UGStyle& geoStyle, UGString& string );
    static void CreateRedundanceRegion( UGGeoRegion* pRgn, const UGPoint2D *pPoints, const UGint* subCountArray, UGlong lSubCount );
    static void CreateRedundanceRegion( UGGeoRegion* pRgn, const UGPoint2D *pPoints, UGlong lPointCount );
	//modified by xielin test end

	//��������
	//pPointString:���ߵĽڵ�����
	//lTotalPoints:�ܵ���
	//PointsCountPerSection:��ÿ�ϲ������
	//modified by xielin test
     static UGbool Spline( UGPoint2Ds &pPointString, UGlong &lTotalPoints , UGuint PointsCountPerSection = 10 );
	//modified by xielin test end

	 //add by xielin ������ŵ�bounds
	 static UGRect CalculateMarkerSymbolBounds(UGPoint markerSymbolAnchor,const UGPoint &pntAnchor, UGuint dwSize);

};

}

#endif // !defined(AFX_UGEDITSTATICFUNCTION_H__0A92950C_5E53_423E_81D5_D4D500A9CAB0__INCLUDED_)
