// UGDataSourceManager.h: interface for the UGDataSourceManager class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDataSourceManager.h
   **************************************************************************************
    \author   �¹���
    \brief    �������涯̬������࣬����̬���غ��ͷ�sdx���涯̬�⣬�������������ͺ�
			  ��̬����������ͬ���͵�����Դ��                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/


#if !defined(AFX_UGDATASOURCEMANAGER_H__EA4836B3_3C1F_4535_A920_07AC41C17303__INCLUDED_)
#define AFX_UGDATASOURCEMANAGER_H__EA4836B3_3C1F_4535_A920_07AC41C17303__INCLUDED_

#include "UGEngineDefine.h"

namespace UGC {
  
class ENGINE_API UGDataSourceManager  
{
public:
	UGDataSourceManager();
	virtual ~UGDataSourceManager();

public:
	//========================================================
	//! \brief 		��������Դʵ������������������������һ������Դ����������Oracle��SQL Server���ݿ⣬
	//				��������ָ��������Դ���ʹ���һ��UGDataSourceĳ�������ʵ������������ָ�롣
	//! \return 	UGDataSource*  newһ������Դָ�룬����������ɹ��ͷ���NULL��
	//! \param 		nEngineType �����������ͣ��������û���չ���������͡�
	static UGDataSource* CreateDataSource(UGEngineType nEngineType);

	static void FreeDao();

protected:

	//========================================================
	//! \brief 		��̬���غ�׺��Ϊsdx���������涯̬�⡣
	void LoadSDX();



protected:
	
	//========================================================
	//! \brief 		�ͷŶ�̬���ص�sdx�������涯̬�⡣
	void UnloadSDX();
	//========================================================
	//! \brief 		�ж��������涯̬�����Ƿ���Ч�������Ч�͹���һ�����涯̬�ⶨ�塣
	//! \return 	UGbool ����������涯̬������Ч�ͷ���true������ͷ���false��
	//! \param 		hHandle �������涯̬������
	//! \param 		EngineDef ���涯̬�ⶨ�塣
	UGbool CheckEngineDef(void* hHandle, UGEngineDefine& EngineDef);
	//========================================================
	//! \brief 		��������Դ�������Ͳ���һ�����涯̬�ⶨ�塣
	//! \return 	UGbool ����ҵ��ͷ���true������ͷ���false��
	//! \param 		nEngineType ����Դ�������͡�
	//! \param 		EngineDefine ���涯̬�ⶨ�塣
	UGbool FindEngine(UGEngineType nEngineType, UGEngineDefine& EngineDefine);

public:	
	//! \brief 		���涯̬�ⶨ������ 
	UGArray<UGEngineDefine> m_EngineDefines;

};

extern ENGINE_API UGDataSourceManager g_DataSourceManager;

}

#endif // !defined(AFX_UGDATASOURCEMANAGER_H__EA4836B3_3C1F_4535_A920_07AC41C17303__INCLUDED_)
