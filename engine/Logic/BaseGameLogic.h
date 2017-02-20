//
// Created by Felipe Costa on 5/25/15.
//

#ifndef CROSSENGINEDESKTOP_BASEGAMELOGIC_H
#define CROSSENGINEDESKTOP_BASEGAMELOGIC_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <map>
#include <list>

#include "../standards.h"
#include "../Timer/Timer.h"
#include "../Interfaces.h"
#include "ProcessManager.h"
#include "../GameApplication.h"

class GameApplication;

extern GameApplication *gameApplication;

typedef std::map<ActorId, boost::shared_ptr<IActor> > ActorMap;

typedef std::map<ActorId, std::pair<Vec2, float> > CollisionCircleMap;

enum GameState {
    INITIALIZING, LOADING_GAME, RUNNING, QUITTING
};

class BaseGameLogic : public IGameLogic {
protected:
    GameState mState;

    GameViewList *mGameViews;
    ProcessManager *mProcessManager;

    ActorMap m_ActorList;
    ActorId m_LastActorId;

    CollisionCircleMap m_CollisionCircleMap;

public:

    BaseGameLogic();

    virtual ~BaseGameLogic();

    ActorId GetNewActorID(void) {
        return ++m_LastActorId;
    }

    virtual boost::shared_ptr<IActor> VGetActor(const ActorId id);

    GameViewList *getGameViewList();

    virtual void addGameView(boost::shared_ptr<IGameView> view, optional<ActorId> actor = optional_empty());

    virtual void removeGameView(boost::shared_ptr<IGameView> view);

    void VAddCollisionCircle(std::pair<Vec2, float> circle, ActorId id);

    virtual void VMoveActor(const ActorId id, Vec2 position);

    virtual void VAddActor(boost::shared_ptr<IActor> actor, optional<ActorId> actorID );

    virtual void VRemoveActor(ActorId id);

    void changeState(GameState newState);

    virtual void onUpdate(double elapsedTime);

    virtual bool VLoadGame();

    virtual void VBuildInitialScene();
};

#endif //CROSSENGINEDESKTOP_BASEGAMELOGIC_H
