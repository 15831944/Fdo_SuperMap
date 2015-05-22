// UGSurfaceAnalyst.h: interface for the UGSurfaceAnalyst class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSURFACEANALYSIS_H__ADE3F4E8_DA63_47E2_8C2C_2C14A7657EDE__INCLUDED_)
#define AFX_UGSURFACEANALYSIS_H__ADE3F4E8_DA63_47E2_8C2C_2C14A7657EDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GridAnalyst/UGRasterAnalystEnv.h"
#include "Engine/UGDatasetRaster.h"

namespace UGC {

class GRIDANALYST_API UGSurfaceAnalyst  : public UGRasterAnalystEnv
{
public:

	UGSurfaceAnalyst();
	virtual ~UGSurfaceAnalyst();

public:
	UGDatasetVector* IsoLine(UGDatasetRaster* pInputRaster, 
							 UGdouble dInterval,
							 const UGString& strOutputVectorName = (""),
							 UGbool bCADDataset = FALSE,
							 UGdouble dBase = 0.0f, 
							 UGint nSmoothDegree = 3,
							 UGint nSmoothMethod = 0,
							 UGdouble dTolerance = 0.0,
							 UGbool bForIsoPolygon = FALSE);

	UGDatasetVector* IsoLine(UGDatasetVector* pPointDataset,  // ����ĵ����ݼ�
								const UGString& strPointField,   // �����ݼ��������ֶ�����
								UGGeoRegion* pClipRegion,    // �ü������ݼ�
								UGdouble dResolution,             // ��Ҫ�����м���dem�ķֱ���							
								UGdouble dInterval,               // ���ڵ�ֵ�ߵĲ�
								UGdouble dBase = 0.0f,            // ��ֵ�߿�ʼλ��
								const UGString& strOutputVectorName = (""),  // �����ֵ�����ݼ�������
								UGdouble dFilterTolerance = 0.0,  // ��ȡ��ֵ��ʱ�������˲������ò���Խ�󣬽����Խ�١�
								UGint nSmoothDegree = 3,          // ���������Ϊ�����ݼ���Ҫ����⻬�̶�
								UGbool bForIsoPolygon = FALSE);         

	UGDatasetVector* IsoPolygon(UGDatasetVector* pPointDataset,  // ����ĵ����ݼ�
								const UGString& strPointField,   // �����ݼ��������ֶ�����
								UGGeoRegion* pClipRegion,    // �ü������ݼ�
								UGdouble dResolution,             // ��Ҫ�����м���dem�ķֱ���							
								UGdouble dInterval,               // ���ڵ�ֵ�ߵĲ�
								UGdouble dBase = 0.0f,            // ��ֵ�߿�ʼλ��
								const UGString& strOutputVectorName = (""),  // �����ֵ�����ݼ�������
								UGdouble dFilterTolerance = 0.0,  // ��ȡ��ֵ��ʱ�������˲������ò���Խ�󣬽����Խ�١�
								UGint nSmoothDegree = 3);			// ���������Ϊ�����ݼ���Ҫ����⻬�̶�

private:
	
	UGbool CalcContourValue( UGdouble dMinZ, UGdouble dMaxZ, UGdouble dBase, UGdouble dInterval,
		                          UGdouble& dMinContour, UGdouble& dMaxContour, UGint& nCountContour );

	UGbool AddBoundEdge(UGDatasetRaster* pInputRaster, UGRecordset* pRecordsetIsolines, UGdouble dMin, UGdouble dInterval);

	UGbool ContourContained(UGdouble dValue1, UGdouble dValue2, UGdouble dMin, UGdouble dInterval);

};

}

#endif // !defined(AFX_UGSURFACEANALYSIS_H__ADE3F4E8_DA63_47E2_8C2C_2C14A7657EDE__INCLUDED_)

