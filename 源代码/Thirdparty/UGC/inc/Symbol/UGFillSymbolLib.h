
/*!
   **************************************************************************************
    \file     UGFillSymbolLib.h
   **************************************************************************************
    \author   �¹���
    \brief    �����ſ��ࡣ                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-23  �¹���    ��ʼ���汾.                                       <br>
   **************************************************************************************
*/

#ifndef UGFILLSYMBOLLIB_H
#define UGFILLSYMBOLLIB_H

#include "UGFillSymbol.h"
#include "UGSymbolLib.h"
#include "UGMarkerSymbolLib.h"

namespace UGC {

class SYMBOL_API UGFillSymbolLib : public UGSymbolLib
{
public:
	UGFillSymbolLib();
	virtual ~UGFillSymbolLib();

public:
	//! \brief �����ȡ
	virtual UGbool Load(UGStream& stream);	
	//! \brief ����׷��
	virtual UGbool Append(UGStream& stream, UGbool bReplace = true);
	//! \brief ���Ᵽ��
	virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

	//! \brief �������ӷ���
	UGbool Add(const UGString& strRasterFile, UGSymbolGroup *pSymbolGroup = NULL);
	//! \brief �������ù����ĵ���ſ�
	void SetResMarkerSymLib(UGMarkerSymbolLib* pResMarkerSymLib);

	//! \brief �����ȡ�����ĵ���ſ�
	UGMarkerSymbolLib* GetResMarkerSymLib() const;
	//! \brief �����ȡ�����ĵ���ſ�
	UGMarkerSymbolLib* GetMarkerSymLib();

protected:
	UGMarkerSymbolLib* m_pResMarkerSymLib;
	UGMarkerSymbolLib m_MarkerSymLib;
};

}

#endif


