//
// Created by Felipe Costa on 8/27/16.
//

#include "PlayerNode.h"


PlayerNode::PlayerNode(const PlayerParams &params, const std::string &name, ALLEGRO_BITMAP *image) : SpriteNode(params,
                                                                                                                name,
                                                                                                                image) {
}

void PlayerNode::VRender(Scene *pScene) {
    SpriteNode::VRender(pScene);
}
