//
// Created by Felipe Costa on 4/24/16.
//

#include "AwesomeEventListener.h"
#include "../../engine/Actor/Base/ActorParams.h"
#include "../../engine/EventManager/Events/EvtData_New_Game.h"
#include "../../engine/EventManager/Events/EvtData_New_Actor.h"
#include "../../engine/EventManager/Events/EvtData_Request_New_Actor.h"
#include "../../engine/EventManager/Events/EvtData_Move_Actor.h"

AwesomeEventListener::AwesomeEventListener(AwesomeGameLogic *awesomeGameLogic) : m_AwesomeGameLogic(awesomeGameLogic) {

}

AwesomeEventListener::~AwesomeEventListener() {

}

char const *AwesomeEventListener::GetName(void) {
    return "AwesomeEventListener";
}

bool AwesomeEventListener::HandleEvent(IEventData const &event) {
    // std::cout << "AwesomeGameViewListener::HandleEvent" << std::endl;

    EventType eventType = event.VGetEventType();

    if (eventType == EvtData_New_Game::sk_EventType) {
        // std::cout << "New Game Event" << std::endl;
        return true;
    } else if (eventType == EvtData_Request_New_Actor::sk_EventType) {
        const EvtData_Request_New_Actor &castEvent = static_cast< const EvtData_Request_New_Actor & >( event );
        ActorParams *pActorParams = castEvent.m_pActorParams;

        if (NULL == pActorParams) {
            return false;
        }

        const ActorId actorID = m_AwesomeGameLogic->GetNewActorID();
        pActorParams->m_Id = actorID;

        const EvtData_New_Actor actorEvent(actorID, pActorParams);
        return safeTriggerEvent(actorEvent);

    } else if (eventType == EvtData_New_Actor::sk_EventType) {
        const EvtData_New_Actor &castEvent = static_cast< const EvtData_New_Actor & >( event );
        ActorParams *pActorParams = castEvent.m_pActorParams;

        if (NULL == pActorParams) {
            return false;
        }

        pActorParams->VCreate(m_AwesomeGameLogic);

        return castEvent.m_id != 0;
    } else if (eventType == EvtData_Move_Actor::sk_EventType) {
        const EvtData_Move_Actor &castEvent = static_cast< const EvtData_Move_Actor & >( event );
        m_AwesomeGameLogic->VMoveActor(castEvent.actorId, castEvent.position);
    }

    return false;
}
