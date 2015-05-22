// UGSitDataSource.h: interface for the UGSitDataSource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSITDATASOURCE_H__FBBB7A27_6C70_4577_A4EF_27C54755FF9A__INCLUDED_)
#define AFX_UGSITDATASOURCE_H__FBBB7A27_6C70_4577_A4EF_27C54755FF9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Base/UGFileStream.h"
#include "Base/ugtypedef.h"
#include "Engine/UGDataSource.h"

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#if defined WIN32
	#include <io.h>
#else
	//deleted by xielin �������ͷ�ļ����Բ������������������linux�·������벻��
	//#include <sm/io.h>
#endif

#include <stdio.h>


namespace UGC{

	
	struct SmSITFileHeader
	{
		UGbyte FileType[4];
		UGint nVersion;
		UGint nEncType;
		PixelFormat ipf;
		UGDatasetRasterInfo::IBSizeOption eBlockSize;
		UGint lBlockSizes;
		UGint nNoValue;
		UGint nTierCount;
		UGint nTierPosOffset;
		UGint nUnit;
		UGint nWidth;
		UGint nHeight;
		UGdouble dLeft;
		UGdouble dTop;
		UGdouble dRight;
		UGdouble dBottom;
		UGint nPalSize;
		UGint nReserve;
		UGbyte btReserved[40];
	};
	
	
	struct SmSITTierHeader 
	{
		UGint lWidth;
		UGint lHeight;
		UGint lWidthBytes;
		UGint lColBlocks;
		UGint lRowBlocks;
		UGint nClipRgnSize;
		UGdouble dXRatio;
		UGdouble dYRatio;
		UGbyte  btReserved[16];
	};
	
	struct SmBlkPos
	{
		UGuint dwRow;
		UGuint dwCol;
		UGlong nPos;
	};
	
	struct SmBlkPosAddr
	{
		UGuint nZippedSize;
		UGuint nOrgSize;
		UGlong nPos;
	};
	
	
	struct SmTierInfo
	{
		UGlong nTierPos;
		SmBlkPos * pBlkPos;
		SmSITTierHeader imgHeader;
	};

class SITENGINE_API UGSitDataSource : public UGDataSource
{
	friend class UGSitDatasetRaster;

public:
	UGSitDataSource();
	virtual ~UGSitDataSource();

	//! \brief  ��������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Create(){return FALSE;};
	
	//! \brief  ������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Open();
	
	//! \brief  �ر�����Դ
	virtual void Close();

	
	//! \brief  ��ȡ������ʱ��
	virtual UGTime GetDateLastUpdated() const{return UGTime(0.0);};
	
	//! \brief  ��ȡ����ʱ��
	virtual UGTime GetDateCreated() const{return UGTime(0.0);};
	
	//! \brief  ����������Ϣ
	virtual UGbool SaveInfo();
	
	//! \brief  �޸�����
	virtual UGbool ChangePassword(const UGString& strNewPassword) {return FALSE;};

	//! \brief  ͨ��DatasetVectorInfo�������ݼ�
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo) {return NULL;};
	
	UGDatasetTopo* CreateDatasetTopo(UGString strName){
		return NULL;
	};
	//! \brief  ͨ��DatasetRasterInfo�������ݼ�
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo) {return NULL;};
	
	//! \brief  ɾ�����ݼ�(ͨ������)
	virtual UGbool DeleteDataset(const UGString& strName) {return FALSE;};

	virtual UGMetadata* GetMetaData() {return NULL;};
	
	//! \brief  ����Դ�Ƿ����������
	virtual UGbool IsConnected();

	//! \brief  �����������ݿ�,��ˢ�����ݼ���
	virtual UGbool Connect();

protected:
	//! \brief ��ȡƥ���ͶӰxml�ļ�
	UGbool OpenPrjFile();
	
private :
	SmSITFileHeader		m_fileHeader;
	SmTierInfo *		m_pTierInfos;
	UGint				m_fHandle;
	UGRect				m_rcView;
	UGRect				m_rcTierView;
	UGint				m_nSizeX;
	UGint				m_nSizeY;
	UGint				m_nTierIndex;
	UGColorTable		m_ColorTable;
};

extern "C" SITENGINE_API UGDataSource* CreateDataSource();

}

#endif // !defined(AFX_UGSITDATASOURCE_H__FBBB7A27_6C70_4577_A4EF_27C54755FF9A__INCLUDED_)
