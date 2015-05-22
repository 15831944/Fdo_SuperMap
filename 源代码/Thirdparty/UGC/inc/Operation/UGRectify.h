/*! \file 		UGRectify.h
*   \brief 		����ʽ����У�� (polynomal geometrical correction) 
*   \remarks 	��׼ 
*   \author 	LIWENLONG 
*   \date 	2004-12-27 10:55:13

*   Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br> 
*        All Rights Reserved 

*    <b>����˵����</b><br> 
*/ 


#if !defined(UGRECTIFY_H)
#define UGRECTIFY_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"
#include "Algorithm/UGMatrix.h"
#include "Algorithm/UGPoint2D.h"
#include "Geometry/UGGeometry.h"
#include "Engine/UGDataSource.h"

namespace UGC{


class OPERATION_API UGRectifyError  
{
public:
	UGRectifyError(){};
	virtual ~UGRectifyError(){};
public:
	UGdouble dResidualX;  //X����в�
	UGdouble dResidualY;  //Y����в�
	UGdouble dOffsetX;    //X����ƫ�Ƶ����ظ���
	UGdouble dOffsetY;    //Y����ƫ�Ƶ����ظ���
    UGdouble dRMS;        //�õ�ľ�����
};

class OPERATION_API UGRectifyErrors : public UGArray <UGRectifyError>
{
public:
	UGRectifyErrors()
	{
	};
	virtual ~UGRectifyErrors()
	{
		if(UGRectifyErrors::GetSize()>0)
		{
			UGRectifyErrors::RemoveAll();
		}
	};
public:
	UGdouble m_dTotalRMS;
};


class OPERATION_API UGRectify  
{
public:
	UGRectify();
	virtual ~UGRectify();

	enum seTransformMethod
	{
		sctRect		= 0, /// ������׼(����2����)
		sctLinear	= 1, /// ������׼(����3����) 
		sctSquare	= 2, /// ������׼(����6����)
		sctCubic	= 3 /// ������׼(����10����)
	};

	//! \brief 		��ȡ��׼�����Ϣ��
	//! \return 	UGbool
	//! \param 		errors
	//! \param 		nMethod
	//! \remarks 		
	UGbool GetErrors(UGRectifyErrors& errors,UGlong nMethod);

	//! \brief 		���ÿ��Ƶ�
	//! \return 	UGbool
	//! \param 		OriginalPoints ԭʼ���Ƶ�
	//! \param 		TargetPoints   Ŀ����Ƶ�
	//! \remarks 		
	UGbool SetContrlPoints(UGPoint2Ds& OriginalPoints,UGPoint2Ds& TargetPoints);

	//! \brief 		����ԭʼ���Ƶ�
	//! \return 	UGbool
	//! \param 		OriginalPoints
	//! \remarks 		
	UGbool SetOriginGCP(UGPoint2Ds& OriginalPoints);

	//! \brief 		����Ŀ����Ƶ�
	//! \return 	UGbool
	//! \param 		TargetPoints
	//! \remarks 		
	UGbool SetTargetGCP(UGPoint2Ds& TargetPoints);

	//! \brief 		�任ʸ�����ݶ���
	//! \return 	UGbool
	//! \param 		nMethod
	//! \param 		pGeometry
	//! \remarks 	��׼����	
	UGbool RectifyGeometry(UGlong nMethod,UGGeometry* pGeometry);
	//! \brief 		�任ʸ��ͼ��
	//! \return 	UGbool
	//! \param 		nMethod
	//! \remarks 	��׼����	
	UGbool RectifyVector(UGlong nMethod);

	//! \brief 		����
	//! \return 	BOOL
	//! \remarks 		
	UGbool RectifyUndo();
	

	//! \brief 	    ����
	//! \return 	BOOL
	//! \remarks 		
	UGbool RectifyRedo();

	//! \brief 		��׼Ӱ��ͼ��
	//! \return 	UGbool
	//! \param 		nMethod        ��׼����
	//! \param 		strNewLayer
	//! \param 		pSmDatasource=NULL
	//! \remarks 	�����µ����ݼ����ڵ�����Դ��������readonly�򿪵ģ����pSmDatasource==NULL,Ĭ��ʹ��m_pImgDataset���ڵ�����Դ	
	UGbool RectifyImg(UGlong nMethod,UGString strNewLayer,UGDataSource* pSmDatasource=NULL);

	//! \brief 		���ز�����׼Ӱ��ͼ��
	//! \return 	UGbool
	//! \param 		nMethod
	//! \remarks 	��׼����
	UGbool Rectify(UGlong nMethod);

	//! \brief 		�õ��ܵľ�����
	//! \return 	UGdouble
	//! \remarks 		
	UGdouble GetTotalRMS();

	//! \brief 		�õ�����ʽ��ϵ����
	//! \return 	UGString
	//! \remarks 		
	UGString GetCoefficient();

	//! \brief 		����դ����׼���������µ����ݼ�
	//! \return 	UGbool
	//! \remarks 		
	UGbool RectifySelf();

protected:

	//! \brief 		����ת������
	//! \return 	UGint
	//! \param 		nMethod			TRUEΪֱ�ӷ���FALSEΪ��ӷ�
	//! \param 		bMethod=FALSE
	//! \remarks 	����1��ʾ�ɹ�������0��ʾʧ�ܣ�����-1��ʾ���ܽ��иôβ����ļ��㣬�轵�δ���	
	UGint CalParam(UGlong nMethod,UGbool bMethod=FALSE);

	//! \brief 		����ת������,ֻ��ϵ������ͼ���������ϵ������	
	//! \return 	UGbool
	//! \param 		nMethod
	//! \param 		InvsParamX		InvsParamX,InvsParamYΪ��������ϵ��
	//! \param 		InvsParamY
	//! \param 		bMethod=FALSE	TRUEΪֱ�ӷ���FALSEΪ��ӷ�
	//! \remarks 		
	UGbool CalParamSimple(UGlong nMethod,UGMatrix& InvsParamX,UGMatrix& InvsParamY,UGbool bMethod=FALSE);

	//X���귴��
	UGdouble XTransPoint(UGint numParam,UGMatrix& TransParam,UGPoint2D &point);
	//Y���귴��
	UGdouble YTransPoint(UGint numParam,UGMatrix& TransParam,UGPoint2D &point);

	//X���귴��
	//ע��ֻ���ز���ʱΪ�˼��ٲ�ʹ�õģ�����Ԥ���趨��������m_dParamX
	UGdouble XTransPoint(UGint numParam,UGPoint2D &point);
	//Y���귴��
	//ע��ֻ���ز���ʱΪ�˼��ٲ�ʹ�õģ�����Ԥ���趨��������m_dParamY
	UGdouble YTransPoint(UGint numParam,UGPoint2D &point);

	//���귴��   �ɱ任��ĵ����乲��������
	UGdouble TransPoint(UGint numParam,UGMatrix& TransParam,UGPoint2D& point);

	//���ڽ�Ԫ�ز��� 
    UGbool NeighborestResample();

	//��������ȡ��
	UGint GetInt(UGdouble dvalue);

	//�õ��任��ĵ������귶Χ
	UGbool RectifyMBR(UGlong nMethod);

	//! \brief 		����ϵ������
	//! \return 	UGbool
	//! \param 		&pntXY			���Ƶ�����
	//! \param 		Coefficent		������ת��������ϵ������
	//! \param 		nMethod			��׼����
	//! \remarks 		
    UGbool SetCoefficientMatrix(UGPoint2Ds &pntXY,UGMatrix& Coefficient,UGlong nMethod);

	//! \brief 		���ؼ�Ȩ���ת������
	//! \return 	UGbool
	//! \param 		Coefficient		ϵ������
	//! \param 		&XYMatrix		X/Y��������
	//! \param 		ReParam			X/Y�����Ȩ���ת������
	//! \remarks 		
	UGbool CalcuReParam(UGMatrix& Coefficient,UGMatrix &XYMatrix,UGMatrix& ReParam);

	//! \brief 		����X/Y�������������
	//! \return 	UGbool
	//! \param 		&Coefficient	ϵ������
	//! \param 		&Observation	һ��X/Y�Ĺ۲�ֵ
	//! \param 		&Param			�ɶ��˷������ת������
	//! \param 		&RectifierX		����������
	//! \remarks 		
	UGbool CalcuError(UGMatrix &Coefficient,UGMatrix &Observation,UGMatrix &Param,UGMatrix &Rectifier);

public:
    //!ָ��Ӱ�����ݼ�
	UGDatasetRaster* m_pImgDataset;
	//!ָ���µ�Ӱ�����ݼ�
	UGDatasetRaster* m_pNewImgDataset;
	//!ָ��ʸ�����ݼ�
	UGDatasetVector* m_pDatasetVector;

protected:
	
	//ԭʼ���Ƶ�
	UGPoint2Ds m_SrcControlPoint;
	//Ŀ����Ƶ�
	UGPoint2Ds m_DestControlPoint;
	//��׼������ݼ��������귶Χ
	UGRect2D m_rcRectify;

	UGlong m_lColIndex;             //ԭʼͼ�����к�
	UGlong m_lRowIndex;             //ԭʼͼ�����к�
	UGlong m_lNewColIndex;          //�µ�ͼ�����к�
	UGlong m_lNewRowIndex;          //�µ�ͼ�����к�

	UGMatrix m_ParamX;  //X��ת��ϵ��
	UGMatrix m_ParamY;  //Y��ת��ϵ��
	UGMatrix m_ErrorX;  //X��������
	UGMatrix m_ErrorY;  //Y��������

	UGdouble m_dParamX[10];
	UGdouble m_dParamY[10];

	UGdouble m_dTotalRMS; //��С������֮��
	
};

}

#endif // !defined(UGRECTIFY_H)
