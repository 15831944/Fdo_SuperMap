/* 
	\file UGRenderOperation.h
	\brief  ��װ��������Ⱦ�����ݰ����ļ�
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/


#if !defined(AFX_UGRENDEROPERATION_H__9A764B82_16B9_4D13_96D8_9A2E2A80CD9B__INCLUDED_)
#define AFX_UGRENDEROPERATION_H__9A764B82_16B9_4D13_96D8_9A2E2A80CD9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Base/UGFileStream.h"
#include "Scene/UGVertexData.h"

namespace UGC 
{
// �ṹ����Բ���Ҫ������,Ϊ��ͳһ�һ���д������
//! \brief ��װ�ľ���������ʵĵ���
class SCENE_API TextureVertex 
{
public:
	TextureVertex(){x=0;y=0;z=0;u=0;v=0;}
	virtual ~TextureVertex(){}
	UGReal x;
	UGReal y;
	UGReal z;
	UGReal u;
	UGReal v;
};
//! \brief ��װ��������Ⱦ�����ݰ���
class SCENE_API UGRenderOperation  
{
public:
	//! \brief ���ݻ��Ƶķ�ʽ
	enum OpType
	{
		/// A list of points, 1 vertex per point
		OT_POINT_LIST = 1,
		/// A list of lines, 2 vertices per line
		OT_LINE_LIST = 2,
		/// A strip of connected lines, 1 vertex per line plus 1 start vertex
		OT_LINE_STRIP = 3,
		/// A list of triangles, 3 vertices per triangle
		OT_TRIANGLE_LIST = 4,
		/// A strip of triangles, 3 vertices for the first triangle, and 1 per triangle after that 
		OT_TRIANGLE_STRIP = 5,
		/// A fan of triangles, 3 vertices for the first triangle, and 1 per triangle after that
		OT_TRIANGLE_FAN = 6
	};
	//! \brief ���ݻ��Ƶ�����
	enum VertexOptions
	{
		VO_NORMALS = 1,   //GL_NORMAL_ARRAY + glNormalPointer()
		VO_TEXTURE_COORDS =2, //GL_TEXTURE_COORD_ARRAY + glTexCoordPointer()
		VO_DIFFUSE_COLOURS = 4, //GL_COLOR_ARRAY + glColorPointer()
		VO_SPECULAR_COLOURS = 8, //Secondary Color
		VO_BLEND_WEIGHTS = 16,
		VO_USE_SINGLE_COLOR = 32, //use only one kind of color
		VO_USE_POINT_SMOOTHING = 64,     // �����㷴����
		VO_MATERIAL=128 //ʹ�ò���
	};
	//! \brief ���캯��
	UGRenderOperation();
	//! \brief ���캯��
	UGRenderOperation(UGbool bUseIndex,UGint enOperationType,UGint eVertexOptions,UGint nTextureDimensions,UGint nNormalMode=SNM_NONE);
	//! \brief ��������
	virtual ~UGRenderOperation();
	//! \brief ���ö�������
	void SetTexVertexValue(UGuint index,UGReal x, UGReal y, UGReal z, UGReal u, UGReal v);
	//! \brief ���ö�������
	void SetTexVertexValue(UGuint index,const TextureVertex& value);
	//! \brief ������������
	void SetIndexNum(UGuint nCount);
	//! \brief ������������Ŀ 
	void SetTexVertexNum(UGuint nCount);
	//! \brief ��������ֵ
	void SetIndexValue(UGuint i, UGushort value);
	//! \brief ���ļ��м������ݰ�
	// ���ӹ��ɰ�Χ�д���
	void Load(UGFileStream& fStream,const UGString& strFilepath, UGBoundingBox& BoundingBox);
	//! \brief �����ݰ���Ϊ�ļ�
	void Save(UGFileStream& fStream);
	//! \brief �ͷ����ݰ�
	void Release();
	//! \brief ���Ʒ�ʽ��Ա
	UGint m_enOperationType;
	//! \brief �������Գ�Ա
	UGint m_nVertexOptions;
	//! \brief ����ģʽ��Ա
	UGint m_enNormalMode;
	//! \brief ���淽���Ա
	UGint m_enFrontFace;
	//! \brief PolygonMode
	UGint m_enPolygonMode;


	//! \brief ��������
	UGReal* m_pNormals;
	//! \brief ������Ŀ
	UGint m_nNormalCount;
	//! \brief ��������ƫ�� 
	UGushort m_nNormalStride; 
	//! \brief ������Ŀ
	UGuint m_nVerticesCount;
	//! \brief ��������
	UGReal *m_pVertices;
	//! \brief ��������ƫ��
	UGushort m_nVertexStride;
	//! \brief �Ƿ�ʹ����������
	UGbool m_bUseIndex;
	//! \brief ������Ŀ
	UGuint m_nIndexesCount;
	//! \brief ��������
	UGushort *m_pIndexes;	
	//! \brief ��ɫ����
    UGulong *m_pDiffuseColor;
	//! \brief ��ɫ����ƫ��
	UGushort m_nDiffuseStride;
	//! \brief ���ʱ��� 
	UGMaterial* m_pMaterial;

	 //! \brief ��ͼ�������� ���֧��6��
	UGReal*	m_pTexCoords[SMSCN_MAX_TEXTURE_COORD_SETS];
	//! \brief ��ͼ�������� ���֧��6��
	UGTexture* m_pTextures[SMSCN_MAX_TEXTURE_COORD_SETS];
	//! \brief ÿ����ͼ�����Stride
	UGushort  m_TexCoordStride[SMSCN_MAX_TEXTURE_COORD_SETS];
	//! \brief ��ͼ���������
	UGint           m_nTexCoordSets;
	//! \brief ��ͼ������Ŀ
	UGint           m_TexCoordCount[SMSCN_MAX_TEXTURE_COORD_SETS];
	//! \brief ��ͼ�����ά��
	UGint			m_TexDimensions[SMSCN_MAX_TEXTURE_COORD_SETS];
	//! \brief �Ƿ�ʹ���ⲿ����
	UGbool m_bExternIndexData;
	
	// ����������Ŀǰû������
	UGVertexData *vertexData;

private:


};
}
#endif // !defined(AFX_UGRENDEROPERATION_H__9A764B82_16B9_4D13_96D8_9A2E2A80CD9B__INCLUDED_)
