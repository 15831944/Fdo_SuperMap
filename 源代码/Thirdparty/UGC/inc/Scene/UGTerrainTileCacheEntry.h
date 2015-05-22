// UGTerrainTileCacheEntry.h: interface for the UGTerrainTileCacheEntry1 class.
/* 
	\file UGTerrainTileCacheEntry.h
	\brief ���ο黺��ӿ�ͷ�ļ���
	\author �����ࡢ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/	
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTERRAINTILECACHEENTRY_H__8B84FC9C_2875_4D4C_923A_56D664F49986__INCLUDED_)
#define AFX_UGTERRAINTILECACHEENTRY_H__8B84FC9C_2875_4D4C_923A_56D664F49986__INCLUDED_
#include "Scene/UGPrerequisites.h"

namespace UGC
{

//! \brief ���ο黺��ӿڡ�
class SCENE_API UGTerrainTileCacheEntry
{
public:
	//! \brief ���캯����
	UGTerrainTileCacheEntry();	
	//! \brief ���캯����
	//! \param pTile ���ο�[in]��
	UGTerrainTileCacheEntry(UGTerrainTile* pTile);
	//! \brief ����������
	~UGTerrainTileCacheEntry();	

public:
	//! \brief ��ȡ���ο�ָ�롣
	//! \return ���ο�ָ�롣
	UGTerrainTile* GetTerrainTile();	
	//! \brief ������ļ����뱾���ο黺����ļ��Ƚϡ�
	//! \param strPath �ļ���[in]��
	//! \return 0 Ϊ��ͬ������Ϊ��ͬ��
	UGint ComparePath(const UGString& strPath);	
	//! \brief ����Ļ���ӿ��뱾����ӿڵķ���ʱ��Ƚϡ�
	//! \param pEntry ����[in]��
	//! \return 0 Ϊ��ͬ������Ϊ��ͬ��
	UGdouble CompareAccessTime(UGTerrainTileCacheEntry* pEntry);	
	//! \brief ���ñ�����ӿڵ�������ʱ�䡣
	//! \param dLassAccess ����ʱ��[in]��
	void SetLastAccess(UGdouble dLassAccess );	

protected:
//	UGint ComparePath(UGTerrainTileCacheEntry* pEntry);		
	//! \brief ��ȡ������ʱ�䡣
	//! \return ������ʱ�䡣
	UGdouble GetLastAccess();		

protected:
	//! \brief ������ʱ�䡣
	UGdouble m_dLastAccess;
	//! \brief ���ο�ָ�롣
	UGTerrainTile* m_pTerrainTile;
};
}
#endif // !defined(AFX_UGTERRAINTILECACHEENTRY_H__8B84FC9C_2875_4D4C_923A_56D664F49986__INCLUDED_)
