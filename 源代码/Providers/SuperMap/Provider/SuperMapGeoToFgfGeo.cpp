/** \file	 SuperMapGeoToFgfGeo.cpp
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-09
*/

#include "SuperMap.h"

//TODO::m_FdoPoint m_FdoMultiLine m_FdoPolygon ���о����Ƿ�����þֲ������Ϳ��Խ��
//TODO:: m_nSubCount m_subPointsCount ����ܸ�Ϊ�������ݵ���ʽ

#define SUPERMAP_GEOMETRY_INITIAL_SIZE    1000 // bytes

SuperMapGeoToFgfGeo::SuperMapGeoToFgfGeo(void)
{
}

SuperMapGeoToFgfGeo::~SuperMapGeoToFgfGeo(void)
{
}

SuperMapGeoToFgfGeo::SuperMapGeoToFgfGeo(UGC::UGRecordset *pRecordset)
{
	m_pRecordset = pRecordset;
	m_pElemGeometry = NULL;
	if(m_pRecordset)
	{
		UGC::UGbool bHasGeometry = m_pRecordset->HasGeometry();
		if(bHasGeometry)
		{
			m_pRecordset->GetGeometry(m_pElemGeometry);
		}
	}
	m_pFdoGeoFactory = FdoFgfGeometryFactory::GetInstance();
	m_pRetByteArray = NULL;
	m_nSubCount = 0;
}

// ����FDOҪ��, ����FDO �㡢�ߡ���
void SuperMapGeoToFgfGeo::CreateFdoGeo()
{
	if (m_pElemGeometry != NULL)
	{
		//modified by zhoux 2007-11-28
		if(m_pElemGeometry->GetType() != UGC::UGGeometry::GeoText)
		{
			m_pElemGeometry->GetSpatialData(m_points, m_subPointsCount, m_nSubCount);
		}

		if(m_pFdoGeoFactory) 
		{
			switch(m_pElemGeometry->GetType()) 
			{
			case UGC::UGGeometry::GeoPoint:
			case UGC::UGGeometry::GeoText: // added by zhoux
			case UGC::UGGeometry::GeoMultiPoint:
				CreateFdoPoint();
				break;

			case UGC::UGGeometry::GeoLine:
			case UGC::UGGeometry::GeoArc:
			case UGC::UGGeometry::GeoCurve:
			case UGC::UGGeometry::GeoBSpline:
			case UGC::UGGeometry::GeoCardinal:
			case UGC::UGGeometry::GeoEllipticArc:
				CreateFdoMultiLine();
				break;

			case UGC::UGGeometry::GeoRect:
			case UGC::UGGeometry::GeoRectRound:
			case UGC::UGGeometry::GeoCircle:
			case UGC::UGGeometry::GeoEllipse:
			case UGC::UGGeometry::GeoRegion:
			case UGC::UGGeometry::GeoPie:
			case UGC::UGGeometry::GeoChord:
				CreateFdoPolygon();
				break;

			case UGC::UGGeometry::GeoCompound:
				CreateFdoCompoundGeometry();
				break;

			case UGC::UGGeometry::GeoLineM:
			case UGC::UGGeometry::GeoImageBlock:
			case UGC::UGGeometry::GeoIcon:
			case UGC::UGGeometry::GeoEquilateral:
				break;

			default:
				break;

			}//switch
		}//if(m_pFdoGeoFactory)
		delete m_pElemGeometry;
		m_pElemGeometry = NULL;
	}//if (m_pElemGeometry != NULL)
}

void SuperMapGeoToFgfGeo::CreateFdoPoint()
{
	FdoPtr<FdoIPoint> FdoPoint;
	FdoPtr<FdoIMultiPoint> FdoMultiPoint;
	// modified by zhouxu for support GeoText To FdoPoint 2007-11-28
	if(m_pElemGeometry->GetType() != UGC::UGGeometry::GeoText)
	{
		long m = 0;
		for (int i = 0; i <  m_nSubCount; i++)
		{
			for (int j = 0; j < m_subPointsCount[i] ; j ++)
			{
				m_fdoCoordinatesArray.Add(m_points[m].x);
				m_fdoCoordinatesArray.Add(m_points[m].y);
				m++;
			}	  
		}
		if(m_nSubCount == 1) //һ����
		{
			FdoPoint = m_pFdoGeoFactory->CreatePoint(FdoDimensionality_XY, m_fdoCoordinatesArray.GetData());//FDO point			
			m_pRetByteArray = m_pFdoGeoFactory->GetFgf(FdoPoint.p);
		}
		else //���
		{
			FdoMultiPoint = m_pFdoGeoFactory->CreateMultiPoint(FdoDimensionality_XY, 
				m_fdoCoordinatesArray.GetSize(), 
				m_fdoCoordinatesArray.GetData());//FDO multipoint
			m_pRetByteArray = m_pFdoGeoFactory->GetFgf(FdoMultiPoint.p);
		}
	}
	else 
	{
		if(m_pRecordset)
		{
			//��ת��CAD���ݼ��е��ı�,��Ϊ��CAD���ݼ��е��ı��͵����𲻿�  // �򿪸������ݼ��е��ı� by zhouxu 2008-4-28 
			/*if(m_pRecordset->GetDataset()->GetType() != UGC::UGDataset::CAD) 
			{*/
				// �ı���������ת����ʱֻ֧��һ���Ӷ�������
				UGC::UGGeoText* pGeoText = (UGC::UGGeoText*)m_pElemGeometry;
				m_fdoCoordinatesArray.Add(pGeoText->GetSubAnchor(0).x);
				m_fdoCoordinatesArray.Add(pGeoText->GetSubAnchor(0).y);

				FdoPoint = m_pFdoGeoFactory->CreatePoint(FdoDimensionality_XY, m_fdoCoordinatesArray.GetData());
				m_pRetByteArray = m_pFdoGeoFactory->GetFgf(FdoPoint.p);
			//}
		}
	}
}

void SuperMapGeoToFgfGeo::CreateFdoMultiLine()
{
	FdoPtr<FdoILineString> FdoLine;
	FdoPtr<FdoIMultiLineString> FdoMultiLine;
	FdoPtr<FdoLineStringCollection> linecollection; //��������

	long m = 0;
	linecollection = FdoLineStringCollection::Create();

	for (int i = 0; i <  m_nSubCount; i++)
	{
		for (int j = 0; j < m_subPointsCount[i] ; j ++)
		{
			m_fdoCoordinatesArray.Add(m_points.GetData()[m].x);
			m_fdoCoordinatesArray.Add(m_points.GetData()[m].y);
			m++;
		}
		FdoLine = m_pFdoGeoFactory->CreateLineString(FdoDimensionality_XY, 
			m_fdoCoordinatesArray.GetSize(), m_fdoCoordinatesArray.GetData()); //�����ߴ�

		linecollection->Add(FdoLine.p); //���ߴ����뼯����
		m_fdoCoordinatesArray.RemoveAll();
	}

	FdoMultiLine = m_pFdoGeoFactory->CreateMultiLineString(linecollection.p);
	m_pRetByteArray = m_pFdoGeoFactory->GetFgf(FdoMultiLine.p);
}

void SuperMapGeoToFgfGeo::CreateFdoPolygon()
{
	FdoPtr<FdoIPolygon> FdoPolygon;
	FdoPtr<FdoILinearRing> exteriorRing; //������⻷
	FdoPtr<FdoILinearRing> innerRing; //������ڻ�
	FdoPtr<FdoLinearRingCollection> interiorRings; //�ڻ�����

	long m = 0;
	interiorRings = FdoLinearRingCollection::Create();//�����ռ���

	for (int i = 0; i <  m_nSubCount; i++)
	{
		for (int j = 0; j < m_subPointsCount[i] ; j ++)
		{
			m_fdoCoordinatesArray.Add(m_points[m].x);
			m_fdoCoordinatesArray.Add(m_points[m].y);
			m++;
		}
		if(i == 0)//create the exteriorRing
		{
			exteriorRing = m_pFdoGeoFactory->CreateLinearRing(FdoDimensionality_XY, 
				m_fdoCoordinatesArray.GetSize(), m_fdoCoordinatesArray.GetData()); //�����⻷
		}
		else
		{
			innerRing = m_pFdoGeoFactory->CreateLinearRing(FdoDimensionality_XY, 
				m_fdoCoordinatesArray.GetSize(), m_fdoCoordinatesArray.GetData()); //�����ڻ����������ڻ�����
			interiorRings->Add(innerRing.p);
		}
		m_fdoCoordinatesArray.RemoveAll();
	}
	FdoPolygon = m_pFdoGeoFactory->CreatePolygon(exteriorRing.p, interiorRings.p); //�⻷+�ڻ�����
	m_pRetByteArray = m_pFdoGeoFactory->GetFgf(FdoPolygon.p);

	/*long m = 0;
	UGC::UGArray<UGC::UGbyte> ugByteArray;
	int nFdoGeoType = FdoGeometryType_Polygon;
	int nDimenType = FdoDimensionality_XY;
	int nSubCount = m_nSubCount;
	ugByteArray.Append((UGC::UGbyte*) &nFdoGeoType, sizeof(FdoInt32));
	ugByteArray.Append((UGC::UGbyte*) &nDimenType, sizeof(FdoInt32));
	ugByteArray.Append((UGC::UGbyte*) &nSubCount, sizeof(FdoInt32));
	for (int i = 0; i <  nSubCount; i++)
	{
		FdoInt32 nSubPtsCount = m_subPointsCount[i];
		ugByteArray.Append((UGC::UGbyte*) &nSubPtsCount, sizeof(FdoInt32));
		for (int j = 0; j < nSubPtsCount; j ++)
		{					
			m_fdoCoordinatesArray.Add(m_points[m].x);
			m_fdoCoordinatesArray.Add(m_points[m].y);
			m++;
		}
		int nBytesNum = sizeof(double) * m_fdoCoordinatesArray.GetSize();
		ugByteArray.Append((UGC::UGbyte*) m_fdoCoordinatesArray.GetData(), nBytesNum);
		m_fdoCoordinatesArray.RemoveAll();
	}
	m_pRetByteArray = FdoByteArray::Create(ugByteArray.GetData(), ugByteArray.GetSize());*/

}

void SuperMapGeoToFgfGeo::CreateFdoCompoundGeometry()
{
	static UGC::UGArray<UGC::UGPoint2D> points;
	static UGC::UGArray<UGC::UGint> nSubPointsCount;
	UGC::UGint nSubCount = 0;
	//�����϶���Ҫ���øú�������ÿһ�����ζ�������ݺ���һ�����ζ�������ݶ��޹أ������Ҫ������ϴν��
	points.RemoveAll();
	nSubPointsCount.RemoveAll();

	//Ŀǰ��֧����ͬ���͵��Ӷ�����ɵ���ϼ��ζ��� 
	if(!IsSameCompoundGeometry(m_pElemGeometry, true))
	{
		return;
	}
	int nGeoType = -1; //�����Ӷ��������
	GetCompoundSpatialData(m_pElemGeometry, points, nSubPointsCount, nSubCount, nGeoType);	

	m_points.SetData(points.GetData(), false);
	m_subPointsCount.SetData(nSubPointsCount.GetData(), false);
	m_nSubCount = nSubCount;

	switch(nGeoType) 
	{
	case UGC::UGGeometry::GeoPoint:
	case UGC::UGGeometry::GeoText: 
	case UGC::UGGeometry::GeoMultiPoint:
		CreateFdoPoint();
		break;

	case UGC::UGGeometry::GeoLine:
	case UGC::UGGeometry::GeoArc:
	case UGC::UGGeometry::GeoCurve:
	case UGC::UGGeometry::GeoBSpline:
	case UGC::UGGeometry::GeoCardinal:
	case UGC::UGGeometry::GeoEllipticArc:
		CreateFdoMultiLine();
		break;

	case UGC::UGGeometry::GeoRect:
	case UGC::UGGeometry::GeoRectRound:
	case UGC::UGGeometry::GeoCircle:
	case UGC::UGGeometry::GeoEllipse:
	case UGC::UGGeometry::GeoRegion:
	case UGC::UGGeometry::GeoPie:
	case UGC::UGGeometry::GeoChord:
		CreateFdoPolygon();
		break;

	case UGC::UGGeometry::GeoLineM:
	case UGC::UGGeometry::GeoImageBlock:
	case UGC::UGGeometry::GeoIcon:
	case UGC::UGGeometry::GeoCompound:
	case UGC::UGGeometry::GeoEquilateral:
		break;

	default:
		break;

	}//switch
}

bool SuperMapGeoToFgfGeo::IsSameCompoundGeometry(UGC::UGGeometry *pCompoundGeometry, bool bFirstCall)
{
	if(NULL == pCompoundGeometry)
	{
		return false;
	}

	static int nGeoType;
	if( bFirstCall )//��һ�ε��ã��ǵݹ����
	{
		nGeoType = -1;
	}
	int nCompoundGeoSubNum = pCompoundGeometry->GetSubCount();
	UGC::UGGeometry * pGeometry = NULL;

	for(int i = 0; i < nCompoundGeoSubNum; i++)
	{
		//�ü��ζ��󻹿�����һ�����϶��󣬼�Ϊ���Ƕ�׵Ĺ�ϵ
		pGeometry = ((UGC::UGGeoCompound *)pCompoundGeometry)->GetGeometry(i); 
		if(NULL == pGeometry)
		{
			return false;
		}

		if(UGC::UGGeometry::GeoCompound != pGeometry->GetType())//��Ϊ��ϼ��ζ���
		{
			if(-1 == nGeoType)
			{
				nGeoType = pGeometry->GetType();
			}
			else
			{
				if(pGeometry->GetType() != nGeoType)
				{
					return false;
				}
			}
		}
		else //��������Ƕ�׵����
		{
			if( !IsSameCompoundGeometry(pGeometry, false) ) //�ݹ����
			{
				return false;
			}
		}
	}
	return true;
}

void SuperMapGeoToFgfGeo::GetCompoundSpatialData(UGC::UGGeometry *pCompoundGeometry, 
												 UGC::UGArray<UGC::UGPoint2D> &points, 
												 UGC::UGArray<UGC::UGint> &nSubPointsCount, 
												 UGC::UGint &nSubCount,
												 UGC::UGint &nGeoType)
{
	if(NULL == pCompoundGeometry)
	{
		return;
	}

	UGC::UGAutoPtr<UGC::UGPoint2D> AutoPoints; 
	UGC::UGAutoPtr<UGC::UGint> AutoSubPointsCount; 
	UGC::UGint AutoSubCount; 

	int nSubPointIndex = 0;
	int nCompoundGeoSubNum = pCompoundGeometry->GetSubCount();
	UGC::UGGeometry * pGeometry = NULL;

	for(int i = 0; i < nCompoundGeoSubNum; i++)
	{
		//�ü��ζ��󻹿�����һ�����϶��󣬼�Ϊ���Ƕ�׵Ĺ�ϵ
		pGeometry = ((UGC::UGGeoCompound *)pCompoundGeometry)->GetGeometry(i); 
		if(NULL == pGeometry)
		{
			return;
		}
		nGeoType = pGeometry->GetType();
		//���Ϊ�򵥼��ζ���Ļ���ֱ��ȡ������Ϣ
		if(nGeoType != UGC::UGGeometry::GeoCompound)
		{
			pGeometry->GetSpatialData(AutoPoints, AutoSubPointsCount, AutoSubCount);
			nSubCount += AutoSubCount;
			for(int i = 0; i< AutoSubCount; i++)
			{
				nSubPointsCount.Add( AutoSubPointsCount[i] );
				for(int j = 0; j < AutoSubPointsCount[i]; j++)
				{
					points.Add( AutoPoints[nSubPointIndex] );
					nSubPointIndex++;
				}
			}
			nSubPointIndex = 0;
			AutoPoints.Release();
			AutoSubPointsCount.Release();
			AutoSubCount = 0;
		}
		else //��������Ƕ�׵����
		{
			GetCompoundSpatialData(pGeometry, points, nSubPointsCount, nSubCount, nGeoType); //�ݹ����
		}
	}
}

FdoByteArray *SuperMapGeoToFgfGeo::GetGeometry()
{
	if(m_pRecordset)
	{
		switch(m_pRecordset->GetDataset()->GetType())
		{
			//Ŀǰ��֧�ֵ㡢�ߡ��桢�ı���CAD���ݼ�
		case UGC::UGDataset::Point:
		case UGC::UGDataset::Line:
		case UGC::UGDataset::Region:
		case UGC::UGDataset::CAD:
		case UGC::UGDataset::Text:
			CreateFdoGeo();
			break;

		case UGC::UGDataset::PointZ:
		case UGC::UGDataset::LineZ:
		case UGC::UGDataset::RegionZ:  
		case UGC::UGDataset::LineM:
		case UGC::UGDataset::DEM:
		case UGC::UGDataset::ECW:
		case UGC::UGDataset::Network:
		case UGC::UGDataset::Image:
			break;

		default:
			break;
		}
	}
	if(NULL == m_pRetByteArray)
	{
		return NULL;
	}
	else
	{
		return FDO_SAFE_ADDREF(m_pRetByteArray.p);
	}
}



