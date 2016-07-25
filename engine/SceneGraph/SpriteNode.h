//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_SPRINTENODE_H
#define CROSSENGINEDESKTOP_SPRINTENODE_H


#include <allegro5/bitmap.h>
#include "SceneNode.h"
#include "../Actor/SpriteObjectParams.h"

class SpriteNode : public SceneNode {

protected:
    ALLEGRO_BITMAP *m_pImage;

public:

    SpriteNode(SpriteObjectParams const &params, std::string name, ALLEGRO_BITMAP *image = NULL);

    virtual ~SpriteNode();

    virtual void VRender(Scene *pScene) override;
};


#endif //CROSSENGINEDESKTOP_SPRINTENODE_H
