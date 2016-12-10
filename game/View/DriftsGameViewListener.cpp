//
// Created by Felipe Costa on 4/24/16.
//

#include "DriftsGameViewListener.h"
#include "DriftsHumanView.h"
#include "../../engine/Actor/Base/ActorParams.h"
#include "../../engine/EventManager/Events/EvtData_New_Game.h"
#include "../../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../../engine/EventManager/Events/EvtData_Keyboard_key_Down.h"
#include "../../engine/EventManager/Events/EvtData_Move_Actor.h"
#include "../../engine/EventManager/Events/EvtData_Mouse_Move.h"
#include "../../engine/Actor/CircleObjectParams.h"

DriftsGameViewListener::DriftsGameViewListener(DriftsHumanView *view) : m_pView(view) {
}

char const *DriftsGameViewListener::GetName() {
    return "AwesomeGameViewListener";
}

bool DriftsGameViewListener::HandleEvent(IEventData const &event) {
    EventType eventType = event.VGetEventType();

    if (eventType == EvtData_New_Game::sk_EventType) {
        // do nothing
    } else if (eventType == EvtData_New_Actor::sk_EventType) {
        const EvtData_New_Actor &ed = static_cast< const EvtData_New_Actor & >( event );

        boost::shared_ptr<ISceneNode> node = ed.m_pActorParams->VCreateSceneNode(m_pView->m_pScene);
        m_pView->m_pScene->AddChild(ed.m_id, node);

        CircleObjectParams *p = static_cast<CircleObjectParams *>(ed.m_pActorParams);

        if (p->m_ViewId == m_pView->VGetId()) {
            m_pView->m_pPlayer = node;
            m_pView->m_pController.reset(NEW DriftsController(node));
            m_pView->m_KeyboardHandler = m_pView->m_pController;
            m_pView->m_MouseHandler = m_pView->m_pController;
        }
        return true;
    } else if (eventType == EvtData_Keyboard_key_Down::sk_EventType) {
        const EvtData_Keyboard_key_Down &eventData = static_cast< const EvtData_Keyboard_key_Down & >( event );

        if (m_pView->m_KeyboardHandler) {
            m_pView->m_KeyboardHandler->VOnKeyDown(eventData.keyCode);
        }

        return true;
    } else if (eventType == EvtData_Mouse_Move::sk_EventType) {
        const EvtData_Mouse_Move &eventData = static_cast< const EvtData_Mouse_Move & >( event );

        if (m_pView->m_MouseHandler) {
            m_pView->m_MouseHandler->VOnMouseMove(eventData.mouseDx, eventData.mouseDy);
        }

        return true;
    } else if (eventType == EvtData_Move_Actor::sk_EventType) {
        const EvtData_Move_Actor &ed = static_cast< const EvtData_Move_Actor & >( event );
        m_pView->MoveActor(ed.actorId, ed.position);
    }

    return false;
}
