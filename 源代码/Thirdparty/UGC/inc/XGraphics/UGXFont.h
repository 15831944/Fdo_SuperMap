// UGXFont.h: interface for the UGXFont class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGXFONT_H__66E87E99_9568_4A9D_92EC_1EB60B912DC1__INCLUDED_)
#define AFX_UGXFONT_H__66E87E99_9568_4A9D_92EC_1EB60B912DC1__INCLUDED_

#include "Graphics/UGFont.h"
#include "XGraphics/UGFreeTypeLib.h"
#include "Base/UGTextCodec.h"

namespace UGC
{
class UGXGraphics;
class UGPoint;
class XGRAPHICS_API UGXFont : public UGFont  
{
public:
	UGXFont();
	virtual ~UGXFont();

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
			UGbool bOutline = false, 
			UGbool bShadow = false,
			UGTextCodec::Charset nCharset = UGTextCodec::GB18030);
	
	// ɾ������
	virtual void DeleteObject();

	void Draw_Bitmap(UGXGraphics&, void*, UGint, UGint);

	void DrawString(UGXGraphics&, UGint, UGint, const UGString&, UGint, UGint);
	
	//modified by xielin 2007-08-16 ��һ����������Graphics���룬��ҪΪ���������ݻ���
	UGbool GetTextExtent(UGXGraphics&,const UGString&, UGint&, UGint&, UGint&);
	
private:
	static inline UGFreeTypeLib::FaceStyle convertStyle(const UGFontData &);
	void _computeBounds(UGint&, UGint&, FT_Vector&, FT_Vector&, UGint&, UGPoint&, 
		UGPoint&, UGPoint&, UGPoint&,UGint,UGint,UGint nPaintOption,UGint nMaxDxE = 0);
	//! \brief �ж��Ƿ�������ϴεĻ�������
	UGbool IsCanUserCacheFontInfo(UGXGraphics&,const UGString&);
	//! \brief ׼���������ݣ���Ҫ�ǰ�����ͨ��freetype��������������image�����ֵ�λ�õ���Ϣ
	UGbool PreFontInfo(UGXGraphics&,const UGString&);
	
	//deleted by xielin 2007-10-18�������û����
	//UGTextCodec m_TextCodec;
	UGbool m_bImitateBold;
	UGbool m_bImitateItalic;
	UGdouble m_dSin_a;
	UGdouble m_dCos_a;
	void* m_Face;

	UGbool m_bNeedRelease;
	//added by lugw 2007-04-07 �Ƿ���÷�����
	UGbool m_bAnti;

};

}

#endif // !defined(AFX_UGXFONT_H__66E87E99_9568_4A9D_92EC_1EB60B912DC1__INCLUDED_)
