//
// Created by Felipe Costa on 7/24/16.
//

#include "CircleObjectParams.h"
#include "Base/BaseActor.h"
#include "../SceneGraph/CircleNode.h"
#include "../SceneGraph/Scene.h"

CircleObjectParams::CircleObjectParams() {
    m_Size = sizeof(CircleObjectParams);
}

boost::shared_ptr<IActor> CircleObjectParams::VCreate(BaseGameLogic *logic) {
    boost::shared_ptr<IActor> actorObject(
            new BaseActor(m_Type, boost::shared_ptr<CircleObjectParams>(NEW CircleObjectParams(*this))));
    logic->VAddActor(actorObject, actorObject->VGetID());

    logic->VAddCollisionCircle(std::make_pair(m_Pos, m_Radius), actorObject->VGetID());
    return actorObject;
}

boost::shared_ptr<ISceneNode> CircleObjectParams::VCreateSceneNode(boost::shared_ptr<Scene> pScene) {
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_EXENAME_PATH);
    al_append_path_component(path, "assets");
    al_set_path_filename(path, "bubbles.png");
    ALLEGRO_BITMAP *img = al_load_bitmap(al_path_cstr(path, '/'));
    al_destroy_path(path);

    boost::shared_ptr<SceneNode> sprite(NEW CircleNode(*this, "Sprite", img));
    pScene->AddChild(m_Id, sprite);

    return sprite;
}
