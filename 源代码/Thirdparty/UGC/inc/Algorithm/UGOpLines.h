/*! \file	 UGOpLines.h
 *  \brief	 �� �Լ�����֮�������
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOpLines.h,v 1.32 2007/12/27 09:14:08 maoqin Exp $
 */


#ifndef UGOPLINES_H
#define UGOPLINES_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGPoint.h"

namespace UGC {

//! \brief �� �Լ�����֮�������
class ALGORITHM_API UGOpLines  
{
private:
	UGOpLines();

public: // �õ�ͼ�ε�����

	//! \brief �õ����ߵĳ���
	static UGdouble Length(const UGPoint2D* pPoints, UGint nPntCount);

	//! \brief �õ�ֱ�ߵ�б��
	//! \return ���б��Ϊ ����� ���������غ�, �򷵻�UGdouble��ֵ�������ֵ: INFINITEBIG
	// static UGdouble Slope(const UGPoint2D& pntStart, const UGPoint2D& pntEnd);


public: // �������

	//! \brief �����߶κ��߶�֮�伫�����
	static UGdouble MaxDistance(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
								const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �����߶κ��߶�֮�伫�����
	static UGdouble MaxDistance(const UGPoint2D* pPoints1, UGint nPntCount1,  
								const UGPoint2D* pPoints2, UGint nPntCount2  );

	//! \brief �����߶κ��߶�֮�伫�����
	static UGdouble MaxDistance(const UGPoint2D* pPoints1, const UGint* plPolyCount1, UGint lSubCount1, 
								const UGPoint2D* pPoints2, const UGint* plPolyCount2, UGint lSubCount2);

	//! \brief �����߶κ��߶�֮�伫С����
	static UGdouble MinDistance(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
								const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief �������߶κ����߶�֮����С����	
	static UGdouble MinDistance(const UGPoint2D* pPointsSrc1, const UGint* plPolySrc1, UGint lSubCount1, 
								const UGPoint2D* pPointsSrc2, const UGint* plPolySrc2, UGint lSubCount2);

	//! \brief �������߶κ����߶�֮����С����	
	static UGdouble MinDistance(const UGPoint2D* pPoints1, UGint nPntCount1,  
								const UGPoint2D* pPoints2, UGint nPntCount2  );
	//! \brief �����߶κ��߶�֮�伫С����
	static UGdouble MinDistance(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
								const UGPoint2D* pPointsSrc2, const UGint* plPolySrc2, UGint lSubCount2);


public: // �ҵ�����һ�������һ����

	//! \brief ����ֱ�ߵķ���, ��ֱ������һ����, ����ʼ��(pntStart)�ľ������dDistance
	//! \remarks ���ֱ�ߵ������㲻���غ�
	static UGPoint2D FindPoint(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
								UGdouble dDistance);

	//! \brief ����������һ����, ����ʼ��ľ������dDistance, ������Ȳ���,���ӳ����һ���߶�
	static UGPoint2D FindPoint(const UGPoint2D* pPoints, UGint nPntCount, 
								UGdouble dDistance);

	//! \brief ��ֱ��(pntStart,pntEnd)��pntStart��ʱ����תdAngle��(�Ƕȵ�λ)���ɵ�ֱ���ϣ�Ѱ�ҵ�pntStart�ľ���ΪdDistance�ĵ�
	//! \remarks ���ֱ�ߵ������㲻���غ�
	static UGPoint2D FindPoint(const UGPoint2D& pntStart, const UGPoint2D&pntEnd,
								UGdouble dDistance, UGdouble dAngle);

	
public: // ������֮��Ľ���

	//! \brief ������ֱ��֮��Ľ���
	//! \remarks ����ͨ�� ���ò�������, �ص���Ϊ��ƽ�е�
	//! \return ƽ�з���false
	static UGbool IntersectLines(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
									const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, 
									UGPoint2D& pntResult);

	//! \brief ֱ�ߺ��߶εĽ���
	//! \remarks ����ͨ�� ���ò�������, �ص���Ϊ��ƽ�е�
	//! \return ƽ�з���false
	static UGbool IntersectLineLineSeg(const UGPoint2D& pntLineStart, const UGPoint2D& pntLineEnd, 
									const UGPoint2D& pntLineSegStart, const UGPoint2D& pntLineSegEnd, 
									UGPoint2D& pntResult);

	//! \brief �߶κ��߶εĽ���
	//! \remarks ����ͨ�����ò�������; 
	//! \return ��ͬһ��ֱ����ʱ,����ص�����ֻ��һ����, ����true,���õ������, 
	//!			���û���ص�����,�����ص�������һ������, �򷵻�false
	static UGbool IntersectLineSegs(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
									const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, 
									UGPoint2D& pntResult);
	
	//! \brief �õ����ޣ����û�����ã��õ�����Ĭ�����õ�����
	static UGdouble UGGetEPSILON();

	//! \brief ��������
    static void UGSetEPSILON(UGdouble dEpsilon);

	//! \brief �߶κ��߶εĽ���
	//! \param pntStart1 �߶�1�����[in]��
	//! \param pntEnd1   �߶�1���յ�[in]��
	//! \param pntStart2 �߶�2�����[in]��
	//! \param pntEnd2 �߶�2���յ�[in]��
	//! \param pntResult ������--��������[out]��
	//! \remarks ����ͨ�����ò�������; 
	//! \return ����TRUE��ʾ�н��㣬�����޽���
	//!         ���������߶Σ�ע�⣺����ֱ�ߣ��Ľ���
	static UGbool IntersectLineSect(	
		UGPoint2D &pntStart1,			
		UGPoint2D &pntEnd1,			
		UGPoint2D &pntStart2,			
		UGPoint2D &pntEnd2,			
		UGPoint2D &pntResult
		);							

	//! \brief �߶��ڲ����߶��ڲ��Ľ���
	//! \remarks ����ͨ�����ò�������; 
	//! \return �ڲ�����Ϊһ����, ����true,���õ������, 
	//!			����Ϊ�ա�Ϊ�����߶�(����)��Ϊ�߶εĶ˵㶼����false
	static UGbool IntersectLineSegsInterior(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
											const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, 
											UGPoint2D& pntResult);
	
	//! \brief �߶κ��߶εĽ���X,Y����
	//! \remarks ����ͨ�����ò�������; 
	//! \return ��ͬһ��ֱ����ʱ,����ص�����ֻ��һ����, ����true,���õ������, 
	//!			���û���ص�����,�����ص�������һ������, �򷵻�false
	static UGbool IntersectLineSegs(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
									const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, 
									UGdouble &dx, UGdouble &dy, UGdouble &dParameter1,
									UGdouble &dParameter2);
	
	//! \brief �����������ߵ����н���
	//! \return û�н���,����false; ������ӵ�pntResults��,pntResultsԭ����Ϣ���ᱻɾ��/����
	static UGbool IntersetPolylines(const UGPoint2D* pPoints1, UGint nPntCount1, 
								   const UGPoint2D* pPoints2, UGint nPntCount2, 
								   UGPoint2Ds& pntResults);

	//! \brief �����������ߵ����н���
	//! \param pntResults ����ʱ, pntResultsӦ��Ϊ�ռ�
	//! \return û�н���,����false; 
	static UGbool IntersetPolyPolylines(const UGPoint2D* pPointsSrc1, const UGint* plPolySrc1, UGint lSubCount1, 
										const UGPoint2D* pPointsSrc2, const UGint* plPolySrc2, UGint lSubCount2, 
										UGPoint2Ds& pntResults);
	
	//�ж������߶εĹ�ϵ!!!
	// return: �ཻ��1��    �غϣ�2
	//         ���룺0��    �ص�: 3
	//CPoint2D& pntResult1,CPoint2D& pntResult2��
	//����ص��򲿷��ص���������ص��߶εĶ���;pntResult1->pntResult1�ķ�����
	//pntStart1->pntStart2��һ�����ֻ��һ�����㣬���������pntResult1�У�pntResult2��Ч��
	static UGint IntersectLineSegs(const UGPoint2D &pntStart1,const UGPoint2D &pntEnd1,
								 const UGPoint2D &pntStart2,const UGPoint2D &pntEnd2,
								 UGPoint2D& pntResult1,UGPoint2D& pntResult2);
	//! \brief ��������߶�l1��l2������ l1 �� l2 �����Ϻ���߶� l1' �� l2' 
	static UGbool IntersectLine(UGPoint2D *pPoints1, UGPoint2D *pPoints2, UGint nPointsCount1, UGint nPointsCount2,
								  UGPoint2Ds &arrLine1Out, UGPoint2Ds &arrLine2Out, UGArray<UGint> &arrVertexNumber1,
								  UGArray<UGint> &arrVertexNumber2,UGdouble dTolerance);

	// add by guohui 2007.10.09 
	//! \brief		����������ߣ����ر������
	//! \remarks	pSrcLinePoints ����Ϻ�ͨ����ϵ㣬�ֱ�����  arrLine1 �� arrLine2 �С�arrLine1 �� arrLine1 �໥����
	static UGbool SplitLine(UGPoint2D *pSrcLinePoints, UGint nSrcPointsCount, UGPoint2D *pSplitLinePoints2, UGint nSplitPointsCount,
								  UGPoint2Ds &arrLine1,UGArray<UGint> &arrlPolyCount1, 
								  UGPoint2Ds &arrLine2,UGArray<UGint> &arrlPolyCount2);

public: // ��ƽ����

	//! \brief �����ߵ�ƽ����
	//! \remark dDistance Ϊ���������� pPoints �����ƽ����;Ϊ����Ϊ�ұ�
	static UGbool Parallel(const UGPoint2D* pPoints, UGint nPntCount,
						 UGdouble dDistance, UGPoint2Ds& pntResults);

	//! \brief �����ߵ�ƽ����
	//! \remark dDistance Ϊ���������ߵ����ƽ����;Ϊ����Ϊ�ұ�
	static UGbool Parallel(const UGPoint2D &pntStart,const UGPoint2D &pntEnd,
						 UGdouble dDistance, UGPoint2D &pntResStart,UGPoint2D &pntResEnd);

// private: // �ڲ���������, �ݲ��ṩ������ʹ��

	//! \brief �õ�����ֱ�ߵĽ�ƽ������ ��һ��, �õ���������ԭֱ��ƽ�е�ֱ�� �� ԭֱ�ߵľ���ΪdDistance
	//! \remarks ����ֱ�߷ֱ�Ϊ (pnt1, pntJoint) �� (pnt2, pntJoint), ����ֱ���ཻ�� pntJoint��
	//!			���������� Parallel ������ʹ��
	
	// by guohui 2007.09.13 ����ӿ�ֻ�ܱ� Parallel ���á�
	// �ӿ��ڲ��д��󡣷��صĵ�ʵ���� -dDistance �ĵ㡣�ⲿ�������С�
	static UGPoint2D FindBisectorPoint(const UGPoint2D& pnt1, const UGPoint2D& pntJoint, 
										const UGPoint2D& pnt2, UGdouble dDistance);

public: // �ز���

	//! \brief		�����ز���
	static UGbool ReSample(const UGPoint2D* pPoints, UGint nPntCount,
						 UGdouble dTolerance, UGPoint2Ds& pntResults);
public: // ��ȡ���ϵĵ�

	//! \brief		�������Ͼ�pntStartPoint����ΪdDistance�ĵ�
	//!  \param		pntStartPoint	��ʼ��
	//!  \param		pntEndPoint		������
	//!  \param		dDistance	���룬����Ϊ���������Դ������峤��
	//! \return		pntStartPoint �� pntEndPoint�غϣ��򷵻�pntEndPoint. 
	//! \remarks	dDistance<0,��Ϊ�����ӳ����ϵĵ�
	static UGPoint2D FindPointOnLineByDistance(const UGPoint2D& pntStartPoint, const UGPoint2D& pntEndPoint, 
											UGdouble dDistance);
	
	//! \brief		�������Ͼ�pntStartPoint����ΪdDistance�ĵ�
	static UGPoint2D FindPointOnLineByDistance(const UGPoint2D* pPoints, UGint nPntCount,
											UGdouble dDistance);

	//! \brief		�������� ��pntStartPoint ���� Ϊ�����߶εĳ��ȵ� dRatio ���ĵ�
	//!  \param		pntStartPoint	��ʼ��
	//!  \param		pntEndPoint		������
	//!  \param		dRatio	����������Ϊ���������Դ���1.0
	//! \return		pntStartPoint �� pntEndPoint�غϣ��򷵻�pntEndPoint. 
	//! \remarks	dDistance<0,��Ϊ�����ӳ����ϵĵ�
	static UGPoint2D FindPointOnLineByRatio(const UGPoint2D& pntStartPoint, const UGPoint2D& pntEndPoint, 
											UGdouble dRatio);
	
	//		return 0: ����
	//		return 1: �ཻ,���㲻�����߶εĶ˵�						���ؽ���pntResult1
	//		return 2: �ཻ,�������߶�1�����						���ؽ���pntResult1
	//		return 3: �ཻ,�������߶�1���յ�						���ؽ���pntResult1
	//		return 4: �ཻ,���㲻�����߶�1�Ķ˵㣬���߶�2�����		���ؽ���pntResult1
	//		return 5: �ཻ,���㲻�����߶�1�Ķ˵㣬���߶�2���յ�		���ؽ���pntResult1
	//		return 6: S1-----S2(E2)-----E1-----E2(S2)				���ؽ���pntResult1(S2(E2)),	pntResult2(E1)
	//		return 7: S2(E2)-----S1-----E2(S2)-----E1				���ؽ���pntResult1(S1),		pntResult2(E2(S2))
	//		return 8: S1-----S2(E2)-----E2(S2)-----E1				���ؽ���pntResult1(S2(E2)),	pntResult2(E2(S2))
	//		return 9: S2-----S1(E1)-----E1(S1)-----E2				���ؽ���pntResult1(S1(E1)),	pntResult2(E1(S1))
	//		return 10: �غ�
	static UGint IntersectLineSegs(UGPoint2D &pntStart1, UGPoint2D &pntEnd1, 
									UGPoint2D &pntStart2, UGPoint2D &pntEnd2, 
									UGPoint2D &pntResult1, UGPoint2D &pntResult2,
									UGdouble &dInterval);


public: // 

	//! \brief �ϲ�������������
	static UGbool UnionMatchLine(const UGPoint2D &pntStart1,const UGPoint2D &pntEnd1,
								 const UGPoint2D &pntStart2,const UGPoint2D &pntEnd2,
								 UGPoint2D& pntResult1,UGPoint2D& pntResult2);

public: // ����

	//! \brief ����ʸ��֮��Ĳ��
	//! \remarks �ںܶ�ط����������õ���
	
	// by guohui 2007.09.13 ��CPP�ļ���ͳһ
	//	static UGdouble XMultiply(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
	//							const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);
	static UGdouble XMultiply(const UGPoint2D& pntFrom1, const UGPoint2D& pntTo1,
						const UGPoint2D& pntFrom2, const UGPoint2D& pntTo2);

	/*!	\brief	����������ת����\n
	  *	\param pPoints			��ŷ��ؽ���ĵ�����
	  *	\param pntCenter		��������������ĵ�
	  *	\param dSemiMajorAxis			������
	  *	\param dSemiMinorAxis			�̰���
	  *	\param dRotation		�������б�Ƕ�(���ȵ�λ)
	  *	\param dRadianBegin		�������ʼ�Ƕ�(���ȵ�λ)
	  *	\param dRadianEnd		�������ֹ�Ƕ�(���ȵ�λ)
	  *	\param lPointCount		���ص�ĸ���
	  *	\param dRadianGrain		ȡ�����ܶ�(���ȵ�λ)
	  *	\return �ɹ�:�㴮ͨ��pPoints���÷��أ�lPointCount���÷��ص�ĸ�����
	  *	\remarks �Ƕȵ�λΪ���ȣ���ʼ�ǿ��Ա���ֹ�Ǵ��ڲ�������Զ���񻯣�
	*/
#if PACKAGE_TYPE==PACKAGE_UGC
	static UGbool BuildArc(UGPoint2D *&pPoints,const UGPoint2D& pntCenter,
							UGdouble dSemiMajorAxis,UGdouble dSemiMinorAxis,UGdouble dRotation,
							UGdouble dRadianBegin,UGdouble dRadianEnd,UGint &lPointCount,
							UGdouble dRadianGrain = 0.05);

	/*!	\brief	����������ת����\n
	  *	\param pPoints			��ŷ��ؽ���ĵ�����
	  *	\param pntCenter		��������������ĵ�
	  *	\param dSemiMajorAxis			������
	  *	\param dSemiMinorAxis			�̰���
	  *	\param dRotation		�������б�Ƕ�(���ȵ�λ)
	  *	\param dRadianBegin		�������ʼ�Ƕ�(���ȵ�λ)
	  *	\param dRadianEnd		�������ֹ�Ƕ�(���ȵ�λ)
	  *	\param lPointCount		���ص�ĸ���
	  *	\param dRadianGrain		ȡ�����ܶ�(���ȵ�λ)
	  *	\return �ɹ�:�㴮ͨ��pPoints���÷��أ�lPointCount���÷��ص�ĸ�����
	  *	\remarks �Ƕȵ�λΪ���ȣ���ʼ�ǿ��Ա���ֹ�Ǵ��ڲ�������Զ���񻯣�
	*/
	static UGbool BuildArc(UGPoint *&pPoints,const UGPoint2D& pntCenter,
							UGdouble dSemiMajorAxis,UGdouble dSemiMinorAxis,UGdouble dRotation,
							UGdouble dRadianBegin,UGdouble dRadianEnd,UGint &lPointCount,
							UGdouble dRadianGrain = 0.05);

	static UGdouble CalcEllipseRadian(const UGdouble &dPntRadian, const UGdouble &dSemiMajorAxis,
									 const UGdouble &dSemiMinorAxis, const UGdouble& dRotateRadian);

	//! \brief ����һ����Բ��������Ƕ���Բ�ϵ�����ꡣ
	//! \param pntCenter [in] ��ԲԲ�ġ�
	//! \param dSemiMajorAxis [in] ��Բ�����ᡣ
	//! \param dSemiMinorAxis [in] ��Բ�̰��ᡣ
	//! \param dRotationAngle [in] ��Բ����ת�Ƕ�
	//! \param dPntAngle [in] ��Բ�ϵĵ��Բ������ �� ��Բ���᷽��ļнǣ� 
	//!			ע�ⲻ�Ǻ�X����ļнǣ� ��Ϊ��Բ��������ת�Ƕ�
	//! \return ��������ĵ����ꡣ
	static UGPoint2D EllipsePoint(const UGPoint2D& pntCenter, UGdouble dSemiMajorAxis, 
									UGdouble dSemiMinorAxis, UGdouble dRotationAngle, UGdouble dPntAngle);	

	static UGbool Cardinal(UGPoint2D * pPntControls, UGPoint2D * pPntCurve,UGint nCurvePoints);

	//{{ by guohui 2007.12.26 �÷�������ʹ�ã�ע�Ͱ�!
	//static UGbool CardinalToLine(UGPoint2D *pCtrlPnts, UGint nCtrlPntCount,UGPoint2D *pPntCurve, 
	//								UGint nPntPreSeg);
	//}} by guohui 2007.12.26 �÷�������ʹ�ã�ע�Ͱ�!

	static UGbool Cardinal2Line(UGPoint2D *pCtrlPoints, UGint lCtrlPointCount,
								UGPoint2D *&pResultPoints, UGint &lResultPointCount,
								UGint nPointCountPerSegment = 20);

	static UGbool Curve2Line(UGPoint2D *pCtrlPoints, UGint lCtrlPointCount,
							UGPoint2D *&pResultPoints, UGint &lResultPointCount, 
							UGint nPointCountPerSegment = 20);

	//! \brief ����B��������תֱ��
	static UGbool BSpline2Line(const UGPoint2D *pCtrlPoints, UGint lCtrlPointCount,
		UGPoint2D *&pResultPoints, UGint &lResultPointCount, UGint nPointCountPerSegment = 20);

private:
	
	static UGdouble CalcEllipseRadian(const UGdouble &dPntRadian, const UGdouble &dSemiMajorAxis,
									 const UGdouble &dSemiMinorAxis);
	
	static UGdouble GetCAR(UGint nCoefficient, UGdouble fSegment);
#endif // end declare ugc API
};

}

#endif 
