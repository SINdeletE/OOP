//
// Created by nuelex on 25/05/25.
//

#include "TransformManagerCommandSetParams.hpp"

void TransformManagerCommandSetParams::execute()
{
    _action(_object, _transform);
}

