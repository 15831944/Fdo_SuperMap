// UGLineSymBaseData.h:

#if !defined(UG_LINESYMBASEDATA_H)
#define UG_LINESYMBASEDATA_H

#include "Base/UGString.h"

namespace UGC 
{
	
class SYMBOL_API UGLineSymBaseData  
{
public:
	friend class UGLineSymbolBase;

public:
	/** ���ߵķ������
		@remarks
		   1.ϵͳ�ڲ�������49�ַ�������
		   2.��ͬ���������о��岻ͬ�Ļ��Ʒ���
		   3.������Щ������ͣ���Щ���Ա�Ĳ�����Ϣ���ò�����
	*/
	enum StyleType
	{
		DSV_DEFAULT					=0,			//�̺���(ϵͳ����)

		DSV_VCENTER 				=1,			//������(���Ķ���)
		DSV_VUP						=2,			//������(�ϱ߶���)
		DSV_VDOWN					=3,			//������(�±߶���)

		DSV_VUPDOWN					=4,			//���½���
		DSV_VSHORTLONGUP			=5,			//���̽���(����)
		DSV_VSHORTLONGDOWN			=6,			//���̽���(����)
		DSV_VSHORTLONGUPDOWN		=7,			//���̽���(�ϳ��¶�)
		DSV_VSHORTLONGDOWNUP		=8,			//���̽���(�϶��³�)

		DSV_VBEVEL					=9,			//��б��( \ )
		DSV_VBEVEL2					=10,		//��б��( / )
		DSV_VBEVELUPDOWN			=11,		//��б��(���½���)

		DSV_VTRIANGLE				=12,		//��ͷʽ( < )
		DSV_VTRIANGLE2				=13,		//��ͷʽ( > )

		DSV_VWAVE					=14,		//������
		DSV_VWALL					=15,		//���Ƿ���5
		DSV_VBOX					=16,		//������

		DSV_VUPDOWNCROSS			=17,		//��������
		DSV_VXCROSS					=18,		//�������( X )
		DSV_VCROSSUP				=19,		//�������(����)
		DSV_VCROSSDOWN				=20,		//�������(����)
		DSV_VCROSSUPDOWN			=21,		//�������(���½���)

		DSV_VBIARCUP				=22,		//��Բ��(����)
		DSV_VBIARCDOWN				=23,		//��Բ��(����)
		DSV_VBIARCUPDOWN			=24,		//��Բ��(���½���)

		DSV_VCIRCLESOLID			=25,		//Բ��(ʵ�ġ�������)
		DSV_VCIRCLEHOLLOW			=26,		//Բ��(���ġ�������)
		DSV_VCIRCLEUPDOWN			=27,		//Բ��(���½���)

		DSV_VTRUETYPEHORIZON		=28,		//���ͷ���(ˮƽ)
		DSV_VTRUETYPEHORIZONREV		=29,		//���ͷ���(ˮƽ����)
		DSV_VTRUETYPEVERTICAL		=30,		//���ͷ���(��ֱ)
		DSV_VTRUETYPEVERTICALREV	=31,		//���ͷ���(��ֱ����)
		DSV_VTRUETYPEFIXED			=32,		//���ͷ���(�̶�����)
		DSV_VTRUETYPEFREEANGLE		=33,		//���ͷ���(���ɽǶȷ���)

		DSV_DASHWITHTAILARROW		=34,		//���ߴ�β��ͷ->
		DSV_DASHWITHHEADERARROW		=35,		//���ߴ�ͷ��ͷ<-
		DSV_DASHWITHDOUBLEARROW		=36,		//���ߴ�˫��ͷ<->
		DSV_DASHWITHMIDIUMARROW		=37,		//�����м������ͷ->-
		DSV_DASHWITHMIDIUMREVERSEARROW=38,		//�����м������-<-

		DSV_ELECTRIC				=39,		//�����߶�
		DSV_ELECTRICEX				=40,		//�����߶�(���м���)
		DSV_ELECTRIC_SPECIAL		=41,		//�����߶�(����)
		DSV_ELECTRICEX2				=42,		//�����߶�(Բ��)

		DSV_DOUBLEPARELLEL			=43,		//ƽ��˫��(���Ķ���)
		DSV_LEFTPARELLEL			=44,		//ƽ��˫��(�ϱ߶���)
		DSV_RIGHTPARELLEL			=45,		//ƽ��˫��(�±߶���)

		DSV_GRADIENT				=46,		//������

		DSV_SYMBOL					=47,		//�Զ�����ţ���ԽǶȣ�
		DSV_SYMBOLFIXED				=48			//�Զ�����ţ��̶��Ƕȣ�			
	};

public:
	UGLineSymBaseData();
	~UGLineSymBaseData();

	//{{--���ڸ���ʹ��Ĭ�ϵĿ����Ͷ�����ok----commented by Y.M.Zheng--
	//UGLineSymBaseData(const UGLineSymBaseData& LineSymBaseData);
	//void operator = (const UGLineSymBaseData& LineSymBaseData);
	//}}--------------------------------------------------------------
	
	UGbool Load(UGStream& stream, UGuint nVersion = 0);
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

protected:
	UGbool Load_Version2003(UGStream& stream);
	UGbool Load_Version2005(UGStream& stream);
	UGbool Save_Version2003(UGStream& stream) const;
	UGbool Save_Version2005(UGStream& stream) const;
	
public:
	UGshort GetVertLength() const;
	void SetVertLength(UGshort nVertLength);
	
	StyleType GetStyleType() const;
	void SetStyleType(StyleType eType);
	
	UGshort GetHoriOffset() const;
	void SetHoriOffset(UGshort nHoriOffset);
	
	UGshort GetVertOffset() const;
	void    SetVertOffset(UGshort nVertOffset);
	

	//! �Ƿ�ˮƽ����: ���� ϵͳ�̺���������
	UGbool IsHoriRepair() const;
	//! �Ƿ�ֱ����: ���� ǰ���ֶ�����������
	UGbool IsVertRepair() const;
	
	UGbool IsPenFixedColor() const;
	UGbool IsPenFixedWidth() const;

	//! \brief ���ͻ���ʱ����Ƿ�̶���
	/**
	������ѡ�з�������ʱ���õ��Ƿ�̶����Ϳ����Ϣ��
	\return �Ƿ�̶���ȣ�1����̶���ȣ�0�����̶���Ĭ��Ϊ0��
	*/
	UGbool IsPenFixedLineWidth() const;
	UGint  GetPenJoinType() const;	
	UGint  GetPenCapType() const;	
	UGint  GetPenDotDashType() const;
	
	void SetHoriRepair(UGbool bHoriRepair);
	void SetVertRepair(UGbool bVertRepair);
	void SetPenFixedColor(UGbool bPenFixedColor);
	void SetPenFixedWidth(UGbool bPenFixedWidth);
	//! \brief ���ͻ���ʱ���ÿ���Ƿ�̶���
	/**
	�趨�Ƿ�̶����Ϳ�ȣ��ڷ��������¿���Ƿ�̶����䡣
	\param bPenFixedLineWidth  �Ƿ�̶����[in]
	*/
	void SetPenFixedLineWidth(UGbool bPenFixedLineWidth);
	void SetPenJoinType(UGint nPenJoin);
	void SetPenCapType(UGint nPenCap);		
	void SetPenDotDashType(UGint nPenStyle);
	
	UGColor GetFixedColor() const;
	void    SetFixedColor(UGColor color);
	UGint   GetFixedWidth() const;
	void    SetFixedWidth(UGint nWidth);
	
	UGString GetFontName() const;
	void SetFontName(const UGString& strFontName);

	UGint GetAsciiCode() const;
	void SetAsciiCode(UGint nCode);
	
	UGdouble GetAngle() const;
	void SetAngle(UGdouble dAngle);
	
	void Reset();
	
protected:
	//! ���ߵķ������(49����֮һ)
	StyleType  m_eStyleType;
	
	//! ���򳤶�(ֻ�Ծ������·����Եķ����������)
	UGshort m_nVertLength;

	//! �û��߻���ʱ��ˮƽ(����)ƫ����(����ǰ���ݸ�ֵ�������������Ƶ���ʼ�˵�)
	UGshort m_nHoriOffset;		

	//! �û��߻���ʱ�Ĵ�ֱ(����)ƫ����(����ǰ���ݸ�ֵ��������������ƫ�ƺ�����е�)
	UGshort m_nVertOffset;		
		
	/*   8 7 6 5 4 3 2 1---------- 1 ������ɫ�Ƿ�̶�
		 | | | | | | +------------ 2 ���ʿ���Ƿ�̶�
		 | | | | | +-------------- 3 �Ƿ�ˮƽ����
		 | | | | +---------------- 4 �Ƿ�ֱ����
		 | | | +------------------ 5 ��������ʱ�Ƿ�̶����ʿ��
		 | | +-------------------- 6 ����
		 | +---------------------- 7 ����
		 +------------------------ 8 */
	//! �������ԣ������еı���λ����־һЩ����
	UGint   m_nAttr;   

	/*��¼���ʵ�����������Ϣ���㻮���͡���ͷ���͡�ת������
	  ��1~4λ(��4λ)����¼PenDotDashStyle������
	  ��9~12λ(��4λ)����¼PenCap�Ķ�ͷ����
	  ��13~16λ(��4λ)����¼PenJoinת������*/
	//! �ڲ����ʵ����ʹ����ת�ǵ����ͷ��.0~7Ϊϵͳ����,>=8Ϊ�û���������,��MFC��������ͬ
	UGint   m_nPenStyle; 		    

	//! �������õĹ̶���ɫ(���m_nAttr�еĹ̶���ɫ��־λ�����ˣ��ڻ���ʱ��ʹ�ø�ֵ�����û�����ã���ֵ�Ͳ��ᱻ�õ�)
	UGColor m_FixedColor;		

	//! �������õĹ̶����(���m_nAttr�еĹ̶���ȱ�־λ�����ˣ��ڻ���ʱ��ʹ�ø�ֵ�����û�����ã���ֵ�Ͳ��ᱻ�õ�)
	UGshort m_nFixedWidth;
	
	//! �ַ���ת�Ƕ�(��λ:0.1��)(ֻ�����ͷ��ŷ������)  
	UGint   m_nAngle;		

	//! �ַ�ASCII��(ֻ�����ͷ��ŷ������)
	UGshort m_nAsciiCode;		

	//! ������������(ֻ�����ͷ��ŷ������)
	UGchar  m_FontName[32];		

	//! ��������
	UGint m_nReserved;
};

}//namespace UGC

#endif

