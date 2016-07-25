//
// Created by Felipe Costa on 4/24/16.
//

#ifndef CROSSENGINEDESKTOP_AWESOMEGAMEVIEWLISTENER_H
#define CROSSENGINEDESKTOP_AWESOMEGAMEVIEWLISTENER_H


#include "../engine/EventManager/Events/IEventListener.h"

class AwesomeHumanView;

class AwesomeGameViewListener : public IEventListener {
private:
    AwesomeHumanView *m_pView;

public:
    explicit AwesomeGameViewListener(AwesomeHumanView *view);

    virtual char const *GetName(void) { return "TeapotWarsGameViewListener"; }

    virtual bool HandleEvent(IEventData const &event);
};


#endif //CROSSENGINEDESKTOP_AWESOMEGAMEVIEWLISTENER_H
