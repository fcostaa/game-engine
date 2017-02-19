//
// Created by Felipe Costa on 4/22/16.
//

#include "BaseActor.h"

BaseActor::BaseActor(ActorType actorType, boost::shared_ptr<ActorParams> params) : m_ActorType(actorType) {
    m_Params = params;
}

void BaseActor::VSetID(ActorId id) {
    m_Params->m_Id = id;
}

Vec2 const BaseActor::VGetPosition() {
    return m_Params->m_Position;
}

const Vec2 BaseActor::VGetVelocity() {
    return m_Params->m_Velocity;
}

void BaseActor::VSetPosition(Vec2 newPosition) {
    m_Params->m_Position = newPosition;
}

void BaseActor::VSetVelocity(Vec2 newVelocity) {
    m_Params->m_Velocity= newVelocity;
}

ActorId BaseActor::VGetID() {
    return *(m_Params->m_Id);
}

const ActorType BaseActor::VGetType() {
    return m_ActorType;
}

boost::shared_ptr<ActorParams> BaseActor::VGetParams() {
    return m_Params;
}
