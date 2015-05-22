// UGODBCDatasource.h: interface for the UGODBCDatasource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCDATASOURCE_H__BCB6E431_4D66_4B77_B645_8E75B07625EA__INCLUDED_)
#define AFX_UGODBCDATASOURCE_H__BCB6E431_4D66_4B77_B645_8E75B07625EA__INCLUDED_

#include "Engine/UGDataSource.h"
#include "UGODBCConnection.h"

namespace UGC
{

class UGEXPORT UGODBCDatasource : public UGDataSource
{
public:
	UGODBCDatasource();
	virtual ~UGODBCDatasource();

public:

	//! \brief  Ԫ���ݲ���
	virtual UGMetadata* GetMetaData();
	
	//! \brief  �ر�����Դ
	virtual void Close();

	//! \brief  ����������Ϣ
	virtual UGbool SaveInfo();

	//! \brief  ����Դ�Ƿ����������
	virtual UGbool IsConnected();
		
	//! \brief  �����������ݿ�,��ˢ�����ݼ���
	virtual UGbool Connect();

	virtual UGEngineProc * GetEngineProc();

	//����ݽ��ͳ���
	virtual UGbool BeginTrans();
	virtual void Commit();
	virtual void Rollback();

public:
	//! \brief �õ����л���ֵ�����MODEΪ1 ��ʾNEXT������CUR
	virtual UGuint GetSeqValue(UGString &strSeq,UGint nMode = 1);
	
	//! \brief ��ȡϵͳ���nextval,Ϊ����SFC52���ּ���
	virtual UGuint GetSysTableSelValue(UGString strTableName, UGString strFieldName);
	
	//! \brief  �õ�����ϵͳ�������л��ֶ��е����ֵ
	virtual UGint GetMaxTableID();

	//! \brief  ִ��SQL��䣬��Ҫ���������ݿ⼶ִ�е����ݲ���
	virtual UGbool Execute(const UGString& strSQL);

	//! \brief ��ȡ���ݼ��ļ�¼��Ŀ
	//! \param strTableName ���ݼ���[in]
	//! \param strFilter	����[in]
	UGint GetRecordCount(UGString strTableName,UGString strFilter = "");
protected:
	//! \brief ��������Դ��Ϣ
	UGbool SetDatasourceInfo();
	//! \brief����ȡ����Դ��Ϣ
	UGbool ReadDatasourceInfo();
	
public:
	UGODBCConnection *m_pConnection;
	UGbool m_bConnected;

public:
	//! \brief �����ռ������ؽӿ�
	//! \brief�����湤���ռ���Ϣ
	//! \param��conn������Դ������Ϣ[in]
	//! \param��strWksName ���ñ��������[in]
	//! \param��nVersion   ���õİ汾��[in]
	//! \param	pbyte	�� �����ռ��ļ�[in]
	//! \param  nbyteSize  �ļ���С[in]
	virtual UGbool SaveWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *pbyte,UGint nbyteSize);
	//! \brief���������ƣ����ع����ռ�
	//! \param��conn������Դ������Ϣ[in]
	//! \param��strWksName ����[in]
	//! \param��nVersion   ���õİ汾��[out]
	//! \param	pbyte	�� �����ռ��ļ�[out]
	//! \param  nbyteSize  �ļ���С[out]
	virtual UGbool LoadWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *&pbyte,UGint &nbyteSize);
	//! \brief���������ƣ���ȡ�����ռ������Ϣ
	//! \param��conn������Դ������Ϣ[in]
	//! \param  wksInfos  �洢�����ռ���Ϣ[out]
	virtual UGbool GetWorkspaceInfo(UGDsConnection conn, UGArray<UGWorkspaceInfo> &wksInfos);
	//! \brief���������ƣ�ɾ�������ռ���Ϣ
	//! \param��conn������Դ������Ϣ[in]
	//! \param��strWksName ����[in]
	virtual UGbool DeleteWorkspaceInfo(UGDsConnection conn, UGString strWksName);
	
};

}


#endif // !defined(AFX_UGODBCDATASOURCE_H__BCB6E431_4D66_4B77_B645_8E75B07625EA__INCLUDED_)
