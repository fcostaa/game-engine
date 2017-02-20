//
// Created by Felipe Costa on 8/23/16.
//

#include "DriftsController.h"
#include "../engine/EventManager/Events/IEventData.h"
#include "../engine/EventManager/Events/EvtData_Move_Actor.h"
#include "../engine/EventManager/IEventManager.h"

DriftsController::DriftsController(boost::shared_ptr<ISceneNode> object) : m_object(object) {
}

void DriftsController::VOnKeyDown(const int keyCode) {
}

bool DriftsController::VOnMouseMove(const int dx, const int dy) {
    optional<ActorId> aid = m_object->VGet()->ActorId();
    safeQueEvent(IEventDataPtr(NEW EvtData_Move_Actor(*aid, Vec2(dx, dy))));
}

void DriftsController::OnUpdate(double elapsedTime) {

}
