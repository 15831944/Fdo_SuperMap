
/*!
    **************************************************************************************
     \file     UGExchangeFile.h
    **************************************************************************************
     \author   ����
     \brief    ����ת������-----����ת������                     
     \remarks   ����ת������-----����ת������                                        <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGEXCHANGEFILE_H__EE8820FE_B390_46E2_A796_E0F03AABD822__INCLUDED_)
#define AFX_UGEXCHANGEFILE_H__EE8820FE_B390_46E2_A796_E0F03AABD822__INCLUDED_


#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Base/UGDict.h" 
#include "Engine/UGDataset.h"
#include "FileParser/UGFileParseVector.h"

namespace UGC {

	class UGDataSource;


class UGExchangeFile
{
public:
	UGExchangeFile();
	virtual ~UGExchangeFile();

	//! \brief	���õ���һ�����ݼ�����Ϣ
	void AddOneDatasetInfo(UGString strName, UGDataset::DatasetType nType, UGint nEncType);

	//! \brief	�����ļ���ʽ����
	void SetFileType(UGint nFileType);

	//! \brief	�����ļ���·��
	void SetFilePathName(const UGString& strFilePathName);

	//! \brief �����������ļ���
	void SetShowProgress(UGbool bShowProgress);

	//! \brief ���ö��ձ�
	void SetMappingFile(const UGString& strMappingFile);

	//! \brief ������ʱ·��
	void SetTempPath(const UGString& strTempPath);

	void SetIsIgnoreCoordSys(UGbool bIgnoreCoordSys);

	void SetIsIgnoreAttribute(UGbool bIgnoreAttribute);

	//! \brief	���õ������ݼ�������
	void SetExportDatasetName(const UGString& strDatasetName);

	//! \brief	�������굥λ			
	void SetDesUnits(UGint nDesUnits);

	//! \brief	���õ����İ汾
	void SetImportVersion(UGint nVersion);

	//! \brief	����һ�������Ĳ���������������ĸ�ʽ���û��Զ��������
	void SetOneParam(const UGString& strFileType, const UGString& strName, const UGVariant& varValue);

public:
	//! \brief	����Ϊʸ�����ݼ�
	virtual UGbool Import(UGDataSource* pDataSource, const UGString& strFilePathName);

	//! \brief	����Ϊ�������ݼ�
	virtual UGbool ImportCAD(UGDataSource* pDataSource, const UGString& strFilePathName);
	
	////! \brief ���ݼ�������Ԥ��������
	virtual UGbool Export(UGDataSource* pDataSource, const UGString& strFilePathName);


protected:
	//����͵����Ĺ�������

	//! \brief ���ݸ�ʽ����
	UGint m_nFileType;
	
	//! \brief �������ļ���
	UGString m_strFilePathName;
	
	//! \brief �Ƿ���ʾ������
	UGbool m_bShowProgress;

	//! \brief �����ļ�ȫ·��
	UGString m_strMappingFile;
	
	//! \brief ��ʱ�ļ�Ŀ¼
	UGString m_strTempPath;

	//! \brief 	�Ƿ����Դ�ļ�������ϵͳ��
	UGbool m_bIgnoreCoordSys; 
	//! \brief 	�Ƿ����������Ϣ��Ӱ���� Arcinfo ������Grid ��
	UGbool m_bIgnoreAttribute; 

protected:
	//��ʸ����դ�񻮷�

	//�����ר�ò���
	//! \brief ͼ���ֶ���
	struct UGImportDatasetInfo
	{
		//! \brief	���ݼ�����
		UGString m_strName; 

		//! \brief	���ݱ�������
		UGint m_nCodecType;	

		UGImportDatasetInfo()
		{
			m_nCodecType = UGDataCodec::encNONE;
		}
	};
	
	typedef UGDict<UGDataset::DatasetType, UGImportDatasetInfo> UGImportDatasetInfos;
	//! \brief	���ݼ�����
	UGImportDatasetInfos m_importDatasetInfos;

protected:
	//��ʸ����դ�񻮷�

	//������ר�ò���
	//! \brief 	�������ݼ������� 
	UGString m_strDatasetName;

	//! \brief 	ָ�����ɵ��ⲿ�ļ��ĵ�λ
	UGint m_nDesUnits; 

	//! \brief	��һ�����ͱ��������õ����ļ���ʽ��ʲô���ͣ���ֵӦ����һЩö����
	UGint m_nVersion;
};







} //namespace UGC

#endif // !defined(AFX_UGEXCHANGEFILE_H__EE8820FE_B390_46E2_A796_E0F03AABD822__INCLUDED_)
