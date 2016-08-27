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
        m_Root->VRender(this);
        m_Root->VRenderChildren(this);
    }
}

void Scene::OnUpdate(const double elapsedTime) {
    m_Root->VOnUpdate(this, elapsedTime);
}

bool Scene::AddChild(optional<ActorId> id, boost::shared_ptr<ISceneNode> kid) {
    if (id.valid()) {
        // This allows us to search for this later based on actor id
        m_ActorMap[*id] = kid;
    }
    return m_Root->VAddChild(kid);
}


bool Scene::RemoveChild(ActorId id) {
    m_ActorMap.erase(id);
    return m_Root->VRemoveChild(id);
}

boost::shared_ptr<ISceneNode> Scene::FindActor(ActorId id) {
    SceneActorMap::iterator i = m_ActorMap.find(id);
    if (i == m_ActorMap.end()) {
        boost::shared_ptr<ISceneNode> nullISceneNode;
        return nullISceneNode;
    }

    return (*i).second;
}
