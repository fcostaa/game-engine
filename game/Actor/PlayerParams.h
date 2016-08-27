//
// Created by Felipe Costa on 8/27/16.
//

#ifndef CROSSENGINEDESKTOP_PLAYERPARAMS_H
#define CROSSENGINEDESKTOP_PLAYERPARAMS_H


#include "../../engine/Actor/Base/ActorParams.h"
#include "../../engine/Actor/SpriteObjectParams.h"

class PlayerParams : public SpriteObjectParams {

public:

    PlayerParams();

    PlayerParams(const PlayerParams &playerParams);

    virtual boost::shared_ptr<IActor> VCreate(BaseGameLogic *logic) override;

    virtual boost::shared_ptr<ISceneNode> VCreateSceneNode(boost::shared_ptr<Scene> pScene) override;
};


#endif //CROSSENGINEDESKTOP_PLAYERPARAMS_H
