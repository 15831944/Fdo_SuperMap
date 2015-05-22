/** \file	 SuperMapLpFeatureSchema.h
*  \brief    ������Ҫ��ɴ�SuperMap����Դ��Fdo�߼�ģʽ��ת����
*  \author	 �� ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-5
*/

#ifndef __SUPERMAP_LP_FEATURESCHEMA_H__
#define __SUPERMAP_LP_FEATURESCHEMA_H__

#ifdef _WIN32
#pragma once
#endif

#include "UGC.h"

class SuperMapConnection;
class SuperMapLpFeatureSchemaCollection ;
class SuperMapLpClassDefinitionCollection ;

class SuperMapLpFeatureSchema : public FdoDisposable
{
public:
	SuperMapLpFeatureSchema(void); // 0-argument constructor to please FdoPtr::operator-> 

	SuperMapLpFeatureSchema(
		SuperMapLpFeatureSchemaCollection* parentLpSchemas,
		SuperMapConnection* connection,
		UGC::UGDataSource* pDataSource,
		FdoFeatureSchema* configLogicalSchema,
		bool ignoreStates = false);

	// For FdoNamedCollection:
    FdoString * GetName() const;
    bool CanSetName() const;

	//! \brief		��ȡ�߼�����ģʽ�е��߼�ģʽ
	//! \return		FdoFeatureSchema* �߼�ģʽ�ĵ�ָ��
    FdoFeatureSchema * GetLogicalSchema() const;

	//! \brief		��ȡ�߼�����ģʽ�е�Ӱ��ģʽ
	//! \return		FdoFeatureSchema* �߼�ģʽ�ĵ�ָ��
    //FdoFeatureSchema * GetImageSchema() const;

    //! \brief		��ȡ�߼�����ģʽ�е��߼������༯��
	//! \return		SuperMapLpClassDefinitionCollection* �߼������༯�ϵ�ָ��	
    SuperMapLpClassDefinitionCollection* GetLpClasses();

    //! \brief		��ȡ�߼�����ģʽ�е���������Դ
	//! \return		UGC::UGDataSource* ��������Դָ�� 
    UGC::UGDataSource* GetDataSource() const;

	//! \brief      ���ݸ�������Ϣ�޸�ģʽ
	//! \param      connection ��ǰ��SuperMap����
	//! \param		configLogicalSchema ���޸ĵ�ģʽ
	//! \param		bool����ignoreStates���Ƿ����ģʽԪ��״̬
	void Modify(SuperMapConnection* connection, FdoFeatureSchema* configLogicalSchema, bool ignoreStates);

	//! \brief		�ڵ�ǰģʽ������һ��Ҫ����
	//! \param		connection ��ǰ��SuperMap����
	//! \param		logicalClass ��ӵ��߼��ࣨ�����������и��ݴ��߼��ഴ���������ݼ���
	void addClass(SuperMapConnection* connection, FdoClassDefinition* logicalClass);

	//! \brief		�ڵ�ǰģʽ��ɾ��һ��Ҫ����
	//! \param		connection ��ǰ��SuperMap����
	//! \param		��ɾ������
	void deleteClass(SuperMapConnection* connection, FdoClassDefinition* logicalClass);

	//! \brief		�ڵ�ǰģʽ���޸�һ��Ҫ����
	//! \param		connection ��ǰ��SuperMap����
	//! \param		���޸ĵ���
	void modifyClass(SuperMapConnection* connection, FdoClassDefinition* logicalClass);

	//! \brief		����ɾ�����߼�ģʽ�е������Ϣ
	//! \param		connection ��ǰ��SuperMap����
	void Delete(SuperMapConnection* connection);

protected:
	//! \biref		����������Դ���߼�ģʽ��ת��
	//! \param		[in]connection ��ǰ����
    void ConvertPhysicalToLogical(SuperMapConnection * connection);
	
	//! \biref		���߼�ģʽ����������Դ��ת��
	//! \param		[in]connection ��ǰ����
	//! \param		[in]configLogicalSchema ��ת�����߼�ģʽ
	//! \param		[in]ignoreStates �Ƿ����FDOģʽԪ��״̬��־
	void ConvertLogicalToPhysical(SuperMapConnection* connection, FdoFeatureSchema* configLogicalSchema, bool ignoreStates);

	virtual ~SuperMapLpFeatureSchema(void);

private:
	SuperMapLpFeatureSchemaCollection*          m_parentLpSchemas ;    // weak reference ��������߼�����ģʽ���߼�����ģʽ����
	FdoPtr<FdoFeatureSchema>					m_logicalSchema ;      // �߼���FDO��ģʽ
	UGC::UGDataSource*							m_pDataSource ;        // ����UGC��ģʽ,��SuperMap����Դ
	FdoPtr<SuperMapLpClassDefinitionCollection> m_lpClasses ;          // �߼�������

	// ר�Ŵ���Ӱ�����ݵ�ģʽ
	//FdoPtr<FdoFeatureSchema> m_ImageSchema;

};

class SuperMapLpFeatureSchemaCollection : public FdoNamedCollection<SuperMapLpFeatureSchema, FdoException>
{
public:
	SuperMapLpFeatureSchemaCollection(void);

	SuperMapLpFeatureSchemaCollection(
		SuperMapConnection* connection,
		UGC::UGDataSource* pDataSource
		);

	// Return pointer to cached logical schema collection:
    FdoFeatureSchemaCollection* GetLogicalSchemas();

protected:
	// Convert physical to logical schema collection:
	void ConvertPhysicalToLogical(SuperMapConnection* connection,UGC::UGDataSource* pDataSource);

	virtual ~SuperMapLpFeatureSchemaCollection(void){}
	/// <summary>Dispose this object instance.</summary>
    /// <returns>Returns nothing</returns>
    virtual void Dispose() 
    { 
        delete this; 
    }

private:
	FdoPtr<FdoFeatureSchemaCollection> m_logicalSchemas;             // ����������Դת�����߼�ģʽ����

};

#endif //__SUPERMAP_LP_FEATURESCHEMA_H__