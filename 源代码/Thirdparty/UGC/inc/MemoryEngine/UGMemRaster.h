//=====================================================================================
// ��Ŀ����			SuperMap Foundation Class (SFC) Library 2.0
// ��  �ߣ�			������,������
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSuperMap GIS����������Ա��δ����ɲ������Դ�����
//					2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����			SmDatasetRaster.h, SmDatasetRaster.cpp
// ��  ����			CDatasetRaster
// ��  �ࣺ			CSmDataset
// ��  �ࣺ			���������Ӱ�����ݼ��࣬��SDB��CSdbDatasetRaster, Oracle��COrcDatasetRaster��
// ����˵����		դ��Ӱ�����ݼ�����
// ����˵����		����������࣬����ֱ��ʹ�ã���Ҫ�����ʵ��������غ���
//=====================================================================================

 
#if !defined(AFX_SMMEMRASTER_H__0FD41E37_3273_11D3_A62A_0080C8EE6685__INCLUDED_)
#define AFX_SMMEMRASTER_H__0FD41E37_3273_11D3_A62A_0080C8EE6685__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDatasetRaster.h"
#include "Geometry/UGImgBlock.h"
#include "MemoryEngine/UGMemDataSource.h"

namespace UGC
{

class MEMENGINE_API UGMemRaster : public UGDatasetRaster
{
	friend class UGMemDataSource;
public:
	UGMemRaster();	
	UGMemRaster(UGMemDataSource *pDataSource);
	virtual ~UGMemRaster();
 
public:
	//! �����ݼ�
	virtual UGbool Open();

	//! �ر����ݼ�
	virtual void Close();

	//! ����������ʱ��
	virtual UGTime GetDateLastUpdated();

	//! ���ش���ʱ��
	virtual UGTime GetDateCreated();

	//! ���ݼ�������,ֻ�ı����ݼ���,��������
	virtual UGbool Rename(const UGString& strNewName);

	//! �������ݼ���Ϣ
	virtual UGbool SaveInfo();

	//! ˢ�����ݼ���Ϣ
	virtual UGbool RefreshInfo();

	//! �������ݼ���Ӧ����
	virtual UGString GetTableName();

	virtual UGbool BuildPyramid(UGbool bShhowProgress);
	virtual UGbool RemovePyramids();
	
	//! ����ָ��������
	virtual UGImgBlock* LoadBlock(UGint nRowBlock,UGint nColBlock);
    
	//! pImgBlock����
	virtual UGbool SaveBlock(UGImgBlock* pImgBlock);

public:
	UGbool Create(UGMemRaster *pDatasetParent, const UGDatasetRasterInfo & rInfo);

};

}

#endif // !defined(AFX_SMMEMRASTER_H__0FD41E37_3273_11D3_A62A_0080C8EE6685__INCLUDED_)
