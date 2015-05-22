
/*!
    **************************************************************************************
     \file     UGExchangeToolkit.h
    **************************************************************************************
     \author   ����
     \brief    ����ת��С������             
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

#if !defined(AFX_UGEXCHANGETOOLKIT_H__257C21F3_D61B_45B9_81B4_5E17F9BFFE2B__INCLUDED_)
#define AFX_UGEXCHANGETOOLKIT_H__257C21F3_D61B_45B9_81B4_5E17F9BFFE2B__INCLUDED_

#include "Algorithm/UGRect2D.h"
#include "Base/ugdefs.h"

namespace UGC {


	class UGDatasetRaster;
	
class UGExchangeToolkit  
{

public:
	UGExchangeToolkit();
	~UGExchangeToolkit();
public:
	//! \brief �ж��Ƿ�Ϊʸ����ʽ
	//! \return ����true��ʾ��ʸ����ʽ; ����false��ʾ��դ���ʽ
	static UGbool IsVector(UGint nFileType);
	//! \brief 	�õ�Ӱ��Ĳ���
	static UGint GetBandCount(UGDatasetRaster *pDatasetRaster, UGint nFileType);

	//! \brief 	�õ�Ӱ�����������
	static UGint GetDataType(UGDatasetRaster *pDatasetRaster, UGint nFileType);

	//! \brief ����һ�¾���
	static void AdjustBound(UGRect2D &rect);
};

} //namespace UGC

#endif // !defined(AFX_UGEXCHANGETOOLKIT_H__257C21F3_D61B_45B9_81B4_5E17F9BFFE2B__INCLUDED_)
