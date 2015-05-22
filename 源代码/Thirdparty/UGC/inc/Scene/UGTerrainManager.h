// UGTerrainManager.h: interface for the UGTerrainManager class.
/* 
	\file UGTerrainManager.h
	\brief ���ι�����ͷ�ļ���
	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTERRAINMANAGER_H__81D06E1A_2C75_47B1_8A61_54623AD0C0C8__INCLUDED_)
#define AFX_UGTERRAINMANAGER_H__81D06E1A_2C75_47B1_8A61_54623AD0C0C8__INCLUDED_

#include "Scene/UGPrerequisites.h"
#include "Scene/UGSingleton.h"
#include "Scene/UGTerrainAccessor.h"

namespace UGC
{
//! \brief ���ι�����������ģʽ��	
//! \remarks ����֧�ֶ��������ݡ�
class SCENE_API UGTerrainManager : public UGSingleton<UGTerrainManager>
{
public:
	//! \brief ���캯����
	UGTerrainManager();
	//! \brief ����������
	virtual ~UGTerrainManager();

public:
	//! \brief ��ȡָ����Χ�ĵ��ο顣
	//! \param north ���߽�[in]��
	//! \param south �ϱ߽�[in]��
	//! \param west ���߽�[in]��
	//! \param east ���߽�[in]��
	//! \param samples �ֱ���[in]��
	//! \return ���ο顣
	UGTerrainTile *GetTerrainTile(UGdouble north, UGdouble south, 
		UGdouble west, UGdouble east, UGint samples);
		
	//! \brief ���õ��η���
	//! \param serverUrl ��ȡ���εķ���URL��ַ[in]��	
	//! \param levelZeroTileSizeDegrees ��0��ÿ��Ķ���[in]��
	//! \param samplesPerTile ÿ��ֱ���[in]��
	//! \param fileExtension ������չ��[in]��
	//! \param numberLevels ����[in]��
	//! \param terraintileDirectory �������ݱ��ش洢Ŀ¼[in]��
	//! \param dataType ������������[in]��
	void AddTerrainAccessor(const UGString& serverUrl,
		UGdouble levelZeroTileSizeDegrees,
		UGint samplesPerTile,
		const UGString& fileExtension,
		UGint numberLevels,
		const UGString& terraintileDirectory,
		const UGString& dataType,UGdouble dNorth=PI/2,UGdouble dSouth=-PI/2, UGdouble dWest=-PI, UGdouble dEast=PI);
	UGdouble GetElevationAt(UGdouble dLon, UGdouble dLat, UGdouble dSamplesPerDegree);
public:	
	//! \brief ����ģʽ��ȡ�ӿڡ�
	static UGTerrainManager& GetSingleton();

protected:
	//! \brief ���λ�ȡ���ӿ����顣
	UGTerrainAccessorArray m_TerrainAccessorArray;
};
}
#endif // !defined(AFX_UGTERRAINMANAGER_H__81D06E1A_2C75_47B1_8A61_54623AD0C0C8__INCLUDED_)
