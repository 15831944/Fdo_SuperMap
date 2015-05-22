
/*!
    **************************************************************************************
     \file     UGDataExchange.h
    **************************************************************************************
     \author   ����
     \brief    �û���-----����ת����
     \remarks   ����ת���࣬�û�ֻҪ���ô���ĽӿھͿ��Խ�������ת��                                                             <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGDATAEXCHANGE_H__B21A086A_BC85_4DE2_BFB1_FDD674B68AA8__INCLUDED_)
#define AFX_UGDATAEXCHANGE_H__B21A086A_BC85_4DE2_BFB1_FDD674B68AA8__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/ugexports.h"


namespace UGC {

	class UGDataSource;
	class UGExchangeParams;
	class UGImportParams;
	class UGExportParams;
	class UGExchangeFile;
	class UGExchangeVector;
	class UGExchangeRaster;
	
class DATAEXCHANGE_API UGDataExchange  
{
public:
	UGDataExchange();
	virtual ~UGDataExchange();


	//! \brief 		����Ҫת��������Դ
	//! \return 	UGbool			����ɹ�����true, ���򷵻�false
	//! \param 		pDataSource		����Դָ��
	//! \remarks 	�������ȵ���AttachDataSource�����ݽ���CSmDataSource��ָ��ĵ�ַ��	
	UGbool AttachDataSource(UGDataSource* pDataSource);
	

	//! \brief 		��������
	//! \return 	UGbool			�ɹ�����true,���򷵻�false
	//! \param 		importParams	���������
	//! \remarks 	�ڵ���֮ǰ�����importParams���ú�	
	UGbool Import(const UGImportParams& importParams);


	//! \brief 		��������
	//! \return 	UGbool			�ɹ�����true,���򷵻�false
	//! \param 		exportParams	����������
	//! \remarks 	�ڵ���֮ǰ�����importParams���ú�		
	UGbool Export(const UGExportParams& exportParams);

private:
	//! \brief ����ʸ����ʽ�ļ�
	UGbool ImportVector(const UGImportParams& importParams);

	//! \brief ����դ���ʽ�ļ�
	UGbool ImportRaster(const UGImportParams& importParams);

	//! \brief ����ʸ���������ݼ�
	UGbool ExportVector(const UGExportParams& exportParams);

	//! \brief ����դ���ʽ���ݼ�
	UGbool ExportRaster(const UGExportParams& exportParams);

private:
	//! \brief ���õ���ʸ�����ݼ������ֵ���Ϣ
	void SetDatasetVectorInfo(UGExchangeVector* pExchangeVector, const UGImportParams& importParams);

	//! \brief ���õ���դ�����ݼ������ֵ���Ϣ
	void SetDatasetRasterInfo(UGExchangeRaster* pExchangeRaster, const UGImportParams& importParams);

	//! \brief �����û��Զ������
	void CopyUserParams(UGExchangeFile* pExchangeFile, const UGExchangeParams& exchangeParams);

	//! \brief ����importParams�еĲ������ж��Ƿ���Ϊ�������ݼ�������û�û���������������ϵͳ�����ݵ����ļ������Ƽ�һ��ֵ
	UGbool IsimportAsCADDataset(const UGImportParams& importParams);
		//! brief ���ݵ�����ļ�����ȷ���Ƿ���Ϊ�������ݼ������û�δ����m_bImportAsCADDatasetʱʹ��
		UGbool GetRecommendIsAsCAD(const UGImportParams& importParams);

	//! \brief ����importParams�еĲ������ж��Ƿ���ΪGrid���ݼ�������û�û���������������ϵͳ�����ݵ����ļ������Ƽ�һ��ֵ
	UGbool IsimportAsGridDataset(const UGImportParams& importParams);
		//! brief ���ݵ�����ļ�����ȷ���Ƿ���Ϊ�������ݼ������û�δ����m_bImportAsGridDatasetʱʹ��
		UGbool GetRecommendIsAsGrid(const UGImportParams& importParams);
private:
	//! \brief ����Դ
	UGDataSource* m_pDataSource;  
};


} //namespace


#endif // !defined(AFX_UGDATAEXCHANGE_H__B21A086A_BC85_4DE2_BFB1_FDD674B68AA8__INCLUDED_)
