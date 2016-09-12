//
// Created by Felipe Costa on 7/23/16.
//

#include "EvtData_New_Actor.h"

const EventType EvtData_New_Actor::sk_EventType("new_actor");

EvtData_New_Actor::EvtData_New_Actor(ActorId id, ActorParams *pCreateParams) {
    m_id = id;
    m_pActorParams = reinterpret_cast<ActorParams *>(NEW char[pCreateParams->m_Size]);
    memcpy(m_pActorParams, pCreateParams, pCreateParams->m_Size);
    m_pActorParams->m_Id = id;
}

EvtData_New_Actor::~EvtData_New_Actor() {
    SAFE_DELETE(m_pActorParams);
}

const EventType &EvtData_New_Actor::VGetEventType() const {
    return sk_EventType;
}

IEventDataPtr EvtData_New_Actor::VCopy() const {
    return IEventDataPtr(NEW EvtData_New_Actor(m_id, m_pActorParams));
}
