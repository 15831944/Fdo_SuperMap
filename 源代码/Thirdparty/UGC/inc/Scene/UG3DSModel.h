// UG3DSModel.h: interface for the UG3DSModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG3DSMODEL_H__C2B90449_7153_444F_B4A1_3229B6A8332D__INCLUDED_)
#define AFX_UG3DSMODEL_H__C2B90449_7153_444F_B4A1_3229B6A8332D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGModel.h"

namespace UGC
{
	//�з���
	typedef UGuchar Byte;
	typedef UGushort Word;
	typedef UGuint DWord;
class SCENE_API UG3DSModel:public UGModel  
{
public:
	UG3DSModel();
	UG3DSModel(const UGString& strModelPath );
	virtual ~UG3DSModel();
	
protected:
	virtual UGbool ReadModel(const UGString& filename);
	virtual void GenRenderOperation();
	//virtual void Unitize();

private:
 void BeforeLoading();
 void AfterLoading();

	/*--��Mesh����������Ϣ�йص����ݴ洢����-----------*/
 void UseObject();
 void  UseObjectName(const UGString& name);	      //0x4000
 void  UseTriMesh();                              //0x4100
 UGReal* UseMeshVertex(UGint nCount);             //0x4110
 void* UseMeshFace(UGint nCount);                 //0x4120
 void  UseMeshMaterialName(const UGString& name); //0x4130
 void* UseMeshTexCoord(UGint nCount);              //0x4140
 void UseMeshLocalO(UGfloat x,UGfloat y,UGfloat z){}
 void UseMeshLocalN(UGfloat x,UGfloat y,UGfloat z){}
 void UseMeshLocalV(UGfloat x,UGfloat y,UGfloat z){}
 void UseMeshLocalU(UGfloat x,UGfloat y,UGfloat z){}

	/*--��Material����������Ϣ�йص����ݴ洢����--------*/
 void UseMaterial();
 void UseMaterialName(const UGString& name);
 void UseMaterialMapFileName(const UGString& name);  
 void UseMaterialAmbient(Byte red,Byte green,Byte blue);
 void UseMaterialDiffuse(Byte red,Byte green,Byte blue);
 void UseMaterialSpecular(Byte red,Byte green,Byte blue);
 void UseMaterialShininess(Word shin);
 void UseMaterialTransparency(Word trans);
 void UseMeshMaterialFacet(Word num,Word* pFaceIndex,const UGString& matName);

protected:	
		struct UG3dsString
		{
			UGchar string[256];
		};
		
		class SCENE_API UG3dsFile
		{//�����ļ����ֽ����Ķ�ȡ
		public:
			UG3dsFile():m_pFile(0){}
			~UG3dsFile(){ Close();}
			
			UGbool Open(const UGString& fileName);
			void Close();
			UGbool CheckFileFormat();
			void Seek(UGlong offset, UGint origin);
			size_t Read( void *buffer, size_t size, size_t count)
			{return fread(buffer,size,count,m_pFile);}
			
			Byte  ReadByte();
			UGushort  ReadWord();
			DWord ReadDword();
			UGfloat ReadFloat();
			UGint ReadString(UG3dsString& str);
			
			FILE* m_pFile;
		};
		
		//{{=====3DS Chunk���ʶ=========================		
		enum
		{
			    SM3DS_PRIMARY = 0x4D4D,    //����(Primary Chunk)
				
				//{{���༭��
				SM3DS_EDIT = 0x3D3D,       //���༭��(Edit Chunk)
				
				SM3DS_EDIT_OBJECT = 0x4000,//������Ϣ��
				
				SM3DS_TRIMESH_INFO = 0x4100,//����������Ϣ
				
				SM3DS_MESH_VERTEX = 0x4110, //�����б�
				SM3DS_MESH_FACE   = 0x4120, //�������б�
				SM3DS_FACE_MAT    = 0x4130,
				SM3DS_FACE_SMOOTH = 0x4150,
				SM3DS_MESH_TEXCOORD = 0x4140, //��������
				SM3DS_MESH_LOCAL    = 0x4160, //ת������
				
				
				
				SM3DS_EDIT_MAT =0xAFFF,
				
				SM3DS_MAT_NAME =0xA000,    //��������
				SM3DS_MAT_AMBIENT        = 0xA010, //���ʵĻ�����ɫ
				SM3DS_MAT_DIFFUSE        = 0xA020, //���ʵ�ɢ����ɫ
				SM3DS_MAT_SPECULAR       = 0xA030, //���ʵľ��淴����ɫ
				SM3DS_MAT_SHININESS      = 0xA040, //���ʵľ��淴�����
				SMEDS_MAT_TRANSPARENT    = 0xA050, //���ʵ�͸����
				SM3DS_MAT_TEXTURE        = 0xA200,
				SM3DS_MAT_TEXTUREMAPFILE = 0xA300,   //������ͼ���ļ�����
				
				//}}���༭��
				
				//{{�ؼ�֡�� KeyFrame Chunk
				SM3DS_PRIM_KEY =0xB000,
				SM3DS_KEY_INFO =0xB008,
				SM3DS_KEY_MESH =0xB002,
				SM3DS_KEYF_HIERARCY =0xB010,
				SM3DS_KEYF_DUMMY    =0xB011,
				SM3DS_KEYF_PIVOT    =0xB013,
				SM3DS_TRACK_POS     =0xB020,
				SM3DS_TRACK_ROT     =0xB021,
				SM3DS_TRACK_SCL     =0xB022,
				SM3DS_KEYF_NODEID   =0xB030,
				//}}�ؼ�֡Chunk
				
				//some chunks in all others
				SM3DS_RGB_FLOAT        = 0x0010,
				SM3DS_RGB_BYTE         = 0x0011,
				SM3DS_RGB_BYTE_GAMMA   = 0x0012,
				SM3DS_RGB_FLOAT_GAMMA  = 0x0013,
				SM3DS_PERCENTAGE_WORD  = 0x0030,  //0~100����ֵ
				SM3DS_PERCENTAGE_FLOAT = 0x0031
				
		};
		//}}=====3DS Chunk���ʶ===================
		
		/*----------------------------------------------------------------------
		chunk��3ds�ļ��Ļ������ɵ�λ��ÿһ��chunk����һ��ͷ��һ�����塣
		chunk��ͷ������������ɣ�
		1��ID of Chunk(��ı�ʶ��ID��ʾchunk�ĺ��壬��һ����)
		2��Length of Chunk(��ĳ��ȡ����ֽ�Ϊ��λ������ͷ�����塻����һ��˫��)
		-----------------------------------------------------------------------*/
		typedef struct CHUNK_3DS_HEADER 
		{
			UGushort ID;
			UGuint Length;
		}UG3dsChunk;
		
		
		void ReadByteRGB(Byte &red,Byte &green,Byte &blue);
		void ReadFloatRGB(UGfloat &red,UGfloat &green,UGfloat &blue);
		void ReadBytePercentage(Byte &per);
		void ReadFloatPercentage(UGfloat &per);
		
		void ReadChunkHeader(UG3dsChunk& chunk);
		
		void ProcessPrimaryChunk();
		void ProcessEditChunk(DWord length);
		void ProcessKeyFrameChunk(DWord length);
		
		void ProcessObjectChunk(DWord length);
		void ProcessMaterialChunk(DWord length);
		
		void ProcessTriMeshChunk(DWord length);
		
		//{{��ȡ��������
		void ReadMeshVertexs();
		void ReadMeshTexCoords();
		void ReadMeshFaces(DWord length);
		void ReadMeshLocal();
		//}}
		
		void ProcessMatTextureChunk(DWord length);  //����
		void ReadAmbientColor(DWord length);
		void ReadDiffuseColor(DWord length);
		void ReadSpecularColor(DWord length);
		void ReadShininess(DWord length);
		void ReadTransparency(DWord length);
		
protected:
	UG3dsFile m_3dsFile;
	UGString m_TmpMeshName;

	};
	//{{========C3ds==========================================
inline void UG3DSModel::ReadChunkHeader(UG3dsChunk& chunk)
{
	chunk.ID = m_3dsFile.ReadWord();
	chunk.Length = m_3dsFile.ReadDword();
}
//}}========C3ds==========================================

}



#endif // !defined(AFX_UG3DSMODEL_H__C2B90449_7153_444F_B4A1_3229B6A8332D__INCLUDED_)
