//
// Created by Felipe Costa on 8/27/16.
//

#include "AIView.h"
#include "../../engine/EventManager/IEventManager.h"
#include "AIViewListener.h"
#include "../../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../../engine/EventManager/Events/EvtData_Move_Actor.h"

AIView::AIView() : velocity(Vec2()) {
    EventListenerPtr listener(NEW AIViewListener(this));
    safeAddListener(listener, EvtData_New_Actor::sk_EventType);

    int sinal1, sinal2;
    if ((rand() % 2) % 2 == 0) {
        sinal1 = 1;
    } else sinal1 = -1;

    sinal2 = 1;
    velocity = Vec2(sinal1 * 2 * (rand() / (float) RAND_MAX), sinal2 * 2 * (rand() / (float) RAND_MAX));
}

AIView::~AIView() {

}

void AIView::onUpdate(double elapsedTime) {
    if (m_PlayerActorId.valid()) {
        boost::shared_ptr<IActor> actor = gameApplication->getGameLogic()->VGetActor((*m_PlayerActorId));

        float newX = actor->VGetPosition().getX() + velocity.getX();
        float newY = actor->VGetPosition().getY() + velocity.getY();

        int display_height = al_get_display_height(al_get_current_display());
        int display_width = al_get_display_width(al_get_current_display());

        if ((newX + 32.0f >= display_width) || (newX - 32.0f <= 0)) {
            velocity = Vec2(-velocity.getX(), velocity.getY());
        }

        if ((newY + 32.0f >= display_height) || (newY - 32.0f <= 0)) {
            velocity = Vec2(velocity.getX(), -velocity.getY());
        }

        Vec2 newPositon = Vec2(newX, newY);
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
