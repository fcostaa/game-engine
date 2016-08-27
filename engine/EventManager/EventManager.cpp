//
// Created by Felipe Costa on 4/10/16.
//

#include "EventManager.h"
#include <iostream>

EventManager::EventManager(char const *const pName, bool setAsGlobal)
        : IEventManager(pName, setAsGlobal),
          m_activeQueue(0) {

}

EventManager::~EventManager() {
    m_activeQueue = 0;
}

//EventListenerList EventManager::GetListenerList(EventType const &eventType) const {
//    return __1::vector<EventListenerPtr>();
//}
//
//EventTypeList EventManager::GetTypeList() const {
//    return __1::vector<EventType>();
//}


void EventManager::RegisterCodeOnlyEvent(const EventType &eventType) {
    const EventTypeSet::const_iterator iter = m_typeList.find(eventType);
    if (iter == m_typeList.end()) {
        m_typeList.insert(eventType);
    }
}

bool EventManager::VAddListener(EventListenerPtr const &inListener, EventType const &inType) {

    if (!VValidateType(inType))
        return false;

    EventTypeSet::iterator evIt = m_typeList.find(inType);

    // find listener map entry, create one if no table already
    // exists for this entry ...

    EventListenerMap::iterator elmIt = m_registry.find(inType);

    if (elmIt == m_registry.end()) {
        EventListenerMapInsertResult elmIRes = m_registry.insert(
                EventListenerMapEntry(inType, EventListenerTable()));

        // whoops, could not insert into map!?!?
        if (elmIRes.second == false)
            return false;

        // should not be possible, how did we insert and create
        // an empty table!?!?!
        if (elmIRes.first == m_registry.end())
            return false;

        // store it so we can update the mapped list next ...
        elmIt = elmIRes.first;
    }

    // update the mapped list of listeners, walk the existing
    // list (if any entries) to prevent duplicate addition of
    // listeners. This is a bit more costly at registration time
    // but will prevent the hard-to-notice duplicate event
    // propogation sequences that would happen if double-entries
    // were allowed.

    // note: use reference to make following code more simple
    EventListenerTable &evlTable = (*elmIt).second;

    for (EventListenerTable::iterator it = evlTable.begin(),
                 itEnd = evlTable.end(); it != itEnd; it++) {
        bool bListenerMatch = (*it == inListener);

        if (bListenerMatch)
            return false;
    }

    // okay, event type validated, event listener validated,
    // event listener not already in map, add it

    evlTable.push_back(inListener);

    return true;
}

bool EventManager::VDelListener(EventListenerPtr const &inHandler, EventType const &inType) {
    return false;
}

bool EventManager::VTrigger(IEventData const &inEvent) const {
    if (!VValidateType(inEvent.VGetEventType()))
        return false;

    EventListenerMap::const_iterator it =
            m_registry.find(inEvent.VGetEventType());

    if (it == m_registry.end())
        return false;

    EventListenerTable const &table = it->second;

    bool processed = false;

    for (EventListenerTable::const_iterator it2 = table.begin(),
                 it2End = table.end(); it2 != it2End; it2++) {
        EventListenerPtr listener = *it2;
        if (listener->HandleEvent(inEvent)) {
            // only set to true, if processing eats the messages
            processed = true;
        }
    }

    return processed;
}

bool EventManager::VQueueEvent(IEventDataPtr const &inEvent) {
    if (!VValidateType(inEvent->VGetEventType()))
        return false;

    EventListenerMap::const_iterator it =
            m_registry.find(inEvent->VGetEventType());

    if (it == m_registry.end()) {
        return false;
    }

    m_queues[m_activeQueue].push_back(inEvent);

    return true;
}

bool EventManager::VThreadSafeQueueEvent(IEventDataPtr const &inEvent) {
    return false;
}

bool EventManager::VAbortEvent(EventType const &inType, bool allOfType) {
    return false;
}

bool EventManager::VTick(unsigned long maxMillis) {
//    unsigned long curMs = GetTickCount();
//    unsigned long maxMs =
//            maxMillis == IEventManager::kINFINITE
//            ? IEventManager::kINFINITE
//            : (curMs + maxMillis );

    int queueToProcess = m_activeQueue;

    m_activeQueue = (m_activeQueue + 1) % kNumQueues;

//    m_queues[m_activeQueue].clear();

    EventListenerMap::const_iterator it;

    while (m_queues[queueToProcess].size() > 0) {
        IEventDataPtr event = m_queues[queueToProcess].front();

        m_queues[queueToProcess].pop_front();

        EventType const &eventType = event->VGetEventType();

        EventListenerMap::const_iterator itListeners =
                m_registry.find(eventType);

        // no listerners currently for this event type, skipit
        if (itListeners == m_registry.end())
            continue;

        std::string kEventId = itListeners->first;
        EventListenerTable const &table = itListeners->second;

        for (EventListenerTable::const_iterator
                     it = table.begin(), end = table.end();
             it != end; it++) {
            if ((*it)->HandleEvent(*event)) {
                break;
            }
        }

//        curMs = GetTickCount();
//
//        if (maxMillis != IEventManager::kINFINITE) {
//
//            if (curMs >= maxMs) {
//                // time ran about, abort processing loop
//                break;
//            }
//        }
    }

    return false;
}

bool EventManager::VValidateType(EventType const &inType) const {
    EventTypeSet::const_iterator evIt =
            m_typeList.find(inType);

    return evIt != m_typeList.end();
}
