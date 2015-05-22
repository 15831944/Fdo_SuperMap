/* 
	\file UGRenderableObject.h
	\brief ����Ⱦ�������ļ�
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/
#if !defined(AFX_UGRENDERABLEOBJECT_H__E2A8E83B_C9F8_49CF_8B50_D278E9755CAD__INCLUDED_)
#define AFX_UGRENDERABLEOBJECT_H__E2A8E83B_C9F8_49CF_8B50_D278E9755CAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include "Scene/UGRenderOperation.h"
#include "Scene/UGVector3R.h"
#include "Scene/UGMatrix4d.h"
#include "Scene/UGBoundingBox.h"
#include "Scene/UGCameraBase.h"
#include "Scene/UGColorValue.h"


namespace UGC 
{

//! \brief ����Ⱦ������
//! \remarks ��ע��Ϣ
class SCENE_API UGRenderableObject
{
public:
	//! \brief ���캯��
	UGRenderableObject();
	//! \brief ���캯��
	UGRenderableObject(const UGString& strName);
	//! \brief ��������
	virtual ~UGRenderableObject();
	//! \brief ���ÿ���Ⱦ��������Ʊ�־
	void SetName(const UGString& strName);
	//! \brief ��ÿ���Ⱦ��������Ʊ�־
	UGString GetName();
	//! \brief ���ÿ���Ⱦ�����Ƿ�ɼ�
	void SetHide(UGbool bHide);
	//! \brief �жϿ���Ⱦ�����Ƿ�ɼ�
	UGbool IsHide();
	//UGbool IsVisible();
	//! \brief ���ÿ���Ⱦ�����͸����
	void SetOpacity(UGfloat dOpacity);
	//! \brief ��ÿ���Ⱦ�����͸����
	UGfloat GetOpacity();
	//! \brief �жϿ���Ⱦ�����Ƿ��ʼ��
	UGbool  IsInitialized();
	//! \brief 
	virtual void Release() = 0;
	//! \brief ���ÿ���Ⱦ����Ŀռ�λ��
	void SetPosition(const UGVector3R& vecPos);
	//! \brief �õ�����Ⱦ����Ŀռ�λ��
	UGVector3R GetPosition();
	//! \brief ������X,Y,Z����תһ���Ƕȣ��Զ�Ϊ��λ,ע�ⲻ������������ϵ
	void RotateX(UGReal dAngle);
	//! \brief ������X,Y,Z����תһ���Ƕȣ��Զ�Ϊ��λ,ע�ⲻ������������ϵ
	void RotateY(UGReal dAngle);
	//! \brief ������X,Y,Z����תһ���Ƕȣ��Զ�Ϊ��λ,ע�ⲻ������������ϵ
	void RotateZ(UGReal dAngle);
	//! \brief ��λ����ת����
	void IdentityRotateMatrix();
	//! \brief ���������ǵĵ���ת������Ĳ����ԽǶ�Ϊ��λ
	void SetRotate(const UGVector3R& vecRot);
	//! \brief ��������ǵĵ���ת������Ĳ����ԽǶ�Ϊ��λ
	UGVector3R GetRotate();
	//! \brief ���ö���Ŀɼ�����
	void SetVisibleDist(UGdouble dDist);
	//! \brief ��ö���Ŀɼ�����
	UGdouble GetVisibleDist();
	//! \brief ���ÿ���Ⱦ���������ģʽ
	virtual void SetNormalMode(UGint normalMode);
	//! \brief �õ�����Ⱦ���������ģʽ
	UGint GetNormalMode();
	//! \brief ���ÿ���Ⱦ��������淽��
	virtual void SetFrontFace(UGint enFrontFace);
	//! \brief �õ�����Ⱦ��������淽��
	UGint GetFrontFace();
	//! \brief ���ÿ���Ⱦ��������ű���
	void SetScale(UGfloat fScale);
	//! \brief ���ÿ���Ⱦ��������ű���
	void SetScale(UGfloat fScaleX,UGfloat fScaleY,UGfloat fScaleZ);
	//! \brief �õ�����Ⱦ��������ű���
	UGVector3R GetScale();
	//! \brief �õ�����Ⱦ����İ�Χ��
	UGBoundingBox GetBoundingBox();
	//! \brief ���ÿ���Ⱦ����ĵ�ǰ���
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);
	//! \brief malq-2007-11-30
	UGCameraBase*  GetActiveCamera();

	//! \brief �ж���Ⱦ�����ǲ������Ӿ����� 
	UGbool IsVisible();



//	// copy ogre function to our system
//	virtual UGMaterial* GetMaterial(void) const {return NULL;};
//	virtual void GetRenderOperation(UGRenderOperation& op) {};
//	virtual void GetWorldTransforms(UGMatrix4d* xform) const {};	
//	virtual UGQuaternion4d& GetWorldOrientation(void) const {return  UGQuaternion4d(1,0,0,45*DTOR);};
//	virtual UGVector3R& GetWorldPosition(void) const {return UGVector3R(0,0,0);};
//	virtual UGReal GetSquaredViewDepth(const UGCameraBase* cam) const {return 0;};
//	virtual UGLightList& GetLights(void) const {UGLightList lst; return lst;}


protected:
	//! \brief �����Ա
	UGCameraBase* m_pActiveCamera;
	//! \brief ��Ⱦ��Ա
	UGRenderOperation m_RenderOperation;
	//! \brief �жϿɼ��Գ�Ա
	UGbool m_bHide;
	//! \brief ���Ʊ�־��Ա
	UGString m_strName;
	//! \brief ͸���ȳ�Ա
	UGfloat  m_dOpacity;
	//! \brief ��ʼ����־��Ա
	UGbool m_bInitialized;
	//! \brief λ�ó�Ա
	UGVector3R m_vecPosition;
	//! \brief ��ת�Ƕȳ�Ա
	UGVector3R m_vecRotate;
	//! \brief ��ת�����Ա
	UGMatrix4d m_matRotate;
	//! \brief ���ű�����Ա
	UGVector3R m_vecScale;
	//! \brief ����ģʽ��Ա
	UGint m_nNormalMode;
	//! \brief ������淽���Ա
	UGint m_nFrontFace;
	//! \brief �ɼ������Ա
	UGdouble  m_dVisibleDist;
	//! \brief ��Χ�г�Ա
	UGBoundingBox m_BoundingBox;

	//! \brief ��ɫ��Ա
	UGColorValue m_DiffuseColor;
	//! \brief ��Ĵ�С�����ߵĴ�ϸ
	UGfloat m_fSize;

};

}
#endif // !defined(AFX_UGRENDERABLEOBJECT_H__E2A8E83B_C9F8_49CF_8B50_D278E9755CAD__INCLUDED_)
