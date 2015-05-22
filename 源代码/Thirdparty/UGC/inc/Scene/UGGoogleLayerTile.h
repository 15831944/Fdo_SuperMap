// UGGoogleLayerTile.h: interface for the UGGoogleLayerTile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGOOGLELAYERTILE_H__505D0DAC_0C2B_4828_A427_47E8F573779C__INCLUDED_)
#define AFX_UGGOOGLELAYERTILE_H__505D0DAC_0C2B_4828_A427_47E8F573779C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include "Scene/UGVector3R.h"
#include "Base/UGThread.h"
#include "UGMathEngine.h"
namespace UGC
{
class UGGoogleLayer;
//! \brief �Ĳ�����ڵ���
//! \remarks ��ע��Ϣ��
class SCENE_API UGGoogleLayerTile : public UGRenderable, public UGMovableObject
{
public:
	//! \brief ���캯��
	UGGoogleLayerTile();
	
 
	//! \brief ���캯��
	//! \param south [in]��ڵ�ľ�γ���ϱ߽�
	//! \param north [in]��ڵ�ľ�γ�ȱ��߽�
	//! \param west [in]��ڵ�ľ�γ�����߽�
	//! \param east [in]��ڵ�ľ�γ�ȶ��߽�
	//! \param level [in]��ڵ���������Ĳ����Ĳ���  
	//! \param pQuadTileSet [in]��ڵ��������Ĳ�������
	UGGoogleLayerTile(UGint nRow,UGint nCol, 
		UGint nLevel, UGGoogleLayer* pQuadTileSet);	
	virtual ~UGGoogleLayerTile();
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
	UGbool IsVisible();
	
protected:	
	 
	//! \brief ����һ��ָ����γ�ȷ�Χ���ӿ�
	//! \param childSouth [in]
	//! \param childNorth [in]
	//! \param childWest [in]
	//! \param childEast [in]
	//! \return ���������ɵ��ӿ��ָ��
	UGGoogleLayerTile* ComputeChild(UGint nRow,UGint nCol);	
	//! \brief ����ÿ���ĸ��ӿ�
	//! \param drawArgs [in]
	void ComputeChildren();		
	void ReleaseChild();	
	//! \brief  ��Ⱦ�ÿ�
	UGbool RenderTile();
	//! \brief �ͷŸÿ�
	virtual void Release();	
	//! \brief  ��Ⱦʵ������
	void RenderTile(UGRenderOperation* pRo);
	//! \brief  ѡ�иÿ�
	virtual UGbool PerformSelectionAction();

	//! \brief 
	void CreateTileMesh();		
	//! \brief 
	void CreateFlatMesh();
	//! \brief 
	void CreateElevatedMesh();
	//! \brief ����ָ���ӿ����������
	//! \param corner [in]
	//! \param pRo [in]
	//! \param meshBaseRadius [in]
	//! \param heightData [in]
	void CreateElevatedMesh(ChildLocation corner, UGRenderOperation* pRo ,
	UGdouble meshBaseRadius, UGfloat* heightData);	

	
	UGdouble ComputeLOD();

protected:
	//! \brief ���������Ĳ���
	UGGoogleLayer* m_pQuadTileSet;
	//! \brief 
	UGbool m_bRenderStruts ;
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
	UGVector3R m_vecLocalOrigin;  
	//! \brief 
	UGbool m_bResetingCache;
	//! \brief 
	UGdouble m_dVerticalExaggeration;
	//! \brief 
	UGGoogleLayerTile* m_pNorthWestChild;
	//! \brief 
	UGGoogleLayerTile* m_pSouthWestChild;
	//! \brief 
	UGGoogleLayerTile* m_pNorthEastChild;
	//! \brief 
	UGGoogleLayerTile* m_pSouthEastChild;
	//! \brief northWestVertices
	UGRenderOperation* m_pNWRo; 
	//! \brief southWestVertices
	UGRenderOperation* m_pSWRo; 
	//! \brief northEastVertices
	UGRenderOperation* m_pNERo; 
	//! \brief southEastVertices
	UGRenderOperation* m_pSERo; 
	//! \brief
	UGTexture* m_pTexture;
	//! \brief
	UGMutex m_mutex;

	// UpperLeft
	UV m_ul;
	UV m_ur;
	// LOWERLEFT
	UV m_ll;
	UV m_lr;
};
}

#endif // !defined(AFX_UGGOOGLELAYERTILE_H__505D0DAC_0C2B_4828_A427_47E8F573779C__INCLUDED_)
