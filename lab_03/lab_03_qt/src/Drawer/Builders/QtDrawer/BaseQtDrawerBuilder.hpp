//
// Created by nuelex on 20/05/25.
//

#ifndef BASEQTDRAWERBUILDER_HPP
#define BASEQTDRAWERBUILDER_HPP
#include <memory>

#include "../BaseDrawerBuilder.hpp"
#include "../../ColorParameters/BaseColorParameters.hpp"
#include "../../Drawer/BaseDrawer.hpp"


class BaseQtDrawerBuilder
{
public:
    BaseQtDrawerBuilder() = delete;
    explicit BaseQtDrawerBuilder(const std::shared_ptr<BaseGraphics> &graphics, const std::shared_ptr<BaseColorParameters> &color_parameters) {}
    virtual ~BaseQtDrawerBuilder() = default;

    virtual bool isBuilded() { return false; }
    virtual void reset() = 0;

    virtual bool buildColor() = 0;
    virtual bool buildPen() = 0;
    virtual bool buildDrawer() = 0;

    virtual std::shared_ptr<BaseDrawer> getDrawer() { return nullptr; }
};



#endif //BASEQTDRAWERBUILDER_HPP
