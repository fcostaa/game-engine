//
// Created by Felipe Costa on 19/02/17.
//

#ifndef CROSSENGINEDESKTOP_PLAYEROBJECTPARAMS_H
#define CROSSENGINEDESKTOP_PLAYEROBJECTPARAMS_H

#include "../../engine/Actor/Base/ActorParams.h"
#include "../../engine/Actor/CircleObjectParams.h"

struct PlayerObjectParams : public ActorParams {

    GameViewId m_ViewId;

    PlayerObjectParams();

    virtual boost::shared_ptr<IActor> VCreate(BaseGameLogic *logic) override;

    virtual boost::shared_ptr<ISceneNode> VCreateSceneNode(boost::shared_ptr<Scene> pScene) override;
};


#endif //CROSSENGINEDESKTOP_PLAYEROBJECTPARAMS_H
