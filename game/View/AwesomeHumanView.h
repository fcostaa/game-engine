//
// Created by Felipe Costa on 4/21/16.
//

#ifndef CROSSENGINEDESKTOP_AWESOMEHUMANVIEW_H
#define CROSSENGINEDESKTOP_AWESOMEHUMANVIEW_H

#include "AwesomeGameViewListener.h"
#include "../../engine/View/HumanView.h"
#include "../../engine/ScreenElementScene.h"
#include "../AwesomeController.h"

class AwesomeHumanView : public HumanView {
    friend class AwesomeGameViewListener;

protected:

    boost::shared_ptr<ScreenElementScene> m_pScene;

    boost::shared_ptr<AwesomeController> m_pController;

    boost::shared_ptr<ISceneNode> m_pPlayer;

    void BuildInitialScene();

    void MoveActor(ActorId i, int i1, int i2);

public:
    AwesomeHumanView();

    ~AwesomeHumanView();

    virtual void onUpdate(double elapsedTime) override;

    virtual void onRender(double elapsedTime) override;

    virtual void VOnAttach(GameViewId vid, optional<ActorId> aid) override;
};


#endif //CROSSENGINEDESKTOP_AWESOMEHUMANVIEW_H
