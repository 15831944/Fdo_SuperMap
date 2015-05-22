// SdbRecordsetSequence.h: interface for the UGSdbPlusRecordsetSequence class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDBRECORDSETSEQUENCE_H__9EB3CDB9_C0D4_4F9B_8565_421CD9672C33__INCLUDED_)
#define AFX_SDBRECORDSETSEQUENCE_H__9EB3CDB9_C0D4_4F9B_8565_421CD9672C33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/UGDict.h"
#include "UGSdbPlusRecordset.h"

namespace UGC
{

//edit sequence dataset is not the same with other.
class UGSdbPlusRecordsetSequence  : public UGSdbPlusRecordset
{
public:
	UGSdbPlusRecordsetSequence();
	UGSdbPlusRecordsetSequence(UGSdbPlusDatasetVector *pDataset);
	virtual ~UGSdbPlusRecordsetSequence();

public:
	virtual UGint AddNew(UGGeometry *pGeometry,UGbool bReturnID=FALSE);	//�����¼�¼,�ɹ������ط�0ֵ������bReturnID=true,���ض���ID�ţ�ʧ�ܣ�����-1�����ʧ�ܣ����ܵ���Update��CancelUpdate.
	virtual UGbool Edit();	//SetXXXǰ��Ҫ����Edit״̬
	virtual UGint Update();	//Addnew��SetXXX����,ע��ռ�����updateǰ����ɾ��
	virtual UGbool CancelUpdate();//ȡ��Update
	virtual UGbool Delete();	//��¼ɾ��
	virtual UGbool DeleteAll();		//ɾ�����еļ�¼
	virtual void FlushCurrentRecord();	//��¼ˢ��
	virtual UGbool Refresh();			//ˢ�¼�¼��
	virtual UGbool SetGeometry(UGGeometry &geometry);	//set geometry
protected:
	UGDict<UGint,UGVariant> m_FieldValues; //�༭��¼�ĸ�������ֵ��������ϵͳ�ֶ�
};

}
#endif // !defined(AFX_SDBRECORDSETSEQUENCE_H__9EB3CDB9_C0D4_4F9B_8565_421CD9672C33__INCLUDED_)
