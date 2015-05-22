// UGTerrainTile.h: interface for the UGTerrainTile class.
/* 
	\file UGTerrainTile.h
	\brief ���ο�ͷ�ļ���
	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTERRAINTILE_H__0C84FBA0_9FA0_45FC_9556_9197E8D6DAFF__INCLUDED_)
#define AFX_UGTERRAINTILE_H__0C84FBA0_9FA0_45FC_9556_9197E8D6DAFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"

namespace UGC
{
//! \brief ���ο顣	
class SCENE_API UGTerrainTile  
{
public:
	//! \brief ���캯����
	UGTerrainTile();
	//! \brief ���캯����
	//! \param pTerraUGintileServer �������ݷ���[in]��
	UGTerrainTile( UGTerrainTileServer* pTerraUGintileServer );
	//! \brief ����������
	virtual ~UGTerrainTile();	

public:
	//! \brief ��ȡ���߽硣
	//! \return ���߽硣
	UGdouble GetEast();	
	//! \brief ���ö��߽硣
	//! \param value ���߽�[in]��
	void SetEast(UGdouble value);	
	//! \brief ��ȡ�ϱ߽硣
	//! \return �ϱ߽硣
	UGdouble GetSouth();
	//! \brief �����ϱ߽硣
	//! \param value �ϱ߽�[in]��
	void SetSouth(UGdouble value);
	//! \brief ��ȡ���߽硣
	//! \return ���߽硣
	UGdouble GetWest();	
	//! \brief �������߽硣
	//! \param value ���߽�[in]��
	void SetWest(UGdouble value);
	//! \brief ��ȡ���߽硣
	//! \return ���߽硣
	UGdouble GetNorth();	
	//! \brief ���ñ��߽硣
	//! \param value ���߽�[in]��
	void SetNorth(UGdouble value);
	//! \brief ���÷ֱ��ʡ�
	//! \param value �ֱ���[in]��
	void SetSamplesPerTile(UGint value);	
	//! \brief ��ȡ�ؿ����ڲ㡣
	//! \return �ؿ����ڲ㡣
	UGint GetTargetLevel();
	//! \brief ���õؿ����ڲ㡣
	//! \param value �ؿ����ڲ�[in]��
	void SetTargetLevel(UGint value);
	//! \brief ��ȡ�кš�
	//! \return �кš�
	UGint GetRow();
	//! \brief �����кš�
	//! \param value �к�[in]��
	void SetRow(UGint value);
	//! \brief ��ȡ�кš�
	//! \return �кš�
	UGint GetCol();
	//! \brief �����кš�
	//! \param value �к�[in]��
	void SetCol(UGint value);
	//! \brief ��ȡ���Ӧ�ı����ļ�����
	//! \return �ļ�����
	UGString GetTileFilePath();
	//! \brief ���ÿ��Ӧ�ı����ļ�����
	//! \param value �ļ���[in]��
	void SetTileFilePath(UGString value);

	//! \brief �Ƿ��ʼ����ϡ�
	//! \return �Ƿ��ʼ����
	UGbool IsInitialized();
	//! \brief ���ó�ʼ����־��
	//! \param value ��ʼ����־[in]��
	void SetInitialized(UGbool value);
	//! \brief �Ƿ���Ч��
	//! \return �Ƿ���Ч��
	UGbool IsValid();
	//! \brief ������Ч��־��
	//! \param value ��Ч��־[in]��
	void SetValid(UGbool value);

	//! \brief ��ȡÿ��Ķ�����
	//! \return ÿ��Ķ�����
	UGdouble GetTileSizeDeg();
	//! \brief ����ÿ��Ķ�����
	//! \param value ÿ��Ķ���[in]��
	void SetTileSizeDeg(UGdouble value);

	//! \brief ��ȡ�������ݡ�
	//! \return ��������ָ�롣
	UGfloat* GetElevationData();
	//! \brief ���õ������ݡ�
	//! \param pElevationData ��������ָ��[in]��
	void SetElevationData(UGfloat* pElevationData);
	//! \brief ��ȡ�������ݵ���Сֵ��
	//! \return ����������Сֵ��
	UGdouble GetMinValue();
	//! \brief ���õ������ݵ���Сֵ��
	//! \param value ����������Сֵ[in]��
	void SetMinValue(UGdouble value);
	//! \brief ��ȡ�������ݵ����ֵ��
	//! \return �����������ֵ��
	UGdouble GetMaxValue();
	//! \brief ���õ������ݵ����ֵ��
	//! \param value �����������ֵ[in]��
	void SetMaxValue(UGdouble value);	
	
	//! \brief ��ʼ���������ݡ�
	void Initialize();	
	//! \brief ��ȡָ����γ�ȵĸ߶ȡ�
	//! \param lat ����[in]��
	//! \param lon γ��[in]��
	//! \return �߶ȡ�
	UGfloat GetElevationAt(UGdouble lat, UGdouble lon);	

protected:
	//! \brief ���������ļ�����
	UGString m_strTileFilePath;
	//! \brief ÿ����ζ�����
	UGdouble m_dTileSizeDeg;
	//! \brief �ֱ��ʡ�
	UGint m_nSamplesPerTile;
	//! \brief �ϱ߽硣
	UGdouble m_dSouth;
	//! \brief ���߽硣
	UGdouble m_dNorth;
	//! \brief ���߽硣
	UGdouble m_dWest;
	//! \brief ���߽硣
	UGdouble m_dEast;
	//! \brief �кš�
	UGint m_nRow;
	//! \brief �кš�
	UGint m_nCol;
	//! \brief ������
	UGint m_nTargetLevel;
	//! \brief ��ʼ����־��
	UGbool m_bInitialized;
	//! \brief ��Ч��־��
	UGbool m_bValid;
	//! \brief �����������ֵ��
	UGdouble m_dMaxValue;
	//! \brief ����������Сֵ��
	UGdouble m_dMinValue;
	//! \brief �������ݷ���
	UGTerrainTileServer* m_pTerrainTileServer;
private:
	//! \brief �������ݡ�
	UGfloat* m_pElevationData;

};
}
#endif // !defined(AFX_UGTERRAINTILE_H__0C84FBA0_9FA0_45FC_9556_9197E8D6DAFF__INCLUDED_)
