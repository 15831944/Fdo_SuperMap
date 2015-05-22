/** \file	 SuperMapGeometryCapabilities.cpp
 *  \author	 ����
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */


#include "SuperMap.h"

SuperMapGeometryCapabilities::SuperMapGeometryCapabilities ()
{
}

SuperMapGeometryCapabilities::~SuperMapGeometryCapabilities ()
{
}

void SuperMapGeometryCapabilities::Dispose()
{
    delete this;
}

/// <summary>Return the list of supported geometry types. For example, if a client wanted to know if a provider supported
/// multi-polygons, it would call GetGeometryTypes and check if the MultiPolygon type was listed.</summary>
/// <param name="length">Output the number of geometry types.</param> 
/// <returns>Returns the list of geometry types</returns> 
FdoGeometryType* SuperMapGeometryCapabilities::GetGeometryTypes (FdoInt32& length)
{
	TRACE(_T("���� SuperMapGeometryCapabilities::GetGeometryTypes()... \n"));
    static const FdoGeometryType geomTypes[] =
    {
	
        FdoGeometryType_Point,
        FdoGeometryType_LineString,
        FdoGeometryType_Polygon,
        FdoGeometryType_MultiPoint,			
        FdoGeometryType_MultiLineString,	// ֧�ֶ�㡢����
		FdoGeometryType_MultiPolygon,

		FdoGeometryType_MultiGeometry

		/*shp
		FdoGeometryType_Point,
        FdoGeometryType_LineString,
        FdoGeometryType_Polygon,
        FdoGeometryType_MultiPoint,
        FdoGeometryType_MultiLineString,
		*/
	};

    length = ELEMENTS(geomTypes);
    return ((FdoGeometryType *)geomTypes);
}

/// <summary>Return the list of supported component types. For example, if a client wanted to know if circular arcs were supported 
/// by a provider, it would call GetGeometryComponentTypes and check for CircularArcSegment in the returned list.</summary>
/// <param name="length">Output the number of component types.</param> 
/// <returns>Returns the list of component types</returns> 
FdoGeometryComponentType* SuperMapGeometryCapabilities::GetGeometryComponentTypes (FdoInt32& length)
{
	TRACE(_T("���� SuperMapGeometryCapabilities::GetGeometryComponentTypes()... \n"));
    static const FdoGeometryComponentType geomComponentTypes[] =
    {
		//TODO::��ʵ�ֺ��ٴ� 
	//	FdoGeometryComponentType_CircularArcSegment,           
	// 	FdoGeometryComponentType_Ring,          
        FdoGeometryComponentType_LinearRing,
        FdoGeometryComponentType_LineStringSegment	// ֧����ϼ������� //added by zhouxu 2008-1-14
    };
    length = ELEMENTS(geomComponentTypes);
    return ((FdoGeometryComponentType *)geomComponentTypes);
	/*shp
	FdoGeometryComponentType_LinearRing,
	FdoGeometryComponentType_LineStringSegment,
	*/
}

/// <summary>Returns the supported dimensionalities which are based on the bit masks defined in the FdoDimensionality enum. 
/// The Z and M bits indicate if the provider supports 3d or Measure dimensions in geometry data. The XY bit should be set too.</summary>
/// <returns>Returns the dimensionalities</returns> 
FdoInt32 SuperMapGeometryCapabilities::GetDimensionalities ()
{
	TRACE(_T("���� SuperMapGeometryCapabilities::GetDimensionalities()... \n"));
    return (FdoDimensionality_XY);//Ŀǰ��֧�ֶ�ά | FdoDimensionality_Z | FdoDimensionality_M);	//֧����ά
}

