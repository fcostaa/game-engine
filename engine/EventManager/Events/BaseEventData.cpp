//
// Created by Felipe Costa on 8/2/15.
//

#include "BaseEventData.h"

BaseEventData::BaseEventData(const float timeStamp)
        : timeStamp(timeStamp) {
}

float BaseEventData::VGetTimeStamp() const {
    return timeStamp;
}

