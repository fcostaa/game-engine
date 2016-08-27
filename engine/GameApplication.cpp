//
// Created by Felipe Costa on 5/25/15.
//

#include "GameApplication.h"
#include "EventManager/Events/EvtData_Keyboard_key_Down.h"
#include "EventManager/Events/EvtData_Mouse_Move.h"

GameApplication *gameApplication = NULL;
ALLEGRO_DISPLAY *window = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
const int FPS = 60;

GameApplication::GameApplication() :
        mInstanceWindow(0), mIsRunning(false), mIsQuitting(false), mGameLogic(NULL) {
    gameApplication = this;
}

GameApplication::~GameApplication() {
    gameApplication = NULL;
}

bool GameApplication::initInstance(int screenWidth, int screenHeight) {

    if (!al_init()) {
        std::cerr << "Allegro init failed" << std::endl;
        return false;
    }

    window = al_create_display(screenWidth, screenHeight);
    if (window == NULL) {
        std::cerr << "Allegro create display failed" << std::endl;
        return false;
    }

    if (!al_install_keyboard()) {
        std::cerr << "Allegro initialize the keyboard failed" << std::endl;
        return -1;
    }

    if (!al_install_mouse()) {
        std::cerr << "Allegro initialize the mouse failed" << std::endl;
        return -1;
    }

    timer = al_create_timer(1.0 / FPS);
    if (!timer) {
        std::cerr << "Allegro timer failed" << std::endl;
        return -1;
    }

    al_init_image_addon();

    event_queue = al_create_event_queue();
    if (event_queue == NULL) {
        fprintf(stderr, "failed to create event_queue!\n");
        return false;
    }

    al_register_event_source(event_queue, al_get_display_event_source(window));

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_register_event_source(event_queue, al_get_mouse_event_source());

    std::string *title = this->getGameTitle();
    al_set_window_title(window, title->c_str());
    SAFE_DELETE(title);

    mEventManager = NEW EventManager("Game Event Mgr", true);
    if (!mEventManager) {
        fprintf(stderr, "failed to register events!\n");
        return false;
    }

    RegisterBaseGameEvents();

    this->mGameLogic = this->createGameAndView();
    if (!this->mGameLogic) {
        return false;
    }

    this->mIsRunning = true;

    return true;
}

void GameApplication::run() {

//    starTimer();
//    Time time = Time();
    double elapsedTime;
    double startTime;
    startTime = elapsedTime = al_get_time();
//    time.elapsedTimeMilliseconds = time.elapsedTime * 1000.0;

    while (mIsRunning) {

        if (mIsQuitting) {
            this->onClose();
            break;
        }

//        updateTimer();
        double current_time = al_get_time();
        std::cout << "current_time: " << current_time << std::endl;
        elapsedTime = current_time - elapsedTime;

        ALLEGRO_EVENT ev;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.06);

        bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);
        if (get_event) {
            handleEvent(ev);
        }

        safeTickEventManager(20);

        this->onUpdate(elapsedTime);

        this->onRender(elapsedTime);

        std::cout << "ElapsedTime: " << elapsedTime << std::endl;

        al_flip_display();

        al_rest(0.000001);

        al_set_target_bitmap(al_get_backbuffer(window));

        al_clear_to_color(al_map_rgb(255, 255, 255));

        std::cout << std::endl << std::endl;
    }

}

void GameApplication::onUpdate(double elapsedTime) {

    if (this->mGameLogic) {
        // Process events
        this->mGameLogic->onUpdate(elapsedTime);
    }
}

void GameApplication::onRender(double elapsedTime) {

    BaseGameLogic *game = this->mGameLogic;

    for (GameViewList::const_iterator i = game->getGameViewList()->begin(),
                 end = game->getGameViewList()->end(); i != end; ++i) {
        (*i)->onRender(elapsedTime);
    }
}

void GameApplication::abortGame() {
    this->mIsQuitting = true;
}

bool GameApplication::onClose() {
    this->mIsRunning = false;

    SAFE_DELETE(this->mGameLogic);

    return true;
}

bool GameApplication::shutDown() {
    cleanUp();
    return true;
}

int GameApplication::getInstanceWindow() const {
    return this->mInstanceWindow;
}

bool GameApplication::IsRunning() const {
    return this->mIsRunning;
}

const BaseGameLogic *GameApplication::getGameLogic() const {
    return this->mGameLogic;
}

void GameApplication::cleanUp() {
    al_destroy_event_queue(event_queue);
    al_destroy_display(window);
    al_uninstall_system();
}

bool GameApplication::RegisterBaseGameEvents() {
    if (mEventManager == NULL) {
        return false;
    }

    return true;
}

void GameApplication::handleEvent(ALLEGRO_EVENT event) {
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        mIsQuitting = true;
    }
//    else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
//        safeTriggerEvent(EvtData_Keyboard_key_Down(event.keyboard.keycode));
//    }
    else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        safeTriggerEvent(EvtData_Mouse_Move(event.mouse.x, event.mouse.y));
    }
}
