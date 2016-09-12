//
// Created by Felipe Costa on 4/22/16.
//

#include "SceneNode.h"

SceneNode::SceneNode(optional<ActorId> actorId, std::string name, Vec2 position) {
    m_pParent = NULL;
    m_Props.m_ActorId = actorId;
    m_Props.m_Name = name;
    VSetPosition(position);
}

SceneNode::~SceneNode() {

}

const SceneNodeProperties *const SceneNode::VGet() const {
    return &m_Props;
}

void SceneNode::VOnUpdate(Scene *scene, double elapsedTime) {

    SceneNodeList::iterator i = m_Children.begin();
    SceneNodeList::iterator end = m_Children.end();

    while (i != end) {
        (*i)->VOnUpdate(scene, elapsedTime);
        i++;
    }
}

void SceneNode::VRender(Scene *pScene) {

}

bool SceneNode::VIsVisible(Scene *pScene) const {
    return true;
}

void SceneNode::VRenderChildren(Scene *pScene) {

    SceneNodeList::iterator i = m_Children.begin();
    SceneNodeList::iterator end = m_Children.end();

    for (; i != end; ++i) {
        if ((*i)->VIsVisible(pScene)) {
            (*i)->VRender(pScene);
        }
    }
}

bool SceneNode::VAddChild(boost::shared_ptr<ISceneNode> kid) {
    m_Children.push_back(kid);
    return true;
}

bool SceneNode::VRemoveChild(ActorId id) {
    for (SceneNodeList::iterator i = m_Children.begin(); i != m_Children.end(); ++i) {
        const SceneNodeProperties *pProps = (*i)->VGet();
        if (pProps->ActorId().valid() && id == *pProps->ActorId()) {
            i = m_Children.erase(i);    //this can be expensive for vectors
            return true;
        }
    }
    return false;
}

void SceneNode::VSetPosition(Vec2 position) {
    m_Props.position = position;
}
