// UGDrawableGeometry.h: interface for the UGDrawableGeometry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGDRAWABLEGEOMETRY_H)
#define UGDRAWABLEGEOMETRY_H

#include "UGDrawable.h"
#include "UGPrimitiveSet.h"
#include "UGVector3.h"
#include "UGColorValue.h"
#include "UGVector2.h"
namespace UGC{

class GRAPHICS3D_API UGDrawableGeometry :public UGDrawable
{
public:
	enum AttributeBinding
	{
		BIND_OFF=0,
        BIND_OVERALL,
        BIND_PER_PRIMITIVE_SET,
        BIND_PER_PRIMITIVE,
        BIND_PER_VERTEX
	};
	typedef UGArray<UGPrimitiveSet*>PrimitiveSetList;
	//!\brief ���PrimitiveSet
	UGbool AddPrimitiveSet(UGPrimitiveSet* pPrimitiveSet);
	UGbool SetPrimitiveSet(UGint i, UGPrimitiveSet* pPrimitiveSet);
	UGbool InsertPrimitiveSet(UGint i,UGPrimitiveSet* pPrimitiveSet);
	UGbool RemovePrimitiveSet(UGint i,UGPrimitiveSet* pPrimitiveSet);
	UGint  GetPrimitiveCount();
	UGPrimitiveSet* GetPrimitiveSet(UGint nIndex);
	const UGPrimitiveSet* GetPrimitiveSet(UGint nIndex)const;

	//!\brief ������Ӧ�Ķ�������
	void SetVertexArray(UGVec3Array& array);
	UGVec3Array& GetVertexArray();
	const UGVec3Array& GetVertexArray()const;

	//!\brief�����ö�Ӧ��������Binding��ʽ
	void SetNormalBinding(AttributeBinding enBinding);
	AttributeBinding GetNormalBinding();

	//!\brief ����������Ϣ
	void SetNormalArray(UGVec3Array& array);
	UGVec3Array GetNormalArray();
	const UGVec3Array GetNormalArray()const;

	//!\brief�����ö�Ӧ����ɫ�� Binding ��ʽ
	void SetColorBinding(AttributeBinding enBinding);
	AttributeBinding GetColorBinding();

	//!\brief ������ɫ����
	void SetColorArray(UGColorArray& array);
	UGColorArray& GetColorArray();
	const UGColorArray& GetColorArray()const;

	//!\brief ���ö�Ӧ����������
	void SetTexCoordArray(UGint nUnit, UGVec2Array& array);
	UGVec2Array& GetTexCoordArray(UGint nUnit);
	const UGVec2Array& GetTexCoordArray(UGint nUnit)const;
	//!\brief���õ���Ӧ����������ĸ���UGC��������������ĿΪ8
	UGint GetTexCoordCount();

	void Draw(UGGraphics3D* pGraphics3D);

public:
	UGDrawableGeometry();
	virtual ~UGDrawableGeometry();
protected:
	//�����Ժ�϶���Ҫ�����µ�����
	
	//!\brief �Ӷ�������
	PrimitiveSetList m_PrimitiveSets;
	
	//!\brief ��������
	UGVec3Array  m_VertexArray;

	//! Normal���ݵ�Binding��ʽ
	AttributeBinding m_enNormalBinding;
	
	//! \brief ��������
	UGVec3Array  m_NormalArray;

	//!\brief Color���ݵ�Binding��ʽ
	AttributeBinding  m_enColorBinding;
	
	//! \brief ��ɫ����
	UGColorArray m_ColorArray;

	//��ʱֻʵ�ֶ�ά����
	
	//!\brief ��������
	UGArray<UGVec2Array> m_TexCoordArray;
};

}

#endif // !defined(AFX_UGDRAWABLEGEOMETRY_H__57376EE3_0263_4AF0_A987_1B37E14AB2C5__INCLUDED_)
