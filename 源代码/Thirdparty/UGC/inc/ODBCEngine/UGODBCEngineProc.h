// UGODBCEngineProc.h: interface for the UGODBCEngineProc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCENGINEPROC_H__0054E816_8709_45DB_8346_FE3BCEC49864__INCLUDED_)
#define AFX_UGODBCENGINEPROC_H__0054E816_8709_45DB_8346_FE3BCEC49864__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGEngineProc.h"

namespace UGC
{
class UGEXPORT UGODBCEngineProc:public UGEngineProc
{
public:
	UGODBCEngineProc();
	virtual ~UGODBCEngineProc();

	//! \brief ȡ�����ݿ�������������ݿ��û���Ϣ
	//! \param &ConnSys [in] ���ݿ����ӣ�Ҫ�ṩϵͳ�û�
	//! \param &aryDBInfos [out] �������ݿ���Ϣ
	//! \return �ɹ� True 
	//! \attention ConnSysһ����ϵͳȨ��	
	virtual UGbool GetAllDbInfo(UGDsConnection &ConnSys,UGArray<UGDBInfo> &aryDBInfos);

};
}
#endif // !defined(AFX_UGODBCENGINEPROC_H__0054E816_8709_45DB_8346_FE3BCEC49864__INCLUDED_)
