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
    bool mIsQuitting;

    BaseGameLogic *mGameLogic;
    EventManager *mEventManager;

public:

    GameApplication();

    virtual ~GameApplication();

    bool initInstance(int screenWidth = SCREEN_WIDTH, int screenHeight = SCREEN_HEIGHT);

    void run();

    void onRender(double elapsedTime);

    void onUpdate(double elapsedTime);

    void abortGame();

    bool onClose();

    bool shutDown();

    int getInstanceWindow() const;

    bool IsRunning() const;

    BaseGameLogic *getGameLogic();

    //Virtual
    virtual bool loadGame() = 0;

    virtual std::string *getGameTitle() = 0;

    virtual BaseGameLogic *createGameAndView() = 0;

    virtual bool RegisterBaseGameEvents();

    void handleEvent(ALLEGRO_EVENT event);
};

extern GameApplication *gameApplication;

#endif //CROSSENGINEDESKTOP_GAMEENGINE_H
