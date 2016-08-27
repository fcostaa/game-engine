//
// Created by Felipe Costa on 8/24/16.
//

#include "EvtData_Move_Actor.h"

const EventType EvtData_Move_Actor::sk_EventType("move_actor");

EvtData_Move_Actor::EvtData_Move_Actor(ActorId actorId, int posX, int poxY) : actorId(actorId),
                                                                              posX(posX),
                                                                              poxY(poxY) { }

IEventDataPtr EvtData_Move_Actor::VCopy() const {
    return IEventDataPtr(NEW EvtData_Move_Actor(actorId, posX, poxY));
}

const EventType &EvtData_Move_Actor::VGetEventType() const {
    return sk_EventType;
}
