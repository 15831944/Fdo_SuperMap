
//UGLineSymbolBase.h

#ifndef UG_LINESYMBOLBASE_H
#define UG_LINESYMBOLBASE_H

#include "UGLineSymParam.h"
#include "UGLineSymBaseData.h"
#include "UGLineSymbolBaseDrawer.h"

namespace UGC 
{
class UGGraphics;
class UGPointSymbolLib;
	
	/** ���͵��߻�(���Ϊ���ߡ�����)
	    @remarks
		   1��һ�����������ɸ�������ɣ������ǹ������͵Ļ�����Ԫ��
		   2��������һϵ�еĲ�������������ͼʱ����Щ���������ƣ�
		   3���������и���Ҫ�ĸ����ʵģʽ���ȣ���������
		      ��ʵģʽ����2������ɣ�ʵ����+�鲿�֣�
			  ���ǵĳ������鲿�ֵĳ��Ⱥ�ʵ���ֵĳ�����ָ��
	*/
class SYMBOL_API UGLineSymbolBase
{

public:
	/** ��ʵģʽ��, ��¼ʵ���������ֵ�ģʽ���ȣ����������ǳɶԳ���
	   @note
	*/
	struct ModeLenPair
	{
		UGushort m_SolidPartLen;  //ʵ���ֵĳ���
		UGushort m_EmptyPartLen;  //�鲿�ֵĳ���
	};

public:
	UGLineSymbolBase();
	~UGLineSymbolBase();
	//UGLineSymbolBase(const UGLineSymbolBase& LineSymbolBase);
	//void operator = (const UGLineSymbolBase& LineSymbolBase);

public:
	//! ���߻�������UGLineSymbolBase�Ļ�������������������ί�и�UGLineSymbolBaseDrawer��ʵ��
	friend class UGLineSymbolBaseDrawer;
	
public:
	UGbool Load(UGStream& stream, UGuint nVersion = 0);
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;
	
	//! �����ƽӿ� �ø�����ȥ������pPointsָ��������
	void Draw(UGGraphics& graphics, 
			  const UGPoint* pPoints,
			  UGint nCount, 
			  UGLineSymParam& DrawingParam);
	
	void Reset();
	
	//{{------------��ʵģʽ����(ModeLen)������--------------------------
	UGint GetCountOfModeLens() const;
	const UGushort* GetModeLenData() const;
	void  RemoveModeLenAt(UGint nIndex);
	void  RemoveAllModeLens();
	void    GetModeLenAt(UGint nIndex, UGint& nSolidModeLen, UGint& nEmptyModeLen);
	void    SetModeLenAt(UGint nIndex, UGint nSolidModeLen, UGint nEmptyModeLen);
	void      AddModeLen(UGint nSolidModeLen, UGint nEmptyModeLen);
	void InsertModeLenAt(UGint nIndex, UGint nSolidModeLen, UGint nEmptyModeLen);
	//! \brief ���ͻ���ʱ����������ʾ��ʵ����
	/**
	�趨�Ƿ�������ʾ��ʵ�����ڷŴ���Сʱ����������ʾ���͡�
	\param bFixed  �Ƿ�������ʾ��ʵ��[in]
	\remarks Ĭ���»������ͻ���ô˷�����
	*/
	void SetCycleChange (UGbool bFixed);
	//! \brief ���ͻ���ʱ�Ƿ�������ʾ��ʵ����
	/**
	�õ��Ƿ�������ʾ��ʵ����
	\return �Ƿ�������ʾ��ʵ����1�����ǣ�0�����Ĭ��Ϊ1��
	*/
	UGbool IsCycleChange() const;
	//}}------------��ʵģʽ���ȹ�����--------------------------
	
	const UGLineSymBaseData& GetLineSymBaseData() const;
	void SetLineSymBaseData(const UGLineSymBaseData& LineSymBaseData);

public:
	//! �Ƿ������ͷ��ŷ��
	UGbool IsCharacterStyle() const;

	//! ���ػ��ߵķ������
	UGLineSymBaseData::StyleType GetStyleType()
	{
		return m_LineSymBaseData.GetStyleType();
	}

	//! �Ƿ���Ҫƫ��
	UGbool IsNeedOffset()
	{
		return IsNeedVertOffset() || IsNeedHoriOffset();
	}

	//! �Ƿ���Ҫ����ƫ��
	UGbool IsNeedVertOffset()
	{
		return m_LineSymBaseData.GetVertOffset() != 0 ;
	}

	//! �Ƿ���Ҫ����ƫ��
	UGbool IsNeedHoriOffset()
	{
		return  m_LineSymBaseData.GetHoriOffset() != 0 ;
	}

	UGbool IsSolidPartStarted() const
	{
		return m_bWhichPartStarted;
	}

	void SetWhichPartStarted(UGbool bWhichPart)
	{
		// bWhichPart == TRUE  -->ʵ����ʼ
		// bWhichPart == FALSE -->�鲿��ʼ
		m_bWhichPartStarted = bWhichPart;
	}

	UGLineSymBaseData m_LineSymBaseData;

protected:
	UGbool Load_Version2003(UGStream& stream);
	UGbool Load_Version2005(UGStream& stream);
	UGbool Save_Version2003(UGStream& stream)const;
	UGbool Save_Version2005(UGStream& stream)const;
	
protected:
	
	//! True��ʵ����ʼ���ƣ�False���鲿��ʼ����
	UGbool  m_bWhichPartStarted;

	//! �û��ߵ���ʵģʽ�ĳ���
	UGArray<ModeLenPair>  m_ModeLengths;

	//! ���ߵĻ�����(�������棬ϵͳ�й���һ��)������Polylineʱ���ɸû���������ɻ���
	static UGLineSymbolBaseDrawer m_Drawer;
	//! \brief �����Ƿ�������ʾ��ʵ����Ϣ��
	/**
	\remarks Ĭ��Ϊ1��
	*/
	UGbool m_bCycleChange;
};

}

#endif

