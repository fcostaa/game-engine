//
// Created by Felipe Costa on 4/24/16.
//

#include "DriftsGameLogic.h"
#include "DriftsEventListener.h"
#include "../../engine/EventManager/Events/EvtData_New_Game.h"
#include "../../engine/EventManager/Events/EvtData_Request_New_Actor.h"
#include "../../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../View/DriftsHumanView.h"
#include "../View/AIView.h"
#include "../../engine/EventManager/Events/EvtData_Move_Actor.h"
#include "../../engine/Actor/SpriteObjectParams.h"


DriftsGameLogic::DriftsGameLogic() : BaseGameLogic() {
    m_awesomeGameViewListener = boost::shared_ptr<AwesomeEventListener>(NEW AwesomeEventListener(this));
    safeAddListener(m_awesomeGameViewListener, EvtData_New_Game::sk_EventType);
    safeAddListener(m_awesomeGameViewListener, EvtData_Request_New_Actor::sk_EventType);
    safeAddListener(m_awesomeGameViewListener, EvtData_New_Actor::sk_EventType);
    safeAddListener(m_awesomeGameViewListener, EvtData_Move_Actor::sk_EventType);
}

DriftsGameLogic::~DriftsGameLogic() {

}

void DriftsGameLogic::VBuildInitialScene() {
    boost::shared_ptr<IGameView> playersView(new DriftsHumanView());
    addGameView(playersView);

    int display_height = al_get_display_height(al_get_current_display());
    int display_width = al_get_display_width(al_get_current_display());

    SpriteObjectParams playerParams;
    playerParams.m_ViewId = playersView->VGetId();
    playerParams.m_Pos = Vec2(display_width - 64, display_height - 64);
    playerParams.m_Radius = 32.0f;

    const EvtData_Request_New_Actor testObjEvt(&playerParams);
    safeTriggerEvent(testObjEvt);

    boost::shared_ptr<IGameView> gameView(NEW AIView());
    addGameView(gameView);

    SpriteObjectParams spriteObjectParams;
    spriteObjectParams.m_ViewId = gameView->VGetId();
    spriteObjectParams.m_Pos = Vec2(display_width / 2, 0);
    spriteObjectParams.m_Radius = 32.0f;
    const EvtData_Request_New_Actor requestActor(&spriteObjectParams);
    safeTriggerEvent(requestActor);
}
