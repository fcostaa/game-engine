//
// Created by Felipe Costa on 7/20/15.
//

#include "IEventManager.h"

static IEventManager * g_pEventMgr = NULL;

IEventManager * IEventManager::Get()
{
    return g_pEventMgr;
}

IEventManager::IEventManager(
        char const * const pName,
        bool setAsGlobal )
{
    if ( setAsGlobal )
        g_pEventMgr = this;
}

IEventManager::~IEventManager()
{
    if ( g_pEventMgr == this )
        g_pEventMgr = NULL;
}

bool safeAddListener(EventListenerPtr const &inHandler, EventType const &inType) {
    return IEventManager::Get()->VAddListener(inHandler, inType);
}

bool safeDelListener(EventListenerPtr const &inHandler, EventType const &inType) {
    return IEventManager::Get()->VDelListener(inHandler, inType);
}

bool safeTriggerEvent(IEventData const &inEvent) {
    return IEventManager::Get()->VTrigger(inEvent);
}

bool safeQueEvent(IEventDataPtr const &inEvent) {
    return IEventManager::Get()->VQueueEvent(inEvent);
}

bool threadSafeQueEvent(IEventDataPtr const &inEvent) {
    return IEventManager::Get()->VThreadSafeQueueEvent(inEvent);
}

bool safeAbortEvent(EventType const &inType,
                    bool allOfType /*= false*/ ) {
    return IEventManager::Get()->VAbortEvent(inType, allOfType);
}

bool safeTickEventManager(unsigned long maxMillis /*= kINFINITE*/ ) {
    return IEventManager::Get()->VTick(maxMillis);
}

bool safeValidateEventType(EventType const &inType) {
    return IEventManager::Get()->VValidateType(inType);
}