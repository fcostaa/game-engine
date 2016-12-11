//
// Created by Felipe Costa on 10/12/16.
//

#ifndef CROSSENGINEDESKTOP_DRIFTSHUD_H
#define CROSSENGINEDESKTOP_DRIFTSHUD_H


#include "../../engine/Interfaces.h"

class DriftsHUD : public IScreenElement {

protected:
    int m_PosX, m_PosY;
    bool m_bIsVisible;
    int score;
    double delta;

public:
    DriftsHUD();

    virtual void onUpdate(double elapsedTime) override;

    virtual void onRender(double elapsedTime) override;

    virtual bool isVisible() const override;

    virtual void setVisible(bool visible) override;

};


#endif //CROSSENGINEDESKTOP_DRIFTSHUD_H
