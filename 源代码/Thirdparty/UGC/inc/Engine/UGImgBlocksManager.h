// UGImgBlocksManager.h: interface for the UGImgBlockManager class.
//
//////////////////////////////////////////////////////////////////////
/* 
	\file UGImgBlocksManager.h
	\brief ������߳�Block������
	\author ������
	\attention �̰߳�ȫ
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/


#if !defined(AFX_UGIMGBLOCKMANAGER_H__1A2DC698_B9F7_40D2_8DE3_2C83B9380D68__INCLUDED_)
#define AFX_UGIMGBLOCKMANAGER_H__1A2DC698_B9F7_40D2_8DE3_2C83B9380D68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Geometry/UGImgBlock.h"

namespace UGC {

class UGDatasetRaster;

class ENGINE_API UGThreadBlocks
{
public:
	UGThreadBlocks();
public:
	UGArray<UGint> m_aryPos;
	UGImgBlocks m_ImgLoadedBlocks;
};

class ENGINE_API UGImgBlocksManager  
{
public:
	UGImgBlocksManager();
	UGImgBlocksManager(UGDatasetRaster *pDtRaster);
	virtual ~UGImgBlocksManager();

	//! \brief ����ָ���Ļ����Block
	//! \param y [in] ���ݿ���ĵڼ��� ��Ӧ����ΪSmColumn
	//! \param x [in] ���ݿ���ĵڼ��� ��Ӧ���ݿ����SmRow
	//! \param *pImgBlock [out] ������ָ��
	//! \return ÿ���߳�ά���Լ����ڴ�
	//! \remarks �����ǰλ���Ѿ��������ݵ�ָ�룬��ôɾ��֮
	//! \attention 
	UGbool SetBlockAt(UGint y,UGint x,UGImgBlock *pImgBlock);

	//! \brief ����ָ���Ļ����Block
	//! \param nIndex [in] Position
	//! \param *pImgBlock [in] ImgBlock
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool SetBlockAt(UGint nIndex,UGImgBlock *pImgBlock);	

	//! \brief �õ�ָ���Ļ����Block
	//! \param y [in] ���ݿ���ĵڼ��� ��Ӧ����ΪSmColumn
	//! \param x [in] ���ݿ���ĵڼ��� ��Ӧ���ݿ����SmRow
	//! \param *pImgBlock [out] ���ص�ָ��
	//! \return ÿ���߳�ά���Լ����ڴ�
	//! \remarks ��
	//! \attention ��
	UGImgBlock * GetBlockAt(UGint y,UGint x);
	

	//! \brief �õ�ָ��λ�õĻ���Block
	//! \param nIndex [in] һά�����λ��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGImgBlock * GetBlockAt(UGint nIndex);	

	//! \brief �ͷŵ�ǰ�̻߳��������
	//! \return TRUE 
	//! \remarks 
	//! \attention ���Block�޸��ˣ�Ҫ�����޸ĵ����ݿ�
	UGbool ReleaseBlocks();


	//! \brief �õ����е�Img��ָ��Ϊ�˿��ٱ���Щ����
	//! \return TRUE
	//! \remarks ���ص�ָ��ֻ��������ɾ��
	//! \attention ��
	UGImgBlocks * GetAllBlocks();

	//! \brief ��ʼ����
	//! \param *pDataset [in]��
	//! \param FALSE [in]��
	//! \return True
	//! \remarks Ĭ����֧�ֶ��̵߳ģ�������SDB���治֧����ô���ò�֧�ַ�ʽ������
	//! \attention ��
	UGbool SetDataset(UGDatasetRaster *pDataset,UGbool bSingleThread = FALSE);	

protected:
	UGDatasetRaster *m_pRaster;
	UGArray<UGint> m_aryThreadIDs;
	UGArray<UGThreadBlocks*> m_aryImgBlocks;
	UGbool m_bSingleThread;
};

}

#endif // !defined(AFX_UGIMGBLOCKMANAGER_H__1A2DC698_B9F7_40D2_8DE3_2C83B9380D68__INCLUDED_)
