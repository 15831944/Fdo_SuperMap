
/*!
    **************************************************************************************
     \file     UGFileParseFactory.h
    **************************************************************************************
     \author   ����
     \brief    �ļ�����������               
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  ����    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGFILEPARSEFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_)
#define AFX_UGFILEPARSEFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/ugexports.h"

namespace UGC {


	class UGFileParseVector;
	class UGFileParseRaster;


class FILEPARSER_API UGFileParseFactory  
{
public:
	UGFileParseFactory();
	~UGFileParseFactory();


	//! \brief ����ʸ���ļ�������
	static UGFileParseVector* CreateFileVector(UGint nFileType);
	
	//! \brief ����դ���ļ�������
	static UGFileParseRaster* CreateFileRaster(UGint nFileType);


	static void DestroyFileVector(UGFileParseVector* pFileVector);

	static void DestroyFileRaster(UGFileParseRaster* pFileRaster);
};


} //namespace UGC


#endif // !defined(AFX_UGFILEPARSEFACTORY_H__1885519B_9074_4676_8294_31061A9FCB47__INCLUDED_)

