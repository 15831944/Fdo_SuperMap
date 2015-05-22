
/*!
    **************************************************************************************
     \file     UGExchangeFileFactory.h
    **************************************************************************************
     \author   ����
     \brief    ����ת��������               
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


#if !defined(AFX_UGEXCHANGEFILEFACTORY_H__E7DB7397_F9F0_4010_AB23_8747F0C75E9F__INCLUDED_)
#define AFX_UGEXCHANGEFILEFACTORY_H__E7DB7397_F9F0_4010_AB23_8747F0C75E9F__INCLUDED_


#include "Base/ugdefs.h"



namespace UGC {

	class UGExchangeVector;
	class UGExchangeRaster;

class DATAEXCHANGE_API UGExchangeFileFactory  
{
public:
	UGExchangeFileFactory();
	~UGExchangeFileFactory();

public:
	////! \brief �������������ļ�
	static UGExchangeVector* CreateExchangeVector(UGint nFileType);

	//! \brief	����դ�񽻻��ļ�
	static UGExchangeRaster* CreateExchangeRaster(UGint nFileType);

	//! \brief	�ͷ�ʸ���ļ�
	static void DestroyExchangeVector(UGExchangeVector* pExchangeVector);

	//! \brief	�ͷ�դ���ļ�
	static void DestroyExchangeRaster(UGExchangeRaster* pExchangeRaster);
};



} //namespace UGC


#endif // !defined(AFX_UGEXCHANGEFILEFACTORY_H__E7DB7397_F9F0_4010_AB23_8747F0C75E9F__INCLUDED_)
