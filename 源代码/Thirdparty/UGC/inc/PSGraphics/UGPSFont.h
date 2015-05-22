// UGPSFont.h: interface for the UGPSFont class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPSFONT_H__FE59CBD1_14D1_46FC_9437_F7EBA1B6E52F__INCLUDED_)
#define AFX_UGPSFONT_H__FE59CBD1_14D1_46FC_9437_F7EBA1B6E52F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Graphics/UGFont.h"
namespace UGC
{	
class UGPSFont : public UGFont  
{
public:
	UGPSFont();
	virtual ~UGPSFont();
// ��������
	virtual UGbool Create();
	
	// �������岢�������������(����,��С,��ʽ,�����).	
	virtual UGbool Create(const UGFontData& FontData);
	virtual UGbool Create(const UGString& strName,
					   UGint nHeight = 40, 
					   UGint nWidth = 0,
					   UGint nWeight = 0, 
					   UGint nAngle = 0, 
					   UGbool bBold = false, 
					   UGbool bItalic = false,
					   UGint nItalicAngle = 0,
					   UGbool bUnderline = false, 
					   UGbool bStrikeOut = false,
					   UGbool bHalo = false, 
					   UGbool bShadow = false,
					   UGTextCodec::Charset nCharset = UGTextCodec::GB18030);

	// ɾ������
	virtual void DeleteObject();
protected:
	UGString GetEPSFontName();
private:
	UGbool m_bNeedRelease;	
};
}
#endif // !defined(AFX_UGPSFONT_H__FE59CBD1_14D1_46FC_9437_F7EBA1B6E52F__INCLUDED_)
