/* 
	\file UGUtilityAnalyst.h
	\brief ��ʩ���������
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGUTILITYANALYST_H
#define UGUTILITYANALYST_H

#include "NetworkAnalyst/UGNetworkAnalyst.h"
#include "Base/ugdefs.h"

namespace UGC {

class NETWORKANALYST_API UGUtilityAnalyst  : public UGNetworkAnalyst
{
public:
	UGUtilityAnalyst();

	virtual ~UGUtilityAnalyst();
	
	//!	\brief	����ģʽ
	enum UGDirectionType
	{
		UGDTPositive	= 0,	//����
		UGDTNegative	= 1,	//����
		UGDTDisable		= 2,	//��Ч����
		UGDTUninitial	= 3,	//δ��ʼ������
	};

	//!	\brief	����ˮϵ׷���ڽӾ���
	UGbool CreateTraceAdjMatrix();

	//!	\brief ɾ��ˮϵ׷���ڽӾ���
	void DeleteTraceAdjMatrix();

	//!	\brief	��������ȼ�
	//! \param  arrSourceIDs �����Դ��ID����[in]
	//!	\param arrSinkIDs ����Ļ��ID����[in]
	//!	\param strGrade ���满�εȼ��ֶ�[in]
	//!	\return �������ɹ��򴴽����εȼ��ֶΣ���д����ػ���ֵ
	UGbool BuildGrade(const UGString strCostName,UGArray<UGuint> &arrSourceIDs, UGArray<UGuint> &arrSinkIDs, const UGString& strGrade,UGbool bFindWithoutLoops = TRUE,UGbool bCreateFeild = FALSE);
	
	//!	\brief	�����������
	//! \param  arrSourceIDs �����Դ��ID����[in]
	//!	\param arrSinkIDs ����Ļ��ID����[in]
	//!	\param strDirection ������������ֶ�[in]
	//!	\param strNodeType ����ڵ������ֶ�[in]
	//!	\return �������ɹ��򴴽������ֶκͽڵ������ֶΣ���д����ؼ���ֵ
	UGbool BuildDirection(const UGString strCostName,UGArray<UGuint> &arrSourceIDs, UGArray<UGuint> &arrSinkIDs, const UGString& strDirection, 
		const UGString& strNodeType,UGbool bCreateFeild = FALSE);
	
	//!	\brief	����arrTraceIDs�еĵ����ӵ����绷· 
	//!	\param  arrTraceIDs	׷�ٵ�ID����[in]
	//!	\param  arrLoopArcID ���滷·�Ļ���ID����[out]
	//!	\return ����ɹ����ش�����·�Ļ���ID����arrLoopArcID
	UGbool FindLoops(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrLoopArcID);
	
	//!	\brief	����arrTraceIDs�еĻ������ӵ����绷· 
	//!	\param  arrTraceIDs	׷�ٻ���ID����[in]
	//!	\param  arrLoopArcID ���滷·�Ļ���ID����[out]
	//!	\return ����ɹ����ش�����·�Ļ���ID����arrLoopArcID
	UGbool FindLoopsFromArc(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrLoopArcID);
	
	//!	\brief	����arrTraceIDs�еĵ���ͨ���߲���ͨ�Ļ��� 
	//!	\param  arrResultArcID	������ͨ�Ļ���ID����[in]
	//!	\param  bFindConnected	�����TRUE�����ҵ�����ͨ�����������ǲ���ͨ����[in]
	//!	\return ����ɹ����ش�����ͨ�Ļ���ID����arrResultArcID
	UGbool FindConnected(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrResultArcID);
	
	//!	\brief	����arrTraceIDs�еĻ�����ͨ���߲���ͨ�Ļ��� 
	//!	\param  arrResultArcID	������ͨ�Ļ���ID����[in]
	//!	\param  bFindConnected	�����TRUE�����ҵ�����ͨ�����������ǲ���ͨ����[in]
	//!	\return ����ɹ����ش�����ͨ�Ļ���ID����arrResultArcID
	UGbool FindConnectedFromArc(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrResultArcID);
	
	//!	\brief	����arrTraceIDs�еĵ㹲ͬ�����λ������λ��� 
	//!	\param  arrTraceIDs	׷�ٵ�ID����[in]
	//!	\param  nMode ����ģʽ�����nMode��STTSource���ҹ�ͬ������,STTSink���ҹ�ͬ������[in]
	//!	\param  arrResultArcID	�������λ������λ���ID����[out]
	//!	\return ����ɹ����ش�����ͨ�Ļ���ID����arrResultArcID
	UGbool FindCommonAncestors(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrResultArcID);
	
	//!	\brief	����arrTraceIDs�л��ι�ͬ�����λ������λ��� 
	//!	\param  arrTraceIDs	׷�ٻ���ID����[in]
	//!	\param  nMode ����ģʽ�����nMode��STTSource���ҹ�ͬ������,STTSink���ҹ�ͬ������[in]
	//!	\param  arrResultArcID	�������λ������λ���ID����[out]
	//!	\return ����ɹ����ش�����ͨ�Ļ���ID����arrResultArcID
	UGbool FindCommonAncestorsFromArc(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrResultArcID);
	
	//!	\brief	��������ڵ�֮�������ӵ����ٻ��θ����Ļ���·�� 
	//!	\param  nStartID ��Ҫ��ѯ����ʼ�ڵ�[in]
	//!	\param  nEndID ��Ҫ��ѯ����ֹ�ڵ�[in]
	//!	\param  arrArcID  ����������ID����[out]
	//!	\param  arrNodeID �������ڵ�ID����[out]
	//!	\return ����ɹ����ش�����ͨ�Ļ���ID����arrArcID���ڵ�ID����arrNodeID
	UGbool FindLeastArcsPath(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	�����������֮�������ӵ����ٻ��θ����Ļ���·�� 
	//!	\param  nStartID ��Ҫ��ѯ����ʼ����[in]
	//!	\param  nEndID ��Ҫ��ѯ����ֹ����[in]
	//!	\param  arrArcID  ����������ID����[out]
	//!	\param  arrNodeID �������ڵ�ID����[out]
	//!	\return ����ɹ����ش�����ͨ�Ļ���ID����arrArcID���ڵ�ID����arrNodeID
	UGbool FindLeastArcsPathFromArc(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	���͵�nTraceID�е����ӵĵ����λ��θ������ٵ�·�� 
	//! \param  nTraceID ��Ҫ��ѯ��һ���ڵ�[in]
	//!	\param  nMode ����ģʽ�����nMode��STTSource��������,STTSink��������[in]
	//!	\param arrArcID	�������εĻ���ID����[out]
	//!	\param arrNodeID �������ڵ�ID����[out]
	//!	\return �������ɹ����ش���������ͨ�Ļ���ID����arrArcID���ڵ�ID����arrNodeID
	UGbool FindAlongStreamPath(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	���͵�nTraceID�е����ӵĻ������λ��߻��θ������ٵ�·�� 
	//! \param  nTraceID ��Ҫ��ѯ�Ļ���[in]
	//!	\param arrArcID	�������εĻ���ID����[out]
	//!	\param arrNodeID �������ڵ�ID����[out]
	//!	\return �������ɹ����ش���������ͨ�Ļ���ID����arrArcID���ڵ�ID����arrNodeID
	UGbool FindAlongStreamPathFromArc(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	����Դͷ�ͽ��� 
	//!	\param nTraceID		׷�ٵ�ID[in]
	//!	\param nMode		׷��ģʽ(����Դ���)[in]
	//!	\param arrArcID		׷�ٵ㵽Ŀ���(Դ���)��������·ID����[out]
	//!	\return �ɹ�:���ش���׷�ٵ㵽Ŀ����������·����arrArcI
	UGint TraceSource(const UGUtilityAnalyseParams &AnalyseParams, UGArray<UGuint> &arrArcID);
	
	//!	\brief	���ڻ��β���Դͷ�ͽ��� 
	//!	\param nTraceID		׷�ٻ���ID[in]
	//!	\param nMode		׷��ģʽ(����Դ���)[in]
	//!	\param arrArcID		׷�ٵ㵽Ŀ���(Դ���)��������·ID����[out]
	//!	\return �ɹ�:���ش���׷�ٵ㵽Ŀ����������·����arrArcI
	UGint TraceSourceFromArc(const UGUtilityAnalyseParams &AnalyseParams, UGArray<UGuint> &arrArcID);
	
	//!	\brief	�������λ����� 
	//!	\param nTraceID		׷�ٵ�ID[in]
	//!	\param nMode		׷��ģʽ(�������λ�����)[in]
	//!	\param arrArcID		������·ID����[out]
	//!	\return ����ɹ����ش���׷�ٵ㵽Ŀ����������·����arrArcID
	UGbool Trace(const UGUtilityAnalyseParams &AnalyseParams, UGArray<UGuint> &arrArcID);
	
	//!	\brief	�������λ����� 
	//!	\param nTraceID		׷�ٻ���ID[in]
	//!	\param nMode		׷��ģʽ(�������λ�����)[in]
	//!	\param arrArcID		������·ID����[out]
	//!	\return ����ɹ����ش���׷�ٵ㵽Ŀ����������·����arrArcID
	UGbool TraceFromArc(const UGUtilityAnalyseParams &AnalyseParams, UGArray<UGuint> &arrArcID);
	
	//!	\brief	������绷· 
	//!	\param arrErrorArcID	���滷·�Ļ���ID����[out]
	//!	\return �ɹ����ش�����·�Ļ���ID����arrErrorArcID
	UGbool TraceCheckError(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrErrorArcID);

private:
	//!	\brief ������ת��Ϊ�ڵ�
	//!	\param arrArcID		����ID����[in]
	//!	\param arrNodeID	ת��Ϊ��Ӧ������ڵ�ID����[out]
	UGbool ConvertArcIDsToNodeIDs(UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief������ת��Ϊ�ڵ�
	//!	\param strCostName	���ѱ���[in]
	//!	\param pCostValues	���ѽṹָ��[out]
	UGbool GetTraceFeildCost(const UGString &strCostName,UGCostValues  * pCostValues);

	//!	\brief	�����������
	//! \param  nNodeIndex �ڵ�����ֵ[in]
	//!	\param arrArcID ����ID����[in]
	//!	\param nMode ��������ģʽ[in]
	//!	\return �������ɹ��򴴽������ֶκͽڵ������ֶΣ���д����ؼ���ֵ
	UGbool BuildSingleDirection(UGCostValues  *pCostValues,UGIniMemory &IniMemory,UGint nNodeIndex, UGTraceType nMode,UGArray<UGuint> &arrArcID);
	
	//!	\brief	��������ȼ���Ҫ���Ӻ���
	//! \param  nSinkID �����Դ��ID[in]
	//!	\param arrArcGrade ���满�εȼ�����[in]
	//!	\return ��������ȼ���Ҫ���Ӻ���
	UGbool BuildSingleGrade(UGCostValues  *pCostValues ,UGIniMemory &IniMemory,UGint nSinkID, UGTraceType nMode,UGArray<UGuint> &arrArcGrade,UGbool bFindWithoutLoops = TRUE);
	
private:
	//! \brief ˮ������
	UGArray<UGuint> m_nDirection; 
	//! \brief������������
	UGArray<UGdouble*> m_arrTraceFTCost;
	//! \brief  ������������
	UGArray<UGdouble*> m_arrTraceTFCost;
	//! \brief  �����ֶ�������Ϣ
	UGArray<UGCostFields> m_arrTraceCostFields;
	//! \brief  �ڵ��ڽӱ�
	UGArray<UGPathNode*> m_TraceAdjMatrix;
	//! \brief  ������Ϣ��
	UGArray <ArcInfo> m_TraceArcInfo;
};

}

#endif 
