//
// Created by Felipe Costa on 5/25/15.
//

#ifndef CROSSENGINEDESKTOP_PROCESS_H
#define CROSSENGINEDESKTOP_PROCESS_H

#include <boost/shared_ptr.hpp>
//#include <boost/noncopyable.hpp>
//#include <memory>

#include "../Timer/Timer.h"

enum PROCESS_TYPE {
    PROCESS_NONE, PROCESS_WAIT
};

static const int PROCESS_FLAG_ATTACHED = 0x00000001;

class Process {

protected:
    int mType;
    bool mKill;
    bool mActive;
    bool mPaused;
    bool mInitialUpdate;
    boost::shared_ptr<Process> mNext;

private:
    unsigned int mProcessFlags;

public:
    Process(int ntype, unsigned int uOrder = 0);

    Process( const Process& other ) = delete; // non construction-copyable
    Process& operator=( const Process& ) = delete; // non copyable

    virtual ~Process();

    bool isDead() const;

    virtual void kill();

    int getType() const;

    void setType(const int t);

    bool isActive() const;

    void setActive(const bool b);

    bool isAttached() const;

    void setAttached(const bool wantAttached);

    bool isPaused(void) const;

    virtual void togglePause();

    bool isInitialized() const;

    boost::shared_ptr<Process> const getNext() const;

    void setNext(boost::shared_ptr<Process> next);

    virtual void onUpdate(double elapsedTime);

    virtual void onInitialize();
};


#endif //CROSSENGINEDESKTOP_PROCESS_H
