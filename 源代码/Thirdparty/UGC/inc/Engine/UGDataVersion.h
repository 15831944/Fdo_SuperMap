/* 
	\file UGDataVersion.h
	\brief �ļ����ݵļ�Ҫ������
	\author �ļ�����
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGDATAVERSION_H__9BAC4D74_E861_4A1B_A4FB_BB45038FEBDA__INCLUDED_)
#define AFX_UGDATAVERSION_H__9BAC4D74_E861_4A1B_A4FB_BB45038FEBDA__INCLUDED_

#include "Engine/UGDataSource.h"

namespace UGC {

class ENGINE_API UGDataVersion  
{
public:
	UGDataVersion();
	virtual ~UGDataVersion();

public:

	//! \brief ��������Դ�İ汾
	//! \param *pDs [in]��
	//! \param &strVersionName [in]��
	//! \param &strDescription [in]��
	//! \return UGbool
	//! \remarks ��
	//! \attention ��
	UGbool CreateDataVersion(UGDataSource *pDs,UGString &strVersionName,UGString &strDescription);
	
	//! \brief ɾ���汾
	//! \param *pDs [in]��
	//! \param &strVersionName [in]��
	//! \return ��
	//! \remarks �˲���Ҫ���أ�ɾ��������Դ˰汾�Ĳ�����
	//! \attention ��
	UGbool DeleteDataVersion(UGDataSource *pDs,UGString &strVersionName);	

	//! \brief ���õ�ǰ�İ汾
	//! \param *pDs [in]��
	//! \param &strVersionName [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool SetCurrentVersion(UGDataSource *pDs,UGString &strVersionName);		

	//! \brief ���õ�ǰ�İ汾
	//! \param *pDs [in]��
	//! \param nVersionID [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool SetCurrentVersion(UGDataSource *pDs,UGint nVersionID);		

	//! \brief �õ��汾����Ϣ
	//! \param *pDs [in]��
	//! \param &aryDataVersionInfos [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool GetDataVersionInfos(UGDataSource *pDs,
					UGArray<UGDataVersionInfo> &aryDataVersionInfos);	
	
	//! \brief ע�����ݼ�Ϊ֧�ְ汾
	//! \param *pDt [in]��
	//! \return ��
	//! \remarks ���A��D��
	//! \attention ����ע��
	UGbool Register(UGDatasetVector *pDt);

	//! \brief ��ע��
	//! \param *pDt [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool UnRegister(UGDatasetVector *pDt);	

	//! \brief �ύһ���汾�����ݼ�
	//! \param *pDt [in]��
	//! \param strVersion [in]��
	//! \param nPostOption [in]��
	//! \param &nCheckConfilct [out]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool PostToMainVersion(UGDatasetVector *pDt,
					UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	//! \brief �ύһ���汾�����ݼ�
	//! \param *pDt [in]��
	//! \param nVersionID [in]��
	//! \param nPostOption [in]��
	//! \param &nCheckConfilct [out]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool PostToMainVersion(UGDatasetVector *pDt,
					UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);


	//! \brief �ύһ���������ݼ�
	//! \param *pDt [in] �汾���ݼ�
	//! \param nVersionID [in] �汾�� 
	//! \param nDataID [in] �����ݼ��Ķ���ID
	//! \param nPostOption [in] �ύ����Ҫ���õķ�ʽ 
	//! \return 
	//! \remarks 
	//! \attention 
	UGbool PostToMainVersion(UGDatasetVector *pDt,
					UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);

	//! \brief ���һ���汾�ı༭
	//! \param *pdt [in]��
	//! \param nVersion [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	UGbool RollBackVersion(UGDatasetVector *pdt,UGint nVersion);
};

}

#endif // !defined(AFX_UGDATAVERSION_H__9BAC4D74_E861_4A1B_A4FB_BB45038FEBDA__INCLUDED_)
