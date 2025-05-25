//
// Created by nuelex on 16/05/25.
//

#include "CameraPTUDirector.hpp"

std::shared_ptr<BaseObject> CameraPTUDirector::create()
{
    if (_builder->buildPosition() && _builder->buildTarget() && _builder->buildUp())
        return _builder->getCameraPTU();

    return nullptr;
}

