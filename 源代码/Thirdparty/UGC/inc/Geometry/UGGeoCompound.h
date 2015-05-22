#ifndef UGGEOCOMPOUND_H
#define UGGEOCOMPOUND_H

#include "UGGeometry.h"

namespace UGC {

//! \brief ���϶���
//! \remarks ���϶���ʹ�������ģʽ�е�"�ۺ�ģʽ",�����԰��������⼸�ζ���(�������϶�����)�ۺ���һ��,
//! �γ�һ����״�Ľṹ;ֵ��ע�����,�����϶���ۺϵļ��ζ��������ָ�����ʽ,��֮��͹鸴�϶����������ڴ���.
class GEOMETRY_API UGGeoCompound : public UGGeometry
{
public:
	//! \brief ���캯��
    UGGeoCompound();
	//! \brief ��������
    virtual ~UGGeoCompound();
	
public: //pure virtual 
	
	//! \brief ��յ�������
	virtual void Clear();
	
	//! \brief �õ�ά��,�̶�Ϊ-1
	virtual UGint GetDimension() const;

	//! \brief �õ�����,�̶�ΪGeoCompound
	virtual Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \remarks �ڵ�Ϊ�����м�˳��(�����м�λ��)�ļ��ζ�����ڵ�
	//! \return �����ڵ�
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief �õ��������
	//! \return �������
	virtual UGdouble GetArea() const;
	
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
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
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
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator ͶӰת����
	//! \param bForward ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual void PJConvert( UGRefTranslator *pRefTranslator, UGbool bForward = true);
	
	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJForward( UGPrjCoordSys *pCoordSys );

	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );
	
public:

	
	//! \brief ���ƹ��츴�϶���
	//! \param geoCompound [in] ���еĸ��϶���
	//! \return ���и��϶���Ƿ�,����false��
	UGbool Make(const UGGeoCompound& geoCompound);	
	
	//! \brief ����һ�����ζ���
	//! \param pGeometry [in] ���ζ���ָ�롣
	//! \param bByDimension [in] ���bByDimensionΪtrueʱ,��������������ӵļ��ζ�������ж����ס
	//!			ֱ���ҵ�һ����ά�����Ҳ��ᱻ�����Ӷ�����ȫ���ǵĶ���Ϊֹ,����ֱ����ײ㡣
	//! \return �����ӵļ��ζ���ָ�벻ΪNULL,����true��
	UGbool AddCompound(UGGeometry *pGeometry, UGbool bByDimension = TRUE);    
	
	//! \brief ��ָ����λ�����ý�϶���
	//! \param nIndex [in] ָ����λ��������
	//! \param pGeometry [in] ���ζ���ָ�롣
	//! \return ���ζ���ָ�벻ΪNULL,����true��
	//! \remarks ָ��λ����ԭ�еļ��ζ��󽫱�delete����
	UGbool SetCompound(UGint nIndex, UGGeometry *pGeometry);    
	
	//! \brief ��ָ����λ�ò���һ�����ζ���
	//! \param nIndex [in] ָ����λ��������
	//! \param pGeometry [in] ���ζ���ָ�롣
	//! \return ���ζ���ָ�벻ΪNULL,����true��
	UGbool InsertCompound(UGint nIndex, UGGeometry *pGeometry);    
	
	//! \brief �Ƴ�(��delete)ָ��λ�õ��Ӷ���
	//! \param nIndex [in] ָ����λ��������
	//! \return �����Ƿ�,����false��
	UGbool RemoveGeometry(UGint nIndex);    
	
	//! \brief �����Ӷ���Bounds�Ĵ�С���������и��϶����и����Ӷ��������˳��
	//! \param bMoveUptheMinObj [in] Ϊtrueʱ,С����������;ΪfalseʱС���������档
	void Adjust(UGbool bMoveUptheMinObj = true);    
	
	//! \brief �õ�ָ��λ�õ��Ӷ���(Ҳ��Geometry)ָ�롣
	//! \param nIndex [in] ָ����λ��������
	//! \return �Ӷ���ָ��, λ�÷Ƿ�ʱ,����NULL��
	UGGeometry *GetGeometry( UGint nIndex );	

	//! \brief �õ�ָ��λ�õ��Ӷ���(Ҳ��Geometry)ָ�롣
	//! \param nIndex [in] ָ����λ��������
	//! \return const�����Ӷ���ָ��,���治���޸�, λ�÷Ƿ�ʱ,����NULL��
    const UGGeometry *GetGeometry( UGint nIndex ) const;
	
	//! \brief �ֽ⸴�϶���
	//! \param arrGeometry [out] �ֽ��õ����Ӷ��������
	//! \param bToLeaf �Ƿ�ֽ⵽Ҷ����, Ĭ��Ϊfalse
	//! \remarks ���϶�����һ����, ������ֽ⵽Ҷ����, �򴫳���arrGeometry��Ȼ���ܴ��ڸ��϶���(��Ҷ)
	//  ���bToLeaf =true, �򴫳���arrGeometry�п϶�û�� ���϶���
	//! \attention ȡ�����ļ��ζ���ָ������, ��Щָ����Ȼ��ָ��GeoCompound�ڲ����ڴ��ַ, ����ʹ�ú�Ҫdelete;
	//! ��GeoCompound�����仯(������Ӷ���,������յ�)��,��Ҫ��ʹ����Щָ��,��Ϊ�п���ΪҰָ��
	UGbool Divide(UGArray<UGGeometry *> &arrGeometry, UGbool bToLeaf=false);

	//! \brief ת��Ϊ�����
	//! \param geoRegion [out] �õ��������
	//! \param nSegmentCount [in] ����������ÿ�εĲ�ֵ�ĵ�����
	//! \return ���������Ӷ���ɹ�,����true��
	//! \remarks �ڲ�ʵ�־��ǰ�GeoCompound�е�ÿһ���Ӷ���ת��ΪRegion,�ټ��뵽geoRegion���ò����С�
	virtual UGbool ConvertToRegion( UGGeoRegion &geoRegion, UGint nSegmentCount = 0 ) const;		
	
	//! \brief ת��Ϊ�߶���
	//! \param geoLine [out] �õ����߶���
	//! \param nSegmentCount [in] ����������ÿ�εĲ�ֵ�ĵ�����
	//! \return �߶�������Ӷ���ɹ�,����true��
	//! \remarks �ڲ�ʵ�־��ǰ�GeoCompound�е�ÿһ���Ӷ���ת��ΪLine,�ټ��뵽geoLine���ò����С�
	virtual UGbool ConvertToLine( UGGeoLine &geoLine, UGint nSegmentCount = 0 ) const;	

#if PACKAGE_TYPE==PACKAGE_UGC
public:			
	//! \brief ��GeoCompound�в�Ϊ�����ε��ߺ���״���ζ�����뵽�����Ͳ��С�
	//! \param geoLine [out] ȡ�����ݵ��߶���
	//! \param nSegmentCount [in] ����ת��Ϊ��,ÿһ�εĲ�ֵ������
	//! \return �����Ӷ���ɹ�,����true��
	UGbool GetLine(UGGeoLine &geoLine, UGint nSegmentCount) const;    

	//! \brief ��GeoCompound����������ΪGeoRegion���Ӷ������ӵ������Ͳ����з��ء�
	//! \param geoRegion [out] ��GeoCompound��ȡ������ΪGeoRegion�������Ͳ�����
	//! \return �Ӷ������ӳɹ�,����true��
	UGbool GetRegion(UGGeoRegion &geoRegion) const;    

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

	//! \brief ���ü��ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���
	virtual void SetTextCharset(UGTextCodec::Charset nCharset);

	//! \brief �ı伸�ζ������ַ�����Charset,��Ҫ����ı����󣬸��϶����е��ı��ַ���,ת���ַ�������
	virtual void ChangeTextCharset(UGTextCodec::Charset nCharset);

#endif // end declare ugc sdk
protected:
	
	virtual UGRect2D ComputeBounds() const;
	
	//virtual UGRect2D GetBoundsInside() const;
	
	//virtual void SetBoundsInside( const UGRect2D & rcBounds );
	
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );
	
private:
	//! \brief ������ż��ζ���(��Ϊ�Ӷ��󿴴�)ָ�������
	UGArray< UGGeometry* > m_GeometryArray;
};

}



#endif 
