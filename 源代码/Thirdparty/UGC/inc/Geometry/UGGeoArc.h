
/*! \file	 UGGeoArc.h
 *  \brief	 ���ζ������
 *  \author	 ugc team
 *  \attention  
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGGeoArc.h,v 1.41 2007/10/25 06:49:40 zhouqin Exp $
 */

#ifndef UGGEOARC_H
#define UGGEOARC_H

#include "UGGeometry.h"

namespace UGC {

//! \brief Բ��
//! \remarks �ڲ����ݽṹͨ����ʼ��/��ֹ��/�м�� ��������Բ��
class GEOMETRY_API UGGeoArc : public UGGeometry
{
public:
	//! \brief ���캯��
    UGGeoArc();
	
	//! \brief ��������
    virtual ~UGGeoArc();
	
public:
	//! \brief ��յ�������
	virtual void Clear();
	
	//! \brief �õ�ά��, GeoArc�̶�Ϊ1ά
	virtual UGint GetDimension() const;
	
	//! \brief �õ�����, �̶�ΪGeoArc
	virtual Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	virtual UGPoint2D GetInnerPoint() const;
		
	//! \brief �õ����󳤶�
	//! \return ���س���
	virtual UGdouble GetLength() const;

	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual UGbool HitTest(const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	virtual void Inflate(UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y������ͬ)
	virtual void Inflate(UGdouble dRatio);
	
	//! \brief ƽ��
	//! \param dX ƽ�Ƶ�Xƫ����
	//! \param dY ƽ�Ƶ�Yƫ����
	virtual void Offset(UGdouble dX, UGdouble dY);
	
	//! \brief ƽ��
	//! \param ƫ����(X,Y������ͬ)
	virtual void Offset(UGdouble dOffset);
	
	//! \brief ƽ��
	//! \param ƽ�Ƶ�ƫ����(�ֱ���UGSize2D�е�x,y����X,Y�����ƫ����)
	virtual void Offset(const UGSize2D &szOffset);
	
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
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dCos, UGdouble dSin, UGdouble dAngle);
	
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
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, UGAutoPtr<UGint>& pPolyCount,
									UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid()const;

	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 
	
	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
public:
	
	//! \brief ����Arc
	//! \param pntCenter [in] Բ�ġ�
	//! \param dRadius [in] �뾶��
	//! \param dStartAngle [in] ��ʼ�Ƕȡ�
	//! \param dEndAngle [in] ��ֹ�Ƕȡ�
	//! \return �뾶Ϊ0ʱ,����ʧ�ܡ�
	UGbool Make(const UGPoint2D& pntCenter, UGdouble dRadius, UGdouble dStartAngle, UGdouble dEndAngle);	
	
	//! \brief ����Arc��
	//! \param pntStart [in] ��ʼ�㡣
	//! \param pntMiddle [in] �м�㡣
	//! \param pntEnd [in] ��ֹ�㡣
	//! \return ���㹲��ʱ,����ʧ�ܡ�
	UGbool Make(const UGPoint2D& pntStart, const UGPoint2D& pntMiddle, const UGPoint2D& pntEnd);    

	//! \brief ����Arc��
	//! \param geoArc [in] ���е�Arc��
	//! \return ԭ��Arc���Ϸ�ʱ,����ʧ�ܡ�
	UGbool Make(const UGGeoArc& geoArc);	
	
	//! \brief �õ���ʼ�㡣
	//! \return ������ʼ�㡣
	UGPoint2D GetStartPoint() const;    
	
	//! \brief �õ��м�㡣
	//! \return �����м�㡣
	UGPoint2D GetMiddlePoint() const;    
	
	//! \brief �õ���ֹ�㡣
	//! \return ������ֹ�㡣
	UGPoint2D GetEndPoint() const;    
	
	//! \brief ������ʼ�㡣
	//! \param pntStart [in] ��ʼ�㡣
	//! \return ������ú������㹲��,�򷵻�false��
	UGbool SetStartPoint(const UGPoint2D &pntStart);    
	
	//! \brief �����м�㡣
	//! \param pntMiddle [in] �м�㡣
	//! \return ������ú������㹲��,�򷵻�false��
	UGbool SetMiddlePoint(const UGPoint2D &pntMiddle);    
	
	//! \brief ������ֹ�㡣
	//! \param pntEnd [in] ��ֹ�㡣
	//! \return ������ú������㹲��,�򷵻�false��
	UGbool SetEndPoint(const UGPoint2D &pntEnd);    
	
	//! \brief ͬʱ�õ���ʼ��/�м��/��ֹ�㡣
	//! \param pntStart [out] �õ�����ʼ�㡣
	//! \param pntMiddle [out] �õ����м�㡣
	//! \param pntEnd [out] �õ�����ֹ�㡣
	void GetPoints(UGPoint2D &pntStart, UGPoint2D &pntMiddle, UGPoint2D &pntEnd);	
	
	//! \brief ͬʱ������ʼ��/�м��/��ֹ�㡣
	//! \param pntStart [in] ��ʼ�㡣
	//! \param pntMiddle [in] �м�㡣
	//! \param pntEnd [in] ��ֹ�㡣
	//! \return ������㹲��,�򷵻�false��
	UGbool SetPoints(const UGPoint2D& pntStart, const UGPoint2D& pntMiddle,
						const UGPoint2D& pntEnd);    
	
	//! \brief �õ�Բ�ĵ㡣
	//! \param pntCenter [out] �õ���Բ�ĵ㡣
	//! \return Arc�Ƿ�,����false
	UGbool GetCenterPoint(UGPoint2D &pntCenter) const;    
	
	//! \brief �õ�Բ���İ뾶��
	//! \param dRadius [out] �õ��İ뾶��
	//! \return Arc�Ƿ�,����false
	UGbool GetRadius(UGdouble &dRadius) const;    
	
	//! \brief �õ���ʼ�Ƕȡ�
	//! \param dStartAngle [out] �õ�����ʼ�Ƕȡ�
	//! \return Arc�Ƿ�����false��
	UGbool GetStartAngle(UGdouble &dStartAngle) const;	
	
	//! \brief �õ���ֹ�Ƕȡ�
	//! \param dEndAngle [out] �õ�����ֹ�Ƕȡ�
	//! \return Arc�Ƿ�����false��
    UGbool GetEndAngle(UGdouble &dEndAngle) const;

	//! \brief �ж��Ƿ���ʱ��
	//! \return ��ʱ�뷵��true, ˳ʱ�뷵��false
	UGbool IsCounterClockwise();
	
	//! \brief �õ�Բ�ĺͰ뾶��
	//! \param pntCenter [out] �õ���Բ�ġ�
	//! \param &dRadius [out] �õ��İ뾶��
	//! \return Arc�Ƿ�����false��
	UGbool Get(UGPoint2D &pntCenter, UGdouble &dRadius) const;    
	
	//! \brief һ�εõ�Բ��,�뾶,��ʼ�ǶȺ���ֹ�Ƕȡ�
	//! \param pntCenter [out] �õ���Բ�ġ�
	//! \param dRadius [out] �õ��İ뾶��
	//! \param dStartAngle [out] �õ�����ʼ�Ƕȡ�
	//! \param dEndAngle [out] �õ�����ֹ�Ƕȡ�
	//! \return Arc�Ƿ�����false��
	UGbool Get(UGPoint2D &pntCenter, UGdouble &dRadius, UGdouble &dStartAngle,
				UGdouble &dEndAngle) const;    
	
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
	//! \return  ���ظ����������
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
	void CalAssistantPoints(const UGPoint2D* pPoints,UGint nPntCount,UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,UGEditType::EditToolShape nEditType);

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
	
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
	
private:
	//! \brief ��ʼ��
	UGPoint2D m_pntStart;
	//! \brief �м��
	//! \remarks ��һ�������м�ĵ�, ��Բ����, ��ʼ�����ֹ��֮��������,��������Ϊ�м��
	//! ��Ϊ�м����Բ����, ��ʼ�����ֹ��֮�� ���ƶ�����Ӱ�� Բ��
	UGPoint2D m_pntMiddle;
	//! \brief ��ֹ��
	UGPoint2D m_pntEnd;
};

}



#endif 
