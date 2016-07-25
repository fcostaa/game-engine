//
// Created by Felipe Costa on 4/22/16.
//

#include "Scene.h"
#include "RootNode.h"

#include "../standards.h"

Scene::Scene() {
    m_Root.reset(NEW RootNode());
}

Scene::~Scene() {
    // Empty
}

void Scene::OnRender() {
    if (m_Root) {
        m_Root->VPreRender(this);
        m_Root->VRender(this);
        m_Root->VRenderChildren(this);
        m_Root->VPostRender(this);
    }
}

void Scene::OnUpdate(const int deltaMilliseconds) {

//    static DWORD lastTime = 0;
//    DWORD elapsedTime = 0;
//    DWORD now = timeGetTime();
//
//    if (!m_Root)
//        return S_OK;
//
//    if (lastTime == 0)
//    {
//        lastTime = now;
//    }
//
//    elapsedTime = now - lastTime;
//    lastTime = now;
//
//     m_Root->VOnUpdate(this, elapsedTime);
}


bool Scene::AddChild(optional<ActorId> id, boost::shared_ptr<ISceneNode> kid) {
    if (id.valid())
    {
        // This allows us to search for this later based on actor id
        m_ActorMap[*id] = kid;
    }
    return m_Root->VAddChild(kid);
}


bool Scene::RemoveChild(ActorId id) {
    m_ActorMap.erase(id);
    return m_Root->VRemoveChild(id);
}
