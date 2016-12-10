//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_SPRINTENODE_H
#define CROSSENGINEDESKTOP_SPRINTENODE_H


#include <allegro5/bitmap.h>
#include "SceneNode.h"
#include "../Actor/CircleObjectParams.h"

class CircleNode : public SceneNode {

protected:
    ALLEGRO_BITMAP *m_pImage;

public:

    CircleNode(CircleObjectParams const &params, std::string name, ALLEGRO_BITMAP *image = NULL);

    virtual ~CircleNode();

    virtual void VRender(Scene *pScene) override;
};


#endif //CROSSENGINEDESKTOP_SPRINTENODE_H
