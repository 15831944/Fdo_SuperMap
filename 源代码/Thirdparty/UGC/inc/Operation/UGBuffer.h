/*! \file 		UGBuffer.h
*   \brief 		������ 
*   \remarks 	����Ļ�����������Բͷ��ƽͷ 
*   \author 	LIWENLONG 
*   \date 	2004-12-27 10:51:48

*   Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br> 
*        All Rights Reserved 

*    <b>����˵����</b><br> 
*	 guohui 2007.11.01	�µĻ�����ʵ���㷨(�ؼ��ʣ�ɨ�����㷨�����ת�Ƿ������桢���ߡ��ߴ�ϡ�����)
*/ 


#ifndef UGBUFFER_H
#define UGBUFFER_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGProgress.h"
#include "Algorithm/UGPoint2D.h"
#include "Geometry/UGGeoRegion.h"
#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"

namespace UGC {
//! \brief ������
/**		
ʹ������:
	(1) ����һ�� UGBufferParam ���󣬸���ʵ�������������ڲ�ֵ��
	(2) ���� UGBuffer::CreateBuffer ���û������ӿڡ�

���룺
	����0ά����(UGGeoPoint,UGGeoMultiPoint).1ά����(UGGeoLine,UGGeoLineM,UGGeoArc,
	UGGeoCircle,UGGeoPie�ȣ����������������߶����������).2ά����(UGGeoRegion,
	UGGeoRect��)
	���ݼ���0ά��1ά��2ά���ݼ���
	��¼����0ά��1ά��2ά��¼����

�����
	������
	���ݼ��������ݼ�
	��¼�������¼��

��ע��	
	(1) ��������������ݼ������¼����Ҫ���ɺϲ��Ķ���Σ�����������豣֤�Ϸ������˹�ϵ��(�Ϸ������˹�ϵ:
	��μ� UGC �� SFC �����˵����)
	(2) ����ӿڵ��ĸ����� pGeoTestLine��pTestDataset ��Ϊ����ά���ṩ���м�������ݣ��ⲿ�û�(UGC�ں˿�����Ա����)
	���贫�ݱ�������UGC �ں˲����Ӷ��м����������ȷ�Ե�ά����
	(3) ������֧�ֻ������뾶Ϊ�������������ʱ���ߵĻ��������ҷ�����Ļ����������ͱ�Ϊ������
*/	

class OPERATION_API UGBuffer  
{
public:

	//! \brief 		�߻�����������
	enum UGSideType
	{
		NONESIDE        = -1,			// �ޱ�����
		UGFULL			= 0,			// ���Ҿ�����(����뾶��ͬ)
		UGLEFT			= 1,			// ��߻���
		UGRIGHT			= 2,			// �ұ߻���
		UGFULLDIFFR		= 3				// ���Ҿ�����(����뾶����ͬ)
	};

	//! \brief 		�߻�����������
	enum UGEndType
	{
		NONEEND	        = 0,			// ��ͷ����
		UGROUND			= 1,			// Բͷ����
		UGFLAT			= 2				// ƽͷ����
	};
	enum UGSideDir
	{
		UGSIDELEFT		=0,				// ���
		UGSIDERIGHT		=1				// �ұ�
	};
	

	//! \brief �����������ṹ��	
	/**		
		(1) ����뾶��ֱ�Ӵ������֣������� m_bFieldRadius = false
		(2) ����뾶��ֱ�Ӵ������֣���뾶������ m_dBufferRadius �С������ֶ��������� m_strBufferRadius��
		(3) ��������Ҳ��ȵ�ƽͷ���壬��뾶������ m_dDiffBufferRadius ���ֶα����� m_strDiffBufferRadius��
		(4) �����������ͱ����� m_nSideType.
		(5) �������˵����ͱ����� m_nEndType.
		(6) ���ڶ������(�������ݼ�����¼��)���ɻ�������m_bUnionRegion=falsle�򷵻ض��������ԭ��������ͬ��
		(6) m_nSemicircleSegments ��Բ����ϵ��߶���Ŀ(��С4�����200)
	*/	
	struct  UGBufferParam
	{

		//! \brief �������뾶
		/** \remarks 	����Ϊ���� */
		UGdouble m_dBufferRadius;

		//! \brief �������뾶�ֶ�
		UGString m_strBufferRadius;


		//! \brief		���Ҳ��ȵ�ƽͷ�������İ뾶�� 
		//!				m_dDiffBufferRadius[UGSIDELEFT],m_dDiffBufferRadius[UGSIDERIGHT]
		/** \remarks 	UGFULLDIFFR �� UGFLAT ʱ��Ч 		*/
		UGdouble m_dDiffBufferRadius[2];

		//! \brief		���Ҳ��ȵ�ƽͷ�������İ뾶�ֶΡ� 
		//!				m_strDiffBufferRadius[UGSIDELEFT],m_strDiffBufferRadius[UGSIDERIGHT]
		/** \remarks 	UGFULLDIFFR �� UGFLAT ʱ��Ч 		*/
		UGString m_strDiffBufferRadius[2];


		//! \brief		������������
		/** \remarks	UGSideType �е�ö������			*/			
		UGint    m_nSideType;
		
		//! \brief		�������˵�����
		/** \remarks	UGEndType �е�ö������			*/			
		UGint    m_nEndType;

		
		//! \brief		��Բ��������߶���
		/** \remarks	ȱʡΪ 12,������ڵ���4,С��200		*/			
		UGint    m_nSemicircleSegments;		// 


		//! \brief		�������뾶�Ƿ����ֶδ���
		/** \remarks	ȱʡΪ false		*/			
		UGbool   m_bFieldRadius;

		//! \brief		�Ƿ�ϲ�������
		/** \remarks	ȱʡΪ true.�������󻺳�����������.	*/			
		UGbool	 m_bUnionRegion;

		//! \brief		�Ƿ񱣴��ֶ���Ϣ
		/** \remarks	ȱʡΪ false.�������󻺳�����������.	*/			
		UGbool   m_bSaveFieldInfo;

		//! \brief		����
		UGdouble m_dTolerance;
		
		UGBufferParam()
		{
			m_nSideType				= UGFULL		;
			m_nEndType				= UGROUND		;
			m_nSemicircleSegments	= 12			;
			m_bFieldRadius			= FALSE			;
			m_bUnionRegion			= TRUE			;
			m_bSaveFieldInfo		= FALSE			;
			m_dTolerance			= -1			;
		}
	};
public:

	//! \brief 		���󴴽�������
	//! \param 		pGeometry		�������֧�ֵ㡢�ߡ���
	//! \param 		BufferParam		����������
	//! \param 		buffer			���ػ����������
	//! \param 		pGeoTestLine	����Ϊ�˺���ά��ʹ�õ�ȱʡ�������ⲿ��ֱ�Ӵ��ݿ�ָ�뼴�ɡ�
	//!								����UGC2.0�ײ㿪���⣬�˲���������ʹ��
	static UGbool CreateBuffer(const UGGeometry * pGeometry,const UGBufferParam & BufferParam,
								UGGeoRegion& buffer,UGGeoLine * pGeoTestLine = NULL);

	//! \brief 		���ݼ�����������
	//! \param 		pDataset		�������֧�ֵ㡢�ߡ���
	//! \param 		BufferParam		����������
	//! \param 		pResDataset		���ػ����������ݼ�.�ⲿ��Ҫ�����ø������ݼ�
	//! \param 		pTestDataset	����Ϊ�˺���ά��ʹ�õ�ȱʡ�������ⲿ��ֱ�Ӵ��ݿ�ָ�뼴�ɡ�
	//!								����UGC2.0�ײ㿪���⣬�˲���������ʹ��
	static UGbool CreateBuffer(UGDataset *pDataset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);

	//! \brief 		��¼������������
	//! \param 		pRecordset		�������֧�ֵ㡢�ߡ���
	//! \param 		BufferParam		����������
	//! \param 		pResDataset		���ػ����������ݼ�.�ⲿ��Ҫ�����ø������ݼ�ָ��
	//! \param 		pTestDataset	����Ϊ�˺���ά��ʹ�õ�ȱʡ�������ⲿ��ֱ�Ӵ��ݿ�ָ�뼴�ɡ�
	//!								����UGC2.0�ײ㿪���⣬�˲���������ʹ��
	static UGbool CreateBuffer(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);
public:
	//! \brief 		�ⲿ����ʹ�ã����ڽӿڲ���
	static UGbool BuildRegionTest(UGDataset *pDataset,UGDataset *pResDataset);
private:

	//! \brief 		��¼������������(���Ҳ��Ȼ�����)
	//! \param 		pRecordset		�������֧�ֵ㡢�ߡ���
	//! \param 		BufferParam		����������
	//! \param 		pResDataset		���ػ����������ݼ�.�ⲿ��Ҫ�����ø������ݼ�ָ��
	//! \param 		pTestDataset	����Ϊ�˺���ά��ʹ�õ�ȱʡ�������ⲿ��ֱ�Ӵ��ݿ�ָ�뼴�ɡ�
	//!								����UGC2.0�ײ㿪���⣬�˲���������ʹ��
	static UGbool CreateBufferSIDEDIFF(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);

	//! \brief 		���ݼ�����������(�ϲ�������뾶��ͬ)
	//! \param 		pDataset		�������֧�ֵ㡢�ߡ���
	//! \param 		BufferParam		����������
	//! \param 		pResDataset		���ػ����������ݼ�.�ⲿ��Ҫ�����ø������ݼ�
	//! \param 		pTestDataset	����Ϊ�˺���ά��ʹ�õ�ȱʡ�������ⲿ��ֱ�Ӵ��ݿ�ָ�뼴�ɡ�
	//!								����UGC2.0�ײ㿪���⣬�˲���������ʹ��
	static UGbool CreateUnionBufferSameRadiu(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);

	//! \brief 		���ݼ�����������(���ϲ�������뾶��ͬ)
	//! \param 		pDataset		�������֧�ֵ㡢�ߡ���
	//! \param 		BufferParam		����������
	//! \param 		pResDataset		���ػ����������ݼ�.�ⲿ��Ҫ�����ø������ݼ�
	//! \param 		pTestDataset	����Ϊ�˺���ά��ʹ�õ�ȱʡ�������ⲿ��ֱ�Ӵ��ݿ�ָ�뼴�ɡ�
	//!								����UGC2.0�ײ㿪���⣬�˲���������ʹ��
	static UGbool CreateNotUnionBufferSameRadiu(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);

	//! \brief 		���ݼ�����������(���ϲ�������뾶����ͬ)
	//! \param 		pTestDataset	����Ϊ�˺���ά��ʹ�õ�ȱʡ�������ⲿ��ֱ�Ӵ��ݿ�ָ�뼴�ɡ�
	//!								����UGC2.0�ײ㿪���⣬�˲���������ʹ��
	static UGbool CreateUnionBufferDiffRadiu(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);

	//! \brief 		���ݼ�����������(���ϲ�������뾶����ͬ)
	//! \param 		pTestDataset	����Ϊ�˺���ά��ʹ�õ�ȱʡ�������ⲿ��ֱ�Ӵ��ݿ�ָ�뼴�ɡ�
	//!								����UGC2.0�ײ㿪���⣬�˲���������ʹ��
	static UGbool CreateNotUnionBufferDiffRadiu(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);
	
//{{==================================================
	//by guohui 2007.10.24 ����ת��Բ�����Ļ�����
private:
	enum UGBufferLineType
	{
		NONELINE			=		-1,			// �Ƿ�����
		PRIMARYLINE			=		0,			// ԭʼ��
		PARALLELLINE		=		1,			// ƽ����
		ARCLINE				=		2,			// ��
		RADIUSLINE			=		3,			// (��,ֱ)��
	};

	struct UGLineSeg
	{// Բ���Ǵ� start �� end ����ʱ����ת
		UGPoint2D			m_pntStart;						// �߶εĿ�ʼ��
		UGPoint2D			m_pntEnd;						// �߶εĽ�����
		UGbool				m_bCircleLineSeg;				// �Ƿ�Բ��
		UGPoint2D			m_pntCentral;					// �����Բ�����򱣴���Բ��
		UGPoint2Ds			m_arrIntersecPnts;				// �ཻ�ĵ�
		UGint				m_LineType;						// �ߵ�����
		UGLineSeg()
		{
			m_bCircleLineSeg = false;
			m_LineType       = 1;
		}

	};

	//  ֻ��ʾ�߶�
	struct UGLineSegEx
	{
		UGPoint2D   m_pntStart;				// �߶εĿ�ʼ��
		UGPoint2D   m_pntEnd;				// �߶εĽ�����
		UGPoint2D * m_pPntCentral;			// Բ��
		UGLineSegEx()
		{
			m_pPntCentral = NULL;
		}		
		~UGLineSegEx()
		{
			if(m_pPntCentral!=NULL)
			{
				delete m_pPntCentral;
				m_pPntCentral = NULL;
			}
		}
	};

	struct  UGLineSegPnt
	{
		UGPoint2D m_LineSegPnt;		// �߶εĵ�
		UGint     m_nIndex;			// ����

		UGLineSegPnt()
		{
			m_nIndex = -1;
		}

		friend UGbool operator < (const UGLineSegPnt & segPoint1,const UGLineSegPnt & segPoint2)
		{
			return segPoint1.m_LineSegPnt<segPoint2.m_LineSegPnt;
		}

		UGbool operator < (const UGLineSegPnt & segPoint2)
		{
			return m_LineSegPnt<segPoint2.m_LineSegPnt;
		}

		void operator = (const UGLineSegPnt & segPoint)
		{
			m_LineSegPnt = segPoint.m_LineSegPnt;
			m_nIndex = segPoint.m_nIndex;
		}
	};

	struct  UGLineSegPntEx
	{
		UGLineSegEx * m_pLineSegEx;		// �߶εĵ�
		UGbool        m_bStartPnt ;		// ��ʼ��	
		
		UGLineSegPntEx()
		{
			m_pLineSegEx = NULL;
			m_bStartPnt  = FALSE;
		}
		friend UGbool operator < (const UGLineSegPntEx & segPoint1,const UGLineSegPntEx & segPoint2)
		{
			if(segPoint1.m_pLineSegEx==NULL || segPoint2.m_pLineSegEx==NULL)
			{
				return FALSE;
			}
			
			UGPoint2D pnt1 = segPoint1.m_bStartPnt? segPoint1.m_pLineSegEx->m_pntStart:segPoint1.m_pLineSegEx->m_pntEnd;
			UGPoint2D pnt2 = segPoint2.m_bStartPnt? segPoint2.m_pLineSegEx->m_pntStart:segPoint2.m_pLineSegEx->m_pntEnd;

			return pnt1<pnt2;
		}
		
		void operator = (const UGLineSegPntEx & segPoint)
		{
			m_pLineSegEx = segPoint.m_pLineSegEx;
			m_bStartPnt = segPoint.m_bStartPnt;
		}
	};

	// �߶ε��ڽӾ�����
	struct UGLineSegNode
	{
		UGPoint2D		    m_pntFromNode	;				// ��
		UGArray<UGint>      m_nArrToIndex	;				// ��һ��
		UGArray<UGPoint2D*> m_pArrPntCentral;				// Բ������
		UGint				m_nInDegree		;
		UGLineSegNode()
		{
			m_nInDegree = 0;
		}
	};

	// �߶ε��ڽӾ���
	struct UGLineSegAdjMatrix
	{
		UGLineSegNode * m_pLineSegNode ;		// ���,����m_pntFromNode����
		UGint			m_nNodeCount ;			// ������
		UGLineSegAdjMatrix()
		{
			m_pLineSegNode = NULL;
			m_nNodeCount = 0 ;
		}
	};

private:

	//! \brief 		���ߴ���������
	// pGeoline ���ڲ���ʹ��
	static UGbool CreateLineBuffer(const UGPoint2D* pPoints, const UGint *pPolyCounts,const UGint lSubCount
								,UGGeoRegion &buffer,UGint nSideType = UGFULL,UGint nEndType =UGROUND,
								UGGeoLine * pGeoline = NULL,UGdouble *pRadius=NULL,UGProgress * pProgress = NULL);

	//! \brief 		�Ե㴴��������
	// pGeoline ���ڲ���ʹ��
	static UGbool CreatePointBuffer(const UGPoint2D* pPoints,const UGint nCount,
							UGGeoRegion &buffer,UGGeoLine * pGeoline = NULL,UGdouble *pRadius=NULL
							,UGProgress * pProgress = NULL);

	//! \brief 		���洴��������
	// pGeoline ���ڲ���ʹ��
	static UGbool CreateRegionBuffer(const UGPoint2D* pPoints, const UGint *pPolyCounts,const UGint lSubCount
								,UGGeoRegion &buffer,UGGeoLine * pGeoline = NULL,UGdouble *pRadius=NULL
								,UGProgress * pProgress = NULL);

private:
	//! \brief 		����������-����ת�Ƿ����ɻ�����
	static UGbool OutLine(const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint lSubCount,
		UGLineSeg * &pLineSegs,UGint & nLineSegCount,UGint nSideType = UGFULL,
		UGint nEndType =UGROUND,UGbool bOnlyParalLine = FALSE,UGdouble *pRadius=NULL
		,UGProgress * pProgress = NULL);


	//! \brief 		����������-�������߽��д��
	static UGbool BreakLines(UGLineSeg * &pLineSegs,UGint & nLineSegCount,UGProgress * pProgress = NULL);

	//! \brief 		ȥ���Ƿ���
	static UGbool ClearLineSegs(const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint lSubCount,
		UGLineSeg * pLineSegs,UGint nLineSegCount,
		UGLineSegEx * &pResLineSegs,UGint &nResLineSegCount,
		UGint nSideType = UGFULL,UGint nEndType =UGROUND,UGdouble *pRadius=NULL,UGProgress * pProgress = NULL);

	//! \brief 		����������-������
	static UGbool BuildRegion(UGLineSegEx * pLineSegs,UGint nLineSegCount,UGGeoRegion & buffer,
		UGPoint2Ds &pntInRgns,UGbool bNotCounterClockwise=FALSE,UGProgress * pProgress = NULL);

	//! \brief 		����������-�Ե����󴴽�ƽ����(ת��Բ��)
	static UGbool OutSingleLine(const UGPoint2D* pPoints, const UGint lCount,UGLineSeg * pLineSegs,UGint &nLineSegCount,UGbool bRight=true);

	//! \brief 		����������-���ɿ�ʼ���߽����İ�Բ��
	static UGint MakeSemicircle(const UGPoint2D& pntFrom,const UGPoint2D& pntTo,UGLineSeg * pLineSegs,UGint nSideType = UGFULL);

	//! \brief 		���ҷ�Χ�ڵ�����
	static UGbool FindIndex(UGLineSegPnt * pPnts,UGint nPntCount,UGdouble dMinX,UGdouble dMaxX,UGint &nFrom,UGint &nTo);

	//! \brief 		�߶��ཻ
	static UGbool LinesIntersect(UGLineSeg *pLineSeg1,UGLineSeg *pLineSeg2);

	//! \brief 		�߶���Բ���ཻ
	static UGbool LineArcIntersect(UGLineSeg *pLsarc,UGLineSeg *pLsline);

	//! \brief 		Բ����Բ���ཻ
	static UGbool ArcsIntersect(UGLineSeg *pArc1,UGLineSeg *pArc2);

	//! \brief 		�����ڽӾ���
	static UGbool BuildAdjMatrix(UGLineSegEx * pLineSegs,UGint nLineSegCount,UGLineSegAdjMatrix * &pLineAdjMatrix
		,UGProgress * pProgress = NULL);

	//! \brief	���ֲ���ĳ��
	static UGbool FindNextLine(UGLineSegAdjMatrix * pLineAdjMatrix,UGint nFromIndex,
								UGint nToIndex,UGint&NextToIndex,UGPoint2D* &pCurrentCirle);

	//! \brief	����תΪ�߶�
	static UGbool ArcToLines(UGLineSegEx * pLineSegs,UGint nLineSegCount,UGGeoLine * pGeoline);
	
	//! \brief	�н��Ƿ���� PI(�ɴ��жϰ���͹)
	//! \remark  1	С��PI,��;0,����PI,ֱ;-1,����PI,͹
	//!			 pntStart-pntMid �� pntMid ��ʱ����ת������	pntMid-	pntEnd�ĽǶ�		
	static UGint  AngleOverPI(const UGPoint2D &pntStart,const UGPoint2D &pntMid,const UGPoint2D &pntEnd);

	//! \brief	���ֲ���ĳ��
	static UGint FindIndexByPnt(const UGPoint2D &pnt,UGLineSegAdjMatrix * pLineAdjMatrix);
	
	//! \brief	���ڽӾ������Ƴ�ĳ�߶�
	static UGbool RemoveLineseg(UGLineSegAdjMatrix * pLineAdjMatrix,UGint nFromIndex,UGint nToNodeIndex);

	//! \brief �����ȷ����֮�䵺����ϵ
	//!			��֤���Ӷ���(˳ʱ��)����(��ʱ��)���������˳��˳����ʱ������
	static UGbool GetOrdinalRegion(UGGeoRegion &geoRegion);

	//! \brief �Ե��������
	static UGbool SortPnt(const UGPoint2D &pntFrom,const UGPoint2D &pntTo,UGPoint2Ds & ArrPnts);

	//! \brief �������е��߶�
	static UGbool SaveOutLine(UGDataset * pTestDataset,UGGeoLine * pgeoOutline);

	//! \brief ��û��ε���������������ĽǶ�(**�ȣ���ʱ��н�)
	static UGdouble GetArcAngle(const UGPoint2D&pntFrom,const UGPoint2D&pntTo,
		const UGPoint2D&pntCircle,UGbool bIn = TRUE);

	//! \brief ��ȡ�㴮
	static UGbool MatrixToLine(UGLineSegAdjMatrix * pLineAdjMatrix,	UGArray<UGint>&nArrNodeIndex,
							UGArray<UGPoint2D*>&pArrPntCentral,UGPoint2Ds& ResLinePoints);
	
private:

	// ��̬�������İ뾶
	static UGdouble m_dBufferRadiusEx ;

	static UGdouble m_dBufferRadiusExAbs ;

	// ��̬�������İ뾶��ƽ��
	static UGdouble m_dBufferRadius2Ex ;	
	
	//�����߶���, ������
	static UGint m_nSemicircleSegmentsEx;

	// ��̬�������İ뾶
	static UGdouble m_dTolerance ;

//}}==================================================
public:

	UGBuffer(UGdouble dBufferRadius, UGint nSemicircleSegments=12);
	UGBuffer();
	virtual ~UGBuffer();

	static void SetParam(UGdouble dBufferRadius, UGint nSemicircleSegments=12);

	//! \brief 	    Բ��BUFFER
	//! \return 	BOOL
	//! \param 		pPoints
	//! \param 		lCount
	//! \param 		buffer
	static UGbool CreateBuffer(UGPoint2D* pPoints,UGint lCount,UGGeoRegion& buffer);


	//! \brief 		ֱ��BUFFER
	//! \return 	BOOL
	//! \param 		*pPoints
	//! \param 		nCount
	//! \param 		dLeft	��߾�
	//! \param 		dRight  �ұ߾�
	//! \param 		&bufferRegion
	//! \param 		iFlag
	//! \remark		iFlag=1 �������
	//!				iFlag=2 �����ұ�
	//!				iFlag=3��Ĭ�ϣ�ȫ����
	static UGbool CreateBuffer(UGPoint2D *pPoints, UGint nCount, UGdouble dLeft,UGdouble dRight,
						UGGeoRegion &bufferRegion, UGint iFlag=3);

	//! \brief		ԲͷBUFFER
	static UGbool CreateBuffer(UGGeometry *pGeometry,UGGeoRegion &bufferRegion);

	//! \brief		ֱ��BUFFER
	static UGbool CreateBuffer(UGGeometry *pGeometry,UGGeoRegion &bufferRegion,UGdouble dLeft,UGdouble dRight,UGint iFlag=3);

	//! \brief		���ݼ���BUFFER
	static UGbool CreateBuffer(UGDataset *pDataset,UGDataset *pResDataset,UGbool bIsUnion = TRUE);

	//! \brief	���ݼ��ǶԳ�BUFFER
	static UGbool CreateBuffer(UGDataset *pDataset,UGDataset *pResDataset,UGdouble dLeft,UGdouble dRight,UGint iFlag=3,UGbool bIsUnion = TRUE);
private:
	static void Init();
	static void Outline(const UGPoint2D& pntStart,const UGPoint2D& pntEnd, UGGeoRegion*& pSkewRect);
	static void MakeSemicircle(const UGPoint2D& point,UGdouble dx,UGdouble dy,UGbool bUp,UGPoint2D* pPoints);
	static inline UGdouble CosAdd(UGdouble doSin,UGdouble dSin,UGdouble doCos,UGdouble dCos);
	static inline UGdouble SinAdd(UGdouble doSin,UGdouble dSin,UGdouble doCos,UGdouble dCos);
	static void MakeCircle(UGPoint2D *pPoints,UGint nSemicircleSegments);

private:
	static UGbool Buffer(UGint nStartPointID,UGint nEndPointID,UGPoint2D* pLeftPoints,
					UGPoint2D* pRightPoints,UGGeoRegion &RegionResult);

private:

	//�뾶�Ͱ뾶��ƽ��
	static UGdouble m_dBufferRadius;
	static UGdouble m_dBufferRadius2;
	//�����߶���, ������
	static UGint m_nSemicircleSegments;
	static UGPoint2D *m_pCirclePoints;
};

}

#endif // !defined(UGBUFFER_H)
