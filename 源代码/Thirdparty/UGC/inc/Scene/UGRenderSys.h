// UGRenderSys.h: interface for the UGRenderSys class.
//
//////////////////////////////////////////////////////////////////////
/* 
	\file UGRenderSys.h
	\brief ���ļ���������ʾ�����ͷ�ļ���
	\author ��������������
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGRENDERSYS_H__2777C030_C1E5_46EB_9998_A09FFE2AB29F__INCLUDED_)
#define AFX_UGRENDERSYS_H__2777C030_C1E5_46EB_9998_A09FFE2AB29F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGConfigOptionMap.h"
#include "Scene/UGMatrix4d.h"
#include "Scene/UGColorValue.h"
#include "Scene/UGLight.h"
#include "Scene/UGTextureUnitState.h"
#include "Scene/UGHardwareVertexBuffer.h"
#include "Scene/UGRenderWindow.h"
#include "Scene/UG3DWindowTypes.h"


namespace UGC 
{

	typedef UGDict<UGString, UGRenderTarget * > RenderTargetMap;
	typedef UGDict<UGuchar, UGRenderTarget * > RenderTargetPriorityMap;

	typedef UGDict<UGString, UGString> NameValuePairList;
/// Enum describing the ways to generate texture coordinates

//! \brief �Զ������������귽��ö�ٳ�����
//! \remarks ÿһ��������Ӧ��һ���Զ������������곣����
enum TexCoordCalcMethod
{
    /// No calculated texture coordinates
	// �������������곣��
    TEXCALC_NONE,

    /// Environment map based on vertex normals
    // ���㻷���������곣��
	TEXCALC_ENVIRONMENT_MAP,
    
	/// Environment map based on vertex positions
    // ����ƽ�滷���������곣��
	TEXCALC_ENVIRONMENT_MAP_PLANAR,
    
	// ���㷴�价���������곣��
	TEXCALC_ENVIRONMENT_MAP_REFLECTION,
    
	// ����һ���������곣��
	TEXCALC_ENVIRONMENT_MAP_NORMAL,
    
	/// Projective texture
	// ����ͶӰ�������곣��
    TEXCALC_PROJECTIVE_TEXTURE
};

/// Enum describing the various actions which can be taken onthe stencil buffer

//! \brief ģ�建�����ö�ٳ�����
enum StencilOperation
{
    /// Leave the stencil buffer unchanged
	// ����ģ�建��ֵ����
    SOP_KEEP,

    /// Set the stencil value to zero
    // ����ģ�建��ֵ���Ϊ��
	SOP_ZERO,

    /// Set the stencil value to the reference value
    // �滻ԭ����ģ�建��
	SOP_REPLACE,

    /// Increase the stencil value by 1, clamping at the maximum value
    // ģ�建��ֵ����һ
	SOP_INCREMENT,

    /// Decrease the stencil value by 1, clamping at 0
    // ģ�建��ֵ����һ
	SOP_DECREMENT,

    /// Increase the stencil value by 1, wrapping back to 0 when incrementing the maximum value
    // ģ�建��ֵ����һ�����������ֵ��ֵΪ��
	SOP_INCREMENT_WRAP,

    /// Decrease the stencil value by 1, wrapping when decrementing 0
	// ģ�建��ֵ����һ�����ﵽ��Сֵ���ټ���
    SOP_DECREMENT_WRAP,

    /// Invert the bits of the stencil buffer
    // ģ�建��ֵλȡ��
	SOP_INVERT

};


//! \brief ������ʾ�����࣬�Ӹ�������D3D��OpenGL��ʾ���档��
//! \remarks ����һ��������ࡣ
class SCENE_API UGRenderSys  
{

public:

	//! \brief ���캯����
	UGRenderSys();	
	//! \brief ����������
	virtual ~UGRenderSys();
	

	//! \brief ��ȡ��ʾ�������ơ�
	//! \return ������ʾ��������ơ�
	virtual const UGString& GetName(void) const = 0;
	//! \brief ���ݴ���Ż�ȡ����������
	//! \param errorNumber �����[in]��
	//! \return ���ش���������
	virtual UGString GetErrorDescription(UGint errorNumber) const = 0;
	//! \brief ��ȡ��ά�������ޡ�
	//! \return ���޶���
	const UGRenderSystemCapabilities* GetCapabilities(void) const;	
	//! \brief ��ȡ��ʾ�����������顣	
	//! \return ������ʾ�����������顣
	virtual UGConfigOptionMap& GetConfigOptions(void) = 0;
	//! \brief ��ָ���������ֵ��
	//! \param name ָ���������������[in]��
	//! \param value ָ�����������ֵ[in]��
	virtual void SetConfigOption(const UGString &name, UGString &value) = 0;
	//! \brief ��֤���úõ���ʾ����������
	//! \return ����д����򷵻ش�����Ϣ�����û�д����򷵻ؿ��ַ�����
	virtual UGString ValidateConfigOptions(void) = 0;

	
	//! \brief ��ʼ����ʾ���档
	//{{���������Ogre�в�һ�� �޸���:�޷��� 2007-10-18 10:33:10
	//}}�޸�ԭ�� �޸���:�޷���  2007-10-18 10:33:10
	virtual UGRenderWindow *Initialize(Window hWnd) = 0;
	//! \brief ����������ı�����³�ʼ����ʾ���档
	virtual void ReInitialize() = 0;
	//! \brief �ر���ʾ���沢�ͷ������Դ��
	virtual void ShutDown(void);
	//! \brief ��Ⱦ������
	//! \param &ro ��Ⱦ����[in]��
	virtual void Render(UGRenderOperation &ro) = 0;
	//! \brief ����������Ⱦ����
	virtual void UpdateAllRenderTargets(void);
	//! \brief  ����������Ⱦ���ڶ��������Ϊͬһ����
	void  SetRenderTargetsFont(const UGTextStyle& textStyle);
	//! \brief ��ʼ��Ⱦ��
	virtual void BeginFrame() = 0;	
	//! \brief ������Ⱦ��
	virtual void EndFrame() = 0;
	//! \brief ��Ŀ�����
	//! \param &target Ŀ�����[in]��
	virtual void AttachRenderTarget( UGRenderTarget &target );		
	//! \brief ��ȡ��ǰ�Ŀ�����
	//! \param &name ����[in]��
	//! \return Ŀ�����ָ�롣
	virtual UGRenderTarget *GetRenderTarget( const UGString &name );	
	//! \brief �������ڶ���
	//! \param hWnd �ⲿ���ھ��[in]��
	//! \param 0 ��ȡ���������б�[in]��
	//! \return ���ڶ���ָ�롣
	virtual UGRenderWindow *CreateRenderWindow(Window hWnd, NameValuePairList *miscParams = 0) = 0;


//	virtual HardwareOcclusionQuery* createHardwareOcclusionQuery(void) = 0;
//	virtual void destroyHardwareOcclusionQuery(HardwareOcclusionQuery *hq);
//	RenderTexture * createRenderTexture( const String & name, unsigned int width, unsigned int height,
//		 	TextureType texType = TEX_TYPE_2D, PixelFormat internalFormat = PF_X8R8G8B8, 
//			const NameValuePairList *miscParams = 0 ); 
//	virtual MultiRenderTarget * createMultiRenderTarget(const String & name) = 0; 
//	virtual void destroyRenderWindow(const String& name);
//	virtual void destroyRenderTexture(const String& name);
//	virtual void destroyRenderTarget(const String& name);
	
//	virtual RenderTarget * detachRenderTarget( const String &name );
//	typedef MapIterator<Ogre::RenderTargetMap> RenderTargetIterator;
//	virtual RenderTargetIterator getRenderTargetIterator(void) 
//	{
//		return RenderTargetIterator( mRenderTargets.begin(), mRenderTargets.end() );
//	}
//	virtual void setScissorTest(UGbool enabled, size_t left = 0, size_t top = 0,
//  	          size_t right = 800, size_t bottom = 600) = 0;
//	virtual void bindGpuProgram(GpuProgram* prg);
//	virtual void bindGpuProgramParameters(GpuProgramType gptype, GpuProgramParametersSharedPtr params) = 0;
//	virtual void bindGpuProgramPassIterationParameters(GpuProgramType gptype) = 0;
//	virtual void unbindGpuProgram(GpuProgramType gptype);
//	virtual UGbool isGpuProgramBound(GpuProgramType gptype);
//	virtual void setClipPlanes(const UGPlaneList& clipPlanes) = 0;
//	virtual void _initRenderTargets(void);
//	virtual void _notifyCameraRemoved(const Camera* cam);


	//! \brief ����ȫ�ֹ����ɫ��ǿ�ȡ�
	//! \param r Red����[in]��
	//! \param g Green����[in]��
	//! \param b Blue����[in]��
	virtual void SetAmbientLight(UGfloat r, UGfloat g, UGfloat b) = 0;
	//! \brief ���õƹ����Ӱģʽ��
	//! \param so ��Ӱģʽ[in]��
	virtual void SetShadingType(ShadeOptions so) = 0;	
	//! \brief �����Ƿ����õƹ�Ч����Ĭ��Ϊ0�Ź�Դ��
	//! \param enabled �����������Ϊtrue����������Ϊfalse[in]��
	virtual void SetLightingEnabled(UGbool enabled) = 0;	
	//! \brief ����ʹ�õĵƹ��б���Ŀ��
	//! \param lights �ƹ��б�[in]��
	//! \param limit ʹ�õĵƹ���Ŀ[in]��
	//! \remarks ����ָ��ͬһ���б����ϵı����Ŀ��
	virtual void UseLights(const UGLightList& lights, UGuint limit) = 0;			
	//! \brief �����رչ�Դ��
	//! \param nLightID ��Դ������[in]��
	//! \param bEnabled TRUEΪ������FALSEΪ�ر�[in]��
	//! \remarks ������SetLightingEnable�����е��ظ���
	//! \remarks D3Dû��ʵ�ָú�����GLû��ʵ��SetLightingEnable����
	//! \attention ����ͳһ�ú�����
	// modified by luofx  07.12.5
//	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled)=0;
	//! \brief �õ���Դ״̬��
	//! \param nLightID �������û��������[in]��
	//! \remarks GL�����ǵƹ�0״̬��D3Dû��ʵ�֡�
	//! \attention ������Ƹú�����
	// modified by luofx 07.12.5
//	virtual UGbool GetLightEnabled(UGint nLightID)=0;
	//! \brief ���ù�Դλ�á�
	//! \param nLightID ��ԴID[in]��
	//! \param x λ��X�����[in]��
	//! \param y λ��Y�����[in]��
	//! \param z λ��Z�����[in]��
	//! \param w ����������[in]��
	//! \remarks GLʵ�֣�D3Dû��ʵ�֡�
	//! \attention ����ͬһ�������ܡ�
//	virtual void SetLightPos(UGint nLightID,UGfloat x,UGfloat y,UGfloat z,UGfloat w)=0;

	//! \brief ���������SetDepthBufferCheckEnabled�ظ���
	//! \param TRUE [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ��
	// modified by luofx 07.12.5
//	virtual void SetDepthBufferEnabled(UGbool bEnabled = TRUE) = 0;
	
	//! \brief �����Ƿ�����W-Buffer��
	//! \param enabled �����������Ϊtrue����������Ϊfalse[in]��
	//! \remarks W-Buffer�Ǳ�Z�������ϸ�Ļ��棬�ú��������D3D��
	void SetWBufferEnabled(UGbool enabled);
	//! \brief ��ȡ�Ƿ�������W-Buffer��
	//! \return ����������򷵻�true�����򷵻�false��
	UGbool GetWBufferEnabled(void) const;	
		//! \brief ������Ȼ��������
	//! \param depthTest �Ƿ�������Ȳ��ԣ�TRUE������FALSE�ر�[in]��
	//! \param depthWrite �Ƿ�������Ȳ��ԣ�TRUE��Ȼ���ֻ����FALSE�ɶ�д[in]��
	//! \param depthFunction ��Ȼ���ȽϺ�����ȱʡΪ������[in]��
	virtual void SetDepthBufferParams(UGbool depthTest = true, UGbool depthWrite = true, 
		CompareFunction depthFunction = CMPF_LESS_EQUAL) = 0;	
	//! \brief �����Ƿ�������Ȼ�����ԡ�
	//! \param enabled TRUEΪ������FALSEΪ�ر�[in]��
	virtual void SetDepthBufferCheckEnabled(UGbool enabled = true) = 0;
	//! \brief ����������Ȼ��档
	//! \param enabled TRUEΪֻ����FALSEΪ�ɶ���д[in]��
	virtual void SetDepthBufferWriteEnabled(UGbool enabled = true) = 0;
	//! \brief ������Ȼ�����ԱȽϺ�����
	//! \param func �ȽϺ���[in]��
	virtual void SetDepthBufferFunction(CompareFunction func = CMPF_LESS_EQUAL) = 0;	
	//! \brief ����������ɫ���档
	//! \param red TRUEΪ���κ�ɫ������ɫ���棬FALSEΪ�෴[in]��
	//! \param green TRUEΪ������ɫ������ɫ���棬FALSEΪ�෴[in]��
	//! \param blue TRUEΪ������ɫ������ɫ���棬FALSEΪ�෴[in]��
	//! \param alpha TRUEΪ��ĻAlpha������FALSEΪ�෴[in]��
	virtual void SetColourBufferWriteEnabled(UGbool red, UGbool green, UGbool blue, UGbool alpha) = 0;	
	//! \brief �������ƫ����ڶ����ƫ�ơ�
	//! \param bias �㶨ƫ����[in]��
	virtual void SetDepthBias(UGushort bias) = 0;	
	//! \brief ����ģ�建�����Ƿ���Ч��
	//! \param enabled TRUE����ģ�建���⣬FALSE��ر�[in]��
	virtual void SetStencilCheckEnabled(UGbool enabled) = 0;	
	//! \brief ����ģ�建�������
	//! \param func �ȽϺ�������[in]��
	//! \param refValue �ο�ֵ��������ģ�建����ֵ���бȽ�[in]��
	//! \param mask ���룬���ο�ֵ�뻺����ֵ���бȽϵ�ֻ��maskֵΪ1λ���бȽ�[in]��
	//! \param stencilFailOp ģ�建���������[in]��
	//! \param depthFailOp ģ�建���������[in]��
	//! \param passOp ģ�建���������[in]��
	//! \param twoSidedOperation �Ƿ�������߽��в�����TRUE�����ǣ�FALSE�����[in]��
	virtual void SetStencilBufferParams(CompareFunction func = CMPF_ALWAYS_PASS, 
            UGuint refValue = 0, UGuint mask = 0xFFFFFFFF, 
            StencilOperation stencilFailOp = SOP_KEEP, 
            StencilOperation depthFailOp = SOP_KEEP,
            StencilOperation passOp = SOP_KEEP, 
            UGbool twoSidedOperation = false) = 0;	
	//! \brief �����档
	//! \param buffers ��������[in]��
	//! \param colour ��ɫֵ������������ɫ����[in]��
	//! \param depth ��ȣ�����������Ȼ���[in]��
	//! \param stencil ģ��ֵ����������ģ�建��[in]��
	virtual void ClearFrameBuffer(UGuint buffers, 
		const UGColorValue& colour = UGColorValue::Black, 
		UGReal depth = 1.0f, UGushort stencil = 0) = 0;
	

	//! \brief �����������
	//! \param &m �������[in]��
	virtual void SetWorldMatrix(const UGMatrix4d &m) = 0;
	virtual UGMatrix4d& GetWorldMatrix() = 0;
	//! \brief ���ö���������
	//! \param m �������[in]��
	//! \param count ������Ŀ[in]��
	virtual void SetWorldMatrices(const UGMatrix4d* m, UGushort count);	
	//! \brief �����Ӿ���
	//! \param &m �Ӿ���[in]��
	virtual void SetViewMatrix(const UGMatrix4d &m) = 0;	
	virtual UGMatrix4d& GetViewMatrix() = 0;
	//! \brief ����ͶӰ����
	//! \param &m ͶӰ����[in]��
	virtual void SetProjectionMatrix(const UGMatrix4d &m) = 0;
	virtual UGMatrix4d& GetProjectionMatrix() = 0;
		//! \brief ת��ͶӰ����
	//! \param matrix ԴͶӰ����[in]��
	//! \param dest Ŀ��ͶӰ����[out]��
	//! \param forGpuProgram TRUEΪ��������ϵ��FALSEΪ��������ϵ[in]��
	virtual void ConvertProjectionMatrix(const UGMatrix4d& matrix,
            UGMatrix4d& dest, UGbool forGpuProgram = false) = 0;	
	//! \brief ����͸��ͶӰ����
	//! \param fovy ͸��ͶӰ�Ƕ�[in]��
	//! \param aspect ��߱�[in]��
	//! \param nearPlane ������Zֵ[in]��
	//! \param farPlane Զ����Zֵ[in]��
	//! \param dest [out]��������ͶӰ����
	//! \param forGpuProgram TRUEΪ��������ϵ��FALSEΪ��������ϵ[in]��
	virtual void MakeProjectionMatrix(const UGAngle& fovy, UGReal aspect, UGReal nearPlane, 
		UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false) = 0;	
	//! \brief ����͸��ͶӰ����
	//! \param left ������[in]��
	//! \param right ������[in]��
	//! \param bottom ������[in]��
	//! \param top ��������[in]��
	//! \param nearPlane ������Zֵ[in]��
	//! \param farPlane Զ����Zֵ[in]��
	//! \param dest �������ɾ���[out]��
	//! \param forGpuProgram TRUEΪ��������ϵ��FALSEΪ��������ϵ[in][in]��
	virtual void MakeProjectionMatrix(UGReal left, UGReal right, UGReal bottom, UGReal top, 
            UGReal nearPlane, UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false) = 0;	
	//! \brief ��������ͶӰ����
	//! \param fovy �Ƕ�[in]��
	//! \param aspect ��߱�[in]��
	//! \param nearPlane ������Zֵ[in]��
	//! \param farPlane Զ����Zֵ[in]��
	//! \param dest �������ɾ���[out]��
	//! \param forGpuProgram [in]��
	virtual void MakeOrthoMatrix(const UGAngle& fovy, UGReal aspect, UGReal nearPlane, 
		UGReal farPlane, UGMatrix4d& dest, UGbool forGpuProgram = false) = 0;	
	//! \brief Ӧ����б���ͶӰ��
	//! \param matrix ͶӰ����[in]��
	//! \param plane [in]��
	//! \param forGpuProgram [in]��
	virtual void ApplyObliqueDepthProjection(UGMatrix4d& matrix, const UGPlane& plane, 
            UGbool forGpuProgram) = 0;	
	//! \brief ����ͶӰ�任����MakeProjectionMatrix���ơ�
	//! \param fovy �Ƕ�[in]��
	//! \param aspect ��߱�[in]��
	//! \param nearPlane ������Zֵ[in]��
	//! \param farPlane Զ����Zֵ[in]��
	//! \return ͶӰ����		
	// modified by luofx 07.12.5
//	virtual UGMatrix4d SetProjectionMatrix(UGReal fovy, UGReal aspect, UGReal nearPlane, 
//				UGReal farPlane)=0;			
	//! \brief ����ģ���ӽǾ���
	//! \param cameraPosition ���λ��[in]��
	//! \param cameraTarget �������[in]��
	//! \param cameraUpVector ������Ϸ���[in]��
	//! \param Tilt ����˳ʱ����X����ת�Ƕ�[in]��
	//! \param Bank ������OpenGL��û��ʹ�õ�[in]��
	//! \param Heading ������˳ʱ����Z����ת�Ƕ�[in]��
	//! \param dDistance ������Z������ƾ���[in]��
	//! \return ģ���ӽǾ���
	//! \remarks D3D��GLʵ����Щ��һ����
	//! \attention ���������������������
//	virtual UGMatrix4d SetViewMatrix(UGVector3R cameraPosition, 
//									UGVector3R cameraTarget, 
//									UGVector3R cameraUpVector, 
//									UGAngle Tilt, UGAngle Bank, UGAngle Heading, UGReal dDistance) = 0;	
	//! \brief ��������ת����Windows���ꡣ
	//! \param &v ��������[in]��
	//! \param &win Windows����[out]��
	//! \remarks D3Dû��ʵ�֡�
	//! \attention ��������ʵ�����������
	virtual void Project(const UGVector3R &v, UGVector3R &win) = 0;
	virtual void MakePickRadial(const UGint x, const UGint y, UGVector3R& nPos, UGVector3R& fPos, UGMatrix4d viewMatrix = UGMatrix4d::ZERO) = 0;
	virtual void UnMakePickRadial(UGfloat& x, UGfloat& y, UGfloat& z, UGVector3R& Pos, UGMatrix4d viewMatrix = UGMatrix4d::ZERO) = 0;
	//! \brief Windows����ת�����������ꡣ
	//! \param &win Windows����[in]��
	//! \param &v ��������[out]��
	//! \remarks ��D3D��GL�����ڡ�
	//! \attention ��		
	virtual void UnProject(const UGVector3R &win,UGVector3R &v) = 0;
	//! \brief ���òü�ƽ�档
	//! \param index �ü���������[in]��
	//! \param &p �ü���[in]��
	virtual void SetClipPlane (UGushort index, const UGPlane &p);	
//  virtual void SetClipPlane (UGushort index, UGReal A, UGReal B, UGReal C, UGReal D) = 0;//  
//  virtual void enableClipPlane (UGushort index, UGbool enable) = 0;
	//! \brief �����ӿڡ�
	//! \param &viewport �ӿڶ���[in]��
	virtual void SetViewport(UGViewport *pViewport) = 0;
	//! \brief ��ȡ�ӿڶ���
	//! \return �ӿڶ���ָ�롣
	virtual UGViewport* GetViewport(void);	
	

	//! \brief ���ö�������������Ԫ��ʽ��
	//! \param texUnit ����Ԫ��ţ�OpenGL�ܹ�ֻ����0-31������Ԫ[in]��
	//! \param tl ����Ԫ��ز�������[in]��
	//! \attention �����ɰ������Զ������������꣬��������������ع��ܡ�
	virtual void SetTextureUnitSettings(UGuint texUnit, UGTextureUnitState& tl);	
	//! \brief ȡ������Ԫ��ʽ���á�
	//! \param texUnit ����Ԫ���к�[in]��
	//! \attention Ŀǰû��ʵ��
	virtual void DisableTextureUnit(UGuint texUnit);
	//! \brief ȡ����������Ԫ��ʽ���á�
	//! \param texUnit ��ʼ������[in]��
	virtual void DisableTextureUnitsFrom(UGuint texUnit);
	//! \brief ��������Ԫ�˲�������
	//! \param unit ����Ԫ������[in]��
	//! \param minFilter ��С�˲�����[in]��
	//! \param magFilter ����˲�����[in]��
	//! \param mipFilter mipmap�˲�����[in]��
	virtual void SetTextureUnitFiltering(UGuint unit, FilterOptions minFilter,
            FilterOptions magFilter, FilterOptions mipFilter);	
		//! \brief ��������Ԫ�Ƿ�������
	//! \param unit ����Ԫ������[in]��
	//! \param enabled �Ƿ�������TRUEΪ������FALSEΪ�ر�[in]��
	//! \param &texname ����Ԫ����[in]��
	virtual void SetTexture(UGuint unit, UGbool enabled, const UGString &texname) = 0;
	//! \brief ������������ϵ��
	//! \param unit ����Ԫ������[in]��
	//! \param index ��������������[in]��
	virtual void SetTextureCoordSet(UGuint unit, UGuint index) = 0;	
	//! \brief ������������ֵ��
	//! \param unit ����Ԫ[in]��
	//! \param m ������������ֵ����[in]��
	//! \param frustum ��׶�壬����������[in]��
	virtual void SetTextureCoordCalculation(UGuint unit, TexCoordCalcMethod m, 
            const UGFrustum* frustum = 0) = 0;	
	//! \brief ����������ģʽ��
	//! \param unit ����Ԫ������[in]��
	//! \param bm ��ɫ�����[in]��
	virtual void SetTextureBlendMode(UGuint unit, const UGLayerBlendModeEx& bm) = 0;
	//! \brief ��������λ�Ĺ����
	//! \param unit ����Ԫ������[in]��
	//! \param ftype ������[in]��
	//! \param filter �˲�����[in]��
	virtual void SetTextureUnitFiltering(UGuint unit, FilterType ftype, FilterOptions filter) = 0;	
	//! \brief ��������Ԫ��������ֵ��
	//! \param unit ����Ԫ������[in]��
	//! \param maxAnisotropy ��������ֵ  [in]��
	virtual void SetTextureLayerAnisotropy(UGuint unit, UGuint maxAnisotropy) = 0;	
	//! \brief ��������Ԫ�����ַ����ģʽ��
	//! \param unit ����Ԫ������[in]��
	//! \param uvw UVW�����ַ����[in]��
	virtual void SetTextureAddressingMode(UGuint unit, const UGTextureUnitState::UVWAddressingMode& uvw) = 0;	
	//! \brief ��������Ԫ�߿���ɫ��
	//! \param unit ����Ԫ������[in]��
	//! \param colour ��ɫֵ[in]��
	virtual void SetTextureBorderColour(UGuint unit, const UGColorValue& colour) = 0;	
	//! \brief ��������Ԫ�������
	//! \param unit ����Ԫ������[in]��
	//! \param xform ����Ԫ����[in]��
	virtual void SetTextureMatrix(UGuint unit, const UGMatrix4d& xform) = 0;		
	//! \brief ���ð�������ϡ�
	//! \param sourceFactor Դ����[in]��
	//! \param destFactor Ŀ������[in]��
	virtual void SetSceneBlending(SceneBlendFactor sourceFactor, SceneBlendFactor destFactor) = 0;	
	//! \brief ����Aplpha���ԣ�һ��������͸������
	//! \param func Alpha�ȽϺ���[in]��
	//! \param value Alpha�ο�ֵ[in]��
	virtual void SetAlphaRejectSettings(CompareFunction func, UGuchar value) = 0;	
	//! \brief ����͸���ȡ�
	//! \param fOpacity ͸����ϵ��[in]��
	//! \return ��
	//! \remarks ���������к���û��ʵ���壬��GL��ʵ�֣�D3Dû��ʵ�֡�
	//! \attention ���۸ú���Ȼ��ʵ�֡�
	virtual void SetOpacity(UGfloat fOpacity);
	//! \brief ������ɫ�ںϡ�
	//! \param  [in]��
	//! \return ��
	//! \remarks ���������к���û��ʵ���壬��GL��ʵ�֣�D3Dû��ʵ�֡�
	//! \attention ���۸ú���Ȼ��ʵ�֡�
	virtual void BlendAlpha();


	//! \brief ɾ����ʾ�б�
	//! \param listIndex ��ʾ�б�ID[in]��
	//! \return ��
	//! \remarks ���������к���û��ʵ���壬��GL��ʵ�֣�D3Dû��ʵ�֡�
	//! \attention ���۸ú���Ȼ��ʵ�֡�
	virtual void DeleteList(UGint listIndex);
	//! \brief ������ʾ�б�
	//! \param listIndex ��ʾ�б�ID[in]��
	//! \return ��
	//! \remarks ���������к���û��ʵ���壬��GL��ʵ�֣�D3Dû��ʵ�֡�
	//! \attention ���۸ú���Ȼ��ʵ�֡�
	virtual void CallList(UGint listIndex);
	//! \brief ���û�����Ⱦϸ��ģʽ��
	//! \param renderDetail ����ģʽ[in]��
	// modified by luofx 07.12.5
//	virtual void SetRenderDetail(SceneDetailLevel renderDetail)=0;	
	
	//! \brief �����޳�ģʽ��
	//! \param mode �޳�ģʽ[in]��
	virtual void SetCullingMode(CullingMode mode) = 0;	
	//! \brief ��ȡ�޳�ģʽ��
	//! \return �޳�ģʽ����
	virtual CullingMode GetCullingMode(void) const;	
	//! \brief ���û��ƶ�������͡�
	//! \param level ����ö�ٳ���[in]��
	virtual void SetPolygonMode(PolygonMode level) = 0;	
	//! \brief ȷ������ǰ�棬�޳�������档
	//! \param enFrontFace ȷ��ǰ�淽��[in]��
	//! \return ��
	//! \remarks GL��ʵ�֣�D3D��ʵ�֡�
	//! \attention �����������ö�ٳ�����Ҫ��Ȼ�������൱�Ѿ���
	//! \attention ͬʱҪͬһ���������
	virtual void SetPolyFrontFace(UGint  enFrontFace)=0;
	//! \brief �����Ƿ�ȴ�Vertical Blank��
	//! \param enabled ����ȴ�����Ϊtrue����������Ϊfalse[in]��
	//! \remarks �������������ͼ���ٶȻ�������ѡ��
	void SetWaitForVerticalBlank(UGbool enabled);	
	//! \brief ��ȡ�Ƿ�ȴ�Vertical Blank��
	//! \return ����ȴ��򷵻�true�����򷵻�false��
	UGbool GetWaitForVerticalBlank(void) const;
	//! \brief ������
	//! \param mode ������ģʽ����ָΪ��ͬ����[in]��
	//! \param colour ����ɫ[in]��
	//! \param expDensity ��Ũ��[in]��
	//! \param linearStart ��Ч��ʼZֵ[in]��
	//! \param linearEnd ��Ч����Zֵ[in]��
	virtual void SetFog(FogMode mode = FOG_NONE, const UGColorValue& colour = UGColorValue::White, 
		UGReal expDensity = 1.0, UGReal linearStart = 0.0, UGReal linearEnd = 1.0) = 0;

	//! \brief ������״̬��
	//! \param bEnable TRUEΪ������FALSEΪ�ر�[in]��
	//! \remarks GLʵ�֣�D3Dû��ʵ�֡�
	//! \attention ����ͬһ�������ܡ�		
    // modified by luofx 07.12.5
//	virtual void SetFogEnable(UGbool bEnable)=0;

	//! \brief ��ȡ���Ƿ��״̬��
	//! \param  [in]��
	//! \return TRUEΪ�򿪣�FALSEΪ�رա�
	//! \remarks GLʵ�֣�D3Dû��ʵ�֡�
	//! \attention ����ͬһ�������ܡ�
	// modified by luofx 07.12.5
//	virtual UGbool GetFogEnable()=0;
	//! \brief ������
	//! \param fStart ��Ч����ʼλ��[in]��
	//! \param fEnd ��Ч������λ��[in]��
	//! \return ��
	//! \remarks ���������������û��ʵ�֣���GLʵ�֣�D3D��ʵ�֡�
	//! \attention ����һ�¸ú�����
	// modified by luofx 07.12.5
//	virtual void RenderFog(UGfloat fStart,UGfloat fEnd);
//	virtual void _setSurfaceParams(const ColourValue &ambient,
//            const ColourValue &diffuse, const ColourValue &specular,
//            const ColourValue &emissive, Real shininess,
//            TrackVertexColourType tracking = TVC_NONE) = 0;
	//! \brief ������Ⱦ�㾫��״̬��
	//! \param enabled trueΪ�򿪣�falseΪ�ر�[in]��
	virtual void SetPointSpritesEnabled(UGbool enabled) = 0;	
	//! \brief ���õ㾫�����Ⱦ������
	//! \param size ���С[in]��
	//! \param attenuationEnabled �۾�������ߴ��Ƿ����ͨ���������ڣ�True��constant,linear,quadratic�������������ߴ硣False����Ч[in]��
	//! \param constant �����ߴ��С���ù�ʽ����[in]��
	//! \param linear �����ߴ��С���ù�ʽһ����ϵ��[in]��
	//! \param quadratic �����ߴ��С���ù�ʽ������ϵ��[in]��
	//! \param minSize ���С��Сֵ[in]��
	//! \param maxSize ���С���ֵ[in]��
	virtual void SetPointParameters(UGReal size, UGbool attenuationEnabled, 
			UGReal constant, UGReal linear, UGReal quadratic, 
			UGReal minSize, UGReal maxSize) = 0;	



	//! \brief ��ʼ�����������Ŀ��
	virtual void BeginGeometryCount(void);	
	//! \brief ��ȡ����Ŀ��
	virtual UGuint GetFaceCount(void) const;
	//! \brief ��ȡ������Ŀ��
	virtual UGuint GetVertexCount(void) const;		
	//! \brief ת����ɫֵΪ����ֵ��
	//! \param colour ԭʼ��ɫֵ[in]��
	//! \param pDest ���������ֵ[in]��
	virtual void ConvertColourValue(const UGColorValue& colour, UGuint* pDest);		
	//! \brief ��ȡ����Ԫ�����͡�
	//! \param void [in]��
	//! \return ����Ԫ�����͡�
	virtual VertexElementType GetColourVertexElementType(void) const = 0;	
//	virtual UGReal getHorizontalTexelOffset(void) = 0;
//	virtual UGReal getVerticalTexelOffset(void) = 0;
//	virtual UGReal getMinimumDepthInputValue(void) = 0;
//	virtual UGReal getMaximumDepthInputValue(void) = 0;	
	//! \brief ����m_unCurrentPassIterationCount����ֵ��
	//! \param count ����ֵ[in]��
	void SetCurrentPassIterationCount(const UGuint count);		
	//! \brief ���õ�ǰ�������������綥������Դ��
	//! \param decl �������ݼ����ݸ�ʽ����[in]��
	virtual void SetVertexDeclaration(UGVertexDeclaration* decl) = 0;	
	//! \brief ���ö������ݻ������󶨡�
	//! \param binding ��¼���ж��㻺������״̬����[in]��
	virtual void SetVertexBufferBinding(UGVertexBufferBinding* binding) = 0;
//	virtual void setNormaliseNormals(UGbool normalise) = 0;
	//! \brief ���������OGRE��û��ʹ�õ��������������һ������ֵ��
	//! \param invert [in]��
	virtual void SetInvertVertexWinding(UGbool invert);		


	//! \brief ��ʾ��ά���塣
	//! \param s �ַ�����[in]��
	//! \param vecPos λ��[in]��
	//! \param colorOutLines �߿���ɫ��û��������[in]��
	//! \param colorFont ������ɫ[in]��
	//! \remarks GLʵ�֣�D3Dû��ʵ�֡�
	//! \attention ��������һ�¸ú������ܡ�
	virtual void TextOut2DText( const UGchar* s,const UGVector3R& vecPos);
	//! \brief ������ά���塣
	//! \param s �ַ���[in]��
	//! \param vecPos λ��ʸ��[in]��
	//! \param colorFont ������ɫ[in]��
	//! \param colorOutLines û�������� [in]��
	//! \param &pCharList �ַ���ʾ�б�[in]��
	//! \remarks GLʵ�֣�D3Dû��ʵ�֡�
	//! \attention ��������һ�¸ú������ܡ�
	virtual void TextOut3DText(const UGchar* s,const UGVector3R& vecPos, const UGColorValue& colorText,UGint* &pCharList);
	//! \brief ���������к���û��ʵ���壬��GL��ʵ�֣�D3Dû��ʵ�֡�
	//! \param  [in]��
	//! \return ��
	//! \remarks ��
	//! \attention ���۸ú���Ȼ��ʵ�֡�
	virtual void SetRenderFont();
		// malq-2007-11-14-���ƾ����
	virtual void RenderSpritePoint(UGdouble x,UGdouble y,UGdouble z,UGbool bDistChange,UGfloat* pQuadratic)=0;
	// malq-2007-11-14-���ƾ����
	virtual void RenderSpritePoint(UGReal* pVertex,UGint nVertexCount,UGbool bDistChange,UGfloat* pQuadratic, UGint selectedPointIndex = -1)=0;
	// malq-2007-11-20-������ͨ�� 
	virtual void RenderSimplePoint(UGdouble x,UGdouble y,UGdouble z,UGbool bPointSmooth=FALSE)=0;
	// malq-2007-11-20-������ͨ�� 
	virtual void RenderSimplePoint(UGReal* pVertex,UGint nVertexCount,UGbool bPointSmooth=FALSE, UGint selectedPointIndex = -1)=0;
	// malq-2007-11-19���õ��ߵ���ɫ
	virtual void  SetSingleColor(const UGColorValue& colorValue)=0;
	virtual void SetPointSize(UGReal fSize)=0;
	virtual void SetLineWidth(UGReal fSize)=0;


	void NotifyCameraRemoved(const UGMomentumCamera* cam);
	virtual void DrawBoundingBox(const UGBoundingBox& boundingBox) = 0;
	virtual void DrawRadia(const UGVector3R& vecStart, const UGVector3R& vecEnd, const UGVector3R& vecIntersect) = 0;
	
	// ��ʱʹ�ù��պ���
	virtual void SetLightEnable(UGint nLightID,UGbool bEnabled) = 0;
	virtual UGbool GetLightEnabled(UGint nLightID) = 0;
	virtual void Render2DImage(UGint xStart,UGint yStart,UGint nWidth,UGint nHeight, UGbool bIsNeedRotate = FALSE, UGdouble dAngle = 0.0f) = 0;

protected:
	//! \brief The render targets��
    RenderTargetMap m_RenderTargets;
	//! \brief The render targets, ordered by priority��
	RenderTargetPriorityMap m_PrioritisedRenderTargets;
	//! \brief The Active render target��
	UGRenderTarget *m_pActiveRenderTarget;
	//! \brief TextureManager��
	UGTextureManager* m_pTextureManager;

	//! \brief ���ι�������
	UGTerrainManager *m_pTerrainManager;
	//! \brief ��ά�����б�������ֵ
	UGRenderSystemCapabilities *m_pCapabilities;
	//! \brief ���������֪��ʲô��˼��
	//! \remarks ��ע��Ϣ��
	UGuint m_unCurrentPassIterationCount;
	//! \brief �������ҳ��֪��ʲô��˼��
	//! \remarks ��ע��Ϣ��
	UGbool m_bInvertVertexWinding;
	//! \brief ������Ŀ	
	UGuint m_unVertexCount;
	//! \brief ����Ŀ
	UGuint m_unFaceCount;

	//! \brief �޳�ģʽ��ö�ٳ���
	CullingMode m_CullingMode;	
	UGbool m_bVSync;
	UGbool m_bWBuffer;
	
	//! \brief ��Ч�ӿڶ���
	UGViewport* m_pActiveViewport;	

	//! \brief�������ģ���ӵ����ͶӰ����
	UGMatrix4d m_WorldMatrix;
	UGMatrix4d m_ModelViewMatrix;
	UGMatrix4d m_ProjectMatrix;

	//! \brief ģ�;������顣
	UGMatrix4d m_WorldMatrices[256];	
};


}
#endif // !defined(AFX_UGRENDERSYS_H__2777C030_C1E5_46EB_9998_A09FFE2AB29F__INCLUDED_)
