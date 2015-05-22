/* 
	\file UG3DLineSet.h
	\brief �߼��࣬����ͳһ�ķ��
	\author ������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/


#if !defined(AFX_UG3DLINESET_H__A7885671_BEB3_4550_8793_31AF22BB8CF8__INCLUDED_)
#define AFX_UG3DLINESET_H__A7885671_BEB3_4550_8793_31AF22BB8CF8__INCLUDED_

#include "base/ugdefs.h"
#include "Scene/UGRenderable.h"
#include "Algorithm/UGPoint2D.h"
#include "Engine/UGDataset.h"
#include "Scene/UG3DLine.h"
#include "Scene/UGQuadDataset.h"
#include "Scene/UG3DStyle.h"

//! \brief ��ļ�Ҫ˵����
//! \remarks ��ע��Ϣ��
namespace UGC
{
class SCENE_API UG3DLineSet: public UGQuadDataset
{
public:
	//! \brief ���캯��
	UG3DLineSet();
	//! \brief ��������
	virtual ~UG3DLineSet();
	//! \brief �ͷ�
	virtual void Release();
	//! \brief ��ʼ��
	virtual void Initialize();
	//! \brief ����
	virtual void Update();
	//! \brief
	virtual void Render();
	//! \brief ��ӵ����߶���
	void AddLine(UG3DLine* pLine);
	//! \brief �õ��߶���ķ��
	UG3DLineStyle& GetLineStyle();
	//! \brief �����߶���ķ��
	void SetLineStyle(const UG3DLineStyle& lineStyle);
	//! \brief 
	virtual void AddDataFromDataset(const UGVectorDatasetAtr& DatasetAtr);
	virtual UGbool InterSectWithRadial(const UGVector3R& nearPos, const UGVector3R& farPos);
	virtual void SetPickStatus(UGbool status);
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);

	UG3DLine *Get3DLine();	
	//! \brief �Ƴ������Ӷ���
	void RemoveAllSubLines();
protected:
	//! \brief ��ʸ�����ݼ�������߶���
	void AddDatasetLines(const UGVectorDatasetAtr& DatasetAtr);
	
	//! \brief �Ӷ���
	UGList<UG3DLine*> m_SubLines;
	//! \brief �߶�����
	UG3DLineStyle m_LineStyle;
	// added by luofx
	UGVectorDatasetAtr m_DatasetAtr;
	//! \brief 
	UGbool m_bNeedTestVisible;


};
}


#endif // !defined(AFX_UG3DLINESET_H__A7885671_BEB3_4550_8793_31AF22BB8CF8__INCLUDED_)
