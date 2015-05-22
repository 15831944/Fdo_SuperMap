// UGGoogleLayer.h: interface for the UGGoogleLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGOOGLELAYER_H__555BC9E7_CA67_4F8D_965F_10BBC8610E0C__INCLUDED_)
#define AFX_UGGOOGLELAYER_H__555BC9E7_CA67_4F8D_965F_10BBC8610E0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include "scene/UGImgAccessor.h"
#include "Base/UGThread.h"
#include "Base/UGFile.h"
#include "Base/UGToolkit.h"
namespace UGC
{

//! \brief �����Ĳ�����0����ڵ���� 
//! \remarks ��ע��Ϣ
class SCENE_API SyncTopGoogleTilesMap
{
public:
	SyncTopGoogleTilesMap(){};
	virtual ~SyncTopGoogleTilesMap(){};
	void inline Lock(){m_mutex.lock();}
	void inline Unlock(){m_mutex.unlock();}

public:
	UGDict<UGlong,UGGoogleLayerTile*> m_Dict;	
protected:
	UGMutex m_mutex;	
};


//! \brief �����Ĳ�������
//! \remarks 
class SCENE_API UGGoogleLayer : public UGRenderable, public UGMovableObject
{
public:
	//! \brief ���캯��
	UGGoogleLayer();	
	//! \brief ���캯��
	UGGoogleLayer(const UGString& strName);	
	 
 
	//! \brief  ���캯��
	//! \param name [in] ����Ⱦ���������
	//! \param distanceAboveSurface [in]��������ĸ߶�
	//! \param north [in]�Ĳ���ԭʼ���ݿ�ı��߽�
	//! \param south [in]�Ĳ���ԭʼ���ݿ���ϱ߽�
	//! \param west [in]�Ĳ���ԭʼ���ݿ�����߽�
	//! \param east [in]�Ĳ���ԭʼ���ݿ�Ķ��߽�
	//! \param dL0TileSizeDeg [in]�Ĳ�����0��ľ�γ�ȿ��
	//! \param *pImgAccessor [in]�Ĳ���Ӱ����ͼ���ݵĻ�ȡ����
	UGGoogleLayer(
	const UGString& name,		
	UGdouble distanceAboveSurface,
	UGImgAccessor *pImgAccessor
	);
	//! \brief  ��������
	virtual ~UGGoogleLayer();

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

	//! \brief �Ĳ�����0��ÿ�龭γ�ȼ��
	UGdouble m_dL0TileSizeLatDeg;
	//! \brief �Ĳ�����0��ÿ�龭γ�ȼ��
	UGdouble m_dL0TileSizeLonDeg;

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
	UGdouble m_dBegineLevel;
	UGdouble m_dLayerRadius;

	//! \brief �Ĳ���LOD��������TileDrawDistance
	UGdouble m_fTileDrawDistance;
	//! \brief �Ĳ���LOD��������TileDrawSpread
	UGdouble m_fTileDrawSpread;
	//! \brief �Ĳ���ÿ��Ӱ������ļ��ع������
	UGImgAccessor *m_pImgAccessor;
	//! \brief �Ĳ�����0����ڵ�Ĺ������
	SyncTopGoogleTilesMap	m_TopmostTiles;
	//! \brief 
	UGlong m_lLastRenderTime;
	//! \brief ����ÿ������ÿ�еĵ���
	UGint m_nElevatedVertexCount;
	//! \brief ����ÿ������������Ŀ
	UGint m_nElevatedVertexIndiceCount;	
	//! \brief ����ÿ��������������
	UGushort* m_pElevatedVertexIndex;	
	static void * m_hProjectDLL;
	
};


}
 

#endif // !defined(AFX_UGGOOGLELAYER_H__555BC9E7_CA67_4F8D_965F_10BBC8610E0C__INCLUDED_)
