//
// Created by Felipe Costa on 8/2/15.
//

#ifndef CROSSENGINEDESKTOP_EMPTYEVENTDATA_H
#define CROSSENGINEDESKTOP_EMPTYEVENTDATA_H

#include "BaseEventData.h"

class EmptyEventData : public BaseEventData {

public:
    explicit EmptyEventData(const float timeStamp = 0.0f);

    virtual IEventDataPtr VCopy() const = 0;
};


#endif //CROSSENGINEDESKTOP_EMPTYEVENTDATA_H
