//
// Created by Felipe Costa on 19/02/17.
//

#include "PlayerObjectParams.h"
#include "../../engine/Actor/Base/BaseActor.h"
#include "../../engine/SceneGraph/Scene.h"
#include "../SceneGraph/PlayerNode.h"

PlayerObjectParams::PlayerObjectParams() {
    m_Size = sizeof(PlayerObjectParams);
}

boost::shared_ptr<IActor> PlayerObjectParams::VCreate(BaseGameLogic *logic) {
    boost::shared_ptr<IActor> actorObject(
            new BaseActor(AT_Player, boost::shared_ptr<PlayerObjectParams>(NEW PlayerObjectParams(*this))));
    logic->VAddActor(actorObject, actorObject->VGetID());

    logic->VAddCollisionCircle(std::make_pair(m_Position, m_Radius), actorObject->VGetID());
    return actorObject;
}

boost::shared_ptr<ISceneNode> PlayerObjectParams::VCreateSceneNode(boost::shared_ptr<Scene> pScene) {
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_EXENAME_PATH);
    al_append_path_component(path, "assets");
    al_set_path_filename(path, "bubbles.png");
    ALLEGRO_BITMAP *img = al_load_bitmap(al_path_cstr(path, '/'));
    al_destroy_path(path);

    boost::shared_ptr<SceneNode> sprite(NEW PlayerNode(*this, "Sprite", img));
    pScene->AddChild(m_Id, sprite);

    return sprite;
}