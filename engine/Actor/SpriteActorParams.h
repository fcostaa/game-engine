//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_SPRITEACTORPARAMS_H
#define CROSSENGINEDESKTOP_SPRITEACTORPARAMS_H

#include "Base/ActorParams.h"

struct SpriteActorParams : public ActorParams {

    GameViewId m_ViewId;

    SpriteActorParams();

    virtual boost::shared_ptr<IActor> VCreate(BaseGameLogic *logic);

    virtual boost::shared_ptr<SceneNode> VCreateSceneNode(boost::shared_ptr<Scene> pScene);
};


#endif //CROSSENGINEDESKTOP_SPRITEACTORPARAMS_H
