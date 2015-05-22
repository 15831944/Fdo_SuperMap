// UGSphere.h: interface for the UGSphere class.


#if !defined(UG_SPHERE_H)
#define UG_SPHERE_H

#include <Graphics3D/UGVector3.h> //�Ѿ�����UGMath.h

namespace UGC
{

    /** ����һ����
    @remarks
        ���巽�̣�x^2 + y^2 + z^2 = r^2 (������ԭ��Ϊ����) 
		
    */
    class GRAPHICS3D_API UGSphere
    {
    protected:
        Real      m_fRadius;
        UGVector3 m_vCenter;

    public:
  
        UGSphere() : m_fRadius(1.0), m_vCenter(UGVector3::ZERO) 
		{
		}
  
		UGSphere(const UGVector3& center, Real radius)
            : m_fRadius(radius), m_vCenter(center) 
		{
		}

        Real GetRadius(void) const 
		{ 
			return m_fRadius; 
		}

        void GetRadius(Real radius) 
		{ 
			m_fRadius = radius; 
		}

        UGVector3 GetCenter(void) const 
		{ 
			return m_vCenter; 
		}

        void SetCenter(const UGVector3& center) 
		{ 
			m_vCenter = center; 
		}

		UGbool Intersects(const UGSphere& s) const
		{
			return ( s.m_vCenter - m_vCenter ).Length() <=
				   ( s.m_fRadius + m_fRadius );
		}

		UGbool Intersects(const UGBoundBox& box) const
		{
			return UGMath::Intersects(*this, box);
		}

		UGbool Intersects(const UGPlane& plane) const
		{
			return UGMath::Intersects(*this, plane);
		}
        

    };
}

#endif // !defined(UG_SPHERE_H)

