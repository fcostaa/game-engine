//
// Created by Felipe Costa on 8/27/16.
//

#ifndef CROSSENGINEDESKTOP_EVTDATA_MOUSE_MOVE_H
#define CROSSENGINEDESKTOP_EVTDATA_MOUSE_MOVE_H


#include "BaseEventData.h"

class EvtData_Mouse_Move : public BaseEventData {

public:
    static const EventType sk_EventType;

    virtual IEventDataPtr VCopy() const;

    virtual const EventType &VGetEventType() const;

    explicit EvtData_Mouse_Move(int mouseDx, int mouseDy);

    int mouseDx;
    int mouseDy;

};


#endif //CROSSENGINEDESKTOP_EVTDATA_MOUSE_MOVE_H
