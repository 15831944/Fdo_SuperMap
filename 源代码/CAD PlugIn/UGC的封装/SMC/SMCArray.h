/*! 
	\file	SMCArray.h
    \brief	���������
	\author	����
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-24 ��ʼ���汾
*/

#ifndef SMCARRAY_H
#define SMCARRAY_H

#include <vector>
#include "SMC.h"

template<typename T>
class SMC_API SMCArray
{
public:
	SMCArray(){}
	~SMCArray(){}
public:
	std::vector<T> m_array;
};

#endif
