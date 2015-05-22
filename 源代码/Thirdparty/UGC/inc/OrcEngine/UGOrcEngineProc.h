// UGOrcEngineProc.h: interface for the UGOrcEngineProc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCENGINEPROC_H__F46AC2F5_0F1E_4492_B786_C7108E190E2C__INCLUDED_)
#define AFX_UGORCENGINEPROC_H__F46AC2F5_0F1E_4492_B786_C7108E190E2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Engine/UGEngineProc.h"

namespace UGC {

class ORCENGINE_API UGOrcEngineProc : public UGEngineProc
{
public:
	UGOrcEngineProc();
	virtual ~UGOrcEngineProc();
	
	//! \brief ȡ�����ݿ�������������ݿ��û���Ϣ
	//! \param &ConnSys [in] ���ݿ����ӣ�Ҫ�ṩϵͳ�û�
	//! \param &aryDBInfos [out] �������ݿ���Ϣ
	//! \return �ɹ� True 
	//! \attention ConnSysһ����ϵͳȨ��	
	virtual UGbool GetAllDbInfo(UGDsConnection &ConnSys,UGArray<UGDBInfo> &aryDBInfos);

};
}
#endif // !defined(AFX_UGORCENGINEPROC_H__F46AC2F5_0F1E_4492_B786_C7108E190E2C__INCLUDED_)
