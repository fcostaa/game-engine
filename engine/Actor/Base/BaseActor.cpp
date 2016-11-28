//
// Created by Felipe Costa on 4/22/16.
//

#include "BaseActor.h"

BaseActor::BaseActor(boost::shared_ptr<ActorParams> params) {
    m_Params = params;
}

void BaseActor::VSetID(ActorId id) {
    m_Params->m_Id = id;
}

Vec2 const BaseActor::VGetPosition() {
    return m_Params->m_Pos;
}

void BaseActor::VSetPosition(Vec2 newPosition) {
    m_Params->m_Pos = newPosition;
}

ActorId BaseActor::VGetID() {
    return *(m_Params->m_Id);
}

boost::shared_ptr<ActorParams> BaseActor::VGetParams() {
    return m_Params;
}
