//
// Created by Felipe Costa on 4/11/16.
//

#ifndef CROSSENGINEDESKTOP_HUMANVIEW_H
#define CROSSENGINEDESKTOP_HUMANVIEW_H

#include <boost/shared_ptr.hpp>
#include "../Interfaces.h"
#include "../Logic/ProcessManager.h"
#include "../standards.h"

class HumanView : public IGameView {

protected:
    ProcessManager *mProcessManager;

    ScreenElementList m_ScreenElements;

    GameViewId m_ViewId;
    optional<ActorId> m_ActorId;

public:
    boost::shared_ptr<IMouseHandler> m_MouseHandler;
    boost::shared_ptr<IKeyboardHandler> m_KeyboardHandler;

    HumanView();

    virtual ~HumanView();

    virtual void onUpdate(double elapsedTime);

    virtual void onRender(double elapsedTime);

    virtual void VOnAttach(GameViewId vid, optional<ActorId> aid);

    virtual void VPushElement(boost::shared_ptr<IScreenElement> pScreen);

    virtual void VPopElement(boost::shared_ptr<IScreenElement> pElement);

    virtual GameViewId VGetId() const;
};

#endif //CROSSENGINEDESKTOP_HUMANVIEW_H
