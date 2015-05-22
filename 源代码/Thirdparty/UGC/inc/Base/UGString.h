/* 
	\file UGString.h
	\brief �ַ�����
	\author ��ͬ�á���־��
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����modified by zengzm 2007-3-12 UGString��Ҫ��std::string�̳У���Ӧ���ǰ�������
	�Ա������ stl�ϣ���UGString���û�Ӧ��������UGString�Ľӿڣ�������ʵ�֣���������ԭ����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGSTRING_H
#define UGSTRING_H

#include "ugdefs.h"
#include "UGArray.h"
#include "UGStream.h"
// by zengzm ע��: ����Ӧ�ñ����MFC��ͷ�ļ�Include����(�ȱ������WIN32��),��ΪMFC��LoadString��Ϊ��
// ��MBCS��ʽ�»��ΪLoadStringA,���±��벻��.

namespace UGC {

class UGString;

typedef const UGchar* LPCTSTR;
typedef UGArray<UGString> UGStrArray;
typedef UGArray<UGString> UGStrings; 


//! \brief �ַ�����
//!	\remarks ����������˵����UGString�Ľӿھ����ܺ�MFC��CString����һ��
//! \attention UGString��֧�ֶ��ֽڱ�����ַ��������ֽڱ�����ַ�����ΪUGStringW��
class BASE_API UGString
{
	friend class UGProgress;

public:
	//! \brief Ĭ�Ϲ��캯����
	UGString();
	//! \brief �������캯����
	//! \param str UGString���͵��ַ���
	UGString(const UGString& str);	
	//! \brief ��std::string�����졣
	//! \param str std::string���͵��ַ���,��Ҫ���ں�UGMarkup�Ƚ���ƥ��
	UGString(const std::string& str);	
	//! \brief ��C �ַ������졣	
	//! \param pstr C�ַ�������
	UGString(const UGchar* pstr);
	//! \brief ָ��C�ַ����ĳ��������졣
	//! \param pstr C�ַ�������
	//! \param nSize ָ��ʹ�õ��ֽڳ���
	UGString(const UGchar* pstr, UGint nSize);
	//! \brief ָ���ض��ַ���ָ�����ظ������������죬��
	//! \param ch ָ�����ַ�
	//! \param nRepeat �ظ�����,Ĭ��Ϊ1
	//! \remarks explicit���ڷ�ֹ���ε�ת��
	explicit UGString(UGchar ch, UGint nRepeat=1);
	//! \brief ת��ΪLPCTSTR��ͨ�����ںʹ�SFC��ֲ�����Ĵ�����ݡ�
	operator LPCTSTR() const;
	//! \brief �õ�C�ַ�����
	//! \return ����C�ַ�����
	const UGchar * Cstr() const;

	//! \brief �õ�ָ���������ַ���
	//! \param nIndex ָ��������
	//! \return ����ָ���������ַ���
	UGchar GetAt(UGint nIndex) const;		
	//! \brief ����ָ���������ַ�
	//! \param nIndex ָ��������
	//! \param ch Ҫ���õ��ַ�
	void SetAt(UGint nIndex, UGchar ch);

	//! \brief �õ�ָ���������ַ���
	//! \param  nIndex ָ��������
	//! \return ����ָ���������ַ�
	UGchar operator[](UGint nIndex) const;
	//! \brief ����ָ���������ַ������ã�֧��str[i]='a'
	//! \param nIndex ָ��������
	//! \return ����ָ���������ַ�������
	UGchar& operator[](UGint nIndex);

	//! \brief ȷ����ָ���ֽڸ������ڴ�ռ�
	//! \remarks ���ԭ�пռ䲻��, �ڴ�ռ������
	//! \remarks ���ԭ�пռ��ָ���Ĵ�, Ҳ�����ͷſռ�
	//! \param nCapacity �����ɵ��ֽڸ���
	void SetCapacity(UGint nCapacity);
	//! \brief �õ�Ŀǰ���пռ�(�����Ѿ�ʹ�õĺͱ�����)��ռ�õ��ֽڸ���
	//! \return ����Ŀǰ���пռ�(�����Ѿ�ʹ�õĺͱ�����)��ռ�õ��ֽڸ���
	UGint GetCapacity() const; 

	//! \brief �õ��ַ�������
	//! \return �����ַ�������,���ֽڸ���
	UGint GetLength() const;	
	//! \brief �����ַ�������
	//! \remarks ������ȱ�С,���Զ��ض�; ������ȱ��,�����0x00, ��Length��䳤���ڲ�����string��resizeʵ�֡�
	//! \param nLength Ҫ���õ��ַ�������(�ֽڸ���)
	void SetLength(UGint nLength);

	//! \brief ׷�����ݣ��ڲ�����string��appendʵ�֡�
	//! \param pch Ҫ׷�ӵ��ַ���ָ��
	//! \param nSize Ҫ׷�ӵ��ֽڸ���
	void Append(const UGchar* pch, UGint nSize);	

	//! \brief ���ַ�������ת��Ϊ��д�������޸ķ�ASCII�ַ�
	//! \return �������������,֧����д
	UGString& MakeUpper();
	//! \brief ���ַ�������ת��ΪСд�������޸ķ�ASCII�ַ�
	//! \return �������������,֧����д
	UGString& MakeLower();
	//! \brief ���ַ�����ת��֧���м�������ģ�MBCS����ת������"ab��c"��ת��Ϊ"c��ba"������û�в��Թ�
	//! \return �������������,֧����д
	UGString& MakeReverse();
	
	//! \brief ȡ���ַ���������ߵ����ɳ��ȵ����ַ���
	//! \param nCount �ֽڸ���
	//! \return �������ָ�����ȵ����ַ���
	UGString Left(UGint nCount) const;
	//! \brief ȡ���ַ����������ұߵ����ɳ��ȵ����ַ���
	//! \param nCount �ֽڸ���
	//! \return �����ұ�ָ�����ȵ����ַ���
	UGString Right(UGint nCount) const;
	//! \brief ���ַ���������ȡ�����м�ĳ����������ַ�������
	//! \param nFirst ָ�����м���������
	//! \return ���ش��м�ָ����������ʼ,���������ַ���
	UGString Mid(UGint nFirst) const;
	//! \brief ���ַ���������ȡ�����м�ĳ������һ�����ȵ����ַ�������������Ŵ�0��
	//! \param nFirst nFirst ָ�����м���������
	//! \param nCount Ҫȡ�����ֽڸ���
	//! \return ���ش��м�ָ����������ʼ,ָ�����ȵ����ַ���
	UGString Mid(UGint nFirst,UGint nCount) const;

	//! \brief ɾ����ָ���������������Ŀ���ַ���������Ŵ�0��
	//! \param nIndex ָ���Ŀ�ʼɾ��������
	//! \param nCount ָ��Ҫɾ�����ֽڸ���
	//! \return ɾ����ָ���ֽڸ���֮��,�ַ�������ĳ���
	UGint Delete(UGint nIndex,UGint nCount=1);
	//! \brief ��ָ��������֮ǰ�����ַ���
	//! \param nIndex ָ��������
	//! \param pstr Ҫ������ַ���
	//! \return �����,�ַ����ĳ���
	UGint Insert(UGint nIndex,const UGchar * pstr);	
	//! \brief ��ָ��������֮ǰ����������Ŀ���ַ�
	//! \param nIndex ָ��������
	//! \param ch ָ�����ַ�
	//! \param nCount �ַ��ظ��Ĵ���
	//! \return �����,�ַ����ĳ���
	UGint Insert(UGint nIndex,UGchar ch,UGint nCount=1);
	//! \brief ɾ���ַ��������е���ָ���ַ����ַ�
	//! \param ch Ҫɾ�����ַ�
	//! \return ����ɾ�����ַ��ĸ���
	UGint Remove(UGchar ch);		

	//! \brief ɾ���ַ���������ߵĿո�0x09��0x0D��0x20��
	//! \return ɾ����,�ַ������������,��֧����д
	UGString& TrimLeft();
	//! \brief ɾ���ַ���������ߵ�ָ���ַ�
	//! \param ch Ҫɾ�����ַ�
	//! \return ɾ����,�ַ������������,��֧����д
	UGString& TrimLeft(UGchar ch);
	//! \brief ɾ���ַ��������������ָ���ַ����ϵ��ַ�
	//! \remarks �����ַ�����,��Ҫɾ����ߵĴ������ַ������е�ÿһ���ַ�
	//!			UGString("? *?? ab* ?").TrimLeft("? *") == UGString("ab* ?")
	//! \param pstr ָ�����ַ�������
	//! \return ɾ����,�ַ������������,��֧����д
	UGString& TrimLeft(const UGchar* pstr);
	//! \brief ɾ���ַ��������ұߵĿո�0x09��0x0D��0x20��
	//! \return ɾ����,�ַ������������,��֧����д
	UGString& TrimRight();
	//! \brief ɾ���ַ��������ұߵ�ָ���ַ�
	//! \param ch ָ�����ַ�
	//! \return ɾ����,�ַ������������,��֧����д
	UGString& TrimRight(UGchar ch);
	//! \brief ɾ���ַ��������ұ�����ָ���ַ����ϵ��ַ�
	//! \remarks �����ַ�����,��Ҫɾ���ұߵĴ������ַ������е�ÿһ���ַ�
	//!			UGString("? *?? ab?* ?").TrimRight("? *") == UGString("? *?? ab")
	//! \param pstr ָ�����ַ�������
	//! \return ɾ����,�ַ������������,��֧����д
	UGString& TrimRight(const UGchar* pstr);
	
	//! \brief �ж��ַ����Ƿ�Ϊ��
	//! \return Ϊ��,����true;��Ϊ��,����false
	UGbool IsEmpty() const;	
	//! \brief ����ַ���
	void Empty();

	//! \brief �ȽϺ������ַ��������һ���ַ����Ƚϴ�С
	//! \remarks ���ִ�Сд�������ڲ�ֵ��˳��Ƚ�
	//! \param lpsz Ҫ�Ƚϵ��ַ���ָ��
	//! \return С�ڷ��ظ��������ڷ���0�����ڷ�������</returns>
	UGint Compare(const UGchar* lpsz) const;
	//modified by xielin 2007-10-17��������������ǿ��ų���������linux��������
	//! \brief �ȽϺ������ַ��������һ���ַ����Ƚϴ�С
	//! \remarks �����ִ�Сд�������ڲ�ֵ��˳��Ƚ�
	//! \param lpsz Ҫ�Ƚϵ��ַ���ָ��
	//! \return С�ڷ��ظ��������ڷ���0�����ڷ�������</returns>
 	UGint CompareNoCase(const UGchar* lpsz) const;

	//added by xielin 2007-10-15 �����Ż����ıȽϺ��������Է��������˴���ʹ�ñȽϺ�����
	//��ǰ��Ч�ʱȽϵͣ���ΪӰ��Ч�ʵ�ƿ��֮һ��������һ���µ�Ч�ʱȽϸߵıȽϺ���
	//! \brief �ȽϺ������ַ��������һ���ַ����Ƚϴ�С
	//! \remarks �����ִ�Сд�������ڲ�ֵ��˳��Ƚ�
	//! \param str Ҫ�Ƚϵ��ַ���
	//! \return С�ڷ��ظ��������ڷ���0�����ڷ�������</returns>
	UGint CompareNoCase(const UGString& str) const;
	
	//! \brief ��ĳλ�ÿ�ʼ������ָ�����ַ�
	//!	\param ch Ҫ���ҵ��ַ�[in]��
	//!	\param nStart ������ʼλ�ã���Ӧ���ַ��ᱻ����[in]��
	//!	\return �����ҵ����ַ�������ֵ����0�����Ҳ�������-1
	UGint Find(UGchar ch,UGint nStart=0) const;		

	//! \brief ��ĳλ�ÿ�ʼ��������ȫ��ȵ����ַ���
	//!	\param lpszSub Ҫ���ҵ����ַ���[in]��
	//!	\param nStart ������ʼλ�ã���Ӧ�����ַ����ᱻ����[in]��
	//!	\return �����ҵ������ַ���������ֵ����0�����Ҳ�������-1
	UGint Find(const UGchar* lpszSub, UGint nStart=0) const;

	//! \brief �Ӻ���ǰ����ָ�����ַ�
	//!	\param ch Ҫ���ҵ��ַ�[in]��
	//!	\return �����ҵ����ַ�������ֵ����0����;�Ҳ�������-1
	UGint ReverseFind(UGchar ch) const;	
	
	//! \brief ���ҵ�һ���������ַ��������У�����ָ�����ַ������С����ַ���λ�á�
	//!	\param lpszCharSet ָ�����ַ�����[in]��
	//!	\return �����ҵ����ַ�����������0�����Ҳ�������-1
	UGint FindOneOf(const UGchar* lpszCharSet) const;	

	//! \brief �õ��ַ��������У��ӵ�0���ַ��𣬵�������ָ���ַ������е��ַ�Ϊֹ�����ַ�����
	//! \param lpszCharSet ָ�����ַ�����[in]��
	//!	\return ���ط������������ַ�����
	//!	\remarks example: UGString("acbdabc").SpanIncluding("abc") == UGString("acb")��
	UGString SpanIncluding(const UGchar* lpszCharSet) const;		

	//! \brief �õ��ַ��������У��ӵ�0���ַ��𣬵�����ָ���ַ������е��ַ�Ϊֹ�����ַ�����
	//! \param lpszCharSet ָ�����ַ�����[in]��
	//!	\return ���ط������������ַ�����
	//!	\remarks example: UGString("acbdabc").SpanExcluding("d") == UGString("acb")��
	UGString SpanExcluding(const UGchar* lpszCharSet) const;
		
	//! \brief �滻���������ַ���������ָ�����ַ��滻Ϊ�µ��ַ���
	//! \param chOld ָ��Ҫ���滻���ַ�[in]��
	//!	\param chNew �µ��ַ�[in]��
	//!	\return �����滻�Ĵ�����
	//! \remarks �Ƚ�ʱ���ִ�Сд��
	UGint Replace(UGchar chOld,UGchar chNew);

	//! \brief �滻���������ַ���������ָ�������ַ����滻Ϊ�µ��ַ���
	//! \param lpszOld ָ��Ҫ���滻�����ַ���[in]��
	//!	\param lpszNew �µ��ַ���[in]��
	//!	\return �����滻�Ĵ�����
	//!	\remarks �Ƚ�ʱ���ִ�Сд��
	UGint Replace(const UGchar* lpszOld,const UGchar* lpszNew);

	//! \brief ��ȡ�ַ��������Hashֵ
	//! \remarks һ���ò��ϣ�����һЩ�������ڲ�ʹ��
	//! \return ���ع����hashֵ,�;�����ַ������������
	UGuint HashVal() const;
	
	//! \brief ������ԴIDװ���ַ�����Դ��
	//! \param nID ����װ���ַ�����Դ����ԴID[in]��
	//! \remarks ����MFC��LoadString�ȵ��ɺ��������ܶ���Ҫ�õ�MFC�Ĺ��̣�
	//!			��ʹ��LoadString��ʱ�򣬶��ᷢ�����벻�������;��ʱ,��ʹ��LoadResString;
	//!			�Ժ��Ҷ�����ʹ��LoadResString,LoadString��һ���汾����ȡ��.
	//!	\return װ�سɹ�������true��ʧ�ܷ���false��
	UGbool LoadResString(UGuint nID);	

	//! \brief ������ԴIDװ���ַ�����Դ��
	//! \param nID ����װ���ַ�����Դ����ԴID[in]��
	//!	\return װ�سɹ�������true��ʧ�ܷ���false��
	UGbool LoadString(UGuint nID);	

	//! \brief ��ʽ��������������sprintf��
	//!	\param fmt ��������ʽ���ַ���[in]��
	//!	\param ... ��ѡ����[in]��
	//!	\remarks ���ܽ�UGString��Ϊ���������ú��������������UGString��Cstr�����õ�C�ַ�����
	//!			 ���ܽ�UGlong��UGulong��64λ������Ϊ��������ú���,��Ӧ����ǿ��ת��Ϊ32λ����
	void Format(const UGchar* fmt,...);
	//! \brief ��ʽ��������������sprintf��
	//!	\param nID ��������ʽ���ַ�������Դ��ID[in]��
	//!	\param ... ��ѡ����[in]��
	//!	\remarks ���ܽ�UGString��Ϊ���������ú��������������UGString��Cstr�����õ�C�ַ�����
	//!			 ���ܽ�UGlong��UGulong��64λ������Ϊ��������ú���,��Ӧ����ǿ��ת��Ϊ32λ����
	void Format(UGuint nID,...);

	//! \brief �ַ�����ֵ������
	const UGString& operator=(const UGString& str);	

	UGString operator+(const UGchar ch) const;
	UGString operator+(const UGchar* pch) const;
	UGString operator+(const UGString& str) const;

	const UGString& operator+=(const UGString& str);
	const UGString& operator+=(const UGchar ch);
	const UGString& operator+=(const UGchar* pch);

	bool operator==(const UGchar* pch) const;
	bool operator==(const UGString& str) const;

	bool operator!=(const UGchar* pch) const;
	bool operator!=(const UGString& str) const;

	bool operator<(const UGString& str) const;

	friend BASE_API UGString operator+(UGchar ch, const UGString &str);
	friend BASE_API UGString operator+(const UGchar* pch, const UGString &str);
	
	//! \brief ��long�͵�����ת��Ϊ�ַ���
	//! \param lVal Ҫת����long������
	//! \param base ����,Ĭ��Ϊ10����,��֧��16����;������ʱ��֧��
	//! \return ����ת������ַ���
	//! \remarks ��baseΪ16����ʱ,ת����Ľ��ǰ����0X,��ĸ��Ϊ��д
	//! �����ַ�ʽ���֧��long�����ݵ�Format,����ת��ΪUGString,����%s���и�ʽ��
	//! ���þ�̬����������UGString�ķ�ʽ���Ա��ڵ��õĴ�����д
	static UGString From(UGlong lVal, UGint base=10);
	static UGString From(UGulong lVal, UGint base=10);
	static UGString From(UGint nVal, UGint base=10);
	static UGString From(UGuint nVal, UGint base=10);
	//friend BASE_API UGString UGLongToString(UGlong lVal, UGint base=10);
	//friend BASE_API UGString UGULongToString(UGulong lVal, UGint base=10);
	
	//Convert string to a integer number, assuming given number base
	//! \brief ���ַ���ת��ΪInt����ֵ
	//friend BASE_API UGint UGIntVal(const UGString& s,UGint base=10);
	UGint ToInt(UGint base=10) const;

	//! \brief ���ַ���ת��Ϊ�޷���Int����ֵ
	//friend BASE_API UGuint UGUIntVal(const UGString& s,UGint base=10);
	UGuint ToUInt(UGint base=10) const;

	
	//! \brief ���ַ���ת��ΪLong����ֵ
	//! \param s Ҫת�����ַ���
	//! \param base ����,Ĭ��Ϊ10����,��֧��16����;������ʱ��֧��
	//friend BASE_API UGlong UGLongVal(const UGString& s,UGint base=10);
	UGlong ToLong(UGint base=10) const;

	//! \brief ���ַ���ת��Ϊ�޷���Long����ֵ
	//! \param s Ҫת�����ַ���
	//! \param base ����,Ĭ��Ϊ10����,��֧��16����;������ʱ��֧��
	//friend BASE_API UGulong UGULongVal(const UGString& s,UGint base=10);
	UGulong ToULong(UGint base=10) const;
	
	//Convert string into real number
	//! \brief ���ַ���ת��ΪFloat����ֵ
	//friend BASE_API UGfloat UGFloatVal(const UGString& s);
	UGfloat ToFloat() const;

	//! \brief ���ַ���ת��ΪDouble����ֵ
	//friend BASE_API UGdouble UGDoubleVal(const UGString& s);	
	UGdouble ToDouble() const;
	
	//! \brief ���ַ�������ָ���ķָ����ָ�Ϊһ���ַ������顣
	//! \param dest ���ɵ��ַ�������[out]��
	//!	\param delims ָ���ķָ�����Ĭ��Ϊ�س�����[in]��
	//!	\param bKeepEmptyString �Ƿ����ָ�� �յ��ַ���, ���ַ���";"ͨ��';'�ָ��,dest�����size
	//! �ڱ������ַ�����ʱ��Ϊ2, ��������ʱ��Ϊ0; 
	//!	\return �ָ���ַ��������size��
	UGint Split(UGStrings &dest,const UGString& delims="\r\n", UGbool bKeepEmptyString=FALSE) const;
		
	//! \brief ���ַ������浽����
	friend BASE_API UGStream& operator<<(UGStream& store,const UGString& s);
		
	//! \brief �����ж����ַ���
	friend BASE_API UGStream& operator>>(UGStream& store,UGString& s);

	//!brief ����/��ȡugstring������ַ��������ַ�������ת����ʱ������
	void SetCharset(UGint enCharset);
	UGint GetCharset();
	//!brief ������ת�����ƶ�������ַ���
	UGbool ChangeCharset(UGint eCharset);
private:
	// added by zengzm 2007-3-19 ����ֻ���岻ʵ�֣�������UGStringֱ�Ӻ�NULL�Ƚ��бȽ�
	// ��Ϊ��linuxƽ̨�ϣ��ᵼ�³������
	bool operator==(int n) const;

private:
	void FormatV(const UGchar* fmt, va_list argList);

	std::string m_string; // �ڲ�����std��stringʵ��
	UGint m_Charset;
};

}

#endif
