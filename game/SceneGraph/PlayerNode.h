//
// Created by Felipe Costa on 19/02/17.
//

#ifndef CROSSENGINEDESKTOP_PLAYERNODE_H
#define CROSSENGINEDESKTOP_PLAYERNODE_H

#include <allegro5/bitmap.h>
#include "../../engine/SceneGraph/SceneNode.h"
#include "../Actor/PlayerObjectParams.h"

class PlayerNode : public SceneNode {

protected:
    ALLEGRO_BITMAP *m_pImage;

public:

    PlayerNode(PlayerObjectParams const &params, std::string name, ALLEGRO_BITMAP *image = NULL);

    virtual ~PlayerNode();

    virtual void VRender(Scene *pScene) override;
};


#endif //CROSSENGINEDESKTOP_PLAYERNODE_H
