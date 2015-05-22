// UGGeoLineM.h: interface for the UGGeoLineM class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOLINEM_H__4D04C30B_CF4B_411E_A107_6ABEE27A07C7__INCLUDED_)
#define AFX_UGGEOLINEM_H__4D04C30B_CF4B_411E_A107_6ABEE27A07C7__INCLUDED_

#include "UGGeometry.h"
#include "Algorithm/UGPoint3D.h"

namespace UGC {

#define UG_NO_MEASURE -9999 //��ֵ����

//! \brief GeoLineM����(·�ɶ���),��GeoLine����������������ÿ���㶼��һ��Mֵ,�������Measure�ĺ���
//! \remarks GeoLineM�����ڲ��õ���Point3D,����z������M; GeoLineM��Ҫ���ڶ�̬�ֶκ������������ı��
class GEOMETRY_API UGGeoLineM : public UGGeometry  
{
public:
	//! \brief ���캯��
	UGGeoLineM();
	//! \brief ��������
	virtual ~UGGeoLineM();
	
public:
	//! \brief ��յ�������
	virtual void Clear();
	
	//! \brief �õ�ά��, �̶�Ϊ1
	//! \return �õ�ά��,�̶�Ϊ1
	virtual UGint GetDimension() const;

	//! \brief �õ�����, �̶�Ϊ GeoLineM
	virtual Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \remarks Ϊ���������Ӷ��� ���м��(�м�����ĵ�, �������м����ĵ�)
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief �õ����󳤶�
	//! \return ���س���	
	virtual UGdouble GetLength() const;
	
	//! \brief �������, ���ڶ����ѡ
	//! \param pntHitTest ��������ѡ�еĵ�
	//! \param dTolerance ����
	//! \return ѡ�з���true, ���򷵻�false
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
	//! \brief �õ��ռ�����, ��Ҫ������Ҫ����ά����ͬʱ
	//! ����ͳһ�����ʱ��, ����һЩ�ռ��жϺͲ������㷨
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual UGbool GetSpatialData( UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief �õ��Ӷ���ĸ���
	//! \return �����Ӷ���ĸ���
	virtual UGint GetSubCount() const;
	
	//! \brief ���ζ����Ƿ���Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid()const;
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	//! \param dRatioM Mֵ�����ű���
	void Inflate(UGdouble dRatioX, UGdouble dRatioY, UGdouble dRatioM);
	
	//! \brief ����
	//! \param dRatioX X�������ű���
	//! \param dRatioY Y�������ű���
	//! \remarks M������
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief ����
	//! \param dRatio ���ű���(X,Y,M��ͬ)
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
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, UGdouble dAngle = 0);
	
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
	
	//! \brief ��������GeoLineM
	//! \param geolineM [in] ����LineM����
	//! \return �����߶���Ƿ�, ����false��
	UGbool Make( const UGGeoLineM& geoLineM);
	
	//! \brief ����һ���Ӷ����GeoLineM
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�ĵ���Ŀ��
	//! \return ����С��2��,����false��
	UGbool Make( const UGPoint3D* pPoints, UGint nPntCount );
	
	//! \brief �������Ӷ���ĸ���GeoLineM
	//! \param pPoints [in] �㴮ָ�롣
	//! \param pPolyCount [in] �Ӷ����е��������顣
	//! \param nSubCount [in] �Ӷ�����Ŀ��
	//! \return �����Ӷ���ĵ�����С��2��,����false��
	UGbool Make( const UGPoint3D* pPoints, const UGint* pPolyCount, UGint nSubCount );
	
	//! \brief ���������һ���Ӷ���
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�ĵ���Ŀ��
	//! \return �㴮����С��2��, ����false��
	UGbool AddSub( const UGPoint3D* pPoints, UGint nPntCount );
	
	//! \brief �����Ӷ���
	//! \param nIndex [in] Ҫ�����λ��������
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPntCount [in] �㴮�е�ĸ�����
	//! \return �����С��2��������λ�÷Ƿ�,����false��
	UGbool InsertSub(UGint nIndex, const UGPoint3D* pPoints, UGint nPntCount);
	
	//! \brief ɾ���Ӷ���
	//! \param nIndex [in] Ҫɾ�����Ӷ����λ��������
	//! \return �����Ƿ�, ����false��
	UGbool DelSub( UGint nIndex );
	
	//! \brief ��ָ����λ�������õ�����ꡣ
	//! \param nIndex [in] λ��������
	//! \param point [in] �����ꡣ
	//! \return �����Ƿ�, ����false��
	//! \remarks �����Ӷ���ĵ���һ�������������, ������û�������Ӷ���, ��ͷ��ʼ����������
	UGbool SetPoint( UGint nIndex, const UGPoint3D& point );
	
	//! \brief �õ��Ӷ�����Ŀ������ָ�롣
	//! \return �����Ӷ�����Ŀ������ָ�롣
	const UGint* GetPolyCounts() const;
	
	//! \brief �õ�ĳ���Ӷ���ĵ�ĸ�����
	//! \param nSubIndex [in] �Ӷ���������
	//! \return ����ĳ���Ӷ���ĵ�ĸ�����
	UGint GetSubPntCount(UGint nSubIndex) const;
	
	//! \brief �õ������Ӷ���ĵ�ĸ����ܺ͡�
	//! \return ���������Ӷ���ĵ�ĸ����ܺ͡�
	UGint GetPointCount() const;
	
	//! \brief �õ�ָ���Ӷ���ĵ㴮��ָ�롣
	//! \param nSubIndex [in] �Ӷ���������
	//! \return �����Ӷ���ĵ㴮��ָ�롣
	const UGPoint3D* GetPoints(UGint nSubIndex=0) const;
	
public:
	//! ��μ���Mֵ��ö��
	enum UGHowToComputeMeasure
	{
		//! ֻ�������֮ǰ��Section
		ExtropolateBefore = 1,   
		//! ֻ�����յ�֮���Section
		ExtropolateAfter  = 2,   
		//! �ڲ�����֮��Ŀ��Ƶ�
		Interpolate		= 5    
	};

	//! �����Ե�ö��
	enum UGMonotonicStyle
	{
		//! ��������
		MeasureAscending   = 0,   
		//! �����ݼ�
		MeasureDescending	 =1,    
		//! �ǵ���
		MeasureNotMonotonic=2     
	};

	enum UGCalibrateBy
	{
		//! ���������
		ByDistance = 1,		
		//! ���߱����
		ByMeasure  = 2		
	};
	
	/*! \brief �ڲ�Measure
	*  \param nFromIndex   ��ʼ������
	*  \param nToIndex     ��ֹ������
	*  \param nFromSubObjID ��ʼ�Ӷ���ID
	*  \param nToSubObjID   ��ֹ�Ӷ���ID
	*  \param bIgnoreGap    �Ƿ�����Ӷ���֮��ļ��
	*  \return �ڲ����ɹ�����True,���򷵻�False
	*  \remarks 
	1�����nFromSubObjIDС��nToSubObjID,��������ʼ����ֹ�Ӷ����ID������
	Ҳ����˵����С��ID������Ϊ��ʼ����
	2�������ʼ�Ӷ������ֹ�Ӷ���֮������ж���������β������������԰�
	������Ϊһ�������ڲ塣����������bIgnoreGap�Ƿ�Ϊ�棬������������Ӷ���֮���ڲ塣
	3��Ŀǰ����ֻ���������Ӷ���������β���������������Ӷ���֮���м������ʱ������
	*/
    UGbool InterpolateMeasure(UGuint nFromIndex,
		UGuint nToIndex,
		UGuint nFromSubObjID =0,UGuint nToSubObjID =0);
	
	/*! \brief ����Measure
	*  \param nExtropolateStyle   ���Ʒ�ʽ
	*  \param nFromIndex   ��ʼ������
	*  \param nToIndex     ��ֹ������
	*  \param nFromSubObjID ��ʼ�Ӷ���ID
	*  \param nToSubObjID   ��ֹ�Ӷ���ID
	*  \param bIgnoreGap    �Ƿ�����Ӷ���֮��ļ��
	*  \return ���Ƽ���ɹ�����True,���򷵻�False
	*  \remarks
	1�����nFromSubObjIDС��nToSubObjID,��������ʼ����ֹ�Ӷ����ID������
	Ҳ����˵����С��ID������Ϊ��ʼ����
    2�������ʼ�Ӷ������ֹ�Ӷ���֮������ж���������β������������԰�
	������Ϊһ�������ڲ塣����������bIgnoreGap�Ƿ�Ϊ�棬������������Ӷ���֮���ڲ塣
	*/
	UGbool ExtrapolateMeasure(UGuint nFromIndex,UGuint nToIndex ,
		UGHowToComputeMeasure nExtropolateStyle = ExtropolateBefore,
		UGuint nFromSubObjID =0,UGuint nToSubObjID =0);
	
	/*! \brief ���¼����߱�
	  *  \param nFromIndex   ��ʼ������
	  *  \param nToIndex     ��ֹ������
	  *  \param dFromM
	  *  \param dToM 
	  *  \param nHowToComputeMeasure
	  *  \param nCalibrateBy
	  *  \param nFromSubObjID ��ʼ�Ӷ���ID
	  *  \param nToSubObjID   ��ֹ�Ӷ���ID
	  *  \param bIgnoreGap    �Ƿ�����Ӷ���֮��ļ��
	  *  \return ���Ƽ���ɹ�����True,���򷵻�False
	  *  \remarks
	  1�����nFromSubObjIDС��nToSubObjID,��������ʼ����ֹ�Ӷ����ID������
	  Ҳ����˵����С��ID������Ϊ��ʼ����
	  2�������ʼ�Ӷ������ֹ�Ӷ���֮������ж���������β������������԰�
	  ������Ϊһ���������㡣����������bIgnoreGap�Ƿ�Ϊ�棬������������Ӷ���֮���ڲ塣
	*/
	UGbool UpdateMeasure(UGuint nFromIndex,UGuint nToIndex ,
					   UGdouble dFromM,UGdouble dToM, 	
					   UGHowToComputeMeasure nHowToComputeMeasure = Interpolate,
					   UGCalibrateBy nCalibrateBy = ByDistance,
					   UGuint nFromSubObjID =0,UGuint nToSubObjID =0);
	
	/*! \brief �߱�ƽ��
	*  \param dOffset   ƽ����
	*  \return 
	*  \remarks
	*/
	void OffsetMeasure(UGdouble dOffset);	  
	
	/*! \brief �Ӿ���õ��߱�
	*  \param  dDistance ���߶����ľ���
	*  \param  nSubObjID �Ӷ���ID
	*  \param  bIgnoreGap �Ƿ�����Ӷ���֮��ļ��
	*  \return �߱�
	*  \remarks
	*/
	UGdouble GetMAtDistance(UGdouble dDistance, UGuint nSubObjID = 0);
	
	/*! \brief  ���ݾ��������߱�
	*  \param pntOrigin   ��ʼԭ��
	*  \param dOffset     ƫ����
	*  \param dScale      �������� 
	*  \param bIgnoreGap  �Ƿ�����Ӷ���֮��ļ��
	*  \return
	*  \remarks  ԭ��pntOriginָ���˾��������λ�á���������߱궼�Ժ�ԭ�����̾�������
	*/
	void SetMAsDistance(UGdouble dOffset =0,UGdouble dScale = 1.0);
	
	/*! \brief   ���߱�õ�����
	*  \param   dMeasure    �߱�
	*  \param   nSubObjID   �Ӷ���ID
	*  \param   bIgnoreGap  �Ƿ�����Ӷ���֮��ļ�� 
	*  \return  ����
	*  \remarks
	*/
	UGdouble GetDistanceAtM(UGdouble dMeasure,UGuint nSubObjID = 0);
	
	/*! \brief  ���߱�õ�����
	*  \param  dMeasure  �߱�
	*  \param  dOffset   ����߶εľ���
	*  \param  pIndex    �����֮ǰ���߶ο��Ƶ�����,����ֵ
	*  \return
	*  \remarks һ���߱�����Ӧ���������ܲ�ֹһ��.�������Ӷ���Ĵ洢˳�����β���,���ص�һ����
	*/
	UGPoint2D GetCoordinateAtM(UGdouble dMeasure, UGdouble dOffset = 0.0, UGint* pIndex = NULL);
	
	/*! \brief   ���߱�õ�����
	*  \param   GeoLine	   �������
	*  \param   dFromMeasure  �����߱�
	*  \param   dToMeasure    �յ���߱�
	*  \return
	*  \remarks
	*/
	UGbool GetSubCurveAtM(UGGeoLine& GeoLine,UGdouble dFromMeasure,UGdouble dToMeasure);
	
	/*! \brief   �������߱�λ�ô����߱�ֵ
	*  \param 
	*  \return
	*  \remarks
	*/
	void CaculateNoM();     
	
	/*! \brief   ��ת�߱�
	*  \param 
	*  \return
	*  \remarks
	*/
	UGbool ReversMOrder();      
		
	/*! \brief   �õ�����߱�ֵ
	*  \param 
	*  \return
	*  \remarks
	*/
	UGdouble GetMaxMeasure();
	
	/*! \brief  �õ���С�߱�ֵ
	*  \param 
	*  \return
	*  \remarks
	*/
	UGdouble GetMinMeasure();
	
	/*! \brief   �õ�·�ߵĵ�����
	*  \param  
	*  \return
	*  \remarks
	*/
	UGMonotonicStyle GetMonotonicStyle();
	
	/*! \brief �ϲ��߶��󣬹����һ�������߶���
	*  \param pGeoLineM �ϲ����߶���
	*  \return
	*  \attetion ��δʵ��
	*/
	UGbool Combination(UGGeoLineM *pGeoLineM );

	/*! \brief �ϲ��߶��󣬹����һ�������߶���
	*  \param pGeoLine �ϲ����߶���
	*  \return
	*  \attetion ��δʵ��
	*/
	UGbool Combination(UGGeoLine* pGeoLine);
	
	/*! \brief  ��ת�����Ĵ���
	*  \return
	*  \remarks
	*/
	UGbool Reverse();
	
	//! \brief ȡ����������������(��Բ)����
	//! \param dRadius ����뾶(��λΪǧ��)
	//! \param nDistUnits ����ϵͳ�еľ��뵥λ
	//! \return ���ش��򳤶�
	UGdouble GetRadianDistance(UGdouble dRadius = 6371118, UGint nDistUnits = AU_METER);
	
	//! \brief �õ�ָ������ĵ����ꡣ
	//! \param dDistance [in] ָ���ľ��롣
	//! \return ���ط��������ĵ����ꡣ
	UGPoint2D GetPointAtDistance(UGdouble dDistance, UGbool bIsIgnoreGap = TRUE);	

#if PACKAGE_TYPE==PACKAGE_UGC
public:	
	
	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
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
	void CalAssistantPoints(const UGPoint2D* pPoints,UGint nPntCount,UGArray<UGEditType::EditAssistantPoint>& eAssistantPoints,UGEditType::EditToolShape nEditType);



	 //! \brief ���ݴ���ĵ㴮���ɶ�����Ҫ���ڱ༭�еĲ�������û���ڲ����鱣��㴮�Ķ���
	 //Ҳ�����Զ������,�������ڲ����鱣��㴮�Ķ��󣬸ú���ֱ��return�ȿɣ�����GeoLine
	 //GeoLine�ȶ����ֱ����AddHandle�����ɣ�Ч�ʱȽϸ�,���������ƽ���ߣ�������������
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


#endif // end declare ugc sdk
	
protected: //! ������Ҫʵ�ֵ�һЩ����������
	virtual UGRect2D ComputeBounds() const;
	
	/*virtual UGRect2D GetBoundsInside() const;
	
	virtual void SetBoundsInside(const UGRect2D & rcBounds);*/
	
	//! \brief �洢��Stream��
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE)  const;
	
	//! \brief ��Stream������Geometry
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE ,UGbool bSDBPlus = FALSE);
	
	// ���߶��Ƿ�����
	UGbool IsHasGapBetween(UGuint nFromSubObjID ,UGuint nToSubObjID);
	UGint GetSubIDFromPointID(UGuint nPointID);	

	UGbool UpdateMeasureBefore(UGuint nIndex,UGdouble dMeasure,UGCalibrateBy nCalibrateBy);
	UGbool UpdateMeasureAfter(UGuint nIndex,UGdouble dMeasure,UGCalibrateBy nCalibrateBy);
	UGbool UpdateMeasureInterval(UGuint nFromIndex,UGuint nToIndex,UGdouble dFromM,UGdouble dToM,
		UGCalibrateBy nCalibrateBy);

#if PACKAGE_TYPE==PACKAGE_UGC
	UGString SubLineToSML(int nIndex, int nIndentCount);
	UGString Point3DToSML(const UGPoint3D* pPoints, int nPntCount, int nIndentCount);
	void GetDoubleArry(UGString& str, std::vector<UGdouble>& doubleDataArray );
	void AddSubLineFromSML(const UGString& strSubSml);
#endif // end declare ugc sdk

private:
	//! \brief �����㴮, z�������Mֵ
	UGArray<UGPoint3D> m_Points;
	
	//! \brief ������� �����Ӷ���ĵ�ĸ��� ��Ϣ����������
	UGArray<UGint> m_PolyCounts;

	//! \brief ���Mֵ,Ĭ��Ϊ0
	mutable UGdouble m_dMaxMeasure;
	//! \brief ��СMֵ,Ĭ��Ϊ0
	mutable UGdouble m_dMinMeasure;

	//UGint m_nLineMID;

	//! \brief ������,Ĭ��ΪMeasureNotMonotonic,�ǵ���
	mutable UGMonotonicStyle m_nMeasureMonotonic;
};

}
#endif // !defined(AFX_UGGEOLINEM_H__4D04C30B_CF4B_411E_A107_6ABEE27A07C7__INCLUDED_)
