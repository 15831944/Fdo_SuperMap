// UGRasterToVector.h: interface for the UGRasterToVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGRASTERTOVECTOR_H__E193928D_9B42_45A1_964B_68933BAF9ED6__INCLUDED_)
#define AFX_UGRASTERTOVECTOR_H__E193928D_9B42_45A1_964B_68933BAF9ED6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDatasetRaster.h"
namespace UGC{
class UGPolyLine;

class EDITOR_API UGRasterToVector  
{
public:
	UGRasterToVector();
	UGRasterToVector(UGDatasetRaster *pDatasetRaster);
	virtual ~UGRasterToVector();
public:
	UGColor GetRasterBkColor();								//�õ�դ�񱳾�ɫ��
	void SetRasterBkColor(UGColor crRasterBack);				//ָ��դ�񱳾�ɫ��
	UGdouble GetFilter();											//�õ����˲�����
	void SetFilter(UGdouble dFilter);								//���ù��˲���
	UGlong GetSmooth();											//�õ��⻬�ȣ�
	void SetSmooth(UGlong lSmooth);								//���ù⻬�ȣ�
	UGlong GetColorTolerance();									//�õ���ɫ����ֵ��
	void SetColorTolerance(UGlong lColorTolerance);				//������ɫ����ֵ��
	UGbool GetAutoPan();											//�õ��Ƿ��Զ�����
	void SetAutoPan(UGbool bAutoPan);								//�����Ƿ��Զ�����
	UGDatasetRaster *GetDatasetRaster();							//�õ�դ�����ݼ���
	UGbool GetLastPoint(UGPoint2D &pntMap);						//�õ����һ�㣻
	UGbool RemoveLastPoint();										//�Ƴ����һ�㣻
	UGbool IsCanTracing();										//�Ƿ��ܹ����٣�
	UGbool ImageToMap(UGPoint pntImage,UGPoint2D &pntMap,UGbool bCenter = TRUE);			//ͼ�����굽��ͼ����
	UGbool MapToImage(UGPoint2D pntMap,UGPoint &pntImage);			//��ͼ���굽ͼ�����ꣻ
	void Release();												//�ͷ��ڴ棻
	UGbool GetGeoLine(UGGeoLine &GeoLine);							//ȡ�ø��ٺ���߶���
	void AttachDatasetRaster(UGDatasetRaster *pDatasetRaster);	//����դ�����ݼ���
	UGbool IsTracingEnd();										//�����Ƿ������
	UGbool TracingStart(UGPoint2D pnt2D);							//���ٿ�ʼ��
	UGbool TracingContinue();										//���ټ�����
	UGbool TracingEnd();											//���ٽ�����
	UGbool TracingBack();											//�������
	UGbool TracingBreak(UGPoint2D pnt2D,UGbool bBreak = FALSE);		//���ٴ�ϣ�
	UGbool TracingAdd(UGPoint2D pnt2D);							//���ټӵ㣻
	UGbool TracingBreakCancel();									//ȡ�����ٴ�ϣ�
	UGGeoRegion* TraceRegion(UGPoint2D pnt2D);
protected:
	UGbool FindRegionEdgePoint(UGPoint &pntStart,UGPoint &pntEnd);
	UGbool FindInRegion(UGArray<UGptr> &Regions);
	UGbool FindOutRegion(UGPoint point,UGArray<UGptr> &Regions);
	UGbool FindRegion(UGPoint point,UGPolyLine *pRegion,UGbool bOutRegion = TRUE);
	UGbool IsSameValue(UGdouble dValue1,UGdouble dValue2);
	UGbool IsValidPointEx(UGPoint pntCurrent);
	UGbool PointProjectToLineset(const  UGPoint2D &pntHitTest, UGPoint2D  pntLinsectStart, UGPoint2D pntLinsectEnd, UGPoint2D &resultPoint);
	UGbool PloylineBreak(UGPoint pntCurrent);						//�������
	UGbool IsValidPoint(UGPoint pntCurrent);						//�ǲ�����Ч�㣻
	UGbool Reverse();												//���ݷ���
	UGbool IsToEnd(UGPoint pntLast);								//�Ƿ�ͷ��
	UGbool ToLinePoints();										//����դ���ʸ�������������ݵ������ݣ�
	UGbool ToRasterBlock(UGPoint pntCurrent,UGbool bStart=FALSE);	//�õ�դ������ݣ�
	UGint  GetBlockValue(UGint x,UGint y);							//�õ�դ�������ֵ��
	UGbool IsDeleted(UGint x,UGint y);								//�жϸ����ص��Ƿ����ɾ����
	UGbool BlockThinned(UGPoint &pntFront);						//դ���ϸ����
	UGbool FindEdgePoint(UGPoint pntFront,UGPoint &pntEdge,UGPoint &pntREdge);	//����դ��ʻ��ı�Ե��
	UGbool RemoveEdgePoint(UGPoint pntStart, UGbool bClockwise = false);			//��Ƥ��ɾ����Ե�㣻
	UGbool FindNextEdgePoint(UGPoint pntBack,UGPoint pntCurrent,UGPoint &pntEdge, UGbool bClockwise = false);  //������һ����Ե�㣻
	void Rotate(UGint &x,UGint &y, UGbool bClockwise = false);		//��ת90�ȣ�
	UGbool AddNextPoint(UGPoint pntBack,UGPoint pntCurrent,UGPoint &pntNext);	//ȡ����һ������ݣ�
	UGbool LampHouseSmooth(UGPoint* pPoints,const UGint nCount,UGdouble dTolerance,UGArray<UGPoint> &arrPoints); //�������⻬��
	UGbool GetNextCenterPoint(UGPoint &pntCenter);					//�õ���һ����դ�������ĵ㣻
	UGbool IsSamePoint(UGPoint point1,UGPoint point2);				//�Ƿ�ͬһ�㣻
	UGbool GetBlockPoints(UGPoint pntCurrent);						//�õ�դ���ʸ�����ݣ�
	UGbool IsSameColor(UGColor color1,UGColor color2);			//�ж���ɫ������Χ���Ƿ���ͬ��
	UGbool ImageToImage(UGDatasetRaster *pDatasetRaster);			//ת������һ��ͼ������ꣻ
protected:
	UGArray<UGbyte> m_arrRasterBlock;				//�洢դ���դ�����ݵ����飻
	UGArray<UGPoint> m_arrLinePointsTmp;	//��ʱ�洢�����ݵ����飻
	UGArray<UGPoint> m_arrLinePoints;		//�洢�����ݵ����飻
	UGArray<UGPoint> m_arrBlockPoints;		//�洢դ��������ݵ����飻
	UGDatasetRaster *m_pDatasetRaster;			//�����ٵ�դ�����ݼ���

	UGPoint m_pntBlockStart;						//դ�����դ��ͼ�����ʼΪ�ã�
	UGPoint m_pntTracingStart;					//�������ٻ�����ٵ���㣻

	UGdouble		m_dFilter;						//���˲�����ֵԽ���Խ�٣�
	UGint		m_lSmooth;						//�⻬��������ֵ�ĵ�����
	UGlong		m_lColorTolerance;				//��ɫ����ֵ��
	UGbool		m_bAutoPan;						//�Ƿ��Զ�������
	UGColor	m_crRasterBack;					//ָ��դ�񱳾�ɫ��
	UGdouble		m_dCurRasterValue;				//��ǰդ��ֵ��

	UGbool		m_bTracingBack;					//�Ƿ�����������ٲ�����
	UGbool		m_bToEnd;						//�Ƿ�ͷ��
	UGbool		m_bTracingEnd;					//�Ƿ���ٽ�����

};

}
#endif // !defined(AFX_UGRASTERTOVECTOR_H__E193928D_9B42_45A1_964B_68933BAF9ED6__INCLUDED_)
