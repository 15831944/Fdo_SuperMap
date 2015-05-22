/*! \file	 UGGeometry.h
 *  \brief	 ���ζ������
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 */


#ifndef UGGEOMETRY_H
#define UGGEOMETRY_H

#include "Algorithm/UGRect2D.h"

#include "Base/UGStyle.h"
#include "Base/UGAutoPtr.h"

#include "Project/UGPrjCoordSys.h"
#include "Project/UGPrjTranslator.h"
#include "Project/UGRefTranslator.h"
#include "Geometry/UGDataCodec.h"
#include "Geometry/UGEditType.h"

namespace UGC {

class UGGeoLine;
class UGGeoRegion;

//added by xielin ^_^
#define  BOUND_HANDLE                   9      //�̶������Ŀ
//added by xielin ^_^ end

//! \brief ���ζ������ 
class GEOMETRY_API UGGeometry  
{
public:
	//! \brief ���ζ������Ͷ���
	//! \remarks UGC 2.0�汾֧�ֵ�Geometry���Ͱ���:
	//!  GeoPoint,GeoLine,GeoRegion,GeoText
	//!  GeoMultiPoint,GeoLineM,GeoCompound,
	//!  GeoRect,GeoRectRound,
	//!  GeoCircle,GeoEllipse,GeoPie,GeoArc,GeoEllipticArc,
	//!  GeoCardinal,GeoCurve,GeoBSpline
	//!  ���������ݲ�֧��
	enum Type
	{
		//! ������
		Null				= 0, 
		//! ������	
		GeoPoint			= 1, 
		//! ������
		GeoLine				= 3, 
		//! ������
		GeoRegion			= 5, 
		//! �ı�����
		GeoText				= 7, 
		
		//GeoRect			=11,	//����
		//! ���κ�б����ͳһΪ����ת�ǵľ���
		GeoRect				=12,
		//! ����������ϵ����(������Mֵ��GeoLine)
		GeoLineM			=35,   

		//! Ӱ���, ��ΪUGImgBlock, 
		GeoImageBlock		=81,	
		//! ͼ��, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoIcon				=87,	
	
		//! ���϶���, ��ֵͬʱ����Geometry�������͵�����
		GeoCompound			=1000,	
#if PACKAGE_TYPE==PACKAGE_UGC
		
		//! ���ϵ�
		GeoMultiPoint		= 2, 
			
		// modified by zengzm 2005-09-05 SFC�о�û�� ����Բ�Ǿ���, type id==13 ���� ����ת�ǵ�Բ�Ǿ���
		// Ϊ�������, ��Ϊ ԭ���� 13 
		//RectRound			=13,	//Բ�Ǿ���
		//GeoRectRound		=14,	//Բ�Ǿ��κ�бԲ�Ǿ���ͳһΪ����ת�ǵ�Բ�Ǿ���
		//! ����ת�ǵ�Բ�Ǿ���
		GeoRectRound		=13,	
		//! Բ
		GeoCircle			=15,	
		//! �ȱ���, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoEquilateral		=17,	
		//Ellipse			=19,	//��Բ
		//! ��Բ��б��ԲͳһΪ����ת�ǵ���Բ
		GeoEllipse			=20,	
		//! ��Բ����
		GeoPie				=21,	
		//! ��, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoChord			=23,	//a closed figure bounded by the intersection of an ellipse and a line segment.
		//! Բ��
		GeoArc				=24,	
		//! ��Բ��
		GeoEllipticArc		=25,	
		//! Cardinal����,��֤����һ��ͨ�����Ƶ�
		GeoCardinal			=27,	
		//! ���� for dgn,��������ѧ���������������͵�����,�㲻̫�����
		GeoCurve			=28,	
		//! ��Ҷ˹����
		GeoBSpline			=29,	
		//! Բ��, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoDonut			=31,	
		//! ������, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoTraverse			=33,	
		//! ��һ��, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoLwpline			=34,	
		//! for Survey, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoPath				=41,	//
		//! ��ά��, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoPointZ			=101,	
		//! ��ά���, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoMultiPointZ		=102,	
		//! ��ά��, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoLineZ			=103,	
		//! ��ά��, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoRegionZ			=105,	
		//! ��ά�ı�, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoTextZ			=107,	
		//! ������, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoTriangle			=109,	
		//! ������, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoCube				=111,	
		//! ������, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoTraverseZ		=133,	
		//! ��Ҷ˹����, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoBSurface			=135,	
		//! ������, �ݲ��ṩ, ��Ҫ���ų�ȥ
		GeoPolyhedron		=137,	
		//! ������������, Tin
		GeoTinBlock			=139	
#endif // end declare ugc sdk
	};
	
	//! \brief GML�汾��Ϣ����
	enum GMLVersionType
	{
		SML = 0,	//supermap�Զ����ʽ
		GML212		= 212,	//GML2.1.2�汾
		GML310		= 310,	//GML3.1.0�汾
		GML311		= 311	//GML2.1.1�汾
	};

public: //! �������������
	//! \brief ���캯��
	UGGeometry();
	
	//! \brief ��������
	virtual ~UGGeometry();
	
public: //! �õ�������һЩ��Ϣ
	
	//! \brief ��յ�������
	virtual void Clear() =0;
	
	//! \brief �õ�ά��, ��Ϊ0ά, ��/���ߵ�Ϊ1ά, ��/�����Ϊ2ά, GeoCompound/GeoText��Ϊ-1
	virtual UGint GetDimension() const = 0;
	
	//! \brief �õ�����
	virtual Type GetType() const = 0;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \return �����ڵ�
	virtual UGPoint2D GetInnerPoint() const = 0;
	
	
	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ�����ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const = 0;	
	
	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid() const = 0;
	
	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const = 0;
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY) = 0;
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y������ͬ)
	virtual void Inflate( UGdouble dRatio) = 0;
	
	//! \brief ƽ��
	//! \param dX ƽ�Ƶ�Xƫ����
	//! \param dY ƽ�Ƶ�Yƫ����
	virtual void Offset( UGdouble dX, UGdouble dY) = 0;
	
	//! \brief ƽ��
	//! \param ƫ����(X,Y������ͬ)
	virtual void Offset( UGdouble dOffset) = 0;
	
	//! \brief ƽ��
	//! \param ƽ�Ƶ�ƫ����(�ֱ���UGSize2D�е�x,y����X,Y�����ƫ����)
	virtual void Offset( const UGSize2D &szOffset) = 0;
	
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
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle,double dAngle = 0) = 0;
	
	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds) = 0;

	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
public:
	//! \brief �õ���������
	//! \remarks ������ز�Ϊ�գ��������ʹ�ú�delete
//	virtual UGGeoLine* GetInnerLine() const;
	
// 	//! \brief �õ������ܳ�
// 	//! \attention DimensionΪ2�Ķ����֧��
// 	//! \return ���ض����ܳ�
// 	virtual UGdouble GetPerimeter() const;
	
	//! \brief �õ��������
	//! \attention DimensionΪ2�Ķ����֧��
	//! \return �������
	virtual UGdouble GetArea() const;
	
	//! \brief �õ����󳤶�
	//! \attention DimensionΪ1or2�Ķ����֧��
	//! \return ���س���
	virtual UGdouble GetLength() const;
	
	//! \brief �õ��Ӷ���ĸ���
	//! \return �����Ӷ���ĸ���
	virtual UGint GetSubCount() const;

public:
	//Projection..

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

public: //! �洢���ⲿ������,���ߴ��ⲿ����������
	
	//! \brief �õ�ID
	//! \return ����ID
	UGint GetID() const;
	
	//! \brief ����ID
	//! \param Ҫ���õ�ID
	void SetID( UGint nID );
	
	//! \brief �õ���Ӿ���
	//! \return ������Ӿ���
	const UGRect2D& GetBounds() const;
	
	//! \brief ������Ӿ���,һ�㲻Ҫʹ��, �ڲ���ά��Bounds����ȷ��
	//! \param rcBounds Ҫ���õ�Bounds
	void SetBounds( const UGRect2D& rcBounds );
	
	//! \brief ���÷��
	//! \param pStyle ���ָ��
	//! \remarks ���pStyle==NULL,��Geometry�ڲ����ָ�뱻ɾ��; ����Ḵ��һ�ݷ��
	//! �����ı������, ���÷��������,��Ϊ�ı��������Լ���TextStyle
	virtual void SetStyle(const UGStyle* pStyle);

	//! \brief �õ��������ָ��,���û�з���NULL
	//! \return ���ط���ָ��,�п���ΪNULL
	UGStyle* GetStyle() const;

public:
	//! \brief ����Geometry�����еĳ�Ա����, ����ID, Style, Bounds��
	//! \param geo �ṩ��Ϣ��Gemetry
	void CopyBaseData(const UGGeometry& geo);
	
	//! \brief ���浽�洢����
	//! \param stream �洢�õ���, ����֮ǰӦ����Open
	//! \param eCodecType �洢�ı��뷽ʽ
	//! \param bIgnoreStyle �Ƿ���Զ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	UGbool Save(UGStream& stream, UGDataCodec::CodecType eCodecType=UGDataCodec::encNONE, 
			UGbool bIgnoreStyle = TRUE) const;
	
	//! \brief ������װ������
	//! \param stream ��
	//! \remarks Loadʱ,���ںܶ���Ϣ�Ѿ��洢��stream����,���Դ洢������Ƿ񱣴���Ȳ����Ͳ���Ҫ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	UGbool Load(UGStream& stream);

public:
//	UGdouble GetMaxZ();
//	void SetMaxZ(UGdouble z);
//	UGdouble GetMinZ();
//	void SetMinZ(UGdouble z);
	
	// zengzm 2005.8.16 ��SDBPlus����,���ò�public֮
	//! \brief ֻ���漸�����ݲ���
	//! \param stream �洢��, ����֮ǰӦ����Open
	//! \param eCodecType �洢�ı��뷽ʽ
	//! \param bSDBPlus �Ƿ�洢ΪSDBPlus�ĸ�ʽ
	//! \remarks ����SDBPlus��������ݿ�����Ĵ洢�ϲ��ϴ�,���Ա���ֱ�ӵ��øú���,
	//! �����ӱ������зֱ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool SaveGeoData(UGStream& stream, 
		UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const = 0;

	//! \brief ֻת�ؼ������ݲ���
	//! \param stream �� 
	//! \param eCodecType ���뷽ʽ
	//! \attention ����Ҫ���� UGbool bSDBPlus = FALSE �Ĳ���
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool LoadGeoData( UGStream& stream , 
		UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE ) = 0;
	
	//! \brief ת��Ϊ�߶���
	//! \param geoLine[out] �õ����߶���
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;
	
	//! \brief ת��Ϊ�����
	//! \param geoRegion[out] �õ��������
	//! \param nSegmentCount ������ת��Ϊ��ʱ,ÿһ���ö��ٸ�����ģ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;

public:
#if PACKAGE_TYPE==PACKAGE_UGC

	//! \brief ����XML��ʽ����Ϣ
	/*֧��
		SML,	//supermap�Զ����ʽ
		GML212,	//GML2.1.2�汾
		GML310,	//GML3.1.0�汾
		GML311��//GML2.1.1�汾
		����GML212��֧��GeoPoint��GeoLine��GeoRegion��GeoMultiPoint
	*/
	//! \param versionType GML�İ汾
	//! \param nPace �����Ŀո���Ŀ,ʹ��xml�ַ������������˹��Ķ�; 
	//! ��Ҫ����������ص�xml�ַ�����һ�����ǩ�е�һ����, ͨ��ָ���ո���Ŀ,����ʹ�������
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0)  const = 0;
	
	//! \brief ��XML�ַ���������Geometry
	//! \param strXML xml��ʽ�ַ���
	//! \param versionType xml�ַ�����GML�汾
	//! \return ����ָ��GML�汾��xml�ַ���
	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType) = 0;

#endif // end declare ugc sdk	

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
	 virtual void MoveHandle( UGint nHandle, const UGPoint2D& pnt2D,
				 UGEditType::EditToolShape nEditType=UGEditType::ET_None);

	//! \brief �ڵ�༭ʱ����������һ�����Ƶ�,Ҳ�������ڻ��ƶ���ʱ����ڵ�
	//! \param nHandle ����λ��
	//! \param pnt2D �����ĵ�������
	virtual void AddHandle( UGint nHandle, const UGPoint2D& pnt2D,
				UGEditType::EditToolShape nEditType=UGEditType::ET_None);
	
	//! \brief ɾ���༭�����ָ���ڵ�
	//! \param nHandle �ڵ���
     virtual UGuint DelNode( UGint nHandle );

	//! \brief ����������ʱ�ĸ����ߣ����ص���һ�����϶���
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	//! \param pStyle	 �����ߵķ���������ΪNULL����Ĭ�ϵķ��
     virtual UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,
				UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);


	//! \brief ����������ʱ�ĸ����㣬���ص��ǵ����Ŀ,
	//! nHandleType���ص��Ǹ����������,�ο�UGEditType::EditHandleType
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param eAssistantPoints �㴮,���صĸ�����㴮
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	 virtual void CalAssistantPoints(const UGPoint2D* pPoints, UGint nPntCount,
				UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,
				UGEditType::EditToolShape nEditType);

	 //! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	 //! Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�
	 //! ����GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ� 
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
     virtual void MakeWithPoints(UGPoint2D* pPoints,UGint nPntCount,
				UGEditType::EditToolShape nEditType=UGEditType::ET_None);

	//! \brief ��ȡ������Ҫ��׽�ĵ㴮
	//! \param aryPnts �㴮������ȥ��Ҫ��׽�ĵ㴮
	//! \return �����true��ʾ����Ҫ��׽�ĵ㴮���������false��ʾ�ö���û����Ҫ��׽�ĵ㴮
	virtual UGbool GetSnapPoints(UGArray<UGPoint2D>& aryPnts);

	//! \brief ��ȡ������Ҫ��׽���߶�����
	//! \param aryLines ��Ҫ��׽�������飨����ж��part����ôaryLines��Ӧ���ж��ٸ�count��
	//! \return �����true��ʾ����Ҫ��׽���ߣ��������false��ʾ�ö���û����Ҫ��׽����
	virtual UGbool GetSnapLines(UGLineArray& aryLines);

	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end

	//! \brief ���ü��ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���,ֻset����ת���ַ�������
	virtual void SetTextCharset(UGTextCodec::Charset nCharset);

	//! \brief �ı伸�ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���,ת���ַ�������
	virtual void ChangeTextCharset(UGTextCodec::Charset nCharset);

protected:
	
	//! \brief ��������Bounds
	//! \return ���صõ���Bounds
	virtual UGRect2D ComputeBounds() const = 0;
	
	//virtual UGRect2D GetBoundsInside() const = 0;
	
	// modified by zengzm 
	//virtual void SetBoundsInside( const UGRect2D & rcBounds ) = 0;

	//! \brief		�ж�Bounds�Ƿ�����
	//! \return		�������, ����true; ���෵��false
	UGbool IsBoundsDirty() const;

	//! \brief		����Bounds�Ƿ�����
	//! \param		bBoundsDirty	Bounds�Ƿ���, Ĭ��Ϊ������
	void SetBoundsDirty(UGbool bBoundsDirty=true);
	
protected:
	//! \brief ���ζ���ID��Ĭ��Ϊ0
	UGint m_nID;
	
	//! \brief ���ζ����Դ����Ĭ��ΪNULL
	UGStyle* m_pStyle;
	
	// modified by zengzm 2005-8-24 �ŵ� private ��, ������ SetBoundsDirty
	//! \brief ���ζ����ڲ��洢��Bounds�Ƿ��Ѿ����ˣ���ʵ�����ݲ���ͬ�ˣ�
	//UGbool m_bBoundsDirty;
	
	//! \brief ���ζ���BOUNDs
	UGRect2D m_rcBounds;

private:
	//! \brief ���ζ����ڲ��洢��Bounds�Ƿ��Ѿ����ˣ���ʵ�����ݲ���ͬ�ˣ�
	UGbool m_bBoundsDirty;
};

}

#endif // !defined(AFX_UGGEOMETRY_H__8844E5E9_172A_4931_913C_5B1322A02D82__INCLUDED_)
