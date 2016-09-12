//
// Created by Felipe Costa on 5/25/15.
//

#include "BaseGameLogic.h"
#include "../Actor/Base/ActorParams.h"
#include "../EventManager/Events/EvtData_New_Game.h"

#import <cmath>

BaseGameLogic::BaseGameLogic() :
        mGameViews(0), m_LastActorId(0) {

    mGameViews = NEW GameViewList();
    mProcessManager = NEW ProcessManager();

    changeState(INITIALIZING);
}

BaseGameLogic::~BaseGameLogic() {

    while (!mGameViews->empty())
        mGameViews->pop_front();

    SAFE_DELETE(mProcessManager);
    SAFE_DELETE(mGameViews);
}

GameViewList *BaseGameLogic::getGameViewList() {
    return (this->mGameViews);
}

void BaseGameLogic::addGameView(boost::shared_ptr<IGameView> view, optional<ActorId> actorId) {
    int viewId = static_cast<int>(mGameViews->size());
    mGameViews->push_back(view);
    view->VOnAttach(viewId, actorId);
}

void BaseGameLogic::removeGameView(boost::shared_ptr<IGameView> view) {
    mGameViews->remove(view);
}

void BaseGameLogic::VAddCollisionCircle(std::pair<Vec2, float> circle, ActorId id) {
    m_CollisionCircleMap.insert(std::make_pair(id, circle));
}

void BaseGameLogic::onUpdate(double elapsedTime) {
    switch (mState) {
        case INITIALIZING:
            // If we get to here we're ready to attach players
            this->changeState(LOADINGGAME);
            break;

        case LOADINGGAME:
            if (gameApplication->loadGame()) {
                this->changeState(RUNNING);
            } else {
                std::cerr << "The game failed to load." << std::endl;
                gameApplication->abortGame();
            }
            break;

        case RUNNING:
            mProcessManager->updateProcesses(elapsedTime);

            for (CollisionCircleMap::const_iterator it = m_CollisionCircleMap.begin(),
                         itEnd = m_CollisionCircleMap.end(); it != itEnd; it++) {
                ActorId const id = it->first;
                std::pair<Vec2, float> circle = it->second;
                boost::shared_ptr<IActor> gameActor = VGetActor(id);

                Vec2 actorPosition = gameActor->VGetPosition();
                Vec2 newActorPosition(actorPosition.getX(), actorPosition.getY());
                m_CollisionCircleMap[id] = std::make_pair(newActorPosition, circle.second);
            }

            for (CollisionCircleMap::const_iterator it = m_CollisionCircleMap.begin(),
                         itEnd = m_CollisionCircleMap.end(); it != itEnd; it++) {

                Vec2 center1 = it->second.first;
                float radius1 = it->second.second;
                ActorId actorId = it->first;

                for (CollisionCircleMap::const_iterator it2 = m_CollisionCircleMap.begin(),
                             itEnd2 = m_CollisionCircleMap.end(); it2 != itEnd2; it2++) {

                    if (actorId == it2->first) {
                        continue;
                    }

                    Vec2 center2 = it2->second.first;
                    float radius2 = it2->second.second;

                    float dx = center1.getX() - center2.getX();
                    float dy = center1.getY() - center2.getY();
                    float distance = sqrtf(dx * dx + dy * dy);

                    if (distance < radius1 + radius2) {
                        std::cout << ">>>>>>>>>> collision detected!" << std::endl;
                    }
                }
            }

            break;

        default:
            std::cerr << "Unrecognized state." << std::endl;
    }

    GameViewList::const_iterator i = this->mGameViews->begin();
    GameViewList::const_iterator end = this->mGameViews->end();

    while (i != end) {
        (*i)->onUpdate(elapsedTime);
        ++i;
    }

}

void BaseGameLogic::changeState(GameState newState) {
    mState = newState;
}

void BaseGameLogic::VAddActor(boost::shared_ptr<IActor> actor, ActorParams *p) {
    optional<ActorId> destActorID = p->m_Id;
    m_ActorList[*destActorID] = actor;
    actor->VSetID(*destActorID);
}

void BaseGameLogic::VRemoveActor(ActorId id) {
    if (NULL != VGetActor(id).get()) {
//        m_pPhysics->VRemoveActor(aid);
        m_ActorList.erase(id);
    }
}


void BaseGameLogic::VMoveActor(const ActorId id, Vec2 position) {
    boost::shared_ptr<IActor> pActor = VGetActor(id);
    if (pActor) {
        pActor->VSetPosition(position);
    }
}

boost::shared_ptr<IActor> BaseGameLogic::VGetActor(const ActorId id) {
    ActorMap::iterator i = m_ActorList.find(id);
    if (i == m_ActorList.end()) {
        boost::shared_ptr<IActor> null;
        return null;
    }

    return (*i).second;
}


bool BaseGameLogic::VLoadGame() {
    safeTriggerEvent(EvtData_New_Game());
    VBuildInitialScene();
    return true;
}

void BaseGameLogic::VBuildInitialScene() {
}
