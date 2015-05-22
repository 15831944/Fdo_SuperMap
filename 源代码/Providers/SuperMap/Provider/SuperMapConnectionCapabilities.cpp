/** \file	 SuperMapConnectionCapabilities.cpp
 *  \author	 ����
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */


#include "SuperMap.h"

SuperMapConnectionCapabilities::SuperMapConnectionCapabilities ()
{

}

SuperMapConnectionCapabilities::~SuperMapConnectionCapabilities ()
{

}

void SuperMapConnectionCapabilities::Dispose()
{
    delete this;
}

/// <summary>Gets an FdoThreadCapability value that declares the feature provider's level of thread safety.</summary>
/// <returns>Returns the connection thread capability.</returns> 
FdoThreadCapability SuperMapConnectionCapabilities::GetThreadCapability ()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::GetThreadCapability()... \n"));
	// �����ṩ��֧�ֵ��߳�����
    return (FdoThreadCapability_SingleThreaded);
	//return (FdoThreadCapability_PerConnectionThreaded);
}

/// <summary>Gets the spatial context extent types supported by the feature provider.</summary>
/// <param name="length">Output the number of spatial context types.</param> 
/// <returns>Returns the list of spatial context extent types.</returns> 
FdoSpatialContextExtentType* SuperMapConnectionCapabilities::GetSpatialContextTypes (FdoInt32& length)
{
	TRACE(_T("���� SuperMapConnectionCapabilities::GetSpatialContextTypes()... \n"));
    static FdoSpatialContextExtentType types[] =
    {
        FdoSpatialContextExtentType_Static
    };

    length = sizeof(types) / sizeof(FdoSpatialContextExtentType);

    return (types);
}

/// <summary>Determines if the feature provider supports persistent locking.</summary>
/// <returns>Returns true if the feature provider supports persistent locking.</returns> 
bool SuperMapConnectionCapabilities::SupportsLocking ()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::SupportsLocking()... \n"));
    return (false);
}

/// <summary>Gets an array of the FdoLockType values supported by the feature provider.</summary>
/// <param name="size">Output the number of lock types.</param>
/// <returns>Returns the list of lock types.</returns> 
FdoLockType* SuperMapConnectionCapabilities::GetLockTypes(FdoInt32& size)
{
	TRACE(_T("���� SuperMapConnectionCapabilities::GetLockTypes()... \n"));
    size = 0;
    return ((FdoLockType*)NULL);
}

/// <summary>Determines if the feature provider supports connection timeout.</summary>
/// <returns>Returns true if the feature provider supports connection timeout.</returns> 
bool SuperMapConnectionCapabilities::SupportsTimeout ()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::SupportsTimeout()... \n"));
    return (false);
}

/// <summary>Determines if the feature provider supports transactions.</summary>
/// <returns>Returns true if the feature provider supports transactions.</returns> 
bool SuperMapConnectionCapabilities::SupportsTransactions ()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::SupportsTransactions()... \n"));
	// TODO::��һ���о�
    return (false); ////  ��ʱ�޸�Ϊ��֧�� by zhouxu 2008-6-2
}

/// <summary>Determines true if the feature provider supports long transactions.</summary>
/// <returns>Returns true if the feature provider supports long transactions.</returns> 
bool SuperMapConnectionCapabilities::SupportsLongTransactions ()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::SupportsLongTransactions()... \n"));
    return (false);
}

/// <summary>Determines if the feature provider supports SQL commands.</summary>
/// <returns>Returns true if the feature provider supports SQL commands.</returns> 
bool SuperMapConnectionCapabilities::SupportsSQL()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::SupportsSQL()... \n"));
    return (false);
}

/// <summary>Determines if the feature provider supports XML configuration.</summary>
/// <returns>Returns true if the feature provider supports the setting of a configuration.</returns> 
bool SuperMapConnectionCapabilities::SupportsConfiguration()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::SupportsConfiguration()... \n"));
	return (false);//
 }

/// <summary>Determines if the provider supports multiple spatial contexts.</summary>
/// <returns>Returns true if the provider supports multiple spatial contexts.</returns> 
bool SuperMapConnectionCapabilities::SupportsMultipleSpatialContexts()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::SupportsMultipleSpatialContexts()... \n"));
    return (true);
}

/// <summary>Determines if the provider supports specifying the coordinate system by name
/// or ID without specifying the WKT when creating a new spatial context.</summary>
/// <returns>Returns true if the provider supports specifying the coordinate system by name
/// or ID without specifying the WKT when creating a new spatial context.</returns> 
bool SuperMapConnectionCapabilities::SupportsCSysWKTFromCSysName()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::SupportsCSysWKTFromCSysName()... \n"));
    return (false);
}

bool SuperMapConnectionCapabilities::SupportsWrite()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::SupportsWrite()... \n"));
    return true;
}

bool SuperMapConnectionCapabilities::SupportsMultiUserWrite()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::SupportsMultiUserWrite()... \n"));
    return false; //Todo�� ��������ݿ������֧�ֶ��û�д sdb�Ͳ�֧��
}

bool SuperMapConnectionCapabilities::SupportsFlush()
{
	TRACE(_T("���� SuperMapConnectionCapabilities::SupportsFlush()... \n"));
	return true; //Todo�� �Ƿ�֧�ֻ��庯��
}
