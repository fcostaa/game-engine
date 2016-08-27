//
// Created by Felipe Costa on 4/22/16.
//

#include "ScreenElementScene.h"


ScreenElementScene::ScreenElementScene() : Scene() {

}

void ScreenElementScene::onUpdate(double elapsedTime) {
    Scene::OnUpdate(elapsedTime);
}

void ScreenElementScene::onRender(double elapsedTime) {
    Scene::OnRender();
}

bool ScreenElementScene::isVisible() const {
    return true;
}

void ScreenElementScene::setVisible(bool visible) {

}
