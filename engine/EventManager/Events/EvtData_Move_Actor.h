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

    int posX;

    int poxY;

    EvtData_Move_Actor(ActorId actorId, int posX, int poxY);

    virtual IEventDataPtr VCopy() const;

    virtual const EventType &VGetEventType() const;
};


#endif //CROSSENGINEDESKTOP_EVTDATA_MOVE_ACTOR_H
