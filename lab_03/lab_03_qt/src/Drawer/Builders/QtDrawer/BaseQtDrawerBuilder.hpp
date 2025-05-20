//
// Created by nuelex on 20/05/25.
//

#ifndef BASEQTDRAWERBUILDER_HPP
#define BASEQTDRAWERBUILDER_HPP
#include <memory>

#include "../BaseDrawerBuilder.hpp"
#include "../../ColorParameters/BaseColorParameters.hpp"
#include "../../Drawer/BaseDrawer.hpp"


class BaseQtDrawerBuilder : public BaseDrawerBuilder
{
public:
    BaseQtDrawerBuilder() = delete;
    explicit BaseQtDrawerBuilder(const std::shared_ptr<BaseGraphics> &graphics, const std::shared_ptr<BaseColorParameters> &color_parameters) : BaseDrawerBuilder(graphics, color_parameters) {}
    ~BaseQtDrawerBuilder() override = default;

    bool isBuilded() override { return false; }
    void reset() override {}

    virtual bool buildColor() = 0;
    virtual bool buildPen() = 0;
    virtual bool buildDrawer() = 0;

    std::shared_ptr<BaseDrawer> getDrawer() override { return nullptr; }
};



#endif //BASEQTDRAWERBUILDER_HPP
