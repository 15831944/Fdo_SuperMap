// UGMath.h: interface for the UGMath class.


#if !defined(UGMATH_H)
#define UGMATH_H

#include <Scene/UGSceneHeaders.h>

namespace UGC
{		
	//ע�⣺�����ǰ�������������namaspace UGC֮��
	class UGSphere;
	class UGBoundBox;
	class UGPlane;
	class UGRay;

	#ifndef UG_PI
		#define UG_PI 3.14159265358979323846
	#endif

	#ifndef UG_TWO_PI
		#define UG_TWO_PI 6.2831853071795864769
	#endif

	#ifndef UG_HALF_PI
		#define UG_HALF_PI 1.5707963267948966
	#endif

	#ifndef UG_DEG_TO_RAD
		#define UG_DEG_TO_RAD 0.0174532925199432958
	#endif

	#ifndef UG_RAD_TO_DEG
		#define UG_RAD_TO_DEG 57.29577951308232
	#endif
	
	 /** ������ѧ�࣭�������װ��һЩ��ά�����г��õ�����ѧ���㺯��
        @remarks
             Ϊ���ܶԻ�������ѧ�������Ż�������ʵ��һ��������ѧ��
             ���಻���Ÿ��û���������ά�����ڲ�ʹ�ã�ʹ��ʱֻ��Ҫnewһ��
             ����Ҳֻ��Newһ�Σ���������ڴ�й©
             ��m_pSinTable , m_pTanTable ,ʼ�ձ������ڴ���
             ʹ��ʱ����ֱ��CSmMath::Sin()����Ҳ����CSmMath::GetSingleton.Sin()����
             �ٶȿ죬��������ȷ����λ: ����(Radian)
    */
	class SCENE_API UGMath  
	{
	public:
		/** trigTableSize Optional parameter to set the size of the tables 
		    used to implement Sin, Cos, Tan
		*/
		UGMath(UGuint trigTableSize = 4096);
		~UGMath();
		
	public:
		/// ���Ǻ���
		static Real Sin( Real fRadian, UGbool bUseTable = false );
		static Real Cos( Real fRadian, UGbool bUseTable = false );
		static Real Tan( Real fRadian, UGbool bUseTable = false );

		/// �����Ǻ���
		static Real ACos( Real fValue );
		static Real ASin( Real fValue );
		static Real ATan( Real fValue );
		static Real ATan2( Real fY, Real fX ); 

		static Real Degree2Radian( Real fDegree );
		static Real Radian2Degree( Real fRadian );

		static Real Sqrt( Real fValue );
		static Real InvSqrt( Real fValue ); ///ƽ�������� ��: 1 / Sqrt(x)

		static Real   Abs( Real fValue );
		static UGuint Log2( UGuint n );

		/// ���ؾ���basevalue�����2^N + 1 ��ֵ
		static UGuint NextPOW2p1(UGuint basevalue);
		
		//�ж����ߺ��棬box, sphere�ཻ������������ؾ��� 
		static UGbool Intersects(const UGRay& ray, const UGPlane& plane,   Real& fDistance);
		static UGbool Intersects(const UGRay& ray, const UGBoundBox& box,  Real& fDistance);
		static UGbool Intersects(const UGRay& ray, const UGSphere& sphere, Real& fDistance);
		
		static UGbool Intersects(const UGSphere& sphere, const UGBoundBox& box);
		static UGbool Intersects(const UGSphere& sphere, const UGPlane& plane);
		static UGbool Intersects(const UGPlane& plane,   const UGBoundBox& box);
//		
//		static UGbool Intersect(const UGRay& ray,const CSmPlane& plane,Real& fDistance,CSmVector3& vIntersection);
//
		
	protected:
	    /// �������Ǻ�����
        void BuildTrigTables();
	
	protected:
	    
		/// ���Ǻ�����Ĵ�С --�ڹ��캯���и����ⲿ���ݽ����Ĳ�����ȷ��
        static UGint m_nTrigTableSize;

        /// Radian -> index factor value ( mTrigTableSize / 2 * PI )
        static Real  m_fTrigTableFactor;
        static Real* m_pSinTable;
        static Real* m_pTanTable;

	private:
        /** ��ȷ��ֹ�������� --�μ�Scott Meyers ��Effective C++��*/
		UGMath(const UGMath& rhs);

		/** ��ȷ��ֹ�������Ŀ��� --�μ�Scott Meyers ��Effective C++��*/
		UGMath& operator=(const UGMath& rhs);
		
	};
}

#endif // !defined(UGMATH_H)

