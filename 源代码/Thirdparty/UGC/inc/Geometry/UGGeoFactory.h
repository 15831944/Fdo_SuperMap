/*! \file	 UGGeoFactory.h
 *  \brief	 ��������Geometry�Ĺ�����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGGeoFactory.h,v 1.11 2007/11/09 00:52:16 lugw Exp $
 */


#if !defined(AFX_UGGEOFACTORY_H__78297849_2C23_469A_A6B2_24C8E982EE63__INCLUDED_)
#define AFX_UGGEOFACTORY_H__78297849_2C23_469A_A6B2_24C8E982EE63__INCLUDED_

#include "Base/ugdefs.h"
#include "UGGeometry.h"

namespace UGC{

//added by xielin 2007-04-30 
//! \brief �ص�������������չ�������
//! \param 		pGeometry		�ⲿҪ��������չ����
//! \param 		eGeoType		��չ���������
//! \param 		pWnd			ʵ�ָûص����������ָ��
typedef void (UGSTDCALL *CREATECUSTOMGEOMETRYCALLBACKPROC)
(UGGeometry** pGeometry,UGint eGeoType,UGlong pWnd);


//! \brief ��������Geometry�Ĺ�����
class GEOMETRY_API UGGeoFactory
{
private: // �������ù�����Ķ����밴��UGGeoFactory::Fun()����ʽֱ��ʹ�þ�̬����
	UGGeoFactory();

public:
	//! \brief ����Geometry���ͣ�����Geometry
	//! \param eGeoType Ҫ������Geometry������
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	static UGGeometry* CreateGeometry(UGGeometry::Type eGeoType);

	//! \brief �������ͺ����ݣ����ɹ���õ�Geometry
	//! \param eGeoType Ҫ������Geometry������
	//! \param pData ������ָ��
	//! \param nSize ��������С(�ֽ�)
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	static UGGeometry* CreateGeometry(UGGeometry::Type eGeoType, 
								const UGbyte* pData, UGint nSize);
	//! \brief ��¡Geometry
	//! \param pGeometry Ҫ����¡��Geometry����ָ��, ����ΪNULL
	//! \attention ���ص�Geometryָ��, ��ʹ�ú�delete
	//! \return �ɹ�,���ش�����Geometry��ָ��; ʧ�ܷ���NULL
	static UGGeometry* CloneGeometry(const UGGeometry* pGeometry);

	//! \brief ����������������UGGeometry::Type
	//! \param strGeometryType ���ζ������͵�����
	//! \attention �ϸ����ִ�Сд, �����"GeoPoint"����ʽ
	//! \return �ɹ����ؼ��ζ�������ö��, ʧ�ܷ���UGGeometry::Null
	static UGGeometry::Type GetGeometryType(const UGString& strGeometryType);
	
	//! \brief ����Geometry
	//! \param pGeometrySrc ԭGeometryָ��, ����ΪNULL
	//! \param pGeometryTag Ŀ��Geometryָ��, ����ΪNULL
	//! \remarks ����Geometry�������ͱ���һ��
	//! \return �ɹ�����true,ʧ�ܷ���false
	static UGbool CopyGeometry(const UGGeometry* pGeometrySrc, UGGeometry* pGeometryTag);

	//! \brief ȷ��pGeometry��ָ��������
	//! \param pGeometry ���ζ���ָ��
	//! \param eType ָ��������
	//! \remarks ��������Ҫ����: �����洫��һ�����ζ�������, ���п���ΪNULL, Ҳ�п��ܲ�����Ҫ������
	//!			 ��ʱ,����Ҫ ���·��� Geometryָ��,new ����Ҫ���͵�Geometry��; ��Ҫ����Recordeset��AddNew�ȵط�
	//! \return ����������·���ռ���,����true; ���򷵻�false
	static UGbool AssureGeoType(UGGeometry* & pGeometry, UGGeometry::Type eType);

	//added by lugw 2007-11-09
	//! \brief �Ƚ�����geometry�Ƿ���ͬ
	//! \param pGeometrySrc �Ա�ָ��1
	//! \param pGeometryTag �Ա�ָ��2
	//! \return ���������ͬΪtrue����֮Ϊfalse
	static UGbool CompareGeometry(const UGGeometry* pGeometrySrc, const UGGeometry* pGeometryTag);

	//added by xielin 2007-04-30 
	static void SetCreateCustomGeometryFunc(CREATECUSTOMGEOMETRYCALLBACKPROC pCreateCustomGeometryFunc,
		UGlong pWnd);
	
};



}

#endif // !defined(AFX_UGGEOFACTORY_H__78297849_2C23_469A_A6B2_24C8E982EE63__INCLUDED_)
