/* 
	\file UGSpatialQuery.h
	\brief �ռ��ѯ��
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGSPATIALQUERY_H
#define UGSPATIALQUERY_H

#include "Engine/UGDatasetVector.h"
#include "Topology/UGTopoSpatialQuery.h"

namespace UGC {

class OPERATION_API UGSpatialQuery  
{
public:
	UGSpatialQuery();
	virtual ~UGSpatialQuery();
	
	enum UGSpatialQueryMode
	{
		UGIdentical						=0,	
		UGDisjoint						=1,	
		UGIntersects					=2,	
		UGTouches						=3,	
		UGOverlaps						=4,	
		UGCrosses						=5,	
		UGWithin						=6,	
		UGContains						=7,	
		UGExtentIntersect				=8,	
		UGRelate						=9,	
		
		UGCommonPoint					=10,
		UGCommonSegment					=11,
		UGCentroidInPolygon				=12,
	};
	
public:
	//! \brief �����ѯ��¼��
	/**
	\param		pRecordset		����ѯ��¼��
	\param		pGeoQuery		��ѯ����
	\param		nMode			��ѯģʽ
	\param		strRelate		UGRelateģ�͵��ַ������ʽ
	\return		���ز�ѯ�����ļ�¼��,�޽������NULL
	\remarks	
	*/
	UGRecordset* Query(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGSpatialQueryMode nMode,
						const UGString& strRelate=(""), UGQueryDef::CursorType nCursorType=UGQueryDef::OpenStatic);
	
	//! \brief �����ѯ���ݼ�
	/**
	\param		pDataset		����ѯ���ݼ�
	\param		pGeoQuery		��ѯ����
	\param		nMode			��ѯģʽ
	\param		strRelate		UGRelateģ�͵��ַ������ʽ
	\return		���ز�ѯ�����ļ�¼��,�޽������NULL
	\remarks	strRelateֻ�����Զ���ģ��(UGRelate)�²�������
	*/
	UGRecordset* Query(UGDatasetVector *pDataset, UGGeometry* pGeoQuery, UGSpatialQueryMode nMode,
						const UGString& strRelate=(""), UGQueryDef::CursorType nCursorType=UGQueryDef::OpenStatic);
	
	//! \brief ��¼����ѯ��¼��
	/**
	\param		pRecordset		����ѯ��¼��
	\param		pRSQuery		��ѯ��¼��
	\param		nMode			��ѯģʽ
	\param		strRelate		UGRelateģ�͵��ַ������ʽ
	\return		���ز�ѯ�����ļ�¼��,�޽������NULL
	\remarks	strRelateֻ�����Զ���ģ��(UGRelate)�²�������
	*/
	UGRecordset* Query(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGSpatialQueryMode nMode,
						const UGString& strRelate=(""), UGQueryDef::CursorType nCursorType=UGQueryDef::OpenStatic);
	
	//! \brief ��¼����ѯ���ݼ�
	/**
	\param		pDataset		����ѯ���ݼ�
	\param		pRSQuery		��ѯ��¼��
	\param		nMode			��ѯģʽ
	\param		strRelate		UGRelateģ�͵��ַ������ʽ
	\return		���ز�ѯ�����ļ�¼��,�޽������NULL
	\remarks	strRelateֻ�����Զ���ģ��(UGRelate)�²�������
	*/
	UGRecordset* Query(UGDatasetVector *pDataset, UGRecordset *pRSQuery, UGSpatialQueryMode nMode,
						const UGString& strRelate=(""), UGQueryDef::CursorType nCursorType=UGQueryDef::OpenStatic);
	
	//! \brief ���ݼ���ѯ���ݼ�
	/**
	\param		pDataset		����ѯ���ݼ�
	\param		pDTQuery		��ѯ���ݼ�
	\param		nMode			��ѯģʽ
	\param		strRelate		UGRelateģ�͵��ַ������ʽ
	\return		���ز�ѯ�����ļ�¼��,�޽������NULL
	\remarks	strRelateֻ�����Զ���ģ��(UGRelate)�²�������
	*/
	UGRecordset* Query(UGDatasetVector *pDataset, UGDatasetVector *pDTQuery, UGSpatialQueryMode nMode,
						const UGString& strRelate=(""), UGQueryDef::CursorType nCursorType=UGQueryDef::OpenStatic);
	
	//! \brief ��������
	/**
	 \param		dInterval	���õ�����
	 \return	���óɹ�����TRUE���޴��󷵻�FALSE
	 \remarks	��dInterval<EP,�����Ӷ�����ΪEP
	*/
	void SetInterval(UGdouble dInterval);
	
	//! \brief ��ȡ�����õ�����
	/**
	 \param		dInterval	���õ�����
	 \return	��������ֵ
	 \remarks	
	*/
	UGdouble GetInterval();
	
private:
	UGbool Query(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGSpatialQueryMode nMode, UGArray<UGint> &arrIDs, 
				const UGString& strRelate);
	UGbool InteriorToInterior(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool InteriorToBoundary(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool InteriorToExterior(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToInterior(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToBoundary(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToExterior(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool ExteriorToInterior(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool ExteriorToBoundary(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	
	UGbool InteriorToInterior(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool InteriorToBoundary(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool InteriorToExterior(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToInterior(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToBoundary(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToExterior(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool ExteriorToInterior(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool ExteriorToBoundary(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryIdentical(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryIdentical(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryDisjoint(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryDisjoint(UGDatasetVector *pDataset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryDisjoint(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryDisjoint(UGDatasetVector *pDataset, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool QueryDisjoint(UGDatasetVector *pDataset, UGDatasetVector *pDTQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryIntersects(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryIntersects(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryTouches(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryTouches(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryOverlaps(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryOverlaps(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryCrosses(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryCrosses(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryWithin(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryWithin(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryContains(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryContains(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryExtentIntersect(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryExtentIntersect(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryRelate(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs, const UGString& strRelate);
	UGbool QueryRelate(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs, const UGString& strRelate);
	
	UGbool QueryCommonPoint(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryCommonPoint(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryCommonSegment(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryCommonSegment(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);	
	
	UGbool QueryCentroidInPolygon(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryCentroidInPolygon(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
private:
	
	UGdouble m_dInterval;
	UGTopoSpatialQuery m_SpatialQuery;
	UGTopoOperators m_TopoOperators;
	
	//=======================���������Ҫ�ŵ��㷨����===============================
	UGint FindIndex(UGint nValue, UGint* pData, UGint nCount);
	UGbool GetDisJointID(UGRecordset *pRecordset, UGArray<UGint> &arrIDs, UGArray<UGint> &arrResIDs);
	UGbool GetExtentIntersectID(const UGRect2D& rcBoundsSrc, UGRecordset *pRecordset, UGArray<UGint> &arrIDs, 
								UGArray<UGint> &arrResIDs);
	UGbool GetExtentIntersectID(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrIDs, 
								UGArray<UGint> &arrResIDs);
	
};

}

#endif // !defined(UGSPATIALQUERY_H)
