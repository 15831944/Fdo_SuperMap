#ifndef UGTEXTCODEC_H
#define UGTEXTCODEC_H

#include "ugdefs.h"
#include "UGString.h"

namespace UGC {

//! �ַ���ת����, �ڲ�����iconvʵ��
class BASE_API UGTextCodec  
{
public:
	enum Charset
	{
		ANSI = 0,
		Default = 1,
		Symbol = 2,
		MAC = 77,
		ShiftJIS = 128,
		Hangeul = 129,
		Johab	= 130,
		//! GB2312 ������ĵļ��������ַ���, ��GBK����GB2312�������չ,�����˺ܶ����ĺͷ�������
		//! GB18030�������µĹ��ұ�׼,��������GB2312��GBK�Ⱥܶ�����, ���,����ͳһ��GB18030�������й�(��½)���ַ���
		GB18030 = 134, 
		//GB2312 = 134, 
		//! Big5��̨�弸��5��������˾������ķ����ַ���, ���ڵ�ʱ���й�(��½)û�й�ͨ��Э��, ����Big5��GB�ǲ����ݵ�,
		//! ������¼�������нϴ���, �ұ����в����ص�, ��˼����ϵͳ���޷��Զ�ʶ�� ĳ�������� GB ���� Big5��.
		//! ��ۺͰ������ڷ����֣����Ҳ����Big5��ͬʱ��������������Ӱ��ϴ�, ��˺ܶ���������Ҳ����Ҫ��Big5����ʹ�ã�
		//! ��������Big5�����������չ, �����е�Ϊ BIG5-HKSCS:2001. ������ǲ���|BIG5-HKSCS:2001".
		ChineseBIG5 = 136, // ��ͬ��BIG5-HKSCS:2001
		Greek = 161,
		Turkish = 162,
		Vietnamese = 163,
		Hebrew = 177,
		Arabic = 178,
		Baltic = 186,		
		Russian = 204,
		Thai = 222,
		EastEurope = 238,
		//! ���ϸ�������˵, UTF8,����UCS2,UCS4�ȶ������ַ���,��ֻ��Unicode��һ�ֱ��뷽ʽ, 
		//! �������⼸��ʹ�ý�ΪƵ��, �Ҽ�����Ĵ����Ϻ������ַ����Ƚ�����, ���,��ͳһ����������.
		UTF8 = 250,
		UCS2LE = 251,//WindowsĬ�ϵ�Unicode����	
		UCS2BE = 252,
		UCS4LE = 253,
		UCS4BE = 254,
		OEM = 255
		//�����ΪWindowsϵͳ�ַ�����
		/* Ŀǰ���ܴ洢��ô����ַ������ַ�����Χ 0~255
		UTF8 = 65536,
		UCS2LE = 65537,//WindowsĬ�ϵ�Unicode����	
		UCS2BE = 65538,
		UCS4LE = 65539,
		UCS4BE = 65540
		*/
	};

public:
	UGTextCodec();
	~UGTextCodec();
	UGTextCodec(const UGString& to, const UGString& from);
	UGTextCodec(Charset to, Charset from);

public:
	static UGString GetCharsetName(Charset charset);
	static Charset GetCharset(const UGString &strCharsetName);
	

public:
	// modified by jifang, 07/29/2005.
	//!\remarks ����������õ�ʱ��, ��ϵͳ��ص�, Ҫ��ϵͳ��֧�ֵı���֮���ת��. 
	//!\remarks ����ֱ��ָ���ַ��������׵��´�ʧ��, ������������ö�ٲ����ĺ���, 
	//!\remarks �;�������������غ���, ʵ�ڲ��е�, ��ֱ�����������. 
	//!\remarks ��֮һ�仰, ʹ��ʱҪС��, ����ҽ��, ���������˲�����!
	UGbool Open(const UGString& to, const UGString& from);
	
	UGbool Open(Charset to, Charset from);

	UGbool IsOpen();
	void Close();	

	//! ���� pSource �� nSize(���ֽڼ�)��
	//! ��target����ת������ַ���
	//! remark ������������ת������ַ�������MBCS�����ֽڱ��룩
	UGbool Convert(UGString& target,const UGString& source);
	UGbool Convert(UGString& target, const UGchar* pSource, UGint nSize);

	// by zengzm 2007-11-21 �⼸������ ������(static ����), �ȷ�����
	//static UGTextCodec& UGTOMBCS(Charset charset);
	//static UGTextCodec& UGTOUCS(Charset charset);
	//!\remarks if bDirction == TRUE convert the Unicode to MBCS and vice versa
	//static UGTextCodec& GetDefault(UGbool bDirection = TRUE);

	// by zengzm 2007-11-21 ��������,���� TextCodec��Open 100��ε�ʱ����2������,
	// Ч�ʻ�������, ���,��ʱ������������Ż�; �Ժ�˭�������������ƿ��,������Դ���

	//! �õ�ĳ���ַ���ת��Ϊ UCS2LE�� ת����
	//! \param charset �ַ�������
	//! \remarks �ڲ����÷����ض���̬����ķ�ʽ, ���Ч��
	//! \return ����ת����
//	static UGTextCodec& ToUCS2LE(Charset charset);

	//! �ð�UCS2LE ת��Ϊ ĳ���ַ����� ת����
	//! \param charset �ַ�������
	//! \remarks �ڲ����÷����ض���̬����ķ�ʽ, ���Ч��
	//! \return ����ת����
//	static UGTextCodec& ToUCS2LE(Charset charset);

private:
	void* m_pHandle;
	// ��������,����iconvӦ��֧�ֶ��߳�, ��˰�buffer�ŵ������ڲ�, �Ա�TextcodecҲ��֧�ֶ��߳�
	// UGString m_strBuffer;
};

}

#endif

/* iconv����ҳ˵��
European languages 
	ASCII, ISO-8859-{1,2,3,4,5,7,9,10,13,14,15,16}, KOI8-R, KOI8-U, KOI8-RU, CP{1250,1251,1252,1253,1254,1257}, CP
	{850,866}, Mac{Roman,CentralEurope,Iceland,Croatian,Romania}, Mac{Cyrillic,Ukraine,Greek,Turkish}, Macintosh 
Semitic languages 
	ISO-8859-{6,8}, CP{1255,1256}, CP862, Mac{Hebrew,Arabic} 
Japanese 
	EUC-JP, SHIFT_JIS, CP932, ISO-2022-JP, ISO-2022-JP-2, ISO-2022-JP-1 
Chinese 
	EUC-CN, HZ, GBK, CP936, GB18030, EUC-TW, BIG5, CP950, BIG5-HKSCS, BIG5-HKSCS:2001, BIG5-HKSCS:1999, ISO-2022-CN, 
	ISO-2022-CN-EXT 
Korean 
	EUC-KR, CP949, ISO-2022-KR, JOHAB 
Armenian 
	ARMSCII-8 
Georgian 
	Georgian-Academy, Georgian-PS 
Tajik 
	KOI8-T 
Kazakh 
	PT154 
Thai 
	ISO-8859-11, TIS-620, CP874, MacThai 
Laotian 
	MuleLao-1, CP1133 
Vietnamese 
	VISCII, TCVN, CP1258 
Platform specifics 
	HP-ROMAN8, NEXTSTEP 
Full Unicode 
	UTF-8 
	UCS-2, UCS-2BE, UCS-2LE 
	UCS-4, UCS-4BE, UCS-4LE 
	UTF-16, UTF-16BE, UTF-16LE 
	UTF-32, UTF-32BE, UTF-32LE 
	UTF-7 
	C99, JAVA 
Full Unicode, in terms of uint16_t or uint32_t (with machine dependent endianness and alignment) 
	UCS-2-INTERNAL, UCS-4-INTERNAL 
Locale dependent, in terms of `char' or `wchar_t' (with machine dependent endianness and alignment, and with OS and 
locale dependent semantics) 
	char, wchar_t 
	The empty encoding name "" is equivalent to "char": it denotes the locale dependent character encoding. 

When configured with the option --enable-extra-encodings, it also provides support for a few extra encodings: 
European languages 
	CP{437,737,775,852,853,855,857,858,860,861,863,865,869,1125} 
Semitic languages 
	CP864 
Japanese 
	EUC-JISX0213, Shift_JISX0213, ISO-2022-JP-3 
Chinese 
	BIG5-2003 (experimental) 
Turkmen 
	TDS565 
Platform specifics 
	ATARIST, RISCOS-LATIN1 

It can convert from any of these encodings to any other, through Unicode conversion. 
It has also some limited support for transliteration, i.e. when a character cannot be represented in the target 
character set, it can be approximated through one or several similarly looking characters. Transliteration is 
activated when "//TRANSLIT" is appended to the target encoding name. 

libiconv is for you if your application needs to support multiple character encodings, but that support lacks from 
your system. 
*/
