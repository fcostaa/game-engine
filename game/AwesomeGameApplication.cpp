//
// Created by Felipe Costa on 4/21/16.
//

#include <iosfwd>
#include "AwesomeGameApplication.h"
#include "AwesomeHumanView.h"
#include "AwesomeGameLogic.h"
#include "Events/EvtData_New_Game.h"
#include "Events/EvtData_New_Actor.h"

bool AwesomeGameApplication::loadGame() {
    return mGameLogic->VLoadGame();
}

std::string *AwesomeGameApplication::getGameTitle() {
    std::string *title = NEW std::string("Cross Platform engine");
    return title;
}

BaseGameLogic *AwesomeGameApplication::createGameAndView() {
    BaseGameLogic *game = NEW AwesomeGameLogic();

    boost::shared_ptr<IGameView> playersView(new AwesomeHumanView());
    game->addGameView(playersView);

    return game;
}

bool AwesomeGameApplication::RegisterBaseGameEvents() {
    bool isSuperRegister = GameApplication::RegisterBaseGameEvents();
    if (isSuperRegister) {
        mEventManager->RegisterEvent<EvtData_New_Game>(EvtData_New_Game::sk_EventType);
        mEventManager->RegisterEvent<EvtData_New_Actor>(EvtData_New_Actor::sk_EventType);
    }
    return isSuperRegister;
}

//void AwesomeGameApplication::RegisterGameSpecificEvents() {
//    mEventManager->RegisterEvent<EvtData_New_Game>(EvtData_New_Game::sk_EventType);
////    mEventManager->RegisterEvent< NewActorEventData >( NewActorEventData::sk_EventType );
//}
