//
// Created by Felipe Costa on 5/25/15.
//

#include "Timer.h"

Time timeParam = Time();

void starTimer() {

    resetTimer();
}

void updateTimer() {
    // the time of the previous frame
//    double current_time = glfwGetTime();
    double current_time = al_get_time();

    timeParam.elapsedTime = current_time - timeParam.elapsedTime;
    timeParam.elapsedTimeMilliseconds = timeParam.elapsedTime * 1000.0;

}

void resetTimer() {
//    glfwSetTime(0.0);

    timeParam.startTime = timeParam.elapsedTime = al_get_time();
    timeParam.elapsedTimeMilliseconds = timeParam.elapsedTime * 1000.0;
}