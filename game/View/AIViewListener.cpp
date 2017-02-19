//
// Created by Felipe Costa on 8/27/16.
//

#include "AIViewListener.h"
#include "../../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../../engine/SceneGraph/CircleNode.h"
#include "AIView.h"

AIViewListener::AIViewListener(AIView *view) : m_pView(view) {

}

char const *AIViewListener::GetName() {
    return "AIViewListener";
}

bool AIViewListener::HandleEvent(IEventData const &event) {
    EventType eventType = event.VGetEventType();

    if (eventType == EvtData_New_Actor::sk_EventType) {
        const EvtData_New_Actor &ed = static_cast< const EvtData_New_Actor & >( event );

        CircleObjectParams *p = static_cast<CircleObjectParams *>(ed.m_pActorParams);
        if (p->m_ViewId == m_pView->m_ViewId) {
            m_pView->m_PlayerActorId = p->m_Id;
        }
    }

    return false;
}
