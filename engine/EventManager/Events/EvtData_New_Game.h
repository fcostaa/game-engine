//
// Created by Felipe Costa on 4/24/16.
//

#ifndef CROSSENGINEDESKTOP_EVTDATA_NEW_GAME_H
#define CROSSENGINEDESKTOP_EVTDATA_NEW_GAME_H

#include "EmptyEventData.h"

class EvtData_New_Game : public EmptyEventData {
public:
    static const EventType sk_EventType;

    virtual const EventType &VGetEventType() const;

    EvtData_New_Game();

    virtual IEventDataPtr VCopy() const;
};

#endif //CROSSENGINEDESKTOP_EVTDATA_NEW_GAME_H
