/** \file	 SuperMapLpPropertyDefinition.h
*  \brief    ������Ҫ��ɴ�SuperMapʸ�����ݼ������е�Fdo�߼�Ҫ��������Ե�ת����
*  \author	 �� ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-5
*/

#ifndef __SUPERMAP_LP_PROPERTYDEFINITION_H__
#define __SUPERMAP_LP_PROPERTYDEFINITION_H__

#ifdef _WIN32
#pragma once
#endif

#include "UGC.h"

class SuperMapLpClassDefinition;

class SuperMapLpPropertyDefinition : public FdoDisposable
{
public:
	SuperMapLpPropertyDefinition(SuperMapLpClassDefinition* parentLpClass, UGC::UGDatasetVector* pDataset, UGC::UGFieldInfo* fieldInfo, FdoPropertyDefinition* configLogicalProperty);
	~SuperMapLpPropertyDefinition(void);

	//! \brief		���������ݼ��������ֶν����߼�Ҫ�������������
	//! \param		[in]fieldInfo ���������ֶ���Ϣ��ָ��
	void ConvertPhysicalToLogical(UGC::UGFieldInfo* fieldInfo);

	//! \brief		���߼�Ҫ������������Խ����������ݼ��������ֶ�
	//! \param		[in/out]pDatasetVector �ڸ�ʸ�����ݼ��н������������ֶ�  
	//! \param		[in]configLogicalProperty ��ת�����߼�����
	void ConvertLogicalToPhysical(UGC::UGDatasetVector* pDatasetVector,FdoPropertyDefinition* configLogicalProperty);

	 // To please FdoNamedCollection:
    FdoString* GetName(void);
    virtual FdoBoolean CanSetName() { return true; }

	// Returns the physical layer:
	UGC::UGFieldInfo* GetFieldInfo() const;
    
protected:
	SuperMapLpPropertyDefinition(){}
private:
	// Parent LpClass, weak reference
	SuperMapLpClassDefinition* m_parentLpClass;

	// logical layer
	FdoPtr<FdoDataPropertyDefinition> m_logicalProperty;

	// physical layer
	UGC::UGFieldInfo* m_fieldInfo;
};

class SuperMapLpPropertyDefinitionCollection : public FdoNamedCollection<SuperMapLpPropertyDefinition, FdoException>
{
public:
	SuperMapLpPropertyDefinitionCollection(){}

protected:
	virtual ~SuperMapLpPropertyDefinitionCollection(){}

	/// <summary>Dispose this object instance.</summary>
    /// <returns>Returns nothing</returns>
    virtual void Dispose() 
    { 
        delete this; 
    }
};


#endif //__SUPERMAP_LP_PROPERTYDEFINITION_H__