/*!
    **************************************************************************************
     \file     UGMetaData.h
    **************************************************************************************
     \author	������
     \brief		Ԫ���ݲ���                   
     \remarks	��Ҫ�Ǹ�������Դ������Ԫ����	                                          <br>
				�漰��������:	1, �Ǹ�����Դ��Ԫ����.
								2, Ԫ���ݴ洢������
				����׼���������,��Դ�Ǹ�����Դ,�洢Ҳ�Ǹ�����Դ.
				һ������Դ���Դ洢���Ԫ����.
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     18/05/2005  ������    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

	<b>����˵��</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
    **************************************************************************************
*/

#if !defined(UGMetadata_H)
#define UGMetadata_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"
#include "Base/UGMarkup.h"
#include "Base/UGDict.h"

#include "UGDataSource.h"
#include "UGEngDefs.h"

namespace UGC
{
#define  SmEastBLName		"#eastBL"		//��
#define  SmSouthBLName		"#southBL"		//��
#define  SmWestBLName		"#westBL"		//��
#define  SmNorthBLName		"#northBL"		//��
#define  SmFieldinfosName	"#feildInfos"
#define  SmDatasetNameName	"#datasetName"	//���ݼ�����
#define  SmRecordCountName	"#recordCount"	//���ݼ���¼��
#define  SmDatasetTypeName	"#datasetType"
#define  SmTableNameName	"#tableName"
#define  SmCreatorName		"#creator"
#define  SmCreateTimeName	"#createTime"	
#define  SmLastUpdateTimeName "#lastUpdateTime"
#define  SmNovalueName		"#noValue"
#define  SmPixelFormatName	"#pixelFormat" 
#define  SmWidthName		"#width"
#define  SmHeightName		"#height"
	
class ENGINE_API UGMetaElements:public UGArray<UG_META_ELEMENT> 
{
	
};

class ENGINE_API UGDatasetTierNames:public UGArray<UG_DATASET_TIER_NAME>
{

};

class ENGINE_API UGDatasetMetaData
{
public:
	UGString GetMetadata();
	UGbool ImportMetadata(UGString &strXML);

	UGString GetTileMetadata(UGint nTileID);
	UGbool ImportMetadata(UGint nTileID,UGString &strXML);

	UGbool IsTile();
public:
	UGint m_nDatasetID;
	UGString m_strDatasetName;

};

class ENGINE_API UGDatasourceMetaData
{
public:
	UGString GetDatasourceMeta();
	UGbool GetAllDatasetMetas(UGArray<UGDatasetMetaData> & arydatasetMetas);
public:
	UGint m_nID;
	UGString m_strDsName;
	UGArray<UGDatasetMetaData> m_aryDatasetMeta;
};


class ENGINE_API UGMetadata  
{
public:
	//Maping �ļ���ĺ�
	enum MappingField
	{
		SmNone			= -1,
		SmEastBL		= 0,
		SmSouthBL		= 1,
		SmWestBL		= 2,
		SmNorthBL		= 3,			
		SmDatasetName	= 4,
		SmTableName		= 5,
		SmDatasetType	= 6,
		SmRecordCount	= 7,
		SmFieldinfos	= 8,
		SmCreator		= 9,
		SmCreateTime    = 10,
		SmLastUpdateTime= 11,
		SmNovalue		= 12,
		SmPixelFormat	= 13,
		SmWidth			= 14,
		SmHeight		= 15
	};
	enum MetaQueryMode
	{
		MQVector	=	1,	//ֻ��ѯʸ��Ԫ����
		MQRaster	=	2,	//ֻ��ѯդ��Ԫ����
		MQAll		=	3	//ȫ��
	};
public:
	UGMetadata();
	virtual ~UGMetadata();

public:
	//! \brief ����������Ϣ���õ��洢Ԫ���ݵ�����Դ
	//! \param *conn [in]��
	//! \return 
	//! \remarks 
	//! \attention ��
	UGbool OpenDesDatabase(UGDsConnection conn);
	
	//! \brief ����Ԫ���ݿ���ص�����Դ,��Ҫ�ȵ���OpenDesDatabase()
	//! \param *pDatasource [in]��
	//! \return 
	//! \remarks ����֮����Ե���ˢ�¹��ܣ���ˢ��Ԫ���ݣ�����֤�͵�ǰ��������Դ��Ϣһ��
	//			 ���Ԫ���ݿ���û���������Դ�������һ�����ж��Ƿ��еı�־�ǣ�
	//			 ���ݿ������û�����	
	//! \attention ��
	virtual UGbool SetDatasource(UGDataSource *pDatasource);

	//! \brief ɾ������Դ��Ԫ���������Ϣ
	virtual UGbool DeleteDSRegister(UGDataSource *pDatasource);

	//! \brief ��õ�ǰԪ���ݿ��д洢������Դ��������Ϣ
	virtual UGbool GetDatasoures(UGArray<UGDsConnection> &arrConns);

	//! \brief ��õ�ǰ����Դ��Ԫ�����Ѿ����ڵ����ݼ���
	virtual UGbool GetDatasetNames(UGDatasetTierNames &datasetTierIDs);

	//ģ�����
	//! \brief ���ģ�棬���ģ�����strCaptial�Ѿ������򷵻�False
	virtual UGbool AddTemplateFile(UGString strCaptial,UGString &strFormatFile,UGString &strDescription);

	//! \brief ��ȡ���ݿ�������ģ�������
	virtual UGbool GetTemplateNames(UGArray<UGString> &aryNames);

	//! \brief ͨ��ģ�����ֵõ�ģ������
	virtual UGString GetTemplateByName(UGString strCaptial);

	//! \brief ɾ��ģ��
	virtual UGbool DeleteTemplateByName(UGString strCaptial);

	//! \brief ͨ��ģ������ ���õ�ǰʹ�õ�ģ��
	//! \param strCaptial [in]��
	UGbool SetTemplate(UGString strCaptial);

	//Mapping���
	//! \brief ���ӳ�� ��ϵ�����strTag�Ѿ������򷵻�False
	virtual UGbool AddMapping(MappingField nMaping, UGString strTag);

	//! \brief ͨ�����ֻ�ȡ ��Ӧ���ֶ�
	virtual UGint GetMapping(UGString strTag);
	
	//! \brief ��ȡ���е�ӳ��
	virtual UGbool GetAllMapping(UGArray<UGString> aryTags, UGArray<UGint> arrField);

	//! \brief ɾ��һ��ӳ��
	virtual UGbool DeleteMapping(UGString strTag);

	UGString GetMetaMappintTable(){
		return m_strMetaMappingTable;
	};

	UGString GetMetaVectorTable(){
		return m_strMetaVectorTable;
	};

	UGString GetMetaRasterTable(){
		return m_strMetaRasterTable;
	};

	//! \brief ˢ��Ԫ���ݣ��������õ�����Դ,��ɾ�������ݼ�Ԫ����Ҫɾ��������ӵ����ݼ������Զ����Ԫ����
	//! \return ��
	//! \remarks ��
	//! \attention ��
    virtual UGbool RefreshDatasource();

//	//! \brief �õ����е����ݵ�Ԫ����
//	//! \param aryDSMetadatas [in]��
//	//! \return ��
//	//! \remarks ��
//	//! \attention ��
//	UGbool GetDatasourceMetadatas(UGArray<UGDatasourceMetaData> & aryDSMetadatas);
//
//	//! \brief ��
//	//! \param nIndex [in]��
//	//! \return ��
//	//! \remarks ��
//	//! \attention ��
//	UGDatasourceMetaData* GetDatasourceMetadata(UGint nIndex);
//
//	//! \brief ��
//	//! \param strAlias [in]��
//	//! \return ��
//	//! \remarks ��
//	//! \attention ��
//	UGDatasourceMetaData* GetDatasourceMetadata(UGString strAlias);	

public:
	//! \brief ����Ԫ����
	UGbool ImportMetadata(UGString strDatasetName, UGint nTileID, UGString &strMetaFile);

	//! \brief ɾ��Ԫ����
	virtual UGbool DeleteMetadata(UGString strDatasetName, UGint nTierID);

	//! \brief ��ȡԪ����
	UGbool GetMetadata(UGString strDatasetName,UGint nTierID,UGString &strXml);

	//! \brief ��ѯԪ����
	UGbool SetQueryMode(MetaQueryMode mode);

	virtual UGbool QueryMetadataWithFilter(UGString strFilter,UGMetaElements &Metadatas) = 0;
	
	UGbool QueryDTsWithFilter(UGArray<UGString> arrTags,UGArray<UGString> arrVals,
		UGDatasetTierNames &datasetTierIDs, UGbool bFuzzyQuery);

	UGbool QueryDTsWithBounds(UGRect2D rcBounds,UGDatasetTierNames &datasetTierIDs);
	
	UGString GetMappingFieldName(MappingField nField);

	UGint GetMappingFieldCaption(UGString strTag);

	UGTextCodec::Charset GetFileEncoding(UGString &strFile, UGbool bStrIsFile = TRUE);

	UGbool InitDataset(UGString strDataset, UGint nTileID);

protected:
	//! \brief �жϵ�ǰ���ݼ���Ԫ�����Ƿ��Ѿ�����
	virtual UGbool IsMetadataExist(UGint nDatasetID);
	
	virtual UGbool AddMetadataDesc(UGint nDatasetID,UGint nTierID,UG_META_ELEMENT & MetaElement) = 0;
	
	void ParseMetadata(UGMarkup &makeup,UG_META_ELEMENT &metadata);
	
	void MatchingMetaData(UGMarkup &markup,UGString &strMetaFile,UGString &strFormatFile);

private:
	
	void MatchingElem(UGMarkup &markup,UGMarkup &Metafile, UGMarkup &Formatfile);
	
	//!�����ݿ������
	UGbool ReadMaping(UGMarkup &markup,UG_META_ELEMENT &metaElement);

	virtual void FillMapping(UGbool bTagFirst);

	virtual void UpdateRegister();

	//! \brief ��QueryDTsWithFilter �е���
	virtual UGbool QueryDTsWithFilterSub(UGArray<UGString> arrTags,UGArray<UGString> arrVals,
		UGDatasetTierNames &datasetTierIDs, UGbool bFuzzyQuery) = 0;

	//! \brief ��QueryDTsWithBounds �е���
	virtual UGbool QueryDTsWithBoundsSub(UGRect2D rcBounds,UGDatasetTierNames &datasetTierIDs)  = 0;

	UGString DatasetType2String(UGDataset::DatasetType nType); 

	UGString PixelFormat2String(PixelFormat pixF);

protected:
	//��Ҫ �洢Ԫ���ݵ�����Դ
	UGDataSource *m_pDatasource;
	
	//�洢Ԫ���ݵ����ݿ�
	UGDataSource *m_pDesDatasource;

	//�� m_pDatasource ����Դ��ص� Ԫ���ݱ� ����
	UGString m_strMetaMappingTable;
	UGString m_strMetaVectorTable;
	UGString m_strMetaRasterTable;
	UGString m_strMetaVectorRegister;
	UGString m_strMetaRasterRegister;

	//��ǰ���ݼ��Ƿ���ʸ�����ݼ�����topo���ݼ�
	UGbool m_bIsDatasetVector;

	//��ǰ���õ�Ԫ����ģ��
	UGString m_strTemplateName;

	UGint m_nLevel;
	UGint m_nDatasetID;
	UGint m_nTileID;

	//ӳ���
	UGDict<UGString,UGString> m_MapDict;
	
	//��ǰ���ݼ�ָ��
	UGDataset    *m_pDataset;

	//��ѯģʽ
	MetaQueryMode m_QueryMode;
};
}


#endif // !defined(UGMetadata_H)
