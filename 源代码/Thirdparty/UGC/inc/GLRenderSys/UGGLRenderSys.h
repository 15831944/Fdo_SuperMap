/**  \file UGGLRenderSys.h
   \brief   OpenGL��Ⱦϵͳ
   \auothor malq
   \attetion
   Copyright(c) 1996-2007 SuperMap GIS Technolgoies, Inc<br>
   All Rights Reserved
   \version 2.0
   <b>����˵����</b>\n
	<em>1����һ��˵����\n
	<em>2���ڶ���˵����\n
*/

#if !defined(AFX_UGGLRENDERSYS_H__E87F3D39_C520_427D_9F11_72CB26885C13__INCLUDED_)
#define AFX_UGGLRENDERSYS_H__E87F3D39_C520_427D_9F11_72CB26885C13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GLRenderSys/UGGLPrerequisites.h"
#include "Scene/UGRenderSys.h"
#include "GLRenderSys/UGGLSupport.h"
#include "Scene/UGSceneConfig.h"
#include "Scene/UGMatrix4d.h"
#include "Base/UGFileStdio.h"
#include "Scene/UGRenderWindow.h"
#include "Scene/UG3DWindowTypes.h"


namespace UGC 
{
	
//! \brief OpenGL��Ⱦ��
class GLRENDERSYS_API UGGLRenderSys : public UGRenderSys
{
public:

	//! \brief ���캯��
	UGGLRenderSys(); 
	//! \brief ��������
	virtual ~UGGLRenderSys();
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
	virtual void SetConfigOption(const UGString &name, UGString &value);
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
	//! \brief  ֡��ʼ��GL�ǿ�����������ɻ���������û�����κ�����
	virtual void BeginFrame();
	//! \brief  ֡������û�����κ�����
	virtual void EndFrame();
	//! \brief  ����ǰ�󻺴�
	virtual void Present();
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
	
	// modified by luofx 07.12.5
//	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled);
//	virtual UGbool GetLightEnabled(UGint nLightID);
//	virtual void SetLightPos(UGint nLightID,UGfloat x,UGfloat y,UGfloat z,UGfloat w);
	

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
	virtual void SetWorldMatrix(const UGMatrix4d& m);
	virtual UGMatrix4d& GetWorldMatrix();
	//! \brief ������ͼ����
	//! \param &m ��ͼ����[in]��
	virtual void SetViewMatrix(const UGMatrix4d& m);
	virtual UGMatrix4d& GetViewMatrix();
	//! \brief ����ͶӰ����
	//! \param &m ͶӰ����[in]��
	virtual void SetProjectionMatrix(const UGMatrix4d &m);
	virtual UGMatrix4d& GetProjectionMatrix();
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
	virtual void MakeOrhtoMatrix(UGReal left, UGReal right, UGReal bottom, 
								 UGReal top, UGReal near, UGReal far, UGMatrix4d& dest);
	//! \brief ������б��Ⱦ���
	//! \param matrix ���ɾ���[out]��
	//! \param plane ƽ��[in]��
	//! \param forGpuProgram [in]��
	virtual void ApplyObliqueDepthProjection(UGMatrix4d& matrix, const UGPlane& plane, 
            UGbool forGpuProgram);

//	virtual UGMatrix4d SetProjectionMatrix(UGReal fovy, UGReal aspect, UGReal nearPlane, 
//		UGReal farPlane);
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
	
	// ����ѡ������
	virtual void MakePickRadial(const UGint x, const UGint y, 
		                        UGVector3R& nPos, UGVector3R& fPos, UGMatrix4d viewMatrix = UGMatrix4d::ZERO);
	virtual void UnMakePickRadial(UGfloat& x, UGfloat& y, UGfloat& z, UGVector3R& Pos, UGMatrix4d viewMatrix = UGMatrix4d::ZERO);

	//! \brief �����ӿڡ�
	//! \param *pViewport �ӿڶ���ָ��[in]��
	virtual void SetViewport(UGViewport *pViewport);



    // malq��������������Ҳ��ʱ����,�ĳɺ���2����������
//	virtual void Project(const UGVector3R &v, 
//		const UGMatrix4d &ViewMatrix, const UGMatrix4d &projMatrix, 
//		const UGViewport &viewPort, UGVector3R &win);
//	virtual void UnProject(const UGVector3R &win, 
//		const UGMatrix4d &ViewMatrix, const UGMatrix4d &projMatrix, 
//		const UGViewport &viewPort, UGVector3R &v);

	//! \brief ��������
	//! \param unit ����ͨ������[in]��
	//! \param enabled trueΪ����,falseΪȡ��[in]��
	//! \param &texname ��������[in]��
	virtual void SetTexture(UGuint unit, UGbool enabled, const UGString &texname);
	virtual UGuint SetTexture(UGuint unit, UGuint size, UGuchar* textureData);
	virtual void SetQuadTexture(UGuint bindId);
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
	GLint ConvertCompareFunction(CompareFunction func) const;
	//! \brief ����͸���ȡ�
	//! \param fOpacity ͸����ֵ[in]��
	virtual void SetOpacity(UGfloat fOpacity);	
	//! \brief �ں�Alphaֵ��
	virtual void BlendAlpha();	



	//! \brief ɾ���б�
	//! \param listIndex �б�����[in]��
	//! \remarks �б��������GL��Ч��D3D��Ч��
	virtual void DeleteList(UGint listIndex);
	//! \brief �����б�
	//! \param listIndex �б�����[in]��
	virtual void CallList(UGint listIndex);	
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
	// modified by luofx 07.12.5
//	virtual void SetFogEnable(UGbool bEnable);
//	virtual UGbool GetFogEnable();
//	virtual void RenderFog(UGfloat fStart,UGfloat fEnd);
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


	void TextOut2DText(const UGchar* s,const UGVector3R& vecPos);
	void TextOut3DText( const UGchar* s,const UGVector3R& vecPos,const UGColorValue& colorText,UGint* & pCharList);
	//! \brief �������塣
	virtual void SetRenderFont();	

	// ��ӻ���BoundingBox����
	virtual void DrawBoundingBox(const UGBoundingBox& boundingBox);
	virtual void DrawRadia(const UGVector3R& vecStart, const UGVector3R& vecEnd, const UGVector3R& vecIntersect);
	

//------------------------------------------------------------------
//                      OpenGLRenderSys�Զ��庯��     
//-------------------------------------------------------------------
	//! \brief ��ȡ�������͡�
	//! \param nTextureType ������[in]��
	//! \return �������ͳ�����
	GLenum GetGLTextureType(UGuint nTextureType) const;	
	//! \brief ���ù�Դλ��
	//virtual void SetLightPos(UGint nLightID,UGfloat x,UGfloat y,UGfloat z,UGbool bLatLongPos);
	//! \brief ��ʾ��λͼ����
//	void PrintBitmapFont( const UGchar* s);	
	//! \brief ��ʾ���߿�����
//	void PrintOutLinesFont(const UGchar* s,const UGVector3R& vecPos,const UGColorValue& colorOutLines,const UGColorValue& colorFont);
	
	//! \brief 		�õ�ɨ���е��ֽڸ���
	//! \return 	UGint
	//! \param 		ePixelFormat ���صĸ�ʽ
	//! \param 		nWidth       һ�����صĸ���
	//! \remarks 		
	//virtual void  RenderTriangles(UGReal* pVertexData=NULL,UGReal* pTexCoordData=NULL,UGReal* pFacetNormsData=NULL,UGReal* pVertexNormsData=NULL);
    
	//! \brief ��ʼ������
	void InitGL();

	//! \brief ��������GLʹ�����飬������
	//! \param gl_matrix[16] �������ɺ�����[in]��
	//! \param m ����[in]��
	void MakeGLMatrix(UGfloat gl_matrix[16], UGMatrix4d& m);
	
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
	virtual void RenderSpritePoint(UGReal* pVertex,UGint nVertexCount,UGbool bDistChange,UGfloat* pQuadratic, UGint selectedPointIndex = -1);
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
	virtual void RenderSimplePoint(UGReal* pVertex,UGint nVertexCount,UGbool bPointSmooth=FALSE, UGint selectedPointIndex = -1);
	//! \brief ���õ�����ɫ��
	//! \param colorValue ��ɫֵ[in]��
	virtual void  SetSingleColor(const UGColorValue& colorValue);
	//! \brief ���õ��С��
	//! \param fSize ��Сֵ[in]��
	virtual void SetPointSize(UGReal fSize);
	//! \brief �����߿�
	//! \param fSize �߿�ֵ[in]��
	virtual void SetLineWidth(UGReal fSize);

	//! \brief �豸�����ĳ�ʼ����
	virtual void OneTimeContextInitialization();	

	//! \brief ���ù�Դλ�÷���
	//! \param lt ��Դ����ָ��[in]��
	//! \param lightindex ��Դ��[in]��
	void SetGLLightPositionDirection(UGLight* lt, GLenum lightindex);	
	
	//! \brief ���ù�Դ��
	//! \param index ��Դ��[in]��
	//! \param lt ��Դ����ָ��[in]��
	void SetGLLight(UGint index, UGLight* lt);	
	
	//! \brief ���ù�Դ��
	void SetLights();	

	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled);
	virtual UGbool GetLightEnabled(UGint nLightID);

private:

	//! \brief ��ȡ�������������
	UGushort GetNumTextureUnits(void);

	//! \brief �������������
	void MakeRowGLMatrix(UGdouble glMatrix[16], const UGMatrix4d& mat);
	
	//! \brief �������������
	void MakeColGLMatrix(UGdouble glMatrix[16], const UGMatrix4d& mat);
	
	//! \brief ɾ��û��ʹ������
//	void DeleteUnusedTextures();

	//! \brief ��ʼ�����ò�����
	void InitConfigOptions(void);
	
	virtual void Render2DImage(UGint xStart,UGint yStart,UGint nWidth,UGint nHeight, UGbool bIsNeedRotate = FALSE, UGdouble dAngle = 0.0f);
	
protected:
	
	//! \brief OpenGL������Ϣ������
	UGGLSupport* m_pGLSupport;
	
	//! \brief ������������
	UGint m_TextureCoordIndex[SMSCN_MAX_TEXTURE_COORD_SETS];

	//! \brief ���ھ���??
	UGMatrix4d m_ViewMatrix;

	//! \brief �����������
	UGMatrix4d m_WorldMatrix;

	UGdouble m_dAngleFromCurToPole;

private:
	
	//! \brief Store last depth write state
	UGbool m_bDepthWrite;

	//! \brief Store last stencil mask state
	UGuint m_nStencilMask;

	//! \brief Store last colour write state
	UGbool m_bColourWrite[4];
	
	//! \brief Number of fixed-function texture units
	UGushort mFixedFunctionTextureUnits;
	
	 //! \brief ��Դָ�����顣
     UGLight* m_pLights[MAX_LIGHTS];
	 
	 //! \brief ��ǰ��Դ��
	 UGuint m_nCurrentLights;

};

extern "C" GLRENDERSYS_API UGRenderSys* CreateRenderSys();

}
#endif // !defined(AFX_UGGLRENDERSYS_H__E87F3D39_C520_427D_9F11_72CB26885C13__INCLUDED_)
