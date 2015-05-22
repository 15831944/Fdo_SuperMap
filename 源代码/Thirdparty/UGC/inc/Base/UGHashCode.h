// UGHashCode.h: interface for the UGHashCode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGHASHCODE_H__655A005A_77A3_426D_B890_151E99E6F0F3__INCLUDED_)
#define AFX_UGHASHCODE_H__655A005A_77A3_426D_B890_151E99E6F0F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base/ugdefs.h"
#include "Base/UGString.h"
namespace UGC {
class BASE_API UGHashCode  
{
public:
	UGHashCode();
	virtual ~UGHashCode();
public:
	static UGint LONGToHashCode(UGlong nValue);
	static UGint ShortToHashCode(UGshort nValue);
	static UGint StringToHashCode(const UGString& strValue);
	static UGint BoolToHashCode(UGbool bValue);
	static UGint PointerToHashCode(void* pValue);
	static UGint DoubleToHashCode(UGdouble dValue);
	static UGint FloatToHashCode(UGfloat fValue);
	static UGint ByteToHashCode(UGbyte btValue);

	//! \brief ���ٰ��ַ���ת��ΪHashCode
	//! \remarks ����Ҫ��SFC���ּ���,StringToHashCode�н�����Unicode��ת��,�ǳ���ʱ
	//! ��������Ҫ���ּ��ݵĵط�,�������������,�ٶȿ�ܶ�
	static UGint FastStringToHashCode(const UGString& strValue);
};
}
#endif // !defined(AFX_UGHASHCODE_H__655A005A_77A3_426D_B890_151E99E6F0F3__INCLUDED_)
