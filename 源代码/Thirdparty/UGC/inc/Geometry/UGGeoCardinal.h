#ifndef INCLUDE_GEOMETRY_UGGEOCARDINAL_H_HEADER_INCLUDED_BE224646
#define INCLUDE_GEOMETRY_UGGEOCARDINAL_H_HEADER_INCLUDED_BE224646

#include "UGGeometry.h"

namespace UGC {
//! \brief Cardinal����
//! \remarks ��SFC��ֲ����, �����ѧ���������ĸ�����, �����Ǻ����, �д���ʵ.
//! Cardinal������һ���ǳ�����������,���ǿ��Ƶ㶼�Ǳ�Ȼ��ͨ���ĵ�,�����ڱ༭��ʱ��о��ȽϺ�
class GEOMETRY_API UGGeoCardinal : public UGGeometry
{
public:
	//! \brief ���캯����
    UGGeoCardinal();
	
	//! \brief ����������
    virtual ~UGGeoCardinal();
	
	
public: //pure virtual 
	//! \brief ��յ�������
	virtual void Clear();

	//! \brief �õ�ά��, �̶�Ϊ1ά
	virtual UGint GetDimension() const;

	//! \brief �õ�����, �̶�ΪUGGeoCardinal
	virtual Type GetType() const;

	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	virtual UGPoint2D GetInnerPoint() const;
	
	//virtual UGbool ConvertToLine( UGGeoLine &GeoLine, UGint nSegmentCount = 0 ) const;

	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;

	//! \brief ����XML��ʽ����Ϣ
	//! \param versionType GML�İ汾
	//! \param nPace �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0) const;

	//! \brief ��XML�ַ���������Geometry
	//! \param strXML xml��ʽ�ַ���
	//! \param versionType xml�ַ�����GML�汾
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType);

	//! \brief �õ��ռ�����
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
				UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;

	//! \brief ���ζ����Ƿ���Ч, ����2���������Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid()const;
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y������ͬ)
	virtual void Inflate( UGdouble dRatio);
	
	//! \brief ƽ��
	//! \param dX ƽ�Ƶ�Xƫ����
	//! \param dY ƽ�Ƶ�Yƫ����
	virtual void Offset( UGdouble dX, UGdouble dY);
	
	//! \brief ƽ��
	//! \param ƫ����(X,Y������ͬ)
	virtual void Offset( UGdouble dOffset);
	
	//! \brief ƽ��
	//! \param ƽ�Ƶ�ƫ����(�ֱ���UGSize2D�е�x,y����X,Y�����ƫ����)
	virtual void Offset( const UGSize2D &szOffset);
	
	//! \brief ��ת
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dAngle ��ת�Ƕ�
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief ��ת,����һЩ����,�Ա��ڲ����Բ��ý���cos,sin, �����������ʱ�����������Ч��
	//! \remarks dAngle���ƶ���,��GeoText��Ҫ,����Ҫ����
	//! \param pntOrigin ��ת�����ĵ�(ê��,������)
	//! \param dCosAngle ��ת��cosֵ
	//! \param dSinAngle ��ת��sinֵ
	//! \param dAngle ��ת�Ƕ�
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle, 
						UGdouble dSinAngle, UGdouble dAngle = 0);
	
	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 


public:	
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator ͶӰת����
	//! \param bForward ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);

	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );

	
public:

	//! \brief ͨ�����Ƶ�㴮����BSpline��
	//! \param pPoints [in] ���Ƶ�㴮ָ�롣
	//! \param nPointCount [in] ���Ƶ���Ŀ��
	//! \return С��2����,���첻�ɹ�,����false��
    UGbool Make( UGPoint2D* pPoints, UGint nPointCount );

	//! \brief ͨ�����ƹ���Cardinal����
	//! \param geoCardinal [in] ԭ�е�Cardinal��
	//! \return ԭ��Cardinal�Ƿ�, ����false��
	UGbool Make(const UGGeoCardinal& geoCardinal);
		
	//! \brief �õ��ڲ����Ƶ������ָ�롣
	//! \return �����ڲ����Ƶ������ָ��, Ϊconst����,һ�㲻Ҫֱ���޸ġ�
    const UGPoint2D *GetPoints() const;
	
	//! \brief �õ����Ƶ������
	//! \return ���ؿ��Ƶ������
    UGint GetPointCount() const;
	
	//! \brief ����һ�����Ƶ㡣
	//! \param pntPoint [in] Ҫ���ӵĿ��Ƶ㡣
	//! \return ����true��
    UGbool Add( const UGPoint2D& pntPoint );
	
	//! \brief ���ӿ��Ƶ�㴮��
	//! \param pPoints [in] ���Ƶ�㴮ָ�롣
	//! \param nPointCount [in] ���Ƶ���Ŀ��
	//! \return ����true��
    UGbool Add( const UGPoint2D *pPoints, UGint nPointCount );
	
	//! \brief ������Ƶ㡣
	//! \param nIndex [in] Ҫ�����λ��������
	//! \param pntPoint [in] Ҫ����Ŀ��Ƶ㡣
	//! \return ��������Ч��Χ��, ����true; ���򷵻�false��
    UGbool InsertAt( UGint nIndex, const UGPoint2D& pntPoint );
	
	//! \brief ��ָ��λ�����ÿ��Ƶ㡣
	//! \param nIndex [in] Ҫ���õ�λ��������
	//! \param pntPoint [in] Ҫ���õĿ��Ƶ㡣
	//! \return ��������Ч��Χ��, ����true; ���򷵻�false��
	//! \remarks ԭ��λ�õĿ��Ƶ�ᱻ�����
    UGbool SetAt( UGint nIndex, const UGPoint2D& pntPoint );
	
	//! \brief �õ�ָ�������Ŀ��Ƶ㡣
	//! \param nIndex [in] ָ����������
	//! \param pntPoint [out] �õ��Ŀ��Ƶ㡣
	//! \return ��������Ч��Χ��, ����true; ���򷵻�false��
	//! \remarks ����falseʱ, pntPointΪ��Чֵ��
    UGbool GetAt( UGint nIndex, UGPoint2D& pntPoint ) const;
	
	//! \brief �Ƴ�ָ�������Ŀ��Ƶ㡣
	//! \param nIndex [in] Ҫ�Ƴ�������λ�á�
	//! \return ��������Ч��Χ��, ����true; ���򷵻�false��
    UGbool RemoveAt( UGint nIndex );
		
	//! \brief �Ƴ����п��Ƶ�
    void RemoveAll();
public:		
	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ
	
	//! \brief ��ñ༭����ľ������Ŀ
	//! \remarks ���ڹ̶��������Ϊ9�����˸ı��С��8�����Ƶ��һ����ת���Ƶ�
     virtual UGint  GetHandleCount();

	
	//nHandle:��ֵ����Ƶ�Ĺ�ϵ����ͼ                         
	//									1---+   	  +--2    	+----3	
	//                                      |         |         |  
	//                                      |         |         |  
	//										x---------x---------x     9
    //										|   ____________    |     |
    //										|  /            \   | x---+
	//									4---x |              |  x-----5
	//										|  \____________/   |
	//										|                   |
	//										x---------x---------x
	//										|		  |         |
	//										|		  |         |
	//								    6---+         +-----7   +-----8
	
	//! \brief ���ݾ�������Ӧ���Ƶ��ֵ
	//! \param nHandle ���Ƶ���
	//! \param point �����Ӧ�Ŀ��Ƶ������ֵ
	//! \return ���ظ����������
	 virtual UGint GetHandle( UGint nHandle, UGPoint2D& point);


	//! \brief �ƶ����Ƶ㵽ָ������,��Ҫ���ڻ��ƶ����޸Ķ���ڵ�Ȳ���
	//! \param nHandle ���Ƶ���
	//! \param point ���Ƶ�����
	virtual void MoveHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_None);

	//! \brief �ڵ�༭ʱ����������һ�����Ƶ�,Ҳ�������ڻ��ƶ���ʱ����ڵ�
	//! \param nHandle ����λ��
	//! \param pnt2D �����ĵ�������
	virtual void AddHandle( UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_None);
	
	//! \brief ɾ���༭�����ָ���ڵ�
	//! \param nHandle �ڵ���
     virtual UGuint DelNode( UGint nHandle );

	//! \brief ����������ʱ�ĸ����ߣ����ص���һ�����϶���
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	//! \param pStyle	 �����ߵķ���������ΪNULL����Ĭ�ϵķ��
     virtual UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);

	 //! \brief ��ȡ������Ҫ��׽�ĵ㴮
	//! \param aryPnts �㴮������ȥ��Ҫ��׽�ĵ㴮
	//! \return �����true��ʾ����Ҫ��׽�ĵ㴮���������false��ʾ�ö���û����Ҫ��׽�ĵ㴮
	virtual UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);

	//! \brief ��ȡ������Ҫ��׽���߶�����
	//! \param aryLines ��Ҫ��׽�������飨����ж��part����ôaryLines��Ӧ���ж��ٸ�count��
	//! \return �����true��ʾ����Ҫ��׽���ߣ��������false��ʾ�ö���û����Ҫ��׽����
	virtual UGbool GetSnapLines(UGLineArray& aryLines);
	
	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end
protected:
	virtual UGRect2D ComputeBounds() const;
	
	//virtual UGRect2D GetBoundsInside() const;

	//virtual void SetBoundsInside( const UGRect2D & rcBounds );

	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );



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
	//! \brief ���Ƶ�����
	UGArray<UGPoint2D> m_Points;
};

} // namespace UGC



#endif /* INCLUDE_GEOMETRY_UGGEOCARDINAL_H_HEADER_INCLUDED_BE224646 */
