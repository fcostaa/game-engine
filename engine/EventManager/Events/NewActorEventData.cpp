//
// Created by Felipe Costa on 7/24/16.
//

#include "NewActorEventData.h"
#include "../../../game/Events/EvtData_New_Actor.h"


NewActorEventData::NewActorEventData(const ActorParams *pCreateParams) : m_pActorParams(NULL) {
    m_pActorParams = reinterpret_cast<ActorParams *>(NEW char[pCreateParams->m_Size]);
    memcpy(m_pActorParams, pCreateParams, pCreateParams->m_Size);
//    m_pActorParams = NEW ActorParams(*pCreateParams);
}

NewActorEventData::~NewActorEventData() {
    SAFE_DELETE(m_pActorParams);
}

IEventDataPtr NewActorEventData::VCopy() const {
    return boost::shared_ptr<IEventData>();
}

const EventType &NewActorEventData::VGetEventType() const {
    return EvtData_New_Actor::sk_EventType;
}
