//
// Created by Felipe Costa on 4/24/16.
//

#ifndef CROSSENGINEDESKTOP_AWESOMEGAMELOGIC_H
#define CROSSENGINEDESKTOP_AWESOMEGAMELOGIC_H


#include "../../engine/Logic/BaseGameLogic.h"

class AwesomeGameLogic : public BaseGameLogic {

private:
    EventListenerPtr m_awesomeGameViewListener;

public:
    AwesomeGameLogic();

    virtual ~AwesomeGameLogic();

    virtual void VBuildInitialScene();
};


#endif //CROSSENGINEDESKTOP_AWESOMEGAMELOGIC_H
