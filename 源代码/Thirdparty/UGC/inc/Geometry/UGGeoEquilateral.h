#ifndef INCLUDE_GEOMETRY_UGGEOEQUILATERAL_H_HEADER_INCLUDED_BE2200C2
#define INCLUDE_GEOMETRY_UGGEOEQUILATERAL_H_HEADER_INCLUDED_BE2200C2

#include "UGGeometry.h"

namespace UGC {

//! \attention UGGeoEquilateral�ݲ�����,��Ҫʹ��
class GEOMETRY_API UGGeoEquilateral : public UGGeometry
{
//modified by xielin ��ʱ������UGGeoEquilateral���󣬹��캯���޸�Ϊprotected 2007.4.7
protected:
    UGGeoEquilateral();

    virtual ~UGGeoEquilateral();

public: //pure virtual 

	virtual void Clear();

	virtual UGint GetDimension() const;

	virtual Type GetType() const;

	virtual UGPoint2D GetInnerPoint() const;
	
//	virtual UGGeoLine* GetInnerLine() const;

	virtual UGdouble GetArea() const;

	virtual UGdouble GetLength() const;
	
	virtual UGbool ConvertToLine( UGGeoLine &GeoLine, UGint nSegmentCount = 0 ) const;

	virtual UGbool ConvertToRegion( UGGeoRegion &GeoRegion, UGint nSegmentCount = 0 ) const;

	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;

	virtual UGString ToXML()  const;

	virtual UGbool FromXML(const UGString& strXML);

	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
				UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;

	// �����Ƿ���Ч
	virtual UGbool IsValid()const;
	
	//! \brief ����
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	virtual void Inflate( UGdouble dRatio);
	
	//! \brief ƽ��
	virtual void Offset( UGdouble dX, UGdouble dY);
	
	//! \brief ƽ��
	virtual void Offset( UGdouble dOffset);
	
	//! \brief ƽ��
	virtual void Offset( const UGSize2D &szOffset);
	
	//! \brief ��ת���Ƕȵ�λΪ��
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief ��ת���Ƕȵ�λΪ��
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle,
						UGdouble dSinAngle, UGdouble dAngle = 0);
	
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

public:
	//Projection..
	virtual void PJConvert( UGRefTranslator *pRefTranslator, UGbool bForward = true);
	virtual void PJForward( UGPrjCoordSys *pCoordSys );
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );	

public:
	UGbool Make(const UGGeoEquilateral& geoEquilateral);

    //�Ƕȵ�λΪ��
    UGbool Make(const UGPoint2D& pntCenter, UGdouble dRadius, UGint nSideCount, UGdouble dAngle);

    UGPoint2D GetCenterPoint();

    void SetCenterPoint( const UGPoint2D& pntCenter );

    UGdouble GetRadius();

    UGbool SetRadius( UGdouble dRadius);

    UGint GetSideCount();

    UGbool SetSideCount(UGint nSideCount);
	
	//����ֵ�Ƕȵ�λΪ��
    UGdouble GetAngle();
	
	//�Ƕȵ�λΪ��
    void SetAngle(UGdouble dAngle);

protected:
	virtual UGRect2D ComputeBounds() const;
	
	//virtual UGRect2D GetBoundsInside() const;

	//virtual void SetBoundsInside( const UGRect2D & rcBounds );

	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );

private:
	UGPoint2D m_pntCenter;

	UGdouble m_dRadius;
	
	UGint m_nSideCount;
	
	UGint m_nAngle; // ����Ƕ�Ҳ������, �ݲ�����
};

} // namespace UGC



#endif 
