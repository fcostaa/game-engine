//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_SCENENODEPROPERTIES_H
#define CROSSENGINEDESKTOP_SCENENODEPROPERTIES_H


#include <string>
#include "../Utils/Optional.h"
#include "../Interfaces.h"

class SceneNodeProperties {

    friend class SceneNode;

protected:
    optional<ActorId> m_ActorId;
    std::string m_Name;

public:
    optional<ActorId> const &ActorId() const;

    const char *Name() const;
};


#endif //CROSSENGINEDESKTOP_SCENENODEPROPERTIES_H
