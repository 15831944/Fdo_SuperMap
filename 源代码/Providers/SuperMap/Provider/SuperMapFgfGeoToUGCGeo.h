/** \file	 SuperMapFgfGeoToUGCGeo.h
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-12
*/

#ifndef __SUPERMAP_FGFGEOTOUGCGEO_H__
#define __SUPERMAP_FGFGEOTOUGCGEO_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapFgfGeoToUGCGeo SuperMapFgfGeoToUGCGeo.h
	\brief ת�����ζ��󣬴�FDO��UGC�����ڲ�����߸��µĲ���
    return ָ��UGC���ζ����ָ��
*/

class SuperMapFgfGeoToUGCGeo
{
public:
	SuperMapFgfGeoToUGCGeo(void);
	SuperMapFgfGeoToUGCGeo(FdoByteArray *byteArray, bool IsTextDataset = false, 
		                   UGC::UGString strText = "", double textSize = 0.0, 
						   bool IsCADDataset = false, bool IsSpatialCondition = false); //modified by zhoux

public:
	/*
		\brief ת�����ζ��󣬴�FDO��UGC
		\return ָ��UGC���ζ����ָ��
		\note m_FgfArray����Ϊ��
	*/
	UGC::UGGeometry *GetGeometry();

private:

	/*
		\brief ����UGC��
		\param [in]pFgfArray ��ά�ȿ�ʼ�ģ�ָ��FDO���ζ���
		\param [in]bMultiPoint  �Ƿ񴴽����ı�־��ȱʡΪ�٣����ڴ���CAD���ݼ�ʱ�ж��Ŀ���
		\note m_FgfArray����Ϊ��
	*/
	void CreateUGCPoint(const int *pFgfArray, bool bMultiPoint = false);

	/*
		\brief ����UGC��
		\param [in]pFgfArray ��ά�ȿ�ʼ�ģ�ָ��FDO���ζ���
		\param [in]bMultiLine  �Ƿ񴴽����ߵı�־��ȱʡΪ��
		\note m_FgfArray����Ϊ��
	*/
	void CreateUGCLine(const int *pFgfArray, bool bMultiLine = false);

	/*
		\brief ����UGC��
		\param [in]pFgfArray ��ά�ȿ�ʼ�ģ�ָ��FDO���ζ���
		\param [in]bMultiPolygon  �Ƿ񴴽�����ı�־��ȱʡΪ��
		\note m_FgfArray����Ϊ��
	*/
	//void CreateUGCRegion(const int *pFgfArray);
	void CreateUGCRegion(const int *pFgfArray, bool bMultiPolygon = false);

	/*
		\brief ����UGC�ı�
		\param [in]pFgfArray ��ά�ȿ�ʼ��ָ��FDO�����
		\note m_FgfArray����Ϊ��
	*/
	void CreateUGCText(const int *pFgfArray);             // added by zhouxu


	/*
		\brief ���������������ڴ���UGC��ά������ά�㣬Ŀǰ�򵥵ĺ��Ե���ά
		\param [in]nPointNum ���������ڵ����ݼ���ֵΪ1������CAD���ݼ�����1 
		\param [in]pUGCGeoArray  ��������
		\param [in]bMultiLine  �Ƿ񴴽����ı�־��ȱʡΪ��
	*/
	void CreateUGC_XYPoint(int nPointNum, double *pUGCGeoArray, bool bMultiPoint = false);
	void CreateUGC_XYZPoint(int nPointNum, double *pUGCGeoArray, bool bMultiPoint = false);

	/*
		\brief ���������������ڴ���UGC��ά������ά�ߣ�Ŀǰ�򵥵ĺ��Ե���ά
		\param [in]nLineNum ���������ڼ��ߣ�ֵΪ1�����ڸ����ߣ���Ϊ1 
		\param [in]nPointsNum ��һ���ߵĵ���
		\param [in]pUGCGeoArray  ָ�������ߵ���������
		\param [in]bMultiPolygon  �Ƿ񴴽����ߵı�־��ȱʡΪ��
	*/
	void CreateUGC_XYLine(int nLineNum, int nPointsNum, double *pUGCGeoArray);
	void CreateUGC_XYZLine(int nLineNum, int nPointsNum, double *pUGCGeoArray);

	/*
		\brief ���������������ڴ���UGC��ά������ά�棬Ŀǰ�򵥵ĺ��Ե���ά
		\param [in]nPolygonNum ���� 
		\param [in]nRingPtsNum ��һ�����ĵ���
		\param [in]pUGCGeoArray  ָ�����л�����������
		\param [in]bMultiPolygon  �Ƿ񴴽�����ı�־��ȱʡΪ��
	*/
	void CreateUGC_XYRegion(int nPolygonNum, int nRingNum, int nRingPtsNum, double *pUGCGeoArray);
	void CreateUGC_XYZRegion(int nPolygonNum, int nRingNum, int nRingPtsNum, double *pUGCGeoArray);

private:
	UGC::UGGeometry *m_pUGGeometry;		//ָ��UGC���ζ����ָ�룬������ʹ����Ϻ�����ͷſռ䣬�����ڴ�й¶ 
	FdoPtr<FdoByteArray> m_FgfArray;	//ָ��FDO���ζ����ָ��
	bool m_IsCADDataset;				//�ж�ʱ����CAD���ݼ������ڴ���������
	bool m_IsSpatialCondition;			//�ж��Ƿ��ǿռ��ѯ���ռ��ѯʱ����ά�Ͷ������

protected:    // added by zhouxu 
	bool m_IsPointOfTextDataset;		//�����ж��Ƿ��ı����ݼ��ĵ�
	UGC::UGString m_strText;			//�洢�ı����ݼ����ı�����
	double m_dTextSize;					//���ı���С
	
public:
	virtual ~SuperMapFgfGeoToUGCGeo(void);
};

#endif // __SUPERMAP_FGFGEOTOUGCGEO_H__
