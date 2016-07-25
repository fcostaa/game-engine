//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_SCENE_H
#define CROSSENGINEDESKTOP_SCENE_H

#include <boost/smart_ptr/shared_ptr.hpp>
#include <map>
#include "SceneNode.h"
#include "../Utils/Optional.h"

typedef std::map<ActorId, boost::shared_ptr<ISceneNode> > SceneActorMap;

class Scene {
protected:
    boost::shared_ptr<SceneNode> m_Root;
    SceneActorMap m_ActorMap;

public:
    Scene();

    virtual ~Scene();

    void OnRender();

    void OnUpdate(const int deltaMilliseconds);

    bool AddChild(optional<ActorId> id, boost::shared_ptr<ISceneNode> kid);

    bool RemoveChild(ActorId id);
};


#endif //CROSSENGINEDESKTOP_SCENE_H
