// UGGeoCurve.h: interface for the UGGeoCurve class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEOCURVE_H__02C1EB1D_1DF5_4285_B810_47F6DF6DEA53__INCLUDED_)
#define AFX_UGGEOCURVE_H__02C1EB1D_1DF5_4285_B810_47F6DF6DEA53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UGGeometry.h"
namespace UGC {

//! \brief ���߶���,������6�����Ƶ㹹��
//! \remarks ��SFC��ֲ����,�洢��SFC���ּ���; �������ѧ�����в����,���ܺ�DGN��ĳ�������Ӧ;
//! �ڲ�������ǿ��Ƶ�, Curve�����ʵ�����߲����������Ƶ�
class GEOMETRY_API UGGeoCurve : public UGGeometry  
{
public:
	//! \brief ���캯����
	UGGeoCurve();	
	//! \brief ����������
	virtual ~UGGeoCurve();
public:

	//! \brief ��յ�������
	virtual void Clear();

	//! \brief �õ�ά��, �̶�Ϊ1ά
	virtual UGint GetDimension() const;
	
	//! \brief �õ�����, �̶�ΪUGGeoCurve
	virtual Type GetType() const;
	
	//! \brief �õ��ڵ㣨��Geometry�ڲ�����������ĵ㣩
	//! \remarks �����Ƿ��ش����м�ƫ��2��λ�õĿ��Ƶ�,ʵ���ϻ�������,�д��Ľ�
	virtual UGPoint2D GetInnerPoint() const;

	//! \brief �õ��ռ�����
	//! \param pPoints �����ĵ���������[out]��
	//! \param pPolyCount ������ÿ���Ӷ�������������[out]��
	//! \param nSubCount �������Ӷ������[out]��
	//! \param nSegmentCount �Բ���������, ÿ�����ηָ��ĸ���[in]��
	//! \remarks ��������������ָ��ļ���,�����߲����ͷ��ڴ�ռ�
	//! \return �ɹ�����true,���򷵻�false��
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;

	//! \brief ���ζ����Ƿ���Ч, ��Curve, ����6���������Ч
	//! \return ��Ч����true,��Ч����false
	virtual UGbool IsValid() const;
	
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
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle,double dAngle = 0);

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

	//! \brief ���㾵��
	//! \param pntMirror1 ���ɾ���ĵ�һ����
	//! \param pntMirror2 ���ɾ���ĵڶ�����
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);

	//! \brief ������������,�޶����µ�Bounds��
	//! \param rcNewBounds �µ�,�޶���Χ��Bounds
	//! \return �ɹ�����true,ʧ�ܷ���false
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

	// �ݲ��ṩ��, ������������Ҳû��;�̶�Ϊ1���Ӷ���
	//UGint GetSubCount() const;

	//! \brief �ڶ��������һ����
	//! \param pntPoint	Ҫ��ӵĵ�
	//! \return ����true
	UGbool Add(const UGPoint2D &pntPoint);
	
	//! \brief ���ӵ㴮��
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPointCount [in] �㴮�ĵ������
	//! \return �㴮ָ��ΪNULL,����false��
	UGbool Add(const UGPoint2D *pPoints, UGint nPointCount);	
	
	//! \brief ����һ���㡣
	//! \param nIndex [in]Ŀ��λ�á�
	//! \param pntPoint [in]Ҫ����ĵ㡣
	//! \return �����Ƿ�,����false��
	UGbool InsertAt(UGint nIndex, const UGPoint2D &pntPoint);	
	
	//���� nPointCount ����
	//������
	//		nIndex		Ŀ��λ��
	//		pPoints		Ҫ��ӵĵ����괮
	//		nPointCount	Ҫ��ӵĵ���

	//! \brief ��ָ��λ�ò���һ���㴮��
	//! \param nIndex [in] ָ��λ��������
	//! \param pPoints [in] Ҫ����ĵ㴮ָ�롣
	//! \param nPointCount [in] �㴮�ĵ������
	//! \return ����λ�÷Ƿ�,���ߵ㴮ָ��ΪNULL,����false��
	UGbool InsertAt(UGint nIndex, const UGPoint2D *pPoints, UGint nPointCount);	
	
	//! \brief ����ָ��λ�õĵ�, ԭ��λ�õĵ㱻�滻��
	//! \param nIndex [in] λ��������
	//! \param pntPoint [in] �����ꡣ
	//! \return �����Ƿ�,����false��
	UGbool SetAt(UGint nIndex, const UGPoint2D &pntPoint);	
	
	//! \brief �õ�ָ��λ�õĵ㡣
	//! \param nIndex [in] λ��������
	//! \param pntPoint [out] ָ��λ�õĵ㡣
	//! \return �����Ƿ�,����false��
	UGbool GetAt(UGint nIndex, UGPoint2D &pntPoint);	
	
	//! \brief �Ƴ�ָ��λ�õĵ㡣
	//! \param nIndex [in]Ҫ�Ƴ��ĵ�λ��������
	//! \return �����Ƿ�,����false��
	UGbool RemoveAt(UGint nIndex);	
	
	//! \brief �Ƴ���ָ��λ�ÿ�ʼ�����ɸ��㡣
	//! \param nFrom [in] ��ʼ�Ƴ���λ�á�
	//! \param nCount [in] Ҫ�Ƴ��ĵ���Ŀ��
	//! \return �����Ƴ��ĵ���Ŀ��
	UGint Remove(UGint nFrom, UGint nCount);	
	
	//! \brief �Ƴ����е㡣
	void RemoveAll();	

public:	
	//! \brief ����ͶӰת���������ú�ת������Ҫ��, ����ͶӰת��
	//! \param pPJTranslator ͶӰת����
	//! \param bForward ת������, true�����UGRefTranslator��Դ(Src)ת����Ŀ��(Des), false���෴
	virtual void PJConvert(UGRefTranslator *pPJTranslator, UGbool bForward = true);

	//! \brief �Ӿ�γ����ϵͳת��ΪͶӰ����ϵͳ
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJForward(UGPrjCoordSys *pCoordSys);

	//! \brief ��ͶӰ����ϵͳת��Ϊ��γ����
	//! \param pCoordSys ͶӰ����ϵͳ
	virtual void PJInverse(UGPrjCoordSys *pCoordSys);
	
public:

	//! \brief ͨ�����Ƶ㴮����Curve����
	//! \param pPoints [in] �㴮ָ�롣
	//! \param nPointCount [in] �㴮�ĵ���Ŀ��
	//! \return ���ָ��ΪNULL���ߵ���Ϊ0,����false��
	UGbool Make(const UGPoint2D * pPoints, UGint nPointCount);	

	//! \brief ͨ�����ж����ƹ���Curve����
	//! \param geoCurve [in] �Ժ��Curve����
	//! \return ���ж���Ƿ�,����false��
	UGbool Make(const UGGeoCurve &geoCurve);	

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
	 virtual UGint GetHandle(UGint nHandle, UGPoint2D& point);


	//! \brief �ƶ����Ƶ㵽ָ������,��Ҫ���ڻ��ƶ����޸Ķ���ڵ�Ȳ���
	//! \param nHandle ���Ƶ���
	//! \param point ���Ƶ�����
	virtual void MoveHandle(UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_None);

	//! \brief �ڵ�༭ʱ����������һ�����Ƶ�,Ҳ�������ڻ��ƶ���ʱ����ڵ�
	//! \param nHandle ����λ��
	//! \param pnt2D �����ĵ�������
	virtual void AddHandle(UGint nHandle, const UGPoint2D& pnt2D,UGEditType::EditToolShape nEditType=UGEditType::ET_None);
	
	//! \brief ɾ���༭�����ָ���ڵ�
	//! \param nHandle �ڵ���
     virtual UGuint DelNode(UGint nHandle);

	//! \brief ����������ʱ�ĸ����ߣ����ص���һ�����϶���
	//! \param pPoints �㴮
	//! \param nPntCount  ��ĸ���
	//! \param nEditType ���ƶ�������ͣ��ο�UGEditType
	//! \param pStyle	 �����ߵķ���������ΪNULL����Ĭ�ϵķ��
     virtual UGGeometry*  CalAssistantLine(const UGPoint2D* pPoints,UGint nPntCount,UGEditType::EditToolShape nEditType,UGStyle* pStyle=NULL);

	//added by xielin ^_^ �༭��غ���,�ѱ༭��geometryͳһ end
	 
protected: //! ������Ҫʵ�ֵ�һЩ����������
	virtual UGRect2D ComputeBounds() const;

	/*virtual UGRect2D GetBoundsInside() const;

	virtual void SetBoundsInside(const UGRect2D & rcBounds);*/

	//! \brief �洢��Stream��
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE)  const;

	//! \brief ��Stream������Geometry
	virtual UGbool LoadGeoData(UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE);

	// �������������������Ƶĺ��� ����Ϊһ����, �ŵ��㷨���UGOpLines��
	UGbool Curve2Line(UGPoint2D *pCtrlPoints, UGlong lCtrnPointCount,
				UGPoint2D *&pResultPoints, UGint &lResultPointCount, UGint nPointCountPerSegment = 20) const;

	static void CurveToPolyline(UGPoint2D *pPoints, UGlong nPointCount, UGArray <UGPoint2D> &pPointsDraw, 
		UGlong &nDrawPointCount, UGdouble dAngleGrain = 0.05);

private:
	//! \brief ���Ƶ�����
	//! \remarks Curve��ʵ��λ�ò����������Ƶ�
	UGArray<UGPoint2D> m_Points;
};

}
#endif // !defined(AFX_UGGEOCURVE_H__02C1EB1D_1DF5_4285_B810_47F6DF6DEA53__INCLUDED_)
