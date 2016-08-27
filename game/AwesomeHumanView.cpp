//
// Created by Felipe Costa on 4/21/16.
//

#include <iostream>
#include "AwesomeHumanView.h"
#include "../engine/EventManager/IEventManager.h"
#include "../engine/EventManager/Events/EvtData_New_Game.h"
#include "../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../engine/EventManager/Events/EvtData_Keyboard_key_Down.h"
#include "../engine/EventManager/Events/EvtData_Move_Actor.h"
#include "../engine/EventManager/Events/EvtData_Request_New_Actor.h"
#include "../engine/EventManager/Events/EvtData_Mouse_Move.h"


AwesomeHumanView::AwesomeHumanView() {
    m_pScene.reset(NEW ScreenElementScene());

    EventListenerPtr listener(NEW AwesomeGameViewListener(this));

    safeAddListener(listener, EvtData_New_Game::sk_EventType);
    safeAddListener(listener, EvtData_New_Actor::sk_EventType);
    safeAddListener(listener, EvtData_Request_New_Actor::sk_EventType);
    safeAddListener(listener, EvtData_Mouse_Move::sk_EventType);
    safeAddListener(listener, EvtData_Keyboard_key_Down::sk_EventType);
    safeAddListener(listener, EvtData_Move_Actor::sk_EventType);
}

AwesomeHumanView::~AwesomeHumanView() {

}

void AwesomeHumanView::BuildInitialScene() {
    VPushElement(m_pScene);
}

void AwesomeHumanView::onUpdate(double elapsedTime) {
    HumanView::onUpdate(elapsedTime);

    if (m_pController) {
        m_pController->OnUpdate(elapsedTime);
    }
}

void AwesomeHumanView::onRender(double elapsedTime) {
    HumanView::onRender(elapsedTime);
}

void AwesomeHumanView::VOnAttach(GameViewId vid, optional<ActorId> aid) {
    HumanView::VOnAttach(vid, aid);
    BuildInitialScene();
}

void AwesomeHumanView::MoveActor(ActorId id, int posX, int posY) {
    boost::shared_ptr<ISceneNode> node = m_pScene->FindActor(id);
    if (node) {
        node->VTranslate(posX, posY);
    }
}
