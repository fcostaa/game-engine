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
#include "../../engine/Actor/CircleObjectParams.h"


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

    CircleObjectParams playerParams;
    playerParams.m_ViewId = playersView->VGetId();
    playerParams.m_Type = AT_Player;
    playerParams.m_Pos = Vec2(display_width - 64, display_height - 64);
    playerParams.m_Radius = 32.0f;

    const EvtData_Request_New_Actor testObjEvt(&playerParams);
    safeTriggerEvent(testObjEvt);

    srand((unsigned int) time(NULL));

    for (int i = 0; i < 7; ++i) {
        boost::shared_ptr<IGameView> gameView(NEW AIView());
        addGameView(gameView);

        CircleObjectParams spriteObjectParams;
        spriteObjectParams.m_ViewId = gameView->VGetId();
        spriteObjectParams.m_Type = AT_Circle;

        float radius = 32.0f;
        float x = rand() % display_width;

        x = (x + radius >= display_width) ? x - (radius + 1) : x;
        x = (x - radius <= 0) ? x + (radius + 1) : x;

        spriteObjectParams.m_Radius = radius;
        spriteObjectParams.m_Pos = Vec2(x, radius);
        const EvtData_Request_New_Actor requestActor(&spriteObjectParams);
        safeTriggerEvent(requestActor);
    }
}
