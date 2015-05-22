// UGSqlDatasetVectorVersion.h: interface for the UGSqlDatasetVectorVersion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSQLDATASETVECTORVERSION_H__63D4CC6F_6AF4_430A_A2C0_5E1E8618752B__INCLUDED_)
#define AFX_UGSQLDATASETVECTORVERSION_H__63D4CC6F_6AF4_430A_A2C0_5E1E8618752B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "ODBCEngine/UGODBCSpatialIndex.h"
#include "SqlPlusEngine/UGSqlDatasetVector.h"
namespace UGC{

class SQLENGINE_API UGSqlDatasetVectorVersion  
{
public:
	UGSqlDatasetVectorVersion();
	UGSqlDatasetVectorVersion(UGSqlDatasetVector *pSqlDatasetVector);
	virtual ~UGSqlDatasetVectorVersion();

public:

	//! \brief ע��汾
	UGbool RegisterOption(UGint nOption);
	//! \brief ע���汾
	UGbool UnRegisterOption(UGint nOption);

	//! \brief �汾�ύ����
	// param��strVersion��		�汾
	// param��nPostOption		��ͻ�����ʽ
	// param��CheckConfilcts	��¼�����ĳ�ͻ
	UGbool PostToMainVersion(UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);	

	//! \brief �汾�ύ����
	// param��strVersion��		�汾��
	// param��nPostOption		��ͻ�����ʽ
	// param��CheckConfilcts	��¼�����ĳ�ͻ
	UGbool PostToMainVersion(UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	UGbool PostToMainVersion(UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);


	//! \brief �汾�ع�
	// param��strVersion��		�汾��
	UGbool RollBackVersion(UGint nVersion);
	
	//! \brief ������ͼ
	UGbool U_FillExtInfos(UGint nVersionID);
	
	//! \brief ����Դɾ���汾ʱ����
	UGbool U_DeleteVersion(UGint nVersion);


	//! \brief �汾�ύ
	//! \brief ����Ƿ��г�ͻ
	// param��nVersionID���汾�š�[in]
	UGbool U_CheckConflict(UGint nVersionID);

	//! \brief ���س�ͻ������
	// param��nVersionID���汾�š�[in]
	// param��CheckConfilcts����¼��ͻ������[out]
	UGbool U_ExtractConflicts(UGint nVersionID, UGArray<UGCheckConflict> &CheckConfilcts);

	//! \brief �����Ѿ��ύ�İ汾�����ͻ
	// param��nVersionID���汾�š�[in]
	UGbool U_PostToMainVersionPrev(UGint nVersionID);
	//! \brief �ϲ������ͻ
	// param��nVersionID���汾�š�[in]
	UGbool U_PostToMainVersionUnion(UGint nVersionID);
	//! \brief ���յ�ǰ�ύ�İ汾�����ͻ
	// param��nVersionID���汾�š�[in]
	UGbool U_PostToMainVersionLast(UGint nVersionID);

	//! \brief �ϲ������ͻ
	// param��CheckConfilcts����¼��ͻ������[in]
	UGbool U_UnionConflict(UGCheckConflict & Checkconflict);

	//! \brief ��A������׷�ӵ�����ͬʱ��������
	// param��nVersionID���汾�š�[in]
	UGbool U_CopyDataByVersion(UGint nVersionID);

	//! \brief �汾���ݼ��ύʱ��Delete,SetGeometry�༭���������Ĵ���
	// param��nVersionID���汾�š�[in]
	//
	/*/
		Delete��		ֱ�Ӵ���������ɾ��
		SetGeometry:	�ȴ���������ɾ����Ȼ��ͨ��A������ӵ�������
	/*/
	UGbool U_PostDisposeIndex(UGint nVersionID);

protected:
	UGSqlDatasetVector *m_pSqlDatasetVector;

};

}

#endif // !defined(AFX_UGSQLDATASETVECTORVERSION_H__63D4CC6F_6AF4_430A_A2C0_5E1E8618752B__INCLUDED_)
