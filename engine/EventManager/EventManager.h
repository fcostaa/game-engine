//
// Created by Felipe Costa on 4/10/16.
//

#ifndef CROSSENGINEDESKTOP_EVENTMANAGER_H
#define CROSSENGINEDESKTOP_EVENTMANAGER_H

#import <vector>
#include <list>
#include <set>
#include <map>

#import "IEventManager.h"

typedef std::set<EventType> EventTypeSet;

typedef std::pair<EventTypeSet::iterator, bool> EventTypeSetInsertResult;

typedef std::list<EventListenerPtr> EventListenerTable;

typedef std::map<std::string, EventListenerTable> EventListenerMap;

typedef std::pair<std::string, EventListenerTable> EventListenerMapEntry;

typedef std::pair<EventListenerMap::iterator, bool> EventListenerMapInsertResult;

typedef std::list<IEventDataPtr> EventQueue;

//typedef std::vector<EventListenerPtr> EventListenerList;

//typedef std::vector<EventType> EventTypeList;

class EventManager : public IEventManager {

public:

    explicit EventManager(char const *const pName,
                          bool setAsGlobal);

    virtual ~EventManager();

//    EventListenerList GetListenerList(EventType const &eventType) const;
//
//    EventTypeList GetTypeList() const;

    void RegisterCodeOnlyEvent(const EventType &eventType);

    template<class T>
    void RegisterEvent(const EventType &eventType);

    virtual bool VAddListener(EventListenerPtr const &inHandler, EventType const &inType);

    virtual bool VDelListener(EventListenerPtr const &inHandler, EventType const &inType);

    virtual bool VTrigger(IEventData const &inEvent) const;

    virtual bool VQueueEvent(IEventDataPtr const &inEvent);

    virtual bool VThreadSafeQueueEvent(IEventDataPtr const &inEvent);

    virtual bool VAbortEvent(EventType const &inType, bool allOfType);

    virtual bool VTick(unsigned long maxMillis);

    virtual bool VValidateType(EventType const &inType) const;

private:

    enum eConstants {
        kNumQueues = 2
    };

    EventTypeSet m_typeList;

    EventListenerMap m_registry;

    EventQueue m_queues[kNumQueues];

    int m_activeQueue;
};

template<class T>
void EventManager::RegisterEvent(const EventType &eventType) {
    RegisterCodeOnlyEvent(eventType);
}


#endif //CROSSENGINEDESKTOP_EVENTMANAGER_H
