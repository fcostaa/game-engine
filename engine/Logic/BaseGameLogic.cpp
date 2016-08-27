//
// Created by Felipe Costa on 5/25/15.
//

#include "BaseGameLogic.h"
#include "../Actor/Base/ActorParams.h"
#include "../EventManager/Events/EvtData_New_Game.h"

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
