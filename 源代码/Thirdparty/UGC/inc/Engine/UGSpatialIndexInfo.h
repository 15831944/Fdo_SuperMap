// UGSpatialIndexInfo.h: interface for the UGSpatialIndexInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSPATIALINDEXINFO_H__DFDA261E_05C0_46C7_A3E6_08A2A6CAA872__INCLUDED_)
#define AFX_UGSPATIALINDEXINFO_H__DFDA261E_05C0_46C7_A3E6_08A2A6CAA872__INCLUDED_

#include "Base/ugdefs.h"
#include "Engine/UGDatasetVectorInfo.h"

namespace UGC {

class ENGINE_API UGSpatialIndexInfo  
{
public:
	UGSpatialIndexInfo();

	//�������͹���
	UGSpatialIndexInfo(IndexType nIndexType);

	//�༶�����������캯��
	UGSpatialIndexInfo(UGPoint2D	pntCenter,
						UGdouble	dGrid0,
						UGdouble	dGrid1,
						UGdouble	dGrid2,
						UGdouble	dGridRatio);

	//R���������캯��
	UGSpatialIndexInfo(UGint nQuality,UGString strSort);

	//ͼ������
	UGSpatialIndexInfo(UGString	strTileFieldName);

	//ͼ������
	UGSpatialIndexInfo(UGdouble	dWidth,UGdouble	dHeight);

	//�Ĳ�������
	UGSpatialIndexInfo(UGint nLevel);

	virtual ~UGSpatialIndexInfo();

public:
	IndexType	nIndexType; 
	UGint		nQuality;	//R�������ֵ * 50��ΪҶ�Ӱ��Ķ������
	UGString	strSort;	//��չ��R������Ȩ���ֶΣ����Ϊ����ʾ������QueryMode ΪFuzzyQuery��ʱ��ʹ��

	UGString	strTileFieldName;	//ͼ�����������������������ֶ�
	UGdouble	dWidth;				//ͼ�������������������ӵĿ��
	UGdouble	dHeight;			//ͼ�������������������ӵĸ߶�

	UGPoint2D	pntCenter;	//�༶�������������ĵ��λ��
	UGdouble	dGrid0;		//�༶����������0���ĸ��ӵĿ��
	UGdouble	dGrid1;		//�༶����������1���ĸ��ӵĿ��
	UGdouble	dGrid2;		//�༶����������2���ĸ��ӵĿ��
	UGdouble	dGridRatio;	//�༶���������и��ӵĴ�С
};

}

#endif // !defined(AFX_UGSPATIALINDEXINFO_H__DFDA261E_05C0_46C7_A3E6_08A2A6CAA872__INCLUDED_)
