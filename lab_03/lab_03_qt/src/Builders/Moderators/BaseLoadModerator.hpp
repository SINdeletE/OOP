//
// Created by nuelex on 25/05/25.
//

#ifndef BASELOADMODERATOR_HPP
#define BASELOADMODERATOR_HPP
#include <memory>

#include "../../BaseObject/BaseObject.hpp"


class BaseLoadModerator
{
public:
    BaseLoadModerator() = default;
    virtual ~BaseLoadModerator() = default;

    virtual std::shared_ptr<BaseObject> load(const std::string &filename) = 0;
};



#endif //BASELOADMODERATOR_HPP
