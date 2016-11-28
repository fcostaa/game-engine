//
// Created by Felipe Costa on 4/21/16.
//

#include <iosfwd>
#include "DriftsGameApplication.h"
#include "../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../engine/EventManager/Events/EvtData_New_Game.h"
#include "../engine/EventManager/Events/EvtData_Move_Actor.h"
#include "../engine/EventManager/Events/EvtData_Keyboard_key_Down.h"
#include "../engine/EventManager/Events/EvtData_Request_New_Actor.h"
#include "../engine/EventManager/Events/EvtData_Mouse_Move.h"
#include "Logic/DriftsGameLogic.h"
#include "View/DriftsHumanView.h"

bool DriftsGameApplication::loadGame() {
    return mGameLogic->VLoadGame();
}

std::string *DriftsGameApplication::getGameTitle() {
    std::string *title = NEW std::string("Drifts Game");
    return title;
}

BaseGameLogic *DriftsGameApplication::createGameAndView() {
    BaseGameLogic *game = NEW DriftsGameLogic();
    return game;
}

bool DriftsGameApplication::registerBaseGameEvents() {
    bool isSuperRegister = GameApplication::registerBaseGameEvents();
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
