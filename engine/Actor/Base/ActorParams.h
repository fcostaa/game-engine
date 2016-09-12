//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_ACTORPARAMS_H
#define CROSSENGINEDESKTOP_ACTORPARAMS_H


//#include "../../Interfaces.h"
#include "../../Logic/BaseGameLogic.h"
#include "../../SceneGraph/SceneNode.h"
#include "../../Math/Vec2.h"

struct ActorParams {

    size_t m_Size;

    optional<ActorId> m_Id;

    Vec2 m_Pos;

    float m_Radius;

    ActorParams();

    ActorParams(const ActorParams &actorParams);

    virtual ~ActorParams();

    virtual boost::shared_ptr<IActor> VCreate(BaseGameLogic *logic);

    virtual boost::shared_ptr<ISceneNode> VCreateSceneNode(boost::shared_ptr<Scene> pScene);
};


#endif //CROSSENGINEDESKTOP_ACTORPARAMS_H
