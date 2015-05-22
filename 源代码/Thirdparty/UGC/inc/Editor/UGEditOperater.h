// UGEditOperater.h: interface for the UGEditOperater class.
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
// �ļ�����			UGEditOperater.h	
// ��  ����			UGEditOperater
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		�����������
// ����˵����		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITOPERATER_H__552A08DF_A1F7_4B0A_8EAE_3D35571F3FEE__INCLUDED_)
#define AFX_UGEDITOPERATER_H__552A08DF_A1F7_4B0A_8EAE_3D35571F3FEE__INCLUDED_

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGList.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRect2D.h"
#include "Project/UGPrjCoordSys.h"
#include "Geometry/UGGeoCompound.h"
//#include "Editor/UGEditToolPack.h"

namespace UGC {

class EDITOR_API UGEditOperater
{

public:
	UGEditOperater();
	virtual ~UGEditOperater();
public:
	// �������
	UGdouble CalculateArea(UGPoint2D *pPoints, UGlong nCount);

	// �������
	UGdouble CalculateDistance(UGPoint2D *pPoints, UGlong nCount, UGbool bIsBL = FALSE);

	// ��ָ��϶��� 
	UGbool SplitGeoCompound(UGGeoCompound *pGeoCompound,UGList<UGGeometry*> *pGeoPtrList);
	//���㾭γ�����
	UGdouble CalculateAreaBL(UGPrjCoordSys &PJCoordSys,UGPoint2D *pPoints,UGlong nCount);
    // about the tolerance of IsZero() function used
	//��ò�׽������
    UGdouble GetSnapTolerance();

	//���ò�׽����
    UGdouble SetSnapTolerance( const UGdouble& dTolerance );
    
    // when you want to get 
	//�õ�uType��1�ĸ�������������ֲ�׽��ʽ
	//uType:��׽��ʽ�����־
	//nFlagLength:��׽��ǳ���
    UGint  GetFlagCount( UGuint uType, UGint nFlagLength );
    
    ///////////////////////////////////////////////////////////////////////
    // base useful function
	//�ж�dValue�Ƿ�������֮��
    UGbool IsZero( UGdouble dValue );

	//�ж�dValeu�Ƿ���dZone�޶���������
    UGbool IsInZone( UGdouble dValue, UGdouble dZone );
    
    // useful rotate point, relative to the pnt( 0,0 )
	//�����(x,y),��(0��0)ΪԲ�ģ���תdAngle�������
    void RotatePoint( UGdouble& x, UGdouble& y, const UGdouble& dAngle );
	
	//�����(x,y),��(0��0)ΪԲ�ģ���תdAngle�������
	//dCosAngle:dAngle������ֵ
	//dSinAngle:dAngle������ֵ
    void RotatePoint( UGdouble& x, UGdouble& y, const UGdouble& dCosAngle, const UGdouble& dSinAngle );

	//�����pnt,��(0��0)ΪԲ�ģ���תdAngle�������
    void RotatePoint( UGPoint2D& pnt, const UGdouble& dAngle );

	//�����pnt,��(0��0)ΪԲ�ģ���תdAngle�������
	//dCosAngle:dAngle������ֵ
	//dSinAngle:dAngle������ֵ
    void RotatePoint( UGPoint2D& pnt, const UGdouble& dCosAngle, const UGdouble& dSinAngle );
    // useful rotate point, relative to the pntOrg
	
	//�����(x,y),�Ե�(xOrg��yOrg)ΪԲ�ģ���תdAngle�������
	void RotatePoint( UGdouble& x, UGdouble& y, const UGdouble& xOrg, const UGdouble& yOrg, const UGdouble& dAngle );
	
	//�����(x,y),�Ե�(xOrg��yOrg)ΪԲ�ģ���תdAngle�������
	//dCosAngle:dAngle������ֵ
	//dSinAngle:dAngle������ֵ
    void RotatePoint( UGdouble& x, UGdouble& y, const UGdouble& xOrg, const UGdouble& yOrg, const UGdouble& dCosAngle, const UGdouble& dSinAngle );

	//�����pontNew,�Ե�(xOrg��yOrg)ΪԲ�ģ���תdAngle�������
	void RotatePoint( UGPoint2D& pntNew, const UGPoint2D& pntOrg, const UGdouble& dAngle );
	
	//�����pontNew,�Ե�(xOrg��yOrg)ΪԲ�ģ���תdAngle�������
	//dCosAngle:dAngle������ֵ
	//dSinAngle:dAngle������ֵ
    void RotatePoint( UGPoint2D& pntNew, const UGPoint2D& pntOrg, const UGdouble& dCosAngle, const UGdouble& dSinAngle );

    // get distance from point1 to point2
	//��������
	UGdouble LineSectDistance(const UGPoint2D& pnt1, const UGPoint2D& pnt2 );
    UGdouble LineSectDistance(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2 );

    // get angle from point2 to point1
    UGdouble LineSectAngle(const UGPoint2D& pnt1, const UGPoint2D& pnt2 );
    UGdouble LineSectAngle(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2 );
    
    // judge the point on line
    UGbool IsPntOnLineSect(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2, const UGdouble& x, const UGdouble& y);
    UGbool IsPntOnLine(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2, const UGdouble& x, const UGdouble& y);
    UGbool IsPntNearLineSect(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2, const UGdouble& x, const UGdouble& y, const UGdouble dZone );
    UGbool IsPntNearLine(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2, const UGdouble& x, const UGdouble& y, const UGdouble dZone );
    
    // judge the point in polygon ( I don't know in or out when point on polygon's line
    UGbool IsInsidePolygon( const UGPoint2D* pPoints, const UGint nCount, const UGPoint2D pnt );
    
    // the two line is the same line
	//�ж������߶��Ƿ���ͬ
	UGbool IS_Same_Line( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2 );
    UGbool ISSameLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2 );
    UGbool ISNearSameLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, const UGdouble& dZone );
    UGbool MakeSameLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, UGPoint2D& pntEnd2, const UGdouble& dZone );
    
    // the two line is the Parallel line
    UGbool IS_Parallel_Line( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2 );
    UGbool ISParallelLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2 );
    UGbool ISNearParallelLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, const UGdouble& dZone );
    UGbool MakeParallelLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, UGPoint2D& pntEnd2, const UGdouble& dZone );
    
    // the two line is the Vertical line
    UGbool ISVerticalLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2 );
    UGbool ISNearVerticalLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, const UGdouble& dZone );
    UGbool MakeVerticalLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, UGPoint2D& pntEnd2, const UGdouble& dZone );
    
    // the three point near the angle
    // please make sure the angle is large than 0 and small than 180
    UGbool ISFixAngle( const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3, const UGdouble& dAngle );
    UGbool ISNearFixAngle( const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3, const UGdouble& dAngle, const UGdouble& dZone );
    UGbool MakeFixAngle( const UGPoint2D& pnt1, const UGPoint2D& pnt2, UGPoint2D& pnt3, const UGdouble& dAngle, const UGdouble& dZone );
    
    // the two point near to the Length
    UGbool ISFixLength( const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGdouble& dLength );
    UGbool ISNearFixLength( const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGdouble& dLength, const UGdouble& dZone );
    UGbool MakeFixLength( const UGPoint2D& pnt1, UGPoint2D& pnt2, const UGdouble& dLength, const UGdouble& dZone );
    
    // line's sect, when the line on one line return is TRUE
    UGbool IntersectLine(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, UGPoint2D& pntResult );
    
    // linesect's sect ( supply by WangHong )
    UGbool Line_Cross(const UGdouble& x3, const UGdouble& y3, const UGdouble& x4, const UGdouble& y4, const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2, UGdouble &dCrossx, UGdouble &dCrossy);
    
    //�����pntHitTest���߶�(pntLinsectStart, pntLinsectEnd)�������ӳ����ϵĴ����(resultPoint)
    //����ֵ:	TRUE -- �������߶���
    //			FALSE -- �������߶���(�ӳ�����)
    // supply by Watson ( don't use this )
    UGbool PointProjectToLinesetWa( const UGPoint2D& pntHitTest, const UGPoint2D&  pntLinsectStart, const UGPoint2D& pntLinsectEnd, UGPoint2D& resultPoint );
    // supply by Chen Junhua ( don't use this )
    UGbool PointProjectToLinesetCh( const UGPoint2D& pntHitTest, const UGPoint2D&  pntLinsectStart, const UGPoint2D& pntLinsectEnd, UGPoint2D& resultPoint );
    // judge by rotate
    UGbool PointProjectToLinesetRo( const UGPoint2D& pntHitTest, const UGPoint2D&  pntLinsectStart, const UGPoint2D& pntLinsectEnd, UGPoint2D& resultPoint );
    // for line
    void PointProjectToLinesetRn( const UGPoint2D& pntHitTest, const UGPoint2D&  pntLinsectStart, const UGPoint2D& pntLinsectEnd, UGPoint2D& resultPoint );

	// ʹ������������������Σ���������ı�ڶ������x��y����
	void MakeSquare( const UGPoint2D& pnt2DOrg, UGPoint2D& pnt2DNew );

	

protected:
    // attribute
    UGdouble              m_dSnapTolerance;

};

}

#endif // !defined(AFX_UGEDITOPERATER_H__552A08DF_A1F7_4B0A_8EAE_3D35571F3FEE__INCLUDED_)
