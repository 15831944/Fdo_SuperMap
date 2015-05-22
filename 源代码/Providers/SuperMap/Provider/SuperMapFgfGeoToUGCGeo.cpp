/** \file	 SuperMapFgfGeoToUGCGeo.cpp
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-12
*/

#include "SuperMap.h"

SuperMapFgfGeoToUGCGeo::SuperMapFgfGeoToUGCGeo(void)
{

}

SuperMapFgfGeoToUGCGeo::~SuperMapFgfGeoToUGCGeo(void)
{

}

//TODO::�ع������������ѡENUM���͵�ֵ��������չ

SuperMapFgfGeoToUGCGeo::SuperMapFgfGeoToUGCGeo
	(FdoByteArray *byteArray, 
	 bool IsTextDataset, 
	 UGC::UGString strText,
	 double textSize, 
	 bool IsCADDataset, 
	 bool IsSpatialCondition) // added by zhoux
{
	m_FgfArray = byteArray;
	m_pUGGeometry = NULL;
	m_IsPointOfTextDataset = IsTextDataset;
	m_strText = strText;
	m_dTextSize = textSize;
	m_IsCADDataset = IsCADDataset;
	m_IsSpatialCondition = IsSpatialCondition;
}

void SuperMapFgfGeoToUGCGeo::CreateUGCPoint(const int *pFgfArray, bool bMultiPoint)
{
	if(NULL == pFgfArray)
	{
		return;
	}

	int nPointNum = 1; // ��������������²�Ϊ1
	if(bMultiPoint) // ������
	{
		nPointNum = *(pFgfArray++); //����
		pFgfArray++; //����
	}
	int nDimenType = *(pFgfArray++); //Dimensionality
	double *pUGCGeoArray = (double*)pFgfArray; //ָ����ʼ����

	switch(nDimenType)
	{
	case FdoDimensionality_XY: //XY
		CreateUGC_XYPoint(nPointNum, pUGCGeoArray, bMultiPoint);
		break;

	case FdoDimensionality_Z: //XYZ
		CreateUGC_XYZPoint(nPointNum, pUGCGeoArray, bMultiPoint);
		break;

	case FdoDimensionality_M: //XYM
		break;
	case FdoDimensionality_Z | FdoDimensionality_M: //XYZM
		break;
	default:
		break;
	}
}

void SuperMapFgfGeoToUGCGeo::CreateUGC_XYPoint(int nPointNum, double *pUGCGeoArray, bool bMultiPoint)
{

	if(NULL == pUGCGeoArray)
	{
		return;
	}

	UGC::UGArray<UGC::UGPoint2D> UGCPointsArray;
	for(int pointcount = 1; pointcount <= nPointNum; pointcount++)
	{
		UGC::UGPoint2D point;
		point.x = *(pUGCGeoArray++);
		point.y = *(pUGCGeoArray++);
		pUGCGeoArray++; //ע�⣬��Ȼ��FDOά���Ƕ�ά��������������Zֵ����Ϊ0!!! ̫�����!!!
		UGCPointsArray.Add(point);
	}

	if(bMultiPoint)
	{
		//m_pUGGeometry = new UGC::UGGeoMultiPoint(); //����UGC���
		m_pUGGeometry = new UGC::UGGeoCompound(); //����UGC���,ʹ�ø��϶���ķ�ʽ�������ܱ༭�ö�����
	}
	else
	{
		m_pUGGeometry = new UGC::UGGeoPoint(); //����UGC��
	}

	if(m_pUGGeometry)
	{
		UGC::UGbool bCreateRet;
		if(bMultiPoint)
		{
			//bCreateRet = ((UGC::UGGeoMultiPoint *)m_pUGGeometry)->Make(UGCPointsArray.GetData(), nPointNum);
			UGC::UGGeoPoint *pPointGeometry = NULL;	
			for(int pointcount = 1; pointcount <= nPointNum; pointcount++)
			{
				pPointGeometry = new UGC::UGGeoPoint(); 
				bCreateRet = pPointGeometry->Make(UGCPointsArray.GetAt(pointcount - 1));
				if(!bCreateRet)
				{
					delete pPointGeometry;
					pPointGeometry = NULL;
					break;
				}
				((UGC::UGGeoCompound *)m_pUGGeometry)->AddCompound(pPointGeometry);
			}
		}
		else
		{
			bCreateRet = ((UGC::UGGeoPoint *)m_pUGGeometry)->Make(UGCPointsArray.GetAt(0));
		}

		if(!bCreateRet) 
		{
			delete m_pUGGeometry;
			m_pUGGeometry = NULL;
		}
	}
}

// �ú���Ŀǰ��CreateUGC_XYPoint()������ͬ
void SuperMapFgfGeoToUGCGeo::CreateUGC_XYZPoint(int nPointNum, double *pUGCGeoArray, bool bMultiPoint)
{
	CreateUGC_XYPoint(nPointNum, pUGCGeoArray, bMultiPoint);
}

void SuperMapFgfGeoToUGCGeo::CreateUGCLine(const int *pFgfArray, bool bMultiLine)
{
	if(NULL == pFgfArray)
	{
		return;
	}

	int nLineNum = 1; //���������ߵ����ֵ��Ϊ1
	if(bMultiLine) // �������
	{
		nLineNum = *(pFgfArray++); //����
		pFgfArray++; //������
	}
	int nDimenType = *(pFgfArray++); //ά��
	int nPointsNum = *(pFgfArray++); //����
	double *pUGCGeoArray = (double*)pFgfArray; //ָ����ʼ����

	switch(nDimenType)
	{
	case FdoDimensionality_XY: //XY		
		CreateUGC_XYLine(nLineNum, nPointsNum, pUGCGeoArray);
		break;

	case FdoDimensionality_Z: //XYZ
		CreateUGC_XYZLine(nLineNum, nPointsNum, pUGCGeoArray);
		break;

	case FdoDimensionality_M: //XYM
		break;
	case FdoDimensionality_Z | FdoDimensionality_M: //XYZM
		break;
	default:
		break;
	}
}

void SuperMapFgfGeoToUGCGeo::CreateUGC_XYLine(int nLineNum, int nPointsNum, double *pUGCGeoArray)
{
	if(NULL == pUGCGeoArray)
		return;

	UGC::UGArray<int> nSubPointsNum;
	UGC::UGArray<UGC::UGPoint2D> UGCPointsArray;

	for(int linecount = 1; linecount <= nLineNum; linecount++) //����
	{
		nSubPointsNum.Add(nPointsNum);
		for(int ptindex = 1; ptindex <= nPointsNum; ptindex++) //ÿһ���ߵĵ���
		{
			UGC::UGPoint2D point;
			point.x = *(pUGCGeoArray++);
			point.y = *(pUGCGeoArray++);
			UGCPointsArray.Add(point);
		}
		int *pNextLine = (int *)pUGCGeoArray; //��һ���ߵ�����
		pNextLine++; //��һ���ߵ�ά��
		pNextLine++; //��һ���ߵĵ���
		nPointsNum = *(pNextLine++);
		pUGCGeoArray = (double *)pNextLine;
	}
	m_pUGGeometry = new UGC::UGGeoLine(); //����UGC�߶���
	if(m_pUGGeometry)
	{
		UGC::UGbool bCreateRet = ((UGC::UGGeoLine *)m_pUGGeometry)->Make(UGCPointsArray.GetData(), nSubPointsNum.GetData(), nLineNum);
		if(!bCreateRet) 
		{
			delete m_pUGGeometry;
			m_pUGGeometry = NULL;
		}
	}
}

//Ŀǰ���ڿռ��ѯ�������Ե���ά���Ժ������չ
void SuperMapFgfGeoToUGCGeo::CreateUGC_XYZLine(int nLineNum, int nPointsNum, double *pUGCGeoArray)
{
	UGC::UGArray<int> nSubPointsNum;
	UGC::UGArray<UGC::UGPoint2D> UGCPointsArray;

	for(int linecount = 1; linecount <= nLineNum; linecount++) //����
	{
		nSubPointsNum.Add(nPointsNum);
		for(int ptindex = 1; ptindex <= nPointsNum; ptindex++) //ÿ���ߵ���
		{
			UGC::UGPoint2D point;
			point.x = *(pUGCGeoArray++);
			point.y = *(pUGCGeoArray++);
			pUGCGeoArray++; //Ŀǰֻ���Ե���ά
			UGCPointsArray.Add(point);
		}
		int *pNextLine = (int *)pUGCGeoArray; //��һ��������
		pNextLine++; //��һ����ά��
		pNextLine++; //��һ���ߵ���
		nPointsNum = *(pNextLine++);
		pUGCGeoArray = (double *)pNextLine;
	}
	m_pUGGeometry = new UGC::UGGeoLine(); //����UGC�߶���
	if(m_pUGGeometry)
	{
		UGC::UGbool bCreateRet = ((UGC::UGGeoLine *)m_pUGGeometry)->Make(UGCPointsArray.GetData(), nSubPointsNum.GetData(), nLineNum);
		if(!bCreateRet) 
		{
			delete m_pUGGeometry;
			m_pUGGeometry = NULL;
		}
	}
}

void SuperMapFgfGeoToUGCGeo::CreateUGCRegion(const int *pFgfArray, bool bMultiPolygon)
{
	if(NULL == pFgfArray)
	{
		return;
	}
	int nPolygonNum = 1;
	if(bMultiPolygon)
	{
		nPolygonNum = *(pFgfArray++); //�������
		pFgfArray++; //���������
	}

	int nDimenType = *(pFgfArray++); //ά��
	int nRingNum = *(pFgfArray++); //����
	int nRingPtsNum = *(pFgfArray++); //��һ�����ĵ���
	double *pUGCGeoArray = (double*)pFgfArray; //ָ���һ��������ʼ����

	switch(nDimenType)
	{
	case FdoDimensionality_XY: //XY		
		CreateUGC_XYRegion(nPolygonNum, nRingNum, nRingPtsNum, pUGCGeoArray);
		break;

	case FdoDimensionality_Z: //XYZ 
		CreateUGC_XYZRegion(nPolygonNum, nRingNum, nRingPtsNum, pUGCGeoArray);
		break;

	case FdoDimensionality_M: //XYM
		break;
	case FdoDimensionality_Z | FdoDimensionality_M: //XYZM
		break;
	default:
		break;
	}
}

void SuperMapFgfGeoToUGCGeo::CreateUGC_XYRegion(int nPolygonNum, int nRingNum, int nRingPtsNum, double *pUGCGeoArray)
{
	if(NULL == pUGCGeoArray)
	{
		return;
	}

	UGC::UGArray<UGC::UGPoint2D> UGCPointsArray;
	for(int polygoncount = 1; polygoncount <= nPolygonNum; polygoncount++) //�������
	{
		for(int ring = 1; ring <= nRingNum; ring++) //����
		{
			for(int ptindex = 1; ptindex <= nRingPtsNum; ptindex++) //ÿ�����ĵ���
			{
				UGC::UGPoint2D point;
				point.x = *(pUGCGeoArray++);
				point.y = *(pUGCGeoArray++);
				UGCPointsArray.Add(point);
			}

			if(NULL == m_pUGGeometry) //��û�д������ζ���
			{
				m_pUGGeometry = new UGC::UGGeoRegion(); //�������ζ���
				if(m_pUGGeometry)
				{
					UGC::UGbool bCreateRet = ((UGC::UGGeoRegion *)m_pUGGeometry)->Make(UGCPointsArray.GetData(), nRingPtsNum);
					if(!bCreateRet) 
					{
						delete m_pUGGeometry;
						m_pUGGeometry = NULL;
					}
				}
			}
			else //����Ѿ������˼��ζ��󣬽�����Ӷ���
			{
				UGC::UGbool bAddRet = ((UGC::UGGeoRegion *)m_pUGGeometry)->AddSub(UGCPointsArray.GetData(), nRingPtsNum);
				if(!bAddRet) 
				{
					delete m_pUGGeometry;
					m_pUGGeometry = NULL;
				}

			}
			if(ring < nRingNum)
			{
				int *pNextRingPtsNum = (int *)pUGCGeoArray;
				nRingPtsNum = *(pNextRingPtsNum++);
				pUGCGeoArray = (double *)pNextRingPtsNum;
			}
			UGCPointsArray.RemoveAll();
		}
		int *pNextPolygonType = (int *)pUGCGeoArray; //��һ�����������
		pNextPolygonType++; //��һ�������ά��
		pNextPolygonType++; //��һ������λ���
		nRingNum = *(pNextPolygonType++); //��һ������εĻ���
		nRingPtsNum = *(pNextPolygonType++); //��һ������ε�һ�����ĵ���
		pUGCGeoArray = (double *)pNextPolygonType; 
	}
}


////Ŀǰ���ڿռ��ѯ�������Ե���ά���Ժ������չ
void SuperMapFgfGeoToUGCGeo::CreateUGC_XYZRegion(int nPolygonNum, int nRingNum, int nRingPtsNum, double *pUGCGeoArray)
{
	UGC::UGArray<UGC::UGPoint2D> UGCPointsArray;
	for(int polygoncount = 1; polygoncount <= nPolygonNum; polygoncount++) //����θ���
	{
		for(int ring = 1; ring <= nRingNum; ring++) //����λ���
		{
			for(int ptindex = 1; ptindex <= nRingPtsNum; ptindex++) //ÿ�����ĵ���
			{
				UGC::UGPoint2D point;
				point.x = *(pUGCGeoArray++);
				point.y = *(pUGCGeoArray++);
				pUGCGeoArray++; //�����Ե���ά
				UGCPointsArray.Add(point);
			}
			if(NULL == m_pUGGeometry) //��û�д������ζ���
			{
				m_pUGGeometry = new UGC::UGGeoRegion(); //�������ζ���
				if(m_pUGGeometry)
				{
					UGC::UGbool bCreateRet = ((UGC::UGGeoRegion *)m_pUGGeometry)->Make(UGCPointsArray.GetData(), nRingPtsNum);
					if(!bCreateRet) 
					{
						delete m_pUGGeometry;
						m_pUGGeometry = NULL;
					}
				}
			}
			else //����Ѿ������˼��ζ��󣬽�����Ӷ���
			{
				UGC::UGbool bAddRet = ((UGC::UGGeoRegion *)m_pUGGeometry)->AddSub(UGCPointsArray.GetData(), nRingPtsNum);
				if(!bAddRet) 
				{
					delete m_pUGGeometry;
					m_pUGGeometry = NULL;
				}

			}
			if(ring < nRingNum)
			{
				int *pNextRingPtsNum = (int *)pUGCGeoArray;
				nRingPtsNum = *(pNextRingPtsNum++);
				pUGCGeoArray = (double *)pNextRingPtsNum;
			}
			UGCPointsArray.RemoveAll();
		}
		int *pNextPolygonType = (int *)pUGCGeoArray; //��һ�����������
		pNextPolygonType++; //��һ�������ά��
		pNextPolygonType++; 
		nRingNum = *(pNextPolygonType++); //��һ������λ���
		nRingPtsNum = *(pNextPolygonType++); //��һ������ε�һ�����ĵ���
		pUGCGeoArray = (double *)pNextPolygonType; 
	}
}

void SuperMapFgfGeoToUGCGeo::CreateUGCText(const int *pFgfArray)   // added by zhoux
{
	if(NULL == pFgfArray)
	{
		return;
	}
	int nDimenType = *(pFgfArray++); //ά��
	double *pUGCGeoArray = (double*)pFgfArray; //��ʼ����
	switch(nDimenType)
	{
	case FdoDimensionality_XY: //ʵ�����ı����ݼ��Ķ�λ��϶��Ƕ�ά          
		m_pUGGeometry = new UGC::UGGeoText(); 
		if(m_pUGGeometry)
		{
			UGC::UGPoint2D pointxy;
			pointxy.x = *pUGCGeoArray;
			pUGCGeoArray++;
			pointxy.y = *pUGCGeoArray;
			UGC::UGbool bCreateRet = ((UGC::UGGeoText *)m_pUGGeometry)->Make(m_strText,pointxy);
			UGC::UGTextStyle textStyle;
			textStyle.SetHeight(m_dTextSize);
			((UGC::UGGeoText *)m_pUGGeometry)->SetTextStyle(textStyle);
			if(!bCreateRet) //execute Make not successfully
			{
				TRACE(_T("SuperMapFgfGeoToUGCGeo::�ı�����ʧ��!... \n"));
				delete m_pUGGeometry;
				m_pUGGeometry = NULL;
			}
		}
		break;

	case FdoDimensionality_Z: //XYZ
		break;

	case FdoDimensionality_M: //XYM
		break;

	case FdoDimensionality_Z | FdoDimensionality_M: //XYZM
		break;
	default:
		break;
	}

}

UGC::UGGeometry *SuperMapFgfGeoToUGCGeo::GetGeometry()
{
	int *pGeoArray = (int*)m_FgfArray->GetData();
	int nFgfGeoType = *(pGeoArray++);
	switch(nFgfGeoType)
	{
	case FdoGeometryType_Point: //fgf point
		{
			if(m_IsPointOfTextDataset)              // modified by zhouxu
			{
				CreateUGCText(pGeoArray);
			}
			else
			{
				CreateUGCPoint(pGeoArray, false);
			}
			break;
		}
	case FdoGeometryType_MultiPoint: //fgf multipoint
		{
			if(m_IsCADDataset || m_IsSpatialCondition)
			{
				CreateUGCPoint(pGeoArray, true);
			}
			else
			{
				throw FdoException::Create (NlsMsgGet (SUPERMAP_POINT_FEATURE_SOURCE_NOT_SUPPORT_MULTIPOINT, "Multipoint is not supported."));
			}
			break;
		}
	case FdoGeometryType_LineString: //fgf line
		CreateUGCLine(pGeoArray, false);
		break;

	case FdoGeometryType_MultiLineString: //fgf multiline
		CreateUGCLine(pGeoArray, true);
		break;

	case FdoGeometryType_Polygon: //fgf polygon
		CreateUGCRegion(pGeoArray, false);
		break;

	case FdoGeometryType_MultiPolygon: //fgf multipolygon
		CreateUGCRegion(pGeoArray, true);
		break;

	case FdoGeometryType_MultiGeometry: //fgf multigeometry
		break;

	case FdoGeometryType_CurveString: //fgf curve
		break;

	case FdoGeometryType_CurvePolygon: //fgf curve polygon
		break;

	case FdoGeometryType_MultiCurveString: //fgf multi curve
		break;

	case FdoGeometryType_MultiCurvePolygon: //fgf multi curve polygon
		break;

	default:
		break;
	}
	return m_pUGGeometry;
}