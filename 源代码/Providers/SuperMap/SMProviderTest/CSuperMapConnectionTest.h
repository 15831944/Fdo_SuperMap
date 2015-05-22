
/** \file	 CSuperMapConnectionTest.h
*  \brief    �����SuperMapConnection����е�Ԫ����
*  \author	 �� ��
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-17
*  \note :
*/

#ifndef __SUPERMAP_CONNECTION_TEST_H__
#define __SUPERMAP_CONNECTION_TEST_H__

#include "cppunit/extensions/HelperMacros.h"

class FdoIConnection;
template <class T> class FdoPtr;

class CSuperMapConnectionTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(CSuperMapConnectionTest);
	//CPPUNIT_TEST(connect);
	//CPPUNIT_TEST(cnnect2);
	//CPPUNIT_TEST(connect3);
	//CPPUNIT_TEST(testSetConnectionString);
	//CPPUNIT_TEST(testOpen);

	//from 2007-12-17
	CPPUNIT_TEST(testConnect);
	CPPUNIT_TEST(testSetConnectionString);

	CPPUNIT_TEST_SUITE_END();

	static FdoPtr<FdoIConnection> m_connection;

public:
	CSuperMapConnectionTest();
	virtual ~CSuperMapConnectionTest();
	void setUp();
	void tearDown();

public:
	//�������ӵ�״̬���ü��򿪲����Ƿ�����
	//void connect();
	//�������ӵ�״̬���ü��رղ����Ƿ�����
	//void connect2();
	//����ͨ�����������������Դ�����߼�ģʽ�Ƿ���ȷ��
	//void connect3();

	// �ص㺯������
	//void testSetConnectionString();
	//void testOpen();

	//from 2007-12-17
	// ��������Ļ������ܽ��в���
	void testConnect();

	/// <summary>Sets the connection string used to open a DataStore. SetConnectionString can only be set while the
	/// connection is closed.</summary>
	/// <param name="value">Input the connection string</param> 
	/// <returns>Returns nothing</returns> 
	/// void SetConnectionString (FdoString* value);
    void testSetConnectionString();
	

protected:
	// ��ȡSuperMapProvider������
	FdoIConnection* GetSuperMapConnection(); 
	

};

#endif //__SUPERMAP_CONNECTION_TEST_H__
