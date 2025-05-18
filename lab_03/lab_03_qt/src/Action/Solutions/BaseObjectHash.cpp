//
// Created by nuelex on 18/05/25.
//

#include "BaseObjectHash.hpp"
#include "../../Exceptions/Hashes/BaseObjectHashException.hpp"

#include <qchar.h>

#include "../../BaseObject/Camera/CameraPTU.hpp"
#include "../../BaseObject/Figure/Figure.hpp"


std::size_t BaseObjectHash::operator()(const std::shared_ptr<BaseObject> &object) const
{
    std::size_t hash;

    if (dynamic_pointer_cast<Figure>(object))
    {
        hash = typeid(Figure).hash_code();
    }
    else
    {
        if (dynamic_pointer_cast<CameraPTU>(object))
        {
            hash = typeid(Camera).hash_code();
        }
        else
        {
            const time_t cur_time = time(nullptr);
            throw ErrorBaseObjectHash_invalid_key(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }
    }

    return hash;
}

