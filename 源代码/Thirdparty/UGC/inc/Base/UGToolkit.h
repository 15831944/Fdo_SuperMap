// UGToolkit.h: interface for the UGToolkit class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGTOOLKIT_H
#define UGTOOLKIT_H

#include "ugdefs.h"
#include "UGString.h"
#include "UGTextCodec.h"
#include "ugplatform.h"

namespace UGC{

class BASE_API UGToolkit  
{
private:
	UGToolkit();
	~UGToolkit();

public:
	//! \brief ��ȷ����Cosֵ
	//! \remark ��Ҫ���������Ƕ�ΪĳЩ����ֵʱ,����ֱ�ӷ��ؾ�ȷ��ֵ
	//!			����PI�Ĳ���ȷ��, ��cos(����)�õ��Ľ������΢С�����, ������Ӧ��Ϊ0�Ⱦ�ȷֵʱ,
	//!			�������������Ϊ�Ƕ�ֵ,�ж����������, �������ȷ��ֵ.
	//!			δ�����Կ����ڲ�����һЩ����ֵ,�����Ч��
	//! \param dAngle �Ƕ�ֵ
	//! \return cos�ļ���ֵ
	//! Ч�ʽϵ�, �ݲ��ṩ
	//static UGdouble CosAngle(UGdouble dAngle);

	//! \brief ��ȷ����Sinֵ
	//! \remark ��Ҫ���������Ƕ�ΪĳЩ����ֵʱ,����ֱ�ӷ��ؾ�ȷ��ֵ
	//!			����PI�Ĳ���ȷ��, ��sin(����)�õ��Ľ������΢С�����, ������Ӧ��Ϊ0�Ⱦ�ȷֵʱ,
	//!			�������������Ϊ�Ƕ�ֵ,�ж����������, �������ȷ��ֵ.
	//!			δ�����Կ����ڲ�����һЩ����ֵ,�����Ч��
	//! \param dAngle �Ƕ�ֵ
	//! \return sin�ļ���ֵ
	//! Ч�ʽϵ�, �ݲ��ṩ
	// static UGdouble SinAngle(UGdouble dAngle);

	static UGint RoundLong(UGdouble dValue)
	{
		if(dValue>0) return UGint(dValue+0.5);
		else return UGint(dValue-0.5);
	};

	//! \brief �õ���ǰ���̵�id
	static UGint GetCurProcessId();

// by zengzm 2007-7-13 ��·����صĺ������ŵ� UGFile��
	//! \attention ԭ��SuperMap50��Ref��Source�ĸ������õߵ���;
	//! ��Ϊ�˱��ִ������,����ֻ�޸ı�������, ������˳��, ʹ���ߴ��벻��Ҫ�Ķ�
	//! ����strSourcePathΪ����·����(����Ϊ��), �����ļ���; ����strRefPathΪ�ļ���, 
	//! �ɴ����·�������·����Ϣ;����ֵΪ������·����Ϣ���ļ���.
	//! ��strSourcePathΪ�յ�ʱ��, ���strRefPathΪ./abc.txt , �򷵻�abc.txt ;
	//! ��strSourcePathΪ�յ�ʱ��, ���strRefPathΪ../abc.txt , �򷵻ؿ��ַ���.
//	static UGString GetAbsolutePath(const UGString &strSrcPath, const UGString &strFile);
	// static UGString GetAbsolutePath(UGString strRefPath, UGString strSourcePath);

	//! �õ����·��
	//! \remarks ����·���Ķ���: ԭ·��(SourcePath)+���·��(RefPath) == ����·��(AbsPath)
	//! �� RefPath = AbsPath - SourcePath
	//! ����˵��: SourcePath="d:\\dir\\", AbsPath="d:\\dir\\path\\",  �� RefPath=".\\path\\"
	//! �����ͷ���ֵ��ֻ����ֻ����Ŀ¼��·����Ϣ, ���������κ��ļ���.
	//! \attention ԭ��SuperMap50�и����ǲ���ȷ��
	//! ��Ϊ�˱��ִ������,����ֻ�޸ı�������, ������˳��, ʹ���ߴ��벻��Ҫ�Ķ�
//	static UGString GetRelativePath(UGString strSourcePath, UGString strAbsPath);
	// static UGString GetRelativePath(UGString strRefPath, UGString strSourcePath);


//	static void SplitPath(const UGString& strPath, UGString& strDrive, UGString& strDir, UGString& strFileName, UGString& strExtName);
//	static UGString ChangeExtName(const UGString &strFileName, const UGString &strExtName);
//	static UGString GetExtName(const UGString &strFileName); 

	// by zengzm 2005.6.2 �������û����, ��ʱ������, ˭Ҫ����˵; ��������뵽UGFile����
	// static UGbool IsSameFile(UGString strFile1, UGString strFile2);
	// static UGString SetDefaultExtName(const UGString& strFileName, const UGString& strExtName);
	
	// modified by jifang 06/16/2005 �����е�UGchar *��UGString&�滻
	//static UGuint GetTemporaryPath(UGuint nBufferLength, UGchar* lpBuffer);
//	static UGString GetTemporaryPath();
//	//static UGuint GetTemporaryFileName(UGchar* lpPathName, UGchar* lpPrefixString,UGuint uUnique,UGchar* lpTempFileName);
//	static UGuint GetTemporaryFileName(const UGString &strPathName, const UGString &strPrefixString, 
//									UGuint uUnique, UGString &strTempFileName);

	//{{ ��̬�⴦����======================================================
	static void* LoadDll(const UGString& strLibName);
	// ͨ����ľ���ͺ�������,�õ�����ָ��
	static void* GetProcAddress(void* hModule, const UGString& strProName);
	// �ͷſ�
	static UGbool FreeDll(void* hModule);
	//}} ��̬�⴦����======================================================

// by zengzm 2007-7-13 ���ļ�, ·����صĺ������ŵ�UGFile����
//	static UGString GetAppPath();
//	static UGString GetModulePath(const UGchar* p);
//
//	//! \brief �õ���Ԫ�����������ڵ�Ŀ¼
//	//! \param strUnitTestName ��Ԫ���Թ��̵��ļ���������TestBase��TestGeometry��
//	//! \remarks ���ص��Ǿ���·������ֱ��ʹ�ã����õ���ugcpath/01_SourceCode/TestUnit/strUnitTestName/Data/ ����ʽ
//	//!			 ������Ҫ�������Ԫ���Թ��̵����ݷ��ڱ����Թ���Ŀ¼��һ����DataĿ¼��; ����ʱ,��strUnitTestName��Ϊ��������
//	//! \return ���ص�Ԫ�����������ڵ�Ŀ¼
//	static UGString GetUnitTestDataPath(const UGString& strUnitTestName);

//	static UGbool FindFileExtPaths(const UGString& strPath, const UGString& strExtName, 
//								  UGArray<UGString>& strFileNames, UGbool bAddPath);
//
//	static UGbool DeleteFileEx(const UGString& strFileName);
//	static UGbool IsFileExisted(const UGString& strFileName);
//	// modified by zengzm 2007-4-2 CopyFileEx��������ֱ�MFC������ΪCopyFileExA�ˣ���ˣ���UGC��ֻ�û�һ�����֣���ǰ���UG
//	// static UGbool CopyFileEx(const UGString& strExistedFileName, const UGString& strNewFileName, UGbool bFailIfExists);
//	static UGbool UGCopyFile(const UGString& strExistedFileName, const UGString& strNewFileName, UGbool bFailIfExists);

	//! \brief �õ���ǰϵͳĬ�ϵ��ַ���
	static UGTextCodec::Charset GetCurCharset();

	//ͨ��ϵͳ������ȡ��Ļ��С��X11�ϻ�ȡ�Ƚ����������������ҪС�ģ��Ƽ���������һ������ add by xll 2006.12.30
	static UGuint GetScreenSize(UGuint nScreen);	
	//��ȡ��Ļ��С��Ϊ�˽�ʡЧ�ʣ�X11�ϻ�ȡ�Ƚ�������ÿ��ondrawǰ��ϵͳ��ȡֵд�뵽��Ա������
	//����Ҫʹ�õ�ʱ���ֱ��ȡ��Ա�����е�ֵ add by xll 2006.12.30
	static UGuint GetScreenSizeFromMemory(UGuint nScreen);

	//! \brief �ڴ���Ϣ�ṹ
	struct MemoryStatus
	{
		MemoryStatus(){memset(this, 0, sizeof(MemoryStatus));}
		//! \brief ���������ڴ�
		UGuint m_nAvailablePhysical;
		//! \brief ���������ڴ�
		UGuint m_nTotalPhysical;
		//! \brief ���������ڴ�
		UGuint m_nAvailableVirtual;
		//! \brief ���������ڴ�
		UGuint m_nTotalVirtual;
		//! \brief ��ǰ���̿����ڴ��С(����min(���������ڴ�+���������ڴ�,����ʣ��ռ�)
		//! \remarks ���̿ռ� �� ����Ϊ23/64λ���,32λΪ2GB,64λ��ǳ�����
		//! \attention ��δʵ��, ��Windowsƽ̨��δ�ҵ�ʵ�ַ���
		//UGuint m_nProcessAvailable = 5,
		//! \brief ��ǰ����ȫ���ڴ��С(����min(���������ڴ�+���������ڴ�,���̿ռ�)
		//! \remarks ���̿ռ� �� ����Ϊ23/64λ���,32λΪ2GB,64λ��ǳ�����
		//! \attention ��δʵ��, ��Windowsƽ̨��δ�ҵ�ʵ�ַ���
		//UGuint m_nProcessTotal = 6
	};
	//! \brief �õ�ϵͳ�ڴ�״̬, ��λ��ΪKB
	//! \param memoryStatus ͨ�����÷����ڴ�ĸ�����Ϣ[out]
	//! \return ���ز�ѯ�õ����ڴ�״̬
	static UGbool GetMemoryStatus(MemoryStatus& memoryStatus);

	//! \brief �õ�ϵͳ�п���(����)�����ڴ�Ĵ�С(KBΪ��λ)
	//! \return ����ϵͳ�п���(����)�����ڴ�Ĵ�С(KBΪ��λ)
	//! \remarks ��ƽ̨ʵ��,Windows����API:GlobalMemoryStatus;Linux/Unix����sysconf����
	//! \attention �������Ѿ���GetMemoryStatus���, �ȼ��� GetMemoryStatus(AvailablePhysical); 
	//! Ϊ�˱�����ǰ�ĳ������,��ʱ����;�µĴ�����ֱ��ʹ�� GetMemoryStatus
	static UGuint GetAvailablePhysicalMemory();


	//! \brief �õ�ϵͳ��ȫ�������ڴ�Ĵ�С(KBΪ��λ)
	//! \return ����ϵͳ��ȫ�������ڴ�Ĵ�С(KBΪ��λ)
	//! \remarks ��ƽ̨ʵ��,Windows����API:GlobalMemoryStatus;Linux/Unix����sysconf����
	//! \sa GetAvailablePhysicalMemory
	// �ݲ��ṩ
	//static UGuint GetPhysicalMemory();
	
	//! \brief �����Ƕ�ֵ,ʹ֮�� [0, 360)֮��
	//! param dAngle Ҫ�������ĽǶ�[in][out]
	static void AdjustAngle(UGdouble& dAngle);

	//! \brief ��������ֵ,ʹ֮�� [0, 2*PI)֮��
	//! param dRadian Ҫ�������Ļ���[in][out]
	static void AdjustRadian(UGdouble& dRadian);

	//! \brief ����X����ĳ�������תһ���ǶȺ��ֱ�resize��֮��Ӧ�õĳ���
	//! \remark ��Ҫ���ڸ��ִ�����ת�Ƕȵ�Geometry��Resize�����ж�X����ĳ��ȵĴ���
	//! \param dXLength X����ĳ���[in]��
	//! \param dCos �ó��Ⱦ߱�����ת���ȵ�cosֵ[in]��
	//! \param dSin �ó��Ⱦ߱�����ת���ȵ�sinֵ[in]��
	//! \param dXRatio X��������ű���[in]��
	//! \param dYRatio Y��������ű���[in]��
	//! \return �����ĳ��ȡ�
	static UGdouble XRotateResize(UGdouble dXLength, UGdouble dCos, UGdouble dSin, 
								UGdouble dXRatio, UGdouble dYRatio);	

	//! \brief ����Y����ĳ�������תһ���ǶȺ��ֱ�resize��֮��Ӧ�õĳ���
	//! \remark ��Ҫ���ڸ��ִ�����ת�Ƕȵ�Geometry��Resize�����ж�Y����ĳ��ȵĴ���
	//! \param dYLength Y����ĳ���[in]��
	//! \param dCos �ó��Ⱦ߱�����ת���ȵ�cosֵ[in]��
	//! \param dSin �ó��Ⱦ߱�����ת���ȵ�sinֵ[in]��
	//! \param dXRatio X��������ű���[in]��
	//! \param dYRatio Y��������ű���[in]��
	//! \return �����ĳ��ȡ�
	static UGdouble YRotateResize(UGdouble dYLength, UGdouble dCos, UGdouble dSin, 
								UGdouble dXRatio, UGdouble dYRatio);

public:
	
	static UGbool InRange(UGint nValue, UGint nMin, UGint nMax);
	static UGbool InRange(const void* pValue, const void* pMin, const void* pMax);
	static UGint GetBitCount(PixelFormat pf); 

public:
	//! \brief �õ�XML�ļ�ͷ
	//! �ڼ������Ļ����·��� <?xml version="1.0" encoding="GB18030"?> 
	static UGString GetXmlFileHeader();

	//���ڱ�ǩ�ڵ�ֵ�����пո񣬻�����ʱ�رմ˷���. yanmb 2008.1.22
	//! \brief added by yanmb 2007.5.11
	/**
	�淶�ı������ʽ
	\param strXml  ��Ҫ�淶���ı��ַ���
	\param nPace   �ı������Ŀո���
	�ı�Ҫ�淶�ĸ�ʽ������ʽ��������
####< >
####   < />
####   < >
####   </ >
####   < >
####      < >
####      </ >
####      < />  //---���ǵ�����ǩ�����---------
####      < />
####   </ >
####   < >
####      < >
####      </ >
####   </ >
####</ >
	\attention
	1.��ֻ���һ�������">"��"<"֮����������ǿ��Թ涨Ϊһ�����м�3���ո�
	2.ͬһ�����">"��"</"֮����������ǿ��Թ涨Ϊһ������
	3.��������"< />"������ǩ�����,���ǽ�����ͬ</ >������
	*/
	static UGString AdjustXmlString(UGString strXml, UGint nPace = 0);

	//! \brief  �ַ�����һ���ָ�
	//! \remark ��Ҫ����GML����ʱ
	//! \param  strSrc		��Ҫ��һ���ָ���ַ���[in]
	//! \param strDestArray ����ַ������� [out]
	//! \Param str1st		��һ�ηָ��������ַ�
	//! \Param str2nd		�ڶ��ηָ��������ַ�
	/*attention
	����ʵ���Ǹ�����֮�٣�����GML��Щ�汾��ǩ�ڵ������Զ��źͿո������
	��Щ���Կո������UGString��split����ֻ����һ���ָ
	�����ط����ܺ��������������������ֻ���Ƿ���GML���÷������ˡ�yanmb
	*///
	static UGbool SlipString(UGString &strSrc, UGStrings &strDestArray, UGString str1st, UGString str2nd);
public: 
	//! \brief �ж��ַ��Ƿ����� ��ASCII�ַ�, ���� �ո�,\t\r\n��
	static UGbool IsSpaceChar(UGchar ch);

	//! \brief �ж��ַ��Ƿ����� ��ASCII�ַ�, ���� �ո�,\t\r\n��
	static UGbool IsSpaceChar(UGwchar wch);

	//! \brief �ж��ַ��Ƿ����� �����ַ�, �� '0' �� '9'
	static UGbool IsDigit(UGchar ch);

	//! \brief �ж��ַ��Ƿ����� ʮ�������ַ�, ������ '0' �� '9', 'A'��'F', 'a'��'f'
	static UGbool IsHexDigit(UGchar ch);

	//! \brief �ж��ַ��Ƿ����� ��д�ַ�, �� 'A' �� 'Z'
	static UGbool IsBigLetter(UGchar ch);

	//! \brief �ж��ַ��Ƿ����� Сд�ַ�, �� 'a' �� 'z'
	static UGbool IsLittleLetter(UGchar ch);

	//! \brief �жϸ��ֽ��Ƿ���lead byte�������ֽںͺ����ֽ�������һ�𹹳�һ��˫�ֽڵ��ַ��������ġ����ĵȣ�
	static UGbool IsLeadByte(UGchar ch);

	//! \brief �ж�һ��UCS2���ַ��Ƿ���Ӣ���ַ�
	//! \return ��������Ļ����ĵ��ַ�������false����Ӣ���ַ�������true
	static UGbool IsAscii(UGushort ch);

	static UGColor Brightness(UGColor c, UGint nPercentage);
	static UGColor Contrast(UGColor c, UGint nPercentage);

private:
	// added by zengzm 2007-3-26 �����ڲ�ʹ��,�ѵõ������ݴ����ڲ�ȫ�ֱ�����
	static void SaveScreenSize(UGuint nScreen, UGuint ScreenValue);
	
};
//������Щģ�庯������ȫ�ֵģ��ŵ��������������û����Ӳ���

//�õ���(��)��ֵ
template<typename Type>
const Type& Max(const Type& tValue1, const Type& tValue2)
{
	return ( (tValue1<tValue2)? tValue2 : tValue1);
}
//��nCount�����еõ����ֵ
template<typename Type>
Type Max(const Type* ptValue, UGint nCount)
{
	assert(ptValue != NULL); //ptValue����Ϊ��
	Type tResult(ptValue[0]); 
	for(UGint i=1; i<nCount; i++)
	{
		tResult = ((ptValue[i]<tResult)? tResult : ptValue[i]);
	}
	return tResult;
}

//�õ���(��)��ֵ,���ñȽϷº���(С�ڱȽ�)
template<typename Type, typename Compare>
const Type& Max(const Type& tValue1, const Type& tValue2, Compare compare)
{
	return (compare(tValue1, tValue2)? tValue2 : tValue1);
}

//��nCount�����еõ����ֵ,���ñȽϷº���(С�ڱȽ�)
template<typename Type, typename Compare>
Type Max(const Type* ptValue, UGint nCount, Compare compare)
{
	assert(ptValue != NULL); //ptValue����Ϊ��
	Type tResult(ptValue[0]); 
	for(UGint i=1; i<nCount; i++)
	{
		tResult = (compare(ptValue[i], tResult)? tResult : ptValue[i]);
	}
	return tResult;
}

template<typename Type>
const Type& Min(const Type& tValue1, const Type& tValue2)
{
	return ( (tValue2<tValue1)? tValue2 : tValue1);
}

//��nCount�����еõ���Сֵ
template<typename Type>
Type Min(const Type* ptValue, UGint nCount)
{
	assert(ptValue != NULL); //ptValue����Ϊ��
	Type tResult(ptValue[0]); 
	for(UGint i=1; i<nCount; i++)
	{
		tResult = ((tResult<ptValue[i])? tResult : ptValue[i]);
	}
	return tResult;
}

//�õ���(��)Сֵ,���ñȽϷº���(С�ڱȽ�)
template<typename Type, typename Compare>
const Type& Min(const Type& tValue1, const Type& tValue2, Compare compare)
{
	return (compare(tValue2,tValue1)? tValue2 : tValue1);
}

//��nCount�����еõ���Сֵ,���ñȽϷº���(С�ڱȽ�)
template<typename Type, typename Compare>
Type Min(const Type* ptValue, UGint nCount, Compare compare)
{
	assert(ptValue != NULL); //ptValue����Ϊ��
	Type tResult(ptValue[0]); 
	for(UGint i=1; i<nCount; i++)
	{
		tResult = (compare(tResult, ptValue[i])? tResult : ptValue[i]);
	}
	return tResult;
}
template<typename Type>
void Sort(Type* pBegin, Type* pEnd)
{
	std::sort(pBegin,pEnd);
}
template<typename Type, typename Compare>
void Sort(Type* pBegin, Type* pEnd, Compare compare)
{
	std::sort(pBegin,pEnd,compare);
}
// StableSort, ����ͬSort, ��������StableSort��֤���Ԫ�ص�ԭ������������󱣳ֲ���
template<typename Type>
void StableSort(const Type* pBegin, const Type* pEnd)
{
	std::stable_sort(pBegin, pEnd);
}

template<typename Type, typename Compare>
void StableSort(const Type* pBegin, const Type* pEnd, Compare compare)
{
	std::stable_sort(pBegin, pEnd, compare);
}

//! \brief ����������֮��Ĳ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type>
void Difference(const Type* pBegin1, const Type* pEnd1, 
				const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief ����������֮��Ĳ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type, typename Compare>
void Difference(const Type* pBegin1, const Type* pEnd1, 
				const Type* pBegin2, const Type* pEnd2, 
				UGArray<Type>&arrResult, Compare compare)
{
	std::set_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief ����������֮��Ľ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type>
void Intersection(const Type* pBegin1, const Type* pEnd1, 
				  const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_intersection(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief ����������֮��Ľ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type, typename Compare>
void Intersection(const Type* pBegin1, const Type* pEnd1, 
				  const Type* pBegin2, const Type* pEnd2, 
				  UGArray<Type>&arrResult, Compare compare)
{
	std::set_intersection(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief ����������֮��ĶԳƲ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type>
void SymmetricDifference(const Type* pBegin1, const Type* pEnd1, 
						 const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_symmetric_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief ����������֮��ĶԳƲ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type, typename Compare>
void SymmetricDifference(const Type* pBegin1, const Type* pEnd1, 
						 const Type* pBegin2, const Type* pEnd2, 
						 UGArray<Type>&arrResult, Compare compare)
{
	std::set_symmetric_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief ����������֮��Ĳ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type>
void Union(const Type* pBegin1, const Type* pEnd1, 
		   const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_union(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief ����������֮��Ĳ�
//! \remarks arrResultԭ�����ݻᱻ����,�ռ䲻�����Զ�����
template<typename Type, typename Compare>
void Union(const Type* pBegin1, const Type* pEnd1, 
		   const Type* pBegin2, const Type* pEnd2, 
		   UGArray<Type>&arrResult, Compare compare)
{
	std::set_union(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief �ü����е�Ԫ�ز��ظ�
//! \param pBegin ���Ͽ�ʼָ��
//! \param pEnd ���Ͻ���ָ��
//! \remarks �ڵ���Unique֮ǰ,���ϱ�����ͨ������,�����������򼯺�
//!			 �����,��֤ǰ�����ɸ�Ԫ�ز��ظ�
//!			 �ڲ�����stl�е�unique�㷨����ʵ��
//! \return ���ز��ظ�Ԫ�صĸ���
template<typename Type>
UGuint Unique(Type* pBegin, Type* pEnd)
{
	return std::unique(pBegin, pEnd) - pBegin;
}

//! \brief �ü����е�Ԫ�ز��ظ�
//! \param pBegin ���Ͽ�ʼָ��
//! \param pEnd ���Ͻ���ָ��
//! \param Compare Ԫ�رȽ϶���
//! \remarks �ڵ���Unique֮ǰ,���ϱ�����ͨ������,�����������򼯺�
//!			 �����,��֤ǰ�����ɸ�Ԫ�ز��ظ�
//!			 �ڲ�����stl�е�unique�㷨����ʵ��
//! \return ���ز��ظ�Ԫ�صĸ���
template<typename Type, typename Compare>
UGuint Unique(Type* pBegin, Type* pEnd, Compare compare)
{
	return std::unique(pBegin, pEnd, compare) - pBegin;
}

//! \brief �ü����е�Ԫ�ز��ظ�
//! \param pBegin ���Ͽ�ʼָ��
//! \param pEnd ���Ͻ���ָ��
//! \param pOut ����ļ���ָ��
//! \remarks �ڵ���UniqueCopy֮ǰ,���ϱ�����ͨ������,�����������򼯺�;��pOut���㹻�Ŀռ�(��С�ڷ���ֵ)
//!			 �����,��֤pOutǰ�����ɸ�Ԫ�ز��ظ�
//!			 �ڲ�����stl�е�unique�㷨����ʵ��
//! \return ���ز��ظ�Ԫ�صĸ���
template<typename Type>
UGuint UniqueCopy(Type* pBegin, Type* pEnd, Type* pOut)
{
	return std::unique_copy(pBegin, pEnd, pOut) - pOut;
}

//! \brief �ü����е�Ԫ�ز��ظ�
//! \param pBegin ���Ͽ�ʼָ��
//! \param pEnd ���Ͻ���ָ��
//! \param pOut ����ļ���ָ��
//! \param Compare Ԫ�رȽ϶���
//! \remarks �ڵ���UniqueCopy֮ǰ,���ϱ�����ͨ������,�����������򼯺�;��pOut���㹻�Ŀռ�(��С�ڷ���ֵ)
//!			 �����,��֤pOutǰ�����ɸ�Ԫ�ز��ظ�
//!			 �ڲ�����stl�е�unique�㷨����ʵ��
//! \return ���ز��ظ�Ԫ�صĸ���
template<typename Type, typename Compare>
UGuint UniqueCopy(Type* pBegin, Type* pEnd, Type* pOut, Compare compare)
{
	return std::unique_copy(pBegin, pEnd, pOut, compare) - pOut;
}

}

#endif

