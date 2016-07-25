//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_ROOTNODE_H
#define CROSSENGINEDESKTOP_ROOTNODE_H

#include "SceneNode.h"
#include "Scene.h"

class RootNode : public SceneNode {
public:
    RootNode();

    virtual bool VAddChild(boost::shared_ptr<ISceneNode> kid);

    virtual bool VRemoveChild(ActorId id);

    virtual void VRenderChildren(Scene *pScene);

    virtual bool VIsVisible(Scene *pScene) const;

    virtual void VOnUpdate(Scene *scene, double elapsedTime);
};


#endif //CROSSENGINEDESKTOP_ROOTNODE_H
