//
// Created by Felipe Costa on 4/21/16.
//

#ifndef CROSSENGINEDESKTOP_AWESOMEHUMANVIEW_H
#define CROSSENGINEDESKTOP_AWESOMEHUMANVIEW_H

#include "../engine/View/HumanView.h"
#include "../engine/ScreenElementScene.h"
#include "AwesomeGameViewListener.h"

class AwesomeHumanView : public HumanView {
    friend class AwesomeGameViewListener;

protected:

    boost::shared_ptr<ScreenElementScene> m_pScene;

    void BuildInitialScene();

public:
    AwesomeHumanView();

    ~AwesomeHumanView();

    virtual void onUpdate(double elapsedTime) override;

    virtual void onRender(const Time &time) override;

    virtual void VOnAttach(GameViewId vid, optional<ActorId> aid) override;
};


#endif //CROSSENGINEDESKTOP_AWESOMEHUMANVIEW_H
