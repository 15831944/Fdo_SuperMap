/* 
	\file UGBoundingBox.h
	\brief �ļ����ݵļ�Ҫ������
	\author �ļ�����
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

// UGBoundingBox.h: interface for the UGBoundingBox class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGBOUNDINGBOX_H__29C05AF1_76E7_49B0_A62C_239A57A92F80__INCLUDED_)
#define AFX_UGBOUNDINGBOX_H__29C05AF1_76E7_49B0_A62C_239A57A92F80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGVector3R.h"
#include "Scene/UGPrerequisites.h"
namespace UGC
{
//! \brief ��Χ����
class SCENE_API UGBoundingBox  
{
public:
	//! \brief ���캯��
	UGBoundingBox();
	//! \brief ���캯��
	UGBoundingBox(UGVector3R& vMin,UGVector3R& vMax);
	//! \brief ���캯��
	UGBoundingBox(const UGVector3R& v0, const UGVector3R& v1, const UGVector3R& v2, const UGVector3R& v3, const UGVector3R& v4, const UGVector3R& v5, const UGVector3R& v6, const UGVector3R& v7);
	//! \brief ���캯��
	UGBoundingBox(UGdouble south, UGdouble north, UGdouble west, UGdouble east, UGdouble radius1, UGdouble radius2);
	//! \brief ��������
	virtual ~UGBoundingBox();
	//! \brief 
	inline void SetMin(UGVector3R vMin);
	//! \brief
	inline void SetMax(UGVector3R vMax);
	//! \brief
	inline void SetMin(UGdouble x,UGdouble y,UGdouble z);
	//! \brief
	inline void SetMax(UGdouble x,UGdouble y,UGdouble z);
	//! \brief
	inline const UGVector3R& GetMin(void) const;
	//! \brief
	inline const UGVector3R& GetMax(void) const;
	//! \brief
	inline void SetExtents(const UGVector3R& vMin,const UGVector3R& vMax);
	//! \brief
	inline void SetExtents(UGdouble minx, UGdouble miny,UGdouble minz,
						   UGdouble maxx, UGdouble maxy, UGdouble maxz);
	inline const UGVector3R* GetCorners()const;
	//! \brief
	UGVector3R GetCenter() const;
	//! \brief
	inline void Transform(UGMatrix4d& matrix);
	//! \brief
	inline void Merge(const UGBoundingBox& BoundBox);
	//! \brief
	inline void SetNULL(void);
	//! \brief
	inline UGbool IsNULL(void)const;
	//! \brief
	inline void Scale(const UGVector3R& s);
	//! \brief �������ĵ�
	UGVector3R CalculateCenter();
	UGbool InterSectWithRadial(const UGVector3R& nearPos, const UGVector3R& farPos);

	// ��ӻ��ƺ���
	void Render();
	void Perp(float*e,float* n);

	UGVector3R GetIntersectedPoint(){return m_vecIntersectedPoint;}
	
	// ��ʱʹ��
	UGVector3R m_nearPos;
	UGVector3R m_farPos;
	UGVector3R m_InsectPos;
	
protected:
	//! \brief ���½ǵ�
	void UpdateCorners(void);

	// ֻ������ཻ�㷨,Ч��Ϊlogn, �п���������
	UGbool InterSectFaceWithRadial(UGint corner1, UGint corner2, UGint corner3, UGint corner4,
		                           const UGVector3R& nearPos, const UGVector3R& farPos);
	// �������������ཻ, Ч��Ϊ2logn
	UGbool IntersectBoxFaces(UGint Corner1, UGint Corner2, UGint Corner3,UGint Corner4,
											const UGVector3R& nearPos, const UGVector3R& farPos);

	UGbool IntersectPointAndRegion(UGint Corner1, UGint Corner2, UGint Corner3,UGint Corner4,
									const UGVector3R& nearPos, const UGVector3R& farPos, 
									UGdouble& t, UGVector3R& vecIntersect);
  
protected:
	//! \brief
	UGVector3R m_vMin;
	//! \brief
	UGVector3R m_vMax;
	//! \brief ��Χ��8���ǵ�
	UGVector3R m_vCorner[8];
	//! \brief
	UGbool m_bNull;

	UGVector3R m_vecIntersectedPoint;
};
}
#endif // !defined(AFX_UGBOUNDINGBOX_H__29C05AF1_76E7_49B0_A62C_239A57A92F80__INCLUDED_)
