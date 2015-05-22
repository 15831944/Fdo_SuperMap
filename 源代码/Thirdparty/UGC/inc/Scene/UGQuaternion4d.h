/* 
	\file UGQuaternion4d.h
	\brief ��Ԫ�����ļ�
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGQUATERNION4D_H__828A96C2_95EA_4DCC_9468_666159FA635E__INCLUDED_)
#define AFX_UGQUATERNION4D_H__828A96C2_95EA_4DCC_9468_666159FA635E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGMatrix3R.h"
#include "Scene/UGMatrix4d.h"

namespace  UGC 
{

//! \brief ��Ԫ����
//! \remarks ��Ԫ����Ҫ����ռ���ת
class SCENE_API UGQuaternion4d  
{

public:
	//! \brief ���캯��
	UGQuaternion4d();
	//! \brief ���캯��
	UGQuaternion4d(UGReal x, UGReal y, UGReal z, UGReal w);
	UGQuaternion4d(const UGVector3R& xaxis, const UGVector3R& yaxis, const UGVector3R& zaxis);
	//! \brief ��������
	virtual ~UGQuaternion4d();
	//! \brief ����Ԫ�����Ԫ����� 
	UGQuaternion4d operator*(const UGQuaternion4d& obj);
	//! \brief ����Ԫ�����Ԫ�����������
	UGVector3R operator* (const UGVector3R& v) const;
	//! \brief ����ת������תΪ��Ԫ��
	void FromAxes (const UGVector3R* akAxis);
	//! \brief ����ά��ת������תΪ��Ԫ��
	void FromAxes (const UGVector3R& xAxis, const UGVector3R& yAxis, const UGVector3R& zAxis);
	//! \brief ����ת����תΪ��Ԫ��
	void FromRotationMatrix (const UGMatrix3R& kRot);
	//! \brief ��׼����Ԫ��
	void Normalize();
	//! \brief ��Ԫ������
	UGReal Length();
	//! \brief ��Ԫ��תΪ��ͽ� 
	void ToAngleAxis (UGReal& rfAngle, UGVector3R& rkAxis);
	//! \brief ��Ԫ����� 
	static UGReal Dot(const UGQuaternion4d& a, const UGQuaternion4d& b);
	//! \brief ��Ԫ��תΪŷ���� 
	static UGVector3R QuaternionToEuler(const UGQuaternion4d& q);
	//! \brief ŷ����תΪ��Ԫ��
	static UGQuaternion4d EulerToQuaternion(UGReal yaw, UGReal pitch, UGReal roll);
	//! \brief ��Ԫ����ֵ
	static UGQuaternion4d Slerp(const UGQuaternion4d& q0, const UGQuaternion4d& q1, UGReal t);
	//! \brief �����תΪ��Ԫ��
	void FromAngleAxis (const UGReal& rfAngle,
								const UGVector3R& rkAxis);
	//! \brief ����Ԫ��רΪ��ת����
	void ToRotationMatrix (UGMatrix3R& kRot);
	//! \brief ����Ԫ��רΪ��ת����
	void ToRotationMatrix (UGMatrix4d& kRot); 
	UGQuaternion4d Inverse () const;
	UGQuaternion4d UnitInverse () const;
	UGbool operator== (const UGQuaternion4d& rhs) const;
	
	//! \brief  
	UGReal x;
	//! \brief  
	UGReal y;
	//! \brief  
	UGReal z;
	//! \brief  
	UGReal w;

	static const UGQuaternion4d ZERO;
    static const UGQuaternion4d IDENTITY;

};
}
#endif // !defined(AFX_UGQUATERNION4D_H__828A96C2_95EA_4DCC_9468_666159FA635E__INCLUDED_)
