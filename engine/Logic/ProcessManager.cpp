//
// Created by Felipe Costa on 5/25/15.
//

#include "ProcessManager.h"
#include <iostream>

void ProcessManager::attach(const boost::shared_ptr<Process> process) {
    this->mProcessList.push_back(process);
    process->setAttached(true);
}

void ProcessManager::updateProcesses(double elapsedTime) {
    // std::cout << "Process List size:" << this->mProcessList.size() << std::endl;
    ProcessList::const_iterator i = this->mProcessList.begin();
    ProcessList::const_iterator end = this->mProcessList.end();
    boost::shared_ptr<Process> next;

    while (i != end) {
        boost::shared_ptr<Process> processPtr(*i);
        ++i;

        if (processPtr->isDead()) {

            next = processPtr->getNext();
            if (next) {
                processPtr->setNext(boost::shared_ptr<Process>((Process *) NULL));
                this->attach(next);
            }
            this->detach(processPtr);
        } else if (processPtr->isActive() && !processPtr->isPaused()) {
            processPtr->onUpdate(elapsedTime);
        }
    }
}

bool ProcessManager::isProcessActive(int type) const {
    for (ProcessList::const_iterator i = this->mProcessList.begin();
         i != this->mProcessList.end(); ++i) {

        if ((*i)->getType() == type
            && ((*i)->isDead() == false || (*i)->getNext()))
            return true;
    }
    return false;
}

bool ProcessManager::hasProcesses() {
    return !(this->mProcessList.empty());
}

ProcessManager::~ProcessManager() {
    for (ProcessList::iterator i = this->mProcessList.begin();
         i != this->mProcessList.end();) {
        this->detach(*(i++));
    }
}

void ProcessManager::detach(boost::shared_ptr<Process> process) {
    this->mProcessList.remove(process);
    process->setAttached(false);
}

ProcessManager::ProcessManager() : mProcessList(0) {
    // std::cout << "ProcessManager with mProcessList.size: " << this->mProcessList.size() << std::endl;
}
