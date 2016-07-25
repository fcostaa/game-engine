//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_SCREENELEMENTSCENE_H
#define CROSSENGINEDESKTOP_SCREENELEMENTSCENE_H

#include "Interfaces.h"
#include "SceneGraph/Scene.h"

class ScreenElementScene : public Scene, public IScreenElement {

public:
    ScreenElementScene();

private:
    virtual void onUpdate(double elapsedTime);

    virtual void onRender(const Time &time);

    virtual bool isVisible() const;

    virtual void setVisible(bool visible);
};


#endif //CROSSENGINEDESKTOP_SCREENELEMENTSCENE_H
