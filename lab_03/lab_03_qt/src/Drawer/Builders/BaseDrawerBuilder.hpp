//
// Created by nuelex on 20/05/25.
//

#ifndef BASEDRAWERBUILDER_HPP
#define BASEDRAWERBUILDER_HPP
#include "../../Builders/BaseBuilder.hpp"
#include "../ColorParameters/BaseColorParameters.hpp"
#include "../Drawer/BaseDrawer.hpp"
#include "../Factory/Factory/AbstractDrawerFactory.hpp"


class BaseDrawerBuilder : public BaseBuilder
{
public:
    BaseDrawerBuilder() = delete;
    explicit BaseDrawerBuilder(const std::shared_ptr<BaseGraphics> &graphics, const std::shared_ptr<BaseColorParameters>& colorParameters) {}
    ~BaseDrawerBuilder() override = default;

    bool isBuilded() override { return false; }
    void reset() override {}

    virtual std::shared_ptr<BaseDrawer> getDrawer() = 0;
};



#endif //BASEDRAWERBUILDER_HPP
