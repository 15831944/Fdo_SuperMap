// UGSdeDataSource.h: interface for the UGSdeDataSource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSDEDATASOURCE_H__EDBD4488_AA85_42AC_9169_833D32CF62C9__INCLUDED_)
#define AFX_UGSDEDATASOURCE_H__EDBD4488_AA85_42AC_9169_833D32CF62C9__INCLUDED_


#include "Engine/UGDataSource.h"
#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGTime.h"
#include "SdeEngine/include/sdetype.h"

namespace UGC {	

class SDEENGINE_API UGSdeDataSource : public UGDataSource
{
public:
	UGSdeDataSource();
	virtual ~UGSdeDataSource();

public:

	//! ��������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Create();

	//! ������Դ,��ҪԤ�����ú�������Ϣ
	virtual UGbool Open();

	//! �ر�����Դ
	virtual void Close();

	//! ��ȡ������ʱ��
	virtual UGTime GetDateLastUpdated() const;

	//! ��ȡ����ʱ��
	virtual UGTime GetDateCreated() const;

	//! ����������Ϣ
	virtual UGbool SaveInfo();

	//! �޸�����
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	//! ͨ��DatasetVectorInfo�������ݼ�
	virtual UGDatasetVector* CreateDatasetVector(const UGDatasetVectorInfo& vInfo);

	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);
	//! ͨ��DatasetRasterInfo�������ݼ�
	virtual UGDatasetRaster* CreateDatasetRaster(const UGDatasetRasterInfo& rInfo);

	//! ɾ�����ݼ�(ͨ������)
	virtual UGbool DeleteDataset(const UGString& strName);

	//! Ԫ���ݹ�����
	virtual UGMetadata* GetMetaData();

	//! ����Դ�Ƿ����������
	virtual UGbool IsConnected();

	//! �����������ݿ�,��ˢ�����ݼ���
	virtual UGbool Connect();

public:
	UGbool check_error(SE_CONNECTION *conn, SE_STREAM stream, UGuint nResultCode,UGchar *comment);

public:
	SE_CONNECTION m_SDEConnection;
};

extern "C" SDEENGINE_API UGDataSource* CreateDataSource();

}
#endif // !defined(AFX_UGSDEDATASOURCE_H__EDBD4488_AA85_42AC_9169_833D32CF62C9__INCLUDED_)

