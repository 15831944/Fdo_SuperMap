// UGBoundBox.h: interface for the UGBoundBox class.


#if !defined(UG_BOUNDBOX_H)
#define UG_BOUNDBOX_H

#include <Graphics3D/UGMatrix4.h>  //�����Ѿ�����UGSceneHeaders.h��UGVector3.h
#include <Graphics3D/UGMath.h>

#include <iostream>
using namespace std; 

namespace UGC
{

	class UGSphere;  //ǰ������
	class UGPlane;

    /** A 3D box aligned with the x/y/z axes.
	    @remarks
		    1.�����װ�򵥵���ά���Box(��߿�������������ƽ��);
            2.���ڲ���¼8�����㣬�Լ�x,y,z������С������2�����㣻 
			3.�������ʾ��ʹ�õ�������(right-handed)����ϵ
			  �����������(����ʱ��)��
                  y
                  | 
                  |
			      1-------2
			     /|      /|
			    / |     / |
			    5------4  |
			    |  0---|--3---x
			    | /    | /
			    |/     |/
			    6------7
               /
			  z 
            4.����ͨ�����ڿɼ����ж�(�Ӿ����޳�VFC)�Լ�������ײ(Collision)
    */
	class GRAPHICS3D_API UGBoundBox  
	{
    protected:
	    UGVector3 m_vMin;         //x,y,z������С�Ķ���
	    UGVector3 m_vMax;         //x,y,z�������Ķ���
		UGVector3 m_vCorners[8];  //8������
	    UGbool m_bNull;

	 
	    void UpdateCorners( void )
	    {
			//����������ͼ
			
			//��һ�����4������( zֵ��ͬ = m_vMin.z )
		    m_vCorners[0] = m_vMin;
		    m_vCorners[1].x = m_vMin.x; m_vCorners[1].y = m_vMax.y; m_vCorners[1].z = m_vMin.z;
		    m_vCorners[2].x = m_vMax.x; m_vCorners[2].y = m_vMax.y; m_vCorners[2].z = m_vMin.z;
		    m_vCorners[3].x = m_vMax.x; m_vCorners[3].y = m_vMin.y; m_vCorners[3].z = m_vMin.z;            

			//ǰһ�����4������( zֵ��ͬ = m_vMax.z )
		    m_vCorners[4] = m_vMax;
		    m_vCorners[5].x = m_vMin.x; m_vCorners[5].y = m_vMax.y; m_vCorners[5].z = m_vMax.z;
		    m_vCorners[6].x = m_vMin.x; m_vCorners[6].y = m_vMin.y; m_vCorners[6].z = m_vMax.z;
		    m_vCorners[7].x = m_vMax.x; m_vCorners[7].y = m_vMin.y; m_vCorners[7].z = m_vMax.z;            
	    }        

    public:
	    inline UGBoundBox()
	    {
		    SetMinimum( -0.5, -0.5, -0.5 );
		    SetMaximum( 0.5, 0.5, 0.5 );
		    m_bNull = TRUE; // ȱʡΪ�յ�Box
	    }

	    inline UGBoundBox( const UGVector3& Min, const UGVector3& Max )
	    {
		    SetExtents( Min, Max );
	    }

	    inline UGBoundBox(
		    Real mx, Real my, Real mz,
		    Real Mx, Real My, Real Mz )
	    {
		    SetExtents( mx, my, mz, Mx, My, Mz );
	    }

	    inline void SetNull()
	    {
		    m_bNull = TRUE;
	    }

	    UGbool IsNull(void) const
	    {
		    return m_bNull;
	    }

	    inline const UGVector3& GetMinimum( void ) const
	    { 
		    return m_vMin; 
	    }

		inline const UGVector3& GetMaximum( void ) const
	    { 
		    return m_vMax;
	    }

	    inline void SetMinimum( const UGVector3& vec )
	    {
		    m_bNull = FALSE;
		    m_vMin = vec;
		    UpdateCorners();
	    }

	    inline void SetMinimum( Real x, Real y, Real z )
	    {
		    m_bNull = FALSE;
		    m_vMin.x = x;
		    m_vMin.y = y;
		    m_vMin.z = z;
		    UpdateCorners();
	    }

		inline void SetMaximum( const UGVector3& vec )
	    {
		    m_bNull = FALSE;
		    m_vMax = vec;
		    UpdateCorners();
	    }

	    inline void SetMaximum( Real x, Real y, Real z )
	    {
		    m_bNull = FALSE;
		    m_vMax.x = x;
		    m_vMax.y = y;
		    m_vMax.z = z;
		    UpdateCorners();
	    }

	    inline void SetExtents( const UGVector3& Min, const UGVector3& Max )
	    {
		    m_bNull = FALSE;
		    m_vMin = Min;
		    m_vMax = Max;
		    UpdateCorners();
	    }

	    inline void SetExtents(
		    Real mx, Real my, Real mz,
		    Real Mx, Real My, Real Mz )
	    {
			assert( Mx > mx && My > my && Mz > mz );

		    m_bNull = FALSE;

		    m_vMin.x = mx;
		    m_vMin.y = my;
		    m_vMin.z = mz;

		    m_vMax.x = Mx;
		    m_vMax.y = My;
		    m_vMax.z = Mz;

		    UpdateCorners();
	    }

	    inline const UGVector3* GetAllCorners( void ) const
	    {
		    assert( m_bNull != FALSE );

		    return (const UGVector3*)m_vCorners;
	    }

	    friend std::ostream& operator<<( std::ostream& o, const UGBoundBox& bb )
	    {
		    if ( bb.IsNull() )
		    {
			    o << "UGBoundBox(null)";
		    }
		    else
		    {
			    o << "UGBoundBox(Min=" << bb.m_vMin << ", Max=" << bb.m_vMax;
			    o << ", corners=\n";
				for (UGint i = 0; i < 7; ++i)
				{
					o << bb.m_vCorners[i] << ", ";
				}
					
				o << bb.m_vCorners[7] << ")";
				
		    }
		    return o;
	    }

	    /** �����ݹ�����rhs Box�ϲ�����Box��
	    */
	    void Merge( const UGBoundBox& rhs )
	    {
		    if ( rhs.IsNull() )
		    {
			    return;
			}
		    else if ( this->IsNull() )
		    {
			    SetExtents( rhs.m_vMin, rhs.m_vMax );
		    }
		    else
		    {
			    UGVector3 Min = m_vMin;
			    UGVector3 Max = m_vMax;
			    Max.MakeCeil( rhs.m_vMax );
			    Min.MakeFloor( rhs.m_vMin );

			    SetExtents( Min, Max );
		    }
	    }

	    /** ���ݾ���matrix����Box���б任
		*/
	    void Transform( const UGMatrix4& matrix )
	    {
		    if( m_bNull ) return;

		    UGVector3 Min, Max, temp;
		    UGbool first = TRUE;
		    UGint i;
			
		    for( i = 0; i < 8; ++i )
		    {			    
				//���α任8������
			    temp = matrix * m_vCorners[i];

				cout << temp.x << endl;

				//�任����֮�󣬼��������С����
			    if( first || temp.x > Max.x )
				    Max.x = temp.x;
			    if( first || temp.y > Max.y )
				    Max.y = temp.y;
			    if( first || temp.z > Max.z )
				    Max.z = temp.z;
			    if( first || temp.x < Min.x )
				    Min.x = temp.x;
			    if( first || temp.y < Min.y )
				    Min.y = temp.y;
			    if( first || temp.z < Min.z )
				    Min.z = temp.z;

			    first = FALSE;
		    }

		    SetExtents( Min,Max );

	    }

        /** ���2��Box�Ƿ��ཻ */
        inline UGbool Intersects( const UGBoundBox& b2 ) const
        {
            if ( this->IsNull() || b2.IsNull() )
			{
                return FALSE;
			}

            //����6�����λ�ý��м�� 
            if ( m_vMax.x < b2.m_vMin.x )
                return FALSE;
            if ( m_vMax.y < b2.m_vMin.y )
                return FALSE;
            if ( m_vMax.z < b2.m_vMin.z )
                return FALSE;

            if ( m_vMin.x > b2.m_vMax.x )
                return FALSE;
            if ( m_vMin.y > b2.m_vMax.y )
                return FALSE;
            if ( m_vMin.z > b2.m_vMax.z )
                return FALSE;

            // ������ض��ཻ��
            return TRUE;

        }

        inline void Scale(const UGVector3& s)
        {
            // note: ��ԭ��Ϊ���Ľ�������
            m_vMin = m_vMin * s;
            m_vMax = m_vMax * s;
        }

		inline void Scale( Real x_scale, Real y_scale, Real z_scale )
        {
            // note: ��ԭ��Ϊ���Ľ�������
            m_vMin.x *= x_scale;
            m_vMin.y *= y_scale;
			m_vMin.z *= z_scale;

			m_vMax.x *= x_scale;
			m_vMax.y *= y_scale;
			m_vMax.z *= z_scale;
        }

		inline UGbool Intersects( const UGSphere& s ) const
		{
			return UGMath::Intersects(s, *this); 
		}
		
		inline UGbool Intersects( const UGPlane& p ) const
		{
			return UGMath::Intersects(p, *this);
		}

	};
}

#endif // !defined(UG_BOUNDBOX_H)

