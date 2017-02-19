//
// Created by Felipe Costa on 5/25/15.
//

#ifndef CROSSENGINEDESKTOP_INTERFACES_H
#define CROSSENGINEDESKTOP_INTERFACES_H

#include <list>
#include <boost/shared_ptr.hpp>

#include "Timer/Timer.h"
#include "Utils/Optional.h"
#include "Math/Vec2.h"

class IKeyboardHandler {
public:
    virtual void VOnKeyDown(const int keyCode) = 0;
//
//    virtual bool VOnKeyUp(const BYTE c) = 0;
};

class IMouseHandler {
public:
    virtual bool VOnMouseMove(const int dx, const int dy) = 0;

//    virtual bool VOnMouseMove(const CPoint &mousePos) = 0;
//
//    virtual bool VOnLButtonDown(const CPoint &mousePos) = 0;
//
//    virtual bool VOnLButtonUp(const CPoint &mousePos) = 0;
//
//    virtual bool VOnRButtonDown(const CPoint &mousePos) = 0;
//
//    virtual bool VOnRButtonUp(const CPoint &mousePos) = 0;
};

typedef unsigned int ActorId;
struct ActorParams;

enum ActorType
{
    AT_Circle,
    AT_Player
};

class IActor {
public:
    virtual ~IActor() {}

    virtual ActorId VGetID() = 0;

    virtual const ActorType VGetType()=0;

    virtual Vec2 const VGetPosition() = 0;

    virtual void VSetID(ActorId id) = 0;

    virtual void VSetPosition(Vec2 newPosition) = 0;

    virtual boost::shared_ptr<ActorParams> VGetParams() = 0;
};

class IGameLogic {
public:

    virtual boost::shared_ptr<IActor> VGetActor(const ActorId id) = 0;

    virtual void VAddActor(boost::shared_ptr<IActor> actor, struct ActorParams *p) = 0;

    virtual void VRemoveActor(ActorId id) = 0;

    virtual void onUpdate(double elapsedTime) = 0;

    virtual bool VLoadGame() = 0;
};

typedef unsigned int GameViewId;

class IGameView {
public:
    virtual void onUpdate(double elapsedTime) = 0;

    virtual void onRender(double elapsedTime) = 0;

    virtual GameViewId VGetId() const = 0;

    virtual void VOnAttach(GameViewId vid, optional<ActorId> aid) = 0;

    virtual ~IGameView() {
    };
};

class IScreenElement {
public:
    virtual ~IScreenElement() {};

    virtual void onUpdate(double elapsedTime) = 0;

    virtual void onRender(double elapsedTime) = 0;

    virtual bool isVisible() const = 0;

    virtual void setVisible(bool visible) = 0;

};

typedef std::list<boost::shared_ptr<IScreenElement> > ScreenElementList;
typedef std::list<boost::shared_ptr<IGameView> > GameViewList;

class Scene;

class SceneNodeProperties;

class ISceneNode {
public:
    virtual const SceneNodeProperties *const VGet() const = 0;

    virtual void VRender(Scene *pScene) = 0;

    virtual void VOnUpdate(Scene *, double elapsedTime) = 0;

    virtual bool VAddChild(boost::shared_ptr<ISceneNode> kid) = 0;

    virtual bool VRemoveChild(ActorId id) = 0;

    virtual void VRenderChildren(Scene *pScene) = 0;

    virtual bool VIsVisible(Scene *pScene) const = 0;

    virtual void VSetPosition(Vec2 position) = 0;

    virtual ~ISceneNode() {};
};

#endif //CROSSENGINEDESKTOP_INTERFACES_H
