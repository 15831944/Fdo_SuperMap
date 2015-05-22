// SdbDatasetRaster.h: interface for the UGSdbPlusDatasetRaster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDBDATASETRASTER49_H__D9758FB9_30E0_11D3_A626_0080C8EE6685__INCLUDED_)
#define AFX_SDBDATASETRASTER49_H__D9758FB9_30E0_11D3_A626_0080C8EE6685__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define SM_SDB_RASTER_EMPTY_BLOCK_POSITION  -2		//ѹ�����ݼ���ImgBlock����������ǿյĿ飬�Ͳ��ô�ŵ��ļ���,���Ա���ѹ���ͼ�ѹ��

namespace UGC{

class SDBPLUSENGINE_API UGSdbPlusDatasetRaster : public UGDatasetRaster
{
	friend class UGSdbPlusDataSource;

protected:

	UGSdbPlusDatasetRaster();
	UGSdbPlusDatasetRaster(UGDataSource *pDataSource);

public:	
	~UGSdbPlusDatasetRaster();

public:	//From CSmDataset
	
	UGbool Open();	//��
	void Close();	//�ر�
	virtual UGbool IsOpen() const;	//�Ƿ�ر�

	UGbool SaveInfo();	//ͼ�������Ϣ����

	//���ݼ�����
	UGTime GetDateLastUpdated();		//��������������
	UGTime GetDateCreated();			//���ش�������
	
	UGbool CanUpdate();		//�Ƿ�ɸ���

	//�߽�
	UGbool ComputeBounds();	//������ʱû����,��֪�����������ʲô.
	
	virtual UGbool BuildPyramid(UGbool bShowProgress); 
	virtual UGbool Rename(const UGString& strNewName);			//���ݼ�������

	virtual UGbool IsSupport(UGEngAction dwEngAction);

	virtual UGbool CacheByBlock(int nLeft,int nTop,int nWidth, int nHeight);

	virtual UGbool RemovePyramids();

	//! ע��ѡ����Ϣ
	virtual UGbool RegisterOption(UGint nOption);

	//! ��ע��ѡ����Ϣ
	virtual UGbool UnRegisterOption(UGint nOption);

	//! �ж����ݼ��Ƿ���ĳ��ѡ����Ϣ
	virtual UGbool HasFlag(UGint nOption);

public:
	virtual UGbool RefreshInfo();
	virtual UGString GetTableName();

protected:
	UGSdbDatasetInfo m_DatasetInfo;
//	UGGeoRegion m_ClipRgn;
	UGString m_strMrSIDPassword;
	
protected:
	UGFolder *m_pFolderDataset;			//ͼ���storage
	UGFolder *m_pFolderPyramid;			//���������Storage

	UGFileLogical	*m_stmGeometry;			//��ſռ�����ImgBlock
	UGFileLogical	*m_stmIndex;			//��ſռ�����λ������,����ѹ���洢�����ݼ���Ч

	UGFileLogical	*m_pFileInfo;				//���ͼ����Ϣ
	UGFileLogical	*m_stmMetadata;			//���ͼ��Ԫ����
	UGFileLogical	*m_stmColorTable;		//���ͼ���ɫ��

	UGint*  m_pBlockIndex;		//Image��λ������

protected:
	//Ԫ������������
	UGint GetMetadataDescCount();		//����Ԫ������������
	UGbool GetMetadataDesc(UGint nIndex, UGString &strTitle, UGString &strContent);	//����Ԫ��������
	UGint AddMetadataDesc(UGString strTitle, UGString strContent);	//׷��Ԫ���������ַ��������е�Ԫ���������ַ������棬������ӵ���λ��
	void ClearMetadataDesc();				//���ԭ�е�Ԫ��������
	UGbool DeleteMetadataDesc(UGint nIndex);	//׷��Ԫ���������ַ��������е�Ԫ���������ַ�������

protected:

	/////////////////////////////////////////////////////
	//����!!��������������UGDatasetRaster�м̳�,����ʵ��
	/////////////////////////////////////////////////////
	UGImgBlock* LoadBlock(UGint lRowBlock,UGint lColBlock); //Load image block to mem
	UGbool SaveBlock(UGImgBlock* pImgBlock);	//Save image block to disk

protected:
	
	//strName:			ͼ�����ƣ��������Ѵ��ڵ�ͼ��ͬ���������ִ�Сд
	//nType:			ͼ�����ͣ��μ�SmElemDatasetInfo.h�еĶ��塣ע�⣬ͼ�����Ϳ����Ƕ�����͵���ϣ�����CAfcType::ltNetwork|CAfcTypeltRegion
	//ImgPixelFormat	Image��ʽ,�����SmDefStruct.h
	//lWidth			Image���(��ĸ���)
	//lHeight			Image�߶�(��ĸ���)
	//eBlockSize		Image��ı߳���С,�����SmDefStruct.h
	
	UGbool Create(const UGDatasetRasterInfo& Info);
	
	UGbool IsValidDataset();	//�ж��Ƿ�Ϸ�Dataset

	UGbool LoadBlockIndex();
	
	UGbool FillPyramidDatasets();
	
	UGbool ReleasePyramidDatasets();

	UGbool OpenPyramid(UGFolder* storage);		//���������ݼ��Ĵ򿪣�����ͨ�����ݼ���ȣ�û��m_pDataSource;
	
	UGDatasetRaster* Tier(UGString strName, UGint lWidth,UGint lHeight,
						UGDatasetRasterInfo::IBSizeOption eBlockSize,UGint nOptions);
	
	UGbool SaveCompressedBlock(UGImgBlock* pImgBlock);
	UGImgBlock* LoadCompressedBlock(UGint lRowBlock,UGint lColBlock);
//	BYTE* m_pCompressBuffer;		//����ѹ������ʱ�ڴ�,��Լ��һ��Image Bloc���ݴ�С��
	
};

}

#endif // !defined(AFX_SDBDATASETRASTER49_H__D9758FB9_30E0_11D3_A626_0080C8EE6685__INCLUDED_)