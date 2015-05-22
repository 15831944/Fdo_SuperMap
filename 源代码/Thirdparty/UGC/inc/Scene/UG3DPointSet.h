/* 
	\file UG3DPointSet.h
	\brief ��άʸ���㼯�ࡣ
	\author ������
	\attention �㼯��װ�����ڲ���ķ�񣬵�����û�з�񣬵㼯�з��
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UG3DPOINTSET_H__2D47E261_BD00_4CDA_9BBE_C552F3682332__INCLUDED_)
#define AFX_UG3DPOINTSET_H__2D47E261_BD00_4CDA_9BBE_C552F3682332__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGRenderable.h"
#include "Base/UGThread.h"
#include "Scene/UGColorValue.h"
#include "Base/UGString.h"
#include "Engine/UGDataset.h"
#include "Scene/UGQuadDataset.h"
#include "Scene/UG3DStyle.h"
#include "Scene/UGMovableObject.h"

//! \brief ��ļ�Ҫ˵����
//! \remarks ��ע��Ϣ��
namespace UGC
{

	class SCENE_API UG3DPointSet: public UGQuadDataset
	{
	public:
		//  �㼯�������ֱ���������ݼ���Ҳ���Բ������Լ���ӵ㣬
		//  ���õ㼯���������ӵ����ݼ������ݼ������ļ�
		UG3DPointSet();	
		//! \brief ��������
		virtual ~UG3DPointSet();
 
		//! \brief �̳���RenderableObject�Ĵ��麯��
		//! \param &drawArgs [in]	
		virtual void Initialize();
		//! \brief �̳���RenderableObject�Ĵ��麯��
		//! \param &drawArgs [in]	
		virtual void Update();
		//! \brief �̳���RenderableObject�Ĵ��麯��
		//! \param &drawArgs [in]	
		virtual void Render();
		//! \brief �̳���RenderableObject�Ĵ��麯��
		//! \param &drawArgs [in]	
		virtual void Release();

		//! \brief ���õ�ķ��
		//! \param 
		void SetPointStyle(const UG3DPointStyle& pointStyle);	
		//! \brief �õ���ķ��
		UG3DPointStyle& GetPointStyle();
		// ���һ���㣬ע�⴫��Ĳ����ǿռ�����
		void AddPoint(UGReal x,UGReal y,UGReal z);
		// ���һ��㣬�������ǰ�x,z,z���е�,���Ҷ��ǿռ�����
		void AddPoints(UGReal* pVertex,UGint nCount);
		//ɾ�����е�
		void RemoveAllPoint();
		UGReal *GetVerTex(); 

		virtual void AddDataFromDataset(const UGVectorDatasetAtr& DatasetAtr);

		virtual UGbool InterSectWithRadial(const UGVector3R& nearPos, const UGVector3R& farPos);
	protected:
		// �ӹ��������ݼ��м����
		void AddDatSetPoints(const UGVectorDatasetAtr& DatasetAtr);
		void RenderEntityPoint(UGReal x,UGReal y,UGReal z);
	private:
		// malq-ע������洢�Ķ��Ǵ��ֱ������ϵ�����꣬�����Ǿ�γ������
		//UGList<UGPoint3D*> m_PntList;
		//! \brief  
		UGReal* m_pVertex;
		//! \brief
		UGint m_nVertexCount;
		//! \brief
		UG3DPointStyle m_PointStyle;
		//! \brief
		UGMutex m_mutex;
		//! \brief
		UGTexture* m_pTexture;
		//! \brief
		UGVectorDatasetAtr m_DatasetAtr;
		//! \brief
		UGbool m_bNeedTestVisible;

		// ��ʱʹ��
		UGint m_nSelectedPointIndex;
	};
}

#endif // !defined(AFX_UG3DPOINTSET_H__2D47E261_BD00_4CDA_9BBE_C552F3682332__INCLUDED_)
