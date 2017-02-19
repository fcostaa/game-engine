//
// Created by Felipe Costa on 8/27/16.
//

#ifndef CROSSENGINEDESKTOP_AIVIEW_H
#define CROSSENGINEDESKTOP_AIVIEW_H


#include "../../engine/Interfaces.h"

class AIView : public IGameView {
    friend class AIViewListener;

protected:
    GameViewId m_ViewId;
    optional<ActorId> m_PlayerActorId;

    Vec2 velocity;
public:

    AIView();

    virtual ~AIView();

    virtual void onUpdate(double elapsedTime);

    virtual void onRender(double elapsedTime);

    virtual GameViewId VGetId() const;

    virtual void VOnAttach(GameViewId vid, optional<ActorId> aid);
};


#endif //CROSSENGINEDESKTOP_AIVIEW_H
