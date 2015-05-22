// UGColorset.h: interface for the UGColorset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGCOLORSET_H)
#define UGCOLORSET_H
#include "ugdefs.h"
#include "UGArray.h"
#include "UGStream.h"

namespace UGC{
#define MAXCOLORCOUNT 0x7fff

typedef struct UGRGB16  // 16λɫ��
{
	UGushort b : 5;		// ����ռ5λ
	UGushort g : 6;		// �̣�ռ6λ	
	UGushort r : 5;		// �죬ռ5λ

}UGRGB16, *LPUGRGB16;

typedef struct UGRGB24  //24λ���
{
	UGbyte blue;		//����ռ8λ
	UGbyte green;		//�̣�ռ8λ
	UGbyte red;			//�죬ռ8λ	
}UGRGB24, *LPUGRGB24;

#if PACKAGE_TYPE==PACKAGE_UGC

typedef enum tagSM_ENUM_STOCK_GRADIENT_SET_STYLE//������ɫ
{
	gtBlackWhite,			//��->��
	gtRedWhite,				//��->��
	gtGreenWhite,			//��->��
	gtBlueWhite,			//��->��
	gtYellowWhite,			//��->��
	gtPinkWhite,			//�ۺ�->��
	gtCyanWhite,			//��->��
	gtRedBlack,				//��->��
	gtGreenBlack,			//��->��
	gtBlueBlack,			//��->��
	gtYellowBlack,			//��->��
	gtPinkBlack,			//�ۺ�->��
	gtCyanBlack,			//��->��
	gtYellowRed,			//��->��
	gtYellowGreen,			//��->��
	gtYellowBlue,			//��->��
	gtGreenBlue,			//��->��
	gtGreenRed,				//��->��
	gtBlueRed,				//��->��
	gtPinkRed,				//��->��
	gtPinkBlue,				//��->��
	gtCyanBlue,				//��->��
	gtCyanGreen,			//��->��
	gtRainbow,				//��->��
	gtGreenOrangeViolet,	//��->�ۻ�->������	
	gtTerrain,				//���ν���,������ά��ʾЧ���Ϻ�
	gtSpectrum				//���׽���
}UG_ENUM_STOCK_GRADIENT_SET_STYLE;	
#endif // end declare ugc sdk

class BASE_API UGColorset:public UGArray<UGColor>
{
public:
	UGColorset();
	virtual ~UGColorset();
	
	void SetColorSize(UGint nSize);

#if PACKAGE_TYPE==PACKAGE_UGC
public:
	//! \brief 		���ɽ�����ɫ��
	//! \return 	UGint 
	//! \param 		nCount  ��ɫ��
	//! \param 		nIndex  ��ɫ������
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ���	
	UGint MakeStockRandom(UGint nCount, UGint nIndex,UGbool bReverse = FALSE);
	
	//! \brief 		���ɽ�����ɫ
	//! \return 	UGint
	//! \param 		nCount			��ɫ��
	//! \param 		btRedStart		
	//! \param 		btRedEnd
	//! \param 		btGreenStart    R,G,B��������ʼֵ����ֵֹ
	//! \param 		btGreenEnd
	//! \param 		btBlueStart
	//! \param 		btBlueEnd
	//! \param 		FALSE			�Ƿ�Ҷ�
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ���	
	UGint MakeRandom(UGint nCount, UGbyte btRedStart,UGbyte btRedEnd,
								UGbyte btGreenStart, UGbyte btGreenEnd,
								UGbyte btBlueStart,UGbyte btBlueEnd,
								UGbool bIsGray = FALSE);

	//! \brief 		���ɽ�����ɫ��
	//! \return 	UGint
	//! \param 		nCount					��ɫ��
	//! \param 		nStockGradientStyle     ��ɫ������
	//! \param 		bReverse=FALSE			�Ƿ���
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ���	
	UGint MakeStockGradient(UGint nCount, UG_ENUM_STOCK_GRADIENT_SET_STYLE nStockGradientStyle, UGbool bReverse=FALSE);
	
	//! \brief 		���ɽ�����ɫ��
	//! \return 	UGint
	//! \param 		&arrayControlColors  
	//! \param 		&arrayIntervals
	//! \remarks 	�������Ƶ�ǵȾཥ����ɫ�������У�arrayControlColorsΪ���Ƶ���ɫ����,
	//!				arrayIntervals�����¼ÿ�������Ƶ���ɫ֮�����ɫ����������Ϊ0�����
	//!				arrayIntervals����Ĵ�С�������arrayControlColors�����С��ȥһ������
	//!				arrayIntervals.GetSize()+1 == arrayControlColors.GetSize()������ɹ���
	//!				�������������ɵ���ɫ���ϴ�С���ô�СӦ�õ���arrayIntervals�и���֮�͡�
	UGint MakeGradient(UGColorset &arrayControlColors, UGArray<UGint> &arrayIntervals);
	

	//! \brief 		�������Ƶ�Ⱦཥ����ɫ��
	//! \return 	UGint
	//! \param 		nCount				nCountΪҪ���ɵ���ɫ�����е���ɫ����
	//! \param 		&arrayCotrolColors	Ϊ���Ƶ���ɫ����
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ�	
	UGint MakeGradient(UGint nCount, UGColorset &arrayCotrolColors);
		

	//! \brief 		
	//! \return 	UGint
	//! \param 		nCount		��ɫ����	
	//! \param 		colorStart
	//! \param 		colorEnd	��ʼ�ͽ�����ɫֵ
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ���	
	UGint MakeGradient(UGint nCount, UGColor colorStart, UGColor colorEnd);

	//! \brief	��ȫ���������
	UGint MakeRandom(UGint nCount);

	//! \brief	Colorset�Ĵ�ȡ
	UGbool Load(UGStream& stream);

	//! \brief	Colorset�Ĵ�ȡ
	UGbool Save(UGStream& stream);
	
#endif // end declare ugc API
	
};
}

#endif // !defined(UGCOLORSET_H)
