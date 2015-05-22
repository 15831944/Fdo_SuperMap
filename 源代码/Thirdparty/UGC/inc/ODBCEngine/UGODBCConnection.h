// UGODBCConnection.h: interface for the UGODBCConnection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCCONNECTION_H__173F3F2B_C652_4D91_B169_0BD07F4AA6C8__INCLUDED_)
#define AFX_UGODBCCONNECTION_H__173F3F2B_C652_4D91_B169_0BD07F4AA6C8__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"
#include "Base/UGThread.h"
#include "Base/UGVariant.h"

#ifndef WIN32
	#include "sql.h"
	#include "sqlext.h"
	#include "sqltypes.h"
#else

	#ifndef _AFX_NO_DB_SUPPORT
	#include <afxdb.h>
	#endif

	#include <sql.h>
	#include <sqlext.h>
	#include <sqltypes.h>
#endif

// added by zengzm 2007-4-29 SQLLEN��VC6��û�ж���,ֻ�����Լ�����һ��,����΢��ļ�����Ҳ������
#if defined(_WIN32) && (_MSC_VER == 1200) //Defined as 1200 for Microsoft Visual C++ 6.0.
    typedef SQLINTEGER SQLLEN;
	typedef SQLUINTEGER SQLULEN;
#endif

namespace UGC {

#define SQL_SUCCEEDED(rc) (((rc)&(~1))==0)

//!  \brief �������ݿ����Ϣ
//!  �����û����û�ID���û�����
//!  \remarks
struct DSNINFO 
{
	UGuchar szDSN[SQL_MAX_DSN_LENGTH+1];
	UGuchar szUID[SQL_MAX_DSN_LENGTH-1];
	UGuchar szPWD[SQL_MAX_DSN_LENGTH-1];
};

//!  \brief	�������ݿ����Ϣ
//!  �������ݿ��������������ݿ⣬�û�ID���û�����
//!  \remarks 
struct DRIVERINFO
{
	UGuchar szDriver[SQL_MAX_DSN_LENGTH-1];
	UGuchar szServer[SQL_MAX_DSN_LENGTH-1];
	UGuchar szDatabase[SQL_MAX_DSN_LENGTH-1];
	UGuchar szUID[SQL_MAX_DSN_LENGTH-1];
	UGuchar szPWD[SQL_MAX_DSN_LENGTH-1];
};

//!  \brief	�ֶ���Ϣ
//!  
//!  \remarks 
struct FIELDINFO
{
	UGint		Scale;
	UGint		Nullable;
	UGuint		Precisioin;
	UGuint		Length;
	UGuchar		FieldName[SQL_MAX_DSN_LENGTH-1];
	UGuchar		TypeName[SQL_MAX_DSN_LENGTH-1];
};
typedef FIELDINFO FieldInfo;
typedef UGArray<FieldInfo> FieldInfos;

class UGEXPORT UGODBCBind
{
public:
	UGODBCBind();
	//! �����
	UGODBCBind(UGshort nPosP,UGint nTypeP,UGint nSizeP,UGString &strNameP,void *pDataP,UGint *pIndP);
	~UGODBCBind();

	void operator = (const UGODBCBind &bind)
	{
		nPos	= bind.nPos;
		nType	= bind.nType;
		nSize	= bind.nSize;
		strName	= bind.strName;
		pData	= bind.pData;
		pindicator	= bind.pindicator;
	}
public:
	UGshort			nPos;
	UGint			nType;
	UGint			nSize;
	UGString		strName;
	void			*pData;
	UGint			*pindicator;
};

typedef UGArray<UGODBCBind> UGODBCBinds;


//----------------------------------------------
//	���ƣ�	ODBCDataTypeEnum
//	���ܣ�	��������ö�ٳ���
//	������	��
//	���أ�	��
//  ˵��:	��DAO������������ͳ���һһ��Ӧ
//----------------------------------------------
typedef enum ODBCDataTypeEnum {
		odbcBoolean = 1,
		odbcByte = 2,
		odbcInteger = 3,
		odbcLong = 4,
		odbcCurrency = 5,
		odbcSingle = 6,
		odbcDouble = 7,
		odbcDate = 8,
		odbcBinary = 9,
		odbcText = 10,
		odbcLongBinary = 11,
		odbcMemo = 12,
		odbcGUID = 15,
		odbcBigInt = 16,
		odbcVarBinary = 17,
		odbcChar = 18,
		odbcNumeric = 19,
		odbcDecimal = 20,
		odbcFloat = 21,
		odbcTime = 22,
		odbcTimeStamp = 23,
		odbcNVarChar = 127	//yanmb
} ODBCDataTypeEnum;


class UGEXPORT UGODBCConnection  
{
	friend class UGODBCCursor;
public:
	UGODBCConnection();
	virtual ~UGODBCConnection();

	//! \brief�����ӵ����ݿ�
	//!  \details 
	//!  \param strDriver ���������͡�[in]
	//!  \param strServer ��������	��[in]
	//!  \param strServer��	���ݿ�	  [in]
	//!  \param strUID		�û�ID    [in]
	//!  \param strPWD��	�û�����  [in]
	//!  \return ���ӳɹ�����True,���򷵻�FALSE
	UGbool DriverConnect(const UGString &strDriver,
					   const UGString  &strServer,
					   const UGString &strDatabase,
					   const UGString &strUID,
					   const UGString &strPWD);
	//! \brief�����ӵ����ݿ�
	//!  \details 
	//!  \param strDriver ���������͡�[in]
	//!  \param strServer ��������	��[in]
	//!  \param strServer��	���ݿ�	  [in]
	//!  \param strUID		�û�ID    [in]
	//!  \param strPWD	��	�û�����  [in]
	//!  \return ���ӳɹ�����True,���򷵻�FALSE
	UGbool DriverConnect(const UGchar * szDriver, 
					   const UGchar * szServer, 
					   const UGchar * szDatabase, 
					   const UGchar * szUID, 
					   const UGchar * szPWD);
	//! \brief�����ӵ����ݿ�
	//!  \details 
	//!  \param szDSN ��	������	��[in]
	//!  \param szUID		�û�ID    [in]
	//!  \param szPWD	��	�û�����  [in]
	//!  \return ���ӳɹ�����True,���򷵻�FALSE
	UGbool Connect(const UGchar * szDSN,const UGchar * szUID,const UGchar * szPWD);
	//! \brief�����ӵ����ݿ�
	//!  \details 
	//!  \param szDSN ��	������	��[in]
	//!  \param szUID		�û�ID    [in]
	//!  \param szPWD��		�û�����  [in]
	//!  \return ���ӳɹ�����True,���򷵻�FALSE
	UGbool Connect(const UGString &strDSN, const UGString &strUID, const UGString &strPWD);
	UGbool Connect();
	
	//! \brief���Ͽ�����
	void DisConnect();

	//! \brief���ж��Ƿ��Ѿ����ӵ����ݿ�
	//! \return �����ӷ���True,���򷵻�FALSE
	UGbool IsConnected(){return m_bConnected;};
	
	//! \brief  ִ��
	UGuint ExecStatCount(const UGchar* pcSQL,const UGchar* pcFile);

	//! \brief  ִ��
	UGuint ExecStatCount(const UGchar* pcSQL, UGODBCBinds& binds, const UGchar* pcFile);
	//! \brief  ִ��
	UGbool ExecUpdate(const UGchar* pcSQL);

	//! \brief  �����Ƿ�֧��ODBC����
	UGbool IsFunctionSupported(UGushort nFunctionID);

	//! \brief  ��ȡ������
	UGshort GetServerName(UGchar * szServer);

	//! \brief  ��ȡ���ݿ���
	//! \param szDatabase ��ȡ�����ݿ�����[out]
	UGshort GetDatabaseName(UGchar * szDatabase);

	//! \brief  ��ȡ�û���
	//! \param szUser ��ȡ���û�����[out]
	UGshort GetUserName(UGchar * szUser);

	//! \brief  �ж��Ƿ�ֻ��
	UGbool GetReadOnly();

	//! \brief  ����ֻ��
	void SetReadOnly(UGbool bReadOnly);

	//! \brief  ��¼��ʱ
	UGint GetLoginTimeOut();
	void SetLoginTimeOut(UGint nTimeOut);

	//! \brief  �ع�
	UGbool TransRollBack();
	//! \brief  �ύ
	UGbool TransCommit();

	//! \brief  ʹ�����ӳ�
	void SetUsingConnpool(UGbool bUsingConnpool);

	//! \brief  �ж��Ƿ�ʹ�������ӳ�
	UGbool IsUsingConnpool(){return m_bConnPool;};

private:
	UGbool Initialize();
	void dumpError( UGint type, SQLHANDLE hnd );

	//����ϵͳ����
public:
	SQLHENV m_hEnv;
	UGMutex m_mutex;
	SQLHDBC m_hDbc;
protected:
	UGbool m_bInitialed;
	UGbool m_bConnected;
	UGbool m_bDriverConnect;
	DSNINFO m_dsnInfo;
	DRIVERINFO m_drvInfo;
	SQLCHAR m_szConnStr[255]; 
	UGbool m_bConnPool;
};


struct ODBCERRORINFO 
{
	SDWORD  dwNativeError;
	UGuchar	szSqlState[SQL_MAX_MESSAGE_LENGTH];
	UGuchar	szErrorMsg[SQL_MAX_MESSAGE_LENGTH];
};
typedef ODBCERRORINFO odbc_error;
typedef UGArray<odbc_error> aryOdbcErrors;

//��ͨ���⴦��
class UGEXPORT UGODBCException
{
public:
	UGODBCException(){};
	~UGODBCException(){};
public:
	aryOdbcErrors m_aryErrors;
};

class UGEXPORT UGODBCCursor  
{
public:
	UGODBCConnection * m_pConnection;
	
	SQLHSTMT m_hStmt;
private:
	SQLUSMALLINT m_nOnceFetchCount;
	SQLUINTEGER * m_pnRowsFetched;
	UGbool m_bRowsetInited;

	UGint m_nUseConnectIndex;

public:
	//! \brief��ִ��SQL���
	SQLRETURN Execute();
	//! \brief��ִ��SQL���
	//! \param��nLineNumber��ִ�г����������Ϣ
	//! \param��szFileName�� ִ�г����������Ϣ
	SQLRETURN Execute(const UGuint nLineNumber,const UGchar * szFileName);
	//! \brief��ִ��SQL���
	//! \param��nLineNumber��ִ�г����������Ϣ
	//! \param��szFileName�� ִ�г����������Ϣ
	SQLRETURN Execute(const UGuint nLineNumber,const UGchar * szFunctionName,const UGchar * szFileName);
	
	//! \brief��ˢ�°󶨵���Ŀ
	void ClearRowset();
	//! \brief�����ð󶨵���Ŀ
	//! \param��nOnceFetchCount��ָ������Ŀ
	//! \param��pnRowsFetched��  �����ݿ���ȷ������Ŀ(�����ݿ���������С��ָ������Ŀ���򰴴���Ŀ��)
	UGbool InitRowset(SQLUSMALLINT nOnceFetchCount,UGint * pnRowsFetched, SQLUSMALLINT * pRowStatusArray);
	//! \brief�����������Ϣ
	void CheckError(const UGchar * strFileName, const UGchar * strFuncName, UGuint nLineNumber);
	
	//! \brief��ִ��SQL���
	//! \param��strSQL��SQL���
	SQLRETURN DirectExecute(const UGString &strSQL);
	//! \brief��ִ��SQL���
	//! \param��szSQL��SQL���
	SQLRETURN DirectExecute(const UGchar * szSQL);

	//! \brief������
	UGint BindByPos(SQLUSMALLINT nParNumber,void *value,UGint nSize,void *indicator,UGint nDataType);
	UGint BindByPos(UGODBCBind &bind);
	UGint Bind(UGODBCBinds &aryBinds);

	//! \brief�����
	UGint DefineByPos(SQLUSMALLINT pos,void *value,UGint nSize,void *indicator,UGint nDataType);
	UGint DefineByPos(UGODBCBind &define);
	UGint Define(UGODBCBinds &aryDefines);
	
	//! \brief����������
	void SetConnection(UGODBCConnection * conn);

	UGbool Open(UGint nCursorType = SQL_CURSOR_FORWARD_ONLY);
	//! \brief���ͷž��
	UGbool FreeStmt();

	//! \brief�����SQL���
	UGint Prepare(const UGString &strSQL);
	UGint Prepare(const UGchar * szSQL);
	UGint PrepareColumns(UGString strTableName);

	//! \brief����ȡ����
	SQLRETURN Fetch();
	SQLRETURN FetchScroll(UGshort FetchOrientation, UGint nFetchOffset);
	UGbool Close();

	//! \brief����ȡ�ֶ���Ϣ
	UGbool GetFieldInfo(SQLUSMALLINT nField ,
						UGString &strFieldName,
						SQLSMALLINT &nDataType,
						SQLUINTEGER &nColSize,
						SQLSMALLINT &nPrecision,
						SQLSMALLINT &nScale,
						SQLSMALLINT &nNullable);


	void SetOption(SQLUSMALLINT nConcurrency,SQLINTEGER nKey,SQLUSMALLINT nRowset);

	//! \brief��������
	SQLRETURN BulkOpration(SQLINTEGER nOnceCount, UGshort OprationType);
	SQLRETURN PutData(void *pData, UGint nBinaryLenght);
	SQLRETURN ParamData();

	UGODBCCursor();
	UGODBCCursor(UGODBCConnection * pConnection);
	virtual ~UGODBCCursor();
};

typedef enum SQLBulkOperationEnum{
		SQLInit = 1,
		SQLADD  = 2,
		SQLUpdate = 3
} SQLBulkOperationEnum;

class UGEXPORT UGColumnBind
{
public:
	//! \brief �����ֶ�
	UGColumnBind(UGshort Type, UGint nOnceFetch);
	//! \brief ������,char, text, memo , binary as so on;
	UGColumnBind(UGshort Type, UGint nOnceFetch, UGint nFieldLength);

	//! \brief��Ϊ�ֶθ�ֵ
	//! \param ItemIndex �ֶ�����[in]
	//! \param var		 �ֶ�ֵ��[in]
	UGbool SetFieldValue(UGint ItemIndex, UGVariant& var);
	//! \brief��������ֵ
	//! \param ItemIndex �ֶ�����[in]
	//! \param pData	 �ֶ�ֵ��[in]
	//! \param nLength	 �ֶ�ֵ���ȡ�[in]
	UGint SetBinaryValue(UGint ItemIndex, void* pData, UGuint nLength);
	UGbool GetBinaryValue(UGint ItemIndex, UGbyte* &pData, UGuint &nLength);

	//! \brief����ȡ�ֶδ�С
	UGint GetFieldSize();
	//! \brief����ȡ�ֶ�����
	UGshort GetFieldType();

	//! \brief���󶨵�ֵ
	UGbyte * GetData();

	SQLINTEGER * GetIndicator();

	~UGColumnBind();
private:
	UGint m_nFieldLength;
	UGint m_nFieldSize;
	UGint m_nOnceBulkCount;
	UGshort m_nType;
	
	UGbyte * m_pData;
	SQLINTEGER * m_pIndicator;
	UGuint * m_pBindOffSet;
};

class  UGEXPORT UGColumnBinds : public UGArray<UGColumnBind *>
{
public:
	
	UGColumnBinds()
	{
	};

	~UGColumnBinds()
	{
		ReleaseAll();
	};

public:

	void ReleaseAll();
	UGColumnBind * operator [](UGint nIndex) const;
};

}
#endif // !defined(AFX_UGODBCCONNECTION_H__173F3F2B_C652_4D91_B169_0BD07F4AA6C8__INCLUDED_)
