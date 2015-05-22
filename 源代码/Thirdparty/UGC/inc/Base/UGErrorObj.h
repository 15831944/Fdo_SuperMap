/*! \file	 UGErrorObj.h
 *  \brief	 ����������ļ�
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGErrorObj.h,v 1.9 2007/10/11 09:13:39 zengzm Exp $
 */

#ifndef UGERROROBJ_H
#define UGERROROBJ_H

#include "ugdefs.h"
#include "UGString.h"
#include "UGArray.h"
#include "ugplatform.h"
//#include "UGLogFile.h"

namespace UGC {

typedef void (*ErrorInfoProc)(const UGchar* pchErrorInfo);

//! �������
class BASE_API UGErrorObj  
{
	friend class UGLogFile;
public:
	//! ������Ϣ
	struct ErrorInfo
	{
		//! \brief ���������ڵ��߳�id
		UGint m_nThreadId;
		//! ���, ��Դ�ַ���id
		UGint m_nID;
		//! ����
		UGString m_strMessage; 
		//! �ļ���
		UGString m_strCodeFile;
		//! �к�
		UGint m_nCodeLine;
		//! Ĭ�Ϲ��캯��
		ErrorInfo() {
			m_nThreadId = -1; 
			m_nID = 0;			//! ��ʾ��û�����ô���, 
			m_nCodeLine = -1;	//! ��ʾ�Ƿ�ֵ
		}

		ErrorInfo(UGuint nThreadId,UGint nID,UGString strMessage,
			UGString strCodeFile,UGint nCodeLine) 
		{
			m_nThreadId = nThreadId;
			m_nID = nID;
			m_strMessage = strMessage;
			m_strCodeFile = strCodeFile;
			m_nCodeLine = nCodeLine;
		}
	};

	UGErrorObj();	
private:
	UGErrorObj(const UGErrorObj&);
	UGErrorObj& operator=(const UGErrorObj&);
	
public:	
	~UGErrorObj();

	//! \brief �õ���������Ψһʵ��, ��Ҫֱ�Ӷ���������
	//! \remarks Ҫ��õ�������Ϣ, �����ȵ���Startup �����־�ļ�
	static UGErrorObj& GetInstance(); 

	//! \brief �����������
	//! \remarks ����������������һ�£�����ʹ��; �ڲ�ʹ��LogFileʵ��
	//! \return �ɹ���������true,ʧ�ܷ���false
	UGbool Startup();

	//! \return �����Ƿ�����
	UGbool IsStartup();

	//! \brief ���ô�����Ļص�����ָ��
	static void SetErrorInfoProc(ErrorInfoProc pErrorInfoFun);	

	//! �õ�����������
	UGint GetCount() const;
	
	//! ��մ������
	void Clear();

	//! ����������С
	void SetCapacity(UGint nCapacity);

	//! ��ȡ������С
	UGint GetCapacity() const;

	ErrorInfo GetAt(UGint nIndex) const;

	//! \brief �õ����һ��������Ϣ
	//! \param bBythread �Ƿ�ֻ���ǵ�ǰ�߳�,Ĭ��Ϊ����; ���Ϊtrue,���ȡ���ڵ�ǰ�߳��е����һ��������Ϣ
	//! ���Ϊfalse,��ȡ�����д�����Ϣ�е����һ��
	//! \return �������һ��������Ϣ
	ErrorInfo GetLast(UGbool bBythread=TRUE) const;

	void Dump(UGString& strErrorInofs,UGbool bBythread=TRUE) const;

	static void Format(const ErrorInfo& errorInfo,UGString& strErrorInfo,UGbool bBythread=TRUE);

private:
	//! ��Ӵ�����Ϣ
	void Add(const ErrorInfo& errorInfo);

	//! ��Ӵ�����Ϣ
	void Add(UGuint nThreadID, UGuint nID, UGString m_strCodeFile, UGint m_nCodeLine);

private:

	// by zengzm 2007-10-11 ��������ڲ�������־�ļ���ʵ��, ��Щ������ע������
	//! �Ƿ���ѭ����
//	UGbool m_bCycled;
	//! ��һ�����λ��
//	UGint m_nPos;
	//! �洢������Ϣ
//	UGArray<ErrorInfo> m_ErrorObjs;	

	
	//! \brief ������Ϣ�ص�����ָ��
	static ErrorInfoProc ms_pErrorInfoFun;
};

}

#endif

