//
// Created by Felipe Costa on 5/25/15.
//

#include "Process.h"

Process::Process(int type, unsigned int order) :
        mType(type),
        mKill(false),
        mActive(true),
        mPaused(false),
        mInitialUpdate(true),
        mProcessFlags(0) {
}

Process::~Process() {

}

bool Process::isDead() const {
    return this->mKill;
}

int Process::getType() const {
    return this->mType;
};

void Process::setType(const int type) {
    this->mType = type;
};

bool Process::isActive() const {
    return this->mActive;
}

void Process::setActive(const bool b) {
    this->mActive = b;
}

void Process::kill() {
    mKill = true;
}

boost::shared_ptr<Process> const Process::getNext() const {
    return this->mNext;
}

void Process::setNext(boost::shared_ptr<Process> next) {
    mNext = next;
}

bool Process::isAttached() const {
    return ((mProcessFlags & PROCESS_FLAG_ATTACHED) ? true : false);
}

void Process::setAttached(const bool wantAttached) {
    if (wantAttached) {
        mProcessFlags |= PROCESS_FLAG_ATTACHED;
    } else {
        mProcessFlags &= ~PROCESS_FLAG_ATTACHED;
    }
}

bool Process::isPaused(void) const {
    return this->mPaused;
}

void Process::togglePause() {
    this->mPaused = !(this->mPaused);
}

bool Process::isInitialized() const {
    return !(this->mInitialUpdate);
}

void Process::onUpdate(double elapsedTime) {
    if (mInitialUpdate) {
        this->onInitialize();
        mInitialUpdate = false;
    }
}

void Process::onInitialize() {

}
