/* 
	\file UGTopoProcess.h
	\brief ���˴���
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGTOPOPROCESS_H
#define UGTOPOPROCESS_H

#include "Engine/UGTopoDataset.h"

namespace UGC {

class OPERATION_API UGTopoProcess  
{
public:
	UGTopoProcess();
	virtual ~UGTopoProcess();
	
	//! \brief  ������Ч����
	/**
	������Ч�������ʹ�������ݼ����õ����˹�����Ч�������������Ӧ�Ĵ������ݼ���
	 \param		pTopology		�������ݼ�ָ������
	 \return	�������ݼ��Ϸ�����TRUE�����򷵻�FALSE
	 \remarks	
	*/
	static UGbool ValidateTopology(UGDatasetTopo* pTopology);
	
	//! \brief  ����Ԥ����
	/**
	����Ԥ����Ҫ���������£�1����㲶׽��2�����뽻�㣻3�����Ӷ��󵺡������������˳��˳����ʱ������
	 \param		parrDatasets		���ݼ�ָ������
	 \param		arrPricision		���ݼ���������
	 \return	�������󷵻�TRUE���޴��󷵻�FALSE
	 \remarks	���ݼ�����ֵԽ���ʾ���ݾ���Խ�ߣ���������Խ�ã� ��㲶׽��ѭ�;����������߾������ݿ�£��
	*/
	static UGbool TopoIniProcess(UGArray<UGTopoDTPricision> &arrTopoDTPricision, UGdouble dInterval=EP);

private:
	static UGbool SaveError(UGRecordset* pRecordset, UGRecordset* pRSCheck, UGArray<UGint> &arrIDs, 
							UGArray<UGint> &arrCheckIDs, UGint nTopoRule, UGDatasetVector* pDTError);
	
	static UGbool SaveError(UGRecordset* pRecordset, UGArray<UGint> &arrIDs, UGArray<UGPoint2D> &arrpnts,
							UGint nTopoRule, UGDatasetVector* pDTError);
	
	static UGbool SaveError(UGRecordset* pRecordset, UGArray<UGint> &arrIDs, UGint nTopoRule, 
							UGDatasetVector* pDTError);
	
	static UGbool SaveError(UGRecordset* pRecordset, UGArray<UGGeoRegion*> &arrpGeoRegion, UGint nTopoRule, 
							UGDatasetVector* pDTError);
	
	static UGbool SaveError(UGRecordset* pRecordset, UGArray<UGGeoLine*> &arrpGeoLine, UGint nTopoRule, 
							UGDatasetVector* pDTError);
};

}

#endif // !defined(UGTOPOCHECK_H)
