//
// Created by Felipe Costa on 4/22/16.
//

#include "SpriteActorParams.h"
#include "Base/BaseActor.h"

SpriteActorParams::SpriteActorParams() : ActorParams() {

}

boost::shared_ptr<IActor> SpriteActorParams::VCreate(BaseGameLogic *logic) {
    boost::shared_ptr<IActor> sprite(new BaseActor(boost::shared_ptr<SpriteActorParams>(NEW SpriteActorParams(*this))));
    logic->VAddActor(sprite, this);
//    logic->VGetGamePhysics()->VAddBox(Vec3(m_Length, m_Length/3, m_Length), &*pTeapot, SpecificGravity(PhysDens_Water)*.8f, PhysMat_Normal);
    return sprite;
}

boost::shared_ptr<SceneNode> SpriteActorParams::VCreateSceneNode(boost::shared_ptr<Scene> pScene) {
//    ALLEGRO_BITMAP *image = al_load_bitmap("image.png");
//    boost::shared_ptr<SceneNode> sprite(NEW SpriteNode(m_Id, "Sprite", image));
    return boost::shared_ptr<SceneNode>();
}
