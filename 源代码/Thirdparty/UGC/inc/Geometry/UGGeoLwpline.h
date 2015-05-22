#ifndef INCLUDE_GEOMETRY_UGGEOLWPLINE_H_HEADER_INCLUDED_BE2202E0
#define INCLUDE_GEOMETRY_UGGEOLWPLINE_H_HEADER_INCLUDED_BE2202E0

#include "UGGeometry.h"

namespace UGC {

class GEOMETRY_API UGGeoLwpline : public UGGeometry
{
 private: // by zengzm 2007-4-10 UGGeoLwpline ��ʱҲ������
/* by zengzm 2007-8-24 ��ʱ�ò����ľ��ȶ�ע������, �Ժ�Ҫ֧���ٿ���
    UGGeoLwpline();

    virtual ~UGGeoLwpline();

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

	virtual UGbool ConvertToRegion( UGGeoRegion &GeoRegion, UGint nSegmentCount = 0 ) const;

	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;


	//=======================================================
	//{{ Deleted by GUOQC at [2005-02-22 16:44:54]
	// * �޸�ԭ�򼰱�Ҫ˵��
	//Del virtual UGbool Save(UGStream& stream, UGDataCodec::CodecType eCodecType=UGDataCodec::encNONE) const;
	//Del 
	//Del virtual UGbool Load(UGStream& stream);
	//}} Deleted by GUOQC at [2005-02-22 16:44:54]
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
	
	//! \brief ��ת
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief ��ת
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, double dAngle = 0);
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

public:	
	//Projection..
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);
	virtual void PJForward( UGPrjCoordSys *pCoordSys );
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );
	
public:
	UGbool Make(const UGGeoLwpline& geoLwpline);

    UGbool Make(const UGPoint2D *pPoints, const UGSize2D* pWidths, UGdouble *pBulge, UGbool bIsClosed, UGint pointCount, float fConstantWidth);

    UGint GetCtrlPointCount();

    UGPoint2D* GetCtrlPoints();

    UGSize2D *GetWidths();

    UGdouble *GetBulges();

    float *GetConstantWidth();

    UGbool IsClosed();

//    UGbool ConstructGeometry(UGGeometry*& pGeometry, CSmDrawParamaters *pDrawParam = NULL);

protected:
	virtual UGRect2D ComputeBounds() const;
	
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE );



	//========================================================
	//! \brief 		��ȡ���ζ���Ĳο��㣬���Լ��ζ���Ĳ�������ʹ��
	//! \return 	UGint		�����ȡ�ĵ㲻�ǿ���������0�����򷵻�1
	//! \param 		pPoints		�㴮ָ��
	//! \param 		nCount		�㴮�е�ĸ���
	//! \remarks 	�������1�����ζ���Ĳ���������Ҫ����SetReferencePoints	
	//virtual UGint GetReferencePoints( UGPoint2D*& pPoints, UGint& nCount );
	

	//========================================================
	//! \brief 		���ü��ζ���Ĳο��㣬�Լ��ζ����Ĳ�����Ҫд�ض���
	//! \return 	UGbool		���óɹ�����true�����򷵻�false
	//! \param 		pPoints		�㴮ָ��
	//! \param 		nCount		�㴮�е�ĸ���
	//! \remarks 	���������Ҫʵ��������������ڻ�ȡ�Ĳο��㲻��ֱ��ָ��������Ķ�����Ҫʵ�ָú���	
	//virtual UGbool SetReferencePoints( UGPoint2D* pPoints, UGint nCount );

private:
	
	UGint m_nPointCount;

	UGArray<UGPoint2D> m_Points;

	UGArray<UGSize2D> m_Widths;

	UGArray<UGdouble> m_Bulges;

	UGbool m_bClosed;

	float m_fConstantWidth;
// by zengzm 2007-8-24 ��ʱ�ò����ľ��ȶ�ע������, �Ժ�Ҫ֧���ٿ���
  */
};

} // namespace UGC



#endif /* INCLUDE_GEOMETRY_UGGEOLWPLINE_H_HEADER_INCLUDED_BE2202E0 */
