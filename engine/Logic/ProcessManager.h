//
// Created by Felipe Costa on 5/25/15.
//

#ifndef CROSSENGINEDESKTOP_PROCESSMANAGER_H
#define CROSSENGINEDESKTOP_PROCESSMANAGER_H

#include <list>
#include <boost/shared_ptr.hpp>

#include "Process.h"
#include "../Timer/Timer.h"

typedef std::list<boost::shared_ptr<Process>> ProcessList;

class ProcessManager {
public:
    void attach(boost::shared_ptr<Process> process);

    void updateProcesses(double elapsedTime);

    bool isProcessActive(int type) const;

    bool hasProcesses();

    ProcessManager();

    ~ProcessManager();

protected:
    ProcessList mProcessList;

private:
    void detach(boost::shared_ptr<Process> process);
};


#endif //CROSSENGINEDESKTOP_PROCESSMANAGER_H
