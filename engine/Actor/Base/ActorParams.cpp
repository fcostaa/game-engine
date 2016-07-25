//
// Created by Felipe Costa on 4/22/16.
//

#include "ActorParams.h"

ActorParams::ActorParams() {
    m_Size = sizeof(ActorParams);
}

ActorParams::~ActorParams() {

}

ActorParams::ActorParams(const ActorParams &actorParams) : ActorParams() {
    m_Id = actorParams.m_Id;
}

boost::shared_ptr<IActor> ActorParams::VCreate(BaseGameLogic *logic) {
    return boost::shared_ptr<IActor>();
}

boost::shared_ptr<SceneNode> ActorParams::VCreateSceneNode(boost::shared_ptr<Scene> pScene) {
    return boost::shared_ptr<SceneNode>();
}
