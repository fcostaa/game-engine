//
// Created by Felipe Costa on 4/21/16.
//

#include <iostream>
#include "AwesomeHumanView.h"
#include "../engine/EventManager/IEventManager.h"
#include "Events/EvtData_New_Game.h"
#include "Events/EvtData_New_Actor.h"


AwesomeHumanView::AwesomeHumanView() {
    m_pScene.reset(NEW ScreenElementScene());

    EventListenerPtr listener(NEW AwesomeGameViewListener(this));

    safeAddListener(listener, EvtData_New_Game::sk_EventType);
    safeAddListener(listener, EvtData_New_Actor::sk_EventType);
}

AwesomeHumanView::~AwesomeHumanView() {

}


void AwesomeHumanView::BuildInitialScene() {
    VPushElement(m_pScene);
}

void AwesomeHumanView::onUpdate(double elapsedTime) {
    HumanView::onUpdate(elapsedTime);

    std::cout << "Hello World Update with time: " << &time << std::endl;
}

void AwesomeHumanView::onRender(const Time &time) {
    HumanView::onRender(time);

    std::cout << "Hello World Render" << std::endl;
}

void AwesomeHumanView::VOnAttach(GameViewId vid, optional<ActorId> aid) {
    HumanView::VOnAttach(vid, aid);
    BuildInitialScene();
}
