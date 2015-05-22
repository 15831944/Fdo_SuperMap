/* 
	\file UGMatrix4d.h
	\brief ���� 4 X 4 �����ࡣ
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGMATRIX4D_H__67A327BB_7D71_4996_8DBC_4884AB212BCD__INCLUDED_)
#define AFX_UGMATRIX4D_H__67A327BB_7D71_4996_8DBC_4884AB212BCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Scene/UGPrerequisites.h"
#include "Scene/UGVector3R.h"
#include "Scene/UGMatrix3R.h"
#include "Scene/UGQuaternion4d.h"

namespace  UGC 
{

//! \brief   4X4������
//! \remarks ά��4X4����
class SCENE_API UGMatrix4d  
{
friend class UGQuaternion4d;
public:

	//! \brief ȱʡ���캯����
	UGMatrix4d();
	
	
	//! \brief ��16�����������������Ĺ��캯����
	//! \param m00 [in]��
	//! \param m01 [in]��
	//! \param m02 [in]��
	//! \param m03 [in]��
	//! \param m10 [in]��
	//! \param m11 [in]��
	//! \param m12 [in]��
	//! \param m13 [in]��
	//! \param m20 [in]��
	//! \param m21 [in]��
	//! \param m22 [in]��
	//! \param m23 [in]��
	//! \param m30 [in]��
	//! \param m31 [in]��
	//! \param m32 [in]��
	//! \param m33 [in]��
	inline UGMatrix4d(
            UGReal m00, UGReal m01, UGReal m02, UGReal m03,
            UGReal m10, UGReal m11, UGReal m12, UGReal m13,
            UGReal m20, UGReal m21, UGReal m22, UGReal m23,
            UGReal m30, UGReal m31, UGReal m32, UGReal m33)	
    {
        m[0][0] = m00;
        m[0][1] = m01;
        m[0][2] = m02;
        m[0][3] = m03;
        m[1][0] = m10;
        m[1][1] = m11;
        m[1][2] = m12;
        m[1][3] = m13;
        m[2][0] = m20;
        m[2][1] = m21;
        m[2][2] = m22;
        m[2][3] = m23;
        m[3][0] = m30;
        m[3][1] = m31;
        m[3][2] = m32;
        m[3][3] = m33;
    }

	//! \brief ����������
	virtual ~UGMatrix4d();
	

	//! \brief ����*����������ֵ��ˡ�
	//! \param scalar ��ֵ[in]��
	//! \return ������ɺ�4x4����
	inline UGMatrix4d operator*(UGReal scalar)
    {
        return UGMatrix4d(
            scalar*m[0][0], scalar*m[0][1], scalar*m[0][2], scalar*m[0][3],
            scalar*m[1][0], scalar*m[1][1], scalar*m[1][2], scalar*m[1][3],
            scalar*m[2][0], scalar*m[2][1], scalar*m[2][2], scalar*m[2][3],
            scalar*m[3][0], scalar*m[3][1], scalar*m[3][2], scalar*m[3][3]);
    }

	//! \brief ����*����ɾ����������ˡ�
	//! \param &m2 ��������[in]��
	//! \return ������ɺ����
	inline UGMatrix4d operator * ( const UGMatrix4d &m2 ) const
   	{
        return Concatenate( m2 );
    }

	//! \brief ����*����������ά������ˡ�
	//! \param &v ��ά����[in]��
	//! \return ��ά������
	//! \remarks �Ӿ�����ȡ��������3X3��������ά����������ˡ�
	inline UGVector3R operator * ( const UGVector3R &v ) const
	{
		UGVector3R r;		
		UGReal fInvW = (UGReal)(1.0 / ( m[3][0] + m[3][1] + m[3][2] + m[3][3] ));
		
		r.x = ( m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] ) * fInvW;
		r.y = ( m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] ) * fInvW;
		r.z = ( m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] ) * fInvW;
		
		return r;
	}
		
	//! \brief ������ˡ�
	//! \param &m2 ����һ��4X4����[in]��
	//! \return ��������4X4����
	inline UGMatrix4d Concatenate(const UGMatrix4d &m2) const
    {
        UGMatrix4d r;
        r.m[0][0] = m[0][0] * m2.m[0][0] + m[0][1] * m2.m[1][0] + m[0][2] * m2.m[2][0] + m[0][3] * m2.m[3][0];
        r.m[0][1] = m[0][0] * m2.m[0][1] + m[0][1] * m2.m[1][1] + m[0][2] * m2.m[2][1] + m[0][3] * m2.m[3][1];
        r.m[0][2] = m[0][0] * m2.m[0][2] + m[0][1] * m2.m[1][2] + m[0][2] * m2.m[2][2] + m[0][3] * m2.m[3][2];
        r.m[0][3] = m[0][0] * m2.m[0][3] + m[0][1] * m2.m[1][3] + m[0][2] * m2.m[2][3] + m[0][3] * m2.m[3][3];

        r.m[1][0] = m[1][0] * m2.m[0][0] + m[1][1] * m2.m[1][0] + m[1][2] * m2.m[2][0] + m[1][3] * m2.m[3][0];
        r.m[1][1] = m[1][0] * m2.m[0][1] + m[1][1] * m2.m[1][1] + m[1][2] * m2.m[2][1] + m[1][3] * m2.m[3][1];
        r.m[1][2] = m[1][0] * m2.m[0][2] + m[1][1] * m2.m[1][2] + m[1][2] * m2.m[2][2] + m[1][3] * m2.m[3][2];
        r.m[1][3] = m[1][0] * m2.m[0][3] + m[1][1] * m2.m[1][3] + m[1][2] * m2.m[2][3] + m[1][3] * m2.m[3][3];

        r.m[2][0] = m[2][0] * m2.m[0][0] + m[2][1] * m2.m[1][0] + m[2][2] * m2.m[2][0] + m[2][3] * m2.m[3][0];
        r.m[2][1] = m[2][0] * m2.m[0][1] + m[2][1] * m2.m[1][1] + m[2][2] * m2.m[2][1] + m[2][3] * m2.m[3][1];
        r.m[2][2] = m[2][0] * m2.m[0][2] + m[2][1] * m2.m[1][2] + m[2][2] * m2.m[2][2] + m[2][3] * m2.m[3][2];
        r.m[2][3] = m[2][0] * m2.m[0][3] + m[2][1] * m2.m[1][3] + m[2][2] * m2.m[2][3] + m[2][3] * m2.m[3][3];

        r.m[3][0] = m[3][0] * m2.m[0][0] + m[3][1] * m2.m[1][0] + m[3][2] * m2.m[2][0] + m[3][3] * m2.m[3][0];
        r.m[3][1] = m[3][0] * m2.m[0][1] + m[3][1] * m2.m[1][1] + m[3][2] * m2.m[2][1] + m[3][3] * m2.m[3][1];
        r.m[3][2] = m[3][0] * m2.m[0][2] + m[3][1] * m2.m[1][2] + m[3][2] * m2.m[2][2] + m[3][3] * m2.m[3][2];
        r.m[3][3] = m[3][0] * m2.m[0][3] + m[3][1] * m2.m[1][3] + m[3][2] * m2.m[2][3] + m[3][3] * m2.m[3][3];

        return r;
    }
 
	//! \brief ����[]��ȡ����Ӧ�С�
	//! \param iRow �кţ���Ч��ΧΪ�㵽��[in]��
	//! \return ����ָ��һ�����ݣ�����������ָ�롣
	inline UGReal* operator[] (UGuint iRow)
    {
        UGASSERT( iRow < 4 );
        return (UGReal*)m[iRow];
    }

 
	//! \brief �ж����������Ƿ���ȡ�
	//! \param &m2 ����һ������[in]��
	//! \return ����ȷ���ΪTRUE����������򷵻�ΪFALSE��
	inline UGbool operator == (const UGMatrix4d &m2)
    {
			return
			(
			UGIS0(m[0][0]-m2.m[0][0])&& 
			UGIS0(m[0][1]-m2.m[0][1])&& 
			UGIS0(m[0][2]-m2.m[0][2])&& 
			UGIS0(m[0][3]-m2.m[0][3])&& 
			UGIS0(m[1][0]-m2.m[1][0])&& 
			UGIS0(m[1][1]-m2.m[1][1])&& 
			UGIS0(m[1][2]-m2.m[1][2])&& 
			UGIS0(m[1][3]-m2.m[1][3])&& 
			UGIS0(m[2][0]-m2.m[2][0])&& 
			UGIS0(m[2][1]-m2.m[2][1])&& 
			UGIS0(m[2][2]-m2.m[2][2])&& 
			UGIS0(m[2][3]-m2.m[2][3])&& 
			UGIS0(m[3][0]-m2.m[3][0])&& 
			UGIS0(m[3][1]-m2.m[3][1])&& 
			UGIS0(m[3][2]-m2.m[3][2])&& 
			UGIS0(m[3][3]-m2.m[3][3])
			);
    }
 
	//! \brief ȡ��ֻ�����������ݡ�
	//! \param iRow �кţ���Ч��ΧΪ�㵽��[in]��
	//! \return �����ݡ�
	inline const UGReal *const operator [] ( UGuint iRow ) const
    {
        UGASSERT( iRow < 4 );
        return m[iRow];
    }
    
	UGReal operator () (UGuint iRow, UGuint iCol)
	{
		UGASSERT( iRow < 4 || iCol < 4);
		return m[iRow][iCol];
	}

	//! \brief ������������ϵ��ģ���ӵ����
	//! \param cameraPosition ���λ��[in]��
	//! \param cameraTarget ��������׼λ��[in]��
	//! \param cameraUpVector ������Ϸ���[in]��
	//! \return  ģ���ӵ����
	//! \remarks ���ɸþ�����������ά��ʹ�øþ���������ɶ���ά��ģ���ӵ��������ã���OpenGL��ʹ�á�
	static UGMatrix4d LookAtRH(UGVector3R cameraPosition, UGVector3R cameraTarget, UGVector3R cameraUpVector);

	//! \brief ������������ϵģ���ӵ����
	//! \param cameraPosition ���λ��[in]��
	//! \param cameraTarget ��������׼λ��[in]��
	//! \param cameraUpVector ������Ϸ���[in]��
	//! \return ģ���ӵ����
	//! \remarks ��Ҫ����DirectX��ʹ�ã�������DirectX�����øþ���Ϊģ���ӵ������������Ե�ģ�;���ɹ���
	static UGMatrix4d LookAtLH(UGVector3R cameraPosition, UGVector3R cameraTarget, UGVector3R cameraUpVector);
	
	//! \brief ����ƽ�ơ�
	//! \param x X���ƶ���С[in]��
	//! \param y Y���ƶ���С[in]��
	//! \param z Z���ƶ���С[in]��
	//! \return ƽ�ƺ����
	static UGMatrix4d Translation(UGReal x, UGReal y, UGReal z);

	//! \brief ��ת��
	//! \param rotationX ��X����ת�Ƕ�[in]��
	//! \param rotationY ��Y����ת�Ƕ�[in]��
	//! \param rotationZ ��Z����ת�Ƕ�[in]��
	//! \return ��ת�����
	static UGMatrix4d RotationXYZ(UGReal rotationX, UGReal rotationY, UGReal rotationZ);
	
	//! \brief ��X����ת��
	//! \param angle ��X����ת�Ƕ�[in]��
	//! \return ��ת�����		
	static UGMatrix4d RotationX(UGReal angle);

	//! \brief ��Y����ת��
	//! \param angle ��Y����ת�Ƕ�[in]��
	//! \return ��ת�����
	static UGMatrix4d RotationY(UGReal angle);

	//! \brief ��Z����ת��
	//! \param angle [in]��
	//! \return ��ת�����		
	static UGMatrix4d RotationZ(UGReal angle);
	
	//! \brief ����͸��ͶӰ����
	//! \param fieldOfViewY �ӽ���Y���ϴ�С[in]��
	//! \param aspectRatio ��׶���߱�[in]��
	//! \param znearPlane ��ƽ��Zֵ[in]��
	//! \param zfarPlane Զƽ��Zֵ[in]��
	//! \return ͸��ͶӰ����
	static UGMatrix4d PerspectiveFovRH(UGReal fieldOfViewY, UGReal aspectRatio, UGReal znearPlane, UGReal zfarPlane);
	
	//! \brief �������İ������
	//! \return ����İ������
	//! \remarks ��	
	UGMatrix4d Adjoint();

	//! \brief �����������ʽֵ��
	//! \return ����ʽֵ����
	UGReal Determinant();

	//! \brief ��������������
	//! \return ���������
	UGMatrix4d Invert();	

	UGMatrix4d Transpose();

	//! \brief 4X4�����
	//! \remarks ����Ԫ��Ϊ��
	static const UGMatrix4d ZERO;


	//! \brief 4X4 ��λ����
	//! \remarks �Խ���Ԫ��Ϊ1������Ϊ0
	static const UGMatrix4d IDENTITY;

	static const UGMatrix4d CLIPSPACE2DTOIMAGESPACE;
	
	
	//! \brief ����4x4������3x3�Ӿ�������ʽ��
	//! \param m 4x4����[in]��
	//! \param r0 ��һ���к�[in]��
	//! \param r1 �ڶ����к�[in]��
	//! \param r2 �������к�[in]��
	//! \param c0 ��һ���к�[in]��
	//! \param c1 �ڶ����к�[in]��
	//! \param c2 �������к�[in]��
	inline UGReal MINOR(const UGMatrix4d& m, const size_t r0, const size_t r1, const size_t r2, 
		const size_t c0, const size_t c1, const size_t c2)
	{
		return m[r0][c0] * (m[r1][c1] * m[r2][c2] - m[r2][c1] * m[r1][c2]) -
			m[r0][c1] * (m[r1][c0] * m[r2][c2] - m[r2][c0] * m[r1][c2]) +
			m[r0][c2] * (m[r1][c0] * m[r2][c1] - m[r2][c0] * m[r1][c1]);
	}
	inline void operator = ( const UGMatrix3R& mat3 )
    {
        m[0][0] = mat3.m[0][0]; m[0][1] = mat3.m[0][1]; m[0][2] = mat3.m[0][2];
        m[1][0] = mat3.m[1][0]; m[1][1] = mat3.m[1][1]; m[1][2] = mat3.m[1][2];
        m[2][0] = mat3.m[2][0]; m[2][1] = mat3.m[2][1]; m[2][2] = mat3.m[2][2];
    }
	inline void SetTrans( const UGVector3R& v )
    {
        m[0][3] = v.x;
        m[1][3] = v.y;
        m[2][3] = v.z;
    }
	void MakeTransform(UGVector3R& position, UGVector3R& scale, UGQuaternion4d& orientation);
    
	static UGMatrix4d ComputeRotateMatrix(UGdouble angle, UGVector3R vecRotateAxis);

	
protected:


	//! \brief ����������
	//! \remarks ���������ݱ����ڸñ����С�
	UGReal m[4][4];

};


}
#endif // !defined(AFX_UGMATRIX4D_H__67A327BB_7D71_4996_8DBC_4884AB212BCD__INCLUDED_)
