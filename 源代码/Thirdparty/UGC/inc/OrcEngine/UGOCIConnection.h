/*! \file	 UGOCIConnection.h
 *  \brief	 Oralce OCI������
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOCIConnection.h,v 1.2 2007/04/05 06:57:41 zhouqin Exp $
 */

#ifndef UGOCICONNECTION_H
#define UGOCICONNECTION_H

#include "Base/ugdefs.h"
#include "OrcEngine/UGOCIBind.h"

#ifndef OCI_ORACLE
#include "oci.h"
#endif

namespace UGC {

//! ����������
class ORCENGINE_API UGOCIConnection  
{
public:
	//! ���캯��
	UGOCIConnection();

	//! ��������
	~UGOCIConnection() {
		Disconnect();
	}

public:
	//�س�
	UGbool TransRollBack();

	//�ύ
	UGbool TransCommit();
	
	//! ����
	void Connect(const UGchar* dblink, const UGchar* username, const UGchar* password,
		const UGint nMinConn, const UGint nMaxConn, const UGint nIncConn);
		
	//! �Ͽ�����
	void Disconnect();

	//! �ж��Ƿ�����
	UGbool IsConnected() { return connected; }

	//! ������
	void CheckError(OCIError* errhp,UGint status);	
	
	//! ִ��
	UGbool ExecUpdate(const UGchar* pcSQL,
		UGOCIBinds& binds,
		const UGchar* pcFile, 
		UGint nLine,
		UGbool bCanTrans);

	//! ִ��
	UGbool ExecUpdate(const UGchar* pcSQL,
		const UGchar* pcFile,
		UGint nLine,
		UGbool bCanTrans);

	//! ִ��
	UGuint ExecStatCount(const UGchar* pcSQL,
		const UGchar* pcFile,
		UGint nLine);

	//! ִ��
	UGuint ExecStatCount(const UGchar* pcSQL,
		UGOCIBinds& binds,
		const UGchar* pcFile,
		UGint nLine);

public:	
	OCIEnv* envhp;      
	
	OCIError* errhp;
	
	OCIServer* srvhp;

	OCISvcCtx* svchp;
	OCISession* usrhp;
protected:
	//! �Ƿ�����
	UGbool connected;

private:
	//���ӳ� ����
	OCICPool *poolhp;
	
	//! brief ���ӳ�����
	OraText *poolName;
	
	//! brief ���ӳس���
	sb4 poolNameLen;
};

}

#endif

