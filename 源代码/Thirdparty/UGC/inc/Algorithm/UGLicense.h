#ifndef _UGLICENSE_H
#define _UGLICENSE_H

#include "lserv.h"
class UGLData;
class UGL
{
public:
	enum FunctionID
	{
		//! brief �õ�����е��û���Ϣ
		efnGetUserInfo = 1,			
		//! brief ��֤����Ƿ���ȷ
		efnVerifyLicense = 2,		 
		//! brief ��������
		efnOpenLock = 3,			 
		//! brief �ر�������
		efnCloseLock = 4,			 
	};
	LS_STATUS_CODE C(UGLData &data);

private:
	LS_HANDLE m_handle;
	static int m_nInitCount;
};
class UGLData
{
public:
	UGLData();
	~UGLData();
	UGL::FunctionID functionid;
	char *pchProduct;
	char *pchVersion;
	char *pchUser;
	char *pchCompany;
};
#endif
