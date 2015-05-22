
/*!
    **************************************************************************************
     \file     UGImportParams.h
    **************************************************************************************
     \author   ����
     \brief    ����ת�����������           
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


#if !defined(AFX_UGIMPORTPARAMS_H__7E206152_BB8D_47AC_9C42_1E02DB85017B__INCLUDED_)
#define AFX_UGIMPORTPARAMS_H__7E206152_BB8D_47AC_9C42_1E02DB85017B__INCLUDED_


#include "UGExchangeParams.h"
#include "Base/UGList.h"
#include "Engine/UGDataset.h"

namespace UGC {

	class UGDatasetInfo;


class DATAEXCHANGE_API UGImportParams : public UGExchangeParams  
{
public:
	UGImportParams();
	~UGImportParams();

	//! \brief ���¾�Ϊ ����/��ȡ �����������
	
	void SetDgnColorMappingTableName(const UGString& strDgnColorMappingTableName);
	UGString GetDgnColorMappingTableName() const;

	void SetToleranceGrain(UGdouble dToleranceGrain);
	UGdouble GetToleranceGrain() const;

	void SetSrcDefaultUnits(UGint nSrcDefaultUnits);
	UGint GetSrcDefaultUnits() const;

	void SetDgnUnitsSelected(UGint nDgnUnitsSelected);
	UGint GetDgnUnitsSelected() const;

	void SetLayers(const UGList<UGString>& layers);
	UGList<UGString> GetLayers() const;

	void SetGridDataType(UGint nGridDataType);
	UGint GetGridDataType() const;

	void SetElevationName(const UGString& strElevationName);
	UGString GetElevationName() const;


	//! \brief �������ݱ��뷽ʽ
	void SetDatasetEncType(UGDataCodec::CodecType encType);
	UGDataCodec::CodecType GetDatasetEncType() const;	

	//! \brief �����Ƿ���Ϊ�������ݼ�������ʸ������ʱ���ã�
	void SetIsImportAsCADDataset(UGbool bImportAsCADDataset);
	UGbool IsImportAsCADDataset() const;
	
	//! \brief�Ƿ�������ݣ���SetIsImportASCADDataset(False)ʱ������ 
	void SetIsImportPoint(UGbool bImportPoint);
	UGbool IsImportPoint() const;

	//! \brief�Ƿ��������ݣ���SetIsImportASCADDataset(False)ʱ������ 
	void SetIsImportLine(UGbool bImportLine);
	UGbool IsImportLine() const;

	//! \brief�Ƿ��������ݣ���SetIsImportASCADDataset(False)ʱ������ 
	void SetIsImportRegion(UGbool bImportRegion);
	UGbool IsImportRegion() const;

	//! \brief�Ƿ����ı����ݣ���SetIsImportASCADDataset(False)ʱ������ 
	void SetIsImportText(UGbool bImportText);
	UGbool IsImportText() const;

	void SetCADDatasetName(UGString str);
	UGString GetCADDatasetName() const;

	void SetPointDatasetName(UGString str);
	UGString GetPointDatasetName() const;

	void SetLineDatasetName(UGString str);
	UGString GetLineDatasetName() const;

	void SetRegionDatasetName(UGString str);
	UGString GetRegionDatasetName() const;

	void SetTextDatasetName(UGString stsr);
	UGString GetTextDatasetName() const;

	void SetIsIgnoreCoordSys(UGbool bIgnoreCoordSys);
	UGbool IsIgnoreCoordSys() const;

	void SetIsIgnoreAttribute(UGbool bIgnoreAttribute);
	UGbool IsIgnoreAttribute() const;

	void SetIsIgnoreNetworkTopology(UGbool bIgnoreNetworkTopology);
	UGbool IsIgnoreNetworkTopology() const;

	void SetIsIgnoreStyle(UGbool bIgnoreStyle);
	UGbool IsIgnoreStyle() const;

	void SetIsHoldNoGeometryDataset(UGbool bHoldNoGeometryDT);
	UGbool IsHoldNoGeometryDataset() const;

	void SetIsBuildSpatialIndex(UGbool bBuildSpatialIndex);
	UGbool IsBuildSpatialIndex() const;

	void SetIsBuildPyramid(UGbool bBuildPyramid);
	UGbool IsBuildPyramid() const;

	//! \brief �Ƿ���ΪGrid���ݼ�������դ������ʱ���ã�
	void SetIsImportAsGridDataset(UGbool bImportAsGrid);
	UGbool IsImportAsGridDataset() const;

	//! \brief ����դ�����ݼ���
	void SetRasterDatasetName(UGString strName);
	UGString GetRasterDatasetName() const;


public:
	//! \brief ���һ���ⲿ�Ƿ����� m_bImportAsCADDataset
	UGbool HasSetImportAsCADDataset() const;	

	//! \brief ���һ���ⲿ�Ƿ����� m_bImportAsGridDataset
	UGbool HasSetImportAsGridDataset() const;

protected:

	//! \brief �������ݼ���
	UGString m_strCADDatasetName;

	//! \brief �����ݼ���
	UGString m_strPointDatasetName;

	//! \brief �����ݼ���
	UGString m_strLineDatasetName;

	//! \brief �����ݼ���
	UGString m_strRegionDatasetName;

	//! \brief �ı����ݼ���
	UGString m_strTextDatasetName;

	//! \biref դ�����ݼ���
	UGString m_strRasterDatasetName;

	//! \brief	dgn��ɫ��ע�⣬��������ڿؼ���û�С��ù����ռ丽������ɫ��
	UGString m_strDgnColorMappingTable; 

	//! \brief ���ݼ��ı��뷽ʽ
	UGDataCodec::CodecType m_encType;

protected:

	//! \brief	��ת������Ϊ�߻������ʱ��ָ���ľ���
	UGdouble m_dToleranceGrain; 
	
	//! \brief 	���ⲿ�ļ�û�����굥λʱ���趨���ٶ������ĵ�λ��ʲô��(����dgn���ԣ�����ָ��ת�뵥λ)
	UGint m_nSrcDefaultUnits;
	
	//! \brief 	dgn�Ķ�������dgn���ĸ���λ��main��sub or pos����Ϊsupermap�ĵ�λ��
	UGint m_nDgnUnitsSelected;	
	
	//! \brief 	ת��Ӱ�����ݺ�ÿ��դ����������ͣ������ֽ�����ʾһ��դ�����ݣ�����Ԥ����ĺ�
	UGint m_nGridDataType; 

	//! \brief 	���ⲿָ�� �ײ��Զ����ϵı�ʾ�߶���Ϣ���ֶε�����
	UGString m_strElevationName; 

protected:

	struct bImportParams 
	{
		//! \brief 	�Ƿ��뵽�������ݼ���CAD���ݼ��У�
		UGbool m_bImportAsCADDataset; 

		//! \brief 	�Ƿ��������
		UGbool m_bImportPoint; 

		//! \brief 	�Ƿ���������
		UGbool m_bImportLine; 

		//! \brief 	�Ƿ���������
		UGbool m_bImportRegion; 

		//! \brief 	�Ƿ����ı�����
		UGbool m_bImportText; 
		
		//! \brief 	�Ƿ����Դ�ļ�������ϵͳ��
		UGbool m_bIgnoreCoordSys; 
		
		//! \brief 	�Ƿ����������Ϣ��
		UGbool m_bIgnoreAttribute; 
		
		//! \brief 	�Ƿ������������
		UGbool m_bIgnoreNetworkTopology; 
		
		//! \brief 	�Ƿ�ʾ�����Է��
		UGbool m_bIgnoreStyle;

		//! \brief ʸ�����ݵ�����Ƿ��Զ������ռ�����
		UGbool m_bBuildSpatialIndex;

		//! \brief �Ƿ���û�м��ζ���ֻ��������Ϣ�����ݼ�
		UGbool m_bHoldNoGeometryDT;	

		//! \brief �Ƿ���Ϊgird���ݼ�
		UGbool m_bImportAsGridDataset;

		//! \brief դ�����ݵ�����Ƿ��Զ�����Ӱ�������
		UGbool m_bBuildPyramid;


		bImportParams()
		{
			m_bImportAsCADDataset = FALSE;
			m_bImportPoint = TRUE;
			m_bImportLine = TRUE;
			m_bImportRegion = TRUE;
			m_bImportText = TRUE;
			m_bIgnoreCoordSys = TRUE;
			m_bIgnoreAttribute = FALSE;
			m_bIgnoreNetworkTopology = TRUE;
			m_bIgnoreStyle = FALSE;
			m_bBuildSpatialIndex = TRUE;
			m_bHoldNoGeometryDT = FALSE;	

			m_bImportAsGridDataset = TRUE;
			m_bBuildPyramid = TRUE;
		}
	};

	bImportParams m_bImportParams;
	
	//! \brief �ⲿ�Ƿ�����m_bImportAsCADDataset���Ƿ���Ϊ�������ݼ�����û���������ṩһ��Ĭ�ϵ�
	UGbool m_bHasSetIsImportAsCADDataset;

	//! \brief �ⲿ�Ƿ�����m_bImportAsGridDataset���Ƿ���Ϊ�������ݼ�����û���������ṩһ��Ĭ�ϵ�
	UGbool m_bHasSetIsImportAsGridDataset;




	//{{һ����UGC6.0Ԥ���ӿ�

	//! \brief �Ƿ���� M ֵ
	UGbool m_bIgnoreMValue;

	//! \brief �Ƿ���� Z ֵ
	UGbool m_bIgnoreZValue;
	
	//! \brief 	���û�ָ��Ҫ�����ͼ������ּ��ϣ�CAD DGN ר�ã�
	UGList<UGString> m_layers; 

	//! \brief �Ƿ�ÿ��ͼ���е㡢�ߡ��桢�ı���������Ϊһ�����ݼ�����m_layers����ʹ�ã���CAD DGN ר�ã�
	UGbool m_bDivideLayer;

	//����Ҫ����CAD DGN ר�õģ��ⲿ�������� ��������ɫֵ����ɫ�������������ֶ���
	//}}

};


} //namespace UGC

#endif // !defined(AFX_UGIMPORTPARAMS_H__7E206152_BB8D_47AC_9C42_1E02DB85017B__INCLUDED_)
