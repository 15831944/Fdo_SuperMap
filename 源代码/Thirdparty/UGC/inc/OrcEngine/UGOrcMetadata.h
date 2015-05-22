// UGOrcMetadata.h: interface for the UGOrcMetadata class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGORCMetadata_H)
#define UGORCMetadata_H

#include "Base/ugdefs.h"	// Added by ClassView
#include "Engine/UGMetaData.h"

namespace UGC
{

class ORCENGINE_API UGOrcMetadata :public UGMetadata
{
public:
	UGOrcMetadata();
	UGOrcMetadata(UGDataSource *pDatasource);
	virtual ~UGOrcMetadata();

public:
	//! \brief ����Ԫ���ݿ���ص�����Դ
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

	//! \brief ˢ��Ԫ���ݣ��������õ�����Դ,��ɾ�������ݼ�Ԫ����Ҫɾ��������ӵ����ݼ������Զ����Ԫ����
	//! \return ��
	//! \remarks ��
	//! \attention ��
    virtual UGbool RefreshDatasource();

	//ģ�����
	//! \brief ����ģ�棬���ģ�����û�������	
	virtual UGbool AddTemplateFile(UGString strCaptial,UGString &strFormatFile,UGString &strDescription);
	
	//! \brief ��ȡ���ݿ�������ģ�������
	virtual UGbool GetTemplateNames(UGArray<UGString> &aryNames);

	//! \brief ͨ��ģ�����ֵõ�ģ������
	virtual UGString GetTemplateByName(UGString strCaptial);

	//! \brief ɾ��ģ��
	virtual UGbool DeleteTemplateByName(UGString strCaptial);

	//! \brief ɾ��Ԫ����
	virtual UGbool DeleteMetadata(UGString strDatasetName, UGint nTierID);

	//Mapping���
	//! \brief ���ӳ�� ��ϵ�����strTag�Ѿ������򷵻�False
	virtual UGbool AddMapping(MappingField nMaping, UGString strTag);

	//! \brief ͨ�����ֻ�ȡ ��Ӧ���ֶ�
	virtual UGint GetMapping(UGString strTag);
	
	//! \brief ��ȡ���е�ӳ��
	virtual UGbool GetAllMapping(UGArray<UGString> aryTags, UGArray<UGint> arrField);

	//! \brief ɾ��һ��ӳ��
	virtual UGbool DeleteMapping(UGString strTag);
	
	virtual UGbool QueryMetadataWithFilter(UGString strFilter,UGMetaElements &Metadatas);
	
protected:
	virtual UGbool IsMetadataExist(UGint nDatasetID);

	virtual UGbool AddMetadataDesc(UGint nDatasetID,UGint nTileID, UG_META_ELEMENT & MetaElement);

private:
	virtual void FillMapping(UGbool bTagFirst);

	virtual void UpdateRegister();
	void UpdateVectorRegister();
	void UpdateRasterRegister();

	UGbool RefreshVectorRegister();
	UGbool RefreshRasterRegister();

	//! \brief ��QueryDTsWithFilter �е���
	virtual UGbool QueryDTsWithFilterSub(UGArray<UGString> arrTags,UGArray<UGString> arrVals,
		UGDatasetTierNames &datasetTierIDs, UGbool bFuzzyQuery);

	//! \brief ��QueryDTsWithBounds �е���
	virtual UGbool QueryDTsWithBoundsSub(UGRect2D rcBounds,UGDatasetTierNames &datasetTierIDs);

	UGString BuildQueryFilterSQL(UGArray<UGString> arrTags,UGArray<UGString> arrVals,UGbool bFuzzyQuery);
	
	UGString BuildQueryBoundsSQL(UGRect2D rcBounds);
};

}

#endif // !defined(UGORCMetadata_H)
