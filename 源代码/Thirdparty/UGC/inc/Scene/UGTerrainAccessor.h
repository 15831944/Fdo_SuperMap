// UGTerrainAccessor.h: interface for the UGTerrainAccessor class.
/* 
	\file UGTerrainAccessor.h
	\brief ���λ�ȡ��ͷ�ļ�
	\author �����ࡢ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTERRAINACCESSOR_H__097390C2_3F90_4628_85CA_1EFC7BACCFC5__INCLUDED_)
#define AFX_UGTERRAINACCESSOR_H__097390C2_3F90_4628_85CA_1EFC7BACCFC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Base/UGThread.h"

namespace UGC
{

//! \brief ���λ�ȡ����������ο�͵��ο黺�档
class SCENE_API UGTerrainAccessor  
{
public:
	//! \brief ���캯����
	UGTerrainAccessor();
	//! \brief ����������
	virtual ~UGTerrainAccessor();
	
public:
	//! \brief ��ȡָ����Χ�ĵ��ο顣
	//! \param north ���߽�[in]��
	//! \param south �ϱ߽�[in]��
	//! \param west ���߽�[in]��
	//! \param east ���߽�[in]��
	//! \param samples �ֱ���[in]��
	//! \return ���ο顣
	UGTerrainTile* GetTerrainTile(UGdouble north, UGdouble south, 
		UGdouble west, UGdouble east, UGint samples);	

	//! \brief ���õ��η���
	//! \param serverUrl ��ȡ���εķ���URL��ַ[in]��	
	//! \param levelZeroTileSizeDegrees ��0��ÿ��Ķ���[in]��
	//! \param samplesPerTile ÿ��ֱ���[in]��
	//! \param fileExtension ������չ��[in]��
	//! \param numberLevels ����[in]��
	//! \param terraintileDirectory �������ݱ��ش洢Ŀ¼[in]��
	//! \param dataType ������������[in]��
	void AddTerrainTileServer(const UGString& serverUrl,
		UGdouble levelZeroTileSizeDegrees,
		UGint samplesPerTile,
		const UGString& fileExtension,
		UGint numberLevels,
		const UGString& terraintileDirectory,
		const UGString& dataType,UGdouble dNorth=PI/2,UGdouble dSouth=-PI/2, UGdouble dWest=-PI, UGdouble dEast=PI);	
	UGbool GetElevationAt(UGdouble dLon,UGdouble dLat,UGdouble dSamplesPerDegree,UGdouble& dElevation);

protected:			
	//! \brief �ѵ��ο黺��ӿڼ��뵽�����б�
	//! \param pttce ���ο黺��ӿ�[in]��
	void AddToCache(UGTerrainTileCacheEntry* pttce);
protected:	
	//! \brief �������ݷ���
	UGTerrainTileServer* m_pTerrainTileServer;
	//! \brief �������ݻ���ӿ��б�
	UGList<UGTerrainTileCacheEntry*> m_TileCache;
	//! \brief �������ݻ�����Ŀ���ֵ��
	UGint m_stCacheSize;
	UGMutex m_mutex;
};

typedef UGArray<UGTerrainAccessor*> UGTerrainAccessorArray;
}
#endif // !defined(AFX_UGTERRAINACCESSOR_H__097390C2_3F90_4628_85CA_1EFC7BACCFC5__INCLUDED_)
