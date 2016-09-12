//
// Created by Felipe Costa on 8/24/16.
//

#ifndef CROSSENGINEDESKTOP_EVTDATA_MOVE_ACTOR_H
#define CROSSENGINEDESKTOP_EVTDATA_MOVE_ACTOR_H


#include "BaseEventData.h"
#include "../../Interfaces.h"

struct EvtData_Move_Actor : public BaseEventData {

    static const EventType sk_EventType;

    ActorId actorId;

    Vec2 position;

    EvtData_Move_Actor(ActorId actorId, Vec2 position);

    virtual IEventDataPtr VCopy() const;

    virtual const EventType &VGetEventType() const;
};


#endif //CROSSENGINEDESKTOP_EVTDATA_MOVE_ACTOR_H
