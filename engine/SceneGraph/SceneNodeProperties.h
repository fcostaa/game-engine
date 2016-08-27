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

    int posX;
    int posY;

public:
    optional<ActorId> const &ActorId() const;

    const char *Name() const;

    int getPosX() const {
        return posX;
    }

    int getPosY() const {
        return posY;
    }
};


#endif //CROSSENGINEDESKTOP_SCENENODEPROPERTIES_H
