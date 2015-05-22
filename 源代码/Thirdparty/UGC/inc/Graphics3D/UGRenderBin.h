// UGRenderBin.h: interface for the UGRenderBin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGRENDERBIN_H)
#define UGRENDERBIN_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Base/UGArray.h"
namespace UGC{
class UGRenderLeaf;
class UGRenderGraph;
class UGRenderStage;
//!\brief �����Ƶ�������Ϊһ�������Ⱦ������͸��
class GRAPHICS3D_API UGRenderBin  
{
public:
	typedef UGArray<UGRenderLeaf*> RenderLeafList;
	typedef UGArray<UGRenderGraph*> RenderGraphList;
	enum SortMode
	{
		NO_SORT,
		SORT_BY_MATERIAL,
        SORT_FRONT_TO_BACK,
        SORT_BACK_TO_FRONT
	};
public:
	UGRenderBin();
	virtual ~UGRenderBin();

	virtual void Reset(){};
	virtual void Clear(){};

	void AddRenderGraph(UGRenderGraph* pRenderGraph);	

	UGRenderBin* GetParent();
	void SetParent(UGRenderBin* pParent);

	void SetSortMode(SortMode sm);
	SortMode GetSortMode();

	//! ���ݲ�ͬ�����ã���������
	void Sort();
	//! ��ʼ��
	void Draw(UGGraphics3D* pGraphics3D);

protected:
	void SortFromBackToFront();
	void SortFromFrontToBack();
	void SortByMaterial();	
	
	UGRenderStage* m_pParent;
	RenderGraphList m_GraphList;
	RenderLeafList m_LeafList;
	SortMode m_enSortMode;
};

}

#endif // !defined(AFX_UGRENDERBIN_H__1DD8212D_5367_445D_95B1_5E62978A324F__INCLUDED_)
