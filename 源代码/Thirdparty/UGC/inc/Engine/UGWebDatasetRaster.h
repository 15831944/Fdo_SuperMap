//////////////////////////////////////////////////////////////////////////
//!  \file UGWebDatasetRaster.h:
//!  \brief UGWebDatasetRaster դ���͵��������ݼ���Ľӿڶ��塣
//!  \details �ļ���ϸ��Ϣ��
//!  \author duxiaomin��
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br>
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGWEBDATASETRASTER_H__2D4A9A10_F7EA_4FD6_BE42_677DD871669E__INCLUDED_)
#define AFX_UGWEBDATASETRASTER_H__2D4A9A10_F7EA_4FD6_BE42_677DD871669E__INCLUDED_

#include "Base/ugdefs.h"
#include "Engine/UGDataset.h"

#include "Engine/UGDatasetRaster.h"

namespace UGC{

//! \brief դ���͵��������ݼ��ࡣ
class ENGINE_API UGWebDatasetRaster :public UGDataset
{
public:
	UGWebDatasetRaster();
	UGWebDatasetRaster(UGDatasetRasterInfo& rInfo);
	virtual ~UGWebDatasetRaster();

public:
	virtual UGbool Open() ;			
	virtual void Close() ;
	virtual UGTime GetDateLastUpdated() ;
	virtual UGTime GetDateCreated() ;
	virtual UGString GetName() ;		//	
	virtual UGString GetTableName() ;
	virtual UGbool Rename(const UGString& strNewName) ;		//
	virtual UGdouble GetMinZ() ;
	virtual void SetMinZ(UGdouble d) ;
	virtual UGdouble GetMaxZ() ;
	virtual void SetMaxZ(UGdouble d) ;
	virtual UGint GetDimension() ;
	virtual UGbool IsVector() ;		//
	virtual UGbool IsTopoDataset() ;		//
	virtual UGbool IsRaster() ;		//
	virtual UGbool IsLinkTable() ;		//
	virtual const UGRect2D& GetBounds() const ;
	virtual UGDataset::DatasetType GetType() const;		//
	virtual void SetBounds(const UGRect2D& r) ;
	virtual UGDataCodec::CodecType GetCodecType() ;
	virtual void SetCodecType(UGDataCodec::CodecType c) ;
	virtual UGint GetOptions() ;
	virtual UGbool SaveInfo() ;
	virtual UGbool RefreshInfo() ;	
protected:
	virtual void SetOptions(UGint nOptions);

public:

	//! \brief �õ������ڴ��դ�����ݼ���
	//! \param strURL ��Web����Դ�����URL[in]��
	//! \return դ�����ݼ�ָ�롣
	//! \remarks �������غ������ɴ˺�����װ��
	virtual UGDatasetRaster* GetDatasetRaster(UGString strURL) =0;

	//! \brief �õ������ڴ��դ�����ݼ�,���ڷŴ���Сƽ�Ʋ���������
	//! \param rcBound ����Ӱ���������Χ[in]��
	//! \param dWidth ����Ӱ��Ŀ��,��λ����[in]��
	//! \param dHeight ����Ӱ��ĸ߶�,��λ����[in]��
	//! \param strFormat ����Ӱ��ĵĸ�ʽ[in]��
	//! \return դ�����ݼ�ָ�롣
	virtual UGDatasetRaster* GetDatasetRaster(UGRect2D rcBound,
		UGint dWidth,UGint dHeight,UGString strFormat ="") = 0;
	

	//! \brief �õ�����Դ������ͼ�������顣
	//! \param aryNames ͼ��������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetAllLayerNames(UGArray<UGString>& aryLayerNames) = 0;

	//! \brief �õ�����Դ������ͼ��������顣
	//! \param aryNames ͼ���������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetAllLayerTitles(UGArray<UGString>& aryLayerTitles) = 0;

	//! \brief �õ�����Դ������ͼ�������顣
	//! \param aryNames ͼ��������[out]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetAllLayerIndexes(UGArray<UGint>& aryLayerIndexes) = 0;
	
	//! \brief �õ����пɼ�ͼ�������顣
	//! \param aryNames �ɼ�ͼ��������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerNames(UGArray<UGString>& aryLayerNames) = 0;
	
	//! \brief �õ����пɼ�ͼ��������顣
	//! \param aryNames �ɼ�ͼ��ͼ���������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerTitles(UGArray<UGString>& aryLayerTitles) = 0;

	//! \brief �õ����ݼ����пɼ���ͼ���ż��ϡ�
	//! \param aryNames �ɼ�ͼ��������[in]��
	//! \return �Ƿ�ɹ��õ�,�ɹ�����TRUE,ʧ�ܷ���FALSE��
	virtual UGbool GetVisibleLayerIndexes(UGArray<UGint>& aryLayerIndexes) = 0;

	//! \brief ���õ�ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param arySrc Դͼ��������[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	virtual UGbool SetVisibleLayers(const UGArray<UGint>& aryLayerIndexes) = 0;	

	//! \brief ���õ�ǰ���ݼ��Ŀɼ�ͼ�㡣
	//! \param arySrc Դͼ����Ϣ����[in]��
	//! \return �Ƿ����óɹ�,�ɹ�����TRUE,���򷵻�FALSE��
	virtual UGbool SetVisibleLayers(const UGArray<UGString>& aryLayerNames) = 0;	
	
	//! \brief ������Դ�õ�������URL��
	//! \return ������URL��
	UGString GetBasalURL();	

public:
	//! \brief �ڴ�����Դ��ָ�����顣
	//! \remarks ��ע��Ϣ��
	UGArray<UGDataSource *> m_MemDataSource;
	
protected:
	//! ����Ϊ��ʵ��GetBounds����˳�Ա
	UGDatasetRasterInfo m_RasterInfo;

};

}

#endif // !defined(AFX_UGWEBDATASETRASTER_H__2D4A9A10_F7EA_4FD6_BE42_677DD871669E__INCLUDED_)

