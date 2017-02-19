//
// Created by Felipe Costa on 4/22/16.
//

#include "CircleNode.h"

CircleNode::CircleNode(CircleObjectParams const &params, std::string name, ALLEGRO_BITMAP *image) :
        SceneNode(params.m_Id, name, params.m_Position) {
    m_pImage = image;
}

CircleNode::~CircleNode() {
    if (m_pImage != NULL)
        al_destroy_bitmap(m_pImage);
}

void CircleNode::VRender(Scene *pScene) {
    SceneNode::VRender(pScene);
    if (m_pImage != NULL) {
        int bitmap_width = al_get_bitmap_width(m_pImage);
        int bitmap_height = al_get_bitmap_height(m_pImage);
        al_draw_bitmap(m_pImage, m_Props.getPosition().getX() - bitmap_width / 2, m_Props.getPosition().getY() - bitmap_height / 2, 0);
    }
}
