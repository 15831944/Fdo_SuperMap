/* 
	\file UGFourColor.h
	\brief ��ɫ�㷨
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGFOURCOLOR_H
#define UGFOURCOLOR_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Algorithm/UGPoint2D.h"
#include "Geometry/UGGeoRegion.h"
#include "Engine/UGDataset.h"
#include "Topology/UGTopoTypes.h"
#include "Engine/UGDatasetVector.h"

namespace UGC {
//!	\brief ͼ����Ϣ�ṹ
struct tagdegreeID
{
	UGint nID;
	UGint ndegree;
};

typedef struct tagdegreeID UGDegreeIDInfo,*pUGDegreeIDInfo;//�淶��������

class OPERATION_API UGFourColor  
{
public:
	UGFourColor();
	virtual ~UGFourColor();
	
	//!	\brief	��ɫ����
	//! \param  pDTRegion ���ݼ�ָ��[in]
	//!	\param strColorValue ��ɫ�ֶ�[in]
	//!	\return �����ɫ�����ɹ�����TRUE�����򷵻�FALSE
	UGbool FourColor(UGDatasetVector* pDTRegion, const UGString& strColorValue = "ColorValue");
private:
	UGbool ColorNew(UGArray<UGDegreeIDInfo> &arrDegreeIDInfo, UGint* pColorClass);
	UGint Color(UGint nPos,UGint CurrentColor, UGint nCountColor, UGbyte* pHandled, 
				UGint* pColorCount, UGint* pOrder, UGint** ppColorAdj, UGint*pColorClass, UGint nRegionCount);
	UGint Maxclique(UGArray<UGDegreeIDInfo> &arrDegreeIDInfo, UGint* pColorClass, 
					UGint *pClique, UGArray<UGint> &arrOrderClique);
	UGbool AssignColor(UGint nNodeIndex, UGint nColorType, UGint* pColorClass, UGint** ppColorAdj, UGint* pColorCount);
	UGbool RemoveColor(UGint nNodeIndex, UGint nColorType, UGint* pColorClass, UGint** ppColorAdj, UGint* pColorCount);
	UGbool IsAdjacent(UGint nPos1, UGint nPos2);
	
	UGTopoGrid* m_pTopoGrid;
	UGint m_BestColoring;
};

}

#endif // !defined(UGFOURCOLOR_H)
