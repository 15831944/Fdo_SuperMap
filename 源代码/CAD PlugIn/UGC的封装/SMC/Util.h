#ifdef _UNICODE

#ifndef _UTIL_STRING_ 
#define _UTIL_STRING_ 

#include <string>
#include <windows.h>
#include <tchar.h>

// ���ַ���תASCII
std::string WcharToString(const wchar_t* wstr);
// ASCIIת��Ϊ���ַ�
std::wstring StringToWString(const std::string &str);

#endif

#endif


