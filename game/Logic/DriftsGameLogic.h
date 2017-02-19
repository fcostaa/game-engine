//
// Created by Felipe Costa on 4/24/16.
//

#ifndef CROSSENGINEDESKTOP_AWESOMEGAMELOGIC_H
#define CROSSENGINEDESKTOP_AWESOMEGAMELOGIC_H


#include "../../engine/Logic/BaseGameLogic.h"

class DriftsGameLogic : public BaseGameLogic {

private:
    EventListenerPtr m_awesomeGameViewListener;

public:
    DriftsGameLogic();

    virtual ~DriftsGameLogic();

    virtual void VBuildInitialScene();

    virtual void onUpdate(double elapsedTime) override;
};


#endif //CROSSENGINEDESKTOP_AWESOMEGAMELOGIC_H
