#ifndef UGGEORECTROUND_H
#define UGGEORECTROUND_H

#include "UGGeoRect.h"
#include "UGGeometry.h"

namespace UGC {

//! \brief Բ�Ǿ���(б)����
//! \remarks Բ�Ǿ��ζ������״��������: �Ⱦ��η��ú�,
//!	Ȼ����ĸ��Ǹ�Ϊ1/4��Բ��(��Բ�ĳ�����Ͷ̰���ֱ�Ϊ:m_dRadiusX��m_dRadiusY)
//! �����ʱ����ת�Ƕ�, ���õ�бԲ�Ǿ���
class GEOMETRY_API UGGeoRectRound : public UGGeometry
{
public:
	//! \brief ���캯��
    UGGeoRectRound();

	//! \brief ��������
    virtual ~UGGeoRectRound();
	
public: //pure virtual 
	
	//! \brief ��յ�������
	virtual void Clear();
	
	//! \brief �õ�ά��, �̶�Ϊ2ά
	virtual UGint GetDimension() const;
	
	//! \brief �õ�����, �̶�Ϊ GeoRectRound
	virtual Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \remarks ��Ϊ���ĵ�
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief �õ����󳤶�
	//! \attention DimensionΪ1or2�Ķ����֧��
	//! \return ���س���
	virtual UGdouble GetLength() const;
	
	//! \brief �õ��������
	//! \return �������
	virtual UGdouble GetArea() const;
	
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
	
	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ�����ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief ���ζ����Ƿ���Ч
	//! \return �߶�/���/������/�̰�����һ��С��0, ����false
	//!			�����������ڿ�ȵ�һ��,���߶̰�����ڸ߶ȵ�һ��, Ҳ����false
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
						UGdouble dSinAngle, double dAngle = 0);
	
	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \remarks б��Բresize��, ���ܲ�����ȫ����µ�bounds; 
	//!			 �ټ���õ���BoundsҲ�п��ܲ�����resize�Ĳ���
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

	//! \brief �������ƹ���Բ�Ǿ��Ρ�
	//! \param geoRectRound [in] ���е�Բ�Ǿ��Ρ�
	//! \return �Ժ����Ƿ�,����false��
	UGbool Make(const UGGeoRectRound& geoRectRound);	
	
	//! \brief ͨ�����ĵ�/Size/��ת�Ƕ�/������/�̰��ṹ��Բ�Ǿ��Ρ�
	//! \param pntCenter [in] ���ĵ㡣
	//! \param szSize [in] ���ε�Size��
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \param dRadiusX [in] Բ�ǵĳ����ᡣ
	//! \param dRadiusY [in] Բ�ǵĶ̰��ᡣ
	//! \return �������̰������С��0,����false��
	UGbool Make(const UGPoint2D &pntCenter, const UGSize2D& szSize, UGdouble dAngle,
				UGdouble dRadiusX, UGdouble dRadiusY);    
	
	//! \brief ͨ�����ζ����Բ�ǳ��̰��ṹ��Բ�Ǿ��Ρ�
	//! \param geoRect [in] ���ζ���
	//! \param dRadiusX [in] Բ�ǳ����ᡣ
	//! \param dRadiusY [in] Բ�Ƕ̰��ᡣ
	//! \return �������̰������С��0,����false��
	UGbool Make(const UGGeoRect& geoRect, UGdouble dRadiusX, UGdouble dRadiusY);    
	
	//! \brief ͨ������/��ת�Ƕ�/Բ�ǳ��̰��ṹ��Բ�Ǿ��Ρ�
	//! \param rect [in] ���Ρ�
	//! \param dAngle [in] ��ת�Ƕȡ�
	//! \param dRadiusX [in] Բ�ǳ����ᡣ
	//! \param dRadiusY [in] Բ�Ƕ̰��ᡣ
	//! \return �������̰������С��0,����false��
	UGbool Make(const UGRect2D& rect, UGdouble dAngle, UGdouble dRadiusX, UGdouble dRadiusY);	
	
	//! \brief �õ����ĵ㡣
	//! \return �������ĵ㡣
	UGPoint2D GetCenterPoint() const;    
	
	//! \brief �������ĵ㡣
	//! \param pntCenter [in] ���ĵ㡣
	void SetCenterPoint( const UGPoint2D& pntCenter );    
	
	//! \brief �õ���ת�Ƕȡ�
	//! \return ������ת�Ƕȡ�
	UGdouble GetAngle() const;    
	
	//! \brief ������ת�Ƕȡ�
	//! \param dAngle [in] ��ת�Ƕȡ�
	void SetAngle( UGdouble dAngle );    
	
	//! \brief �õ�Բ�ǳ����ᡣ
	//! \return ����Բ�ǳ����ᡣ
	UGdouble GetRadiusX() const;    
	
	//! \brief ����Բ�ǳ����ᡣ
	//! \param dRadiusX [in] Բ�ǳ����ᡣ
	//! \return ���������С��0,����false��
	UGbool SetRadiusX(UGdouble dRadiusX);    
	
	//! \brief �õ�Բ�Ƕ̰��ᡣ
	//! \return ����Բ�Ƕ̰��ᡣ
	UGdouble GetRadiusY() const;    
	
	//! \brief ����Բ�Ƕ̰��ᡣ
	//! \param dRadiusY [in] Բ�Ƕ̰��ᡣ
	//! \return ����̰���С��0,����false��
    UGbool SetRadiusY(UGdouble dRadiusY);
	
	//! \brief �õ����θ߶ȡ�
	//! \return ���ؾ��θ߶ȡ�
	UGdouble GetHeight() const;	
	
	//! \brief ���þ��θ߶ȡ�
	//! \param dHeight [in] Ҫ���õľ��θ߶ȡ�
	//! \return �߶�С�ڵ���0,����false��
	UGbool SetHeight( UGdouble dHeight );	
	
	//! \brief �õ����ο�ȡ�
	//! \return ���ؾ��ο�ȡ�
	UGdouble GetWidth() const;
	
	//! \brief ���þ��ο�ȡ�
	//! \param dWidth [in] Ҫ���õľ��ο�ȡ�
	//! \return ���С�ڵ���0,����false��
	UGbool SetWidth( UGdouble dWidth );
	
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

 	//! \brief ����������ʱ�ĸ����㣬���ص��ǵ����Ŀ,nHandleType���ص��Ǹ����������,�ο�UGEditType::EditHandleType
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param eAssistantPoints �㴮,���صĸ�����㴮
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	 virtual void CalAssistantPoints(const UGPoint2D* pPoints,UGint nPntCount,UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,UGEditType::EditToolShape nEditType);

	 //! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	 //Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�����GeoLine
	 //GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ� 
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
     virtual void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType=UGEditType::ET_None);

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
	
	/*virtual UGRect2D GetBoundsInside() const;
	
	virtual void SetBoundsInside( const UGRect2D & rcBounds );*/
	
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
	
	// by zengzm 2007-9-6 IsPointInRoundRectʵ�ֵĹ�ȥ����,����û�п�������,�ȷ�����
	//UGbool IsPointInRoundRect(const UGPoint2D &pntHitTest) const;
	
private:
	//! \brief ���ĵ�
	UGPoint2D m_pntCenter;
	
	//! \brief ���ο��
	UGdouble m_dWidth;
	
	//! \brief ���θ߶�
	UGdouble m_dHeight;
	
	//! \brief Բ�ǳ�����
	UGdouble m_dRadiusX;
	
	//! \brief Բ�Ƕ̰���
	UGdouble m_dRadiusY;
	
	// modified by zengzm 2007-4-27 
	//UGint m_nAngle;
	//! \brief ��ת�Ƕ�
	//! \remarks �ڴ��и�Ϊdouble,�Ƕȵ�λ,�洢ʱ��SFC���ּ���
	UGdouble m_dAngle;
};

} // namespace UGC


#endif /* INCLUDE_GEOMETRY_UGGEORECTROUND_H_HEADER_INCLUDED_BE22541D */
