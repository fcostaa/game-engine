//
// Created by Felipe Costa on 8/23/16.
//

#ifndef CROSSENGINEDESKTOP_AWESOMECONTROLLER_H
#define CROSSENGINEDESKTOP_AWESOMECONTROLLER_H

#include "../engine/Interfaces.h"
#include "../engine/SceneGraph/SceneNodeProperties.h"

class AwesomeController : public IMouseHandler, public IKeyboardHandler {

protected:
    boost::shared_ptr<ISceneNode> m_object;

public:
    AwesomeController(boost::shared_ptr<ISceneNode> object);

    void OnUpdate(double elapsedTime);

    virtual void VOnKeyDown(const int keyCode);

    virtual bool VOnMouseMove(const int dx, const int dy);
};


#endif //CROSSENGINEDESKTOP_AWESOMECONTROLLER_H
