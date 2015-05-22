/* 
	\file UGMesh.h
	\brief ��ṹ�����������ࡣ
	\author malq zhangyl
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/


#if !defined(AFX_UGMESH_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_)
#define AFX_UGMESH_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_

#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderOperation.h"

namespace UGC
{

//! \brief ��ṹ�塣
struct Face
{
	//! \brief ƽ�淽��ϵ����
	UGushort a,b,c;
	
	//! \brief ������
	UGshort m_MatIndex;

	//! \brief ���캯����
	Face()	
	{
		a = 0;
		b = 0;
		c = 0;
		m_MatIndex = -1;
	}
};

//! \brief �������
class SCENE_API UGMesh
{

public:

	//! \brief ���캯����
	UGMesh();	
	
	//! \brief ���������캯����
	//! \param strName ����[in]��
	UGMesh(const UGString& strName);
	
	//! \brief ����������
	virtual ~UGMesh();	

	//! \brief �ͷ���Դ��
	void Release();	
	
	//! \brief ��������
	//! \param pTexture �������[in]��
	void SetTexture(UGTexture* pTexture);	
	
	//! \brief ��������
	//! \param strImgPath ����ͼƬ·��[in]��
	void SetTexture(const UGString& strImgPath);	
	
	//! \brief ����ǰ�档
	//! \param enFrontFace ǰ�淽ʽ����[in]��
	void SetFrontFace(UGint enFrontFace);	
	
	//! \brief ��������ģʽ��
	//! \param normalMode ģʽ����[in]��
	void SetNormalMode(UGint normalMode);	
	
	//! \brief ��Ⱦ����
	//! \param &drawArgs ����[in]��
	void Render();	
	
	//! \brief ��ʼ���������
	//! \param &drawArgs ����[in]��
	void Initialize();	
	
	//! \brief �����������
	//! \param strName ����[in]��
	//! \return �������ָ�롣
	UGMesh* FindMesh(const UGString& strName);	
	
	// ע������������ı��������������һ��Ҫ�ı����
	
	//! \brief �����������ݡ�
	//! \param numVertice ������Ŀ[in]��
	//! \param numNormal ������Ŀ[in]��
	//! \param numFace ����Ŀ[in]��
	//! \param numTextCoord ����������Ŀ[in]��
	void SetupGeometryData(UGint numVertice,UGint numNormal,UGint numFace,UGint numTextCoord );	

	//! \brief ��ȡ���������
	//! \param index ������[in]��
	//! \return �������ָ�롣
	UGMesh* GetSubMeshAt(UGint index);	
	
	//! \brief ����������
	//! \param strName ����[in]��
	//! \return �������ָ�롣
	UGMesh* AddMesh(const UGString& strName);	
	
	//! \brief ��ȡ�����񼯺ϡ�
	//! \return �������б�
	UGList<UGMesh*>* GetSubList();	
	
	//! \brief ����������
	//! \param fScale ����ϵ��[in]��
	void Scale(UGfloat fScale);	
	
	//! \brief ��������ֵ��
	//! \param vecCenter ����λ��[in]��
	//! \param fScale ����ϵ��[in]��
	void Unitize(const UGVector3R& vecCenter,UGReal fScale);	
	
	//! \brief ���㶥��������
	void ComputerVertexNormals();	

public:

	//! \brief ��Ⱦ����
	UGRenderOperation m_RenderOperation;
	//! \brief ���ơ�
	UGString m_strName;
	//! \brief ����ID��
	UGint  m_nMaterialID;

	// �⼸�����ǰ������� RenderOperation��
	//! \brief ��������������ָ�롣
	UGuint* m_pIndexTriangles;

	//! \brief ��������׵�ַ��
	Face   *m_pFaces;        // �����涥������(a,b,c)
	
	//! \brief ��������Ŀ��
	UGuint m_nNumTriangles;
	
	//! \brief ����Ƿ��������ݡ�
	UGbool m_bShareVertexData;
	
	//! \brief ���ʶ������顣
	UGArray<UGMaterial*> m_arryMaterial;


private:

	//! \brief ����������б�
	UGList<UGMesh*>m_listSubMesh;
};

}

#endif // !defined(AFX_UGMESH_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_)
