//
// Created by nuelex on 20/05/25.
//

#ifndef BASEDRAWERBUILDER_HPP
#define BASEDRAWERBUILDER_HPP
#include "../ColorParameters/BaseColorParameters.hpp"
#include "../Drawer/BaseDrawer.hpp"
#include "../Factory/Factory/AbstractDrawerFactory.hpp"


class BaseDrawerBuilder
{
public:
    BaseDrawerBuilder() = delete;
    explicit BaseDrawerBuilder(const std::shared_ptr<BaseGraphics> &graphics, const std::shared_ptr<BaseColorParameters>& colorParameters) {}
    virtual ~BaseDrawerBuilder() = default;

    virtual bool isBuilded() { return false; }
    virtual void reset() {}

    virtual std::shared_ptr<BaseDrawer> getDrawer() = 0;
};



#endif //BASEDRAWERBUILDER_HPP
