//
// Created by Felipe Costa on 8/27/16.
//

#include "PlayerParams.h"
#include "../../engine/Actor/Base/BaseActor.h"
#include "../SceneGraph/PlayerNode.h"

PlayerParams::PlayerParams() : SpriteObjectParams() {
    m_Size = sizeof(PlayerParams);
}

PlayerParams::PlayerParams(const PlayerParams &playerParams) : SpriteObjectParams(playerParams) {
    m_Size = sizeof(PlayerParams);
}

boost::shared_ptr<IActor> PlayerParams::VCreate(BaseGameLogic *logic) {
    boost::shared_ptr<IActor> pTestObject(
            new BaseActor(boost::shared_ptr<PlayerParams>(NEW PlayerParams(*this))));
    logic->VAddActor(pTestObject, this);
    return pTestObject;
}

boost::shared_ptr<ISceneNode> PlayerParams::VCreateSceneNode(boost::shared_ptr<Scene> pScene) {
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_EXENAME_PATH);
    al_append_path_component(path, "assets");
    al_set_path_filename(path, "bubbles.png");
    ALLEGRO_BITMAP *img = al_load_bitmap(al_path_cstr(path, '/'));
    al_destroy_path(path);

    boost::shared_ptr<SceneNode> sprite(NEW PlayerNode(*this, "Sprite", img));
    return sprite;
}
