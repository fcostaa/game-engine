//
// Created by Felipe Costa on 7/23/16.
//

#ifndef CROSSENGINEDESKTOP_EVTDATA_NEW_ACTOR_H
#define CROSSENGINEDESKTOP_EVTDATA_NEW_ACTOR_H


#include "../../engine/EventManager/Events/BaseEventData.h"
#include "../../engine/Interfaces.h"

class EvtData_New_Actor : public BaseEventData {
public:
    static const EventType sk_EventType;

    virtual const EventType &VGetEventType() const;

    explicit EvtData_New_Actor( ActorId id, ActorParams *pCreateParams);

    virtual ~EvtData_New_Actor();

    virtual IEventDataPtr VCopy() const;

    ActorId m_id;	//ID of actor created
    ActorParams *m_pActorParams;	//Parameters for actor
};


#endif //CROSSENGINEDESKTOP_EVTDATA_NEW_ACTOR_H
