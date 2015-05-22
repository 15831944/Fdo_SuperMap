// UGEngineProc.h: interface for the UGEngineProc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGENGINEPROC_H__9BE9CE22_0DAF_4792_88C0_DE17AE70EDE8__INCLUDED_)
#define AFX_UGENGINEPROC_H__9BE9CE22_0DAF_4792_88C0_DE17AE70EDE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Engine/UGDataSource.h"
#include "Engine/UGDsConnection.h"

namespace UGC {

class ENGINE_API UGDBInfo
{
public:
	UGDsConnection	m_dsConntion;
	UGint			m_nVersion;
};

class ENGINE_API UGEngineProc  
{
public:
	UGEngineProc();
	virtual ~UGEngineProc();
	
	//! \brief ȡ�����ݿ�������������ݿ��û���Ϣ
	//! \param &ConnSys [in] ���ݿ����ӣ�Ҫ�ṩϵͳ�û�
	//! \param &aryDBInfos [out] �������ݿ���Ϣ
	//! \return �ɹ� True 
	//! \attention ConnSysһ����ϵͳȨ��
	virtual UGbool GetAllDbInfo(UGDsConnection &ConnSys,UGArray<UGDBInfo> &aryDBInfos) = 0;

	

};
}
#endif // !defined(AFX_UGENGINEPROC_H__9BE9CE22_0DAF_4792_88C0_DE17AE70EDE8__INCLUDED_)
