//
// Created by Felipe Costa on 4/24/16.
//

#ifndef CROSSENGINEDESKTOP_AWESOMEEVENTLISTENER_H
#define CROSSENGINEDESKTOP_AWESOMEEVENTLISTENER_H

#include "AwesomeGameLogic.h"

class AwesomeEventListener : public IEventListener {
public:

    explicit AwesomeEventListener(AwesomeGameLogic *awesomeGameLogic);

    virtual ~AwesomeEventListener();

    char const *GetName(void);

    bool HandleEvent(IEventData const &event);

private:
    AwesomeGameLogic *m_AwesomeGameLogic;
};


#endif //CROSSENGINEDESKTOP_AWESOMEEVENTLISTENER_H
