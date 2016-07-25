//
// Created by Felipe Costa on 4/24/16.
//

#include "AwesomeGameViewListener.h"
#include "Events/EvtData_New_Game.h"
#include "Events/EvtData_New_Actor.h"
#include "../engine/SceneGraph/SceneNode.h"
#include "AwesomeHumanView.h"
#include "../engine/Actor/Base/ActorParams.h"

AwesomeGameViewListener::AwesomeGameViewListener(AwesomeHumanView *view) {
    m_pView = view;
}

bool AwesomeGameViewListener::HandleEvent(IEventData const &event) {
    std::cout << "AwesomeGameViewListener::HandleEvent" << std::endl;

    EventType eventType = event.VGetEventType();

    if (eventType == EvtData_New_Game::sk_EventType) {
        // do nothing
    } else if (eventType == EvtData_New_Actor::sk_EventType) {
        const EvtData_New_Actor &ed = static_cast< const EvtData_New_Actor & >( event );

        boost::shared_ptr<SceneNode> node = ed.m_pActorParams->VCreateSceneNode(m_pView->m_pScene);
        m_pView->m_pScene->AddChild(ed.m_pActorParams->m_Id, node);

//        if (ed.m_pActorParams->m_Type == AT_Teapot)
//        {
//            TeapotParams *p = static_cast<TeapotParams *>(ed.m_pActorParams);
//            //shared_ptr<SceneNode> teapot = m_pView->CreateTeapot(*p);
//            //assert(teapot);
//            if (p->m_ViewId == m_pView->m_ViewId)
//            {
//                m_pView->m_pTeapot = node;
//                m_pView->m_pTeapotController.reset(GCC_NEW TeapotController(m_pView->m_pTeapot, 0, 0));
//                m_pView->m_KeyboardHandler = m_pView->m_pTeapotController;
//                m_pView->m_MouseHandler = m_pView->m_pTeapotController;
//                m_pView->m_pCamera->SetTarget(m_pView->m_pTeapot);
//                m_pView->m_pTeapot->SetAlpha(0.8f);
//            }
//        }
        return true;
    }

    return false;
}
