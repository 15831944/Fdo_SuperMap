/* 
	\file UGOverlayAnalyst.h
	\brief ���ӷ����࣬�����ü����󽻡�������ͬһ���ϲ����ԳƲ���²���
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵����</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#ifndef UGOVERLAYANALYST_H
#define UGOVERLAYANALYST_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"
#include "Topology/UGTopoOverlay.h"

namespace UGC {

class UGDataSource;
class UGDatasetVector;

class OPERATION_API UGOverlayAnalyst
{
public:
	UGOverlayAnalyst();
	virtual ~UGOverlayAnalyst();
	
	//! \brief ���ӷ�������
	enum UGOverlayMode
	{   //! \brief �ü�
		UGClip		= 0,
		//! \brief ����	
		UGErase		= 1,
		//! \brief ͬһ
		UGIdentity	= 2,
		//! \brief �ཻ
		UGIntersect	= 3,
		//! \brief �ԳƲ�
		UGSymmetric	= 4,
		//! \brief �ϲ�
		UGUnion		= 5,
		//! \brief ����
		UGUpdate	= 6,
	};
	
	//! \brief		��������
	//! \param		dInterval	���õ�����
	//! \return		���óɹ�����TRUE���޴��󷵻�FALSE
	//! \remarks	�� dInterval<EP,�����EP��Ϊ����
	void SetInterval(UGdouble dInterval);
	
	//! \brief	��ȡ�����õ�����
	//! \param	dInterval ���õ�����
	//! \return	��������ֵ
	//! \remarks	
	UGdouble GetInterval();
	
	//! \brief	���úͻ�ȡԴ���ݼ����ֶ� 
	//! \param	arrFieldSrc Դ���ݼ�(�����еı����ӵ����ݼ�)��Ҫ�������ֶ�
	//! \param	arrFieldOp  �������ݼ�(�����еĵ��ӵ����ݼ����������ݼ�)��Ҫ�������ֶ�
	UGbool SetFields(UGStrArray& arrFieldSrc, UGStrArray& arrFieldOp);
	
	/*!	\brief	��ȡԴ���ݼ����ֶ� */
	//! \param	arrFieldSrc Դ���ݼ�(�����еı����ӵ����ݼ�)��Ҫ�������ֶ�
	UGbool GetFieldSrc(UGStrArray& arrFieldSrc);
	
	/*!	\brief	���ò������ݼ����ֶ� */
	//! \param	arrFieldOp  �������ݼ�(�����еĵ��ӵ����ݼ����������ݼ�)��Ҫ�������ֶ�
	UGbool GetFieldOp(UGStrArray& arrFieldOp);
	
	//! \brief ���ݼ�֮����Ӳ���
	//! param		pSrcDataset		Դ���ݼ�
	//! param		pDTRegion		���������ݼ�
	//! param		pDestDataset	������ݼ�
	//! param		nMode			������������
	//! remarks		pDTRegion�����������ݼ�
	UGbool Overlay(UGDatasetVector *pDataset, UGDatasetVector *pDTRegion, UGDatasetVector *pDestDataset,
		const UGOverlayMode nMode);
	
	//! \brief ��¼��֮����Ӳ���
	//! param		pRecordset		Դ��¼��
	//! param		pRSRegion		�������¼��
	//! param		pDestDataset	������ݼ�
	//! param		nMode			������������
	//! remarks		pRSRegion���������¼��
	UGbool Overlay(UGRecordset *pRecordset, UGRecordset *pRSRegion, UGDatasetVector *pDestDataset, 
		const UGOverlayMode nMode);
	
	//! \brief 		�ü����ݼ�����
	//! \param 		*pSrcDataset Դ���ݼ�
	//! \param 		*pClipRegion ���������ݼ�
	//! \param 		*pDestDataset ������ݼ�
	//! \remarks 	2.0�汾ֻ֧����ü��ߡ���ü��棻	
	UGbool ClipDatasets(UGDatasetVector *pSrcDataset, UGGeoRegion *pClipRegion, UGDatasetVector *pDestDataset);
	
private:

	//! \brief 		�����ݼ����ӷ���
	UGbool OverlayPoints(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetRes, 
						 UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						 UGOverlayMode nMode);
	
	//! \brief 		�����ݼ����ӷ���
	UGbool OverlayLines(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetRes, 
						 UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						 UGOverlayMode nMode);
	
	//! \brief 		�����ݼ����ӷ���
	UGbool OverlayRegions(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetRes, 
						 UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						 UGOverlayMode nMode);
	
	//! \brief 		��¼�����ӷ���
	UGbool Overlay(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetRes, 
					UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
					UGOverlayMode nMode);
	
	//! \brief 		�жϴ�������Ƿ���Ч
	UGbool IsValid(UGDatasetVector *pDatasetSrc, UGDatasetVector *pDatasetTag, UGDatasetVector *pDatasetRes, 
					UGOverlayMode nMode);
	
	//! \brief 		�������ݼ����ӷ������
	UGbool SaveLeftObjects(UGDatasetVector *pDatasetSrc, UGDatasetVector *pDatasetTag, UGDatasetVector *pDatasetRes, 
						UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						UGOverlayMode nMode);
	
	//! \brief 		�����¼�����ӷ������
	UGbool SaveLeftObjects(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetRes, 
						UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						UGOverlayMode nMode);
	
	//! \brief 		���ݼ�¼������Ŀ���ֶ�
	UGbool CreateDestFeilds(UGRecordset* pRecordsetSrc, 
							UGRecordset* pRecordsetTag, 
							UGDatasetVector *pDatasetRes, 
							UGStrArray& arrFieldSrc, 
							UGStrArray& arrFieldTag, 
							UGStrArray& arrFieldRes, 
							const UGOverlayMode nMode);
	
	//! \brief 		�������ݼ�����Ŀ���ֶ�
	UGbool CreateDestFeilds(UGDatasetVector *pSrcDataset,
							UGDatasetVector *pDSRegion, 
							UGDatasetVector *pDestDataset,
							UGStrArray& arrFieldSrc, 
							UGStrArray& arrFieldTag, 
							UGStrArray& arrFieldRes, 
							const UGOverlayMode nMode);
	
	//! \brief 		�����ֶ���
	UGbool AdjustFieldNames(UGFieldInfos& fields);
private:

	//! \brief 		����
	UGdouble m_dInterval;

	//! \brief 		Topo����
	UGTopoOverlay m_TopoOverlay;

	//! \brief 		Դ���ݼ���Ҫ������ֶ�
	UGStrArray m_arrFieldSrc;

	//! \brief 		Ŀ�����ݼ���Ҫ������ֶ�
	UGStrArray m_arrFieldTag;
};

}

#endif // !defined(UGOVERLAYANALYST_H)
