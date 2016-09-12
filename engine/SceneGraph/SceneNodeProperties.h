//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_SCENENODEPROPERTIES_H
#define CROSSENGINEDESKTOP_SCENENODEPROPERTIES_H


#include <string>
#include "../Utils/Optional.h"
#include "../Interfaces.h"
#include "../Math/Vec2.h"

class SceneNodeProperties {

    friend class SceneNode;

protected:
    optional<ActorId> m_ActorId;
    std::string m_Name;

    Vec2 position;

public:
    optional<ActorId> const &ActorId() const;

    const char *Name() const;

    const Vec2 &getPosition() const {
        return position;
    }
};


#endif //CROSSENGINEDESKTOP_SCENENODEPROPERTIES_H
