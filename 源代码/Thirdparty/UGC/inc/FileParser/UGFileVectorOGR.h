// UGFileVectorOGR.h: interface for the UGFileVectorOGR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEVECTOROGR_H__93BBC489_7396_4FB0_BAD3_7C9A44BBCD16__INCLUDED_)
#define AFX_UGFILEVECTOROGR_H__93BBC489_7396_4FB0_BAD3_7C9A44BBCD16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FileParser/UGFileParseVector.h"
#include "Engine/UGDataset.h"
#include "ogrsf_frmts.h"
#include "gdal_priv.h"


namespace UGC {

class UGFileVectorOGR : public UGFileParseVector  
{
public:
	UGFileVectorOGR();
	virtual ~UGFileVectorOGR();
	
public:
	//////////////////////////////////////////////////////////////////////////
	// ��ȡ����
	//////////////////////////////////////////////////////////////////////////
	
	//! \brief ׼����ȡһ�������ļ�
	virtual UGbool OpenForRead(const UGString& strFileName);
	
	//! \brief �õ�ͼ�����Ŀ
	virtual UGint GetLayerCount();
	
	//! \brief �õ�ָ����ŵ�ͼ����Ϣ��
	virtual UGbool GetLayerInfo(UGint nIndex, UGString& strLayerName, 
		UGint& nLayerType, UGString& strSubName);
	
	//! \brief �ر��ļ�
	virtual void Close();
	
	//////////////////////////////////////////////////////////////////////////
	// ��ȡ����
	//////////////////////////////////////////////////////////////////////////
	
	//! \brief �õ�����ο�ϵͳ
	virtual UGbool GetSpatialRef(UGPrjCoordSys& spatialRef);
	
	//! \brief �õ���ǰͼ��Ķ�����
	virtual UGint GetFeatureCount();

	//! \brief �õ���ǰͼ��ķ�Χ
	virtual UGRect2D GetLayerExtent();

	//! \brief �õ�ָ��ͼ����ֶ���Ŀ
	virtual UGint GetFieldCount(UGint nLayerIndex);	

	//! \brief �õ�ָ��ͼ�㡢ָ���ֶ���ŵ��ֶ���Ϣ
	virtual UGbool GetFieldInfo(UGint nLayerIndex, UGint nFieldIndex, UGFieldInfo &fieldInfo);
	
	//! \brief �õ�ָ��ͼ�����չ�ֶε���Ŀ
	virtual UGint GetExtendFieldCount(UGint nLayerIndex);
	
	//! \brief �õ�ָ��ͼ�㡢ָ���ֶ���ŵ���չ�ֶ���Ϣ
	virtual UGbool GetExtendFieldInfo(UGint nLayerIndex, UGint nFieldIndex, 
		UGString& strFieldName, UGint& nFieldType, UGint& nFieldSize);
	
	//! \brief �õ���ǰ��¼�ġ�ָ����ŵ���չ�ֶ�ֵ��
	virtual UGbool GetExtendFieldValue(UGint nIndex, UGVariant& value);
		
	
	//! \brief �Ѷ��ļ���ָ�������������ļ�ͷ�������Ϳ������¶�ȥ�ļ�
	virtual void ResetReading();
	
	//! \brief ��ʼ��ȡ��¼���ڵ�һ�ε��ö�ȡ��¼ǰ��������á�
	virtual void BeginReadRecord();
	
	//! \brief �Ƿ��Ѿ���ȡ���ļ�β�ˣ������Ϊ��ȡ�����ı�־
	//! \remarks ������Ϊ���麯������Ϊ�ļ���������û����������������ѭ���ģ�����Ҫ
	//! \return ����true,˵���ѵ��ļ�β,��Ҫ������ȡ��
	virtual UGbool IsEOF();
	
	//! \brief ��ʼ��ȡһ����¼��
	virtual void BeginReadOneRecord();
	
	//! \brief ��ȡһ����¼�еļ��ζ���
	//! \remarks �������false��ֻ˵����ȡ����Geometry�����⣬���������Ѿ�����
	//! ��ȡ�ļ��Ƿ������ʹ��IsEOF�����ж�
	virtual UGbool ReadOneGeometry(UGGeometry*& pGeometry);

	//! \brief �õ���ǰ���ζ�������ͼ������֣������ͼ�㲻��Ҫת����ô�Ͳ���Ҫ��ȡ������ζ���
	virtual UGString GetLayerOfGeometry();
	
	//! \brief �õ���ǰ��¼�ġ�ָ����ŵ��ֶ�ֵ��
	virtual UGbool GetFieldValue(UGint nIndex, UGVariant& value);
	
	//! \brief ������ȡһ����¼��
	virtual void EndReadOneRecord();
	
	//! \brief �õ���ǰ�Ѿ���������ݵİٷֱ�
	//! \remarks ���ڲ��ṩ�ܼ�¼���ĺ���,�ʶ���������Ҫ�������
	virtual UGint GetCurrentPercent();
	
	//! \brief ������ȡ���м�¼
	virtual void EndReadRecord();


	//////////////////////////////////////////////////////////////////////////
	// ����ѯ�ʺ���
	//////////////////////////////////////////////////////////////////////////
	//! \brief �Ƿ��е�������ݼ������ָ���ͼ�����������������û�����������������
	//! ��Щ���ݵ���ʱ��һ������
	virtual UGbool IsDatasetNameByLayer();

//public:
//	//! \brief ��λ����ǰ Layer
//	void GetLayerAt(UGint nIndex);


private:
	//! \brief m_pOGRDS �� ��ǰ�ļ���Ӧ 
	OGRDataSource  *m_pOGRDS;
	
	//! \brief ��ǰͼ��
	OGRLayer *m_pLayer;

	//! \brief ��ǰ��¼
	OGRFeature *m_pFeature;

	//! \brief OGRDriver��
	UGString m_strDriver;

	//! \brief ��ǰ��¼���ֶ���Ϣ
	OGRFeatureDefn *m_poFDefn;

	//! \brief ͼ��ļ�¼��
	UGint m_nFeatureCount;

private:
	//! \breif �ж��Ƿ���Ϊ��һͼ�㴦��
	UGbool IsSingleLayer();
	
	//! \brief �õ����ݼ�����,�� GetLayerInfo()�е���
	UGbool GetDatasetType(OGRwkbGeometryType ogrGeoType, UGDataset::DatasetType &datasetType);

	//! \breif �ֶ���Ϣת��
	UGbool OGRFieldDefnToUGCFieldInfo(OGRFieldDefn *ogrFieldDefn, UGFieldInfo &fieldInfo);

	//! \brief ���¼����������������� OGR �ļ��ζ���ת���� UGC �ļ��ζ���
		typedef std :: vector<UGPoint2D> UGVecPoint2Ds;
		typedef std :: vector<UGint> UGVecInts;

		//! \brief ��OGRPolygon �еõ�����ĵ㴮�͵���
		void ConverPolygon( OGRPolygon *poPolygon, UGVecPoint2Ds& points, UGVecInts& PolyCount)const;

		//! \brief �� OGRLineString ת UGGeoLine
		void ConvertLine(OGRLineString *poPolyline, UGPoint2D *&pPoints, int &nPointCount);
		
		//! \brief �� OGRGeometryCollection ת UGGeoCompound
		void ConvertCollection(OGRGeometryCollection *poCollection, UGGeoCompound *pGeoCompoud);

	//! \brief m_pFeature(Label) �й���Text
	UGbool MakeTextFromFeature(UGString &strText, UGPoint2D &pntAnchor, UGTextStyle &textStyle);

	//! \brief �õ����ζ���ķ��
	UGbool MakeStyleFromFeature(UGString &strText, UGStyle &geoStyle);

	//����ת���У�Project������һ�����ݣ�����GeoCoordSys ��Ҫ��Բ�ͬ�ⲿ�ļ�����Ŀǰֻ������ shapefile��mif/mid��miftab
	//!\brief ͶӰ����ת��	�� virtual UGbool GetSpatialRef(UGPrjCoordSys& spatialRef); �е���
	UGbool OGRPrjToUGC(OGRSpatialReference *poSpatialRef, UGProjection &PJObject, UGPrjParams &PJParams);

	//!\brief Datum ת��	�� virtual UGbool GetSpatialRef(UGPrjCoordSys& spatialRef); �е���
	void OGRGeoCoordSysToUGC(OGRSpatialReference *poSpatialRef,  UGGeoCoordSys &PJGeoCoordSys);
};

}	//namespace UGC

#endif // !defined(AFX_UGFILEVECTOROGR_H__93BBC489_7396_4FB0_BAD3_7C9A44BBCD16__INCLUDED_)
