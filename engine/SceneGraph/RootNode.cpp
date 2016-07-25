//
// Created by Felipe Costa on 4/22/16.
//

#include "RootNode.h"

RootNode::RootNode() : SceneNode(optional_empty(), "Root") {

}

bool RootNode::VAddChild(boost::shared_ptr<ISceneNode> kid) {
    return SceneNode::VAddChild(kid);
}

bool RootNode::VRemoveChild(ActorId id) {
    return SceneNode::VRemoveChild(id);
}

void RootNode::VRenderChildren(Scene *pScene) {
    SceneNode::VRenderChildren(pScene);
}

void RootNode::VOnUpdate(Scene *scene, double elapsedTime) {
    SceneNode::VOnUpdate(scene, elapsedTime);
}

bool RootNode::VIsVisible(Scene *pScene) const {
    return SceneNode::VIsVisible(pScene);
}
