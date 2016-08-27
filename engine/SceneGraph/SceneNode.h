//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_SCENENODE_H
#define CROSSENGINEDESKTOP_SCENENODE_H

#include <vector>
#include "../Interfaces.h"
#include "../Utils/Optional.h"
#include "SceneNodeProperties.h"

typedef std::vector<boost::shared_ptr<ISceneNode> > SceneNodeList;

class SceneNode : public ISceneNode {

    friend class Scene;

protected:
    SceneNodeList m_Children;
    SceneNode *m_pParent;
    SceneNodeProperties m_Props;

public:

    SceneNode(optional<ActorId> actorId, std::string name);

    virtual ~SceneNode();

    virtual void VRender(Scene *pScene);

    virtual void VOnUpdate(Scene *scene, double elapsedTime);

    virtual void VRenderChildren(Scene *pScene);

    virtual bool VIsVisible(Scene *pScene) const;

    virtual bool VAddChild(boost::shared_ptr<ISceneNode> kid);

    virtual bool VRemoveChild(ActorId id);

    virtual const SceneNodeProperties *const VGet() const;

    virtual void VTranslate(int posX, int posY);
};


#endif //CROSSENGINEDESKTOP_SCENENODE_H
