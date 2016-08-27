//
// Created by Felipe Costa on 8/23/16.
//

#include "EvtData_Keyboard_key_Down.h"

const EventType EvtData_Keyboard_key_Down::sk_EventType("key_down");

EvtData_Keyboard_key_Down::EvtData_Keyboard_key_Down(int keyCode) : keyCode(keyCode) {
}

IEventDataPtr EvtData_Keyboard_key_Down::VCopy() const {
    return IEventDataPtr(NEW EvtData_Keyboard_key_Down(keyCode));
}

const EventType &EvtData_Keyboard_key_Down::VGetEventType() const {
    return sk_EventType;
}
