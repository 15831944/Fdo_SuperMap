#ifndef INCLUDE_GEOMETRY_UGGEOPATH_H_HEADER_INCLUDED_BE22747D
#define INCLUDE_GEOMETRY_UGGEOPATH_H_HEADER_INCLUDED_BE22747D


#include "UGGeometry.h"

namespace UGC {

// ������� ��Ҫ��?
class GEOMETRY_API UGGeoPath : public UGGeometry
{
	/* by zengzm 2007-8-24 ��ʱ�ò����ľ��ȶ�ע������, �Ժ�Ҫ֧���ٿ���
public:
	enum PointType
	{
		MoveTo = 1,
		LineTo = 2,
		ArcTo  = 3,
		BezierTo = 4
	};

// modified by zengzm 2007-4-25 �������������, ����new����
private:
    UGGeoPath();

    virtual ~UGGeoPath();

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
	//{{ Deleted by GUOQC at [2005-02-22 16:45:41]
	// * �޸�ԭ�򼰱�Ҫ˵��
	//Del virtual UGbool Save(UGStream& stream, UGDataCodec::CodecType eCodecType=UGDataCodec::encNONE) const;
	//Del 
	//Del virtual UGbool Load(UGStream& stream);
	//}} Deleted by GUOQC at [2005-02-22 16:45:41]
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
	
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

public:
	//Projection..
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);
	virtual void PJForward( UGPrjCoordSys *pCoordSys );
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );
	

public:

    void SetClose(UGbool bClosed = true);

    void SetFill(UGbool bFilled = true);

	UGbool Make(const UGGeoPath& geoPath);

    UGbool Make(UGPoint2D *pPoints, UGbyte *pTypes, UGint nCount, UGbool bClosed = false, UGbool bFilled = false);

    UGbool Make(UGGeoPath &PathObj);

    UGbyte *GetTypes();

    UGint GetSubCount();

    UGint GetPointCount();

    UGPoint2D *GetPoints();

    UGbool GetAt(UGint nIndex, UGPoint2D &pntVertex, PointType &btType);


    UGPoint2D GetStartNode();

    UGPoint2D GetEndNode();

    UGbool Add(const UGPoint2D &pntPoint, UGGeoPath::PointType btType);

    UGbool Add(UGPoint2D *pPoints, UGGeoPath::PointType *pbtType, UGint nCount);

    UGbool InsertAt(UGint nIndex, const UGPoint2D &pntPoint, UGGeoPath::PointType btType);

    UGbool InsertAt(UGint nIndex, UGPoint2D *pPoints, UGGeoPath::PointType *pbtType, UGint nCount);

    UGbool SetAt(UGint nIndex, const UGPoint2D &pntPoint, UGGeoPath::PointType btType);

    UGbool SetAt(UGint nIndex, UGPoint2D *pPoints, UGGeoPath::PointType *pbtType, UGint nCount);

    UGbool RemoveAt(UGint nIndex);

    UGint Remove(UGint nFrom, UGint nCount);

    UGbool RemoveAll();

	
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
	UGArray<UGPoint2D> m_Points;
	
	UGArray<UGbyte> m_pTypes;
	
	UGint m_nPointCount;
	
	UGbool m_bClosed;
	
	UGbool m_bFilled;
	// by zengzm 2007-8-24 ��ʱ�ò����ľ��ȶ�ע������, �Ժ�Ҫ֧���ٿ���
	*/
};

} // namespace UGC



#endif /* INCLUDE_GEOMETRY_UGGEOPATH_H_HEADER_INCLUDED_BE22747D */
