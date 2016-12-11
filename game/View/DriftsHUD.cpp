//
// Created by Felipe Costa on 10/12/16.
//

#include "DriftsHUD.h"
#include "../../engine/standards.h"
#include <allegro5/allegro_font.h>
//#include "../../engine/GameApplication.cpp"

extern ALLEGRO_FONT *font;

void DriftsHUD::onUpdate(double elapsedTime) {

}

void DriftsHUD::onRender(double elapsedTime) {
        std::cout << "elapsedTime: " << elapsedTime << std::endl;
    al_draw_text(font, al_map_rgb(0, 0, 0), m_PosX, m_PosY, ALLEGRO_ALIGN_RIGHT, "Your Text Here!");
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
}
