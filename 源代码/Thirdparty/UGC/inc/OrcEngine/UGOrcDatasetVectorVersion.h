// UGOrcDatasetVectorVersion.h: interface for the UGOrcDatasetVectorVersion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCDATASETVECTORVERSION_H__FEBA9AFA_9A12_42EB_AE9D_14A9481A5D5C__INCLUDED_)
#define AFX_UGORCDATASETVECTORVERSION_H__FEBA9AFA_9A12_42EB_AE9D_14A9481A5D5C__INCLUDED_


#include "Base/ugdefs.h"	// Added by ClassView
#include "OrcEngine/UGOrcDatasetVector.h"
#include "UGOCIConnection.h"
namespace UGC{

class ORCENGINE_API UGOrcDatasetVectorVersion
{
public:
	UGOrcDatasetVectorVersion();
	UGOrcDatasetVectorVersion(UGOrcDatasetVector *pOrcDatasetVector);
	virtual ~UGOrcDatasetVectorVersion();

public:
	//! ע��ѡ����Ϣ
	virtual UGbool RegisterOption(UGint nOption);

	UGbool UnRegisterOptionDataVersion();

	UGbool PostToMainVersion(UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);	

	UGbool PostToMainVersion(UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	UGbool PostToMainVersion(UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);


	UGbool RollBackVersion(UGint nVersion);


	UGbool U_FillExtInfos(UGint nVersionID);

	//����Դɾ���汾ʱ����
	UGbool U_DeleteVersion(UGint nVersion);

protected:
	//����Ƿ��г�ͻ
	UGbool U_CheckConflict(UGint nVersionID);

	//���س�ͻ������
	UGbool U_ExtractConflicts(UGint nVersionID, UGArray<UGCheckConflict> &CheckConfilcts);

	//�����ͻ
	UGbool U_PostToMainVersionPrev(UGint nVersionID);
	//�����ͻ
	UGbool U_PostToMainVersionUnion(UGint nVersionID);
	//ǿ�Ƹɻ�
	UGbool U_PostToMainVersionLast(UGint nVersionID);

	UGbool U_UnionConflict(UGCheckConflict & Checkconflict);

	UGbool U_CopyDataByVersionAndID(UGint nDataVersionID,UGint nDataID);

	UGbool U_CopyDataByVersion(UGint nVersionID);

	UGbool U_ExtractConflict(UGint nVersionID,UGint nDataID,UGCheckConflict &nCheckConflict);

	//�����Ĵ��������ͼ�������������ύ�汾��ʱ�����
	UGbool U_UpdateIndex(UGint nVersionID);
	
protected:
	UGOrcDatasetVector *m_pOrcDatasetVector;
	
};

}

#endif // !defined(AFX_UGORCDATASETVECTORVERSION_H__FEBA9AFA_9A12_42EB_AE9D_14A9481A5D5C__INCLUDED_)
