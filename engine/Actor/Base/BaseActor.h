//
// Created by Felipe Costa on 4/22/16.
//

#ifndef CROSSENGINEDESKTOP_BASEACTOR_H
#define CROSSENGINEDESKTOP_BASEACTOR_H


#include "../../Interfaces.h"
#include "ActorParams.h"

class BaseActor : public IActor {
    friend class BaseGameLogic;

protected:
    boost::shared_ptr<ActorParams> m_Params;
    ActorType m_ActorType;

public:
    BaseActor(ActorType actorType, boost::shared_ptr<ActorParams> params);

    virtual void VSetID(ActorId id);

    virtual Vec2 const VGetPosition();

    virtual void VSetPosition(Vec2 newPosition);

    virtual ActorId VGetID();

    virtual const ActorType VGetType() override;

    virtual boost::shared_ptr<ActorParams> VGetParams();
};


#endif //CROSSENGINEDESKTOP_BASEACTOR_H
