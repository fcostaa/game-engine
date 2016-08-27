//
// Created by Felipe Costa on 7/24/16.
//

#ifndef CROSSENGINEDESKTOP_EVTDATA_REQUEST_NEW_ACTOR_H
#define CROSSENGINEDESKTOP_EVTDATA_REQUEST_NEW_ACTOR_H

#include "BaseEventData.h"
#include "../../Actor/Base/ActorParams.h"

struct EvtData_Request_New_Actor : public BaseEventData {

    static const EventType sk_EventType;

    ActorParams *m_pActorParams;

    explicit EvtData_Request_New_Actor(const ActorParams *pCreateParams);

    virtual ~EvtData_Request_New_Actor();

    virtual IEventDataPtr VCopy() const;

    virtual const EventType &VGetEventType() const;
};


#endif //CROSSENGINEDESKTOP_EVTDATA_REQUEST_NEW_ACTOR_H
