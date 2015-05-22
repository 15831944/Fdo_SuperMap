/*! \file 		UGColorTable.h
*   \brief 		�ֲ���ɫ��ɫ�� 
*   \remarks 	��UGColorset�Ľ��,֧�ֲַ���ɫ�ͼ��������ɫ
*   \author 	LIWENLONG 
*   \date 	2005-02-24 08:56:16
*	\attention
*   Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br> 
*        All Rights Reserved 

*    <b>����˵����</b><br> 
*/ 


#ifndef UGColorTable_H
#define UGColorTable_H

#include "ugdefs.h"
#include "UGString.h"
#include "UGArray.h"
#include "UGColorset.h"

namespace UGC {

class BASE_API UGColorTable
{
public:
	UGColorTable();
	virtual ~UGColorTable();

public:

	UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	UGString ToXML(UGint nVersion = 0, const UGString& strElemName = ("")) const;
	
	//! \brief 		�õ���ɫ��
	//! \return 	UGint
	//! \remarks 		
	UGint GetSize();

	//! \brief 		������ɫ��
	//! \return 	void
	//! \param 		nNewValue
	//! \remarks 		
	void SetSize(UGint nNewValue);

	//! \brief 		����ɫnColor������ɫ��
	//! \return 	UGlong
	//! \param 		nColor
	//! \remarks 		
	UGlong AddColor(UGColor nColor);

	//! \brief 		�����ɫ
	//! \return 	UGlong
	//! \param 		Red
	//! \param 		Green	Red,Green,Blue��RGB����
	//! \param 		Blue
	//! \remarks 		
	UGlong Add(UGuchar Red, UGuchar Green, UGuchar Blue);

	//! \brief 		ת��ColorFolder
	//! \return 	UGbool
	//! \param 		&colorFolder
	//! \remarks 		
	UGbool ToColorset(UGColorset &colorset);

	//! \brief 		ת��ColorFolder
	//! \return 	UGbool
	//! \param 		&colorFolder
	//! \remarks 		
	UGbool FromColorset(const UGColorset &colorset);

	//! \brief 		��������ȡ����ɫ
	//! \return 	UGColor
	//! \param 		nIndex
	//! \remarks 		
	UGColor GetRGB(UGint nIndex);

	//! \brief 		�޸���ɫ���е���ɫ
	//! \return 	void
	//! \param 		nIndex
	//! \param 		nNewValue
	//! \remarks 		
	void SetColor(UGint nIndex, UGint nNewValue);

#if PACKAGE_TYPE==PACKAGE_UGC

	//! \brief 		���ݸ߶�ȡ����ɫ����������Ӧ���ڷֲ���ɫ
	//! \return 	UGbool
	//! \param 		z
	//! \param 		r
	//! \param 		g
	//! \param 		b
	//! \remarks 		
	UGbool GetColor(UGdouble z,UGdouble& r,UGdouble& g,UGdouble& b);
	
		
	//! \brief 		���ݷ������������ float NormalV0�ǰ�������������Ԫ����(x,y,z).
	//! \return 	UGfloat
	//! \param 		NormalV0[]
	//! \remarks 		
	UGfloat GetLightRatio(UGfloat NormalV0[]);

	//! \brief 		�õ����պ����ɫ
	//! \return 	UGlong
	//! \param 		z			�߳�:���ݸ߳�ֵ->�߳���ɫ
	//! \param 		NormalV0[]	NormalV0��������Ԫ��:  ������->���ձ���
	//! \remarks 		
	UGlong GetLightenColor(UGdouble z,UGfloat NormalV0[]);
	
	//! \brief 		��Сz�߶�
	//! \return 	UGdouble
	//! \remarks 		
	UGdouble GetZFloor()const;

	//! \brief 		������Сz�߶�
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetZFloor(UGdouble newValue);

	//! \brief 		���z�߶�
	//! \return 	UGdouble
	//! \remarks 		
	UGdouble GetZCeiling()const;

	//! \brief 		�������z�߶�
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetZCeiling(UGdouble newValue);

	//! \brief 		���ˮ�߸߶�
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	UGdouble GetWaterLevel();

	//! \brief 		����ˮ�߸߶�
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetWaterLevel(UGdouble newValue);

	//! \brief 		��Դ��x����
	//! \return 	UGfloat
	//! \remarks 		
	UGfloat GetLightX();

	//! \brief 		���ù�Դ��x����
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetLightX(UGfloat newValue);

	//! \brief 		��Դ��y����
	//! \return 	UGfloat
	//! \remarks 		
	UGfloat GetLightY();

	//! \brief 		���ù�Դ��y����
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetLightY(UGfloat newValue);

	//! \brief 		��Դ��z����
	//! \return 	UGfloat
	//! \remarks 		
	UGfloat GetLightZ();

	//! \brief 		���ù�Դ��z����
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetLightZ(UGfloat newValue);

	//! \brief 		��ɫ���ߵ�����
	//! \return 	void
	//! \remarks 		
	void SwapIndex();

	//! \brief 		��ɫ������������
	//! \return 	void
	//! \remarks 		
	void SwapRedBlue();

	//! \brief 		������ɫ������ɫ������ɫ���ɵ�ǰm_Colorset����Ŀ����
	//! \return 	UGint
	//! \remarks 		
	UGint CreateGrey();

	//! \brief 		������ɫ������ɫ������ɫ���ɵ�ǰm_Colorset����Ŀ����
	//! \return 	UGlong
	//! \remarks 		
	UGint CreateRed();

	//! \brief 		������ɫ������ɫ������ɫ���ɵ�ǰm_Colorset����Ŀ����
	//! \return 	UGint
	//! \remarks 		
	UGint CreateGreen();

	//! \brief 		������ɫ������ɫ������ɫ���ɵ�ǰm_Colorset����Ŀ����
	//! \return 	UGuint
	//! \remarks 		
	UGint CreateBlue();

	//! \brief 		�������ν�����ɫ������ɫ���ɵ�ǰm_Colorset����Ŀ����
	//! \return 	UGint
	//! \remarks 	�������ˮ�ߣ���ôҪ��ʼ������COLORSET	
	UGint CreateDefault();
	
	//! \brief 		���ļ���������ɫ��
	//! \return 	UGlong
	//! \param 		strFileName
	//! \remarks 	��δʵ��	
	UGlong Open(LPCTSTR strFileName);

	//! \brief 		����ɫ��д���ļ�
	//! \return 	UGlong
	//! \param 		strFileName
	//! \remarks 	��δʵ��
	UGlong Save(LPCTSTR strFileName);
	
		//! \brief 		���ݸ߶�ȡ����ɫ������Ӧ���ڷֲ���ɫ
	//! \return 	UGColor
	//! \param 		dZValue
	//! \remarks 		
	UGColor GetColor(UGdouble dZValue);
	
		//! \brief 		���ɽ�����ɫ��
	//! \return 	UGint
	//! \param 		nCount				��ɫ��
	//! \param 		nStockGradientStyle ��ɫ������
	//! \param 		FALSE				�Ƿ���
	//! \remarks 		
	UGint CreateStockGradient(UGint nCount, UG_ENUM_STOCK_GRADIENT_SET_STYLE nStockGradientStyle, UGbool bReverse = FALSE);

	//! \brief 		���㽥����ɫ��
	//! \return 	UGint
	//! \param 		nCount		��ɫ����	
	//! \param 		colorStart
	//! \param 		colorEnd	��ʼ�ͽ�����ɫֵ
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ���	
	UGint CreateGradient(UGint nCount, UGColor colorStart,UGColor colorEnd);

	//! \brief 		���ݸ߶�ȡ����ɫ
	//! \return 	UGColor
	//! \param 		ZValue
	//! \remarks 		
	UGColor InterColor(UGdouble ZValue);
	
		//! \brief 		ȡ�ú���ɫ����
	//! \return 	UGshort
	//! \param 		nIndex
	//! \remarks 		
	UGshort GetRed(UGint nIndex);

	//! \brief 		���ú���ɫ����
	//! \return 	void
	//! \param 		nIndex
	//! \param 		nNewValue
	//! \remarks 		
	void SetRed(UGint nIndex,UGuchar nNewValue);

	//! \brief 		ȡ������ɫ����
	//! \return 	UGshort
	//! \param 		nIndex
	//! \remarks 		
	UGshort GetGreen(UGint nIndex);

	//! \brief 		��������ɫ����
	//! \return 	void
	//! \param 		nIndex
	//! \param 		nNewValue
	//! \remarks 		
	void SetGreen(UGint nIndex,UGuchar nNewValue);

	//! \brief 		ȡ������ɫ����
	//! \return 	UGshort
	//! \param 		nIndex
	//! \remarks 		
	UGshort GetBlue(UGint nIndex);

	//! \brief 		������ɫ����
	//! \return 	void
	//! \param 		nIndex
	//! \param 		nNewValue
	//! \remarks 		
	void SetBlue(UGint nIndex,UGuchar nNewValue);

private:
	UGColor InterColor(UGColorset &colorset,UGdouble dUpperLimit,UGdouble dLowerLimit,UGdouble ZValue);
#endif // end declare ugc sdk

	UGColorTable(const UGColorTable&);
	UGColorTable& operator=(const UGColorTable&);

public:
	UGColorset m_Colorset;
	
#if PACKAGE_TYPE==PACKAGE_UGC
public:
	UGColorset m_ColorsetWater;
protected:
	//��������.
	UGfloat	m_dLightX,m_dLightY,m_dLightZ;

	UGdouble m_dZMax, m_dZFloor,m_dZWaterLevel;

private:
	UGbool m_bWaterLevel;
#endif // end declare ugc sdk
};

}

#endif
