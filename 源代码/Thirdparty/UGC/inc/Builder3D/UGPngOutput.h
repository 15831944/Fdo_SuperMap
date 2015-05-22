// UGPngOutput.h: interface for the UGPngOutput class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPNGOUTPUT_H__22587CC6_DCEE_4C06_8353_FB059129ED2C__INCLUDED_)
#define AFX_UGPNGOUTPUT_H__22587CC6_DCEE_4C06_8353_FB059129ED2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGFileStream.h"
#include "png.h"
#include "Base/UGMemoryStream.h"
namespace UGC
{

class BUILDER3D_API UGPngOutput  
{
public:
	UGPngOutput();
	virtual ~UGPngOutput();
	// �����32λpng
	UGbool OutputDirect(UGString strFileName,UGuchar* pData,UGint nWidth,UGint nHeight);
	
private:
	
	UGFileStream m_FilePng;
	png_structp m_pPngStruct;
	png_infop m_pPngInfo;
	png_colorp m_pPngPalette;
	UGbool m_bRead;		//������д��
	UGMemoryStream m_MemoryStream;
	//! \brief �Ƿ���OutputDirect��������SavePngHeader()��������ΪOutputDirect���þ���Ҫ���⴦����RGBA->RGB,����ת���Ͳ���Ҫ��
	UGbool m_bOutputDirect;
private:
	void Close();
	UGbool OpenForWrite(const UGString& strFileName,UGint nWidth,UGint nHeight);
	//! \brief ����Png���ļ�ͷ
	UGbool SavePngHeader(int nWidth,int nHeight);
	 

};
}

#endif // !defined(AFX_UGPNGOUTPUT_H__22587CC6_DCEE_4C06_8353_FB059129ED2C__INCLUDED_)
