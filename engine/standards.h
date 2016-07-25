//
// Created by Felipe Costa on 5/25/15.
//

#ifndef CROSSENGINEDESKTOP_STANDARDS_H
#define CROSSENGINEDESKTOP_STANDARDS_H

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;
const unsigned long long MEGABYTE = 1024 * 1024;

//#if defined (DEBUG) || (TEST)

//#include "memory/MemoryManager.h"
//
//extern MemoryManager memoryManager;
//
//#define NEW new(memoryManager, __FILE__,__LINE__)
//#define SAFE_DELETE(p) destroy(p, memoryManager);

//operator delete(p, memoryManager, __FILE__,__LINE__ );
//destroy(p, memoryManager);

//#else
//
#define NEW new
#define SAFE_DELETE(p) delete (p)
//
//#endif

#endif //CROSSENGINEDESKTOP_STANDARDS_H
