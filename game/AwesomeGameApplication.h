//
// Created by Felipe Costa on 4/21/16.
//

#ifndef CROSSENGINEDESKTOP_AWESOMEGAMEAPPLICATION_H
#define CROSSENGINEDESKTOP_AWESOMEGAMEAPPLICATION_H

#include "../engine/GameApplication.h"

class AwesomeGameApplication : public GameApplication {
public:
    virtual bool loadGame() override;

    virtual std::string *getGameTitle() override;

    virtual BaseGameLogic *createGameAndView() override;

    virtual bool RegisterBaseGameEvents() override;
};


#endif //CROSSENGINEDESKTOP_AWESOMEGAMEAPPLICATION_H
