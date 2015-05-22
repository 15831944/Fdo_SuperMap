#ifndef INCLUDE_GEOMETRY_UGGEODONUT_H_HEADER_INCLUDED_BE220C91
#define INCLUDE_GEOMETRY_UGGEODONUT_H_HEADER_INCLUDED_BE220C91

#include "UGGeometry.h"

namespace UGC {

//! \attention �ݲ�֧��,��Ҫʹ��
class GEOMETRY_API UGGeoDonut : public UGGeometry
{
	/* by zengzm 2007-8-24 ��ʱ�ò����ľ��ȶ�ע������, �Ժ�Ҫ֧���ٿ���
private:// by zengzm 2007-4-10 UGGeoDonut ��ʱҲ������
    UGGeoDonut();

    virtual ~UGGeoDonut();

public: //pure virtual 

	virtual void Clear();

	virtual UGint GetDimension() const;

	virtual Type GetType() const;

	virtual UGPoint2D GetInnerPoint() const;
	
//	virtual UGGeoLine* GetInnerLine() const;

	virtual UGdouble GetPerimeter() const;

	virtual UGdouble GetArea() const;

	virtual UGdouble GetLength() const;
	
	virtual UGbool ConvertToLine( UGGeoLine &GeoLine, UGint nSegmentCount = 0 ) const;


	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;

	virtual UGbool ConvertToRegion( UGGeoRegion &GeoRegion, UGint nSegmentCount = 0 ) const;

	//=======================================================
	//{{ Deleted by GUOQC at [2005-02-22 15:28:49]
	// * �޸�ԭ�򼰱�Ҫ˵��
	//Del 
	//Del virtual UGbool Save(UGStream& stream, UGDataCodec::CodecType eCodecType=UGDataCodec::encNONE) const;
	//Del 
	//Del virtual UGbool Load(UGStream& stream);
	//}} Deleted by GUOQC at [2005-02-22 15:28:49]
	//=======================================================
	
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0) const;

	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType);

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
	
	//! \brief ��ת,�Ƕȵ�λΪ��
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief ��ת,�Ƕȵ�λΪ��
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, double dAngle = 0);
	
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

public:
	//Projection..
	virtual void PJConvert( UGRefTranslator *pRefTranslator, UGbool bForward = true);
	virtual void PJForward( UGPrjCoordSys *pCoordSys );
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );

public:
	UGbool Make(const UGGeoDonut& geoDonut);

    UGbool Make( const UGPoint2D& pntCenter, UGdouble dInner, UGdouble dOuter );

    UGPoint2D GetCenterPoint();

    void SetCenterPoint( const UGPoint2D& pntCenter );

    UGdouble GetInner();

    UGbool SetInner(UGdouble Inner);

    UGdouble GetOuter();

    UGbool SetOuter(UGdouble Outer);

protected:
	virtual UGRect2D ComputeBounds() const;
	
	//virtual UGRect2D GetBoundsInside() const;

	//virtual void SetBoundsInside( const UGRect2D & rcBounds );

	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE );

private:
	UGPoint2D m_pntCenter;

	UGdouble m_dInner;

	UGdouble m_dOuter;
	// by zengzm 2007-8-24 ��ʱ�ò����ľ��ȶ�ע������, �Ժ�Ҫ֧���ٿ���
	*/
};

} // namespace UGC



#endif /* INCLUDE_GEOMETRY_UGGEODONUT_H_HEADER_INCLUDED_BE220C91 */
