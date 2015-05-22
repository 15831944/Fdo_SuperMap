/* 
	\file UGRenderObject.h
	\brief ����Ⱦ����ĳ������ļ�
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/

#if !defined(AFX_UGRENDEROBJECT_H__618529B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_)
#define AFX_UGRENDEROBJECT_H__618529B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_


#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderOperation.h"
#include "Scene/UGVector3R.h"
#include "Scene/UGMatrix4d.h"
#include "Scene/UGBoundingBox.h"
#include "Scene/UGColorValue.h"
#include "Scene/UGLight.h"
#include "Scene/UGQuaternion4d.h"

namespace UGC 
{

//! \brief ����Ⱦ����ĳ�����
//! \remarks ��װ�˿���Ⱦ����Ĺ����ӿ�
class SCENE_API UGRenderObject  
{

public:
	//! \brief ���캯��
	UGRenderObject();
	//! \brief ��������
	virtual ~UGRenderObject();

public:
	
	
	//! \brief ���캯��
	UGRenderObject(const UGString& strName);
	//! \brief ���ÿ���Ⱦ��������Ʊ�־
	// ����ֻ��UGMovableObject��ӵ�и�����
	// ����ο�OGRE���÷���ȥ��Renderable��Name����
	void SetName(const UGString& strName);
	//! \brief ��ÿ���Ⱦ��������Ʊ�־
	UGString GetName();
	//! \brief ���ÿ���Ⱦ�����Ƿ�ɼ�
	void EnableShow(UGbool bShow);
	//! \brief �жϿ���Ⱦ�����Ƿ�ɼ�
	UGbool IsVisible();
	//! \brief ���ÿ���Ⱦ�����͸����
	void SetOpacity(UGfloat dOpacity);
	//! \brief ��ÿ���Ⱦ�����͸����
	UGfloat GetOpacity();
	//! \brief �жϿ���Ⱦ�����Ƿ��ʼ��
	UGbool  IsInitialized();
	
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
	//! \brief ���ÿ���Ⱦ�������ɫ
	void SetColor(const UGColorValue& color);	
	//! \brief �õ�����Ⱦ����İ�Χ��
	UGBoundingBox& GetBoundingBox();
	void SetBoundingBox(const UGBoundingBox& boundingBox);
	//! \brief ���ÿ���Ⱦ����ĵ�ǰ���	
// 	UGCameraBase*  GetActiveCamera();

	virtual void Release();
	//! \brief ��Ⱦ����ĳ�ʼ���ӿ�
	virtual void Initialize();
	//! \brief ��Ⱦ����ĸ��½ӿ�
	virtual void Update();
	//! \brief ��Ⱦ�������Ⱦ�ӿ�
	virtual void Render();

	UGMatrix4d& GetRotateMatrix();
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);
	
	// copy ogre functions to our system
	virtual UGMaterial* GetMaterial(void) const;
	virtual UGRenderOperation *GetRenderOperation();
	virtual void GetWorldTransforms(UGMatrix4d* xform) const;	
	virtual UGQuaternion4d GetWorldOrientation(void) const;
	virtual UGVector3R GetWorldPosition(void) const;
	virtual UGReal GetSquaredViewDepth(const UGCameraBase* cam) const;
	virtual UGLightList GetLights(void) const;

	virtual UGushort GetNumWorldTransforms(void) const { return 1; }
	virtual UGbool UseIdentityProjection(void) const { return false; }
	virtual UGbool UseIdentityView(void) const { return false; }
	virtual UGbool GetNormaliseNormals(void) const { return false; }
	virtual void SetPolygonModeOverrideable(UGbool override);
	virtual UGbool GetPolygonModeOverrideable(void) const;

	virtual UGMatrix4d GetModelViewMatrix() {return UGMatrix4d::IDENTITY;}
	virtual UGbool InterSectWithRadial(const UGVector3R& nearPos, const UGVector3R& farPos){return false;}
	virtual void SetPickStatus(UGbool status);
	virtual UGbool GetPickStatus();

protected:
	
	UGbool m_bPolygonModeOverrideable;
	//! \brief �����Ա
	UGCameraBase* m_pActiveCamera;
	//! \brief ��Ⱦ��Ա
	UGRenderOperation m_RenderOperation;
	//! \brief �жϿɼ��Գ�Ա
	UGbool m_bVisible;

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
	//! \brief malq-2007-11-19 ��Ĵ�С�����ߵĴ�ϸ
	UGfloat m_fSize;

	// �����Ƿ�ѡ��,trueѡ�У�false��ѡ��
	UGbool m_bPicked;
};

}
#endif // !defined(AFX_UGRENDEROBJECT_H__618529B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_)
