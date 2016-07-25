//
// Created by Felipe Costa on 5/25/15.
//

#ifndef CROSSENGINEDESKTOP_GAMEENGINE_H
#define CROSSENGINEDESKTOP_GAMEENGINE_H

#include <cstdlib>
#include <string>
#include <list>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "standards.h"
#include "Logic/BaseGameLogic.h"
#include "Timer/Timer.h"
#include "EventManager/EventManager.h"

class BaseGameLogic;

class GameApplication {

private:
    void cleanUp();
protected:
    int mInstanceWindow;
    bool mIsRunning;
    bool mQuitting;

    BaseGameLogic *mGameLogic;
    EventManager *mEventManager;

public:

    GameApplication();

    virtual ~GameApplication();

    bool initInstance(int screenWidth = SCREEN_WIDTH, int screenHeight = SCREEN_HEIGHT);

    void run();

    void onRender(Time &time);

    void onUpdate(double elapsedTime);

    void abortGame();

    bool onClose();

    bool shutDown();

    int getInstanceWindow() const;

    bool IsRunning() const;

    const BaseGameLogic *getGameLogic() const;

    //Virtual
    virtual bool loadGame() = 0;

    virtual std::string *getGameTitle() = 0;

    virtual BaseGameLogic *createGameAndView() = 0;

    virtual bool RegisterBaseGameEvents();

};

extern GameApplication *gameApplication;

#endif //CROSSENGINEDESKTOP_GAMEENGINE_H
