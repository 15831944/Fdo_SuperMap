// UGQuadGridSet.h: interface for the UGQuadTileGrid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGQUADTILEGRID_H__504F4C12_5DDB_4816_A901_3A197F2383F7__INCLUDED_)
#define AFX_UGQUADTILEGRID_H__504F4C12_5DDB_4816_A901_3A197F2383F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include "Base/UGThread.h"
#include "Scene/UGQuadGrid.h"
#include "Base/UGDict.h"
#include "Scene/UGVectorDatasetAtr.h"
namespace UGC
{
class UGDataset;
//! \brief �����Ĳ�����0����ڵ���� 
//! \remarks ��ע��Ϣ
class SCENE_API SyncTopGridMap
{
public:
	SyncTopGridMap(){};
	virtual ~SyncTopGridMap(){};
	void inline Lock(){m_mutex.lock();}
	void inline Unlock(){m_mutex.unlock();}

public:
	UGDict<UGlong,UGQuadGrid*> m_Dict;	
protected:
	UGMutex m_mutex;	
};

//! \brief �����Ĳ�������
//! \remarks 
class SCENE_API UGQuadGridSet:public UGRenderable, public UGMovableObject
{
public:
	//! \brief ���캯��
	UGQuadGridSet();	
	virtual ~UGQuadGridSet();
public:	
	//! \brief �õ�����LOD�Ĳ�������TileDrawDistance
	UGfloat GetTileDrawDistance();
	//! \brief ���ü���LOD�Ĳ�������TileDrawDistance
	void SetTileDrawDistance(UGfloat value);
	//! \brief �õ�����LOD�Ĳ�������TileDrawSpread
	UGfloat GetTileDrawSpread();
	//! \brief ���ü���LOD�Ĳ�������TileDrawSpread
	void SetTileDrawSpread(UGfloat value);
	//! \brief �õ�ȫ��ͳһ������ʹ�õ�����뾶
	UGdouble GetGlobalRadius();
	//! \brief ����ȫ��ͳһ������ʹ�õ�����뾶
	void SetGlobalRadius(UGdouble dRadius);
	//! \brief �õ�ȫ��ͳһ������������
	UGint GetMaxLevel();
	//! \brief ����ȫ��ͳһ������������
	void SetMaxLevel(UGint nMaxLevel);
	UGList<UGVectorDatasetAtr>& GetDatasetList();
	void AddDataset(const UGVectorDatasetAtr& pDataset);
	UGbool IsDatasetExist(const UGString& strName);
	void RemoveDataset(const UGString& strName);
	UGbool GetDataset(const UGString& strName,UGVectorDatasetAtr& atr);

 
	//! \brief �õ��Ĳ���ԭʼ���ݿ�ı��߽�
	UGReal GetNorth();
	//! \brief �õ��Ĳ���ԭʼ���ݿ�Ķ��߽�
	UGReal GetEast();
	//! \brief �õ��Ĳ���ԭʼ���ݿ���ϱ߽�
	UGReal GetSouth();
	//! \brief �õ��Ĳ���ԭʼ���ݿ�����߽�
	UGReal GetWest();
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
	

protected:	
	//! \brief �Ĳ�����0��ÿ�龭γ�ȼ��
	UGdouble m_dL0TileSizeDeg;
	//! \brief �Ĳ���LOD��������TileDrawDistance
	UGfloat m_fTileDrawDistance;
	//! \brief �Ĳ���LOD��������TileDrawSpread
	UGfloat m_fTileDrawSpread;
	//! \brief �Ĳ�����0����ڵ�Ĺ������
	SyncTopGridMap	m_TopmostTiles;
	//! \brief 
	UGlong m_lLastRenderTime;
	//! \brief ȫ��ͳһ����������
	UGint m_nMaxLevel;
	//! �뾶
	UGdouble m_dGlobalRadius;
	UGList<UGVectorDatasetAtr>m_DatasetList;
};
}

#endif // !defined(AFX_UGQUADTILEGRID_H__504F4C12_5DDB_4816_A901_3A197F2383F7__INCLUDED_)
