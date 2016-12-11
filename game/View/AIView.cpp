//
// Created by Felipe Costa on 8/27/16.
//

#include "AIView.h"
#include "../../engine/EventManager/IEventManager.h"
#include "AIViewListener.h"
#include "../../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../../engine/EventManager/Events/EvtData_Move_Actor.h"
#include "../../engine/EventManager/Events/EvtData_New_Game.h"


AIView::AIView() {
    EventListenerPtr listener(NEW AIViewListener(this));
    safeAddListener(listener, EvtData_New_Actor::sk_EventType);
}

AIView::~AIView() {

}

void AIView::onUpdate(double elapsedTime) {
//    std::cout << "elapsedTime: " << elapsedTime << std::endl;
    if (m_PlayerActorId.valid()) {
        boost::shared_ptr<IActor> actor = gameApplication->getGameLogic()->VGetActor((*m_PlayerActorId));
        Vec2 newPositon = Vec2(actor->VGetPosition().getX(), actor->VGetPosition().getY() + 20.0f * (float) elapsedTime);
        safeQueEvent(IEventDataPtr(NEW EvtData_Move_Actor(*m_PlayerActorId, newPositon)));
    }
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
