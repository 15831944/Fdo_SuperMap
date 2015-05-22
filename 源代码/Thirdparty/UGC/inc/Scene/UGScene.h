/* 
	\file UGScene.h
	\brief �ļ����ݵļ�Ҫ������
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>����˵������</b>
	<em>1����һ��˵����</em>
	<em>2���ڶ���˵����</em>
*/
#if !defined(AFX_UGSCENE_H__0863518E_8AEE_4702_8105_7D7A51E4C276__INCLUDED_)
#define AFX_UGSCENE_H__0863518E_8AEE_4702_8105_7D7A51E4C276__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGSceneSetting.h"
#include "Scene/UGVectorDatasetAtr.h"
#include "Scene/UGRenderable.h"
#include "Scene/UGRenderSys.h"
#include "Base/UGThread.h"
#include "Scene/UG3DLayers.h"
#include "Scene/UGRenderObjectList.h"


namespace UGC 
{
//! \brief MeasureDistanceFunc �¼��ص�����
extern "C" typedef UGdouble (*MeasureDistanceFunc)(const UGPoint2D &pntFrom,const UGPoint2D& pntTo,UGdouble dRadius);

//! \brief ������
//! \remarks ��ע��Ϣ��
class SCENE_API UGScene
{
public:
	UGScene();
	//! \brief ���캯��
	UGScene(const UGString& name);
	//! \brief ��������
	virtual ~UGScene();
	//! \brief ��ʼ��
	//void Initialize();
	//! \brief ���º���
	void UpdateData();
	//! \brief ��Ⱦ����
	//void Render();
	//! \brief ��Ⱦ����
	void RenderScene(UGViewport *pVP, UGbool bIncludeOverlays);
	//! \brief �����ӿ�
	virtual void SetViewport(UGViewport *vp);
	//! \brief �ͷų���
	void Release();
	//! \brief ����ĳ������Ⱦ�����Ƿ�ɼ�
	void SetLayerHide(UGString strName, UGbool bShow);
	//! \brief �õ�ĳ������Ⱦ�����Ƿ��
	UGbool IsLayerHide(UGString strName);
	//! \brief �õ����λ�ȡ��
	UGTerrainAccessor* GetTerrainAccessor();
	//! \brief ���õ��λ�ȡ��
	void SetTerrainAccessor(UGTerrainAccessor* pTerrainAccessor);
	//! \brief �ȴ���Ⱦ
	static void  WaitForRender(UGulong& dBeiginClock);
	//! \brief ���ù�Դλ��
	void SetLightPos(UGReal dLon,UGReal dLat,UGReal dHeight,UGbool bMoveLight);
	//! \brief �ͷ��������
	void DestroyAllCameras();
	//! \brief ����һ�����
	UGMomentumCamera *CreateCamera(const UGString& Name);
	//! \brief �õ�һ�����
	UGMomentumCamera *GetCamera(const UGString& name);
	//! \brief ����ʹ�õ���Ⱦ����
	void SetDestRenderSys(UGRenderSys *pRenderSys);
	//! \brief �õ�ʹ�õ���Ⱦ����
	UGRenderSys* GetDestRenderSys();
	//! \brief ���õ�ǰ�����
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);
	//! \brief ��Scene��������ݼ�
	void AddDataset(const UGVectorDatasetAtr& DatasetAtr);
	//! \brief �õ������е�ĳ�����ݼ�
	UGbool GetDataset(const UGString& strName,UGVectorDatasetAtr& atr);
	//! \brief �Ƴ������е�ĳ�����ݼ�
	void RemoveDataset(const UGString& strName);
	UGRenderObject *AddDataset(const UGString& strSgdFile);

public:
	//! \brief �������Բ���
	static UGSceneSetting ms_SceneSetting;
	//! \brief ��Ⱦ��־����
	static UGbool       ms_bRendering;
	//! \brief ���߱�־
	static UGdouble     ms_dSleepTime;
	//! \brief ������Ⱦ��־
	static UGbool ms_bSceneRenderAllow;
	//! \brief ������±�־
	static UGbool ms_bSceneUpdateAllow;
	//! \brief �ж��Ƿ���Ҫ����
	static UGbool ms_bNeedRefresh;

protected:
	//! \brief ���������п���Ⱦ�����б�
//	UGRenderableObjectList m_RootList;
	//! \brief
	UGlong m_nLastElevationUpdate;
	//! \brief
	UGRenderSys *m_pDestRenderSystem;
	//! \brief ����б�
	typedef UGDict<UGString, UGMomentumCamera *> UGCameraBaseMap;
	//! \brief
	UGCameraBaseMap m_CameraBaseMap;

	// �����ж��ǲ��Ǹı��ˣ������Щû�иı�Ͳ����ػ���������
	UGMatrix4d m_OldProjectionMatrix; 
	UGMatrix4d m_OldViewMatrix;
	UGMatrix4d m_OldWorldMatrix;

	// �����߳��л�,������ʾ����
	// ����ʹ�����ٽ�����ʵ�ֽ���ͬ��
	UGMutex m_Mutex;

// ����ο�OGRE������Ժͷ���
protected:
	UGString m_strName;
	UGColorValue m_AmbientLight;
	typedef UGDict<UGString, UGSceneNode*> SceneNodeList;
	SceneNodeList m_SceneNodes;
	UGMomentumCamera* m_CameraInProgress;
	UGViewport* m_CurrentViewport;

	UGSceneNode* m_pSceneRoot;
	UGSceneNode* m_pLayerRootNode;

	UGRenderObjectList m_RenderObjectList;
	UGRenderObjectList m_RenderObjectListPlane;
	UGRenderObject* m_pSelectedRenderObject;


	typedef UGList<UGSceneNode*> AutoTrackingSceneNodes;
    AutoTrackingSceneNodes m_AutoTrackingSceneNodes;

	// Fog
    FogMode m_FogMode;
    UGColorValue m_FogColour;
    UGReal m_FogStart;
    UGReal m_FogEnd;
    UGReal m_FogDensity;
	
	
	typedef UGDict<UGString, UGMovableObject*> MovableObjectMap;
	typedef UGDict<UGString, MovableObjectMap*> MovableObjectCollectionMap;
	MovableObjectCollectionMap m_MovableObjectCollectionMap;

	UGbool m_bDisplayNodes;
	UGbool m_bFindVisibleObjects;



protected:
	// ʵ���岻�ܷŵ�cpp�ļ���
	// ����cpp�б��벻��ȥ����MovableObjectMap�Զ�����������
	// �����������ѯ��ʦ��MovableObjectMapǰҪ�������÷�
	// UGScene::MovableObjectMap���ܱ���ͨ��
	MovableObjectMap* GetMovableObjectMap(UGString typeName);


public:
	enum PrefabType 
	{
            PT_PLANE
    };
public:
	virtual UGbool HasCamera(const UGString& name) const;
	virtual void DestroyCamera(UGMomentumCamera* cam);
	virtual void DestroyCamera(const UGString& name);
	virtual UGLight* CreateLight(const UGString& name);
	virtual UGLight* GetLight(const UGString& name);
	virtual UGbool HasLight(const UGString& name) const;
	virtual void DestroyLight(const UGString& name);
	virtual void DestroyLight(UGLight* light);
	virtual void DestroyAllLights(void);
	virtual void PopulateLightList(const UGVector3R& position, UGReal radius, UGLightList& destList);
	virtual UGSceneNode* CreateSceneNode(void);
	virtual UGSceneNode* CreateSceneNode(const UGString& name);
	virtual void DestroySceneNode(const UGString& name);
	virtual UGSceneNode* GetRootSceneNode(void) const;
	virtual UGSceneNode* GetSceneNode(const UGString& name) const;
	virtual UGbool HasSceneNode(const UGString& name) const;
	virtual UGEntity*    CreateEntity(UGString entityName, UGString meshName);
	virtual UGEntity* CreateEntity(const UGString& entityName, PrefabType ptype);
	virtual UGEntity* GetEntity(const UGString& name);
	virtual UGbool HasEntity(const UGString& name) const;
	virtual void DestroyEntity(UGEntity* ent);
	virtual void DestroyEntity(const UGString& name);
	virtual void DestroyAllEntities(void);
	void SetAmbientLight(const UGColorValue& colour);
	UGColorValue GetAmbientLight(void) const;
	void SetFog(FogMode mode = FOG_NONE, const UGColorValue& colour = UGColorValue::White,
            UGReal expDensity = 0.001, UGReal linearStart = 0.0, UGReal linearEnd = 1.0);
	virtual FogMode GetFogMode(void) const;
	virtual const UGColorValue& GetFogColour(void) const;
	virtual UGReal GetFogStart(void) const;
	virtual UGReal GetFogEnd(void) const;
	virtual UGReal GetFogDensity(void) const;
	virtual void SetDisplaySceneNodes(UGbool display);
	virtual UGMovableObject* CreateMovableObject(UGString name, UGString typeName, 
												 NameValuePairList* params = 0);
	virtual void DestroyMovableObject(const UGString& name, const UGString& typeName);
	virtual void DestroyMovableObject(UGMovableObject* m);
	virtual void DestroyAllMovableObjectsByType(const UGString& typeName);
	virtual void DestroyAllMovableObjects(void);
	virtual UGMovableObject* GetMovableObject(const UGString& name, const UGString& typeName);
	virtual UGbool HasMovableObject(const UGString& name, const UGString& typeName) const;
	virtual void InjectMovableObject(UGMovableObject* m);
	virtual void ExtractMovableObject(const UGString& name, const UGString& typeName);
	virtual void ExtractMovableObject(UGMovableObject* m);
	virtual void ExtractAllMovableObjectsByType(const UGString& typeName);
	
	//! \brief ѡ��ģ��
	UGRenderObject* PickModelObjects(const UGint pointx, const UGint pointy, UGbool bPick = true);
	UGRenderObject* PickVectorObjects(const UGint pointx, const UGint pointy, UGbool bPick = true);
	virtual void AddSceneNode(UGSceneNode* node);

	UGRenderObjectList& GetRenderObjectList();
	UGRenderObjectList& GetRenderObjectListPlane();
	UGRenderObject *GetSelectedRenderObject();
	void SetSelectedRenderObjectNULL();


public:
	// ���ûص�����
	void SetMeasureDistanceFunc(MeasureDistanceFunc pFunc);
	
	// ִ�лص�����
	UGdouble RunMeasureDistanceFunc(UGPoint2D pntFrom,UGPoint2D pntTo,UGdouble dRadius = 6378137);
protected:
	MeasureDistanceFunc m_pFunc;


public:
	const UGString& GetName(void) const { return m_strName; }
	virtual UGbool GetDisplaySceneNodes(void) const {return m_bDisplayNodes;}
	virtual void SetFindVisibleObjects(UGbool find) { m_bFindVisibleObjects = find; }
	virtual UGbool GetFindVisibleObjects(void) { return m_bFindVisibleObjects; }
	UGViewport* GetCurrentViewport(void) { return m_CurrentViewport; }	

};

}
#endif // !defined(AFX_UGSCENE_H__0863518E_8AEE_4702_8105_7D7A51E4C276__INCLUDED_)
