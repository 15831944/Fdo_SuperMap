/*! \file	 UGOCICursor.h
 *  \brief	 �α���
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOCICursor.h,v 1.2 2007/05/10 07:49:21 liwl Exp $
 */

#ifndef UGOCICURSOR_H
#define UGOCICURSOR_H

#include "Base/ugdefs.h"
#include "UGOCIConnection.h"
#include "Base/UGString.h"
#include "Engine/UGFieldInfo.h"
#include "UGOCIBind.h"
#include "UGOCIDefine.h"

namespace UGC {

//! �α���
class ORCENGINE_API UGOCICursor  
{
public:
	//! ���캯��
	UGOCICursor();

	UGOCICursor(UGOCIConnection* c);

	//! ��������
	~UGOCICursor();

	//! ������������
	void SetConnection(UGOCIConnection* c);

	//! ��
	void Open();

	//! �ر�
	void Close();	

	//! ��ȡ�ֶ���Ϣ
	UGbool GetFieldInfos(UGFieldInfos & fieldInfos,UGFieldInfos &SrcFieldInfos);

	UGbool GetFieldInfo(UGint nPos,
		sb1 *pbScale,
		sb1 *pbIsNULL,
		ub2 *pwType,
		ub2 *pnPrecision,
		ub4 *pnDataSize,
		UGString & strName);

	//����	
	void Prepare(const UGString& strStmt);
	
	//��
	void BindByPos(UGint pos, void* value, 
		UGint size, void* indicator, ub2 type);

	void BindByPos(UGint pos, OCIBind *& binhp,
		void* value, UGint size, void* indicator, ub2 type);

	void BindByPos(UGOCIBind &bind);

	void Bind(UGOCIBinds &binds);


	//���
	void DefineByPos(UGint pos, void* value,
		UGint size, void* indicator, ub2 type);

	void DefineByPos(UGint pos, OCIDefine *& defhp, 
		void* value, UGint size, void* indicator, ub2 type);

	void DefineByPos(UGOCIDefine &def);

	void Define(UGOCIDefines &defs);
	
	
	//ִ��ȡֵ
	void Execute(UGint times, const UGString & strFileName = "",
		UGint nLineNumber = 0);

	void Fetch(UGint rows);

protected:
	void CheckError(sword status);
public:
	UGOCIConnection* conn;
	OCIStmt* stmthp;
	OCIDefine* m_pOCIDefine;
	UGString m_strFileName;
	UGint m_nLineNumber;
	UGString m_strSQL;
	UGbool m_bOpened;
};

}

#endif

