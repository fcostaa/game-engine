//
// Created by Felipe Costa on 4/24/16.
//

#include "AwesomeEventListener.h"
#include "Events/EvtData_New_Game.h"
#include "Events/EvtData_New_Actor.h"
#include "../engine/Actor/Base/ActorParams.h"

AwesomeEventListener::AwesomeEventListener(AwesomeGameLogic *awesomeGameLogic) : m_AwesomeGameLogic(awesomeGameLogic) {

}

AwesomeEventListener::~AwesomeEventListener() {

}

char const *AwesomeEventListener::GetName(void) {
    return "AwesomeEventListener";
}

bool AwesomeEventListener::HandleEvent(IEventData const &event) {
    std::cout << "AwesomeGameViewListener::HandleEvent" << std::endl;

    EventType eventType = event.VGetEventType();

    if (eventType == EvtData_New_Game::sk_EventType) {
        std::cout << "New Game Event" << std::endl;
        return true;
    } else if (eventType == EvtData_New_Actor::sk_EventType) {
        const EvtData_New_Actor &castEvent = static_cast< const EvtData_New_Actor & >( event );
        ActorParams *pActorParams = castEvent.m_pActorParams;

        if (NULL == pActorParams) {
            return false;
        }

        pActorParams->VCreate(m_AwesomeGameLogic);

        return castEvent.m_id != 0;
    }

    return false;
}
