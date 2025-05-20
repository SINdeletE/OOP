//
// Created by nuelex on 20/05/25.
//

#ifndef QTDRAWERBUILDER_HPP
#define QTDRAWERBUILDER_HPP
#include "BaseQtDrawerBuilder.hpp"


class QtDrawerBuilder : public BaseQtDrawerBuilder
{
public:
    QtDrawerBuilder() = delete;
    explicit QtDrawerBuilder(const std::shared_ptr<BaseGraphics> &graphics, const std::shared_ptr<BaseColorParameters> &color_parameters);
    ~QtDrawerBuilder() override = default;

    bool isBuilded() override { return (total == 3); }
    void reset() override { _drawer.reset(); _color.reset(); _pen.reset(); total = 0; }

    bool buildColor() override;
    bool buildPen() override;
    bool buildDrawer() override;

    std::shared_ptr<BaseDrawer> getDrawer() override;

private:
    int total;
    std::shared_ptr<BaseGraphics> _graphics;
    std::shared_ptr<BaseColorParameters> _color_parameters;

    std::shared_ptr<BaseColor> _color;
    std::shared_ptr<BasePen> _pen;
    std::shared_ptr<BaseDrawer> _drawer;

    std::shared_ptr<AbstractDrawerFactory> _factory;
};



#endif //QTDRAWERBUILDER_HPP
