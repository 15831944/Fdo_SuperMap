// UG3DGeometry.h: interface for the UG3DGeometry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UG3DGEOMETRY_H)
#define UG3DGEOMETRY_H
namespace UGC{

#include "Geometry/UGGeometry.h"


class GRAPHICS3D_API UG3DGeometry  :public UGGeometry
{
public:
	UG3DGeometry();
	virtual ~UG3DGeometry();
public:
	//! \brief ��յ�������
	virtual void Clear();
	
	//! \brief �õ�ά��
	virtual UGint GetDimension() const;
	
	//! \brief �õ�����
	virtual Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief ����XML��ʽ����Ϣ
	virtual UGString ToXML()  const;
	
	//! \brief ��XML�ַ���������Geometry
	virtual UGbool FromXML(UGString& strXML);
	
	//! \brief �õ��ռ�����
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount) const;
	
	//! \brief ���ζ����Ƿ���Ч
	virtual UGbool IsValid() const;
	
	//! \brief �������
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
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
	
	//! \brief ��ת
	virtual void Rotate(const UGPoint2D& pntOrigin, const UGdouble& dAngle);
	
	//! \brief ��ת
	virtual void Rotate( const UGPoint2D& pntOrigin, const UGdouble& dCosAngle, const UGdouble& dSinAngle,double dAngle = 0);
protected:
	virtual UGbool SaveGeoData( UGStream& stream, UGDataCodec::CodecType eCodecType ) const;
	
	virtual UGbool LoadGeoData( UGStream& stream );
	
	

};

}

#endif // !defined(UG3DGEOMETRY_H)
