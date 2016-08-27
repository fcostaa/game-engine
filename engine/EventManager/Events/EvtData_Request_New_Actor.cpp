//
// Created by Felipe Costa on 7/24/16.
//

#include "EvtData_Request_New_Actor.h"
#include "EvtData_New_Actor.h"

const EventType EvtData_Request_New_Actor::sk_EventType( "request_new_actor" );

EvtData_Request_New_Actor::EvtData_Request_New_Actor(const ActorParams *pCreateParams) : m_pActorParams(NULL) {
    m_pActorParams = reinterpret_cast<ActorParams *>(NEW char[pCreateParams->m_Size]);
    memcpy(m_pActorParams, pCreateParams, pCreateParams->m_Size);
//    m_pActorParams = NEW ActorParams(*pCreateParams);
}

EvtData_Request_New_Actor::~EvtData_Request_New_Actor() {
    SAFE_DELETE(m_pActorParams);
}

IEventDataPtr EvtData_Request_New_Actor::VCopy() const {
    return boost::shared_ptr<IEventData>();
}

const EventType &EvtData_Request_New_Actor::VGetEventType() const {
    return EvtData_Request_New_Actor::sk_EventType;
}
