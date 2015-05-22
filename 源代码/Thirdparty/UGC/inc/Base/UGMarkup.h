#ifndef UGMARKUP_H
#define UGMARKUP_H

#include "ugdefs.h"
#include "ugplatform.h"

namespace UGC {

#ifdef DEBUG
#define _DS(i) (i?&(m_strDoc.c_str())[m_aPos[i].nStartL]:0)
#define MARKUP_SETDEBUGSTATE m_pMainDS=_DS(m_iPos); m_pChildDS=_DS(m_iPosChild)
#else
#define MARKUP_SETDEBUGSTATE
#endif

//! \brief XML������
//! \remarks ���������ص�һ����, ԭ��ΪUGMarkup; ��ϸ�Ĺ���ʹ��˵����ο�����ע��˵��. 
//! UGMarkup�ǻ��ڡ�ѹ�����ĵ�����ģ��(EDOM �� "Encapsulated" Document Object Model,)��
//!	���������XML�������Ĺؼ�������һ��XML�������Ͳ�����Ч����DOM(Document Object Model)
//!	��һ���ġ���������DOM�������Ķ������ͣ���EDOMֻ������һ������XML�ĵ���EDOM�ص���XMLԭʼ������������. 
//! Markup ��װ��XML�ĵ��ı����ṹ�͵�ǰλ�á����ṩ������Ԫ�ء������͵õ�Ԫ�����Ժ����ݵ����з�����
//! ���ĵ��в�����ִ�еĵط�ȡ���ڵ�ǰλ�ú͵�ǰ��λ�á���ǰλ������������һ��Ԫ�ص��ĵ��е����λ�ã�
//! ������Ҫ��ȷָ�����Ӷ����ĵ�������ϣ���Markup����Ч���������
//! ����һֱ������һ�����������ĵ����ַ������������GetDoc.���Եõ���.
class BASE_API UGMarkup
{
public:
	UGMarkup() { SetDoc( NULL ); m_nFlags=0; };
	UGMarkup( const char* szDoc ) { SetDoc( szDoc ); };
	UGMarkup( const UGMarkup& markup ) { *this = markup; };
	void operator=( const UGMarkup& markup );
	virtual ~UGMarkup() {};

	// Navigate
	UGbool Load( const char* szFileName );
	UGbool SetDoc( const char* szDoc );
	UGbool IsWellFormed();
	UGbool FindElem( const char* szName=NULL );
	UGbool FindChildElem( const char* szName=NULL );
	UGbool IntoElem();
	UGbool OutOfElem();
	void ResetChildPos() { x_SetPos(m_iPosParent,m_iPos,0); };
	void ResetMainPos() { x_SetPos(m_iPosParent,0,0); };
	void ResetPos() { x_SetPos(0,0,0); };
	std::string GetTagName() const;
	std::string GetChildTagName() const { return x_GetTagName(m_iPosChild); };
	std::string GetData() const { return x_GetData(m_iPos); };
	std::string GetChildData() const { return x_GetData(m_iPosChild); };
	std::string GetAttrib( const char* szAttrib ) const { return x_GetAttrib(m_iPos,szAttrib); };
	std::string GetChildAttrib( const char* szAttrib ) const { return x_GetAttrib(m_iPosChild,szAttrib); };
	std::string GetAttribName( int n ) const;
	UGbool SavePos( const char* szPosName="" );
	UGbool RestorePos( const char* szPosName="" );
	const std::string& GetError() const { return m_strError; };

	enum MarkupNodeType
	{
		MNT_ELEMENT					= 1,  // 0x01
		MNT_TEXT					= 2,  // 0x02
		MNT_WHITESPACE				= 4,  // 0x04
		MNT_CDATA_SECTION			= 8,  // 0x08
		MNT_PROCESSING_INSTRUCTION	= 16, // 0x10
		MNT_COMMENT					= 32, // 0x20
		MNT_DOCUMENT_TYPE			= 64, // 0x40
		MNT_EXCLUDE_WHITESPACE		= 123// 0x7b
	};

	// Create
	UGbool Save( const char* szFileName );
	const std::string& GetDoc() const { return m_strDoc; };
	UGbool AddElem( const char* szName, const char* szData=NULL ) { return x_AddElem(szName,szData,false,false); };
	UGbool InsertElem( const char* szName, const char* szData=NULL ) { return x_AddElem(szName,szData,true,false); };
	UGbool AddChildElem( const char* szName, const char* szData=NULL ) { return x_AddElem(szName,szData,false,true); };
	UGbool InsertChildElem( const char* szName, const char* szData=NULL ) { return x_AddElem(szName,szData,true,true); };
	UGbool AddAttrib( const char* szAttrib, const char* szValue ) { return x_SetAttrib(m_iPos,szAttrib,szValue); };
	UGbool AddChildAttrib( const char* szAttrib, const char* szValue ) { return x_SetAttrib(m_iPosChild,szAttrib,szValue); };
	UGbool AddAttrib( const char* szAttrib, int nValue ) { return x_SetAttrib(m_iPos,szAttrib,nValue); };
	UGbool AddChildAttrib( const char* szAttrib, int nValue ) { return x_SetAttrib(m_iPosChild,szAttrib,nValue); };
	UGbool AddSubDoc( const char* szSubDoc ) { return x_AddSubDoc(szSubDoc,false,false); };
	UGbool InsertSubDoc( const char* szSubDoc ) { return x_AddSubDoc(szSubDoc,true,false); };
	std::string GetSubDoc() const { return x_GetSubDoc(m_iPos); };
	UGbool AddChildSubDoc( const char* szSubDoc ) { return x_AddSubDoc(szSubDoc,false,true); };
	UGbool InsertChildSubDoc( const char* szSubDoc ) { return x_AddSubDoc(szSubDoc,true,true); };
	std::string GetChildSubDoc() const { return x_GetSubDoc(m_iPosChild); };

	// Modify
	UGbool RemoveElem();
	UGbool RemoveChildElem();
	UGbool SetAttrib( const char* szAttrib, const char* szValue ) { return x_SetAttrib(m_iPos,szAttrib,szValue); };
	UGbool SetChildAttrib( const char* szAttrib, const char* szValue ) { return x_SetAttrib(m_iPosChild,szAttrib,szValue); };
	UGbool SetAttrib( const char* szAttrib, int nValue ) { return x_SetAttrib(m_iPos,szAttrib,nValue); };
	UGbool SetChildAttrib( const char* szAttrib, int nValue ) { return x_SetAttrib(m_iPosChild,szAttrib,nValue); };
	UGbool SetData( const char* szData, int nCDATA=0 ) { return x_SetData(m_iPos,szData,nCDATA); };
	UGbool SetChildData( const char* szData, int nCDATA=0 ) { return x_SetData(m_iPosChild,szData,nCDATA); };


protected:

#ifdef DEBUG
	const char* m_pMainDS;
	const char* m_pChildDS;
#endif

	std::string m_strDoc;
	std::string m_strError;
	int m_nFlags;

	struct ElemPos
	{
		ElemPos() { Clear(); };
		ElemPos( const ElemPos& pos ) { *this = pos; };
		UGbool IsEmptyElement() const { return (nStartR == nEndL + 1); };
		void Clear() { memset( this, 0, sizeof(ElemPos) ); };
		void AdjustStart( int n ) { nStartL+=n; nStartR+=n; };
		void AdjustEnd( int n ) { nEndL+=n; nEndR+=n; };
		int nStartL;
		int nStartR;
		int nEndL;
		int nEndR;
		int nReserved;
		int iElemParent;
		int iElemChild;
		int iElemNext;
	};

	int m_iPosParent;
	int m_iPos;
	int m_iPosChild;
	int m_iPosFree;
	int m_nNodeType;

	struct TokenPos
	{
		TokenPos( const char* sz ) { Clear(); szDoc = sz; };
		void Clear() { nL=0; nR=-1; nNext=0; bIsString=false; };
		UGbool Match( const char* szName )
		{
			int nLen = nR - nL + 1;
		// To ignore case, define MARKUP_IGNORECASE
		#ifdef MARKUP_IGNORECASE
			return ( (strnicmp( &szDoc[nL], szName, nLen ) == 0)
		#else
			return ( (strncmp( &szDoc[nL], szName, nLen ) == 0)
		#endif
				&& ( szName[nLen] == '\0' || strchr(" =/[",szName[nLen]) ) );
		};
		int nL;
		int nR;
		int nNext;
		const char* szDoc;
		UGbool bIsString;
	};

	struct SavedPos
	{
		int iPosParent;
		int iPos;
		int iPosChild;
	};
	typedef std::map<std::string,SavedPos> mapSavedPosT;
	mapSavedPosT m_mapSavedPos;

	void x_SetPos( int iPosParent, int iPos, int iPosChild )
	{
		m_iPosParent = iPosParent;
		m_iPos = iPos;
		m_iPosChild = iPosChild;
		m_nNodeType = iPos?MNT_ELEMENT:0;
		MARKUP_SETDEBUGSTATE;
	};

	struct PosArray
	{
		PosArray() { Clear(); };
		~PosArray() { Release(); };
		enum { PA_SEGBITS = 16, PA_SEGMASK = 0xffff };
		void RemoveAll() { Release(); Clear(); };
		void Release() { for (int n=0;n<SegsUsed();++n) delete[] (char*)pSegs[n]; if (pSegs) delete[] (char*)pSegs; };
		void Clear() { nSegs=0; nSize=0; pSegs=NULL; };
		int GetSize() const { return nSize; };
		int SegsUsed() const { return ((nSize-1)>>PA_SEGBITS) + 1; };
		ElemPos& operator[](int n) const { return pSegs[n>>PA_SEGBITS][n&PA_SEGMASK]; };
		ElemPos** pSegs;
		int nSize;
		int nSegs;
	};
	PosArray m_aPos;

	int x_GetFreePos() { if (m_iPosFree==m_aPos.GetSize()) x_AllocPosArray(); return m_iPosFree++; };
	int x_ReleasePos() { --m_iPosFree; return 0; };
	UGbool x_AllocPosArray( int nNewSize = 0 );
	UGbool x_ParseDoc();
	int x_ParseElem( int iPos );
	int x_ParseError( const char* szError, const char* szName = NULL );
	static UGbool x_FindChar( const char* szDoc, int& nChar, char c );
	static UGbool x_FindAny( const char* szDoc, int& nChar );
	static UGbool x_FindToken( TokenPos& token );
	std::string x_GetToken( const TokenPos& token ) const;
	int x_FindElem( int iPosParent, int iPos, const char* szPath );
	std::string x_GetTagName( int iPos ) const;
	std::string x_GetData( int iPos ) const;
	std::string x_GetAttrib( int iPos, const char* szAttrib ) const;
	UGbool x_AddElem( const char* szName, const char* szValue, UGbool bInsert, UGbool bAddChild );
	std::string x_GetSubDoc( int iPos ) const;
	UGbool x_AddSubDoc( const char* szSubDoc, UGbool bInsert, UGbool bAddChild );
	UGbool x_FindAttrib( TokenPos& token, const char* szAttrib=NULL ) const;
	UGbool x_SetAttrib( int iPos, const char* szAttrib, const char* szValue );
	UGbool x_SetAttrib( int iPos, const char* szAttrib, int nValue );
	UGbool x_CreateNode( std::string& strNode, int nNodeType, const char* szText );
	void x_LocateNew( int iPosParent, int& iPosRel, int& nOffset, int nLength, int nFlags );
	int x_ParseNode( TokenPos& token );
	UGbool x_SetData( int iPos, const char* szData, int nCDATA );
	int x_RemoveElem( int iPos );
	void x_DocChange( int nLeft, int nReplace, const std::string& strInsert );
	void x_PosInsert( int iPos, int nInsertLength );
	void x_Adjust( int iPos, int nShift, UGbool bAfterPos = false );
	std::string x_TextToDoc( const char* szText, UGbool bAttrib = false ) const;
	std::string x_TextFromDoc( int nLeft, int nRight ) const;
};

}

#endif

/** Markup ����Ҫ����ʹ��˵��:
1, ����һ��XML�ĵ�
���ڴ���һ��XML�ĵ�����Ҫʵ����һ��UGMarkup���󣬲�����AddElem������Ԫ�ء�
�����λ�ã��������� AddElem("ORDER") ������ĵ���򵥵�װһ����ORDERԪ��<ORDER/>. 
Ȼ�����AddChildElem �ڸ�Ԫ�ص����洴��Ԫ�� (���磺�����롱��Ԫ���ڲ�����α�ʾ).
�����ʾ�����봴��һ��XML�ĵ����������������ݣ���һ���ַ����С�
UGMarkup xml;
xml.AddElem( "ORDER" );
xml.AddChildElem( "ITEM" );
xml.IntoElem();
xml.AddChildElem( "SN", "132487A-J" );
xml.AddChildElem( "NAME", "crank casing" );
xml.AddChildElem( "QTY", "1" );
CString csXML = xml.GetDoc();
��Щ��������������XML������������ORDERԪ�أ�ע�����Ŀ�ʼ��ǩ<ORDER> �ڿ�ͷ��������ǩ</ORDER>�ڽ�β��
��һ��Ԫ������һ�������棨����򱻰������������Ԫ�صĿ�ʼ��ǩҪ����֮ǰ��������ǩҪ����֮��
ORDERԪ�ذ���һ��ITEMԪ�أ���ITEMԪ�ذ�������������Ԫ�أ�SN��NAME��QTY��
<ORDER>
	<ITEM>
		<SN>132487A-J</SN>
		<NAME>crank casing</NAME>
		<QTY>1</QTY>
	</ITEM>
</ORDER>
������������ʾ�ģ���Ҳ�ܹ���һ����Ԫ���´�����Ԫ�أ�����Ҫ����IntoElem �ƶ���ĵ�ǰ��λ�õ���ǰ��Ԫ��λ�ã�
Ȼ����Ϳ���������������һ����Ԫ���ˡ�UGMarkup�������б�����һ����ǰλ��ָ�룬�Ա�֤���Դ����Ӷ̺͸��򵥣�
�������ļ�ʱ����ͬ���߼�λ��Ҳ�ᱻʹ�á�

2,����XML�ĵ�
�����������������XML�ַ�������SetDoc�������뵽UGMarkup�������ܹ���������
��Ҳ������������ȷ�Ľ��뱻������ͬһ��UGMarkup�����У������Ҫ���õ�ǰλ�õ��ĵ��Ŀ�ʼʱ����Ҫ����ResetPos.
������������У���csXML�ַ�������UGMarkup���������ѭ��ORDERԪ���µ�����ITEMԪ�أ����õ�ÿ����Ŀ����ź�������
UGMarkup xml;
xml.SetDoc( csXML );
while ( xml.FindChildElem("ITEM") )
{
    xml.IntoElem();
    xml.FindChildElem( "SN" );
    CString csSN = xml.GetChildData();
    xml.FindChildElem( "QTY" );
    int nQty = atoi( xml.GetChildData() );
    xml.OutOfElem();
}
�������Ƿ��ֵ�ÿ��Ԫ�أ��ڲ�ѯ������Ԫ��֮ǰҪ����IntoElem����ѯ��֮���ٵ���OutOfElem ��
����ϰ�������ֵ�������ʱ���㽫֪����������ѭ��ʱ��Ҫȷ��ÿ��IntoElem ���ö���һ����֮��Ӧ��OutOfElem ���� ��

3,����Ԫ�غ�����
���洴���ĵ��������н�������һ��ITEMԪ�أ�������������Ǵ��������Ŀ����ǰһ�����ݼӲú�����������Դ��
����SHIPMENT��ϢԪ������һ�����ԣ���δ���Ҳ��ʾ�����ܵ��õ���IntoElem��AddElem������AddChildElem,�������á�
��Ȼ����ζ�Ÿ���ĵ��ã����������Ϊ������ֱ�ۡ�
UGMarkup xml;
xml.AddElem( "ORDER" );
xml.IntoElem(); // inside ORDER
for ( int nItem=0; nItem<aItems.GetSize(); ++nItem )
{
    xml.AddElem( "ITEM" );
    xml.IntoElem(); // inside ITEM
    xml.AddElem( "SN", aItems[nItem].csSN );
    xml.AddElem( "NAME", aItems[nItem].csName );
    xml.AddElem( "QTY", aItems[nItem].nQty );
    xml.OutOfElem(); // back out to ITEM level
}
xml.AddElem( "SHIPMENT" );
xml.IntoElem(); // inside SHIPMENT
xml.AddElem( "POC" );
xml.SetAttrib( "type", csPOCType );
xml.IntoElem(); // inside POC
xml.AddElem( "NAME", csPOCName );
xml.AddElem( "TEL", csPOCTel );
��δ�������������XML����Ԫ��ORDER��������ITEMԪ�غ�һ��SHIPMENTԪ�أ�
ITEMԪ��ȫ������SN��NAME����QTYԪ�أ�
SHIPMENTԪ�ذ���һ�������������͵�POCԪ�أ���NAME��TEL��Ԫ�ء�
<ORDER>
	<ITEM>
		<SN>132487A-J</SN>
		<NAME>crank casing</NAME>
		<QTY>1</QTY>
	</ITEM>
	<ITEM>
		<SN>4238764-A</SN>
		<NAME>bearing</NAME>
		<QTY>15</QTY>
	</ITEM>
	<SHIPMENT>
		<POC type="non-emergency">
			<NAME>John Smith</NAME>
			<TEL>555-1234</TEL>
		</POC>
	</SHIPMENT>
</ORDER>

4, ����Ԫ��
FindElem �� FindChildElem�������ڵ���һ���ֵ�Ԫ�ء������ѡ�ı�ǩ����ָ����
��ô���ǽ�����һ�����ǩ����ƥ���Ԫ�أ������ֵ�Ԫ���ǵ�ǰԪ�أ�
�����´ε���Find���ᵽ��ǰλ�ú����һ���ֵܻ���һ��ƥ���ֵܡ�
�����޷��ж�Ԫ�ص�����ʱ���ڵ�������Find����֮�䣬һ��Ҫ��λ��ǰλ�á�
�������������ITEMԪ�أ�����Ǳ���˴�����XML�ļ����㲻��ȷ��SNԪ����QTYԪ��֮ǰ��
��ô�ڲ���QTYԪ��֮ǰ��Ҫ����ResetChildPos();
������һ���ض������ȥ����Ԫ�أ�����Ҫ��ȫѭ��ITEMԪ�أ����Ƚ�SNԪ�ص����ݺ���������������š�
������Ӳ�ͬ����ǰ���������ӣ�������IntoElem ���뵽ORDERԪ�أ�
������FindElem("ITEM")�滻FindChildElem("ITEM");��ʵ���ַ�ʽ��ͦ�á�
��Ҫע����ǣ���Find������ָ��ITEMԪ�صı�ǩ�������ǻ���������������ֵ�Ԫ�أ�����SHIPMENTԪ�ء�
UGMarkup xml;
xml.SetDoc( csXML );
xml.FindElem(); // ORDER element is root
xml.IntoElem(); // inside ORDER
while ( xml.FindElem("ITEM") )
{
    xml.FindChildElem( "SN" );
    if ( xml.GetChildData() == csFindSN )
        break; // found
}

5,����
ASCII�����������������������ַ���128���µ��ַ�������Ӣ���̡�
�����ֻʹ��ASCII�룬�ܷ��㣬UTF-8�������������ASCII����ͬ��
�������ʹ�õ��ַ�������Unicode���뼯(UTF-8��UTF-16��UCS-2)�У�
��ô���ڽ������Լ���IE�кܺõ���ʾ���������Ҫ��XML�����н���������
��ISO-8859-1(��ŷ)�ַ���ָ���ַ�ֵ��һ����������128��255֮�䡣
�Ա�ÿ���ַ���Ȼʹ��һ�����ء�Windows˫�ֽ��ַ�����GB2312��Shift_JIS��EUC-KR��
ÿ���ַ�������һ���������ֽڣ�������ЩWindows�ַ����������Ԥ��������Ҫ���� _MBCS ��
��Ҫȷ���û��Ĳ���ϵͳ���õ����ʵı���ҳ��
������һ��XML������XML�ĵ�ǰ׺����<?xml version="1.0" encoding="ISO-8859-1"?>��
��Ҫͨ����SetDoc��UGMarkup�Ĺ��캯�������ݡ��ڽ�βҪ�����س�����������������ʾ����һ�С�
xml.SetDoc( "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\r\n" );
xml.AddElem( "island", "Cura?ao" );

*/

