//
// Created by Felipe Costa on 4/21/16.
//

#include <iostream>
#include "DriftsHumanView.h"
#include "../../engine/EventManager/IEventManager.h"
#include "../../engine/EventManager/Events/EvtData_New_Game.h"
#include "../../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../../engine/EventManager/Events/EvtData_Keyboard_key_Down.h"
#include "../../engine/EventManager/Events/EvtData_Move_Actor.h"
#include "../../engine/EventManager/Events/EvtData_Request_New_Actor.h"
#include "../../engine/EventManager/Events/EvtData_Mouse_Move.h"
#include "../../engine/EventManager/IEventManager.h"
#include "../../engine/EventManager/Events/EvtData_New_Game.h"
#include "../../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../../engine/EventManager/Events/EvtData_Request_New_Actor.h"
#include "../../engine/EventManager/Events/EvtData_Mouse_Move.h"
#include "../../engine/EventManager/Events/EvtData_Keyboard_key_Down.h"
#include "../../engine/EventManager/Events/EvtData_Move_Actor.h"
#include "DriftsHUD.h"


DriftsHumanView::DriftsHumanView() {
    m_pScene.reset(NEW ScreenElementScene());

    EventListenerPtr listener(NEW DriftsGameViewListener(this));

    safeAddListener(listener, EvtData_New_Game::sk_EventType);
    safeAddListener(listener, EvtData_New_Actor::sk_EventType);
    safeAddListener(listener, EvtData_Request_New_Actor::sk_EventType);
    safeAddListener(listener, EvtData_Mouse_Move::sk_EventType);
    safeAddListener(listener, EvtData_Keyboard_key_Down::sk_EventType);
    safeAddListener(listener, EvtData_Move_Actor::sk_EventType);
}

DriftsHumanView::~DriftsHumanView() {

}

void DriftsHumanView::BuildInitialScene() {
    VPushElement(m_pScene);

    boost::shared_ptr<DriftsHUD> m_HUD;
    m_HUD.reset(NEW DriftsHUD());
    VPushElement(m_HUD);
}

void DriftsHumanView::onUpdate(double elapsedTime) {
    HumanView::onUpdate(elapsedTime);

    if (m_pController) {
        m_pController->OnUpdate(elapsedTime);
    }
}

void DriftsHumanView::onRender(double elapsedTime) {
    HumanView::onRender(elapsedTime);
}

void DriftsHumanView::VOnAttach(GameViewId vid, optional<ActorId> aid) {
    HumanView::VOnAttach(vid, aid);
    BuildInitialScene();
}

void DriftsHumanView::MoveActor(ActorId id, Vec2 position) {
    boost::shared_ptr<ISceneNode> node = m_pScene->FindActor(id);
    if (node) {
        node->VSetPosition(position);
    }
}
