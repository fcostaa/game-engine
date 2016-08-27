//
// Created by Felipe Costa on 7/24/16.
//

#include "SpriteObjectParams.h"
#include "Base/BaseActor.h"
#include "../SceneGraph/SpriteNode.h"
#include "../SceneGraph/Scene.h"

SpriteObjectParams::SpriteObjectParams() {
    m_Size = sizeof(SpriteObjectParams);
}

boost::shared_ptr<IActor> SpriteObjectParams::VCreate(BaseGameLogic *logic) {
    boost::shared_ptr<IActor> pTestObject(
            new BaseActor(boost::shared_ptr<SpriteObjectParams>(NEW SpriteObjectParams(*this))));
    logic->VAddActor(pTestObject, this);
    return pTestObject;
}

boost::shared_ptr<ISceneNode> SpriteObjectParams::VCreateSceneNode(boost::shared_ptr<Scene> pScene) {
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_EXENAME_PATH);
    al_append_path_component(path, "assets");
    al_set_path_filename(path, "bubbles.png");
    ALLEGRO_BITMAP *img = al_load_bitmap(al_path_cstr(path, '/'));
    al_destroy_path(path);

    boost::shared_ptr<SceneNode> sprite(NEW SpriteNode(*this, "Sprite", img));
    pScene->AddChild(m_Id, sprite);
    return sprite;
}
