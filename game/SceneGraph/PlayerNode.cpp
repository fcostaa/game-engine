//
// Created by Felipe Costa on 19/02/17.
//

#include "PlayerNode.h"


PlayerNode::PlayerNode(PlayerObjectParams const &params, std::string name, ALLEGRO_BITMAP *image) :
        SceneNode(params.m_Id, name, params.m_Position) {
    m_pImage = image;
}

PlayerNode::~PlayerNode() {
    if (m_pImage != NULL)
        al_destroy_bitmap(m_pImage);
}

void PlayerNode::VRender(Scene *pScene) {
    SceneNode::VRender(pScene);
    if (m_pImage != NULL) {
        int bitmap_width = al_get_bitmap_width(m_pImage);
        int bitmap_height = al_get_bitmap_height(m_pImage);
        ALLEGRO_COLOR tintColor = al_map_rgba_f(1, 0, 0, 1);
        float x = m_Props.getPosition().getX() - bitmap_width / 2;
        float y = m_Props.getPosition().getY() - bitmap_height / 2;
        al_draw_tinted_bitmap(m_pImage, tintColor, x, y, 0);
    }
}