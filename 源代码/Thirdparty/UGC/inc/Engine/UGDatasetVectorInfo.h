/*! \file	 UGDatasetVectorInfo.h
 *  \brief	 ʸ�����ݼ���Ϣ����
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetVectorInfo.h,v 1.14 2007/10/19 08:20:43 liwl Exp $
 */

#ifndef UGDATASETVECTORINFO_H
#define UGDATASETVECTORINFO_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Algorithm/UGRect2D.h"
#include "UGDataset.h"

namespace UGC {

//! �ռ�����
enum IndexType
{
	IdxNone		= 1,		//û������
	IdxRTree	= 2,		//Rtree����
	IdxQTree	= 3,		//�Ĳ�������
	IdxTile		= 4,		//ͼ������ UGC�ﲻ֧�ֱ༭
	IdxDynamic  = 5,		//multi-level Grid
};


//! ʸ�����ݼ���Ϣ��
class ENGINE_API UGDatasetVectorInfo  
{
public:
	//! ���캯��
	UGDatasetVectorInfo();
	//! ��������
	~UGDatasetVectorInfo();

	void SetToleranceToDefault();

	//! �õ���ǰ����������
	UGint GetIndexType(){return m_nIndexType;};
	void SetIndexType(IndexType nIdxType){m_nIndexType = nIdxType;};

public:
	//! ���ݼ�����
	UGString m_strName;

	//! ���ݼ�����
	UGDataset::DatasetType m_nType;

	//! ѡ����Ϣ
	UGint m_nOptions;
	
	//! �������
	UGint m_nObjectCount;

	//! �������� 
	UGint	m_nIndexType;
	
	//! ����������־
	UGint	m_nDynamicIndex;
	
	//! ��������ר�ò���
	UGPoint2D m_pntIdxCenter;
	UGdouble  m_dbGridRatio;
	UGdouble  m_dbdGrid0;
	UGdouble  m_dbdGrid1;
	UGdouble  m_dbdGrid2;
		
	//! �ռ���������
	UGint m_nSpatialIndexLevel;
		
	//! ���ݼ���Bounds
	UGRect2D m_rc2Bounds;

	//! ��άBounds����Сֵ
	UGdouble m_dMinZ;

	//! ��άBounds�����ֵ
	UGdouble m_dMaxZ;
	
	//! ���ݼ������������õ�Bounds
	UGRect2D m_rc2IndexedBounds;	

	//! ���µ�����Ϊ�������˹�ϵ���༭ʱʹ��
	//UGdouble m_dToleranceFuzzy;
	UGdouble m_dToleranceExtend;
	UGdouble m_dToleranceDangle;
	UGdouble m_dToleranceNodeSnap;
	UGdouble m_dToleranceSmallPolygon;
	UGdouble m_dToleranceGrain;

	//! Tin���ݼ����������ʹ��
	UGdouble m_dTinTolerance;

	//! ��������������״̬
	UGint m_nCheckedUserID;
	UGint m_nLockedUserID;
	UGint m_nState;

	//! ���ݱ�������
	UGint m_nCodecType;	

	UGString m_strDescription;	//�����ݼ���������Ϣ
};

}

#endif

