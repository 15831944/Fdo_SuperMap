/* 
	\file UGQuadTileSet.h
	\brief �����Ĳ��������ļ� 
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/



#if !defined(AFX_UGQUADTILESET_H__204A8275_7394_4378_97CF_6245678A5ED3__INCLUDED_)
#define AFX_UGQUADTILESET_H__204A8275_7394_4378_97CF_6245678A5ED3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"
#include "scene/UGImgAccessor.h"
#include "Base/UGThread.h"

namespace UGC
{
//! \brief �����Ĳ�����0����ڵ���� 
//! \remarks ��ע��Ϣ
class SCENE_API SyncTopTilesMap
{
public:
	SyncTopTilesMap(){};
	virtual ~SyncTopTilesMap(){};
	void inline Lock(){m_mutex.lock();}
	void inline Unlock(){m_mutex.unlock();}

public:
	UGDict<UGlong,UGQuadTile*> m_Dict;	
protected:
	UGMutex m_mutex;	
};

//! \brief �����Ĳ�������
//! \remarks 
class SCENE_API UGQuadTileSet : public UGRenderObject
{
public:
	//! \brief ���캯��
	UGQuadTileSet();	
	//! \brief ���캯��
	UGQuadTileSet(const UGString& strName);	
	 
 
	//! \brief  ���캯��
	//! \param name [in] ����Ⱦ���������
	//! \param distanceAboveSurface [in]��������ĸ߶�
	//! \param north [in]�Ĳ���ԭʼ���ݿ�ı��߽�
	//! \param south [in]�Ĳ���ԭʼ���ݿ���ϱ߽�
	//! \param west [in]�Ĳ���ԭʼ���ݿ�����߽�
	//! \param east [in]�Ĳ���ԭʼ���ݿ�Ķ��߽�
	//! \param dL0TileSizeDeg [in]�Ĳ�����0��ľ�γ�ȿ��
	//! \param *pImgAccessor [in]�Ĳ���Ӱ����ͼ���ݵĻ�ȡ����
	UGQuadTileSet(
	const UGString& name,		
	UGdouble distanceAboveSurface,
	UGdouble north,
	UGdouble south,
	UGdouble west,
	UGdouble east,
	UGdouble dL0TileSizeLatDeg,
	UGdouble dL0TileSizeLonDeg,
	UGImgAccessor *pImgAccessor
	);
	//! \brief  ��������
	virtual ~UGQuadTileSet();

public:	
	//! \brief �õ����Ĳ�����İ뾶
	UGdouble GetLayerRadius();	
	//! \brief �õ����Ĳ���Ӱ����ͼ����
	UGImgAccessor *GetImgAccessor();
	//! \brief �õ�����LOD�Ĳ�������TileDrawDistance
	UGdouble GetTileDrawDistance();
	//! \brief ���ü���LOD�Ĳ�������TileDrawDistance
	void SetTileDrawDistance(UGdouble value);
	//! \brief �õ�����LOD�Ĳ�������TileDrawSpread
	UGdouble GetTileDrawSpread();
	//! \brief ���ü���LOD�Ĳ�������TileDrawSpread
	void SetTileDrawSpread(UGdouble value);
	/*
	//! \brief ��ʱ����
	UGbool GetbRenderStruts();
	//! \brief ��ʱ����
	void SetbRenderStruts(UGbool value);
	//! \brief  
	*/
	UGbool GetbAlwaysRenderBaseTiles();
	//! \brief  
	void SetbAlwaysRenderBaseTiles(UGbool value);
	//! \brief �õ�����ÿ������ÿ�еĵ���
	UGint GetElevatedVertexCount();
	//! \brief �õ�����ÿ������������Ŀ
	UGint GetElevatedVertexIndiceCount();
	//! \brief �õ�����ÿ�������������飬��ÿ�鶼��ͬ��������Щ���ݱ����п鹲��
	UGushort *GetElevatedVertexIndexData();
	UGbool GetElevationAt(UGdouble dLon, UGdouble dLat, UGdouble &dZ);

	 

protected:
	//! \brief �õ��Ĳ���ԭʼ���ݿ�ı��߽�
	UGdouble GetNorth();
	//! \brief �õ��Ĳ���ԭʼ���ݿ�Ķ��߽�
	UGdouble GetEast();
	//! \brief �õ��Ĳ���ԭʼ���ݿ���ϱ߽�
	UGdouble GetSouth();
	//! \brief �õ��Ĳ���ԭʼ���ݿ�����߽�
	UGdouble GetWest();
	//! \brief �õ��Ĳ����鼯�İ뾶
	void SetLayerRadius(UGdouble value);	
	//! \brief �̳��Կ���Ⱦ����ĺ���
	virtual void Initialize();
	//! \brief �̳��Կ���Ⱦ����ĺ������������ݵ�ѡ��
	virtual UGbool PerformSelectionAction();
	//! \brief �̳��Կ���Ⱦ����ĺ�������������ݵĸ���
	virtual void Update();
	//! \brief �̳��Կ���Ⱦ����ĺ������������ݵ���Ⱦ
	virtual void Render();
	//! \brief �̳��Կ���Ⱦ����ĺ������������ݵ��ͷ�
	virtual void Release();
	virtual void ResetCacheForCurrentView(UGMomentumCamera* pCamera);
	//! \brief ���Ĳ������㲻�ɼ������Ⱦ������ɾ��
	void RemoveInvisibleTiles(UGMomentumCamera* pCamera);
	//! \brief ��ʼ�������������
	void InitVertexIndexArray();

protected:	
	//! \brief �Ĳ���ԭʼ���ݿ�ı��߽�
	UGdouble m_dNorth;
	//! \brief �Ĳ���ԭʼ���ݿ���ϱ߽�
	UGdouble m_dSouth;
	//! \brief �Ĳ���ԭʼ���ݿ�����߽�
	UGdouble m_dWest;
	//! \brief �Ĳ���ԭʼ���ݿ�Ķ��߽�
	UGdouble m_dEast;
	//! \brief �Ĳ���ԭʼ���ݿ����뾶
	UGdouble m_dLayerRadius;
	//! \brief �Ĳ�����0��ÿ�龭γ�ȼ��
	UGdouble m_dL0TileSizeLatDeg;
	//! \brief �Ĳ�����0��ÿ�龭γ�ȼ��
	UGdouble m_dL0TileSizeLonDeg;
	//! \brief �Ĳ���LOD��������TileDrawDistance
	UGdouble m_fTileDrawDistance;
	//! \brief �Ĳ���LOD��������TileDrawSpread
	UGdouble m_fTileDrawSpread;
	//! \brief �Ĳ���ÿ��Ӱ������ļ��ع������
	UGImgAccessor *m_pImgAccessor;
	//! \brief �Ĳ�����0����ڵ�Ĺ������
	SyncTopTilesMap	m_TopmostTiles;
	//! \brief 
	UGlong m_lLastRenderTime;
	//! \brief ����ÿ������ÿ�еĵ���
	UGint m_nElevatedVertexCount;
	//! \brief ����ÿ������������Ŀ
	UGint m_nElevatedVertexIndiceCount;	
	//! \brief ����ÿ��������������
	UGushort* m_pElevatedVertexIndex;	
	
};
}
#endif // !defined(AFX_UGQUADTILESET_H__204A8275_7394_4378_97CF_6245678A5ED3__INCLUDED_)

       
  
         
       
 
 