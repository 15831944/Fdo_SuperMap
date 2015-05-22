#pragma once
/*! 
	\file	SMCStringHelper.h
    \brief	�ַ���������
	\author	�� ��
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-28 ��ʼ���汾
*/

#include "SMC.h"

class SMC_API SMCStringHelper
{
public:
	//! \brief      ����delimeter�ָ����ַ������н������ָ������ַ���
	//! \return     std::vector<_tstring> �����������Vector��
	//! \param      [in]strSorce,Ҫ�ָ����ַ���
	//! \param		[in]delimeter,�ַ����Ľ綨��������;��
	//! \note		�ú����Ǿ�̬��Ա����
	static std::vector<_tstring> Explode(const _tstring &strSorce, const _tstring& delimeter);

	//! \brief      ������A=B��ʽ�Ĵ�ת��ΪMap�е�Key=A��Value=B
	//! \param      [in]strSorce,Դ��������
	//! \param		[out]connInfo,ת�����Map
	//! \note		�ú����Ǿ�̬��Ա����
	static void ProKeyAndVal(const std::vector<_tstring> &strSource, std::map<_tstring, _tstring> &connInfo); 

	//! \brief      ���ַ���ת��ΪСд
	//! \return		����ַ���
	//! \param      [in]strSorce,Դ�ַ�����
	//! \note		�ú����Ǿ�̬��Ա����
	static _tstring MakeStrLower(const _tstring &strSource);
};
