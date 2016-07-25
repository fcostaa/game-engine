//
// Created by Felipe Costa on 4/22/16.
//

#include "SceneNodeProperties.h"

optional<ActorId> const &SceneNodeProperties::ActorId() const {
    return m_ActorId;
}

const char *SceneNodeProperties::Name() const {
    return m_Name.c_str();
}
