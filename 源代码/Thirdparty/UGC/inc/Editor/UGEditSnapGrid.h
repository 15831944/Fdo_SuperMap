// UGEditSnapGrid.h: interface for the UGEditSnapGrid class.
//
//=====================================================================================
// ��Ŀ����			Supermap Foundation Class (SFC) Library 2.0
// ��  �ߣ�			�ιظ�
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSupermap GIS����������Ա��δ����ɲ������Դ�����
//					2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����			UGEditSnapGrid.h	
// ��  ����			UGEditSnapPoints��UGEditSnapVertexs��UGEditSnapLineChart��UGEditSnapLineGrid��UGEditSnapPointGrid
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		UGEditSnapPoints:��׽�ĵ�����
//					UGEditSnapVertexs:��׽�Ľڵ�����
//					UGEditSnapLineChart:��׽�߱�
//					UGEditSnapLineGrid:��׽������
//					UGEditSnapPointGrid:��׽������
// ����˵����		
//=====================================================================================
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_AFCEDITSNAPGRID_H__12695D03_E19B_11D2_A590_0080C8EE6684__INCLUDED_)
#define AFX_AFCEDITSNAPGRID_H__12695D03_E19B_11D2_A590_0080C8EE6684__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugexports.h"
#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Algorithm/UGPoint2D.h"
#include "Editor/UGEditDef.h"
#include "Geometry/UGEditType.h"
#include "Map/UGLayer.h"

namespace UGC {

class EDITOR_API UGEditSnapPoints 
{
//Constructs/Destructs
public:
    UGEditSnapPoints();
    virtual ~UGEditSnapPoints();

//Implement
	//ȡ��һ���������
	//nIndex:������������
	//lPointIndex:���������ֵ
	void GetAt(UGint nIndex, UGint& lPointIndex );

	//����һ���������
	//nIndex:������������
	//lPointIndex:���������ֵ
	void SetAt(UGint nIndex, UGint lPointIndex );
	UGint  Add  (UGint lPointIndex );

	//ȡ�õ���������Ŀ
    inline UGint  GetSize( ) const { return m_PointIndexArray.GetSize(); };

	//ȡ������
	inline UGint  GetUpperBound( ) const { return m_PointIndexArray.GetUpperBound(); };

public:
    UGArray<UGint>    m_PointIndexArray;//��׽������
};

class EDITOR_API UGEditSnapVertexs
{
//Constructs/Destructs
public:
    UGEditSnapVertexs();
    virtual ~UGEditSnapVertexs();

//Implement
    //ȡ������
	void GetAt(UGint nIndex, UGint& lLineIndex, UGint& lVertexIndex );

	//��������
	void SetAt(UGint nIndex, UGint lLineIndex, UGint lVertexIndex );

	//���һ������
	UGint  Add  (UGint lLineIndex, UGint lVertexIndex );

	//����ָ���Ľڵ��Ƿ�Ψһ
    UGbool IsUnique( UGint lLineIndex, UGint lVertexIndex );

	//ȡ�ñ��������������
    inline UGint  GetSize( ) const { return m_LineIndexArray.GetSize(); };

	//ȡ�ñ��������������
	inline UGint  GetUpperBound( ) const { return m_LineIndexArray.GetUpperBound(); };

public:
    UGArray<UGint>    m_LineIndexArray;  //������������
    UGArray<UGint>    m_VertexIndexArray;//�ڵ���������
};



class EDITOR_API UGEditSnapPointGrid  
{
//Constructs/Destructs
public:
	UGEditSnapPointGrid( UGint lGridCount = 20 );
	virtual ~UGEditSnapPointGrid();

//Implement
public:
    void Reset( UGint lGridCount = 20 );

//Attribute
public:
    UGint                    m_lPointGridCount;  //��׽��ļ���
    UGEditSnapPoints*     m_pGridPointUnits;   //��׽����������
    UGPnt2DArray             m_Pnt2DArray;		//��׽������	
	//added by xielin 2007-05-31  ���ӱ��沶׽�����ڶ����id�����ڶ���������ͼ��ָ��
	UGArray<UGint>			m_aryIDs;
	UGArray<UGLayer*>       m_aryLayers;
	//added by xielin 2007-05-31 end

};



class EDITOR_API UGEditSnapLineGrid  
{
//Constructs/Destructs
public:
	UGEditSnapLineGrid( UGint lVertexGridCount = 20, UGint lLineGridCount = 20 );
	virtual ~UGEditSnapLineGrid();

//Implement
public:
    void Reset( UGint lVertexGridCount = 20, UGint lLineGridCount = 20 );

//Attribute
public:
    UGint                    m_lVertexGridCount;//�ڵ�����
    UGint                    m_lLineGridCount;//������
    UGEditSnapVertexs*    m_pGridVertexUnits;//�ڵ���������
    UGEditSnapVertexs*    m_pGridSectUnits;//�߶���������
	UGLineArray              m_LineArray;//�߶�����
	//added by xielin 2007-05-31  ���ӱ��沶׽�����ڶ����id�����ڶ���������ͼ��ָ��,������һ�������߶������ڵڼ���sub���������
	UGArray<UGint>			m_aryIDs;
	UGArray<UGLayer*>       m_aryLayers;
	//UGArray<UGint>			m_arySubIndex;
	//added by xielin 2007-05-31 end
};

//UGEditSnapLineChart����Բ�ʹ���ˣ������Ű�
class UGEditSnapLineChart
{
//Constructs/Destructs
public:
    UGEditSnapLineChart();
    virtual ~UGEditSnapLineChart();

//Implement
public:
    void Create( UGint nGeometryBaseIndex );//���ɲ�׽�߱�
	void Add   ( UGint lGeometryID, UGint lSubLineIndex ,UGLayer* pLayer); //���һ����׽���ζ���Ͳ�׽�ߵ�����
    UGbool GetGeometryInfo( UGint nLineIndex, UGint& lGeometryID, UGint& lSubLineIndex,UGLayer*& pLayer );//ȡ��һ����׽���ζ���Ͳ�׽�ߵ���������geometry����ͼ��
    void Reset();//���

//Attribute
public:
    UGbool                    m_bEnable;
    UGint                     m_nBaseIndex;
    UGArray<UGint>        m_arrayGeometrysID;//����׽�ļ��ζ����ID����
    UGArray<UGint>        m_SubLineIndexArray;//��׽���߶ε�����
	//added by xielin 2007-05-31  ���ӱ��沶׽�����ڶ���������ͼ��ָ��
	UGArray<UGLayer*>       m_aryLayers;
	//added by xielin 2007-05-31 end
};
/*
typedef CTypedPtrArray <CPtrArray, UGImgGrid*> UGImgArray;

class UGEditSnapImgArray
{
//Constructs/Destructs
public:
    UGEditSnapImgArray();
    virtual ~UGEditSnapImgArray();

//Implement
public:
	void GetAt(UGint nIndex, UGImgGrid** pImg );
	void SetAt(UGint nIndex, UGImgGrid* pImg );
	UGint  Add  (UGImgGrid* pImg );

    inline UGint  GetSize( ) const { return m_arraySmImg.GetSize(); };
	inline UGint  GetUpperBound( ) const { return m_arraySmImg.GetUpperBound(); };
    void Reset();

//Attribute
public:
    UGImgArray            m_arraySmImg;
};
*/
}

#endif // !defined(AFX_AFCEDITSNAPGRID_H__12695D03_E19B_11D2_A590_0080C8EE6684__INCLUDED_)
