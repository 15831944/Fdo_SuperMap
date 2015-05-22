// UGKrigingBuilder.h: interface for the UGKrigingBuilder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGKRIGINGBUILDER_H)
#define UGKRIGINGBUILDER_H

#include "GridAnalyst/UGGridBuilder.h"
#include "GridAnalyst/UGGridOptions.h"

namespace UGC{
class UGQuadNode;
class UGKdTree;
class UGKrigingBuilder: public UGGridBuilder  
{
public:    
	UGKrigingBuilder();
	virtual ~UGKrigingBuilder();
	//! \brief ���������ȷʡ���� not implemented yet
	void CalculateDefaultParameters(UGdouble& dRange,UGdouble& dNugget,UGdouble& dSill,const UGGridOptions& options);
protected:
	//! \brief ͨ�������������в�ֵ
	virtual UGbool DoInterpolation(UGDatasetRaster* pResultGrid,const UGGridOptions& options);	
	//! \brief ��������������ȫ���ĵ�������㣬����ڵ������Ƚ��ٵ�ʱ��Ƚ���Ч
	UGbool Interpolate1(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief ����KDTree���ٽ���ķ�������,ָ������
	UGbool Interpolate2(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief ����KDTree����ʱ��,ָ������
	UGbool Interpolate21(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief �����Ĳ����ֿ���в�ֵ
	UGbool Interpolate3(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief Implemention details here
	void QuadInterpolate(UGDatasetRaster* pResultGrid,UGQuadNode* pTree);
	//! \brief �����ݽ��з���,not implemented yet
	void RegroupThePoints(UGdouble dLagSize, UGint nLagNums);
	
	UGdouble KGetRange(void);
	UGbool TranspMatrix(UGdouble *pMatrix_arg, UGint iM_arg,UGint iN_arg,UGdouble *pTranspMatrix_arg);	
	//���ܣ��������ĳ˻���
	//������pLMatrix_arg: ������ָ�룻
	//      iLm_arg     : ������������
	//      iLn_arg     : ������������
	//      pRMatrix_arg: �Ҿ����ָ�룻
	//      iRm_arg     : �Ҿ����������
	//      iRn_arg     : �Ҿ����������
	//      pMultiMatrix_arg : �˻���Ľṹ����
	//����ֵ���������ɹ�����true,���򷵻�false;
	//  ���ܵĸĽ���������˹����ɭ�㷨ʵ�֡�    
	UGbool CalMatrix(UGdouble  *pLMatrix_arg,UGint iLm_arg,UGint iLn_arg, UGdouble *pRMatrix_arg,UGint iRm_arg,UGint iRn_arg,UGdouble *pMultiMatrix_arg);
	
	//���ܣ���Gause-Jordan����������������
	//       ������ά��<20ʱ���á�
	//����: pMatrix_arg:��Ҫ�������ľ���
	//      iN_arg: �������Ľ�����
	//����ֵ������ɹ�����true;���򷵻�false;
	UGbool  KCalInverMatrix(UGdouble *pMatrix_arg,UGint iN_arg);
	//}}Kriging��ֵ�ø������� added by caogf 2003-6-7 

	//����:�������Э����;
	//����:pMatrix_arg:ָ��Ҫ����ľ����ָ��;
	//      iM_arg    :������������;
	//      iN_arg    :������������;
	//  pCovMatrix_arg:Ҫ���صľ���ָ��;
	//�������:8/9/2002
	UGbool CalCov( UGdouble *pMatrix_arg,UGint iM_arg, UGint iN_arg,UGdouble *pCovMatrix_arg);
	
protected:
	UGQuadNode* m_pQuadRoot;
	UGKdTree* m_pKdTree;	
	UGdouble m_dSill;
	UGdouble m_dNugget;
	UGdouble m_dRange;
	UGGridOptions::VariogramMode m_nVairogramMode;
	UGint m_nMax;
	UGint m_nMax2;
	UGint m_nNodeCount;
	UGint m_nCurrentNode;
};
}

#endif // !defined(UGKRIGINGBUILDER_H)





















