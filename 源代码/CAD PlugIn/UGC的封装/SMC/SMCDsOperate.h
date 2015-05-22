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

#include "SMC.h"
#include "SMCDsConnection.h"

const  _tstring SMC_CONNECTION_TYPE			= _T("type");
const  _tstring SMC_CONNECTION_SERVER		= _T("server");
const  _tstring SMC_CONNECTION_DATABASE		= _T("database");
const  _tstring SMC_CONNECTION_USER			= _T("user");
const  _tstring SMC_CONNECTION_PWD			= _T("pwd");
const  _tstring SMC_CONNECTION_FILE			= _T("file");

//! \brief		�����������ֵõ���������
//! \return		SMCDsConnection::SMEngineType ��������
//! \param		[in]strSource ��������
SMCDsConnection::SMEngineType EngNameToEngType(const _tstring strSource);



