//
// Created by nuelex on 10/05/25.
//

#include "CompositeObject.hpp"

#include "../../Exceptions/BaseObject/CompositeException.hpp"

void CompositeObject::addChild(const std::shared_ptr<BaseObject>& child)
{
    try
    {
        children.push_back(child);
    }
    catch (std::bad_alloc& e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCompositeObject_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}
