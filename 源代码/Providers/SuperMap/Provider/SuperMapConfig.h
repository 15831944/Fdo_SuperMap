/** \file	 SuperMapConfig.h
*  \author	 ����
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-03-25
*/

#ifndef _SUPERMAP_CONFIG_H_
#define _SUPERMAP_CONFIG_H_

#ifdef _WIN32
#pragma once
#endif // _WIN32

#define CONFIG_FILE     "ProviderConfig.ini"
#define COMMON_SECTION  "CommonConfig" 
#define SMFIELD_KEY     "ReadSuperMapSystemField"

class SuperMapConfig
{
public:
	SuperMapConfig();
	~SuperMapConfig();

	//�������ļ���ʼ����Ա����
	static void Init();
public:
	static bool m_IsReadSmField;  //�Ƿ��ȡSuperMapϵͳ�ֶ�

};

#endif
