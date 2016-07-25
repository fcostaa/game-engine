//
// Created by Felipe Costa on 5/25/15.
//

#ifndef CROSSENGINEDESKTOP_TIMER_H
#define CROSSENGINEDESKTOP_TIMER_H

#include <allegro5/altime.h>

#ifdef __cplusplus
extern "C"
#endif
void starTimer();

#ifdef __cplusplus
extern "C"
#endif
void updateTimer();

#ifdef __cplusplus
extern "C"
#endif
void resetTimer();

struct Time {
    double elapsedTime;
    double startTime;
    double elapsedTimeMilliseconds;
};

extern Time timeParam;


#endif //CROSSENGINEDESKTOP_TIMER_H
