/*! 
	\file	SMCDataset.h
    \brief	���ݼ����ࣨ�����ࣩ
	\author	����
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-19 ��ʼ���汾
*/


#ifndef SMCDATASET_H
#define SMCDATASET_H

#include "SMC.h"

class SMCDataSource;

class SMC_API SMCDataset
{
public:
	//! brief	���ݼ�����
	enum DatasetType
	{
		Tabular		=0,		//! ֻ�����Ա�û�м��ζ���
		Point		=1,		//! �����ݼ�
		Line		=3,		//! �����ݼ�
		Network		=4,		//! �������ݼ�
		Region		=5,		//! ��������ݼ�
		Text		=7,		//! �ı����ݼ�
		LineM		=35,	//! ·�����ݼ�
		Image		=81,	//! Ӱ��
		MrSID		=82,	//! MrSID
		Grid		=83,	//! դ��
		DEM			=84,	//! DEM
		ECW			=85,	//! ECW
		WMS			=86,	//! WMS		
	
		PointZ		=101,	//! ��ά��
		LineZ		=103,	//! ��ά��
		RegionZ		=105,	//! ��ά��
		PointGL		=137,	//! ����������Point3D
		TIN			=139,	//! TIN���ݼ�
		CAD			=149,	//! CAD���ݼ�
		
		WFS			=151,	//! WFS
		LinkTable	=153,	//! ���ݿ��,ֻ������
		Topo		=154	//! Topo���ݼ�	
	}; 

public:
	SMCDataset();
	~SMCDataset();

public:
	//! \brief	�����ݼ�
	virtual bool Open() = 0;

	//! \brief	�ر����ݼ�
	virtual void Close() = 0;

	//! \brief 		�õ����ݼ�����
	//! \return     SMCDataset::DatasetType (or int) �������ݼ����ͣ����������ݼ�����ö�ٶ���
	virtual DatasetType GetType() const=0;

	//! \brief		�������ݼ���(���Ժͱ�����ͬ)
	virtual _tstring GetName() =0;

	//! \brief		���ݼ�������,ֻ�ı����ݼ���,��������
	//! \param		steNewName  �޸ĺ��������
	//! \return     bool �޸ĳɹ�����true�� ���򷵻�false
	virtual bool Rename(const _tstring& strNewName) = 0;

	//! \brief		�ж��Ƿ���ʸ�����ݼ�
	//! \return		bool ��ʸ�����ݼ�����true�� ���򷵻�false
	virtual bool IsVector() =0;

	//! \brief		�������ݼ���Ϣ
	//! \return		bool ����ɹ�����true�� ���򷵻�false
	virtual bool SaveInfo() = 0;

	//! \brief		ˢ�����ݼ���Ϣ
	//! \return		bool ˢ�³ɹ�����true�� ���򷵻�false
//	virtual bool RefreshInfo() = 0;	

public:
	//! \brief		�������ݼ���ID
	//! \return		int ���ݼ���ID
	int GetID() const ;

	//! \brief		�������ݼ���ID
	//! \param		nID �����õ�ID��
	void SetID(int nID);

	//! /brief		��������Դָ��
	//! /param[out] pDataSource�������ݼ�����������Դ
	//! /return		bool��ȡ����Դ�ɹ�����true�����򷵻�false
	bool GetDataSource(SMCDataSource*& pDataSource) const ;

	//! /brief		��������Դָ��
	//! /param	    pDataSource,�����ݼ���Ϊ���ڴ�����Դ
	void SetDataSource(SMCDataSource* pDataSource);

	//! /brief		�ж����ݼ��Ƿ��޸�
	//! return		������޸��򷵻�true�� ���򷵻�false
	bool IsModified() const;

	//! /brief		�����޸ı�־
	//! /param		bModified,����޸������ݼ�����Ϊtrue��������Ϊfalse��Ĭ����Ϊtrue
	void SetModifiedFlag(bool bModified = TRUE);

	//! /brief		�ж����ݼ��Ƿ��Ѿ���
	//! /return     bool����Ѿ����򷵻�true�����򷵻�false
	virtual bool IsOpen() const;

public:
	void *m_pDataset;
};

#endif