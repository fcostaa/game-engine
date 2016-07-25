//
// Created by Felipe Costa on 8/2/15.
//

#ifndef CROSSENGINEDESKTOP_IEVENTLISTENER_H
#define CROSSENGINEDESKTOP_IEVENTLISTENER_H


#include "IEventData.h"

class IEventListener {

public:

    explicit IEventListener() { }

    virtual ~IEventListener() { }

    virtual bool HandleEvent(IEventData const &event) = 0;

};


#endif //CROSSENGINEDESKTOP_IEVENTLISTENER_H
