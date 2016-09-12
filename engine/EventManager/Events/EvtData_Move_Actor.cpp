//
// Created by Felipe Costa on 8/24/16.
//

#include "EvtData_Move_Actor.h"

const EventType EvtData_Move_Actor::sk_EventType("move_actor");

EvtData_Move_Actor::EvtData_Move_Actor(ActorId actorId, Vec2 position) : actorId(actorId),
                                                                         position(position) {
}

IEventDataPtr EvtData_Move_Actor::VCopy() const {
    return IEventDataPtr(NEW EvtData_Move_Actor(actorId, position));
}

const EventType &EvtData_Move_Actor::VGetEventType() const {
    return sk_EventType;
}
