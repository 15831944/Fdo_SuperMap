// UGQuadGrid1.h: interface for the UGQuadGrid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGQUADGRID1_H__934E03A2_8EC2_4B86_B4A9_105F83E03C72__INCLUDED_)
#define AFX_UGQUADGRID1_H__934E03A2_8EC2_4B86_B4A9_105F83E03C72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Base/UGThread.h"
#include "Scene/UGRenderable.h"
namespace UGC
{
class SCENE_API UGQuadDataList:public UGList<UGQuadDataset*>
{
public:
	UGQuadDataList();
	virtual~ UGQuadDataList();
	void ReleaseAll();
	void Render();
	void Initialize();
};
class SCENE_API UGQuadGrid:public UGRenderable, public UGMovableObject
{
public:
	//! \brief ���캯��
	UGQuadGrid();
	
 
	//! \brief ���캯��
	//! \param south [in]��ڵ�ľ�γ���ϱ߽�
	//! \param north [in]��ڵ�ľ�γ�ȱ��߽�
	//! \param west [in]��ڵ�ľ�γ�����߽�
	//! \param east [in]��ڵ�ľ�γ�ȶ��߽�
	//! \param level [in]��ڵ���������Ĳ����Ĳ���  
	//! \param pQuadTileSet [in]��ڵ��������Ĳ�������
	UGQuadGrid(UGdouble south, UGdouble north, UGdouble west, UGdouble east, 
		UGint level, UGQuadGridSet* pQuadTileSet);	
	virtual ~UGQuadGrid();
public:
	/// <summary>
	/// Child tile location
	/// </summary>
	enum ChildLocation
	{
		NorthWest,
		SouthWest,
		NorthEast,
		SouthEast	
	};
public:
	//! \brief �̳��Կ���Ⱦ����ĺ����������ĳ�ʼ��
	virtual void Initialize();
	//! \brief �̳��Կ���Ⱦ����ĺ����������ĸ���
	virtual void Update();
	//! \brief �̳��Կ���Ⱦ����ĺ�������������Ⱦ
	virtual void Render();
	
	//! \brief �̳��Կ���Ⱦ����ĺ������������ļ�����
	void ResetCache();
	//! \brief �̳��Կ���Ⱦ����ĺ�������ÿ�Ĳ��� 
	UGint GetLevel();
	//! \brief �̳��Կ���Ⱦ����ĺ�������ÿ���к�
	UGint GetRow();
	//! \brief �̳��Կ���Ⱦ����ĺ�������ÿ���к�
	UGint GetCol();
	
protected:	
	 
	//! \brief ����һ��ָ����γ�ȷ�Χ���ӿ�
	//! \param childSouth [in]
	//! \param childNorth [in]
	//! \param childWest [in]
	//! \param childEast [in]
	//! \return ���������ɵ��ӿ��ָ��
	UGQuadGrid* ComputeChild(UGdouble childSouth, UGdouble childNorth, 
		UGdouble childWest, UGdouble childEast);	
	//! \brief ����ÿ���ĸ��ӿ�
	//! \param drawArgs [in]
	void ComputeChildren();		
	void ReleaseChild();	
	//! \brief  ��Ⱦ�ÿ�
	UGbool RenderTile();
	//! \brief  ��Ⱦ�ÿ������
	void RenderTileData();
	//! \brief �ͷŸÿ�
	virtual void Release();	
protected:
	//! \brief ���������Ĳ���
	UGQuadGridSet* m_pQuadTileSet;
	//! \brief 
	UGdouble m_dWest;
	//! \brief 
	UGdouble m_dEast;
	//! \brief 
	UGdouble m_dNorth;
	//! \brief 
	UGdouble m_dSouth;
	//! \brief 
	UGdouble m_dCenterLatitude;
	//! \brief 
	UGdouble m_dCenterLongitude;
	//! \brief 
	UGdouble m_dLatitudeSpan;
	//! \brief 
	UGdouble m_dLongitudeSpan;
	//! \brief 
	UGint m_nLevel;
	//! \brief 
	UGint m_nRow;
	//! \brief 
	UGint m_nCol;	
	//! \brief 
	UGbool m_bResetingCache;
	//! \brief 
	UGQuadGrid* m_pNorthWestChild;
	//! \brief 
	UGQuadGrid* m_pSouthWestChild;
	//! \brief 
	UGQuadGrid* m_pNorthEastChild;
	//! \brief 
	UGQuadGrid* m_pSouthEastChild;
	//! \brief northWest
	UGQuadDataList m_DataList;
	/*
	//! \brief southWestVertices
	UGQuadDataList m_SWDataList;
	//! \brief northEastVertices
	UGQuadDataList m_NEDataList;
	//! \brief southEastVertices
	UGQuadDataList m_SEDataList;
	*/
	//! \brief
	UGMutex m_mutex;
};
}
#endif // !defined(AFX_UGQUADGRID1_H__934E03A2_8EC2_4B86_B4A9_105F83E03C72__INCLUDED_)
