//
// Created by Felipe Costa on 8/27/16.
//

#include "EvtData_Mouse_Move.h"

const EventType EvtData_Mouse_Move::sk_EventType("mouse_move");

IEventDataPtr EvtData_Mouse_Move::VCopy() const {
    return IEventDataPtr(NEW EvtData_Mouse_Move(mouseDx, mouseDy));
}

const EventType &EvtData_Mouse_Move::VGetEventType() const {
    return EvtData_Mouse_Move::sk_EventType;
}

EvtData_Mouse_Move::EvtData_Mouse_Move(int mouseDx, int mouseDy) : mouseDx(mouseDx), mouseDy(mouseDy) {

}
