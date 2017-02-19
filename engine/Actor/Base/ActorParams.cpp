//
// Created by Felipe Costa on 4/22/16.
//

#include "ActorParams.h"

ActorParams::ActorParams() {
    m_Size = sizeof(ActorParams);
}

ActorParams::~ActorParams() {

}

ActorParams::ActorParams(const ActorParams &actorParams) {
    m_Id = actorParams.m_Id;
    m_Position = actorParams.m_Position;
    m_Velocity = actorParams.m_Velocity;
    m_Radius = actorParams.m_Radius;
    m_Size = sizeof(ActorParams);
}

boost::shared_ptr<IActor> ActorParams::VCreate(BaseGameLogic *logic) {
    return boost::shared_ptr<IActor>();
}

boost::shared_ptr<ISceneNode> ActorParams::VCreateSceneNode(boost::shared_ptr<Scene> pScene) {
    return boost::shared_ptr<SceneNode>();
}
