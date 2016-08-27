//
// Created by Felipe Costa on 8/23/16.
//

#ifndef CROSSENGINEDESKTOP_EVTDATA_KEYBOARD_KEY_DOWN_H
#define CROSSENGINEDESKTOP_EVTDATA_KEYBOARD_KEY_DOWN_H

#include "BaseEventData.h"

class EvtData_Keyboard_key_Down : public BaseEventData {
public:
    static const EventType sk_EventType;

    virtual IEventDataPtr VCopy() const;

    virtual const EventType &VGetEventType() const;

    explicit EvtData_Keyboard_key_Down(int keyCode);

    int keyCode;
};

#endif //CROSSENGINEDESKTOP_EVTDATA_KEYBOARD_KEY_DOWN_H
