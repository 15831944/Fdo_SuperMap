// UGQuadDataset.h: interface for the UGQuadDataset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGQUADDataset_H__57354CBC_0666_400A_81A6_D7D2D040F237__INCLUDED_)
#define AFX_UGQUADDataset_H__57354CBC_0666_400A_81A6_D7D2D040F237__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"
#include "Scene/UGVectorDatasetAtr.h"
namespace UGC
{
class UGDataset;
class SCENE_API UGQuadDataset: public UGRenderObject
{
public:
	UGQuadDataset(const UGVectorDatasetAtr& DatasetAtr);
	UGQuadDataset();
	virtual ~UGQuadDataset();
	virtual void Release();
	virtual void Initialize();
	virtual void Update();
	virtual void Render();	
	void SetNeedTestVisible(UGbool bNeedTestVisible);
	// ��������ǰ����ݼ����õ���ʾ����ȥ�����bImmediately=FALSE���ݲ����������ص���ʾ���ڣ�����Ҫ��ʾ
	//��ʱ��ż��أ��������ݼ����ú󣬲��������ͷ����ݼ��� ���bImmediately=TRUE�������������ص���ʵ����
	//���ݼ����������Ӻ��ͷ�
	void ConnectDataset(const UGVectorDatasetAtr& DatasetAtr,UGbool bImmediately=TRUE);
	UGVectorDatasetAtr GetConnectDataset();
	// ���ڼ��ط����ݼ����ݵ�ʱ������Լ�����ĵ㣬�����Ϻ�Ҫʹ�����������־�����Ѿ�����
	void SetDataLoaded(UGbool bLoaded=TRUE);
	virtual void AddDataFromDataset(const UGVectorDatasetAtr& DatasetAtr);
protected:
	UGbool m_bNeedTestVisible;
	UGVectorDatasetAtr m_DatasetAtr;
};
}

#endif // !defined(AFX_UGQUADDataset_H__57354CBC_0666_400A_81A6_D7D2D040F237__INCLUDED_)
