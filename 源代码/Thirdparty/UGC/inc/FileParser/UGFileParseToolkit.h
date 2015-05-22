
/*!
    **************************************************************************************
     \file     UGFileParseToolkit.h
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


#if !defined(AFX_UGFILEPARSETOOLKIT_H__AAED9863_4B12_4F48_8406_F32E3EB0CF52__INCLUDED_)
#define AFX_UGFILEPARSETOOLKIT_H__AAED9863_4B12_4F48_8406_F32E3EB0CF52__INCLUDED_

#include "Geometry/UGImgScanline.h"
#include "Base/UGString.h"
#include "Base/UGFileStream.h"
namespace UGC {

class FILEPARSER_API UGFileParseToolkit  
{
public:
	UGFileParseToolkit();
	~UGFileParseToolkit();
public:



	//! \brief 		�������ظ�ʽ���ص�ɫ��ĸ���
	//! \return 	UGint
	//! \param 		ePixelFormat
	//! \remark		
	static UGint GetColorCount(PixelFormat ePixelFormat);

	//! \brief 		������ɫ�ĸ������õ����ظ�ʽ
	//! \return 	PixelFormat �������صĸ�ʽ
	//! \param 		nColorEntryCount  ������ɫ�ĸ���
	//! \remarks 	ֻ�е�ɫ���ʹ����Ч	
	static PixelFormat GetPixelFormat(UGint nColorEntryCount);



	//! \brief 		����BitCount���õ����ظ�ʽ
	//! \return 	PixelFormat �������ظ�ʽ
	//! \param 		nBitCount  
	//! \remarks 		
	static PixelFormat Bit2Format(UGint nBitCount);
	
	//! \brief 		�õ�ɨ���е��ֽڸ���
	//! \return 	UGint
	//! \param 		ePixelFormat ���صĸ�ʽ
	//! \param 		nWidth       һ�����صĸ���
	//! \remarks 		
	static UGint GetWidthBytes(PixelFormat ePixelFormat, UGint nWidth);


	//! \brief 		��strReadData�ֽ��nPartCount���֣��洢��pStrInfos�������pStrInfosӦ�����ⲿ���úÿռ�
	//! \return 	UGbool ����ֵ: True- ��һ�е�ʵ��part count >=nPartCount; ���򷵻�false
	//! \param 		&strReadData  �ַ�������
	//! \param 		*pStrInfos  �洢��pStrInfos������� pStrInfosӦ�����ⲿ���úÿռ䡣
	//! \param 		nPartCount  ����ֵ: True- ��һ�е�ʵ��part count >=nPartCount; ���򷵻�false
	//! \param 		&strDelimiter="  strDelimiter�ָ�����Ĭ��Ϊ ���ţ�ASCII,��
	//! \remarks 		
	static UGbool SplitOneRow(UGString &strReadData, 
							UGString *pStrInfos, UGint nPartCount, 
							const UGString &strDelimiter=","); 

	static UGString GetExtNameByFileType(UGint nFileType);

};

} // namespace UGC

#endif // !defined(AFX_UGFILEPARSETOOLKIT_H__AAED9863_4B12_4F48_8406_F32E3EB0CF52__INCLUDED_)
