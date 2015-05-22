/** \file	 SuperMapCreateDataStoreCommand.h
*  \brief    ������ҪΪʵ��FDO��FdoICreateDataStore�ӿڣ���ɴ���SDB����Դ�Ĺ���
*  \author	 ����
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-1-23
*/  

#ifndef __SUPERMAP_CREATEDATASTORECOMMAND_H__
#define __SUPERMAP_CREATEDATASTORECOMMAND_H__

#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapCreateDataStoreCommand : public FdoCommonCommand<FdoICreateDataStore, SuperMapConnection>
{
	friend class SuperMapConnection;

protected:
	SuperMapCreateDataStoreCommand(SuperMapConnection* connection);

public:

    ///<summary>Gets the FdoIDataStorePropertyDictionary interface that    
    ///can be used to dynamically query    and    set    the    properties required    
    ///to create a new datastore.</summary>
    ///    <returns>Returns the property dictionary</returns>
    virtual FdoIDataStorePropertyDictionary* GetDataStoreProperties() 
    { 
        return (FdoIDataStorePropertyDictionary *)(FDO_SAFE_ADDREF(m_dataStorePropertyDictionary.p));
    }

    ///    <summary>Executes the FdoICreateDataStore command.</summary>
    ///    <returns>Returns nothing</returns> 
    virtual void Execute(); 

protected:
    /**
     * The dictionary of connection parameters.
     */
    FdoPtr<FdoCommonDataStorePropDictionary> m_dataStorePropertyDictionary;

};

#endif // __SUPERMAP_CREATEDATASTORECOMMAND_H__