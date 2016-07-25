//
// Created by Felipe Costa on 4/22/16.
//

#include "SpriteNode.h"


SpriteNode::SpriteNode(SpriteObjectParams const &params, std::string name, ALLEGRO_BITMAP *image) :
        SceneNode(params.m_Id, name) {
    m_pImage = image;
}

SpriteNode::~SpriteNode() {
    if (m_pImage != NULL)
        al_destroy_bitmap(m_pImage);
}

void SpriteNode::VRender(Scene *pScene) {
    SceneNode::VRender(pScene);
    std::cout << "SpriteNode->VRender" << std::endl;
    if (m_pImage != NULL)
        al_draw_bitmap(m_pImage, 0, 0, 0);
}
