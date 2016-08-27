//
// Created by Felipe Costa on 8/27/16.
//

#ifndef CROSSENGINEDESKTOP_AIVIEWLISTENER_H
#define CROSSENGINEDESKTOP_AIVIEWLISTENER_H

#include "../../engine/EventManager/Events/IEventListener.h"

class AIView;

class AIViewListener : public IEventListener {
private:
    AIView *m_pView;
public:

    explicit AIViewListener(AIView *view);

    virtual char const *GetName();

    virtual bool HandleEvent(IEventData const &event);

};


#endif //CROSSENGINEDESKTOP_AIVIEWLISTENER_H
