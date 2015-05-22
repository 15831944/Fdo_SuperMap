/** \file	 SuperMapGeoToFgfGeo.h
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-09
*/

#ifndef __SUPERMAP_GEOTOFGFGEO_H__
#define __SUPERMAP_GEOTOFGFGEO_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapGeoToFgfGeo SuperMapGeoToFgfGeo.h
	\brief ���ζ���ת������UGC��FDO�����ڲ�ѯ����ʱ
    return ��FdoByteArray ����ʽ����FDO���ζ���
*/

class SuperMapGeoToFgfGeo
{
public:
	SuperMapGeoToFgfGeo(void);
	SuperMapGeoToFgfGeo(UGC::UGRecordset *pRecordset);

public:
	virtual ~SuperMapGeoToFgfGeo(void);

public:
	/*
		\brief �õ�ת�����FDO���ζ���
		\return ��FdoByteArray ����ʽ����FDO���ζ���
		\note UGC�ļ�¼������Ϊ��
	*/
	FdoByteArray *GetGeometry();

private:
	/*
		\brief �Զ�ά����ʽ����FDO���ζ���, �����㡢�ߡ��桢CAD���ݼ��еļ��ζ���
		\note m_pElemGeometry ����Ϊ��
	*/
	void CreateFdoGeo();

	/*
		\brief �Զ�ά����ʽ����FDO��
		\note m_pElemGeometry ����Ϊ��
	*/
	void CreateFdoPoint();

	/*
		\brief �Զ�ά����ʽ����FDO����
		\note m_pElemGeometry ����Ϊ��
	*/
	void CreateFdoMultiLine();

	/*
		\brief �Զ�ά����ʽ����FDO��
		\note m_pElemGeometry ����Ϊ��
	*/
	void CreateFdoPolygon();

	/*
		\brief �Զ�ά����ʽ����CAD���ݼ�����϶����Ӧ��FDO���ζ��󣬰������ּ��ζ���
		\note m_pElemGeometry ����Ϊ��
	*/
	void CreateFdoCompoundGeometry();

	/*
		\brief �õ�UGC��ϼ��ζ���Ŀռ�����
		\param[in] ָ����϶����ָ��
		\param[out] ��ż��ζ���ռ����ݵ�����
		\param[out] ��Ÿ����Ӷ������������
		\param[out] �Ӷ�������
		\param[out] ����ϼ��϶����Ӷ��������
 		\note pGeometry ����Ϊ�գ������ڵݹ���ã�����༶��϶�������
	*/
	void GetCompoundSpatialData(UGC::UGGeometry *pGeometry, 
								UGC::UGArray<UGC::UGPoint2D> &points, 
								UGC::UGArray<UGC::UGint> &nSubPointsCount, 
								UGC::UGint &nSubCount,
								UGC::UGint &nGeoType);

	/*
		\brief �ж���ϼ��ζ���������Ӷ���������Ƿ�һ�� 
		\param[in] pGeometry ָ����϶����ָ��
		\param[in] bFirstCall ��־�Ƿ��ǵ�һ�ε��ã��ﵽ�������ζ�������ͻ���Ӱ��
		\return ��������Ӷ�������Ͷ�һ���Ļ��������棬���ⷵ�ؼ�
 		\note pGeometry����Ϊ�գ������ڵݹ���ã�����༶��϶�������
	*/
	bool IsSameCompoundGeometry(UGC::UGGeometry *pCompoundGeometry, bool bFirstCall);

private:
	UGC::UGRecordset *m_pRecordset;					//UGC��¼�� 
	UGC::UGGeometry *m_pElemGeometry;				//�Ӽ�¼����ȡ���ļ��ζ����ָ��
	UGC::UGArray<double> m_fdoCoordinatesArray;		//��Ź���FDO���ζ������������
	FdoPtr<FdoByteArray> m_pRetByteArray;			//��Fgf��ʽ���ص�FDO���ζ��������ָ��
	FdoFgfGeometryFactory *m_pFdoGeoFactory;		//FGF���ι���

	UGC::UGAutoPtr<UGC::UGPoint2D> m_points;		//��������Ӷ���������Ϣ������
	UGC::UGAutoPtr<UGC::UGint> m_subPointsCount;	//UGC���ζ�������Ӷ������������
	UGC::UGint m_nSubCount;							//UGC���ζ����Ӷ���ĸ���
};


#endif // __SUPERMAP_GEOTOFGFGEO_H__