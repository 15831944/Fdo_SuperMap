/*! 
	\file	SMCDsOperate.h
    \brief	����Դ������
	\author	�� ��
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-28 ��ʼ���汾
*/
#include "SMCDsOperate.h"

SMCDsConnection::SMEngineType EngNameToEngType(const _tstring strSource)
{
	SMCDsConnection::SMEngineType nEngine;
	if(strSource == _T("sdb"))
	{
		nEngine = SMCDsConnection::SDBPlus;
	}
	else if(strSource == _T("ora"))
	{
		nEngine = SMCDsConnection::OraclePlus;
	}
	else if(strSource == _T("sql server"))
	{
		nEngine = SMCDsConnection::SQLPlus;
	}
	else
	{
		nEngine = SMCDsConnection::SDBPlus;
	}
	return nEngine;
}
