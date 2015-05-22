// UGGeometry3D.h: interface for the UGGeometry3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGGEOMETRY3D_H)
#define UGGEOMETRY3D_H

#include "Geometry/UGGeometry.h"

namespace UGC{
class UGStyle3D;
class GRAPHICS3D_API UGGeometry3D :public UGGeometry
{
public:
	UGGeometry3D();
	virtual ~UGGeometry3D();
public:
	//! \brief �õ�ά��
	virtual UGint GetDimension() const;
	
	//! \brief �õ�����
	virtual UGGeometry::Type GetType() const;

	//! \brief ��յ�������
	virtual void Clear();

	//! \brief ����XML��ʽ����Ϣ
	virtual UGString ToXML()  const;
	
	//! \brief ��XML�ַ���������Geometry
	virtual UGbool FromXML(UGString& strXML);

	//! \brief ���ζ����Ƿ���Ч
	virtual UGbool IsValid() const;
	
	//{{Inherited from parend and these functions have nothing to do with the Geometry3D		
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	virtual UGPoint2D GetInnerPoint() const{return UGPoint2D(0,0);};
		
	//! \brief �õ��ռ�����
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount) const{return FALSE;};
		
	//! \brief �������
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const{return FALSE;};
	
	//! \brief ����
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY){};
	
	//! \brief ����
	virtual void Inflate( UGdouble dRatio){};
	
	//! \brief ƽ��
	virtual void Offset( UGdouble dX, UGdouble dY){};
	
	//! \brief ƽ��
	virtual void Offset( UGdouble dOffset){};
	
	//! \brief ƽ��
	virtual void Offset( const UGSize2D &szOffset){};
	
	//! \brief ��ת
	virtual void Rotate(const UGPoint2D& pntOrigin, const UGdouble& dAngle){};
	
	//! \brief ��ת
	virtual void Rotate( const UGPoint2D& pntOrigin, const UGdouble& dCosAngle, const UGdouble& dSinAngle,double dAngle = 0){};
	//}}

protected:

	virtual UGbool SaveGeoData( UGStream& stream, UGDataCodec::CodecType eCodecType ) const;
	
	virtual UGbool LoadGeoData( UGStream& stream );

protected:

	UGStyle3D* m_pStyle3D;
};

}

#endif // !defined(UGGeometry3D)
