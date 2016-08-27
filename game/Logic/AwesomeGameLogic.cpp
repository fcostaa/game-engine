//
// Created by Felipe Costa on 4/24/16.
//

#include "AwesomeGameLogic.h"
#include "AwesomeEventListener.h"
#include "../../engine/EventManager/Events/EvtData_New_Game.h"
#include "../../engine/EventManager/Events/EvtData_Request_New_Actor.h"
#include "../../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../Actor/PlayerParams.h"
#include "../View/AwesomeHumanView.h"
#include "../View/AIView.h"


AwesomeGameLogic::AwesomeGameLogic() : BaseGameLogic() {
    m_awesomeGameViewListener = boost::shared_ptr<AwesomeEventListener>(NEW AwesomeEventListener(this));
    safeAddListener(m_awesomeGameViewListener, EvtData_New_Game::sk_EventType);
    safeAddListener(m_awesomeGameViewListener, EvtData_Request_New_Actor::sk_EventType);
    safeAddListener(m_awesomeGameViewListener, EvtData_New_Actor::sk_EventType);
}

AwesomeGameLogic::~AwesomeGameLogic() {

}


//bool AwesomeGameLogic::VLoadGame() {
//    VBuildInitialScene();
//    return true;
//}

void AwesomeGameLogic::VBuildInitialScene() {
    boost::shared_ptr<IGameView> playersView(new AwesomeHumanView());
    addGameView(playersView);

    PlayerParams playerParams;
    playerParams.m_ViewId = playersView->VGetId();
//    top.m_Type = AT_TestObject;
//    top.m_Color = g_Green;
//    top.m_Mat = Mat4x4::g_Identity;
//    top.m_Mat.SetPosition(Vec3(6.0f,0,18.0f));
    const EvtData_Request_New_Actor testObjEvt(&playerParams);
    safeTriggerEvent(testObjEvt);

    boost::shared_ptr<IGameView> gameView(NEW AIView());
    addGameView(gameView);

    SpriteObjectParams spriteObjectParams;
    spriteObjectParams.m_ViewId = gameView->VGetId();
    const EvtData_Request_New_Actor requestActor(&spriteObjectParams);
    safeTriggerEvent(requestActor);
}