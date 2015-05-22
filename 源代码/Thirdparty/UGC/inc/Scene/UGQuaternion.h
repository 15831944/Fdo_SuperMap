// UGQuaternion.h: interface for the UGQuaternion class.


#if !defined(UG_QUATERNION_H)
#define UG_QUATERNION_H

#include <Scene/UGSceneHeaders.h>

namespace UGC
{
	class UGVector3;
	class UGMatrix3;

	/** ʵ��һ����Ԫ��
	   @remarks
			��ǰ���õ���Euler Angles�ķ������ֱ���������ᣬ��˳����б任
			�����ĺ���ǻ����Gimbal Lock(�����)����
			Ҳ���Ƿֱ������������˳��任�ĺ���ǿ��ܳ����������غϵ����
			���õķ����ǲ���Quaternion(��Ԫ��),��������ı任ͬʱ����

            ��������������Ԫ�������ת������и���ĺô���
			��Ϊ��Ԫ����Ҫ�Ĵ洢�ռ���٣���Ԫ��֮�������������Ҫ���������٣�
			�ڲ���ƽ������ά����ʱ������Ԫ������׽����޸ġ�

			���±�ʾһ����Ԫ��
			q = [w,x,y,z] = w + x*i + y*j + z*k
			              = s + V
						  s ��ʾ�������֣���Ӧ��q��w������
						  V ��ʾ�������֣���Ӧ��q��x��y��z����
	*/
	
	class SCENE_API UGQuaternion  
	{
	public:
		// 4 components
		Real w, x, y, z;

		// cutoff for sine near zero
		static Real ms_fEpsilon;
		
		// special values
		static UGQuaternion ZERO;
		static UGQuaternion IDENTITY;
		
	public:
		UGQuaternion ( Real fW = 1.0,
			           Real fX = 0.0, Real fY = 0.0, Real fZ = 0.0 );
		UGQuaternion ( const UGQuaternion& rkQ );
		
		//�任�������Ӧ��Quaternion֮���ת��
		void FromRotationMatrix ( const UGMatrix3& kRot );
		void ToRotationMatrix ( UGMatrix3& kRot ) const;
		
		void FromAngleAxis ( const Real& rfAngle, const UGVector3& rkAxis );
		void ToAngleAxis ( Real& rfAngle, UGVector3& rkAxis ) const;
		
		void FromAxes ( const UGVector3* akAxis );
		void FromAxes ( const UGVector3& xAxis, const UGVector3& yAxis, const UGVector3& zAxis );
		void ToAxes ( UGVector3& xAxis, UGVector3& yAxis, UGVector3& zAxis );
		void ToAxes ( UGVector3* akAxis ) const;
		
		UGQuaternion& operator= ( const UGQuaternion& rkQ );
		UGQuaternion  operator+ ( const UGQuaternion& rkQ ) const;
		UGQuaternion  operator- ( const UGQuaternion& rkQ ) const;
		UGQuaternion  operator* ( const UGQuaternion& rkQ ) const;
		UGQuaternion  operator* ( Real fScalar ) const;
		UGQuaternion  operator- () const;
		UGbool          operator== ( const UGQuaternion& rhs ) const;
		friend UGQuaternion operator* ( Real fScalar, const UGQuaternion& rkQ );
		
		Real Dot (const UGQuaternion& rkQ) const;  // dot product
		Real Norm () const;                        // squared-length
		UGQuaternion Inverse () const;             // apply to non-zero CQuaternion
		UGQuaternion UnitInverse () const;         // apply to unit-length CQuaternion
		UGQuaternion Exp () const;
		UGQuaternion Log () const;
		
		// ʹ�ø�CQuaternion
		UGVector3 operator* (const UGVector3& rkVector) const;
		
		// spherical linear interpolation  �������Բ�ֵ
		static UGQuaternion Slerp ( Real fT, const UGQuaternion& rkP, const UGQuaternion& rkQ );
		
		static UGQuaternion SlerpExtraSpins (Real fT,
			const UGQuaternion& rkP, const UGQuaternion& rkQ,
			int iExtraSpins);
		
		// setup for spherical quadratic interpolation
		static void Intermediate (const UGQuaternion& rkQ0,
			const UGQuaternion& rkQ1, const UGQuaternion& rkQ2,
			UGQuaternion& rka, UGQuaternion& rkB);
		
		// spherical quadratic interpolation
		static UGQuaternion Squad (Real fT, const UGQuaternion& rkP,
			const UGQuaternion& rkA, const UGQuaternion& rkB,
			const UGQuaternion& rkQ);
		

		
		/** Function for writing to a stream.
		*/
		inline friend std::ostream& operator <<
			( std::ostream& o, const UGQuaternion& q )
		{
			o << "UGQuaternion(" << q.x << ", " << q.y << ", " << q.z << ", " << q.w << ")";
			return o;
		}		
	};
}


#endif // !defined(UG_QUATERNION_H)

