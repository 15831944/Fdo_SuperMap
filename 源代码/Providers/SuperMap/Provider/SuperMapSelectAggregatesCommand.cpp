
/** \file	 SuperMapSelectAggregatesCommand.cpp
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#include "SuperMap.h"

#define m_FeatureReader m_pSelect

//����ֻ��Ϊ�˲����ã��Ժ�ֱ��ɾ�����Ϳ�����
class TestDataReader:public FdoIDataReader
{
public: 
	FdoStringP m_strReaderName;
public:
	TestDataReader(){m_strReaderName=L"";}
	virtual FdoInt32 GetPropertyCount(){return 0;}
	virtual FdoString* GetPropertyName(FdoInt32 index){return NULL;}
	virtual FdoDataType GetDataType(FdoString* propertyName){return FdoDataType_Boolean;}
	virtual FdoPropertyType GetPropertyType(FdoString* propertyName){return FdoPropertyType_DataProperty;}

	virtual bool GetBoolean(FdoString* propertyName){return 0;}
	virtual FdoByte GetByte(FdoString* propertyName){return 0;}
	virtual FdoDateTime GetDateTime(FdoString* propertyName){FdoDateTime Ftime;return Ftime;}
	virtual double GetDouble(FdoString* propertyName){return 0;}
	virtual FdoInt16 GetInt16(FdoString* propertyName){return 0;}
    virtual FdoInt32 GetInt32(FdoString* propertyName){return 0;}
    virtual FdoInt64 GetInt64(FdoString* propertyName){return 0;}
    virtual float GetSingle(FdoString* propertyName){return 0;}
    virtual FdoString* GetString(FdoString* propertyName){return NULL;}
    virtual FdoLOBValue* GetLOB(FdoString* propertyName){return NULL;}
	virtual FdoIStreamReader* GetLOBStreamReader(const wchar_t* propertyName ){return NULL;}
	virtual bool IsNull(FdoString* propertyName){return 0;}
	virtual FdoByteArray* GetGeometry(FdoString* propertyName){return NULL;}
	virtual FdoIRaster* GetRaster(FdoString* propertyName){return NULL;}
	virtual bool ReadNext(){return 0;}
	virtual void Close(){return;}

	virtual void Dispose(){delete this;}

};
//�����ඨ�����


SuperMapSelectAggregatesCommand::SuperMapSelectAggregatesCommand (FdoIConnection *connection) :
    FdoCommonFeatureCommand<FdoISelectAggregates, FdoIConnection> (connection),
    m_bDistinct(false),
    m_eOrderingOption(FdoOrderingOption_Ascending)
{
    m_GroupingIds = FdoIdentifierCollection::Create();
    m_OrderingIds = FdoIdentifierCollection::Create();
    mPropertiesToSelect = FdoIdentifierCollection::Create();

	m_pSelect = new SuperMapSelectCommand( (SuperMapConnection *)connection );
}


/** Do not implement the copy constructor. **/
//ShpSelectAggregatesCommand::ShpSelectAggregatesCommand (const ShpSelectAggregatesCommand &right) { }

SuperMapSelectAggregatesCommand::~SuperMapSelectAggregatesCommand (void)
{
	if(NULL != m_pSelect)
	{
		delete m_pSelect;
	}
}

/// <summary>Gets the FdoIdentifierCollection that holds the list of property names to 
/// return with the result. If empty all properties of the specified class
/// are returned.</summary>
/// <returns>Returns the list of property names.</returns> 
FdoIdentifierCollection* SuperMapSelectAggregatesCommand::GetPropertyNames ()
{
    return (FDO_SAFE_ADDREF(mPropertiesToSelect.p));
}

/// <summary>Executes the select command and returns a reference to an FdoIDataReader.</summary>
/// <returns>Returns the feature reader.</returns> 
FdoIDataReader* SuperMapSelectAggregatesCommand::Execute ()
{
	TRACE(_T("���� SuperMapSelectAggregatesCommand::Execute()... \n"));

	if(mFilter == NULL)
	{
		TRACE(_T("SuperMapSelectAggregatesCommand::��ѯ����Ϊ��... \n"));
	}
	else
	{
		TRACE(_T("SuperMapSelectAggregatesCommand::��ѯ����Ϊ:[%ls]\n"), mFilter->ToString());
	}
	if(mClassName == NULL)
	{
		TRACE(_T("SuperMapSelectAggregatesCommand::Ҫ������Ϊ��... \n"));
	}
	else
	{
		TRACE(_T("SuperMapSelectAggregatesCommand::Ҫ������Ϊ[%ls]... \n"), mClassName->GetName());
	}

	/*
	TRACE(_T("�ο� ShpSelectAggregatesCommand::Execute()... \n"));
	TRACE(_T("1.��������õ�ģʽ����...\n"));
	TRACE(_T("2.�õ�Ҫ���µ�Ҫ��������ʶ�� GetFeatureClassName()---...\n"));
	TRACE(_T("3.������ͨ��Select����...\n"));
	TRACE(_T("4.��Select���ֵҪ�������͹�����mFilter...\n"));
	TRACE(_T("5.�õ�Ҫ���ҵ�������...\n"));
	TRACE(_T("6.����Ҫ���ҵ������еõ����еľۼ�����...\n"));
	TRACE(_T("7.ִ�����ɵ�Select�������Ҫ��Reader...\n"));
	TRACE(_T("8.�ӷ��ص�Ҫ��Reader�Լ��õ��ľۼ����������ʽ�ĺ������߼�Ҫ���ඨ������һ��DataReader...\n"));
	TRACE(_T("9.�������DataReader...\n"));
	TRACE(_T("10.֮���ѯ����Ĵ�ȡ�Ǵ�DataReader�����...\n"));

	*/
	FdoPtr<FdoIdentifierCollection> countprop;

	countprop = GetPropertyNames();
	TRACE(_T("SuperMapSelectAggregatesCommand::���Ը���[%d]... \n"), GetPropertyNames()->GetCount());

	/*for(int i = 0; i< 2; i++)
	{
		FdoPtr<FdoIdentifier> dentity= countprop->GetItem(i);

		TRACE(_T("SuperMapSelectAggregatesCommand::����[%ls]... \n"), dentity->GetName());
	}*/

	if(NULL != m_pSelect)
	{
		m_pSelect->SetFilter(mFilter);
		m_pSelect->SetFeatureClassName(mClassName);
	}
	FdoPtr<FdoIDataReader> ret = new SuperMapDataReader((SuperMapFeatureReader*)m_pSelect->Execute( ));
	return FDO_SAFE_ADDREF(ret.p);
}


/// <summary>Set the distinct option of the selection. Note that grouping criteria is not supported with Distinct. 
/// Non-simple properties such as object properties, geometry properties, raster properties, association properties, etc. will not be supported with Distinct.</summary>
/// <param name="value">true or false; when set to true, only distinct values are returned. Otherwise all values are returned</param> 
/// <returns>Returns nothing</returns>  
void SuperMapSelectAggregatesCommand::SetDistinct( bool value )
{
    m_bDistinct = value;
}

/// <summary>Get the distinct option.</summary>
/// <returns>Returns true if distinct is set, false otherwise.</returns> 
bool SuperMapSelectAggregatesCommand::GetDistinct( )
{
    return m_bDistinct;
}

/// <summary>Gets the FdoIdentifierCollection that holds the list of group by property names. If empty no grouping is used. This list is initially
/// empty and the caller need to add the property that the command should use as a group by criteria. No LOB or Geometry type properties
/// can be used for ordering.</summary>
/// <returns>Returns the list of group by property names.</returns> 
FdoIdentifierCollection* SuperMapSelectAggregatesCommand::GetGrouping()
{
    return FDO_SAFE_ADDREF(m_GroupingIds.p);
}

/// <summary>Set the grouping by filter. Use the grouping filter to restrict the groups of returned properties to those groups for 
/// which the specified filter is TRUE. For example "order by city" and  "min(lanes) = 2". The FdoFilter have to evalute to a 
/// binary value(true or false).</summary>
/// <param name="filter">The grouping filter.</param> 
/// <returns>Returns nothing</returns> 
void SuperMapSelectAggregatesCommand::SetGroupingFilter(FdoFilter* filter)
{
    m_GroupingFilter = FDO_SAFE_ADDREF(filter);
}

/// <summary>Gets the grouping by filter.</summary>
/// <returns>Returns the grouping filter.</returns> 
FdoFilter* SuperMapSelectAggregatesCommand::GetGroupingFilter(void)
{
    return FDO_SAFE_ADDREF(m_GroupingFilter.p);
}

/// <summary>Gets the FdoIdentifierCollection that holds the list of order by property names. If empty no ordering is used. This list is initially
/// empty and the caller need to add the property that the command should use as a order by criteria.</summary>
/// <returns>Returns the list of group by property names.</returns> 
FdoIdentifierCollection* SuperMapSelectAggregatesCommand::GetOrdering(void)
{
    return FDO_SAFE_ADDREF(m_OrderingIds.p);
}

/// <summary>Set the ordering option of the selection. This is only used if the ordering collection is not empty.</summary>
/// <param name="option">Is the ordering option and should be set to one of FdoOrderingOption_Ascending or FdoOrderingOption_Descending.
/// FdoOrderingOption_Ascending is the default value.</param> 
/// <returns>Returns nothing</returns> 
void SuperMapSelectAggregatesCommand::SetOrderingOption(FdoOrderingOption option)
{
    m_eOrderingOption = option;
}

/// <summary>Gets the ordering option.</summary>
/// <returns>Returns the ordering option.</returns> 
FdoOrderingOption SuperMapSelectAggregatesCommand::GetOrderingOption(void)
{
    return m_eOrderingOption;
}