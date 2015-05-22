// UGDatasetTopo.h: interface for the UGDatasetTopo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATASETTOPO_H__6F79F774_FF2A_4EB2_AB64_A5958D572828__INCLUDED_)
#define AFX_UGDATASETTOPO_H__6F79F774_FF2A_4EB2_AB64_A5958D572828__INCLUDED_

#include "Engine/UGDataset.h"
#include "Engine/UGDatasetVector.h"

namespace UGC{

	struct UGTopoDTPricision
	{
		UGDatasetVector *pDataset;
		UGint nPricision;
	};

	struct UGTopoRule
	{
		UGint nID;
		UGDatasetVector *pDataset;
		UGDatasetVector *pCheckDataset;
		UGint nRule;
	};

class ENGINE_API UGDatasetTopo : public UGDataset
{
public: 
	UGDatasetTopo();
	virtual ~UGDatasetTopo();

public:
	enum TopoRuleMode
	{
		UGTopoRegionOverlapB			=0,	
		UGTopoRegionGapsS				=1,	
		UGTopoRegionNotCoveredM			=2,	
		UGTopoRegionNotCoveredEachM		=3,	
		UGTopoRegionNotContainedM		=4,	
		UGTopoRegionNotContainPointM	=5,	
		UGTopoLineOverlapB				=6,	
		UGTopoLineOverlapSelfS			=7,	
		UGTopoLineIntersectS			=8,	
		UGTopoLineIntersectSelfS		=9,	
		UGTopoLineIntersectORTouchS		=10,
		UGTopoLineDangleNodeS			=11,
		UGTopoLinePseudoNodeS			=12,
		UGTopoLineEndPointNotCoveredM	=13,
		UGTopoPointNotContainedM		=14,
		UGTopoPointNotCoveredByEndPointM=15,
		UGTopoBoundaryNotCoveredM		=16,
		UGTopoMultiPartS				=17,
	};
	
	//! �������ݼ�����
	virtual DatasetType GetType() const{
		return Topo;
	};

	//! �������ݼ���Ӧ����
	virtual UGString GetTableName();

	//! ������С�߳�
	virtual UGdouble GetMinZ();

	//! ������С�߳�
	virtual void SetMinZ(UGdouble d);

	//! �������߳�
	virtual UGdouble GetMaxZ();

	//! �������߳�
	virtual void SetMaxZ(UGdouble d);

	//! �������ݼ���ά��
	virtual UGint GetDimension();

	//! �ж��Ƿ���ʸ�����ݼ�
	virtual UGbool IsVector();

	//! �ж��Ƿ���topo���ݼ�
	virtual UGbool IsTopoDataset();

	//! �ж��Ƿ���դ�����ݼ�
	virtual UGbool IsRaster();

	virtual UGbool IsLinkTable(){return FALSE; };

	//! �������ݼ��ķ�Χ
	virtual const UGRect2D& GetBounds() const
	{
		return m_rcBounds;
	};

	//! �������ݼ��ķ�Χ
	virtual void SetBounds(const UGRect2D& r);

	//! ���ؿռ����ݱ��뷽ʽ
	virtual UGDataCodec::CodecType GetCodecType();
	
	//! ���ÿռ����ݱ��뷽ʽ
	virtual void SetCodecType(UGDataCodec::CodecType c);

public:
	UGdouble GetInterval();
	void SetInterval(UGdouble dInterval);
	UGbool SaveDirtyRegion(UGGeoRegion *pGeo);
public:
	//topo���
	//! \brief ��Topo���ݼ������һ�����ݼ�
	//! \param *pDatasetVector [in] ���ݼ�
	//! \param dInterval [in] ����
	//! \return ��
	//! \remarks ������ͬһ������Դ�����ݼ�
	//! \attention 
	virtual UGbool AddDataset(UGDatasetVector *pDatasetVector,UGint nPricision);

	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,UGDatasetVector *pdatasetCheck,TopoRuleMode nRule);
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,TopoRuleMode nRule);

	//! ����ѡ�����ݼ����й��������ݼ���ȷ��ɾ��Rule
	//��Ҫע��һ�����������ݼ��ж��Rule�������С��ɾ������
	virtual UGbool DeleteRule(TopoRuleMode nRule, const UGString &strSrcName, const UGString &strCheckName = "");

	//! ���Topo�����ݼ�,����ʵ��
	virtual UGbool GetAllRelation(UGArray<UGTopoDTPricision> &aryTopoRelations);

	virtual UGbool GetAllRules(UGArray<UGTopoRule> &aryRules);

	//! ���Topo�������ݼ�,����ʵ��
	virtual UGDatasetVector * GetPointErrorDataset();
	virtual UGDatasetVector * GetLineErrorDataset();
	virtual UGDatasetVector * GetRegionErrorDataset();
	virtual UGDatasetVector * GetDirtyAreaDataset();

	UGGeoRegion * GetDirtyArea();

protected:
	virtual UGbool AddSubDataset(UGTopoDTPricision structTopo);
	
protected:
	//! ���ݼ��������ݼ�ָ��
	UGSubDtArray m_ArySubDataset;
	UGArray<UGTopoDTPricision> m_aryTopoRelationDts;
	UGArray<UGTopoRule> m_aryTopoRules;
	UGString m_strName;
	UGint m_nOptions;
	UGRect2D m_rcBounds;
	UGdouble m_dInterval;
};

}

#endif // !defined(AFX_UGDatasetTopo_H__6F79F774_FF2A_4EB2_AB64_A5958D572828__INCLUDED_)
