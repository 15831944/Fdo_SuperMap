// SmEditToolSnapPack.h: interface for the UGEditToolSnapPack class.
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
// �ļ�����			SmEditToolSnapPack.h
// ��  ����			UGEditToolSnapPack
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		���Ʋ�׽��Դ�㡢Դ��
// ����˵����		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITTOOLSNAPPACK_H__BFEE1573_E724_11D2_A5A2_0080C8EE6684__INCLUDED_)
#define AFX_UGEDITTOOLSNAPPACK_H__BFEE1573_E724_11D2_A5A2_0080C8EE6684__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Base/ugexports.h"
#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Geometry/UGGeometry.h"
#include "Editor/UGEditDef.h"


namespace UGC {


class EDITOR_API UGEditToolSnapPack  
{
//Construct/Destruct
public:
	UGEditToolSnapPack();
	virtual ~UGEditToolSnapPack();
	
	//���ò�׽���߰���һЩ������Ϣ
	//uSnapPackType:
	//pPntSnaping:
	//uChangedType:
	//pObj:
	//nSnapHandle:
    void SetValue(  UGuint                uSnapPackType,
                    UGPoint2D*           pPntSnaping,
                    UGuint                uChangedType = AFC_SNAP_CHANGED_NONE,
                    UGGeometry*        pObj = NULL,
                    UGint                 nSnapHandle = 0 );
	
	//���ò�׽��
    void SetSnapedLine( const UGPoint2D& pnt1, const UGPoint2D& pnt2 );
	
	//ȡ�ò�׽��
    UGbool GetSnapedLine( UGPoint2D& pnt1, UGPoint2D& pnt2 );

	//��ղ�׽���߰�����
    void Reset();
//Attrubute
public:
    UGuint   m_uSnapPackType;//��׽���߰�����
    UGuint   m_uChangedType;//���Ըı�Ĳ�׽����
    UGPoint2D*   m_pPntSnaping;//��ǰ�Ĳ�׽Դ��
    UGGeometry* m_pObj;//�༭����

    UGint  m_nSnapHandle;//��׽���
protected:
    UGPoint2D*   m_pPntSnapedLine;//��ǰ���в�׽����
};

}

#endif // !defined(AFX_AFCEDITTOOLSNAPPACK_H__BFEE1573_E724_11D2_A5A2_0080C8EE6684__INCLUDED_)
