//
// Created by nuelex on 19/05/25.
//

#ifndef BASEDRAWERDIRECTOR_HPP
#define BASEDRAWERDIRECTOR_HPP
#include <memory>

#include "../Drawer/BaseDrawer.hpp"


class BaseDrawerDirector
{
public:
    BaseDrawerDirector() = default;
    virtual ~BaseDrawerDirector() = default;

    virtual std::shared_ptr<BaseDrawer> createDrawer(const std::shared_ptr<BaseColorParameters> &color) = 0;
};



#endif //BASEDRAWERDIRECTOR_HPP
