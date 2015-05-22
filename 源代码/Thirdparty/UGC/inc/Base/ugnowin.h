/* 
	\file ugnowin.h
	\brief ��Windowsƽ̨��Linux��Unix�ȣ���ͷ�ļ�����
	\author zengzm
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef _UGNOWIN_H
#define _UGNOWIN_H

// commited by zengzm 2007-3-30 ��link.h�������������Solaris�б��벻����
// ��Ϊ����ᶨ��_FILE_OFFSET_BITSΪ64����link.h��include��libelf.h��
// �ж�_FILE_OFFSET_BITS������32����_ILP32Ҳ�Ѿ������壬�ͻ�����������
// �������м��ĳ��ͷ�ļ��ж�����_ILP32����˰�link.h�ŵ���ǰ���У��Ա���˱������
#ifdef _AIX
#include <dlfcn.h> // for dlopen() & dlsym()
#else 
#include <link.h>  // for dlopen() & dlsym()
#endif               

// ͷ�ļ�����
// ����꣬ʹ�ÿ��Դ�����ļ���>4GB��
#undef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <dirent.h>	
#include <fcntl.h>
#define UGopen	open
#define UGwrite	write
#define UGread	read
#define UGseek	lseek
#define UGclose	close

#define UGBINARY 0
#define UGREADWRITE 0666

//#ifndef O_BINARY
//	#define O_BINARY 0
//#endif	//O_BINARY

#define PATHSEP '/'
#define PATHSEPSTRING "/"
#define PATHLISTSEP ':'
#define PATHLISTSEPSTRING ":"
#define ISPATHSEP(c) ((c)=='/')
#define EOLSTRING "\n"
#define WEOLSTRING L"\n"

#define UGCALLBACK  
#define UGSTDCALL 


#include <X11/Xlib.h>  

namespace UGC {

// �������Ͷ���
typedef unsigned long UGThreadID;
typedef void*		  UGHandle;

//deleted by xielin 2007-06-26 ������û���û������ͻ��ɾ��
//typedef ::Display*  Display;
//typedef ::Window   DisplayWnd;

}


#endif // _UGNOWIN_H
