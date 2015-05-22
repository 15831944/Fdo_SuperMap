// UGTerrainTileServer.h: interface for the UGTerrainTileServer class.
/* 
	\file UGTerrainTileServer.h
	\brief �������ݷ���ͷ�ļ���
	\author ��������������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTERRAINTILESERVER_H__2071A872_1E06_40CD_B1CB_6D809CDC7D19__INCLUDED_)
#define AFX_UGTERRAINTILESERVER_H__2071A872_1E06_40CD_B1CB_6D809CDC7D19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"

namespace UGC
{

//! \brief �������ݷ���
class SCENE_API UGTerrainTileServer  
{
public:
	//! \brief ���캯����
	UGTerrainTileServer();
	//! \brief ���캯����
	//! \param serverUrl ��ȡ���εķ���URL��ַ[in]��	
	//! \param levelZeroTileSizeDegrees ��0��ÿ��Ķ���[in]��
	//! \param samplesPerTile ÿ��ֱ���[in]��
	//! \param fileExtension ������չ��[in]��
	//! \param numberLevels ����[in]��
	//! \param terraintileDirectory �������ݱ��ش洢Ŀ¼[in]��
	//! \param dataType ������������[in]��
	UGTerrainTileServer(
		const UGString& serverUrl,
		UGdouble levelZeroTileSizeDegrees,
		UGint samplesPerTile,
		const UGString& fileExtension,
		UGint numberLevels,
		const UGString& terraintileDirectory,
		const UGString& dataType,UGdouble dNorth=PI/2,UGdouble dSouth=-PI/2, UGdouble dWest=-PI, UGdouble dEast=PI);
	//! \brief ����������
	virtual ~UGTerrainTileServer();

public:
	//! \brief ����ָ���ĵ��ο�ĵ������ݡ�
	//! \param pTerrainTile ���ο�ָ��[in]��
	//! \return �Ƿ����سɹ���
	UGbool DownloadTerrainDataFile(UGTerrainTile *pTerrainTile);	
	//! \brief ��ȡ�����ļ��Ŀ�����͡�
	//! \return ������͡�
	//! \remarks �ַ���"Int16"Ϊ����16λ, �ַ���"Float32"Ϊ������32λ ��
	UGString GetDataType();	
	//! \brief ��ȡָ���ľ�γ�ȶԶ�Ӧ�ĵؿ顣
	//! \param latitude ����[in]��
	//! \param longitude γ��[in]��
	//! \param samplesPerDegree �ֱ���[in]��
	//! \return �ؿ�ָ�롣
	UGTerrainTile* GetTerrainTile(UGdouble latitude, UGdouble longitude, 
		UGdouble samplesPerDegree);	
	UGdouble GetNorth(){return m_dNorth;};
	UGdouble GetSouth(){return m_dSouth;};
	UGdouble GetWest(){return m_dWest;};
	UGdouble GetEast(){return m_dEast;};

protected:
	//! \brief ��ȡ���εķ���URL��ַ��
	UGString m_strServerUrl;
	//! \brief ��0��ÿ��Ķ�����
	UGdouble m_dL0TileSizeDeg;
	//! \brief ÿ��ֱ��ʡ�
	UGint m_nSamplesPerTile;
	//! \brief ������
	UGint m_nNumberLevels;
	//! \brief ������չ����
	UGString m_strFileExt;
	//! \brief �������ݱ��ش洢Ŀ¼��
	UGString m_strTileDir;
	//! \brief �����������͡�
	UGString m_strDataType;
	UGdouble m_dNorth;
	UGdouble m_dSouth;
	UGdouble m_dWest;
	UGdouble m_dEast;
};
}

#endif // !defined(AFX_UGTERRAINTILESERVER_H__2071A872_1E06_40CD_B1CB_6D809CDC7D19__INCLUDED_)
