
/** \file	 SuperMapUpdateCommand.h
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#ifndef __SUPERMAP_UPDATECOMMAND_H__
#define __SUPERMAP_UPDATECOMMAND_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapUpdateCommand SuperMapUpdateCommand.h
	\brief ����ִ��Ҫ����ĸ��²�������Map 3D�м��Ҫ�ؽ����޸ĺ��ټ���ʱ�Զ����ø����е�Execute����
    return Execute�������ظ���Ҫ�صĸ���
*/

class SuperMapUpdateCommand :
    public FdoCommonFeatureCommand<FdoIUpdate, SuperMapConnection>
{
    typedef FdoCommonFeatureCommand<FdoIUpdate, SuperMapConnection> superclass;

    friend class SuperMapConnection;

private:
    SuperMapUpdateCommand (FdoIConnection *connection);
    virtual ~SuperMapUpdateCommand (void);

public:
    //
    // Prevent the use of the Assignment Operation by definning it and not implemeting it.
    // DO NOT IMPLEMENT
    SuperMapUpdateCommand & operator= (const SuperMapUpdateCommand &right);

    //
    // FdoIUpdate interface
    //

    /// <summary>Gets the FdoPropertyValueCollection that specifies the names and values of the 
    /// properties to be updated.</summary>
    /// <returns>Returns the list of properties and their values.</returns> 
    virtual FdoPropertyValueCollection* GetPropertyValues ();

    /// <summary>Executes the update command and returns the number of modified 
    /// instances.</summary>
    /// <returns>Returns the number of features updated.</returns> 
    virtual FdoInt32 Execute ();

    /// <summary> Updating objects might result in lock conflicts if objects
    /// to be updated are not exclusively locked for the user attempting to
    /// update the object. If objects to be updated are not exclusively locked for the 
    /// user attempting to update the object, a lock conflict report is generated.
    /// The function GetLockConflicts returns a lock conflict reader providing
    /// access to the list of lock conflicts that occurred during the execution
    /// of the update operation.</summary>
    /// <returns>Returns a lock conflict reader.</returns> 
    virtual FdoILockConflictReader* GetLockConflicts ();
};

#endif // __SUPERMAP_UPDATECOMMAND_H__