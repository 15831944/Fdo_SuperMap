/** \file	 SuperMapLpClassDefinition.h
*  \brief    ������Ҫ��ɴ�SuperMap���ݼ���Fdo�߼����ת����
*  \author	 �� ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-5
*/

#ifndef __SUPERMAP_LP_CLASSDEFINITION_H__
#define __SUPERMAP_LP_CLASSDEFINITION_H__

#ifdef _WIN32
#pragma once
#endif

class SuperMapConnection;
class SuperMapLpFeatureSchema;
class SuperMapLpPropertyDefinitionCollection;

class SuperMapLpClassDefinition : public FdoDisposable
{
	friend class SuperMapLpFeatureSchema;

public:
	SuperMapLpClassDefinition(void);
	SuperMapLpClassDefinition(
		SuperMapLpFeatureSchema* parentLpSchema, 
		SuperMapConnection* connection, 
		UGC::UGDataset* pDataset, 
		FdoClassDefinition* configLogicalClass);

	~SuperMapLpClassDefinition(void);

	//! \biref		���������ݼ����߼�Ҫ�����ת��
	//! \param		[in]connection ��ǰ����
	//! \param		[in]pDataset ��ת�����������ݼ�
	void ConvertPhysicalToLogical(SuperMapConnection * connection, UGC::UGDataset* pDataset);
	
	//! \biref		���߼�Ҫ���ൽ�������ݼ���ת��
	//! \param		[in]connection ��ǰ����
	//! \param		[in]configLogicalClass ��ת�����߼�Ҫ����
	void ConvertLogicalToPhysical(SuperMapConnection* connection, FdoClassDefinition* configLogicalClass);

	//! \biref		���������ݼ��ı�ʶ�ֶ�ת�����߼���ı�ʶ�����ֶ�
	//! \return     ����һ��FdoDataPropertyDefinition��ָ��
    static FdoDataPropertyDefinition* ConvertPhysicalToLogicalIdentityProperty();

	//! \brief		�����������ݼ���������Ҫ����ļ�������
    //! \param		[in]connection ��ǰ����
	//! \param      [in]pDatasetVector ʸ�����������ݼ�
	//! \return     ����һ��FdoGeometricPropertyDefinition��ָ��
    static FdoGeometricPropertyDefinition* ConvertPhysicalToLogicalGeometryProperty(SuperMapConnection *connection,
		UGC::UGDatasetVector* pDatasetVector);

	//! \brief		��Fdo�ļ������͵��������ݼ����͵�ת��
    //! \param		[in]geomTypes �洢�����Fdo�������͵�����
	//! \param      [in]geomTypeCount �������������о���ļ������͸���
	//! \return     ����UGC���������ݼ�����
	//! \note		Fdo����������������FdoGeometricPropertyDefinition::SetSpecificGeometryTypes()���ÿ�����ȷת��;
	//!             ��������FdoGeometricPropertyDefinition::SetGeometryTypes()��������            
	static UGC::UGDataset::DatasetType FdoGeometryToUGDatasetType(FdoGeometryType* geomTypes, FdoInt32 geomTypeCount,
		bool has_elevation, bool has_measure);
	
	//! \brief		����դ�����ݼ����ɶ�Ӧ���߼�դ������
	//! \param		connection ��ǰ����
	//! \param		pDatasetRaster դ�����ݼ�ָ��
	//! \return		����һ��FdoRasterPropertyDefinition��ָ��
	static FdoRasterPropertyDefinition* ConvertPhysicalToLogicalRasterProperty(SuperMapConnection* connection, 
		UGC::UGDatasetRaster* pDatasetRaster);

	//! \brief		��ȡ���߼�����Ҫ����������߼��������Եļ���
	//! \return		SuperMapLpPropertyDefinitionCollection* �߼��������Լ��ε�ָ��
    SuperMapLpPropertyDefinitionCollection* GetLpProperties() const;

	//! \brief		��ȡ�߼��������е��������ݼ�
	//! \return		UGC::UGDataset* �������ݼ�ָ�� 
    UGC::UGDataset* GetDataset(void);

	//! \brief		��ȡ�߼��������е��߼���
	//! \return		FdoClassDefinition* �߼����ָ��
    FdoClassDefinition* GetLogicalClass(void);

	//! \brief		���ø��߼�����ģʽ
	//! \param		[in]parent �߼�����ģʽ
    void SetParent (SuperMapLpFeatureSchema* parent);

	//! \brief		����ɾ���߼����������
	//! \param		connection��ǰ��SuperMap����
	void Delete (SuperMapConnection* connection);

	// To please FdoNamedCollection:
    FdoString* GetName();
    virtual FdoBoolean CanSetName() { return true; }

private:
	SuperMapConnection*  m_connection;				// NOTE: weak reference

	// Logical layer:
    FdoPtr<FdoClassDefinition> m_logicalClassDefinition;

	 // LogicalPhysical layer:
    SuperMapLpFeatureSchema*                       m_parentLpSchema; // weak reference
    FdoPtr<SuperMapLpPropertyDefinitionCollection> m_LpProperties;

	// Physical layer:
	UGC::UGDataset* m_pDataset;
};

class SuperMapLpClassDefinitionCollection : public FdoNamedCollection<SuperMapLpClassDefinition, FdoException>
{
public:
	SuperMapLpClassDefinitionCollection(){}

protected:
	virtual ~SuperMapLpClassDefinitionCollection(){}

	virtual void Dispose()
	{
		delete this;
	}
};

#endif // __SUPERMAP_LP_CLASSDEFINITION_H__ 
