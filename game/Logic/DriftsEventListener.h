//
// Created by Felipe Costa on 4/24/16.
//

#ifndef CROSSENGINEDESKTOP_AWESOMEEVENTLISTENER_H
#define CROSSENGINEDESKTOP_AWESOMEEVENTLISTENER_H

#include "DriftsGameLogic.h"

class AwesomeEventListener : public IEventListener {
public:

    explicit AwesomeEventListener(DriftsGameLogic *awesomeGameLogic);

    virtual ~AwesomeEventListener();

    char const *GetName(void);

    bool HandleEvent(IEventData const &event);

private:
    DriftsGameLogic *m_AwesomeGameLogic;
};


#endif //CROSSENGINEDESKTOP_AWESOMEEVENTLISTENER_H
