//
// Created by Felipe Costa on 4/22/16.
//

#include "SpriteNode.h"

SpriteNode::SpriteNode(SpriteObjectParams const &params, std::string name, ALLEGRO_BITMAP *image) :
        SceneNode(params.m_Id, name, params.m_Pos) {
    m_pImage = image;
}

SpriteNode::~SpriteNode() {
    if (m_pImage != NULL)
        al_destroy_bitmap(m_pImage);
}

void SpriteNode::VRender(Scene *pScene) {
    SceneNode::VRender(pScene);
    if (m_pImage != NULL) {
        int bitmap_width = al_get_bitmap_width(m_pImage);
        int bitmap_height = al_get_bitmap_height(m_pImage);
        al_draw_bitmap(m_pImage, m_Props.getPosition().getX() - bitmap_width / 2, m_Props.getPosition().getY() - bitmap_height / 2, 0);
//        al_draw_bitmap(m_pImage, m_Props.getPosition().getX() - bitmap_width / 2, m_Props.getPosition().getY() - bitmap_height / 2, 0);

//        int bitmap_width = al_get_bitmap_width(m_pImage);
//        int bitmap_height = al_get_bitmap_height(m_pImage);
//
//        ALLEGRO_TRANSFORM t1, t2, t3, trans, prevTrans;
//
//        al_copy_transform(&prevTrans, al_get_current_transform());
//
//        al_identity_transform(&t1);
//        al_scale_transform(&t1, 0.5f, 0.5f);
//
//        al_identity_transform(&t2);
//        al_translate_transform(&t2, bitmap_width / 2, bitmap_height / 2);
//
//        al_identity_transform(&t3);
//        al_translate_transform(&t3, m_Props.getPosX(), m_Props.getPosY());
//
//        al_identity_transform(&trans);
//        al_compose_transform(&trans, &t1);
//        al_compose_transform(&trans, &t2);
//        al_compose_transform(&trans, &t3);
//        al_use_transform(&trans);
//
//        al_draw_bitmap(m_pImage, 0, 0, 0);
//
//        al_use_transform(&prevTrans);
    }
}
