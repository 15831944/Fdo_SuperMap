/* 
	\file ugwin32.h
	\brief Win32ƽ̨��ͷ�ļ�����
	\author zengzm
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef _UGWIN32_H
#define _UGWIN32_H

// 2003-5-28-by-malq-base���߳����ʹ��
#ifndef _WIN32_WINNT		// Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0x0400	// Change this to the appropriate value to target Windows 2000 or later.
#endif	

//#undef LoadString
//#undef DeleteFile
//#undef GetCurrentTime

#pragma warning(disable: 4018)  // signed/unsigned mismatch
#pragma warning(disable: 4097)
#pragma warning(disable: 4100)
#pragma warning(disable: 4164)
#pragma warning(disable: 4244)
// ���¼�������̫���������Ƿŵ�ugdefs.h��
//#pragma warning(disable: 4251)
//#pragma warning(disable: 4275)
//#pragma warning(disable: 4786)
#pragma warning(disable: 4514)
#pragma warning(disable: 4663)
//#pragma warning(disable: 4710) // Ϊ����չ��ѡ���˸�����������������û��ִ��������

// ͷ�ļ����� 
#include <io.h>
//#include <WinDef.h>

// by zengzm 2007-4-16 vsnprintf ��windows��û�ж���,������_vsnprintf��Ϊ���Ʒ,
// �ʶ��ض���һ��
//	#define vsnprintf _vsnprintf
#ifndef vsnprintf
	#define vsnprintf _vsnprintf
#endif


#define UGopen	_open
#define UGwrite	_write
#define UGread	_read
#define UGseek	_lseeki64
#define UGclose	_close

#define UGBINARY O_BINARY
#define UGREADWRITE _S_IREAD|_S_IWRITE

#define PATHSEP '\\'
#define PATHSEPSTRING "\\"
#define PATHLISTSEP ';'
#define PATHLISTSEPSTRING ";"
#define ISPATHSEP(c) ((c)=='/' || (c)=='\\')
#define EOLSTRING "\r\n"
#define WEOLSTRING L"\r\n"

// copy from <windef.h>
#if (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)
	#define CALLBACK    __stdcall
#else
	#define CALLBACK
#endif

#define UGCALLBACK CALLBACK
#define UGSTDCALL __stdcall

namespace UGC {

// ��������
typedef void*         UGThreadID;
typedef unsigned int  UGHandle;

}

#endif
