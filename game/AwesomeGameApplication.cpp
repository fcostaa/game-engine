//
// Created by Felipe Costa on 4/21/16.
//

#include <iosfwd>
#include "AwesomeGameApplication.h"
#include "../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../engine/EventManager/Events/EvtData_New_Game.h"
#include "../engine/EventManager/Events/EvtData_Move_Actor.h"
#include "../engine/EventManager/Events/EvtData_Keyboard_key_Down.h"
#include "../engine/EventManager/Events/EvtData_Request_New_Actor.h"
#include "../engine/EventManager/Events/EvtData_Mouse_Move.h"
#include "Logic/AwesomeGameLogic.h"
#include "View/AwesomeHumanView.h"

bool AwesomeGameApplication::loadGame() {
    return mGameLogic->VLoadGame();
}

std::string *AwesomeGameApplication::getGameTitle() {
    std::string *title = NEW std::string("Cross Platform engine");
    return title;
}

BaseGameLogic *AwesomeGameApplication::createGameAndView() {
    BaseGameLogic *game = NEW AwesomeGameLogic();
    return game;
}

bool AwesomeGameApplication::RegisterBaseGameEvents() {
    bool isSuperRegister = GameApplication::RegisterBaseGameEvents();
    if (isSuperRegister) {
        mEventManager->RegisterEvent<EvtData_New_Game>(EvtData_New_Game::sk_EventType);
        mEventManager->RegisterEvent<EvtData_New_Actor>(EvtData_New_Actor::sk_EventType);
        mEventManager->RegisterEvent<EvtData_New_Actor>(EvtData_Keyboard_key_Down::sk_EventType);
        mEventManager->RegisterEvent<EvtData_New_Actor>(EvtData_Mouse_Move::sk_EventType);
        mEventManager->RegisterEvent<EvtData_Request_New_Actor>(EvtData_Request_New_Actor::sk_EventType);
        mEventManager->RegisterEvent<EvtData_New_Actor>(EvtData_Move_Actor::sk_EventType);
    }
    return isSuperRegister;
}
