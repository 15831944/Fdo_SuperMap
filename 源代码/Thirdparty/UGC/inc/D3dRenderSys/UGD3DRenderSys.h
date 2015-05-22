/* 
	\file UGD3DRenderSys.h
	\brief D3D��Ⱦ�������ļ���
	\author ������ luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGD3DRENDERSYS_H__6736EEA2_1529_43BA_87AF_CE7A52A398E3__INCLUDED_)
#define AFX_UGD3DRENDERSYS_H__6736EEA2_1529_43BA_87AF_CE7A52A398E3__INCLUDED_

#include "Scene/UGRenderSys.h"
#include "D3dRenderSys/UGD3D9Mappings.h"
#include "Algorithm/UGRect2D.h"

namespace UGC
{

class UGD3D9DriverList;
class UGD3D9Driver;



//! \brief D3D��Ⱦ������
class D3DRENDERSYS_API UGD3DRenderSys : public UGRenderSys
{

public:

	//! \brief ���캯����
	UGD3DRenderSys();	
	//! \brief ����������
	virtual ~UGD3DRenderSys();		
	//! \brief ��ȡ�������ơ�
	//! \return �������ơ�
	//! \remarks ��������Ψһ��
	const UGString& GetName(void) const;
	//! \brief ��ȡ����������
	//! \param errorNumber �����[in]��
	//! \return ����������
	virtual UGString GetErrorDescription(UGint errorNumber) const;	
	//! \brief ��ȡ���ò�����
	//! \return ���ò�����
	UGConfigOptionMap& GetConfigOptions(void);		
	//! \brief �������ò�����
	//! \param &name ���ò�������[in]��
	//! \param &value ���ò�����ֵ[in]��
	void SetConfigOption(const UGString &name, UGString &value);		
	//! \brief �������ò�����
	//! \return ���ò����ַ�����
	UGString ValidateConfigOptions(void);	
	

    
	//! \brief ��ʼ����ʾ���档
	//! \param hWnd �������ھ��[in]��
	//! \return ��Ⱦ���ڡ�
	virtual UGRenderWindow *Initialize(Window hWnd);	
	//! \brief ���³�ʼ����
	virtual void ReInitialize();	
	//! \brief �����������
	virtual void ShutDown(void);
	//! \brief ��Ⱦ����
	//! \param &ro ����Ⱦ����[in]��
	virtual void Render(UGRenderOperation &ro);	
	//! \brief ����ʼ��
	virtual void BeginFrame();	
	//! \brief ֡������
	virtual void EndFrame();		
	//! \brief �������ڶ���
	//! \param hWnd �ⲿ���ھ��[in]��
	//! \return ���ڶ���
	virtual UGRenderWindow *CreateRenderWindow(Window hWnd, NameValuePairList *miscParams = 0);	

	

	//! \brief ���û����⡣
	//! \param r �����[in]��
	//! \param g �̷���[in]��
	//! \param b ������[in]��
	virtual void SetAmbientLight(UGfloat r, UGfloat g, UGfloat b);	
	//! \brief ������Ⱦģʽ��
	//! \param so ��Ⱦģʽ[in]��
	virtual void SetShadingType(ShadeOptions so);	
	//! \brief ���ù�Դ״̬��
	//! \param enabled trueΪ����,falseΪ�ر�[in]��
	virtual void SetLightingEnabled(UGbool enabled);	
	//! \brief ʹ�ù�Դ��
	//! \param lights ��Դ����[in]��
	//! \param limit ��Դ����[in]��
	virtual void UseLights(const UGLightList& lights, UGuint limit);	
	//! \brief ���ù�Դ״̬��
	//! \param nLightID ��ԴID[in]��
	//! \param bEnabled true����,falseΪ�ر�[in]��
	// modified by luofx 07.12.5
//	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled);	
	//! \brief ��ȡ��Դ״̬��
	//! \param nLightID ��ԴID[in]��
	// modified by luofx 07.12.5
//	virtual UGbool GetLightEnabled(UGint nLightID);	
	//! \brief ���ù�Դλ�á�
	//! \param nLightID ��ԴID[in]��
	//! \param x λ��x����[in]��
	//! \param y λ��y����[in]��
	//! \param z λ��z����[in]��
	//! \param w λ��w����[in]��
	// modified by luofx 07.12.5
//	virtual void SetLightPos(UGint nLightID,UGfloat x,UGfloat y,UGfloat z,UGfloat w);
	


	//! \brief ������Ȼ����Ƿ�������
	//! \param bEnable ȱʡΪtrue,trueΪ����,falseΪ�ر�[in]��
//	virtual void SetDepthBufferEnabled(UGbool bEnabled = TRUE);	
	//! \brief ������Ȼ��������
	//! \param depthTest ȱʡΪtrue trueΪ������Ȳ���,falseΪ�ر���Ȳ���[in]��
	//! \param depthWrite ȱʡΪtrue true��д,falseΪ����д[in]��
	//! \param depthFunction  ȱʡΪCMPF_LESS_EQUAL, �ȽϺ���[in]��
	virtual void SetDepthBufferParams(UGbool depthTest = true, UGbool depthWrite = true, 
						CompareFunction depthFunction = CMPF_LESS_EQUAL);
	//! \brief ������Ȼ���״̬��
	//! \param enabled ȱʡΪtrue,trueΪ����,falseΪ�ر� [in]��
	virtual void SetDepthBufferCheckEnabled(UGbool enabled = true);	
	//! \brief ���û����Ƿ��д��
	//! \param enabled ȱʡΪtrue, trueΪ��д,falseΪ����д [in]��
	virtual void SetDepthBufferWriteEnabled(UGbool enabled = true);	
	//! \brief ������Ȼ���ȽϺ�����
	//! \param func ȱʡΪCMPF_LESS_EQUAL,�ȽϺ��� [in]��
	virtual void SetDepthBufferFunction(CompareFunction func = CMPF_LESS_EQUAL);	
	//! \brief ���ÿ�д��ɫ���档
	//! \param red ��ɫ����[in]��
	//! \param green ��ɫ����[in]��
	//! \param blue ��ɫ[in]��
	//! \param alpha alpha����[in]��
	virtual void SetColourBufferWriteEnabled(UGbool red, UGbool green, UGbool blue, UGbool alpha);	
	//! \brief �������ƫ�
	//! \param bias ƫ��ֵ[in]��
	virtual void SetDepthBias(UGushort bias);	
	//! \brief ����ģ�滺��״̬��
	//! \param enabled trueΪ����ģ�滺��, falseΪ�ر�ģ�滺��[in]��
	virtual void SetStencilCheckEnabled(UGbool enabled);	
	//! \brief ����ģ�滺�������
	//! \param CMPF_ALWAYS_PASS �ȽϺ���[in]��
	//! \param refValue ȱʡΪ0 ģ��ο�ֵ[in]��
	//! \param mask 0xFFFFFFFF ����ֵ[in]��
	//! \param stencilFailOp ȱʡΪSOP_KEEP ģ�����ʧ�ܺ���[in]��
	//! \param depthFailOp ȱʡΪSOP_KEEP ��Ȳ���ʧ�ܺ���[in]��
	//! \param passOp ȱʡΪSOP_KEEP ͨ������[in]��
	//! \param twoSidedOperation ȱʡΪfalse,trueΪ���߶�����,false�෴[in]��
	virtual void SetStencilBufferParams(CompareFunction func = CMPF_ALWAYS_PASS, 
        UGuint refValue = 0, UGuint mask = 0xFFFFFFFF, 
        StencilOperation stencilFailOp = SOP_KEEP, 
        StencilOperation depthFailOp = SOP_KEEP,
        StencilOperation passOp = SOP_KEEP, 
        UGbool twoSidedOperation = false);
	//! \brief ����֡���档
	//! \param buffers ״̬��־[in]��
	//! \param colour ȱʡΪUGColorValue::Black ������ɫ[in]��
	//! \param depth ȱʡΪ1.0f ��Ȼ���ֵ[in]��
	//! \param stencil ȱʡΪ0 ģ��ֵ[in]��
	virtual void ClearFrameBuffer(UGuint buffers, 
		const UGColorValue& colour = UGColorValue::Black, 
		UGReal depth = 1.0f, UGushort stencil = 0);
	


	//! \brief �����������
	//! \param &m �������[in]��
	virtual void SetWorldMatrix(const UGMatrix4d &m);	
	//! \brief ������ͼ����
	//! \param &m ��ͼ����[in]��
	virtual void SetViewMatrix(const UGMatrix4d &m);	
	//! \brief ����ͶӰ����
	//! \param &m ͶӰ����[in]��
	virtual void SetProjectionMatrix(const UGMatrix4d &m);	
	//! \brief ת������
	//! \param matrix Դ����[in]��
	//! \param dest Ŀ�����[out]��
	//! \param forGpuProgram ȱʡΪfalse [in]��
	//! \remarks ��������ϵת������������ϵ��
	virtual void ConvertProjectionMatrix(const UGMatrix4d& matrix,
			UGMatrix4d& dest, UGbool forGpuProgram = false);
	//! \brief ����ͶӰ����
	//! \param fovy �Ƕ�[in]��
	//! \param aspect ��߱�[in]��
	//! \param nearPlane ��ƽ��zֵ[in]��
	//! \param farPlane Զƽ��zֵ[in]��
	//! \param dest ���ɾ���[out]��
	//! \param forGpuProgram ȱʡΪfalse [in]��
	virtual void MakeProjectionMatrix(const UGAngle& fovy, UGReal aspect, UGReal nearPlane, 
		UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false);	
	//! \brief ����ͶӰ����
	//! \param left ��x����ֵ[in]��
	//! \param right ��x����ֵ[in]��
	//! \param bottom ��y����ֵ[in]��
	//! \param top ��y����ֵ[in]��
	//! \param nearPlane ��ƽ��zֵ[in]��
	//! \param farPlane Զƽ��zֵ[in]��
	//! \param dest ���ɾ���[out]��
	//! \param forGpuProgram ȱʡΪfalse[in]��
	virtual void MakeProjectionMatrix(UGReal left, UGReal right, UGReal bottom, UGReal top, 
            UGReal nearPlane, UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false);	
	//! \brief ����ƽ��ͶӰ����
	//! \param fovy �Ƕ�[in]��
	//! \param aspect ��߱�[in]��
	//! \param nearPlane ��ƽ��zֵ[in]��
	//! \param farPlane Զƽ��Zֵ[in]��
	//! \param dest ���ɾ���[out]��
	//! \param forGpuProgram ȱʡΪfalse[in]��
	virtual void MakeOrthoMatrix(const UGAngle& fovy, UGReal aspect, UGReal nearPlane, 
		UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false);	
	//! \brief ������б��Ⱦ���
	//! \param matrix ���ɾ���[out]��
	//! \param plane ƽ��[in]��
	//! \param forGpuProgram [in]��
	virtual void ApplyObliqueDepthProjection(UGMatrix4d& matrix, const UGPlane& plane, 
            UGbool forGpuProgram);	
	//! \brief ����ͶӰ����
	//! \param fovy �Ƕ�[in]��
	//! \param aspect ��߱�[in]��
	//! \param nearPlane ��ƽ��zֵ[in]��
	//! \param farPlane Զƽ��[in]��
	//! \return ͶӰ����
	// modified by luofx 07.12.5
//	virtual UGMatrix4d SetProjectionMatrix(UGReal fovy, UGReal aspect, UGReal nearPlane, 
//		                                   UGReal farPlane);	
	//! \brief ������ͼ����
	//! \param cameraPosition ���λ��[in]��
	//! \param cameraTarget �������[in]��
	//! \param cameraUpVector ������Ϸ���[in]��
	//! \param Tilt [in]��
	//! \param Bank [in]��
	//! \param Heading ����[in]��
	//! \param dDistance ����[in]��
	//! \return ��ͼ����
	// modified by luofx 07.12.5
//	virtual UGMatrix4d SetViewMatrix(UGVector3R cameraPosition, 
//		UGVector3R cameraTarget, 
//		UGVector3R cameraUpVector, 
//		UGAngle Tilt, UGAngle Bank, UGAngle Heading, UGReal dDistance);	
	//! \brief ��������ͶӰ����Ļ���ꡣ
	//! \param &v ��������[in]��
	//! \param &win ��Ļ����[out]��
	virtual void Project(const UGVector3R &v, UGVector3R &win);		
	//! \brief ��Ļ����ת�����������ꡣ
	//! \param &win ��Ļ����[in]��
	//! \param &v ��������[out]��
	virtual void UnProject(const UGVector3R &win,UGVector3R &v);	
	//! \brief �����ӿڡ�
	//! \param *pViewport �ӿڶ���ָ��[in]��
	virtual void SetViewport(UGViewport *pViewport);	

	
	//! \brief ��������
	//! \param unit ����ͨ������[in]��
	//! \param enabled trueΪ����,falseΪȡ��[in]��
	//! \param &texname ��������[in]��
	virtual void SetTexture(UGuint unit, UGbool enabled, const UGString &texname);	
	//! \brief ������������ϵ��
	//! \param unit ����Ԫ������[in]��
	//! \param index ��������������[in]��
	virtual void SetTextureCoordSet(UGuint unit, UGuint index);	
	//! \brief ������������ֵ��
	//! \param unit ����Ԫ[in]��
	//! \param m ������������ֵ����[in]��
	//! \param frustum ��׶�壬����������[in]��
	virtual void SetTextureCoordCalculation(UGuint unit, TexCoordCalcMethod m, 
            const UGFrustum* frustum = 0);	
	//! \brief ����������ģʽ��
	//! \param unit ����Ԫ������[in]��
	//! \param bm ��ɫ�����[in]��
	virtual void SetTextureBlendMode(UGuint unit, const UGLayerBlendModeEx& bm);		
	//! \brief ��������λ�Ĺ����
	//! \param unit ����Ԫ������[in]��
	//! \param ftype ������[in]��
	//! \param filter �˲�����[in]��
	virtual void SetTextureUnitFiltering(UGuint unit, FilterType ftype, FilterOptions filter);	
	//! \brief ��������Ԫ��������ֵ��
	//! \param unit ����Ԫ������[in]��
	//! \param maxAnisotropy ��������ֵ[in]��
	virtual void SetTextureLayerAnisotropy(UGuint unit, UGuint maxAnisotropy);	
	//! \brief ��������Ԫ�����ַ����ģʽ��
	//! \param unit ����Ԫ������[in]��
	//! \param uvw UVW�����ַ����[in]��
	virtual void SetTextureAddressingMode(UGuint unit, const UGTextureUnitState::UVWAddressingMode& uvw);	
	//! \brief ��������Ԫ�߿���ɫ��
	//! \param unit ����Ԫ������[in]��
	//! \param colour ��ɫֵ[in]��
	virtual void SetTextureBorderColour(UGuint unit, const UGColorValue& colour);	
	//! \brief ��������Ԫ�������
	//! \param unit ����Ԫ������[in]��
	//! \param xform ����Ԫ����[in]��
	virtual void SetTextureMatrix(UGuint unit, const UGMatrix4d& xform);	
	//! \brief ���ð�������ϡ�
	//! \param sourceFactor Դ����[in]��
	//! \param destFactor Ŀ������[in]��
	virtual void SetSceneBlending(SceneBlendFactor sourceFactor, SceneBlendFactor destFactor);		
	//! \brief ����Aplpha���ԣ�һ��������͸������
	//! \param func Alpha�ȽϺ���[in]��
	//! \param value Alpha�ο�ֵ[in]��
	virtual void SetAlphaRejectSettings(CompareFunction func, UGuchar value);	
	

	//! \brief ���û�����Ⱦϸ��ģʽ��
	//! \param renderDetail ����ģʽ[in]��
	// modified by luofx 07.12.5
//	virtual void SetRenderDetail(SceneDetailLevel renderDetail);	
	//! \brief �����޳�ģʽ��
	//! \param mode �޳�ģʽ[in]��
	virtual void SetCullingMode(CullingMode mode);	
	//! \brief ���û��ƶ�������͡�
	//! \param level ����ö�ٳ���[in]��
	virtual void SetPolygonMode(PolygonMode level);	
	//! \brief ȷ������ǰ�棬�޳�������档
	//! \param enFrontFace ȷ������ǰ�淽��[in]��
	//! \attention �����������ö�ٳ�����Ҫ��Ȼ�������൱�Ѿ���
	//! \attention ͬʱҪͬһ���������
	virtual void SetPolyFrontFace(UGint  enFrontFace);	
	//! \brief ������
	//! \param mode ������ģʽ[in]��
	//! \param colour ����ɫ[in]��
	//! \param expDensity ��Ũ��[in]��
	//! \param linearStart ��Ч��ʼZֵ[in]��
	//! \param linearEnd ��Ч����Zֵ[in]��
	virtual void SetFog(FogMode mode = FOG_NONE, const UGColorValue& colour = UGColorValue::White, 
		UGReal expDensity = 1.0, UGReal linearStart = 0.0, UGReal linearEnd = 1.0);	
//	//! \brief ������״̬��
//	//! \param bEnable TRUEΪ������FALSEΪ�ر�[in]��
//	virtual void SetFogEnable(UGbool bEnable);	
//	//! \brief ��ȡ��״̬��
//	//! \return TRUEΪ�򿪣�FALSEΪ�رա�
//	virtual UGbool GetFogEnable();	
	//! \brief �����Ƿ���Ⱦ�㾫�顣
	//! \param enabled �����Ⱦ����true����������false[in]��
	virtual void SetPointSpritesEnabled(UGbool enabled);	
	//! \brief ���õ㾫�����Ⱦ������
	//! \param size ���С[in]��
	//! \param attenuationEnabled True��constant,linear,quadratic�������������ߴ硣False����Ч[in]��
	//! \param constant �����ߴ��С���ù�ʽ����[in]��
	//! \param linear �����ߴ��С���ù�ʽһ����ϵ��[in]��
	//! \param quadratic �����ߴ��С���ù�ʽ������ϵ��[in]��
	//! \param minSize ���С��Сֵ[in]��
	//! \param maxSize ���С���ֵ[in]��
	virtual void SetPointParameters(UGReal size, UGbool attenuationEnabled, 
			UGReal constant, UGReal linear, UGReal quadratic, 
			UGReal minSize, UGReal maxSize);	
	
	
	//! \brief ��ȡ����Ԫ�����͡�
	//! \return ����Ԫ�����͡�
	virtual VertexElementType GetColourVertexElementType(void) const;	
	//! \brief ���ö���������
	//! \param decl ��������[in]��
	virtual void SetVertexDeclaration(UGVertexDeclaration* decl);	
	//! \brief ���ð󶨶��㻺�塣
	//! \param binding ���㻺��󶨶���[in]��
	virtual void SetVertexBufferBinding(UGVertexBufferBinding* binding);	

	//! \brief ���Ƶ����㾫�顣
	//! \param x ��xֵ[in]��
	//! \param y ��yֵ[in]��
	//! \param z ��zֵ[in]��
	//! \param bDistChange trueΪ���ü�����С��ʽ��ABC������falseΪʹ��Ĭ��ֵ[in]��
	//! \param pQuadratic ����A,B,Cֵ�׵�ַ[in]��
	virtual void RenderSpritePoint(UGdouble x,UGdouble y,UGdouble z,UGbool bDistChange,UGfloat* pQuadratic);
	
	//! \brief ���ƶ������㾫�顣
	//! \param pVertex ������ֵ�׵�ַ[in]��
	//! \param nVertexCount �������[in]��
	//! \param bDistChange trueΪ���ü�����С��ʽ��ABC������falseΪʹ��Ĭ��ֵ[in]��
	//! \param pQuadratic ����A,B,Cֵ�׵�ַ[in]��
	virtual void RenderSpritePoint(UGReal* pVertex,UGint nVertexCount,UGbool bDistChange,UGfloat* pQuadratic);	
	
	
	//! \brief ���Ƶ�����ͨ�㡣
	//! \param x ��xֵ[in]��
	//! \param y ��yֵ[in]��
	//! \param z ��zֵ[in]��
	//! \param bPointSmooth ȱʡΪFALSE��trueΪ�⻬�㣬falseΪ�ǹ⻬��[in]��
	virtual void RenderSimplePoint(UGdouble x,UGdouble y,UGdouble z,UGbool bPointSmooth=FALSE);	
	
	
	//! \brief ���ƶ����ͨ�㡣
	//! \param pVertex �����׵�ַ[in]��
	//! \param nVertexCount �������[in]��
	//! \param bPointSmooth ȱʡΪFALSE��trueΪ�⻬�㣬falseΪ�ǹ⻬��[in]��
	virtual void RenderSimplePoint(UGReal* pVertex,UGint nVertexCount,UGbool bPointSmooth=FALSE);	
	
	
	//! \brief ���õ�����ɫ��
	//! \param colorValue ��ɫֵ[in]��
	virtual void  SetSingleColor(const UGColorValue& colorValue);	
	
	//! \brief ���õ��С��
	//! \param fSize ��Сֵ[in]��
	virtual void SetPointSize(UGReal fSize);	
	
	//! \brief �����߿�
	//! \param fSize �߿�ֵ[in]��
	virtual void SetLineWidth(UGReal fSize);	

protected:
	
	//! \brief ����D3D������ֵ��
	//! \param state ��������[in]��
	//! \param value ��ֵ[in]��
	HRESULT SetRenderState(D3DRENDERSTATETYPE state, DWORD value);
	
	//! \brief ���ö���������
	//! \param &ro ���Ʋ�������[in]��
	HRESULT SetVertexDeclaration(const UGRenderOperation &ro);	
	
	//! \brief ���û������ݡ�
	//! \param &ro ���ƶ���[in]��
	HRESULT SetBufferData(const UGRenderOperation &ro);	

	//! \brief �������㻺�塣
	HRESULT CreateVertexBuffer();	
	
	//! \brief �����������塣
	HRESULT CreateIndexBuffer();	
	
	//! \brief ���������塣
	HRESULT CreateTextureBuffer();	
	
	//! \brief ��ȡ��������������
	//! \param &ro ���Ʋ�������[in]��
	UGushort GetVertexElementCount(const UGRenderOperation &ro);	

	//! \brief ��䶥��������
	//! \param &ro ���Ʋ�������[in]��
	//! \param *pDwDecl ��������[in]��
	HRESULT FillVertexElement(const UGRenderOperation &ro, 
										  D3DVERTEXELEMENT9 *pDwDecl);	

	//! \brief �ж��Ƿ��ж������ݡ�
	//! \param &ro ���Ʋ�������[in]��
	//! \return trueΪ�ж������ݣ�falseΪû�ж������ݡ�
	UGbool HasVertexData(const UGRenderOperation &ro);	
	
	//! \brief �ж��Ƿ����������ݡ�
	//! \param &ro ���Ʋ�������[in]��
	//! \return trueΪ�������������ݣ�falseΪû�ж������ݡ�
	UGbool HasIndexData(const UGRenderOperation &ro);

	//! \brief �����豸״̬��
	void TestDeviceState();	
	
	//! \brief ��������D3D״̬��
	HRESULT ResetD3D();	
	
	//! \brief ����������
	HRESULT InvalidateBuffer();	

	//! \brief ��ȡD3D�豸�б�
	//! \return D3D�豸���
	UGD3D9DriverList* GetDirect3DDrivers(void);	

	//! \brief ˢ��D3D���á�
	void RefreshD3DSettings(void);	
	
	//! \brief ˢ��FSAA������
	void RefreshFSAAOptions(void);	
	//! \brief �ͷ��豸��
	void FreeDevice(void);	

	//! \brief �����ز���������
	//! \param type ���ز�������[in]��
	//! \param *outQuality ��������[out]��
	//! \param format ��ʽ[in]��
	//! \param adapterNum ����������[in]��
	//! \param deviceType �豸���[in]��
	//! \param fullScreen trueΪȫ����falseΪ��ȫ��[in]��
	UGbool CheckMultiSampleQuality(D3DMULTISAMPLE_TYPE type, 
								   DWORD *outQuality, D3DFORMAT format, UINT adapterNum, 
								   D3DDEVTYPE deviceType, UGbool fullScreen);	

	//! \brief ����FSAA��
	//! \param type ���ز�������[in]��
	//! \param qualityLevel ��������[in]��
	void SetFSAA(D3DMULTISAMPLE_TYPE type, DWORD qualityLevel);	
    
	
	//! \brief ��ʼ�����ò�����
	void InitConfigOptions(void);	
	
	//! \brief �ͷ����ò�����
	void ReleaseConfigOptions();	

	//! \brief ���ù��ա�
	//! \param index ������[in]��
	//! \param lt �����ָ��[in]��
	void SetD3D9Light( size_t index, UGLight* lt );	
	
	//! \brief ����D3D״̬����
	//! \param state ״̬���͡�
	//! \param value ״ֵ̬Ϊ��������
	HRESULT SetFloatRenderState(D3DRENDERSTATETYPE state, UGReal value);	
	
	//! \brief ��������Ѱַ���ԡ�
	//! \param stage ����ͨ��[in]��
	//! \param type Ѱַ����[in]��
	//! \param value ����ֵ[in]��
	HRESULT SetTextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value);	
	
	//! \brief ���������������
	//! \param sampler ����ͨ��[in]��
	//! \param type ����������[in]��
	//! \param value ����ֵ[in]��
	HRESULT SetSamplerState(DWORD sampler, D3DSAMPLERSTATETYPE type, DWORD value);	
	
	//! \brief ��ȡ��ǰ������ֵ��
	//! \param unit ����ͨ������[in]��
	DWORD GetCurrentAnisotropy(size_t unit);	

	//! \brief ��ʼ��D3D��
	void InitD3D();

	//! \brief �����ά���֡�
	//! \param strText �����������[in]��
	//! \param rect λ��[in]��
	//! \param color ��ɫ[in]��
	//! \param DT_LEFT ��ʽ[in]��
	//! \remarks �������ʽ����ID3DFontģʽ��
	void TextOut2DText(UGString strText, UGRect2D rect, D3DCOLOR color, UGuint format = DT_TOP | DT_LEFT);
	

	//! \brief �����ά���֡�
	//! \param strText ��������[in]��
	void TextOut3DText(UGString strText);

	virtual void DrawBoundingBox(const UGBoundingBox& boundingBox){};
	virtual void DrawRadia(const UGVector3R& vecStart, const UGVector3R& vecEnd, const UGVector3R& vecIntersect){};
	
	// ��ʱʹ�ù��պ���
	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled){};
	virtual UGbool GetLightEnabled(UGint nLightID){return false;}
	virtual void MakePickRadial(const UGint x, const UGint y, UGVector3R& nPos, UGVector3R& fPos, UGMatrix4d viewMatrix = UGMatrix4d::ZERO){};
	virtual UGMatrix4d& GetWorldMatrix(){return (UGMatrix4d)UGMatrix4d::ZERO;}
	virtual UGMatrix4d& GetViewMatrix(){return (UGMatrix4d)UGMatrix4d::ZERO;};
	virtual UGMatrix4d& GetProjectionMatrix(){return (UGMatrix4d)UGMatrix4d::ZERO;};
	virtual void RenderSimplePoint(UGReal* pVertex,UGint nVertexCount,UGbool bPointSmooth=FALSE, UGint selectedPointIndex = -1){};

	
private:		
	
	//! \brief �ͷ���������
	void ReleaseAllTexture();	
	
	//! \brief ��ʵ֡Ƶͳ�ơ�
	void ShowFrameStat();	

private:
	
	//! \brief D3D����
	LPDIRECT3D9 m_pD3D;
	
	//! \brief D3D�豸����
	LPDIRECT3DDEVICE9 m_pD3DDevice;		

	//! \brief �豸����
	UGD3D9Driver *m_pActiveD3DDriver;
	
	//! \brief �豸�����б�
	UGD3D9DriverList* m_pDriverList;

	//! \brief ���ò�������
	UGConfigOptionMap m_Options;

	//! \brief ��Ա�ļ�Ҫ˵����
	UGbool m_bUseNVPerfHUD;

	//! \brief ���ز������͡�
	D3DMULTISAMPLE_TYPE m_FSAAType;

	//! \brief ���ز�����������
	DWORD m_FSAAQuality;	
	
	//! \brief ��ȡ�
	unsigned int m_nWidth;

	//! \brief �߶ȡ�
	unsigned int m_nHeight;
    //! \brief ��ɫ��ȡ�
	unsigned int m_nColourDepth;
	
	//! \brief �豸״̬��
	HRESULT m_hDeviceState;

	//! \brief ������Ŀ��
	UGuint m_unLastVertexSourceCount;

	//! \brief Ŀǰ��Դ����
	unsigned short m_nCurrentLights;

	//! \brief ��ͼ����
	UGMatrix4d m_ViewMatrix;

	//! \brief �ֶ��ں���ɫ����
	UGColorValue m_ManualBlendColours[MAX_TEXTURE_NUM][2];	
	//! \brief ������������
	LPDIRECT3DVERTEXDECLARATION9 m_pDecl;
	//! \brief ������Ŀ��
	UGuint m_unVBUsedVertexCount;	
	//! \brief ������ľ��
	UGuint m_unIBUsedVertexCount;
	//! \brief ���㻺�档
	LPDIRECT3DVERTEXBUFFER9 m_pVB;	
	//! \brief �������档
	LPDIRECT3DINDEXBUFFER9  m_pIB;
	//! \brief �����档
	LPDIRECT3DVERTEXBUFFER9 m_pTB;
//	LPDIRECT3DTEXTURE9 m_pTB;
	//! \brief �������顣
	LPDIRECT3DTEXTURE9 m_pTexture[MAX_TEXTURE_NUM];		
	//! \brief �豸���ܶ���
	D3DCAPS9 m_Caps;

	//! \brief ��Ա�ļ�Ҫ˵����
	UGbool m_bPerStageConstantSupport;

	


	//! structure holding texture unit settings for every stage
	struct D3DTextureStageDesc
	{
		/// the type of the texture
		UGD3D9Mappings::eD3DTexType texType;
		/// wich texCoordIndex to use
		size_t coordIndex;
		/// type of auto tex. calc. used
		TexCoordCalcMethod autoTexCoordType;
        /// Frustum, used if the above is projection
        const UGFrustum *frustum;
		/// texture 
		IDirect3DBaseTexture9 *pTex;
	} m_TexStageDesc[MAX_TEXTURE_NUM];
	
	//! \brief �����ʽ��
	struct D3DVertexFormat
	{
		UGfloat x, y, z;
		UGfloat u, v;
	};

};
extern "C" D3DRENDERSYS_API UGRenderSys* CreateRenderSys();
}

#endif // !defined(AFX_UGD3DRENDERSYS_H__6736EEA2_1529_43BA_87AF_CE7A52A398E3__INCLUDED_)
