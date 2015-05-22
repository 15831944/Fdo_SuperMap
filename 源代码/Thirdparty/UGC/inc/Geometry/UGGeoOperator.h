//! \file UGGeoOperator.h
//! \brief ����Geometry�Ŀռ�����
//! \remarks������: ���ص�Geometryָ��pGeoResultΪ���ô��룬���pGeoResult��ʼֵ��Ϊ�գ�
//!			��ֱ��ʹ��pGeoResultָ�룬�������ָ��pGeoResult�ǷǷ�ָ�룬����ɵ������Լ�����
//!			���pGeoResult��ʼֵΪ�գ�pGeoResult�ں����ڲ�����ռ䣬��������Ҫ�Լ������ͷţ�
//!			�������ʧ�ܣ���pGeoResult�����κα䶯��


#ifndef UGGEOOPERATOR_H
#define UGGEOOPERATOR_H

#include "Algorithm/UGRect2D.h"
#include "UGGeometry.h"

namespace UGC {


class GEOMETRY_API UGGeoOperator  
{
private:
	UGGeoOperator();

public: // Geometry ֮��Ĳ�������

	//! \brief ��
	//! \param pGeometry1 �μӲ����ļ��ζ���ָ��, ����ΪNULL
	//! \param pGeometry2 �μӲ����ļ��ζ���ָ��, ����ΪNULL
	//! \param pGeoResult ������ζ���; �������ʱΪNULL���߲����Ͻ�����ζ�������Ҫ��, ���������ɽ�����ζ���
	//! \remarks ����Geometry��ά�ȱ���һ��
	//! \attention ��֧�ֶ�ά����Ĳ�������ά�ȵĲ�������
	//! \return �������Geometry��ά�Ȳ���ȣ�����NULL
	static UGbool Union(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);

	//! \brief ��
	//! \param pGeometry1 �μӲ����ļ��ζ���ָ��, ����ΪNULL
	//! \param pGeometry2 �μӲ����ļ��ζ���ָ��, ����ΪNULL
	//! \param pGeoResult ������ζ���; �������ʱΪNULL���߲����Ͻ�����ζ�������Ҫ��, ���������ɽ�����ζ���
	//! \attention        ���桢���ߡ����ߡ����桢����֮���󽻣����֮������ͬ��;
	//!				      �������	���� = ��(GeoPoint) ; ���� = ��(GeoPoint)
	//!						     		���� = ��(GeoMultiPoint) ; ���� = �� ; ���� = ��
	//! \return   
	static UGbool Intersect(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);

	//! \brief ��(Ҳ���� Erase ���� )
	//! \remarks ��pGeoClipȥ�ü�pGeoSubject���õ�pGeoSubject����pGeoClip�еĲ���
	//!			���Ϊ pGeoSubject - pGeoClip
	//!			pGeoClip��ά��>=pGeoSubject��ά�ȣ����Geometry��ά�ȵ���pGeoSubject��ά��
	//! \return ������Ϊ�գ�����NULL
	static UGbool Difference(const UGGeometry* pGeoSubject, const UGGeometry* pGeoClip, UGGeometry*& pGeoResult);

	//! \brief ���
	//! \remarks ��򣽣�������
	//!			����Geometry��ά�ȱ���һ��(һά֮�����û��ʵ��)
	//! \return �������Geometry��ά�Ȳ�һ�������߽��Ϊ�գ�����NULL
	static UGbool Xor(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);

	//! \brief		����((A-B)��B). ���� pGeometry1 �� pGeometry2 �ཻ�Ĳ��� �Լ� pGeometry2 ���ռ���״�����仯
	//! \remarks	������������֮��Ŀռ����
	static UGbool Update(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);
	
	//! \brief ͬһ����((A��B)��(A��B))����ռ���״����
	//! \return pGeoResult ǰ����Ϊ pGeometry2 ��Ķ���(δ��ͬһ)���󲿷�Ϊ pGeometry2 �ڵĶ���(��ͬһ)
	//! \remarks pGeometry1 ����Ϊ�㡢�ߡ���;pGeometry2ֻ��Ϊ��
	static UGbool Identity(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);

public: // ��������Geometry֮��ľ���
	
	//! \brief ��������Geometry֮��ľ���
	//! \remarks ����Ķ��壺��pGeometry1��pGeometry2�зֱ��������pnt1��pnt2��ʹ��distance(pnt1,pnt2)
	//!			 �ﵽ��С
	static UGdouble Distance(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2);

	//! \brief ��������Geometry֮���������
	//! \remarks ������Ķ��壺��pGeometry1��pGeometry2�зֱ��������pnt1��pnt2��ʹ��distance(pnt1,pnt2)
	//!			 �ﵽ���
	static UGdouble MaxDistance(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2);

public: // �ü�Geometry
	
	//! \brief ���βü�
	//! \param bInside=true, ������Rect�ڵĲ���; bInside=false, ������Rect��Ĳ���
	//! \return ������Ϊ��,����NULL
	static UGbool Clip(const UGGeometry* pGeometry, const UGRect2D& rectClip, UGGeometry*& pGeoResult, UGbool bInside=TRUE);

	//! \brief �ü�
	//! \param pGeoSource �μӲ����ļ��ζ���ָ��, ����ΪNULL
	//! \param pGeoClip   �μӲ����ļ��ζ���ָ��, ����ΪNULL
	//! \param pGeoResult ������ζ���; �������ʱΪNULL���߲����Ͻ�����ζ�������Ҫ��, ���������ɽ�����ζ���
	//! \attention        ���桢���ߡ����ߡ����桢����֮���󽻣����֮������ͬ��;
	//!				      �������	���� = ��(GeoPoint) ; ���� = ��(GeoPoint)
	//!						     		���� = ��(GeoMultiPoint) ; ���� = �� ; ���� = ��
	//! \return ������Ϊ��,����NULL
	static UGbool Clip(const UGGeometry* pGeoSource, const UGGeometry* pGeoClip, UGGeometry*& pGeoResult);
	
	//! \brief ���βü��棬���������ߵ��໥�ռ�λ�ù�ϵ
	//! \param RegionSource		���ü������ 
	//! \param RectClipper		�ü�����
	//! \param RegionResult		�ü����������
	//! \param dInterval		�жϽ����ȵ�����
	//! \return 
	//! 0-------����
	//! 1-------�ཻ
	//! 2-------���ΰ��������
	//! 3-------����ΰ�������
	static UGint IsIntersectRegionWithRect(UGGeometry* pRegionSource,UGRect2D &RectClipper,UGGeoRegion &RegionResult, 
											UGdouble dInterval=EP);
public: // �ز���

	//! \brief �����ز���
	//! \return ���ص�Geometry��ά�Ⱥ�����Geometry��ά��һ��
	//! \remark ֻ֧��1ά��2ά����
	static UGbool Resample(const UGGeometry* pGeoSource, UGGeometry*& pGeoResult, UGdouble dTolerance);

	//! \brief �ָ�,pGeoSource��pGeoSplit���ָ�
	//! \remarks pGeoSplitֻ����0ά����1ά����; 
	//!			pGeoSource��ά��=pGeoSplit��ά��, ����pGeoSource��ά��=pGeoSplit��ά��+1
	//!         ֧�� ��ָ��ߡ��߷ָ��ߡ��߷ָ���
	static UGbool Split(const UGGeometry* pGeoSource, const UGGeometry* pGeoSplit, 
						UGGeometry* &pGeoResult1, UGGeometry* &pGeoResult2);
	
	//! \brief ����, �������� Geometry �ص��Ĳ���,�γ�һ������
	//! \remarks ����Geometry�������ص�����,��ά�ȱ���һ��
	//static UGGeometry* Dissolve(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2);

	//! \brief ����, 
	//! \remarks ����Geometry��ά�ȱ���һ��
	//!			����Geometry������β����,�������ص�
	//!			�ڲ���û��ʵ��
	static UGbool Link(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);
	
	//! \brief �������Ļ��ȳ���
	//! \return  ���ض���Ļ��ȳ���
	//! \remarks ����ά�ȱ��������ά��1ά�����Ͼ��룻2ά�������ܳ���pGeometry������ֵΪ��γ����
	static UGdouble GetRadianDistance(UGGeometry* pGeometry, UGdouble dRadius/*, UGint nDistUnits*/);
	
	
	//! \brief �õ�ȥ��� Geometry 
	//! \param pGeometry		����ϼ��ζ���
	//! \param pntBomb			��ϵ�
	//! \param pBreakLine		������
	//! \param dTolerance		����(����㵽ֱ�ߵľ���������ޣ��򲻴��)
	//! \return 
	//! \remarks ֻ֧�� Geometry Ϊ һά����          
	static UGbool Break(UGGeometry* pGeometry, UGPoint2D& pntBomb, UGArray<UGGeometry*>& pBreakLine, 
						UGdouble dTolerance);

	//! \brief ����Geometry�������ٸ�����
	//! \param *pGeometry [in] �������Ŀռ����
	//! \param &pntCenter [in]�����յ����ĵ�����
	//! \param &dGrid0 [in]��0����������
	//! \param &dGrid1 [in]��1����������
	//! \param &dGrid2 [in]��2����������
	//! \param &aryMaybeGrid [out]����������󾭹��ĸ�������
	//! \param &aryGrid [out]���������������ȫ�����ĸ�������
	//! \param dGridRatio [in]�����񳤿��Ĭ��Ϊ1��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	static UGbool ComputeGrid(UGGeometry *pGeometry,UGPoint2D &pntCenter, UGdouble &dGrid0, UGdouble &dGrid1,
							UGdouble &dGrid2,UGArray<UGPoint> &aryMaybeGrid, UGArray<UGPoint> &aryGrid, 
							UGdouble dGridRatio=1);
};


}

#endif // !defined(AFX_UGGEOOPERATOR_H__38FEB7EF_6E68_49EA_9A5F_6E472FFF15D4__INCLUDED_)
