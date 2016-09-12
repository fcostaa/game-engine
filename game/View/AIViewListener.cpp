//
// Created by Felipe Costa on 8/27/16.
//

#include "AIViewListener.h"
#include "../../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../../engine/SceneGraph/SpriteNode.h"
#include "AIView.h"
#include "../../engine/EventManager/Events/EvtData_New_Game.h"

AIViewListener::AIViewListener(AIView *view) : m_pView(view) {

}

char const *AIViewListener::GetName() {
    return "AIViewListener";
}

bool AIViewListener::HandleEvent(IEventData const &event) {
    EventType eventType = event.VGetEventType();

    if (eventType == EvtData_New_Game::sk_EventType) {
         std::cout << "New Game Event" << std::endl;
        return true;
    } else if (eventType == EvtData_New_Actor::sk_EventType) {
        const EvtData_New_Actor &ed = static_cast< const EvtData_New_Actor & >( event );

        SpriteObjectParams *p = static_cast<SpriteObjectParams *>(ed.m_pActorParams);
        if (p->m_ViewId == m_pView->m_ViewId) {
            m_pView->m_PlayerActorId = p->m_Id;
        }
    }

    return false;
}
