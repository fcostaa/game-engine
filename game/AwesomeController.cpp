//
// Created by Felipe Costa on 8/23/16.
//

#include "AwesomeController.h"
#include "../engine/EventManager/Events/IEventData.h"
#include "../engine/EventManager/Events/EvtData_Move_Actor.h"
#include "../engine/EventManager/IEventManager.h"

AwesomeController::AwesomeController(boost::shared_ptr<ISceneNode> object) : m_object(object) {
}

void AwesomeController::VOnKeyDown(const int keyCode) {
//    if (keyCode == ALLEGRO_KEY_RIGHT) {
//        optional<ActorId> aid = m_object->VGet()->ActorId();
//        safeQueEvent(IEventDataPtr(NEW EvtData_Move_Actor(*aid, Vec2(5, 0))));
//    }
}

bool AwesomeController::VOnMouseMove(const int dx, const int dy) {
    optional<ActorId> aid = m_object->VGet()->ActorId();
    safeQueEvent(IEventDataPtr(NEW EvtData_Move_Actor(*aid, Vec2(dx, dy))));
}

void AwesomeController::OnUpdate(double elapsedTime) {

}
