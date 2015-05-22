
/** \file	 SuperMapDeleteCommand.h
*  \author	 ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#ifndef __SUPERMAP_DELETECOMMAND_H__
#define __SUPERMAP_DELETECOMMAND_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapDeleteCommand SuperMapDeleteCommand.h
	\brief ����ִ�д�Ҫ��Դ��ɾ��Ҫ��ʱ��ɾ����������Map 3D��ɾ��ĳһҪ�ز�����ʱ���Զ�ִ�и����е�Execute����
    return Execute����������ɾ��Ҫ�صĸ���
*/

class SuperMapDeleteCommand :
    public FdoCommonFeatureCommand<FdoIDelete, SuperMapConnection>
{
    friend class SuperMapConnection;

private:
    SuperMapDeleteCommand (FdoIConnection *connection);
    virtual ~SuperMapDeleteCommand (void);

public:
    //
    // Prevent the use of the Assignment Operation by defining it and not implementing it.
    // DO NOT IMPLEMENT
    SuperMapDeleteCommand & operator= (const SuperMapDeleteCommand &right);

    //
    // FdoIDelete interface
    //

    /// <summary>Executes the delete command and returns the number of instances
    /// deleted</summary>
    /// <returns>Returns the number of instances deleted.</returns> 
    virtual FdoInt32 Execute ();

    /// <summary> Deleting objects might result in lock conflicts if objects
    /// to be deleted are not exclusively locked for the user attempting to
    /// delete the object. A lock conflict report is generated.
    /// The function GetLockConflicts returns a lock conflict reader that provides
    /// access to the list of lock conflicts that occurred during the execution
    /// of the delete operation.</summary>
    /// <returns>Returns a lock conflict reader.</returns> 
    virtual FdoILockConflictReader* GetLockConflicts ();
};

#endif // __SUPERMAP_DELETECOMMAND_H__

