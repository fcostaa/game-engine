//
// Created by Felipe Costa on 4/24/16.
//

#include "EvtData_New_Game.h"

const EventType EvtData_New_Game::sk_EventType("new_game");

EvtData_New_Game::EvtData_New_Game() {

}

const EventType &EvtData_New_Game::VGetEventType() const {
    return sk_EventType;
}

IEventDataPtr EvtData_New_Game::VCopy() const {
    return IEventDataPtr(NEW EvtData_New_Game());
}


