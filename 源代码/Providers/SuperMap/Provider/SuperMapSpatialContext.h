/** \file	 SuperMapSpatialContext.h
*  \brief    ������Ҫ����洢SuperMap��������Դ�Ŀռ�������Ϣ
*  \author	 �� ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-14
*/

#ifndef __SUPERMAP_SPATIAL_CONTEXT_H__
#define __SUPERMAP_SPATIAL_CONTEXT_H__

#ifdef _WIN32
#pragma once
#endif

class SuperMapSpatialContext : public FdoDisposable
{

public:
	SuperMapSpatialContext();
	virtual ~SuperMapSpatialContext();

	virtual FdoString* GetName();
	virtual void SetName(FdoString* Name);
	virtual FdoString* GetDescription();
	virtual void SetDescription(FdoString* desc);
	virtual FdoString* GetCoordSysName();
	virtual void SetCoordSysName(FdoString* csName);
	virtual FdoString* GetCoordinateSystemWkt ();
    virtual void SetCoordinateSystemWkt (FdoString* wkt);
	virtual FdoSpatialContextExtentType GetExtentType ();
    virtual void SetExtentType (FdoSpatialContextExtentType type);
	 virtual FdoByteArray* GetExtent ();
    virtual void SetExtent (FdoByteArray* extent);
    virtual double GetXYTolerance ();
    virtual void SetXYTolerance (double tol);
    virtual double GetZTolerance ();
    virtual void SetZTolerance (double tol);

	// To please FdoNamedCollection:
    virtual FdoBoolean CanSetName() { return true; }

private:
	FdoStringP m_Name;             // ��ռ�������
    FdoStringP m_Description;      // ��ռ���������
    FdoStringP m_CoordSysName;     // ������ϵ����
    FdoStringP m_Wkt;              // ��WKT��ʽ��ʾ�ռ�������Ϣ���ڵ�һ�ε���GetCoordinateSystemWktʱ���г�ʼ��

    FdoSpatialContextExtentType m_ExtentType;
    FdoPtr<FdoByteArray> m_Extent;

	double m_XYTolerance;
    double m_ZTolerance;

	/// ��Ҫ�Ŀռ�������Ϣ���������WKT�ı�ʱҲ����ǰ����,���г�Ա�������ڲ�ʹ�ã�
public:
	FdoStringP m_ProjectName;      //  ͶӰ����
	FdoStringP m_DatumName;        //  ��׼���� DATUM
	FdoStringP m_SpheroidName;     //  ��������
	double m_dSemiMajor;           //  �����峤���᳤��
	double m_dInvflattening;       //  ��������ʵ��� 
	FdoStringP m_PrimeMeridian;    //  ���������ߣ�0�Ⱦ��ߣ�ͨ��Ϊ"Greenwich"
	FdoStringP m_GeoUnit;          //  ��λ	
	FdoStringP m_GeoUnitFactor;    //  �Ƕȵ�λΪ�����ȵĻ���ϵ����1�� = 0.0174532925199433 ���ȡ�
	FdoStringP m_Unit;
	FdoStringP m_UnitFactor;       //  ���ȵ�λΪ���׵Ļ���ϵ���� 1cm = 0.01m��
	                             

	// ͶӰ����
	double m_dFalseEasting;			//  0 False easting (X0)
	double m_dFalseNorthing;		//  1 False northing (Y0)
	double m_dCentralMeridian;		//  2 Central meridian, Longitude of origin (LON0)
	double m_dCentralParallel;		//  6 Central parallel, Latitude of origin	(LAT0)

	double m_dStandardParallel1;	//  3 Standard parallel 1, Latitude of 1st point (LAT1)
	double m_dStandardParallel2;	//  4 Standard parallel 2, Latitude of 2nd point (LAT2)

	double m_dScaleFactor;			//  5 Scale factor
	double m_dAzimuth;				//  7 Azimuth

	double m_dFirstPointLongitude;		//  8 Longitude of 1st point (LON1)
	double m_dSecondPointLongitude;		//  9 Longitude of 2nd point  (LON2)

	UGC::EmSpatialRefType m_eType;
};


class SuperMapSpatialContextCollection : public FdoNamedCollection<SuperMapSpatialContext, FdoException>
{
public:
	SuperMapSpatialContextCollection(void){}
	
protected:
	virtual ~SuperMapSpatialContextCollection(void){}

	virtual void Dispose()
	{
		delete this;
	}
};


#endif //__SUPERMAP_SPATIAL_CONTEXT_H__