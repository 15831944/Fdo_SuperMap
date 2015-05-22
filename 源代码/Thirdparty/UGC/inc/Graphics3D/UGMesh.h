// UGMesh.h: interface for the UGMesh class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGMESH_H)
#define UGMESH_H

#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGGeometry3D.h"
#include "UGVector3.h"
#include "UGVector2.h"

namespace UGC{	
class GRAPHICS3D_API UGMesh:public UGGeometry3D
{
public:
	enum Mode
	{
		TRIANGLES,// = GL_TRIANGLES,
		TRIANGLE_STRIP,// = GL_TRIANGLE_STRIP,
		TRIANGLE_FAN,// = GL_TRIANGLE_FAN,
	};
public:
	UGMesh();
	virtual ~UGMesh();
	
protected:
	//!\brief �Ӷ������
	UGuint m_nSubCount;
	//!\brief �Ӷ����Modeֵ
	Mode* m_pModes;
	//ÿ���ֶ����Ӧ������
	Real** m_pIndices;
	//!\brief ��ĸ���
	UGuint m_nNumVertices;
	//!\brief ������������
	Real* m_pVertices;	
	//! \brief ����
	UGbool m_bHasNormal;
	//! \brief ��������
	Real*   m_pNormals;	
	//! \brief ��ɫ
	UGbool  m_bHasColor;	
	//! \brief ��ɫ����
	UGint * m_pColors;
	//! \brief ��������ĸ���
	UGushort m_nNumTexCoords;	
	//! \brief ÿ�������ά��
	UGushort m_nTexCoordDim[UGC_MAX_TEXTURE_COORD_SETS];	
	//! \brief ��������
	Real*    m_pTexCoords[UGC_MAX_TEXTURE_COORD_SETS];
	//!\brief stride
//	UGushort  m_nVertexStride;
//	UGushort m_nNormalStride;
//	UGushort  m_nTexCoordStride[UGC_MAX_TEXTURE_COORD_SETS];
//	UGushort  m_nColorStride;
	
};

}

#endif // !defined(UGMESH_H)
