//
// Created by Felipe Costa on 8/27/16.
//

#include "AIView.h"
#include "../../engine/EventManager/IEventManager.h"
#include "AIViewListener.h"
#include "../../engine/EventManager/Events/EvtData_New_Actor.h"


AIView::AIView() {
    EventListenerPtr listener(NEW AIViewListener(this));
    safeAddListener(listener, EvtData_New_Actor::sk_EventType);
}

AIView::~AIView() {

}

void AIView::onUpdate(double elapsedTime) {

}

void AIView::onRender(double elapsedTime) {

}

GameViewId AIView::VGetId() const {
    return m_ViewId;
}

void AIView::VOnAttach(GameViewId vid, optional<ActorId> aid) {
    m_ViewId = vid;
    m_PlayerActorId = aid;
}
