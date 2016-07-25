//
// Created by Felipe Costa on 7/24/16.
//

#ifndef CROSSENGINEDESKTOP_EVTDATA_REQUEST_NEW_ACTOR_H
#define CROSSENGINEDESKTOP_EVTDATA_REQUEST_NEW_ACTOR_H

#include "BaseEventData.h"
#include "../../Actor/Base/ActorParams.h"

struct NewActorEventData : public BaseEventData {

    ActorParams *m_pActorParams;

    explicit NewActorEventData(const ActorParams *pCreateParams);

    virtual ~NewActorEventData();

    virtual IEventDataPtr VCopy() const;

    virtual const EventType &VGetEventType() const;
};


#endif //CROSSENGINEDESKTOP_EVTDATA_REQUEST_NEW_ACTOR_H
