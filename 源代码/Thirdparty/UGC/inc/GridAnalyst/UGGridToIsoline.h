//�㷨˼��ܾ��䣬��ϧʵ�ֵĺ����
//1���������㷨��˼�롣
//2����д�����ݽṹ��
//3����������ṹ��
//�㷨��˼·�ǣ�
//1�����ݵ�ֵ�ߵ�ֵ����DEM����ȡ����Ӧ�ĵ�ֵ�㡣
//2������ֵ�����ɵ�ֵ�ߡ�
//
//            �����ש��ש���
//            �� \��  ��  ��
//            �ǡ��贈�贈��
//             ��/��  ��  �� 
//            �ǩ��贈�贈��
//            ��  ��  ��  ��		
//            �ǩ��贈�贈��
//			  ��  ��  ��  ��
//			  �ǩ��贈�贈��	
//
//
//
//}}

/*--------by Y.M.Zheng 2006.02-------------------------*\
 1. �޸���GridEdge�����ݽṹ�����Ч��
	��д��AcquireIsoPnts()��TopToBottomTrace()��BottomToTopTrace()��
	LeftToRightTrace()��RightToLeftTrace()
	TraceOpenIsoline()��TraceClosedIsoline()��
	TraceContour()�⼸��������
    ������һ������TraceNextPoint()

 2. �ع�����(ԭ���Ĵ���̫������)��
    ɾ���������õĴ��룬��ӹؼ�ע��
\*---------by Y.M.Zheng--------------------------------*/

#if !defined(AFX_GRIDTOISOLINE_H__22CCAB83_B299_11D3_8A28_0080C8EE62D1__INCLUDED_)
#define AFX_GRIDTOISOLINE_H__22CCAB83_B299_11D3_8A28_0080C8EE62D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Engine/UGDatasetRaster.h"
#include "Base/UGList.h"

/*--------------------------------------------------*\
      �����
  ���м�¼��
      1. ����ߵı�ʶ(xNum,yNum,bIsHorV);
	  2. ��������ϵĵ�ֵ�������;
	  3. ���������׷�ٹ������Ƿ�ʹ�ù�;
  
	              (xNum+1,yNum)       (xNum+1,yNum+1)  
	                      ____________
                         |            |
				         |            |
	          �ݱ�b----��| (����Ԫ) |
				         |            |
				         |____________|
                   (xNum,yNum) �O   (xNum+1,yNum)
				               �O
						       ��
						     ���a

     // NOTE: 
	 // (xNum,yNum)�Ƕ˵����ڵ��кź��кţ����Ǵ�0��ʼ����
	 // �˵㣬���ں�ߣ���������˵㣻�����ݱߣ��������¶˵�
	 // (xNum,yNum,bIsHorV)-->��������������ͬ��ʶһ����
	 // ��ͼ�У����a���ݱ�b��ǰ2������(xNum,yNum)��ͬ��
	 // ��bIsHorV�����֣�bIsHorVΪTrue���Ǻ�ߣ��������ݱ�     
       
\*--------------------------------------------------*/
namespace UGC {

const UGdouble dMinTolerance = 1.0e-9;

class GridEdge
{

public:
	//GridPnt  GridPnt1;  
	//GridPnt  GridPnt2;
	
	// ����Ҫͬʱ��¼���˵��λ�ã�
	// ֻ��Ҫ��¼һ���˵�(xNum,yNum)���ټ�һ���Ǻ�߻����ݱߵı�־�����ˣ�
	// �����Ľṹ��2���ô���
	// 1����Խ�ʡ�ڴ棻
	// 2�������㷨��ʵ��(��Ϊ�㷨�о�����Ҫ�ж�һ��������Ǻ�߻����ݱ�)��
	
	UGint  xNum;
	UGint  yNum; 
	UGbool bIsHorV; // true:��ߣ�false:�ݱ� (note:��UGbool����UGbool�ڴ�ҪС)

	//һ������ֻ��һ����ֵ��, �����Ϊһ��ֵ׷�ٵ�ֵ��ʱ,��ֻ�ܱ���һ��
	UGbool bUsed;

	// ��������ϵĵ�ֵ�㣬һ�����Ͼ�ֻ��һ����ֵ��
	UGPoint2D EdgeIsoPnt;

	GridEdge() : xNum(0), yNum(0), bIsHorV(true), bUsed(false)
	{}
	
};

//-------- Define Isoline:
class UGIsoline
{
public:
	UGIsoline()/*: IsSelected(FALSE)*/
	{}

	~UGIsoline() 
	{
		// UGList�������������Զ������RemoveAll()
		/*Isoline2DPntList.RemoveAll();*/ 
	}

    UGdouble m_dz;

	//��ֵ���ϵĵ�ֵ��(x,y)����
	UGList<UGPoint2D> Isoline2DPntList;


	//UGbool IsSelected;

	UGbool CompressPoints(UGdouble dTolerance);
	UGbool ConvertToPoint2Ds(UGArray<UGPoint2D> &arrPoints);
	//UGIsoline& operator=(UGIsoline &p);
};

/*inline UGIsoline &UGIsoline::operator=(UGIsoline &PolyLine)
{  	
	this->m_dz=PolyLine.m_dz;
	Isoline2DPntList.RemoveAll();
	
	POSITION Pos = PolyLine.Isoline2DPntList.GetHeadPosition();
    while(Pos != NULL) 
	{
	   Isoline2DPntList.AddTail(PolyLine.Isoline2DPntList.GetNext(Pos));
	}
	return *this;
}*/



//----------  The below:  fully use the above definations --------------
class UGGridToIsoline  
{
public:
	UGGridToIsoline(UGDatasetRaster *pSmDatasetGrid, UGint nSmoothDegree = 3, UGint nSmoothMethod = 0,UGdouble dTolerance = 0.0f);
	virtual ~UGGridToIsoline();

public:
    
	// ���ݵ������Ϣ
	UGDatasetRaster* m_pDtRaster;
	UGuint m_unWidth;  // ���������
	UGuint m_unHeight; // ���������
    UGdouble m_dResolutionX; // ������֮��ľ�����
	UGdouble m_dResolutionY; // ������֮��ľ�����
	UGdouble m_dMinZ; // �����е���Сֵ
//	UGdouble m_dMaxZ; // �����е����ֵ

	// ��Ҫ׷�ٵĵ�ֵ�ߵ�ֵ
	UGdouble m_dZValue; // Isoline Z Value

	// ��ֵ�����߽��й⻬�Ĺ⻬����
//	UGdouble m_dBaseContourVal;//�����߸߶� 
	UGuint m_nSmoothDegree; //�⻬��	
	UGuint m_nSmoothMethod; //�⻬����
	UGdouble m_dTolerance; //ѹ��������� caogf
	
protected:
	UGdouble m_dSmoothCut; //Ĩ�Ƿ��ȷ��߶���
	
//    POSITION  m_posHeadPos, m_Pos, m_posTailPos;
//    POSITION  m_posHeadPos1,m_Pos1;
//    
//    UGPoint2D  m_pntA1;
//	  UGPoint2D  m_pntCurrA1;
//    GridEdge* m_pGridEdge2;
	
	// ׷���㷨��������Ҫǰһ��ֵ�㡢��ǰ��ֵ�㡢��һ��ֵ����������Ϣ
	UGList<GridEdge*>::POSITION  m_CurrentPos, m_NextPos;
	GridEdge  *m_pPrevGridEdge, *m_pCurrentGridEdge, *m_pNextGridEdge;
	UGPoint2D  m_CurIsoPt, m_NextIsoPt;
	

	GridEdge m_PrevGridEdge;
	

	// ��׷����һ����ֵ��ʱ�õ�����ʱ��������
	GridEdge *m_pTopHEdge, *m_pBottomHEdge, *m_pLeftVEdge, *m_pRightVEdge;
	GridEdge *m_pTmpGridEdge;
	UGPoint2D  TopTmpIsoPnt, BottomTmpIsoPnt, LeftTmpIsoPnt, RightTmpIsoPnt;
    

public:
	
	//output:
	UGList<GridEdge*> m_GridEdgeListWithIsoPnts;//��Ŵ��е�ֵ���Grid�ߵ�����
    
    UGList<UGIsoline*> SmoothIsolines;//��Ź⻬��ֵ�ߵ�����

public:	
	// ��ȡGrid���ϵ�ֵ��ķֲ��������¼����ֵ���Grid�ߣ�
	UGbool AcquireIsoPnts(UGdouble dIsolineVal);

protected:

	UGbool TopToBottomTrace(/*UGPoint2D& OutIsoPnt*/);
	UGbool BottomToTopTrace(/*UGPoint2D& OutIsoPnt*/);
	UGbool LeftToRightTrace(/*UGPoint2D& OutIsoPnt*/);
	UGbool RightToLeftTrace(/*UGPoint2D& OutIsoPnt*/);
	
	UGbool TraceOpenIsoline(UGbool bSmooth = TRUE);
	UGbool TraceClosedIsoline(UGbool bSmooth = TRUE);

	// ����ǰһ��͵�ǰ�����Ϣ��׷����һ��
	UGbool TraceNextPoint(); // added by Y.M.Zheng


public:
	UGbool TraceContour(UGdouble dContourVal, UGbool bSmooth = TRUE);

protected:	

	//����Ĩ�Ƿ��⻬�̶�  �������4��Ĩ������ʱ������Ϊ4��ע�⣺ÿ����һ�Σ�����������һ��
	void SetSmoothDegree(UGlong nSmoothDegree);
	void SetSmoothMethod(UGlong nSmoothMethod);
    UGbool Smooth(UGIsoline* pIsoline, UGuint nSmoothDegree, UGlong nSmoothMethod = 0);//ֻΪһ��ֵ�⻬��ֵ��,Ϊ�������Ҫѭ������.

	void ExcludeUsedIsoPnts();//�޳��ѱ�׷�ٽ���ֵ���˵ĵ�ֵ��
	void Reset();
	
public:

	void freeSmoothIsolines();
	void freeGridEdgeList();

};

}
#endif // !defined(AFX_GRIDTOISOLINE_H__22CCAB83_B299_11D3_8A28_0080C8EE62D1__INCLUDED_)




