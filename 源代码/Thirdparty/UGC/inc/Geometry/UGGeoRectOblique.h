#ifndef INCLUDE_GEOMETRY_UGGEORECTOBLIQUE_H_HEADER_INCLUDED_BE220BE3
#define INCLUDE_GEOMETRY_UGGEORECTOBLIQUE_H_HEADER_INCLUDED_BE220BE3

#include "UGGeoRect.h"
#include "UGGeometry.h"

namespace UGC {

//! \attention UGGeoRectOblique��UGGeoRectȡ��, ��ʹ��UGGeoRect
class GEOMETRY_API UGGeoRectOblique : public UGGeometry
{
private:
	// by zengzm 2007-4-25 UGGeoRectOblique��б��Բ, UGC�е�UGGeoRect�Ѿ���б��Բ��,��������Ͳ���Ҫ��,
	// ��������������һ���ο�,�Ժ� ɾ����OK��.
    UGGeoRectOblique();

    virtual ~UGGeoRectOblique();


public: //pure virtual 

	virtual void Clear();

	virtual UGint GetDimension() const;

	virtual Type GetType() const;

	virtual UGPoint2D GetInnerPoint() const;
	
//	virtual UGGeoLine* GetInnerLine() const;

	virtual UGdouble GetPerimeter() const;

	virtual UGdouble GetArea() const;

	virtual UGdouble GetLength() const;
	
	virtual UGbool ConvertToLine( UGGeoLine &GeoLine, UGlong nSegmentCount = 0 ) const;

	virtual UGbool ConvertToRegion( UGGeoRegion &GeoRegion, UGlong nSegmentCount = 0 ) const;

	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;


	virtual UGString ToXML()  const;

	virtual UGbool FromXML(const UGString& strXML);

	virtual UGbool GetSpatial(UGAutoPtr<UGPoint2D>& pPoints, 
				UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount) const;
public:

    UGbool MakeRectOblique( const UGPoint2D &pntCenter, const UGSize2D& szSize, UGlong nAngle );

    UGbool MakeRectOblique( const UGGeoRect& Rect, UGlong nAngle );


	UGbool MakeRectOblique( const UGRect2D& rcRect, UGlong nAngle );

    UGPoint2D GetCenterPoint()const ;

    void SetCenterPoint( const UGPoint2D& pntCenter );

	UGdouble GetHeight() const;

	UGbool SetHeight( UGdouble dHeight );

	UGdouble GetWidth() const;

	UGbool SetWidth( UGdouble dWidth );

    UGlong GetAngle() const ;

    void SetAngle( UGlong nAngle );

   
protected:
	virtual UGRect2D ComputeBounds() const;
	
	/*virtual UGRect2D GetBoundsInside() const;

	virtual void SetBoundsInside( const UGRect2D & rcBounds );*/

	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE ,UGbool bSDBPlus = FALSE);



	//========================================================
	//! \brief 		��ȡ���ζ���Ĳο��㣬���Լ��ζ���Ĳ�������ʹ��
	//! \return 	UGint		�����ȡ�ĵ㲻�ǿ���������0�����򷵻�1
	//! \param 		pPoints		�㴮ָ��
	//! \param 		nCount		�㴮�е�ĸ���
	//! \remarks 	�������1�����ζ���Ĳ���������Ҫ����SetReferencePoints	
	virtual UGint GetReferencePoints( UGPoint2D*& pPoints, UGint& nCount );
	

	//========================================================
	//! \brief 		���ü��ζ���Ĳο��㣬�Լ��ζ����Ĳ�����Ҫд�ض���
	//! \return 	UGbool		���óɹ�����true�����򷵻�false
	//! \param 		pPoints		�㴮ָ��
	//! \param 		nCount		�㴮�е�ĸ���
	//! \remarks 	���������Ҫʵ��������������ڻ�ȡ�Ĳο��㲻��ֱ��ָ��������Ķ�����Ҫʵ�ָú���	
	virtual UGbool SetReferencePoints( UGPoint2D* pPoints, UGint nCount );

private:
	UGPoint2D m_pntCenter;
	
	UGdouble m_dWidth;

	UGdouble m_dHeight;

	UGlong m_nAngle;

};

} // namespace UGC



#endif /* INCLUDE_GEOMETRY_UGGEORECTOBLIQUE_H_HEADER_INCLUDED_BE220BE3 */
