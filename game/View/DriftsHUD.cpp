//
// Created by Felipe Costa on 10/12/16.
//

#include "DriftsHUD.h"
#include "../../engine/standards.h"
#include <allegro5/allegro_font.h>

extern ALLEGRO_FONT *font;

void DriftsHUD::onUpdate(double elapsedTime) {
    delta += elapsedTime;
    if (delta > 1.0) {
        score++;
        delta = 0.0;
    }
}

void DriftsHUD::onRender(double elapsedTime) {
    al_draw_textf(font, al_map_rgb(0, 0, 0), m_PosX, m_PosY, ALLEGRO_ALIGN_RIGHT, "Score: %i", score);
}

bool DriftsHUD::isVisible() const {
    return m_bIsVisible;
}

void DriftsHUD::setVisible(bool visible) {
    m_bIsVisible = visible;
}

DriftsHUD::DriftsHUD() {
    m_bIsVisible = true;
    m_PosX = SCREEN_WIDTH - 8;
    m_PosY = 8;
    score = 0;
    delta = 0.0;
}
