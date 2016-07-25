//
// Created by Felipe Costa on 8/2/15.
//

#ifndef CROSSENGINEDESKTOP_BASEEVENTDATA_H
#define CROSSENGINEDESKTOP_BASEEVENTDATA_H


#include "IEventData.h"

class BaseEventData : public IEventData {

public:
    explicit BaseEventData(const float timeStamp = 0.0f);

    virtual float VGetTimeStamp() const;

    virtual IEventDataPtr VCopy() const = 0;

protected:
    const float timeStamp;
};


#endif //CROSSENGINEDESKTOP_BASEEVENTDATA_H
