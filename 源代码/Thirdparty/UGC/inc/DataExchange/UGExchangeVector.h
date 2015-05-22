
/*!
    **************************************************************************************
     \file     UGExchangeVector.h
    **************************************************************************************
     \author   ����
     \brief    ����ת������-----����ת��ʸ����                      
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/

#if !defined(AFX_UGEXCHANGEVECTOR_H__F0CBB300_85F0_4105_87D2_F0F9F5C211B5__INCLUDED_)
#define AFX_UGEXCHANGEVECTOR_H__F0CBB300_85F0_4105_87D2_F0F9F5C211B5__INCLUDED_


#include "UGExchangeFile.h"
#include "Base/UGList.h"
#include "Base/UGDict.h"
#include "Base/UGProgress.h"
#include "Engine/UGDatasetVector.h"

namespace UGC {

class UGRecordset;
class UGFileParseVector;
class UGDatasetVector;
	
class UGExchangeVector : public UGExchangeFile  
{
public:
	UGExchangeVector();
	virtual ~UGExchangeVector();

public:
	//! \brief ����Ϊ�����ݼ�
	virtual UGbool Import(UGDataSource* pDataSource, const UGString& strFilePathName);
	
	//! \brief	����Ϊ�������ݼ�
	virtual UGbool ImportCAD(UGDataSource* pDataSource, const UGString& strFilePathName);

	//! \brief	������δʵ�֣�
	virtual UGbool Export(UGDataSource* pDataSource, const UGString& strFilePathName);

	
public:
	//! \brief	���·�����Ϊ�������÷���
	void SetDgnColorMappingTableName(const UGString& strDgnColorMappingTableName);

	void SetToleranceGrain(UGdouble dToleranceGrain);

	void SetSrcDefaultUnits(UGint nSrcDefaultUnits);

	void SetDgnUnitsSelected(UGint nDgnUnitsSelected);

	void SetLayers(const UGList<UGString>& layers);

	void SetLayerName(const UGString& strLayerName);

	void SetElevationName(const UGString& strElevationName);

	void SetIsImportAsCompressedDatset(UGbool bImportAsCompressedDatset);

	void SetIsIgnoreNetworkTopology(UGbool bIgnoreNetworkTopology);

	void SetIsIgnoreStyle(UGbool bIgnoreStyle);

	void SetIsBuildSpatialIndex(UGbool bBuildSpatialIndex);

	void SetIsHoldNoGeometryDT(UGbool bHoldNoGeoDT);

	void SetSymbolStyle();

	//! brief ���÷��Ŷ���
	void SetSymbolStyleMapper(UGSymbolStyleMapper SymbolStyleMapper);
	
	//! brief �������Ͷ���
	void SetPenStyleMaper(UGPenStyleMapper PenStyleMapper);
	
	//! brief ������������
	void SetBrushStyleMapper(UGBrushStyleMapper BrushStyleMapper);

	//! brief �������������
	void SetFontStyleMapper(UGFontStyleMapper FontStyleMapper);

protected:

	//! \brief һ��ͼ�㵼��ʱ,��Ӧ�ļ�¼�� �� �ֶ�����
	struct UGRecordsetInfo
	{
		//! \brief ��¼��ָ��
		UGRecordset* m_pRecordset;
		//! \brief ͼ���ֶ���
		UGString m_strLayerField;
		//! \brief ��ͼ����
		UGString m_strSubName;
		//! \brief �ֶ�������
		UGStrings m_strFieldNames;
		//! \brief ��չ�ֶ�������
		UGStrings m_strExtendFieldNames;
		//! \brief ����������, �Ƿ��Զ��ͷż�¼����
		UGbool m_bAutoRelease;
		//! \brief �Ƿ��Զ������ռ�����
		UGbool m_bBuildSpatialIndex;
		//! \brief �Ƿ���û�м��ζ���ֻ��������Ϣ�����ݼ�
		UGbool m_bHoldNoGeometryDT;		
		//! \brief ���캯��
		UGRecordsetInfo()
		{
			m_pRecordset=NULL;
			m_bAutoRelease = FALSE;
			m_bBuildSpatialIndex = TRUE;
			m_bHoldNoGeometryDT = FALSE;
		}

		//! \brief ��������, �ͷż�¼�����ر����ݼ�
		~UGRecordsetInfo();
	};

	typedef UGDict<UGString, UGRecordsetInfo*> NameToRecordset;	

	typedef UGArray<UGRecordsetInfo> UGRecordsetInfos;

protected:

	//! \brief	dgn��ɫ��ע�⣬��������ڿؼ���û�С��ù����ռ丽������ɫ��
	UGString m_strDgnColorMappingTable; 

	//! \brief	��ת������Ϊ�߻������ʱ��ָ���ľ���
	UGdouble m_dToleranceGrain; 
	
	//! \brief 	���ⲿ�ļ�û�����굥λʱ���趨���ٶ������ĵ�λ��ʲô��(����dgn���ԣ�����ָ��ת�뵥λ)
	UGint m_nSrcDefaultUnits;	
	
	//! \brief 	dgn�Ķ�������dgn���ĸ���λ��main��sub or pos����Ϊsupermap�ĵ�λ��
	UGint m_nDgnUnitsSelected;	

	//! \brief 	���û�ָ��Ҫ�����ͼ������ּ���
	UGList<UGString> m_layers; 
	
	//! \brief 	���ⲿָ�� �ײ��Զ����ϵı�ʾ�߶���Ϣ���ֶε�����
	UGString m_strElevationName; 

	//! \brief	ͼ���ֶ���
	//! \remarks ����ʱ��Ϊ���ɵġ����ͼ����Ϣ���ֶΣ�����
	//! ����ʱ��������ֶε�ֵ�����õ�ǰ��¼������������ͼ��
	UGString m_strLayerName;

	//! \brief 	���ݼ��Ƿ�ѹ��
	UGbool m_bImportAsCompressedDatset; 
	//! \brief 	�Ƿ������������
	UGbool m_bIgnoreNetworkTopology; 
	//! \brief 	�Ƿ�ʾ�����Է��
	UGbool m_bIgnoreStyle;
	//! \brief ʸ�����ݵ�����Ƿ��Զ������ռ�����
	UGbool m_bBuildSpatialIndex;	
	//! \brief �Ƿ���û�м��ζ���ֻ��������Ϣ�����ݼ�
	UGbool m_bHoldNoGeometryDT;	

	//! brief ���Ŷ��ձ�
	UGSymbolStyleMapper m_SymbolStyleMapper;	
	//! brief ���Ͷ���
	UGPenStyleMapper m_PenStyleMapper;	
	//! brief ��������
	UGBrushStyleMapper m_BrushStyleMapper;	
	//! brief ��������
	UGFontStyleMapper m_FontStyleMapper;	

	//! brief ͶӰ ��ǰ����Դ�� �ռ�ο�
	UGPrjCoordSys m_UGCSpatialRef;

	//! brief ͶӰ �����ļ��� �ռ�ο�
	UGPrjCoordSys m_FileSpatialRef;

	//! brief ������
	UGProgress m_Progress;

private:
	//void CopyUserParams(UGFileParseVector* pFileVector);

	//! \brief ����ʸ�����ݼ�, �����ֶ�, ���Ѳ�ѯ��Ľ��ͨ����������
	UGbool CreateDatasetVector(UGFileParseVector* pFileVector, 
						UGDataSource* pDataSource, NameToRecordset& nameToRecordset);

	//! \brief ����CAD���ݼ�, �����ֶ�, ���Ѳ�ѯ��Ľ��ͨ����������
	UGbool CreateDatasetCAD(UGFileParseVector* pFileVector, 
		UGDataSource* pDataSource, UGRecordsetInfo& recordsetInfo);

	//! \brief ����ͼ����,ͼ������ ����Ϣ, ����/�õ�  ���ݼ���ָ��
	//! \return �����������, ����NULL
	UGDatasetVector* GetDatasetVector(UGDataSource* pDataSource, 
									UGFileParseVector* pFileVector,
									const UGString& strLayerName, 
									UGint nLayerType, const UGString& strSubName, 
									NameToRecordset& nameToRecordset);
	void CreateFields(UGDatasetVector* pDataset, UGFileParseVector* pFileVector, 
						UGRecordsetInfo* pRecordsetInfo, UGint nIndexLayer);

	//! \brief Import�����ݼ�ʱ,���һ���򵥶���
	void AddGeometry(UGRecordsetInfo *pRecordsetInfo, UGFileParseVector* pFileVector, UGGeometry *pGeometry, UGString strLayerName);

	//����ϵͳ ת��
	enum UGPJConvertType//�ⲿ�����ļ�����
	{
		Plane2Plane   =0,			//ƽ������֮���ת������Ҫ�����굥λ��ͳһ����
		Geo2Geo		  =1,			//��γ������֮���ת����Ӧ�ÿ��ǵ���ͬDatum�Ĳ��
		Geo2PJ		  =2,			//��γ������-->ͶӰ����֮���ת����Ӧ�ÿ��ǵ���ͬDatum�Ĳ��
		PJ2Geo		  =3,			//ͶӰ������-->��γ����֮���ת����Ӧ�ÿ��ǵ���ͬDatum�Ĳ��
		PJ2PJ		  =4,			//ͶӰ������-->ͶӰ����֮���ת����Ӧ�ÿ��ǵ���ͬDatum�Ĳ��
	};
	
	//�ռ�ο��任Ҫ�õ��ķ���
	//! \brief ���� m_FileSpatialRef �� DataSource �еĿռ�ο��õ� UGPJConvertType
	UGbool GetDefaultPJConvertType(UGPJConvertType& nPJConvertType);

	//! \brief ����ϵת��	
	void ConvertCoordSys(UGGeometry *pGeometry,UGPJConvertType nConvertType = Plane2Plane);

	//! \brief ����������:��ʼ��
	void InitialProgress(UGString strMesg);
};



} //namespace UGC

#endif // !defined(AFX_UGEXCHANGEVECTOR_H__F0CBB300_85F0_4105_87D2_F0F9F5C211B5__INCLUDED_)
