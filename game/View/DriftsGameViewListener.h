//
// Created by Felipe Costa on 4/24/16.
//

#ifndef CROSSENGINEDESKTOP_AWESOMEGAMEVIEWLISTENER_H
#define CROSSENGINEDESKTOP_AWESOMEGAMEVIEWLISTENER_H


#include "../../engine/EventManager/Events/IEventListener.h"

class DriftsHumanView;

class DriftsGameViewListener : public IEventListener {
private:
    DriftsHumanView *m_pView;

public:
    explicit DriftsGameViewListener(DriftsHumanView *view);

    virtual char const *GetName();

    virtual bool HandleEvent(IEventData const &event);
};


#endif //CROSSENGINEDESKTOP_AWESOMEGAMEVIEWLISTENER_H
