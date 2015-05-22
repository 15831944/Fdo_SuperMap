
/** \file	 SuperMapFilterStringBuffer.h
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/

#ifndef __SUPERMAP_FILTERSTRINGBUFFER_H__
#define __SUPERMAP_FILTERSTRINGBUFFER_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapFilterStringBuffer SuperMapFilterStringBuffer.h
	\brief ���ڴ�Ž�����Ĺ��˴�
	return ���ַ�������ʽ���ع��˴�
*/

class SuperMapFilterStringBuffer
{
public:
	SuperMapFilterStringBuffer(void);

public:
	~SuperMapFilterStringBuffer(void);

protected:
	char* m_pFilterText;		// ���ڴ洢������Ĺ��˴�
    size_t m_BuffSize;			// ���˴��Ĵ�С
    size_t m_FirstBuffIndex;	// ָ����˴���ʼ��λ�ã�Ϊ�˷����ڴ���ǰ�������ַ���
    size_t m_NextBuffIndex;		// ָ����˴���β��λ��  

public:
	/*
		\brief �õ�������Ĺ��˴�
		\return ָ����˴���ָ��
	*/
    const char* GetString();  

	/*
		\brief �ڹ��˴���ĩβ����һ���ַ���
		\param [in]Str ָ��Ҫ���ӵ��ַ���
		\note �ڸú����ڿ���Ҫ����ռ�
	*/
    void AppendString(const char *Str);

	/*
		\brief �ڹ��˴���ǰ������һ���ַ���
		\param [in]Str ָ��Ҫ���ӵ��ַ���
		\note �ڸú����ڿ���Ҫ���·���ռ�
	*/
    void PrependString(const char *Str);  

	/*
		\brief ��չ��˴������ͷſռ�
	*/
    void ClearBuffer(void);
      
protected:
	/*
		\brief ���·�����˴��ռ�
		\param [in]Size ���·����ڴ�Ĵ�С
		\param [in]bAtEnd ���·����ڴ�ķ���, ���Ϊ��: �Ӻ�������ڴ�, �����ǰ������ڴ�; 
	*/
  void ReallocBuffer( size_t Size , bool bAtEnd );
};

#endif