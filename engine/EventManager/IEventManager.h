//
// Created by Felipe Costa on 7/20/15.
//

#ifndef CROSSENGINEDESKTOP_IEVENTMANAGER_H
#define CROSSENGINEDESKTOP_IEVENTMANAGER_H

#include "Events/IEventListener.h"

typedef boost::shared_ptr<IEventListener> EventListenerPtr;
//typedef concurrent_queue<IEventDataPtr> ThreadSafeEventQueue;

class IEventManager {
public:

    enum eConstants {
        kINFINITE = 0xffffffff
    };

    explicit IEventManager(char const *const pName,
                           bool setAsGlobal);

    virtual ~IEventManager();

    // Register a handler for a specific Events type, implicitly
    // the Events type will be added to the known Events types if
    // not already known.
    //
    // The function will return false on failure for any
    // reason. The only really anticipated failure reason is if
    // the input Events type is bad ( e.g.: known-ident number
    // with different signature text, or signature text is empty
    // )

    virtual bool VAddListener(EventListenerPtr const &inHandler,
                              EventType const &inType) = 0;

    // Remove a listener/type pairing from the internal tables
    //
    // Returns false if the pairing was not found.

    virtual bool VDelListener(EventListenerPtr const &inHandler,
                              EventType const &inType) = 0;

    // Fire off Events - synchronous - do it NOW kind of thing -
    // analogous to Win32 SendMessage() API.
    //
    // returns true if the Events was consumed, false if not. Note
    // that it is acceptable for all Events listeners to act on an
    // Events and not consume it, this return signature exists to
    // allow complete propogation of that shred of information
    // from the internals of this system to outside uesrs.

    virtual bool VTrigger(IEventData const &inEvent) const = 0;

    // Fire off Events - asynchronous - do it WHEN the Events
    // system tick() method is called, normally at a judicious
    // time during game-loop processing.
    //
    // returns true if the message was added to the processing
    // queue, false otherwise.

    virtual bool VQueueEvent(IEventDataPtr const &inEvent) = 0;

    virtual bool VThreadSafeQueueEvent(IEventDataPtr const &inEvent) = 0;

    // Find the next-available instance of the named Events type
    // and remove it from the processing queue.
    //
    // This may be done up to the point that it is actively being
    // processed ...  e.g.: is safe to happen during Events
    // processing itself.
    //
    // if 'allOfType' is input true, then all events of that type
    // are cleared from the input queue.
    //
    // returns true if the Events was found and removed, false
    // otherwise

    virtual bool VAbortEvent(EventType const &inType,
                             bool allOfType = false) = 0;

    // Allow for processing of any queued messages, optionally
    // specify a processing time limit so that the Events
    // processing does not take too long. Note the danger of
    // using this artificial limiter is that all messages may not
    // in fact get processed.
    //
    // returns true if all messages ready for processing were
    // completed, false otherwise (e.g. timeout )

    virtual bool VTick(unsigned long maxMillis = kINFINITE) = 0;

    // --- information lookup functions ---

    // Validate an Events type, this does NOT add it to the
    // internal registry, only verifies that it is legal (
    // e.g. either the ident number is not yet assigned, or it is
    // assigned to matching signature text, and the signature
    // text is not empty ).

    virtual bool VValidateType(EventType const &inType) const = 0;

private:

    // internal use only accessor for the static methods in the
    // helper to use to get the active global instance.

    static IEventManager *Get();

    // These methods are declared friends in order to get access to the
    // Get() method. Since there is no other private entity declared
    // in this class this does not break encapsulation, but does allow
    // us to do this without requiring macros or other older-style
    // mechanims.

    friend bool safeAddListener(EventListenerPtr const &inHandler,
                                EventType const &inType);

    friend bool safeDelListener(EventListenerPtr const &inHandler,
                                EventType const &inType);

    friend bool safeTriggerEvent(IEventData const &inEvent);

    friend bool safeQueEvent(IEventDataPtr const &inEvent);

    friend bool threadSafeQueEvent(IEventDataPtr const &inEvent);

    friend bool safeAbortEvent(EventType const &inType,
                               bool allOfType);

    friend bool safeTickEventManager(unsigned long maxMillis);

    friend bool safeValidateEventType(EventType const &inType);


};

// Lastly, these methods are used for easy-access methods to carry
// out basic operations without needing to pass around a pointer-to
// ( or some other construct ) for sharing a global Events manager.

bool safeAddListener(EventListenerPtr const &inHandler,
                     EventType const &inType);

bool safeDelListener(EventListenerPtr const &inHandler,
                     EventType const &inType);

bool safeTriggerEvent(IEventData const &inEvent);

bool safeQueEvent(IEventDataPtr const &inEvent);

bool threadSafeQueEvent(IEventDataPtr const &inEvent);

bool safeAbortEvent(EventType const &inType,
                    bool allOfType = false);

bool safeTickEventManager(unsigned long maxMillis = IEventManager::kINFINITE);

bool safeValidateEventType(EventType const &inType);


#endif //CROSSENGINEDESKTOP_IEVENTMANAGER_H
