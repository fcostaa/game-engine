//
// Created by Felipe Costa on 8/27/16.
//

#ifndef CROSSENGINEDESKTOP_PLAYERNODE_H
#define CROSSENGINEDESKTOP_PLAYERNODE_H


#include "../../engine/SceneGraph/SpriteNode.h"
#include "../Actor/PlayerParams.h"

class PlayerNode : public SpriteNode {

public:
    PlayerNode(const PlayerParams &params, const std::string &name, ALLEGRO_BITMAP *image) ;

    virtual void VRender(Scene *pScene) override;

};


#endif //CROSSENGINEDESKTOP_PLAYERNODE_H
