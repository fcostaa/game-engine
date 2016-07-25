//
// Created by Felipe Costa on 4/11/16.
//

#include "HumanView.h"

HumanView::HumanView() {
    mProcessManager = NEW ProcessManager();
}

HumanView::~HumanView() {
    while (!m_ScreenElements.empty()) {
        m_ScreenElements.pop_front();
    }

    SAFE_DELETE(mProcessManager);
}

void HumanView::onUpdate(double elapsedTime) {

    mProcessManager->updateProcesses(elapsedTime);

    for (ScreenElementList::iterator i = m_ScreenElements.begin(); i != m_ScreenElements.end(); ++i) {
        (*i)->onUpdate(elapsedTime);
    }
}

void HumanView::onRender(const Time &time) {

    for (ScreenElementList::iterator i = m_ScreenElements.begin(); i != m_ScreenElements.end(); ++i) {
        if ((*i)->isVisible()) {
            (*i)->onRender(time);
        }
    }
}

GameViewId HumanView::VGetId() const {
    return m_ViewId;
}

void HumanView::VOnAttach(GameViewId vid, optional<ActorId> aid) {
    m_ViewId = vid;
    m_ActorId = aid;
}

void HumanView::VPushElement(boost::shared_ptr<IScreenElement> pScreen) {
    m_ScreenElements.push_front(pScreen);
}

void HumanView::VPopElement(boost::shared_ptr<IScreenElement> pElement) {
    m_ScreenElements.remove(pElement);
}
