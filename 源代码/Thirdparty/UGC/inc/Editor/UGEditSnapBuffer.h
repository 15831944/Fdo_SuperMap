// UGEditSnapBuffer.h: interface for the UGEditSnapBuffer class.
//
//=====================================================================================
// ��Ŀ����			Supermap Foundation Class (SFC) Library 2.0
// ��  �ߣ�			�ιظ�
// ��  λ��			������ͼ������Ϣ�������޹�˾
// ����޸�ʱ�䣺	���ļ�����Ϊ׼
//-------------------------------------------------------------------------------------
// ��Ҫ������		1. ���ʹ�÷�ΧΪSupermap GIS����������Ա��δ����ɲ������Դ�����
//					2. ���ʹ���߲����޸ı��ļ����ݣ�����ᵼ�����ʹ�ô���
//					
//-------------------------------------------------------------------------------------
// �ļ�����			UGEditSnapBuffer.h
// ��  ����			UGEditSnapElement��UGEditSnapBuffer
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		UGEditSnapElement:��׽��¼Ԫ��
//					UGEditSnapBuffer:�ṩ��׽Ԫ�ض�ջ
// ����˵����		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITSNAPBUFFER_H__DECB27E6_E117_11D2_A58F_0080C8EE6684__INCLUDED_)
#define AFX_UGEDITSNAPBUFFER_H__DECB27E6_E117_11D2_A58F_0080C8EE6684__INCLUDED_

#include "Base/ugexports.h"
#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Base/UGList.h"
#include "Algorithm/UGRect2D.h"
#include "Editor/UGEditDef.h"
#include "Map/UGLayer.h"


namespace UGC {


class EDITOR_API UGEditSnapElement
{
public:
	UGEditSnapElement();
    UGEditSnapElement(UGuint uAction ,UGint nID,UGLayer* pLayer );
	virtual ~UGEditSnapElement();
public:
	//���ò�׽������
	//uActionΪ����׽���ͳ���
    void    SetValue( UGuint uAction);

	//��ò�׽����
    UGuint	GetValue();

	//������ͼ�ص�ˮƽ����ֱ����ͱ��ͼ�ص��غϡ��ߺ�����ͼ���ཻ
	//����׽���ĵ�ӵ���׽Ԫ����
    UGbool    SetPoint  ( const UGPoint2D& pnt2D );

	//������ͼ�ص�ˮƽ����ֱ����ͱ��ͼ�ص��غϡ��ߺ�����ͼ���ཻ
	//�Ӳ�׽Ԫ���ж�����׽��
    UGbool    GetPoint  ( UGPoint2D& pnt2D );

	//�߶�ˮƽ����ֱ���̶����ȡ�ͬһ�߶γɹ̶��Ƕȡ�������ͼ���߶�ƽ�С�������ͼ���߶δ�ֱ
	//����׽���ĵ�ӵ���׽Ԫ����
    UGbool    SetPoint  ( const UGPoint2D& pnt2D1, const UGPoint2D& pnt2D2 );

	//�߶�ˮƽ����ֱ���̶����ȡ�ͬһ�߶γɹ̶��Ƕȡ�������ͼ���߶�ƽ�С�������ͼ���߶δ�ֱ
	//�Ӳ�׽Ԫ���ж�����׽��
    UGbool    GetPoint  ( UGPoint2D& pnt2D1, UGPoint2D& pnt2D2 );
	
	//���ڱ��ͼ�����ϡ���������ͼ�ص��е㡢����������ͼ�ص��ӳ�����ʱ
	//����׽�ӵ��ĵ�ӵ���׽Ԫ����
    UGbool    SetPoint  ( const UGPoint2D& pnt2D1, const UGPoint2D& pnt2D2 , const UGPoint2D& pnt2D3 );
	
	//���ڱ��ͼ�����ϡ���������ͼ�ص��е㡢����������ͼ�ص��ӳ�����ʱ
	//�Ӳ�׽Ԫ���ж�����׽��
    UGbool    GetPoint  ( UGPoint2D& pnt2D1, UGPoint2D& pnt2D2 , UGPoint2D& pnt2D3 );
	
	//����ָ�����ϵ�ָ���ڵ�
    UGbool    SetLineIndex( UGint lLineIndex, UGint lVertexIndex );
	
	//ȡ�ò�׽Ԫ�ص�ָ�����ϵ�ָ���ڵ�
    UGbool    GetLineIndex( UGint& lLineIndex, UGint& lVertexIndex );

	//�ж�������׽Ԫ���Ƿ���ͬ
    UGbool    IsSameOne   ( const UGEditSnapElement* pElement );

	//�Ƿ�Ӧ��ɾ��ָ��Ԫ��
    UGbool    IsDeleteLine( const UGEditSnapElement* pElement );

	//�ж�һ����׽Ҫ���Ƿ�����
    UGbool    IsSelfUseful( const UGEditSnapElement* pElement );

		
	//���༭���߶ι�ĳһ��ʱ������׽���Ľڵ�ӵ�������
	//point2D:��׽���ĵ������
	//bPrev:�Ƿ�Ϊǰһ���߶�
    UGbool    GetSnapAddPoint( UGPoint2D& pnt2D, UGbool& bPrev );

	//added by xielin 2007-05-31
	//! \brief ��ȡ�ò�׽�����ID
	UGint	  GetID();

	//added by xielin 2007-05-31
	//! \brief ���øò�׽�����ID
	void	  SetID(UGint nID);

	//! \brief ��ȡ�ò�׽��������ͼ��ָ��
	UGLayer*	  GetLayer();

	//added by xielin 2007-05-31
	//! \brief ���øò�׽��������ͼ��ָ��
	void	  SetLayer(UGLayer* pLayer);

public:
//Attribute
    UGuint            m_uAction;
    UGPoint2D*       m_pPoints;
    UGint            m_lLineIndex;
    UGint            m_lVertexIndex;

	//added by xielin 2007-05-31  ���Ӹò�׽����������ͼ��ָ��͸ö����id�����ظ��û�
	//�ܹ����ظ��û�����Ϣ�У�ID��pLayer��SnapAction��SnapedPoints�����������Ѿ�����
	UGint			m_nID;
	UGLayer*       m_pLayer;
	//added by xielin 2007-05-31 end
};

typedef UGList<UGEditSnapElement*> UGEditSnapElementList;

class EDITOR_API UGEditSnapBuffer  
{
public:
//Implement of structure
	UGEditSnapBuffer();
	virtual ~UGEditSnapBuffer();

//Implement of resolvent
    UGint     GetMaxSize();
    void    SetMaxSize( UGint uSize );
    UGbool    Push ( UGEditSnapElement* pElement );
    UGbool    Pop  ( UGEditSnapElement** ppElement );
	
	//���༭���߶ι�ĳһ��ʱ������׽���Ľڵ�ӵ�������
	//point2D:��׽���ĵ������
	//nIndex:��׽Ԫ�ص�����
	//bPrev:�Ƿ�Ϊǰһ���߶�
    UGbool    GetSnapAddPoint( UGPoint2D& pnt2D, UGint& nIndex, UGbool& bPrev );

	//ͨ��������ȡ�ò�׽���ߵ���������Ӧ�ڵ�ĵ�����
    UGbool    GetLineIndex( UGint& nIndex, UGint& lLineIndex, UGint& lVertexIndex );

	//�ж�һ����׽Ҫ���Ƿ��Ѵ���
    UGbool    IsUnique( const UGEditSnapElement* pNewElement );

	//�ж�һ����׽Ҫ���Ƿ�����
    UGbool    IsUseful( UGEditSnapElement* pNewElement );

	//ɾ��û�õĲ�׽Ԫ��
    UGbool    DeleteSnapedLine( const UGEditSnapElement* pNewElement );

	//�������ò�׽������
    UGbool    ReSet();


    UGbool    ResetSP();

public:
//Attribute 
    UGRect2D                 m_rcLast;           // for user invalid rect
    UGuint                    m_uSnapType;        // user have done snap type
    UGint                     m_nBufferMaxSize;   // max length of the buffer
    UGint                     m_nSP;
    UGEditSnapElementList m_listBuffer;       // buffer body
};

}

#endif // !defined(AFX_UGEDITSNAPBUFFER_H__DECB27E6_E117_11D2_A58F_0080C8EE6684__INCLUDED_)
