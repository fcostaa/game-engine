//
// Created by Felipe Costa on 4/22/16.
//

#include "BaseActor.h"

BaseActor::BaseActor(boost::shared_ptr<ActorParams> params) {
    m_Params = params;
}


void BaseActor::VOnUpdate(int deltaMilliseconds) {
// Nothing
}

void BaseActor::VSetID(ActorId id) {
    m_id = id;
}

Vec2 const BaseActor::VGetPosition() {
    return position;
}

void BaseActor::VSetPosition(Vec2 newPosition) {
    position = newPosition;
//    std::cout << "VSetPosition: " << position.getX() << " and: "
//    << position.getY() << std::endl;
}

ActorId BaseActor::VGetID() {
    return m_id;
}

boost::shared_ptr<ActorParams> BaseActor::VGetParams() {
    return m_Params;
}
