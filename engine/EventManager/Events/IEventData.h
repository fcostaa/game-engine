//
// Created by Felipe Costa on 8/2/15.
//

#ifndef CROSSENGINEDESKTOP_IEVENTDATA_H
#define CROSSENGINEDESKTOP_IEVENTDATA_H

#include <strstream>
#include <boost/shared_ptr.hpp>

#include "../../standards.h"

typedef std::string EventType;

class IEventData;

typedef boost::shared_ptr<IEventData> IEventDataPtr;

class IEventData {
public:

    virtual const EventType &VGetEventType() const = 0;

    // added for the Multicore chapter
    virtual IEventDataPtr VCopy() const = 0;

    virtual float VGetTimeStamp() const = 0;
};


#endif //CROSSENGINEDESKTOP_IEVENTDATA_H
