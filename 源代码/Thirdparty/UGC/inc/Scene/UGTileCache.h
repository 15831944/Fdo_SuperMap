// UGTileCache.h: interface for the UGTileCache class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTILECACHE_H__A9135BF6_F75F_4F47_BFDA_9C7A5F1E420E__INCLUDED_)
#define AFX_UGTILECACHE_H__A9135BF6_F75F_4F47_BFDA_9C7A5F1E420E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include"Base/UGThread.h"

namespace UGC
{
class UGVeTile;
class SCENE_API UGTileCacheEntry
{
public:
	//! \brief ���캯����
	UGTileCacheEntry();	
	//! \brief ���캯����
	//! \param pTile ���ο�[in]��
	UGTileCacheEntry(UGVeTile* pTile);
	//! \brief ����������
	~UGTileCacheEntry();	
public:
	//! \brief ��ȡ���ο�ָ�롣
	//! \return ���ο�ָ�롣
	UGVeTile* GetTile();	
	//! \brief ������ļ����뱾���ο黺����ļ��Ƚϡ�
	//! \param strPath �ļ���[in]��
	//! \return 0 Ϊ��ͬ������Ϊ��ͬ��
	UGbool IsEqual(UGint nRow,UGint nCol,UGint nLevel);	
	//! \brief ����Ļ���ӿ��뱾����ӿڵķ���ʱ��Ƚϡ�
	//! \param pEntry ����[in]��
	//! \return 0 Ϊ��ͬ������Ϊ��ͬ��
	UGdouble CompareAccessTime(UGTileCacheEntry* pEntry);	
	//! \brief ���ñ�����ӿڵ�������ʱ�䡣
	//! \param dLassAccess ����ʱ��[in]��
	void SetLastAccess(UGdouble dLassAccess );	
	
protected:
	//	UGint ComparePath(UGTileCacheEntry* pEntry);		
	//! \brief ��ȡ������ʱ�䡣
	//! \return ������ʱ�䡣
	UGdouble GetLastAccess();		
	
protected:
	//! \brief ������ʱ�䡣
	UGdouble m_dLastAccess;
	//! \brief ���ο�ָ�롣
	UGVeTile* m_pTile;
};

class SCENE_API UGTileCache  
{
public:
	UGTileCache();
	virtual ~UGTileCache();
	// �������쵽���棬��ѭ����ȥ��������ʱ���Ⱥ����Ļ���ĺ���λ��
	void AddTileToCache(UGTileCacheEntry* pTce);
	// ��������ʵĿ���ӵĻ��棬����Ҫ������ע�������ֱ����ӵĻ����ͷ������Ϊ������ʣ�����ʱ������
	void AddRecentTileToCache(UGTileCacheEntry* pTce);
	void AddRecentTileToCache(UGVeTile* pTile);
	void ClearCache();
	// ������������п�
	// �ڻ������ҵ���Tile,�����޸������ʱ�䣬���Ұ�ʱ������
	UGVeTile* AskCacheTile(UGint nRow, UGint nCol, UGint nLevel);
	//  ֻ������ң�������
	UGVeTile* FindCacheTile(UGint nRow, UGint nCol, UGint nLevel);
	void Lock(){m_Mutex.lock();}
	void UnLock(){m_Mutex.unlock();}
	void DelNoUseTile();
	inline UGbool IsFull(){return m_CacheTileList.GetCount()>m_nCacheSize;}
	inline UGbool IsMore(){return m_CacheTileList.GetCount()>m_nCacheSize>>1;}
	
	/*
	void inline Lock(){m_Mutex.lock();}
	void inline Unlock(){m_Mutex.unlock();}
	void inline AddRenderQueueTail(UGVeTile* pTile);
	void inline AddRenderQueueHead(UGVeTile* pTile);
	// ע�����ﲻɾ��������ʱ���浽�����е�
	void ClearRenderQueue();
	//UGbool FindRenderQueueTile(UGint nRow,UGint nCol,UGint nLevel);
	void Render();
	*/
private:
	UGint  m_nCacheSize;
	UGList<UGTileCacheEntry*> m_CacheTileList;
	UGMutex m_Mutex;
	// �����ÿ����Ⱦ�Ŀ� 
	//UGList<UGVeTile*> m_RenderQueue;	
 

};

}

#endif // !defined(AFX_UGTILECACHE_H__A9135BF6_F75F_4F47_BFDA_9C7A5F1E420E__INCLUDED_)
