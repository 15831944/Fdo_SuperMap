
/*!
    **************************************************************************************
     \file     UGExchangeRaster.h
    **************************************************************************************
     \author   ����
     \brief    ����ת������-----����ת��դ����                       
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

#if !defined(AFX_UGEXCHANGERASTER_H__0260A745_42E5_4180_A01B_A14D1BE55D10__INCLUDED_)
#define AFX_UGEXCHANGERASTER_H__0260A745_42E5_4180_A01B_A14D1BE55D10__INCLUDED_



#include "UGExchangeFile.h"
#include "Base//UGDataExchangeConstant.h"
#include "Engine/UGDataset.h"



namespace UGC {

	class UGDatasetRaster;
	class UGDataSource;
	class UGFileParseRaster;

class UGExchangeRaster : public UGExchangeFile  
{
public:
	UGExchangeRaster();
	virtual ~UGExchangeRaster();

public:
	

	//! \brief 		��������
	//! \return 	UGbool			�ɹ�����true,���򷵻�false
	//! \param 		pDataSource		����Դָ��
	//! \param 		strFilePathName �������ݵ����֣�ȫ·����
	//! \remarks 	�ڵ���֮ǰӦ�ý������ã�����Set***
	virtual UGbool Import(UGDataSource* pDataSource, const UGString& strFilePathName);

	//! \brief 		��������
	//! \return 	UGbool			�ɹ�����true,���򷵻�false
	//! \param 		pDataSource		����Դָ��
	//! \param 		strFilePathName �������ݵ����֣�ȫ·����
	//! \remarks 	�ڵ���֮ǰӦ�ý������ã�����Set***
	virtual UGbool Export(UGDataSource* pDataSource, const UGString& strFilePathName);
public:
	
	//! \brief ���õ���դ�������
	void SetImageName(const UGString& strDatasetImage);

	//! \brief ���õ���դ�����ݵ�����
	void SetGridDataType(UGint nGridDataType);

	//! \brief ���õ���򵼳�Ӱ������ʱ��������Ӱ������ο��ļ�������
	void SetImageGeoRefFileName(const UGString& strImageGeoRefFileName);

	//! \brief ���õ���򵼳�Ӱ������ʱ��������Ӱ������ο��ļ�������
	void SetImageGeoRefFileType(UGint nImageGeoRefFileType);
	

	void SetIsBuildPyramid(UGbool bBuildPyramid);
protected:
	
	//! \brief 	����image���ݼ�ʱ��ָ�����ɵ�Ӱ��ο��ļ�������
	UGString m_strImageGeoRefFileName; 

	//! \brief	����image���ݼ�ʱ��ָ�����ɵ�Ӱ��ο��ļ�������
	UGint m_nImageGeoRefFileType;

	//! \brief	ת��image�ļ�ʱ�����ɵ�image���͵����ݼ�������
	UGString m_strDatasetImage;

	//! \brief 	ת��Ӱ�����ݺ�ÿ��դ����������ͣ������ֽ�����ʾһ��դ�����ݣ�����Ԥ����ĺ�
	UGint m_nGridDataType; 

	//! \brief 	��ŵ������ݼ�������
	UGString m_strDatasetName;

	//! \brief դ�����ݵ�����Ƿ��Զ�����Ӱ�������
	UGbool m_bBuildPyramid;

	//UGDatasets m_datasets;
private:

	//! \brief 	�������ݼ�
	UGDatasetRaster* CreateDataset(UGDataSource* pDatasource, UGFileParseRaster* pFileRaster, UGint nIndex);
	//! \brief 	��ȡɨ��������
	UGbool ReadScanlineData(UGDatasetRaster* pDatasetRaster, UGFileParseRaster* pFileRaster, UGint nBandIndex = 0);
	//! \brief 	��ȡ��״����
	UGbool ReadBlockData(UGDatasetRaster* pDatasetRaster, UGFileParseRaster* pFileRaster, UGint nBandIndex = 0);

	//! \brief 	��ȡӰ������ο��ļ�
	UGbool ImportGeoRefFile(UGDatasetRaster* pDatasetRaster); 
	//! \brief 	����Ӱ������ο��ļ�
	UGbool ExportGeoRefFile(UGDatasetRaster* pDatasetRaster); 
	//! \brief 	�õ�Ӱ��Ĳ���

	
};


} //namespace UGC


#endif // !defined(AFX_UGEXCHANGERASTER_H__0260A745_42E5_4180_A01B_A14D1BE55D10__INCLUDED_)
