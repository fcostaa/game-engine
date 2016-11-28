//
// Created by Felipe Costa on 4/21/16.
//

#ifndef CROSSENGINEDESKTOP_AWESOMEHUMANVIEW_H
#define CROSSENGINEDESKTOP_AWESOMEHUMANVIEW_H

#include "DriftsGameViewListener.h"
#include "../../engine/View/HumanView.h"
#include "../../engine/ScreenElementScene.h"
#include "../DriftsController.h"

class DriftsHumanView : public HumanView {
    friend class DriftsGameViewListener;

protected:

    boost::shared_ptr<ScreenElementScene> m_pScene;

    boost::shared_ptr<DriftsController> m_pController;

    boost::shared_ptr<ISceneNode> m_pPlayer;

    void BuildInitialScene();

    void MoveActor(ActorId i, Vec2 position);

public:
    DriftsHumanView();

    ~DriftsHumanView();

    virtual void onUpdate(double elapsedTime) override;

    virtual void onRender(double elapsedTime) override;

    virtual void VOnAttach(GameViewId vid, optional<ActorId> aid) override;
};


#endif //CROSSENGINEDESKTOP_AWESOMEHUMANVIEW_H
